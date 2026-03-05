modded class MissionGameplay
{
	protected ref EMC_Menu m_EMCMenu;
	protected ref EMC_Config m_EMCConfig;

	override void OnInit()
	{
		super.OnInit();
		m_EMCMenu = new EMC_Menu();
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);

		if (rpc_type == EMC_RPC.OPEN_UI)
		{
			OpenMercenaryUI();
			return;
		}

		if (rpc_type == EMC_RPC.SYNC_CONFIG)
		{
			if (!ctx.Read(m_EMCConfig))
				return;

			if (m_EMCMenu)
				m_EMCMenu.SetConfig(m_EMCConfig);
			return;
		}

		if (rpc_type == EMC_RPC.RESULT)
		{
			EMC_RpcResult result;
			if (!ctx.Read(result))
				return;

			string prefix = result.Success ? "[EMC] " : "[EMC][ERROR] ";
			GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCSystem, "Mercenary Broker", prefix + result.Message, ""));
		}
	}

	void OpenMercenaryUI()
	{
		if (!m_EMCMenu)
			m_EMCMenu = new EMC_Menu();

		if (m_EMCConfig)
			m_EMCMenu.SetConfig(m_EMCConfig);

		GetUIManager().ShowScriptedMenu(m_EMCMenu, null);
	}
};

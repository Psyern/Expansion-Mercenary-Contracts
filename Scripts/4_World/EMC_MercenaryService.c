class EMC_MercenaryService
{
	protected static ref EMC_MercenaryService s_Instance;
	protected ref map<string, ref EMC_PlayerData> m_PlayerData;

	static EMC_MercenaryService Get()
	{
		if (!s_Instance)
			s_Instance = new EMC_MercenaryService();

		return s_Instance;
	}

	void EMC_MercenaryService()
	{
		m_PlayerData = new map<string, ref EMC_PlayerData>();
	}

	void OpenUI(PlayerBase player)
	{
		if (!GetGame().IsServer() || !player)
			return;

		SyncConfig(player);
		GetRPCManager().SendRPC("EMC", "RPC_OpenUI", null, true, player.GetIdentity());
	}

	void SyncConfig(PlayerBase player)
	{
		if (!GetGame().IsServer() || !player)
			return;

		autoptr ScriptRPC rpc = new ScriptRPC();
		rpc.Write(EMC_ConfigLoader.Get());
		rpc.Send(player, EMC_RPC.SYNC_CONFIG, true, player.GetIdentity());
	}

	void HandleHireRequest(PlayerBase player, int mercIndex)
	{
		if (!GetGame().IsServer() || !player || !player.GetIdentity())
			return;

		EMC_Config config = EMC_ConfigLoader.Get();
		if (!config || mercIndex < 0 || mercIndex >= config.Mercenaries.Count())
		{
			SendResult(player, false, "Invalid mercenary selection.");
			return;
		}

		EMC_PlayerData playerData = GetOrCreatePlayerData(player);
		if (playerData.ActiveMercs >= config.MaxMercPerPlayer)
		{
			SendResult(player, false, "Mercenary limit reached.");
			return;
		}

		int now = GetGame().GetTime() / 1000;
		int cooldownUntil = playerData.GetCooldownUntil(mercIndex);
		if (cooldownUntil > now)
		{
			SendResult(player, false, "Mercenary is on cooldown for " + (cooldownUntil - now).ToString() + "s.");
			return;
		}

		EMC_MercenaryEntry entry = config.Mercenaries.Get(mercIndex);
		if (!TryTakePayment(player, entry))
		{
			SendResult(player, false, "Insufficient funds/reputation.");
			return;
		}

		if (!SpawnAndAssignMercenary(player, entry))
		{
			SendResult(player, false, "Failed to spawn mercenary.");
			return;
		}

		playerData.ActiveMercs++;
		playerData.SetCooldownUntil(mercIndex, now + entry.Cooldown);
		SendResult(player, true, "Mercenary hired: " + entry.Loadout);
	}

	void NotifyMercenaryDied(PlayerBase owner)
	{
		EMC_PlayerData playerData = GetOrCreatePlayerData(owner);
		if (playerData.ActiveMercs > 0)
			playerData.ActiveMercs--;
	}

	void CleanupForPlayer(PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return;

		string uid = player.GetIdentity().GetPlainId();
		m_PlayerData.Remove(uid);
	}

	protected EMC_PlayerData GetOrCreatePlayerData(PlayerBase player)
	{
		string uid = player.GetIdentity().GetPlainId();
		if (!m_PlayerData.Contains(uid))
			m_PlayerData.Set(uid, new EMC_PlayerData());

		return m_PlayerData.Get(uid);
	}

	protected bool TryTakePayment(PlayerBase player, EMC_MercenaryEntry entry)
	{
		// Adapter stub: integrate Expansion Market / Hardline here.
		// Payment==1: currency, Payment==0: reputation.
		return true;
	}

	protected bool SpawnAndAssignMercenary(PlayerBase owner, EMC_MercenaryEntry entry)
	{
		vector ownerPos = owner.GetPosition();
		vector spawnPos = ownerPos + "1 0 1";
		spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]);

		EntityAI merc = EntityAI.Cast(GetGame().CreateObject("SurvivorM_Mirek", spawnPos, false, true));
		if (!merc)
			return false;

		// Adapter stub: apply loadout + Expansion AI follow/guard owner.
		EMC_Log.Info(string.Format("Spawned mercenary '%1' for %2 using loadout '%3'.", merc, owner.GetIdentity().GetName(), entry.Loadout));
		return true;
	}

	protected void SendResult(PlayerBase player, bool success, string message)
	{
		autoptr ScriptRPC rpc = new ScriptRPC();
		rpc.Write(new EMC_RpcResult(success, message));
		rpc.Send(player, EMC_RPC.RESULT, true, player.GetIdentity());
	}
};

modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		EMC_ConfigLoader.Get();
		EMC_Log.Info("MissionServer init complete.");
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);

		if (!GetGame().IsServer() || rpc_type != EMC_RPC.REQUEST_HIRE)
			return;

		Param1<int> request;
		if (!ctx.Read(request))
			return;

		PlayerBase player = PlayerBase.Cast(target);
		if (!player)
			player = PlayerBase.Cast(GetGame().GetPlayer());

		EMC_MercenaryService.Get().HandleHireRequest(player, request.param1);
	}

	override void InvokeOnDisconnect(PlayerBase player)
	{
		super.InvokeOnDisconnect(player);
		EMC_MercenaryService.Get().CleanupForPlayer(player);
	}
};

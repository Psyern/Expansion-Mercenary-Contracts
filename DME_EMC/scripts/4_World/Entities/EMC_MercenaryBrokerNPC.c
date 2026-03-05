class EMC_MercenaryBrokerNPC : SurvivorBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		return false;
	}

	override void SetActions()
	{
		super.SetActions();
	}

	override bool CanBeTargetedByAI(EntityAI ai)
	{
		return false;
	}

	override bool IsFacingCamera()
	{
		return true;
	}

	void OpenContractsFor(PlayerBase player)
	{
		if (!GetGame().IsServer() || !player)
			return;

		EMC_MercenaryService.Get().OpenUI(player);
	}
};

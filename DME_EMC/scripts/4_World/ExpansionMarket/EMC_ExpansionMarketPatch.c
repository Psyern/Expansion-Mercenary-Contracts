// =====================================================================
// EMC_ExpansionMarketPatch.c
// Integration: Expansion Market "buy" triggers EMC hire flow.
// Server-authoritative: handled inside ExpansionMarketModule purchase path.
// =====================================================================

#ifdef EXPANSIONMODMARKET

modded class ExpansionMarketModule
{
	// Hook into server-side purchase execution.
	// If the purchased item is our virtual mercenary contract item, consume the purchase
	// and execute the hire logic instead.
	override private void Exec_RequestPurchase(notnull PlayerBase player, int itemID, int count, int currentPrice, ExpansionTraderObjectBase trader, bool includeAttachments = true, int skinIndex = -1, TIntArray attachmentIDs = NULL)
	{
		// Always call super for non-EMC items.
		ExpansionMarketItem item = ExpansionMarketCategory.GetGlobalItem(itemID);
		if (item && EMC_ExpansionMarketIntegration.IsEMCContractItem(item.ClassName))
		{
			EMC_ExpansionMarketIntegration.HandlePurchase(player, item.ClassName, count);
			return;
		}

		super.Exec_RequestPurchase(player, itemID, count, currentPrice, trader, includeAttachments, skinIndex, attachmentIDs);
	}
};

#endif

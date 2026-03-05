// =====================================================================
// EMC_ExpansionMarketIntegration.c
// Minimal bridge that maps Expansion Market purchases to EMC hires.
// =====================================================================

#ifdef EXPANSIONMODMARKET

class EMC_ExpansionMarketIntegration
{
	// Friendly fake market item class names.
	// These do not need to be real DayZ classes; they are only used as identifiers in Market JSON.
	// Mapping:
	//  - Mercenary1 -> mercIndex 0
	//  - Mercenary2 -> mercIndex 1
	//  - ...
	static const string CONTRACT_PREFIX = "Mercenary";

	static bool IsEMCContractItem(string className)
	{
		if (className == "")
			return false;

		return className.IndexOf(CONTRACT_PREFIX) == 0;
	}

	static bool TryParseIndex(string className, out int mercIndex)
	{
		mercIndex = -1;
		if (!IsEMCContractItem(className))
			return false;

		string s = className.Substring(CONTRACT_PREFIX.Length(), className.Length() - CONTRACT_PREFIX.Length());
		int oneBased = s.ToInt();
		if (oneBased <= 0)
			return false;

		mercIndex = oneBased - 1;
		return true;
	}

	static void HandlePurchase(PlayerBase player, string className, int count)
	{
		if (!GetGame().IsServer() || !player)
			return;

		int mercIndex;
		if (!TryParseIndex(className, mercIndex))
		{
			EMC_Log.Warn("Market purchase: Invalid mercenary contract item: " + className);
			return;
		}

		// Requirement: One purchase = exactly one hire (ignore count).
		EMC_MercenaryService.Get().HandleHireRequest(player, mercIndex);
	}
};

#endif

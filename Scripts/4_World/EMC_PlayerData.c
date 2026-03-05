class EMC_PlayerData
{
	int ActiveMercs;
	ref map<int, int> CooldownUntilByIndex;

	void EMC_PlayerData()
	{
		ActiveMercs = 0;
		CooldownUntilByIndex = new map<int, int>();
	}

	int GetCooldownUntil(int mercIndex)
	{
		if (!CooldownUntilByIndex.Contains(mercIndex))
			return 0;

		return CooldownUntilByIndex.Get(mercIndex);
	}

	void SetCooldownUntil(int mercIndex, int unixTime)
	{
		CooldownUntilByIndex.Set(mercIndex, unixTime);
	}
};

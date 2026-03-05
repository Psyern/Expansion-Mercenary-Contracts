class EMC_MercenaryEntry
{
	string Loadout;
	int Payment;
	int Cost;
	int Cooldown;

	void EMC_MercenaryEntry(string loadout = "BanditLoadout", int payment = 1, int cost = 1000, int cooldown = 1500)
	{
		Loadout = loadout;
		Payment = payment;
		Cost = cost;
		Cooldown = cooldown;
	}
};

class EMC_Config
{
	int Version;
	int MaxMercPerPlayer;
	ref array<ref EMC_MercenaryEntry> Mercenaries;

	void EMC_Config()
	{
		Version = EMC_Constants.CONFIG_VERSION;
		MaxMercPerPlayer = 4;
		Mercenaries = new array<ref EMC_MercenaryEntry>();
	}

	void EnsureDefaults()
	{
		if (!Mercenaries)
			Mercenaries = new array<ref EMC_MercenaryEntry>();

		if (Mercenaries.Count() == 0)
		{
			Mercenaries.Insert(new EMC_MercenaryEntry("BanditLoadout", 1, 1000, 1500));
			Mercenaries.Insert(new EMC_MercenaryEntry("NBCLoadout", 1, 1000, 1500));
		}

		if (MaxMercPerPlayer <= 0)
			MaxMercPerPlayer = 4;
	}
};

class EMC_RpcResult
{
	bool Success;
	string Message;

	void EMC_RpcResult(bool success = false, string message = "")
	{
		Success = success;
		Message = message;
	}
};

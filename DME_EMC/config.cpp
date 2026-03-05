class CfgPatches
{
	class DME_EMC
	{
		units[] =
		{
			"Mercenary1",
			"Mercenary2",
			"Mercenary3",
			"Mercenary4",
			"Mercenary5",
			"Mercenary6",
			"Mercenary7",
			"Mercenary8",
			"Mercenary9",
			"Mercenary10"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Scripts"};
	};
};

class CfgMods
{
	class DME_EMC
	{
		dir = "DME_EMC";
		name = "DME_EMC";
		credits = "";
		author = "Psyern";
		authorID = "";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DME_EMC/scripts/3_Game"};
			};

			class worldScriptModule
			{
				value = "";
				files[] = {"DME_EMC/scripts/4_World"};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {"DME_EMC/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;

	class MercenaryContractBase: Inventory_Base
	{
		scope = 0;
		displayName = "Mercenary Contract";
		descriptionShort = "Use Expansion Market purchase to hire a mercenary.";
		weight = 1;
		itemSize[] = {1, 1};
		rotationFlags = 1;
	};

	class Mercenary1: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 1"; };
	class Mercenary2: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 2"; };
	class Mercenary3: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 3"; };
	class Mercenary4: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 4"; };
	class Mercenary5: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 5"; };
	class Mercenary6: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 6"; };
	class Mercenary7: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 7"; };
	class Mercenary8: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 8"; };
	class Mercenary9: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 9"; };
	class Mercenary10: MercenaryContractBase { scope = 2; displayName = "Mercenary Contract 10"; };
};

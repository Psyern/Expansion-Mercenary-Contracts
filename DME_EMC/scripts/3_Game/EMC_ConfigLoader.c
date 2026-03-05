class EMC_ConfigLoader
{
	protected static ref EMC_Config s_Config;

	static EMC_Config Get()
	{
		if (!s_Config)
			s_Config = LoadOrCreateDefault();

		return s_Config;
	}

	static EMC_Config LoadOrCreateDefault()
	{
		if (!FileExist(EMC_Constants.ROOT_FOLDER))
		{
			MakeDirectory(EMC_Constants.ROOT_FOLDER);
			EMC_Log.Info("Created config folder: " + EMC_Constants.ROOT_FOLDER);
		}

		EMC_Config loaded = new EMC_Config();

		if (!FileExist(EMC_Constants.CONFIG_FILE))
		{
			loaded.EnsureDefaults();
			Save(loaded);
			EMC_Log.Warn("Config missing - default created at " + EMC_Constants.CONFIG_FILE);
			return loaded;
		}

		JsonFileLoader<EMC_Config>.JsonLoadFile(EMC_Constants.CONFIG_FILE, loaded);
		loaded.EnsureDefaults();
		EMC_Log.Info("Loaded config with " + loaded.Mercenaries.Count().ToString() + " mercenaries.");
		return loaded;
	}

	static void Save(EMC_Config config)
	{
		JsonFileLoader<EMC_Config>.JsonSaveFile(EMC_Constants.CONFIG_FILE, config);
	}
};

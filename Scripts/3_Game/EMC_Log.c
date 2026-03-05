class EMC_Log
{
	static void Info(string message)
	{
		Print("[EMC][INFO] " + message);
	}

	static void Warn(string message)
	{
		Print("[EMC][WARN] " + message);
	}

	static void Error(string message)
	{
		Print("[EMC][ERROR] " + message);
	}
};

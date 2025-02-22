main()
{
	print(!"_______________________________________________________ ");
	print(!" Arizona Role Play - Core succefully started..");
	print(!" Arizona RP © 2025, inc. all rights reserved.");
	print(!"_______________________________________________________ ");
}

public OnGameModeInit()
{
	new day, month, year;
	getdate(day, month, year);
	
	f(global, 64, "Build: %d.%d.%d", day, month, year);
	SetGameModeText(global);

	return 1;
}

public OnGameModeExit()
{
	return 1;
}
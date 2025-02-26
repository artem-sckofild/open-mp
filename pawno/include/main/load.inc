main()
{
	print(!"_______________________________________________________ ");
	print(!" Arizona Role Play - Core succefully started..");
	print(!" Arizona RP © 2025, inc. all rights reserved.");
	print(!"_______________________________________________________ ");
}

public OnGameModeInit()
{
	setBuildDate();
	setConnectInBD();

	return 1;
}

public OnGameModeExit()
{
	mysql_close(mysql);
	return 1;
}
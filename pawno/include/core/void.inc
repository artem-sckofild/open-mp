void:clearChatForPlayer(playerid)
    for(new i; i < 15; i++) SendClientMessage(playerid, -1, " ");

void:setBuildDate()
{
    new day, month, year;
    getdate(day, month, year);

    f(global, 64, "Build: %d.%d.%d", day, month, year);
    SetGameModeText(global);
}

void:setConnectInBD()
{
	mysql = mysql_connect("149.202.88.119", "gs281101", "k7yM9HCNozVP", "gs281101");
    if(mysql_errno(mysql) != 0) printf("MySQL error connect - Code: %d.", mysql_errno(mysql));
    else print("MySQL success connect.");
}

void:checkDifferencePlayerIp(playerid, player_ip[])
{
    new against_ip[33], difference = 0;

    foreach(new x: Player)
    {
        if(IsPlayerConnected(x))
        {
            GetPlayerIp(x, against_ip, 32);

            if(!strcmp(against_ip, player_ip)) difference++;
        }
    }

	if(difference > 3) BanEx(playerid, "InputOtherDisconnected");
}
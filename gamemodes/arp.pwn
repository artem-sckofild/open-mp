#include <core/a_samp.inc>
#include <core/define.inc>
#include <core/void.inc>


#include "main/load.inc"

stock SetSpawnInfoEx(playerid, skin, Float:x, Float:y, Float:z, Float:a)
    return SetSpawnInfo(playerid, 255, skin, x, y, z-0.4, a, 0, 0, 0, 0, 0, 0);

public OnPlayerSpawn(playerid)
{
    sendDebugMessage(playerid, "OnPlayerSpawn => has call in playerid %d", playerid);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    SetSpawnInfoEx(playerid, 100, 2859.1819, 1259.2250, 11.3906, 331.3528);
	return 1;
}

public OnPlayerConnect(playerid)
{
	SendClientMessage(playerid, COLOR_RED, !"Добро пожаловать на Arizona Role Play!");
	clearChatForPlayer(playerid);
	return 1;
}
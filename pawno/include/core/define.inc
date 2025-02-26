new global[4096], MySQL:mysql;

#define or ||
#define and &&
#define f format
#define public:%0(%1) forward%0(%1); public%0(%1)
#define sendDebugMessage(%0,%1,%2) format(global, 144, %1, %2), SendClientMessage(%0, COLOR_RED, global)
#define PN(%0) PlayerName[%0]

// dialog
stock ShowPlayerDialogEx(playerid, dialogid, style, caption[], info[], button1[], button2[])
{
	static str[100];
	str = "{BFBBBA}", strcat(str,caption);
	ShowPlayerDialog(playerid, dialogid, style, str, info, button1, button2);
	if(dialogid)  SetPVarInt(playerid, "DialogID", dialogid);
	return SetPVarInt(playerid, "DialogOpen", 1);
}

#define SPD(%0,%1,%2,%3,%4,%5,%6) ShowPlayerDialogEx(%0, %1, %2, %3, %4, %5, %6)
#define SPDF(%0,%1,%2,%3,%4,%5,%6,%7) format(global, 1024, %4,%7), ShowPlayerDialogEx(%0, %1, %2, %3, global, %5, %6)

// raknet
#define GetPlayerLauncher(%0) launcherStatus[%0]

// colors:

#define COLOR_RED 0xFF6347FF

// other work with strings

stock SetString(param_1[], param_2[], size = 300)  return strmid(param_1, param_2, 0, strlen(param_2), size); 
stock GetString(param1[],param2[]) return !strcmp(param1, param2, false);
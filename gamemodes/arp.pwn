#include <core/a_samp.inc>
#include <core/a_mysql.inc>
#include <core/foreach.inc>
#include <core/define.inc>
#include <core/global_var.inc>
#include <core/void.inc>

#include "Pawn.RakNet.inc"

#include "main/raknet/bitstream_preload.inc"
#include "main/raknet/bitstream_handler.inc"
#include "main/load.inc"
#include "main/function/func_register.inc"

#include "main/dialog_response.inc"

stock SetSpawnInfoEx(playerid, skin, Float:x, Float:y, Float:z, Float:a)
    return SetSpawnInfo(playerid, 255, skin, x, y, z-0.4, a, 0, 0, 0, 0, 0, 0);

public OnPlayerSpawn(playerid)
{
    sendDebugMessage(playerid, "OnPlayerSpawn => has call in playerid %d", playerid);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetSpawnInfo(playerid, 255, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0);
	return 1;
}

public OnPlayerConnect(playerid)
{
	GetPlayerIp(playerid, PlayerIp[playerid], 16);
	
	checkDifferencePlayerIp(playerid, PlayerIp[playerid]);
	clearChatForPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1228);

	mysql_format(mysql, global, 128, "SELECT * FROM `accounts` WHERE `NickName` = '%e' LIMIT 1;", PlayerName[playerid]);
	mysql_tquery(mysql, global, "getMysqlInfoAC", "d", playerid);

	return SendClientMessage(playerid, COLOR_RED, !"Добро пожаловать на Arizona Role Play!"), true;
}

public: getMysqlInfoAC(playerid)
{
	new bool:account = cache_num_rows() ? true:false;

	if(GetPlayerLauncher(playerid) == 2) SetPlayerCameraPos(playerid, 1770.9120, -1902.2330, 14.0240), SetPlayerCameraLookAt(playerid, 1774.7010, -1898.9810, 13.7740);
	else InterpolateCameraPos(playerid, 2172.4255, -1043.7322, 73.9263, 2172.4255, -1043.7322, 73.9263, 10000, CAMERA_CUT),
		 InterpolateCameraLookAt(playerid, 2170.4832, -1045.6545, 73.8663, 2170.4832, -1045.6545, 73.8663, 10000, CAMERA_CUT);
	
//	mysql_format(mysql, global, 150, "SELECT * FROM `banip` WHERE `IP` = '%s' LIMIT 1", PlayerIp[playerid]);
//	mysql_tquery(mysql, global, "MysqlCheckPlayerBanIP", "d", playerid);

	return showPlayerAuthorisation(playerid, 0/*GetPlayerLauncher(playerid)*/, account);
}

stock showPlayerAuthorisation(playerid, type, account)
{
	switch(type)
	{
		case 0: 
		{
			if(!account) showStageRegistration(playerid, PT[playerid][tRegStage]);
			else SPDF(playerid, 2, DIALOG_STYLE_PASSWORD, !"Авторизация", "{FFFFFF}Добро пожаловать на {EBA225}Arizona Role Play{FFFFFF}\n\n\
				Введите свой пароль\n\
				{FFFFFF}Попыток для ввода пароля: {28910B}%d", !"Принять", !"Контекст", PT[playerid][tPasswordAttemp]);
		}
	}
	return true;
}
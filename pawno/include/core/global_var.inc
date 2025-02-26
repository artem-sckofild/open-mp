// config debug
new bool:SEARCH_SYSTEM = true; 

// raknet (preload)

new launcherStatus[MAX_PLAYERS];

new 
    PlayerName[MAX_PLAYERS][MAX_PLAYER_NAME],
    PlayerIp[MAX_PLAYERS][16];

// info player ac

enum playerInfo 
{
    pRegistrationPass[33],
    pReferalNickName[24],

    pSex,
    pRace
}

enum tempPlayerInfo
{
    tRegStage,
    tPasswordAttemp
}

new 
    PI[MAX_PLAYERS][playerInfo],
    PT[MAX_PLAYERS][tempPlayerInfo];
public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	switch(rpcid)
	{
		case 25:
		{
			new JoinData[PR_JoinData];
            BS_ReadJoinServer(bs, JoinData);

			SetString(PlayerName[playerid], JoinData[PR_NickName]);
			launcherStatus[playerid] = GetString(JoinData[PR_ClientVersion], "Arizona PC") ? 1 : GetString(JoinData[PR_ClientVersion], "arizona-mobile") ? 2 : 0;
		}
	}
	return true;
}
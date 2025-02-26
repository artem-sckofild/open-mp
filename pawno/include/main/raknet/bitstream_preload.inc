
enum PR_JoinData
{
	PR_iVersion,
	PR_byteMod,
	PR_byteNicknameLen,
	PR_NickName[24],
	PR_uiClientChallengeResponse,
	PR_byteAuthKeyLen,
	PR_auth_key[50],
	PR_iClientVerLen,
	PR_ClientVersion[30]
};

stock BS_ReadJoinServer(BitStream:bs, data[PR_JoinData])
{
    BS_ReadValue(
        bs,
        PR_INT32, data[PR_iVersion],
		PR_UINT8, data[PR_byteMod],
		PR_UINT8, data[PR_byteNicknameLen],
		PR_STRING, data[PR_NickName], data[PR_byteNicknameLen],
		PR_UINT32, data[PR_uiClientChallengeResponse],
		PR_UINT8, data[PR_byteAuthKeyLen],
		PR_STRING, data[PR_auth_key], data[PR_byteAuthKeyLen],
		PR_UINT8, data[PR_iClientVerLen]
	);

	BS_ReadValue(
		bs,
		PR_STRING, data[PR_ClientVersion], (data[PR_iClientVerLen] >= 30 ? 30:data[PR_iClientVerLen]) 
	);
}

stock BS_WriteJoinServer(BitStream:bs, data[PR_JoinData])
{
    BS_WriteValue(
        bs,
        PR_INT32, data[PR_iVersion],
		PR_UINT8, data[PR_byteMod],
		PR_UINT8, data[PR_byteNicknameLen],
		PR_STRING, data[PR_NickName],
		PR_UINT32, data[PR_uiClientChallengeResponse],
		PR_UINT8, data[PR_byteAuthKeyLen],
		PR_STRING, data[PR_auth_key],
		PR_UINT8, data[PR_iClientVerLen],
		PR_STRING, data[PR_ClientVersion]
	);
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid && GetPVarInt(playerid, "DialogID") != dialogid) return false;

	static inputtextsave[256];
	global = "";

	mysql_escape_string(inputtext, inputtextsave);

	for(new i; i < strlen(inputtextsave); i++)
	{
		switch inputtextsave[i] do
		{
			case 'A'..'Z', 'a'..'z', 'À'..'ß', 'à'..'ÿ', '0'..'9', ' ', '>', '<', '(', ')', '/', '+', '-','_', '?', '!', '.', ',', '@': continue;
			default: inputtextsave[i] = ' ';
		}
	}
	
	for(new i; i < strlen(inputtextsave); i ++)
	{
		if(inputtextsave[i] == '%') inputtextsave[i] = '#';
		else if(inputtextsave[i] == '{' && inputtextsave[i+7] == '}') strdel(inputtextsave, i, i+8);
	}
	
	PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0), DeletePVar(playerid, "DialogOpen"), DeletePVar(playerid, "DialogID");
	
    if(SEARCH_SYSTEM)
        printf("[SEARCH_SYSTEM] Player %s[%i] was active in dialog number - %i on the button %i, received parameters: listitem %i, inputtext %s", PN(playerid), playerid, dialogid, response, listitem, inputtext);

    switch(dialogid)
    {
		case 1: 
		{
			if(!response) 
				return showStageRegistration(playerid, PT[playerid][tRegStage] < 0 ? 0 : PT[playerid][tRegStage]--);

			switch(PT[playerid][tRegStage])
			{
				case 0: 
				{
					if(strlen(inputtextsave) < 6 || strlen(inputtextsave) > 30 && !CheckPassword(inputtextsave))
						return showStageRegistration(playerid, 0);

					SetString(PI[playerid][pRegistrationPass], inputtextsave);
					PT[playerid][tRegStage]++, showStageRegistration(playerid, PT[playerid][tRegStage]);
				}
				case 1, 2: PI[playerid][listitem == 1 ? pSex:pRace] = listitem, PT[playerid][tRegStage]++, showStageRegistration(playerid, PT[playerid][tRegStage]);
				case 3,4,5:
				{
					if(listitem == 1 && PT[playerid][tRegStage] == 3) return PT[playerid][tRegStage]++, showStageRegistration(playerid, PT[playerid][tRegStage]);
					if(PT[playerid][tRegStage] == 4) SetString(PI[playerid][pReferalNickName], inputtextsave);
				}
			}
		}
    }
    return true;
}
stock CheckPassword(pass[])
{
	for(new i; i < strlen(pass); i++)
	{
	    if((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z') || (pass[i] >= '�' && pass[i] <= '�') || (pass[i] >= '�' && pass[i] <= '�') || (pass[i] >= '0' && pass[i] <= '9')) continue;
		else return false;
	}
	return true;
}

stock showStageRegistration(playerid, stage)
{
	switch(stage)
	{
		case 0: 
		{
			f(global, 1024, "\
                {FFFFFF}����� ����������, {205CA2}%s{FFFFFF}\n\n\
                ���� ������� {FF6347}�� ��������������� {FFFFFF}�� ����� �������.\n\
                ��� ����������� ������� ������.\n\
                �� ����� �������������� ��� ����������� �� ����� �������.\n\n\
                {BF2F2F}\t����������:\n\
                \t- ����� ������ �� 6 �� 30 ��������\n\
                \t- ������ ������ �������� �� ���� � ����\n\
                \t- ������ ������������ � ��������\n", PlayerName[playerid]);

			SPD(playerid, 1, DIALOG_STYLE_INPUT, !"{E88813}(1/4) ������", global, !"�������", !"�����");
		}
		case 1: SPD(playerid, 1, DIALOG_STYLE_LIST, !"{E88813}[2/4] �������� ��� ���", !"�������\n�������", !"�������", !"�����");
		case 2: SPD(playerid, 1, DIALOG_STYLE_LIST, !"{E88813}[3/4] �������� ���� ����", !"{FFCC99}�������\n{FFCC99}Ҹ����", !"�������", !"�����");
		case 3: SPD(playerid, 1, DIALOG_STYLE_LIST, !"[4/4] ������ �� � ��� ������?", !"������� 'Hosted'\n�� ������\n�� ��������/�������\n� ����������\n������", !"�������", !"�����");
	    case 4: SPD(playerid, 1, DIALOG_STYLE_INPUT, !"{E88813}[4/4] ������� ��� �������������?", !"{FFFFFF}������� ��� ������ ������������� ���.\n������: {E88813}Carl_Johnson\n", !"�������", !"�����");
		case 5: 
		{
			mysql_format(mysql, global, 128, "SELECT * FROM `accounts` WHERE `NickName` = '%e' LIMIT 1;", PlayerName[playerid]);
			mysql_tquery(mysql, global, "OnPlayerRegister", "d", playerid);
		}
	}
	return true;
}
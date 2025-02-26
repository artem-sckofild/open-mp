stock CheckPassword(pass[])
{
	for(new i; i < strlen(pass); i++)
	{
	    if((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z') || (pass[i] >= 'а' && pass[i] <= 'я') || (pass[i] >= 'А' && pass[i] <= 'Я') || (pass[i] >= '0' && pass[i] <= '9')) continue;
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
                {FFFFFF}Добро пожаловать, {205CA2}%s{FFFFFF}\n\n\
                Этот аккаунт {FF6347}не зарегистрирован {FFFFFF}на нашем сервере.\n\
                Для регистрации введите пароль.\n\
                Он будет использоваться для авторизации на нашем сервере.\n\n\
                {BF2F2F}\tПримечания:\n\
                \t- Длина пароля от 6 до 30 символов\n\
                \t- Пароль должен состоять из букв и цифр\n\
                \t- Пароль чувствителен к регистру\n", PlayerName[playerid]);

			SPD(playerid, 1, DIALOG_STYLE_INPUT, !"{E88813}(1/4) Пароль", global, !"Принять", !"Выход");
		}
		case 1: SPD(playerid, 1, DIALOG_STYLE_LIST, !"{E88813}[2/4] Выберите ваш пол", !"Мужчина\nЖенщина", !"Принять", !"Выход");
		case 2: SPD(playerid, 1, DIALOG_STYLE_LIST, !"{E88813}[3/4] Выберите цвет кожи", !"{FFCC99}Светлый\n{FFCC99}Тёмный", !"Принять", !"Выход");
		case 3: SPD(playerid, 1, DIALOG_STYLE_LIST, !"[4/4] Откуда вы о нас узнали?", !"Вкладка 'Hosted'\nОт друзей\nНа порталах/форумах\nВ поисковике\nДругое", !"Принять", !"Выход");
	    case 4: SPD(playerid, 1, DIALOG_STYLE_INPUT, !"{E88813}[4/4] Введите ник пригласившего?", !"{FFFFFF}Введите ник игрока пригласившего вас.\nПример: {E88813}Carl_Johnson\n", !"Принять", !"Выход");
		case 5: 
		{
			mysql_format(mysql, global, 128, "SELECT * FROM `accounts` WHERE `NickName` = '%e' LIMIT 1;", PlayerName[playerid]);
			mysql_tquery(mysql, global, "OnPlayerRegister", "d", playerid);
		}
	}
	return true;
}
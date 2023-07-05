/*            *
 * DOBRODOSLI NAM NA...       *
 * ------------- Nova Era RolePlay!
 *       *       =====================
 *____________________________________*
 *                             *
 * Verzija: 2.4    *
 *                             *
 * Developer: DentisT_and_Brace
 *               *
 * Zadnji update: 22.01.2021      *
 *
 * Mapper: Mata | Vlasnik: Makso          *
 *                   *
 */


#define task%0[%1](%2) %0(%2);public %0(%2)
#define NERP_TIMER(%1,%2,%3$%4); if(timerid==%4){printf("\tUcitavanje timera: "%1"\t\nTick rate: %i",GetServerTickRate());CallLocalFunction(%1,"");SetTimer(%1,%2,%3);return 1;}


KreirajTajmere(timerid); public KreirajTajmere(timerid)
{
	#if NERP_LOAD_TIMERS == 1
	NERP_TIMER("T_Spectator"					,3000			,true$1);
	NERP_TIMER("T_EventTimeR"					,1050			,true$2);
	NERP_TIMER("T_PetnesTMinutesTimer"			,900000			,true$3);
	NERP_TIMER("T_OcistiChatNeulogovanim"		,100			,true$4);
	NERP_TIMER("T_FiveMinutesTimer"				,420000			,true$5);
	NERP_TIMER("T_SyncTime"						,60000			,true$6);
	NERP_TIMER("MISSION"						,3600000		,true$7);
	NERP_TIMER("NeaktivnostDodavanje2"			,3600000		,true$8);

	NERP_TIMER("ServerTimer"					,1000			,true$9);

	NERP_TIMER("VehRespawntask"					,2000000		,true$10);
	NERP_TIMER("TaskSendMSG"					,300000			,true$11);
	NERP_TIMER("TaskSendMSG2"					,600000			,true$12);
	NERP_TIMER("TaskSendMSG3"					,400000			,true$13);
	NERP_TIMER("TaskSendMSG4"					,1200000		,true$14);
	NERP_TIMER("TaskSendMSG5"					,195000			,true$15);
	NERP_TIMER("ObavjestiIgraceTask"			,1800000		,true$16);
	NERP_TIMER("SwapBarCol"						,1000			,true$17);
	NERP_TIMER("TaskAktivirajPoklone"			,100000			,true$18);
	NERP_TIMER("LoadingTimerTacketask"			,500			,true$19);
	NERP_TIMER("FixDealerstask"					,1200000		,true$20);
	NERP_TIMER("ZOMBIE_UPDATE"					,500			,true$21);
	NERP_TIMER("ZOMBIE_SPAWN"					,4000			,true$22);
	NERP_TIMER("ZOMBIE_POS"						,10000			,true$23);
	NERP_TIMER("ZOMBIE_GAME"					,800			,true$24);

	NERP_TIMER("BrziTajmerTask"					,150			,true$25);

	NERP_TIMER("RDYBLINKtimer"					,500			,true$26);
	NERP_TIMER("betaprovera"					,900000			,true$27);
	NERP_TIMER("NewHappyJob"					,3600000		,true$28);
	NERP_TIMER("PonovnoUcitavanjeTela"			,600000			,true$29);
	NERP_TIMER("PetSec"							,5000			,true$30);
	NERP_TIMER("PolaMinuteTimer"				,30000			,true$31);
	NERP_TIMER("LoadDealers"					,1400			,true$32);
	NERP_TIMER("DostavaVozila"					,625726			,true$33);
	
	NERP_TIMER("vrijeme"						,1500			,true$34);
	NERP_TIMER("SetPlayerTitle"					,5000			,true$35);
	NERP_TIMER("updateMoneyBar"					,2000			,true$36);
	NERP_TIMER("PreviewItemForPlayer"			,600			,true$37);
	NERP_TIMER("InternetConnectionCheck"		,2500			,true$38);
	
	#endif
	return 1;
}

task LoadDealers[1400]()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		for( new b = 0; b < MAX_DEALERS; b++ )
		{
	        if( IsPlayerInRangeOfPoint( i, 20.0, DealerInfo[b][dealerPos][0],DealerInfo[b][dealerPos][1],DealerInfo[b][dealerPos][2] ) )
	        {
	        	Dileri3D(b, false, i);
	        }
		}
	}
	return 1;
}

task vrijeme[1500]() 
{
	//print("Timer 'vrijeme' was called.");
	new tmphour,
		tmpminute,
		tmpsecond,
		year,
		month,
		day,
		stringicc[ 20 ],stringicc1[ 30 ];

    getdate( year, month, day );
	gettimeEx( tmphour, tmpminute, tmpsecond );
	FixHour( tmphour );
	tmphour = shifthour;

    format( stringicc, sizeof( stringicc ), "~w~%s%d~y~:~w~%s%d", (tmphour < 10) ? ("0") : (""), tmphour, (tmpminute < 10) ? ("0") : (""), tmpminute);
	TextDrawSetString( TDEditor_TD[35], stringicc );
 	format( stringicc1, sizeof( stringicc1 ), "~w~%d~r~/~w~%d~r~/~w~%d", day, month, year );
    TextDrawSetString( TDEditor_TD[36], stringicc1 );
    return 1;
}

task T_Spectator[2000]()
{
	Spectator();
	return 1;
}

task T_EventTimeR[1000]()
{
	EventTimeR();
	return 1;
}

task T_PetnesTMinutesTimer[900000]()
{
	PetnesTMinutesTimer();
	return 1;
}

task T_OcistiChatNeulogovanim[100]()
{
	OcistiChatNeulogovanim();
	return 1;
}

task T_FiveMinutesTimer[420000]()
{
	FiveMinutesTimer();
	return 1;
}

task T_SyncTime[60000]()
{
	SyncTime();
	return 1;
}

task MISSION[3600000]()
{
	Misija();
	return 1;
}

task NeaktivnostDodavanje2[3600000]()
{
	NeaktivnostDodavanje();
	return 1;
}

task ServerTimer[1000]()
{
	GlobalTimer();
	return 1;
}

task VehRespawntask[2000000]()
{
	VehRespawn();
	return 1;
}

task TaskSendMSG[300000]()
{
	SendMSG();
	return 1;
}

task TaskSendMSG2[600000]()
{
	SendMSG2();
	return 1;
}

task TaskSendMSG3[400000]()
{
	SendMSG3();
	return 1;
}

task TaskSendMSG4[1200000]()
{
	SendMSG4();
	return 1;
}

task TaskSendMSG5[195000]()
{
	SendMSG5();
	return 1;
}

task ObavjestiIgraceTask[1800000]()
{
	#if NERP_DISCORD_BOT == 1
	ObavjestiIgrace();
	#endif
	return 1;
}

task SwapBarCol[1000]()
{
	SwapModernTextDrawBarColors();
	return 1;
}

task TaskAktivirajPoklone[100000]()
{
	AktivirajPoklone();
	return 1;
}

task LoadingTimerTacketask[500]()
{
	LoadingTimerTacke();
	return 1;
}

task FixDealerstask[1200000]()
{
	FixDealers();
	return 1;
}

#if NERP_ZOMBIE_SISTEM == 1

task ZOMBIE_UPDATE[500]()
{
	zombieUpdate();
	return 1;
}

task ZOMBIE_SPAWN[3000]()
{
	zombieSpawn();
	return 1;
}

task ZOMBIE_POS[10000]()
{
	UpdateZombiePos();
	return 1;
}

task ZOMBIE_GAME[100]()
{
	zombieGame();
	return 1;
}

#endif

task BrziTajmerTask[200]()
{
	BrziTajmer();
	return 1;
}

task RDYBLINKtimer[500]()
{
	RDYBLINK();
	return 1;
}

task betaprovera[900000]()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && PlayerLogged[i])
		{
			//ShowPlayerDialog(i,dialog_BETA,DSI,"Nova Era | Beta test - vase iskustvo","Postovanje i pozdrav.\n\nUpamtite da trenutno igrate na BETA verziji igre.\nTrenutna verzija ne reprezentira konacne rezultate.\n\nSa obzirom da nam je stalo do vasih performansi tokom \nigre na nasem serveru, zelimo cuti Vase povrate informacije o\nVasem iskustvu tokom igre na ovoj beta verziji.\n\nHvala Vam sto ste beta tester ove zajednice,\ni sto pomazete da ucinimo ovaj server zabavnijim i kvalitetnijim.","Unesi","Izlaz");
			SendInfoMessage(i,"Povratne informacije mozete slati kada god zelite komandom: /betainfo");
		}
	}
	return 1;
}

task NewHappyJob[3600000]()
{
	new happyjobid = random(MAX_JOBS);
	HappyJobID = happyjobid;

	new happyjobannouncement[300];
	format(happyjobannouncement, \
	sizeof(happyjobannouncement), \
	""col_balkanstory"[ SRECNE PLATE ]{ffffff}: Trenutno su ukljucene duple plate na poslu "col_balkanstory"%s{ffffff}.",GetJobName(happyjobid));
	return 1;
}

task PonovnoUcitavanjeTela[600000]()
{
	SCMA(-1,""SERVERBOJA_CRVENA"[ VOICE CHAT ] Brza i jednostavna instalacija na linku - {ffffff}/forum"SERVERBOJA_CRVENA"!");
	for( new ko = 1; ko < MAX_BODIES; ko++ )
	{
 		new bodyFile[ 50 ];

	    format( bodyFile, sizeof( bodyFile ), BODY_FILE, ko );
	    //new koFile = bodyFile;
	    if( fexist( bodyFile ) )
		{
		    if( IsValidDynamic3DTextLabel( bodyInfo[ko][bodyText3D] ) )
				DestroyDynamic3DTextLabel( bodyInfo[ko][bodyText3D] );
				
	        INI_ParseFile( bodyFile, "OcitajMrtvoTelo", .bExtra = true, .extra = ko );

			new deadbody_text_label[500];
			//format(deadbody_text_label,sizeof(deadbody_text_label),
			//""col_balkanstory"|| DEATHPOINT IGRACA - Mrtvo tijelo: %d ||\n\n
			//{FFFFFF}Ovo mrtvo nije sveze i zastarelo je, "col_balkanstory"nije 
			//moguce identificirati igraca!\n(("SERVERBOJA_SIVA" Ovaj igrac je ubijen - 
			//ovo je njegovo mrtvo tijelo,\nda prijavite zlocin, pozovite policiju!"
			//col_balkanstory" ))\n\n|| Admin nivo 1337+ moze ocistiti tijela na serveru, 
			//komanda: /ddt,\nukoliko radite poslovnu misiju grobar, kucajte: /pokupitelo ||", ko);
			format(deadbody_text_label,sizeof(deadbody_text_label),
				""col_balkanstory"[MRTVO TELO >> ID - %i]\n\n{ffffff}Ovo telo je zastarelo i\nnije sveze.\nIz tog razloga nije moguce\nidentificirati mrtvaca.\n\n[/ddt, /pokupitelo]",ko);
			bodyInfo[ko][bodyText3D] = CreateDynamic3DTextLabel( deadbody_text_label, -1, bodyInfo[ ko ][bodyObjPos][0], bodyInfo[ ko ][bodyObjPos][1], bodyInfo[ ko ][bodyObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
		}
	}
	SCMA(-1,""col_sanm"[ SERVER ]:"SERVERBOJA_SIVA" Mrtva tijela na serveru su ozvjezena u databazi - sada nije moguce identificirati tijela!");
	return 1;
}

task PetSec[5000]()
{
	new online[50];
	format(online,sizeof(online),"ONLINE:~n~%d",ServerInfo[Online]);
	TextDrawSetString(TDEditor_TD[47],online);
	//TextDrawSetString(moderntds[8],online);
    TextDrawSetString(TDEditor_TD[45], DailyTips[random(sizeof(DailyTips))]);

    return 1;
}

task PolaMinuteTimer[30000]()
{
	// novi kurac uradjen update
    new leveligracaq[50];
    format(leveligracaq,sizeof(leveligracaq),"REKORD: %d",ServerInfo[RekordServera]);
	TextDrawSetString(TDEditor_TD[39],leveligracaq);
	//TextDrawSetString(moderntds[14],leveligracaq);
	TextDrawSetString(TDEditor_TD[43], PromenjljivePoruke[random(sizeof(PromenjljivePoruke))]);
	//TextDrawSetString(moderntds[6], PromenjljivePoruke[random(sizeof(PromenjljivePoruke))]);
	/*for(new i; i < MAX_PLAYERS; i++)
	{
	    new leveligraca[50];
	    format(leveligraca,sizeof(leveligraca),"LEVEL: %d",PlayerInfo[i][xLevel]);
		TextDrawSetString(TDEditor_TD[45],leveligraca);
	}*/
	return 1;
}

task srwname[1000]()
{
	new num = random(7);
	switch(num) 
	{
	    case 0: {
	        SendRconCommand( "hostname :[NE-RP]:- Nova Era - || www.NE-ogc.com || " );
	        SetGameModeText( "-= |NE:RP~"NERP_VERZIJA"| =-" );
		}
		case 1: {
		    SendRconCommand( "hostname :[NE-RP]:- Dobro nam dosli! - || Hvala! <3 ||  " );
	        SetGameModeText( "-= |by DEntisT| =-" );
		}
		case 2: {
			SendRconCommand( "hostname :[NE-RP]:- Uzivajte u igri! - || Vas STAFF. || " );
	        SetGameModeText( "-= |NE:RP~"NERP_VERZIJA"| =-" );
		}
		case 3: {
		    SendRconCommand( "hostname :[NE-RP]:~| Eventi, nagrade i jos mnogo toga! | " );
	        SetGameModeText( "-= |by DEntisT| =-" );
		}
		case 4: {
		    SendRconCommand( "hostname :[NE-RP]:~| Live eventi i saloni - otvoreno! |");
		    SetGameModeText( "NE-RP | Izvori: Skopsi" );
		}
		case 5: {
			SetGameModeText( "NE:RP - Version: beta" );
		}
		#if NERP_ZIMSKI_MOD == 1
		case 6: {
			SetGameModeText("NE:RP - Winter Edition");
		}
		#endif
	}
	return 1;
}

task DostavaVozila[600000]()
{
	//SCMA(-1,""SERVERBOJA_CRVENA"");
	SCMA(-1,""SERVERBOJA_CRVENA"[KONKURSI] Konkursi za Admina, GMa i Promotera na - {ffffff}/forum"SERVERBOJA_CRVENA"!");
	//SCMA(-1,""SERVERBOJA_CRVENA"");
	if(ServerInfo[VoziloDostavljeno] == false ) 
	{
		for(new i; i < MAX_PLAYERS; i++) {
		    notfi(i,"Dojava","Automobil za preradu je dostavljen na tajnu lokaciju!");
		}
		ServerInfo[VoziloDostavljeno] = true;
		return 1;
	}
	else if(ServerInfo[VoziloDostavljeno] == true ) 
	{
	    for(new i; i < MAX_PLAYERS; i++) {
		    notfi(i,"Kamera","Automobil za preradu je neko ukrao, sacekajte dostavu novog vozila!");
		    notfi(i,"Dojava","Vozilo ce biti dostavljeno za 10 minuta...");
		}
		ServerInfo[VoziloDostavljeno] = false;
		return 1;
	}
	//konkursi
	return 0;
}

task SetPlayerTitle[2000]()
{
	//print("Timer 'SetPlayerTitle' was called.");
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(!IsPlayerConnected(playerid)) continue;
		if( NaDmEventu[ playerid ] == false && WARPInfo[ playerid ][ WARIgrac ] == -1 && Ranjen[playerid] == 0 )
		{
			if( PlayerInfo[playerid][xAdmin] == 0 && \
				PlayerInfo[playerid][xHelper] == 0 && \
				PlayerInfo[playerid][xClan] == 0 && \
				PlayerInfo[playerid][xLevel] >= 5 && \
				PlayerInfo[playerid][xProperty][0] == -1 &&\
				PlayerInfo[playerid][xProperty][1] == -1 &&\
				PlayerInfo[playerid][xProperty][2] == -1
			)
			{
				SetPlayerChatBubble( playerid, "[ BESKUCNIK ]", PLAVA, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
	        else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 1 && AdminDuty[playerid])
			{
				SetPlayerChatBubble( playerid, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 1 && !AdminDuty[playerid])
			{
				SetPlayerChatBubble( playerid, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 2 )
			{
				SetPlayerChatBubble( playerid, "[ DIZAJNER ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xVIPLevel ] == 5  )
			{
				SetPlayerChatBubble( playerid, "[ MASTER DONATOR ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 1 && AdminDuty[playerid])
			{
				SetPlayerChatBubble( playerid, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 1 && !AdminDuty[playerid])
			{
				SetPlayerChatBubble( playerid, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 3 )
			{
				SetPlayerChatBubble( playerid, "[ MAPPER ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xSkriptaRank ] == 6 )
			{
				SetPlayerChatBubble( playerid, "[ SU-VLASNIK ]", tdboja, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ playerid ][ xAdmin ] >= 1 && PlayerInfo[ playerid ][ xAdmin ] <= 5 )
			{
				SetPlayerChatBubble( playerid, "[ ADMIN ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xAdmin ] == 6 )
			{
				SetPlayerChatBubble( playerid, "[ HEAD ADMIN ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xAdmin ] == 1337 )
			{
				SetPlayerChatBubble( playerid, "[ DIREKTOR ]", tdboja, 40.0, 10000);
			}
			
	        else if( PlayerInfo[ playerid ][ xAdmin ] == 1339)
			{
				SetPlayerChatBubble( playerid, "[ VLASNIK ]", tdboja, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ playerid ][ xHelper ] >= 1 && PlayerInfo[ playerid ][ xHelper ] <= 3)
			{
				SetPlayerChatBubble( playerid, "[ GameMaster ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xHelper ] == 4 )
			{
				SetPlayerChatBubble( playerid, "[ Vodja GameMastera ]", tdboja, 40.0, 10000);
			}

			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ playerid ][ xVIPLevel ] >= 1 && PlayerInfo[ playerid ][ xWanted ] == 0 )
			{
			
				SetPlayerChatBubble( playerid, "[ Prime Member ]", tdboja, 40.0, 10000);
				
				/*if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 && !PlayerInfo[ playerid ][ xDBO ] )
				{
	   				SetPlayerColor( playerid, 0xB7B700FF );
				}*/
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ playerid ][ xPromoter ] == 1 )
			{
				SetPlayerChatBubble( playerid, "[ Promoter ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ playerid ][ xLevel ] == 1  )
			{
				SetPlayerChatBubble( playerid, "[ Pocetnik ]", PLAVA, 40.0, 10000);
			}
		}
	}
	return 1;
}


NERP_ONPLAYERUPDATE(playerid);
public NERP_ONPLAYERUPDATE(playerid)
{
	//if(GetServerTickRate() < 130) print("Timer 'NERP_ONPLAYERUPDATE' was called.");
	CallLocalFunction("SelectTextdrawSys", "i", playerid);
	
		
	if( Ranjen[playerid] == 1)
	{
		SetPlayerChatBubble( playerid, "(( Ovaj igrac je trenutno ranjen... Umire tacno za 20 sekundi! - /pomozi ))", PLAVA, 40.0, 10000);
	}


	new text[128];
	format(text, sizeof text, "Tick rate servera: %i", GetServerTickRate());
	announcement(playerid,text);


	if(PlayerLogged[playerid] == true && ClientType[playerid] == CLIENT_PC)
	{
		PlayerTextDrawShow(pid,MoneyBar[pid]);
	}

	return 1;
}


task PreviewItemForPlayer[600]()
{
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(!IsPlayerConnected(playerid)) continue;
		new weapon_found = -1;
		for( new a = 0; a < MAX_GOBJ; a++ )
		{
			if( IsPlayerInRangeOfPoint( playerid, 2.0, dGunData[ a ][ ObjPos ][ 0 ], dGunData[ a ][ ObjPos ][ 1 ], dGunData[ a ][ ObjPos ][ 2 ] ) )
			{
				if(PlayerInfo[playerid][xPUBG] == 1)
				{
					if(dGunData[a][PUBG] == 0) weapon_found = -1;
					else if(dGunData[a][PUBG] == 1) weapon_found = a;
				}
				else if(PlayerInfo[playerid][xPUBG] == 0)
				{
					weapon_found = a;
				}
			    break;
			}
		}
		if(weapon_found == -1)
		{
			if(ItemNearbyShowed[playerid])
			{
				ShowPlayerNearbyItem(playerid, false);
			}
		}
		if(weapon_found != -1)
		{
			if(!ItemNearbyShowed[playerid])
			{
				new found_weaponid = dGunData[ weapon_found ][ ObjData ][ 0 ];

				ShowPlayerNearbyItem(playerid, true,WeaponInfos[ found_weaponid ][ wTXDName ],WeaponInfos[ found_weaponid ][ wName ],WeaponInfos[ found_weaponid ][ wAmmoName ],dGunData[ weapon_found ][ ObjData ][ 1 ]);
			}
		}
	}
	return 1;
}


task InternetConnectionCheck[2500]()
{
	//print("Timer 'InternetConnectionCheck' was called.");
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(!IsPlayerConnected(playerid)) continue;
		if(WifiConnectionTDShowed[playerid])
		{
			if(GetPlayerPing(playerid) > 100)
			{
				SendScreenMessage(playerid, "Imate probleme sa internetom, molimo sacekajte!");
			}
			WifiConnectionTDControl(playerid, false);

			if(GetPlayerPing(playerid) <= 300 || GetPlayerPing(playerid) > 300)
			{
				PlayerTextDrawColor(playerid, WifiConnection[1][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[2][playerid], SIVA);
				PlayerTextDrawColor(playerid, WifiConnection[3][playerid], SIVA);
				PlayerTextDrawColor(playerid, WifiConnection[4][playerid], SIVA);
			}
			if(GetPlayerPing(playerid) <= 200)
			{
				PlayerTextDrawColor(playerid, WifiConnection[1][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[2][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[3][playerid], SIVA);
				PlayerTextDrawColor(playerid, WifiConnection[4][playerid], SIVA);
			}
			if(GetPlayerPing(playerid) <= 120)
			{
				PlayerTextDrawColor(playerid, WifiConnection[1][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[2][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[3][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[4][playerid], SIVA);
			}
			if(GetPlayerPing(playerid) <= 50)
			{
				PlayerTextDrawColor(playerid, WifiConnection[1][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[2][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[3][playerid], tdboja);
				PlayerTextDrawColor(playerid, WifiConnection[4][playerid], tdboja);
			}

			WifiConnectionTDControl(playerid, true);

			new ping[20];
			format(ping,sizeof ping,"%i ms", GetPlayerPing(playerid));
			PlayerTextDrawSetString(playerid, WifiConnection[5][playerid], ping);
		}
	}
}

task UpdatePlayer[3000]()
{
	//print("Timer 'UpdatePlayer' was called.");
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(!IsPlayerConnected(playerid)) continue;
		new igra[10], kills[10];
		format(igra,10,"%i", PUBGenum[xCekaIgraca] + PUBGenum[xIgraMatch]);

		if(PlayerInfo[playerid][xPUBG] == 1)
		{
			TextDrawSetString(PubgEventTd[5], igra);

			format(kills,10,"%i", PlayerInfo[playerid][xPUBGKills]);
			PlayerTextDrawSetString(playerid, PubgEventKills[playerid], kills);
		}
		if(PUBGTDShowed[playerid])
		{
			PlayerTextDrawHide(playerid,PUBGTextdraw[2][playerid]);
			PlayerTextDrawSetPreviewModel(playerid,PUBGTextdraw[2][playerid],PlayerInfo[playerid][xSkin]);
			PlayerTextDrawShow(playerid,PUBGTextdraw[2][playerid]);
		}
		if(!PUBGTDShowed[playerid])
		{
			PlayerTextDrawHide(playerid,PUBGTextdraw[2][playerid]);
		}
		
		if(!StatsTDShowed[playerid])
		{
			PlayerTextDrawHide(playerid, SkinIgraca[playerid]);
		}

		if(PlayerLogged[playerid]) LoginTDControl(playerid, false);

		if(PlayerInfo[playerid][xPUBG] == 0)
		{
			PubgEventTDControl(playerid, false);
		}

		if(PlayerInfo[playerid][xPUBG] == 1)
		{
			PubgEventTDControl(playerid, false);
			PubgEventTDControl(playerid, true);
		}
	}
	return 1;
}

UpdateOdjecaModels(playerid);
public UpdateOdjecaModels(playerid)
{
	if(OdjecaTDShowed[playerid])
	{
		PlayerTextDrawHide(playerid, OdjecaTextdraw[10][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[11][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[12][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[13][playerid]);

		if(PlayerInfo[playerid][xHead] != 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[10][playerid], 0.0, -90.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[10][playerid],PlayerInfo[playerid][xHead]);
		}
		if(PlayerInfo[playerid][xSungMask] != 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[11][playerid], 0.0, 0.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[11][playerid],PlayerInfo[playerid][xSungMask]);
		}
		if(PlayerInfo[playerid][xFace] != 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[12][playerid], 0.0, -90.0, 0.0, 1.0);			
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[12][playerid],PlayerInfo[playerid][xFace]);
		}
		if(PlayerInfo[playerid][xPapagaj] != 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[13][playerid], 0.0, -90.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[13][playerid],19078);
		}


		if(PlayerInfo[playerid][xHead] == 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[10][playerid], 0.0, 0.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[10][playerid],18631);
		}
		if(PlayerInfo[playerid][xSungMask] == 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[11][playerid], 0.0, 0.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[11][playerid],18631);
		}
		if(PlayerInfo[playerid][xFace] == 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[12][playerid], 0.0, 0.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[12][playerid],18631);
		}
		if(PlayerInfo[playerid][xPapagaj] == 0)
		{
			PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[13][playerid], 0.0, 0.0, 0.0, 1.0);
			PlayerTextDrawSetPreviewModel(playerid,OdjecaTextdraw[13][playerid],18631);
		}

		PlayerTextDrawShow(playerid, OdjecaTextdraw[10][playerid]);
		PlayerTextDrawShow(playerid, OdjecaTextdraw[11][playerid]);
		PlayerTextDrawShow(playerid, OdjecaTextdraw[12][playerid]);
		PlayerTextDrawShow(playerid, OdjecaTextdraw[13][playerid]);
	}
	if(!OdjecaTDShowed[playerid])
	{
		PlayerTextDrawHide(playerid, OdjecaTextdraw[10][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[11][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[12][playerid]);
		PlayerTextDrawHide(playerid, OdjecaTextdraw[13][playerid]);
		OdjecaTDControl(playerid, false);
	}
	return 1;
}

task updateMoneyBar[2000]()
{
	//print("Timer 'updateMoneyBar' was called.");
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if(!IsPlayerConnected(playerid)) continue;
		if( PlayerLogged[ playerid ] == true && ClientType[playerid] == CLIENT_PC)
		{

			PlayerTextDrawShow(playerid,MoneyBar[playerid]);
			new moneybarstring[20];

			if(PlayerInfo[ playerid ][ xNovac ] >= 0 && PlayerInfo[ playerid ][ xNovac ] < 10)
			{
				format(moneybarstring, 20, "$00000000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 10 && PlayerInfo[ playerid ][ xNovac ] < 100)
			{
				format(moneybarstring, 20, "$0000000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 100 && PlayerInfo[ playerid ][ xNovac ] < 1000)
			{
				format(moneybarstring, 20, "$000000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 1000 && PlayerInfo[ playerid ][ xNovac ] < 10000)
			{
				format(moneybarstring, 20, "$00000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 10000 && PlayerInfo[ playerid ][ xNovac ] < 100000)
			{
				format(moneybarstring, 20, "$0000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 100000 && PlayerInfo[ playerid ][ xNovac ] < 1000000)
			{
				format(moneybarstring, 20, "$000%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 1000000 && PlayerInfo[ playerid ][ xNovac ] < 10000000)
			{
				format(moneybarstring, 20, "$00%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 10000000 && PlayerInfo[ playerid ][ xNovac ] < 100000000)
			{
				format(moneybarstring, 20, "$0%i", PlayerInfo[ playerid ][ xNovac ]);
			}
			if(PlayerInfo[ playerid ][ xNovac ] >= 100000000 && PlayerInfo[ playerid ][ xNovac ] < 999999999)
			{
				format(moneybarstring, 20, "$%i", PlayerInfo[ playerid ][ xNovac ]);
			}

			PlayerTextDrawSetString( playerid, MoneyBar[ playerid ], moneybarstring );
		}
	}
	return 1;
}
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


#include <YSI\y_timers>

stock KreirajTajmere()
{
	print("Timeri kreirani.");

	SendRconCommand("password 0");
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
	ObavjestiIgrace();
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

task ZOMBIE_UPDATE[100]()
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

task ZOMBIE_GAME[500]()
{
	zombieGame();
	return 1;
}

task BrziTajmerTask[100]()
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
	""col_balkanstory"[ SRECNE PLATE ]{ffffff}: Trenutno su ukljucene duple plate na poslu "col_balkanstory"%s{ffffff}.", \
	GetJobName(happyjobid));
	return 1;
}

task PonovnoUcitavanjeTela[600000]()
{

	SCMA(-1,""SERVERBOJA_CRVENA"[VOICE CHAT] Brza i jednostavna instalacija na linku - {ffffff}/forum"SERVERBOJA_CRVENA"!");
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
	switch(num) {
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
		case 6: {
			SetGameModeText("NE:RP - Winter Edition");
		}
	}
	return 1;
}

task DostavaVozila[600000]()
{
	//SCMA(-1,""SERVERBOJA_CRVENA"");
	SCMA(-1,""SERVERBOJA_CRVENA"[KONKURSI] Konkursi za Admina, GMa i Promotera na - {ffffff}/forum"SERVERBOJA_CRVENA"!");
	//SCMA(-1,""SERVERBOJA_CRVENA"");
	if(ServerInfo[VoziloDostavljeno] == false ) {
		for(new i; i < MAX_PLAYERS; i++) {
		    notfi(i,"Dojava","Automobil za preradu je dostavljen na tajnu lokaciju!");
		}
		ServerInfo[VoziloDostavljeno] = true;
		return 1;
	}
	else if(ServerInfo[VoziloDostavljeno] == true ) {
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
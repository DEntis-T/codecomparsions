#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif

AntiDeAMX()
{
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a
}

UcitavanjeModa(componentid);
public UcitavanjeModa(componentid)
{
	if(componentid == 1)
	{
		CreateMapObjects();
		SetTimerEx("UcitavanjeModa", 5000, false, "i", 2);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje mape...");
	}
	if(componentid == 2)
	{
		CallLocalFunction("LoadScriptfiles", "");
		SetTimerEx("UcitavanjeModa", 10000, false, "i", 3);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje scriptfiles...");
	}
	if(componentid == 3)
	{
		LoadVehicles( );
		SetTimerEx("UcitavanjeModa", 10000, false, "i", 4);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje vozila...");
	}
	if(componentid == 4)
	{
		CreateMapIcons( );
		SetTimerEx("UcitavanjeModa", 5000, false, "i", 5);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje ikona mape...");
	}
	if(componentid == 5)
	{
		CreateTextDraws( );
		SetTimerEx("UcitavanjeModa", 10000, false, "i", 6);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje textdrawa...");
	}
	if(componentid == 6)
	{
		CallLocalFunction("DefineGatesAndDoors", "");
		SetTimerEx("UcitavanjeModa", 5000, false, "i", 7);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje vrata i kapija...");
	}
	if(componentid == 7)
	{
		CreatePickupsAnd3Ds( );
		SetTimerEx("UcitavanjeModa", 5000, false, "i", 8);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje labela i pickupa...");
	}
	if(componentid == 8)
	{
		ResetAllFarmPlants();
		EnableStuntBonusForAll( 0 );
		DisableInteriorEnterExits( );
		ManualVehicleEngineAndLights( );
		AllowInteriorWeapons( 1 );
		ShowPlayerMarkers( 0 );
		printf("[NE:RP] - Nova Era | Postavljanje dodatnih podesavanja je zapoceto!");
		SetTimerEx("UcitavanjeModa", 10000, false, "i", 9);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje ostalih stvari...");
	}
	if(componentid == 9)
	{
		SetTimer("KreirajTajmereSistem", 100, false);
		SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje tajmera...");
		SetTimerEx("UcitavanjeModa", 5000, false, "i", 10);
	}
	if(componentid == 10)
	{
		print("NERP: Sve je spremno");
		SetTimer("srwname"						,3000			,true);
		SendRconCommand("password 0");
	}
	return 1;
}

KreirajTajmereSistem(); public KreirajTajmereSistem()
{
	new interval = 1;
	for(new i; i < 40; i++)
	{
		interval=interval+1;
		SetTimerEx("KreirajTajmere", interval, false, "i", i);
	}
	return 1;
}

public OnGameModeInit( )
{
	//SetTimer("CheckTickRate", 300, true);
	new gminit_debug = 1;
	//ConnectNPC("Administrator", "admin_nerp");
	new NERP_ANIMACIJE = 1;
	////////
	ServerInfo[Online] = 0;
	ServerInfo[Reklamiranje] = 0;
	ServerInfo[PreuzetoGrobarVoziilo] = false;
	//SetGameModeText( VERZIJA_MODA );
	//SendRconCommand( "language "MAP_NAME"" );
	//SetGameModeText( "-= BS|v0.1|DEntisT =-" );
	SendRconCommand( "language Balkanski" );
	//SendRconCommand( "hostname :[NE-RP]:- Nova Era - || www.NE-ogc.com ||" );
	SendRconCommand( "mapname Balkan" );

	//ulaz u sef
	new 
		wall_obj = 19367,
		Float:wall_x = 1468.135742,
		Float:wall_y = -986.855041,
		Float:wall_z = 2059.820556,
		Float:wall_ax = 0.000000,
		Float:wall_ay = 0.000000,
		Float:wall_az = 90.000000;
	CreateDynamicObject( wall_obj, wall_x, wall_y, wall_z, wall_ax, wall_ay, wall_az );

	ServerInfo[ HangarPaket ] = true;
	
	#if NERP_ZIMSKI_MOD  == 1
	SetWeather( 38 );
	GlobalnoVrijeme = 38;
	ServerInfo[ Prognozasys ] = 38;
	#else
	ServerInfo[ Prognozasys ] = 10;
	SetWeather( 10 );
	GlobalnoVrijeme = 10;
	#endif

	MapAndreas_Init( MAP_ANDREAS_MODE_FULL );
	SendRconCommand( "hostname [NE-RP] Nova Era - Server se pokrece..." );
	SendRconCommand("password NERP_ROLEPLAY_INIT");
	SetTimerEx("UcitavanjeModa", 2000, false, "i", 1);
	

	//-----------------------------------------------------------------------------------
	new Float:Y = 350.0;

	Box = CreateBox(194.0,Y-20,3*64.0 + 3*20,84,0x00000077);

	// Cherries (x25)
	Digit1[ 0 ] = CreateSprite(214.0,Y,"LD_SLOT:cherry",64,64);
	Digit2[ 0 ] = CreateSprite(288.0,Y,"LD_SLOT:cherry",64,64);
	Digit3[ 0 ] = CreateSprite(362.0,Y,"LD_SLOT:cherry",64,64);

	// grapes (x100)
	Digit1[ 1 ] = CreateSprite(214.0,Y,"LD_SLOT:grapes",64,64);
	Digit2[ 1 ] = CreateSprite(288.0,Y,"LD_SLOT:grapes",64,64);
	Digit3[ 1 ] = CreateSprite(362.0,Y,"LD_SLOT:grapes",64,64);

	// 69's (x250)
	Digit1[ 2 ] = CreateSprite(214.0,Y,"LD_SLOT:r_69",64,64);
	Digit2[ 2 ] = CreateSprite(288.0,Y,"LD_SLOT:r_69",64,64);
	Digit3[ 2 ] = CreateSprite(362.0,Y,"LD_SLOT:r_69",64,64);

	// bells (x500)
	Digit1[3] = CreateSprite(214.0,Y,"LD_SLOT:bell",64,64);
	Digit2[3] = CreateSprite(288.0,Y,"LD_SLOT:bell",64,64);
	Digit3[3] = CreateSprite(362.0,Y,"LD_SLOT:bell",64,64);

	// Bars [1 bar] (x1000)
	Digit1[4] = CreateSprite(214.0,Y,"LD_SLOT:bar1_o",64,64);
	Digit2[4] = CreateSprite(288.0,Y,"LD_SLOT:bar1_o",64,64);
	Digit3[4] = CreateSprite(362.0,Y,"LD_SLOT:bar1_o",64,64);

	// Bars [2 bar] (x2000)
	Digit1[5] = CreateSprite(214.0,Y,"LD_SLOT:bar2_o",64,64);
	Digit2[5] = CreateSprite(288.0,Y,"LD_SLOT:bar2_o",64,64);
	Digit3[5] = CreateSprite(362.0,Y,"LD_SLOT:bar2_o",64,64);


	ReadyText=TextDrawCreate(320.0,Y+1.4,"~w~KASINO~n~~y~ ~k~~PED_SPRINT~ ~w~- ~g~gamble~n~~y~~k~~VEHICLE_ENTER_EXIT~ ~w~- ~r~exit~n~~y~~k~~PED_JUMPING~ ~w~- ~y~increase Bet");
	TextDrawUseBox(ReadyText,1);
	TextDrawFont(ReadyText,2);
	TextDrawSetShadow(ReadyText,0);
	TextDrawSetOutline(ReadyText,1);
	TextDrawLetterSize(ReadyText,0.3,1.23);
	TextDrawAlignment(ReadyText,2);
	TextDrawBoxColor(ReadyText,0x00000077);
	TextDrawTextSize(ReadyText,350,210);

	for(new i; i < MAX_PLAYERS; i++)
	{
		BetText[i]=TextDrawCreate(195.0,Y+58,"~y~Ulog: 5$");
		TextDrawFont(BetText[i],2);
		TextDrawLetterSize(BetText[i],0.35,0.8);
		TextDrawSetShadow(BetText[i],0);
		TextDrawSetOutline(BetText[i],1);
	}

	#if kladionica == 1
	PostaviParoveKladionica( );
	#endif
	
	//Streamer_VisibleItems(STREAMER_TYPE_OBJECT,1000);

	new year, month, day;
	getdate( year, month, day );

	gettimeEx(ghour, gminute, gsecond);
	FixHour(ghour);
	ghour = shifthour;
	if( !realtime )
	{
		SetWorldTime(wtime);
		GlobalniSat = wtime;
		ServerInfo[ VremeInGame ] = wtime;
	}

	AntiDeAMX();

	// za fly hack, minx, miny, maxx, maxy
	farmerField = CreateDynamicRectangle( -1198.3669, -1065.8173, -1002.0459, -909.7990 );
	bankSafe = CreateDynamicRectangle( 1473.7382, -1031.7211, 1465.0930, -1007.0601 );
	ZlataraSef = CreateDynamicRectangle( 918.9664, -1011.9576, 913.6884, -1010.5016 );
	SpawnZona = CreateDynamicRectangle( 356.0672,-2013.1305, 422.5678,-2096.5896 );//edited leon
	FarmerPosao = CreateDynamicRectangle( -1224.0177, -1220.6852, -1027.5038, -1064.8070 );
	GradjPosao = CreateDynamicRectangle(1859.0541,-1452.8436, 1979.4402,-1345.2263);//edited leon
	SSB = CreateDynamicRectangle( 1951.0851, -1744.1436, 1966.6748, -1723.7572 );
	KosacMost = CreateDynamicRectangle( 1956.7731, -1262.3374, 1985.3881, -1138.9209 );//edited leon
	AdminBaza = CreateDynamicRectangle( 2436.5176,1604.1638, 2598.3367,1482.1650 );//edited leon
	ZgradaNeka = CreateDynamicRectangle( 1521.3862, -1378.1085, 1564.0503, -1333.2006 );
	GSFMost = CreateDynamicRectangle( 2412.8169, -1722.5156, 2447.5449, -1575.6823 );//edited leon
	AutoPijacaBG = CreateDynamicRectangle( 1588.1996,-1151.6184, 1828.9156,-1025.6559 );//edited leon
	VineWoodArea = CreateDynamicRectangle( 1413.37354, -830.92944, 1466.22461, -795.86652 );//edited leon
	SAJBaza = CreateDynamicRectangle( 1246.2416,-1229.9323,1331.2672,-1176.3035 );//edited leon

	
	new KurvaP1 = CreateActor( 63, -2411.0474, 994.7935, -20.4423, 6.7633 );
	new KurvaP2 = CreateActor( 64, -2412.1418, 993.2431, -20.4423, 123.0319 );
	new KurvaP3 = CreateActor( 152, -2391.5752, 993.4570, -20.4423, 116.0734 );
	new KurvaP4 = CreateActor( 207, -2393.1602, 1023.3606, -20.3654, 123.7557 );
	new KurvaP5 = CreateActor( 238, -2401.6619, 1022.3336, -20.3654, 90.2079 );
	ApplyActorAnimation( KurvaP1, "STRIP", "strip_A", 4.0, 1, 1, 1, 1, 0 );
	ApplyActorAnimation( KurvaP2, "STRIP", "strip_B", 4.0, 1, 1, 1, 1, 0 );
	ApplyActorAnimation( KurvaP3, "STRIP", "strip_C", 4.0, 1, 1, 1, 1, 0 );
	ApplyActorAnimation( KurvaP4, "STRIP", "strip_D", 4.0, 1, 1, 1, 1, 0 );
	ApplyActorAnimation( KurvaP5, "STRIP", "strip_E", 4.0, 1, 1, 1, 1, 0 );

	
	//AddStaticVehicle_V(408, 2174.2351, -2265.6245, 14.1000, 225.0000, -1, -1);

	/*CreateObject_V(1331, 2374.13110, -1533.58521, 23.93410, 0.00000, 0.00000, 180.00000);*/

	//-------[Interijeri]--------
	KreirajInterijer( "ZatvorUlaz", 1824.5696,-1538.0585,13.5469, -1612.8118,-1141.2781,1441.8942, 1, 0, 1, 0);

	KreirajInterijerEx("KLADIONICA",1691.2272,-1343.2809,17.4297,1670.3978,-1340.6511,20163.0254,0,0,0,0);


	// 2233.8032, 1712.2303, 1011.7632
	// casino int
	CreateDynamicObject(14777,211.85473633,404.94235229,1021.71655273,0.00000000,0.00000000,0.00000000); //object(int_5weecasino) (1)
	//



	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//1
	for( new askid = 1; askid < MAX_ASKQS; askid++ ) {
		askqList[ askid ][ askqSend ] = false;
		askqList[ askid ][ askqID ] = -1;

		strmid( askqList[ askid ][ askqOwner ], "None", 0, strlen( "None" ), 32 );
		strmid( askqList[ askid ][ askqQuestion ], "None", 0, strlen( "None" ), 128 );
	}
	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//2
	if( realtime ) {
		new tmphour,
			tmpminute,
			tmpsecond,
			stringicc[ 20 ],stringicc1[ 30 ];

		gettimeEx( tmphour, tmpminute, tmpsecond );
		FixHour( tmphour );
		tmphour = shifthour;
		SetWorldTime( tmphour );
		GlobalniSat = tmphour;
		ServerInfo[ VremeInGame ] = tmphour;
		//printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;
		format( stringicc, sizeof( stringicc ), "~w~%s%d~y~:~w~%s%d", (tmphour < 10) ? ("0") : (""), tmphour, (tmpminute < 10) ? ("0") : (""), tmpminute);
		TextDrawSetString( TDEditor_TD[35], stringicc );
		format( stringicc1, sizeof( stringicc1 ), "~w~%d~r~/~w~%d~r~/~w~%d", day, month, year );
		TextDrawSetString( TDEditor_TD[36], stringicc1 );
	}
	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//3
	if(NERP_ANIMACIJE == 1) UsePlayerPedAnims();
	////////////////////////////////////mysql//////////////////////////////
	#if defined mysql_dataon
	mysql_data = mysql_connect(mysql_host, mysql_user, mysql_password, mysql_database);
	if(mysql_data == MYSQL_INVALID_HANDLE || mysql_errno(mysql_data) != 0) {
		mysql_print("[MySQL] - Error: Neuspjesno povezivanje sa databazom!");
		return (false);
	}
	else if(mysql_errno(mysql_data) == 0)
	{
		mysql_print("[MySQL] - Info: Server je uspesno povezan sa databazom!");
	}

	//new bool:use_cache;
	new Cache:query_cache;
	query_cache = mysql_query(MySQL:mysql_data, "SELECT * FROM `info`");//, bool:use_cache = true);

	new mysql_database_rows;
	cache_get_row_count(mysql_database_rows);
	if(!mysql_database_rows) return (false);
	else {
		cache_get_value_int(0, "broj", ServerInfo[ServerPassword]);
		mysql_print("[MySQL] - Info: Uspjesno su ucitani podaci iz databaze!");
	}
	cache_delete(query_cache);
	
	Database = mysql_connect(mysql_host, mysql_user, mysql_pass, mysql_database);
	if(Database == MYSQL_INVALID_HANDLE || mysql_errno(Database) != 0) {
		print("Connecting to MySQL database failed");
		//SendRconCommand("exit");
		return (false);
	}
	#endif
	//////////////////////////////////////////////////////////////////////////
	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//4
	
	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//5

	//mysql_data_connect();
	CallLocalFunction("NERP_ONGMINIT", "");
	printf(">> Game Init : Debug ~ %i",gminit_debug);gminit_debug++;//6
	return true;
}

public OnGameModeExit( ) {
	TurnOffMap();
	#if defined JEBOTE_MYSQL_U_GUZICU
	mysql_data_disconnect();
	#endif
	//TurnOffMap();
	for( new f = 0; f < MAX_BUSSINES; f++ ) {
		new gFile[ 40 ];
		format( gFile, 40, F_FILE, f );
		if( fexist( gFile ) ) {
			SaveBussines( f );
		}
	}
	for( new c = 0; c < MAX_CARS; c++ ) {
		new gFile[ 40 ];
		format( gFile, 40, V_FILE, c );
		if( fexist( gFile ) ) {
			SaveVehicle( c );
		}
	}
	for( new im = 0; im < MAX_IMOVINA; im++ ) {
		new gFile[ 40 ];
		format( gFile, 40, IM_FILE, im );
		if( fexist( gFile ) ) {
			SaveProperty( im );
		}
	}
	for(new i; i < MAX_PLAYERS; i++) {
		Dimi_KillTimer( gZone_Timer[ i ] );
		Dimi_KillTimer( zauzimanje_firme_Timer[ i ] );
		Dimi_KillTimer( TimerLearn[ i ] );
		Dimi_KillTimer( atmrobTimer[ i ] );
		#if NERP_ZIMSKI_MOD  == 1
		Dimi_KillTimer( EffectTimer[ i ] );
		#endif
		Dimi_KillTimer( SkolaTimer[ i ] );
		Dimi_KillTimer( TimerPitanje[ i ] );
		Dimi_KillTimer( RentTimer[ i ] );
		Dimi_KillTimer( DragTimer[ i ] );
		Dimi_KillTimer( TimerTutorial[ i ] );
		Dimi_KillTimer( FarbanjeTimer[ i ] );
		Dimi_KillTimer( BolnicaTimer[ i ] );
		Dimi_KillTimer( TaxiTimer[ i ] );
		Dimi_KillTimer( TazerTimer[ i ] );
		Dimi_KillTimer( CistacTimer[ i ] );
		Dimi_KillTimer( TrashTimer[ i ] );
		Dimi_KillTimer( PilotTimer[ i ] );
		Dimi_KillTimer( FarbanjeTimer[ i ] );
		Dimi_KillTimer( TravaTimer[ i ] );
		Dimi_KillTimer( ZitoTimer[ i ] );
		Dimi_KillTimer( smecedoletimer[ i ] );
		Dimi_KillTimer( ravnjanjetimer[ i ] );
		Dimi_KillTimer( PljackanjeBankeTimer[ i ] );
		Dimi_KillTimer( PljackanjeZlatareTimer[ i ] );
		Dimi_KillTimer( rudarPosao[ i ][ rudarTimer ] );
	}
	//mysql
	#if defined mysql_dataon
	mysql_close(mysql_data);
	
	for(new i; i < MAX_PLAYERS; i++) {
		mysql_SavePlayer(i);
	}
	mysql_close(Database);
	#endif

	CallLocalFunction("NERP_ONGMEXIT", "");
	return true;
}

// GMEXIT HOOK
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit NERP_ONGMEXIT

forward NERP_ONGMEXIT();


LoadScriptfiles(); public LoadScriptfiles()
{
	//------[Organizacije]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje organizacija...");
	for( new id = 1; id < MAX_ORG; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'ORGANIZACIJE' pod sektorom: %i",id);
		new oFile[ 40 ], pFile[ 40 ];
		format( oFile, sizeof( oFile ), O_FILE, id );
		format( pFile, sizeof( pFile ), PORT_FILE, id );
		OI[ id ][ oSavez ] = -1;
		if( fexist( oFile ) )
		{
			INI_ParseFile(oFile, "UcitajOrganizaciju", .bExtra = true, .extra = id);
			new string[ 256 ];
			format( string, sizeof( string ), ""col_balkanstory"|| %s ||\n"col_white"Da udjete koristite\n", OI[ id ][ oName ] );
			Org3D[ id ] = Create3DTextLabel( string, -1, OI[ id ][ oPozExtX ], OI[ id ][ oPozExtY ], OI[ id ][ oPozExtZ ], 25, 0, 1);
			OrgPickup[ id ] = CreateDynamicPickup(19133, 1, OI[ id ][ oPozExtX ], OI[ id ][ oPozExtY ], OI[ id ][ oPozExtZ ] );
			if( OI[ id ][ oDutyPoint ][ 0 ] != 0 && OI[ id ][ oDutyPoint ][ 1 ] != 0 )
			{
				OrgDuty3D[ id ] = CreateDynamic3DTextLabel( ""col_balkanstory"|| DUZNOST ||\n"col_white"Da odete na duznost\n"col_balkanstory"/duty\n/undercover", -1, OI[ id ][ oDutyPoint ][ 0 ], OI[ id ][ oDutyPoint ][ 1 ], OI[ id ][ oDutyPoint ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oDutyVW ], OI[ id ][ oDutyInt ], -1, 20.0);
				DutyPointPickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oDutyPoint ][ 0 ], OI[ id ][ oDutyPoint ][ 1 ], OI[ id ][ oDutyPoint ][ 2 ], OI[ id ][ oDutyVW ], OI[ id ][ oDutyInt ], -1, 20.0 );
			}
			if( OI[ id ][ oEquipPoint ][ 0 ] != 0 && OI[ id ][ oEquipPoint ][ 1 ] != 0 )
			{
				OrgEquip3D[ id ] = CreateDynamic3DTextLabel( ""col_balkanstory"|| OPREMA ||\n"col_white"Da uzmete opremu\n"col_balkanstory"/oprema", -1, OI[ id ][ oEquipPoint ][ 0 ], OI[ id ][ oEquipPoint ][ 1 ], OI[ id ][ oEquipPoint ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oEquipVW ], OI[ id ][ oEquipInt ], -1, 20.0);
				EquipPointPickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oEquipPoint ][ 0 ], OI[ id ][ oEquipPoint ][ 1 ], OI[ id ][ oEquipPoint ][ 2 ], OI[ id ][ oEquipVW ], OI[ id ][ oEquipInt ], -1, 20.0 );
			}
			#if nerp_droga == 1
			if( OI[ id ][ oDrugField ][ 0 ] != 0 && OI[ id ][ oDrugField ][ 1 ] != 0 )
			{
				new stringfield[ 128 ];
				format( stringfield, sizeof( stringfield ), ""col_balkanstory"|| POLJANA ||\n"col_white"Ova poljana je u vlasnistvu\n"col_balkanstory"%s", OI[ id ][ oName ] );
				OrgField3d[ id ] = CreateDynamic3DTextLabel( stringfield, -1, OI[ id ][ oDrugField ][ 0 ], OI[ id ][ oDrugField ][ 1 ], OI[ id ][ oDrugField ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 50.0);
				OrgFieldPickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oDrugField ][ 0 ], OI[ id ][ oDrugField ][ 1 ], OI[ id ][ oDrugField ][ 2 ], 0, 0, -1, 50.0 );
			}
			#endif
			if( OI[ id ][ oSafePos ][ 0 ] != 0 && OI[ id ][ oSafePos ][ 1 ] != 0 )
			{
				new stringsafe[ 128 ];
				format( stringsafe, sizeof( stringsafe ), ""col_balkanstory"|| %s ||\n"col_white"Da otvorite sef\n"col_balkanstory"/orgsef", OI[ id ][ oName ] );
				OrgSafe3d[ id ] = CreateDynamic3DTextLabel( stringsafe, -1, OI[ id ][ oSafePos ][ 0 ], OI[ id ][ oSafePos ][ 1 ], OI[ id ][ oSafePos ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oVw ], OI[ id ][ oInt ], -1, 20.0);
				OrgSafePickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oSafePos ][ 0 ], OI[ id ][ oSafePos ][ 1 ], OI[ id ][ oSafePos ][ 2 ], OI[ id ][ oVw ], OI[ id ][ oInt ], -1, 20.0 );
			}
			Orge3D( id );
			if( fexist( pFile ) )
			{
				INI_ParseFile( pFile, "LoadPorts", .bExtra = true, .extra = id);
				for( new i = 0; i < OI[ id ][ oMaxPort ]; i++)
				{
					if( PortOP[ id ][ i ][ Pos1 ][ 0 ] != 0 )
					{
						PortOP[ id ][ i ][ Pickup ][ 0 ] = CreateDynamicPickup( 1239, 1, PortOP[ id ][ i ][ Pos1 ][ 0 ], PortOP[ id ][ i ][ Pos1 ][ 1 ], PortOP[ id ][ i ][ Pos1 ][ 2 ], PortOP[ id ][ i ][ VW ][ 0 ], PortOP[ id ][ i ][ Int ][ 0 ], -1, 20.0 );
					}
					if( PortOP[ id ][ i ][ Pos2 ][ 0 ] != 0 )
					{
						PortOP[ id ][ i ][ Pickup ][ 1 ] = CreateDynamicPickup( 1239, 1, PortOP[ id ][ i ][ Pos2 ][ 0 ], PortOP[ id ][ i ][ Pos2 ][ 1 ], PortOP[ id ][ i ][ Pos2 ][ 2 ], PortOP[ id ][ i ][ VW ][ 1 ], PortOP[ id ][ i ][ Int ][ 1 ], -1, 20.0 );
					}
				}
			}
		}
	}
	//------[Hoteli]----
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje hotela...");
	for( new h = 1; h < MAX_HOTELS; h++) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'HOTELI' pod sektorom: %i",h);
		new string[ 256 ], File[ 50 ];
		format( File, sizeof( File ), HOTEL_FILE, h );
		if( fexist( File ) ) {
			INI_ParseFile( File, "LoadHotel", .bExtra = true, .extra = h );
			if( hotelInfo[ h ][ hOwned ] == 0 ) {
				format( string, sizeof( string ), "{36AB00}Hotel na Prodaju"col_white"[ID %d]{36AB00}\n{36AB00}Cena: "col_white"%d$\n{36AB00}Potreban level: "col_white"%d\n{36AB00}Adresa: "col_white"%s\n{36AB00}Za kupovinu "col_white"/kupihotel", h, hotelInfo[ h ][ hPrice ], hotelInfo[ h ][ hLevel ], hotelInfo[ h ][ hAdress ] );
			}
			else if( hotelInfo[ h ][ hOwned ] == 1 ) {
				format( string, sizeof( string ), ""col_white"[ID %d]{36AB00}Vlasnik: "col_white"%s\n{36AB00}Adresa: "col_white"%s\n{36AB00}Cena najma: "col_white"%d\n{36AB00}'ENTER' za ulaz u hotel", h, hotelInfo[ h ][ hOwner ], hotelInfo[ h ][ hAdress ], hotelInfo[ h ][ hRoomPrice ] );
			}
			if( hotelInfo[ h ][ hOwned ] == 0 )
			{
				format( string, sizeof( string ), "{36AB00}[ HOTEL >> NA PRODAJU ]\n"col_white"[ID hotela >> %d]{36AB00}\n{36AB00}Cena: "col_white"%d$\n{36AB00}Potreban level: "col_white"%d\n{36AB00}Adresa: "col_white"%s\n{36AB00}Za kupovinu "col_white"/kupihotel", h, hotelInfo[ h ][ hPrice ], hotelInfo[ h ][ hLevel ], hotelInfo[ h ][ hAdress ] );
			}
			else if( hotelInfo[ h ][ hOwned ] == 1 )
			{
				format( string, sizeof( string ), "{36AB00}[ HOTEL >> U VLASNISTVU ]\n"col_white"[ID hotela >> %d]{36AB00}\nVlasnik: "col_white"%s\n{36AB00}Adresa: "col_white"%s\n{36AB00}Cena najma: "col_white"%d\n{36AB00}'ENTER' za ulaz u hotel", h, hotelInfo[ h ][ hOwner ], hotelInfo[ h ][ hAdress ], hotelInfo[ h ][ hRoomPrice ] );
			}
			hotelInfo[ h ][ hPickup ] = CreateDynamicPickup( 19134, 1, hotelInfo[ h ][ hEnter ][ 0 ], hotelInfo[ h ][ hEnter ][ 1 ], hotelInfo[ h ][ hEnter ][ 2 ] );
			hotelInfo[ h ][ h3DText ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, hotelInfo[ h ][ hEnter ][ 0 ], hotelInfo[ h ][ hEnter ][ 1 ], hotelInfo[ h ][ hEnter ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
		}
	}
	//------[AutoSaloni]----
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje auto salona...");
	for( new as = 1; as < MAX_AUTOS; as++)
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'AUTO SALONI' pod sektorom: %i",as);
		new asFile[ 50 ];
		format( asFile, sizeof( asFile ), AS_FILE, as );
		if( fexist( asFile ) ) {
			INI_ParseFile( asFile, "LoadSalon", .bExtra = true, .extra = as );
			AutoSalon[ as ][ AlreadyBuying ] = false;
			AutoSalon[ as ][ AutoSalon3D ] = CreateDynamic3DTextLabel( ""col_white"Da kupite vozilo kucajte\n"col_balkanstory"[ /kupivozilo ]", -1, AutoSalon[ as ][ aPickupPos ][ 0 ], AutoSalon[ as ][ aPickupPos ][ 1 ], AutoSalon[ as ][ aPickupPos ][ 2 ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, AutoSalon[ as ][ aVW ], AutoSalon[ as ][ aInt ], -1, 20.0);
			AutoSalon[ as ][ AutoSalonPickup ] = CreateDynamicPickup( 1239, 1, AutoSalon[ as ][ aPickupPos ][ 0 ], AutoSalon[ as ][ aPickupPos ][ 1 ], AutoSalon[ as ][ aPickupPos ][ 2 ], AutoSalon[ as ][ aVW ], AutoSalon[ as ][ aInt ], -1, 20.0 );
		}
	}
	//------[Imovina]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje imovine...");
	for( new im = 1; im < MAX_IMOVINA; im++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'IMOVINA' pod sektorom: %i",im);
		new string[ 300 ], iFile[ 50 ];
		format( iFile, sizeof( iFile ), IM_FILE, im );
		if( fexist( iFile ) )
		{
			INI_ParseFile( iFile, "OcitajImovinu", .bExtra = true, .extra = im );
			II[ im ][ iVW ] = im;
			LoadFurniture( im );
			////////////////////////////////////////////////////////////////////////////////////////
			if( II[ im ][ iUsage ] == IMOVINA_KUCA )//EDITEDD LEON
			{
				if( II[ im ][ iOwned ] == 0 )
				{
					format( string, sizeof( string ),"{D50000}[ KUCA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Level: {FFFFFF}%d\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Da kupite kucu: {FFFFFF}/kupikucu",II[ im ][ iPrice ],GetVrstaKuce( II[ im ][ iVrsta ] ),II[ im ][ iLevel ],im,II[ im ][ iAdress ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
				{
					format( string, sizeof( string ),"{D50000}[ KUCA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Neaktivnost: {FFFFFF}%dh",II[ im ][ iOwner ],GetVrstaKuce( II[ im ][ iVrsta ] ),im,II[ im ][ iAdress ],II[ im ][ iNeaktivnost ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
				{
					format( string, sizeof( string ),"{D50000}[ KUCA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Neaktivnost: {FFFFFF}%dh\n{D50000}Cijena renta: {FFFFFF}%d$",II[ im ][ iOwner ],GetVrstaKuce( II[ im ][ iVrsta ] ),im,II[ im ][ iAdress ],II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if( II[ im ][ iUsage ] == IMOVINA_STAN )
			{
				if( II[ im ][ iOwned ] == 0 )
				{
					format( string, sizeof( string ),"{FF8040}[ STAN >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Level: {FFFFFF}%d\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Da kupite stan: {FFFFFF}/kupistan",II[ im ][ iPrice ],GetVrstaStana( II[ im ][ iVrsta ] ), II[ im ][ iLevel ],im, II[ im ][ iAdress ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
				{
					format( string, sizeof( string ),"{FF8040}[ STAN >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Neaktivnost: {FFFFFF}%dh", II[ im ][ iOwner ],GetVrstaStana( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
				{
					format( string, sizeof( string ),"{FF8040}[ STAN >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Neaktivnost: {FFFFFF}%dh\n{FF8040}Cijena renta: {FFFFFF}%d$", II[ im ][ iOwner ],GetVrstaStana( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if( II[ im ][ iUsage ] == IMOVINA_VIKENDICA )
			{
				/*if( II[ im ][ iOwned ] == 0 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{FFFF00}Vrsta: {FFFFFF}Mala vikendica\n{FFFF00}Level: {FFFFFF}%d\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Da kupite vikendicu: {FFFFFF}/kupivikendicu",II[ im ][ iPrice ],GetVrstaVikendice( II[ im ][ iVrsta ] ), II[ im ][ iLevel ],im, II[ im ][ iAdress ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}Mala vikendica\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}Mala vikendica\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh\n{FFFF00}Cijena renta: {FFFFFF}%d$",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}*/
				if( II[ im ][ iOwned ] == 0 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Level: {FFFFFF}%d\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Da kupite vikendicu: {FFFFFF}/kupivikendicu",II[ im ][ iPrice ],GetVrstaVikendice( II[ im ][ iVrsta ] ), II[ im ][ iLevel ],im, II[ im ][ iAdress ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
				else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
				{
					format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh\n{FFFF00}Cijena renta: {FFFFFF}%d$",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
					ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
				}
			}
			/////////////////////////////////////////////////////////////////////////////
			ServerInfo[ BrojImovina ]++;
			ImovinaLabel[ im ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
		}
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje firmi...");
	//------[Firme]------
	for( new f = 1; f < MAX_BUSSINES; f++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'FIRME' pod sektorom: %i",f);
		new string[ 512 ], fFile[ 50 ];
		format( fFile, sizeof( fFile ), F_FILE, f );
		if( fexist( fFile ) ) {
			INI_ParseFile( fFile, "OcitajFirmu", .bExtra = true, .extra = f );

			if( BussinesInfo[ f ][ bOwned ] == 0) {
				format(string,sizeof(string), ""col_yelow"[ FIRMA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n"col_yelow"Vrsta: {FFFFFF}%s\n"col_yelow"Level: {FFFFFF}%d\n"col_yelow"Broj: {FFFFFF}%d\n"col_yelow"Adresa: {FFFFFF}%s\n"col_yelow"Da kupite firmu: {FFFFFF}/kupifirmu",BussinesInfo[ f ][ bPrice ],getBussinesType( f ),BussinesInfo[ f ][ bLevel ],f,UliceFirme( f ) );
				FirmaPickup[ f ] = CreateDynamicPickup( 1274, 1, BussinesInfo[ f ][ bEnterX], BussinesInfo[ f ][ bEnterY], BussinesInfo[ f ][ bEnterZ ] );
			}
			else if( BussinesInfo[ f ][ bOwned ] == 1)
			{
				format(string,sizeof(string), ""col_yelow"[ FIRMA >> U VLASNISTVU ]\nIme: %s\nVlasnik: {FFFFFF}%s\n"col_yelow"Vrsta: {FFFFFF}%s\n"col_yelow"Broj: {FFFFFF}%d\n"col_yelow"Adresa: {FFFFFF}%s\n"col_yelow"Iznuda: {FFFFFF}%s\n"col_yelow"Neaktivnost: {FFFFFF}%dh",BussinesInfo[ f ][ bName ],BussinesInfo[ f ][ bOwner ],getBussinesType( f ),f,UliceFirme( f ),GetReketName( BussinesInfo[ f ][ bReket ] ),BussinesInfo[ f ][ bNeaktivnost ]);
				FirmaPickup[ f ] = CreateDynamicPickup( 1274, 1, BussinesInfo[ f ][ bEnterX], BussinesInfo[ f ][ bEnterY], BussinesInfo[ f ][ bEnterZ ] );
			}
			FirmaLabel[ f ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, BussinesInfo[ f ][ bEnterX], BussinesInfo[ f ][ bEnterY], BussinesInfo[ f ][ bEnterZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
		}
	}
	//------[Kapije]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje privatnih kapija...");
	for( new g = 1; g < MAX_GATES; g++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'KAPIJE' pod sektorom: %i",g);
		new gFile[ 50 ];
		format( gFile, sizeof( gFile ), GATE_FILE, g );
		if( fexist( gFile ) ) {
			INI_ParseFile( gFile, "LoadGate", .bExtra = true, .extra = g );
			GateData[ g ][ gateOpened ] = false;
			GateData[ g ][ gateObject ] = CreateDynamicObject( GateData[ g ][ gateModel ], GateData[ g ][ gatePos ][ 0 ], GateData[ g ][ gatePos ][ 1 ], GateData[ g ][ gatePos ][ 2 ], GateData[ g ][ gatePos ][ 3 ], GateData[ g ][ gatePos ][ 4 ], GateData[ g ][ gatePos ][ 5 ], GateData[ g ][ gateWorld ], GateData[ g ][ gateInterior ] );
		}
	}
	//------[Eventi]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje evenata...");
	for( new i = 1; i < MAX_EVENTS; i++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'EVENTI' pod sektorom: %i",i);
		strmid( Event[ i ][ Name ], "Nema eventa", 0, strlen( "Nema eventa" ), 32 );
		new gFile[ 35 ];
		format( gFile, 35, EVENT_FILE, i );
		if( fexist( gFile ) ) {
			INI_ParseFile( gFile, "LoadEvent", .bExtra = true, .extra = i );
		}
	}
	//------[Kontejneri]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje kontejnera...");
	for( new ko = 1; ko < MAX_KONT; ko++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'KONTEJNERI' pod sektorom: %i",ko);
		new koFile[ 50 ];
		//new i = ko;
		format( koFile, sizeof( koFile ), KO_FILE, ko );
		if( fexist( koFile ) )
		{
			INI_ParseFile( koFile, "OcitajKont", .bExtra = true, .extra = ko );
			KontInfo[ ko ][ koObjID ] = CreateDynamicObject(1345, KontInfo[ ko ][ koObjPos ][ 0 ], KontInfo[ ko ][ koObjPos ][ 1 ], KontInfo[ ko ][ koObjPos ][ 2 ], KontInfo[ ko ][ koObjRot ][ 0 ], KontInfo[ ko ][ koObjRot ][ 1 ], KontInfo[ ko ][ koObjRot ][ 2 ] );
			ServerInfo[ BrojKontejnera ]++;
			KontInfo[ ko ][ KontText3D ] = CreateDynamic3DTextLabel( ""col_balkanstory"[KONTEJNER]\n\n{FFFFFF}Koristite kontejner sljedecim komandama:\n"col_balkanstory"[ /trazi, /baci ]", -1, KontInfo[ ko ][koObjPos][0], KontInfo[ ko ][koObjPos][1], KontInfo[ ko ][koObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

		}
	}
	/*new street_id_pickup_text[300];
			format(street_id_pickup_text,sizeof(street_id_pickup_text),
				""col_balkanstory"[ DILER ]\n\nU vlasnistvu: "SERVERBOJA_ZELENA"Slobodan\nDa kupite dilera /kupidilera\nDa kupite od dilera /diler");
*/
	//------[Ulice]------ 19133 streetInfo[st][streetObjPos][],
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje ulica...");
	for( new st = 1; st < MAX_STREETS; st ++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'ULICE' pod sektorom: %i",st);
		new streetFile[50];

		format(streetFile,sizeof(streetFile), STREET_FILE,st);

		if( fexist( streetFile ))
		{
			INI_ParseFile( streetFile, "OcitajUlicu", .bExtra = true, .extra = st );
			new street_id_pickup_text[300];
			format(street_id_pickup_text,sizeof(street_id_pickup_text),""col_balkanstory"[ ULICA ]\n\n{ffffff}Naziv ulice:"col_balkanstory" %s\n{ffffff}Tip ulice: Starija ulica\n"col_white"Dobrodosli u ovu ulicu, uzivajte u provodu!\n"col_balkanstory"Broj ulice: %d", GetStreetLocation(st), st);
			//format(street_id_pickup_text,sizeof(street_id_pickup_text),""col_balkanstory"[ ULICA ]\n\n"col_white"Dobrodosli u ovu ulicu, uzivajte u provodu!\n"col_balkanstory"Broj ulice: %d", st);
			streetInfo[st][streetText3D] = CreateDynamic3DTextLabel( street_id_pickup_text, -1, streetInfo[st][streetObjPos][0],streetInfo[st][streetObjPos][1],streetInfo[st][streetObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
			streetPickup[ st ] = CreateDynamicPickup(1314, 1, streetInfo[st][streetObjPos][0],streetInfo[st][streetObjPos][1],streetInfo[st][streetObjPos][2] );
		}
	}
	//------[Dileri]------ 19133 streetInfo[st][streetObjPos][],
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje dilera...");
	for( new diler = 0; diler < MAX_DEALERS; diler ++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'DILERI' pod sektorom: %i",diler);
		new streetFile[50];

		format(streetFile,sizeof(streetFile), DEALER_FILE,diler);

		if( fexist( streetFile ))
		{
			INI_ParseFile( streetFile, "OcitajDilera", .bExtra = true, .extra = diler );
			Dileri3D(diler);
		}
	}
	//------[Rentovi]------ 
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje rentova...");
	for( new st = 1; st < MAX_RENTS; st ++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'BRZI RENT' pod sektorom: %i",st);
		new rentFile[50];

		new rent_database = st;
		format(rentFile,sizeof(rentFile), RENT_FILE , rent_database);

		if( fexist( rentFile ))
		{
			INI_ParseFile( rentFile, "OcitajRent", .bExtra = true, .extra = rent_database );
			new rent_id_pickup_text[300];
			format(rent_id_pickup_text,sizeof(rent_id_pickup_text),""col_balkanstory"[ BRZI RENT ]{ffffff}\n\nDobrodosli na brzi rent!\nOvde mozete spawnovati rent vozilo, kucajte:\n\n"col_balkanstory"[ /spawnrentvozilo ]");
			rentInfo[st][rentText3D] = CreateDynamic3DTextLabel( rent_id_pickup_text, -1, rentInfo[st][rentObjPos][0],rentInfo[st][rentObjPos][1],rentInfo[st][rentObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
			rentPickup[ st ] = CreateDynamicPickup(RENT_PICKUPID,1, rentInfo[st][rentObjPos][0],rentInfo[st][rentObjPos][1],rentInfo[st][rentObjPos][2] );
		}
	}
	//------[Mrtva tela]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje mrtvih tijela...");
	for( new ko = 1; ko < MAX_BODIES; ko++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'MRTVA TELA' pod sektorom: %i",ko);
		new bodyFile[ 50 ];

		format( bodyFile, sizeof( bodyFile ), BODY_FILE, ko );
		
		new dead_body_fileid = ko;
		
		if( fexist( bodyFile ) )
		{
			INI_ParseFile( bodyFile, "OcitajMrtvoTelo", .bExtra = true, .extra = dead_body_fileid );
			bodyInfo[ ko ][ bodyObjID ] = CreateDynamicObject(3092,bodyInfo[ ko ][ bodyObjPos ][0],bodyInfo[ ko ][ bodyObjPos ][1],bodyInfo[ ko ][ bodyObjPos ][2],93.7, 120.0, random(360)/*,600.000,600.0*/);//CreateDynamicObject(1345, bodyInfo[ ko ][ bodyObjPos ][ 0 ], bodyInfo[ ko ][ bodyObjPos ][ 1 ], bodyInfo[ ko ][ bodyObjPos ][ 2 ] );

			new deadbody_text_label[500];
			//format(deadbody_text_label,sizeof(deadbody_text_label),""col_balkanstory"|| DEATHPOINT IGRACA - Mrtvo tijelo: %d ||\n\n{FFFFFF}Ovo mrtvo nije sveze i zastarelo je, "col_balkanstory"nije moguce identificirati igraca!\n(("SERVERBOJA_SIVA" Ovaj igrac je ubijen - ovo je njegovo mrtvo tijelo,\nda prijavite zlocin, pozovite policiju!"col_balkanstory" ))\n\n|| Admin nivo 1337+ moze ocistiti tijela na serveru, komanda: /ddt,\nukoliko radite poslovnu misiju grobar, kucajte: /pokupitelo ||", ko);
			format(deadbody_text_label,sizeof(deadbody_text_label),
				""col_balkanstory"[MRTVO TELO >> ID - %i]\n\n{ffffff}Ovo tijelo je veoma staro,\nmolimo pozovite grobare!\n\n{ffffff}[ /ddt, /pokupitelo ]",ko);
			bodyInfo[ko][bodyText3D] = CreateDynamic3DTextLabel( deadbody_text_label, -1, bodyInfo[ ko ][bodyObjPos][0], bodyInfo[ ko ][bodyObjPos][1], bodyInfo[ ko ][bodyObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
		}
	}
	
	//------[Bankomati]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje bankomata...");
	for( new atm = 1; atm < MAX_ATM; atm++ ) {
		printf("[ SCRIPT ]: Ucitavanje modula 'BANKOMATI' pod sektorom: %i",atm);
		new aFile[ 50 ];
		new b_string[128];
		format( aFile, sizeof( aFile ), ATM_FILE, atm );
		if( fexist( aFile ) )
		{
			INI_ParseFile( aFile, "LoadATM", .bExtra = true, .extra = atm );
			atmInfo[ atm ][ atmObject ] = CreateDynamicObject(2942, atmInfo[ atm ][ atmPos ][ 0 ], atmInfo[ atm ][ atmPos ][ 1 ], atmInfo[ atm ][ atmPos ][ 2 ], atmInfo[ atm ][ atmPos ][ 3 ], atmInfo[ atm ][ atmPos ][ 4 ], atmInfo[ atm ][ atmPos ][ 5 ] );
			format( b_string, sizeof( b_string ),""col_yelow"[BANKOMAT]\nBroj bankomata: {FFFFFF}%d\n"col_yelow"Komande:\n{FFFFFF}/bankomat",atm);
			atmInfo[ atm ][ atmText3D ] = CreateDynamic3DTextLabel( b_string, -1, atmInfo[ atm ][atmPos][ 0 ], atmInfo[ atm ][atmPos][ 1 ], atmInfo[ atm ][atmPos][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
		}
	}
	//------[Radari]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje radara...");
	for( new radarID = 1; radarID < MAX_RADARS; radarID++ ) {
		printf("[ SCRIPT ]: Ucitavanje modula 'RADARI' pod sektorom: %i",radarID);
		new radarFile[ 50 ];
		format( radarFile, sizeof( radarFile ), F_RADARS, radarID );
		if( fexist( radarFile ) ) {
		
			INI_ParseFile( radarFile, "LoadRadar", .bExtra = true, .extra = radarID );
			radarInfo[ radarID ][ radarObject ] = CreateDynamicObject( 18880, radarInfo[ radarID ][ radarPos ][ 0 ], radarInfo[ radarID ][ radarPos ][ 1 ], radarInfo[ radarID ][ radarPos ][ 2 ], radarInfo[ radarID ][ radarPos ][ 3 ], radarInfo[ radarID ][ radarPos ][ 4 ], radarInfo[ radarID ][ radarPos ][ 5 ] );
		}
	}
	//------[Imanje]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje imanja...");
	for( new id = 1; id < MAX_FIELDS; id++ ) {
		printf("[ SCRIPT ]: Ucitavanje modula 'IMANJA' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_FIELD, id );
		
		if( fexist( filename ) ) {

			new string[ 200 ];

			INI_ParseFile( filename, "LoadFields", .bExtra = true, .extra = id );

			if( !fieldInfo[ id ][ fieldOwned ] ) {
				format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nImanje na prodaju!\nLevel:{FFFFFF} %d\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena:{FFFFFF}%d$\n/kupiimanje", fieldInfo[ id ][ fieldLevel ],id,fieldInfo[ id ][ fieldPrice ] );
				fieldInfo[ id ][ fieldObject ] = CreateDynamicObject( 19470, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ], fieldInfo[ id ][ fieldObjectPos ][ 3 ], fieldInfo[ id ][ fieldObjectPos ][ 4 ], fieldInfo[ id ][ fieldObjectPos ][ 5 ], -1, -1, -1, 200.0 );
			}
			else if( fieldInfo[ id ][ fieldOwned ] ) {
				format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nVlasnik:{FFFFFF} %s\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena: {FFFFFF}%d$\n{009EEA}Adresa: {FFFFFF}%s",fieldInfo[ id ][ fieldOwner ],id,fieldInfo[ id ][ fieldPrice ],UlicaImanja( id ) );
				fieldInfo[ id ][ fieldPickup ] = CreateDynamicPickup( 1239, 1, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 0, 0 );
			}
			fieldInfo[ id ][ field3D ] = CreateDynamic3DTextLabel( string, BELA, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			fieldInfo[ id ][ fieldRectAngle ] = CreateDynamicRectangle( fieldInfo[ id ][ fieldMinX ], fieldInfo[ id ][ fieldMinY ], fieldInfo[ id ][ fieldMaxX ], fieldInfo[ id ][ fieldMaxY ], -1, -1, -1 );
		}
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje pumpi...");
	//------[Pumpe]------
	for( new fstationID = 1; fstationID < MAX_FSTATION; fstationID++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'PUMPE' pod sektorom: %i",fstationID);
		new filename[ 64 ];
		format( filename, sizeof( filename ), FSTATION_FILE, fstationID );
		if( fexist( filename ) ) {
		
			INI_ParseFile( filename, "FStation_Load", .bExtra = true, .extra = fstationID );
			if( FuelStation[ fstationID ][ fsPlaced ] ) {

				new string[ 512 ];
				format( string, sizeof( string ), ""col_balkanstory"|| {FFFFFF}%s"col_balkanstory" ||\nCijena benzina: {FFFFFF}%d$\n"col_balkanstory"Cijena dizela: {FFFFFF}%d$\n{FFFFFF}/natoci\n"col_balkanstory"| {FFFFFF}Adresa: {FFFFFF}%d "col_balkanstory"|",
					FuelStation[ fstationID ][ fsName ],
					FuelStation[ fstationID ][ fsGasolinePrice ],
					FuelStation[ fstationID ][ fsDieselPrice ],
					fstationID );

				FuelStation[ fstationID ][ fs3d ] = CreateDynamic3DTextLabel( string, 0x33CCFFFF, FuelStation[ fstationID ][ fsPos ] [ 0 ], FuelStation[ fstationID ][ fsPos ] [ 1 ], FuelStation[ fstationID ][ fsPos ] [ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
				FuelStation[ fstationID ][ fsPickup ] = CreateDynamicPickup (1650, 1, FuelStation[ fstationID ][ fsPos ] [ 0 ], FuelStation[ fstationID ][ fsPos ] [ 1 ], FuelStation[ fstationID ][ fsPos ] [ 2 ], 0, 0 );

			}
		}
	}
	//------[Stabljike imanja]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje stabljika voca...");
	for( new id = 1; id < MAX_STALKS; id++ ) {//stabljike ucitavanje

		printf("[ SCRIPT ]: Ucitavanje modula 'STABLJIKE' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_STALK, id );

		if( fexist( filename ) ) {

			new string[ 180 ], vrsta[ 10 ];
			INI_ParseFile( filename, "LoadStalks", .bExtra = true, .extra = id );
			if( stalkInfo[ id ][ sPlanted ] == true ) {
			
				if( stalkInfo[ id ][ sType ] == BILJKA_SLJIVA ) {
					vrsta = "SLJIVA";
					stalkInfo[ id ][ sObject ] = CreateDynamicObject( stalkInfo[ id ][ sObjectID ], stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ]-4, 0.0000000, 0.0000000, 0.0000000 );
				}
				else if( stalkInfo[ id ][ sType ] == BILJKA_KRUSKA ) {
					vrsta = "KRUSKA";
					stalkInfo[ id ][ sObject ] = CreateDynamicObject( stalkInfo[ id ][ sObjectID ], stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ]-4, 0.0000000, 0.0000000, 0.0000000 );
				}
				else if( stalkInfo[ id ][ sType ] == BILJKA_JABUKA ) {
					stalkInfo[ id ][ sObject ] = CreateDynamicObject( stalkInfo[ id ][ sObjectID ], stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ]-4, 0.0000000, 0.0000000, 0.0000000 );
					vrsta = "JABUKA";
				}
				else if( stalkInfo[ id ][ sType ] == BILJKA_KUPUS ) {
					stalkInfo[ id ][ sObject ] = CreateDynamicObject( stalkInfo[ id ][ sObjectID ], stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ], 0.0000000, 0.0000000, 0.0000000 );
					vrsta = "KUPUS";
				}
				else if( stalkInfo[ id ][ sType ] == BILJKA_RUZE ) {
					stalkInfo[ id ][ sObject ] = CreateDynamicObject( stalkInfo[ id ][ sObjectID ], stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ]-0.8, 0.0000000, 0.0000000, 0.0000000 );
					vrsta = "RUZE";
				}
				
				if( stalkInfo[ id ][ sMinut ] > 0 || stalkInfo[ id ][ sHour ] > 0 )
				{
					if( stalkInfo[ id ][ sType ] == BILJKA_SLJIVA )
					{
						format( string, sizeof( string ), "{09AFFF}| %s |\nPlodovi jos nisu zreli za branje!\nVrijeme do sazrijevanja: %dh i %dmin", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//Sljiva
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_KRUSKA )
					{
						format( string, sizeof( string ), "{FFFF04}| %s |\nPlodovi jos nisu zreli za branje!\nVrijeme do sazrijevanja: %dh i %dmin", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//kruska
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_JABUKA )
					{
						format( string, sizeof( string ), "{80FF00}| %s |\nPlodovi jos nisu zreli za branje!\nVrijeme do sazrijevanja: %dh i %dmin", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//jabuka
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_KUPUS )
					{
						format( string, sizeof( string ), "{458A00}| %s |\nPlod jos nije zreo za branje!\nVrijeme do sazrijevanja: %dh i %dmin", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//kupus
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_RUZE )
					{
						format( string, sizeof( string ), "{F90000}| %s |\nCvijet jos nije zreo za branje!\nVrijeme do sazrijevanja: %dh i %dmin", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//ruze
					}

				}
				else if( stalkInfo[ id ][ sGrow ] == true && stalkInfo[ id ][ sMinut ] == 0 && stalkInfo[ id ][ sHour ] == 0 )
				{

					if( stalkInfo[ id ][ sType ] == BILJKA_SLJIVA )
					{
						format( string, sizeof( string ), "{09AFFF}| %s |\nSljive su zrele za branje!\nDa oberes sljivu /oberidrvo", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//Sljiva
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_KRUSKA )
					{
						format( string, sizeof( string ), "{FFFF04}| %s |\nKruske su zrele za branje!!\nDa oberes krusku /oberidrvo", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//kruska
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_JABUKA )
					{
						format( string, sizeof( string ), "{80FF00}| %s |\nJabuke su zrele za branje!!\nDa oberes jabuku /oberidrvo", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//jabuka
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_KUPUS )
					{
						format( string, sizeof( string ), "{458A00}| %s |\nKupus je zreo za branje!\nDa poberes kupus /oberidrvo", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//kupus
					}
					else if( stalkInfo[ id ][ sType ] == BILJKA_RUZE )
					{
						format( string, sizeof( string ), "{F90000}| %s |\nCvijet je zreo za branje!!\nDa oberes ruzu /oberidrvo", vrsta, stalkInfo[ id ][ sHour ], stalkInfo[ id ][ sMinut ] );//ruze
					}

					
				}
				
				stalkInfo[ id ][ s3D ] = CreateDynamic3DTextLabel( string, -1, stalkInfo[ id ][ sPos ][ 0 ]+1, stalkInfo[ id ][ sPos ][ 1 ], stalkInfo[ id ][ sPos ][ 2 ], 15 );
			}
		}
	}
	//------[GPS]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje BG-GPS sistema...");
	for( new id = 1; id < MAX_BGGPS; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'GPS LOKACIJE' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_BGGPS, id );

		if( fexist( filename ) )
		{
			INI_ParseFile( filename, "BGLoadGPS", .bExtra = true, .extra = id );
		}
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje SA-GPS sistema...");
	for( new id = 1; id < MAX_SAGPS; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'SAGPS' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_SAGPS, id );

		if( fexist( filename ) )
		{
			INI_ParseFile( filename, "SALoadGPS", .bExtra = true, .extra = id );
		}
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje ZG-GPS sistema...");
	for( new id = 1; id < MAX_ZGGPS; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'ZGGPS' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_ZGGPS, id );

		if( fexist( filename ) )
		{
			INI_ParseFile( filename, "ZGLoadGPS", .bExtra = true, .extra = id );
		}
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje GPS postavki...");
	for( new id = 1; id < MAX_OSGPS; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'OSGPS' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_OSGPS, id );

		if( fexist( filename ) )
		{
			INI_ParseFile( filename, "OSLoadGPS", .bExtra = true, .extra = id );
		}
	}
	//------[Garaze]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje garaza...");
	for( new id = 1; id < MAX_GARAGES; id++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'GARAZE' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_GARAGE, id );

		if( fexist( filename ) ) {

			new string[ 256 ], vrsta[ 20 ];

			INI_ParseFile( filename, "LoadGarages", .bExtra = true, .extra = id );

			switch( garageInfo[ id ][ garageType ] ) {
				case 0:
				{
					vrsta = "N/A";
				}
				case 1:
				{
					vrsta = "Mala garaza";
				}
				case 2:
				{
					vrsta = "Srednja garaza";
				}
				case 3:
				{
					vrsta = "Velika garaza";
				}
			}

			
			if( !garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_orange"[ GARAZA >> NA PRODAJU - "col_white"ID: %d ]\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Cena garaze: "col_white"%d\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za kupovinu kucajte "col_white"/kupigarazu", id, vrsta, garageInfo[ id ][ garagePrice ], garageInfo[ id ][ garageLevel ] );
			}
			else if( garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_orange"[ GARAZA >> U VLASNISTVU - "col_white"ID: %d ]\n"col_orange"Vlasnik: "col_white"%s\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za ulaz koristite "col_white"/genter", id, garageInfo[ id ][ garageOwner ], vrsta, garageInfo[ id ][ garageLevel ] );
			}
			garageInfo[ id ][ garage3D ] = CreateDynamic3DTextLabel( string, BELA, garageInfo[ id ][ garagePos ][ 0 ], garageInfo[ id ][ garagePos ][ 1 ], garageInfo[ id ][ garagePos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			garageInfo[ id ][ garagePickup ] = CreateDynamicPickup( 19130, 1, garageInfo[ id ][ garagePos ][ 0 ], garageInfo[ id ][ garagePos ][ 1 ], garageInfo[ id ][ garagePos ][ 2 ], 0, 0 );
		}
	}
	
	//------[GZone]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje gangzona...");
	for( new id = 1; id < MAX_GZONE; id++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'GANG ZONE' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_GZONE, id );

		if( fexist( filename ) ) {

			new string[ 256 ];

			INI_ParseFile( filename, "GZone_Load", .bExtra = true, .extra = id );

			gZoneInfo[ id ][ gZoneTime ] = 0;
			if( !gZoneInfo[ id ][ gZoneTaken ] ) {
			
				gZoneInfo[ id ][ gZonePickup ] = CreateDynamicPickup( 1313, 1, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 0, 0 );
				gZoneInfo[ id ][ gZone3D ] = CreateDynamic3DTextLabel( ""col_white"[ TERITORIJA ]\nTeritorija je "col_balkanstory"slobodna"col_white"\nAko zelis da je zauzmes kucaj "col_balkanstory"/zauzmi", BELA, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			}
			else if( gZoneInfo[ id ][ gZoneTaken ] ) {

				gZoneInfo[ id ][ gZonePickup ] = CreateDynamicPickup( 1313, 1, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 0, 0 );
				format( string, sizeof( string ), ""col_white"[ TERITORIJA ]\nTeritorija je u vlasnistvu bande "col_balkanstory"%s"col_white"\nAko zelis da je zauzmes kucaj "col_balkanstory"/zauzmi",  OI[ gZoneInfo[ id ][ gZoneGangID ] ][ oName ] );
				gZoneInfo[ id ][ gZone3D ] = CreateDynamic3DTextLabel( string, BELA, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			}
			
			gZoneInfo[ id ][ gZoneID ] = GangZoneCreate( gZoneInfo[ id ][ gZoneMinX ], gZoneInfo[ id ][ gZoneMinY ], gZoneInfo[ id ][ gZoneMaxX ], gZoneInfo[ id ][ gZoneMaxY ] );
			gZoneInfo[ id ][ gZoneRectAngle ] = CreateDynamicRectangle( gZoneInfo[ id ][ gZoneMinX ], gZoneInfo[ id ][ gZoneMinY ], gZoneInfo[ id ][ gZoneMaxX ], gZoneInfo[ id ][ gZoneMaxY ], -1, -1, -1 );
		}
	}

	//------[Parkinzi]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje parkinga...");
	for( new parkID = 1; parkID < MAX_PARKINGS; parkID++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'PARKINZI' pod sektorom: %i",parkID);
		new filename[ 32 ];
		format( filename, sizeof( filename ), PARKING_FILE, parkID );

		if( fexist( filename ) ) {
		
			INI_ParseFile( filename, "Parking_Load", .bExtra = true, .extra = parkID );
			
			new string[ 128 ];
			
			format( string, sizeof( string ), "{FFFFFF}[ PARKING APARAT | "col_sanm"%d"col_white" ]\n{FFFFFF}Da kupite parking listic kucajte\n( "col_balkanstory"/kupiparkinglistic {FFFFFF})", parkID );
			ParkingInfo[ parkID ][ park3d_1 ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 2 ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
			ParkingInfo[ parkID ][ parkPickup_1 ] = CreateDynamicPickup( 1239, 1, ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 2 ], 0, 0 );
		
			format( string, sizeof( string ), "{FFFFFF}[ PARKING ZONA | "col_sanm"%d"col_white" ]\n{FFFFFF}Otidjite do aparata\nda bi kupili ( "col_balkanstory"parking listic {FFFFFF})", parkID );
			ParkingInfo[ parkID ][ park3d_2 ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 2 ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
			ParkingInfo[ parkID ][ parkPickup_2 ] = CreateDynamicPickup( 1239, 1, ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 2 ], 0, 0 );

			ParkingInfo[ parkID ][ parkObject ] = CreateDynamicObject( 4639, ParkingInfo[ parkID ][ parkObjectPos ][ 0 ], ParkingInfo[ parkID ][ parkObjectPos ][ 1 ], ParkingInfo[ parkID ][ parkObjectPos ][ 2 ], ParkingInfo[ parkID ][ parkObjectPos ][ 3 ], ParkingInfo[ parkID ][ parkObjectPos ][ 4 ], ParkingInfo[ parkID ][ parkObjectPos ][ 5 ], 0, 0, -1, 200.0 );

			ParkingInfo[ parkID ][ parkRectAngle ] = CreateDynamicRectangle( ParkingInfo[ parkID ][ parkMinX ], ParkingInfo[ parkID ][ parkMinY ], ParkingInfo[ parkID ][ parkMaxX ], ParkingInfo[ parkID ][ parkMaxY ], -1, -1, -1 );

		}
	}

	//------[Pokloni]------
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje poklona...");
	#if NERP_ZIMSKI_MOD  == 1

	for( new id = 1; id < MAX_CTREES; id++ ) 
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'DRVECA' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_CTREES, id );
		
		if( fexist( filename ) ) {
		
			new string[ 128 ];
		
			INI_ParseFile( filename, "LoadCTrees", .bExtra = true, .extra = id );
			
			if( CTree[ id ][ ctPlaced ] ) {
			
				format( string, sizeof( string ), "{6ef83c}Zelimo vam srecne Bozicne\ni novogodisnje praznike!\n*** 2021 ***" );
				CTree[ id ][ ct3d ] = CreateDynamic3DTextLabel( string, -1, CTree[ id ][ ctPos ][ 0 ], CTree[ id ][ ctPos ][ 1 ], CTree[ id ][ ctPos ][ 2 ]+2, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
				CTree[ id ][ ctObject ] = CreateDynamicObject(19076, CTree[ id ][ ctPos ][ 0 ], CTree[ id ][ ctPos ][ 1 ], CTree[ id ][ ctPos ][ 2 ], CTree[ id ][ ctPos ][ 3 ], CTree[ id ][ ctPos ][ 4 ], CTree[ id ][ ctPos ][ 5 ] );
			}
		}
	}
	
	for( new id = 1; id < MAX_XORBS; id++ ) {
		printf("[ SCRIPT ]: Ucitavanje modula 'POKLONI' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_XORBS, id );

		if( fexist( filename ) ) {

			new object = 19059;
			new rand = random( 5 );
			switch( rand ) {
				case 0: object = 19059;
				case 1: object = 19060;
				case 2: object = 19061;
				case 3: object = 19062;
				case 4: object = 19063;
			}

			INI_ParseFile( filename, "LoadXOrbs", .bExtra = true, .extra = id );

			if( XmasOrbs[ id ][ xoPlaced ] ) {

				XmasOrbs[ id ][ xoObject ] = CreateDynamicObject(object, XmasOrbs[ id ][ xoPos ][ 0 ], XmasOrbs[ id ][ xoPos ][ 1 ], XmasOrbs[ id ][ xoPos ][ 2 ], XmasOrbs[ id ][ xoPos ][ 3 ], XmasOrbs[ id ][ xoPos ][ 4 ], XmasOrbs[ id ][ xoPos ][ 5 ] );
			}
		}
	}
	#endif
	for( new id = 1; id < MAX_PRESENTS; id++ )
	{
		printf("[ SCRIPT ]: Ucitavanje modula 'SISTEM' pod sektorom: %i",id);
		new filename[ 32 ];
		format( filename, sizeof( filename ), F_PRESENTS, id );

		if( fexist( filename ) )
		{
		
			new string[ 128 ];
		
			INI_ParseFile( filename, "LoadPresents", .bExtra = true, .extra = id );
			
			if( presentsInfo[ id ][ presPlaced ] )
			{
			
				new object = 19054;
				new rand = random( 5 );
				switch( rand )
				{
					case 0: object = 19054;
					case 1: object = 19055;
					case 2: object = 19056;
					case 3: object = 19057;
					case 4: object = 19058;
				}
				
				if( !presentsInfo[ id ][ presTaken ] )
				{
				
					format( string,sizeof( string ), ""col_white"Poklon nije otvoren!\n\n"col_red"/poklon" );
					presentsInfo[ id ][ pres3d ] = CreateDynamic3DTextLabel( string, -1, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
					presentsInfo[ id ][ presObject ] = CreateDynamicPickup(object, 1, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], -1, -1);//CreateDynamicObject( object, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], presentsInfo[ id ][ presPos ][ 3 ], presentsInfo[ id ][ presPos ][ 4 ], presentsInfo[ id ][ presPos ][ 5 ] );
				}
				else if( presentsInfo[ id ][ presTaken ] )
				{
				
					format( string, sizeof( string ), ""col_white"Poklon je otvoren!" );
					presentsInfo[ id ][ pres3d ] = CreateDynamic3DTextLabel( string, -1, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
					presentsInfo[ id ][ presObject ] = CreateDynamicPickup(object, 1, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], -1, -1);//CreateDynamicObject( object, presentsInfo[ id ][ presPos ][ 0 ], presentsInfo[ id ][ presPos ][ 1 ], presentsInfo[ id ][ presPos ][ 2 ], presentsInfo[ id ][ presPos ][ 3 ], presentsInfo[ id ][ presPos ][ 4 ], presentsInfo[ id ][ presPos ][ 5 ] );
				}
			}
		}
	}
	//#endif
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje NovaSecurity sistema...");
	print("[NE:RP] - Nova Era | Ucitavanje NovaSecurity sistema...");

	if( fexist( "Ostalo/anticheat.ini" ) )
	{
		INI_ParseFile( "Ostalo/anticheat.ini", "LoadAntiCheat" );
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje konfiguracije...");
	print("[NE:RP] - Nova Era | Ucitavanje konfiguracije...");
	if( fexist( "Ostalo/serverstats.ini" ) )
	{
		INI_ParseFile( "Ostalo/serverstats.ini", "LoadServerStats" );
	}
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje poslova...");
	print("[NE:RP] - Nova Era | Ucitavanje NovaSecurity poslova...");
	if( fexist( "PlatePoslova/PosloviInfo.ini" ) )
	{
		INI_ParseFile( "PlatePoslova/PosloviInfo.ini", "LoadPosloviInfo" );
	}

	/*if( fexist( "Ostalo/StariParovi.ini" ) )
	{
		INI_ParseFile( "Ostalo/StariParovi.ini", "LoadStareParove" );
	}
*/
	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje teleportova...");
	print("[NE:RP] - Nova Era | Ucitavanje teleportova...");
	LoadBGAports( );//BG ADMIN PORT
	LoadSAAports( );//SA ADMIN PORT
	LoadZGAports( );//ZG ADMIN PORT
	LoadOSAports( );//OSTALE ADMIN PORT
	
	print("[NE:RP] - Nova Era | Ucitavanje ostalih stvari...");
	LoadBGSports( );
	LoadSASports( );
	LoadZGSports( );
	LoadOSSports( );
	

	SendRconCommand("hostname [NE:RP] - Nova Era | Ucitavanje skinova...");
	print("[NE:RP] - Nova Era | Ucitavanje skinova...");
	skinlist = LoadModelSelectionMenu("skins.txt"); // load skins for buy
	regskinlist = LoadModelSelectionMenu("skins.txt"); // load skins for buy

	print("[NE:RP] - Nova Era | Ucitavanje zavrseno!");

	return 1;
}
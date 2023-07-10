#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


forward connecttd(playerid,br);
public connecttd(playerid,br)
{
	if(br == 364)
	{
		new 
			camview = random(3);
		//SetPlayerVirtualWorld(playerid, random(9999));
		switch(camview)
		{
			case 0:
			{
				SetPlayerPos(playerid, 1148.4430,-1344.8217,13.6616);
				InterpolateCameraPos(playerid, 927.724792, -1286.564941, 51.656623, 1397.496093, -1415.905517, 32.533592, 30000);
				InterpolateCameraLookAt(playerid, 932.431823, -1288.218383, 51.324836, 1392.709960, -1414.556640, 32.011108, 30000);
			}
			case 1:
			{
				SetPlayerPos(playerid, 2275.1340,-1700.6871,13.6479);
				InterpolateCameraPos(playerid, 2042.767822, -1470.297851, 54.489799, 2546.400146, -1771.930541, 41.233219, 30000);
				InterpolateCameraLookAt(playerid, 2047.054321, -1472.868164, 54.349193, 2542.777832, -1768.697875, 40.037876, 30000);
			}
			case 2:
			{
				SetPlayerPos(playerid, 2411.5686,-1106.1973,40.1652);
				InterpolateCameraPos(playerid, 2515.796142, -1008.902709, 88.511833, 2062.358886, -1379.888061, 46.693622, 30000);
				InterpolateCameraLookAt(playerid, 2511.572509, -1011.466735, 87.745338, 2063.165771, -1375.001464, 46.008289, 30000);
			}
		}
		
		BRACETMLogoView(playerid, false);
		TextDrawShowForPlayer(playerid,betaversiontd);
		BRACETMLogoShowed[playerid] = false;

		Fading[ playerid ] = CreatePlayerTextDraw( playerid, -5.000, -2.000, "~n~");
		PlayerTextDrawFont(playerid, Fading[ playerid ], 3);
		PlayerTextDrawUseBox(playerid, Fading[ playerid ], 1);
		PlayerTextDrawLetterSize(playerid, Fading[ playerid ], 0.500000, 50.300003);
		PlayerTextDrawBoxColor(playerid, Fading[ playerid ], -1);
		PlayerTextDrawTextSize(playerid, Fading[ playerid ], 655.000, 625.000);
		PlayerTextDrawColor(playerid, Fading[ playerid ], -1);

		FadeFromBlack(playerid);

		new h,m,s;
		gettime(h,m,s);
		SetPlayerTime(playerid,h,m);
		
		//SendClientMessage(playerid, -1, ""col_balkanstory"[NE:RP] - "SERVERBOJA_SIVA"Ucitavanje servera...");
		PlayAudioStreamForPlayer(playerid, 
			"https://bracetm.000webhostapp.com/streams/NOVAERA_BACKGROUNDMUSIC.mp3");
		SetTimerEx( "connecttd", 2500, false, "ii", playerid, 1 );
		announcement(playerid, "Ucitavanje servera...");
		//SendPlayerNotification(playerid, true, "Ucitavanje~n~servera...");
	}
	if(br == 1)
	{
		TextDrawShowForPlayer(playerid,connect0);
		SetTimerEx( "connecttd", 3500, false, "ii", playerid, 2 );
	}
	if(br == 2)
	{
		TextDrawShowForPlayer(playerid,connect1);
		TextDrawShowForPlayer(playerid,connect4);
		TextDrawShowForPlayer(playerid,connect5);
		SetTimerEx( "connecttd", 3500, false, "ii", playerid, 3 );
	}
	if(br == 3)
	{
		TextDrawShowForPlayer(playerid,connect2);
		SetTimerEx( "connecttd", 3500, false, "ii", playerid, 4 );
	}
	if(br == 4)
	{
	
		TextDrawShowForPlayer(playerid,connect3);
		SetTimerEx( "connecttd", 3500, false, "ii", playerid, 6 );
	}
	if(br == 6)
	{
		ShowLogo(playerid);

		SetTimerEx( "connecttd", 3500, false, "ii", playerid, 5 );
		WifiConnectionTDControl(playerid, true);
	}
	if(br == 5)
	{
		if(!IsUsingSAMPP(playerid))
		{
			//SendInfoMessage(playerid, "Vi nemate SAMP+ addon u vasem GTA klijentu, nabavite ga radi boljeg dozivljaja na serveru!");
			announcement(playerid, "~r~Vi nemate SAMP+ addon!");
		}
		for( new i = 0; i < sizeof( ForbiddenNames ); i ++ ) {
			if( !strcmp( ImeIgraca( playerid ), ForbiddenNames[ i ], true ) ) {
				announcement(playerid, "Vase ime ovde nije dozvoljeno");
				Kickovanje( playerid, ""col_red""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Vase ime ovde nije dozvoljeno");
			}
		}

		#if NERP_ZIMSKI_MOD  == 1
		EffectTimer[ playerid ] = SetTimerEx( "ActionEffect", 1900, true, "d", playerid );
		#endif


		new playersip[ 128 ];
		GetPlayerIp( playerid, playersip, sizeof( playersip ) );
		new string[ 128 ];
		
		format( string, sizeof( string ), "Igrac: %s | IP: %s ", ImeIgraca( playerid ), playersip );
		LogSave( "Ostalo/LogConnect.log", string );
		
		if( fexist( Korisnici( playerid ) ) ) // LINE 71794
		{
			AccPostoji[playerid] = 1;
		}
		else
		{
			AccPostoji[playerid] = 0;
		}

		SetTimerEx("ClientSelectionTimer", 1000, false, "ii", playerid, 0);

		proveriAlias( playerid );
	
		CreatePlayerAltChat(playerid);
	}
	return 1;
}
forward connection(playerid);
public connection(playerid)
{
	//ZombieEvent_OnPlayerConnect(playerid);
	//SetPlayerCameraPos(playerid,2274.1978,-1549.6207,26.8750);
	//SetPlayerCameraLookAt(playerid,1962.0978,-1966.4637,41.8861);
	//SetPlayerTime(playerid, 0, 0);
	
	BrziRentVozilo[playerid] = -1;
	PlayAudioStreamForPlayer(playerid, 
		"https://bracetm.000webhostapp.com/streams/BRACETM_INTROSOUND.mp3");
	//FadeFromBlack(playerid);
	//PlayAudioStreamForPlayer( playerid, "https://jjs.jisiss.is/06282ea54b2fd6f81d892c84dda4114b/W4VTq0sa9yg/cauwcrnwcaewra");	
	ClearChat(playerid,20);

	ServerInfo[Online] += 1;
	
	ServerInfo[ BrojPosetaServeru ]++;
	GotoOff[playerid] = true;

	PekarInfo[playerid][xMisija] = 0;
	PekarInfo[playerid][xPreuzeoTjesto] = 0;

	DzeparosInfo[playerid][xMisija] = 0;

	LiderSkins[playerid] = 0;
	PlayerLogged[playerid] = false;

	PlayerInfo[playerid][xPosaoMisija] = 0;
	PlayerInfo[playerid][xUzeoMrtvoTelo] = 0;
	
	PlayerInfo[playerid][xPokupioAuto] = 0;

	Branje[playerid] = 0;

	PlayerInfo[playerid][xPUBG] = 0;
	Ranjen[playerid] = 0;

	PDuty[playerid] = false;
	PlayerInfo[playerid][xMreza] = 0;
	PlayerInfo[playerid][xTelAuto] = 0;

	PlayerInfo[playerid][xDeathScreen] = 0;

	grobar_car[ playerid ] = -1;
	inDrugFactory[playerid] = -1;
	inOrgGarage[playerid] = -1;

	gPlayerUsingLoopingAnim[playerid] = 0;
	gPlayerAnimLibsPreloaded[playerid] = 0;
	StopLoopingAnim(playerid);
	Modern[playerid] = 0;
	//PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
	g_NERP_Animation[playerid] = 0;

	LastOrgVehDetected[playerid] = -1;

	PlayerInfo[playerid][xPFV] = 0;

	CheckRekord( );
	//ObrisiObjekte( playerid );
	ResetPlayer( playerid );
	//UzeoDPlatu[playerid] = true;
	SetPlayerVirtualWorld(playerid, (playerid + 2000));
	SetPlayerColor(playerid, 0xAFAFAF00);

	
	SetTimerEx( "connecttd", 9500, false, "ii", playerid, 364 );
	return 1;
}

//glavniconnect
public OnPlayerConnect( playerid )
{
	if(IsPlayerNPC(playerid))
	{
		return 1;
	}
	BRACETMLogoView(playerid, true);
	PreloadWeaponIcons(playerid);
	CreatePlayerTextDraws( playerid );
	PreloadAnimations( playerid );
	CallLocalFunction("ANIM_OnPlayerConnect", "i", playerid);
	RemoveBuildings(playerid);
	BRACETMLogoShowed[playerid] = true;
	TogglePlayerSpectating(playerid, 1);
	PlayerInfo[playerid][xGamemode] = 0;
	ToggleHUDComponentForPlayer(playerid, 
		HUD_COMPONENT_WEAPON, false);
	ToggleHUDComponentForPlayer(playerid, 
		HUD_COMPONENT_HEALTH, false);
	ToggleHUDComponentForPlayer(playerid, 
		HUD_COMPONENT_MONEY, false);
	ToggleHUDComponentForPlayer(playerid, 
		HUD_COMPONENT_AMMO, false);
	//PlayAudioStreamForPlayer(playerid, 
	//	"https://bracetm.000webhostapp.com/streams/gta_sa_remix.mp3");
	#if defined JEBOTE_MYSQL_U_GUZICU
	mysql_data_user(playerid);
	#endif

	SetTimerEx( "connection", 4000, false, "i", playerid );

	for(new i; i < 50; i++)
	{
		SendClientMessage(playerid, -1, " ");
	}
	CallLocalFunction("NERP_OPC", "i", playerid);
	return true;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect NERP_OPCeee

forward NERP_OPCeeee(playerid);

public OnPlayerDisconnect( playerid, reason )
{
	CallLocalFunction("ZombieEvent_CloseConnection", "i", playerid);
	DestroyDynamic3DTextLabel(br_label[playerid]);
	PlayerTextDrawHide( playerid, MoneyBar[playerid]);
	DestroyPlayerAltChat(playerid);
	#if defined JEBOTE_MYSQL_U_GUZICU
	mysql_acc_save(playerid);
	#endif
	killrentveh(playerid);
	#if BETA_BUILD == 1
	hidebatd(playerid);
	#endif
	Modern[playerid] = 0;
	KillTimer(PinDur[playerid]);
	KillTimer(DeathAfterInjury[playerid]);
	KillTimer(BHKrajTimer[playerid]);
	KillTimer(animtimer[playerid]);
	

	if( grobar_car[playerid] != -1 )
	{
		Dimi_DestroyVehicle( grobar_car[ playerid ] );
		grobar_car[ playerid ] = -1;
		ServerInfo[ PreuzetoGrobarVoziilo ] = false;
		KillTimer(AutoRespawnGrobarVozila(playerid));
		Delete3DTextLabel( grobar_car_label[playerid] );
	}
	ServerInfo[Online] -= 1;


	Delete3DTextLabel(adutylabel[playerid]);
	Delete3DTextLabel(gmdutylabel[playerid]);
	//DestroyPlayerVehicles( playerid );

	new lastid = playerid;
	if( IsValidDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] ) )
	{
		DestroyDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] );
	}
	
	for(new t = 0; t < GRADJEVINARHRPICE; t++)//ovdje povecat broj kad doradimo objekte
	{
		if( IsValidDynamicObject( pijesakhrpa[playerid][t] ) )
		{
			DestroyDynamicObject(pijesakhrpa[playerid][t]);
		}
	}
	
	
	
	
	if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] ) )
	{
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
	}

	if( IsValidDynamicCP( PlayerGpsRadar[ playerid ][ _pgrCheckPointId ] ) )
	{
		DestroyDynamicCP( PlayerGpsRadar[ playerid ][ _pgrCheckPointId ] );
	}

	ExitPlayerFromSlotMachine( playerid );
	if( Start[ playerid ] != PlayerText:INVALID_TEXT_DRAW )
	{
		Delete_PokerTextDraw( playerid );
	}

	TextDrawHideForPlayer( playerid, Digit1[ 0 ]);
	TextDrawHideForPlayer( playerid, Digit2[ 0 ]);
	TextDrawHideForPlayer( playerid, Digit3[ 0 ]);

	TextDrawHideForPlayer( playerid, Digit1[ 1 ]);
	TextDrawHideForPlayer( playerid, Digit2[ 1 ]);
	TextDrawHideForPlayer( playerid, Digit3[ 1 ]);

	TextDrawHideForPlayer( playerid, Digit1[ 2 ]);
	TextDrawHideForPlayer( playerid, Digit2[ 2 ]);
	TextDrawHideForPlayer( playerid, Digit3[ 2 ]);

	TextDrawHideForPlayer( playerid, Digit1[3]);
	TextDrawHideForPlayer( playerid, Digit2[3]);
	TextDrawHideForPlayer( playerid, Digit3[3]);

	TextDrawHideForPlayer( playerid, Digit1[4]);
	TextDrawHideForPlayer( playerid, Digit2[4]);
	TextDrawHideForPlayer( playerid, Digit3[4]);

	TextDrawHideForPlayer( playerid, Digit1[5]);
	TextDrawHideForPlayer( playerid, Digit2[5]);
	TextDrawHideForPlayer( playerid, Digit3[5]);

	TextDrawHideForPlayer(playerid,Box);
	TextDrawHideForPlayer(playerid,ReadyText);

	if(SlotTimer[ playerid ] != -1) KillTimer(SlotTimer[ playerid ]);

	if( IsPlayerInAnyVehicle( playerid ) )
	{
		new Float:x,Float:y,Float:z,vehicleid = GetPlayerVehicleID(playerid);
		GetVehiclePos( vehicleid,x, y, z );
		RealVehiclePositions[ vehicleid ][ 0 ] = x;
		RealVehiclePositions[ vehicleid ][ 1 ] = y;
		RealVehiclePositions[ vehicleid ][ 2 ] = z;
	}

	antiCheatCS[ playerid ][ CPSCount ] = 0;
	antiCheatCS[ playerid ][ CPSTick ] = 0;
	antiCheatCS[ playerid ][ CWTime ] = 0;
	antiCheatCS[ playerid ][ CWVehID ] = -1;

	if( IsValidPlayerObject( playerid, farmerInfo[ playerid ][ fiBucketObject ] ) )
		DestroyPlayerObject( playerid, farmerInfo[ playerid ][ fiBucketObject ] );

	if( farmerInfo[ playerid ][ fiVehicleBucket ] != -1 )
	{
		new farmvehicle = farmerInfo[ playerid ][ fiVehicleBucket ];

		farmerVehicles[ farmvehicle ][ fvMilk ] = false;
		farmerVehicles[ farmvehicle ][ fvMilkpID ] = -1;
	}

	if( SearchNadji[ playerid ] != -1 ) {
		SearchNadji[ playerid ] = -1;
		Dimi_DisablePlayerCheckpoint( playerid);
	}

	#if NERP_ZIMSKI_MOD  == 1
	if( Snow[ playerid ] ) DestroyPlayerObject( playerid, SnowObject[ playerid ] );
	#endif
	#if kladionica == 1
	if( ListaPrikazana[ playerid ] )
	{
		KladionicaTDControl( playerid, false );
	}
	if( MojListicPrikazan[ playerid ] )
	{
		KladionicaListicTDControl( playerid, false );
	}
	if( RezultatiPrikazana[ playerid ] )
	{
		RezultatiTDControl( playerid, false );
	}
	#endif
	if( PlayerInBlowJob[ playerid ] != 0 )
	{

		switch( PlayerInBlowJob[ playerid ] )
		{

			case 1:
			{
			
				DestroyActor( Sex_Lisa );
				WhoreLisa = false;
			}
			case 2: {
			
				DestroyActor( Sex_Angelina );
				WhoreAngelina = false;
			}
			case 3: {
			
				DestroyActor( Sex_Mia );
				WhoreMia = false;
			}
			case 4: {
			
				DestroyActor( Sex_Sendy );
				WhoreSendy = false;
			}
		}

		StopAudioStreamForPlayer( playerid );
		SetCameraBehindPlayer( playerid );
		PlayerInBlowJob[ playerid ] = 0;
		SexTDControl( playerid, false );
		BlowJobCount[ playerid ] = 0;
		TogPlayerHud( playerid );
		TogglePlayerControllable( playerid, ( true ) );
		ClearAnimations( playerid );
		Dimi_KillTimer( PusenjeTimer[ playerid ] );
	}

	switch( reason ) {
		case 0: {
			format( globalstring, sizeof( globalstring ), "[LEAVE] | Crash: Igrac %s je napustio server zbog pada igrice!", ImeIgraca( playerid ) );
			PorukaRadius( 60.0 , playerid, globalstring, 0xBFC0C2FF );
		}
		case 1: {
			format( globalstring, sizeof( globalstring ), "[LEAVE] | Disconnect: Igrac %s je upravo izasao servera!", ImeIgraca( playerid ) );
			PorukaRadius( 60.0 , playerid, globalstring, 0xBFC0C2FF );
		}
	}

	if( GetPVarInt( playerid, "Computer" ) == 1 ) {
		Police_TVTDControl( playerid, false );
		SetPVarInt( playerid, "Computer", 0 );
	}

	DestroyPlayerTextDraws( playerid );

	if( IgracSeRegistruje[ playerid ] == true ) RegisterTDControl( playerid, false );

	if( AdminVozilo[ playerid ] != -1 ) Dimi_DestroyVehicle( AdminVozilo[ playerid ] ), AdminVozilo[ playerid ] = -1;

	if( TrkaVozilo[ playerid ] != -1 ) Dimi_DestroyVehicle( TrkaVozilo[ playerid ] ), TrkaVozilo[ playerid ] = -1;

	if( HitmanInfo[ playerid ][ GotHit ] > 0) {
		if( HitmanInfo[ playerid ][ GetChased ] < 999 ) {
			if( IsPlayerConnected( HitmanInfo[ playerid ][ GetChased ] ) ){
				SendClientMessagee( HitmanInfo[ playerid ][ GetChased ], ZUTA, "Vasa meta je izasla sa servera." );
				HitmanInfo[ HitmanInfo[ playerid ][ GetChased ] ][ GoChase ] = 999;
			}
		}
	}
	
	if( garbagemanInfo[ playerid ][ gmiJob ] == true ) {

		new vehicleid = garbagemanInfo[ playerid ][ gmiVehicleID ];

		garbagemanVehicles[ vehicleid ][ gGarbages ] = 0;
		garbagemanVehicles[ vehicleid ][ gPlayerID ] = -1;

		SetVehicleToRespawn( vehicleid );
	}
	
	if( PlayerCement[ playerid ] != -1 ) VehCement[ PlayerCement[ playerid ] ] = false;
	if( IDBusaKojiVozi[ playerid ] != -1) IDIgracaKojiVoziBus[ IDBusaKojiVozi[ playerid ] ] = -1;

	if( DeliverCar[ playerid ] != -1 ) KamionUsed[ DeliverCar[ playerid ] ] = -1, StateBox[ DeliverCar[ playerid ] ] = 0;

	if( IDVozilaKojimSverca[ playerid ] != -1 ) KutijaMatsa[ IDVozilaKojimSverca[ playerid ] ] = false;
	
	if( PlayerPrevozNovca[ playerid ] != -1 ) VehNovac[ PlayerPrevozNovca[ playerid ] ] = false;

	if( PljackaVreme[ playerid ] > 0 ) Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] ), PljackaUToku = false;
	
	PljackaNovac[ playerid ] = 0;
	VremeZaNovac[ playerid ] = 0;
	PljackaVreme[ playerid ] = 0;
	
	if( ZlatoVreme[ playerid ] > 0 ) Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] ), ZlataraUToku = false;
	
	PljackaZlato[ playerid ] = 0;
	VremeZaZlato[ playerid ] = 0;
	ZlatoVreme[ playerid ] = 0;
	
	if( DragedPlayerID[ playerid ] != -1 ) {

		format( globalstring, sizeof( globalstring ), "%s je napustio server, pusteni ste.", ImeIgraca( playerid ) );
		SendClientMessagee( DragedPlayerID[ playerid ], -1, globalstring );
		TogglePlayerControllable( DragedPlayerID[ playerid ], 1 );
		Draged[ DragedPlayerID[ playerid ] ] = -1;
	}
	
	if( farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] != -1 ) {
	
		for( new plantid = 0; plantid < MAX_FARMS; plantid++ ) {
		
			if( plantInfo[ plantid ][ farmPlantCreated ] && plantInfo[ plantid ][ farmPlayerID ] == lastid ) {
			
				if( IsValidDynamic3DTextLabel( plantInfo[ plantid ][ farm3D ] ) )
					DestroyDynamic3DTextLabel( plantInfo[ plantid ][ farm3D ] );

				if( IsValidDynamicObject( plantInfo[ plantid ][ farmObject ] ) )
					DestroyDynamicObject( plantInfo[ plantid ][ farmObject ] );

				ResetFarmPlant( plantid );
			}
		}
	}

	PlayerTextDrawDestroy( playerid, PlayerGpsRadarText[ playerid ] );

	if( PitanjeBroj[ playerid ] != 0 ) Dimi_KillTimer( TimerPitanje[ playerid ] );
	
	Dimi_KillTimer( atmrobTimer[ playerid ] );
	
	if( PocetniTutorialStartovan[ playerid ] == true ) Dimi_KillTimer( TimerTutorial[ playerid ] );
	
	Dimi_KillTimer( FarbanjeTimer[ playerid ] );
	
	if( PlayerInfo[ playerid ][ xUbijen ] == 1 ) //Dimi_KillTimer( BolnicaTimer[ playerid ] );
		PlayerInfo[ playerid ][ xUbijen ] = 0; 

	#if nerp_droga == 1
	if( IgracPosadio[ playerid ] != 0 )
	{
		for( new plantid = 1; plantid < MAX_PLANTS; plantid++ )
		{
			if( strcmp( ImeIgraca( playerid ), DrogaStab[ plantid ][ wOwner ], true ) == 0 )
			{
				if( DrogaStab[ plantid ][ wPlanted ] == 1 )
				{
					DrogaStab[ plantid ][ Plantx ] = 0;
					DrogaStab[ plantid ][ Planty ] = 0;
					DrogaStab[ plantid ][ Plantz ] = 0;
					DrogaStab[ plantid ][ wType ] = 0;
					DrogaStab[ plantid ][ wPlanted ] = 0;
					DrogaStab[ plantid ][ wHoursPassed ] = 0;
					strmid( DrogaStab[ plantid ][ wOwner ], "Niko", 0, strlen( "Niko" ), 255);
					DrogaStab[ plantid ][wViwo] = GetPlayerVirtualWorld( playerid );
					DestroyDynamicObject( DrogaStab[ plantid ][ wObjectID ] );
				}
			}
		}
	}
	#endif
	if( PlayerInfo[ playerid ][ xPosao ] == POSAO_MEHANICAR ) {
		if(GetPVarInt( playerid, "JobDuty") == 1) { Mechanics -= 1; }
	}

	if( PlayerBuyingAS[ playerid ] != -1 ) {
		AutoSalon[ PlayerBuyingAS[ playerid ] ][ AlreadyBuying ] = false;
		PlayerBuyingAS[ playerid ] = -1;
	}

	antiCheatCS[ playerid ][ ArmedWeapon ] = 0;

	if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) {
		format( globalstring, sizeof( globalstring ), ""col_orange"WAR | {F81414}%s: "col_white"je napustio WAR.", ImeIgraca( playerid ) );
		WARPoruka( WARPInfo[ playerid ][ WARIgrac ], 0xFF9900AA, globalstring );
		WARInfo[ WARPInfo[ playerid ][ WARIgrac ] ][ WARTimClanovi ][ 0 ]--; }

	if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) {
		format( globalstring, sizeof( globalstring ), ""col_orange"WAR | "col_balkanstory"%s: "col_white"je napustio WAR.", ImeIgraca( playerid ) );
		WARPoruka( WARPInfo[ playerid ][ WARIgrac ], 0xFF9900AA, globalstring );
		WARInfo[ WARPInfo[ playerid ][ WARIgrac ] ][ WARTimClanovi ][ 1 ]--; }

	if( Rentano[ playerid ] != -1 ) {
		Dimi_KillTimer( RentTimer[ playerid ] );
		VehicleObjectCheck( Rentano[ playerid ] );
		SetVehicleToRespawn( Rentano[ playerid ] );
		LinkVehicleToInterior( Rentano[ playerid ], 0 );
		Rentano[ playerid ] = -1;
	}

	if( PlayerCuffed[ playerid ] >= 1 )
	{
		if( PlayerInfo[ playerid ][ xZatvor ] == 0 )
		{
			PlayerInfo[ playerid ][ xZatvor ] = OBICAN_ZATVOR;
			PlayerInfo[ playerid ][ xZatvorVreme ] = 60;
			strmid( PlayerInfo[ playerid ][ xOffPJail ], "LTA", 0, strlen("LTA"), 64 );
		}
	}

	if( PlayerInfo[ playerid ][ xWanted ] > 0 )
	{
		if( PlayerInfo[ playerid ][ xZatvor ] == 0 )
		{
			for(new i; i < MAX_PLAYERS; i++)
			{
				if( IsPlayerConnected( i ) )
				{
					if( GetFactionType( i ) == ORG_TIP_PD && CrimInRange( 40.0, playerid, i ) )
					{
		
						PlayerInfo[ playerid ][ xLeaveJail ] = true;
						PlayerInfo[ playerid ][ xZatvor ] = OBICAN_ZATVOR;
						PlayerInfo[ playerid ][ xZatvorVreme ] = 6*PlayerInfo[ playerid ][ xWanted ];
						new price = PlayerInfo[ playerid ][ xWanted ]*500;
						PlayerInfo[ playerid ][ xNovac ] -= price;
						PlayerInfo[ playerid ][ xWanted ] = 0;
					}
				}
			}
		}
	}

	if( GetFactionType( playerid ) == ORG_TIP_MD ) {
		if( MedicDuty[ playerid ] == true ) { Medics -= 1; }
	}

	if( GetPVarInt(playerid, "BreakingLock") == 1 )
	{
		Dimi_KillTimer( GetPVarInt( playerid, "BreakLockTimer" ) );
	}

	if( GetPVarInt( playerid, "ImmobTimerCalled") == 1 )
	{
		Dimi_KillTimer( GetPVarInt( playerid, "immobcounttimer" ) );
	}

	if( GetPVarInt( playerid, "BreakLockTimerCalled" ) == 1 )
	{
		Dimi_KillTimer( GetPVarInt( playerid, "breakcounttimer" ) );
	}


	if( BoomboxInfo[ playerid ][ boomboxPlaced ] ) {
		Boombox_Destroy( playerid );
	}

	if( antiCheatCS[ playerid ][ TakeVehicle ] != INVALID_VEHICLE_ID ) {
		BusyVehicle[ antiCheatCS[ playerid ][ TakeVehicle ] ] = -1;
	}

	if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) SacuvajAdmina( playerid );

	if( PlayerLogged[ playerid ] == true ) {
		SavePlayer( playerid );
	}

	if( Uciskolu[ playerid ] == true ) { Dimi_KillTimer( SkolaTimer[ playerid ] ); }

	if( CistacPosao[ playerid ] == true )  { Dimi_KillTimer( CistacTimer[ playerid ] ); }

	if( TrashSearch[ playerid ] == 1 )  { Dimi_KillTimer( TrashTimer[ playerid ] ); }

	if( GetPVarInt( playerid, "RequestingBackup" ) == 1 ) {
		Dimi_KillTimer( backuptimer[ playerid ] );
		BackupClear( playerid, 0 );
	}

	if( KupujeNamestaj[ playerid ] == 1 ) {
		nekokupujenamestaj = 0;
		KupujeNamestaj[ playerid ] = 0;
	}

	if( offeredByCabbie[ playerid ] != INVALID_PLAYER_ID )
	{
		TaximetarUkljucen[ offeredByCabbie[ playerid ] ] = false;

		PlayerTextDrawSetString( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 7 ], "N/A" );
		PlayerTextDrawShow( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 7 ] );
		
		PlayerTextDrawSetString( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 5 ], "N/A" );
		PlayerTextDrawShow( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 5 ] );

		CenaVoznje[ offeredByCabbie[ playerid ] ] = 0;
		VoziIgracaID[ offeredByCabbie[ playerid ] ] = INVALID_PLAYER_ID;
		Dimi_KillTimer( TaxiTimer[ offeredByCabbie[ playerid ] ] );
		offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
	}

	if( GetPVarInt( playerid, "CuffTimerCalled") == 1 )
	{
		Dimi_KillTimer( TazerTimer[ playerid ] );
	}

	if( AdminDuty[ playerid ] ) {
		AdminDuty[ playerid ] = false;
	}

	if( KrenuoKosenje[ playerid ] )
	{
		for( new i = 0; i < 76; i++)
		{
			if( IsValidDynamicObject( Grass[ playerid ][ i ] ) )
			{
				DestroyDynamicObject( Grass[ playerid ][ i ] );
				RemovePlayerMapIcon(playerid, i);
			}
		}
	}
	
	if(KrenuoZetvu[ playerid ] )
	{
		for( new i = 0; i < 72; i++)
		{
			if( IsValidDynamicObject( ZitoObjects[ playerid ][ i ] ) )
			{
				DestroyDynamicObject( ZitoObjects[ playerid ][ i ] );
				RemovePlayerMapIcon(playerid, i);
			}
		}
	}
	
	CallLocalFunction("NERP_OPD","ii",playerid, reason);
	
	return true;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect NERP_OPDeee

forward NERP_OPDeee(playerid, reason);

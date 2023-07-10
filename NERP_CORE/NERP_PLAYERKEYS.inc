
/*
*
*	NERP ROLEPLAY SAMP SERVER
*	By DEntisT
*
*	Player key states
*					beta 1.0
*
*/


#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


public OnPlayerKeyStateChange( playerid, newkeys, oldkeys )
{
	CallLocalFunction("ANIM_OnPlayerKeyStateChange", "iii", playerid,newkeys,oldkeys);
	if( !IsPlayerInAnyVehicle(playerid) && newkeys & KEY_JUMP && oldkeys & KEY_SPRINT)
	{
		if(UkljucenBH == 1 && PlayerInfo[playerid][xBHD] == 0 && Ranjen[playerid] == 0)
		{
			BunnyHopPokusaji[playerid] ++;
			if( BunnyHop[playerid] == 1)
			{
				LoopingAnim(playerid,"PED","IDLE_tired",3.0,1,0,0,0,0);
				return false;
			}
			if(BunnyHopPokusaji[playerid] == 3)
			{
		   
				SendClientMessage( playerid,-1,""col_balkanstory"[ BUNNY HOP ]: {FFFFFF}Zabranjen je Bunny Hop, procitajte pravila servera na"col_balkanstory" /forum{ffffff}!");

			  
				BunnyHop[playerid] = 1;
				TogglePlayerControllable(playerid,0);

				PreloadAnimationLibrary(playerid,"PED");

				BHKrajTimer[playerid] = SetTimerEx("BHkraj", 4000, false, "i", playerid); 

				animtimer[playerid] = SetTimerEx("animacijabh", 150, false, "i", playerid);

				SendInfoMessage(playerid,"Uganuli ste clanak, pricekajte dok se odmorite.");
			}
		}
	}
	if(!gPlayerUsingLoopingAnim[playerid]){}
	if(IsKeyJustDown(KEY_HANDBRAKE,newkeys,oldkeys))
	{
		if(Ranjen[playerid] == 1) return 1;
		StopLoopingAnim(playerid);
		//PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
		g_NERP_Animation[playerid] = 0;
	}
	#if NERP_ZIMSKI_MOD  == 1
	if( Snow_F[ playerid ] ) {
	
		if( Shoot[ playerid ] == 0 ) {
		
			if( newkeys & 128 ) {

				if( Charged[ playerid ] == 1 ) return CheckSnow( playerid );
				else if( Charged[ playerid ] == 0 ) return ApplyAnimation( playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0 ), Charged[ playerid ] = 1;
			}
		}
	}
	#endif

	//ZA RUCNU KOCNICU, rucna kocnica
	
	new autos = GetVehicleModel(GetPlayerVehicleID(playerid));
	new stats = GetPlayerState(playerid);
	if(autos != 509 && autos != 481 && autos != 510 && autos != 519 && autos != 520 && autos != 553 && autos != 592 && autos != 460 && autos != 476 && autos != 511 && autos != 512 && autos != 513)
	{
		if(stats == PLAYER_STATE_DRIVER)
		{

			if(HOLDING(KEY_HANDBRAKE))
			{
				announcement(playerid, "Rucna kocnica podignuta!", 3000);
			}

		}

	}
	
	//
	
	if( PRESSED( KEY_SUBMISSION ) )
	{
		if( IsPlayerInAnyVehicle( playerid ) && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER )
		{
			new vehicle = GetPlayerVehicleID( playerid ),
				engine,lights,alarm,doors,bonnet,boot,objective;

			if( vCanDrive[ vehicle ] == 0 ) return GRESKA( playerid, "Ovo vozilo je unisteno i ne moze se pokrenuti.");
			if( IsVehicleBajs( vehicle ) ) return GRESKA( playerid, "Stvarno mislis upaliti biciklu? " );
			if( Fuel[ vehicle ] == 0 ) return GRESKA( playerid, "Vozilo nema goriva ne mozete ga upaliti." );

			if( TipVozila[ vehicle ] == PRIVATNO_VOZILO )
			{
			
				if( PlayerInfo[ playerid ][ xAdmin ] >= 5 ) { }
				else
				{
					if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 && VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vID ] == vehicle ) { }
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 && VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vID ] == vehicle ) { }
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 && VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vID ] == vehicle ) { }
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 && VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vID ] == vehicle ) { }
					else if( PlayerInfo[ playerid ][ xRezervniKljucevi ] == ScriptIDVozila[ vehicle ] ) { }
					else return GRESKA( playerid, "Ovo nije vase vozilo." );
				}

				GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
				if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
				if( Maskuse[ playerid ] == true )
					format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
				else
					format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
				PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
				SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
				SetPVarInt( playerid, "StartingVehicle", 1 );
			
			}
			
			else if( TipVozila[ vehicle ] == NAPRODAJU_VOZILO )
			{

				if( PlayerInfo[ playerid ][ xAdmin ] >= 1338 && AdminDuty[playerid] ) { }
				else return GRESKA( playerid, "Ne mozes pokrenuti vozilo koje je na prodaju!" );

				GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
				if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
				if( Maskuse[ playerid ] == true )
					format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
				else
					format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
				PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
				SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
				SetPVarInt( playerid, "StartingVehicle", 1 );

			}

			else if( TipVozila[ vehicle ] == ORGANIZACIJSKO_VOZILO )
			{
				if( OrgaVozila[ vehicle ] == PlayerInfo[ playerid ][ xClan ] || PlayerInfo[ playerid ][ xAdmin ] >= 5 )
				{
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
			
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				
				}
			}
			else if( TipVozila[ vehicle ] == POSLOVNO_VOZILO ) {

				if( PosaoVozila[ vehicle ] == PlayerInfo[ playerid ][ xPosao ] || PlayerInfo[ playerid ][ xAdmin ] >= 5 ) {
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
				
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == RENTANO_VOZILO ) {
				if( Rentano[ playerid ] == vehicle || PlayerInfo[ playerid ][ xAdmin ] >= 5 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
				
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				  
				}
			}
			else if( TipVozila[ vehicle ] == GRADONACELNIKOVO_VOZILO ) {
				if( PlayerInfo[ playerid ][ xGradRank ] == GRAD_DRIVER || PlayerInfo[ playerid ][ xGradRank ] == GRAD_LDRIVER || PlayerInfo[ playerid ][ xAdmin ] >= 5 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
	
				}
				else {
					GRESKA( playerid, "Nemate kljuceve od ovog vozila ili uniformu vozaca gradonacelnika!");

				}
			}
			else if( TipVozila[ vehicle ] == IZLOZBENO_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] == 1339 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == ADMIN_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
					return 1;
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				} 
			}
			else if( TipVozila[ vehicle ] == HELPER_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xHelper ] >= 1 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
					return 1;
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == PROMOTER_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || PlayerInfo[ playerid ][ xPromoter ] >= 1 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
					return 1;
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				} 
			}
			else if( TipVozila[ vehicle ] == VIP_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || PlayerInfo[ playerid ][ xVIPLevel ] >= 1 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
					return 1;
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == POLAGANJE_VOZILO ) {
				if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || Polaganje[ playerid ] >= 1 ) {
					GetVehicleParamsEx( vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );
					return 1;
				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == PUMPA_VOZILO ) {

				if( PumpaImanjeVozilo[ vehicle ] == PlayerInfo[ playerid ][ xFirmaID ] || PlayerInfo[ playerid ][ xAdmin ] >= 5 ) {
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );

				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else if( TipVozila[ vehicle ] == IMANJE_VOZILO ) {

				if( PumpaImanjeVozilo[ vehicle ] == PlayerInfo[ playerid ][ xFieldID ] || PlayerInfo[ playerid ][ xAdmin ] >= 5 ) {
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
					if( Maskuse[ playerid ] == true )
						format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
					else
						format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
					PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
					SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
					SetPVarInt( playerid, "StartingVehicle", 1 );

				}
				else {
					GRESKA( playerid, "Nemate kljuc ovog vozila.");
				}
			}
			else {
				GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
				if( engine == 1 ) return GRESKA( playerid, "Motor ovog vozila je vec upaljen - kucajte '/ugasi' da ga ugasite!" );
				if( Maskuse[ playerid ] == true )
					format( globalstring, sizeof( globalstring ), "* Maska_%d pokusava pokrenuti motor.", PlayerInfo[ playerid ][ xMaskID ] );
				else
					format( globalstring, sizeof( globalstring ), "* %s pokusava pokrenuti motor.", ImeIgraca( playerid ) );
				PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
				SetTimerEx( "VehicleEngineStart", 1000, 0, "i", playerid );
				SetPVarInt( playerid, "StartingVehicle", 1 );

			}
		}
	}

	if( takingselfie[ playerid ] ) {
	
		if( PRESSED( KEY_ANALOG_RIGHT ) ) {
		
			GetPlayerPos(playerid,lX[ playerid ],lY[ playerid ],lZ[ playerid ]);
			static Float: n1X, Float: n1Y;
			if(Degree[ playerid ] >= 360) Degree[ playerid ] = 0;
			Degree[ playerid ] += SelfieSpeed;
			n1X = lX[ playerid ] + SelfieRadius * floatcos(Degree[ playerid ], degrees);
			n1Y = lY[ playerid ] + SelfieRadius * floatsin(Degree[ playerid ], degrees);
			SetPlayerCameraPos(playerid, n1X, n1Y, lZ[ playerid ] + SelfieHeight);
			SetPlayerCameraLookAt(playerid, lX[ playerid ], lY[ playerid ], lZ[ playerid ]+1);
			SetPlayerFacingAngle(playerid, Degree[ playerid ] - 90.0);
		}
		if( PRESSED( KEY_ANALOG_LEFT ) ) {
		
			GetPlayerPos(playerid,lX[ playerid ],lY[ playerid ],lZ[ playerid ]);
			static Float: n1X, Float: n1Y;
			if(Degree[ playerid ] >= 360) Degree[ playerid ] = 0;
			Degree[ playerid ] -= SelfieSpeed;
			n1X = lX[ playerid ] + SelfieRadius * floatcos(Degree[ playerid ], degrees);
			n1Y = lY[ playerid ] + SelfieRadius * floatsin(Degree[ playerid ], degrees);
			SetPlayerCameraPos(playerid, n1X, n1Y, lZ[ playerid ] + SelfieHeight);
			SetPlayerCameraLookAt(playerid, lX[ playerid ], lY[ playerid ], lZ[ playerid ]+1);
			SetPlayerFacingAngle(playerid, Degree[ playerid ] - 90.0);
		}
	}

	if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RIBAR && fishermanInfo[ playerid ][ Fishing ] && (PRESSED(KEY_SPRINT) || PRESSED(KEY_JUMP) || PRESSED(KEY_FIRE) || PRESSED(KEY_SECONDARY_ATTACK ) ) ) {
		ApplyAnimation(playerid, "SWORD", "sword_IDLE", 50.0, 0, 1, 1, 1, 1);
	}

	if( HOLDING( KEY_FIRE ) ) {
		new autoid = GetPVarInt( playerid, "ResprayvID" );
		new igrac = GetPVarInt( playerid, "ResprayDozvola" );
		if( igrac != -1 && GetPVarInt( playerid, "RespraySpray" ) == 1 && ResprayColor1[ playerid ] != -1 && ResprayColor2[ playerid ] != -1 && GetWeapon( playerid ) == 41 && IsPlayerNearPlayer( 10.0, playerid, igrac ) && IsPlayerInAnyVehicle( igrac ) )
		{
			if( IsPlayerInRangeOfPoint( playerid, 15.0, 1978.9244, -1585.0405, 13.3126 ) && IsPlayerInRangeOfPoint( igrac, 15.0, 1978.9244, -1585.0405, 13.3126 ) && PlayerInfo[ playerid ][ xMDelovi ] >= 5  && strcmp( ImeIgraca( igrac ), VehicleInfo[ autoid ][ vOwner ], true) == 0 && IsPlayerFacingVehicle( playerid, GetPlayerVehicleID( igrac ) ) )
			{
				FarbanjeTimer[ playerid ] = SetTimerEx( "ResprayTimer", 3000, 0, "ii", igrac, autoid );
			}
		}
	}

	/*if( newkeys & KEY_ACTION ) {
	
		if( IsPlayerInAnyVehicle( playerid ) ) {
		
			if( IsVehicleBajs( GetPlayerVehicleID( playerid ) ) ) {
			
				if( BikeBH[ playerid ] == 0 ) {
				
					if( PlayerInfo[ playerid ][ xBHD ] != 1 ) {
					
						GRESKA( playerid, "Nije moguce skakati sa biciklom!");
						SetTimerEx( "BikeBunnyHop", 2000, false, "i", playerid );
						BikeBH[ playerid ] = 1;
						new Float:Pos[ 3 ];
						GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
						Dimi_SetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ]+2 );
					}
				}
			}
		}
	}*/

	if( newkeys == KEY_SECONDARY_ATTACK ) {
		if( GetPlayerState( playerid ) == 1 ) UlazIzlaz( playerid );

		if( GetPlayerSpecialAction( playerid ) != SPECIAL_ACTION_NONE && GetPlayerSpecialAction( playerid ) != SPECIAL_ACTION_CUFFED  ) {
			SetPlayerSpecialAction( playerid, SPECIAL_ACTION_NONE );
		}
	}

	if( newkeys & KEY_SPRINT ) {
	
		if( Gambling[ playerid ] == 1 ) {
			new kesmoney = PlayerInfo[ playerid ][xNovac];
			if(Bet[ playerid ] > kesmoney+Balance[ playerid ] ) {
			
				announcement( playerid, "~r~Nemas dovoljno novca!", 5000, 4 );
				return 1;
			}

			if( Balance[ playerid ] - Bet[ playerid ] < 0 ) {
			
				announcement( playerid, "~r~Imas premalo na racunu!", 5000, 4);
				return 1;
			}

			SlotCounter[ playerid ] = 30+random( 18 );
			SlotTimer[ playerid ] = SetTimerEx( "Gambler", 100, 1, "d", playerid );
			Gambling[ playerid ] = 2;

			Balance[ playerid ] -= Bet[ playerid ];

			new prefix[ 4 ];
			if( Balance[ playerid ] == 0) strcat( prefix,"~y~" );
			if( Balance[ playerid ]  > 0) strcat( prefix,"~g~" );
			if( Balance[ playerid ]  < 0) strcat( prefix,"~r~" );

			UpdateBetText( playerid );

			TextDrawHideForPlayer( playerid, ReadyText );
		}
	}
	if(newkeys & KEY_JUMP)
	{
		if(Gambling[ playerid ] == 1)
		{
			Bet[ playerid ] = GetNextValidBet(Bet[ playerid ]);
			UpdateBetText(playerid);
		}
	}

	/*if( HOLDING( KEY_SPRINT ) ) {
		if( PRESSED( KEY_JUMP ) ) {
			if( PlayerInfo[ playerid ][xVIPLevel] == 5 ) {
			}
			if( PlayerInfo[ playerid ][xAdmin] == 1339 ) {
			}
			//if(KnockedDown[ playerid ] == false && PlayerInfo[ playerid ][ xZatvor ] == 0 && !IsPlayerInAnyVehicle( playerid ) && PlayerInfo[ playerid ][ xRPLearn ] == 0 && !AdminDuty[ playerid ] && NaDmEventu[ playerid ] == false && WARPInfo[ playerid ][ WARIgrac ] == -1 && Uciskolu[ playerid ] == false && PlayerCuffed[ playerid ] == 0 && TrashSearch[ playerid ] == 0 ) {
			if(PlayerInfo[playerid][xBHD] != 1) {
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				
				SendClientMessageEx( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Zabranjeno je raditi Bunny Hop na ovom serveru!");
			}
		}
	}*/

	if( !IsPlayerInAnyVehicle( playerid ) && IsCbugWeapon( playerid ) && ( ( tickcount( ) - antiCheatCS[ playerid ][ LastWShot ] ) < 750 ) ) {
		if( HOLDING( KEY_JUMP | KEY_SPRINT | KEY_CROUCH ) ) {
		
			new Float:Zivot;
			GetPlayerHealth( playerid, Zivot );
			Dimi_SetPlayerHealth( playerid, Zivot-30 );

			announcement( playerid, "~r~Prestani da radis C-Bug!", 1000, 3 );

			antiCheatCS[ playerid ][ LastWShot ] = -1;

			return 1;
		}
		if( newkeys & KEY_CROUCH ) {
		
			SetTimerEx( "__check", 200, false, "i", playerid );
		}
	}

	if( ( newkeys==KEY_SECONDARY_ATTACK ) && GetPVarInt( playerid, "gSmoking") > 0 )
	{
		if(GetPVarInt( playerid, "gSmoking") == 1)
		{
			SetPlayerSpecialAction( playerid,0 );
			SetPVarInt( playerid, "gSmoking", 0 );
			format( globalstring, sizeof( globalstring ), "** %s baca cigaretu na pod.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
		}
		else if(GetPVarInt( playerid, "gSmoking") == 2)
		{
			SetPlayerSpecialAction( playerid,0 );
			SetPVarInt( playerid, "gSmoking", 0 );
			format( globalstring, sizeof( globalstring ), "** %s baca joint na pod.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
		}

	}
	else if( ( newkeys == KEY_SECONDARY_ATTACK ) && InAmbu[ playerid ] != -1 && IsPlayerInRangeOfPoint( playerid, 1.5, 2003.2792, 2283.7454, 1011.1256 ) )
	{
		new Float:vehPos[ 3 ];
		getPosBehindVehicle( InAmbu[ playerid ], vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0 );
		Dimi_SetPlayerPos( playerid, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] );
		SetPlayerInterior( playerid, 0 );
		InAmbu[ playerid ] = -1;
	}
	else if( PRESSED( KEY_FIRE ) ) {
		if( PlayerCreateEvent[ playerid ] ) {

			if( EventCP[ playerid ] == 1 ) {
				new dFile[ 32 ], Float:Pos[ 4 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				GetPlayerFacingAngle( playerid, Pos[ 3 ] );
				format( dFile, 35, EVENT_FILE, EventID[ playerid ] );
				if( EventCarsCreate[ playerid ] == 1 ) {
					new
						INI:File = INI_Open( dFile );

					INI_WriteString( File, "Name", EventName[ playerid ] );
					INI_WriteFloat( File, "TCPX", Pos[ 0 ] );
					INI_WriteFloat( File, "TCPY", Pos[ 1 ] );
					INI_WriteFloat( File, "TCPZ", Pos[ 2 ] );
					INI_WriteFloat( File, "TCPA", Pos[ 3 ] );
					INI_WriteInt( File, "Veh", EventVehID[ playerid ] );
					INI_Close( File );
					format( Event[ EventID[ playerid ] ][ Name ], 64, "%s", EventName[ playerid ] );
					Event[ EventID[ playerid ] ][ TCPX ] = Pos[ 0 ];
					Event[ EventID[ playerid ] ][ TCPY ] = Pos[ 1 ];
					Event[ EventID[ playerid ] ][ TCPZ ] = Pos[ 2 ];
					Event[ EventID[ playerid ] ][ TCPA ] = Pos[ 3 ];
					Event[ EventID[ playerid ] ][ VehID ] = EventVehID[ playerid ];
					SendClientMessagee( playerid, ZUTA, "Postavio si red za vozila 1." );
					EventCarsCreate[ playerid ]++;
				}
				else if( EventCarsCreate[ playerid ] == 2 ) {
					new
						INI:File = INI_Open( dFile );

					INI_WriteFloat( File, "TCPX2", Pos[ 0 ] );
					INI_WriteFloat( File, "TCPY2", Pos[ 1 ] );
					INI_WriteFloat( File, "TCPZ2", Pos[ 2 ] );
					INI_WriteFloat( File, "TCPA2", Pos[ 3 ] );
					INI_Close( File );
					EventCP[ playerid ]++;
					EventCarsCreate[ playerid ] = 0;
					Event[ EventID[ playerid ] ][ TCPX2 ] = Pos[ 0 ];
					Event[ EventID[ playerid ] ][ TCPY2 ] = Pos[ 1 ];
					Event[ EventID[ playerid ] ][ TCPZ2 ] = Pos[ 2 ];
					Event[ EventID[ playerid ] ][ TCPA2 ] = Pos[ 3 ];
					SendClientMessagee( playerid, ZUTA, "Postavio si red za vozila 2." );
					SendClientMessagee( playerid, ZUTA, "Koristi LMB(levi klik misa) za postavljanje checkpointa. Kada zavrsis ukucaj /ezavrsi.");
				}
			}
			else if( EventCP[ playerid ] > 1 ) {
				new dFile[ 32 ], Float:Pos[ 3 ], string[ 6 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				format( dFile, 35, EVENT_FILE, EventID[ playerid ] );

				new
					INI:File = INI_Open( dFile );

				format( string, 6, "CPX%d", EventCP[ playerid ] );
				INI_WriteFloat( File, string, Pos[ 0 ] );
				CheckPoint[ EventID[ playerid ] ][ EventCP[ playerid ] ][ CPX ] = Pos[ 0 ];

				format( string, 6, "CPY%d", EventCP[ playerid ] );
				INI_WriteFloat( File, string, Pos[ 1 ] );
				CheckPoint[ EventID[ playerid ] ][ EventCP[ playerid ] ][ CPY ] = Pos[ 1 ];

				format( string, 6, "CPZ%d",EventCP[ playerid ] );
				INI_WriteFloat( File, string, Pos[ 2 ] );
				CheckPoint[ EventID[ playerid ] ][ EventCP[ playerid ] ][ CPZ ] = Pos[ 2 ];

				INI_Close( File );
				SendClientMessageEx( playerid, ZUTA, "Postavio si Checkpoint %d.", EventCP[ playerid ]-1 );
				EventCP[ playerid ]++;
			}
		}

		if( CreatingThing[ playerid ] == 1 ) {
			new Float:Pos[ 3 ];
			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
			
			if( IsCordsInOtherField( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugom imanju." );
			
			CreatingPos[ playerid ][ 0 ] = Pos[ 0 ];
			CreatingPos[ playerid ][ 1 ] = Pos[ 1 ];
			SendInfoMessage( playerid, "Koristi "col_white"LMB"col_balkanstory" da postavis pozicije." );
			SendInfoMessage( playerid, "Sada sacuvaj poziciju desnog gornjeg ugla polja." );
			CreatingThing[ playerid ]++;
		}
		else if( CreatingThing[ playerid ] == 2 ) {
			new Float:Pos[ 4 ];
			new id = NextFieldID( MAX_FIELDS );

			if( id == -1 ) return GRESKA( playerid, "Vec ima maksimalni broj imanja." );

			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
			GetPlayerFacingAngle( playerid, Pos[ 3 ] );
			
			if( IsCordsInOtherField( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugom imanju." );
			
			CreatingPos[ playerid ][ 2 ] = Pos[ 0 ];
			CreatingPos[ playerid ][ 3 ] = Pos[ 1 ];
			CreatingThing[ playerid ] = -1;
			CreatingField[ playerid ] = id;

			ResetField( id );

			if( CreatingPos[ playerid ][ 0 ] > CreatingPos[ playerid ][ 2 ] ) {
				fieldInfo[ id ][ fieldMaxX ] = CreatingPos[ playerid ][ 0 ];
				fieldInfo[ id ][ fieldMinX ] = CreatingPos[ playerid ][ 2 ];
			}
			else if( CreatingPos[ playerid ][ 2 ] > CreatingPos[ playerid ][ 0 ] ) {
				fieldInfo[ id ][ fieldMaxX ] = CreatingPos[ playerid ][ 2 ];
				fieldInfo[ id ][ fieldMinX ] = CreatingPos[ playerid ][ 0 ];
			}

			if( CreatingPos[ playerid ][ 1 ] > CreatingPos[ playerid ][ 3 ] ) {
				fieldInfo[ id ][ fieldMaxY ] = CreatingPos[ playerid ][ 1 ];
				fieldInfo[ id ][ fieldMinY ] = CreatingPos[ playerid ][ 3 ];
			}
			else if( CreatingPos[ playerid ][ 3 ] > CreatingPos[ playerid ][ 1 ] ) {
				fieldInfo[ id ][ fieldMaxY ] = CreatingPos[ playerid ][ 3 ];
				fieldInfo[ id ][ fieldMinY ] = CreatingPos[ playerid ][ 1 ];
			}
			
			fieldInfo[ id ][ fieldObject ] = CreateDynamicObject( 19470, Pos[ 0 ]+2, Pos[ 1 ], Pos[ 2 ]+ 0.6, 0.0, 0.0, Pos[ 3 ] , 0, 0, -1, 200.0 );
			Streamer_Update( playerid );
			PlayerEditObject( playerid, fieldInfo[ id ][ fieldObject ] );
			fieldInfo[ id ][ fieldTractorID ] = -1; 
			fieldInfo[ id ][ fieldAdditionID ] = -1;
			fieldInfo[ id ][ fieldTruckID ] = -1;
			
			fieldInfo[ id ][ fieldRectAngle ] = CreateDynamicRectangle( fieldInfo[ id ][ fieldMinX ], fieldInfo[ id ][ fieldMinY ], fieldInfo[ id ][ fieldMaxX ], fieldInfo[ id ][ fieldMaxY ], -1, -1, -1 );
			Field_Save( id );

			SendInfoMessage( playerid, "Uspjesno si sacuvao pozicije, sada sacuvaj poziciju objekta koji oznacava da je imanje na prodaju." );
		}


		if( CreatingGZone[ playerid ] == 1 ) {
		
			new Float:Pos[ 3 ];
			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

			if( IsCordsInOtherGZone( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugoj gang zoni." );

			CreatingPos[ playerid ][ 0 ] = Pos[ 0 ];
			CreatingPos[ playerid ][ 1 ] = Pos[ 1 ];
			SendInfoMessage( playerid, "Koristi "col_white"LMB"col_balkanstory" da postavis pozicije." );
			SendInfoMessage( playerid, "Sada sacuvaj poziciju desnog gornjeg ugla polja." );
			CreatingGZone[ playerid ]++;
		}
		else if( CreatingGZone[ playerid ] == 2 ) {
		
			new Float:Pos[ 4 ];
			new id = CreatingGZoneID[ playerid ];

			if( id == -1 ) return GRESKA( playerid, "Vec ima maksimalni broj gang zona." );

			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
			GetPlayerFacingAngle( playerid, Pos[ 3 ] );

			if( IsCordsInOtherGZone( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugoj gang zoni." );

			CreatingPos[ playerid ][ 2 ] = Pos[ 0 ];
			CreatingPos[ playerid ][ 3 ] = Pos[ 1 ];
			CreatingGZone[ playerid ]++;

			GZone_Reset( id );

			if( CreatingPos[ playerid ][ 0 ] > CreatingPos[ playerid ][ 2 ] ) {
				gZoneInfo[ id ][ gZoneMaxX ] = CreatingPos[ playerid ][ 0 ];
				gZoneInfo[ id ][ gZoneMinX ] = CreatingPos[ playerid ][ 2 ];
			}
			else if( CreatingPos[ playerid ][ 2 ] > CreatingPos[ playerid ][ 0 ] ) {
				gZoneInfo[ id ][ gZoneMaxX ] = CreatingPos[ playerid ][ 2 ];
				gZoneInfo[ id ][ gZoneMinX ] = CreatingPos[ playerid ][ 0 ];
			}

			if( CreatingPos[ playerid ][ 1 ] > CreatingPos[ playerid ][ 3 ] ) {
				gZoneInfo[ id ][ gZoneMaxY ] = CreatingPos[ playerid ][ 1 ];
				gZoneInfo[ id ][ gZoneMinY ] = CreatingPos[ playerid ][ 3 ];
			}
			else if( CreatingPos[ playerid ][ 3 ] > CreatingPos[ playerid ][ 1 ] ) {
				gZoneInfo[ id ][ gZoneMaxY ] = CreatingPos[ playerid ][ 3 ];
				gZoneInfo[ id ][ gZoneMinY ] = CreatingPos[ playerid ][ 1 ];
			}

			gZoneInfo[ id ][ gZoneID ] = GangZoneCreate( gZoneInfo[ id ][ gZoneMinX ], gZoneInfo[ id ][ gZoneMinY ], gZoneInfo[ id ][ gZoneMaxX ], gZoneInfo[ id ][ gZoneMaxY ] );
			GZone_Save( id );
			gZoneInfo[ id ][ gZoneRectAngle ] = CreateDynamicRectangle( gZoneInfo[ id ][ gZoneMinX ], gZoneInfo[ id ][ gZoneMinY ], gZoneInfo[ id ][ gZoneMaxX ], gZoneInfo[ id ][ gZoneMaxY ], -1, -1, -1 );

			SendInfoMessage( playerid, "Koristi "col_white"LMB"col_balkanstory" da postavis pozicije." );
			SendInfoMessage( playerid, "Sada sacuvaj poziciju za pickup i text." );
		}
		else if( CreatingGZone[ playerid ] == 3 ) {
		
			new Float:Pos[ 3 ], stringic[ 24 ];
		
			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
		
			new id = IsCordsInGZone( CreatingGZoneID[ playerid ], Pos[ 0 ], Pos[ 1 ] );

			if( id != CreatingGZoneID[ playerid ] ) return GRESKA( playerid, "Moras sacuvati u zoni koju kreiras." );
		
			gZoneInfo[ id ][ gZonePickupPos ][ 0 ] = Pos[ 0 ];
			gZoneInfo[ id ][ gZonePickupPos ][ 1 ] = Pos[ 1 ];
			gZoneInfo[ id ][ gZonePickupPos ][ 2 ] = Pos[ 2 ];
		
			gZoneInfo[ id ][ gZoneTaken ] = false;
			gZoneInfo[ id ][ gZoneTakeable ] = true;
			gZoneInfo[ id ][ gZoneTime ] = 0;
		
			gZoneInfo[ id ][ gZonePickup ] = CreateDynamicPickup( 1313, 1, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 0, 0 );
			gZoneInfo[ id ][ gZone3D ] = CreateDynamic3DTextLabel( ""col_white"[ TERITORIJA ]\nTeritorija je "col_balkanstory"slobodna"col_white"\nAko zelis da je zauzmes kucaj "col_balkanstory"/zauzmi", BELA, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );

			format( stringic, sizeof( stringic ), "0x%s66", gZoneInfo[ id ][ gZoneColor ] );
			GangZoneShowForAll( gZoneInfo[ id ][ gZoneID ], HexToInt( stringic ) );

			GZone_Save( id );

			CreatingGZone[ playerid ] = -1;
			CreatingGZoneID[ playerid ] = -1;
		}


		if( ListaBurg[ playerid ] > 0 ) {
			if( PlayerInfo[ playerid ][ xNovac ] < 20 ) return GRESKA( playerid, "Nemate dovoljno novca(20$)." );
			if( ListaBurg[ playerid ] == 1 )
			{
				SetPlayerCameraPos( playerid, 377.4937, -67.9324, 1002.1277);
				SetPlayerCameraLookAt( playerid, 377.5477, -66.9359, 1001.6640); //2
				ListaBurg[ playerid ] = 2;
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], "~w~Big Mac" );
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], "~w~Cena: ~r~70$" );
			}
			else if( ListaBurg[ playerid ] == 2 )
			{
				SetPlayerCameraPos( playerid, 378.1165, -67.9661, 1002.1277);
				SetPlayerCameraLookAt( playerid, 378.1705, -66.9697, 1001.6640); // 3
				ListaBurg[ playerid ] = 3;
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], "~w~Cheeseburger" );
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], "~w~Cena: ~r~60$" );
			}
			else if( ListaBurg[ playerid ] == 3 )
			{
				SetPlayerCameraPos( playerid, 378.7393, -67.9999, 1002.1277);
				SetPlayerCameraLookAt( playerid, 378.7933, -67.0034, 1001.6640); // 4
				ListaBurg[ playerid ] = 4;
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], "~w~Chicken Burger" );
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], "~w~Cena: ~r~60$" );
			}
			else if( ListaBurg[ playerid ] == 4 )
			{
				SetPlayerCameraPos( playerid, 379.3621, -68.0336, 1002.1277);
				SetPlayerCameraLookAt( playerid, 379.4161, -67.0371, 1001.6640); // 5
				ListaBurg[ playerid ] = 5;
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], "~w~Country Burger" );
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], "~w~Cena: ~r~75$" );
			}
			else if( ListaBurg[ playerid ] == 5 )
			{
				SetPlayerCameraPos( playerid, 376.8709, -67.8987, 1002.1277);
				SetPlayerCameraLookAt( playerid, 376.9249, -66.9022, 1001.6640); // 1
				ListaBurg[ playerid ] = 1;
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], "~w~Hamburger" );
				PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], "~w~Cena: ~r~65$" );
			}
		}
////////////////////////////////////////////////////////////////////////////////
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_KOMUNALAC )
		{
			if( garbagemanInfo[ playerid ][ gmiDuty ] )
			{

				if( IsPlayerInAnyVehicle( playerid )) return GRESKA(playerid,"Morate biti van vozila!");
				
				if( !garbagemanInfo[ playerid ][ gmiHasGarbage ] )
				{
					if( GetNearestContainer( playerid ) != -1 )
					{
						if(AktivanKontejner[playerid] > 0 )//AktivanKontejner[ playerid ] = -1;
						{
							ClearAnimations( playerid );
							SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 1264, 5, 0.352547, -0.205320, 0.184597, 212.175216, 292.318084, 151.621368, 1.000000, 1.000000, 1.000000);

							garbagemanInfo[ playerid ][ gmiHasGarbage ] = true;
						}
						//else GRESKA( playerid, "Ne mozes uzeti smece iz kontejnera jer nisi zapoceo posao!" );
					}
				}
				else
				{
					new vehicleid = getPlayerNearestVehicle( playerid );
					if( GetNearestContainer( playerid ) != -1 )
					{

						ClearAnimations( playerid );
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
						SendJobMessage( playerid, "Ubacio si smece u kontejner." );
						SendJobMessage( playerid, "Ukoliko si hteo u kamion, pomeri ga malo." );
					}
					else if( GetVehicleModel( vehicleid ) == 408 )
					{

						if( garbagemanVehicles[ vehicleid ][ gGarbages ] == AKTIV_KONTEJNERI )
						{
							SendJobMessage( playerid, "Kamion je napunjen s maksimalnih %d vreca",garbagemanVehicles[ vehicleid ][ gGarbages ]);
							SendJobMessage( playerid, "Vratite vrecu u kontejner");
						}
						else
						{
						
							new Float:vehPos[ 3 ];
							getPosBehindVehicle( vehicleid, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0 );

							if( IsPlayerInRangeOfPoint( playerid, 2.0, vehPos[ 0 ], vehPos[ 1 ], vehPos[2 ] ) )
							{
							
								ClearAnimations( playerid );

								RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
								garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
								garbagemanVehicles[ vehicleid ][ gGarbages ]++;
								isprazniovreca[playerid] ++;
								AktivanKontejner[ playerid ]++;
								SendJobMessage( playerid, "U kamion ste ubacili"col_job" %d/%d"col_white"vreca smeca!", garbagemanVehicles[ vehicleid ][ gGarbages ],AKTIV_KONTEJNERI );
								if( garbagemanVehicles[ vehicleid ][ gGarbages ] < AKTIV_KONTEJNERI )
								{
									Dimi_SetPlayerCheckpoint( playerid, KontInfo[ AktivanKontejner[ playerid ] ][ koObjPos ][ 0 ], KontInfo[ AktivanKontejner[ playerid ] ][ koObjPos ][ 1 ], KontInfo[ AktivanKontejner[ playerid ] ][ koObjPos ][ 2 ], 5.0 );
									CheckpointStatus[ playerid ] = 22;
									SendJobMessage( playerid, "Novi kontejner je oznacen na mapi, nastavite dalje!");
								}
								else if( garbagemanVehicles[ vehicleid ][ gGarbages ] == AKTIV_KONTEJNERI )
								{

									Dimi_SetPlayerCheckpoint( playerid, 2070.6895,-1984.1779,13.5544, 5.0 );

									CheckpointStatus[ playerid ] = 9;

									garbagemanInfo[ playerid ][ gmiDuty ] = false;
									garbagemanInfo[ playerid ][ gmiReadyToDump ] = true;

									SendJobMessage( playerid, "Ocistili ste sve kontejnere, sada vozite prema markeru da istovarite smece!");

								}
							}
						}
					}
				}
			}
		}
	
		////////////////////////////////////////////////////////////////////////////////
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_FARMER )
		{

			if( farmerInfo[ playerid ][ fiHaveBucket ] )
			{//edo majkara
				if( farmerInfo[ playerid ][ fiCowNumber ] == 26 )
				{

					if( !IsPlayerInAnyVehicle( playerid ) && IsPlayerInRangeOfPoint(playerid,4.0,-1081.7942,-1208.5925,129.2188 ))
					{

						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						farmerInfo[ playerid ][ fiHaveBucket ] = false;
						//farmerInfo[ playerid ][ fiCowNumber ] = 15;
						SendJobMessage( playerid, "Sacekajte malo da se mlijeko upakuje!" );
						TogglePlayerControllable( playerid, false );
						SetTimerEx("preradamleka", 5000, false, "i", playerid);
						announcement(playerid,"~w~Prerada...",5000,1);
						CheckpointStatus[ playerid ] = 0;
					}

				}
			}
			////////////////////////////////////////////////////////////////////frenkie
			
			new vehicleid = getPlayerNearestTractor( playerid );
			new aa1 = IsPlayerInRangeOfPoint( playerid, 3.0, 1871.1295,-1658.0997,13.3773);
			new bb1 = IsPlayerInRangeOfPoint( playerid, 3.0, 1871.1284,-1667.5623,13.3773);
			new cc1 = IsPlayerInRangeOfPoint( playerid, 3.0, 1871.1284,-1667.5623,13.3773);
			if( farmerInfo[ playerid ][ fiHaveFruits ] )
			{
				if( vehicleid != INVALID_VEHICLE_ID )
				{
					if( farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 3 )
					{
						if( GetVehicleModel( vehicleid ) == 422 )
						{
							if( !IsPlayerInAnyVehicle( playerid ) )
							{

								new Float:vehPos[ 3 ];
								getPosBehindVehicle( vehicleid, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0);
								if( farmerVehicles[ vehicleid ][ fvMilk ] == true ) return GRESKA( playerid, "U ovom vozilu je vec nesto utovareno!" );
								if( IsPlayerInRangeOfPoint( playerid, 1.5, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) )
								{

									RemovePlayerAttachedObject( playerid, 0);
									RemovePlayerAttachedObject( playerid, 1);
									RemovePlayerAttachedObject( playerid, 2);
									farmerInfo[ playerid ][ fiHaveFruits ] = false;
									farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 4;

									SendJobMessage( playerid, "Sada udjite u vozilo i dostavite voce na trznicu!" );
									Dimi_SetPlayerCheckpoint( playerid, 1829.2881,-1649.9618,13.5469, 5.0 );
									CheckpointStatus[ playerid ] = 16;
									farmerVehicles[ vehicleid ][ fvMilk ] = true;
									farmerVehicles[ vehicleid ][ fvMilkpID ] = playerid;
									farmerInfo[ playerid ][ fiVehicleBucket ] = vehicleid;
									ApplyAnimation( playerid, "CARRY", "putdwn", 3.0, 0, 0, 0, 0, 0 );
									StaroVreme[ playerid ] = gettime();
									NovoVreme[ playerid ] = 110;
								} else return GRESKA( playerid, "Morate biti iza vozila." );
							}
						}
					}
				}
				else if( aa1 || bb1 || cc1 && farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 5 && farmerInfo[ playerid ][ fiHaveFruits ] && !IsPlayerInAnyVehicle( playerid ) )
				{
					RemovePlayerAttachedObject( playerid, 0 );
					RemovePlayerAttachedObject( playerid, 1 );
					RemovePlayerAttachedObject( playerid, 2 );
					farmerInfo[ playerid ][ fiHaveFruits ] = false;
					farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 6;
					SendJobMessage( playerid, "Dostavili ste voce sada se svojim vozilom vratite nazad po isplatu!" );
					Dimi_SetPlayerCheckpoint( playerid, -1047.9996, -1230.6726, 128.6476, 5.0 );
					CheckpointStatus[ playerid ] = 26;
					StaroVreme[ playerid ] = gettime();
					NovoVreme[ playerid ] = 120;
				}
			}
			else if( !farmerInfo[ playerid ][ fiHaveFruits ] )
			{
				if( vehicleid != INVALID_VEHICLE_ID )
				{
					if( farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 4 )
					{
						if( farmerVehicles[ vehicleid ][ fvMilk ] == true )
						{
							if( GetVehicleModel( vehicleid ) == 422 )
							{
								if( !IsPlayerInAnyVehicle( playerid ) )
								{

									new Float:vehPos[ 3 ];
									getPosBehindVehicle( vehicleid, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0);
									if( farmerVehicles[ vehicleid ][ fvMilkpID ] != playerid ) return GRESKA( playerid, "Ovde nije tvoje voce!");
									if( IsPlayerInRangeOfPoint( playerid, 1.5, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) )
									{

										SendJobMessage( playerid, "Izvadili ste voce iz vozila, sada ga ostavite kod standa sa vocem!" );
										farmerVehicles[ vehicleid ][ fvMilk ] = false;
										farmerVehicles[ vehicleid ][ fvMilkpID ] = -1;
										farmerInfo[ playerid ][ fiVehicleBucket ] = -1;
										farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 5;
										farmerInfo[ playerid ][ fiHaveFruits ] = true;
										Dimi_DisablePlayerCheckpoint( playerid );
										CheckpointStatus[ playerid ] = 0;
										SetPlayerAttachedObject(playerid, 0, 19636, 1, -0.027999, 0.444999, -0.022000, -0.999999, 94.299942, 91.899963);
										SetPlayerAttachedObject(playerid, 1, 19638, 1, 0.125999, 0.449999, 0.002000, -8.199994, 94.899948, 91.199966);
										SetPlayerAttachedObject(playerid, 2, 19637, 1, 0.283000, 0.449999, -0.043000, -8.199994, 94.899948, 97.699897);
										ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
									} else return GRESKA( playerid, "Morate biti iza kamioneta." );
								}
							}
						}
					}
				}
			}
			////////////////////////////////////////////////////////////////////
			if( farmerInfo[ playerid ][ fiCowNumber ] == 0 )
			{
				new plantid = getPlayerNearFarmerPlant( playerid );
				new vehicleidd = getPlayerNearestTractor( playerid );
				if( vehicleidd != INVALID_VEHICLE_ID && isATractor( vehicleidd ) && farmerInfo[ playerid ][ fiFarmerSeeds ] > 0 && !IsPlayerInAnyVehicle( playerid ) )
				{
					SetPlayerSpecialAction( playerid, SPECIAL_ACTION_NONE );
					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );

					if( farmerVehicles[ vehicleidd ][ fvSeeds ] == 10 ) return GRESKA( playerid, "Vec ima 10 sjemenki u traktoru!" );
					farmerVehicles[ vehicleidd ][ fvSeeds ] = 10;
					farmerInfo[ playerid ][ fiFarmerSeeds ] = 0;

					SendJobMessage( playerid, "Ubacio si semenke u traktor, sad ih odi posijat." );
					SendJobMessage( playerid, "Poljana za sejanje vam je oznacena na mapi." );

					Dimi_SetPlayerCheckpoint( playerid, -1209.3190, -1064.4297, 127.9703, 5.0 );
					CheckpointStatus[ playerid ] = 15;
				}
				//////////////////////////////////////////////////////////////////////
				else if( plantid > -1 && !farmerInfo[ playerid ][ fiFarmerPickupedBale ] && !IsPlayerInAnyVehicle( playerid ) )
				{

					if( UzeoOpremu[ playerid ] == true )
					{

						if( plantInfo[ plantid ][ farmPlayerID ] == playerid && plantInfo[ plantid ][ farmWheatCreated ] )
						{

							ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.0, 0, 0, 0, 0, 0);
							if( IsValidDynamic3DTextLabel( plantInfo[ plantid ][ farm3D ] ) )
								DestroyDynamic3DTextLabel( plantInfo[ plantid ][ farm3D ] );

							if( IsValidDynamicObject( plantInfo[ plantid ][ farmObject ] ) )
								DestroyDynamicObject( plantInfo[ plantid ][ farmObject ] );

							ResetFarmPlant( plantid );

							SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 2901, 1, 0.080628, -0.363714, -0.035524, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
							farmerInfo[ playerid ][ fiFarmerPickupedBale ] = true;
						}
						else SendJobMessage( playerid, "Prvo moras sa kombajnom pozeti useve, a onda ih tek mozes sakupiti.");
					}
				}
				//////////////////////////////////////////////////////////////////////
				else if( IsPlayerInRangeOfPoint(playerid, 2.0, -1100.0110, -1142.8070, 129.2188 ) )
				{

					if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) && farmerInfo[ playerid ][ fiFarmerPickupedBale ] && !IsPlayerInAnyVehicle( playerid ) ) {

						if( farmerInfo[ playerid ][ fiFarmerWheatCreated ] == MAX_FARMERS_PLANTS_PLANTED )
						{

							RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );

							farmerInfo[ playerid ][ fiFarmerPickupedBales ]++;
							farmerInfo[ playerid ][ fiFarmerPickupedBale ] = false;

							new bonus = random(30);
							PlayerInfo[ playerid ][ xPlatniRacun ] += (250+bonus);
							SavePlayer( playerid ); UpdatePlataTD( playerid );
							BussinesJobMoney( POSAO_FARMER, ((250+bonus)/10) );

							SendJobMessage( playerid, "Zaradio si "col_white"%d$.", (250+bonus) );
							SendJobMessage( playerid, "Ako vam dodje do neke greske sa poslom ukucajte {F81414}/prekiniposao"col_white" i krenite iznova." );

							if( farmerInfo[ playerid ][ fiFarmerPickupedBales ] == farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] )
							{
								farmerInfo[ playerid ][ fiFarmerPickupedBales ] = 0;
								farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] = -1;
								farmerInfo[ playerid ][ fiFarmerWheatCreated ] = -1;
								Dimi_DisablePlayerCheckpoint( playerid );
								CheckpointStatus[ playerid ] = 0;
								SendJobMessage( playerid, "Sakupio si sve useve, ako zelis sakupiti jos useva, prvo ih moras posijati");
							}
						}
						else GRESKA( playerid, "Moras prvo da poznjes sve useve pa tek onda da sakupis." );
					}
					else GRESKA( playerid, "Nemas usev u ruci ili si u vozilu!");
				}
			}

			
			else
			{//edo majkara
				new vehicleids = getPlayerNearestTractor( playerid );
				if( farmerInfo[ playerid ][ fiHaveBucket ] )
				{
					if( vehicleids != INVALID_VEHICLE_ID )
					{
						if( farmerInfo[ playerid ][ fiCowNumber ] == 9 )
						{
							if( GetVehicleModel( vehicleids ) == 422 )
							{
								if( !IsPlayerInAnyVehicle( playerid ) )
								{

									new Float:vehPos[ 3 ];
									getPosBehindVehicle( vehicleids, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0);
									if( farmerVehicles[ vehicleids ][ fvMilk ] == true ) return GRESKA( playerid, "U ovom vozilu vec ima utovareno mlijeko!" );
									if( IsPlayerInRangeOfPoint( playerid, 1.5, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) )
									{

										RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
										farmerInfo[ playerid ][ fiHaveBucket ] = false;
										farmerInfo[ playerid ][ fiCowNumber ] = 15;

										SendJobMessage( playerid, "Sada udjite u kamionet i odvezite mlijeko na prikazani marker." );
										Dimi_SetPlayerCheckpoint( playerid, 172.7875, -23.4740, 1.5765, 5.0 );
										CheckpointStatus[ playerid ] = 17;
										farmerVehicles[ vehicleids ][ fvMilk ] = true;
										farmerVehicles[ vehicleids ][ fvMilkpID ] = playerid;
										farmerInfo[ playerid ][ fiVehicleBucket ] = vehicleid;
										ApplyAnimation( playerid, "CARRY", "putdwn", 3.0, 0, 0, 0, 0, 0 );
										StaroVreme[ playerid ] = gettime();
										NovoVreme[ playerid ] = 110;
									} else return GRESKA( playerid, "Morate biti iza kamioneta." );
								}
							}
						}
					}
					else if( IsPlayerInRangeOfPoint( playerid, 2.0, 156.6077, -22.2604, 1.5781 ) && farmerInfo[ playerid ][ fiCowNumber ] == 16 && farmerInfo[ playerid ][ fiHaveBucket ] && !IsPlayerInAnyVehicle( playerid ) )
					{

						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						farmerInfo[ playerid ][ fiHaveBucket ] = false;
						farmerInfo[ playerid ][ fiCowNumber ] = 17;
						SendJobMessage( playerid, "Dostavili ste mlijeko sada se svojim vozilom vratite nazad po isplatu!" );
						Dimi_SetPlayerCheckpoint( playerid, -1047.9996, -1230.6726, 128.6476, 5.0 );
						CheckpointStatus[ playerid ] = 26;
						StaroVreme[ playerid ] = gettime();
						NovoVreme[ playerid ] = 120;
					}
				}
				
				else if( !farmerInfo[ playerid ][ fiHaveBucket ] )
				{
				
					if( vehicleid != INVALID_VEHICLE_ID )
					{
						if( farmerInfo[ playerid ][ fiCowNumber ] == 15 )
						{
							if( farmerVehicles[ vehicleid ][ fvMilk ] == true )
							{
								if( GetVehicleModel( vehicleid ) == 422 )
								{
									if( !IsPlayerInAnyVehicle( playerid ) )
									{
						
										new Float:vehPos[ 3 ];
										getPosBehindVehicle( vehicleid, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0);
										if( farmerVehicles[ vehicleid ][ fvMilkpID ] != playerid ) return GRESKA( playerid, "Ovde nije tvoje mlijeko!");
										if( IsPlayerInRangeOfPoint( playerid, 1.5, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) )
										{

											SendJobMessage( playerid, "Izvadili ste mlijeko iz vozila sada ga dostavi mljekari!" );
											farmerVehicles[ vehicleid ][ fvMilk ] = false;
											farmerVehicles[ vehicleid ][ fvMilkpID ] = -1;
											farmerInfo[ playerid ][ fiVehicleBucket ] = -1;
											farmerInfo[ playerid ][ fiCowNumber ] = 16;
											farmerInfo[ playerid ][ fiHaveBucket ] = true;
											Dimi_DisablePlayerCheckpoint( playerid );
											CheckpointStatus[ playerid ] = 0;
											SetPlayerAttachedObject(playerid, OBJECT_SLOT_RHAND, 19569, 1, 0.003000, 0.422999, 0.000999, 3.700000, 97.499969, 86.699958, 2.293999, 3.209000, 1.359000);
											ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
										} else return GRESKA( playerid, "Morate biti iza kamioneta." );
									}
								}
							}
						}
					}
				}
			}
		}
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PNAMESTAJA ) {
		
			if( NamestajLevel[ playerid ] == 5 ) {
			
				if( Rezanje[ playerid ] < 100 ) {
				
					if(KoristioRezanje[ playerid ] == 1 ) return GRESKA( playerid, "Vec ste u fazi rezanja, sacekajte par sekundi!");
					Rezanje[ playerid ] += 10;
					TogglePlayerControllable( playerid, true );
					KoristioRezanje[ playerid ] = 1;
					ApplyAnimation( playerid, "KISSING", "Playa_Kiss_01", 4.1, 1, 0, 0, 1, 0 );
					NamestajTajmer[ playerid ] = SetTimerEx( "TimerRezanja",3000, false, "i", playerid );
					SendJobMessage( playerid, "Rezete dasku za namestaj, izrezano: "col_job"%d%%!", Rezanje[playerid]);
				
				}
				if( Rezanje[ playerid ] == 100 ) {
				
					SendJobMessage( playerid, "Uspjesno ste izrezali dasku i napravili deo namestaja!");
					SendJobMessage( playerid, "Deo odnesite napolje u skladiste!");
					DestroyPlayerObject( playerid, Objekat[ playerid ] );
					TogglePlayerControllable( playerid, true );
					NamestajLevel[ playerid ] = 6;
					SetPlayerSpecialAction( playerid, SPECIAL_ACTION_CARRY );
					Dimi_SetPlayerCheckpoint( playerid, 2197.8872,-2267.6538,13.5547, 4.0);
					CheckpointStatus[ playerid ] = 40;
					new objekat = random(3);
					switch( objekat ) {
					
						case 0: {
							SetPlayerAttachedObject(playerid, OBJECT_SLOT_BADGE, 2321, 1, 0.00, 0.67, 0.68, 0.0, 89.0, 4.0, 1.00, 1.00, 1.00);
						}
						case 1: {
							SetPlayerAttachedObject(playerid, OBJECT_SLOT_BADGE, 2235, 1, 0.00, 0.03, 0.48, 0.0, 88.0, 0.0, 1.00, 1.00, 1.00);
						}
						case 2: {
							SetPlayerAttachedObject(playerid, OBJECT_SLOT_BADGE, 2234, 1, 0.00, 0.20, 0.47 ,0.0 ,87.0, 0.0, 1.00, 1.00, 1.00);
						}
					}
				}
			}
		
		}
	}
	else if( PRESSED( KEY_NO ) ) {
	
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RIBAR ) {
	
			if( fishermanInfo[ playerid ][ Fishing ] ) {
			
				if( fishermanInfo[ playerid ][ FishKG ] != 50 ) {
				
					if( fishermanInfo[ playerid ][ TriesFish ] > 0 ) {
					
						fishermanInfo[ playerid ][ TriesFish ]++;
						ApplyAnimation( playerid, "SWORD", "sword_block", 50.0, 0, 1, 0, 1, 1);

						switch( fishermanInfo[ playerid ][ TriesFish ] )
						{

							/*case 2: ChangeFisherManCoordinates(playerid, 10.0000);
							case 3: ChangeFisherManCoordinates(playerid, 20.0000);
							case 4: ChangeFisherManCoordinates(playerid, 30.0000);
							case 5: ChangeFisherManCoordinates(playerid, 40.0000);
							case 6: ChangeFisherManCoordinates(playerid, 50.0000);
							case 7: ChangeFisherManCoordinates(playerid, 60.0000);
							case 8: ChangeFisherManCoordinates(playerid, 70.0000);
							case 9: ChangeFisherManCoordinates(playerid, 80.0000);
							case 10: ChangeFisherManCoordinates(playerid, 90.0000);
							case 11:
							{
								ChangeFisherManCoordinates(playerid, 100.0000);
							}*/
						}
						//ShowFishingTD( playerid, true );

						if( fishermanInfo[ playerid ][ TriesFish ] == 11 ) {
							new randomizacija = randomEx( 1, 10 );
							if( randomizacija <= 5 ) {

								fishermanInfo[ playerid ][ Fishing ] = false;
								SendJobMessage( playerid, "Riba vam je pobjegla. Pokusajte ponovo." );
								//ChangeFisherManCoordinates( playerid, 0.0000 );
								RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
								//ShowFishingTD( playerid, true );
								ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
								fishermanInfo[ playerid ][ TriesFish ] = 0;
							}
							else if( randomizacija >= 6 ) {

								fishermanInfo[ playerid ][ Fishing ] = false;
								new fishkgsrand = randomEx( 1, 4 );
								SendJobMessage( playerid, "Upecali ste ribu tesku: "col_job"%d"col_white" kilograma.", fishkgsrand );
								fishermanInfo[ playerid][ FishKG] += fishkgsrand;
								if( fishermanInfo[ playerid ][ FishKG ] > 50 ) { fishermanInfo[ playerid ][ FishKG ] = 50; }

								format( globalstring, sizeof( globalstring ), "~w~Riba: ~r~%d/50kg", fishermanInfo[ playerid ][ FishKG ] );
								PlayerTextDrawSetString( playerid, FishermangTD[1][ playerid ], globalstring );

								//ChangeFisherManCoordinates( playerid, 0.0000);
								//ShowFishingTD( playerid, true );
								RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );

								ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);

								fishermanInfo[ playerid ][ TriesFish ] = 0;
								if( fishermanInfo[ playerid ][ FishKG ] == 50 ) {

									ClearChat( playerid, 25 );
									SendJobMessage( playerid, "Idite isporucite ribu na lokaciju oznacenu na mapi.");
									CheckpointStatus[ playerid ] = 38;
									SetPlayerCheckpoint( playerid, 2117.7710, 126.1180, -0.4941, 5.0 );
								}
							}
						}
					}
				}
			}
		}
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PNAMESTAJA ) {
		
			if( NamestajLevel[ playerid ] == 3 ) {
			
				if( IsPlayerInRangeOfPoint( playerid, 3, 2144.5337, -2267.7898, 13.2944 ) ) {
				
					if( EndWood[ playerid ] == 1 ) return GRESKA( playerid, "Drvo se jos nije preradilo!" );

					SendJobMessage( playerid, "Skinuli ste preradjeno drvo sa trake, sada ga stavite na zantatski stol!");
					DestroyPlayerObject( playerid, Objekat[ playerid ] );
					SetPlayerSpecialAction( playerid, SPECIAL_ACTION_CARRY);
					SetPlayerAttachedObject( playerid, OBJECT_SLOT_BADGE, 2410, 1, 0.00, 0.46, -0.00, 0.0, 91.0, -1.0, 1.07, 0.88, 1.00 );
					NamestajLevel[ playerid ] = 4;
					Dimi_SetPlayerCheckpoint( playerid, 2125.7715,-2278.3010,14.7825, 4.0 );
					CheckpointStatus[ playerid ] = 40;
				}
				else return GRESKA( playerid, "Ne nalazite se blizu masine!");
			}
		}
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_TEMPODOSTAVA ) {
		
			if( DeliverLevel[ playerid ] == 2 ) {
			
				new Float:vehPos[ 3 ];
				getPosBehindVehicle( DeliverCar[ playerid ], vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0 );
				if( IsPlayerInRangeOfPoint( playerid, 2.0, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) ) {
			
					if( StateBox[ DeliverCar[ playerid ] ] > 0 )
					{
						new randomkutija = random(2);
						if( IsPlayerInAnyVehicle( playerid )) return SendClientMessagee(playerid, -1 , "Morate da izadjete iz vozila!");
						if( StateBox[ DeliverCar[ playerid]  ] == 0) return SendClientMessagee(playerid, -1 ,"U kamionu nema vise paketa!");
						if( CarriesBox[ playerid ] == 1) return SendClientMessagee(playerid, -1 , "Vi vec drzite paket u rukama, ostavite je u trafiku!");
						StateBox[ DeliverCar[ playerid ] ] --;
						CarriesBox[ playerid ] = 1;
						SendJobMessage( playerid, "Izvadili ste paket iz kamiona, paketa u kamionu: %d/%d.", StateBox[ DeliverCar[ playerid ] ],AKTIV_TEMPOKUTIJE);
						SetPlayerSpecialAction( playerid, SPECIAL_ACTION_CARRY);

						if(randomkutija == 0)//paket soka
						{
							SetPlayerAttachedObject(playerid, OBJECT_SLOT_BADGE, 19572, 5, -0.1309, 0.1169, 0.2379, 0.0000, 108.8999, 11.8000, 1.0000, 1.0000, 1.0000, 0, 0);
						}
						else if(randomkutija == 1)//paket hrane
						{
							SetPlayerAttachedObject(playerid, OBJECT_SLOT_BADGE, 1220, 5, 0.042000, 0.115999, 0.184000, 8.499999, 14.900006, 10.999997, 0.551000, 0.406000, 0.593999, 0, 0);
						}
						
						
					}
				}
			}
		}
		
		if( CreateParkingID[ playerid ] != -1 )	{

			if( CreatingParkingLevel[ playerid ] == 6 ) {

				new parkID = CreateParkingID[ playerid ];

				SendInfoMessage( playerid, "Zavrsili ste kreiranje parkinga." );

				Parking_Save( parkID );
				
				CreatingParkingLevel[ playerid ] = 0;
				CreateParkingID[ playerid ] = -1;

			}
		}
	
	}
	else if( PRESSED( KEY_YES ) )//mamu ti jebem
	{


		if( GetFactionType( playerid ) == ORG_TIP_PD )
		{
			if(IsPlayerInRangeOfPoint(playerid,2.0,240.0040,117.6840,1021.4257))
			{
			
				if(vrataPD == false)
				{
					MoveDynamicObject( vrataPDobject, 239.5967, 116.8530, 1020.3098, 1.0, 0.0000, 0.0000, 193.0000 );
					vrataPD = true;
					SetTimer( "ZatvoriPDVrata", 3000, 0 );
					
			
				}

			}
		
		}

		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_FARMER )
		{
		
			new vehicleid = GetPlayerVehicleID( playerid );

			if( vehicleid != INVALID_VEHICLE_ID && isATractor( vehicleid ) && IsPlayerInDynamicArea( playerid, farmerField ) )
			{

				if( farmerVehicles[ vehicleid ][ fvSeeds ] > 0 )
				{
				
					new
						Float:playerPos[ 3 ],
						plantMessage[ 138 ];

					GetPlayerPos( playerid, playerPos[ 0 ], playerPos[ 1 ], playerPos[ 2 ] );
					if( UzeoOpremu[ playerid ] == false ) return GRESKA( playerid, "Nemate opremu!" );
					if( !isPlayerNearFarmerPlant( playerid ) )
					{
						new plantid = GetFreeFarmID( );
						if( farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] == MAX_FARMERS_PLANTS_PLANTED ) return GRESKA( playerid, "Vec si posejao 10 sjemenki!");
						plantInfo[ plantid ][ farmObject ] = CreateDynamicObject( 872, playerPos[ 0 ], playerPos[ 1 ], ( playerPos[ 2 ] - 1 ), 0.0, 0.0, 0.0 );
						plantInfo[ plantid ][ farmPlantCreated ] = true;
						plantInfo[ plantid ][ farmWheatCreated ] = false;
						plantInfo[ plantid ][ farmPlayerID ] = playerid;
						farmerVehicles[ vehicleid ][ fvSeeds ]--;

						format( plantMessage, sizeof( plantMessage ), "FARMERSKI usev\n"col_white"Posijao ga je {36AB00}%s\n"col_white"Da ga sakupis pritisni tipku {36AB00}LMB", ImeIgraca( playerid ) );
						plantInfo[ plantid ][ farm3D ] = CreateDynamic3DTextLabel( plantMessage, 0x0066BAFF, playerPos[ 0 ], playerPos[ 1 ], playerPos[ 2 ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0 );
						farmerInfo[ playerid ][ fiFarmerPlantsPlanted ]++;
						if( farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] == MAX_FARMERS_PLANTS_PLANTED ) 
						{
							farmerInfo[ playerid ][ fiFarmerWheatCreated ] = 0;
							SetVehicleToRespawn( vehicleid );
							SendJobMessage( playerid, "Posejao si sve semenke iz traktora, sada sedi u kombajn i poznji sve." );
						}
					}
				}
				else GRESKA( playerid, "Nemas vise sjemenki u traktoru." );
			}
		}
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PNAMESTAJA ) {
		
			if( NamestajLevel[ playerid ] == 2) {
			
				if( IsPlayerInRangeOfPoint( playerid, 3.0, 2149.6013, -2273.1235, 13.3047 ) ) {
				
					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE ); SetPlayerSpecialAction( playerid, 0 );
					Objekat[ playerid ] = CreatePlayerObject( playerid, 19793, 2150.81616, -2271.90015, 13.31280,   0.00000, 0.00000, -45.00000 );
					MovePlayerObject(playerid, Objekat[ playerid ], 2148.72168, -2270.14478, 13.23200, 1.0 );
					NamestajLevel[ playerid ] = 3; EndWood[ playerid ] = 1;
					SendJobMessage( playerid, "Ubacili ste drva za preradu u masinu, sacekajte da se drvo preradi!");
					SendJobMessage( playerid, "Preradjeno drvo ce izaci na drugu stranu masine.");
					SendJobMessage( playerid, "Sa trake ga uzimate pritiskom na tipku "col_job"N." );
					NamestajTajmer[ playerid ] = SetTimerEx( "Prerada",5000, false, "i", playerid );
					NamestajTajmer2[ playerid ] = SetTimerEx( "Prerada2",10900, false, "i", playerid );
				}
				else return GRESKA(playerid, "Ne nalazite se blizu masine!");
			}
		
		}
		else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_TEMPODOSTAVA ) {
		
			if( DeliverLevel[ playerid ] == 1 ) {
			
				new Float:vehPos[ 3 ];
				getPosBehindVehicle( DeliverCar[ playerid ], vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ], 0.0 );
				if( IsPlayerInRangeOfPoint( playerid, 2.0, vehPos[ 0 ], vehPos[ 1 ], vehPos[ 2 ] ) ) {

					if( StateBox[ DeliverCar[ playerid ] ] < AKTIV_TEMPOKUTIJE ) {

						if( IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate da izadjete iz vozila!");
						if( StateBox[ DeliverCar[ playerid]  ] == AKTIV_TEMPOKUTIJE ) return GRESKA( playerid, "U kamionu ima maksimalan broj kutija!");
						if( CarriesBox[ playerid ] == 0) return GRESKA( playerid, "Vi nemate kutiju u rukama, prvo je uzmite iz skladista!");
						StateBox[ DeliverCar[ playerid ] ] ++;
						CarriesBox[ playerid ] = 0;
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );
						SendJobMessage( playerid, "Stavili ste paket robe u kombi, paketa u kombiju: %d/%d.", StateBox[ DeliverCar[ playerid ] ],AKTIV_TEMPOKUTIJE);
					}

					if( StateBox[ DeliverCar[ playerid ] ] == AKTIV_TEMPOKUTIJE ) {

						DeliverLevel[ playerid ] = 2;
						SendJobMessage( playerid, "Utovarili ste svu robu, sada odvezi robu do Tempo Marketa!");
						SendInfoMessage( playerid, "Kada stignete do Tempo Marketa kutija iz kombija vadite na tipku ' N '!");
						new broj = random( 4 );
						Dimi_SetPlayerCheckpoint( playerid, 1128.5640,-1322.0059,12.8617, 4.0 );
						TrafikaTrenutna[ playerid ] = broj;
						TrafikaPrva[ playerid ] = broj;
						CheckpointStatus[ playerid ] = 5;
						
						StaroVreme[ playerid ] = gettime();
						NovoVreme[ playerid ] = 120;
					}
				}
				else return GRESKA( playerid, "Ne nalazite se iza kamiona!");
				return 1;
			}
			else if( DeliverLevel[ playerid ] == 2 ) {
			
				if( IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate da izadjete iz vozila!");
				if( StateBox[ DeliverCar[ playerid]  ] == AKTIV_TEMPOKUTIJE ) return GRESKA( playerid, "U kamionu ima maksimalan broj kutija!");
				if( CarriesBox[ playerid ] == 0) return GRESKA( playerid, "Vi nemate kutiju u rukama!");
				StateBox[ DeliverCar[ playerid ] ] ++;
				CarriesBox[ playerid ] = 0;
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );
				SendJobMessage( playerid, "Stavili ste paket robe u kombi, paketa u kombiju: %d/%d.", StateBox[ DeliverCar[ playerid ] ],AKTIV_TEMPOKUTIJE);
			
			}
		}
		
		if( CreateParkingID[ playerid ] != -1 )	{

			if( CreatingParkingLevel[ playerid ] == 2 ) {

				new parkID = CreateParkingID[ playerid ], Float:Pos[ 3 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

				ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 0 ] = Pos[ 0 ];
				ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 1 ] = Pos[ 1 ];
				ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 2 ] = Pos[ 2 ];
			 
				CreatingParkingLevel[ playerid ] = 3;

				new string[ 128 ];
				/*format
				( string, 
				sizeof( string ), 
				"{FFFFFF}- Parking Aparat ("col_sanm"%d"col_white") -\n
				{FFFFFF}Da kupite parking listic kucajte\n( "col_balkanstory"/kupiparkinglistic 
				{FFFFFF})", parkID );
				*/
				format( string, sizeof( string ), 
					"{FFFFFF}[ PARKING APARAT - "col_sanm"%d"col_white" ]\n{FFFFFF}Da kupite parking listic kucajte\n( "col_balkanstory"/kupiparkinglistic {FFFFFF})", parkID );
			
				ParkingInfo[ parkID ][ park3d_1 ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 2 ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
				ParkingInfo[ parkID ][ parkPickup_1 ] = CreateDynamicPickup( 1239, 1, ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_1_Pos ][ 2 ], 0, 0 );

				Parking_Save( parkID );

				SendInfoMessage( playerid, "Dodali ste uspjesno poziciju pickupa za kupovinu listica." );
				SendInfoMessage( playerid, "Sada napravite zonu parkinga, krenite prvo sa kordinata leve donje coske." );
				SendInfoMessage( playerid, "Pozicije cuvate koristeci tipk 'Y'.");
			}
			else if( CreatingParkingLevel[ playerid ] == 3 ) {

				new Float:Pos[ 3 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

				if( IsCordsInOtherParkingZone( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugoj parking zoni." );

				CreatingPos[ playerid ][ 0 ] = Pos[ 0 ];
				CreatingPos[ playerid ][ 1 ] = Pos[ 1 ];

				CreatingParkingLevel[ playerid ] = 4;

				SendInfoMessage( playerid, "Sada sacuvajte kordinate desne gornje coske." );
				SendInfoMessage( playerid, "Pozicije cuvate koristeci tipk 'Y'.");
			}
			else if( CreatingParkingLevel[ playerid ] == 4 ) {
			
				new parkID = CreateParkingID[ playerid ], Float:Pos[ 3 ];

				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

				if( IsCordsInOtherParkingZone( Pos[ 0 ], Pos[ 1 ] ) != -1 ) return GRESKA( playerid, "Ne mozes da postavis u drugoj parking zoni." );

				CreatingPos[ playerid ][ 2 ] = Pos[ 0 ];
				CreatingPos[ playerid ][ 3 ] = Pos[ 1 ];

				if( CreatingPos[ playerid ][ 0 ] > CreatingPos[ playerid ][ 2 ] ) {
					ParkingInfo[ parkID ][ parkMaxX ] = CreatingPos[ playerid ][ 0 ];
					ParkingInfo[ parkID ][ parkMinX ] = CreatingPos[ playerid ][ 2 ];
				}
				else if( CreatingPos[ playerid ][ 2 ] > CreatingPos[ playerid ][ 0 ] ) {
					ParkingInfo[ parkID ][ parkMaxX ] = CreatingPos[ playerid ][ 2 ];
					ParkingInfo[ parkID ][ parkMinX ] = CreatingPos[ playerid ][ 0 ];
				}

				if( CreatingPos[ playerid ][ 1 ] > CreatingPos[ playerid ][ 3 ] ) {
					ParkingInfo[ parkID ][ parkMaxY ] = CreatingPos[ playerid ][ 1 ];
					ParkingInfo[ parkID ][ parkMinY ] = CreatingPos[ playerid ][ 3 ];
				}
				else if( CreatingPos[ playerid ][ 3 ] > CreatingPos[ playerid ][ 1 ] ) {
					ParkingInfo[ parkID ][ parkMaxY ] = CreatingPos[ playerid ][ 3 ];
					ParkingInfo[ parkID ][ parkMinY ] = CreatingPos[ playerid ][ 1 ];
				}

				ParkingInfo[ parkID ][ parkRectAngle ] = CreateDynamicRectangle( ParkingInfo[ parkID ][ parkMinX ], ParkingInfo[ parkID ][ parkMinY ], ParkingInfo[ parkID ][ parkMaxX ], ParkingInfo[ parkID ][ parkMaxY ], -1, -1, -1 );
				Parking_Save( parkID );

				CreatingParkingLevel[ playerid ] = 5;

				SendInfoMessage( playerid, "Uspjesno si sacuvao pozicije, sada sacuvaj poziciju za pickup za oznacavanje parking zone." );
			
			}
			else if( CreatingParkingLevel[ playerid ] == 5 ) {

				new parkID = CreateParkingID[ playerid ], Float:Pos[ 3 ];

				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

				new id = IsCordsInParkingZone( parkID, Pos[ 0 ], Pos[ 1 ] );

				if( id != parkID ) return GRESKA( playerid, "Ne moze da ide izvan parkinga." );
				
				ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 0 ] = Pos[ 0 ];
				ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 1 ] = Pos[ 1 ];
				ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 2 ] = Pos[ 2 ];

				CreatingParkingLevel[ playerid ] = 6;

				new string[ 128 ];
				format( string, sizeof( string ), "{FFFFFF}[ PARKING ZONA - "col_sanm"%d"col_white" ]\n{FFFFFF}Otidjite do aparata\nda bi kupili ( "col_balkanstory"parking listic {FFFFFF})", parkID );
			
				ParkingInfo[ parkID ][ park3d_2 ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 2 ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
				ParkingInfo[ parkID ][ parkPickup_2 ] = CreateDynamicPickup( 1239, 1, ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 0 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 1 ], ParkingInfo[ parkID ][ parkPickup_2_Pos ][ 2 ], 0, 0 );

				Parking_Save( parkID );
				
				SendInfoMessage( playerid, "Uspjesno si sacuvao pozicije.");
				SendInfoMessage( playerid, "Sada kreni sa oznacavanjem pozicija za parking mesta koristi tipku 'Y'.");
				SendInfoMessage( playerid, "Da bi oznacio sva mesta moras biti u vozilu, koristi cmd "col_sanm"'/veh 560 1 1'." );
				SendInfoMessage( playerid, "Kada mislis da je dosta, stisni tipku 'N' za kraj." );
				
			}
			else if( CreatingParkingLevel[ playerid ] == 6 ) {
			
				new parkID = CreateParkingID[ playerid ], Float:Pos[ 4 ], filename[ 64 ], string[ 24 ];
				
				new trenutni = ParkingInfo[ parkID ][ parkMaxParkPlaces ];
				
				if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate biti u vozilu." );
				
				if( trenutni == MAX_PARK_PL-1 ) return GRESKA( playerid, "Vec ste kreirali 50 komada." );
				
				GetVehiclePos( GetPlayerVehicleID( playerid ), Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				GetVehicleZAngle( GetPlayerVehicleID( playerid ), Pos[ 3 ] );

				new id = IsCordsInParkingZone( parkID, Pos[ 0 ], Pos[ 1 ] );

				if( id != parkID ) return GRESKA( playerid, "Ne moze da ide izvan parkinga." );

				format( filename, sizeof( filename ), PARKING_FILE, parkID );

				new INI:File = INI_Open( filename );

				format( string, sizeof( string ), "parkPlace_X%d", trenutni );
				INI_WriteFloat( File, string, Pos[ 0 ] );
				ParkingPlaces[ parkID ][ trenutni ][ parkPlace_X ] = Pos[ 0 ];

				format( string, sizeof( string ), "parkPlace_Y%d", trenutni );
				INI_WriteFloat( File, string, Pos[ 1 ] );
				ParkingPlaces[ parkID ][ trenutni ][ parkPlace_Y ] = Pos[ 1 ];

				format( string, sizeof( string ), "parkPlace_Z%d", trenutni );
				INI_WriteFloat( File, string, Pos[ 2 ] );
				ParkingPlaces[ parkID ][ trenutni ][ parkPlace_Z ] = Pos[ 2 ];
				
				format( string, sizeof( string ), "parkPlace_A%d", trenutni );
				INI_WriteFloat( File, string, Pos[ 3 ] );
				ParkingPlaces[ parkID ][ trenutni ][ parkPlace_A ] = Pos[ 3 ];

				ParkingPlaces[ parkID ][ trenutni ][ parkTaken ] = false;

				INI_Close( File );
				SendInfoMessage( playerid, "Postavio si mesto za parking broj - %d.", trenutni+1 );
				ParkingInfo[ parkID ][ parkMaxParkPlaces ]++;
			
			}
		}
		
		
		if( CreatingFStation[ playerid ] != -1 ) {
		
			if( ProcesFStation[ playerid ] == 1 ) {
			
				new fstationID = CreatingFStation[ playerid ];
				new Float:Pos[ 4 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				GetPlayerFacingAngle( playerid, Pos[ 3 ] );
				
				for( new i = 1; i < MAX_CARS; i++ ) {
				
					new fileauta[ 40 ];
					format(fileauta, sizeof( fileauta ), V_FILE, i);
					if( !fexist( fileauta ) ) {
					
						VehicleInfo[ i ][ vOwned ] = 0;
						VehicleInfo[ i ][ vNeaktivnost ] = 0;
						VehicleInfo[ i ][ vKilometri ] = 0;
						VehicleInfo[ i ][ vMetri ] = 0;
						VehicleInfo[ i ][ vPrice ] = 0;
						strmid( VehicleInfo[ i ][ vOwner ], "Drzava", 0, strlen("Drzava"), 32);
						VehicleInfo[ i ][ vLocked ] = 1;
						VehicleInfo[ i ][ vLokacijaX ] = Pos[ 0 ];
						VehicleInfo[ i ][ vLokacijaY ] = Pos[ 1 ];
						VehicleInfo[ i ][ vLokacijaZ ] = Pos[ 2 ];
						VehicleInfo[ i ][ vLokacijaA ] = Pos[ 3 ];
						VehicleInfo[ i ][ vVirtualWorld ] = 0;
						VehicleInfo[ i ][ vInterior ] = 0;
						VehicleInfo[ i ][ vUsage ] = PUMPA_VOZILO;
						VehicleInfo[ i ][ vJob ] = -1;
						VehicleInfo[ i ][ vOrganization ] = -1;
						VehicleInfo[ i ][ vFuelProperty ] = fstationID;
						VehicleInfo[ i ][ vColor1 ] = 4;
						VehicleInfo[ i ][ vColor2 ] = 4;
						VehicleInfo[ i ][ vModel ] = 403;
						VehicleInfo[ i ][ vReg ] = 1;
						VehicleInfo[ i ][ vRegVreme ] = 0;
						VehicleInfo[ i ][ vTeh ] = 1;
						VehicleInfo[ i ][ vGPS ] = 0;
						VehicleInfo[ i ][ vOsiguranje ] = 5;
						VehicleInfo[ i ][ vLock ] = 5;
						VehicleInfo[ i ][ vAlarm ] = 4;
						VehicleInfo[ i ][ vTuned ] = 0;
						VehicleInfo[ i ][ vNeon ] = 0;
						VehicleInfo[ i ][ vImobilizator ] = 5;
						VehicleInfo[ i ][ vSpoiler ] = 0;
						VehicleInfo[ i ][ vHood ] = 0;
						VehicleInfo[ i ][ vRoof ] = 0;
						VehicleInfo[ i ][ vSkirt ] = 0;
						VehicleInfo[ i ][ vLamps ] = 0;
						VehicleInfo[ i ][ vNitro ] = 0;
						VehicleInfo[ i ][ vExhaust ] = 0;
						VehicleInfo[ i ][ vWheels ] = 0;
						VehicleInfo[ i ][ vStereo ] = 0;
						VehicleInfo[ i ][ vHydraulics ] = 0;
						VehicleInfo[ i ][ vFrontBumper ] = 0;
						VehicleInfo[ i ][ vRearBumper ] = 0;
						VehicleInfo[ i ][ vVents ] = 0;
						VehicleInfo[ i ][ vPaintJob ] = 255;
						VehicleInfo[ i ][ vProvera ] = i;
						VehicleInfo[ i ][ vMaterijali ] = 0;
						#if nerp_droga == 1
						VehicleInfo[ i ][ vDrug ][ 0 ] = 0; VehicleInfo[ i ][ vDrug ][ 1 ] = 0; VehicleInfo[ i ][ vDrug ][ 2 ] = 0; VehicleInfo[ i ][ vDrug ][ 3 ] = 0; VehicleInfo[ i ][ vDrug ][ 4 ] = 0; VehicleInfo[ i ][ vDrug ][ 5 ] = 0;
						VehicleInfo[ i ][ vDrugCode ][ 0 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 1 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 2 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 3 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 4 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 5 ] = 0;
						#endif
						VehicleInfo[ i ][ vMelee ] = 0; VehicleInfo[ i ][ vWeap1 ] = 0; VehicleInfo[ i ][ vAmmo1 ] = 0; VehicleInfo[ i ][ vWeap2 ] = 0; VehicleInfo[ i ][ vAmmo2 ] = 0;

						VehicleInfo[ i ][ vID ] = Dimi_CreateVehicle( i, PUMPA_VOZILO, -1, -1, VehicleInfo[ i ][ vFuelProperty ], VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ]+1.0, VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], 300000 );
						SetVehicleVirtualWorld( VehicleInfo[ i ][ vID ], GetPlayerVirtualWorld( playerid ) );
						LinkVehicleToInterior( VehicleInfo[ i ][ vID ], GetPlayerInterior( playerid ) );

						if( VoziloJeDizel( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 1;
						else if( VoziloJeBenzin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 2;
						else if( VoziloJeKerozin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 3;
						else if( VoziloNemaGorivo( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 4;

						VehicleInfo[ i ][ vFuel ] = getAmountFuel( VehicleInfo[ i ][ vID ] ); vCanDrive[ VehicleInfo[ i ][ vID ] ] = 1; Fuel[ VehicleInfo[ i ][ vID ] ] = getAmountFuel( VehicleInfo[ i ][ vID ] );
						UnLockCar( VehicleInfo[ i ][ vID ] ); ResetVehicleStatistics( VehicleInfo[ i ][ vID ] ); SetTablice( VehicleInfo[ i ][ vID ] );
						SaveVehicle( i );
						carspawntimer = 1;
						SetTimer("AntiSpawnCrash", 3000, 0);

						FuelStation[ fstationID ][ fsTruckID ] = i;
						FStation_Save( fstationID );
						PutPlayerInVehicle( playerid, VehicleInfo[ i ][ vID ], 0 );

						SendInfoMessage( playerid, "Sada parkirajte kamion, koristeci tipku Y!" );
						ProcesFStation[ playerid ] = 2;

						break;
					}
				}
			}
			else if( ProcesFStation[ playerid ] == 2 ) {
			
				new fstationID = CreatingFStation[ playerid ];
				
				if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Niste u vozilu!" );
				if( ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] == -1 ) return GRESKA( playerid, "Da bi koristili ovu komandu morate biti u server side vozilu." );

				new autoid = ScriptIDVozila[ GetPlayerVehicleID( playerid ) ], Float:Pos[ 4 ];

				if( VehicleInfo[ autoid ][ vFuelProperty ] != fstationID ) return GRESKA( playerid, "Ovaj kamion ne pripada pumpi koju kreirate." );

				GetVehiclePos( VehicleInfo[ autoid ][ vID ], Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				GetVehicleZAngle( VehicleInfo[ autoid ][ vID ], Pos[ 3 ] );

				VehicleInfo[ autoid ][ vVirtualWorld ] = GetPlayerVirtualWorld( playerid );
				VehicleInfo[ autoid ][ vInterior ] = GetPlayerInterior( playerid );

				VehicleInfo[ autoid ][ vLokacijaX ] = Pos[ 0 ];
				VehicleInfo[ autoid ][ vLokacijaY ] = Pos[ 1 ];
				VehicleInfo[ autoid ][ vLokacijaZ ] = Pos[ 2 ];
				VehicleInfo[ autoid ][ vLokacijaA ] = Pos[ 3 ];

				DestroyVehicle( VehicleInfo[ autoid ][ vID ] );
				VehicleInfo[ autoid ][ vID ] = Dimi_CreateVehicle( autoid, VehicleInfo[ autoid ][ vUsage ], VehicleInfo[ autoid ][ vOrganization ], VehicleInfo[ autoid ][ vJob ], VehicleInfo[ autoid ][ vFuelProperty ], VehicleInfo[ autoid ][ vModel ], VehicleInfo[ autoid ][ vLokacijaX ], VehicleInfo[ autoid ][ vLokacijaY ], VehicleInfo[ autoid ][ vLokacijaZ ]+1.0, VehicleInfo[ autoid ][ vLokacijaA ], VehicleInfo[ autoid ][ vColor1 ], VehicleInfo[ autoid ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ autoid ][ vID ], VehicleInfo[ autoid ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ autoid ][ vID ], VehicleInfo[ autoid ][ vVirtualWorld ] );

				SetVehicleParamsEx( VehicleInfo[ autoid ][ vID ], 0, 0, 0, VehicleInfo[ autoid ][ vLocked ], 0, 0, 0 );

				SaveVehicle( autoid );

				SendInfoMessage( playerid, "Preparkirali ste vozilo. ID = %d.", autoid );
			
				SendInfoMessage( playerid, "Sada dodajte cisternu, koristeci tipku Y!" );
				ProcesFStation[ playerid ] = 3;
			
			}
			else if( ProcesFStation[ playerid ] == 3 ) {
			
				new fstationID = CreatingFStation[ playerid ];
				new Float:Pos[ 4 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				GetPlayerFacingAngle( playerid, Pos[ 3 ] );

				for( new i = 1; i < MAX_CARS; i++ ) {

					new fileauta[ 40 ];
					format(fileauta, sizeof( fileauta ), V_FILE, i);
					if( !fexist( fileauta ) ) {

						VehicleInfo[ i ][ vOwned ] = 0;
						VehicleInfo[ i ][ vNeaktivnost ] = 0;
						VehicleInfo[ i ][ vKilometri ] = 0;
						VehicleInfo[ i ][ vMetri ] = 0;
						VehicleInfo[ i ][ vPrice ] = 0;
						strmid( VehicleInfo[ i ][ vOwner ], "Drzava", 0, strlen("Drzava"), 32);
						VehicleInfo[ i ][ vLocked ] = 1;
						VehicleInfo[ i ][ vLokacijaX ] = Pos[ 0 ];
						VehicleInfo[ i ][ vLokacijaY ] = Pos[ 1 ];
						VehicleInfo[ i ][ vLokacijaZ ] = Pos[ 2 ];
						VehicleInfo[ i ][ vLokacijaA ] = Pos[ 3 ];
						VehicleInfo[ i ][ vVirtualWorld ] = 0;
						VehicleInfo[ i ][ vInterior ] = 0;
						VehicleInfo[ i ][ vUsage ] = PUMPA_VOZILO;
						VehicleInfo[ i ][ vJob ] = -1;
						VehicleInfo[ i ][ vOrganization ] = -1;
						VehicleInfo[ i ][ vFuelProperty ] = fstationID;
						VehicleInfo[ i ][ vColor1 ] = 7;
						VehicleInfo[ i ][ vColor2 ] = 12;
						VehicleInfo[ i ][ vModel ] = 584;
						VehicleInfo[ i ][ vReg ] = 1;
						VehicleInfo[ i ][ vRegVreme ] = 0;
						VehicleInfo[ i ][ vTeh ] = 1;
						VehicleInfo[ i ][ vGPS ] = 0;
						VehicleInfo[ i ][ vOsiguranje ] = 5;
						VehicleInfo[ i ][ vLock ] = 5;
						VehicleInfo[ i ][ vAlarm ] = 4;
						VehicleInfo[ i ][ vTuned ] = 0;
						VehicleInfo[ i ][ vNeon ] = 0;
						VehicleInfo[ i ][ vImobilizator ] = 5;
						VehicleInfo[ i ][ vSpoiler ] = 0;
						VehicleInfo[ i ][ vHood ] = 0;
						VehicleInfo[ i ][ vRoof ] = 0;
						VehicleInfo[ i ][ vSkirt ] = 0;
						VehicleInfo[ i ][ vLamps ] = 0;
						VehicleInfo[ i ][ vNitro ] = 0;
						VehicleInfo[ i ][ vExhaust ] = 0;
						VehicleInfo[ i ][ vWheels ] = 0;
						VehicleInfo[ i ][ vStereo ] = 0;
						VehicleInfo[ i ][ vHydraulics ] = 0;
						VehicleInfo[ i ][ vFrontBumper ] = 0;
						VehicleInfo[ i ][ vRearBumper ] = 0;
						VehicleInfo[ i ][ vVents ] = 0;
						VehicleInfo[ i ][ vPaintJob ] = 255;
						VehicleInfo[ i ][ vProvera ] = i;
						VehicleInfo[ i ][ vMaterijali ] = 0;
						#if nerp_droga == 1
						VehicleInfo[ i ][ vDrug ][ 0 ] = 0; VehicleInfo[ i ][ vDrug ][ 1 ] = 0; VehicleInfo[ i ][ vDrug ][ 2 ] = 0; VehicleInfo[ i ][ vDrug ][ 3 ] = 0; VehicleInfo[ i ][ vDrug ][ 4 ] = 0; VehicleInfo[ i ][ vDrug ][ 5 ] = 0;
						VehicleInfo[ i ][ vDrugCode ][ 0 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 1 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 2 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 3 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 4 ] = 0; VehicleInfo[ i ][ vDrugCode ][ 5 ] = 0;
						#endif
						VehicleInfo[ i ][ vMelee ] = 0; VehicleInfo[ i ][ vWeap1 ] = 0; VehicleInfo[ i ][ vAmmo1 ] = 0; VehicleInfo[ i ][ vWeap2 ] = 0; VehicleInfo[ i ][ vAmmo2 ] = 0;

						VehicleInfo[ i ][ vID ] = Dimi_CreateVehicle( i, PUMPA_VOZILO, -1, -1, VehicleInfo[ i ][ vFuelProperty ], VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ]+1.0, VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], 300000 );
						SetVehicleVirtualWorld( VehicleInfo[ i ][ vID ], GetPlayerVirtualWorld( playerid ) );
						LinkVehicleToInterior( VehicleInfo[ i ][ vID ], GetPlayerInterior( playerid ) );

						if( VoziloJeDizel( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 1;
						else if( VoziloJeBenzin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 2;
						else if( VoziloJeKerozin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 3;
						else if( VoziloNemaGorivo( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 4;

						VehicleInfo[ i ][ vFuel ] = getAmountFuel( VehicleInfo[ i ][ vID ] ); vCanDrive[ VehicleInfo[ i ][ vID ] ] = 1; Fuel[ VehicleInfo[ i ][ vID ] ] = getAmountFuel( VehicleInfo[ i ][ vID ] );
						UnLockCar( VehicleInfo[ i ][ vID ] ); ResetVehicleStatistics( VehicleInfo[ i ][ vID ] ); SetTablice( VehicleInfo[ i ][ vID ] );
						SaveVehicle( i );
						carspawntimer = 1;
						SetTimer("AntiSpawnCrash", 3000, 0);

						SetVehicleLabels( i );

						FuelStation[ fstationID ][ fsCisternID ] = i;
						FStation_Save( fstationID );

						SendInfoMessage( playerid, "Zavrsili ste sa kreiranjem pumpe!" );
						ProcesFStation[ playerid ] = 0;
						CreatingFStation[ playerid ] = -1;

						break;
					}
				}
			}
		}
		
	}
	else if( ( newkeys == KEY_SECONDARY_ATTACK ) && ListaBurg[ playerid ] > 0 ) {
	
		if( ListaBurg[ playerid ] == 1 ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 3 ) return GRESKA( playerid, "Nemate dovoljno novca(3 $)." );
			TogglePlayerControllable( playerid, 1);
			DajIgracuNovac( playerid, -65 ); DajIgracuGlad( playerid, 12 ); Dimi_SetPlayerHealth( playerid, 30 );
			BussinesMoney( uFirmi[ playerid ], 55 );
			SetCameraBehindPlayer( playerid );
			ListaBurg[ playerid ] = 0; OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima hranu sa stola i jede.", ImeIgraca( playerid ) );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			CKilometriTDControl( playerid, false );
		}
		else if( ListaBurg[ playerid ] == 2 ) {
		
			if( PlayerInfo[ playerid ][ xNovac ] < 4 ) return GRESKA( playerid, "Nemate dovoljno novca(4 $)." );
			TogglePlayerControllable( playerid, 1);
			DajIgracuNovac( playerid, -70 ); DajIgracuGlad( playerid, 15 ); Dimi_SetPlayerHealth( playerid, 30 );
			BussinesMoney( uFirmi[ playerid ], 60 );
			SetCameraBehindPlayer( playerid );
			ListaBurg[ playerid ] = 0; OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima hranu sa stola i jede.", ImeIgraca( playerid ) );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			CKilometriTDControl( playerid, false );
		}
		else if( ListaBurg[ playerid ] == 3 )
		{
			if( PlayerInfo[ playerid ][ xNovac ] < 3 ) return GRESKA( playerid, "Nemate dovoljno novca(3 $)." );
			TogglePlayerControllable( playerid, 1);
			DajIgracuNovac( playerid, -60 ); DajIgracuGlad( playerid, 10 ); Dimi_SetPlayerHealth( playerid, 30 );
			BussinesMoney( uFirmi[ playerid ], 52 );
			SetCameraBehindPlayer( playerid );
			ListaBurg[ playerid ] = 0; OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima hranu sa stola i jede.", ImeIgraca( playerid ) );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			CKilometriTDControl( playerid, false );
		}
		else if( ListaBurg[ playerid ] == 4 )
		{
			if( PlayerInfo[ playerid ][ xNovac ] < 5 ) return GRESKA( playerid, "Nemate dovoljno novca(5 $)." );
			TogglePlayerControllable( playerid, 1);
			DajIgracuNovac( playerid, -60 ); DajIgracuGlad( playerid, 10 ); Dimi_SetPlayerHealth( playerid, 30 );
			BussinesMoney( uFirmi[ playerid ], 52 );
			SetCameraBehindPlayer( playerid );
			ListaBurg[ playerid ] = 0; OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima hranu sa stola i jede.", ImeIgraca( playerid ) );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			CKilometriTDControl( playerid, false );
		}
		else if( ListaBurg[ playerid ] == 5 )
		{
			if( PlayerInfo[ playerid ][ xNovac ] < 5 ) return GRESKA( playerid, "Nemate dovoljno novca(5 $)." );
			TogglePlayerControllable( playerid, 1);
			DajIgracuNovac( playerid, -75 ); DajIgracuGlad( playerid, 20 ); Dimi_SetPlayerHealth( playerid, 30 );
			BussinesMoney( uFirmi[ playerid ], 65 );
			SetCameraBehindPlayer( playerid );
			ListaBurg[ playerid ] = 0; OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima hranu sa stola i jede.", ImeIgraca( playerid ) );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			CKilometriTDControl( playerid, false );
		}
	}
	else if( ( newkeys == KEY_JUMP ) && ListaBurg[ playerid ] > 0 )
	{
		SendClientMessagee( playerid, CRVENA, "Odustali ste od kupovine!");
		ListaBurg[ playerid ] = 0;
		TogglePlayerControllable( playerid, true );
		SetCameraBehindPlayer( playerid );
		CKilometriTDControl( playerid, false );
	}
	else if( ( newkeys == KEY_CROUCH ) && NearestGate( playerid ) != -1 )
	{
	
		if( GateData[ NearestGate( playerid ) ][ gateFor ] == 1 )
		{
			if( GateData[ NearestGate( playerid ) ][ gateOrgID ] != -1 )
			{
				if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || GateData[ NearestGate( playerid ) ][ gateOrgID ] == PlayerInfo[ playerid ][ xClan ] )
				{
					Gate_Operate( playerid, NearestGate( playerid ) );
				}
			}
		}
		else if( GateData[ NearestGate( playerid ) ][ gateFor ] == 2 )
		{
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || strcmp( ImeIgraca( playerid ), GateData[ NearestGate( playerid ) ][ gateOwner ], true ) == 0 || strcmp( PlayerInfo[ playerid ][ xKljucKapije ], GateData[ NearestGate( playerid ) ][ gateOwner ], true ) == 0 )
			{
				Gate_Operate( playerid, NearestGate( playerid ) );
			}
		}
		else if( GateData[ NearestGate( playerid ) ][ gateFor ] == 3 )
		{
		
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 )
			{
				Gate_Operate( playerid, NearestGate( playerid ) );
			}
		}
		else if( GateData[ NearestGate( playerid ) ][ gateFor ] == 4 )
		{

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xHelper ] >= 1 )
			{
				Gate_Operate( playerid, NearestGate( playerid ) );
			}
		}
		else if( GateData[ NearestGate( playerid ) ][ gateFor ] == 5 ) {

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xVIPLevel ] >= 1 )
			{
				Gate_Operate( playerid, NearestGate( playerid ) );
			}
		}
		else if( GateData[ NearestGate( playerid ) ][ gateFor ] == 6 )
		{

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xPromoter ] >= 1 )
			{
				Gate_Operate( playerid, NearestGate( playerid ) );
			}
		}
	}
	/*else if( ( newkeys == KEY_CROUCH ) && GetFactionType( playerid ) == ORG_TIP_PD ) {
		
	}*/
	return true;
}

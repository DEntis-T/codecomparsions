#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


public OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ ) {

	/*if( hittype == BULLET_HIT_TYPE_OBJECT ) {
	
		if( hitid == objectzapucanje ) {
			SendClientMessagee( playerid, -1, "PUKO SI GA PICKO." );
		}
	}*/

	if( hittype != BULLET_HIT_TYPE_NONE ) {
		if( !( -1000.0 <= fX <= 1000.0 ) || !( -1000.0 <= fY <= 1000.0 ) || !( -1000.0 <= fZ <= 1000.0 ) ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Bullet Crash", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Bullet Crash");
			return 0;
		}
	}
	if( hittype == BULLET_HIT_TYPE_PLAYER ) {
		if( hitid == playerid ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Bullet Crash", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Bullet Crash");
			return 0;
		}
	}
	
	if( hittype == BULLET_HIT_TYPE_PLAYER ) {
		if( fX == 0.000000 && fY == 0.000000 && fZ == 0.500000 && weaponid == 0 ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Command kill", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Command kill");
			return 0;
		}
	}
	
	if( hittype == 0 && !IsValidWeapon( weaponid ) ) {
		if( fX == 0.000000 && fY == 0.000000 && fZ == 0.000000 ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Bullet Crash", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Bullet Crash");
			return 0;
		}
	}
	
	if( antiCheatCS[ playerid ][ LastAmmo ] != 0 && weaponid != 38 ) {
		if( HavePlayerWeapon( playerid ) ) {
			if( antiCheatCS[ playerid ][ LastAmmo ] == GetPlayerWeaponAmmo( playerid, weaponid ) ) {
				antiCheatCS[ playerid ][ LastAmmoChecks ]++;
				if( antiCheatCS[ playerid ][ LastAmmoChecks ] >= 10 ) {
					antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;
					antiCheatCS[ playerid ][ LastAmmo ] = 0;
					
					format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc infinite ammo hack || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
					AdminPoruka( ANTICHEAT, globalstring );
				}
			}
		}
	}
	antiCheatCS[ playerid ][ LastAmmo ] = GetPlayerAmmo( playerid );
	//
	antiCheatCS[ playerid ][ LastWShot ] = tickcount( );

	if( GetPlayerAmmo( playerid ) <= 1 ) {
		antiCheatCS[ playerid ][ WeaponDetect ] = 3;

		antiCheatCS[ playerid ][ Weapon ][ g_aWeaponSlots[ weaponid ] ] = 0;
		antiCheatCS[ playerid ][ Ammo ][ g_aWeaponSlots[ weaponid ] ] = 0;
	}

	//printf( "Weapon %i fired. hittype: %i   hitid: %i   pos: %f, %f, %f", weaponid, hittype, hitid, fX, fY, fZ);
	return 1;
}



forward neaktivnostFirmi( b );
public neaktivnostFirmi( b ) {

		
	new fFile[ 50 ];
	format( fFile, sizeof( fFile ), F_FILE, b );

	if( fexist( fFile ) ) {
		
		if( BussinesInfo[ b ][ bOwned ] == 1 ) {

			BussinesInfo[ b ][ bNeaktivnost ]++;
			BussinesInfo[ b ][ bFacture ]--;
			
			new time = gettime( );
			if( BussinesInfo[ b ][ bReket ] != -1 && BussinesInfo[ b ][ bReketTime ] != 0 && ( time - BussinesInfo[ b ][ bReketTime ] ) >= 604800 )
			{
				BussinesInfo[ b ][ bReket ] = -1;
				BussinesInfo[ b ][ bReketTime ] = 0;
			}
			
			if( BussinesInfo[ b ][ bNeaktivnost ] >= 500 ) {
				
				new string[ 256 ];

				format( string, sizeof( string ), "FirmaID: %d | Prodana zbog neaktivnosti vlasnika %s ", b, BussinesInfo[ b ][ bOwner ] );
				LogSave( "Ostalo/LogNeaktivnost.log", string );

				BussinesInfo[ b ][ bOwned ] = 0;
				BussinesInfo[ b ][ bNeaktivnost ] = 0;
				BussinesInfo[ b ][ bFacture ] = 100;
				strmid( BussinesInfo[ b ][ bOwner ], "Drzava", 0, strlen( "Drzava" ), 32);
				
			}
			
			if( BussinesInfo[ b ][ bFacture ] <= 0 ) {
			
				new string[ 256 ];

				format( string, sizeof( string ), "FirmaID: %d | Prodana zbog nedostatka fakturi %s ", b, BussinesInfo[ b ][ bOwner ] );
				LogSave( "Ostalo/LogFakture.log", string );

				BussinesInfo[ b ][ bOwned ] = 0;
				BussinesInfo[ b ][ bNeaktivnost ] = 0;
				BussinesInfo[ b ][ bFacture ] = 100;
				strmid( BussinesInfo[ b ][ bOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

			}
			
			SaveBussines( b );
			Bussines_Refresh( b );
		}
	}
		
	if( b+1 < MAX_BUSSINES ) SetTimerEx( "neaktivnostFirmi", 10, false, "d", b+1 );
	return 1;
}

forward neaktivnostImovine( i );
public neaktivnostImovine( i ) {


	new iFile[ 50 ];
	format( iFile, sizeof( iFile ), IM_FILE, i );

	if( fexist( iFile ) ) {

		if( II[ i ][ iOwned ] == 1 ) {

			II[ i ][ iNeaktivnost ]++;
			if( II[ i ][ iNeaktivnost ] >= 500 ) {

				new string[ 256 ];

				format( string, sizeof( string ), "ImovinaID: %d | Prodana zbog neaktivnosti vlasnika %s.", i, II[ i ][ iOwner ] );
				LogSave( "Ostalo/LogNeaktivnost.log", string );

				II[ i ][ iOwned ] = 0;
				II[ i ][ iNeaktivnost ] = 0;
				strmid( II[ i ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
				PropertyRefresh( i );
					
			}
			SaveProperty( i );
			PropertyRefresh( i );
		}
	}
	
	if( i+1 < MAX_IMOVINA ) SetTimerEx( "neaktivnostImovine", 10, false, "d", i+1 );
	return 1;
}

forward neaktivnostVozila( c );
public neaktivnostVozila( c )
{

	new vFile[ 50 ];
	format( vFile, sizeof( vFile ), V_FILE, c );

	if( fexist( vFile ) )
	{
		if( VehicleInfo[ c ][ vUsage ] == PRIVATNO_VOZILO && VehicleInfo[ c ][ vOwned ] == 1 )
		{

			new Float:vehx, Float:vehy, Float:vehz, Float:veha;
			new novacena = VehPrice[ VehicleInfo[ c ][ vModel ] - 400 ][ 1 ];//prava cijena kolko kosta u salonu
			new polovnacena = novacena/2; //pola od prave
			new polovnacena2 = novacena/4;
			new zadnjacena = polovnacena+polovnacena2;
			GetVehiclePos(c, vehx, vehy, vehz);
			GetVehicleZAngle(c, veha);

			VehicleInfo[ c ][ vRegVreme ]--;
			if( VehicleInfo[ c ][ vRegVreme ] == 0 )
			{

				VehicleInfo[ c ][ vReg ] = 0;
				VehicleInfo[ c ][ vTeh ] = 0;
			
			}
			if( VehicleInfo[ c ][ vRegVreme ] == -720 )
			{
			
				Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
				VehicleInfo[ c ][ Validv3DText ] = false;
				
				Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

				VehicleInfo[ c ][ vVirtualWorld ] = 0;
				VehicleInfo[ c ][ vInterior ] = 0;
				
				VehicleInfo[ c ][ vReg ] = 0;
				VehicleInfo[ c ][ vTeh ] = 0;
				VehicleInfo[ c ][ vRegVreme ] = 0;

				VehicleInfo[ c ][ vOwned ] = 0;
				VehicleInfo[ c ][ vNeaktivnost ] = 0;
				VehicleInfo[ c ][ vPrice ] = zadnjacena;
				VehicleInfo[ c ][ vLocked ] = 0;
				VehicleInfo[ c ][ vUsage ] = NAPRODAJU_VOZILO;
				VehicleInfo[ c ][ vLokacijaX ] = vehx;
				VehicleInfo[ c ][ vLokacijaY ] = vehy;
				VehicleInfo[ c ][ vLokacijaZ ] = vehz;
				VehicleInfo[ c ][ vLokacijaA ] = veha;

				VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );

				strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

				TuneVehicle( c );
				SetVehicleLabels( c );

				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
				if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
				{
					SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
				}
			
			}
			
			VehicleInfo[ c ][ vNeaktivnost ]++;
			if( VehicleInfo[ c ][ vNeaktivnost ] >= 500 )
			{

				Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
				VehicleInfo[ c ][ Validv3DText ] = false;

				Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

				VehicleInfo[ c ][ vVirtualWorld ] = 0;
				VehicleInfo[ c ][ vInterior ] = 0;

				VehicleInfo[ c ][ vOwned ] = 0;
				VehicleInfo[ c ][ vNeaktivnost ] = 0;
				VehicleInfo[ c ][ vPrice ] = zadnjacena;
				VehicleInfo[ c ][ vLocked ] = 0;
				VehicleInfo[ c ][ vUsage ] = NAPRODAJU_VOZILO;
				VehicleInfo[ c ][ vLokacijaX ] = vehx;
				VehicleInfo[ c ][ vLokacijaY ] = vehy;
				VehicleInfo[ c ][ vLokacijaZ ] = vehz;
				VehicleInfo[ c ][ vLokacijaA ] = veha;

				VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );
				
				strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

				TuneVehicle( c );
				SetVehicleLabels( c );

				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
				if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
				{
					SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
				}
			}
			SaveVehicle( c );
		}
	}
	
	if( c+1 < MAX_CARS ) SetTimerEx( "neaktivnostVozila", 10, false, "d", c+1 );
	return 1;
}

CheckTickRate(); public CheckTickRate()
{
	printf("\tTick rate servera je: %i", GetServerTickRate());
	return 1;
}

NeaktivnostDodavanje(); public NeaktivnostDodavanje()
{

	SetTimerEx( "neaktivnostFirmi", 10, false, "d", 0 );

	SetTimerEx( "neaktivnostImovine", 15000, false, "d", 0 );

	SetTimerEx( "neaktivnostVozila", 80000, false, "d", 0 );

	return 1;
}
//------------------------------------------------------------------------------
stock UpdateSpecTD(playerid, targetid)
{
	SpecTDControl(playerid,false);
	new str[100], Float:h;
	GetPlayerHealth(playerid,h);
	format(str,100,"%i",PlayerInfo[targetid][xLevel]);
	PlayerTextDrawSetString(playerid, SpecTextdraw[2][playerid], str);
	
	format(str,100,"%s (%i)",ImeIgraca(targetid),targetid);
	PlayerTextDrawSetString(playerid, SpecTextdraw[3][playerid], str);
	
	format(str,100,"%i $",PlayerInfo[targetid][xNovac]);
	PlayerTextDrawSetString(playerid, SpecTextdraw[4][playerid], str);
	
	format(str,100,"%f",h);
	PlayerTextDrawSetString(playerid, SpecTextdraw[7][playerid], str);

	if(GetPlayerWeapon(targetid) != 0)
	{
		format(str,100,"%i",GetPlayerAmmo(targetid));
		PlayerTextDrawSetString(playerid, SpecTextdraw[10][playerid], str);

		PlayerTextDrawSetString(playerid,SpecTextdraw[9][playerid],
			WeaponInfos[ GetPlayerWeapon(targetid) ][ wTXDName ]);
	}
	if(GetPlayerWeapon(targetid) == 0)
	{
		format(str,100,"");
		PlayerTextDrawSetString(playerid, SpecTextdraw[10][playerid], str);

		PlayerTextDrawSetString(playerid,SpecTextdraw[9][playerid],
			WeaponInfos[ GetPlayerWeapon(targetid) ][ wTXDName ]);
	}
	PlayerTextDrawSetPreviewModel(playerid,SpecTextdraw[11][playerid],
		PlayerInfo[targetid][xSkin]);

	SpecTDControl(playerid,true);
	return 1;
}

//------------------------------------------------------------------------------
forward StopSearchNadji( playerid );
public StopSearchNadji( playerid )
{
	SearchNadji[ playerid ] = IPI;
	return true;
}
//------------------------------------------------------------------------------
forward Pitanje( playerid );
public Pitanje( playerid )
{
	if( PlayerInfo[ playerid ][ xRPLearn ] == 1 )
	{
		Dimi_KillTimer( TimerPitanje[ playerid ] );
		Dimi_Kick( playerid );
	}
	else
	{
		Dimi_KillTimer( TimerPitanje[ playerid ] );
	}
	return true;

}
//------------------------------------------------------------------------------
forward KrajRenta( playerid, vehicleid );
public KrajRenta( playerid, vehicleid )
{
	VehicleObjectCheck( vehicleid );
	SetVehicleToRespawn( vehicleid );
	LinkVehicleToInterior( vehicleid, 0 );
	if( Rentano[ playerid ] == vehicleid )
	{
		Rentano[ playerid ] = -1;
		Dimi_KillTimer( RentTimer[ playerid ] );
	}
	SendInfoMessage(playerid, "Isteklo je vrijeme renta i vozilo je vraceno!");
	return true;
}
//------------------------------------------------------------------------------
// anticheat
forward Dimi_SetPlayerPos( playerid, Float:x, Float:y, Float:z );
public Dimi_SetPlayerPos( playerid, Float:x, Float:y, Float:z ) 
{
	SetPlayerPos( playerid, x, y, z );
	antiCheatCS[ playerid ][ TeleportPos ][ 0 ] = x;
	antiCheatCS[ playerid ][ TeleportPos ][ 1 ] = y;
	antiCheatCS[ playerid ][ TeleportPos ][ 2 ] = z;
	antiCheatCS[ playerid ][ TeleportCheck ] = 4;
	antiCheatCS[ playerid ][ EnterVehTime ] -= 221;
	return true;
}

forward Dimi_SetSpawnInfo( playerid );
public Dimi_SetSpawnInfo( playerid ) 
{
	new rand;

	if( playerid % 2 == 0 ) {
		rand = random( sizeof( RandomLSSpawn1 ) );
		antiCheatCS[ playerid ][ TeleportPos ][ 0 ] = RandomLSSpawn1[ rand ][ 0 ];
		antiCheatCS[ playerid ][ TeleportPos ][ 1 ] = RandomLSSpawn1[ rand ][ 1 ];
		antiCheatCS[ playerid ][ TeleportPos ][ 2 ] = RandomLSSpawn1[ rand ][ 2 ];
		SetSpawnInfo( playerid, 0, PlayerInfo[ playerid ][ xSkin ], RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ], 360.00, 0, 0, 0, 0, 0, 0 );
	}
	else {
		rand = random( sizeof( RandomLSSpawn2 ) );
		antiCheatCS[ playerid ][ TeleportPos ][ 0 ] = RandomLSSpawn2[ rand ][ 0 ];
		antiCheatCS[ playerid ][ TeleportPos ][ 1 ] = RandomLSSpawn2[ rand ][ 1 ];
		antiCheatCS[ playerid ][ TeleportPos ][ 2 ] = RandomLSSpawn2[ rand ][ 2 ];
		SetSpawnInfo( playerid, 0, PlayerInfo[ playerid ][ xSkin ], RandomLSSpawn2[ rand ][ 0 ], RandomLSSpawn2[ rand ][ 1 ], RandomLSSpawn2[ rand ][ 2 ], 360.00, 0, 0, 0, 0, 0, 0 );
	}
	antiCheatCS[ playerid ][ TeleportCheck ] = 4;
	return true;
}

stock Dimi_AttachTrailerToVehicle( trailerid, vehicleid ) 
{
	LastPullingVehicle[ trailerid ] = vehicleid;
	return AttachTrailerToVehicle( trailerid, vehicleid );
}

forward Dimi_SetVehiclePos( vehicleid, Float:x, Float:y, Float:z );
public Dimi_SetVehiclePos( vehicleid, Float:x, Float:y, Float:z ) 
{
	if( vehicleid != INVALID_VEHICLE_ID ) {
		if( SetVehiclePos( vehicleid, x, y, z ) ) {
			RealVehiclePositions[ vehicleid ][ 0 ] = x;
			RealVehiclePositions[ vehicleid ][ 1 ] = y;
			RealVehiclePositions[ vehicleid ][ 2 ] = z;
			for(new i; i < MAX_PLAYERS; i++) {
				if( GetPlayerVehicleID( i ) == vehicleid ) {
					antiCheatCS[ i ][ TeleportPos ][ 0 ] = x;
					antiCheatCS[ i ][ TeleportPos ][ 1 ] = y;
					antiCheatCS[ i ][ TeleportPos ][ 2 ] = z;
					antiCheatCS[ i ][ TeleportCheck ] = 4;
					antiCheatCS[ i ][ EnterVehTime ] -= 221;
				}
			}
			return 1;
		}
	}
	return 1;
}

stock Dimi_PutPlayerInVehicle( playerid, vehicleid, seatid ) 
{
	antiCheatCS[ playerid ][ EnteredVehicle ] = vehicleid;
	antiCheatCS[ playerid ][ EnterVehTime ] -= 221;
	PutPlayerInVehicle( playerid, vehicleid, seatid );
}

stock Dimi_RemovePlayerFromVehicle( playerid ) 
{
	antiCheatCS[ playerid ][ RemoveVehicle ] = true;
	antiCheatCS[ playerid ][ EnteredVehicle ] = INVALID_VEHICLE_ID;
	antiCheatCS[ playerid ][ EnterVehTime ] -= 221;
	return RemovePlayerFromVehicle( playerid );
}
//------------------------------------------------------------------------------
public UlazIzlaz( playerid ) 
{
	antiCheatCS[ playerid ][ TeleportCheck ] = 4;
	for( new i= 1; i < MAX_ORG; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 2.0, OI[ i ][ oPozExtX ], OI[ i ][ oPozExtY ], OI[ i ][ oPozExtZ ] ) ) {

			if( OI[ i ][ oTip ] == ORG_TIP_PD || OI[ i ][ oTip ] == ORG_TIP_CNN || OI[ i ][ oTip ] == ORG_TIP_MD || OI[ i ][ oTip ] == ORG_TIP_TAXI ) {

				FadeFromBlack( playerid );
				
				Dimi_SetPlayerPos( playerid, OI[ i ][ oPozIntX ], OI[ i ][ oPozIntY ], OI[ i ][ oPozIntZ ] );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, OI[ i ][ oInt ] );
				SetPlayerVirtualWorld( playerid, OI[ i ][ oVw ] );
				inOrgInt[ playerid ] = i;
			}
			else {
			
				if( PlayerInfo[ playerid ][ xClan ] == i || PlayerInfo[ playerid ][ xAdmin ] >= 1337 ) 
				{

					FadeFromBlack( playerid );

					Dimi_SetPlayerPos( playerid, OI[ i ][ oPozIntX ], OI[ i ][ oPozIntY ], OI[ i ][ oPozIntZ ] );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
					SetCameraBehindPlayer( playerid );
					TogglePlayerControllable( playerid, false );
					SetPlayerInterior( playerid, OI[ i ][ oInt ] );
					SetPlayerVirtualWorld( playerid, OI[ i ][ oVw ] );
					inOrgInt[ playerid ] = i;
				}
				else return announcement( playerid, "~r~Zakljucano", 5000, 6 );
			}
		}
		else if( IsPlayerInRangeOfPoint( playerid, 2.0, OI[ i ][ oPozIntX ], OI[ i ][ oPozIntY ], OI[ i ][ oPozIntZ ] ) && GetPlayerVirtualWorld( playerid ) == OI[ i ][ oVw ] ) {

			FadeFromBlack( playerid );

			Dimi_SetPlayerPos( playerid, OI[ i ][ oPozExtX ], OI[ i ][ oPozExtY ], OI[ i ][ oPozExtZ ] );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, 0);
			SetPlayerInterior( playerid, 0);
			SetPlayerVirtualWorld( playerid, 0);
			inOrgInt[ playerid ] = -1;
		}
	}
	//DRUG LAB
	//DrugFactoryCoords  | 2 |1314
	for( new i= 1; i < MAX_ORG; i++) {

		if(IsPlayerInRangeOfPoint( playerid, 2.0, 
			OI[ i ][ oDrugFactoryPos ] [0], 
			OI[ i ][ oDrugFactoryPos ] [1], 
			OI[ i ][ oDrugFactoryPos ] [2] ) 
			&& inOrgInt[ playerid ] == i) 
		{

			if(PlayerInfo[playerid][xClan] == i) 
			{
				FadeFromBlack( playerid );
				Dimi_SetPlayerPos( playerid, DrugFactoryCoords  );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, DrugFactoryInt );
				SetPlayerVirtualWorld( playerid, OI[ i ][ oVw ] );
				inOrgInt[ playerid ] = -1;
				inDrugFactory[playerid] = i;
			}
			else if(PlayerInfo[playerid][xClan] != i)
			{
				announcement(playerid, "~r~Zakljucano");
			}
		}
	}
	if(IsPlayerInRangeOfPoint( playerid, 2.0, DrugFactoryCoords )) 
	{
		if(PlayerInfo[playerid][xClan] == inDrugFactory[playerid]) 
		{
			FadeFromBlack( playerid );
			Dimi_SetPlayerPos( playerid, 
				OI[ inDrugFactory[playerid] ][ oDrugFactoryPos ] [0], 
				OI[ inDrugFactory[playerid] ][ oDrugFactoryPos ] [1], 
				OI[ inDrugFactory[playerid] ][ oDrugFactoryPos ] [2]);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, 0);
			SetPlayerInterior( playerid, OI[ inDrugFactory[playerid] ][ oInt ]);
			SetPlayerVirtualWorld( playerid, OI[ inDrugFactory[playerid] ][ oVw ]);
			inOrgInt[ playerid ] = inDrugFactory[playerid];
			inDrugFactory[playerid] = -1;
		}
		else if(PlayerInfo[playerid][xClan] != inDrugFactory[playerid])
		{
			announcement(playerid, "~r~Zakljucano");
		}
	}
	//ORG GARAGE
	for( new i= 1; i < MAX_ORG; i++) {

		if(IsPlayerInRangeOfPoint( playerid, 2.0, 
			OI[ i ][ oGaragePos ] [0], 
			OI[ i ][ oGaragePos ] [1], 
			OI[ i ][ oGaragePos ] [2] ) 
			&& inOrgInt[ playerid ] == i) {

			if(PlayerInfo[playerid][xClan] == i) 
			{
				FadeFromBlack( playerid );
				Dimi_SetPlayerPos( playerid, GarageCoords  );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, GarageInt );
				SetPlayerVirtualWorld( playerid, OI[ i ][ oVw ] );
				inOrgInt[ playerid ] = -1;
				inOrgGarage[playerid] = i;
			}
			else if(PlayerInfo[playerid][xClan] != i)
			{
				announcement(playerid, "~r~Zakljucano");
			}
		}
	}
	if(IsPlayerInRangeOfPoint( playerid, 2.0, GarageCoords )) 
	{
		if(PlayerInfo[playerid][xClan] == inOrgGarage[playerid]) 
		{
			FadeFromBlack( playerid );
			Dimi_SetPlayerPos( playerid, 
				OI[ inOrgGarage[playerid] ][ oGaragePos ] [0], 
				OI[ inOrgGarage[playerid] ][ oGaragePos ] [1], 
				OI[ inOrgGarage[playerid] ][ oGaragePos ] [2]);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, 0);
			SetPlayerInterior( playerid, OI[ inOrgGarage[playerid] ][ oInt ]);
			SetPlayerVirtualWorld( playerid, OI[ inOrgGarage[playerid] ][ oVw ]);
			inOrgInt[ playerid ] = inOrgGarage[playerid];
			inOrgGarage[playerid] = -1;
		}
		else if(PlayerInfo[playerid][xClan] != inOrgGarage[playerid])
		{
			announcement(playerid, "~r~Zakljucano");
		}
	}
	//PORTOVI ORGI
	for( new i = 1; i < MAX_ORG; i++ ) {
		for( new id = 0; id < OI[ i ][ oMaxPort ]; id++ ) {
			if( PlayerInfo[ playerid ][ xClan ] == i ) {
				if( IsPlayerInRangeOfPoint( playerid, 2.0, PortOP[ i ][ id ][ Pos1 ][ 0 ], PortOP[ i ][ id ][ Pos1 ][ 1 ], PortOP[ i ][ id ][ Pos1 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 0 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 0 ] ) {
					Dimi_SetPlayerPos( playerid, PortOP[ i ][ id ][ Pos2 ][ 0 ], PortOP[ i ][ id ][ Pos2 ][ 1 ], PortOP[ i ][ id ][ Pos2 ][ 2 ] );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
					SetCameraBehindPlayer( playerid );
					TogglePlayerControllable( playerid, false );
					SetPlayerInterior( playerid, PortOP[ i ][ id ][ Int ][ 1 ] );
					SetPlayerVirtualWorld( playerid, PortOP[ i ][ id ][ VW ][ 1 ] );
				}
				else if( IsPlayerInRangeOfPoint( playerid, 2.0, PortOP[ i ][ id ][ Pos2 ][ 0 ], PortOP[ i ][ id ][ Pos2 ][ 1 ], PortOP[ i ][ id ][ Pos2 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 1 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 1 ] ) {
					Dimi_SetPlayerPos( playerid, PortOP[ i ][ id ][ Pos1 ][ 0 ], PortOP[ i ][ id ][ Pos1 ][ 1 ], PortOP[ i ][ id ][ Pos1 ][ 2 ] );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
					SetCameraBehindPlayer( playerid );
					TogglePlayerControllable( playerid, false );
					SetPlayerInterior( playerid, PortOP[ i ][ id ][ Int ][ 0 ] );
					SetPlayerVirtualWorld( playerid, PortOP[ i ][ id ][ VW ][ 0 ] );
				}
			}
		}
	}
	for( new i= 1; i < MAX_IMOVINA; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 2.0, II[ i ][ iEnter ][ 0 ], II[ i ][ iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] ) ) {

			if( II[ i ][ iLocked ] == 0 ) {

				FadeFromBlack( playerid );

				Dimi_SetPlayerPos( playerid, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, II[ i ][ iInterior ] );
				SetPlayerVirtualWorld( playerid, II[ i ][ iVW ] );
				inProperty[ playerid ] = i;
			}
			else return announcement( playerid, "~r~Zakljucano", 5000, 6 );
		}
		else if( IsPlayerInRangeOfPoint( playerid, 2.0, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == II[ i ][ iVW ] ) {

			FadeFromBlack( playerid );

			Dimi_SetPlayerPos( playerid, II[ i ][ iEnter ][ 0 ], II[ i ][ iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, 0);
			SetPlayerInterior( playerid, 0);
			SetPlayerVirtualWorld( playerid, 0);
			inProperty[ playerid ] = -1;
		}
	}
	for( new i = 1; i < MAX_HOTELS; i++) {
	
		if( IsPlayerInRangeOfPoint( playerid, 2.0, hotelInfo[ i ][ hEnter ][ 0 ], hotelInfo[ i ][ hEnter ][ 1 ], hotelInfo[ i ][ hEnter ][ 2 ] ) ) {

			if( hotelInfo[ i ][ hLocked ] == 0 ) {
			
				FadeFromBlack( playerid );

				Dimi_SetPlayerPos( playerid, hotelInfo[ i ][ hExit ][ 0 ], hotelInfo[ i ][ hExit ][ 1 ], hotelInfo[ i ][ hExit ][ 2 ] );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, hotelInfo[ i ][ hInterior ] );
				SetPlayerVirtualWorld( playerid, hotelInfo[ i ][ hVW ] );
				inHotel[ playerid ] = i;
			}
			else return announcement( playerid, "~r~Zakljucano", 5000, 6 );
		}
		else if( IsPlayerInRangeOfPoint( playerid, 2.0, hotelInfo[ i ][ hExit ][ 0 ], hotelInfo[ i ][ hExit ][ 1 ], hotelInfo[ i ][ hExit ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == hotelInfo[ i ][ hVW ] ) {

			FadeFromBlack( playerid );

			Dimi_SetPlayerPos( playerid, hotelInfo[ i ][ hEnter ][ 0 ], hotelInfo[ i ][ hEnter ][ 1 ], hotelInfo[ i ][ hEnter ][ 2 ] );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx("SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, 0 );
			SetPlayerInterior( playerid, 0 );
			SetPlayerVirtualWorld( playerid, 0 );
			inHotel[ playerid ] = -1;
		}
	}
	for( new f = 1; f < MAX_BUSSINES; f++)
	{
	
		if( IsPlayerInRangeOfPoint( playerid, 1.0, BussinesInfo[ f ][ bEnterX], BussinesInfo[ f ][ bEnterY], BussinesInfo[ f ][ bEnterZ] ) )
		{

			if( BussinesInfo[ f ][ bLocked ] == 1 ) return GRESKA( playerid, "Ova firma je zakljucana!" );
			if( BussinesInfo[ f ][ bType ] == VRSTA_JFIRMA ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_TRAFIKA ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_POSAO ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_RENT ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			//else if( BussinesInfo[ f ][ bType ] == VRSTA_OGLAS ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_TELEKOM ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_PAYSPRAY ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_KOMUNALIJE ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_VODOVOD ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_ELEKTRANA ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_LUTRIJA ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_NEON ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			else if( BussinesInfo[ f ][ bType ] == VRSTA_RODA ) return GRESKA( playerid, "Ova firma je zakljucana - ne mozete u nju da udjete!" );
			/*else if( BussinesInfo[ f ][ bType ] == VRSTA_JAVNAK || BussinesInfo[ f ][ bType ] == VRSTA_KLAD  )
			{
				if( PlayerInfo[ playerid ][ xGodine ] < 18 ) return GRESKA( playerid, "Zabranjen ulaz maloletnicima, samo 18+." );
			}*/
			
			FadeFromBlack( playerid );

			Dimi_SetPlayerPos( playerid, BussinesInfo[ f ][ bExitX], BussinesInfo[ f ][ bExitY ], BussinesInfo[ f ][ bExitZ ] );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, BussinesInfo[ f ][ bInInt ] );
			SetPlayerVirtualWorld( playerid, BussinesInfo[ f ][ bInVW ] );
			uFirmi[ playerid ] = f;
			if( BussinesInfo[ f ][ bType ] == VRSTA_MARKET )
			{
				if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) return GRESKA( playerid, "Ne mozete uci sa objektom u desnoj ruci.");
				SendUsageMessage( playerid, "/ubaci [ opcija ] | /izbaci [ opcija ]");
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19592, 6, 0.08, -0.12, -0.07, -54.0, -95.0, 15.0, 1.00, 1.00, 1.00 );
				format( globalstring, sizeof( globalstring ), "%s desnom rukom uzima korpu za kupovinu.", ImeIgraca( playerid ) );
				PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			}
			SetPlayerTime( playerid, 12, 0 );
			if( BussinesInfo[ f ][ bType ] == VRSTA_JAVNAK )
			{
				SetPlayerTime( playerid, 20, 0 );
			}
		}
		else if( IsPlayerInRangeOfPoint( playerid, 2.0, BussinesInfo[ f ][ bExitX ], BussinesInfo[ f ][ bExitY ], BussinesInfo[ f ][ bExitZ ] ) && GetPlayerVirtualWorld( playerid ) == BussinesInfo[ f ][ bInVW ] ) {

			if( BussinesInfo[ f ][ bType ] == VRSTA_MARKET ) {
				UzeoIzMarketa[ playerid ][ 0 ] = 0;
				UzeoIzMarketa[ playerid ][ 1 ] = 0;
				UzeoIzMarketa[ playerid ][ 2 ] = 0;
				UzeoIzMarketa[ playerid ][ 3 ] = 0;
				UzeoIzMarketa[ playerid ][ 4 ] = 0;
				UzeoIzMarketa[ playerid ][ 5 ] = 0;
				UzeoIzMarketa[ playerid ][ 6 ] = 0;
				UzeoIzMarketa[ playerid ][ 7 ] = 0;
				UzeoIzMarketa[ playerid ][ 8 ] = 0;
				UzeoIzMarketa[ playerid ][ 9 ] = 0;
				UzeoIzMarketa[ playerid ][ 10 ] = 0;
				UkupnaCena[ playerid ] = 0;
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
			}

			FadeFromBlack( playerid );

			Dimi_SetPlayerPos( playerid, BussinesInfo[ f ][ bEnterX ], BussinesInfo[ f ][ bEnterY ], BussinesInfo[ f ][ bEnterZ ] );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, BussinesInfo[ f ][ bInt ] );
			SetPlayerVirtualWorld( playerid, BussinesInfo[ f ][ bVW ] );
			uFirmi[ playerid ] = -1;
			SetPlayerTime( playerid, ServerInfo[ VremeInGame ], 0 );
		}
	}
	for( new i; i < MAX_INTERIJERA; i++) {
	
		if( IsPlayerInRangeOfPoint( playerid, 1.5, IntInfo[ i ][iXUlaz], IntInfo[ i ][iYUlaz], IntInfo[ i ][iZUlaz]) && GetPlayerVirtualWorld( playerid ) == IntInfo[ i ][iVwIDSpolja] && !IsPlayerInAnyVehicle( playerid )) {

			FadeFromBlack( playerid );

			SetPlayerInterior( playerid, IntInfo[ i ][iIntID] );
			SetPlayerVirtualWorld( playerid, IntInfo[ i ][iVwID] );
			Dimi_SetPlayerPos( playerid, IntInfo[ i ][iXIzlaz], IntInfo[ i ][iYIzlaz], IntInfo[ i ][iZIzlaz] );
			SetPlayerFacingAngle( playerid, IntInfo[ i ][iAIzlaz] );
			SetCameraBehindPlayer( playerid );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false);
			SetPlayerTime( playerid, 12, 0 );
			uInterijeru[ playerid ] = i;
			
		}
		else if( IsPlayerInRangeOfPoint( playerid, 1.5, IntInfo[ i ][iXIzlaz], IntInfo[ i ][iYIzlaz], IntInfo[ i ][iZIzlaz]) && GetPlayerVirtualWorld( playerid ) == IntInfo[ i ][iVwID]) {

			FadeFromBlack( playerid );

			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false);
			SetPlayerVirtualWorld( playerid, IntInfo[ i ][iVwIDSpolja] );
			SetPlayerInterior( playerid, IntInfo[ i ][iIntIDSpolja] );
			Dimi_SetPlayerPos( playerid, IntInfo[ i ][iXUlaz], IntInfo[ i ][iYUlaz], IntInfo[ i ][iZUlaz] );
			SetPlayerFacingAngle( playerid, IntInfo[ i ][iAUlaz] );
			SetCameraBehindPlayer( playerid );
			SetPlayerTime( playerid, ServerInfo[ VremeInGame ], 0 );
			uInterijeru[ playerid ] = -1;
		}
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1924.3861, -1524.3082, 2429.4849 ) ) { // CNN Studio
	
		FadeFromBlack( playerid );
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerInterior( playerid, 3 );
		SetPlayerVirtualWorld( playerid, 3 );
		Dimi_SetPlayerPos( playerid, 1917.1879, -1533.8624, 2429.4897 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1524.6689, -1726.9661, -60.5881 ) ) { // PD KROV
	
		if( GetFactionType( playerid ) == ORG_TIP_PD ) {
		
			SetCameraBehindPlayer( playerid );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 0 );
			SetPlayerVirtualWorld( playerid, 0 );
			Dimi_SetPlayerPos( playerid, 1564.8328, -1666.9375, 28.3956 );
		}
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1879.1925,2339.4995,10.9799 ) ) { // Heki helipad
		SetCameraBehindPlayer( playerid );
		SetPlayerInterior( playerid, 0 );
		SetPlayerVirtualWorld( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1871.5922,2332.8225,14.7813 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1871.5922,2332.8225,14.7813 ) ) { // Heki helipad
		SetCameraBehindPlayer( playerid );
		SetPlayerInterior( playerid, 0 );
		SetPlayerVirtualWorld( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1879.1925,2339.4995,10.9799 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1533.1113, -1736.2327, -64.0829 ) ) { // PD GARAZA
		if( GetFactionType( playerid ) == ORG_TIP_PD ) {
			SetCameraBehindPlayer( playerid );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 0 );
			SetPlayerVirtualWorld( playerid, 0 );
			Dimi_SetPlayerPos( playerid, 1524.4833, -1677.7874, 6.2188 );
		}
	}
	if( IsPlayerInRangeOfPoint(playerid, 1.5, 1564.8328, -1666.9375, 28.3956 ) ) { //// PD KROV
		if( GetFactionType( playerid ) == ORG_TIP_PD ) {
			SetCameraBehindPlayer(playerid);
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 3 );
			SetPlayerVirtualWorld( playerid, 3 );
			Dimi_SetPlayerPos( playerid, 1524.6689, -1726.9661, -60.5881 );
		}
	}
	if( IsPlayerInRangeOfPoint(playerid, 1.5, 1524.4833, -1677.7874, 6.2188 ) ) { // PD GARAZA
		if( GetFactionType( playerid ) == ORG_TIP_PD ) {
			SetCameraBehindPlayer(playerid);
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 3 );
			SetPlayerVirtualWorld( playerid, 3 );
			Dimi_SetPlayerPos( playerid, 1533.1113, -1736.2327, -64.0829 );
		}
	}
	/////////////////GIGATRON////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 3.0,1420.5889,-1178.2612,25.9932 ) )
	{ // GIGATRON ULAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1395.9540,-1197.2256,2002.9253 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 3.0,1395.9165,-1200.2422,2002.9253 ) )
	{ // GIGATRON IZLAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1424.0372,-1178.1893,25.9932 );
	}
	//////////////////GRANICNI PRELAZ KUCICA//////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0,1743.9816,538.1619,26.9405 ) )
	{ // GRANICNI PRELAZ ULAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1742.4491,533.6021,27.2972 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0,1742.4491,533.6021,27.2972 ) )
	{ // GRANICNI PRELAZ IZLAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1743.9816,538.1619,26.9405 );
	}
	//////////////////GRANICNI PRELAZ 2 KUCICA//////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0,58.7620,-1532.6776,5.2208 ) )
	{ // GRANICNI PRELAZ 2- ULAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 55.0628,-1532.0175,5.2585);
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0,55.0628,-1532.0175,5.2585 ) )
	{ // GRANICNI PRELAZ 2 -IZLAZ
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 58.7620,-1532.6776,5.2208 );
	}
	///////////////GIGATRON END//////////////////
	if( IsPlayerInRangeOfPoint( playerid, 3.0, 1700.5277, -1667.7759, 20.2188 ) )
	{ // AFK Zona
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 1733.2987,-1912.1025,13.6621 );
	}
	
	if( IsPlayerInRangeOfPoint( playerid, 3.0, 1733.2987,-1912.1025,13.6621 ) )
	{ // AFK Zona
		if( PlayerInfo[ playerid ][ xWanted ] == 0 )
		{
			antiCheatCS[ playerid ][ TeleportCheck ] = 4;

			new rand = random( sizeof( RandomAFKZone ) );
			Dimi_SetPlayerPos( playerid, RandomAFKZone[ rand ][ 0 ], RandomAFKZone[ rand ][ 1 ], RandomAFKZone[ rand ][ 2 ] );
			SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetCameraBehindPlayer( playerid );
			SetPlayerInterior( playerid, 18 );
			SetPlayerVirtualWorld( playerid, 0 );
		}
		else return GRESKA( playerid, "Ne mozete sa wanted levelom uci!" );
	}
	
	
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 0, 0, 10000 ) ) { // Bela kuca
	
		FadeFromBlack( playerid );
	
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 5 );
		Dimi_SetPlayerPos( playerid, 1261.3109, -785.4236, 1091.9063 );
	}
	if( IsPlayerInRangeOfPoint(playerid, 1.5, 1917.1879, -1533.8624, 2429.4897 ) ) { // CNN Studio
		SetCameraBehindPlayer(playerid);
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid);
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerInterior( playerid, 3 );
		SetPlayerVirtualWorld( playerid, 3 );
		Dimi_SetPlayerPos( playerid, 1924.3861, -1524.3082, 2429.4849 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1261.3109, -785.4236, 1091.9063)) { // Bela kuca
		SetCameraBehindPlayer( playerid );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		TogglePlayerControllable( playerid, false );
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		Dimi_SetPlayerPos( playerid, 0, 0, 10000 );
	}
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 493.1782,788.5486,-22.1103 ) ) { // Rudnik
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR || PlayerInfo[ playerid ][ xHelper ] >= 1 || PlayerInfo[ playerid ][ xAdmin ] >= 1 )
		{
			SetPlayerVirtualWorld( playerid, 1 );
			SetPlayerInterior( playerid, 1 );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			Dimi_SetPlayerPos( playerid, 499.7608,772.2524,1001.4630 );
			SetCameraBehindPlayer( playerid );
		}
		else return announcement( playerid, "~r~Zakljucano", 5000, 6 );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 499.7608,772.2524,1001.4630 ) ) { // Rudnik
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR || PlayerInfo[ playerid ][ xHelper ] >= 1 || PlayerInfo[ playerid ][ xAdmin ] >= 1 )
		{
			SetPlayerVirtualWorld( playerid, 0 );
			SetPlayerInterior( playerid, 0 );
			Dimi_SetPlayerPos( playerid, 493.1782,788.5486,-22.1103 );
			SetCameraBehindPlayer( playerid );
		}
		else return announcement( playerid, "~r~Zakljucano", 5000, 6 );
	}
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1268.5072,-1543.9985,13.5690 ) )
	{ // Biro BG Ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 1 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1321.2214,-865.2743,1407.5430 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1321.2214,-865.2743,1407.5430 ) )
	{ // Biro BG izlaz

		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1268.5072,-1543.9985,13.5690 );
		SetCameraBehindPlayer( playerid );
	}
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1136.1217,-897.1509,43.3906 ) )
	{ // Javni WC BG Ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 1 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1131.7759,-891.5052,-48.9141 );
		SendInfoMessage(playerid,"Usli ste u javni wc komande: /mokri");
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1131.7759,-891.5052,-48.9141 ) )
	{ // Javni WC  BG izlaz
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1136.1217,-897.1509,43.3906 );
		SetCameraBehindPlayer( playerid );
	}
	////////////////////////////////////////////////////////////////////////////
	
	/*if( IsPlayerInRangeOfPoint( playerid, 2.0, 1143.3789,-1353.4247,12.8617 ) )
	{ // Tempo ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 1 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 86.5936, 1942.5052, -46.4106 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 86.5936, 1942.5052, -46.4106 ) )
	{ // Tempo izlaz
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1143.3789,-1353.4247,12.8617 );
		SetCameraBehindPlayer( playerid );
	}*/
	////////////////////////////////////////////////////////////////////////////
	
	if( IsPlayerInRangeOfPoint( playerid, 2.0, banka_ulaz_x,banka_ulaz_y,banka_ulaz_z ) )
	{ // Komercijalna ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		//
		SetPlayerTime(playerid, 13, 0);
		SetPlayerWeather(playerid, 1);
		//
		SetPlayerInterior( playerid, 1 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1467.0833,-1012.5338,2058.0039 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1467.0833,-1012.5338,2058.0039 ) )
	{ // Komercijalna izlaz
		SetPlayerVirtualWorld( playerid, 0 );
		//
		SetPlayerTime(playerid, GlobalniSat,0);
		SetPlayerWeather(playerid, GlobalnoVrijeme);
		//
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, banka_ulaz_x,banka_ulaz_y,banka_ulaz_z );
		SetCameraBehindPlayer( playerid );
	}
	////////////////////////////////////////////////////////////////////////////
	
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1231.7878,-1428.6324,13.6951 ) )
	{ // Zlatara Pandora BG Ulaz
		SetPlayerVirtualWorld( playerid, 3 );
		SetPlayerInterior( playerid, 1 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 916.3696,-994.4591,-48.9141 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 916.3696,-994.4591,-48.9141 ) )
	{ // Zlatara Pandora  BG izlaz
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1231.7878,-1428.6324,13.6951 );
		SetCameraBehindPlayer( playerid );
	}
	
	
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1481.0422,-1771.4331,18.7958 ) )
	{ // opstina BG Ulaz
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 3 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 390.0416, 173.7430, 1008.4553 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 390.0416, 173.7430, 1008.4553 ) )
	{ // opstina BG izlaz
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1481.0422,-1771.4331,18.7958 );
		SetCameraBehindPlayer( playerid );
	}
	////////////////////////////////////////////////////////////////////////////
	/*if( IsPlayerInRangeOfPoint( playerid, 2.0, 2034.0833, -1401.7124, 17.3742 ) )
	{ // bolnica BG Ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 3 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 1137.32629, -1330.96631, 804.60999 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1137.32629, -1330.96631, 804.60999) )
	{ // bolnica BG izlaz

		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 2034.0833, -1401.7124, 17.3742 );
		SetCameraBehindPlayer( playerid );
	}*/
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 2052.4143,-1897.3738,13.5585 ) )
	{ // Auto skola BG Ulaz
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 3 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 2921.6353, -2053.1565, 1002.3162 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 2921.6353, -2053.1565, 1002.3162) )
	{ // Auto skola BG izlaz
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 2052.4143,-1897.3738,13.5585 );
		SetCameraBehindPlayer( playerid );
	}
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 2052.4531,-1886.4448,13.5585 ) )
	{ // Auto skola BG Ulaz 2
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 3 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 2903.3679,-2052.8181,1002.2381 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 2903.3679,-2052.8181,1002.2381) )
	{ // Auto skola BG izlaz 2
		FadeFromBlack(playerid);
		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 2052.4531,-1886.4448,13.5585 );
		SetCameraBehindPlayer( playerid );
	}
	//
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 252.7960,125.2640,1021.4188 ) )
	{
		if( GetFactionType( playerid ) == ORG_TIP_PD || PlayerInfo[ playerid ][ xAdmin ] > 0)
		{
			// U MUPU DA IDE NA KROV I PARKING
			ShowPlayerDialog(playerid,dialog_IZLAZIIZPD,DSL,"Odaberite izlaz","Krov izlaz 1\nKrov izlaz 2\nParking","Uredu","Izlaz");
			
		}

	}
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1565.2023,-1665.9219,28.3956 ) || IsPlayerInRangeOfPoint( playerid, 2.0,1564.4135,-1685.2876,28.3956))
	{
		if( GetFactionType( playerid ) == ORG_TIP_PD || PlayerInfo[ playerid ][ xAdmin ] > 0)
		{
			// Ulaz u MUP sa krov1 i krov 2
			SetPlayerVirtualWorld( playerid, 1 );
			SetPlayerInterior( playerid, 1 );
			TogglePlayerControllable( playerid, false );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			Dimi_SetPlayerPos( playerid, 252.7960,125.2640,1021.4188 );
			SetCameraBehindPlayer( playerid );
		}
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 1568.7417,-1690.5629,5.8906 ))
	{
		if( GetFactionType( playerid ) == ORG_TIP_PD || PlayerInfo[ playerid ][ xAdmin ] > 0)
		{
			// Ulaz u MUP sa parkinga
			SetPlayerVirtualWorld( playerid, 1 );
			SetPlayerInterior( playerid, 1 );
			TogglePlayerControllable( playerid, false );
			SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			Dimi_SetPlayerPos( playerid, 252.7960,125.2640,1021.4188 );
			SetCameraBehindPlayer( playerid );
		}
	}
	
	
	////////////////////////////////////////////////////////////////////////////
	if( IsPlayerInRangeOfPoint( playerid, 2.0, 938.22638, -1720.29016, 13.62720 ) )
	{ // Apoteka BG Ulaz
		SetPlayerVirtualWorld( playerid, 1 );
		SetPlayerInterior( playerid, 3 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, -429.7872, -1729.6360, 2244.4395 );
		SetCameraBehindPlayer( playerid );
	}
	if( IsPlayerInRangeOfPoint( playerid, 2.0, -429.7872, -1729.6360, 2244.4395) )
	{ // Apoteka BG izlaz

		SetPlayerVirtualWorld( playerid, 0 );
		SetPlayerInterior( playerid, 0 );
		TogglePlayerControllable( playerid, false );
		SetTimerEx("SlobodnoSada", 3000, false, "i", playerid );
		ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
		Dimi_SetPlayerPos( playerid, 938.22638, -1720.29016, 13.62720 );
		SetCameraBehindPlayer( playerid );
	}
	
	////////////////////////////////////////////////////////////////////////////
	
	if( IsPlayerInRangeOfPoint( playerid, 1.5, 1462.6173, -1005.6067, 57.5132 ) )
	{ // tajni ulaz PD/SAJ/CIA

		if( GetFactionType( playerid ) == ORG_TIP_PD )
		 {

			SetCameraBehindPlayer( playerid );
			SetTimerEx("SlobodnoSada", 1000, false, "i", playerid);
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 1 );
			SetPlayerVirtualWorld( playerid, 1 );
			Dimi_SetPlayerPos( playerid, 1477.275268, -1013.916320, 2045.536743 );
		}
	}
	//ShowLoadingTextdraws(playerid, true);
	return true;
}
//------------------------------------------------------------------------------
public split(const strsrc[], strdest[][], delimiter)
{
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc)){
		if(strsrc[ i ]==delimiter || i==strlen(strsrc)){
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i+1;
			aNum++;
		}
		i++;
	}
	return 1;
}
//------------------------------------------------------------------------------
public ImmobCountForPlayer( playerid )
{
	if(GetPVarInt( playerid, "immobsecounds"))
	{
		new immobstring[ 34 ];
		format( immobstring,sizeof( immobstring ),"~w~Preostalo sekundi: ~g~%d", GetPVarInt(playerid, "immobsecounds")-1);
		announcement( playerid, immobstring, 1100, 4 );
		PlayerPlaySound( playerid, 1056, 0.0, 0.0, 0.0 );

		PovecajPVarInt(playerid, "immobsecounds", -1);

		if(!GetPVarInt(playerid, "immobsecounds"))
		{
			Dimi_KillTimer(GetPVarInt(playerid, "immobcounttimer"));
		}
	}
}

public BreakLockCountForPlayer( playerid )
{
	new Float:X, Float:Y, Float:Z;
	GetVehiclePos( GetPVarInt( playerid, "BreakingVehicle"), X, Y, Z );
	if(!IsPlayerInRangeOfPoint( playerid, 3.0, X, Y, Z ) )
	{
		TogglePlayerControllable( playerid, 1 );

		Dimi_KillTimer( GetPVarInt( playerid, "BreakLockTimer" ) );
		Dimi_KillTimer( GetPVarInt( playerid, "breakcounttimer" ) );
		SetPVarInt( playerid, "BreakLockTimerCalled", 0 );
		SetPVarInt( playerid, "BreakingLock", 0 );

		GRESKA( playerid, "Vozilo u koje pokusavate provaliti nije blizu vas." );
	}
	if(GetPVarInt(playerid, "breaksecounds"))
	{
		new breakstring[ 34 ];
		format( breakstring,sizeof( breakstring ),"~w~Preostalo sekundi: ~g~%d", GetPVarInt( playerid, "breaksecounds" )-1 );
		announcement( playerid, breakstring, 1100, 4 );
		PlayerPlaySound( playerid, 1056, 0.0, 0.0, 0.0 );

		PovecajPVarInt( playerid, "breaksecounds", -1 );

		if(!GetPVarInt( playerid, "breaksecounds" ) )
		{
			Dimi_KillTimer( GetPVarInt( playerid, "breakcounttimer" ) );
		}
	}
}
public VehicleBreakLock( playerid, vehicleid, autoid ) {
	if( IsPlayerConnected( playerid ) )
	{
		SetPVarInt( playerid, "BreakingLock", 0 );
		announcement( playerid, "~w~Vozilo ~g~otkljucano", 5000, 6 );
		PlayerPlaySound( playerid, 1145, 0.0, 0.0, 0.0);
		VehicleInfo[ autoid ][ vLocked ] = 0;
		TogglePlayerControllable( playerid, true );
		UnLockCar( vehicleid );
	}
}
//------------------------------------------------------------------------------
public TrashLimitOff( playerid ) {
	if( GetNearestContainer( playerid ) == -1 ) return GRESKA( playerid, "Otisao si od kontejnera i nisi nasao nista." );
	new rands = random( 4 )+1;
	switch( rands ) {
		case 1: {
			if( Maskuse[ playerid ] == true )
				format( globalstring, sizeof( globalstring ), "** Alat za obijanje je nadjen u kontejneru (( Maska_%d ))", PlayerInfo[ playerid ][ xMaskID ] );
			else
				format( globalstring, sizeof( globalstring ), "** Alat za obijanje je nadjen u kontejneru (( %s ))", ImeIgraca( playerid ) );
			PlayerInfo[ playerid ][ xToolkit ] = true;
		}
		case 2: {
			if( Maskuse[ playerid ] == true )
				format( globalstring, sizeof( globalstring ), "** Upaljac je nadjen u kontejneru (( Maska_%d ))", PlayerInfo[ playerid ][ xMaskID ] );
			else
				format( globalstring, sizeof( globalstring ), "** Upaljac je nadjen u kontejneru (( %s ))", ImeIgraca( playerid ) );
			PlayerInfo[ playerid ][ xUpaljac ] = 1;
		}
		case 3: {
			if( Maskuse[ playerid ] == true )
				format( globalstring, sizeof( globalstring ), "** Spric sa iglom je nadjen u kontejneru (( Maska_%d ))", PlayerInfo[ playerid ][ xMaskID ] );
			else
				format( globalstring, sizeof( globalstring ), "** Spric sa iglom je nadjen u kontejneru (( %s ))", ImeIgraca( playerid ) );
			PlayerInfo[ playerid ][ xInekcija ] = true;
		}
		case 4: {
			if( Maskuse[ playerid ] == true )
				format( globalstring, sizeof( globalstring ), "** Uze je nadjeno u kontejneru (( Maska_%d ))", PlayerInfo[ playerid ][ xMaskID ] );
			else
				format( globalstring, sizeof( globalstring ), "** Uze je nadjeno u kontejneru (( %s ))", ImeIgraca( playerid ) );
			Uze[ playerid ] = true;
		}
		case 5: {
			if( Maskuse[ playerid ] == true )
				format( globalstring, sizeof( globalstring ), "** Sat je nadjen u kontejneru (( Maska_%d ))", PlayerInfo[ playerid ][ xMaskID ] );
			else
				format( globalstring, sizeof( globalstring ), "** Sat je nadjen u kontejneru (( %s ))", ImeIgraca( playerid ) );
			PlayerInfo[ playerid ][ xSat ] = 19039;
		}
	}
	PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
	TrashSearch[ playerid ] = 0;
	VremeTDControl( playerid, false );
	ClearAnimations( playerid );
	TogglePlayerControllable( playerid, true );
	return 1;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

public OnVehicleDamageStatusUpdate( vehicleid, playerid ) 
{
	static fc_tires, fc_lights;
	GetVehicleDamageStatus( vehicleid, fc_lights, fc_tires, fc_lights, fc_tires );
	if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
		if( fc_lights || fc_tires )
			return 1;

		new time = GetTickCount( );
		switch( time - antiCheatCS[ playerid ][ CPSTick ] ) {
			case 0 .. 500: {
				antiCheatCS[ playerid ][ CPSCount ] ++;
				if( antiCheatCS[ playerid ][ CPSCount ] >= 10 ) {
					format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Cleo Particle Spam", ImeIgraca( playerid ) );
					AdminPoruka( SVETLOCRVENA, globalstring );
					Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Cleo Particle Spam");
					return 1;
				}
			}
			default: antiCheatCS[ playerid ][ CPSCount ] = 0;
		}
		antiCheatCS[ playerid ][ CPSTick ] = time;
	}
	return 1;
}

//------------------------------------------------------------------------------
public UpdatePlayerGps(playerid, fresh) {
	new bool:arrived = false;
	if( IsPlayerInRangeOfPoint( playerid, 20.0, PlayerGpsRadar[ playerid ][_pgrPos][ 0 ], PlayerGpsRadar[ playerid ][_pgrPos][ 1 ], PlayerGpsRadar[ playerid ][_pgrPos][2 ] ) ) {
		arrived = true;
		if( IsValidDynamicMapIcon(PlayerGpsRadar[ playerid ][_pgrIconId ] ) ) {
			DestroyDynamicMapIcon(PlayerGpsRadar[ playerid ][_pgrIconId] );
		}
		
		PlayerGpsRadar[ playerid ][_pgrIconId] = -1;
	}

	if(!arrived) {
		if(PlayerInfo[ playerid ][ xGpsLevel ] >= 2) {
			new Float:x1, Float:y1, Float:z1;
			GetPlayerPos(playerid, x1, y1, z1);

			new Float:x2 = PlayerGpsRadar[ playerid ][_pgrPos][ 0 ];
			new Float:y2 = PlayerGpsRadar[ playerid ][_pgrPos][ 1 ];
			new Float:z2 = PlayerGpsRadar[ playerid ][_pgrPos][ 2 ];

			new distanceString[64], Float:distance = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
			new zonen[32];

			GetZoneName(x2, y2, zonen, sizeof(zonen));
			format(distanceString, sizeof(distanceString), "Udaljenost: %.2f metara~n~%s", distance, zonen);
			PlayerTextDrawSetString(playerid, PlayerGpsRadarText[ playerid ], distanceString);

			if(fresh) {
				PlayerTextDrawShow( playerid, PlayerGpsRadarText[ playerid ] );
			}
		}
		if( PlayerInfo[ playerid ][ xGpsLevel ] >= 3 ) {
			if( IsPlayerInAnyVehicle( playerid ) ) {
			
				new Float:x2 = PlayerGpsRadar[ playerid ][_pgrPos][ 0 ];
				new Float:y2 = PlayerGpsRadar[ playerid ][_pgrPos][ 1 ];
				new Float:VPos[ 3 ], Float:Rotation;
				
				GetVehiclePos( GetPlayerVehicleID( playerid ), VPos[ 0 ], VPos[ 1 ], VPos[ 2 ] );
				Rotation = PointAngle( playerid, VPos[ 0 ], VPos[ 1 ], x2, y2 );
				AttachDynamicObjectToVehicle( PlayerGpsRadar[ playerid ][ _pgrObject ], GetPlayerVehicleID( playerid ), 0.0, 0.0, 1.5, 0.0, 90.0, Rotation );
			}
		}
		SetTimerEx("UpdatePlayerGps", 100, false, "dd", playerid, 0);
	} else {
		PlayerTextDrawHide(playerid, PlayerGpsRadarText[ playerid ] );
		DestroyDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] );
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
		PlayerGpsRadar[ playerid ][ _pgrIconId ] = -1;
		PlayerGpsRadar[ playerid ][ _pgrObject ] = -1;
	}
}

public GetPlayerBusinessId( playerid, type ) {
	for (new i = 1; i < MAX_BUSSINES; i++) {
		if( IsPlayerInRangeOfPoint( playerid, 50.0, BussinesInfo[ i ][ bExitX ], BussinesInfo[ i ][ bExitY ], BussinesInfo[ i ][ bExitZ ] ) && GetPlayerVirtualWorld( playerid ) == BussinesInfo[ i ][ bInVW ] )
		{
			if( BussinesInfo[ i ][ bType ] == type )
			{
				return i;
			}
		}
	}

	return -1;
}

//------------------------------------------------------------------------------
EventTimeR(); public EventTimeR()
{
	if( EventInfo[ eID ] != 0 )
	{
		EventInfo[ EventTime ]--;
		switch( EventInfo[ EventTime ] )
		{
			case 0: {
				for(new i; i < MAX_PLAYERS; i++)
				{
					if( PlayerCP[ i ] > 0 )
					{
						SetPlayerRaceCheckpoint( i, 0, CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ] ][ CPX ], CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ] ][ CPY ], CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ] ][ CPZ ], CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ]+1 ][ CPX ], CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ]+1 ][ CPY ], CheckPoint[ EventInfo[ eID ] ][ PlayerCP[ i ]+1 ][ CPZ ], 7.0 );
						TogglePlayerControllable( i, true );
						announcement( i ,"~y~KRENI!", 2000, 5 );
					}
				}
			}
			case 1:
			{
				for(new i; i < MAX_PLAYERS; i++)
				{
					if( PlayerCP[ i ] > 0 )
					{
						announcement( i ,"~y~1", 999, 5 );
					}
				}
			}
			case 2:
			{
				for(new i; i < MAX_PLAYERS; i++)
				{
					if( PlayerCP[ i ] > 0 )
					{
						announcement( i ,"~y~2", 999, 5 );
					}
				}
			}
			case 3:
			{
				for(new i; i < MAX_PLAYERS; i++)
				{
					if( PlayerCP[ i ] > 0 )
					{
						announcement( i ,"~y~3", 999, 5 );
					}
				}
			}
			case 8:
			{
				//format( globalstring, sizeof( globalstring ), ""col_balkanstory"%s | "col_white"Event pocinje za {A6A6A6}5 sekundi", Event[ EventInfo[ eID ] ][ Name ] );
				//SCMA( -1, globalstring );
			}
			case 13:
			{
				format( globalstring, sizeof( globalstring ), ""col_balkanstory"%s | "col_white"Imate {A6A6A6}10 "col_white"sekundi da se prijavite.", Event[ EventInfo[ eID ] ][ Name ] );
				SCMA( -1, globalstring );
			}
		}
	}
	
}
//------------------------------------------------------------------------------

forward TimerIzazov( playerid );
public TimerIzazov( playerid )
{
	if( TrkaIzazov[ playerid ] != 0 )
	{
		TrkaIzazov[ playerid ]--;
		switch( TrkaIzazov[ playerid ] )
		{
			case 0:
			{
				SetPlayerRaceCheckpoint( playerid, 0, -1431.3984, -129.8569, 1045.4110, -1456.4524, -282.5754, 1050.6942, 7.0 );
				TrkaCheckpoint[ playerid ] = 1;
				Dimi_KillTimer( IzazivanjeTimer[ playerid ] );
				TogglePlayerControllable( playerid, true );
				announcement( playerid ,"~y~MOZES KRENUTI - SAD!", 2000, 5 );
			}
			case 1:
			{
				announcement( playerid ,"~y~1", 999, 5 );
			}
			case 2:
			{
				announcement( playerid ,"~y~2", 999, 5 );
			}
			case 3:
			{
				announcement( playerid ,"~y~3", 999, 5 );
			}
		}
	}
}
//------------------------------------------------------------------------------
public Provera1( playerid, type )
{
	{
	new Float:pos[ 3 ];
	GetPlayerPos(playerid, pos[ 0 ], pos[ 1 ], pos[ 2 ] );
	Dimi_SetPlayerPos(playerid, pos[ 0 ], pos[ 1 ], pos[ 2 ] );
	}
	SetCameraBehindPlayer( playerid );
	TogglePlayerControllable( playerid, false );
	SetTimerEx( "Provera2", 3000, 0, "ii", playerid, type );
	return 1;
}
//============================================================================//
public Provera2( playerid, type )
{
	new Float:testpos[ 6 ];
	GetPlayerCameraPos( playerid, testpos[ 0 ], testpos[ 1 ], testpos[ 2 ] );
	GetPlayerPos( playerid, testpos[ 3 ], testpos[ 4 ], testpos[ 5 ] );
	TogglePlayerControllable( playerid, true );

	if( floatabs( testpos[ 2 ] - testpos[ 5 ] ) > 1.5 )
	{
		format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s {FFFFFF}je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Sobeit Hack!", ImeIgraca( playerid ) );
		

		
		SendClientMessageToAll( 0xFF6347AA, globalstring );
		Kickovanje( playerid, "Kickovan: SOBEIT" );
	}
	return 1;
}
//------------------------------------------------------------------------------
forward VehicleRentRespawn( vehicleid );
public VehicleRentRespawn( vehicleid )
{
		if( vehicleid != INVALID_VEHICLE_ID )
		{
			if( TipVozila[ vehicleid ] != RENTANO_VOZILO ) occupied[ vehicleid ] = true;
			if( Parked[ vehicleid ] != -1 ) occupied[ vehicleid ] = true;
			if( IsTrailerAttachedToVehicle( vehicleid ) ) occupied[ GetVehicleTrailer( vehicleid ) ] = true;
			if( !occupied[ vehicleid ] )
			{
				SetVehicleToRespawn( vehicleid );
			} else occupied[ vehicleid ] = false;
		}
		if( vehicleid+1 < MAX_VEHICLES ) SetTimerEx( "VehicleRentRespawn", 10, false, "d", vehicleid+1 );
		else ServerInfo[ RRVehicle ] = false, AdminPoruka( 0x86C6DBAA, "{FF0000}|| RESPAWN || {FFFFFF}Respawn praznih rentanih vozila je zavrsen!" );
		return 1;
}

forward VehicleOrgRespawn( vehicleid );
public VehicleOrgRespawn( vehicleid )
{
		if( vehicleid != INVALID_VEHICLE_ID )
		{
			if( TipVozila[ vehicleid ] != ORGANIZACIJSKO_VOZILO ) occupied[ vehicleid ] = true;
			if( Parked[ vehicleid ] != -1 ) occupied[ vehicleid ] = true;
			if( IsTrailerAttachedToVehicle( vehicleid ) ) occupied[ GetVehicleTrailer( vehicleid ) ] = true;
			if( !occupied[ vehicleid ] )
			{
				SetVehicleToRespawn( vehicleid );
			} else occupied[ vehicleid ] = false;
		}
		if( vehicleid+1 < MAX_VEHICLES ) SetTimerEx( "VehicleOrgRespawn", 10, false, "d", vehicleid+1 );
		else ServerInfo[ RRVehicle ] = false, AdminPoruka( 0x86C6DBAA, "{FF0000}|| RESPAWN || {FFFFFF}Respawn praznih organizacijskih vozila je zavrsen!" );
		return 1;
}

forward VehicleJobsRespawn( vehicleid );
public VehicleJobsRespawn( vehicleid )
{
		if( vehicleid != INVALID_VEHICLE_ID )
		{
			if( TipVozila[ vehicleid ] != POSLOVNO_VOZILO ) occupied[ vehicleid ] = true;
			if( Parked[ vehicleid ] != -1 ) occupied[ vehicleid ] = true;
			if( IsTrailerAttachedToVehicle( vehicleid ) ) occupied[ GetVehicleTrailer( vehicleid ) ] = true;
			if( !occupied[ vehicleid ] )
			{
				SetVehicleToRespawn( vehicleid );
			} else occupied[ vehicleid ] = false;
		}
		if( vehicleid+1 < MAX_VEHICLES ) SetTimerEx( "VehicleJobsRespawn", 10, false, "d", vehicleid+1 );
		else ServerInfo[ RRVehicle ] = false, AdminPoruka( 0x86C6DBAA, "{FF0000}|| RESPAWN || {FFFFFF}Respawn praznih poslovnih vozila je zavrsen!" );
		return 1;
}

forward VehiclePrivateRespawn( vehicleid );
public VehiclePrivateRespawn( vehicleid )//leonardo ug
{
		if( vehicleid != INVALID_VEHICLE_ID )
		{
			if( TipVozila[ vehicleid ] != PRIVATNO_VOZILO ) occupied[ vehicleid ] = true;
			if( Parked[ vehicleid ] != -1 ) occupied[ vehicleid ] = true;
			if( IsTrailerAttachedToVehicle( vehicleid ) ) occupied[ GetVehicleTrailer( vehicleid ) ] = true;
			if( !occupied[ vehicleid ] )
			{
				SetVehicleToRespawn( vehicleid );
			} else occupied[ vehicleid ] = false;
		}
		if( vehicleid+1 < MAX_VEHICLES ) SetTimerEx( "VehiclePrivateRespawn", 10, false, "d", vehicleid+1 );
		else ServerInfo[ RRVehicle ] = false, AdminPoruka( 0x86C6DBAA, "{FF0000}|| RESPAWN || {FFFFFF}Respawn praznih osobnih vozila je zavrsen!" );
		return 1;
}

forward RespawnCallGlobal( );
public RespawnCallGlobal( )
{
	for( new i = 0; i < MAX_PLAYERS; i++ )
	{
		if( IsPlayerConnected( i ) )
		{
			if( IsPlayerInAnyVehicle( i ) )
			{
				if( IsTrailerAttachedToVehicle( GetPlayerVehicleID( i ) ) ) occupied[ GetVehicleTrailer( GetPlayerVehicleID( i ) ) ] = true;
				if( !occupied[ GetPlayerVehicleID( i ) ] )
				{
					occupied[ GetPlayerVehicleID( i ) ] = true;
				}
				SetVehicleLabels(GetPlayerVehicleID( i ));
			}
		}
	}
	for(new i; i < MAX_PLAYERS; i++) {
		SendClientMessagee( i, 0x86C6DBAA, "[RESPAWN]: Server je automatski pokrenuo vracanje vozila u prvobitni polozaj!" ); }
	SetTimerEx( "VehicleRespawn", 10, false, "d", 0 );
	ServerInfo[ RRVehicle ] = true;
	AdminPoruka( 0x86C6DBAA, "[ADMIN-RESPAWN]: Server je pokrenuo respawn vozila..." );
	
	return 1;
}

forward RespawnCall( playerid, broj );
public RespawnCall( playerid, broj )
{
	switch( broj )
	{
		case 1:
		{
			for( new i = 0; i < MAX_PLAYERS; i++ )
			{
				if( IsPlayerConnected( i ) )
				{
					if( IsPlayerInAnyVehicle( i ) )
					{
						if( !occupied[ GetPlayerVehicleID( i ) ] )
							occupied[ GetPlayerVehicleID( i ) ] = true;
					}
				}
			}
			SetTimerEx( "VehiclePrivateRespawn", 10, false, "d", 0 );
			ServerInfo[ RRVehicle ] = true;
		}
		case 2:
		{
			for( new i = 0; i < MAX_PLAYERS; i++ )
			{
				if( IsPlayerConnected( i ) )
				{
					if( IsPlayerInAnyVehicle( i ) )
					{
						if( !occupied[ GetPlayerVehicleID( i ) ] )
							occupied[ GetPlayerVehicleID( i ) ] = true;
					}
				}
			}
			SetTimerEx( "VehicleJobsRespawn", 10, false, "d", 0 );
			ServerInfo[ RRVehicle ] = true;
		}
		case 3:
		{
			for( new i = 0; i < MAX_PLAYERS; i++ )
			{
				if( IsPlayerConnected( i ) )
				{
					if( IsPlayerInAnyVehicle( i ) )
					{
						if( !occupied[ GetPlayerVehicleID( i ) ] )
							occupied[ GetPlayerVehicleID( i ) ] = true;
					}
				}
			}
			
			SetTimerEx( "VehicleOrgRespawn", 10, false, "d", 0 );
			ServerInfo[ RRVehicle ] = true;
		}
		case 4:
		{
			for( new i = 0; i < MAX_PLAYERS; i++ )
			{
				if( IsPlayerConnected( i ) )
				{
					if( IsPlayerInAnyVehicle( i ) )
					{
						if( !occupied[ GetPlayerVehicleID( i ) ] )
							occupied[ GetPlayerVehicleID( i ) ] = true;
					}
				}
			}
			SetTimerEx( "VehicleRentRespawn", 10, false, "d", 0 );
			ServerInfo[ RRVehicle ] = true;
		}
		case 5:
		{
			for( new i = 0; i < MAX_PLAYERS; i++ )
			{
				if( IsPlayerConnected( i ) )
				{
					if( IsPlayerInAnyVehicle( i ) )
					{
						if( IsTrailerAttachedToVehicle( GetPlayerVehicleID( i ) ) ) occupied[ GetVehicleTrailer( GetPlayerVehicleID( i ) ) ] = true;
						if( !occupied[ GetPlayerVehicleID( i ) ] )
							occupied[ GetPlayerVehicleID( i ) ] = true;
					}
				}
			}
			SetTimerEx( "VehicleRespawn", 10, false, "d", 0 );
			ServerInfo[ RRVehicle ] = true;
		}
	}
	return 1;
}

forward VehicleRespawn( vehicleid );
public VehicleRespawn( vehicleid )
{
		if( vehicleid != INVALID_VEHICLE_ID )
		{
			if( Parked[ vehicleid ] != -1 ) occupied[ vehicleid ] = true;
			if( !occupied[ vehicleid ] )
			{
				SetVehicleToRespawn( vehicleid );
			} else occupied[ vehicleid ] = false;
		}
		if( vehicleid+1 < MAX_VEHICLES ) SetTimerEx( "VehicleRespawn", 10, false, "d", vehicleid+1 );
		else SetTimer( "VRRMSG", 210, false ), ServerInfo[ RRVehicle ] = false, AdminPoruka( 0x86C6DBAA, ""col_balkanstory"|| RESPAWN || {FFFFFF}ADMIN OBAVESTENJE: Vozila su sada respawnovana!" );
		//SetTimer( "VRRMSG", 210, false );
		return 1;
}
forward VRRMSG();
public VRRMSG() {
	SCMA(-1, ""col_balkanstory"[ RESPAWN VOZILA ]: {FFFFFF}Sva vozila na serveru su vracena u prvobitni polozaj!" );
	return 1;
}
//------------------------------------------------------------------------------
IsACabrio(model)
{
	if(	model == 424 || model == 429 || model == 430 || model == 439 || model == 446 ||
		model == 448 || model == 452 || model == 453 || model == 454 || model == 457 ||
		model == 461 || model == 462 || model == 463 || model == 468 || model == 471 ||
		model == 472 || model == 473 || model == 476 || model == 480 || model == 481 ||
		model == 484 || model == 485 || model == 486 || model == 493 || model == 500 ||
		model == 506 || model == 509 || model == 510 || model == 512 || model == 513 ||
		model == 521 || model == 522 || model == 523 || model == 530 || model == 531 ||
		model == 533 || model == 536 || model == 539 || model == 555 || model == 567 ||
		model == 568 || model == 571 || model == 572 || model == 575 || model == 581 ||
		model == 586 )
	{
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
stock RenamePlayer( staroime[], name[], playerid ) {

	new oldname[ 40 ], newname[ 40 ];
	new voziloid1 = PlayerInfo[ playerid ][ xVoziloID ][ 0 ];
	new voziloid2 = PlayerInfo[ playerid ][ xVoziloID ][ 1 ];
	new voziloid3 = PlayerInfo[ playerid ][ xVoziloID ][ 2 ];
	new voziloid4 = PlayerInfo[ playerid ][ xVoziloID ][ 3 ];
	new imovina1 = PlayerInfo[ playerid ][ xProperty ][ 0 ];
	new imovina2 = PlayerInfo[ playerid ][ xProperty ][ 1 ];
	new imovina3 = PlayerInfo[ playerid ][ xProperty ][ 2 ];
	new firma = PlayerInfo[ playerid ][ xFirmaID ];
	new hotel = PlayerInfo[ playerid ][ xHotelID ];
	new imanje = PlayerInfo[playerid][xFieldID];
	format( oldname, sizeof( oldname ), "Korisnici/%s.ini", staroime );
	format( newname, sizeof( newname ), "Korisnici/%s.ini", name );
	if( fexist( newname ) ) return GRESKA( playerid, "Novo ime vec postoji u bazi podataka!" );
	if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 && strcmp( ImeIgraca( playerid ), II[ imovina1 ][ iOwner ], true) == 0)
	{
		strmid( II[ imovina1 ][ iOwner ], name, 0, strlen( name ), 24 );
		PropertyRefresh( imovina1 ); SaveProperty( imovina1 );
	}
	if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 && strcmp( ImeIgraca( playerid ), II[ imovina2 ][ iOwner ], true) == 0)
	{
		strmid( II[ imovina2 ][ iOwner ], name, 0, strlen( name ), 24 );
		PropertyRefresh( imovina2 ); SaveProperty( imovina2 );
	}
	if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 && strcmp( ImeIgraca( playerid ), II[ imovina3 ][ iOwner ], true) == 0)
	{
		strmid( II[ imovina3 ][ iOwner ], name, 0, strlen( name ), 24 );
		PropertyRefresh( imovina3 ); SaveProperty( imovina3 );
	}
	if( PlayerInfo[ playerid ][ xFirmaID ] != -1 && strcmp( ImeIgraca( playerid ), BussinesInfo[ firma ][ bOwner ], true) == 0) {
		strmid( BussinesInfo[ firma ][ bOwner ], name, 0, strlen( name ), 24 );
		Bussines_Refresh( firma ); SaveBussines( firma );
	}
	if( PlayerInfo[ playerid ][ xHotelID ] != -1 && strcmp( ImeIgraca( playerid ), hotelInfo[ hotel ][ hOwner ], true) == 0) {
		strmid( hotelInfo[ hotel ][ hOwner ], name, 0, strlen( name ), 24 );
		HotelRefresh( hotel ); SaveHotel( hotel );
	}
	if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 && strcmp( ImeIgraca( playerid ), VehicleInfo[ voziloid1 ][ vOwner ], true) == 0)
	{
		strmid( VehicleInfo[ voziloid1 ][ vOwner ], name, 0, strlen( name ), 24 );
		SaveVehicle( voziloid1 );
	}
	if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 && strcmp( ImeIgraca( playerid ), VehicleInfo[ voziloid2 ][ vOwner ], true) == 0)
	{
		strmid( VehicleInfo[ voziloid2 ][ vOwner ], name, 0, strlen( name ), 24 );
		SaveVehicle( voziloid2 );
	}
	if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 && strcmp( ImeIgraca( playerid ), VehicleInfo[ voziloid3 ][ vOwner ], true) == 0)
	{
		strmid( VehicleInfo[ voziloid3 ][ vOwner ], name, 0, strlen( name ), 24 );
		SaveVehicle( voziloid3 );
	}
	if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 && strcmp( ImeIgraca( playerid ), VehicleInfo[ voziloid4 ][ vOwner ], true) == 0)
	{
		strmid( VehicleInfo[ voziloid4 ][ vOwner ], name, 0, strlen( name ), 24 );
		SaveVehicle( voziloid4 );
	}
	if(PlayerInfo[playerid][xFieldID] != -1 && strcmp( ImeIgraca( playerid ), fieldInfo[ imanje ][ fieldOwner ], true) == 0)
	{
		strmid( fieldInfo[ imanje ][ fieldOwner ], name, 0, strlen( name ), 24 );
		Field_Save( imanje ); Field_Refresh( imanje );
	}
	if( fexist( Inventory( playerid ) ) ) {
		
		new oldinv[ 40 ], newinv[ 40 ];
		format( oldinv, sizeof( oldinv ), "Inventory/%s.ini", staroime );
		format( newinv, sizeof( newinv ), "Inventory/%s.ini", name );
		frename( oldinv, newinv );
	}
	
	frename( oldname, newname ); SetPlayerName( playerid, name );
	SendInfoMessage( playerid, "Baza podataka uspjesno modifikovana!" );
	return 1;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
public RolePlayTut( playerid, learnid )
{
	if( IsPlayerConnected( playerid ) )
	{
		if(learnid == 1)
		{
			SetPlayerCameraPos( playerid, 1414.1941,-965.3426,58.9375 );
			SetPlayerCameraLookAt( playerid, 1420.8086,-810.6372,75.3894 );
			SetPlayerInterior( playerid, 0 );
			SetPlayerVirtualWorld( playerid, 0 );
			Dimi_SetPlayerPos( playerid, 1415.2184, -970.2783, 46.9375 );
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Pocetak TUTORIJALA? ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Niste savladali pravila naseg servera." );
			SendClientMessagee( playerid, BELA, "Slijedi tutorijal o vaznim pravilima Nova Era servera." );
			SendClientMessagee( playerid, BELA, "Nakon toga kviz znanja da se provjeri koliko ste naucili." );
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 2);
		}
		else if(learnid == 2)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Metagaming [MG] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Metagaming je koristenje OOC informacija u IC korist. ");
			SendClientMessagee( playerid, BELA, "Postoji vise vrsta Metagaminga, prvi je Nick MG ako primjerice na glas govorite necije ime u IC chatu, ");
			SendClientMessagee( playerid, BELA, "ali da ga jos uvijek niste upoznali IC, to jest njegovo ime niste saznali IC ili RP nacinom, ");
			SendClientMessagee( playerid, BELA, "vec ste samo vidjeli ime iznad njegove glave. Druga vrsta Metagaming je Forum MG, ");
			SendClientMessagee( playerid, BELA, "ukoliko neke informacije saznate preko foruma i OOC dijela i dodjete u igru i koristite ih u svoju svrhu ");
			SendClientMessagee( playerid, BELA, "a da to niste IC ili na RP nacin saznali. Kao primer racije na neku bandu/mafiju. ");
			SendClientMessagee( playerid, BELA, "Treci primjer je Skin MG ukoliko neki clan nosi skin nekog clana bande i sada primjerice policajac ide njega ");
			SendClientMessagee( playerid, BELA, "pretresati i sve to zbog toga sto je on vidio da je on clan neke bande i slicno.");
			SendClientMessagee( playerid, BELA, "Cetvri primjer je Chat MG, primjerice kada pisete u IC chat lol, xD, wtf, omg, roll, :D, :) i slicno, ");
			SendClientMessagee( playerid, BELA, "jer se smajlici i skracenice ne koriste u IC chatu. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 40000, 0, "ii", playerid, 3);
		}
		else if(learnid == 3)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Powergaming [PG] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Powergaming je kada prisile nekoga ili sebe na radnju koju je nemoguce izvesti u stvarnom zivotu u bilo kojem trenutku. ");
			SendClientMessagee( playerid, BELA, "Primjeri za ovo Pravilo su skakanje sa nekakvih zgrada bez ozlijeda, znaci skocite i nastavite hodat ili trcat bez da vam se ista dogodilo. ");
			SendClientMessagee( playerid, BELA, "Drugi primjer je izbjegavanje i bjezanje od metaka, jer znate i sami da je jako tesko izbjeci metak koji vas pogodi i da je uopse tesko ");
			SendClientMessagee( playerid, BELA, "preziviti ako vas pogodi vice metaka a da pri tome nemate pancirku na sebi. Treci primjer je kada netko uperi neko oruzije u vas i sad vi ");
			SendClientMessagee( playerid, BELA, "ne znate sta cete i vi vadite svoje oruzije nabrzinu i pucate na njega, to je strogo zabranjeno i kaznjivo pravilo");
			SendClientMessagee( playerid, BELA, "i molim vas da ga se pridrzavate.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 30000, 0, "ii", playerid, 4 );
		}
		else if(learnid == 4)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Deathmatch [DM] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Ubijanje ljudi bez ikakvog IC i RP razloga. ");
			SendClientMessagee( playerid, BELA, "Ima dosta primjera za ovo Pravilo, navest cu vam par koji se vrlo cesto krse i na koje bi trebali pripaziti. ");
			SendClientMessagee( playerid, BELA, "Prvi primjer je pucanje na javnim mjestima, pod javna mjesta spadaju Burger Shot, Pizza Stack, Banka, Vijecnica, Casino i slicno. ");
			SendClientMessagee( playerid, BELA, "Znaci kod svih tih mjesta postoje ili nekakvi strazari, kamere ili nesto sto bi vas dovesti u opasnost i gdje bi vas mogli prijaviti ");
			SendClientMessagee( playerid, BELA, "ili uhvatiti. Drugi primjer je kada pucate po svemu sto god vidite bez ikakvog razloga i strogo ce se kaznjavat ovo krsenje Pravila. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 30000, 0, "ii", playerid, 5);
		}
		else if(learnid == 5)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Roleplay 2 Win [RP2WIN] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Ovo pravilo znaci RPanje nekakve situacije u svoju korist bez pruzanja prilike drugim igracima da se pokusaju izvuci iz te situacije.");
			SendClientMessagee( playerid, BELA, "Dobar primjer je ukoliko vas PD/FBI uhvati i pretrese Vas i pronadju 2 grama kokain i Vi napisete da se to nenalazi kod Vas vec ste to");
			SendClientMessagee( playerid, BELA, "ostavili u kuci je cist primjer RP 2 Win-a. Sve sto se skriptom nalazi kod Vas onda je kod Vas i IC.");
			SendClientMessagee( playerid, BELA, "Zabranjena je zloupotreba ovog Pravila i strogo ce se kaznjavat krsenje ovog Pravila.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 30000, 0, "ii", playerid, 6);
		}
		else if(learnid == 6)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Drive By [DB] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Pucanje iz vozila(Automobil,motor,zrakoplov,plovilo) sa mjesta vozaca na pjesake, motoriste i bicikliste. ");
			SendClientMessagee( playerid, BELA, "Takodjer u ovo Pravilo i spada ubijanje ljudi sa elisom od helikoptera, te se odnosi na vozace uglavnom. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 15000, 0, "ii", playerid, 7);
		}
		else if(learnid == 7)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Bunny Hopp [BH] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Skakanje jednom, dva puta ili vise puta prilikom trcanja sa ciljem brzeg trcanja ili izbjegavanja nekakvih situacija. ");
			SendClientMessagee( playerid, BELA, "Bunny Hopping je strogo zabranjen i bilo bi prikladno da hodat/trcite kao i u pravome zivotu, to jest hodati drzeci ");
			SendClientMessagee( playerid, BELA, "tipku ALT ili upisivanjem neke od komandi za hodanje(/gwalk, /walk). ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 15000, 0, "ii", playerid, 8);
		}
		else if(learnid == 8)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Revenge Kill [RK] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Kao sto i samo ime pojma govori, ovo Pravilo je ubojstvo iz osvete. ");
			SendClientMessagee( playerid, BELA, "Ubijanje iz osvete je strogo zabranjeno iz razloga sto ukoliko netko ubije vas vi ne znate nista o toj osobi kada se ponovno respawnate i ");
			SendClientMessagee( playerid, BELA, "nemate se pravo pribliziti njemu ili tom naselju ukoliko se on nalazi u nekakvoj bandi kada je on tamo. ");
			SendClientMessagee( playerid, BELA, "Ukoliko se ponovno preko IC i RP nacina upoznate, tj. preko drugih ljudi koji su vas povezali onda ponovno saznajte informacije o njemu. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 9);
		}
		else if(learnid == 9)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Non-Roleplay [NonRP] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Ometanje RP radnji koje izvrsavaju drugi igraci smatra se krsenjem ovog pravila, primjeri ovog pravila su naprimjer ukoliko igrac");
			SendClientMessagee( playerid, BELA, "nesto Roleplaya i vi dodjete do njega i pisete mu u OOC chat i ometate njegov Roleplay, takodjer u ovo Pravilo spada i parkiranje vozila ");
			SendClientMessagee( playerid, BELA, "na sred ceste, zabijanje u svaku drugu banderu, voznja u ostecenom i skrsenom vozilu i ostalo krsenje pravila primjera PGa, DMa ili RKa. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 10);
		}
		else if(learnid == 10)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Spamming [SPAM] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Pisanje iste rijeci ili recenice dva ili vise puta za redom. ");
			SendClientMessagee( playerid, BELA, "Znaci ukoliko ponovite isti tekst 2 ili vise puta smatrat ce se spamanjem. ");
			SendClientMessagee( playerid, BELA, "Jedino opravdanje vaseg spamanja moze biti lagg ili nesto slicno. ");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 15000, 0, "ii", playerid, 11);
		}
		else if(learnid == 11)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Hacking & Exploiting [Hack & Abuse] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Zabranjeno je koristenje bilo kakvih programa kojim se dobiva odredjena prednost u igri, u to takodjer spadaju sve vrste cheatova.");
			SendClientMessagee( playerid, BELA, "Jedini dopusteni programi su: programi za pricanje s ostalim igracima ili video/glasovni poziv( Ventrilo, xFire, MSN, TeamSpeak, Skype).");
			SendClientMessagee( playerid, BELA, "Takodjer su dozvoljeni modovi koji ne mijenjaju fizicku osnovu igre i Keybindsi.");
			SendClientMessagee( playerid, BELA, "Zabranjuje se koristenje bilo kakvih poznatih/nepoznatih bugova/propusta u igri ili skripti koje ce vam donjeti prednost nad ostalim igracima.");
			SendClientMessagee( playerid, BELA, "U to se ubraja i spawnanje novca, iskoristavanje bugova ili uzimanje CJ skina da biste brze trcali i ostale stvari.");
			SendClientMessagee( playerid, BELA, "Kazne za krsenje ovih Server Pravila bit ce dozivotni ban bez prava na unban svima koji su pokusali na bilo koji nacin hackati ili abuseati.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 40000, 0, "ii", playerid, 12);
		}
		else if(learnid == 12)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Iskoristavanje Admin & GM pozicije [Admin/GM Abuse] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Koristenje Admin/GM pozicije za prijetnje ili za korist sebi, a na stetu drugima igracima je strogo zabranjeno i nece se tolerisati.");
			SendClientMessagee( playerid, BELA, "Admin i Game Masteri su dobro upoznati sa ovim pravilom i znaju sve posljedice koje se ticu ovog Pravila.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 13);
		}
		else if(learnid == 13)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Terrorist RP [Terror RP] ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Zabranjeno je RPati terorista, jer sa time samo poticete Deathmatching i bez razloga ubijate ljude na serveru.");
			SendClientMessagee( playerid, BELA, "Za to postoje drugi Deathmatching serveri pa se tamo odite ubijat sve sto se krece i pucat po svemu.");
			SendClientMessagee( playerid, BELA, "Kazna za krsenje ovog Server Pravila bit ce dozivotni ban bez prava na unban.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 14);
		}
		else if(learnid == 14)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Ingame pljacke i prijevare ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Maksimalne dozvoljene pljacke nad drugim igracima su do 20.000$, ne vise od toga i naravno to sve mora biti lijepo IC");
			SendClientMessagee( playerid, BELA, "i Roleplay opljackano, a ukoliko se tu radi o Roleplay prijevari maksimalno dozvoljena kradja je 50.000$.");
			SendClientMessagee( playerid, BELA, "Strogo je zabranjeno je pljackanje i varanje igraca koji su 1, 2 ili 3 level, sve ostale levele iznad je dozvoljeno");
			SendClientMessagee( playerid, BELA, "pljackati i varati do gore napisanih cifri.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 20000, 0, "ii", playerid, 15);
		}
		else if(learnid == 15)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Komande /me, /do ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Komanda /me sluzi kako bismo iskazali neku vlastitu radnju koju ne mozemo pokazati likom jer nemamo posebnu animaciju za to ili tipku kojom ");
			SendClientMessagee( playerid, BELA, "bi se posluzili. Nije potrebno koristiti /me komandu ukoliko imate odredjene animacije(/animacije) sa kojima bi mogli opisati neku situaciju.");
			SendClientMessagee( playerid, BELA, "Takodjer pazite da neradite Powergaming sa ovom komandom tako  da morate pruziti i drugima sansu na Roleplay,");
			SendClientMessagee( playerid, BELA, "a ne misliti samo na sebe i gledati kako cete izaci kao pobjednik.");
			SendClientMessagee( playerid, BELA, "Komanda /do sluzi za opis nekakve situacije koju ne mozemo znati.");
			SendClientMessagee( playerid, BELA, "Pomocu /do komande opisujemo situacije koje se ticu opisa charactera, situacije topa njuha i slicnih stvari koje spadaju u /do chat.");
			SendClientMessagee( playerid, BELA, "Sluzi iskljucivo za opis necega sto ne mozemo predociti bez dodatnog opisa.");
			SendClientMessagee( playerid, BELA, "Zabranjneno je pisanje onoga na primjer: /me udara Ime_Prezime u glavu.- /do Padas? i slicno, znaci takve situacije se nece tolerirati ");
			SendClientMessagee( playerid, BELA, "i bit ce kaznjive po Pravilniku.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 40000, 0, "ii", playerid, 16);
		}
		else if(learnid == 16)
		{
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendClientMessagee( playerid, 0xAFAFAFAA," ");
			SendInfoMessage( playerid, "~ Komande /ame, /attempt ~");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Komanda /ame sluzi za opisivanje vlastitog lika(charactera) i to je tekst koji pise iznad vase glave.");
			SendClientMessagee( playerid, BELA, "Preko ove komande mozete docarati opis i osobine svog lika kojeg RPate tako da napisete svoj izgled, visinu, dob, debljinu i slicne ");
			SendClientMessagee( playerid, BELA, "stvari ali morate paziti da taj opis odgovara skinu kojeg nosite u igri. Ukoliko se koristite skin MODovima koristite /do komandu za bolji");
			SendClientMessagee( playerid, BELA, "i detaljniji opis vaseg charactera.");
			SendClientMessagee( playerid, BELA, " ");
			SendClientMessagee( playerid, BELA, "Komanda /attempt sluzi kako bi pokusali iskazati neku radnju u kojoj imate 50 posto sanse da uspete i 50 posto sanse da ne uspete.");
			SendClientMessagee( playerid, BELA, "Ova komanda se koristi kao pomoc /me i /do komandi i zabranjeno ju je koristiti nad ljudima i u nekakve Powergaming svrhe.");
			SendClientMessagee( playerid, BELA, "Takodjer dozvoljeno je ovu komandu koristiti samo za svoje potrebe, u prijevodu smijete ju koristiti samo na sebi.");
			TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 40000, 0, "ii", playerid, 17);
		}
		else if( learnid == 17 ) {
			PitanjeBroj[ playerid ] = 1;
			TacanOdgovor[ playerid ] = 0;
			ShowPlayerDialog( playerid, dialog_RPTEST, DSL, "1. Sto je Metagaming [MG] ? ", "A) Koristenje OOC informacija u IC korist.\nB) Radnja koju je nemoguce izvesti u stvarnom zivotu u bilo kojem trenutku.\nC) Skakanje jednom ili vise puta tokom trcanja sa ciljem brzeg trcanja.\nD) Pisanje iste rijeci ili recenice dva ili vise puta za redom.", D_ODABERI, D_ODUSTANI );
			TimerPitanje[ playerid ] = SetTimerEx( "Pitanje", 120000, 0, "i", playerid);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public ClearKnock( playerid )
{
	TogglePlayerControllable( playerid, true );
	ClearAnimations( playerid );
	KnockedDown[ playerid ] = false;
}
//------------------------------------------------------------------------------
public ClearPlayerRob( playerid )
{
	IgracOpljackan[ playerid ] = false;
}
//------------------------------------------------------------------------------
public Taxitimer( playerid )
{
	new stringB[5],string[64];
	if( IsPlayerInAnyVehicle( playerid ) )
	{
		if( VoziIgracaID[ playerid ] != INVALID_PLAYER_ID && GetPlayerVehicleID( playerid ) == GetPlayerVehicleID( VoziIgracaID[ playerid ] ) )
		{
			if( GetSpeed( playerid ) > 5  )
			{
				if( PlayerInfo[ VoziIgracaID[ playerid ] ][ xNovac ] >= CenaVoznje[ playerid ] )
				{
					CenaVoznje[ playerid ] += 10;
					format( string, sizeof( string ), "%s", GetPlayerLocation( VoziIgracaID[ playerid ] ) );
					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 7 ], string );
					
					format( string, sizeof( string ), "%s", GetPlayerLocation( VoziIgracaID[ playerid ] ) );
					PlayerTextDrawSetString( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 7 ], string );
					/////////////////////////////////////////////////////////////////////////////////////////////////////////
					format( stringB, sizeof( stringB ), "%d$", CenaVoznje[ playerid ] );
					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 5 ], stringB);
					
					format( stringB, sizeof( stringB ), "%d$", CenaVoznje[ playerid ] );
					PlayerTextDrawSetString( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 5 ], stringB );
				}
				else
				{
					TaximetarUkljucen[ playerid ] = false;

					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 0 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 1 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 2 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 3 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 4 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 5 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 6 ] );
					PlayerTextDrawHide( VoziIgracaID[ playerid ], TaxistaTD[ VoziIgracaID[ playerid ] ][ 7 ] );

					DajIgracuNovac( VoziIgracaID[ playerid ], -CenaVoznje[ playerid ] );
					DajIgracuNovac( playerid, CenaVoznje[ playerid ] );

					SendClientMessageEx( VoziIgracaID[ playerid ], ZUTA, "Zavrsili ste voznju jer nemate dovoljno novca. Naplaceno vam je %d.", CenaVoznje[ playerid ] );
					SendClientMessageEx( playerid, ZUTA, "Klijent nema dovoljno novca te je izasao i naplatili ste mu %d$ za voznju", CenaVoznje[ playerid ] );

					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 7 ], "N/A" );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 7 ] );
					
					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 5 ], "N/A" );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 5 ] );

					Dimi_RemovePlayerFromVehicle( VoziIgracaID[ playerid ] );
					CenaVoznje[ playerid ] = 0;
					Dimi_KillTimer( TaxiTimer[ playerid ] );
					offeredByCabbie[ VoziIgracaID[ playerid ] ] = INVALID_PLAYER_ID;
					VoziIgracaID[ playerid ] = INVALID_PLAYER_ID;
				}
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public PocetniTut( playerid, izbor ) 
{
	if( izbor == 1 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Konfiguracija postavki zapoceta!");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1252.5060, -1512.7377, 9.2656 );
		InterpolateCameraPos(playerid, 1299.457763, -1571.612670, 14.601311, 1298.004394, -1525.792846, 14.601311, 20000);
		InterpolateCameraLookAt(playerid, 1294.471191, -1571.714233, 14.952584, 1293.765869, -1528.428466, 14.898012, 20000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,BELA, " ");//biro rada
		SendClientMessage(playerid,BELA, " ");
		SendClientMessage(playerid,BELA, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,BELA, " ");
		SendClientMessage(playerid,BELA, " ");
		TutorijalTDControl(playerid, 1);
		//SendClientMessage(playerid,BELA, ""col_balkanstory"_____________________________________________________________");

		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 25000, false, "ii", playerid, 2 );
	}
	else if( izbor == 2 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Registracija racuna u toku...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1475.3021, -1788.4011, 13.9256 );
		InterpolateCameraPos(playerid, 1375.716308, -1626.305419, 70.459548, 1424.363891, -1689.544433, 53.629177, 20000);
		InterpolateCameraLookAt(playerid, 1378.733032, -1630.183227, 69.531364, 1427.068237, -1693.488891, 52.170238, 20000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//opstina
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 2);
		//SendClientMessage(playerid,-1, ""col_balkanstory"__________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 25000, false, "ii", playerid, 3 );
	}
	else if( izbor == 3 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Cuvanje registrovanih podataka u bazu...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1473.0046, -1011.1181, 26.6798 );
		InterpolateCameraPos(playerid, 1495.698486, -1057.418579, 42.250335, 1484.888916, -1043.303833, 36.637706, 10000);
		InterpolateCameraLookAt(playerid, 1492.851806, -1053.638671, 40.635295, 1481.771118, -1039.520263, 35.655849, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//komercialna banka
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 3);
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 4 );
	}
	else if( izbor == 4 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Skeniranje skina...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1858.5201, -1760.7402, 13.2980 );
		InterpolateCameraPos(playerid, 1880.138793, -1816.624389, 58.561801, 1879.045166, -1788.210205, 50.730747, 10000);
		InterpolateCameraLookAt(playerid, 1879.953491, -1811.807495, 57.234169, 1878.859863, -1783.393310, 49.403114, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//gradska trznica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 4);
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 5 );
	}
	else if( izbor == 5 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Ucitavanje shop itema...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1675.4829, -1345.5950, 17.4190 );
		InterpolateCameraPos(playerid, 1776.638183, -1338.348754, 56.637863, 1742.406860, -1339.964111, 37.828945, 10000);
		InterpolateCameraLookAt(playerid, 1772.033813, -1338.444458, 54.690773, 1737.680297, -1340.191772, 36.213905, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 5);
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 10 );
	}
	else if( izbor == 10 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Kreiranje glavnih varijabli zapoceto...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid,  1296.1425,-1442.2716,77.9596 );
		InterpolateCameraPos(playerid, 1296.1425,-1442.2716,77.9596, 1231.4746,-1327.1732,14.1355, 20000);
		//InterpolateCameraLookAt(playerid, -6.596968, -1852.076660, 17.325490, 322.778747, -1996.908691, 28.987028, 20000);*/
		InterpolateCameraLookAt(playerid, 1296.1425,-1442.2716,77.9596, 1231.4746,-1327.1732,14.1355, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//spawn
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 10);
		//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 11 );
	}
	else if( izbor == 11 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Kreiranje pickupa zapoceto...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos(playerid, 1148.4430,-1344.8217,13.6616);
		InterpolateCameraPos(playerid, 927.724792, -1286.564941, 51.656623, 1397.496093, -1415.905517, 32.533592, 30000);
		InterpolateCameraLookAt(playerid, 932.431823, -1288.218383, 51.324836, 1392.709960, -1414.556640, 32.011108, 30000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//gigatron
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 11);
		//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 12 );
	}
	else if( izbor == 12 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Skeniranje dostupne imovine zapoceto...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos(playerid, 2275.1340,-1700.6871,13.6479);
		InterpolateCameraPos(playerid, 2042.767822, -1470.297851, 54.489799, 2546.400146, -1771.930541, 41.233219, 30000);
		InterpolateCameraLookAt(playerid, 2047.054321, -1472.868164, 54.349193, 2542.777832, -1768.697875, 40.037876, 30000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid,12);//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 13 );
	}
	else if( izbor == 13 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Ucitavanje vozila...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos(playerid, 2411.5686,-1106.1973,40.1652);
		InterpolateCameraPos(playerid, 2515.796142, -1008.902709, 88.511833, 2062.358886, -1379.888061, 46.693622, 30000);
		InterpolateCameraLookAt(playerid, 2511.572509, -1011.466735, 87.745338, 2063.165771, -1375.001464, 46.008289, 30000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 13);
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 14 );
	}
	else if( izbor == 14 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Ucitavanje objekata...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos(playerid, 1894.9603,-1494.3060,3.2374);
		InterpolateCameraPos(playerid, 1894.9603,-1494.3060,3.2374, 1824.2610,-1585.6229,13.3575, 30000);
		//InterpolateCameraLookAt(playerid, 2511.572509, -1011.466735, 87.745338, 2063.165771, -1375.001464, 46.008289, 30000);*/
		InterpolateCameraLookAt(playerid, 1894.9603,-1494.3060,3.2374, 1824.2610,-1585.6229,13.3575, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 14);
		//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 15 );
	}
	else if( izbor == 15 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Ucitavanje komandi...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1609.6746,-1585.5336,13.7188 );
		InterpolateCameraPos(playerid, 1609.6746,-1585.5336,13.7188, 1424.2689,-1712.7000,13.5469, 30000);
		//InterpolateCameraLookAt(playerid, 2511.572509, -1011.466735, 87.745338, 2063.165771, -1375.001464, 46.008289, 30000);*/
		InterpolateCameraLookAt(playerid, 1609.6746,-1585.5336,13.7188, 1424.2689,-1712.7000,13.5469, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 15);
		//SendClientMessage(playerid,-1, " ");
		//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 16 );
	}
	else if( izbor == 16 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Ucitavanje organizacija...");
		ShowLogo(playerid);
		Dimi_SetPlayerPos( playerid, 1532.9167,-1021.1403,45.2602 );
		InterpolateCameraPos(playerid, 1532.9167,-1021.1403,45.2602, 1427.3610,-1171.3484,24.2865, 30000);
		//InterpolateCameraLookAt(playerid, 2511.572509, -1011.466735, 87.745338, 2063.165771, -1375.001464, 46.008289, 30000);*/
		InterpolateCameraLookAt(playerid, 1532.9167,-1021.1403,45.2602, 1427.3610,-1171.3484,24.2865, 10000);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		SendClientMessage(playerid,-1, " ");//wwin kladionica
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 16);//SendClientMessage(playerid,-1, ""col_balkanstory"________________________________________________________________________");
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 20000, false, "ii", playerid, 6 );
	}
	else if( izbor == 6 ) {
		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		announcement(playerid,"Konfiguracija postavki zavrsena.");
		ShowLogo(playerid);
		Dimi_SetPlayerPos(playerid,937.3864,-1048.0986,31.2265);
		SetPlayerInterior( playerid, 0 );
		//SetPlayerVirtualWorld( playerid, 1 );
		InterpolateCameraPos(playerid,937.3864,-1048.0986,31.2265, 1440.6066,-853.4370,87.5552, 20000);
		InterpolateCameraLookAt(playerid, 937.3864,-1048.0986,31.2265, 1440.6066,-853.4370,87.5552, 20000);
		
		SendClientMessage(playerid,-1, " ");//kraj tutoriala
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		TutorijalTDControl(playerid, 6);
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 18000, false, "ii", playerid, 7 );
	}
	else if( izbor == 7 ) {
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		SendClientMessage(playerid,-1, " ");
		aliasLogin( playerid );
		PlayerInfo[ playerid ][ xPocetniTut ] = 1;
		TutorijalTDControl(playerid, -1);
		antiCheatCS[ playerid ][ TeleportCheck ] = 4;
		antiCheatCS[ playerid ][ WeaponDetect ] = 4;
		//SetCameraBehindPlayer( playerid ); TogglePlayerControllable( playerid, true );
		//SetPlayerInterior( playerid, 0 ); SetPlayerVirtualWorld( playerid, 0 );
		//Dimi_SetSpawnInfo( playerid );
		//SpawnPlayer( playerid ); 
		SavePlayer( playerid );
		TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 300, false, "ii", playerid, 8 );
		//CreatePlayerVehicles( playerid );
	}
	else if( izbor == 8 ) {
	
		PocetniTutorialStartovan[ playerid ] = false;
		
		ServerInfo[ RegistrovanihKorisnika ]++;//khurcina
	
		//ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, DialogTekstovi[ 1 ], "U redu", "" );
		new logg[2048];
		new dolazi[30];
		new mail[128];
		new password[128];
		new godina = PlayerInfo[ playerid ][ xGodine ];
		format(password,128,"%s",PlayerInfo[ playerid ][ xLozinka ]);
		format(mail,128,"%s",PlayerInfo[ playerid ][ xEmail ]);
		
		if(PlayerInfo[ playerid ][ xDrzava ] == 1) { dolazi = "Makedonije"; }
		else if(PlayerInfo[ playerid ][ xDrzava ] == 2) { dolazi = "Hrvatske"; }
		else if(PlayerInfo[ playerid ][ xDrzava ] == 3) { dolazi = "Srbije"; }
		else if(PlayerInfo[ playerid ][ xDrzava ] == 4) { dolazi = "Crne_Gore"; }
		else if(PlayerInfo[ playerid ][ xDrzava ] == 5) { dolazi = "Bosne i Hercegovine"; }
		else if(PlayerInfo[ playerid ][ xDrzava ] == 6) { dolazi = "Ostalo"; }


		format(logg,sizeof(logg),"Uspjesno ste se registrovali na "col_balkanstory"Nova Era RolePlay!{ffffff}\nOvdje Vam prikazujemo informacije o vasem racunu\nkoji ste upravo registrovali u nasu databazu,\nukoliko primjetite greske, fotografisite ovaj dijalog\n i postavite zahtjev za izmenu podataka na\nnasem forumu. Link do naseg portala mozete\n dobiti kucajuci komandu: /forum\n\nVase ime: "col_balkanstory"%s{ffffff}\nStarost: "col_balkanstory"%d{ffffff}\nDolazite iz: "col_balkanstory"%s{ffffff}\nVas e-mail: "col_balkanstory"%s\nLozinka: "col_balkanstory"%s{ffffff}\n\nZbog sigurnosti vaseg naloga uslikajte ovaj dialog(F8)!\n\nUkoliko ste PROCITALI sve, mozete nastaviti sa ulogovanjem na racun.",ImeIgraca(playerid),godina,dolazi,mail,password);

		ShowPlayerDialog(playerid,764, DSMSG, D_NASLOV,logg, "U redu", "");
		/*for( new i = 0; i < 52; i ++)
		{
			TextDrawShowForPlayer( playerid, TDEditor_TD[ i ] );
		}*/
		//////////////////
		/*for( new i = 0; i < 15; i ++)
		{
			TextDrawShowForPlayer( playerid, GPSIGTD[ i ] );
		}*/
		/*TextDrawShowForPlayer( playerid, GladTDPizza);
		TextDrawShowForPlayer( playerid, WcTDSolja);
		/////////////////////////////////////
		TextDrawShowForPlayer( playerid, HappyHoursTD );
		showhjhh(playerid);
		TextDrawShowForPlayer(playerid,HappyJobsTD);*/
		
		//bagovali boxovi
		PlayerTextDrawHide( playerid, RegisterTD[playerid][ 12 ]);
		PlayerTextDrawDestroy( playerid, RegisterTD[ playerid ][ 12 ] );
		PlayerTextDrawHide( playerid, RegisterTD[playerid][ 13 ]);
		PlayerTextDrawDestroy( playerid, RegisterTD[ playerid ][ 13 ] );
		///////////////////////////
		#if kladionica == 1
		for(  new i = 0; i < 10; i++ )//resetuje listic kladionice bioBUG
		{
			KladionicaListic[ playerid ][ parID ][ i ] = -1;
			KladionicaListic[ playerid ][ keciksdva ][ i ] = -1;
			KladionicaListic[ playerid ][ Kvota ][ i ] = 0.0;
			KladionicaListic[ playerid ][ teamID1 ][ i ] = -1;
			KladionicaListic[ playerid ][ teamID2 ][ i ] = -1;
		}
		KladionicaListic[ playerid ][ Uplaceno ] = false;
		KladionicaListic[ playerid ][ Zavrseno ] = false;
		KladionicaListic[ playerid ][ Uplata ] = 0;
		KladionicaListic[ playerid ][ Dobitak ] = 0;
		KladionicaListic[ playerid ][ Status ] = false;
		SaveKladionica( playerid );
		#endif
		/////////////////////////////////////
		ResetAllWeapons( playerid );
		
		new playersip[ 128 ];
		GetPlayerIp( playerid, playersip, sizeof( playersip ) );
					
		format( globalstring, sizeof( globalstring ), ""col_balkanstory"[REGISTRACIJA]: {ffffff}Korisnik: %s | [ID:%d] | [IP:%s] se upravo registrovao na server!", ImeIgraca( playerid ), playerid, playersip );
		AdminPoruka( ZUTA, globalstring );
		
		#if NERP_ZIMSKI_MOD  == 1
		SendClientMessagee( playerid, -1, ""col_balkanstory"| NE:RP | "col_white"Nova Era OGC vam zeli srecne novogodisnje praznike - HAPPY NEW YEAR -");
		#endif
		//TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 18000, false, "ii", playerid, 9 );
	}
	else if(izbor == 9)
	{
		static a;
		#pragma unused a
		//SetTimerEx( "Login", 100, false, "d", playerid );
	}
	return 1;
}
//------------------------------------------------------------------------------
public KSpam( playerid )
{
	if(GetPVarInt( playerid, "Kladjenje") == 1)
	{
		SetPVarInt( playerid, "Kladjenje", 0);
	}
	return 1;
}
IsMeleeWeapon(weaponid)
{
	switch(weaponid)
	{
		case 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15: return true;
	}
	return false;
}
//------------------------------------------------------------------------------
ShowStats( playerid, targetid )
{
	if( IsPlayerConnected( playerid ) && IsPlayerConnected( targetid ) )
	{
		new pol[ 7 ];
		if( PlayerInfo[ playerid ][ xPol ] == 1 ) pol = "musko";
		else if( PlayerInfo[ playerid ][ xPol ] == 2 ) pol = "zensko";

		new nxtlevel = PlayerInfo[ targetid ][ xLevel ]+1,
			expamount = nxtlevel*levelexp,
			warns = PlayerInfo[ targetid ][ xWarn ],
			level = PlayerInfo[ targetid ][ xLevel ],
			exp = PlayerInfo[ targetid ][ xRespekt ];

		new playersip[ 128 ];
		GetPlayerIp(targetid, playersip, sizeof( playersip ) );

		new weapon[13],
			weapname[13][50],
			bullets[13];

		for( new slot = 0; slot < 13; slot++) {
			GetPlayerWeaponData( targetid, slot, weapon[ slot ], bullets[ slot ] );

			GetWeaponName( weapon[ slot ], weapname[ slot ], 50 );
		}


		SendClientMessage(playerid, 0x5BD3FFAA,"_________________________________________________");
		format( globalstring, sizeof( globalstring ),"*** %s ***", ImeIgraca( targetid ) );
		SendClientMessage(playerid, UGBOJA,globalstring);
		format( globalstring, sizeof( globalstring ), "Pol [%s] | Level:[%d] | Sati Igranja:[%d]", pol, level, PlayerInfo[ targetid ][ xOnlineSati ] );
		SendClientMessage(playerid, 0xFFFFFFAA,globalstring);
		format( globalstring, sizeof( globalstring ), "Respekt:[%d/%d] | Novac: [%d$] | Banka: [%d$]", exp, expamount, PlayerInfo[ targetid ][ xNovac ], PlayerInfo[ targetid ][ xBRacun] );
		SendClientMessage(playerid, 0xFFFFFFAA,globalstring);
		format( globalstring, sizeof( globalstring ), "Upozorenja: [%d/5] | Posao: [%s] | Posao ugovor: [%d/3]", warns, getJobName( PlayerInfo[ targetid ][ xPosao ] ), PlayerInfo[ targetid ][ xUgovor ] );
		SendClientMessage(playerid, 0xFFFFFFAA,globalstring);
		format( globalstring, sizeof( globalstring ), "Godine: [%d] | Organizacija: [%s] | Rank: [%d]", PlayerInfo[ targetid ][ xGodine ], getOrgName( PlayerInfo[ targetid ][ xClan ] ), PlayerInfo[ targetid ][ xRank ] );
		SendClientMessage(playerid, 0xFFFFFFAA,globalstring);
		format( globalstring, sizeof( globalstring ), "Kljuc Imovine1 [%d] | Kljuc Imovine2 [%d] | Kljuc Imovine3 [%d]", PlayerInfo[ targetid ][ xProperty ][ 0 ], PlayerInfo[ targetid ][ xProperty ][ 1 ], PlayerInfo[ targetid ][ xProperty ][ 2 ] );
		SendClientMessage(playerid, 0xF0F0F0FF,globalstring);
		format( globalstring, sizeof( globalstring ), "Kljuc Firme [%d] | Garaza [%d]", PlayerInfo[ targetid ][ xFirmaID ], PlayerInfo[ targetid ][ xGarageID ] );
		SendClientMessage(playerid, 0xF0F0F0FF,globalstring);
		format( globalstring, sizeof( globalstring ), "Kljuc Vozila1 [%d] | Kljuc Vozila2 [%d]", PlayerInfo[ targetid ][ xVoziloID ][ 0 ], PlayerInfo[ targetid ][ xVoziloID ][ 1 ] );
		SendClientMessage(playerid, 0xF0F0F0FF,globalstring);
		format( globalstring, sizeof( globalstring ), "Kljuc Vozila3 [%d] | Kljuc Vozila4 [%d]", PlayerInfo[ targetid ][ xVoziloID ][ 2 ], PlayerInfo[ targetid ][ xVoziloID ][ 3 ] );
		SendClientMessage(playerid, 0xF0F0F0FF,globalstring);
		format( globalstring, sizeof( globalstring ), "Aktivnost igraca u staff timu: %d minuta", PlayerInfo[ targetid ][ xStaffMin ] );
		SendClientMessage( playerid, 0xF0F0F0FF, globalstring );
		format( globalstring, sizeof( globalstring ), "Kljuc hotela: [%d] | IP Adresa: [%s]", PlayerInfo[ targetid ][ xHotelID ], playersip );
		SendClientMessage( playerid, 0xF0F0F0FF, globalstring );
		format( globalstring, sizeof( globalstring ), "%s[ 0 ] | %s[%d] | %s[%d] | %s[%d] | %s[%d] | %s[%d]", weapname[ 0 ], weapname[ 1 ], bullets[ 1 ], weapname[ 2 ], bullets[ 2 ], weapname[ 3 ], bullets[ 3 ], weapname[4], bullets[4], weapname[5], bullets[5] );
		SendClientMessage( playerid, 0xF0F0F0FF,  globalstring );
		format( globalstring, sizeof( globalstring ), "%s[%d] | %s[%d] | %s[%d] | %s[ 0 ] | %s[ 0 ] | %s[ 0 ]", weapname[6], bullets[6], weapname[7], bullets[7] ,weapname[8], bullets[8], weapname[9], weapname[10], weapname[11] );
		SendClientMessage( playerid, 0xF0F0F0FF,globalstring );
		SendClientMessage( playerid, 0x5BD3FFAA,"_________________________________________________");
	}
}
//------------------------------------------------------------------------------
ShowPDStats( playerid, targetid )
{
	if( IsPlayerConnected( playerid ) && IsPlayerConnected( targetid ) )
	{
		new coordsstring[84];
		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
		strcat( DialogStrgEx, "__________________________________________________________________\n");
		format( coordsstring, sizeof( coordsstring ),"*** %s ***\n", ImeIgraca( targetid ) );
		strcat( DialogStrgEx, coordsstring );
		format( coordsstring, sizeof( coordsstring ), "Izdao ticketa: [%d] | Oduzeo novaca preko ticketa: [%d]\n", PlayerInfo[ targetid ][ xPDStatsTicket ], PlayerInfo[ targetid ][ xPDStatsTicketMoney ] );
		strcat( DialogStrgEx, coordsstring );
		format( coordsstring, sizeof( coordsstring ), "Oduzeo oruzja: [%d]\n", PlayerInfo[ targetid ][ xTakenWeps ] );
		strcat( DialogStrgEx, coordsstring );
		format( coordsstring, sizeof( coordsstring ), "Puta uhitio nekoga: [%d]\n", PlayerInfo[ targetid ][ xPDUhapsio ] );
		strcat( DialogStrgEx, coordsstring );
		strcat( DialogStrgEx, "__________________________________________________________________");
		ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, DialogStrgEx, "U redu", "" );
		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));
	}
}
//------------------------------------------------------------------------------
ShowAdminStats( playerid, targetid )
{
	if( IsPlayerConnected( playerid ) && IsPlayerConnected( targetid ) )
	{
		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
		strcat( DialogStrgEx, "__________________________________________________________________\n");
		format( globalstring, sizeof( globalstring ),"*** %s ***\n", ImeIgraca( targetid ) );
		strcat( DialogStrgEx, globalstring );
		format( globalstring, sizeof( globalstring ), "Dao banova: [%d] | Dao warnova: [%d] | Kickovao puta: [%d]\n", AI[ targetid ][ aTBan ], AI[ targetid ][ aTWarn ], AI[ targetid ][ aTKick ] );
		strcat( DialogStrgEx, globalstring );
		format( globalstring, sizeof( globalstring ), "Oduzeo novca: [%d] | Odgovorenih PMova: [%d] |  Stavio u zatvor/areu: [%d]\n", AI[ targetid ][ aTCharge ], AI[ targetid ][ aTPM ], AI[ targetid ][ aTJail ] );
		strcat( DialogStrgEx, globalstring );
		format( globalstring, sizeof( globalstring ), "Unbanovao puta: [%d] |  Unwarnovao puta: [%d] |  Unjailovao puta: [%d]\n", AI[ targetid ][ aTUnban ] , AI[ targetid ][ aTUnwarn ] , AI[ targetid ][ aTUnjail ] );
		strcat( DialogStrgEx, globalstring );
		strcat( DialogStrgEx, "__________________________________________________________________");
		ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, DialogStrgEx, "U redu", "" );
		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));
	}
}
//------------------------------------------------------------------------------
public BackupClear( playerid, calledbytimer )
{
	if( IsPlayerConnected( playerid ) )
	{
		if( GetFactionType( playerid ) == ORG_TIP_PD  )
		{
			if( GetPVarInt( playerid, "RequestingBackup" ) == 1 )
			{
				for(new i; i < MAX_PLAYERS; i++)
				{
					if( IsPlayerConnected(i))
					{
						if( OI[ PlayerInfo[ i ][ xClan ] ][ oTip ] == ORG_TIP_PD )
						{
							Dimi_DisablePlayerCheckpoint( i );
						}
					}
				}
				if( calledbytimer != 1 )
				{
					SendClientMessagee( playerid, 0x8D8DFF00, "Vase pojacanje je izbrisano." );
				}
				else
				{
					SendClientMessagee( playerid, 0x8D8DFF00, "Vas zahtev za pojacanje je izbrisano automatksi." );
				}
				SetPVarInt( playerid, "RequestingBackup", 0 );
			}
			else
			{
				if(calledbytimer != 1 )
				{
					GRESKA( playerid, "Nemate aktivan zahtev za pojacanje!");
				}
			}
		}
	}
	return 1;
}

HideDamageTextDraw(playerid);
public HideDamageTextDraw(playerid)
{
	PlayerTextDrawHide(playerid,DamageTextdraw[playerid]);
	return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if(PlayerInfo[playerid][xPUBG] == 1 && PlayerInfo[playerid][xSkocio] == 0)
	{
		greska(playerid, "Ne mozete se udarati/pucati dok ne skocite iz aviona.");
		Dimi_SetPlayerHealth(damagedid, 100);
		return 1;
	}
	new damagestring[10];
	format(damagestring,sizeof damagestring, "-%.1f",amount);
	PlayerTextDrawSetString(playerid, DamageTextdraw[playerid],damagestring);
	PlayerTextDrawShow(playerid,DamageTextdraw[playerid]);
	SetTimerEx("HideDamageTextDraw", 2000, false, "i", playerid);
	if(bodypart == 9 && weaponid == 34)
	{
		if(PlayerInfo[damagedid][xAdmin] > 0)
		{
			greska(playerid, "Ne mozete njega - taj igrac ima status administratora!");
			return 1;
		}
		new
			ime[MAX_PLAYER_NAME];
		GetPlayerName(damagedid, ime,sizeof(ime));
		Dimi_SetPlayerHealth(damagedid, 0);
		Dimi_SetPlayerArmour(damagedid, 0);
		SendInfoMessage(playerid, "Pogodili ste %s u glavu sniperom!", ime);
		if(sniperevent == 1)
		{
			SendScreenMessage(playerid, "~y~Sniper Event:~w~ Dobili ste 1 headshot point!");
			PlayerInfo[playerid][xSniperHeadshots]++;
			DajIgracuNovac(playerid, 2000);
			SendInfoMessage(playerid, "Zbog Sniper Event-a ste dobili "col_balkanstory"$2000{ffffff} za postignuti headshot!");
		}
		SendInfoMessage(damagedid, "Pogodjeni ste u glavu sniperom!");
	}
	return 1;
}


//------------------------------------------------------------------------------
public OnPlayerTakeDamage( playerid, issuerid, Float:amount, weaponid, bodypart )
{
	//if(NaZombieEventu[playerid]) return ZombieEvent_OnPlayerTakeDamage(playerid,issuerid,amount,weaponid,bodypart);
	//printf("Igrac ID %d ( %s ) je primio damage od igraca ID %i ( %s )",playerid,ImeIgraca(playerid),issuerid,ImeIgraca(issuerid));
	if(Ranjen[playerid] == 0)
	{
		new damagedealt[10],notification[100];
		format(damagedealt,sizeof(damagedealt),"%.1f",amount);
		format(notification,sizeof notification,
			"%s vam je oduzeo %s HP", ImeIgraca(issuerid), damagedealt);
		SendPlayerNotification(playerid,true,notification);
		/*ptakedamage0[playerid] = CreatePlayerTextDraw(playerid, 444.444580, 327.040039, "Dentist Brace");
		PlayerTextDrawLetterSize(playerid, ptakedamage0[playerid], 0.237111, 0.873244);
		PlayerTextDrawAlignment(playerid, ptakedamage0[playerid], 1);
		PlayerTextDrawColor(playerid, ptakedamage0[playerid], -1);
		PlayerTextDrawSetShadow(playerid, ptakedamage0[playerid], 0);
		PlayerTextDrawSetOutline(playerid, ptakedamage0[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, ptakedamage0[playerid], 51);
		PlayerTextDrawFont(playerid, ptakedamage0[playerid], 1);
		PlayerTextDrawSetProportional(playerid, ptakedamage0[playerid], 1);

		ptakedamage1[playerid] = CreatePlayerTextDraw(playerid, 406.666625, 328.533355, "-100.0");
		PlayerTextDrawLetterSize(playerid, ptakedamage1[playerid], 0.217111, 0.823466);
		PlayerTextDrawAlignment(playerid, ptakedamage1[playerid], 1);
		PlayerTextDrawColor(playerid, ptakedamage1[playerid], -1);
		PlayerTextDrawSetShadow(playerid, ptakedamage1[playerid], 0);
		PlayerTextDrawSetOutline(playerid, ptakedamage1[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, ptakedamage1[playerid], 51);
		PlayerTextDrawFont(playerid, ptakedamage1[playerid], 1);
		PlayerTextDrawSetProportional(playerid, ptakedamage1[playerid], 1);
		if(issuerid == 65535)
		{
			TextDrawShowForPlayer(playerid,takedamage0);
			TextDrawShowForPlayer(playerid,takedamage1);
			PlayerTextDrawSetString(playerid,ptakedamage0[playerid],"Pad/udarac");

			new damagedealt[10];
			format(damagedealt,sizeof(damagedealt),"%.2f",amount);
			PlayerTextDrawSetString(playerid,ptakedamage1[playerid],damagedealt);

			PlayerTextDrawShow(playerid,ptakedamage0[playerid]);
			PlayerTextDrawShow(playerid,ptakedamage1[playerid]);

			hideptakedamage[playerid] = SetTimerEx("phidetdtd", 1500, false, "i", playerid);
		}*
		if(issuerid != IPI && issuerid != 65535)
		{
			//showtdtd(playerid);
			TextDrawShowForPlayer(playerid,takedamage0);
			TextDrawShowForPlayer(playerid,takedamage1);
			PlayerTextDrawSetString(playerid,ptakedamage0[playerid],ImeIgraca(issuerid));

			new damagedealt[10];
			format(damagedealt,sizeof(damagedealt),"%.2f",amount);
			PlayerTextDrawSetString(playerid,ptakedamage1[playerid],damagedealt);

			PlayerTextDrawShow(playerid,ptakedamage0[playerid]);
			PlayerTextDrawShow(playerid,ptakedamage1[playerid]);

			hideptakedamage[playerid] = SetTimerEx("phidetdtd", 1500, false, "i", playerid);
		}*/
	}
	/*if( PlayerInfo[issuerid][xLevel] == 0 || PlayerInfo[issuerid][xLevel] == 1 || PlayerInfo[issuerid][xLevel] == 2 ) {
		SendAcMessage(playerid, "Ti si pocetnik, zabranjeno ti je da se boris ili pucas!");
		SendAcMessage(playerid, "Administracija je obavjestena o tvojim akcijama na serveru!");
		new ac[200];
		format( ac, sizeof( ac ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white" je pocetnik (igrac level - 1 ili 2 ), nema dopustenje za pucanje i tucu! (/spec)", ImeIgraca( issuerid ) );
		AdminPoruka( SVETLOCRVENA, ac );
		return 1;
	}*/ //uklonjeno radi baga
	if( issuerid != INVALID_PLAYER_ID && issuerid != INVALID_PLAYER_ID && amount == 0 && weaponid == 0 && bodypart == 3 )
	{
		format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Command kill", ImeIgraca( issuerid ) );
		AdminPoruka( SVETLOCRVENA, globalstring );
		Kickovanje( issuerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Command kill");
		return 0;
	}
	if( issuerid != INVALID_PLAYER_ID  )
	{
		if( OI[ PlayerInfo[ issuerid ][ xClan ] ][ oTip ] == ORG_TIP_PD && !IsPlayerInAnyVehicle( issuerid ) && !IsPlayerInAnyVehicle( playerid ) && GetWeapon( issuerid ) == 23 && ImaTazer[ issuerid ] == true && !AdminDuty[ playerid ] ) {
			if( GetFactionType( playerid ) == ORG_TIP_PD ) return SendClientMessagee( issuerid, CRVENA, "Ne mozes tazovati PD!" );

			new Float:Pos[ 3 ];
			GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
			if( IsPlayerInRangeOfPoint( issuerid, 10.0, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] ) )
			{

				format( globalstring, sizeof( globalstring ), "%s puca tazerom na %s-a i uspjesno ga pogadja!", ImeIgraca( issuerid ), ImeIgraca( playerid ) );
				PorukaRadius( 20.0, issuerid, globalstring, LJUBICASTA );
				TogglePlayerControllable( playerid, false );

				if( Maskuse[ playerid ] == true )
				{
					SetPlayerName( playerid, RealName[ playerid ] );
					Maskuse[ playerid ] = false;
				}

				PlayerCuffed[ playerid ] = 1;
				Dimi_SetPlayerHealth( playerid, 50 );
				SetPVarInt( playerid, "CuffTimerCalled", 1 );
				TazerTimer[ playerid ] = SetTimerEx("TazovanTajmer", 15000, false, "i", playerid );
				OnePlayAnim( playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0 );
				return 0;
			}
		}
		
		/*if( NaDmEventu[ playerid ] == false && WARPInfo[ playerid ][ WARIgrac ] == -1 && !AdminDuty[ playerid ] && PlayerCuffed[ playerid ] == 0 ) {
			if( weaponid <= 42 ) {
				new Float:takeHealth = antiCheatCS[ playerid ][ TrueHealth ] - WeaponDamage[ weaponid ][ bodypart - 3 ];
				Dimi_SetPlayerHealth( playerid, takeHealth );
			}
		}*/
		
		//printf( "%s je naneo %.0f demidza %s-u, oruzje: %d, deo tela: %d", ImeIgraca( issuerid ), amount, ImeIgraca( playerid ), weaponid, bodypart );
	}
	return 1;
}

public TazovanTajmer( playerid ) {
	if( PlayerCuffed[ playerid ] == 1 ) {
	
		PlayerCuffed[ playerid ] = 0;
		SetPVarInt( playerid, "CuffTimerCalled", 0 );
		TogglePlayerControllable( playerid, true );
		announcement( playerid, "~y~Tazer zavrsen", 5000, 3 );
		ClearAnimations( playerid );
		Dimi_KillTimer( TazerTimer[ playerid ] );
	}
	return 1;
}
/*/------------------------------------------------------------------------------
Float:GetDistanceBetweenPlayers(p1,p2)
{
	new Float:x1,
		Float:y1,
		Float:z1,
		Float:x2,
		Float:y2,
		Float:z2;

	if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2))
	{
		return -1.00;
	}

	GetPlayerPos(p1,x1,y1,z1);
	GetPlayerPos(p2,x2,y2,z2);

	return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}
//------------------------------------------------------------------------------
GetClosestPlayer(p1)
{
	new Float:dis,
		Float:dis2,
		player;

	player = -1;
	dis = 99999.99;

	for(new x; x < MAX_PLAYERS; x++)
	{
		if( IsPlayerConnected(x))
		{
			if(x != p1)
			{
				dis2 = GetDistanceBetweenPlayers(x,p1);
				if(dis2 < dis && dis2 != -1.00)
				{
					dis = dis2;
					player = x;
				}
			}
		}
	}
	return player;
}*/
//------------------------------------------------------------------------------
OtherCheck( playerid )
{
	if( PlayerInfo[ playerid ][ xZatvor ] > 0 )
	{
		if(PlayerInfo[ playerid ][ xZatvorVreme ] > 0 )
		{
			PlayerInfo[ playerid ][ xZatvorVreme ] -= 1;
			format( globalstring, sizeof( globalstring ), "~r~Do slobode: ~w~%d ~r~min",( PlayerInfo[ playerid ][ xZatvorVreme ]+1 ) );
			PlayerTextDrawSetString(playerid,JailTD[playerid],globalstring);
			PlayerTextDrawShow(playerid,JailTD[playerid]);
		}
		else if( PlayerInfo[ playerid ][ xZatvorVreme ] <= 0 )
		{
			if( PlayerInfo[ playerid ][ xZatvor ] == OBICAN_ZATVOR )
			{
				new rand = random( sizeof( RandomCelije ) );
				Dimi_SetPlayerPos( playerid, RandomCelije[ rand ][ 0 ], RandomCelije[ rand ][ 1 ], RandomCelije[ rand ][ 2 ] );
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SetCameraBehindPlayer( playerid );
				TogglePlayerControllable( playerid, false );
				SetPlayerInterior( playerid, 0 );
				SetPlayerVirtualWorld( playerid, 0 );
			}
			else if( PlayerInfo[ playerid ][ xZatvor ] == ALKATRAZ )
			{
				SetPlayerWorldBounds( playerid, 20000.0000, -20000.0000, 20000.0000, -20000.0000 );
				SetPlayerInterior( playerid, 0 );
				SetPlayerVirtualWorld( playerid, 0 );
				Dimi_SetPlayerPos( playerid, 1802.3077, -1578.9171, 13.5572);
			}
			PlayerInfo[ playerid ][ xZatvor ] = 0; PlayerInfo[ playerid ][ xZatvorVreme ] = 0;
			SendInfoMessage( playerid, "Odrobijali ste svoju kaznu i sada ste slobodni!" );
			announcement( playerid, "~g~Sloboda~n~~w~Pokusajte biti bolji gradjanin", 5000, 1);
			PlayerTextDrawHide(playerid,JailTD[playerid]);
		}
	}
}
//------------------------------------------------------------------------------
stock CrimInRange( Float:radi, playerid, copid ) {
	if( IsPlayerConnected( playerid ) && IsPlayerConnected( copid ) ) {
		new Float:posx,
			Float:posy,
			Float:posz,
			Float:oldposx,
			Float:oldposy,
			Float:oldposz,
			Float:tempposx,
			Float:tempposy;

		GetPlayerPos( playerid, oldposx, oldposy, oldposz);
		GetPlayerPos(copid, posx, posy, posz);

		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);

		if(((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)))
		{
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
public Provala( playerid )
{
	for( new i = 1; i < MAX_IMOVINA; i++) {
		if( IsPlayerInRangeOfPoint( playerid, 2, II[  i][ iEnter ][ 0 ], II[  i][ iEnter ][ 1 ], II[  i][ iEnter ][ 2 ] ) ) {
			if(GetPVarInt( playerid, "Pokusaj") == 1) {
				if( II[ i ][ iAlarm ] == 1 ) {
					format( globalstring, sizeof( globalstring ), "[%s ALARM] BEEP BEEP BEEP!!", II[ i ][ iAdress ] );
					PorukaRadius(60.0, playerid, globalstring, LJUBICASTA );
				}
				else if( II[ i ][ iAlarm ] == 2) {
					for(new h; h < MAX_PLAYERS; h++) {
						if( IsPlayerConnected( h ) ) {
							if( strcmp( ImeIgraca( h ), II[ i ][ iOwner ], true) == 0 ) {
								SendClientMessagee( h, ZUTA, "SMS: Netko vam je provalio bravu! Pozovite policiju, Vas Alarm!");
							}
						}
					}
					format( globalstring, sizeof( globalstring ), "[%s ALARM] BEEP BEEP BEEP!!", II[ i ][ iAdress ] );
					PorukaRadius(60.0, playerid, globalstring, LJUBICASTA );
				}
				else if( II[ i ][ iAlarm ] >= 3)
				{
					for(new h; h < MAX_PLAYERS; h++)
					{
						if( IsPlayerConnected( h ) )
						{
							if( strcmp( ImeIgraca( h ), II[ i ][ iOwner ], true) == 0 )
							{
								SendClientMessagee( h, ZUTA, "SMS: Netko vam pokusava provaliti u kucu, Vas Alarm!" );
							}
						}
					}
					for( new id = 1; id < MAX_ORG; id++) {
						if( OI[ id ][ oTip ] == ORG_TIP_PD ) {
							OrgPoruka( id, 0x2641FEAA, "HQ: Svim jedinicama: Prijavio: Tihi Alarm" );
							OrgPoruka( id, 0x2641FEAA, "HQ: Zlocin: Provala u kucu    ||  Osumljiceni: Nepoznat" );
							format( globalstring, sizeof( globalstring ), "HQ: Adresa kuce: %s", II[ i ][ iAdress ] );
							OrgPoruka( id, 0x2641FEAA, globalstring );
							format( globalstring, sizeof( globalstring ), "[%s ALARM] BEEP BEEP BEEP!!", II[ i ][ iAdress ] );
							PorukaRadius(60.0, playerid, globalstring, LJUBICASTA );
						}
					}
				}
				II[ i ][ iLocked ] = 0; Odbrojavanje[ playerid ] = 0;
				VremeTDControl( playerid, false );
				SendClientMessagee( playerid, SVETLOPLAVA, "Onesposobili ste bravu, sada mozete uci u kucu!");
				PlayerPlaySound( playerid, 1145, 0.0, 0.0, 0.0);
				TogglePlayerControllable( playerid, 1);
				SetPVarInt( playerid, "Pokusaj", 0);
			}
		}
	}
	return 1;
}
//=========================| GM PORT BEOGRAD |================================
forward SaveBGSports( );
public SaveBGSports( )
{
	if( fexist( F_BGSPORT ) )
	{
		fremove( F_BGSPORT );
	}
	new File:_h_handler = fopen( F_BGSPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_BGSPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", BGsupportInfo[ i ][ BGsupportID ], BGsupportInfo[ i ][ BGsupportCreated ], BGsupportInfo[ i ][ BGsupportName ], BGsupportInfo[ i ][ BGsupportPos ][ 0 ], BGsupportInfo[ i ][ BGsupportPos ][ 1 ], BGsupportInfo[ i ][ BGsupportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);

	return 1;
}
//------------------------------------------------------------------------------
forward LoadBGSports( );
public LoadBGSports( )
{
	if( fexist( F_BGSPORT ) )
	{
		new File:_h_handler = fopen( F_BGSPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			BGsupportInfo[ i ][ BGsupportID ] = strval( arrCoords[ 0 ] );
			BGsupportInfo[ i ][ BGsupportCreated ] = strval( arrCoords[ 1 ] );
			strmid( BGsupportInfo[ i ][ BGsupportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			BGsupportInfo[ i ][ BGsupportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			BGsupportInfo[ i ][ BGsupportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			BGsupportInfo[ i ][ BGsupportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );

			i++;
		}

		fclose(_h_handler);
	}

	return 1;
}




//=========================| GM PORT SARAJEVO |================================
forward SaveSASports( );
public SaveSASports( )
{
	if( fexist( F_SASPORT ) )
	{
		fremove( F_SASPORT );
	}
	new File:_h_handler = fopen( F_SASPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_SASPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", SAsupportInfo[ i ][ SAsupportID ], SAsupportInfo[ i ][ SAsupportCreated ], SAsupportInfo[ i ][ SAsupportName ], SAsupportInfo[ i ][ SAsupportPos ][ 0 ], SAsupportInfo[ i ][ SAsupportPos ][ 1 ], SAsupportInfo[ i ][ SAsupportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);

	return 1;
}
//------------------------------------------------------------------------------
forward LoadSASports( );
public LoadSASports( )
{
	if( fexist( F_SASPORT ) )
	{
		new File:_h_handler = fopen( F_SASPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			SAsupportInfo[ i ][ SAsupportID ] = strval( arrCoords[ 0 ] );
			SAsupportInfo[ i ][ SAsupportCreated ] = strval( arrCoords[ 1 ] );
			strmid( SAsupportInfo[ i ][ SAsupportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			SAsupportInfo[ i ][ SAsupportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			SAsupportInfo[ i ][ SAsupportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			SAsupportInfo[ i ][ SAsupportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );

			i++;
		}

		fclose(_h_handler);
	}

	return 1;
}




//=========================| GM PORT ZAGREB |================================
forward SaveZGSports( );
public SaveZGSports( )
{
	if( fexist( F_ZGSPORT ) )
	{
		fremove( F_ZGSPORT );
	}
	new File:_h_handler = fopen( F_ZGSPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_ZGSPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", ZGsupportInfo[ i ][ ZGsupportID ], ZGsupportInfo[ i ][ ZGsupportCreated ], ZGsupportInfo[ i ][ ZGsupportName ], ZGsupportInfo[ i ][ ZGsupportPos ][ 0 ], ZGsupportInfo[ i ][ ZGsupportPos ][ 1 ], ZGsupportInfo[ i ][ ZGsupportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);

	return 1;
}
//------------------------------------------------------------------------------
forward LoadZGSports( );
public LoadZGSports( )
{
	if( fexist( F_ZGSPORT ) )
	{
		new File:_h_handler = fopen( F_ZGSPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			ZGsupportInfo[ i ][ ZGsupportID ] = strval( arrCoords[ 0 ] );
			ZGsupportInfo[ i ][ ZGsupportCreated ] = strval( arrCoords[ 1 ] );
			strmid( ZGsupportInfo[ i ][ ZGsupportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			ZGsupportInfo[ i ][ ZGsupportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			ZGsupportInfo[ i ][ ZGsupportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			ZGsupportInfo[ i ][ ZGsupportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );

			i++;
		}

		fclose(_h_handler);
	}

	return 1;
}





//=========================| GM PORT OSTALO |================================
forward SaveOSSports( );
public SaveOSSports( )
{
	if( fexist( F_OSSPORT ) )
	{
		fremove( F_OSSPORT );
	}
	new File:_h_handler = fopen( F_OSSPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_OSSPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", OSsupportInfo[ i ][ OSsupportID ], OSsupportInfo[ i ][ OSsupportCreated ], OSsupportInfo[ i ][ OSsupportName ], OSsupportInfo[ i ][ OSsupportPos ][ 0 ], OSsupportInfo[ i ][ OSsupportPos ][ 1 ], OSsupportInfo[ i ][ OSsupportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);

	return 1;
}
//------------------------------------------------------------------------------
forward LoadOSSports( );
public LoadOSSports( )
{
	if( fexist( F_OSSPORT ) )
	{
		new File:_h_handler = fopen( F_OSSPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			OSsupportInfo[ i ][ OSsupportID ] = strval( arrCoords[ 0 ] );
			OSsupportInfo[ i ][ OSsupportCreated ] = strval( arrCoords[ 1 ] );
			strmid( OSsupportInfo[ i ][ OSsupportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			OSsupportInfo[ i ][ OSsupportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			OSsupportInfo[ i ][ OSsupportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			OSsupportInfo[ i ][ OSsupportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );

			i++;
		}

		fclose(_h_handler);
	}

	return 1;
}








//------------------------| BG ADMIN PORT |------------------------------------
forward SaveBGAports( );
public SaveBGAports( )
{
	if( fexist( F_BGAPORT ) )
	{
		fremove( F_BGAPORT );
	}
	new File:_h_handler = fopen( F_BGAPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_BGAPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", AportBGInfo[ i ][ BGaportID ], AportBGInfo[ i ][ BGaportCreated ], AportBGInfo[ i ][ BGaportName ], AportBGInfo[ i ][ BGaportPos ][ 0 ], AportBGInfo[ i ][ BGaportPos ][ 1 ], AportBGInfo[ i ][ BGaportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);
	return 1;
}
//
forward LoadBGAports( );
public LoadBGAports( )
{
	if( fexist( F_BGAPORT ) )
	{
		new File:_h_handler = fopen( F_BGAPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			AportBGInfo[ i ][ BGaportID ] = strval( arrCoords[ 0 ] );
			AportBGInfo[ i ][ BGaportCreated ] = strval( arrCoords[ 1 ] );
			strmid( AportBGInfo[ i ][ BGaportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			AportBGInfo[ i ][ BGaportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			AportBGInfo[ i ][ BGaportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			AportBGInfo[ i ][ BGaportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );
			i++;
		}
		fclose(_h_handler);
	}
	return 1;
}



//------------------------| SA ADMIN PORT |------------------------------------
forward SaveSAAports( );
public SaveSAAports( )
{
	if( fexist( F_SAAPORT ) )
	{
		fremove( F_SAAPORT );
	}
	new File:_h_handler = fopen( F_SAAPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_SAAPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", AportSAInfo[ i ][ SAaportID ], AportSAInfo[ i ][ SAaportCreated ], AportSAInfo[ i ][ SAaportName ], AportSAInfo[ i ][ SAaportPos ][ 0 ], AportSAInfo[ i ][ SAaportPos ][ 1 ], AportSAInfo[ i ][ SAaportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);
	return 1;
}
//
forward LoadSAAports( );
public LoadSAAports( )
{
	if( fexist( F_SAAPORT ) )
	{
		new File:_h_handler = fopen( F_SAAPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			AportSAInfo[ i ][ SAaportID ] = strval( arrCoords[ 0 ] );
			AportSAInfo[ i ][ SAaportCreated ] = strval( arrCoords[ 1 ] );
			strmid( AportSAInfo[ i ][ SAaportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			AportSAInfo[ i ][ SAaportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			AportSAInfo[ i ][ SAaportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			AportSAInfo[ i ][ SAaportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );
			i++;
		}
		fclose(_h_handler);
	}
	return 1;
}

//------------------------| ZG ADMIN PORT |------------------------------------
forward SaveZGAports( );
public SaveZGAports( )
{
	if( fexist( F_ZGAPORT ) )
	{
		fremove( F_ZGAPORT );
	}
	new File:_h_handler = fopen( F_ZGAPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_ZGAPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", AportZGInfo[ i ][ ZGaportID ], AportZGInfo[ i ][ ZGaportCreated ], AportZGInfo[ i ][ ZGaportName ], AportZGInfo[ i ][ ZGaportPos ][ 0 ], AportZGInfo[ i ][ ZGaportPos ][ 1 ], AportZGInfo[ i ][ ZGaportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);
	return 1;
}
//
forward LoadZGAports( );
public LoadZGAports( )
{
	if( fexist( F_ZGAPORT ) )
	{
		new File:_h_handler = fopen( F_ZGAPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			AportZGInfo[ i ][ ZGaportID ] = strval( arrCoords[ 0 ] );
			AportZGInfo[ i ][ ZGaportCreated ] = strval( arrCoords[ 1 ] );
			strmid( AportZGInfo[ i ][ ZGaportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			AportZGInfo[ i ][ ZGaportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			AportZGInfo[ i ][ ZGaportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			AportZGInfo[ i ][ ZGaportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );
			i++;
		}
		fclose(_h_handler);
	}
	return 1;
}

//------------------------| OSTALO ADMIN PORT |------------------------------------
forward SaveOSAports( );
public SaveOSAports( )
{
	if( fexist( F_OSAPORT ) )
	{
		fremove( F_OSAPORT );
	}
	new File:_h_handler = fopen( F_OSAPORT, io_append ), _s_str[256];
	for( new i = 0; i < MAX_OSAPORTS; i++)
	{
		format(_s_str, sizeof(_s_str), "%d,%d,%s,%f,%f,%f\r\n", AportOSInfo[ i ][ OSaportID ], AportOSInfo[ i ][ OSaportCreated ], AportOSInfo[ i ][ OSaportName ], AportOSInfo[ i ][ OSaportPos ][ 0 ], AportOSInfo[ i ][ OSaportPos ][ 1 ], AportOSInfo[ i ][ OSaportPos ][ 2 ] );
		fwrite(_h_handler, _s_str);
	}
	fclose(_h_handler);
	return 1;
}
//
forward LoadOSAports( );
public LoadOSAports( )
{
	if( fexist( F_OSAPORT ) )
	{
		new File:_h_handler = fopen( F_OSAPORT, io_read ), _l_str[256], i = 0;
		new arrCoords[ 6 ][ 64 ];
		while( fread( _h_handler, _l_str ) )
		{
			split( _l_str, arrCoords, ',' );
			AportOSInfo[ i ][ OSaportID ] = strval( arrCoords[ 0 ] );
			AportOSInfo[ i ][ OSaportCreated ] = strval( arrCoords[ 1 ] );
			strmid( AportOSInfo[ i ][ OSaportName ], arrCoords[ 2 ], 0, strlen( arrCoords[ 2 ] ), 255);
			AportOSInfo[ i ][ OSaportPos ][ 0 ] = floatstr( arrCoords[ 3 ] );
			AportOSInfo[ i ][ OSaportPos ][ 1 ] = floatstr( arrCoords[ 4 ] );
			AportOSInfo[ i ][ OSaportPos ][ 2 ] = floatstr( arrCoords[ 5 ] );
			i++;
		}
		fclose(_h_handler);
	}
	return 1;
}


//------------------------------------------------------------------------------
public SaveFurniture( hid ) {
	new _h_str[28];
	format(_h_str, sizeof(_h_str), "Furniture/imovina_%03d.cfg", hid);

	if(fexist(_h_str)) {
		fremove(_h_str);
	}

	new File:_h_handler = fopen(_h_str, io_append), _s_str[256];

	for (new i = 0; i < MAX_X_OBJECTS; i++) {
		format(_s_str, sizeof(_s_str), "%d,%f,%f,%f,%f,%f,%f,%d\r\n", Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], Furniture[ hid ][ i ][ f_VW ] );
		fwrite(_h_handler, _s_str);
	}

	fclose(_h_handler);

	return 1;
}
public LoadFurniture( hid ) {
	new _h_str[28];
	format(_h_str, sizeof(_h_str), "Furniture/imovina_%03d.cfg", hid);

	if(fexist(_h_str)) {
		new File:_h_handler = fopen(_h_str, io_read), _l_str[256], i = 0;
		new arrCoords[ 8 ][ 64 ];
		while (fread(_h_handler, _l_str)) {
			split( _l_str, arrCoords, ',' );
			Furniture[ hid ][ i ][ f_Model ] = strval( arrCoords[ 0 ] );
			Furniture[ hid ][ i ][ f_X ] = floatstr( arrCoords[ 1 ] );
			Furniture[ hid ][ i ][ f_Y ] = floatstr( arrCoords[ 2 ] );
			Furniture[ hid ][ i ][ f_Z ] = floatstr( arrCoords[ 3 ] );
			Furniture[ hid ][ i ][ f_rX ] = floatstr( arrCoords[ 4 ] );
			Furniture[ hid ][ i ][ f_rY ] = floatstr( arrCoords[ 5 ] );
			Furniture[ hid ][ i ][ f_rZ ] = floatstr( arrCoords[ 6 ] );
			Furniture[ hid ][ i ][ f_VW ] = strval( arrCoords[ 7 ] );
			//sscanf(_l_str, "p<|>e<dffffffd>", Furniture[ hid ][ i ] );
			if(Furniture[ hid ][ i ][ f_Model ] ) {
				Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
			} else {
				Furniture[ hid ][ i ][ f_VW ] = 0;
				Furniture[ hid ][ i ][ f_X ] = 0.0;
				Furniture[ hid ][ i ][ f_Y ] = 0.0;
				Furniture[ hid ][ i ][ f_Z ] = 0.0;
				Furniture[ hid ][ i ][ f_rX ] = 0.0;
				Furniture[ hid ][ i ][ f_rY ] = 0.0;
				Furniture[ hid ][ i ][ f_rZ ] = 0.0;
			}

			i++;
		}

		fclose(_h_handler);
		SaveFurniture(hid);
	}

	return 1;
}
//------------------------------------------------------------------------------
forward RobZiceAtm( playerid );
public RobZiceAtm( playerid ) {

	if( playerid != IPI && PlayerLogged[ playerid ] && robbingATM[ playerid ] != -1 ) {
	
		if( robbingATM[ playerid ] == GetNearestAtm( playerid ) ) {

			new stringic[ 128 ];

			robbingATMSeconds[ playerid ]--;

			format( stringic, sizeof( stringic ), "~w~Ostani pored bankomata jos %d sec", robbingATMSeconds[ playerid ] );
			announcement( playerid, stringic, 1000, 1 );
			
			if( robbingATMSeconds[ playerid ] == 0 ) {
			
				Dimi_KillTimer( atmrobTimer[ playerid ] );

				//new brojcina = random(10);

				robbingATMSeconds[ playerid ] = 95;
				/*if( brojcina <= 4 ) {
					atmTDControl( playerid, false );
					PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );

					atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
					SacuvajATM( robbingATM[ playerid ] );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 60;
						
					SendInfoMessage( playerid, "Isekli ste pogresnu zicu i oglasili alarm." );
				}
				else if( brojcina >= 6 ) {
		
					SelectTextDraw( playerid, UGBOJA );

					atmInfo[ robbingATM[ playerid ] ][ atmPreseceneZice ] = true;
					SacuvajATM( robbingATM[ playerid ] );

					SendInfoMessage( playerid, "Uspjesno ste srusili odbrambeni sistem.");
					SendInfoMessage( playerid, "Sada mozete ukrasti novac iz bankomata.");
				}*/
				PostaviWanted( playerid, "Pljacka bankomata", "Sistem", 3 );

				atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
				SacuvajATM( robbingATM[ playerid ] );
				PlayerInfo[ playerid ][ xPljackaVreme ] = 60;
				SelectTextDraw( playerid, UGBOJA );

				atmInfo[ robbingATM[ playerid ] ][ atmPreseceneZice ] = true;
				SacuvajATM( robbingATM[ playerid ] );

				SendInfoMessage( playerid, "Uspjesno ste srusili odbrambeni sistem.");
				SendInfoMessage( playerid, "Sada mozete ukrasti novac iz bankomata.");

			}
		}
		else {

			Dimi_KillTimer( atmrobTimer[ playerid ] );

			PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );
			atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
			SacuvajATM( robbingATM[ playerid ] );
			PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

			robbingATM[ playerid ] = -1;
			robbingATMSeconds[ playerid ] = 95;
			SendInfoMessage( playerid, "Pomerili ste se od bankomata i probijanje istog je prekinuto." );
		}
	}
}
//------------------------------------------------------------------------------
/*forward ProgresAtmBar( playerid );
public ProgresAtmBar( playerid ) {
	if( robbingATM[ playerid ] == GetNearestAtm( playerid ) ) {
		new Float:Value = GetPlayerProgressBarValue( playerid, playeratmBar[ playerid ] );
		if( Value != 100 ) {
			SetPlayerProgressBarValue( playerid, playeratmBar[ playerid ], Value+1 );

			new stringic[ 5 ];
			format( stringic, sizeof( stringic ), "%d%", floatround( Value+1 ) );
			PlayerTextDrawSetString( playerid, atmrobLoading[ playerid ][ 1 ], stringic );

			atmrobTimer[ playerid ] = SetTimerEx( "ProgresAtmBar", 1000, false, "d", playerid );
		}
		else if( Value == 100 ) {
			if( LaptopRuke[ playerid ] ) {
				SelectTextDraw( playerid, UGBOJA );
				Dimi_KillTimer( atmrobTimer[ playerid ] );
				atmLoadingTDControl( playerid, false );

				HidePlayerProgressBar(playerid, playeratmBar[ playerid ] );
				DestroyPlayerProgressBar(playerid, playeratmBar[ playerid ] );
				playeratmBar[ playerid ] = PlayerBar:INVALID_PLAYER_BAR_ID;

				atmInfo[ robbingATM[ playerid ] ][ atmProbijenBios ] = true;
				SacuvajATM( robbingATM[ playerid ] );

				SendInfoMessage( playerid, "Uspesno ste srusili odbrambeni sistem.");
				SendInfoMessage( playerid, "Sada mozete prebaciti novac na vas racun.");

				robbingATM[ playerid ] = -1;
			}
			else {
				atmTDControl( playerid, false );

				Dimi_KillTimer( atmrobTimer[ playerid ] );
				atmLoadingTDControl( playerid, false );

				HidePlayerProgressBar(playerid, playeratmBar[ playerid ] );
				DestroyPlayerProgressBar(playerid, playeratmBar[ playerid ] );
				playeratmBar[ playerid ] = PlayerBar:INVALID_PLAYER_BAR_ID;

				PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );

				atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
				SacuvajATM( robbingATM[ playerid ] );
				PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

				robbingATM[ playerid ] = -1;

				SendInfoMessage( playerid, "Nemate laptop u rukama i prekunuta vam je pljacka." );
			}
		}
	}
	else { 
		atmTDControl( playerid, false );
		
		Dimi_KillTimer( atmrobTimer[ playerid ] );
		atmLoadingTDControl( playerid, false );

		HidePlayerProgressBar(playerid, playeratmBar[ playerid ] );
		DestroyPlayerProgressBar(playerid, playeratmBar[ playerid ] );
		playeratmBar[ playerid ] = PlayerBar:INVALID_PLAYER_BAR_ID;
		
		PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );
		
		atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
		SacuvajATM( robbingATM[ playerid ] );
		PlayerInfo[ playerid ][ xPljackaVreme ] = 60;
		
		robbingATM[ playerid ] = -1;
		
		SendInfoMessage( playerid, "Pomerili ste se od bankomata i vase hakovanje istog je prekinuto." );
	}
}*/
forward ProgresAtmBar( playerid );
public ProgresAtmBar( playerid ) {
	if( playerid != IPI && PlayerLogged[ playerid ] && robbingATM[ playerid ] != -1 ) {

		if( robbingATM[ playerid ] == GetNearestAtm( playerid ) ) {

			new stringic[ 128 ];

			robbingATMSeconds[ playerid ]--;

			atmrobTimer[ playerid ] = SetTimerEx( "ProgresAtmBar", 1000, false, "d", playerid );

			format( stringic, sizeof( stringic ), "~w~Ostani pored bankomata jos %d sec", robbingATMSeconds[ playerid ] );
			announcement( playerid, stringic, 1000, 1 );

			if( robbingATMSeconds[ playerid ] == 0 ) {

				Dimi_KillTimer( atmrobTimer[ playerid ] );

				//new brojcina = random(10);

				robbingATMSeconds[ playerid ] = 95;
				/*if( brojcina < 2 ) {
					atmTDControl( playerid, false );
					PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );

					atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
					SacuvajATM( robbingATM[ playerid ] );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

					SendInfoMessage( playerid, "Prilikom hakovanja ste unijeli pogresnu komandu u programu i oglasili alarm!" );
				}
				else if( brojcina == 2 ) {
					atmTDControl( playerid, false );
					PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );

					atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
					SacuvajATM( robbingATM[ playerid ] );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

					SendInfoMessage( playerid, "Prilikom hakovanja ste unijeli pogresnu komandu u programu i oglasili alarm!" );
				}
				else if( brojcina >= 8 ) {

					SelectTextDraw( playerid, UGBOJA );

					atmInfo[ robbingATM[ playerid ] ][ atmProbijenBios ] = true;
					SacuvajATM( robbingATM[ playerid ] );

					SendInfoMessage( playerid, "Uspjesno ste srusili odbrambeni sistem.");
					SendInfoMessage( playerid, "Sada mozete ukrasti novac iz bankomata.");
				}*/
				PostaviWanted( playerid, "Pljacka bankomata", "Sistem", 3 );

				atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
				SacuvajATM( robbingATM[ playerid ] );
				PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

				SelectTextDraw( playerid, UGBOJA );

				atmInfo[ robbingATM[ playerid ] ][ atmProbijenBios ] = true;
				SacuvajATM( robbingATM[ playerid ] );

				SendInfoMessage( playerid, "Uspjesno ste srusili odbrambeni sistem.");
				SendInfoMessage( playerid, "Sada mozete ukrasti novac iz bankomata.");
			}
		}
		else {

			Dimi_KillTimer( atmrobTimer[ playerid ] );

			PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );
			atmInfo[ robbingATM[ playerid ] ][ atmVremeDoRoba ] = 60;
			SacuvajATM( robbingATM[ playerid ] );
			PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

			robbingATM[ playerid ] = -1;
			robbingATMSeconds[ playerid ] = 95;
			SendInfoMessage( playerid, "Pomerili ste se od bankomata i vase hakovanje istog je prekinuto." );
		}
	}
}
//------------------------------------------------------------------------------
OnPlayerJoinPUBG(playerid); public OnPlayerJoinPUBG(playerid)
{
	LoginTDControl(playerid, false);
	PUBGenum[xCekaIgraca]++;
	//PUBGTDControl(playerid, false);
	PlayerInfo[playerid][xPUBG] = 1;
	SetPlayerVirtualWorld(playerid,pubg_server);
	PlayerInfo[playerid][xSkocio] = 0;
	Dimi_SetPlayerPos(playerid,-307.8986,1527.4154,79.3594);
	announcement(playerid,"Povezivanje...");
	announcetimer[playerid] = SetTimerEx("announce", 5000, false, "i", playerid);
	FadeFromBlack(playerid);
	for(new i = 0; i < 50; i++)
	{
		SendClientMessage(playerid,-1, "");
	}
	SendInfoMessage(playerid, "Sada ste povezani na PUBG virtualni server.");
	SendInfoMessage(playerid, "Necete moci vidjeti ostale igrace i vozila koja nisu na PUBG-u.");
	SendInfoMessage(playerid, "Da se iskljucite: /izadjisapubg");
	return 1;
}
//------------------------------------------------------------------------------
//opctd
public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if( _:clickedid != INVALID_TEXT_DRAW )
	{
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 10.0);
		CallLocalFunction("OnPlayerClickEditingMenu", "ii", playerid, _:clickedid);

		if(clickedid == ClientSelection[3])//pc
		{
			ClientSelectControl(playerid, false);
			ClientType[playerid] = CLIENT_PC;
			SendScreenMessage(playerid, "Odabrali ste PC client!");
			SetTimerEx("LogRegSelectionTimer", 2000, false, "ii", playerid, 0);
			ShowLoadingTextdraws(playerid, true, 2800);
		}
		if(clickedid == ClientSelection[4])//mobile
		{
			ClientSelectControl(playerid, false);
			ClientType[playerid] = CLIENT_MOBILE;
			SendScreenMessage(playerid, "Odabrali ste mobile client!");
			SetTimerEx("LogRegSelectionTimer", 2000, false, "ii", playerid, 0);
			ShowLoadingTextdraws(playerid, true, 2800);
		}
		if(clickedid == LogRegSelection[3])//login
		{
			if(AccPostoji[playerid] == 0) return SendScreenMessage(playerid, "Racun sa ovim imenom nije pronadjen. Registrujte se!");
			LogRegSelectControl(playerid, false);
			INI_ParseFile( Korisnici( playerid ), "OcitajKorisnika", .bExtra = true, .extra = playerid);

			if( PlayerInfo[ playerid ][ xRegistrovan ] == 1 )
			{
				ShowLoadingTextdraws(playerid, true, 2000);
				SetTimerEx( "Login", 3000, false, "d", playerid );
			}
			else
			{
			
				if( ServerInfo[ Registracija ] == false )
				{
					announcement(playerid, "Registracija je trenutno onemogucena");
					SetTimerEx( "KickIgraca", 150, false, "d", playerid );
					return 1;
				}
				ShowLoadingTextdraws(playerid, true, 2000);
				SetTimerEx( "Register", 3000, false, "d", playerid );
			}
		}
		if(clickedid == LogRegSelection[4])//register
		{
			if(AccPostoji[playerid] == 1) return SendScreenMessage(playerid, "Racun sa ovim imenom je pronadjen. Ulogujte se!");
			LogRegSelectControl(playerid, false);
			if( !IsValidRoleplayName( ImeIgraca( playerid ) ) )
			{
				announcement(playerid, "Vase ime je neispravno");
				SetTimerEx( "KickIgraca", 150, false, "d", playerid );
				return 1;
			}
		
			if( ServerInfo[ Registracija ] == false )
			{

				announcement(playerid, "Registracija je trenutno onemogucena");
				SetTimerEx( "KickIgraca", 150, false, "d", playerid );
				return 1;
			}
			ShowLoadingTextdraws(playerid, true, 2000);
			SetTimerEx( "Register", 3000, false, "d", playerid );
		}
		if( clickedid == gamemodetd[6])
		{
			announcement(playerid, "Onaj game mode koji selektujete~n~ovjde ce se pokrenuti nakon~n~sto kliknete ''Play''");
		}
		if( clickedid == gamemodetd[1])
		{
			PlayerTextDrawHide(playerid, p_gamemodetd[0][playerid]);
			PlayerTextDrawDestroy(playerid, p_gamemodetd[0][playerid]);
			hidegmtd(playerid);

			/*OruzjeIgraca1[playerid] = CreatePlayerTextDraw(playerid,501.333343, 28.871110, "");
			PlayerTextDrawTextSize(playerid,OruzjeIgraca1[playerid], 40.000030, 35.840003);
			PlayerTextDrawAlignment(playerid,OruzjeIgraca1[playerid], 0);
			PlayerTextDrawBackgroundColor(playerid,OruzjeIgraca1[playerid], 0xFFFFFFFF00);
			PlayerTextDrawSetShadow(playerid,OruzjeIgraca1[playerid], 0);
			PlayerTextDrawFont(playerid,OruzjeIgraca1[playerid], 5);
			PlayerTextDrawSetProportional(playerid,OruzjeIgraca1[playerid], 0);
			PlayerTextDrawSetPreviewModel(playerid,OruzjeIgraca1[playerid], 294);
			PlayerTextDrawSetPreviewRot(playerid,OruzjeIgraca1[playerid], 0.000000, 0.000000, 0.000000, 1.000000);
			PlayerTextDrawSetSelectable(playerid,OruzjeIgraca1[playerid], true);*/
			if( PlayerInfo[playerid][xGamemode] == 0)
			{
				//PUBGTDControl(playerid, false);
				LoginTDControl(playerid, false);

				new aastring[64];
				format( aastring, sizeof( aastring ), A_FILE, ImeIgraca( playerid ) );
				if( PlayerInfo[ playerid ][ xAdmin ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije administratora!" );
					fremove( aastring );
				}
				if( PlayerInfo[ playerid ][ xHelper ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije helpera." );
					fremove( aastring );
				}

				if( fexist( Admini( playerid ) ) ) INI_ParseFile( Admini( playerid ), "OcitajAdmina", .bExtra = true, .extra = playerid );

				if( fexist( Inventory( playerid ) ) ) INI_ParseFile( Inventory( playerid ), "LoadInventory", .bExtra = true, .extra = playerid );

				#if kladionica == 1
				INI_ParseFile( KladIme( playerid ), "LoadKladionica", .bExtra = true, .extra = playerid );
				#endif

				LoginTDControl( playerid, false );
				CancelSelectTextDraw( playerid );

				new datum[ 64 ]; new year, month,day;
				getdate( year, month, day );
				new tmphour, tmpminute, tmpsecond;
				gettimeEx( tmphour, tmpminute, tmpsecond );
				FixHour( tmphour );
				tmphour = shifthour;
				format( datum, sizeof( datum ), "%02d/%02d/%d - %d/%d/%d", day, month, year, tmphour, tmpminute, tmpsecond );
				strmid( PlayerInfo[ playerid ][ xLastLogin ], datum, 0, strlen( datum ), 64 );
				
				if( PlayerInfo[ playerid ][ xFirmaID ] != -1 ) {
				
					BussinesInfo[ PlayerInfo[ playerid ][ xFirmaID ] ][ bNeaktivnost ] = 0;
					SaveBussines( PlayerInfo[ playerid ][ xFirmaID ] );
				}
				
				if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {
				
					II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 2 ] );
				}

				if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] );
				}

				new banfile[ 100 ]; format( banfile, sizeof( banfile ), FILE_BAN, ImeIgraca( playerid ) );
				if( fexist( banfile ) ) {
					new File: UserFile = fopen( banfile, io_read );
					new razlogbana[ 128 ] = "Nepoznat";
					new key[256];
					new Data[256];
					while ( fread( UserFile , Data, sizeof( Data ) ) ) {
						key = ini_GetKey( Data );
						if( strcmp( key , "Razlog" , true ) == 0 ) {
							format( razlogbana, strlen( ini_GetValue ( Data ) ), "%s", ini_GetValue( Data ) );
						}
					}
					fclose( UserFile );
					getdate( year, month, day );

					SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Vas racun je trenutno iskljucen sa servera! Izbaceni ste!" );
					format( globalstring, sizeof( globalstring ), "Razlog bana: %s", razlogbana );
					SendClientMessage( playerid, BELA, globalstring );
					format( globalstring, sizeof( globalstring ), "Vas server nick: %s, Danasnji datum: %d.%d.%d", ImeIgraca( playerid ), day, month, year );
					SendClientMessage( playerid, ZUTA, globalstring );
					Dimi_Kick( playerid );
					return 1;
				}

				if( PlayerInfo[ playerid ][ xPocetniTut ] == 0 ) {
					TogglePlayerSpectating( playerid, 1 );
					InterpolateCameraPos(playerid, 374.912872, -1113.013427, 124.437553, 2345.744384, -2112.316162, 98.540664, 50000);
					InterpolateCameraLookAt(playerid, 379.372039, -1115.274536, 124.378959, 2343.739257, -2107.836425, 97.585632,1);
					SetPlayerInterior( playerid, 0 );
					SetPlayerVirtualWorld( playerid, 1 );
					Dimi_SetPlayerPos( playerid, 1463.7633,-1041.4501,26.8281);
					SendClientMessage(playerid,-1, "");//dobrodoslica UBACENOOO
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					TutorijalTDControl(playerid, 0);
					TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 35000, false, "ii", playerid, 1 );
					PocetniTutorialStartovan[ playerid ] = true;
				}
				else {
				
					aliasLogin( playerid );
				
					if( fexist( Inventory( playerid ) ) ) ProveriInvOruzje[ playerid ] = SetTimerEx( "ProveraInvOruzja", 10, false, "dd", playerid, 0 );
				
					Dimi_SetSpawnInfo( playerid );
					TogglePlayerSpectating( playerid, 0);
					SpawnPlayer( playerid ); PlayerLogged[ playerid ] = true;
					antiCheatCS[ playerid ][ TeleportCheck ] = 4;
					antiCheatCS[ playerid ][ WeaponDetect ] = 4;

					
					for( new i = 0; i < 52; i ++)
					{
						TextDrawShowForPlayer( playerid, TDEditor_TD[ i ] );
					}
					/*for( new i = 0; i < 15; i ++)
					{
						TextDrawShowForPlayer( playerid, GPSIGTD[ i ] );
					}*/
					//showhjhh(playerid);
					
					TextDrawShowForPlayer( playerid, GladTDPizza);
					TextDrawShowForPlayer( playerid, WcTDSolja);
					if( PlayerInfo[ playerid ][ xPol ] == 0 ) PlayerInfo[ playerid ][ xPol ] = 1;
					
					//CreatePlayerVehicles( playerid );
					SetPlayerVirtualWorld( playerid, 0 );
					
					DonatorBoja( playerid );
					
					ResetAllWeapons( playerid );
					
					new playersip[ 128 ];
					GetPlayerIp( playerid, playersip, sizeof( playersip ) );
					
					format( globalstring, sizeof( globalstring ), ""col_balkanstory"CONNECT | {ffffff}Korisnik: %s | [ID:%d] | [LVL:%d] | se prijavio na server! (gamemode: ROLEPLAY)", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ]);
					AdminPoruka( ZUTA, globalstring );//jebise
				}
				return 1;
			}
			if( PlayerInfo[playerid][xGamemode] == 1) // DEATHMATCH
			{
				//PUBGTDControl(playerid, false);

				new aastring[64];
				format( aastring, sizeof( aastring ), A_FILE, ImeIgraca( playerid ) );
				if( PlayerInfo[ playerid ][ xAdmin ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije administratora!" );
					fremove( aastring );
				}
				if( PlayerInfo[ playerid ][ xHelper ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije helpera." );
					fremove( aastring );
				}

				if( fexist( Admini( playerid ) ) ) INI_ParseFile( Admini( playerid ), "OcitajAdmina", .bExtra = true, .extra = playerid );

				if( fexist( Inventory( playerid ) ) ) INI_ParseFile( Inventory( playerid ), "LoadInventory", .bExtra = true, .extra = playerid );

				#if kladionica == 1
				INI_ParseFile( KladIme( playerid ), "LoadKladionica", .bExtra = true, .extra = playerid );
				#endif

				LoginTDControl( playerid, false );
				CancelSelectTextDraw( playerid );

				new datum[ 64 ]; new year, month,day;
				getdate( year, month, day );
				new tmphour, tmpminute, tmpsecond;
				gettimeEx( tmphour, tmpminute, tmpsecond );
				FixHour( tmphour );
				tmphour = shifthour;
				format( datum, sizeof( datum ), "%02d/%02d/%d - %d/%d/%d", day, month, year, tmphour, tmpminute, tmpsecond );
				strmid( PlayerInfo[ playerid ][ xLastLogin ], datum, 0, strlen( datum ), 64 );
				
				if( PlayerInfo[ playerid ][ xFirmaID ] != -1 ) {
				
					BussinesInfo[ PlayerInfo[ playerid ][ xFirmaID ] ][ bNeaktivnost ] = 0;
					SaveBussines( PlayerInfo[ playerid ][ xFirmaID ] );
				}
				
				if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {
				
					II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 2 ] );
				}

				if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] );
				}

				/*new banfile[ 100 ]; format( banfile, sizeof( banfile ), FILE_BAN, ImeIgraca( playerid ) );
				if( fexist( banfile ) ) {
					new File: UserFile = fopen( banfile, io_read );
					new razlogbana[ 128 ] = "Nepoznat";
					new key[256];
					new Data[256];
					while ( fread( UserFile , Data, sizeof( Data ) ) ) {
						key = ini_GetKey( Data );
						if( strcmp( key , "Razlog" , true ) == 0 ) {
							format( razlogbana, strlen( ini_GetValue ( Data ) ), "%s", ini_GetValue( Data ) );
						}
					}
					fclose( UserFile );
					getdate( year, month, day );

					SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Vas racun je trenutno iskljucen sa servera! Izbaceni ste!" );
					format( globalstring, sizeof( globalstring ), "Razlog bana: %s", razlogbana );
					SendClientMessage( playerid, BELA, globalstring );
					format( globalstring, sizeof( globalstring ), "Vas server nick: %s, Danasnji datum: %d.%d.%d", ImeIgraca( playerid ), day, month, year );
					SendClientMessage( playerid, ZUTA, globalstring );
					Dimi_Kick( playerid );
					return 1;
				}*/

				if( PlayerInfo[ playerid ][ xPocetniTut ] == 0 ) {
					TogglePlayerSpectating( playerid, 1 );
					InterpolateCameraPos(playerid, 374.912872, -1113.013427, 124.437553, 2345.744384, -2112.316162, 98.540664, 50000);
					InterpolateCameraLookAt(playerid, 379.372039, -1115.274536, 124.378959, 2343.739257, -2107.836425, 97.585632,1);
					SetPlayerInterior( playerid, 0 );
					SetPlayerVirtualWorld( playerid, 1 );
					Dimi_SetPlayerPos( playerid, 1463.7633,-1041.4501,26.8281);
					SendClientMessage(playerid,-1, "");//dobrodoslica UBACENOOO
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					TutorijalTDControl(playerid, 0);
					TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 35000, false, "ii", playerid, 1 );
					PocetniTutorialStartovan[ playerid ] = true;
				}
				else {
				
					aliasLogin( playerid );
				
					if( fexist( Inventory( playerid ) ) ) ProveriInvOruzje[ playerid ] = SetTimerEx( "ProveraInvOruzja", 10, false, "dd", playerid, 0 );
				
					Dimi_SetSpawnInfo( playerid );
					TogglePlayerSpectating( playerid, 0);
					SpawnPlayer( playerid ); PlayerLogged[ playerid ] = true;
					antiCheatCS[ playerid ][ TeleportCheck ] = 4;
					antiCheatCS[ playerid ][ WeaponDetect ] = 4;

					
					for( new i = 0; i < 52; i ++)
					{
						TextDrawShowForPlayer( playerid, TDEditor_TD[ i ] );
					}
					/*for( new i = 0; i < 15; i ++)
					{
						TextDrawShowForPlayer( playerid, GPSIGTD[ i ] );
					}*/
					//showhjhh(playerid);
					
					TextDrawShowForPlayer( playerid, GladTDPizza);
					TextDrawShowForPlayer( playerid, WcTDSolja);
					if( PlayerInfo[ playerid ][ xPol ] == 0 ) PlayerInfo[ playerid ][ xPol ] = 1;
					
					//CreatePlayerVehicles( playerid );
					SetPlayerVirtualWorld( playerid, 0 );
					
					DonatorBoja( playerid );
					
					ResetAllWeapons( playerid );
					
					new playersip[ 128 ];
					GetPlayerIp( playerid, playersip, sizeof( playersip ) );
					
					format( globalstring, sizeof( globalstring ), ""col_balkanstory"CONNECT | {ffffff}Korisnik: %s | [ID:%d] | [LVL:%d] | se prijavio na server! (GAMEMODE: DEATHMATCH)", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ]);
					AdminPoruka( ZUTA, globalstring );//jebise
				}
				NaDmEventu[ playerid ] = true;
				new rand = random( sizeof( RandomDMPos ) );
				Dimi_SetPlayerPos( playerid, RandomDMPos[ rand ][ 0 ], RandomDMPos[ rand ][ 1 ],RandomDMPos[ rand ][ 2 ] );
				SetPlayerFacingAngle( playerid, 360.000 );
				SetCameraBehindPlayer( playerid );
				SetPlayerInterior( playerid, 0 );
				SetPlayerVirtualWorld( playerid, 10 );
				Dimi_SetPlayerHealth( playerid, 100 );
				Dimi_SetPlayerArmour( playerid, 100 );
				
				if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 4500 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 10." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 26, 150 );
					GiveWeaponToPlayer( playerid, 28, 400 );
					GiveWeaponToPlayer( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 4000 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 9." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 27, 150 );
					GiveWeaponToPlayer( playerid, 32, 800 );
					GiveWeaponToPlayer( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 3500 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 8." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 27, 150 );
					GiveWeaponToPlayer( playerid, 28, 800 );
					GiveWeaponToPlayer( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 3000 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 7." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 27, 150 );
					GiveWeaponToPlayer( playerid, 29, 400 );
					GiveWeaponToPlayer( playerid, 31, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 2500 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 6." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 26, 150 );
					GiveWeaponToPlayer( playerid, 29, 400 );
					GiveWeaponToPlayer( playerid, 31, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 2000 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 5." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 26, 150 );
					GiveWeaponToPlayer( playerid, 29, 400 );
					GiveWeaponToPlayer( playerid, 30, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 1500 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 4." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 25, 100 );
					GiveWeaponToPlayer( playerid, 29, 400 );
					GiveWeaponToPlayer( playerid, 31, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 1000 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 3." );
					GiveWeaponToPlayer( playerid, 24, 150 );
					GiveWeaponToPlayer( playerid, 25, 100 );
					GiveWeaponToPlayer( playerid, 29, 400 );
					GiveWeaponToPlayer( playerid, 30, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 500 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 2." );
					GiveWeaponToPlayer( playerid, 24, 200 );
					GiveWeaponToPlayer( playerid, 25, 100 );
					GiveWeaponToPlayer( playerid, 29, 400 );
				}
				else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 0 )
				{
					SendInfoMessage( playerid, "Usao si na DM sa rankom 1." );
					GiveWeaponToPlayer( playerid, 24, 200 );
					GiveWeaponToPlayer( playerid, 25, 100 );
				}
				SendInfoMessage( playerid, "Da izadjes iz DM zone kucaj /izadjizidm." );
				showdmtd(playerid);
				return 1;
			}
			if( PlayerInfo[playerid][xGamemode] == 2) // PUBG EVENT
			{
				//PUBGTDControl(playerid, false);
				new aastring[64];
				format( aastring, sizeof( aastring ), A_FILE, ImeIgraca( playerid ) );
				if( PlayerInfo[ playerid ][ xAdmin ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije administratora!" );
					fremove( aastring );
				}
				if( PlayerInfo[ playerid ][ xHelper ] == 0 && fexist( aastring ) ) {
					SendClientMessagee( playerid, -1, "Smenjen si sa pozicije helpera." );
					fremove( aastring );
				}

				if( fexist( Admini( playerid ) ) ) INI_ParseFile( Admini( playerid ), "OcitajAdmina", .bExtra = true, .extra = playerid );

				if( fexist( Inventory( playerid ) ) ) INI_ParseFile( Inventory( playerid ), "LoadInventory", .bExtra = true, .extra = playerid );

				#if kladionica == 1
				INI_ParseFile( KladIme( playerid ), "LoadKladionica", .bExtra = true, .extra = playerid );
				#endif

				LoginTDControl( playerid, true );
				CancelSelectTextDraw( playerid );

				new datum[ 64 ]; new year, month,day;
				getdate( year, month, day );
				new tmphour, tmpminute, tmpsecond;
				gettimeEx( tmphour, tmpminute, tmpsecond );
				FixHour( tmphour );
				tmphour = shifthour;
				format( datum, sizeof( datum ), "%02d/%02d/%d - %d/%d/%d", day, month, year, tmphour, tmpminute, tmpsecond );
				strmid( PlayerInfo[ playerid ][ xLastLogin ], datum, 0, strlen( datum ), 64 );
				
				if( PlayerInfo[ playerid ][ xFirmaID ] != -1 ) {
				
					BussinesInfo[ PlayerInfo[ playerid ][ xFirmaID ] ][ bNeaktivnost ] = 0;
					SaveBussines( PlayerInfo[ playerid ][ xFirmaID ] );
				}
				
				if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {

					II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {
				
					II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iNeaktivnost ] = 0;
					SaveProperty( PlayerInfo[ playerid ][ xProperty ][ 2 ] );
				}

				if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] );
				}
				if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 ) {

					VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vNeaktivnost ] = 0;
					SaveVehicle( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] );
				}

				/*new banfile[ 100 ]; format( banfile, sizeof( banfile ), FILE_BAN, ImeIgraca( playerid ) );
				if( fexist( banfile ) ) {
					new File: UserFile = fopen( banfile, io_read );
					new razlogbana[ 128 ] = "Nepoznat";
					new key[256];
					new Data[256];
					while ( fread( UserFile , Data, sizeof( Data ) ) ) {
						key = ini_GetKey( Data );
						if( strcmp( key , "Razlog" , true ) == 0 ) {
							format( razlogbana, strlen( ini_GetValue ( Data ) ), "%s", ini_GetValue( Data ) );
						}
					}
					fclose( UserFile );
					getdate( year, month, day );

					SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Vas racun je trenutno iskljucen sa servera! Izbaceni ste!" );
					format( globalstring, sizeof( globalstring ), "Razlog bana: %s", razlogbana );
					SendClientMessage( playerid, BELA, globalstring );
					format( globalstring, sizeof( globalstring ), "Vas server nick: %s, Danasnji datum: %d.%d.%d", ImeIgraca( playerid ), day, month, year );
					SendClientMessage( playerid, ZUTA, globalstring );
					Dimi_Kick( playerid );
					return 1;
				}*/

				if( PlayerInfo[ playerid ][ xPocetniTut ] == 0 ) {
					TogglePlayerSpectating( playerid, 1 );
					InterpolateCameraPos(playerid, 374.912872, -1113.013427, 124.437553, 2345.744384, -2112.316162, 98.540664, 50000);
					InterpolateCameraLookAt(playerid, 379.372039, -1115.274536, 124.378959, 2343.739257, -2107.836425, 97.585632,1);
					SetPlayerInterior( playerid, 0 );
					SetPlayerVirtualWorld( playerid, 1 );
					Dimi_SetPlayerPos( playerid, 1463.7633,-1041.4501,26.8281);
					SendClientMessage(playerid,-1, "");//dobrodoslica UBACENOOO
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					SendClientMessage(playerid,-1, "");
					TutorijalTDControl(playerid, 0);
					TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 35000, false, "ii", playerid, 1 );
					PocetniTutorialStartovan[ playerid ] = true;
				}
				else {
				
					aliasLogin( playerid );
				
					if( fexist( Inventory( playerid ) ) ) ProveriInvOruzje[ playerid ] = SetTimerEx( "ProveraInvOruzja", 10, false, "dd", playerid, 0 );
				
					//Dimi_SetSpawnInfo( playerid );
					TogglePlayerSpectating( playerid, 0);
					//SpawnPlayer( playerid ); 
					PlayerLogged[ playerid ] = true;
					antiCheatCS[ playerid ][ TeleportCheck ] = 4;
					antiCheatCS[ playerid ][ WeaponDetect ] = 4;
					
					TextDrawShowForPlayer( playerid, GladTDPizza);
					TextDrawShowForPlayer( playerid, WcTDSolja);
					if( PlayerInfo[ playerid ][ xPol ] == 0 ) PlayerInfo[ playerid ][ xPol ] = 1;
					
					SetPlayerVirtualWorld(playerid,pubg_server);
					TogglePlayerSpectating(playerid, true);
					DonatorBoja( playerid );
					
					ResetAllWeapons( playerid );
					
					new playersip[ 128 ];
					GetPlayerIp( playerid, playersip, sizeof( playersip ) );
					
					format( globalstring, sizeof( globalstring ), ""col_balkanstory"CONNECT | {ffffff}Korisnik: %s | [ID:%d] | [LVL:%d] | se prijavio na server! (GAMEMODE: PUBG)", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ]);
					AdminPoruka( ZUTA, globalstring );//jebise
				}
				//show pubg tds
				if(PUBGenum[xPokrenut] == 0)
				{
					//if(PUBGenum[xCekaIgraca] == PUBGenum[xTrebaIgraca]) return greska(playerid,"Match je vec napunjen.");
					//if(PlayerInfo[playerid][xAdmin] < 1339) return greska(playerid,"Niste ovlasteni da palite PUBG event.");
					//if(PUBGenum[xPokrenut] == 1) return greska(playerid,"PUBG je vec pokrenut od strane nekog administratora!");
					if(PUBGenum[xPoceoMatch] == 1) return greska(playerid,"PUBG match trenutno traje.");
					if(PlayerInfo[playerid][xPUBG] == 1) return greska(playerid,"Ti si vec na PUBG eventu!");
					if(NaDmEventu[ playerid ] == true) return greska(playerid, "Ti si na DeathMatch eventu - prvo izadji sa DeathMatcha");
					if(PUBGenum[xZapocetoUcitavanje] == 1) return greska(playerid, "Sacekaj nekoliko sekundi pa pokusaj ponovo!");
					new pubg_event_announce[300], broj_potrebnih_igraca = 10;
					format(pubg_event_announce,sizeof(pubg_event_announce),""col_balkanstory"[ PUBG EVENT ]{ffffff}: Admin %s je upravo pokrece PUBG event - molimo sacekajte...",ImeIgraca(playerid),broj_potrebnih_igraca);
					PUBGenum[xTrebaIgraca] = broj_potrebnih_igraca;
					SCMA(-1,""col_balkanstory"[ PUBG EVENT ]{ffffff}: Zapoceto je ucitavanje komponenti igre...");
					RemovePUBGVehicles();
					RemovePUBGLoot();
					PUBGenum[xZapocetoUcitavanje] = 1;
					pubg_srw = SetTimerEx("ucitavanje_pubg",2000,false,"si",ImeIgraca(playerid),broj_potrebnih_igraca);
					//pubgstat_timer = SetTimer("pubgtdupdate", 1000, true);
					announcement(playerid,"Biti cete povezani~n~na PUBG za 5s.");
					SetTimerEx("OnPlayerJoinPUBG", 5000, false, "i", playerid);
				}
				if(PUBGenum[xPokrenut] == 1)
				{
					//if(PUBGenum[xPokrenut] == 0) return greska(playerid,"PUBG event nije pokrenut ili match trenutno traje.");
					if(PUBGenum[xCekaIgraca] == PUBGenum[xTrebaIgraca]) return greska(playerid,"Match je vec napunjen.");
					if(PlayerInfo[playerid][xPUBG] == 1) return greska(playerid,"Ti si vec na PUBG eventu!");
					if(NaDmEventu[ playerid ] == true) return greska(playerid, "Ti si na DeathMatch eventu - prvo izadji sa DeathMatcha");
					PUBGenum[xCekaIgraca]++;
					PlayerInfo[playerid][xPUBG] = 1;
					SetPlayerVirtualWorld(playerid,pubg_server);
					PlayerInfo[playerid][xSkocio] = 0;
					PlayerInfo[playerid][xPUBGKills] = 0;
					Dimi_SetPlayerPos(playerid,-307.8986,1527.4154,79.3594);
					announcement(playerid,"Povezivanje...");
					announcetimer[playerid] = SetTimerEx("announce", 5000, false, "i", playerid);
					FadeFromBlack(playerid);
					for(new i = 0; i < 50; i++)
					{
						SendClientMessage(playerid,-1, "");
					}
					SendInfoMessage(playerid, "Sada ste povezani na PUBG virtualni server.");
					SendInfoMessage(playerid, "Necete moci vidjeti ostale igrace i vozila koja nisu na PUBG-u.");
					SendInfoMessage(playerid, "Da se iskljucite: /izadjisapubg");
					//td
					PubgEventTDControl(playerid, true);
				}
				return 1;
			}
		}
		if( clickedid == TDEditor_TD[65] ) //stats
		{
			if(PlayerInfo[ playerid ][ xLicna ] == 0) return GRESKA( playerid, "Nemate licnu kartu, izvadite je u opstini!");
	
			if( StatsTDShowed[ playerid ] == false )
			{
		

				PlayerTextDrawSetString(playerid,PlayerStats[3][playerid],"Ucitavanje...");


				PlayerTextDrawSetString(playerid,PlayerStats[4][playerid],"Ucitavanje...");
			

				PlayerTextDrawSetString(playerid,PlayerStats[6][playerid],"Ucitavanje...");
		

				PlayerTextDrawSetString(playerid,PlayerStats[7][playerid],"Ucitavanje...");


				PlayerTextDrawSetString(playerid,PlayerStats[8][playerid],"Ucitavanje...");

				

				PlayerTextDrawSetString(playerid,PlayerStats[10][playerid],"Ucitavanje...");
				

				PlayerTextDrawSetString(playerid,PlayerStats[11][playerid],"Ucitavanje...");
		
			
				StatsTDControl( playerid, true );
				StatsTDShowed[ playerid ] = true;
				SetTimerEx("LoadStats", 1000, false, "i", playerid);
			}
			else {
				StatsTDShowed[ playerid ] = false;
				StatsTDControl( playerid, false );
			}
			return true;
		}
		if( clickedid == TDEditor_TD[66] ) //inv
		{
			if( PlayerInfo[ playerid ][ xRanac ] == 0 ) return GRESKA( playerid, "Nemate ranac." );
			if( WARPInfo[ playerid ][ WARIgrac ] != -1 ) return GRESKA( playerid, "Ne mozes ovo dok si u waru." );
			if( NaDmEventu[ playerid ] == true ) return GRESKA( playerid, "Ne mozes ovo dok si na dmu." );
			if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return GRESKA( playerid, "Ne mozes ovo dok si u zatvoru." );
			//if( IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Ne mozes dok si u vozilu." );
			OpenInventory( playerid );
			return true;
		}
		if( clickedid == TDEditor_TD[64] ) // cmds
		{
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
			strcat( DialogStrgEx, "Account\nTelefon\nChat\nImovina\nVozilo\nImanje\nOrganizacija\nPosao\nAnimacije" );
			ShowPlayerDialog( playerid, dialog_LISTAKOMANDI, DSL, D_NASLOV, DialogStrgEx, "Izaberi", "Izlaz" );
			
			//ShowPlayerDialog( playerid, dialog_HELP, DSMSG, D_NASLOV, DialogStrgEx, "Ok", "" );
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));
			return true;
		}
		if( clickedid == TDEditor_TD[63] ) //askq
		{
			if( PlayerInfo[playerid][xLevel] < 10 || PlayerInfo[playerid][xLevel] == 10) return SendSrwMessage(playerid, "Vi ste novajlija (lvl 10 ili manje), koristite '/n' za razgovaranje sa staffom!");
			if( PlayerCuffed[ playerid ] >= 1 ) return GRESKA( playerid, "Ne mozes kad si zavezan/tazovan!");
			if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return GRESKA( playerid, "Zatvoreni ste!" );
			if( ServerInfo[ Pitanja ] == false ) return GRESKA( playerid, "Slanje pitanja je trenutno iskljuceno!" );
			if( PlayerInfo[ playerid ][ xMute ] != 0) return GRESKA( playerid, "Mutirani ste !");
			if( askqInfo[ playerid ][ askqSended ] == true ) return GRESKA( playerid, "Vi ste vec poslali pitanje, molimo za strpljenje - pustite i druge da pitaju!" );
			new askQ = -1;
			for( new id = 1; id < MAX_ASKQS; id++ )
			{
				if( askqList[ id ][ askqSend ] == false )
				{
					askQ = id;
					break;
				}
			}
			if( askQ == -1 ) return GRESKA( playerid, "Lista pitanja je puna - sacekajte malo te ponovite kasnije!" );
			ShowPlayerDialog( playerid, dialog_PITAADMINA, DSI, "Posalji upit", "Upisite i posaljite vase pitanje Admin/GM timu.\nOdgovor cete dobiti u najkracem roku\nCijena upita: 100$", "Uredu", "Izlaz" );
			
			return true;
		}
		if( clickedid == TDEditor_TD[67] ) //vise
		{
			if(OdjecaTDShowed[playerid]) return GRESKA(playerid, "Vec ti je upaljen meni za odjecu.");
			if(MessageBoxShowed[playerid]) return GRESKA(playerid, "Vec ti je upaljen neki meni.");

			ShowPlayerDialog(playerid, dialog_OSTALOITDS, 
				DSL, 
				D_NASLOV, 
				"Dodaci na odjeci\n\
				Moje droge\n\
				Event info", 
				"Izaberi", "Izlaz");
			return true;
		}
	}
	return 0;
}



//////////////////////////////////////////////


//opcptd
public OnPlayerClickPlayerTextDraw( playerid, PlayerText:playertextid )
{
	if( _:playertextid != INVALID_TEXT_DRAW )
	{
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 10.0);

		//tds
		if(playertextid == MessageBox[6][playerid])
		{
			MessageBoxControl(playerid, false);
			CancelSelectTextDraw(playerid);
		}
		if(playertextid == MessageBox[3][playerid])
		{
			MessageBoxControl(playerid, false);
			CancelSelectTextDraw(playerid);
		}
		if(playertextid == MessageBox[4][playerid])
		{
			MessageBoxControl(playerid, false);
			CancelSelectTextDraw(playerid);
		}
		if(playertextid == OdjecaTextdraw[7][playerid])
		{
			OdjecaTDControl(playerid,false);
			SendInfoMessage(playerid, "Iskljucio si interaktivni meni za odjecu.");
		}
		//STAVI SVE
		if(playertextid == OdjecaTextdraw[9][playerid])
		{
			//NAOCARE
			if( PlayerInfo[ playerid ][ xSungMask ] == 0 ) return GRESKA( playerid, "Ne posedujes naocare." );
			if( !SungOn[ playerid ] )
			{
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL, 
					PlayerInfo[ playerid ][ xSungMask ],2,
					PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ], 0, 0);

				SungOn[ playerid ] = true;

				if( PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija naocara odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL ); EditingBody[ playerid ] = 1;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si naocare na glavu." );
			}
			else if( SungOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL);
				SungOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si naocare sa glave." );
			}

			//BANDANA
			if( PlayerInfo[ playerid ][ xFace ] == 0 ) return GRESKA( playerid, "Ne posedujes maramu(bandanu)." );
			if( !FaceOn[ playerid ] )
			{
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA, 
					PlayerInfo[ playerid ][ xFace ],2,
					PlayerInfo[ playerid ][ xFacePos ][ 0 ],
					PlayerInfo[ playerid ][ xFacePos ][ 1 ],
					PlayerInfo[ playerid ][ xFacePos ][ 2 ],
					PlayerInfo[ playerid ][ xFacePos ][ 3 ],
					PlayerInfo[ playerid ][ xFacePos ][ 4 ],
					PlayerInfo[ playerid ][ xFacePos ][ 5 ],
					PlayerInfo[ playerid ][ xFacePos ][ 6 ],
					PlayerInfo[ playerid ][ xFacePos ][ 7 ],
					PlayerInfo[ playerid ][ xFacePos ][ 8 ], 0, 0);

				FaceOn[ playerid ] = true;

				if( PlayerInfo[ playerid ][ xFacePos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xFacePos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xFacePos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija marame odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_BANDANA ); EditingBody[ playerid ] = 2;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si maramu na glavu." );
			}
			else if( FaceOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA);
				FaceOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si maramu sa glave." );
			}

			//SESIR
			if( PlayerInfo[ playerid ][ xHead ] == 0 ) return GRESKA( playerid, "Ne posedujes kapu/sesir/maramu(bandanu)." );
			if( !HeadOn[ playerid ] )
			{
				if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_HEAD ) ) return GRESKA( playerid, "Vec imate objekt na glavi." );
				
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, 
					PlayerInfo[ playerid ][ xHead ],2,
					PlayerInfo[ playerid ][ xHeadPos ][ 0 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 1 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 2 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 3 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 4 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 5 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 6 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 7 ],
					PlayerInfo[ playerid ][ xHeadPos ][ 8 ], 0, 0);
				
				HeadOn[ playerid ] = true;
			   
				if( PlayerInfo[ playerid ][ xHeadPos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xHeadPos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xHeadPos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija kape/sesira/marame odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_HEAD ); EditingBody[ playerid ] = 3;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si kapu/sesir/maramu na glavu." );
			}
			else if( HeadOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_HEAD);
				HeadOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si kapu/sesir/maramu sa glave." );
			}
			//PAPAGAJ
			if(PlayerInfo[playerid][xPapagaj] == 0) return GRESKA(playerid, "Nemas papagaja.");
			if(!PapagajOn[playerid])
			{
				PapagajOn[playerid] = true;
				SendInfoMessage(playerid, "Stavio si papagaja na sebe!");
				SetPlayerAttachedObject( playerid,5,19078,1,0.320722,-0.067912,-0.165151,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000 );
			}
			else if(PapagajOn[playerid])
			{
				PapagajOn[playerid] = false;
				SendInfoMessage(playerid, "Skinuo si papagaja sa sebe!");
				RemovePlayerAttachedObject(playerid,5);
			}
			SendInfoMessage(playerid,"Uspjesno si stavio/skinuo papagaja, kapu, sesir i maramu!");
		}
		//SESIR
		if(playertextid == OdjecaTextdraw[10][playerid])
		{
			//SESIR
			if( PlayerInfo[ playerid ][ xHead ] == 0 ) return GRESKA( playerid, "Ne posedujes kapu/sesir/maramu(bandanu)." );
			if( !HeadOn[ playerid ] )
			{
				if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_HEAD ) ) return GRESKA( playerid, "Vec imate objekt na glavi." );

				SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, 
						PlayerInfo[ playerid ][ xHead ],2,
						PlayerInfo[ playerid ][ xHeadPos ][ 0 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 1 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 2 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 3 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 4 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 5 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 6 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 7 ],
						PlayerInfo[ playerid ][ xHeadPos ][ 8 ], 0, 0);

				HeadOn[ playerid ] = true;

				if( PlayerInfo[ playerid ][ xHeadPos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xHeadPos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xHeadPos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija kape/sesira/marame odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_HEAD ); EditingBody[ playerid ] = 3;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si kapu/sesir/maramu na glavu." );
			}
			else if( HeadOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_HEAD);
				HeadOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si kapu/sesir/maramu sa glave." );
			}
		}
		//NAOCALE
		if(playertextid == OdjecaTextdraw[11][playerid])
		{
			//NAOCARE
			if( PlayerInfo[ playerid ][ xSungMask ] == 0 ) return GRESKA( playerid, "Ne posedujes naocare." );
			if( !SungOn[ playerid ] )
			{
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL, 
					PlayerInfo[ playerid ][ xSungMask ],2,
					PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ],
					PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ], 0, 0);

				SungOn[ playerid ] = true;

				if( PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija naocara odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL ); EditingBody[ playerid ] = 1;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si naocare na glavu." );
			}
			else if( SungOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL);
				SungOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si naocare sa glave." );
			}
		}
		//BANDANA
		if(playertextid == OdjecaTextdraw[12][playerid])
		{
			//BANDANA
			if( PlayerInfo[ playerid ][ xFace ] == 0 ) return GRESKA( playerid, "Ne posedujes maramu(bandanu)." );
			if( !FaceOn[ playerid ] )
			{
				SetPlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA, 
					PlayerInfo[ playerid ][ xFace ],2,
					PlayerInfo[ playerid ][ xFacePos ][ 0 ],
					PlayerInfo[ playerid ][ xFacePos ][ 1 ],
					PlayerInfo[ playerid ][ xFacePos ][ 2 ],
					PlayerInfo[ playerid ][ xFacePos ][ 3 ],
					PlayerInfo[ playerid ][ xFacePos ][ 4 ],
					PlayerInfo[ playerid ][ xFacePos ][ 5 ],
					PlayerInfo[ playerid ][ xFacePos ][ 6 ],
					PlayerInfo[ playerid ][ xFacePos ][ 7 ],
					PlayerInfo[ playerid ][ xFacePos ][ 8 ], 0, 0);

				FaceOn[ playerid ] = true;

				if( PlayerInfo[ playerid ][ xFacePos ][ 6 ] > 2.0 || 
					PlayerInfo[ playerid ][ xFacePos ][ 7 ] > 2.0 || 
					PlayerInfo[ playerid ][ xFacePos ][ 8 ] > 2.0 )
				{
					GRESKA( playerid, "Losa pozicija marame odradi je ponovo." );
					EditAttachedObject( playerid, OBJECT_SLOT_BANDANA ); EditingBody[ playerid ] = 2;
					return true;
				}

				SendInfoMessage( playerid, "Stavio si maramu na glavu." );
			}
			else if( FaceOn[ playerid ] )
			{
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA);
				FaceOn[ playerid ] = false;
				SendInfoMessage( playerid, "Skinuo si maramu sa glave." );
			}
		}
		//PAPAGAJ
		if(playertextid == OdjecaTextdraw[13][playerid])
		{
			//PAPAGAJ
			if(PlayerInfo[playerid][xPapagaj] == 0) return GRESKA(playerid, "Nemas papagaja.");
			if(!PapagajOn[playerid])
			{
				PapagajOn[playerid] = true;
				SendInfoMessage(playerid, "Stavio si papagaja na sebe!");
				SetPlayerAttachedObject( playerid,5,19078,1,0.320722,-0.067912,-0.165151,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000 );
			}
			else if(PapagajOn[playerid])
			{
				PapagajOn[playerid] = false;
				SendInfoMessage(playerid, "Skinuo si papagaja sa sebe!");
				RemovePlayerAttachedObject(playerid,5);
			}
		}
		if( playertextid == SkinIgraca[playerid] )
		{
			if( PlayerInfo[playerid][xAdmin] == 0 && \
				PlayerInfo[playerid][xHelper] == 0 && \
				PlayerInfo[playerid][xVIPLevel] == 0 ) return greska(playerid,"Ti nisi vip/staff da bi promenio skin putem skin td-a!");

			if(PlayerInfo[playerid][xAdmin] == 0 && \
				PlayerInfo[playerid][xHelper] == 0 && \
				PlayerInfo[playerid][xClan] == 0 && \
				PlayerInfo[playerid][xLevel] >= 5 && \
				PlayerInfo[playerid][xProperty][0] == -1 &&\
				PlayerInfo[playerid][xProperty][1] == -1 &&\
				PlayerInfo[playerid][xProperty][2] == -1
			) return greska(playerid,"Ne mozes mijenjati skin jer si beskucnik!");

			if( PlayerInfo[ playerid ][ xNovac ] < 500 ) return GRESKA( playerid, "Nemate dovoljno novca(500$).");
			if(!AdminDuty[playerid] && !PDuty[playerid] && PlayerInfo[playerid][xVIPLevel] != 5) 
			{
				if( PlayerInfo[ playerid ][ xClan ] != 0 ) return GRESKA( playerid, "Ne mozete kupiti skin jer ste u organizaciji." ); 
			}
			ShowModelSelectionMenu(playerid,skinlist,"Odaberi skin");

		}
		if(playertextid == PlayerStats[15][playerid])
		{
			StatsTDControl(playerid, false);
			StatsTDShowed[ playerid ] = false;
		}
		if(playertextid == BanTD[playerid][10])
		{
			//za unban td
			format( globalstring, sizeof( globalstring ), "{FF0000}| UNBAN REQUEST |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"se konektovao na server i zatrazio unban. (/unban)", ImeIgraca(playerid), playerid);
			AdminPoruka( ANTICHEAT, globalstring );
			scminfo(playerid, "Vas zahtev za unban je poslan svim online administratorima! Molimo pricekajte...");
		}
		if( playertextid == p_gamemodetd[0][playerid])
		{
			ShowPlayerDialog(playerid,dialog_GAMEMODE, DSL, "Nova Era OGC | Odaberite gamemode","RolePlay\nDeathMatch\nPUBG", "Odaberi", "Odustani");
		}
		if( playertextid == p_gamemodetd[1][playerid])
		{
			if(PlayerInfo[playerid][xgms] == 0)
			{
				PlayerTextDrawSetSelectable(playerid, p_gamemodetd[0][playerid], false);
				PlayerInfo[playerid][xgms] = 1;
				PlayerTextDrawColor(playerid,p_gamemodetd[1][playerid],tdboja);
				PlayerTextDrawHide(playerid, p_gamemodetd[0][playerid]);
				PlayerTextDrawHide(playerid, p_gamemodetd[1][playerid]);
				PlayerTextDrawShow(playerid, p_gamemodetd[0][playerid]);
				PlayerTextDrawShow(playerid, p_gamemodetd[1][playerid]);
				return 1;
			}
			if(PlayerInfo[playerid][xgms] == 1)
			{
				PlayerTextDrawSetSelectable(playerid, p_gamemodetd[0][playerid], true);
				PlayerInfo[playerid][xgms] = 0;
				PlayerTextDrawColor(playerid,p_gamemodetd[1][playerid],-16776961);
				PlayerTextDrawHide(playerid, p_gamemodetd[0][playerid]);
				PlayerTextDrawHide(playerid, p_gamemodetd[1][playerid]);
				PlayerTextDrawShow(playerid, p_gamemodetd[0][playerid]);
				PlayerTextDrawShow(playerid, p_gamemodetd[1][playerid]);
				return 1;
			}
		}
		if( playertextid == BuyCar[ playerid ][ 1 ] )
		 {
			new as = GetNearestSalon( playerid ), slotid = AutoSalon[ as ][ aIzlogVeh ];
			if( as != -1 )
			{
				if( ModelCar[ playerid ] == (AutoSalon[ as ][ aMaxVehModel ]-1) ) return 1;
				
				ModelCar[ playerid ]++;

				new string[ 128 ];
				format( string, sizeof( string ), "%s", ImeVozila[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 3 ], string );

				format( string, sizeof( string ), "~w~%d$", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ][ 1 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 7 ], string );

				format( string, sizeof( string ), "~w~%dg", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ][ 2 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 11 ], string );

				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 5 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 5 ] );
				
				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 12 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 12 ] );
				
				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 9 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 9 ] );

				SetPlayerCameraPos( playerid, AutoSalon[ as ][ aCameraPos ][ 0 ], AutoSalon[ as ][ aCameraPos ][ 1 ], AutoSalon[ as ][ aCameraPos ][ 2 ] );
				SetPlayerCameraLookAt( playerid, AutoSalon[ as ][ aCameraLookAt ][ 0 ], AutoSalon[ as ][ aCameraLookAt ][ 1 ], AutoSalon[ as ][ aCameraLookAt ][ 2 ] );

				Dimi_DestroyVehicle( VehicleInfo[ slotid ][ vID ] );
				VehicleInfo[ slotid ][ vID ] = Dimi_CreateVehicle( slotid, VehicleInfo[ slotid ][ vUsage ], VehicleInfo[ slotid ][ vOrganization ], VehicleInfo[ slotid ][ vJob ], VehicleInfo[ slotid ][ vFuelProperty ], AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ], VehicleInfo[ slotid ][ vLokacijaX ], VehicleInfo[ slotid ][ vLokacijaY ], VehicleInfo[ slotid ][ vLokacijaZ ]+1.0, VehicleInfo[ slotid ][ vLokacijaA ], AutoSalonBojaVozila[ playerid ], AutoSalonBojaVozila[ playerid ], -1 );
				SetVehicleVirtualWorld( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aVW ] );
				LinkVehicleToInterior( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aInt ] );

				////////////////////////////////////////////////////////////////////////////////////////
				if( VoziloJeDizel( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Dizel" );
				}
				else if( VoziloJeBenzin( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Benzin" );
				}
				else if( VoziloJeKerozin( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Kerozin" );
				}
				else if( VoziloNemaGorivo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~N/A" );
				}
				/////////////////////////////////////////////////////////////////////////////////////////
				if( VoziloJe2Vrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~2" );
				}
				else if( VoziloJe4Vrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~4" );
				}
				else if( VoziloNemaVrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~0" );
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////
				if( SportVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~sportsko" );
				}
				else if( PutnickoVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~putnicko" );
				}
				else if( IsVehicleMotor( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~motocikl" );
				}
				else if( IsVehicleBajs( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~bicikl" );
				}
				else if( IsVehicleLetelica( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~letilica" );
				}
				else if( IsVehicleBrod( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~plovilo" );
				}
				else if( TeretnoVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~teretno" );
				}
				else
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~N/A" );
				}
				////////////////////////////////////////////////////////////////////////////////////////////


				new Cboja1 = AutoSalonBojaVozila[ playerid ];
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ],Cboja1, Cboja1);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ],Cboja1, Cboja1);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ],Cboja1, Cboja1);

				SelectTextDraw( playerid, UGBOJA );
			}
			return true;
		}
		if( playertextid == BuyCar[ playerid ][ 4 ] )
		 {
			new as = GetNearestSalon( playerid ), slotid = AutoSalon[ as ][ aIzlogVeh ];
			if( as != -1 )
			{
				if( ModelCar[ playerid ] == 0 ) return 1;
				ModelCar[ playerid ]--;

				new string[ 128 ];
				format( string, sizeof( string ), "%s", ImeVozila[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 3 ], string );

				format( string, sizeof( string ), "~w~%d$", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ][ 1 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 7 ], string );
				
				format( string, sizeof( string ), "~w~%dg", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ][ 2 ] );
				PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 11 ], string );
				
				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 5 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 5 ] );
				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 12 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 12 ] );
				PlayerTextDrawSetPreviewModel( playerid, BuyCar[ playerid ][ 9 ],AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ] );
				PlayerTextDrawShow( playerid, BuyCar[ playerid ][ 9 ] );

				SetPlayerCameraPos( playerid, AutoSalon[ as ][ aCameraPos ][ 0 ], AutoSalon[ as ][ aCameraPos ][ 1 ], AutoSalon[ as ][ aCameraPos ][ 2 ] );
				SetPlayerCameraLookAt( playerid, AutoSalon[ as ][ aCameraLookAt ][ 0 ], AutoSalon[ as ][ aCameraLookAt ][ 1 ], AutoSalon[ as ][ aCameraLookAt ][ 2 ] );

				Dimi_DestroyVehicle( VehicleInfo[ slotid ][ vID ] );
				VehicleInfo[ slotid ][ vID ] = Dimi_CreateVehicle( slotid, VehicleInfo[ slotid ][ vUsage ], VehicleInfo[ slotid ][ vOrganization ], VehicleInfo[ slotid ][ vJob ], VehicleInfo[ slotid ][ vFuelProperty ], AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ], VehicleInfo[ slotid ][ vLokacijaX ], VehicleInfo[ slotid ][ vLokacijaY ], VehicleInfo[ slotid ][ vLokacijaZ ]+1.0, VehicleInfo[ slotid ][ vLokacijaA ], AutoSalonBojaVozila[ playerid ], AutoSalonBojaVozila[ playerid ], -1 );
				SetVehicleVirtualWorld( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aVW ] );
				LinkVehicleToInterior( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aInt ] );

				////////////////////////////////////////////////////////////////////////////////////////
				if( VoziloJeDizel( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Dizel" );
				}
				else if( VoziloJeBenzin( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Benzin" );
				}
				else if( VoziloJeKerozin( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~Kerozin" );
				}
				else if( VoziloNemaGorivo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 17 ], "Gorivo: ~w~N/A" );
				}
				/////////////////////////////////////////////////////////////////////////////////////////
				if( VoziloJe2Vrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~2" );
				}
				else if( VoziloJe4Vrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~4" );
				}
				else if( VoziloNemaVrata( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 18 ], "Broj vrata: ~w~0" );
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////
				if( SportVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~sportsko" );
				}
				else if( PutnickoVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~putnicko" );
				}
				else if( IsVehicleMotor( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~motocikl" );
				}
				else if( IsVehicleBajs( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~bicikl" );
				}
				else if( IsVehicleLetelica( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~letilica" );
				}
				else if( IsVehicleBrod( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~plovilo" );
				}
				else if( TeretnoVozilo( VehicleInfo[ slotid ][ vID ] ) )
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~teretno" );
				}
				else
				{
					PlayerTextDrawSetString( playerid, BuyCar[ playerid ][ 19 ], "Vrsta: ~w~N/A" );
				}
				////////////////////////////////////////////////////////////////////////////////////////////




				new Cboja1 = AutoSalonBojaVozila[ playerid ];
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ],Cboja1, Cboja1);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ],Cboja1, Cboja1);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ],Cboja1, Cboja1);



				SelectTextDraw( playerid, UGBOJA );
			}
			return true;
		}
		if( playertextid == BuyCar[ playerid ][ 8 ] )
		{
			new as = GetNearestSalon( playerid ), slotid = AutoSalon[ as ][ aIzlogVeh ];
			if( as != -1 )
			{
				AutoSalon[ as ][ AlreadyBuying ] = false;

				PlayerBuyingAS[ playerid ] = -1;
				AutoSalonBojaVozila[ playerid ] = -1;
				ModelCar[ playerid ] = 0;

				Dimi_DestroyVehicle( VehicleInfo[ slotid ][ vID ] );
				VehicleInfo[ slotid ][ vID ] = Dimi_CreateVehicle( slotid, VehicleInfo[ slotid ][ vUsage ], VehicleInfo[ slotid ][ vOrganization ], VehicleInfo[ slotid ][ vJob ], VehicleInfo[ slotid ][ vFuelProperty ], AutoSalon[ as ][ aVehModel ][ 0 ], VehicleInfo[ slotid ][ vLokacijaX ], VehicleInfo[ slotid ][ vLokacijaY ], VehicleInfo[ slotid ][ vLokacijaZ ]+1.0, VehicleInfo[ slotid ][ vLokacijaA ], -1, -1, -1 );
				SetVehicleVirtualWorld( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aVW ] );
				LinkVehicleToInterior( VehicleInfo[ slotid ][ vID ], AutoSalon[ as ][ aInt ] );

				BuyCarTDControl( playerid, false );
				BojaVozilaTDControl( playerid, false );
				TogPlayerHud( playerid );
				TogglePlayerControllable( playerid, true );

				SetCameraBehindPlayer( playerid );
				CancelSelectTextDraw( playerid );
			}
			return true;
		}
		if( playertextid == BuyCar[ playerid ][ 10 ] )
		{

			new as = GetNearestSalon( playerid );
			if( as != -1 ) {

				strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );

				strcat( DialogStrgEx, ""col_balkanstory"__________________________________________________________________\n");
				format( globalstring, sizeof( globalstring ),""col_white"Da li ste sigurni da zelite kupiti vozilo "col_balkanstory"%s.\n", ImeVozila[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ] );
				strcat( DialogStrgEx, globalstring );
				format( globalstring, sizeof( globalstring ),""col_white"Cena: "col_balkanstory"%dg zlata.\n", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]- 400 ][ 2 ] );
				strcat( DialogStrgEx, globalstring );
				strcat( DialogStrgEx, ""col_balkanstory"__________________________________________________________________");

				ShowPlayerDialog( playerid, dialog_VEHGOLDBUY, DSMSG, D_NASLOV, DialogStrgEx, "Kupi", "Odustani" );
				strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));


			} 
			return true;
		}
		if( playertextid == BuyCar[ playerid ][ 6 ] )
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{

				strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );

				strcat( DialogStrgEx, ""col_balkanstory"__________________________________________________________________\n");
				format( globalstring, sizeof( globalstring ),""col_white"Da li ste sigurni da zelite kupiti vozilo "col_balkanstory"%s.\n", ImeVozila[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]-400 ] );
				strcat( DialogStrgEx, globalstring );
				format( globalstring, sizeof( globalstring ),""col_white"Cena: "col_balkanstory"%d$.\n", VehPrice[ AutoSalon[ as ][ aVehModel ][ ModelCar[ playerid ] ]- 400 ][ 1 ] );
				strcat( DialogStrgEx, globalstring );
				strcat( DialogStrgEx, ""col_balkanstory"__________________________________________________________________");

				ShowPlayerDialog( playerid, dialog_VEHMONEYBUY, DSMSG, D_NASLOV, DialogStrgEx, "Kupi", "Odustani" );
				strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));


			}
			return true;
		}
		////////////////////////////////////////////////////////////////////////
		if( playertextid == ASBojaVozila[ 4 ] [ playerid ] )//crna
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 0;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);
				
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);
				
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
				
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 5 ] [ playerid ] )//bijela
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 1;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 6 ] [ playerid ] )//svijetlo plava
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 135;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 7 ] [ playerid ] )//crvena
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 3;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 8 ] [ playerid ] )//zelenoplava
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 165;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 9 ] [ playerid ] )//pink
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 126;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 10 ] [ playerid ] )//zuta
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 6;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 11 ] [ playerid ] )//zelena
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 191;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);

			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 12 ] [ playerid ] )//tamno ljubicasta
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 179;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);

			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 13 ] [ playerid ] )//svijetlo zelena
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 145;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);

			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 14 ] [ playerid ] )//narandjasta
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 219;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 15 ] [ playerid ] )//tamnoplava
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 93;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 16 ] [ playerid ] )//zelenoplava
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 155;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 17 ] [ playerid ] )//tamno siva
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 63;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		if( playertextid == ASBojaVozila[ 18 ] [ playerid ] )//tamno crvena
		{
			new as = GetNearestSalon( playerid );
			if( as != -1 )
			{
				AutoSalonBojaVozila[ playerid ] = 17;
				new slotid = AutoSalon[ as ][ aIzlogVeh ];
				new bojica = AutoSalonBojaVozila[ playerid ];
				ChangeVehicleColor(VehicleInfo[ slotid ][ vID ], bojica, bojica);
				//
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawHide(playerid, BuyCar[ playerid ][ 5 ]);

				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], bojica, bojica);
				PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5 ], bojica, bojica);

				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 12 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 9 ]);
				PlayerTextDrawShow(playerid, BuyCar[ playerid ][ 5 ]);
			}
			return true;
		}
		
		////////////////////////////////////////////////////////////////////////
		/*if( playertextid == LicnaKartaTD[19][playerid] )
		{


			if( LicnaKartaShowed[ playerid ] == true )
			{

				LicnaKartaShowed[ playerid ] = false;
				LicnaKartaControl( playerid, false );

			}
			return true;
		}*/
		
		/*if( playertextid == StatsTDs[39][playerid] )//guzaa
		{


			if( StatsTDShowed[ playerid ] == true )
			{
				StatsTDShowed[ playerid ] = false;
				StatsTDsControl( playerid, false );
			}
			return true;
		}*/
		
		

		#if kladionica == 1
		if( playertextid == KladionicaSM[ playerid ][ 31 ] ) {
		
			new str[ 128 ];
		
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
			strcat( DialogStrgEx, str );
		
			for(  new i = 0; i < 10; i++ ) {
			
				format( str, sizeof( str ), "%s vs %s\n", bettingInfo[ Parovi[ i ][ parID ][ 0 ] ][ teamName ], bettingInfo[ Parovi[ i ][ parID ][ 1 ] ][ teamName ] );

				strcat( DialogStrgEx, str );
			}
		
			ShowPlayerDialog( playerid, dialog_UPLATITIKET, DSL, "Izaberi par:", DialogStrgEx, "Izaberi", "Odustani" );
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));
			return true;
		}
		#endif
		if( playertextid == Regtd21[playerid] ) {
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			ShowPlayerDialog(playerid,dialog_REGISTER, DSI, "Odabir lozinke", ""col_balkanstory"==============================================================\n\n"SERVERBOJA_AQUA"Molimo vas da odaberete vasu lozinku sa kojom cete pristupati vasem nalogu.\nLozinka ne moze biti manja od 6 i veca od 24 karaktera!\n\n"col_balkanstory"==============================================================", "Uredu", "Odustani");
			
			return true;
		}
		if( playertextid == Regtd23[playerid] ) { // spol
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			/*PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], "Musko");
			PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], 29 );
			for( new i = 7; i < 14; i ++) {//counting2 ok
				PlayerTextDrawShow( playerid, RegisterTD[ playerid ][ i ] );
			}*/
			ShowPlayerDialog(playerid,dialog_SPOL,DSMSG,"Registracija | Odabir spola","Odaberite Vas spol na serveru!\nSpol ne mora biti isti kao i u RL!","Musko","Zensko");
			BiraPol[ playerid ] = 1;
			return true;
		}
		/*if( playertextid == RegisterTD[ playerid ][ 9 ] ) { // desno
			if( BiraPol[ playerid ] > 0 ) {
				if( BiraPol[ playerid ] == 1 ) {
					BiraPol[ playerid ] = 2;
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], "Zensko");
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], Fe29 );
				}
				else if( BiraPol[ playerid ] == 2 ) {
					BiraPol[ playerid ] = 1;
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], "Musko");
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], 29 );
				}
			}
			if( BiraSkin[ playerid ] > 0 ) {
				if( RegSex[ playerid ] == 1 ) { // musko
					if( BiraSkin[ playerid ] == 4 ) BiraSkin[ playerid ] = 0;
					BiraSkin[ playerid ]++;
					PlayerInfo[ playerid ][ xSkin ] = MaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ];
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], MaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ] );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], MaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
				else if( RegSex[ playerid ] == 2 ) { // zensko
					if( BiraSkin[ playerid ] == 4 ) BiraSkin[ playerid ] = 0;
					BiraSkin[ playerid ]++;
					PlayerInfo[ playerid ][ xSkin ] = FemaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ];
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], FemaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ] );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], FemaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
			}
			PlayerTextDrawShow( playerid, RegisterTD[ playerid ][ 7 ] );
			return true;
		}
		if( playertextid == RegisterTD[ playerid ][ 10 ] ) { // levo
			if( BiraPol[ playerid ] > 0 ) {
				if( BiraPol[ playerid ] == 1 ) {
					BiraPol[ playerid ] = 2;
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], Fe29 );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], "Zensko");
				}
				else if( BiraPol[ playerid ] == 2 ) {
					BiraPol[ playerid ] = 1;
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], 29 );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], "Musko");
				}
			}
			if( BiraSkin[ playerid ] > 0 ) {
				if( RegSex[ playerid ] == 1 ) { // musko
					if( BiraSkin[ playerid ] == 1 ) BiraSkin[ playerid ] = 5;
					BiraSkin[ playerid ]--;
					PlayerInfo[ playerid ][ xSkin ] = MaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ];
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], MaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ] );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], MaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
				else if( RegSex[ playerid ] == 2 ) { // zensko
					if( BiraSkin[ playerid ] == 1 ) BiraSkin[ playerid ] = 5;
					BiraSkin[ playerid ]--;
					PlayerInfo[ playerid ][ xSkin ] = FemaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ];
					PlayerTextDrawSetPreviewModel( playerid, RegisterTD[ playerid ][ 7 ], FemaleSkinIDs[ BiraSkin[ playerid ]-1 ][ 0 ] );
					PlayerTextDrawSetString( playerid, RegisterTD[ playerid ][ 8 ], FemaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
			}
			PlayerTextDrawShow( playerid, RegisterTD[ playerid ][ 7 ] );
			return true;
		}
		if( playertextid == RegisterTD[ playerid ][ 11 ] ) { // izaberi
			if( BiraPol[ playerid ] > 0 ) {
				if( BiraPol[ playerid ] == 1 ) {
					PlayerInfo[ playerid ][ xPol ] = 1;
					RegSex[ playerid ] = 1;
					BiraPol[ playerid ] = 0;
					PlayerTextDrawSetString( playerid, Regtd23[playerid], "Musko");
					PlayerInfo[ playerid ][ xSkin ] = 29;
				}
				else if( BiraPol[ playerid ] == 2 ) {
					PlayerInfo[ playerid ][ xPol ] = 2;
					RegSex[ playerid ] = 2;
					BiraPol[ playerid ] = 0;
					PlayerTextDrawSetString( playerid, Regtd23[playerid], "Zensko");
					PlayerInfo[ playerid ][ xSkin ] = Fe29;
				}
			}
			if( BiraSkin[ playerid ] > 0 ) {
				if( RegSex[ playerid ] == 1 ) {
					PlayerTextDrawSetString( playerid, Regtd26[playerid], MaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
				else if( RegSex[ playerid ] == 2 ) {
					PlayerTextDrawSetString( playerid, Regtd26[playerid], FemaleSkinNames[ BiraSkin[ playerid ]-1 ][ 0 ] );
				}
				//PlayerTextDrawLetterSize( playerid, Regtd26[playerid], 0.200000, 1.000000 );//
				PlayerTextDrawShow( playerid, Regtd26[playerid] );
				BiraSkin[ playerid ] = 0;
			}
			for( new i = 7; i < 14; i ++) {//counting2 ok
				PlayerTextDrawHide( playerid, RegisterTD[ playerid ][ i ] );
			}
			return true;
		}*/
		//___________________________________[ NA LOGINU CLICKABLE ]__________________________
		
		
		/*if( playertextid == LoginTD[ playerid ][ 24 ] )//login button
		{
			PrviSpawn[ playerid ] = 1;
			//format( sDStrg, sizeof( sDStrg ),DialogTekstovi[ 0 ], MAX_POKUSAJ_LOGINA );
			//ShowPlayerDialog( playerid, dialog_LOGIN, DSP, D_NASLOV, sDStrg, D_ODABERI, D_ODUSTANI );
			new logg[400];
			format(logg,sizeof(logg),"{FFFFFF}Dobrodosli na "col_balkanstory"Nova Era - RolePlay!\n\n"col_balkanstory"||------------------------------------------------------------||\n\n"col_balkanstory"-Vase Ime: {FFFFFF}%s\n\n"col_balkanstory"-Discord: {FFFFFF}https://discord.gg/XkcSmSxFMe https://discord.gg/XkcSmSxFMe \n\n"col_balkanstory"-Account: {FFFFFF}Vas account je registrovan\n\n"col_balkanstory"-Unesite vas {FFFFFF}password!\n\n"col_balkanstory"||------------------------------------------------------------||",ImeIgraca(playerid));
			ShowPlayerDialog(playerid,dialog_LOGIN, DSP, "LOGIN",logg, "Prijava", "Odustani");


			return true;
		}
		
		if( playertextid == LoginTD[ playerid ][ 25 ] )//credits button
		{

			ShowPlayerDialog(playerid,0,DSMSG, ""col_balkanstory"Nova Era OGC Credits", "\n\n"col_balkanstory"OWNERI: {C9C9C9}Skopsi & Vladimir i Savic \n\n"col_balkanstory"OWNER & DEVELOPER: {C9C9C9}Skopsi\n\n"col_balkanstory"DIRECTOR: {C9C9C9}Mirza \n\n"col_balkanstory"MAPPER: {C9C9C9}Mata i Skopsi\n\n"col_balkanstory"MAPPER: {C9C9C9}Skopsi\n\n", "Uredu", "");//dialog creditsa

			return true;
		}
		
		if( playertextid == LoginTD[ playerid ][ 22 ] )//forum button
		{

			ShowPlayerDialog(playerid,0,DSMSG, ""col_balkanstory"Nova Era OGC Portal", "\n"col_balkanstory"==============================\n\n        https://{FFFFFF}discord.gg/"col_balkanstory"XkcSmSxFMe\n\n==============================", "Uredu", "");//dialog foruma

			return true;
		}
		
		if( playertextid == LoginTD[ playerid ][ 23 ] )//TS3 button
		{

			ShowPlayerDialog(playerid,0,DSMSG, ""col_balkanstory"Nova Era OGC TS3 Server", "\n"col_balkanstory"==============================\n\n      TS3 IP:{FFFFFF}USKORO"col_balkanstory"\n\n==============================", "Uredu", "");//dialog TS-a

			return true;
		}*/
		//___________________________________________________________________________________
		if( playertextid == Regtd26[playerid] ) { // skin
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			if( RegSex[ playerid ] == 0 ) return ShowPlayerDialog( playerid, 0, DSMSG, "Registracija | Vas pol","Niste odabrali pol!", "U redu", "" );
			ShowModelSelectionMenu(playerid,regskinlist,"Odaberi skin");
			//ShowPlayerDialog( playerid, 0, DSMSG, "Registracija | Vas skin","Vas default skin je uspjesno postavljen!\nMozete nastaviti sa registracijom.", "U redu", "" );
			return true;
		}
		if( playertextid == Regtd24[playerid] ) {
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			ShowPlayerDialog( playerid, dialog_COUNTRY, DSL, "Vasa drzava", ""col_balkanstory"[1]{FFFFFF} Srbija\n"col_balkanstory"[2]{FFFFFF} Hrvatska\n"col_balkanstory"[3]{FFFFFF} Makedonija\n"col_balkanstory"[4]{FFFFFF} Crna Gora\n"col_balkanstory"[5]{FFFFFF} BiH\n"col_balkanstory"[6]{FFFFFF} Ostalo", "Odabir", "Izadji" );
			return true;
		}
		if( playertextid == Regtd22[playerid] ) {
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			ShowPlayerDialog(playerid,dialog_AGE, DSI, "Vasa starost", ""col_balkanstory"==============================================================\n\n"SERVERBOJA_AQUA"Molimo vas da unesete koliko imate godina.\nUkoliko ste mladji od 12 i stariji od 70 godina necete moci nastaviti dalje!\n\n"col_balkanstory"==============================================================", "Uredu", "Odustani");
			return true;
		}
		if( playertextid == Regtd25[playerid] ) {
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			//PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], false);
			ShowPlayerDialog(playerid,dialog_MAIL, DSI, "E-mail adresa", ""col_balkanstory"==============================================================\n\n"SERVERBOJA_AQUA"Molimo vas da unesete vasu ispravnu E-mail adresu.\nU slucaju problema sa nalogom e-mail ce vam pomoci!\n\n"col_balkanstory"==============================================================", "Uredu", "Odustani");
			return true;
		}
		if( playertextid == Regtd28[playerid] ) {
			if( InputPassword[ playerid ] == false ) return GRESKA( playerid, "Niste odabrali lozinku!" );
			if( ChoseCountry[ playerid ] == false ) return GRESKA( playerid, "Niste odabrali vase porijeklo!" );
			if( InputAge[ playerid ] == false ) return GRESKA( playerid, "Niste upisali koliko imate godina!" );
			if( InputMail[ playerid ] == false ) return GRESKA( playerid, "Niste unijeli vas E-mail!" );
			if( RegSex[ playerid ] == 0 ) return GRESKA( playerid, "Niste odabrali drzavu iz koje dolazite!" );
			if( OdabraoSkinZaReg[ playerid ] == 0 ) return GRESKA( playerid, "Niste odabrali skin koji zelite!" );
			hidetdtd(playerid);
			CancelSelectTextDraw( playerid );
			IgracSeRegistruje[ playerid ] = false;
			PlayerTextDrawHide( playerid, Regtd21[playerid] );
			PlayerTextDrawHide( playerid, Regtd22[playerid] );
			PlayerTextDrawHide( playerid, Regtd23[playerid] );
			PlayerTextDrawHide( playerid, Regtd24[playerid] );
			PlayerTextDrawHide( playerid, Regtd25[playerid] );
			PlayerTextDrawHide( playerid, Regtd26[playerid] );
			hidesrtd(playerid);
			hidetdtd(playerid);
			RegisterTDControl( playerid, false );
			PlayerInfo[ playerid ][ xRegistrovan ] = 1;
			PlayerInfo[ playerid ][ xPocetniTut ] = 0;
			PlayerInfo[ playerid ][ xSpawn ] = SetRandomSpawn( playerid );
			PlayerInfo[ playerid ][ xLevel ] = ServerInfo[ PocetniLevel ];
			new datum[ 64 ]; new year, month,day;
			getdate( year, month, day );
			new tmphour, tmpminute, tmpsecond;
			gettimeEx( tmphour, tmpminute, tmpsecond );
			FixHour( tmphour );
			tmphour = shifthour;
			format( datum, sizeof( datum ), "%02d/%02d/%d - %d/%d/%d", day, month, year, tmphour, tmpminute, tmpsecond );
			strmid( PlayerInfo[ playerid ][ xLastLogin ], datum, 0, strlen( datum ), 64 );
			SetPlayerScore( playerid, PlayerInfo[ playerid ][ xLevel ] );
			DajIgracuNovac( playerid, ServerInfo[ PocetniNovaca ] );
			SavePlayer( playerid );
			SetPlayerSkin( playerid, PlayerInfo[ playerid ][ xSkin ] );
			announcement( playerid, "Uspjesno ste registrovani na Nova Era Online Gaming Community");
			TogglePlayerSpectating( playerid, 1 );
			
			InterpolateCameraPos(playerid, 374.912872, -1113.013427, 124.437553, 2345.744384, -2112.316162, 98.540664, 50000);
			InterpolateCameraLookAt(playerid, 379.372039, -1115.274536, 124.378959, 2343.739257, -2107.836425, 97.585632, 1);
			//SetPlayerInterior( playerid, 0 );
			//SetPlayerVirtualWorld( playerid, 1 );
			Dimi_SetPlayerPos( playerid, 473.3107, -1342.6024, 31.8416);
			SendClientMessage(playerid,-1, " ");//dobrodoslica
			SendClientMessage(playerid,-1, " ");
			SendClientMessage(playerid,-1, " ");
			SendClientMessage(playerid,-1, " ");
			SendClientMessage(playerid,-1, " ");
			TutorijalTDControl(playerid, 0);
			//SendClientMessage(playerid,-1, ""col_balkanstory"__________________________________________________________________");
			TimerTutorial[ playerid ] = SetTimerEx( "PocetniTut", 25000, false, "ii", playerid, 1 );
			PocetniTutorialStartovan[ playerid ] = true;
			return true;
		}
		/*if( playertextid == Regtd22[playerid] ) {
			Kickovanje( playerid, "Prekinuli ste registraciju i kickovani ste!" );
			return true;
		}*/
		//
		if( playertextid == TuningBuy[ playerid ][ 7 ] ) { // desno
			if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate biti u vozilu." );
			if( GetPlayerState( playerid ) != PLAYER_STATE_DRIVER ) return GRESKA( playerid, "Morate biti na mjestu vozaca." );

			if( TPInfo[ playerid ][ tPaintjob ] == false ) {

				new compid = -1, vehicleid = GetPlayerVehicleID( playerid );

				for( new i = ( TPInfo[ playerid ][ tID ]+1 ); i < MAX_COMPONENTS; i++ ) {
					if( cInfo[ i ][ cType ] == TPInfo[ playerid ][ tType ] ) {
						if( cInfo[ i ][ cID ] == IsComponentidCompatible( GetVehicleModel( vehicleid ), cInfo[ i ][ cID ] ) ) {
							compid = i;
							break;
						}
					}
				}
				if( compid == -1 ) return GRESKA( playerid, "Nema vise kompatibilnih komponenti izabrane vrste za vas model auta." );

				RemoveVehicleComponent( vehicleid, cInfo[ TPInfo[ playerid ][ tID ] ][ cID ] );

				TPInfo[ playerid ][ tID ] = compid;

				format( globalstring, sizeof( globalstring ), "%s", cInfo[ compid ][ cName ] );
				PlayerTextDrawSetString( playerid, TuningBuy[ playerid ][ 3 ], globalstring );

				AddVehicleComponent( vehicleid, cInfo[ compid ][ cID ] );

				SelectTextDraw( playerid, UGBOJA );
			}
			else if( TPInfo[ playerid ][ tPaintjob ] == true ) {

				new paintid = -1, vehicleid = GetPlayerVehicleID( playerid );

				for( new i = ( TPInfo[ playerid ][ tID ]+1 ); i < NUMBER_TYPE_PAINTJOB; i++ ) {
					if( pjInfo[ i ][ vehID ] == GetVehicleModel( vehicleid ) ) {
						paintid = i;
						break;
					}
				}
				if( paintid == -1 ) return GRESKA( playerid, "Nema vise kompatibilnih boja za vas model auta." );

				TPInfo[ playerid ][ tID ] = paintid;

				format( globalstring, sizeof( globalstring ), "%s", pjInfo[ paintid ][ pNameBre ] );
				PlayerTextDrawSetString( playerid, TuningBuy[ playerid ][ 3 ], globalstring );

				ChangeVehiclePaintjob( vehicleid, pjInfo[ paintid ][ pNumber ] );

				SelectTextDraw( playerid, UGBOJA );
			}
			return true;
		}
		if( playertextid == TuningBuy[ playerid ][ 8 ] ) { // levo
			if( TPInfo[ playerid ][ tPaintjob ] == false ) {

				if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate biti u vozilu." );
				if( GetPlayerState( playerid ) != PLAYER_STATE_DRIVER ) return GRESKA( playerid, "Morate biti na mjestu vozaca." );

				new compid = -1, vehicleid = GetPlayerVehicleID( playerid );

				for( new i = (TPInfo[ playerid ][ tID ]-1); i > 0; i-- ) {
					if( cInfo[ i ][ cType ] == TPInfo[ playerid ][ tType ] ) {
						if( cInfo[ i ][ cID ] == IsComponentidCompatible( GetVehicleModel( vehicleid ), cInfo[ i ][ cID ] ) ) {
							compid = i;
							break;
						}
					}
				}
				if( compid == -1 ) return GRESKA( playerid, "Nema vise kompatibilnih komponenti izabrane vrste za vas model auta." );

				RemoveVehicleComponent( vehicleid, cInfo[ TPInfo[ playerid ][ tID ] ][ cID ] );

				TPInfo[ playerid ][ tID ] = compid;

				format( globalstring, sizeof( globalstring ), "%s", cInfo[ compid ][ cName ] );
				PlayerTextDrawSetString( playerid, TuningBuy[ playerid ][ 3 ], globalstring );

				AddVehicleComponent( vehicleid, cInfo[ compid ][ cID ] );

				SelectTextDraw( playerid, UGBOJA );
			}
			else if( TPInfo[ playerid ][ tPaintjob ] == true ) {

				new paintid = -1, vehicleid = GetPlayerVehicleID( playerid );

				for( new i = (TPInfo[ playerid ][ tID ]-1); i > 0; i-- ) {
					if( pjInfo[ i ][ vehID ] == GetVehicleModel( vehicleid ) ) {
						paintid = i;
						break;
					}
				}
				if( paintid == -1 ) return GRESKA( playerid, "Nema vise kompatibilnih boja za vas model auta." );

				TPInfo[ playerid ][ tID ] = paintid;

				format( globalstring, sizeof( globalstring ), "%s", pjInfo[ paintid ][ pNameBre ] );
				PlayerTextDrawSetString( playerid, TuningBuy[ playerid ][ 3 ], globalstring );

				ChangeVehiclePaintjob( vehicleid, pjInfo[ paintid ][ pNumber ] );

				SelectTextDraw( playerid, UGBOJA );
			}
			return true;
		}
		if( playertextid == TuningBuy[ playerid ][ 9 ] ) { // buy
			if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate biti u vozilu." );
			if( GetPlayerState( playerid ) != PLAYER_STATE_DRIVER ) return GRESKA( playerid, "Morate biti na mjestu vozaca." );

			new Float:Pos[ 6 ], vehicleid = GetPlayerVehicleID( playerid );

			if( TPInfo[ playerid ][ tPaintjob ] == false ) {

				new cid = TPInfo[ playerid ][ tID ];

				RemoveVehicleComponent( vehicleid, cInfo[ TPInfo[ playerid ][ tID ] ][ cID ] );

				VehicleInfo[ vehicleid ][ vTuned ] = true;

				AddVehicleComponent( vehicleid, cInfo[ cid ][ cID ] );

				SavePlayerVehicleTuning(vehicleid, cInfo[ cid ][ cID ]);

			}
			else if( TPInfo[ playerid ][ tPaintjob ] == true ) {

				new paintid = TPInfo[ playerid ][ tID ];

				VehicleInfo[ vehicleid ][ vTuned ] = true;

				VehicleInfo[ vehicleid ][ vPaintJob ] = pjInfo[ paintid ][ pNumber ];

				ChangeVehicleColor( vehicleid, TPInfo[ playerid ][ PJColor ][ 0 ], TPInfo[ playerid ][ PJColor ][ 1 ] );

				ChangeVehiclePaintjob( vehicleid, pjInfo[ paintid ][ pNumber ] );

				VehicleInfo[ vehicleid ][ vPaintJob ] = pjInfo[ paintid ][ pNumber ];
				VehicleInfo[ vehicleid ][ vTuned ] = 1;
				VehicleInfo[ vehicleid ][ vColor1 ] = TPInfo[ playerid ][ PJColor ][ 0 ];
				VehicleInfo[ vehicleid ][ vColor2 ] = TPInfo[ playerid ][ PJColor ][ 1 ];
				SaveVehicle( vehicleid );

			}
			GetVehicleCameraPos( vehicleid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ], 0, 6, 2 );
			SetPlayerCameraPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

			GetVehiclePos( vehicleid, Pos[ 0 ],Pos[ 1 ],Pos[ 2 ] );
			SetPlayerCameraLookAt( playerid, Pos[ 0 ],Pos[ 1 ],Pos[ 2 ] );

			CancelSelectTextDraw( playerid );

			TuningTDShow( playerid, false );
			TogglePlayerControllable( playerid, true );

			ShowPlayerDialog( playerid, dialog_TUNING, DSL, D_NASLOV, "Paintjobs\nColors\nExhausts\nFront Bumper\nRear Bumper\nRoof\nSpoilers\nSide Skirts\nWheels\nCar Stereo\nHydraulics\nNitro", D_ODABERI, D_ODUSTANI );
			return true;
		}
		if( playertextid == TuningBuy[ playerid ][ 13 ] ) { // close

			if( !IsPlayerInAnyVehicle( playerid ) ) return GRESKA( playerid, "Morate biti u vozilu." );
			if( GetPlayerState( playerid ) != PLAYER_STATE_DRIVER ) return GRESKA( playerid, "Morate biti na mjestu vozaca." );

			new Float:Pos[ 6 ], vehicleid = GetPlayerVehicleID( playerid );

			if( TPInfo[ playerid ][ tPaintjob ] == false ) {

				RemoveVehicleComponent( vehicleid, cInfo[ TPInfo[ playerid ][ tID ] ][ cID ] );
			}
			else if( TPInfo[ playerid ][ tPaintjob ] == true ) {
				ChangeVehiclePaintjob( vehicleid, 3 );
				ChangeVehicleColor( vehicleid, TPInfo[ playerid ][ PJColor ][ 0 ], TPInfo[ playerid ][ PJColor ][ 1 ] );
			}
			
			GetVehicleCameraPos( vehicleid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ], 0, 6, 2 );
			SetPlayerCameraPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

			GetVehiclePos( vehicleid, Pos[ 0 ],Pos[ 1 ],Pos[ 2 ] );
			SetPlayerCameraLookAt( playerid, Pos[ 0 ],Pos[ 1 ],Pos[ 2 ] );

			CancelSelectTextDraw( playerid );

			TuningTDShow( playerid, false );
			TogglePlayerControllable( playerid, true );

			ShowPlayerDialog( playerid, dialog_TUNING, DSL, D_NASLOV, "Paintjobs\nColors\nExhausts\nFront Bumper\nRear Bumper\nRoof\nSpoilers\nSide Skirts\nWheels\nCar Stereo\nHydraulics\nNitro", D_ODABERI, D_ODUSTANI );
			return true;
		}
		//
		/*if( playertextid == atmTD[ playerid ][ 1 ] ) { // presecanje zica
			new atmid = GetNearestAtm( playerid );
			if( atmid == -1 ) return GRESKA( playerid, "Nisi pored bankomata." );
			if( atmInfo[ atmid ][ atmPreseceneZice ] == true ) return GRESKA( playerid, "Vec su presecene zice." );
			if( atmInfo[ atmid ][ atmVremeDoRoba ] != 0 ) return GRESKA( playerid, "Ovaj bankomat je vec opljackan." );
			if( GetWeapon( playerid ) != 4 ) return GRESKA( playerid, "Morate da imate noz u rukama" );

			atmrobTimer[ playerid ] = SetTimerEx( "RobZiceAtm", 1000, true, "d", playerid );
			robbingATM[ playerid ] = atmid;
			robbingATMSeconds[ playerid ] = 95;

			CancelSelectTextDraw( playerid );
			SendInfoMessage( playerid, "Poceli ste sa obijanjem bankomata, ne pomerajte se sa svog mesta." );
			return true;
		}
		if( playertextid == atmTD[ playerid ][ 2 ] ) { // ulazak u bios
			new atmid = GetNearestAtm( playerid );
			if( !LaptopRuke[ playerid ] ) return GRESKA( playerid, "Nemate laptop u rukama." );
			if( atmid == -1 ) return GRESKA( playerid, "Nisi pored bankomata." );
			if( atmInfo[ atmid ][ atmProbijenBios ] == true ) return GRESKA( playerid, "Vec je hakovan ovaj bankomat." );
			if( atmInfo[ atmid ][ atmVremeDoRoba ] != 0 ) return GRESKA( playerid, "Ovaj bankomat je vec opljackan." );
			

			
			robbingATM[ playerid ] = atmid;
			atmLoadingTDControl( playerid, true );
			
			//PlayerTextDrawSetString( playerid, atmrobLoading[ playerid ][ 1 ], "0%" );
			
			atmrobTimer[ playerid ] = SetTimerEx( "ProgresAtmBar", 1000, false, "d", playerid );
			
			CancelSelectTextDraw( playerid );
			return true;
		}
		if( playertextid == atmTD[ playerid ][ 3 ] ) { // kradja novca
			new atmid = GetNearestAtm( playerid );
			if( atmid == -1 ) return GRESKA( playerid, "Nisi pored bankomata." );
			if( atmInfo[ atmid ][ atmVremeDoRoba ] != 0 ) return GRESKA( playerid, "Ovaj bankomat je vec opljackan." );
			if( atmInfo[ atmid ][ atmPreseceneZice ] == true ) {
				new pokusaj = random(4);
				if( pokusaj == 1 ) {
					Dimi_KillTimer( atmrobTimer[ playerid ] );
					
					SendInfoMessage( playerid, "Niste uspeli ukrasti novac, alarm se oglasio." );
					PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );

					atmInfo[ atmid ][ atmVremeDoRoba ] = 60;
					SacuvajATM( atmid );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

					atmTDControl( playerid, false );
				}
				else {
					Dimi_KillTimer( atmrobTimer[ playerid ] );
					
					new money = ( random(5000)+5000 );
					DajIgracuNovac( playerid, money );
					SavePlayer( playerid ); UpdateBankTD( playerid );
					SendInfoMessage( playerid, "Uspjesno ste ukrali iz bankomata %d$.", money );
					PostaviWanted( playerid, "Pljacka bankomata", "Nepoznati", 3 );

					atmInfo[ atmid ][ atmVremeDoRoba ] = 120;
					SacuvajATM( atmid );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 120;

					atmTDControl( playerid, false );
				}
			}
			else if( atmInfo[ atmid ][ atmProbijenBios ] == true ) {
				new pokusaj = random(4);
				if( pokusaj == 1 ) {
					Dimi_KillTimer( atmrobTimer[ playerid ] );
					
					SendInfoMessage( playerid, "Niste uspeli prebaciti novac na vas racun, sistem zastite bankomata je ponovno podignut." );
					PostaviWanted( playerid, "Pokusaj pljacke bankomata", "Nepoznati", 3 );
					
					atmInfo[ atmid ][ atmVremeDoRoba ] = 60;
					SacuvajATM( atmid );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 60;

					atmTDControl( playerid, false );
				}
				else {
					Dimi_KillTimer( atmrobTimer[ playerid ] );
					
					new money = ( random(5000)+10000 );
					PlayerInfo[ playerid ][ xBRacun ] += money;
					SavePlayer( playerid ); UpdateBankTD( playerid );
					SendInfoMessage( playerid, "Uspjesno ste sa bankomata prebacili %d$ na vas racun.", money );
					PostaviWanted( playerid, "Pljacka bankomata", "Nepoznati", 3 );

					atmInfo[ atmid ][ atmVremeDoRoba ] = 120;
					SacuvajATM( atmid );
					PlayerInfo[ playerid ][ xPljackaVreme ] = 120;

					atmTDControl( playerid, false );
				}
			}
			else return GRESKA( playerid, "Moras prvo da hakujes bankomat ili da mu preseces zice." );
			return true;
		}*/
		//
		if( playertextid == buyWatch[ playerid ][ 3 ] ) {
			new text[ 30 ];
			if( WatchModel[ playerid ] == 19039 ) {
				if( PlayerInfo[ playerid ][ xNovac ] < 521 ) return GRESKA( playerid, "Nemate dovoljno novca." );
				DajIgracuNovac( playerid, -521 );
				text = "Rolex Datejust za 521$";
				PlayerInfo[ playerid ][ xSat ] = 19039;
			}
			else if( WatchModel[ playerid ] == 19040 ) {
				if( PlayerInfo[ playerid ][ xNovac ] < 618 ) return GRESKA( playerid, "Nemate dovoljno novca." );
				DajIgracuNovac( playerid, -618 );
				text = "Emporio Armani za 618$";
				PlayerInfo[ playerid ][ xSat ] = 19040;
			}
			else if( WatchModel[ playerid ] == 19041 ) {
				if( PlayerInfo[ playerid ][ xNovac ] < 723 ) return GRESKA( playerid, "Nemate dovoljno novca." );
				DajIgracuNovac( playerid, -723 );
				text = "Casio G-Shock za 723$";
				PlayerInfo[ playerid ][ xSat ] = 19041;
			}
			else if( WatchModel[ playerid ] == 19042 ) {
				if( PlayerInfo[ playerid ][ xNovac ] < 819 ) return GRESKA( playerid, "Nemate dovoljno novca." );
				DajIgracuNovac( playerid, -819 );
				text = "Michael Kors za 819$";
				PlayerInfo[ playerid ][ xSat ] = 19042;
			}
			else if( WatchModel[ playerid ] == 19043 ) {
				if( PlayerInfo[ playerid ][ xNovac ] < 916 ) return GRESKA( playerid, "Nemate dovoljno novca." );
				DajIgracuNovac( playerid, -916 );
				text = "Hugo Boss za 916$";
				PlayerInfo[ playerid ][ xSat ] = 19043;
			}
			
			SendInfoMessage( playerid, "Uspjesno si kupio sat marke %s.( koristi komandu /vrijeme ).", text );
			
			SavePlayer( playerid );
			
			buyWatchTDControl( playerid, false );
			return true;
		}
		if( playertextid == buyWatch[ playerid ][ 7 ] ) {
			SendInfoMessage( playerid, "Odustali ste od kupovine sata." );
			buyWatchTDControl( playerid, false );
			return true;
		}
		if( playertextid == buyWatch[ playerid ][ 4 ] ) {
			new text[ 30 ];
			if( WatchModel[ playerid ] == 19043 ) return 1;
			WatchModel[ playerid ]++;
			PlayerTextDrawSetPreviewModel( playerid, buyWatch[ playerid ][ 1 ], WatchModel[ playerid ] );
			PlayerTextDrawShow( playerid, buyWatch[ playerid ][ 1 ] );
			if( WatchModel[ playerid ] == 19039 ) text = "Rolex Datejust - 521$";
			else if( WatchModel[ playerid ] == 19040 ) text = "Emporio Armani - 618$";
			else if( WatchModel[ playerid ] == 19041 ) text = "Casio G-Shock - 723$";
			else if( WatchModel[ playerid ] == 19042 ) text = "Michael Kors - 819$";
			else if( WatchModel[ playerid ] == 19043 ) text = "Hugo Boss - 916$";
			PlayerTextDrawSetString( playerid, buyWatch[ playerid ][ 2 ], text );
			return true;
		}
		if( playertextid == buyWatch[ playerid ][ 5 ] ) {
			new text[ 30 ];
			if( WatchModel[ playerid ] == 19039 ) return 1;
			WatchModel[ playerid ]--;
			PlayerTextDrawSetPreviewModel( playerid, buyWatch[ playerid ][ 1 ], WatchModel[ playerid ] );
			PlayerTextDrawShow( playerid, buyWatch[ playerid ][ 1 ] );
			if( WatchModel[ playerid ] == 19039 ) text = "Rolex Datejust - 521$";
			else if( WatchModel[ playerid ] == 19040 ) text = "Emporio Armani - 618$";
			else if( WatchModel[ playerid ] == 19041 ) text = "Casio G-Shock - 723$";
			else if( WatchModel[ playerid ] == 19042 ) text = "Michael Kors - 819$";
			else if( WatchModel[ playerid ] == 19043 ) text = "Hugo Boss - 916$";
			PlayerTextDrawSetString( playerid, buyWatch[ playerid ][ 2 ], text );
			return true;
		}
		// 
		if( playertextid == Ormar[ playerid ][ 8 ] ) {
			if( II[ inProperty[ playerid ] ][ iSkin ][ 0 ] == GetPlayerSkin( playerid ) ) { II[ inProperty[ playerid ] ][ iSkin ][ 0 ] = 0; }
			if( II[ inProperty[ playerid ] ][ iSkin ][ 1 ] == GetPlayerSkin( playerid ) ) { II[ inProperty[ playerid ] ][ iSkin ][ 1 ] = 0; }
			if( II[ inProperty[ playerid ] ][ iSkin ][ 2 ] == GetPlayerSkin( playerid ) ) { II[ inProperty[ playerid ] ][ iSkin ][ 2 ] = 0; }

			SaveProperty( inProperty[ playerid ] );
			PlayerInfo[ playerid ][ xSkin ] = GetPlayerSkin( playerid );
			SendClientMessagee( playerid, UGBOJA, "Obukli ste drugu odecu. " );
			Dimi_SetPlayerPos( playerid, II[ inProperty[ playerid ] ][ iExit ][ 0 ], II[ inProperty[ playerid ] ][ iExit ][ 1 ], II[ inProperty[ playerid ] ][ iExit ][ 2 ] );
			SetPlayerInterior( playerid, II[ inProperty[ playerid ] ][ iInterior ] );
			SetPlayerVirtualWorld( playerid, II[ inProperty[ playerid ] ][ iVW ] );
			ClearAnimations( playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, false );
			CancelSelectTextDraw( playerid );
			OrmarTDControl( playerid, false );
			TogglePlayerControllable( playerid, true );
			return true;
		}
		if( playertextid == Ormar[ playerid ][ 3 ] ) {
			if( II[ inProperty[ playerid ] ][ iSkin ][ 0 ] == 0 ) return GRESKA( playerid, " U ovom slotu nemate odecu." );
			SetPlayerSkin( playerid, II[ inProperty[ playerid ] ][ iSkin ][ 0 ] ); ApplyAnimation( playerid, "CLOTHES","CLO_Pose_Legs",4.1,1,0,0,0,0, 1);
			return true;
		}
		if( playertextid == Ormar[ playerid ][ 4 ] ) {
			if( II[ inProperty[ playerid ] ][ iSkin ][ 1 ] == 0 ) return GRESKA( playerid, " U ovom slotu nemate odecu." );
			SetPlayerSkin( playerid, II[ inProperty[ playerid ] ][ iSkin ][ 1 ] ); ApplyAnimation( playerid, "CLOTHES","CLO_Pose_Legs",4.1,1,0,0,0,0, 1);
			return true;
		}
		if( playertextid == Ormar[ playerid ][ 5 ] ) {
			if( II[ inProperty[ playerid ] ][ iSkin ][ 2 ] == 0 ) return GRESKA( playerid, " U ovom slotu nemate odecu." );
			SetPlayerSkin( playerid, II[ inProperty[ playerid ] ][ iSkin ][ 2 ] ); ApplyAnimation( playerid, "CLOTHES","CLO_Pose_Legs",4.1,1,0,0,0,0, 1);
			return true;
		}
		if( playertextid == Ormar[ playerid ][ 9 ] ) {
			Dimi_SetPlayerPos( playerid, II[ inProperty[ playerid ] ][ iExit ][ 0 ], II[ inProperty[ playerid ] ][ iExit ][ 1 ], II[ inProperty[ playerid ] ][ iExit ][ 2 ] );
			SetPlayerInterior( playerid, II[ inProperty[ playerid ] ][ iInterior ] );
			SetPlayerVirtualWorld( playerid, II[ inProperty[ playerid ] ][ iVW ] );
			SendClientMessagee( playerid, UGBOJA, "Odustali ste od oblacenja nove odece. " );
			SetPlayerSkin( playerid, PlayerInfo[ playerid ][ xSkin ] );
			ClearAnimations( playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, false );
			CancelSelectTextDraw( playerid );
			OrmarTDControl( playerid, false );
			TogglePlayerControllable( playerid, true );
			return true;
		}
		if( playertextid == ObjektTD[ playerid ][ 4 ] ) {
			if( ListaoObjekte[ playerid ] == 0 ) return 1;
			ListaoObjekte[ playerid ]--;
			new i = ListaoObjekte[ playerid ];
			DestroyObject( glavniobjekt );
			glavniobjekt = CreateObject( OBPR[ i ][ 0 ], OBPR1[ i ][ 0 ], OBPR1[ i ][ 1 ], OBPR1[ i ][ 2 ],  OBPR1[ i ][ 3 ], OBPR1[ i ][4], OBPR1[ i ][5] );

			format( globalstring, sizeof( globalstring ), "cena: ~w~%d$", OBPR[ i ][ 1 ] );
			PlayerTextDrawSetString( playerid, ObjektTD[ playerid ][ 1 ], globalstring );
			return true;
		}
		if( playertextid == ObjektTD[ playerid ][ 2 ] ) {

			if( ListaoObjekte[ playerid ] == (MAX_OBJ_FURNITURE-1) ) return 1;
			ListaoObjekte[ playerid ]++;
			new i = ListaoObjekte[ playerid ];
			DestroyObject( glavniobjekt );
			glavniobjekt = CreateObject( OBPR[ i ][ 0 ], OBPR1[ i ][ 0 ], OBPR1[ i ][ 1 ], OBPR1[ i ][ 2 ],  OBPR1[ i ][ 3 ], OBPR1[ i ][4], OBPR1[ i ][5] );

			format( globalstring, sizeof( globalstring ), "cena: ~w~%d$", OBPR[ i ][ 1 ] );
			PlayerTextDrawSetString( playerid, ObjektTD[ playerid ][ 1 ], globalstring );
			return true;
		}
		if( playertextid == ObjektTD[ playerid ][ 5 ] ) {
			new i = ListaoObjekte[ playerid ];

			if( ServerInfo[ Namestaj ] == 0 ) return GRESKA( playerid, "Nema vise namestaja u resursima za namestaje." );

			if( PlayerInfo[ playerid ][ xNovac ] < OBPR[ i ][ 1 ] ) return GRESKA( playerid, " Nemate dovoljno novca." );
			if( PlayerInfo[ playerid ][ xObject ][ 0 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 0 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 1 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 1 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 2 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 2 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 3 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 3 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 4 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 4 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 5 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 5 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 6 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 6 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 7 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 7 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 8 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 8 ] = OBPR[ i ][ 0 ]; }
			else if( PlayerInfo[ playerid ][ xObject ][ 9 ] == -1 ) { PlayerInfo[ playerid ][ xObject ][ 9 ] = OBPR[ i ][ 0 ]; }
			else { GRESKA( playerid, "Vec ste kupili 10 objekta, nema mesta vise u kamionu." ); return 1; }
			DajIgracuNovac( playerid, -OBPR[ i ][ 1 ] );
			SendClientMessagee( playerid, UGBOJA, "Uspjesno ste kupili namestaj!" );
			SendClientMessagee( playerid, UGBOJA, "Na mjestu gdje zelite postaviti namestaj, upisite /namestaj postavi" );
			SendClientMessagee( playerid, UGBOJA, "Mozete kupiti 10 namestaja odjednom." );
			ServerInfo[ Namestaj ] -= 1;
			SaveServerStats( );
			return true;
		}
		if( playertextid == ObjektTD[ playerid ][ 3 ] ) {

			nekokupujenamestaj = 0;
			KupujeNamestaj[ playerid ] = 0;
			ListaoObjekte[ playerid ] = 0;
			TogglePlayerControllable( playerid, true );
			SetCameraBehindPlayer( playerid );
			CancelSelectTextDraw( playerid );
			ObjektTDControl( playerid, false );
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 3 ] )
		 {
			ShowPlayerDialog( playerid, dialog_SEARCH_NAME, DSI, D_NASLOV, "Upisite Ime i prezime gradjanina(Ime_Prezime) kojega zelite potraziti u bazi podataka:", D_ODABERI, D_ODUSTANI );
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 6 ] )
		 {
			ShowPlayerDialog( playerid, dialog_SEARCH_NUMBERPLATE, DSI, D_NASLOV, "Unesite broj tablice u prazno polje.(bez nula-00 i bez LS( samo broj ) )", D_ODABERI, D_ODUSTANI );
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 13 ] )
		 {
			Police_TVTDControl( playerid, false );
			CancelSelectTextDraw( playerid );
			SetPVarInt( playerid, "Computer", 0 );
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 12 ] )
		 {
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
			strcat( DialogStrgEx, "|_______-=Popis svih osumnjicenih=-________|\n" );
			for(new i; i < MAX_PLAYERS; i++)
			{
				if( IsPlayerConnected( i ) )
				{
					if( PlayerInfo[ i ][ xWanted ] > 0 )
					{
						format( globalstring, sizeof( globalstring ), "- %s | Wanted Level: %d\n", ImeIgraca( i ), PlayerInfo[ i ][ xWanted ] );
						strcat( DialogStrgEx, globalstring );
					}
				}
			}
			ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, DialogStrgEx, "U redu", "" );
			strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 8 ] )
		 {
			if(GetPVarInt( playerid, "RequestingBackup") != 1)
			 {
				format( globalstring, sizeof( globalstring ), "SVE JEDINICE: %s trazi pojacanje i oznacen je na GPSu (crveno).", ImeIgraca( playerid ) );
				SetPVarInt( playerid, "RequestingBackup", 1);

				for(new i; i < MAX_PLAYERS; i++)
				{
					if( IsPlayerConnected(i))
					{
						if( OI[ PlayerInfo[ i ][ xClan ] ][ oTip ] == ORG_TIP_PD )
						{
							SetPlayerMarkerForPlayer( i, playerid, 0xFF0000FF );
							SendClientMessagee( i, 0x8D8DFF00, globalstring );
						}
					}
				}
				SendClientMessagee( playerid, 0x8D8DFF00, "Ukucajte /bkc da bi ste izbrisali pojacanje." );
				backuptimer[ playerid ] = SetTimerEx( "BackupClear", 180000, false, "ii", playerid, 1 );
			} else GRESKA( playerid, "Vec imate aktivan zahjtev za pojacanje!");
			return true;
		}
		if( playertextid == Police_TV[ playerid ][ 10 ] )
		 {
			ShowPlayerDialog( playerid, dialog_POSTAVIPOTERU, DSI, D_NASLOV, "Upisite Ime i prezime gradjanina(Ime_Prezime) i razlog za potjeru.", D_ODABERI, D_ODUSTANI );
			return true;
		}
		//
		if( playertextid == PizzaMenu[ playerid ][ 7 ] ) {
		
			if( PlayerInfo[ playerid ][ xNovac ] < 67 ) return GRESKA( playerid, "Nemate dovoljno novca 67$!");
			BussinesMoney( uFirmi[ playerid ] , 67 );
			DajIgracuNovac( playerid, -67 );
			DajIgracuGlad( playerid, 13 );
			DodajIgracuHP( playerid, 30 );
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		if( playertextid == PizzaMenu[ playerid ][ 10 ] ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 79) return GRESKA( playerid, "Nemate dovoljno novca 79$!");
			BussinesMoney( uFirmi[ playerid ] , 79);
			DajIgracuNovac( playerid, -79 );
			DajIgracuGlad( playerid, 14 );
			DodajIgracuHP( playerid, 30 );
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		if( playertextid == PizzaMenu[ playerid ][ 13 ] ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 81) return GRESKA( playerid, "Nemate dovoljno novca 81$!");
			
			BussinesMoney( uFirmi[ playerid ] , 81);
			DajIgracuNovac( playerid, -81 );
			DajIgracuGlad( playerid, 15 );
			DodajIgracuHP( playerid, 30 );
			
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		if( playertextid == PizzaMenu[ playerid ][ 16 ] ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 89) return GRESKA( playerid, "Nemate dovoljno novca 89$!");
			
			BussinesMoney( uFirmi[ playerid ] , 89);
			DajIgracuNovac( playerid, -89 );
			DajIgracuGlad( playerid, 16 );
			DodajIgracuHP( playerid, 30 );
			
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		if( playertextid == PizzaMenu[ playerid ][ 19 ] ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 98) return GRESKA( playerid, "Nemate dovoljno novca 98$!");
			
			BussinesMoney( uFirmi[ playerid ] , 98);
			DajIgracuNovac( playerid, -98 );
			DajIgracuGlad( playerid, 17 );
			DodajIgracuHP( playerid, 30 );
			
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		if( playertextid == PizzaMenu[ playerid ][ 22 ] ) {

			if( PlayerInfo[ playerid ][ xNovac ] < 108) return GRESKA( playerid, "Nemate dovoljno novca 108$!");
			
			BussinesMoney( uFirmi[ playerid ] , 108);
			DajIgracuNovac( playerid, -108 );
			DajIgracuGlad( playerid, 18 );
			DodajIgracuHP( playerid, 30 );
			
			format( globalstring, sizeof( globalstring ), "* %s uzima kupljene stvari od prodavacice i jede.", ImeIgraca( playerid ) );
			PorukaRadius( 15.0, playerid, globalstring, LJUBICASTA );
			OnePlayAnim( playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
			PizzaMenuTDControl( playerid, false );
			return true;
		}
		//--------------------stats---------------------------------------------
	   /* if( playertextid == PlayerStats[ 3 ][ playerid ] || playertextid == PlayerStats[ 4 ][ playerid ] ) {
		
			if( StatsTDShowed[ playerid ] == true )  {
		
				new vrednost;
				
				if( playertextid == PlayerStats[ 3 ][ playerid ] ) {

					if( StatsList[ playerid ] == 5 ) return 1;
					vrednost = 1;
					StatsList[ playerid ]++;
				}
				else if( playertextid == PlayerStats[ 4 ][ playerid ] ) {
				
					if( StatsList[ playerid ] == 1 ) return 1;
					vrednost = 2;
					StatsList[ playerid ]--;
				}

				if( StatsList[ playerid ] == 1 ) {

					PlayerTextDrawHide( playerid, PlayerStats[ 10 ][ playerid ] );
					PlayerTextDrawDestroy( playerid, PlayerStats[ 10 ][ playerid ] );
					PlayerTextDrawHide( playerid, PlayerStats[ 11 ][ playerid ] );
					PlayerTextDrawDestroy( playerid, PlayerStats[ 11 ][ playerid ] );

					new nxtlevel = PlayerInfo[ playerid ][ xLevel ]+1,
						expamount = nxtlevel*levelexp,
						exp = PlayerInfo[ playerid ][ xRespekt ],
						str[ 1024 ], promoter[ 10 ];

					if( PlayerInfo[ playerid ][ xPromoter ] == 0 ) promoter = "Ne";
					else if( PlayerInfo[ playerid ][ xPromoter ] == 1 ) promoter = "Da";

					PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "ooc stats");
					PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "ooc stats");

					format( str, sizeof( str ), "~w~Level: ~r~%d~n~~w~Sati igranja: ~r~%d~n~~w~Respekti: ~r~%d/%d~n~~w~Spawn Health: ~r~%.2f~n~~w~Admin Level: ~r~%d~n~~w~GM Level: ~r~%d~n~~w~VIP level: ~r~%d~n~~w~Vrijeme do plate: ~r~%d min~n~~w~Upozorenja ~r~%d/5~n~~w~Promoter: ~r~%s~n~~w~RP Poeni: ~r~%d~n~~w~APoeni: ~r~%d",
						PlayerInfo[ playerid ][ xLevel ],
						PlayerInfo[ playerid ][ xOnlineSati ],
						exp,
						expamount,
						(50+PlayerInfo[ playerid ][ xSHealth ]),
						PlayerInfo[ playerid ][ xAdmin ],
						PlayerInfo[ playerid ][ xHelper ],
						PlayerInfo[ playerid ][ xVIPLevel ],
						(60-PlayerInfo[ playerid ][ xPayDay ]),
						PlayerInfo[ playerid ][ xWarn ],
						promoter,
						PlayerInfo[ playerid ][ xRPPoen ],
						PlayerInfo[ playerid ][ xApoeni ] );


					PlayerTextDrawSetString( playerid, PlayerStats[ 7 ][ playerid ], str );

					PlayerTextDrawSetString( playerid, PlayerStats[ 8 ][ playerid ], ImeIgraca( playerid ) );

					format( promoter, sizeof( promoter ), "%d", PlayerInfo[ playerid ][ xSkin ] );
					PlayerTextDrawSetString( playerid, PlayerStats[ 9 ][ playerid ], promoter );
					
					new str1[ 256 ];
					format( str1, sizeof( str1 ), "~r~Event statistika~n~~w~ ~n~~w~Osvojena 1 mesta: ~r~%d~n~~w~Osvojena 2 mesta: ~r~%d~n~~w~Osvojena 3 mesta: ~r~%d~n~~w~Ubistva u DM zoni: ~r~%d", PlayerInfo[ playerid ][ xEvent1Mesto ], PlayerInfo[ playerid ][ xEvent2Mesto ], PlayerInfo[ playerid ][ xEvent3Mesto ], PlayerInfo[ playerid ][ xDMEventUbistva ] );

					PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 319.125000, 305.833099, str1 );
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 10 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);
					
					PlayerTextDrawShow( playerid, PlayerStats[ 10 ][ playerid ] );

				}
				else if( StatsList[ playerid ] == 2 ) {
				
					if( vrednost == 1 ) {
					
						PlayerTextDrawHide( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 10 ][ playerid ] );
					
						new fakultet[5], srednja[5], osnovna[5], pol[ 7 ];

						if( PlayerInfo[ playerid ][ xFakultet ] == 15 ) fakultet = "Ima";
						else fakultet = "Nema";
						if( PlayerInfo[ playerid ][ xSrednja ] == 6 ) srednja = "Ima";
						else srednja = "Nema";
						if( PlayerInfo[ playerid ][ xOsnovna ] == 3 ) osnovna = "Ima";
						else osnovna = "Nema";

						if( PlayerInfo[ playerid ][ xPol ] == 1 ) pol = "musko";
						else if( PlayerInfo[ playerid ][ xPol ] == 2 ) pol = "zensko";


						PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "ic stats");
						PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "ic stats");

						new str[ 1024 ];
						format( str, sizeof( str ), "~w~Pol: ~r~%s~n~~w~Godine: ~r~%d~n~~w~Novac: ~r~%d$~n~~w~Novac u banci: ~r~%d$~n~~w~Broj telefona: ~r~%d~n~~w~Osnovna skola: ~r~%s~n~~w~Srednja skola: ~r~%s~n~~w~Fakultet: ~r~%s~n~~w~Uhapsen: ~r~%d~n~~w~Ozenjen/Udana: ~r~%s~n~~w~Materijali: ~r~%d",
							pol,
							PlayerInfo[ playerid ][ xGodine ],
							PlayerInfo[ playerid ][ xNovac ],
							PlayerInfo[ playerid ][ xBRacun ],
							PlayerInfo[ playerid ][ xBrojTelefona ],
							osnovna, srednja, fakultet,
							PlayerInfo[ playerid ][ xUhapsen ],
							PlayerInfo[ playerid ][ xMarriedTo ],
							PlayerInfo[ playerid ][ xMaterijali] );
					
						PlayerTextDrawSetString( playerid, PlayerStats[ 7 ][ playerid ], str );

						PlayerTextDrawSetString( playerid, PlayerStats[ 8 ][ playerid ], ImeIgraca( playerid ) );

						format( pol, sizeof( pol ), "%d", PlayerInfo[ playerid ][ xSkin ] );
						PlayerTextDrawSetString( playerid, PlayerStats[ 9 ][ playerid ], pol );
						
						PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 269.750000, 260.333435, "rot0");
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.449999, 1.600000);
						PlayerTextDrawTextSize(playerid, PlayerStats[ 10 ][ playerid ], 94.375000, 71.166633);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
						PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
						PlayerTextDrawUseBox(playerid, PlayerStats[ 10 ][ playerid ], true);
						PlayerTextDrawBoxColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
						PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 5);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);
						
						switch( PlayerInfo[ playerid ][ xPosao ] ) {
							case POSAO_NEMA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], -1 );
							case POSAO_MEHANICAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 525 );
							case POSAO_MASINOVODJA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 538 );
							case POSAO_PREVOZNIK: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 515 );
							case POSAO_KOSAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 572 );
							case POSAO_KOMUNALAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 408 );
							case POSAO_GRADJEVINAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 486 );
							case POSAO_PIZZA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 448 );
							case POSAO_PILOT: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 519 );
							case POSAO_FARMER: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 531 );
							case POSAO_BUSVOZAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 431 );
							case POSAO_RUDAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 455 );
							case POSAO_PREVOZNOVCA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 428 );
							case POSAO_RIBAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 473 );
							case POSAO_PNAMESTAJA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 578 );
							case POSAO_TEMPODOSTAVA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 498 );
						}
						
						PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 10 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);


						format( globalstring, sizeof( globalstring ), "~r~%s~n~~w~Ugovor: ~r~%d/3", getJobName( PlayerInfo[ playerid ][ xPosao ] ), PlayerInfo[ playerid ][ xUgovor ] );

						PlayerStats[ 11 ][ playerid ] = CreatePlayerTextDraw(playerid, 319.125000, 326.833099, globalstring );
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 11 ][ playerid ], 0.318748, 0.888331);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 11 ][ playerid ], 2);
						PlayerTextDrawColor(playerid, PlayerStats[ 11 ][ playerid ], -1);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 11 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 11 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 11 ][ playerid ], 51);
						PlayerTextDrawFont(playerid, PlayerStats[ 11 ][ playerid ], 3);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 11 ][ playerid ], 1);
						
						PlayerTextDrawShow( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 11 ][ playerid ] );
					}
					else if( vrednost == 2 ) {
					
						PlayerTextDrawHide( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 10 ][ playerid ] );

						new fakultet[5], srednja[5], osnovna[5], pol[ 7 ];

						if( PlayerInfo[ playerid ][ xFakultet ] == 15 ) fakultet = "Ima";
						else fakultet = "Nema";
						if( PlayerInfo[ playerid ][ xSrednja ] == 6 ) srednja = "Ima";
						else srednja = "Nema";
						if( PlayerInfo[ playerid ][ xOsnovna ] == 3 ) osnovna = "Ima";
						else osnovna = "Nema";

						if( PlayerInfo[ playerid ][ xPol ] == 1 ) pol = "musko";
						else if( PlayerInfo[ playerid ][ xPol ] == 2 ) pol = "zensko";


						PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "ic stats");
						PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "ic stats");

						new str[ 1024 ];
						format( str, sizeof( str ), "~w~Pol: ~r~%s~n~~w~Godine: ~r~%d~n~~w~Novac: ~r~%d$~n~~w~Novac u banci: ~r~%d$~n~~w~Broj telefona: ~r~%d~n~~w~Osnovna skola: ~r~%s~n~~w~Srednja skola: ~r~%s~n~~w~Fakultet: ~r~%s~n~~w~Uhapsen: ~r~%d~n~~w~Ozenjen/Udana: ~r~%s~n~~w~Materijali: ~r~%d",
							pol,
							PlayerInfo[ playerid ][ xGodine ],
							PlayerInfo[ playerid ][ xNovac ],
							PlayerInfo[ playerid ][ xBRacun ],
							PlayerInfo[ playerid ][ xBrojTelefona ],
							osnovna, srednja, fakultet,
							PlayerInfo[ playerid ][ xUhapsen ],
							PlayerInfo[ playerid ][ xMarriedTo ],
							PlayerInfo[ playerid ][ xMaterijali ] );

						PlayerStats[ 1 ][ playerid ] = CreatePlayerTextDraw(playerid, 366.250000, 130.083358, "New Textdraw");
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 1 ][ playerid ], 0.449999, 1.600000);
						PlayerTextDrawTextSize(playerid, PlayerStats[ 1 ][ playerid ], 123.125000, 112.583328);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 1 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 1 ][ playerid ], 0);
						PlayerTextDrawColor(playerid, PlayerStats[ 1 ][ playerid ], -1);
						PlayerTextDrawUseBox(playerid, PlayerStats[ 1 ][ playerid ], true);
						PlayerTextDrawBoxColor(playerid, PlayerStats[ 1 ][ playerid ], 0);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 1 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 1 ][ playerid ], 1);
						PlayerTextDrawFont(playerid, PlayerStats[ 1 ][ playerid ], 5);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 1 ][ playerid ], 1);
						PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 1 ][ playerid ], PlayerInfo[ playerid ][ xSkin ] );
						PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 1 ][ playerid ], 0.000000, 0.000000, -30.000000, 1.000000);
						PlayerTextDrawSetSelectable(playerid,PlayerStats[ 1 ][ playerid ], 0);

						PlayerStats[ 7 ][ playerid ] = CreatePlayerTextDraw(playerid, 163.875000, 162.416458, str );
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 7 ][ playerid ], 0.318748, 0.888331);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 7 ][ playerid ], 1);
						PlayerTextDrawColor(playerid, PlayerStats[ 7 ][ playerid ], -1);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 7 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 7 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 7 ][ playerid ], 51);
						PlayerTextDrawFont(playerid, PlayerStats[ 7 ][ playerid ], 3);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 7 ][ playerid ], 1);

						PlayerStats[ 8 ][ playerid ] = CreatePlayerTextDraw(playerid, 427.375000, 246.833084, ImeIgraca( playerid ) );
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 8 ][ playerid ], 0.277498, 0.806665);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 8 ][ playerid ], 2);
						PlayerTextDrawColor(playerid, PlayerStats[ 8 ][ playerid ], -1);
						PlayerTextDrawUseBox(playerid, PlayerStats[ 8 ][ playerid ], true);
						PlayerTextDrawBoxColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 8 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 8 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 8 ][ playerid ], 51);
						PlayerTextDrawFont(playerid, PlayerStats[ 8 ][ playerid ], 2);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 8 ][ playerid ], 1);

						format( pol, sizeof( pol ), "%d", PlayerInfo[ playerid ][ xSkin ] );
						PlayerStats[ 9 ][ playerid ] = CreatePlayerTextDraw(playerid, 440.250000, 137.583114, pol );
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 9 ][ playerid ], 0.277498, 0.806665);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 9 ][ playerid ], 1);
						PlayerTextDrawColor(playerid, PlayerStats[ 9 ][ playerid ], -1);
						PlayerTextDrawUseBox(playerid, PlayerStats[ 9 ][ playerid ], true);
						PlayerTextDrawBoxColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 9 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 9 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 9 ][ playerid ], 51);
						PlayerTextDrawFont(playerid, PlayerStats[ 9 ][ playerid ], 2);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 9 ][ playerid ], 1);
						
						PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 269.750000, 260.333435, "rot0");
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.449999, 1.600000);
						PlayerTextDrawTextSize(playerid, PlayerStats[ 10 ][ playerid ], 94.375000, 71.166633);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
						PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
						PlayerTextDrawUseBox(playerid, PlayerStats[ 10 ][ playerid ], true);
						PlayerTextDrawBoxColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
						PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 5);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);

						switch( PlayerInfo[ playerid ][ xPosao ] ) {
							case POSAO_NEMA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], -1 );
							case POSAO_MEHANICAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 525 );
							case POSAO_MASINOVODJA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 538 );
							case POSAO_PREVOZNIK: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 515 );
							case POSAO_KOSAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 572 );
							case POSAO_KOMUNALAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 408 );
							case POSAO_GRADJEVINAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 486 );
							case POSAO_PIZZA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 448 );
							case POSAO_PILOT: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 519 );
							case POSAO_FARMER: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 531 );
							case POSAO_BUSVOZAC: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 431 );
							case POSAO_RUDAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 455 );
							case POSAO_PREVOZNOVCA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 428 );
							case POSAO_RIBAR: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 473 );
							case POSAO_PNAMESTAJA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 578 );
							case POSAO_TEMPODOSTAVA: PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 498 );
						}

						PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 10 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);


						format( globalstring, sizeof( globalstring ), "~r~%s~n~~w~Ugovor: ~r~%d/3", getJobName( PlayerInfo[ playerid ][ xPosao ] ), PlayerInfo[ playerid ][ xUgovor ] );

						PlayerStats[ 11 ][ playerid ] = CreatePlayerTextDraw(playerid, 319.125000, 326.833099, globalstring );
						PlayerTextDrawLetterSize(playerid, PlayerStats[ 11 ][ playerid ], 0.318748, 0.888331);
						PlayerTextDrawAlignment(playerid, PlayerStats[ 11 ][ playerid ], 2);
						PlayerTextDrawColor(playerid, PlayerStats[ 11 ][ playerid ], -1);
						PlayerTextDrawSetShadow(playerid, PlayerStats[ 11 ][ playerid ], 0);
						PlayerTextDrawSetOutline(playerid, PlayerStats[ 11 ][ playerid ], 1);
						PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 11 ][ playerid ], 51);
						PlayerTextDrawFont(playerid, PlayerStats[ 11 ][ playerid ], 3);
						PlayerTextDrawSetProportional(playerid, PlayerStats[ 11 ][ playerid ], 1);

						PlayerTextDrawShow( playerid, PlayerStats[ 1 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawShow( playerid, PlayerStats[ 11 ][ playerid ] );
					}

				}
				else if( StatsList[ playerid ] == 3 ) {

					if( vrednost == 1 ) {
					
						PlayerTextDrawHide( playerid, PlayerStats[ 1 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 1 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 11 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 11 ][ playerid ] );
						
					}
					else if( vrednost == 2 ) {
					
						PlayerTextDrawHide( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 7 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 8 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 9 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 10 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 11 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 11 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 12 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 12 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 13 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 13 ][ playerid ] );
						PlayerTextDrawHide( playerid, PlayerStats[ 14 ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ 14 ][ playerid ] );
					}
					
					PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "organizacija");
					PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "organizacija");

					PlayerStats[ 7 ][ playerid ] = CreatePlayerTextDraw(playerid, 284.750000, 248.333282, "rot30,1.0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 7 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 7 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 7 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 7 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 7 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 7 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 7 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 7 ][ playerid ], 0);
					
					if( PlayerInfo[ playerid ][ xClan ] != 0 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 7 ][ playerid ], OI[ PlayerInfo[ playerid ][ xClan ] ][ oSkin5 ] );
					else PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 7 ][ playerid ], -1 );
					
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 7 ][ playerid ], 0.000000, 0.000000, 30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 7 ][ playerid ], 0);

					PlayerStats[ 8 ][ playerid ] = CreatePlayerTextDraw(playerid, 221.375000, 248.749954, "rot_-30");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 8 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 8 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 8 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 8 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 8 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
					
					if( PlayerInfo[ playerid ][ xClan ] != 0 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 8 ][ playerid ], OI[ PlayerInfo[ playerid ][ xClan ] ][ oSkin4 ] );
					else PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 8 ][ playerid ], -1 );
					
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 8 ][ playerid ], 0.000000, 0.000000, -30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 8 ][ playerid ], 0);

					PlayerStats[ 9 ][ playerid ] = CreatePlayerTextDraw(playerid, 254.875000, 249.166641, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 9 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 9 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 9 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 9 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawFont(playerid, PlayerStats[ 9 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 9 ][ playerid ], 1);
					
					if( PlayerInfo[ playerid ][ xClan ] != 0 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 9 ][ playerid ], OI[ PlayerInfo[ playerid ][ xClan ] ][ oSkin6 ] );
					else PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 9 ][ playerid ], -1 );
					
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 9 ][ playerid ], 0.000000, 0.000000, 0.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 9 ][ playerid ], 0);

					new string[ 256 ];

					format( string, sizeof( string ), "~w~Organizacija: ~r~%s~n~~w~Rank: ~r~%s~n~~w~Vrijeme u org: ~r~%dh~n~~w~Kazneni ugovor: ~r~%dh",
						getOrgName( PlayerInfo[ playerid ][ xClan ] ),
						getOrgRank( playerid, PlayerInfo[ playerid ][ xClan ] ),
						PlayerInfo[ playerid ][ xOrgUgovor ],
						PlayerInfo[ playerid ][ xKazneniUgovor ]  );

					PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 314.250000, 173.916488, string );
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 10 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 10 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);

					PlayerTextDrawShow( playerid, PlayerStats[ 7 ][ playerid ] );
					PlayerTextDrawShow( playerid, PlayerStats[ 8 ][ playerid ] );
					PlayerTextDrawShow( playerid, PlayerStats[ 9 ][ playerid ] );
					PlayerTextDrawShow( playerid, PlayerStats[ 10 ][ playerid ] );
				}
				else if( StatsList[ playerid ] == 4 ) {
				
					if( vrednost == 1 ) {
						for( new i = 7; i < 11; i ++) {
							PlayerTextDrawHide( playerid, PlayerStats[ i ][ playerid ] );
							PlayerTextDrawDestroy( playerid, PlayerStats[ i ][ playerid ] );
						}
					}
					else if( vrednost == 2 ) {
						for( new i = 7; i < 32; i ++) {
							PlayerTextDrawHide( playerid, PlayerStats[ i ][ playerid ] );
							PlayerTextDrawDestroy( playerid, PlayerStats[ i ][ playerid ] );
						}
					}
				
					
					PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "vozila");
					PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "vozila");
					
					format( globalstring, sizeof( globalstring ), "slot 1: ~r~%s", getVehicleName( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ) );
					PlayerStats[ 7 ][ playerid ] = CreatePlayerTextDraw(playerid, 175.250000, 240.833190, globalstring );

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 7 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 7 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 7 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 7 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 7 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 7 ][ playerid ], 1);

					PlayerStats[ 8 ][ playerid ] = CreatePlayerTextDraw(playerid, 168.375000, 149.250091, "rot0");  // slot 1
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 8 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 8 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 8 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 8 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 8 ][ playerid ], true);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 8 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 8 ][ playerid ], 1);
					
					if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 8 ][ playerid ], VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vModel ] );
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] == -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 8 ][ playerid ], -1 );

					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 8 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 8 ][ playerid ], 0);

					PlayerStats[ 9 ][ playerid ] = CreatePlayerTextDraw(playerid, 343.750000, 150.833358, "rot0"); // slot 2
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 9 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 9 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 9 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 9 ][ playerid ], true);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 9 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 9 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 9 ][ playerid ], VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vModel ] );
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] == -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 9 ][ playerid ], -1 );

					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 9 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 9 ][ playerid ], 0);

					PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 169.125000, 245.166641, "rot0");   // slot 3
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 10 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 10 ][ playerid ], true);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vModel ] );
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] == -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], -1 );

					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 10 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 10 ][ playerid ], 0);

					PlayerStats[ 11 ][ playerid ] = CreatePlayerTextDraw(playerid, 354.375000, 244.749969, "rot0");  // slot 4
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 11 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 11 ][ playerid ], 123.125000, 112.583328);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 11 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 11 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 11 ][ playerid ], true);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 11 ][ playerid ], 0);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 11 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 11 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 11 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 11 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 11 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 11 ][ playerid ], VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vModel ] );
					else if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] == -1 ) PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 11 ][ playerid ], -1 );

					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 11 ][ playerid ], -10.000000, 0.000000, -30.000000, 1.000000);
					PlayerTextDrawSetSelectable(playerid,PlayerStats[ 11 ][ playerid ], 0);

					format( globalstring, sizeof( globalstring ), "slot 2: ~r~%s", getVehicleName( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ) );
					PlayerStats[ 12 ][ playerid ] = CreatePlayerTextDraw(playerid, 356.875000, 240.666534, globalstring );
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 12 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 12 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 12 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 12 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 12 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 12 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 12 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 12 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 12 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 12 ][ playerid ], 1);

					format( globalstring, sizeof( globalstring ), "slot 3: ~r~%s", getVehicleName( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ) );
					PlayerStats[ 13 ][ playerid ] = CreatePlayerTextDraw(playerid, 175.375000, 336.166778, globalstring );
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 13 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 13 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 13 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 13 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 13 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 13 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 13 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 13 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 13 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 13 ][ playerid ], 1);

					format( globalstring, sizeof( globalstring ), "slot 4: ~r~%s", getVehicleName( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ) );
					PlayerStats[ 14 ][ playerid ] = CreatePlayerTextDraw(playerid, 358.250000, 337.166503, globalstring );
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 14 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 14 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 14 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 14 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 14 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 14 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 14 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 14 ][ playerid ], 1);
					
					for( new i = 7; i < 15; i ++) {
						PlayerTextDrawShow( playerid, PlayerStats[ i ][ playerid ] );
					}
				
				}
				else if( StatsList[ playerid ] == 5 ) {

					for( new i = 7; i < 15; i ++) {
						PlayerTextDrawHide( playerid, PlayerStats[ i ][ playerid ] );
						PlayerTextDrawDestroy( playerid, PlayerStats[ i ][ playerid ] );
					}

					PlayerTextDrawSetString( playerid, PlayerStats[ 5 ][ playerid ], "nepokretna imovina");
					PlayerTextDrawSetString( playerid, PlayerStats[ 6 ][ playerid ], "imovina");

					if( PlayerInfo[ playerid ][ xFirmaID ] != -1 )
					{
					
						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xFirmaID ], BussinesInfo[ PlayerInfo[ playerid ][ xFirmaID ] ][ bName ] );
					
						PlayerStats[ 7 ][ playerid ] = CreatePlayerTextDraw(playerid, 203.125000, 329.333160, globalstring );
					}
					else
					{
						PlayerStats[ 7 ][ playerid ] = CreatePlayerTextDraw(playerid, 203.125000, 329.333160, "~r~(~w~ID: -1~r~)~n~~w~Nema Firme");
					}
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 7 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 7 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 7 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 7 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 7 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 7 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 7 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 7 ][ playerid ], 1);

					PlayerStats[ 8 ][ playerid ] = CreatePlayerTextDraw(playerid, 153.750000, 258.166748, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 8 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 8 ][ playerid ], 94.375000, 71.166633);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 8 ][ playerid ], 2);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawColor(playerid, PlayerStats[ 8 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 8 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 8 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 8 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 8 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 8 ][ playerid ], 1274 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 8 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 9 ][ playerid ] = CreatePlayerTextDraw(playerid, 269.750000, 260.333435, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 9 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 9 ][ playerid ], 94.375000, 71.166633);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 9 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 9 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 9 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 9 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 9 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 9 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 9 ][ playerid ], 1273 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 9 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 10 ][ playerid ] = CreatePlayerTextDraw(playerid, 387.000000, 263.083557, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 10 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 10 ][ playerid ], 94.375000, 71.166633);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 10 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 10 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 10 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 10 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 10 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 10 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 10 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 10 ][ playerid ], 1272 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 10 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					if( PlayerInfo[ playerid ][ xHotelID ] != -1 ) {

						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xHotelID ], hotelInfo[ PlayerInfo[ playerid ][ xHotelID ] ][ hAdress ] );

						PlayerStats[ 11 ][ playerid ] = CreatePlayerTextDraw(playerid, 319.125000, 326.833099, globalstring );
					}
					else {
						PlayerStats[ 11 ][ playerid ] = CreatePlayerTextDraw(playerid, 319.125000, 326.833099, "~r~(~w~ID: -1~r~)~n~~w~Nema Hotela");
					}

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 11 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 11 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 11 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 11 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 11 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 11 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 11 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 11 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xGarageID ] != -1 ) {

						new vrsta[ 20 ];
						switch( garageInfo[ PlayerInfo[ playerid ][ xGarageID ] ][ garageType ] ) {
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

						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xGarageID ], vrsta );

						PlayerStats[ 12 ][ playerid ] = CreatePlayerTextDraw(playerid, 435.125000, 326.666412, globalstring );
					}
					else {
						PlayerStats[ 12 ][ playerid ] = CreatePlayerTextDraw(playerid, 435.125000, 326.666412, "~r~(~w~ID: -1~r~)~n~~w~Nema Garaze");
					}

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 12 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 12 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 12 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 12 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 12 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 12 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 12 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 12 ][ playerid ], 1);

					PlayerStats[ 13 ][ playerid ] = CreatePlayerTextDraw(playerid, 338.625000, 141.583984, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 13 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 13 ][ playerid ], 185.625000, 149.916625);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 13 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 13 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 13 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 13 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 13 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 13 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 13 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 13 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 13 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 )
					{

						if( II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iUsage ] == IMOVINA_KUCA )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 13 ][ playerid ], 19522 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iUsage ] == IMOVINA_STAN )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 13 ][ playerid ], 19523 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iUsage ] == IMOVINA_VIKENDICA )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 13 ][ playerid ], 19524 );
						}

					}
					else
					{
						PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 13 ][ playerid ], 19522 );
					}
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 13 ][ playerid ], 0.000000, 0.000000, 0.000000, 1.000000);

					if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {

						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xProperty ][ 2 ], II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iAdress ] );

						PlayerStats[ 14 ][ playerid ] = CreatePlayerTextDraw(playerid, 434.250000, 243.666244, globalstring );
					}
					else {
						PlayerStats[ 14 ][ playerid ] = CreatePlayerTextDraw(playerid, 434.250000, 243.666244, "~r~(~w~ID: -1~r~)~n~~w~Nema Imovine");
					}

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 14 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 14 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 14 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 14 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 14 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 14 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 14 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 14 ][ playerid ], 1);

					PlayerStats[ 15 ][ playerid ] = CreatePlayerTextDraw(playerid, 221.500000, 137.917297, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 15 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 15 ][ playerid ], 185.625000, 149.916625);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 15 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 15 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 15 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 15 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 15 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 15 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 15 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 15 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 15 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 )
					{

						if( II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iUsage ] == IMOVINA_KUCA )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 15 ][ playerid ], 19522 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iUsage ] == IMOVINA_STAN )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 15 ][ playerid ], 19523 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iUsage ] == IMOVINA_VIKENDICA )
						{

							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 15 ][ playerid ], 19524 );
						}

					}
					else {
						PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 15 ][ playerid ], 19522 );
					}
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 15 ][ playerid ], 0.000000, 0.000000, 0.000000, 1.000000);

					PlayerStats[ 16 ][ playerid ] = CreatePlayerTextDraw(playerid, 103.750000, 135.417312, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 16 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 16 ][ playerid ], 185.625000, 149.916625);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 16 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 16 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 16 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 16 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 16 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 16 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 16 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 16 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 16 ][ playerid ], 1);
 
					if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 )
					{
					
						if( II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iUsage ] == IMOVINA_KUCA )
						{
						
							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 16 ][ playerid ], 19522 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iUsage ] == IMOVINA_STAN )
						{
						
							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 16 ][ playerid ], 19523 );
						}
						else if( II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iUsage ] == IMOVINA_VIKENDICA )
						{
						
							PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 16 ][ playerid ], 19524 );
						}
					
					}
					else {
						PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 16 ][ playerid ], 19522 );
					}
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 16 ][ playerid ], 0.000000, 0.000000, 0.000000, 1.000000);

					if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {

						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xProperty ][ 1 ], II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iAdress ] );

						PlayerStats[ 17 ][ playerid ] = CreatePlayerTextDraw(playerid, 317.750000, 242.332901, globalstring );
					}
					else {
						PlayerStats[ 17 ][ playerid ] = CreatePlayerTextDraw(playerid, 317.750000, 242.332901, "~r~(~w~ID: -1~r~)~n~~w~Nema Imovine");
					}

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 17 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 17 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 17 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 17 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 17 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 17 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 17 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 17 ][ playerid ], 1);

					if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {

						format( globalstring, sizeof( globalstring ), "~r~(~w~ID: %d~r~)~n~~w~%s", PlayerInfo[ playerid ][ xProperty ][ 0 ], II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iAdress ] );

						PlayerStats[ 18 ][ playerid ] = CreatePlayerTextDraw(playerid, 200.625000, 239.832901, globalstring );
					}
					else {
						PlayerStats[ 18 ][ playerid ] = CreatePlayerTextDraw(playerid, 200.625000, 239.832901, "~r~(~w~ID: -1~r~)~n~~w~Nema Imovine");
					}

					PlayerTextDrawLetterSize(playerid, PlayerStats[ 18 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 18 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 18 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 18 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 18 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 18 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 18 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 18 ][ playerid ], 1);
					//
					PlayerStats[ 19 ][ playerid ] = CreatePlayerTextDraw(playerid, 382.375000, 87.333580, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 19 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 19 ][ playerid ], 63.750000, 48.416664);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 19 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 19 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 19 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 19 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 19 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 19 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 19 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 19 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 19 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 19 ][ playerid ], 19522 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 19 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 20 ][ playerid ] = CreatePlayerTextDraw(playerid, 450.750000, 106.749771, "- kuca");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 20 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 20 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 20 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 20 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 20 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 20 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 20 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 20 ][ playerid ], 1);

					PlayerStats[ 21 ][ playerid ] = CreatePlayerTextDraw(playerid, 312.125000, 88.333610, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 21 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 21 ][ playerid ], 63.750000, 48.416664);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 21 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 21 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 21 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 21 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 21 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 21 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 21 ][ playerid ], 5);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 21 ][ playerid ], 0);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 21 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 21 ][ playerid ], 19523 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 21 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 22 ][ playerid ] = CreatePlayerTextDraw(playerid, 220.000000, 88.750274, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 22 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 22 ][ playerid ], 63.750000, 48.416664);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 22 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 22 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 22 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 22 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 22 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 22 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 22 ][ playerid ], 0);
					PlayerTextDrawFont(playerid, PlayerStats[ 22 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 22 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 22 ][ playerid ], 19524 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 22 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 23 ][ playerid ] = CreatePlayerTextDraw(playerid, 378.000000, 106.583099, "- stan");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 23 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 23 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 23 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 23 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 23 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 23 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 23 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 23 ][ playerid ], 1);

					PlayerStats[ 24 ][ playerid ] = CreatePlayerTextDraw(playerid, 299.000000, 108.749763, "- vikendica");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 24 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 24 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 24 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 24 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 24 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 24 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 24 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 24 ][ playerid ], 1);

					PlayerStats[ 25 ][ playerid ] = CreatePlayerTextDraw(playerid, 235.375000, 123.000305, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 25 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 25 ][ playerid ], 35.625000, 26.249996);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 25 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 25 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 25 ][ playerid ], true);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 25 ][ playerid ], 0);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 25 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 25 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 25 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 25 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 25 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 25 ][ playerid ], 1273 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 25 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 26 ][ playerid ] = CreatePlayerTextDraw(playerid, 289.375000, 131.333129, "- hotel");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 26 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 26 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 26 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 26 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 26 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 26 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 26 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 26 ][ playerid ], 1);

					PlayerStats[ 27 ][ playerid ] = CreatePlayerTextDraw(playerid, 310.125000, 123.416992, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 27 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 27 ][ playerid ], 35.625000, 26.249996);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 27 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 27 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 27 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 27 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 27 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 27 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 27 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 27 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 27 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 27 ][ playerid ], 1272 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 27 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 28 ][ playerid ] = CreatePlayerTextDraw(playerid, 368.500000, 131.749786, "- garaza");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 28 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 28 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 28 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 28 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 28 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 28 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 28 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 28 ][ playerid ], 1);

					PlayerStats[ 29 ][ playerid ] = CreatePlayerTextDraw(playerid, 390.500000, 124.416976, "rot0");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 29 ][ playerid ], 0.449999, 1.600000);
					PlayerTextDrawTextSize(playerid, PlayerStats[ 29 ][ playerid ], 35.625000, 26.249996);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 29 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 29 ][ playerid ], -1);
					PlayerTextDrawUseBox(playerid, PlayerStats[ 29 ][ playerid ], true);
					PlayerTextDrawBoxColor(playerid, PlayerStats[ 29 ][ playerid ], 0);
					PlayerTextDrawBackgroundColor( playerid, PlayerStats[ 29 ][ playerid ], 0);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 29 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 29 ][ playerid ], 1);
					PlayerTextDrawFont(playerid, PlayerStats[ 29 ][ playerid ], 5);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 29 ][ playerid ], 1);
					PlayerTextDrawSetPreviewModel(playerid, PlayerStats[ 29 ][ playerid ], 1274 );
					PlayerTextDrawSetPreviewRot(playerid, PlayerStats[ 29 ][ playerid ], 0.000000, 0.000000, 00.000000, 1.000000);

					PlayerStats[ 30 ][ playerid ] = CreatePlayerTextDraw(playerid, 444.500000, 131.583129, "- firma");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 30 ][ playerid ], 0.318748, 0.888331);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 30 ][ playerid ], 2);
					PlayerTextDrawColor(playerid, PlayerStats[ 30 ][ playerid ], -1);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 30 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 30 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 30 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 30 ][ playerid ], 3);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 30 ][ playerid ], 1);

					PlayerStats[ 31 ][ playerid ] = CreatePlayerTextDraw(playerid, 182.500000, 158.666671, "-");
					PlayerTextDrawLetterSize(playerid, PlayerStats[ 31 ][ playerid ], 18.701887, 0.340000);
					PlayerTextDrawAlignment(playerid, PlayerStats[ 31 ][ playerid ], 1);
					PlayerTextDrawColor(playerid, PlayerStats[ 31 ][ playerid ], -16776961);
					PlayerTextDrawSetShadow(playerid, PlayerStats[ 31 ][ playerid ], 0);
					PlayerTextDrawSetOutline(playerid, PlayerStats[ 31 ][ playerid ], 1);
					PlayerTextDrawBackgroundColor(playerid, PlayerStats[ 31 ][ playerid ], 51);
					PlayerTextDrawFont(playerid, PlayerStats[ 31 ][ playerid ], 1);
					PlayerTextDrawSetProportional(playerid, PlayerStats[ 31 ][ playerid ], 1);

					for( new i = 7; i < 32; i ++) {
						PlayerTextDrawShow( playerid, PlayerStats[ i ][ playerid ] );
					}

				}
		
			}
			return true;
		}
*/
		//
		if( playertextid == ZaposljavanjeTD[ playerid ][ 7 ] ) {
		
			if( PlayerInfo[ playerid ][ xPosao ] != 0 ) {
				GRESKA( playerid, "Vi ste vec zaposleni negdje, onda - prvo morate dati otkaz!");
				ZaposljavanjeTDControl( playerid, false, "", "", "" );
				CancelSelectTextDraw( playerid );
				return true;
			}
			
			if( GetPlayerState( playerid ) != 1 ) {
				GRESKA( playerid, "Ne smete biti u vozilu!");
				ZaposljavanjeTDControl( playerid, false, "", "", "" );
				CancelSelectTextDraw( playerid );
				return true;
			}
			
			if( ChosenJob[ playerid ] == POSAO_MEHANICAR ) {
				if( PlayerInfo[ playerid ][ xSrednja ] != 6 ) return GRESKA( playerid, "Moras da zavrsis prvo srednju skolu. " );
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Mehanicar",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Mehanicar!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /mechanic /tow", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_MASINOVODJA ) {
				//if( PlayerInfo[ playerid ][ xFakultet ] != 15 ) return GRESKA( playerid, "Moras prvo da zavrsis fakultet. " );
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Masinovodja",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Masinovodja!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_PREVOZNIK ) {
				if( PlayerInfo[ playerid ][ xKamionskaC1 ] == 0 ) return GRESKA( playerid, "Ne posedujes dozvolu za kombije. ");
				if( PlayerInfo[ playerid ][ xKamionskaC2 ] == 0 ) return GRESKA( playerid, "Ne posedujes dozvolu za kamione. ");
				if( PlayerInfo[ playerid ][ xKamionskaC3 ] == 0 ) return GRESKA( playerid, "Ne posedujes dozvolu za kamione sa prikolicom. ");
				if( PlayerInfo[ playerid ][ xVozacka ] == 0 ) return GRESKA( playerid, "Ne posedujes vozacku dozvolu. ");
				if( PlayerInfo[ playerid ][ xSrednja ] != 6 ) return GRESKA( playerid, "Moras da zavrsis prvo srednju skolu. " );
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Prevoznik",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Prevoznik!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /prevozdrveca /prevozsljunka /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_KOSAC ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Kosac trave",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Kosac trave!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_KOMUNALAC ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Komunalac",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Komunalac!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_GRADJEVINAR ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Gradjevinar",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Gradjevinar!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white"/prekiniposao /uniforma", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_PIZZA ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Dostavljac pica",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Dostavljac pica!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /pizza", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_PILOT ) {
				if( PlayerInfo[ playerid ][ xLetelica ] == 0 ) return GRESKA( playerid, "Ne posedujes dozvolu za avion/helic." );
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Pilot",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Pilot!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_FARMER ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Farmer",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Farmer!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /uzmisemenke /uzmikantu /muzikrave /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_BUSVOZAC ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Bus vozac",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Bus vozac!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_RUDAR ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Rudar",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Rudar!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_PREVOZNOVCA ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Prevoznik Novca",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Prevoznik Novca!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /prekiniposao", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_RIBAR ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Posao Ribar",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Ribar!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /pecaj /uniforma /zavrsipecanje", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_PNAMESTAJA ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Proizvodjac Namestaja",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Proizvodjac Namestaja!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /posao /uniforma /ostavidrvo /uzmidrvo", "U redu", "");
			}
			else if( ChosenJob[ playerid ] == POSAO_TEMPODOSTAVA ) {
				ShowPlayerDialog( playerid, 0, DSMSG, "Tempo Dostavljac",
					""col_job"Cestitamo! Uspjesno ste se zaposlili kao Tempo Dostavljac!\n\n" \
					""col_job"Potrebno je da odradite barem 3 sati ugovora kako bi ste dali otkaz!\n" \
					""col_job"Komande posla: "col_white" /uzmiktuiju /uniforma", "U redu", "");
			}

			PlayerInfo[ playerid ][ xPosao ] = ChosenJob[ playerid ];
			PlayerInfo[ playerid ][ xUgovor ] = 0;
			SavePlayer( playerid );

			ZaposljavanjeTDControl( playerid, false, "", "", "" );
			CancelSelectTextDraw( playerid );
			return true;
		}
		if( playertextid == ZaposljavanjeTD[ playerid ][ 8 ] ) {
			SendInfoMessage( playerid, "Odustali ste od zaposljavanja." );
			ZaposljavanjeTDControl( playerid, false, "", "", "" );
			CancelSelectTextDraw( playerid );
			return true;
		}
		
		// sasasa
		if(Start[ playerid ] != PlayerText:INVALID_TEXT_DRAW) {
		if(DEALSTEXT == playertextid)
		{
				if(PP_Info[ playerid ][click_dealbutton] == WAIT_CLICKDEALTEXT) return 1;
				if(PP_Info[ playerid ][click_dealbutton] == FIRST_CLICKDEALTEXT)
				{
						if(PP_Info[ playerid ][Credit] < 1) return GRESKA(playerid,  "Nemas na racunu. Klikni na {FFFFFF}ADD COIN");
						if(PP_Info[ playerid ][Credit] < PP_Info[ playerid ][PokerBet])
						{
								PP_Info[ playerid ][PokerBet] = PP_Info[ playerid ][Credit];
						}
						PP_Info[ playerid ][Credit] -= PP_Info[ playerid ][PokerBet];
						PP_Info[ playerid ][click_dealbutton] = WAIT_CLICKDEALTEXT;
						PlayerTextDrawHide(playerid, ADDCOINSTEXT);
						PlayerTextDrawHide(playerid, BETTEXT);
						PlayerPlaySound(playerid, 43000, 0.00, 0.00, 0.00);
						RandomCard(PP_Info[ playerid ][fivecards_hand], 10);
						WinnText(playerid);
						BetCredit(playerid);
						TextDrawDizajn(playerid, 0);
				} else {
						PP_Info[ playerid ][click_dealbutton] = FIRST_CLICKDEALTEXT;
						PlayerTextDrawShow(playerid, ADDCOINSTEXT);
						PlayerTextDrawShow(playerid, BETTEXT);
						for(new i; i < 5; i++)
						{
								if(PP_Info[ playerid ][holdstate][i] == HOLDON)
								{
										PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, " ");
										PP_Info[ playerid ][holdstate][i] = HOLDOFF;
								} else {
										Swap(PP_Info[ playerid ][fivecards_hand][i], PP_Info[ playerid ][fivecards_hand][i + 5]);
										PlayerTextDrawSetString(playerid, CARDSTEXT + PlayerText:i, LD_POKE[PP_Info[ playerid ][fivecards_hand][i]]);
								}
						}
						new
								first,
								second,
								rank = get_rank(PP_Info[ playerid ][fivecards_hand]),
								win = get_win(rank);
						rankname(rank, first, second);
						if(win > ONE_PAIR)
						{
								PP_Info[ playerid ][Credit] += (pot[win] * PP_Info[ playerid ][PokerBet]);
								switch(win)
								{
										case STRAIGHT, FLUSH, STRAIGHT_FLUSH, FULL_HOUSE, ROYAL_FLUSH:
										{
												for(new i = 0; i < 5; i++)
												{
														PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "LD_POKE:holdmid");
												}
										}
										case TWO_PAIR:
										{
												for(new i = 0; i < 5; i++)
												{
														if(first == Card_Value[PP_Info[ playerid ][fivecards_hand][i]] ||
																second == Card_Value[PP_Info[ playerid ][fivecards_hand][i]])
														{
																PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "LD_POKE:holdmid");
														}
												}
										}
										case THREE_OF_A_KIND, FOUR_OF_A_KIND:
										{
												for(new i = 0; i < 5; i++)
												{
														if(first == Card_Value[PP_Info[ playerid ][fivecards_hand][i]])
														{
																PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "LD_POKE:holdmid");
														}
												}
										}
								}
								PlayerPlaySound(playerid, 5448, 0.00, 0.00, 0.00);
								WinnText(playerid, win, rank);
								BetCredit(playerid);
						} else {
								for(new i = 0; i < 5; i++)
								{
										PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "_");
								}
						}
				}
		} else {
				if(PP_Info[ playerid ][click_dealbutton] == SECOND_CLICKDEALTEXT)
				{
						for(new i = 0; i < 5; i++)
						{
								if(CARDSTEXT + PlayerText:i == playertextid)
								{
										PP_Info[ playerid ][holdstate][i] = HOLDOFF - PP_Info[ playerid ][holdstate][i];
										if(PP_Info[ playerid ][holdstate][i])
												PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "_");
										else
												PlayerTextDrawSetString(playerid, HOLDSTEXT + PlayerText:i, "LD_POKE:holdon");
										PlayerPlaySound(playerid, 21000, 0.00, 0.00, 0.00);
										return 1;
								}
						}
				}
				else if(ADDCOINSTEXT == playertextid)
				{
						if( PlayerInfo[ playerid ][ xNovac ] < 100)
						{
								GRESKA( playerid, "Nemas novca.");
						} else {
								DajIgracuNovac( playerid, -100 );
								PP_Info[ playerid ][ Credit ] += 100;
								BetCredit(playerid);
								PlayerPlaySound(playerid, 4203, 0.00, 0.00, 0.00);
						}
						return 1;
				}
				else if(BETTEXT == playertextid)
				{
						if(PP_Info[ playerid ][PokerBet] < 100)
								PP_Info[ playerid ][PokerBet]++;
						else
								PP_Info[ playerid ][PokerBet] = 5;

						BetCredit(playerid);
						WinnText(playerid);
						PlayerPlaySound(playerid, 4202, 0.00, 0.00, 0.00);
						return 1;
				}
		}

		if(CHANGEBACKGROUND == playertextid)
		{
				PP_Info[ playerid ][LastBackGround]++;
				if(PP_Info[ playerid ][LastBackGround] == sizeof BackGroundData)
						PP_Info[ playerid ][LastBackGround] = 0;
				PlayerTextDrawSetString(playerid, BACKGROUND, BackGroundData[PP_Info[ playerid ][LastBackGround]]);
				return 1;
		}

		if(EXITPOKER == playertextid)
		{
				ExitPoker(playerid);
				return 1;
		}
		}
	}
	return 1;
}

///////////


//------------------------------------------------------------------------------
public DinamicWeather()
{
	new tmphour,
		tmpminute,
		tmpsecond;

	gettimeEx(tmphour, tmpminute, tmpsecond);
	FixHour( tmphour );
	tmphour = shifthour;

	#if NERP_ZIMSKI_MOD  == 1
	SetWeather( 38 );
	GlobalnoVrijeme = 38;
	ServerInfo[ Prognozasys ] = 38;
	#else
	if(tmphour >= 6 && tmphour <= 20)
	{
		new RandomWeather;
		RandomWeather = random(10);
		switch(RandomWeather)
		{
			case 0:
			{
				SetWeather(1);
				GlobalnoVrijeme = 1;
				SendClientMessageToAll( NARANDZASTA1, "  {008080}*Prognoza vremena: Danas ce biti suncano i toplo." );
				ServerInfo[ Prognozasys ] = 1;
			}
			case 1:
			{
				SetWeather(7);
				GlobalnoVrijeme = 7;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je hladno i maglovito, obucite se toplije!");
				ServerInfo[ Prognozasys ] = 7;
			}
			case 2:
			{
				SetWeather(8);
				GlobalnoVrijeme = 8;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je kisovito i upozoravamo vozace na skliske kolovoze!");
				ServerInfo[ Prognozasys ] = 8;
			}
			case 3:
			{
				SetWeather(13);
				GlobalnoVrijeme = 13;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je suncano i toplo, odlicno vrijeme za setnju u prirodi.");
				ServerInfo[ Prognozasys ] = 13;
			}
			case 4:
			{
				SetWeather(15);
				GlobalnoVrijeme = 15;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je oblacno i vjetrovito, obucite toplu odjecu!");
				ServerInfo[ Prognozasys ] = 15;
			}
			case 5:
			{
				SetWeather(17);
				GlobalnoVrijeme = 17;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je toplo sa umjerenom naoblakom.");
				ServerInfo[ Prognozasys ] = 17;
			}
			case 6:
			{
				SetWeather(24);
				GlobalnoVrijeme = 24;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Vrijeme je toplo i suncano trenuta temperatura je 36C!");
				ServerInfo[ Prognozasys ] = 24;
			}
			case 7:
			{
				SetWeather(10);
				GlobalnoVrijeme = 10;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je suncano i svjeze, trenutna temperatura 18C");
				ServerInfo[ Prognozasys ] = 10;
			}
			case 8:
			{
				SetWeather(43);
				GlobalnoVrijeme = 43;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je vlazno i maglovito!");
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Upozoravamo vozace da voze oprezno!");
				ServerInfo[ Prognozasys ] = 43;
			}
			case 9:
			{
				SetWeather(40);
				GlobalnoVrijeme = 40;
				SendClientMessageToAll(NARANDZASTA1, "  {008080}*Prognoza vremena: Danas je ugodno i toplo uz temperaturu od 25C");
				ServerInfo[ Prognozasys ] = 40;
			}
		}
	}
	else if( tmphour >= 21 && tmphour <= 5 )
	{
		SetWeather(10);
		GlobalnoVrijeme = 10;
		ServerInfo[ Prognozasys ] = 10;
	}
	#endif
	return 1;
}
//------------------------------------------------------------------------------
#if nerp_droga == 1
DrugCheck( playerid ) {
	new hour,minuite,second;

	if( PlayerDrugged[ playerid ] == true ) {

		if( GetPVarInt( playerid, "PlayerDruggedSeconds") > 0)
			PovecajPVarInt( playerid, "PlayerDruggedSeconds", -1);
		else {
			gettimeEx( hour, minuite, second );
			FixHour( hour );
			hour = shifthour;

			SetPlayerDrunkLevel( playerid, 0 );
			PlayerDrugged[ playerid ] = false;
			SetPVarInt( playerid, "PlayerDruggedSeconds", 0 );
			PlayerStoned[ playerid ] = false;
			SetPlayerWeather( playerid, ServerInfo[ Prognozasys ] );
			SetPlayerTime( playerid, hour, minuite );
		}
	}
}
//------------------------------------------------------------------------------
public CarCheck( playerid )
{
	new Float:health;
	if( IsPlayerConnected( playerid ) ) {

		GetPlayerHealth( playerid, health );
		if( NaDmEventu[ playerid ] == false && WARPInfo[ playerid ][ WARIgrac ] == -1 ) {
			if( PlayerInfo[ playerid ][ xHeroinAddict ] == true && PlayerInfo[ playerid ][ xHeroinUsed ] < 1 )
			{
				Dimi_SetPlayerHealth( playerid, health - 3.5);
				ApplyAnimation( playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0, 1);
				announcement( playerid, "~r~Niste uzeli svoju dozu, vase tijelo zeli drogu!", 2000, 6);
			}
			else if( PlayerInfo[ playerid ][ xMethAddict ] == true && PlayerInfo[ playerid ][ xMethUsed ] < 1 )
			{
				Dimi_SetPlayerHealth( playerid, health - 3.2);
				ApplyAnimation( playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0, 1);
				announcement( playerid, "~r~Niste uzeli vasu dozu metamfetamina, vase tijelo zeli drogu!", 2000, 6);
			}
			else if( PlayerInfo[ playerid ][ xCokeCrackAddict ] == true && PlayerInfo[ playerid ][ xCokeCrackUsed ] < 1 )
			{
				Dimi_SetPlayerHealth( playerid, health - 3.0);
				ApplyAnimation( playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0, 1);
				announcement( playerid, "~r~Niste uzeli svoju dozu, vase tijelo zeli drogu!", 2000, 6);
			}
		}

	}
	return 1;
}
#endif

//------------------------------------------------------------------------------
#if nerp_droga == 1
GetDrugNameByDrugID( drugid ) {
	switch( drugid ) {
		case 1000..1999: //Marihuana
		{
			format( globalstring, sizeof( globalstring ), "Marihuana");
		}
		case 2000..2999: //LSD
		{
			format( globalstring, sizeof( globalstring ), "LSD");
		}
		case 3000..3999: //Methamphetamine
		{
			format( globalstring, sizeof( globalstring ), "Methamphetamine");
		}
		case 4000..4999: //Heroin
		{
			format( globalstring, sizeof( globalstring ), "Heroin");
		}
		case 5000..5999: //Cocaine
		{
			format( globalstring, sizeof( globalstring ), "Kokain");
		}
		case 6000..6999: //Blue Methamphetamine
		{
			format( globalstring, sizeof( globalstring ), "Plavi Methamphetamine");
		}
		case 7000..7999: //crack
		{
			format( globalstring, sizeof( globalstring ), "Crack");
		}
		default:
		{
			format( globalstring, sizeof( globalstring ), "Prazno");
		}
	}
	return globalstring;
}

UsingCrack( playerid, drugid ) {

	if( IsPlayerConnected( playerid ) ) {
	
		if( IsAStrongCrack( drugid ) ) {
		
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 100;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 6;

			DajIgracuGlad( playerid, 30 );
			DodajIgracuArmour( playerid, 30 );
		}
		else if( IsAGoodCrack( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 80;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 5;

			DajIgracuGlad( playerid, 25 );
			DodajIgracuArmour( playerid, 25 );
		}
		else if( IsABadCrack( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 60;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 3;

			DajIgracuGlad( playerid, 20 );
			DodajIgracuArmour( playerid, 20 );
		}
		else if( IsAVeryBadCrack( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 45;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true )
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 1;

			DajIgracuGlad( playerid, 15 );
			DodajIgracuArmour( playerid, 15 );

			if( PlayerInfo[ playerid ][ xCokeCrackIndicator ] > 680 ) {

				PlayerInfo[ playerid ][ xUbijen ] = 1;
				SendClientMessagee( playerid, ZUTA, "Predozirali ste se krekom i umrli." );
				Dimi_SetPlayerHealth( playerid, 0 );
			}
		}
		if(PlayerInfo[ playerid ][ xCokeCrackIndicator ] > 750 && PlayerInfo[ playerid ][ xCokeCrackAddict ] == false)
			PlayerInfo[ playerid ][ xCokeCrackAddict ] = true;
	}
}


UsingCocaine( playerid, drugid)
{
	if( IsPlayerConnected( playerid ))
	{
		if( IsAStrongCocaine( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 100;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 6;

			DajIgracuGlad( playerid, 30 );
			DodajIgracuArmour( playerid, 30 );
		}
		else if( IsAGoodCocaine( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 80;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 5;

			DajIgracuGlad( playerid, 25 );
			DodajIgracuArmour( playerid, 25 );
		}
		else if( IsABadCocaine( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 60;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true)
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 3;

			DajIgracuGlad( playerid, 20 );
			DodajIgracuArmour( playerid, 20 );
		}
		else if( IsAVeryBadCocaine( drugid ) )
		{
			PlayerInfo[ playerid ][ xCokeCrackIndicator ] += 45;
			if(PlayerInfo[ playerid ][ xCokeCrackAddict ] == true )
				PlayerInfo[ playerid ][ xCokeCrackUsed ] = 1;

			DajIgracuGlad( playerid, 15 );
			DodajIgracuArmour( playerid, 15 );

			if( PlayerInfo[ playerid ][ xCokeCrackIndicator ] > 680 ) {

				PlayerInfo[ playerid ][ xUbijen ] = 1;
				SendClientMessagee( playerid, ZUTA, "Predozirali ste se kokainom i umrli." );
				Dimi_SetPlayerHealth( playerid, 0 );
			}
		}
		if(PlayerInfo[ playerid ][ xCokeCrackIndicator ] > 750 && PlayerInfo[ playerid ][ xCokeCrackAddict ] == false)
			PlayerInfo[ playerid ][ xCokeCrackAddict ] = true;
	}
}

UsingBMeth( playerid, drugid) {
	if( IsPlayerConnected( playerid ) ) {
	
		if( IsAStrongBlueMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 100;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 6;

			DajIgracuGlad( playerid, 30 );
			DodajIgracuArmour( playerid, 30 );
		}
		else if( IsAGoodBlueMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 90;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 5;

			DajIgracuGlad( playerid, 25 );
			DodajIgracuArmour( playerid, 25 );
		}
		else if( IsABadBlueMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 80;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 3;

			DajIgracuGlad( playerid, 20 );
			DodajIgracuArmour( playerid, 20 );
		}
		else if( IsAVeryBadBlueMeth( drugid ) )
		{
			PlayerInfo[ playerid ][ xMethIndicator ] += 40;
			if( PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 1;

			DajIgracuGlad( playerid, 15 );
			DodajIgracuArmour( playerid, 15 );

			if( PlayerInfo[ playerid ][ xMethIndicator ] > 385 ) {

				PlayerInfo[ playerid ][ xUbijen ] = 1;
				SendClientMessagee( playerid, ZUTA, "Predozirali ste se metom i umrli." );
				Dimi_SetPlayerHealth( playerid, 0 );
			}
		}
		if(PlayerInfo[ playerid ][ xMethIndicator ] > 450 && PlayerInfo[ playerid ][ xMethAddict ] == false )
			PlayerInfo[ playerid ][ xMethAddict ] = true;
	}
}

UsingMeth( playerid, drugid)
{
	if( IsPlayerConnected( playerid ) ) {
		if( IsAStrongMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 95;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 6;

			DajIgracuGlad( playerid, 30 );
			DodajIgracuArmour( playerid, 30 );
		}
		else if( IsAGoodMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 85;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 5;

			DajIgracuGlad( playerid, 25 );
			DodajIgracuArmour( playerid, 25 );
		}
		else if( IsABadMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 70;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 3;

			DajIgracuGlad( playerid, 20 );
			DodajIgracuArmour( playerid, 20 );
		}
		else if( IsAVeryBadMeth( drugid ) ) {
		
			PlayerInfo[ playerid ][ xMethIndicator ] += 35;
			if(PlayerInfo[ playerid ][ xMethAddict ] == true )
				PlayerInfo[ playerid ][ xMethUsed ] = 1;

			DajIgracuGlad( playerid, 15 );
			DodajIgracuArmour( playerid, 15 );

			if( PlayerInfo[ playerid ][ xMethIndicator ] > 380 ) {

				PlayerInfo[ playerid ][ xUbijen ] = 1;
				SendClientMessagee( playerid, ZUTA, "Predozirali ste se metom i umrli." );
				Dimi_SetPlayerHealth( playerid, 0 );
			}
		}
		if( PlayerInfo[ playerid ][ xMethIndicator ] > 450 && PlayerInfo[ playerid ][ xMethAddict ] == false )
			PlayerInfo[ playerid ][ xMethAddict ] = true;
	}
}

UsingHeroin( playerid, drugid ) {
	if( IsPlayerConnected( playerid ) ) {
		if( IsAStrongHeroin( drugid ) )
		{
			PlayerInfo[ playerid ][ xHeroinIndicator ] += 100;

			if(PlayerInfo[ playerid ][ xHeroinAddict ] == true)
				PlayerInfo[ playerid ][ xHeroinUsed ] = 6;

			DajIgracuGlad( playerid, 30 );
			DodajIgracuArmour( playerid, 30 );
		}
		else if( IsAGoodHeroin( drugid ) )
		{
			PlayerInfo[ playerid ][ xHeroinIndicator ] += 90;

			if(PlayerInfo[ playerid ][ xHeroinAddict ] == true)
				PlayerInfo[ playerid ][ xHeroinUsed ] = 5;

			DajIgracuGlad( playerid, 25 );
			DodajIgracuArmour( playerid, 25 );
		}
		else if( IsABadHeroin( drugid ) )
		{
			PlayerInfo[ playerid ][ xHeroinIndicator ] += 75;

			if(PlayerInfo[ playerid ][ xHeroinAddict ] == true)
				PlayerInfo[ playerid ][ xHeroinUsed ] = 3;

			DajIgracuGlad( playerid, 20 );
			DodajIgracuArmour( playerid, 20 );
		}
		else if( IsAVeryBadHeroin( drugid ) )
		{
			PlayerInfo[ playerid ][ xHeroinIndicator ] += 40;

			if(PlayerInfo[ playerid ][ xHeroinAddict ] == true)
				PlayerInfo[ playerid ][ xHeroinUsed ] = 1;

			DajIgracuGlad( playerid, 15 );
			DodajIgracuArmour( playerid, 15 );
			if( PlayerInfo[ playerid ][ xHeroinIndicator ] > 250 ) {

				PlayerInfo[ playerid ][ xUbijen ] = 1;
				SendClientMessagee( playerid, ZUTA, "Predozirali ste se heroinom i umrli." );
				Dimi_SetPlayerHealth( playerid, 0 );
			}
		}

		if( PlayerInfo[ playerid ][ xHeroinIndicator ] > 300 && PlayerInfo[ playerid ][ xHeroinAddict ] == false)
			PlayerInfo[ playerid ][ xHeroinAddict ] = true;

	}
}

IsAMarijuana(drugid)
{
	if(drugid >= 1000 && drugid <= 1999)
	{
		return true;
	}
	return false;
}

IsALSD(drugid)
{
	if(drugid >= 2000 && drugid <= 2999)
	{
		return true;
	}
	return false;
}

IsAMethamphetamine(drugid)
{
	if(drugid >= 3000 && drugid <= 3999)
	{
		return true;
	}
	return false;
}

IsAHeroin(drugid)
{
	if(drugid >= 4000 && drugid <= 4999)
	{
		return true;
	}
	return false;
}


IsACocaine(drugid)
{
	if(drugid >= 5000 && drugid <= 5999)
	{
		return true;
	}
	return false;
}

IsACrack(drugid)
{
	if(drugid >= 7000 && drugid <= 7999)
	{
		return true;
	}
	return false;
}

IsAStrongCrack(drugid)
{
	if(drugid >= 7800 && drugid <= 7999)
	{
		return true;
	}
	return false;
}

IsAGoodCrack(drugid)
{
	if(drugid >= 7500 && drugid <= 7799)
	{
		return true;
	}
	return false;
}

IsABadCrack(drugid)
{
	if(drugid >= 7200 && drugid <= 7499)
	{
		return true;
	}
	return false;
}

IsAVeryBadCrack(drugid)
{
	if(drugid >= 7000 && drugid <= 7199)
	{
		return true;
	}
	return false;
}


IsABlueMeth(drugid)
{
	if(drugid >= 6000 && drugid <= 6999)
	{
		return true;
	}
	return false;
}

IsAStrongHeroin(drugid)
{
	if(drugid >= 4549 && drugid <= 4741)
	{
		return true;
	}
	return false;
}

IsAGoodHeroin(drugid)
{
	if(drugid >= 4742 && drugid <= 4999)
	{
		return true;
	}
	return false;
}

IsABadHeroin(drugid)
{
	if(drugid >= 4244 && drugid <= 4548)
	{
		return true;
	}
	return false;
}

IsAVeryBadHeroin(drugid)
{
	if(drugid >= 4000 && drugid <= 4243)
	{
		return true;
	}
	return false;
}

IsAStrongBlueMeth(drugid)
{
	if(drugid >= 6800 && drugid <= 6999)
	{
		return true;
	}
	return false;
}

IsAGoodBlueMeth(drugid)
{
	if(drugid >= 6500 && drugid <= 6799)
	{
		return true;
	}
	return false;
}

IsABadBlueMeth(drugid)
{
	if(drugid >= 6200 && drugid <= 6499)
	{
		return true;
	}
	return false;
}

IsAVeryBadBlueMeth(drugid)
{
	if(drugid >= 6000 && drugid <= 6199)
	{
		return true;
	}
	return false;
}

IsAStrongLSD(drugid)
{
	if(drugid >= 2800 && drugid <= 2999)
	{
		return true;
	}
	return false;
}

IsAGoodLSD(drugid)
{
	if(drugid >= 2500 && drugid <= 2799)
	{
		return true;
	}
	return false;
}

IsABadLSD(drugid)
{
	if(drugid >= 2200 && drugid <= 2499)
	{
		return true;
	}
	return false;
}

IsAVeryBadLSD(drugid)
{
	if(drugid >= 2000 && drugid <= 2199)
	{
		return true;
	}
	return false;
}

IsAStrongMeth(drugid)
{
	if(drugid >= 3800 && drugid <= 3999)
	{
		return true;
	}
	return false;
}

IsAGoodMeth(drugid)
{
	if(drugid >= 3500 && drugid <= 3799)
	{
		return true;
	}
	return false;
}

IsABadMeth(drugid)
{
	if(drugid >= 3200 && drugid <= 3499)
	{
		return true;
	}
	return false;
}

IsAVeryBadMeth(drugid)
{
	if(drugid >= 3000 && drugid <= 3199)
	{
		return true;
	}
	return false;
}


IsAStrongCocaine( drugid ) {
	if( drugid >= 5800 && drugid <= 5999 ) {
		return true;
	}
	return false;
}

IsAGoodCocaine( drugid ) {
	if( drugid >= 5500 && drugid <= 5799 ){
		return true;
	}
	return false;
}

IsABadCocaine( drugid ) {
	if( drugid >= 5200 && drugid <= 5499 ) {
		return true;
	}
	return false;
}

IsAVeryBadCocaine( drugid ) {
	if( drugid >= 5000 && drugid <= 5199 ) {
		return true;
	}
	return false;
}
#endif
//------------------------------------------------------------------------------
public CistacKilometri( playerid ) {
	if( IsPlayerInAnyVehicle( playerid ) && antiCheatCS[ playerid ][ AFKMinute ] == 0 && !IsPlayerPaused( playerid ) && GetSpeed( playerid ) > 2 && GetSpeed( playerid ) < 120 && CistacPosao[ playerid ] == true  ) {
		
		#if NERP_ZIMSKI_MOD  == 1
		if( TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO &&
			GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 455 &&
			PosaoVozila[ GetPlayerVehicleID( playerid ) ] == POSAO_KOMUNALAC ) { }
		else return 1;
		#else
		if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 574 ) { }
		else return 1;
		#endif

		cistacmetri[ playerid ] += ( GetSpeed( playerid )*10)/36;
		
		new Float:Pos[ 3 ];
		GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
		if( cistacpoz[ playerid ][ 0 ] == Pos[ 0 ] && cistacpoz[ playerid ][ 1 ] == Pos[ 1 ] ) {
			CistacWarning[ playerid ]++;
			if( CistacWarning[ playerid ] == 10 ) {
				
				SendJobMessage( playerid, "Sumnja se da ste bili u mjestu vise od 10 sekundi pa vam je prekinuo posao." );
				SetVehicleToRespawn( cistacvozilo[ playerid ] );
				cistacvozilo[ playerid ] = -1;
				CistacPosao[ playerid ] = false;
				cistackilometri[ playerid ] = 0;
				cistacmetri[ playerid ] = 0;
				cistacnovac[ playerid ] = 0;
				cistacpoz[ playerid ][ 0 ] = 0.0;
				cistacpoz[ playerid ][ 1 ] = 0.0;
				cistacpoz[ playerid ][ 2 ] = 0.0;
				CistacWarning[ playerid ] = 0;
				Dimi_KillTimer( CistacTimer[ playerid ] );
				CKilometriTDControl( playerid, false );
				return 1;
			}
		}
		GetPlayerPos( playerid, cistacpoz[ playerid ][ 0 ], cistacpoz[ playerid ][ 1 ], cistacpoz[ playerid ][ 2 ] );
		
		if( cistacmetri[ playerid ] > 999 ) {
			cistackilometri[ playerid ] += 1;
			cistacmetri[ playerid ] = 0;
			cistacnovac[ playerid ] = (cistackilometri[ playerid ]*280);
			format( globalstring, sizeof( globalstring ), "Predjeno: %dkm", cistackilometri[ playerid ] );
			PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 1 ], globalstring );
			//format( globalstring, sizeof( globalstring ), "Zarada: %d$", cistacnovac[ playerid ] );
			//PlayerTextDrawSetString( playerid, CKilometri[ playerid ][ 2 ], globalstring );
			
			if( cistackilometri[ playerid ] == 10 ) {
				Dimi_KillTimer( CistacTimer[ playerid ] );
				CKilometriTDControl( playerid, false );
				
				SendJobMessage( playerid, "Presli ste 10km morate isprazniti vozilo u bazi, pa poceti opet ako zelite." );
				
				Dimi_SetPlayerCheckpoint( playerid, 2074.1355,-1994.7986,13.5469, 5.0);
				CheckpointStatus[ playerid ] = 27;
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public FakultetCasovi( playerid, broj ) {
	if( PlayerInfo[ playerid ][ xFakultet ] != 15 ) {
		PlayerInfo[ playerid ][ xFakultet ] = broj;
		Odbrojavanje[ playerid ] = 0; Uciskolu[ playerid ] = false;
		Dimi_KillTimer( SkolaTimer[ playerid ] );
		PlayerInfo[ playerid ][ xSkolaLimit ] = 1;
		SendInfoMessage( playerid, "Polozio si %d deo (od mogucih 15) fakultet.", broj );
		TogglePlayerControllable( playerid, true );
		VremeTDControl( playerid, false );
		format( globalstring, sizeof( globalstring ), "* %s ustaje sa stolice.", ImeIgraca( playerid ) );
		PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
		ClearAnimations( playerid ); SavePlayer( playerid );
		SavePlayer( playerid );
	}
	return 1;
}
public SrednjaCasovi( playerid, broj ) {
	if( PlayerInfo[ playerid ][ xSrednja ] != 6 ) {
		PlayerInfo[ playerid ][ xSrednja ] = broj;
		Odbrojavanje[ playerid ] = 0; Uciskolu[ playerid ] = false;
		Dimi_KillTimer( SkolaTimer[ playerid ] );
		PlayerInfo[ playerid ][ xSkolaLimit ] = 1;
		SendInfoMessage( playerid, "Polozio si %d deo (od mogucih 6) srednje skole. ", broj );
		TogglePlayerControllable( playerid, true );
		VremeTDControl( playerid, false );
		format( globalstring, sizeof( globalstring ), "* %s ustaje sa stolice.", ImeIgraca( playerid ) );
		PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
		ClearAnimations( playerid ); SavePlayer( playerid );
		SavePlayer( playerid );
	}
}
public OsnovnaCasovi( playerid, broj )
{
	if( PlayerInfo[ playerid ][ xOsnovna ] != 3 )
	{
		PlayerInfo[ playerid ][ xOsnovna ] = broj;
		Odbrojavanje[ playerid ] = 0; Uciskolu[ playerid ] = false;
		Dimi_KillTimer( SkolaTimer[ playerid ] );
		PlayerInfo[ playerid ][ xSkolaLimit ] = 1;
		TogglePlayerControllable( playerid, true );
		SendInfoMessage( playerid, "Polozio si %d deo (od mogucih 3) osnovne skole. ", broj );
		VremeTDControl( playerid, false );
		format( globalstring, sizeof( globalstring ), "* %s ustaje sa stolice.", ImeIgraca( playerid ) );
		PorukaRadius( 20.0, playerid, globalstring, LJUBICASTA );
		ClearAnimations( playerid ); SavePlayer( playerid );
		SavePlayer( playerid );
	}
	return 1;
}
//------------------------------------------------------------------------------
PlayerPlayMusic( playerid )
{
	if( IsPlayerConnected( playerid ) )
	{
		SetTimer("StopMusic", 5000, 0);
		PlayerPlaySound( playerid, 1068, 0.0, 0.0, 0.0);
	}
}
public StopMusic()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if( IsPlayerConnected(i))
		{
			PlayerPlaySound(i, 1069, 0.0, 0.0, 0.0);
		}
	}
}

//------------------------------------------------------------------------------
public ZetvaT( i )
{
	new Float:Pos[ 3 ];
	if( PlayerInfo[ i ][ xPosao ] == POSAO_FARMER && KrenuoZetvu[ i ] && GetVehicleModel( GetPlayerVehicleID( i ) ) == 532 )
	{
		for( new j = 0; j < 72; j++ )
		{
			if( ZitoID[ j ][ i ] == 804 )
			{
				GetDynamicObjectPos( ZitoObjects[ i ][ j ], Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				if( IsPlayerInRangeOfPoint( i, 3.0, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] ) )
				{

					if( PokosenoZito[ i ] == 72 )
					{
						new time = gettime( );
						new ostatak = ( NovoVreme[ i ] - ( time - StaroVreme[ i ] ) );
						if( ( time - StaroVreme[ i ] ) < NovoVreme[ i ] )
						{
							GRESKA( i, "Zavrsili ste posao ranije nego sto je predvidjeno. " );
							GRESKA( i, "Sacekajte jos %d sekundi i prodjite ponovo kroz objekt.", ostatak );
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je zavrsio farmera prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( i ), i, (NovoVreme[ i ]-ostatak), NovoVreme[ i ] );
							AdminPoruka( ANTICHEAT, globalstring );
							return 1;
						}
					}

					DestroyDynamicObject( ZitoObjects[ i ][ j ] );
					RemovePlayerMapIcon(i, j);
					ZitoID[ j ][ i ] = 19473;
					PokosenoZito[ i ]++;
					break;
				}
			}
		}

		if( PokosenoZito[ i ] == 72 )
		{
			Dimi_KillTimer( ZitoTimer[ i ] );
			SendJobMessage(i, "Poznjeli ste svo zito i zavrsili posao!");
			PokosenoZito[ i ] = 0;
			new bonus = random(PosloviInfo[ BonusFarmerZito ]);
			new isplata = PosloviInfo[ FarmerZitoPlata ] + bonus;
			PlayerInfo[ i ][ xPlatniRacun ] += isplata;
			SavePlayer( i );
			SendJobMessage( i, "Zaradili ste "col_job"%d$ "col_white"koji su vam legli na platni racun.",isplata );
			ShowPlayerDialog(i, dialog_ZETVAZITA, DSMSG, ""col_white"Vrsenje zita",""col_white"Da li zelite ponovo vrsiti zito?\n","Da","Ne");
			KrenuoZetvu[ i ] = false; UpdatePlataTD( i );
			//BussinesJobMoney( POSAO_KOSAC, 50 );
		}
	}
	return 1;
}

//------------------------------------------------------------------------------
public TravaT( i )
{
	new Float:Pos[ 3 ];
	if( PlayerInfo[ i ][ xPosao ] == POSAO_KOSAC && KrenuoKosenje[ i ] && GetVehicleModel( GetPlayerVehicleID( i ) ) == 572 )
	{
		for( new j = 0; j < 76; j++ )
		{
			if( GrassID[ j ][ i ] == 804 )
			{
				GetDynamicObjectPos( Grass[ i ][ j ], Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				if( IsPlayerInRangeOfPoint( i, 2.0, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] ) )
				{
					if( PokosenaTrava[ i ] == 76 )
					{
						new time = gettime( );
						new ostatak = ( NovoVreme[ i ] - ( time - StaroVreme[ i ] ) );
						if( ( time - StaroVreme[ i ] ) < NovoVreme[ i ] )
						{
							GRESKA( i, "Zavrsili ste posao ranije nego sto je predvidjeno. " );
							GRESKA( i, "Sacekajte jos %d sekundi i prodjite ponovo kroz objekt.", ostatak );
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je zavrsio kosaca prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( i ), i, (NovoVreme[ i ]-ostatak), NovoVreme[ i ] );
							AdminPoruka( ANTICHEAT, globalstring );
							return 1;
						}
					}
					DestroyDynamicObject( Grass[ i ][ j ] );
					RemovePlayerMapIcon(i, j);
					GrassID[ j ][ i ] = 19473;
					PokosenaTrava[ i ]++;
					break;
				}
			}
		}
		
		if( PokosenaTrava[ i ] == 76 )
		{
			Dimi_KillTimer( TravaTimer[ i ] );
			SendClientMessagee(i, SVETLOPLAVA, "Pokosili ste svu travu.");
			PokosenaTrava[ i ] = 0;
			//SetVehicleToRespawn( GetPlayerVehicleID( i ) );
			new dodatno = random(PosloviInfo[ BonusKosaca ]);
			new isplacen = PosloviInfo[ PlataKosaca ] + dodatno;
			PlayerInfo[ i ][ xPlatniRacun ] += isplacen;
			SavePlayer( i );
			SendJobMessage( i, "Zaradili ste "col_white"%d$ "col_job"koji su vam legli na platni racun.",isplacen );
			ShowPlayerDialog(i, dialog_KOSACPOSAO, DSMSG, ""col_white"Kosac trave",""col_white"Da li zelite ponovo kositi travu?\n","Da","Ne");
			KrenuoKosenje[ i ] = false; UpdatePlataTD( i );
			BussinesJobMoney( POSAO_KOSAC, 50 );
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
AFKCheck( playerid )
{
	GetPlayerPos(playerid, antiCheatCS[ playerid ][ AFKSecondPos ][ 0 ], antiCheatCS[ playerid ][ AFKSecondPos ][ 1 ], antiCheatCS[ playerid ][ AFKSecondPos ][ 2 ] );

	if( !floatcmp( antiCheatCS[ playerid ][ AFKSecondPos ][ 0 ], antiCheatCS[ playerid ][ AFKFirstPos ][ 0 ] ) && !floatcmp( antiCheatCS[ playerid ][ AFKSecondPos ][ 1 ], antiCheatCS[ playerid ][ AFKFirstPos ][ 1 ] ) )
	{
		if( PlayerInfo[ playerid ][ xRPLearn ] == 0 && PlayerInfo[ playerid ][ xAdmin ] != 7 )
		{
			antiCheatCS[ playerid ][ AFKMinute ]++;
		}
	}
	else
	{
		antiCheatCS[ playerid ][ AFKMinute ] = 0;
		VecJeAfk[ playerid ] = false;
	}
	
	antiCheatCS[ playerid ][ AFKFirstPos ][ 0 ] = antiCheatCS[ playerid ][ AFKSecondPos ][ 0 ];
	antiCheatCS[ playerid ][ AFKFirstPos ][ 1 ] = antiCheatCS[ playerid ][ AFKSecondPos ][ 1 ];
	antiCheatCS[ playerid ][ AFKFirstPos ][ 2 ] = antiCheatCS[ playerid ][ AFKSecondPos ][ 2 ];

	if( antiCheatCS[ playerid ][ AFKMinute ] >= 10 && PlayerInfo[ playerid ][ xZatvor ] == 0 )
	{
	
		if( PlayerInfo[ playerid ][ xWanted ] > 0 )
		{
			if(VecJeAfk[ playerid ] == false)
			{
				SendInfoMessage( playerid, "Imali ste Wanted Level i bili ste AFK, sada ste u zatvoru!" );
				VecJeAfk[ playerid ] = true;
			}
			PlayerInfo[ playerid ][ xZatvor ] = OBICAN_ZATVOR;
			PlayerInfo[ playerid ][ xZatvorVreme ] = 6*PlayerInfo[ playerid ][ xWanted ];
			new price = PlayerInfo[ playerid ][ xWanted ]*500;
			DajIgracuNovac( playerid, -price );
			
			format( globalstring, sizeof( globalstring ), "~r~Do slobode: ~w~%d ~r~min",( PlayerInfo[ playerid ][ xZatvorVreme ]+1 ) );
			PlayerTextDrawSetString(playerid,JailTD[playerid],globalstring);
			PlayerTextDrawShow(playerid,JailTD[playerid]);

			new rand = random( sizeof( RandomZatvor ) );
			Dimi_SetPlayerPos( playerid, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ],RandomZatvor[ rand ][ 2 ] );
			PlayerInfo[ playerid ][ xWanted ] = 0;
			Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
			strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid ); SetPlayerInterior( playerid, 1);
			SetPlayerVirtualWorld( playerid, 1);
			TogglePlayerControllable( playerid, 0 );
			SavePlayer( playerid );
		}
		else if( PlayerInfo[ playerid ][ xWanted ] == 0 )
		{
	
			if(VecJeAfk[ playerid ] == false)
			{
				SendInfoMessage( playerid, "Prebaceni ste u AFK zonu jer ste bili 10 minuta AFK!" );
				VecJeAfk[ playerid ] = true;
			}
			
			antiCheatCS[ playerid ][ TeleportCheck ] = 4;

			if( NaDmEventu[ playerid ] == true )
			{
				NaDmEventu[ playerid ] = false;
				ResetAllWeapons( playerid );
			}

			new rand = random( sizeof( RandomAFKZone ) );
			Dimi_SetPlayerPos( playerid, RandomAFKZone[ rand ][ 0 ], RandomAFKZone[ rand ][ 1 ], RandomAFKZone[ rand ][ 2 ] );
			SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			TogglePlayerControllable( playerid, false );
			SetCameraBehindPlayer( playerid );
			SetPlayerInterior( playerid, 18 );
			SetPlayerVirtualWorld( playerid, 0 );
		}
	}
}


//////////////////////////////////


//------------------------------------------------------------------------------

public PayDay( playerid ) {

	if( PlayerLogged[ playerid ] == true ) {

		SendClientMessage(playerid,tdboja,"_________________________| PAYDAY |_________________________");
		new stariiznos = PlayerInfo[ playerid ][ xBRacun ];
		
		new donatorkamata = 0, platapd = 0, plataadms = 0, plataprom = 0;
		
		PlayerInfo[ playerid ][ xRespekt ]++;
		PlayerInfo[ playerid ][ xOnlineSati ]++;
		PlayerInfo[ playerid ][ xPayDay ] = 0;
		PlayerInfo[ playerid ][ xSkolaLimit ] = 0;
		PlayerInfo[ playerid ][ xLesLimit ] = 0;

		if( PlayerInfo[ playerid ][ xNovac ] < 0 )
		{
			if( PlayerInfo[ playerid ][ xZatvor ] == 0 )
			{
				SendClientMessagee( playerid, 0xFF6347AA, "Niste platili vas dug, vrijeme je za zatvor(5 min)." );

				ResetAllWeapons( playerid );

				PlayerInfo[ playerid ][ xZatvor ] = OBICAN_ZATVOR;
				PlayerInfo[ playerid ][ xZatvorVreme ] = 5;
				
				format( globalstring, sizeof( globalstring ), "~r~Do slobode: ~w~%d ~r~min",( PlayerInfo[ playerid ][ xZatvorVreme ]+1 ) );
				PlayerTextDrawSetString(playerid,JailTD[playerid],globalstring);
				PlayerTextDrawShow(playerid,JailTD[playerid]);

				new rand = random( sizeof( RandomZatvor ) );
				Dimi_SetPlayerPos( playerid, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ], RandomZatvor[ rand ][ 2 ] );
				SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				TogglePlayerControllable( playerid, false );
				SetCameraBehindPlayer( playerid );
				SetPlayerInterior( playerid, 1 );
				SetPlayerVirtualWorld( playerid, 1 );
			}
		}

		if( GetFactionType( playerid ) == ORG_TIP_PD ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] == 0 && !IsPlayerPaused( playerid ) ) {
				platapd = 2000;
			}
		}
		else if( GetFactionType( playerid ) == ORG_TIP_CNN ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] == 0 && !IsPlayerPaused( playerid ) ) {
				platapd = 1200;
			}
		}
		else if( GetFactionType( playerid ) == ORG_TIP_MD ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] == 0 && !IsPlayerPaused( playerid ) ) {
				platapd = 1200;
			}
		}

		if( PlayerInfo[ playerid ][ xPromoter ] > 0 ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] == 0 && !IsPlayerPaused( playerid ) ) {
				plataprom = 1000;
			}
		}

		if( PlayerInfo[ playerid ][ xHelper ] > 0 ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] < 2 && !IsPlayerPaused( playerid ) ) {
				plataadms = 2000+(PlayerInfo[ playerid ][ xHelper ]*200);
			}
		}
		
		if( PlayerInfo[ playerid ][ xAdmin ] > 0 ) {
			if( antiCheatCS[ playerid ][ AFKMinute ] < 2 && !IsPlayerPaused( playerid ) ) {
				plataadms = 2200+(PlayerInfo[ playerid ][ xAdmin ]*200);
			}
		}

		if( PlayerInfo[ playerid ][ xRentID ] != -1 )
		{
			new id = PlayerInfo[ playerid ][ xRentID ];
			if( II[ id ][ iRentable ] == 1 )
			{
				if( II[ id ][ iRentPrice ] > PlayerInfo[ playerid ][ xNovac ] )
				{

					II[ id ][ iRentovano ]--;
					SaveProperty( id );

					PlayerInfo[ playerid ][ xRentID ] = -1;
					PlayerInfo[ playerid ][ xSpawn ] = SPAWN_NERP;
					SendClientMessageEx( playerid, ZUTA, "Niste imali dovoljno novca za rent, izbaceni ste." );
				}
				else
				{
					II[ id ][ iMoney ] += II[ id ][ iRentPrice ];
					SaveProperty( id );

					DajIgracuNovac( playerid, -II[ id ][ iRentPrice ] );
					SendClientMessageEx( playerid, ZUTA, "Platili ste rent %d$.", II[ id ][ iRentPrice ] );
				}
			}
			else if( II[ id ][ iRentable ] == 0 ) {
				II[ id ][ iRentovano ]--;
				SaveProperty( id );

				PlayerInfo[ playerid ][ xRentID ] = -1;
				PlayerInfo[ playerid ][ xSpawn ] = SPAWN_NERP;
				
				SendClientMessageEx( playerid, ZUTA, "Kuca koju ste rentali vise nije na iznajmljivanje!" );
			}
		}

		if( ServerInfo[ HappyHours ] == true ) PlayerInfo[ playerid ][ xRespekt ]++;

		if( PlayerInfo[ playerid ][ xVIPLevel ] == 5 )
		{
			PlayerInfo[ playerid ][ xRespekt ]+= 2;
		}
		if( PlayerInfo[ playerid ][ xIznosRate ] > 0 &&
			PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] > 0 &&
			PlayerInfo[ playerid ][ xIznosKredita ] > 0 )
		{
			if( PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] < PlayerInfo[ playerid ][ xIznosRate ] ) {
				PlayerInfo[ playerid ][ xIznosRate ] = PlayerInfo[ playerid ][ xPreostaloZaOtplatu ];
			}
			PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] -= PlayerInfo[ playerid ][ xIznosRate ];
			PlayerInfo[ playerid ][ xBRacun ] -= PlayerInfo[ playerid ][ xIznosRate ];
			if( PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] < 0 ) PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] = 0;
			if( PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] <= 0 ) { PlayerInfo[ playerid ][ xIznosKredita ] = 0; PlayerInfo[ playerid ][ xIznosRate ] = 0; }
		}

		if( PlayerInfo[ playerid ][ xHotelRoom ] != -1 ) {
			new hid = PlayerInfo[ playerid ][ xHotelRoom ];
			hotelInfo[ hid ][ hMoney ] += (hotelInfo[ hid ][ hRoomPrice ]/2);
			DajIgracuNovac( playerid, -hotelInfo[ hid ][ hRoomPrice ] );
			SaveHotel( hid );
			SendClientMessageEx( playerid, -1, "Platili ste %d$ cijenu najma.", hotelInfo[ hid ][ hRoomPrice ] );
		}

		new iznosplate = 0, osnova = 0, prihod = 0, rashod = 0, struja = 0, voda = 0, smece = 0, grijanje = 0, porez = 0, stecaj = 0;
		osnova = 45 + random( 5 );
		iznosplate = ((osnova*PlayerInfo[ playerid ][ xLevel ])+PlayerInfo[ playerid ][ xPlatniRacun ]);
		

		if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 )
		{
			new imovina = PlayerInfo[ playerid ][ xProperty ][ 0 ];
			//------------------------------------------------------------------
			if( II[ imovina ][ iUsage ] == IMOVINA_KUCA )//EDITEDD LEON
			{
				if( II[ imovina ][ iVrsta ] == MALA_KUCA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_KUCA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_KUCA ) { porez += 650; }
				else if( II[ imovina ][ iVrsta ] == VILA_KUCA ) { porez += 900; }
			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_STAN )
			{
				if( II[ imovina ][ iVrsta ] == MALI_STAN ) { porez += 150; }
				else if( II[ imovina ][ iVrsta ] == SREDNJI_STAN ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKI_STAN ) { porez += 650; }
			
			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_VIKENDICA )
			{
				if( II[ imovina ][ iVrsta ] == MALA_VIKENDICA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_VIKENDICA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_VIKENDICA ) { porez += 650; }
			}
			//------------------------------------------------------------------
			struja += (250 + random(50)); voda += (150 + random(50)); smece += 150; grijanje += 250;
			donatorkamata = 2;
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 4 )
			{
				donatorkamata = 4;
			}
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 )
			{
				donatorkamata = 5;
			}

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 )
			{
				donatorkamata = 5;
			}

		}
		
		if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 )
		{
			new imovina = PlayerInfo[ playerid ][ xProperty ][ 1 ];
			//------------------------------------------------------------------
			if( II[ imovina ][ iUsage ] == IMOVINA_KUCA )//EDITEDD LEON
			{
				if( II[ imovina ][ iVrsta ] == MALA_KUCA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_KUCA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_KUCA ) { porez += 650; }
				else if( II[ imovina ][ iVrsta ] == VILA_KUCA ) { porez += 900; }
			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_STAN )
			{
				if( II[ imovina ][ iVrsta ] == MALI_STAN ) { porez += 150; }
				else if( II[ imovina ][ iVrsta ] == SREDNJI_STAN ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKI_STAN ) { porez += 650; }

			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_VIKENDICA )
			{
				if( II[ imovina ][ iVrsta ] == MALA_VIKENDICA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_VIKENDICA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_VIKENDICA ) { porez += 650; }
			}
			//------------------------------------------------------------------
			
			struja += (250 + random(50)); voda += (150 + random(50)); smece += 150; grijanje += 250;
			donatorkamata = 2;
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 4 ) {
				donatorkamata = 4;
			}
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 ) {
				donatorkamata = 5;
			}

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) {
				donatorkamata = 5;
			}

		}
		
		if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 )
		{
			new imovina = PlayerInfo[ playerid ][ xProperty ][ 2 ];
			//------------------------------------------------------------------
			if( II[ imovina ][ iUsage ] == IMOVINA_KUCA )//EDITEDD LEON
			{
				if( II[ imovina ][ iVrsta ] == MALA_KUCA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_KUCA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_KUCA ) { porez += 650; }
				else if( II[ imovina ][ iVrsta ] == VILA_KUCA ) { porez += 900; }
			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_STAN )
			{
				if( II[ imovina ][ iVrsta ] == MALI_STAN ) { porez += 150; }
				else if( II[ imovina ][ iVrsta ] == SREDNJI_STAN ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKI_STAN ) { porez += 650; }

			}
			//------------------------------------------------------------------
			else if( II[ imovina ][ iUsage ] == IMOVINA_VIKENDICA )
			{
				if( II[ imovina ][ iVrsta ] == MALA_VIKENDICA ) { porez += 300; }
				else if( II[ imovina ][ iVrsta ] == SREDNJA_VIKENDICA ) { porez += 500; }
				else if( II[ imovina ][ iVrsta ] == VELIKA_VIKENDICA ) { porez += 650; }
			}
			//------------------------------------------------------------------
			
			struja += (250 + random(50)); voda += (150 + random(50)); smece += 150; grijanje += 250;
			donatorkamata = 2;
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 4 )
			{
				donatorkamata = 4;
			}
			
			if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 )
			{
				donatorkamata = 5;
			}

			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 )
			{
				donatorkamata = 5;
			}

		}
		
		if( PlayerInfo[ playerid ][ xVIPLevel ] == 5 )
		{
			PlayerInfo[ playerid ][ xRespekt ]+=2;
		}

		if( PlayerInfo[ playerid ][ xFirmaID ] != -1 ) { porez += 50; }

		if( donatorkamata != 0 )
		{
			if( PlayerInfo[ playerid ][ xBRacun ] >= 100000 && PlayerInfo[ playerid ][ xBRacun ] <= 4000000 )
			{
				stecaj = ( PlayerInfo[ playerid ][ xBRacun ]/1000 ) * donatorkamata;
			}
		}

		BussinesVodovodMoney( ( (voda/10)*3 ) );
		BussinesElektranaMoney( ( (struja/10)*3 ) );
		BussinesKomunalijeMoney( ( (smece/10)*3 ) );
		
		new strings[300];
		prihod = iznosplate + stecaj + platapd + plataadms + plataprom;
		rashod = struja + voda + porez + smece + grijanje;
		PlayerInfo[ playerid ][ xBRacun ] += prihod;
		PlayerInfo[ playerid ][ xBRacun ] -= rashod;
		PlayerInfo[ playerid ][ xPlatniRacun ] = 0;

		//format( strp1, sizeof( strp1 ), "NLB Banka | Plata je stigla na vas racun\n\nPlata: %d$\nSteceni interes: %d$\n\nKredit Informacije\nIznos kredita: %d$\nIznos rate: %d$\nZa otplatu: %d%\n\n", (iznosplate+platapd+plataadms+plataprom), stecaj, PlayerInfo[ playerid ][ xIznosKredita ], PlayerInfo[ playerid ][ xIznosRate ], PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] );
		//format( strp2, sizeof( strp2 ), "Platili ste\nPorez na imovinu: %d$\nStruja: %d$\nVoda: %d$\nSmece: %d$\nGrejanje: %d$\n\nStari iznos: %d$\nNovi iznos: %d$", porez, struja, voda, smece, grijanje, stariiznos, PlayerInfo[ playerid ][ xBRacun ] );

		//format( strp, sizeof( strp ), "%s%s", strp1, strp2);
		//ShowPlayerDialog( playerid, dialog_PAYDAY, DSMSG, D_NASLOV, strp, D_ODABERI, "" );

		///////////////////////////////////////////////////////////////////////

		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ) );
		format( strings, sizeof( strings ),""col_balkanstory"-------------------------------------------------\n\nPlata je stigla na vas racun\n\nPlata: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Interes: "SERVERBOJA_AQUA"%d\n"col_balkanstory"Staro stanje: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Novo stanje: "SERVERBOJA_AQUA"%d$\n\n", (iznosplate+platapd+plataadms+plataprom), stecaj, stariiznos, PlayerInfo[ playerid ][ xBRacun ] );
		strcat( DialogStrgEx, strings );

		format( strings, sizeof( strings ),""col_balkanstory"Kredit: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Rata: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Preostalo: "SERVERBOJA_AQUA"%d$\n\n"col_balkanstory"Porez na imovinu: "SERVERBOJA_AQUA"%d$", PlayerInfo[ playerid ][ xIznosKredita ], PlayerInfo[ playerid ][ xIznosRate ], PlayerInfo[ playerid ][ xPreostaloZaOtplatu ],porez );
		strcat( DialogStrgEx, strings );

		format( strings, sizeof( strings ),"\n"col_balkanstory"Struja: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Voda: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Smece: "SERVERBOJA_AQUA"%d$\n"col_balkanstory"Grijanje: "SERVERBOJA_AQUA"%d$\n\n"col_balkanstory"-------------------------------------------------", struja, voda, smece, grijanje );
		strcat( DialogStrgEx, strings );

		ShowPlayerDialog( playerid, dialog_PAYDAY, DSMSG, "Plata", DialogStrgEx, "Ok", "" );
		strdel( DialogStrgEx, 0, sizeof( DialogStrgEx ));

		///////////////////////////////////////////////////////////////////////

		SendInfoMessage( playerid, "Transakcija plate izvrsena na vas racun!" );

		if( PlayerInfo[ playerid ][ xPosao ] > 0 ) PlayerInfo[ playerid ][ xUgovor ] += 1;

		if( PlayerInfo[ playerid ][ xClan ] != 0 ) PlayerInfo[ playerid ][ xOrgUgovor ]++;

		if( PlayerInfo[ playerid ][ xKazneniUgovor ] != 0 ) PlayerInfo[ playerid ][ xKazneniUgovor ]--;

		if( PlayerInfo[ playerid ][ xBRacun ] <= -200000 ) {
			if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {
				new imovina = PlayerInfo[ playerid ][ xProperty ][ 0 ];
				II[ imovina ][ iLevel ] = 99;
				II[ imovina ][ iOwned ] = 0;
				II[ imovina ][ iNeaktivnost ] = 0;
				strmid( II[ imovina ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
				PropertyRefresh( imovina );
				SaveProperty( imovina );
				PlayerInfo[ playerid ][ xProperty ][ 0 ] = -1;
			}
			if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {
				new imovina = PlayerInfo[ playerid ][ xProperty ][ 1 ];
				II[ imovina ][ iLevel ] = 99;
				II[ imovina ][ iOwned ] = 0;
				II[ imovina ][ iNeaktivnost ] = 0;
				strmid( II[ imovina ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
				PropertyRefresh( imovina );
				SaveProperty( imovina );
				PlayerInfo[ playerid ][ xProperty ][ 1 ] = -1;
			}
			if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {
				new imovina = PlayerInfo[ playerid ][ xProperty ][ 2 ];
				II[ imovina ][ iLevel ] = 99;
				II[ imovina ][ iOwned ] = 0;
				II[ imovina ][ iNeaktivnost ] = 0;
				strmid( II[ imovina ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
				PropertyRefresh( imovina );
				SaveProperty( imovina );
				PlayerInfo[ playerid ][ xProperty ][ 2 ] = -1;
			}
			SendClientMessagee( playerid, ZUTA, "Zbog neizmirenih dugova u banci(-200.000$), oduzeta vam je sva imovina!" );
		}
		
		new nxtlevel = PlayerInfo[ playerid ][ xLevel ]+1;
		new expamount = nxtlevel*levelexp;
		if( PlayerInfo[ playerid ][ xRespekt ] >= expamount ) {
			format( globalstring, sizeof( globalstring ), "~g~NOVI NIVO...~n~~w~Sada ste na nivou: %d - bravo!", nxtlevel );
			announcement( playerid, globalstring, 5000, 1);
			PlayerPlaySound( playerid, 1052, 0.0, 0.0, 0.0);
			PlayerPlayMusic( playerid );
			PlayerInfo[ playerid ][ xLevel ]++;
			SetPlayerScore( playerid, PlayerInfo[ playerid ][ xLevel ] );
			PlayerInfo[ playerid ][ xPoboljsanja ] += 2;
			PlayerInfo[ playerid ][ xRespekt ] = 0; 
			format( globalstring, sizeof( globalstring ), "LVL: Sada si level %d ukucaj /upgrade za neke bonuse", nxtlevel );
			SendClientMessagee( playerid, SVETLOPLAVA, globalstring);
			format( globalstring, sizeof( globalstring ), "UP: Imas %d neiskoristenih Upgrade Poena", PlayerInfo[ playerid ][ xPoboljsanja ] );
			SendClientMessagee( playerid, BELA, globalstring);
		}
		
		if( PlayerInfo[ playerid ][ xRPPoen ] > 0 ) {
		
			DajIgracuNovac( playerid, PlayerInfo[ playerid ][ xRPPoen ]*1000 );
			
			SendClientMessageEx( playerid, ZUTA, "RPP: Dobili ste %d$ zbog %d RP poena.", PlayerInfo[ playerid ][ xRPPoen ]*1000, PlayerInfo[ playerid ][ xRPPoen ] );
		
		}
		if( PlayerInfo[ playerid ][ xVIPLevel ] == 4 )
		{
			SendInfoMessage(playerid,"Vi ste VIP level 4 i dobili ste dodatnih 2000$ na platu!");
			DajIgracuNovac( playerid, 2000 );
		}
		
		if( PlayerInfo[ playerid ][ xVIPLevel ] == 5 )
		{
			SendInfoMessage(playerid,"Vi ste VIP level 5 i dobili ste dodatnih 4000$ na platu!");
			DajIgracuNovac( playerid, 4000 );
		}
		
		if( PlayerInfo[ playerid ][ xRPPoen ] < 0 ) {

			DajIgracuNovac( playerid, PlayerInfo[ playerid ][ xRPPoen ]*1000 );

			SendClientMessageEx( playerid, ZUTA, "Izgubili ste %d$ zbog %d RP poena.", PlayerInfo[ playerid ][ xRPPoen ]*-1000, PlayerInfo[ playerid ][ xRPPoen ] );

		}
		
		/*if( PlayerInfo[ playerid ][ xOnlineSati ] == 500 || PlayerInfo[ playerid ][ xOnlineSati ] == 1000 ||
			PlayerInfo[ playerid ][ xOnlineSati ] == 1500 || PlayerInfo[ playerid ][ xOnlineSati ] == 2000 ||
			PlayerInfo[ playerid ][ xOnlineSati ] == 2500 || PlayerInfo[ playerid ][ xOnlineSati ] == 3000 ||
			PlayerInfo[ playerid ][ xOnlineSati ] == 3500 || PlayerInfo[ playerid ][ xOnlineSati ] == 4000 ||
			PlayerInfo[ playerid ][ xOnlineSati ] == 4500 || PlayerInfo[ playerid ][ xOnlineSati ] == 5000 ||
			PlayerInfo[ playerid ][ xOnlineSati ] == 5500 || PlayerInfo[ playerid ][ xOnlineSati ] == 6000 ) {

			PlayerInfo[ playerid ][ xApoeni ]++;
			SendClientMessageEx( playerid, ZUTA, "Dobili ste jedan APoen zbog %d online sati.", PlayerInfo[ playerid ][ xOnlineSati ] );
		}*/
		PlayerInfo[ playerid ][ xApoeni ]++;
		SendSrwMessage(playerid, "Dobili ste jedan aktivni poen, samo nastavite tako - cestitamo!");
		SendSrwMessage(playerid, "Mozete kucati: /apoeni");
		if( PlayerInfo[ playerid ][ xVIPLevel ] > 0 && PlayerInfo[ playerid ][ xVIPLevel ] < 5 ) {
			PlayerInfo[ playerid ][ xVipTime ]--;
			SendInfoMessage(playerid, "Ostalo Vam je jos %d sati koriscenja V.I.P. pogodnosti, vrijeme mozete produziti! (/pitaj ili /prijavi)");
		}
		if( PlayerInfo[ playerid ][ xVIPLevel ] == 5 ) {
			SendInfoMessage(playerid, "Vi ste Master Donator (VIP 5), vase pogodniosti ne mogu isteci!");
		}
		if( PlayerInfo[playerid][xVIPLevel] > 0 && PlayerInfo[playerid][xVIPLevel] < 5 && PlayerInfo[ playerid ][ xVipTime ] == 0 ) {
			PlayerInfo[playerid][xVIPLevel] = 0;
			PlayerInfo[playerid][xVipTime] = 0;
			SendInfoMessage(playerid, "Vas V.I.P. nivo je upravo istekao - da bi ste nastavili koristiti isti - produzite ga!" );
		}
		
		/*if( UzeoDPlatu[playerid] == true ) {
			UzeoDPlatu[playerid] = false;
			SendInfoMessage(playerid, "Vrijeme za uzimanje VIP plate je isteklo, mozete uzeti vasih 100000$ ponovo! (/gm)");
		}*/
		/*new time = gettime( );
		if( PlayerInfo[ playerid ][ xVIPLevel ] > 0 && PlayerInfo[ playerid ][ xVipTime ] != 0 && ( time - PlayerInfo[ playerid ][ xVipTime ] ) >= 2592000 )
		{
			SendClientMessagee( playerid, ZUTA, "Vas V.I.P. nivo je upravo istekao!" );
			PlayerInfo[ playerid ][ xVIPLevel ] = 0;
			PlayerInfo[ playerid ][ xVipTime ] = 0;
		}*/
		if(PlayerInfo[playerid][xFieldID] != -1) {
			SendClientMessage(playerid, -1, ""col_balkanstory"[ IMANJE ]:{ffffff} Vi posjedujete imanje - dobili ste dodatnih trideset hiljada dolara na platu!");
			PlayerInfo[ playerid ][ xBRacun ] += 30000;
		}
		if( ServerInfo[HappyJobs] == true ) {
			if( PlayerInfo[playerid][xPosao] != HappyJobID ) {
				if( PlayerInfo[ playerid ][ xPlatniRacun ] != NEMA_PLATU ) 
				{
					new hjplata = random(5000)+5000;
					SendClientMessageEx(playerid,-1,""col_sanm"[HAPPY JOBS]"col_white": Uspjesno ste dobili dodatnih %d na vasu platu zbog HappyJob sistema!", hjplata);
					PlayerInfo[ playerid ][ xBRacun ] += hjplata;
				}
				else {
					SendClientMessage(playerid,-1,""col_sanm"[HAPPY JOBS]"col_white": Ne mozete dobiti HJ platu jer niste radili zadnjih sat vremena!");
				}
			}
			else {
				SendClientMessage(playerid,-1,""col_sanm"[HAPPY JOBS]"col_white": Vi nemate posao, ne mozete dobiti HJ dodatnu platu...");
			}
		}
		if(PlayerInfo[playerid][xVakcina] != 1) 
		{
			new string[300];
			if( Maskuse[ playerid ] == false )
				format( string, sizeof( string ), "* %s povraca i kaslje uz teske bolove!", ImeIgraca( playerid ));
			else
				format( string, sizeof( string ), "* Maska_%d povraca i kaslje uz teske bolove!", PlayerInfo[ playerid ][ xMaskID ] );
			PorukaRadius( 30.0, playerid, string, LJUBICASTA );
			//announcement( playerid, "~y~Bolesni ste...\n~w~Sto prije pozovite lijecnika!", 3000, 5 );
			OnePlayAnim(playerid,"CRACK","crckdeth2",4.1,0,0,0,0,0);
			announcement(playerid,"Bolesni ste! Pozovite lijecnika...");
		}
		SavePlayer( playerid );
		UpdateBankTD( playerid );
		//UpdatePlataTD( playerid );
		if(AdminDuty[playerid] == true)
		{
			PlayerInfo[playerid][xDutyTime]++;
			SendInfoMessage(playerid,"Dobio si jedan DutyTime poen! Sada imas %d sati na admin/gm duznosti.",PlayerInfo[playerid][xDutyTime]);
			SavePlayer(playerid);
		}

	}
	return 1;
}
//------------------------------------------------------------------------------
public PayCheck( playerid ) {
	if( PlayerLogged[ playerid ] == true ) {

		PlayerInfo[ playerid ][ xPayDay ] += 1;

		if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) PlayerInfo[ playerid ][ xStaffMin ]++;

		if( PlayerInfo[ playerid ][ xHelper ] >= 1  ) PlayerInfo[ playerid ][ xStaffMin ]++;

		VremeZaCuvanje[ playerid ]++;
		if( VremeZaCuvanje[ playerid ] == 30 ) {
			VremeZaCuvanje[ playerid ] = 0;
			SavePlayer( playerid );
		}

		if( PlayerInfo[ playerid ][ xPayDay ] == 30) {
			if( PlayerInfo[ playerid ][ xHeroinAddict ] == true ) {
				if( PlayerInfo[ playerid ][ xHeroinUsed ] > 0)
					PlayerInfo[ playerid ][ xHeroinUsed ] -= 1;
			}
			else {
				if( PlayerInfo[ playerid ][ xHeroinIndicator ] > 0)
					PlayerInfo[ playerid ][ xHeroinIndicator ] -= 10;
			}
			if( PlayerInfo[ playerid ][ xMethAddict ] == true ) {
				if( PlayerInfo[ playerid ][ xMethUsed ] > 0)
					PlayerInfo[ playerid ][ xMethUsed ] -= 1;
			}
			else {
				if(PlayerInfo[ playerid ][ xMethIndicator ] > 0 )
					PlayerInfo[ playerid ][ xMethIndicator ] -= 10;
			}
			if( PlayerInfo[ playerid ][ xCokeCrackAddict ] == true ) {
				if( PlayerInfo[ playerid ][ xCokeCrackUsed ] > 0 )
					PlayerInfo[ playerid ][ xCokeCrackUsed ] -= 1;
			}
			else {
				if( PlayerInfo[ playerid ][ xCokeCrackIndicator ] > 0)
					PlayerInfo[ playerid ][ xCokeCrackIndicator ] -= 10;
			}
		}

		if( PlayerInfo[ playerid ][ xPayDay ] >= 60 ) {
			PayDay( playerid );
		}
	}
	return 1;
}


public InitFly(playerid)
{
	OnFly[playerid] = false;
	return;
}

bool:StartFly(playerid)
{
	if(OnFly[playerid])
		return false;
	OnFly[playerid] = true;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetPlayerPos(playerid,x,y,z+5.0);
	ApplyAnimation(playerid,"PARACHUTE","PARA_steerR",6.1,1,1,1,1,0,1);
	Fly(playerid);
	announcement(playerid,"~y~Leteci mod~n~~r~~k~~PED_FIREWEAPON~ ~w~- da idete vise~n~~r~RMB ~w~- da idete nize~n~\
	~r~~k~~PED_SPRINT~ ~w~- da ubrzate~n~\
	~r~~k~~SNEAK_ABOUT~ ~w~- da usporite",10000,3);
	return true;
}
//------------------------------------------------------------------------------

public Fly(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 1;
	new k, ud,lr;
	GetPlayerKeys(playerid,k,ud,lr);
	new Float:v_x,Float:v_y,Float:v_z,
		Float:x,Float:y,Float:z;
	if(ud < 0)	// forward
	{
		GetPlayerCameraFrontVector(playerid,x,y,z);
		v_x = x+0.1;
		v_y = y+0.1;
	}
	if(k & 128)	// down
		v_z = -0.2;
	else if(k & KEY_FIRE)	// up
		v_z = 0.2;
	if(k & KEY_WALK)	// slow
	{
		v_x /=5.0;
		v_y /=5.0;
		v_z /=5.0;
	}
	if(k & KEY_SPRINT)	// fast
	{
		v_x *=4.0;
		v_y *=4.0;
		v_z *=4.0;
	}
	if(v_z == 0.0)
		v_z = 0.025;
	SetPlayerVelocity(playerid,v_x,v_y,v_z);
	if(v_x == 0 && v_y == 0)
	{
		if(GetPlayerAnimationIndex(playerid) == 959)
			ApplyAnimation(playerid,"PARACHUTE","PARA_steerR",6.1,1,1,1,1,0,1);
	}
	else
	{
		GetPlayerCameraFrontVector(playerid,v_x,v_y,v_z);
		GetPlayerCameraPos(playerid,x,y,z);
		SetPlayerLookAt(playerid,v_x*500.0+x,v_y*500.0+y);
		if(GetPlayerAnimationIndex(playerid) != 959)
			ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_Accel",6.1,1,1,1,1,0,1);
	}
	if(OnFly[playerid])
		SetTimerEx("Fly",100,false,"i",playerid);
	return 1;
}

bool:StopFly(playerid)
{
	if(!OnFly[playerid])
		return false;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetPlayerPos(playerid,x,y,z);
	OnFly[playerid] = false;
	return true;
}

stock SetPlayerLookAt(playerid,Float:x,Float:y)
{
	new Float:Px, Float:Py, Float: Pa;
	GetPlayerPos(playerid, Px, Py, Pa);
	Pa = floatabs(atan((y-Py)/(x-Px)));
	if (x <= Px && y >= Py) 		Pa = floatsub(180.0, Pa);
	else if (x < Px && y < Py) 		Pa = floatadd(Pa, 180.0);
	else if (x >= Px && y <= Py)	Pa = floatsub(360.0, Pa);
	Pa = floatsub(Pa, 90.0);
	if (Pa >= 360.0)
		Pa = floatsub(Pa, 360.0);
	SetPlayerFacingAngle(playerid, Pa);
	return;
}

//------------------------------------------------------------------------------
forward FarmerCows( playerid, id );
public FarmerCows( playerid, id ) {

	if( id < 9 )
	{
		TogglePlayerControllable( playerid, true );
		ClearAnimations( playerid );
		DestroyPlayerObject( playerid, farmerInfo[ playerid ][ fiBucketObject ] );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 2613, 1, -0.200000, 1.000000, -0.699999, -9.000000, 90.000000, -21.000000);
		farmerInfo[ playerid ][ fiCowNumber ] = id;
		Dimi_SetPlayerCheckpoint( playerid, milkInfo[ id ][ cpPos ][ 0 ], milkInfo[ id ][ cpPos ][ 1 ], milkInfo[ id ][ cpPos ][ 2 ], 1.0);
		CheckpointStatus[ playerid ] = 16;
		SendJobMessage( playerid, "Pomuzli ste ovu kravu idite dalje, pomuzeno %d/9",id);
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 9 )
	{
		SendJobMessage( playerid, "Pomuzli ste sve krave sada odnesi mlijeko da se upakuje za preradu!" );
		TogglePlayerControllable( playerid, true );
		ClearAnimations( playerid );
		DestroyPlayerObject( playerid, farmerInfo[ playerid ][ fiBucketObject ] );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 2613, 1, -0.200000, 1.000000, -0.699999, -9.000000, 90.000000, -21.000000);
		farmerInfo[ playerid ][ fiCowNumber ] = 25;
		CheckpointStatus[ playerid ] = 16;
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
		Dimi_SetPlayerCheckpoint( playerid, -1081.7942,-1208.5925,129.2188, 1.0);
		
	}
	return 1;
}

//------------------------------------------------------------------------------
forward FarmerFruits( playerid, id );
public FarmerFruits( playerid, id )
{
	if( id == 1 )//obrao prvu jabuku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 2;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1087.0242,-1259.6188,132.1514, 1.0);//druga jabuka
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 2 )//obrao drugu jabuku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 3;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1102.7379,-1259.6202,132.3821, 1.0);//treca jabuka
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 3 )//obrao trecu jabuku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 4;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1118.9681,-1259.6205,132.3829, 1.0);//cetvrta jabuka
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 4 )//obrao cetvrtu jabuku
	{
		SendJobMessage( playerid, "Obrali ste jabuke, sada ih odnesi do skladista!" );
		RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19637, 1, 0.017999, 0.470999, 0.029999, -0.900001, 95.499961, -86.599990);
		farmerInfo[ playerid ][ fiFruitNumber ] = 5;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1072.8331, -1211.2627, 129.3114, 1.0);//obrao jabuke ide da ostavi
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 5 )//obrao prvu krusku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 7;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1087.1758,-1270.7754,132.5310, 1.0);//druga kruska
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 6 )//obrao drugu krusku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 8;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1102.7494,-1270.7584,132.5204, 1.0);//treca kruska
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 7 )//obrao trecu krusku
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 9;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1116.5676,-1270.7185,132.4448, 1.0);//cetvrta kruska
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	//----------------------------------------------------------------------------
	else if( id == 8 )//obrao cetvrtu krusku
	{
		SendJobMessage( playerid, "Obrali ste kruske, sada ih odnesi do skladista!" );
		RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19638, 1, 0.017999, 0.470999, 0.029999, -0.900001, 95.499961, -86.599990);
		farmerInfo[ playerid ][ fiFruitNumber ] = 10;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1072.8331, -1211.2627, 129.3114, 1.0);//obrao kruske ide da ostavi
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 9 )//obrao prvu sljivu
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 12;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1087.7372,-1282.4021,131.8305, 1.0);//druga sliva
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 10 )//obrao drugu sljivu
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 13;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1101.8395,-1282.4276,131.8511, 1.0);//treca sliva
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	else if( id == 11 )//obrao trecu sljivu
	{
		SendJobMessage( playerid, "Obrali ste ovo drvo, sada idite na sljedece!" );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		farmerInfo[ playerid ][ fiFruitNumber ] = 14;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1115.7712,-1282.4225,131.8437, 1.0);//cetvrta sliva
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	//----------------------------------------------------------------------------
	else if( id == 12 )//obrao cetvrtu sljivu
	{
		SendJobMessage( playerid, "Obrali ste sljive, sada ih odnesi do skladista!" );
		RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
		TogglePlayerControllable( playerid, true );
		//ClearAnimations( playerid );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19636, 1, 0.017999, 0.470999, 0.029999, -0.900001, 95.499961, -86.599990);
		farmerInfo[ playerid ][ fiFruitNumber ] = 15;
		CheckpointStatus[ playerid ] = 16;
		Dimi_SetPlayerCheckpoint( playerid, -1072.8331, -1211.2627, 129.3114, 1.0);//obrao sljive ide da ostavi
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
	}
	
	
	return 1;
}



//------------------------------------------------------------------------------
forward ZatvoriGranice( broj );
public ZatvoriGranice( broj )
{
	if( broj == 1 ) {
	
		DestroyDynamicObject(rampagranice1_1);
		rampagranice1_1 = CreateDynamicObject(968, 55.9345, -1536.2976, 4.8009,   0.0000, -90.0000, 82.2394);//newara
	}
	else if( broj == 2 ) {

		DestroyDynamicObject(rampagranice1_2);
		rampagranice1_2 = CreateDynamicObject(968, 48.9824, -1527.1849, 4.9181,   0.0000, 90.0000, 80.1310);//newara
	}
	else if( broj == 3 ) {
	
		DestroyDynamicObject(rampagranice2_1);
		rampagranice2_1 = CreateDynamicObject(968, 1748.3174, 535.2873, 27.1845,  0.0000, 90.0000, -19.2145);//newara
	}
	else if( broj == 4 ) {
	
		DestroyDynamicObject(rampagranice2_3);
		rampagranice2_3 = CreateDynamicObject(968, 1728.9937, 530.8777, 27.6405,   0.0000, 90.0000, -19.0000);//newara
		
	}
	return 1;
}
//------------------------------------------------------------------------------
public Istovar( playerid, vehicleid, broj )
{
	if( broj == 1) {
		TogglePlayerControllable( playerid, true );
		WOOD[ vehicleid ] = false;
		DestroyDynamicObject( WOODObject[ vehicleid ] );
		announcement( playerid, "~w~Drvece je istovareno..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, -569.0004, -93.3358, 63.9587, 5.0);
		CheckpointStatus[ playerid ] = 29;
		SendJobMessage( playerid, "Drvece je istovareno, vozi sada nazad do baze posla da uzmes zaradu." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 130;
	}
	if( broj == 2 ) {
	
		TogglePlayerControllable( playerid, true );
		announcement( playerid, "~w~Sljunak je istovaren..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, 620.8951, 832.1742, -42.9609, 5.0);
		CheckpointStatus[ playerid ] = 30;
		SendJobMessage( playerid, "Sljunak je istovaren, vozi sada nazad do baze posla da uzmes zaradu." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 133;
	}
	if( broj == 3 ) {
	
		
	}
	if( broj == 4 ) {
	
		
	}
	if( broj == 5 ) {
	
		
	}
	if( broj == 6 ) {
	
		
	}
	if( broj == 7 ) {
	
		TogglePlayerControllable( playerid, true );
		announcement( playerid, "~w~Beton je istovaren..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, 1912.03259, -1381.30347, 12.58050, 5.0);
		CheckpointStatus[ playerid ] = 24;
		RemovePlayerAttachedObject(playerid,betonobject1[playerid]);
		DestroyPlayerObject(playerid,betonobject1[playerid]);
		SendJobMessage( playerid, "Beton je istovaren, vozi sada nazad do baze posla." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 65;
	}
	if( broj == 8 ) {
	
		Dimi_DisablePlayerCheckpoint( playerid );
		CheckpointStatus[ playerid ] = 0;
		VehNovac[ GetPlayerVehicleID( playerid ) ] = false;
		PlayerPrevozNovca[ playerid ] = -1;
		new bonus = random(200);
		PlayerInfo[ playerid ][ xPlatniRacun ] += (2200+bonus);
		SavePlayer( playerid ); UpdatePlataTD( playerid );
		BussinesJobMoney( POSAO_PREVOZNOVCA, ((2200+bonus)/10) );
		SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );

		ServerInfo[ NovacBanka ] += 5000;
		if( ServerInfo[ NovacBanka ] > 1000000 ) ServerInfo[ NovacBanka ] = 1000000;
		SaveServerStats( );
		
		new novacstring[ 256 ];
		format( novacstring, sizeof( novacstring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Da opljackate banku kucajte\n"col_balkanstory"[ /postavidinamit /provalilozinku /pljackajbanku ]", ServerInfo[ NovacBanka ] );
		UpdateDynamic3DTextLabelText( ServerInfo[ NovacLabel ], BELA, novacstring );
		
		format( novacstring, sizeof( novacstring ), ""col_white"[ STANJE NOVCA ]\n"col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Maksimalno moze imati "col_balkanstory"1 000 000$\n"col_balkanstory"", ServerInfo[ NovacBanka ] );
		UpdateDynamic3DTextLabelText( ServerInfo[ NovacLabel2 ], BELA, novacstring );
	
		SendJobMessage( playerid, "Razvoz novca je zavrsen, zaradio si "col_white"%d$ "col_job"koji su ti legli na platni racun.", (2400+bonus) );
		StaroVreme[ playerid ] = 0;
		NovoVreme[ playerid ] = 0;
		
		TogglePlayerControllable( playerid, true );
	
	}
	return 1;
}
public Utovar( playerid, vehicleid, broj ) {
	if( broj == 1 ) {
		TogglePlayerControllable( playerid, true );
		WOOD[ GetPlayerVehicleID( playerid ) ] = true;
		WOODObject[ GetPlayerVehicleID( playerid ) ] = CreateDynamicObject( 18609, 0, 0, 1500, 0, 0, 0 );
		AttachDynamicObjectToVehicle( WOODObject[ GetPlayerVehicleID( playerid ) ], GetPlayerVehicleID( playerid ), -0.075000, -4.874999, 0.750000, 0.000000, 0.000000, 0.000000 );
		announcement( playerid, "~w~Drvece je utovareno, odvezi ga u pilanu..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, 2163.7754, -2299.2244, 14.2532, 5.0);
		CheckpointStatus[ playerid ] = 3;
		SendJobMessage( playerid, "Drvece je utovareno, vozi u pilanu da istovaris." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 129;
	}
	if( broj == 2 ) {
		TogglePlayerControllable( playerid, true );
		sljunak[ vehicleid ] = true;
		announcement( playerid, "~w~Sljunak je utovaren, odvezi ga u Zagreb na gradiliste..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, -2119.2505,245.4850,35.2527, 10.0);
		CheckpointStatus[ playerid ] = 4;
		SendJobMessage( playerid, "Sljunak je utovaren, vozi u Zagreb na gradiliste." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 145;
	}
	if( broj == 3 ) {
		
	}
	if( broj == 4 ) {
		VehCement[ vehicleid ] = true;
		PlayerCement[ playerid ] = vehicleid;
		TogglePlayerControllable( playerid, true );
		announcement( playerid, "~w~Beton je utovaren..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, 2433.0212, 1932.9012, 5.0138, 5.0);
		CheckpointStatus[ playerid ] = 23;
		SendJobMessage( playerid, "Beton je utovaren, odvezi ga do gradilista." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 145;
	}
	if( broj == 5 ) {
		VehNovac[ vehicleid ] = true;
		PlayerPrevozNovca[ playerid ] = vehicleid;
		TogglePlayerControllable( playerid, true );
		announcement( playerid, "~w~Novac je utovaren..", 5000, 1);
		Dimi_SetPlayerCheckpoint( playerid, 1504.6968, -1025.6024, 23.7875, 5.0);
		CheckpointStatus[ playerid ] = 36;
		SendJobMessage( playerid, "Novac je utovaren, odvezi ga sada nazad u banku." );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 200;
	}
	return 1;
}
//------------------------------------------------------------------------------
public Postaviotable( playerid, izbor ) {

	if( VehicleInfo[ izbor ][ vReg ] == 1 ) {
		SetTablice( VehicleInfo[ izbor ][ vID ] );
	}
	else if( VehicleInfo[ izbor ][ vReg ] == 2 ) {
		SetVehicleNumberPlate( VehicleInfo[ izbor ][ vID ], VehicleInfo[ izbor ][ vTablice ] );
	}
	ClearAnimations( playerid );
	SetVehicleToRespawn( VehicleInfo[ izbor ][ vID ] );
	SendClientMessagee( playerid, SVETLOPLAVA, "Postavio si tablice na vozilo." );
	return 1;
}
//------------------------------------------------------------------------------
public Fillup( playerid, fuel )
{
	new VID = GetPlayerVehicleID( playerid );
	new fsID = GetNearestFuelStation( playerid );
	TogglePlayerControllable( playerid, true );

	Fuel[ VID ] += fuel;
	FuelTime[ VID ] = 0;
	
	PuniGorivo[ playerid ] = false;
	
	VehicleInfo[ ScriptIDVozila[ VID ] ][ vFuel ] = Fuel[ VID ];
	
	if( VehicleInfo[ ScriptIDVozila[ VID ] ][ vFuelType ] == 1 ) {
	
		SendClientMessageEx( playerid, SVETLOPLAVA, "* Vozilo napunjeno gorivom, za: $%d.", fuel*FuelStation[ fsID ][ fsDieselPrice ] );//dizel inace
		DajIgracuNovac( playerid, -( fuel*FuelStation[ fsID ][ fsDieselPrice ] ) );
		BussinesPumpaMoney( playerid, fuel*FuelStation[ fsID ][ fsDieselPrice ] );
		FuelStation[ fsID ][ fsDieselL ] -= fuel;
		FStation_Save( fsID );
	}
	else if( VehicleInfo[ ScriptIDVozila[ VID ] ][ vFuelType ] == 2 ) {
	
		SendClientMessageEx( playerid, SVETLOPLAVA, "* Vozilo napunjeno gorivom, za: $%d.", fuel*FuelStation[ fsID ][ fsGasolinePrice ] );//benzin inace
		DajIgracuNovac( playerid, -( fuel*FuelStation[ fsID ][ fsGasolinePrice ] ) );
		BussinesPumpaMoney( playerid, fuel*FuelStation[ fsID ][ fsGasolinePrice ] );
		FuelStation[ fsID ][ fsGasolineL ] -= fuel;
		FStation_Save( fsID );
	}
	else if( VehicleInfo[ ScriptIDVozila[ VID ] ][ vFuelType ] == 3 ) {
	
		SendClientMessageEx( playerid, SVETLOPLAVA, "* Vozilo napunjeno gorivom, za: $%d.", fuel*FuelStation[ fsID ][ fsGasOilPrice ] );//gasno inace
		DajIgracuNovac( playerid, -( fuel*FuelStation[ fsID ][ fsGasOilPrice ] ) );
		BussinesPumpaMoney( playerid, fuel*FuelStation[ fsID ][ fsGasOilPrice ] );
		FuelStation[ fsID ][ fsGasOilL ] -= fuel;
		FStation_Save( fsID );
	}
}
//------------------------------------------------------------------------------
public CheckGas( playerid ) {
	static bool:InVehicle[ MAX_PLAYERS ];
	if( InVehicle[ playerid ] ) {
		InVehicle[ playerid ] = false;
	}
	if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
		new vehicle = GetPlayerVehicleID( playerid ),
			engine, lights, alarm, doors, bonnet, boot, objective;
		GetVehicleParamsEx( vehicle, engine, lights, alarm, doors, bonnet, boot, objective );
		if( engine == 1 ) {
				FuelTime[ vehicle ]++;
				if( Fuel[ vehicle ] >= 1 ) {
					if( FuelTime[ vehicle ] == 2 ) {
						if( Fuel[ vehicle ] <= 10 ) PlayerPlaySound( playerid, 1085, 0.0, 0.0, 0.0);

						if( GetPVarInt( playerid, "gGas" ) == 1) {
							if( !InVehicle[ playerid ] ) {
								InVehicle[ playerid ] = true;
							}
							if( !IsVehicleBajs( vehicle ) ) Fuel[ vehicle ] --;
						}
						if( TipVozila[ vehicle ] == POSLOVNO_VOZILO || TipVozila[ vehicle ] == ADMIN_VOZILO || TipVozila[ vehicle ] == HELPER_VOZILO || IsVehicleBajs( vehicle ) || IsVehicleBrod( vehicle ) || IsVehicleLetelica( vehicle ) ) {
							Fuel[ vehicle ] ++;
						}
						FuelTime[ vehicle ] = 0;
					}
				}
				else {
					SetPVarInt( playerid, "NoFuel", 1 );
					TogglePlayerControllable( playerid, false );
					SendClientMessagee( playerid, CRVENA, "Nema vise goriva. Upisite /exit da bi ste napustili vozilo ili zovite mehanicara /pozovi 555.");
				}
				if( ScriptIDVozila[ vehicle ] != -1 ) VehicleInfo[ ScriptIDVozila[ vehicle ] ][ vFuel ] = Fuel[ vehicle ];
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
FixHour(hour)
{
	hour = timeshift+hour;

	if(hour < 0)
	{
		hour = hour+24;
	}
	else if(hour > 23)
	{
		hour = hour-24;
	}
	shifthour = hour;
	return 1;
}
//------------------------------------------------------------------------------

forward StalksCheck( id );
public StalksCheck( id ) {

	new iFile[ 50 ];
	format( iFile, sizeof( iFile ), F_STALK, id );
	if( fexist( iFile ) )
	{

		new string[ 180 ], vrsta[ 10 ];
		if( stalkInfo[ id ][ sPlanted ] == true && stalkInfo[ id ][ sGrow ] == false )
		{

			if( stalkInfo[ id ][ sType ] == BILJKA_SLJIVA ) { vrsta = "SLJIVA"; }
			else if( stalkInfo[ id ][ sType ] == BILJKA_KRUSKA ) { vrsta = "KRUSKA"; }
			else if( stalkInfo[ id ][ sType ] == BILJKA_JABUKA ) { vrsta = "JABUKA"; }
			else if( stalkInfo[ id ][ sType ] == BILJKA_KUPUS ) { vrsta = "KUPUS"; }
			else if( stalkInfo[ id ][ sType ] == BILJKA_RUZE ) { vrsta = "RUZE"; }

			if( stalkInfo[ id ][ sHour ] >= 0 && stalkInfo[ id ][ sMinut ] >= 1 )
			{
				stalkInfo[ id ][ sMinut ]--;
				
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
			else if( stalkInfo[ id ][ sHour ] >= 1 && stalkInfo[ id ][ sMinut ] == 0 )//mamuti
			{
				stalkInfo[ id ][ sHour ]--;
				stalkInfo[ id ][ sMinut ] = 60;
				
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
			else if( stalkInfo[ id ][ sHour ] == 0 && stalkInfo[ id ][ sMinut ] == 0 )
			{
				stalkInfo[ id ][ sGrow ] = true;
				
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
			UpdateDynamic3DTextLabelText( stalkInfo[ id ][ s3D ], BELA, string );
			Stalk_Save( id );
		}
	}
	if( id+1 < MAX_STALKS ) SetTimerEx( "StalksCheck", 10, false, "d", id+1 );

	return 1;
}

SyncTime(); public SyncTime()
{
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
	//TextDrawSetString( moderntds[9], stringicc ); 
	format( stringicc1, sizeof( stringicc1 ), "~w~%d~r~/~w~%d~r~/~w~%d", day, month, year );
	TextDrawSetString( TDEditor_TD[36], stringicc1 );
	//TextDrawSetString( moderntds[7], stringicc1 );
	
	for( new i = 1; i < MAX_ATM; i++ )
	{
		if( atmInfo[ i ][ atmExists ] == true )
		{
			if( atmInfo[ i ][ atmVremeDoRoba ] != 0 )
			{
				atmInfo[ i ][ atmVremeDoRoba ]--;
				if( atmInfo[ i ][ atmVremeDoRoba ] == 0 )
				{
					atmInfo[ i ][ atmPreseceneZice ] = false;
					atmInfo[ i ][ atmProbijenBios ] = false;
				}
			}
		}
	}
	
	for( new i = 1; i < MAX_GZONE; i++ )
	{
		if( gZoneInfo[ i ][ gZoneTime ] != 0 )
		{
		
			gZoneInfo[ i ][ gZoneTime ]--;
		}
	}

	if( VremeZatvaranjaCelija > -1 )
	{
		VremeZatvaranjaCelija--;
		if( VremeZatvaranjaCelija == 0 )
		{
			UpravljanjeCelijama( false );
		}
	}
	
	/*if( tmpminute == 30 || tmpminute == 0 )
	{
		SetTimer( "RespawnCallGlobal", 60000, false );
		SCMA( 0x86C6DBAA, ""SERVERBOJA_AQUA"| RESPAWN | {2DBBFF}Pokrenut je respawn svih vozila za 1 minut!" );
		SCMA( 0x86C6DBAA, ""SERVERBOJA_AQUA"| RESPAWN | {2DBBFF}Udjite u svoja vozila prije respawna!" );
	}*/
	
	//if( tmpminute == 45 )
	//{

	SetTimerEx( "StalksCheck", 1000, false, "d", 0 );
	//}
	
	if( ( tmphour > ghour ) || ( tmphour == 0 && ghour == 23 ) )
	{
		SCMA(-1," ");
		format( globalstring, sizeof( globalstring ), ""col_balkanstory"(NOVA ERA): {ffffff}Sada je tacno "SERVERBOJA_AQUA"%d:00 {FFFFFF}sati - hvala vam sto igrate na serveru!", tmphour );
		//OOCNews( BELA, globalstring );
		//SCMA(-1,"Hvala vam sto igrate na Nova Era serveru!");
		SCMA(-1,globalstring);
		
		SCMA(-1," ");

		ghour = tmphour;

		if( tmphour == 21 )
		{
			SetWeather( 10 );
			GlobalnoVrijeme = 10;
		}

		if( realtime )
		{
			SetWorldTime( tmphour );
			GlobalniSat = tmphour;
			ServerInfo[ VremeInGame ] = tmphour;
		}
		DinamicWeather( );
		
		/*for( new i = 1; i < MAX_GZONE; i++ ) UKINUTO ZBOG BUGA
		{

			if( gZoneInfo[ i ][ gZoneGangID ] != -1 )
			{

				OI[ gZoneInfo[ i ][ gZoneGangID ] ][ oSafeMoney ] += 200;
				SaveOrganization( gZoneInfo[ i ][ gZoneGangID ] );

			}
		}*/
		
		UpravljanjeCelijama( true );
		VremeZatvaranjaCelija = 10;
		
		SetTimerEx( "IzvlacenjeKuglica", 3000, false, "d", 1 );
		
		for( new f = 0; f < MAX_GOBJ; f++ )
		{
		
			if( IsValidDynamicObject( dGunData[ f ][ gObjID ] ) )
				DestroyDynamicObject( dGunData[ f ][ gObjID ] );
				
			dGunData[ f ][ ObjPos ][ 0 ] = 0.0;
			dGunData[ f ][ ObjPos ][ 1 ] = 0.0;
			dGunData[ f ][ ObjPos ][ 2 ] = 0.0;
			dGunData[ f ][ gObjID ] = -1;
			dGunData[ f ][ ObjData ][ 0 ] = 0;
			dGunData[ f ][ ObjData ][ 1 ] = 0;
		}
		#if kladionica == 1
		IzvuciRezultateKladionica( );
		
		for(new playerid; playerid < MAX_PLAYERS; playerid++)
		{
		
			new bool:tiket = false;
			if( KladionicaListic[ playerid ][ Uplaceno ] && !KladionicaListic[ playerid ][ Zavrseno ] )
			{
				for(  new i = 0; i < 10; i++ )
				{
					if( KladionicaListic[ playerid ][ keciksdva ][ i ] != -1 )
					{
						if( Parovi[ KladionicaListic[ playerid ][ parID ][ i ] ][ Rezultat ][ 2 ] == KladionicaListic[ playerid ][ keciksdva ][ i ] )
						{
							tiket = true;
						}
						else if( Parovi[ KladionicaListic[ playerid ][ parID ][ i ] ][ Rezultat ][ 2 ] != KladionicaListic[ playerid ][ keciksdva ][ i ] )
						{
							tiket = false;
							break;
						}

					}
				}
			}
			if( tiket == true )
			{
				KladionicaListic[ playerid ][ Status ] = true;
				KladionicaListic[ playerid ][ Zavrseno ] = true;
				KladionicaListic[ playerid ][ Uplaceno ] = true;
				SaveKladionica( playerid );
			}
			else if( tiket == false )//moguc bug ba
			{
			
				KladionicaListic[ playerid ][ Status ] = false;
				/*for(  new i = 0; i < 10; i++ ) {
					KladionicaListic[ playerid ][ parID ][ i ] = -1;
					KladionicaListic[ playerid ][ keciksdva ][ i ] = -1;
					KladionicaListic[ playerid ][ Kvota ][ i ] = 0.0;
				}*/
				KladionicaListic[ playerid ][ Uplaceno ] = true;
				KladionicaListic[ playerid ][ Zavrseno ] = true;
				//KladionicaListic[ playerid ][ Uplata ] = 0;
				//KladionicaListic[ playerid ][ Dobitak ] = 0;
				SaveKladionica( playerid );

			}
		}
		
		PostaviParoveKladionica( );
		#endif
	}

	for(new i; i < MAX_PLAYERS; i++)
	{
		AFKCheck( i );

		PayCheck( i );

		CheckGas( i );

		OtherCheck( i );

		if( PlayerInfo[ i ][ xWanted ] != 0 && GetPlayerInterior( i ) == 0 && GetPlayerVirtualWorld( i ) == 0 )
		{
			MinutiIgraca[ i ]++;
			if( MinutiIgraca[ i ] == 6 )
			{
				MinutiIgraca[ i ] = 0;
				PlayerInfo[ i ][ xWanted ]--;
				Dimi_SetPlayerWantedLevel( i, PlayerInfo[ i ][ xWanted ] );
				if( PlayerInfo[ i ][ xWanted ] == 0 )
				{
					strmid( ZlocinInfo[ i ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
					strmid( ZlocinInfo[ i ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
					strmid( ZlocinInfo[ i ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
				}
			}
		}
		
		if( PlayerInfo[ i ][ xPljackaVreme ] != 0 )
		{
			PlayerInfo[ i ][ xPljackaVreme ]--;
		}
		
		if( PlayerInfo[ i ][ xHangarTime ] != 0 )
		{
		
			PlayerInfo[ i ][ xHangarTime ]--;
		}

		if( PlayerInfo[ i ][ xZauzimanjeVreme ] != 0 )
		{

			PlayerInfo[ i ][ xZauzimanjeVreme ]--;
		}
		
		if( PlayerInfo[ i ][ xSvercer ] != 0 )
		{

			PlayerInfo[ i ][ xSvercer ]--;
		}

		if( PlayerInfo[ i ][ xZatvor ] == OBICAN_ZATVOR )
		{
			if( VremeZatvaranjaCelija == 2 && OtvoreneCelije == true )
			{
				SendClientMessagee( i, SVETLOCRVENA, "ZATVOR | Celije se zatvaraju za 2 minuta, udjite u celije ili cete biti kaznjeni!");
			}
			else if( VremeZatvaranjaCelija == 1 && OtvoreneCelije == true )
			{
				SendClientMessagee( i, SVETLOCRVENA, "ZATVOR | Celije se zatvaraju za 1 minut, udjite u celije ili cete biti kaznjeni!");
			}
			else if( VremeZatvaranjaCelija == 0 && OtvoreneCelije == false )
			{
				if( IsPlayerInCell( i ) )
				{
					SendClientMessagee( i, SVETLOCRVENA, "ZATVOR | Celije su se zatvorile!");
				}
				else if( !IsPlayerInCell( i ) )
				{
					SendClientMessagee( i, SVETLOCRVENA, "ZATVOR | Celije su se zatvorile, ostali ste van celija i dobili 10 minuta dodatne kazne!");
					PlayerInfo[ i ][ xZatvorVreme ] += 10;
					new rand = random( sizeof( RandomZatvor ) );
					Dimi_SetPlayerPos( i, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ],RandomZatvor[ rand ][ 2 ] );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", i );
					announcement( i, "~y~Ucitavanje sistema i objekata...", 1000, 4 );
					TogglePlayerControllable( i, false );
					SetCameraBehindPlayer( i );
					SetPlayerInterior( i, 1 );
					SetPlayerVirtualWorld( i, 1 );
				}
			}
		}

	}
	return 1;
}


//------------------------------------------------------------------------------
forward GradjevinarKapijaClose( );
public GradjevinarKapijaClose( )
{
	MoveDynamicObject( gradjkapija, 1861.8921, -1384.9541, 12.5581, 2.00 );
}


forward ZatvoriPDVrata( );
public ZatvoriPDVrata( )
{
	if(vrataPD == true)
	{
		vrataPD = false;
		MoveDynamicObject( vrataPDobject, 239.5967, 116.8530, 1020.3098, 1.0, 0.0000, 0.0000, 90.0000 );
	}
}




forward RudnikLiftTrue( );
public RudnikLiftTrue( )
{
	RudnikLift = true;
	RudnikLiftuPokretu = false;
}

forward ulazeputnici(playerid,broj);
public ulazeputnici(playerid,broj)
{

	if(broj == 1)//druga stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		DestroyActor(BusActor3[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Bolnica" );
		SetPlayerCheckpoint(playerid,2116.2891, -1491.5397, 22.7968,3.0);
		BusActor1[playerid] = CreateActor(69, 2118.40674, -1490.58655, 23.95120,   -90.00000);
		BusActor2[playerid] = CreateActor(79, 2118.46313, -1491.68799, 23.95120,   -90.00000);
		SetActorFacingAngle(BusActor1[playerid], 90.00000);
		SetActorFacingAngle(BusActor2[playerid], 90.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 2;

	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 2)//treca stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Glen park" );
		SetPlayerCheckpoint(playerid,2075.3647, -1242.7875, 22.8079,3.0);
		BusActor1[playerid] = CreateActor(98, 2077.83594, -1241.57202, 23.96480,   90.00000);
		BusActor2[playerid] = CreateActor(101, 2077.96655, -1242.91565, 23.96480,   90.00000);
		SetActorFacingAngle(BusActor1[playerid], 90.00000);
		SetActorFacingAngle(BusActor2[playerid], 90.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 3;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 3)//cetvrta stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Auto pijaca" );
		SetPlayerCheckpoint(playerid,1682.7053, -1157.1478, 22.6555,3.0);
		BusActor1[playerid] = CreateActor(122, 1681.24304, -1154.87463, 23.81280,   0.00000);
		BusActor2[playerid] = CreateActor(124, 1682.61218, -1154.88672, 23.81280,   0.00000);
		BusActor3[playerid] = CreateActor(141, 1683.77417, -1154.84021, 23.81280,   0.00000);
		SetActorFacingAngle(BusActor1[playerid], 180.00000);
		SetActorFacingAngle(BusActor2[playerid], 180.00000);
		SetActorFacingAngle(BusActor3[playerid], 180.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 4;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 4)//peta stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		DestroyActor(BusActor3[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Komercijalna Banka" );
		SetPlayerCheckpoint(playerid,1416.3308, -1030.1265, 22.6545,3.0);
		BusActor1[playerid] = CreateActor(147, 1415.11121, -1027.73254, 23.81200,   0.00000);
		BusActor2[playerid] = CreateActor(169, 1416.34192, -1027.75720, 23.81200,   0.00000);
		SetActorFacingAngle(BusActor1[playerid], 180.00000);
		SetActorFacingAngle(BusActor2[playerid], 180.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 5;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 5)//sesta stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"MC Donalds" );
		SetPlayerCheckpoint(playerid,1128.0197, -942.0354, 41.6925,3.0);
		BusActor1[playerid] = CreateActor(186, 1128.15283, -939.61627, 42.88200,   0.00000);
		BusActor2[playerid] = CreateActor(185, 1127.07007, -939.65527, 42.88200,   0.00000);
		SetActorFacingAngle(BusActor1[playerid], 180.00000);
		SetActorFacingAngle(BusActor2[playerid], 180.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 6;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 6)//sedma stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Tempo Market" );
		SetPlayerCheckpoint(playerid,1050.0541, -1345.9054, 12.3782,3.0);
		BusActor1[playerid] = CreateActor(214, 1048.08911, -1347.23206, 13.53390,   -15.52060);
		BusActor2[playerid] = CreateActor(223, 1048.10046, -1345.36609, 13.53390,   -15.52060);
		BusActor3[playerid] = CreateActor(263, 1048.11060, -1346.39990, 13.53390,   -15.52060);
		SetActorFacingAngle(BusActor1[playerid], -90.00000);
		SetActorFacingAngle(BusActor2[playerid], -90.00000);
		SetActorFacingAngle(BusActor3[playerid], -90.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 7;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 7)//osma stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		DestroyActor(BusActor3[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Biro rada" );
		SetPlayerCheckpoint(playerid,1293.2910, -1603.2551, 12.3777,3.0);
		BusActor1[playerid] = CreateActor(12, 1291.2563, -1604.6388, 13.5808,   0.00000);
		BusActor2[playerid] = CreateActor(19, 1291.1912, -1603.6808, 13.5808,   0.00000);
		SetActorFacingAngle(BusActor1[playerid],  -90.00000);
		SetActorFacingAngle(BusActor2[playerid],  -90.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 8;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 8)//deveta stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Opstina" );
		SetPlayerCheckpoint(playerid,1393.3374, -1875.9353, 12.3777,3.0);
		BusActor1[playerid] = CreateActor(23, 1394.2711, -1878.2363, 13.5334,   0.00000);
		BusActor2[playerid] = CreateActor(29, 1393.0890, -1878.2089, 13.5334,   0.00000);
		SetActorFacingAngle(BusActor1[playerid], 0.00000);
		SetActorFacingAngle(BusActor2[playerid], 0.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 9;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 9)//deseta stanica
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Zeljeznicka stanica" );
		SetPlayerCheckpoint(playerid,1643.4191, -1876.1260, 12.3763,3.0);
		BusActor1[playerid] = CreateActor(46, 1644.9006, -1878.1599, 13.5295,   0.00000);
		SetActorFacingAngle(BusActor1[playerid], 0.00000);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 10;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 10)//jedanesa stanica
	{
		DestroyActor(BusActor1[playerid]);
		SendInfoMessage( playerid, "Sljedeca stanica: "col_balkanstory"Terminal" );
		SetPlayerCheckpoint(playerid,1817.6779, -1874.6764, 12.4065,3.0);
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[playerid] = 11;
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 11)//jedanesa stanica
	{

		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor3[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor4[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor5[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,12);

	}
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 12)//kraj isplata
	{
		DestroyActor(BusActor1[playerid]);
		DestroyActor(BusActor2[playerid]);
		DestroyActor(BusActor3[playerid]);
		DestroyActor(BusActor4[playerid]);
		DestroyActor(BusActor5[playerid]);
		IDBusaKojiVozi[ playerid ] = -1;
		IDIgracaKojiVoziBus[ GetPlayerVehicleID(playerid) ] = -1;
		TogglePlayerControllable(playerid,1);
		VoziBeogradStanicu[ playerid ] = 0;
		CheckpointStatus[ playerid ] = 0;
		Dimi_DisablePlayerCheckpoint( playerid );
		new bonus = random( PosloviInfo[ BonusBusBG ] );
		new isplata = PosloviInfo[ PlataBusBG ] + bonus;
		SendJobMessage( playerid, "Zavrsili ste liniju i zaradili "col_white"%d$" ,isplata );
		ShowPlayerDialog( playerid, dialog_BUSVOZACPOSAO, DSL, "Bus linije", ""col_balkanstory"(1). "col_white"Linija - Beograd\n"col_balkanstory"(2). "col_white"Linija BG - SA", D_ODABERI, D_ODUSTANI );
		PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
		SavePlayer( playerid );
		UpdatePlataTD( playerid );
		StaroVreme[ playerid ] = 0;
		NovoVreme[ playerid ] = 0;
		BussinesJobMoney( POSAO_BUSVOZAC, (200/10) );

	}
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	if(broj == 20)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,1472.6694,-2230.7698,13.3828,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 21)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,1414.5532,-2137.2952,13.3828,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 22)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,1845.6897,834.1715,9.7482,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 23)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,2074.6921,1677.4542,10.6719,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 24)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,2156.1326,2272.5405,10.6719,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 25)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,2119.6802,1928.6738,10.6719,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 26)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,2039.3781,1523.2173,10.6719,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 27)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,2046.3375,875.4427,7.0087,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 28)//
	{
		SendPlayerNotification(playerid,true,"Putnici ukrcani! Nastavite dalje!");
		SetPlayerCheckpoint(playerid,1664.0723,-908.5660,61.6411,3.0);
		TogglePlayerControllable(playerid,1);
		return 1;
	}
	else if(broj == 29)//
	{
		IDBusaKojiVozi[ playerid ] = -1;
		IDIgracaKojiVoziBus[ GetPlayerVehicleID(playerid) ] = -1;
		TogglePlayerControllable(playerid,1);
		VoziSarajevoStanicu[ playerid ] = 0;
		CheckpointStatus[ playerid ] = 0;
		Dimi_DisablePlayerCheckpoint( playerid );
		new bonus = random( PosloviInfo[ BonusBusSA ] );
		new isplata = PosloviInfo[ PlataBusSA ] + bonus;
		SendJobMessage( playerid, "Zavrsili ste liniju i zaradili "col_white"%d$" ,isplata );
		ShowPlayerDialog( playerid, dialog_BUSVOZACPOSAO, DSL, "Bus linije", ""col_balkanstory"(1). "col_white"Linija - Beograd\n"col_balkanstory"(2). "col_white"Linija BG - SA", D_ODABERI, D_ODUSTANI );
		PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
		SavePlayer( playerid );
		UpdatePlataTD( playerid );
		StaroVreme[ playerid ] = 0;
		NovoVreme[ playerid ] = 0;
		BussinesJobMoney( POSAO_BUSVOZAC, (200/10) );
		return 1;
	}
	
	return 1;
}


//------------------------------------------------------------------------------
public CarDamageTimer( playerid ) {
	new Float:vHealth,
		newcar = GetPlayerVehicleID( playerid ),
		engine, lights, alarm, doors, bonnet, boot, objective;

	if( IsPlayerInAnyVehicle( playerid ) ) {
		if( !IsVehicleLetelica( newcar ) && !IsVehicleBrod( newcar ) && !IsVehicleBajs( newcar ) ) {

			GetVehicleHealth(newcar, vHealth);

			if( vHealth >= 250 && vHealth <= 350 ) {
				GetVehicleParamsEx(newcar,engine, lights, alarm, doors, bonnet, boot, objective );
				SetVehicleParamsEx(newcar,0,lights,alarm,doors,bonnet,boot,objective);
				SetCameraBehindPlayer( playerid );
				announcement( playerid, "~r~Vozilo je unisteno. Pozovite mehanicara!", 3000, 1);
				vCanDrive[newcar] = 0;
			}
		}
	}
}
//------------------------------------------------------------------------------
public AntiSpawnCrash()
{
	carspawntimer = 0;
}
//------------------------------------------------------------------------------
public KickIgraca( playerid )
{
	Kick( playerid );
	return 1;
}
//------------------------------------------------------------------------------
public GPSConnect( playerid, gpslvl, vehicleid)
{
	// if login edit if(Bit1_Get(g_PlayerLogged, playerid) != 0)

		if(gpslvl == 1)
		{
			new TmpZone[MAX_ZONE_NAME];
			GetVehicleZone( vehicleid, TmpZone, sizeof(TmpZone));
			SendInfoMessage( playerid, "Vase vozilo je u cetvrti: %s", TmpZone);

			new Float:x,Float:y,Float:z;
			GetVehiclePos( vehicleid, x, y, z);

			Dimi_SetPlayerCheckpoint( playerid, x, y, z, 5.0);
			CheckpointStatus[ playerid ] = 1;
			SetPVarInt( playerid, "LocatingCar", 1);
			SetPVarInt( playerid, "GPSTimerCalled", 0);

			announcement( playerid, "~g~gps aktiviran", 3000, 1);
		}
		return 1;
}
//------------------------------------------------------------------------------
public BoxTrain( playerid ) {
	if(Training[ playerid ] == 0 ) {
		TogglePlayerControllable( playerid, 0);
		Dimi_SetPlayerPos( playerid, 768.1064,14.3897,1000.6992);
		SetPlayerFacingAngle( playerid, 266.8890);
		SetPlayerCameraPos( playerid, 765.4290,8.6809,1000.7123);
		SetPlayerCameraLookAt( playerid, 768.1064,14.3897,1000.6992);
		ApplyAnimation( playerid,"GYMNASIUM","GYMshadowbox",4.1,1,1,1,1,9500);
		SetTimerEx("BoxTrain", 10000, false, "i", playerid);
		Training[ playerid ]  = 1;
		announcement( playerid, "Treniranje...",10000,3);
	}
	else if(Training[ playerid ] == 1 ) {
		SetPlayerCameraPos( playerid, 771.5601,11.3144,1000.7026);
		SetPlayerCameraLookAt( playerid, 768.1064,14.3897,1000.6992);
		ApplyAnimation( playerid,"GYMNASIUM","GYMshadowbox",4.1,1,1,1,1,14500);
		SetTimerEx("BoxTrain", 15000, false, "i", playerid);
		announcement( playerid, "Treniranje...",15000,3);
		Training[ playerid ]  = 2;
	}
	else if( Training[ playerid ] == 2 ) {  
		BussinesMoney( uFirmi[ playerid ], 1000 );
		SetPlayerCameraPos( playerid, 772.9484,-0.2051,1000.7241);
		SetPlayerCameraLookAt( playerid, 768.1064,14.3897,1000.6992);
		ApplyAnimation( playerid,"GYMNASIUM","GYMshadowbox",4.1,1,1,1,1,19500);
		SetTimerEx("BoxTrain", 20000, false, "i", playerid);
		Training[ playerid ]  = 3;
		announcement( playerid, "Treniranje...",20000,3);
	}
	else if( Training[ playerid ] == 3 ) {
		TogglePlayerControllable( playerid, 1);
		SetCameraBehindPlayer( playerid );
		ClearAnimations( playerid );
		SendClientMessagee( playerid, UGBOJA, "Zavrsio si svoj trening, i naucio borbeni stil Boxing!");
		announcement( playerid, "Gotovo!",10000,3);
		SetPlayerFightingStyle ( playerid, FIGHT_STYLE_BOXING);
		PlayerInfo[ playerid ][ xBStil ] = 1; SavePlayer( playerid );
		Training[ playerid ]  = 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
public KungTrain( playerid ) {
	if(Training[ playerid ]  == 0) {
		TogglePlayerControllable( playerid, 0);
		Dimi_SetPlayerPos( playerid, 772.6890,5.4252,1000.7802);
		SetPlayerFacingAngle( playerid, 89.2975);
		SetPlayerCameraPos( playerid, 767.2456,-0.7102,1000.7197);
		SetPlayerCameraLookAt( playerid, 772.6890,5.4252,1000.7802);
		ApplyAnimation( playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,7500);
		SetTimerEx("KungTrain", 8000, false, "i", playerid);
		Training[ playerid ]  = 1;
		announcement( playerid, "Treniranje...",10000,3);
	}
	else if(Training[ playerid ]  == 1) {
		SetPlayerCameraPos( playerid, 765.4534,8.1254,1000.7133);
		SetPlayerCameraLookAt( playerid, 772.6890,5.4252,1000.7802);
		ApplyAnimation( playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,12500);
		SetTimerEx("KungTrain", 13000, false, "i", playerid);
		Training[ playerid ]  = 2;
		announcement( playerid, "Treniranje...",13000,3);
	}
	else if(Training[ playerid ]  == 2) {
		BussinesMoney( uFirmi[ playerid ], 1200 );
		SetPlayerCameraPos( playerid, 774.3497,10.2337,1000.7027);
		SetPlayerCameraLookAt( playerid, 772.6890,5.4252,1000.7802);
		ApplyAnimation( playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,17500);
		SetTimerEx("KungTrain", 18000, false, "i", playerid);
		Training[ playerid ]  = 3;
		announcement( playerid, "Treniranje...",18000,3);
	}
	else if(Training[ playerid ]  == 3)
	{
		TogglePlayerControllable( playerid, 1);
		SetCameraBehindPlayer( playerid );
		ClearAnimations( playerid );
		SendClientMessagee( playerid, UGBOJA, "Zavrsio si svoj trening, i naucio borbeni stil Kung Fu-a!");
		announcement( playerid, "Gotovo!",10000,3);
		SetPlayerFightingStyle ( playerid, FIGHT_STYLE_KUNGFU);
		PlayerInfo[ playerid ][ xBStil ] = 2; SavePlayer( playerid );
		Training[ playerid ]  = 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
public GrabTrain( playerid )
{
	if(Training[ playerid ]  == 0)
	{
		TogglePlayerControllable( playerid, 0);
		Dimi_SetPlayerPos( playerid, 767.1951,-2.5557,1000.7187);
		SetPlayerFacingAngle( playerid, 172.0182);
		SetPlayerCameraPos( playerid, 772.6243,-0.1576,1000.7242);
		SetPlayerCameraLookAt( playerid, 767.1951,-2.5557,1000.7187);
		ApplyAnimation( playerid,"GANGS","shake_carSH",4.0,1,0,0,0,8500);
		SetTimerEx("GrabTrain", 9000, false, "i", playerid);
		Training[ playerid ]  = 1;
		announcement( playerid, "Treniranje...",9000,3);
	}
	else if(Training[ playerid ]  == 1)
	{
		SetPlayerCameraPos( playerid, 763.0099,2.6098,1001.5942);
		SetPlayerCameraLookAt( playerid, 767.1951,-2.5557,1000.7187);
		ApplyAnimation( playerid,"GANGS","shake_cara",4.0,1,0,0,0,13500);
		SetTimerEx("GrabTrain", 14000, false, "i", playerid);
		Training[ playerid ]  = 2;
		announcement( playerid, "Treniranje...",14000,3);
	}
	else if(Training[ playerid ]  == 2)
	{
		BussinesMoney( uFirmi[ playerid ], 1400 );
		SetPlayerCameraPos( playerid, 769.8934,8.1243,1000.7101);
		SetPlayerCameraLookAt( playerid, 767.1951,-2.5557,1000.7187);
		ApplyAnimation( playerid,"FIGHT_D","FightD_G",4.0,1,0,0,0,18500);
		SetTimerEx("GrabTrain", 19000, false, "i", playerid);
		Training[ playerid ]  = 3;
		announcement( playerid,"Treniranje...",19000,3);
	}
	else if(Training[ playerid ]  == 3) 
	{
		TogglePlayerControllable( playerid, 1);
		SetCameraBehindPlayer( playerid );
		ClearAnimations( playerid );
		SendClientMessagee( playerid, UGBOJA, "Zavrsio si svoj trening, i naucio borbeni stil Grab'n'Kick!");
		announcement( playerid, "Gotovo!",10000,3);
		SetPlayerFightingStyle ( playerid, FIGHT_STYLE_GRABKICK);
		PlayerInfo[ playerid ][ xBStil ] = 4; SavePlayer( playerid );
		Training[ playerid ]  = 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
public KneeTrain( playerid ) {
	if(Training[ playerid ]  == 0) {
		TogglePlayerControllable( playerid, 0);
		Dimi_SetPlayerPos( playerid, 772.4446,5.4702,1000.7802);
		SetPlayerFacingAngle( playerid, 89.8261);
		SetPlayerCameraPos( playerid, 764.1777,5.6911,1000.7161);
		SetPlayerCameraLookAt( playerid, 772.4446,5.4702,1000.7802);
		ApplyAnimation( playerid,"GYMNASIUM","GYMshadowbox",4.0,1,1,1,1,29500);
		SetTimerEx("KneeTrain", 30000, false, "i", playerid);
		Training[ playerid ]  = 1;
		announcement( playerid, "Treniranje...",30000,3);
	}
	else if(Training[ playerid ]  == 1) {
		SetPlayerCameraPos( playerid, 770.2583,-2.5223,1000.7255);
		SetPlayerCameraLookAt( playerid, 772.4446,5.4702,1000.7802);
		ApplyAnimation( playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,34500);
		SetTimerEx("KneeTrain", 35000, false, "i", playerid);
		Training[ playerid ]  = 2;
		announcement( playerid, "Treniranje...",35000,3);
	}
	else if(Training[ playerid ]  == 2) {
		BussinesMoney( uFirmi[ playerid ], 1500 );
		SetPlayerCameraPos( playerid, 765.2747,12.5178,1000.7049);
		SetPlayerCameraLookAt( playerid, 772.4446,5.4702,1000.7802);
		ApplyAnimation( playerid,"BSKTBALL","BBALL_Dnk",4.0,1,0,0,0,36500);
		SetTimerEx("KneeTrain", 37000, false, "i", playerid);
		Training[ playerid ]  = 3;
		announcement( playerid, "Treniranje...",37000,3);
	}
	else if( Training[ playerid ]  == 3 ) {
		TogglePlayerControllable( playerid, 1);
		SetCameraBehindPlayer( playerid );
		ClearAnimations( playerid );
		SendClientMessagee( playerid, UGBOJA, "Zavrsio si svoj trening, i naucio borbeni stil KneeHead!");
		announcement( playerid, "Gotovo!",10000,3);
		SetPlayerFightingStyle ( playerid, FIGHT_STYLE_KNEEHEAD);
		PlayerInfo[ playerid ][ xBStil ] = 3; SavePlayer( playerid );
		Training[ playerid ]  = 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
public VehicleEngineStart( playerid ) {
	if( IsPlayerConnected( playerid ) ) {
		new engine,lights,alarm,doors,bonnet,boot,objective,
			vehicle = GetPlayerVehicleID( playerid ),
			Float:vHealth,
			RandomStart;

		RandomStart = random(10);
		GetVehicleHealth(vehicle, vHealth);
		SetPVarInt( playerid, "StartingVehicle", 0);
		if(vHealth >= 800 && vHealth <= 1000) {
			switch( RandomStart ) {
				case 0..8:
				{
					//vEngine[vehicle] = ON;
					SendInfoMessage( playerid, "Uspjesno ste pokrenuli motor.");
					announcement(playerid,"Motor upaljen...");
					TogglePlayerControllable( playerid, true );
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					SetVehicleParamsEx(vehicle,1,lights,alarm,doors,bonnet,boot,objective);
				}
				case 9:
					SendInfoMessage( playerid, "Niste uspjeli pokrenuti motor."),announcement(playerid,"Motor nije upaljen");
			}
		}
		else if(vHealth >= 500 && vHealth <= 799)
		{
			switch(RandomStart)
			{
				case 0..7:
				{
					//vEngine[vehicle] = ON;
					SendInfoMessage( playerid, "Uspjesno ste pokrenuli motor.");
					announcement(playerid,"Motor upaljen...");
					TogglePlayerControllable( playerid, true );
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					SetVehicleParamsEx(vehicle,1,lights,alarm,doors,bonnet,boot,objective);
				}
				case 8,9:
					SendInfoMessage( playerid, "Niste uspjeli pokrenuti motor."),announcement(playerid,"Motor nije upaljen");
			}
		}
		else if(vHealth >= 351 && vHealth <= 499)
		{
			switch(RandomStart)
			{
				case 0..5:
				{
					//vEngine[vehicle] = ON;
					SendInfoMessage( playerid, "Uspjesno ste pokrenuli motor.");
					announcement(playerid,"Motor upaljen...");
					TogglePlayerControllable( playerid, true );
					GetVehicleParamsEx(vehicle,engine, lights, alarm, doors, bonnet, boot, objective );
					SetVehicleParamsEx(vehicle,1,lights,alarm,doors,bonnet,boot,objective);
				}
				case 6..9:
					SendInfoMessage( playerid, "Niste uspjeli pokrenuti motor."),announcement(playerid,"Motor nije upaljen");
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerEditDynamicObject(playerid, objectid, response, 
	Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	new Float:oldX, Float:oldY, Float:oldZ,
		Float:oldRotX, Float:oldRotY, Float:oldRotZ;
	GetObjectPos(objectid, oldX, oldY, oldZ);
	GetObjectRot(objectid, oldRotX, oldRotY, oldRotZ);
	if( response == EDIT_RESPONSE_FINAL )
	{
		if( ObjectEdition_TYPE[ playerid ] != 255 ) {
			new hid = inProperty[ playerid ];
			new i = ObjectEdition_TYPE[ playerid ];
			if( hid != -1 ) {
				Furniture[ hid ][ i ][ f_X ] = x;
				Furniture[ hid ][ i ][ f_Y ] = y;
				Furniture[ hid ][ i ][ f_Z ] = z;
				Furniture[ hid ][ i ][ f_rX ] = rx;
				Furniture[ hid ][ i ][ f_rY ] = ry;
				Furniture[ hid ][ i ][ f_rZ ] = rz;
				Furniture[ hid ][ i ][ f_VW ] = GetPlayerVirtualWorld( playerid );
				SendClientMessagee( playerid, UGBOJA, "Namestaj sacuvan");
				DestroyDynamicObject( Furniture[ hid ][ i ][ f_Object ] );
				Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
				SaveFurniture( hid ); ObjectEdition_TYPE[ playerid ] = 255;
				return true;
			}
		}
		if( EditDGate[ playerid ] != -1 ) {
			new g = EditDGate[ playerid ];
			
			GateData[ g ][ gatePos ][ 0 ] = x;
			GateData[ g ][ gatePos ][ 1 ] = y;
			GateData[ g ][ gatePos ][ 2 ] = z;
			GateData[ g ][ gatePos ][ 3 ] = rx;
			GateData[ g ][ gatePos ][ 4 ] = ry;
			GateData[ g ][ gatePos ][ 5 ] = rz;
			
			SendInfoMessage( playerid, "Uspjesno sacuvana pozicija zatvorene kapije.");
			SendClientMessagee( playerid, UGBOJA, "Sada sacuvajte poziciju otvorene kapije.");
			
			PlayerEditObject( playerid, GateData[ g ][ gateObject ] );
			SaveGate( g ); EditDGate[ playerid ] = -1; EditDGateMove[ playerid ] = g;
			return true;
		}
		if( EditDGateMove[ playerid ] != -1 ) {
			new g = EditDGateMove[ playerid ];

			GateData[ g ][ gateMove ][ 0 ] = x;
			GateData[ g ][ gateMove ][ 1 ] = y;
			GateData[ g ][ gateMove ][ 2 ] = z;
			GateData[ g ][ gateMove ][ 3 ] = rx;
			GateData[ g ][ gateMove ][ 4 ] = ry;
			GateData[ g ][ gateMove ][ 5 ] = rz;

			SendInfoMessage( playerid, "Uspjesno sacuvana pozicija otvorene kapije.");
			ShowPlayerDialog( playerid, dialog_CREATEGATE_2, DSI, D_NASLOV, "Unesite brzinu zatvaranja i otvaranja kapije( 0-20.0).", D_ODABERI, D_NAZAD );
			DestroyDynamicObject( GateData[ g ][ gateObject ] );
			GateData[ g ][ gateObject ] = CreateDynamicObject( GateData[ g ][ gateModel ], GateData[ g ][ gatePos ][ 0 ], GateData[ g ][ gatePos ][ 1 ], GateData[ g ][ gatePos ][ 2 ], GateData[ g ][ gatePos ][ 3 ], GateData[ g ][ gatePos ][ 4 ], GateData[ g ][ gatePos ][ 5 ], GateData[ g ][ gateWorld ], GateData[ g ][ gateInterior ] );
   
			SaveGate( g ); EditDGate[ playerid ] = g; EditDGateMove[ playerid ] = -1;
			return true;
		}
		if( CreatingField[ playerid ] != -1 ) {
			new id = IsCordsInField( CreatingField[ playerid ], x, y );

			if( id != CreatingField[ playerid ] ) return PlayerEditObject( playerid, fieldInfo[ CreatingField[ playerid ] ][ fieldObject ] ), GRESKA( playerid, "Ne moze znak da ide izvan polja" );

			DestroyDynamicObject( fieldInfo[ id ][ fieldObject ] );
			
			fieldInfo[ id ][ fieldObject ] = CreateDynamicObject( 19470, x, y, z, rx, ry, rz, -1, -1, -1, 200.0 );
			fieldInfo[ id ][ fieldObjectPos ][ 0 ] = x;
			fieldInfo[ id ][ fieldObjectPos ][ 1 ] = y;
			fieldInfo[ id ][ fieldObjectPos ][ 2 ] = z;
			fieldInfo[ id ][ fieldObjectPos ][ 3 ] = rx;
			fieldInfo[ id ][ fieldObjectPos ][ 4 ] = ry;
			fieldInfo[ id ][ fieldObjectPos ][ 5 ] = rz;
			fieldInfo[ id ][ fieldTractorID ] = -1;  
			fieldInfo[ id ][ fieldAdditionID ] = -1;
			fieldInfo[ id ][ fieldTruckID ] = -1;

			new string[ 180 ];
			format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nImanje na prodaju!\nLevel:{FFFFFF} %d\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena:{FFFFFF}%d$\n/kupiimanje", fieldInfo[ id ][ fieldLevel ],id,fieldInfo[ id ][ fieldPrice ] );
			fieldInfo[ id ][ field3D ] = CreateDynamic3DTextLabel( string, BELA, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );

			Field_Save( id );
			ShowPlayerDialog( playerid, dialog_CREATEFIELD, DSI, D_NASLOV, "Unesite u prazno polje level i cijenu imanja.\nPrimer: 4 10000", D_ODABERI, D_NAZAD );
			return true;
		}
		if( EditKontejnera[ playerid ] != -1 ) {
			new i = EditKontejnera[ playerid ];
			DestroyDynamicObject( KontInfo[ i ][ koObjID ] );

			KontInfo[ i ][ koObjPos ][ 0 ] = x;
			KontInfo[ i ][ koObjPos ][ 1 ] = y;
			KontInfo[ i ][ koObjPos ][ 2 ] = z;
			KontInfo[ i ][ koObjRot ][ 0 ] = rx;
			KontInfo[ i ][ koObjRot ][ 1 ] = ry;
			KontInfo[ i ][ koObjRot ][ 2 ] = rz;
			KontInfo[ i ][ koObjID ] = CreateDynamicObject(1345, x, y, z, rx, ry, rz);
			SacuvajKont( i );
			KontInfo[ i ][ KontText3D ] = CreateDynamic3DTextLabel( ""col_balkanstory"[ KONTEJNER ]\n\n{FFFFFF}Koristite kontejner sljedecim komandama:\n"col_balkanstory"[ /trazi, /baci ]", -1, KontInfo[ i ][koObjPos][0], KontInfo[ i ][koObjPos][1], KontInfo[ i ][koObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditKontejnera[ playerid ] = -1;
			return true;
		}
		if( EditATM[ playerid ] != -1 )
		{
			new i = EditATM[ playerid ];
			new b_string[128];
			DestroyDynamicObject( atmInfo[ i ][ atmObject ] );

			atmInfo[ i ][ atmPos ][ 0 ] = x;
			atmInfo[ i ][ atmPos ][ 1 ] = y;
			atmInfo[ i ][ atmPos ][ 2 ] = z;
			atmInfo[ i ][ atmPos ][ 3 ] = rx;
			atmInfo[ i ][ atmPos ][ 4 ] = ry;
			atmInfo[ i ][ atmPos ][ 5 ] = rz;
			atmInfo[ i ][ atmPreseceneZice ] = false;
			atmInfo[ i ][ atmProbijenBios ] = false;
			atmInfo[ i ][ atmVremeDoRoba ] = 0;
			atmInfo[ i ][ atmExists ] = true;
			atmInfo[ i ][ atmObject ] = CreateDynamicObject(2942, x, y, z, rx, ry, rz);
			SacuvajATM( i );

			format( b_string, sizeof( b_string ),""col_yelow"[ BANKOMAT ]\nBroj bankomata: {FFFFFF}%d\n"col_yelow"Komande:\n{FFFFFF}/bankomat",i );
			atmInfo[ i ][ atmText3D ] = CreateDynamic3DTextLabel( b_string, -1, atmInfo[ i ][atmPos][ 0 ], atmInfo[ i ][atmPos][ 1 ], atmInfo[ i ][atmPos][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditATM[ playerid ] = -1;
			return true;
		}
		if( EditPresents[ playerid ] != -1 )	{
			new i = EditPresents[ playerid ];
			DestroyDynamicPickup( presentsInfo[ i ][ presObject ] );

			new object = 19054;
			new rand = random( 5 );
			switch( rand ) {
				case 0: object = 19054;
				case 1: object = 19055;
				case 2: object = 19056;
				case 3: object = 19057;
				case 4: object = 19058;
			}

			presentsInfo[ i ][ presPos ][ 0 ] = x;
			presentsInfo[ i ][ presPos ][ 1 ] = y;
			presentsInfo[ i ][ presPos ][ 2 ] = z;
			presentsInfo[ i ][ presPos ][ 3 ] = rx;
			presentsInfo[ i ][ presPos ][ 4 ] = ry;
			presentsInfo[ i ][ presPos ][ 5 ] = rz;
			presentsInfo[ i ][ presPlaced ] = true;
			presentsInfo[ i ][ presTaken ] = false;
			presentsInfo[ i ][ presObject ] = CreateDynamicPickup(object, 1, x, y, z, -1, -1);//CreateDynamicObject( object, x, y, z, rx, ry, rz);
			SavePresent( i );

			presentsInfo[ i ][ pres3d ] = CreateDynamic3DTextLabel( ""col_white"Poklon nije otvoren!\n\n"col_red"/poklon", -1, presentsInfo[ i ][ presPos ][ 0 ], presentsInfo[ i ][ presPos ][ 1 ], presentsInfo[ i ][ presPos ][ 2 ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditPresents[ playerid ] = -1;
			return true;
		}
		if( EditCTrees[ playerid ] != -1 )	{
			new i = EditCTrees[ playerid ];
			DestroyDynamicObject( CTree[ i ][ ctObject ] );

			CTree[ i ][ ctPos ][ 0 ] = x;
			CTree[ i ][ ctPos ][ 1 ] = y;
			CTree[ i ][ ctPos ][ 2 ] = z;
			CTree[ i ][ ctPos ][ 3 ] = rx;
			CTree[ i ][ ctPos ][ 4 ] = ry;
			CTree[ i ][ ctPos ][ 5 ] = rz;
			CTree[ i ][ ctPlaced ] = true;
			CTree[ i ][ ctObject ] = CreateDynamicObject(19076, x, y, z, rx, ry, rz);
			SaveCTree( i );

			CTree[ i ][ ct3d ] = CreateDynamic3DTextLabel( "{6ef83c}Zelimo vam srecne Bozicne\ni novogodisnje praznike!\n*** 2021 ***", -1, CTree[ i ][ ctPos ][ 0 ], CTree[ i ][ ctPos ][ 1 ], CTree[ i ][ ctPos ][ 2 ]+2, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditCTrees[ playerid ] = -1;
			return true;
		}
		if( EditXOrbs[ playerid ] != -1 )	{
			new i = EditXOrbs[ playerid ];
			DestroyDynamicObject( XmasOrbs[ i ][ xoObject ] );

			new object = 19059;
			new rand = random( 5 );
			switch( rand ) {
				case 0: object = 19059;
				case 1: object = 19060;
				case 2: object = 19061;
				case 3: object = 19062;
				case 4: object = 19063;
			}

			XmasOrbs[ i ][ xoPos ][ 0 ] = x;
			XmasOrbs[ i ][ xoPos ][ 1 ] = y;
			XmasOrbs[ i ][ xoPos ][ 2 ] = z;
			XmasOrbs[ i ][ xoPos ][ 3 ] = rx;
			XmasOrbs[ i ][ xoPos ][ 4 ] = ry;
			XmasOrbs[ i ][ xoPos ][ 5 ] = rz;
			XmasOrbs[ i ][ xoPlaced ] = true;
			XmasOrbs[ i ][ xoObject ] = CreateDynamicObject(object, x, y, z, rx, ry, rz);
			SaveXOrb( i );

			EditXOrbs[ playerid ] = -1;
			return true;
		}
		if( CreateParkingID[ playerid ] != -1 )	{
		
			new parkID = CreateParkingID[ playerid ];
			if( CreatingParkingLevel[ playerid ] == 1 ) {
		
				DestroyDynamicObject( ParkingInfo[ parkID ][ parkObject ] );
		
				ParkingInfo[ parkID ][ parkObjectPos ][ 0 ] = x;
				ParkingInfo[ parkID ][ parkObjectPos ][ 1 ] = y;
				ParkingInfo[ parkID ][ parkObjectPos ][ 2 ] = z;
				ParkingInfo[ parkID ][ parkObjectPos ][ 3 ] = rx;
				ParkingInfo[ parkID ][ parkObjectPos ][ 4 ] = ry;
				ParkingInfo[ parkID ][ parkObjectPos ][ 5 ] = rz;

				CreatingParkingLevel[ playerid ] = 2;

				ParkingInfo[ parkID ][ parkObject ] = CreateDynamicObject( 4639, x, y, z, rx, ry, rz , 0, 0, -1, 200.0 );
				Parking_Save( parkID );

				SendInfoMessage( playerid, "Sada dodajte pickup za kupovinu listica na slovo Y." );
				
			}
			return true;
		}
		if( EditRadar[ playerid ] != -1 )	{
		
			new radarID = EditRadar[ playerid ];
			DestroyDynamicObject( radarInfo[ radarID ][ radarObject ] );

			radarInfo[ radarID ][ radarPos ][ 0 ] = x;
			radarInfo[ radarID ][ radarPos ][ 1 ] = y;
			radarInfo[ radarID ][ radarPos ][ 2 ] = z;
			radarInfo[ radarID ][ radarPos ][ 3 ] = rx;
			radarInfo[ radarID ][ radarPos ][ 4 ] = ry;
			radarInfo[ radarID ][ radarPos ][ 5 ] = rz;
			radarInfo[ radarID ][ radarObject ] = CreateDynamicObject( 18880, x, y, z, rx, ry, rz );
			SaveRadar( radarID );

			EditRadar[ playerid ] = -1;
			return true;
		}
	}
	if( response == EDIT_RESPONSE_CANCEL ) {

		if( ObjectEdition_TYPE[ playerid ] != 255 ) {
			new hid = inProperty[ playerid ];
			new i = ObjectEdition_TYPE[ playerid ];
			if( hid != -1 ) {
				Furniture[ hid ][ i ][ f_X ] = oldX;
				Furniture[ hid ][ i ][ f_Y ] = oldY;
				Furniture[ hid ][ i ][ f_Z ] = oldZ;
				Furniture[ hid ][ i ][ f_rX ] = oldRotX;
				Furniture[ hid ][ i ][ f_rY ] = oldRotY;
				Furniture[ hid ][ i ][ f_rZ ] = oldRotZ;
				Furniture[ hid ][ i ][ f_VW ] = GetPlayerVirtualWorld( playerid );
				SendClientMessagee( playerid, CRVENA, "Odustali ste od postavljanja objekta.");
				DestroyDynamicObject( Furniture[ hid ][ i ][ f_Object ] );
				Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
				SaveFurniture( hid ); ObjectEdition_TYPE[ playerid ] = 255;
				return true;
			}
		}
	}
	return 1;
}
//////////////////////////////////NOVO//////////////////////////
OnPlayerRespondToEditingMenu(playerid, objectid, response, 
	Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
public OnPlayerRespondToEditingMenu(playerid, objectid, response, 
	Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	new Float:oldX, Float:oldY, Float:oldZ,
		Float:oldRotX, Float:oldRotY, Float:oldRotZ;
	GetObjectPos(objectid, oldX, oldY, oldZ);
	GetObjectRot(objectid, oldRotX, oldRotY, oldRotZ);
	if( response == EDIT_RESPONSE_FINAL )
	{
		if( ObjectEdition_TYPE[ playerid ] != 255 ) {
			new hid = inProperty[ playerid ];
			new i = ObjectEdition_TYPE[ playerid ];
			if( hid != -1 ) {
				Furniture[ hid ][ i ][ f_X ] = x;
				Furniture[ hid ][ i ][ f_Y ] = y;
				Furniture[ hid ][ i ][ f_Z ] = z;
				Furniture[ hid ][ i ][ f_rX ] = rx;
				Furniture[ hid ][ i ][ f_rY ] = ry;
				Furniture[ hid ][ i ][ f_rZ ] = rz;
				Furniture[ hid ][ i ][ f_VW ] = GetPlayerVirtualWorld( playerid );
				SendClientMessagee( playerid, UGBOJA, "Namestaj sacuvan");
				DestroyDynamicObject( Furniture[ hid ][ i ][ f_Object ] );
				Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
				SaveFurniture( hid ); ObjectEdition_TYPE[ playerid ] = 255;
				return true;
			}
		}
		if( EditDGate[ playerid ] != -1 ) {
			new g = EditDGate[ playerid ];
			
			GateData[ g ][ gatePos ][ 0 ] = x;
			GateData[ g ][ gatePos ][ 1 ] = y;
			GateData[ g ][ gatePos ][ 2 ] = z;
			GateData[ g ][ gatePos ][ 3 ] = rx;
			GateData[ g ][ gatePos ][ 4 ] = ry;
			GateData[ g ][ gatePos ][ 5 ] = rz;
			
			SendInfoMessage( playerid, "Uspjesno sacuvana pozicija zatvorene kapije.");
			SendClientMessagee( playerid, UGBOJA, "Sada sacuvajte poziciju otvorene kapije.");
			
			PlayerEditObject( playerid, GateData[ g ][ gateObject ] );
			SaveGate( g ); EditDGate[ playerid ] = -1; EditDGateMove[ playerid ] = g;
			return true;
		}
		if( EditDGateMove[ playerid ] != -1 ) {
			new g = EditDGateMove[ playerid ];

			GateData[ g ][ gateMove ][ 0 ] = x;
			GateData[ g ][ gateMove ][ 1 ] = y;
			GateData[ g ][ gateMove ][ 2 ] = z;
			GateData[ g ][ gateMove ][ 3 ] = rx;
			GateData[ g ][ gateMove ][ 4 ] = ry;
			GateData[ g ][ gateMove ][ 5 ] = rz;

			SendInfoMessage( playerid, "Uspjesno sacuvana pozicija otvorene kapije.");
			ShowPlayerDialog( playerid, dialog_CREATEGATE_2, DSI, D_NASLOV, "Unesite brzinu zatvaranja i otvaranja kapije( 0-20.0).", D_ODABERI, D_NAZAD );
			DestroyDynamicObject( GateData[ g ][ gateObject ] );
			GateData[ g ][ gateObject ] = CreateDynamicObject( GateData[ g ][ gateModel ], GateData[ g ][ gatePos ][ 0 ], GateData[ g ][ gatePos ][ 1 ], GateData[ g ][ gatePos ][ 2 ], GateData[ g ][ gatePos ][ 3 ], GateData[ g ][ gatePos ][ 4 ], GateData[ g ][ gatePos ][ 5 ], GateData[ g ][ gateWorld ], GateData[ g ][ gateInterior ] );
   
			SaveGate( g ); EditDGate[ playerid ] = g; EditDGateMove[ playerid ] = -1;
			return true;
		}
		if( CreatingField[ playerid ] != -1 ) {
			new id = IsCordsInField( CreatingField[ playerid ], x, y );

			if( id != CreatingField[ playerid ] ) return PlayerEditObject( playerid, fieldInfo[ CreatingField[ playerid ] ][ fieldObject ] ), GRESKA( playerid, "Ne moze znak da ide izvan polja" );

			DestroyDynamicObject( fieldInfo[ id ][ fieldObject ] );
			
			fieldInfo[ id ][ fieldObject ] = CreateDynamicObject( 19470, x, y, z, rx, ry, rz, -1, -1, -1, 200.0 );
			fieldInfo[ id ][ fieldObjectPos ][ 0 ] = x;
			fieldInfo[ id ][ fieldObjectPos ][ 1 ] = y;
			fieldInfo[ id ][ fieldObjectPos ][ 2 ] = z;
			fieldInfo[ id ][ fieldObjectPos ][ 3 ] = rx;
			fieldInfo[ id ][ fieldObjectPos ][ 4 ] = ry;
			fieldInfo[ id ][ fieldObjectPos ][ 5 ] = rz;
			fieldInfo[ id ][ fieldTractorID ] = -1;  
			fieldInfo[ id ][ fieldAdditionID ] = -1;
			fieldInfo[ id ][ fieldTruckID ] = -1;

			new string[ 180 ];
			format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nImanje na prodaju!\nLevel:{FFFFFF} %d\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena:{FFFFFF}%d$\n/kupiimanje", fieldInfo[ id ][ fieldLevel ],id,fieldInfo[ id ][ fieldPrice ] );
			fieldInfo[ id ][ field3D ] = CreateDynamic3DTextLabel( string, BELA, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );

			Field_Save( id );
			ShowPlayerDialog( playerid, dialog_CREATEFIELD, DSI, D_NASLOV, "Unesite u prazno polje level i cijenu imanja.\nPrimer: 4 10000", D_ODABERI, D_NAZAD );
			return true;
		}
		if( EditKontejnera[ playerid ] != -1 ) {
			new i = EditKontejnera[ playerid ];
			DestroyDynamicObject( KontInfo[ i ][ koObjID ] );

			KontInfo[ i ][ koObjPos ][ 0 ] = x;
			KontInfo[ i ][ koObjPos ][ 1 ] = y;
			KontInfo[ i ][ koObjPos ][ 2 ] = z;
			KontInfo[ i ][ koObjRot ][ 0 ] = rx;
			KontInfo[ i ][ koObjRot ][ 1 ] = ry;
			KontInfo[ i ][ koObjRot ][ 2 ] = rz;
			KontInfo[ i ][ koObjID ] = CreateDynamicObject(1345, x, y, z, rx, ry, rz);
			SacuvajKont( i );
			KontInfo[ i ][ KontText3D ] = CreateDynamic3DTextLabel( ""col_balkanstory"[ KONTEJNER ]\n\n{FFFFFF}Koristite kontejner sljedecim komandama:\n"col_balkanstory"[ /trazi, /baci ]", -1, KontInfo[ i ][koObjPos][0], KontInfo[ i ][koObjPos][1], KontInfo[ i ][koObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditKontejnera[ playerid ] = -1;
			return true;
		}
		if( EditATM[ playerid ] != -1 )
		{
			new i = EditATM[ playerid ];
			new b_string[128];
			DestroyDynamicObject( atmInfo[ i ][ atmObject ] );

			atmInfo[ i ][ atmPos ][ 0 ] = x;
			atmInfo[ i ][ atmPos ][ 1 ] = y;
			atmInfo[ i ][ atmPos ][ 2 ] = z;
			atmInfo[ i ][ atmPos ][ 3 ] = rx;
			atmInfo[ i ][ atmPos ][ 4 ] = ry;
			atmInfo[ i ][ atmPos ][ 5 ] = rz;
			atmInfo[ i ][ atmPreseceneZice ] = false;
			atmInfo[ i ][ atmProbijenBios ] = false;
			atmInfo[ i ][ atmVremeDoRoba ] = 0;
			atmInfo[ i ][ atmExists ] = true;
			atmInfo[ i ][ atmObject ] = CreateDynamicObject(2942, x, y, z, rx, ry, rz);
			SacuvajATM( i );

			format( b_string, sizeof( b_string ),""col_yelow"[ BANKOMAT ]\nBroj bankomata: {FFFFFF}%d\n"col_yelow"Komande:\n{FFFFFF}/bankomat",i );
			atmInfo[ i ][ atmText3D ] = CreateDynamic3DTextLabel( b_string, -1, atmInfo[ i ][atmPos][ 0 ], atmInfo[ i ][atmPos][ 1 ], atmInfo[ i ][atmPos][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditATM[ playerid ] = -1;
			return true;
		}
		if( EditPresents[ playerid ] != -1 )	{
			new i = EditPresents[ playerid ];
			DestroyDynamicPickup( presentsInfo[ i ][ presObject ] );

			new object = 19054;
			new rand = random( 5 );
			switch( rand ) {
				case 0: object = 19054;
				case 1: object = 19055;
				case 2: object = 19056;
				case 3: object = 19057;
				case 4: object = 19058;
			}

			presentsInfo[ i ][ presPos ][ 0 ] = x;
			presentsInfo[ i ][ presPos ][ 1 ] = y;
			presentsInfo[ i ][ presPos ][ 2 ] = z;
			presentsInfo[ i ][ presPos ][ 3 ] = rx;
			presentsInfo[ i ][ presPos ][ 4 ] = ry;
			presentsInfo[ i ][ presPos ][ 5 ] = rz;
			presentsInfo[ i ][ presPlaced ] = true;
			presentsInfo[ i ][ presTaken ] = false;
			presentsInfo[ i ][ presObject ] = CreateDynamicPickup(object, 1, x, y, z, -1, -1);//CreateDynamicObject( object, x, y, z, rx, ry, rz);
			SavePresent( i );

			presentsInfo[ i ][ pres3d ] = CreateDynamic3DTextLabel( ""col_white"Poklon nije otvoren!\n\n"col_red"/poklon", -1, presentsInfo[ i ][ presPos ][ 0 ], presentsInfo[ i ][ presPos ][ 1 ], presentsInfo[ i ][ presPos ][ 2 ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditPresents[ playerid ] = -1;
			return true;
		}
		if( EditCTrees[ playerid ] != -1 )	{
			new i = EditCTrees[ playerid ];
			DestroyDynamicObject( CTree[ i ][ ctObject ] );

			CTree[ i ][ ctPos ][ 0 ] = x;
			CTree[ i ][ ctPos ][ 1 ] = y;
			CTree[ i ][ ctPos ][ 2 ] = z;
			CTree[ i ][ ctPos ][ 3 ] = rx;
			CTree[ i ][ ctPos ][ 4 ] = ry;
			CTree[ i ][ ctPos ][ 5 ] = rz;
			CTree[ i ][ ctPlaced ] = true;
			CTree[ i ][ ctObject ] = CreateDynamicObject(19076, x, y, z, rx, ry, rz);
			SaveCTree( i );

			CTree[ i ][ ct3d ] = CreateDynamic3DTextLabel( "{6ef83c}Zelimo vam srecne Bozicne\ni novogodisnje praznike!\n*** 2021 ***", -1, CTree[ i ][ ctPos ][ 0 ], CTree[ i ][ ctPos ][ 1 ], CTree[ i ][ ctPos ][ 2 ]+2, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );

			EditCTrees[ playerid ] = -1;
			return true;
		}
		if( EditXOrbs[ playerid ] != -1 )	{
			new i = EditXOrbs[ playerid ];
			DestroyDynamicObject( XmasOrbs[ i ][ xoObject ] );

			new object = 19059;
			new rand = random( 5 );
			switch( rand ) {
				case 0: object = 19059;
				case 1: object = 19060;
				case 2: object = 19061;
				case 3: object = 19062;
				case 4: object = 19063;
			}

			XmasOrbs[ i ][ xoPos ][ 0 ] = x;
			XmasOrbs[ i ][ xoPos ][ 1 ] = y;
			XmasOrbs[ i ][ xoPos ][ 2 ] = z;
			XmasOrbs[ i ][ xoPos ][ 3 ] = rx;
			XmasOrbs[ i ][ xoPos ][ 4 ] = ry;
			XmasOrbs[ i ][ xoPos ][ 5 ] = rz;
			XmasOrbs[ i ][ xoPlaced ] = true;
			XmasOrbs[ i ][ xoObject ] = CreateDynamicObject(object, x, y, z, rx, ry, rz);
			SaveXOrb( i );

			EditXOrbs[ playerid ] = -1;
			return true;
		}
		if( CreateParkingID[ playerid ] != -1 )	{
		
			new parkID = CreateParkingID[ playerid ];
			if( CreatingParkingLevel[ playerid ] == 1 ) {
		
				DestroyDynamicObject( ParkingInfo[ parkID ][ parkObject ] );
		
				ParkingInfo[ parkID ][ parkObjectPos ][ 0 ] = x;
				ParkingInfo[ parkID ][ parkObjectPos ][ 1 ] = y;
				ParkingInfo[ parkID ][ parkObjectPos ][ 2 ] = z;
				ParkingInfo[ parkID ][ parkObjectPos ][ 3 ] = rx;
				ParkingInfo[ parkID ][ parkObjectPos ][ 4 ] = ry;
				ParkingInfo[ parkID ][ parkObjectPos ][ 5 ] = rz;

				CreatingParkingLevel[ playerid ] = 2;

				ParkingInfo[ parkID ][ parkObject ] = CreateDynamicObject( 4639, x, y, z, rx, ry, rz , 0, 0, -1, 200.0 );
				Parking_Save( parkID );

				SendInfoMessage( playerid, "Sada dodajte pickup za kupovinu listica na slovo Y." );
				
			}
			return true;
		}
		if( EditRadar[ playerid ] != -1 )	{
		
			new radarID = EditRadar[ playerid ];
			DestroyDynamicObject( radarInfo[ radarID ][ radarObject ] );

			radarInfo[ radarID ][ radarPos ][ 0 ] = x;
			radarInfo[ radarID ][ radarPos ][ 1 ] = y;
			radarInfo[ radarID ][ radarPos ][ 2 ] = z;
			radarInfo[ radarID ][ radarPos ][ 3 ] = rx;
			radarInfo[ radarID ][ radarPos ][ 4 ] = ry;
			radarInfo[ radarID ][ radarPos ][ 5 ] = rz;
			radarInfo[ radarID ][ radarObject ] = CreateDynamicObject( 18880, x, y, z, rx, ry, rz );
			SaveRadar( radarID );

			EditRadar[ playerid ] = -1;
			return true;
		}
	}
	if( response == EDIT_RESPONSE_CANCEL ) {

		if( ObjectEdition_TYPE[ playerid ] != 255 ) {
			new hid = inProperty[ playerid ];
			new i = ObjectEdition_TYPE[ playerid ];
			if( hid != -1 ) {
				Furniture[ hid ][ i ][ f_X ] = oldX;
				Furniture[ hid ][ i ][ f_Y ] = oldY;
				Furniture[ hid ][ i ][ f_Z ] = oldZ;
				Furniture[ hid ][ i ][ f_rX ] = oldRotX;
				Furniture[ hid ][ i ][ f_rY ] = oldRotY;
				Furniture[ hid ][ i ][ f_rZ ] = oldRotZ;
				Furniture[ hid ][ i ][ f_VW ] = GetPlayerVirtualWorld( playerid );
				SendClientMessagee( playerid, CRVENA, "Odustali ste od postavljanja objekta.");
				DestroyDynamicObject( Furniture[ hid ][ i ][ f_Object ] );
				Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ], Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ], Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
				SaveFurniture( hid ); ObjectEdition_TYPE[ playerid ] = 255;
				return true;
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerEditAttachedObject( playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
	if( response ) {
	
		if( EditingBody[ playerid ] == 1 ) {
		
			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL );
				GRESKA( playerid, "Losa pozicija naocara odradi je ponovo." );
				return true;
			}
			
			PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
		else if( EditingBody[ playerid ] == 2 ) {

			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_BANDANA );
				GRESKA( playerid, "Losa pozicija marame odradi je ponovo." );
				return true;
			}
			PlayerInfo[ playerid ][ xFacePos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xFacePos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xFacePos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xFacePos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xFacePos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xFacePos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xFacePos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xFacePos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xFacePos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
		else if( EditingBody[ playerid ] == 3 ) {

			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_HEAD );
				GRESKA( playerid, "Losa pozicija kape/marame/sesira odradi je ponovo." );
				return true;
			}
			PlayerInfo[ playerid ][ xHeadPos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xHeadPos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xHeadPos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xHeadPos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xHeadPos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xHeadPos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xHeadPos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
		else if( EditingBody[ playerid ] == 4 ) {

			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_HEAD );
				GRESKA( playerid, "Losa pozicija kape/marame/sesira odradi je ponovo." );
				return true;
			}
			PlayerInfo[ playerid ][ xHeadPos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xHeadPos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xHeadPos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xHeadPos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xHeadPos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xHeadPos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xHeadPos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
		else if( EditingBody[ playerid ] == 5 ) {

			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_HEAD );
				GRESKA( playerid, "Losa pozicija kape/marame/sesira odradi je ponovo." );
				return true;
			}
			PlayerInfo[ playerid ][ xHeadPos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xHeadPos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xHeadPos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xHeadPos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xHeadPos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xHeadPos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xHeadPos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xHeadPos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
		else if( EditingBody[ playerid ] == 6 ) {

			if( fScaleX > 2.0 || fScaleY > 2.0 || fScaleZ > 2.0 ) {
				EditAttachedObject( playerid, OBJECT_SLOT_HELMET );
				GRESKA( playerid, "Losa pozicija kacige odradi je ponovo." );
				return true;
			}
			PlayerInfo[ playerid ][ xHelmetPos ][ 0 ] = fOffsetX;
			PlayerInfo[ playerid ][ xHelmetPos ][ 1 ] = fOffsetY;
			PlayerInfo[ playerid ][ xHelmetPos ][ 2 ] = fOffsetZ;
			PlayerInfo[ playerid ][ xHelmetPos ][ 3 ] = fRotX;
			PlayerInfo[ playerid ][ xHelmetPos ][ 4 ] = fRotY;
			PlayerInfo[ playerid ][ xHelmetPos ][ 5 ] = fRotZ;
			PlayerInfo[ playerid ][ xHelmetPos ][ 6 ] = fScaleX;
			PlayerInfo[ playerid ][ xHelmetPos ][ 7 ] = fScaleY;
			PlayerInfo[ playerid ][ xHelmetPos ][ 8 ] = fScaleZ;
			EditingBody[ playerid ] = 0; SavePlayer( playerid );
		}
	}
	
	if( !response ) {
		if( EditingBody[ playerid ] == 1 ) {
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL );
			SungOn[ playerid ] = false;
		}
		else if( EditingBody[ playerid ] == 2 ) {
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA );
			FaceOn[ playerid ] = false;
		}
		else if( EditingBody[ playerid ] >= 3 && EditingBody[ playerid ] <= 5 ) {
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_HEAD );
			HeadOn[ playerid ] = false;
		}
		else if( EditingBody[ playerid ] == 6 ) {
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_HELMET );
			HelmetOn[ playerid ] = false;
		}
	}
	
	return 1;
}
//------------------------------------------------------------------------------
public OnModelSelectionResponse( playerid, extraid, index, modelid, response ) {
	if( ( extraid == 1 && response ) && inventoryInfo[ playerid ][ index ][ invExists ] ) {
	
		new name[ 64 ];
		ChosenItem[ playerid ] = index;
		format( name, sizeof( name ), "%s (%d)", inventoryInfo[ playerid ][ index ][ invItem ], inventoryInfo[ playerid ][ index ][ invQuantity ] );
		ShowPlayerDialog( playerid, dialog_INVENTORY, DSL, name, "Uzmi\nDaj\nBaci", "Odaberi", "Odustani");

	}
	return true;
}
//------------------------------------------------------------------------------
public OnPlayerModelSelection( playerid, response, listid, modelid) {

	if( listid == skinlist ) {
	
		if( response ) {
			if(!AdminDuty[playerid] && !PDuty[playerid] && PlayerInfo[playerid][xVIPLevel] != 5) {
			if( PlayerInfo[ playerid ][ xClan ] != 0 ) return GRESKA( playerid, "Ne mozete kupiti skin jer ste u organizaciji." ); }
			if( PlayerInfo[ playerid ][ xNovac ] < 500 ) return GRESKA( playerid, " Nemate dovoljno novca(500 $)." );
			SendInfoMessage( playerid, "Kupio si odecu za 500$.");
			PlayerInfo[ playerid ][ xSkin ] = modelid;
			SetPlayerSkin( playerid, modelid );
			SavePlayer( playerid ); DajIgracuNovac( playerid, -500 );


			if( IsPlayerInRangeOfPoint( playerid, 3.0, 0, 0, 0 ) ) {
				BussinesRodaMoney( 500 );
			}
			else {
				BussinesMoney( uFirmi[ playerid ], 500 );
			}
		}
		else SendClientMessagee( playerid, CRVENA, "Ugasio si kupovinu odece.");
		return 1;
	}
	//SelectTextDraw( playerid, UGBOJA );
	if( listid == regskinlist ) {
	
		if( response ) {
			//SendPlayerNotification(playerid,true,"Skin odabran!");
			PlayerInfo[ playerid ][ xSkin ] = modelid;
			SetPlayerSkin( playerid, modelid );
			SavePlayer( playerid );
			SelectTextDraw( playerid, UGBOJA );
			OdabraoSkinZaReg[playerid] = 1;
		}
		else
		{
			//SendPlayerNotification(playerid,true,"Morate odabrati skin!");
			SelectTextDraw( playerid, UGBOJA );
		}
		return 1;
	}
	return 1;
}


//------------------------------------------------------------------------------
public OnPlayerModelSelectionEx( playerid, response, extraid, modelid)
{
	if(extraid == 1)
	{
		if( response )
		{
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL, modelid, 2, 0.10, 0.03, 0, 0, 90, 90, 1.2, 1.2, 1.4 );
			EditAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL); EditingBody[ playerid ] = 1;
			PlayerInfo[ playerid ][ xSungMask ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -400 );
			BussinesMoney( uFirmi[ playerid ], 400); SungOn[ playerid ] = true;
		}
	}
	else if(extraid == 2)
	{
		if( response )
		{
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA, modelid, 2, 0.09, 0.02, -0.01, -90, 0, -90, 1.15, 1.15, 1.15 );
			EditAttachedObject( playerid, OBJECT_SLOT_BANDANA); EditingBody[ playerid ] = 2;
			PlayerInfo[ playerid ][ xFace ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -500 );
			BussinesMoney( uFirmi[ playerid ], 500); FaceOn[ playerid ] = true;
		}
	}
	else if(extraid == 3)
	{
		if( response )
		{
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, modelid, 2, 0.12, 0.01 ,0, -90, 0, -90, 1.2, 1.2, 1.1 );
			EditAttachedObject( playerid, OBJECT_SLOT_HEAD); EditingBody[ playerid ] = 3;
			PlayerInfo[ playerid ][ xHead ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -500 );
			BussinesMoney( uFirmi[ playerid ], 500); HeadOn[ playerid ] = true;
		}
	}
	else if(extraid == 4)
	{
		if( response )
		{
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, modelid, 2,0.15,0.02,-0.01,0,0,0,1.3,1.2,1.3);
			EditAttachedObject( playerid, OBJECT_SLOT_HEAD); EditingBody[ playerid ] = 4;
			PlayerInfo[ playerid ][ xHead ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -700 );
			BussinesMoney( uFirmi[ playerid ], 700); HeadOn[ playerid ] = true;
		}
	}
	else if(extraid == 5)
	{
		if( response )
		{
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, modelid, 2,0.14,0.01,-0.01,0,0,0,1.2,1.2,1.2);
			EditAttachedObject( playerid, OBJECT_SLOT_HEAD); EditingBody[ playerid ] = 5;
			PlayerInfo[ playerid ][ xHead ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -600 );
			BussinesMoney( uFirmi[ playerid ], 600); HeadOn[ playerid ] = true;
		}
	}
	else if(extraid == 6)
	{
		if( response )
		{
			if( modelid == -1 ) return GRESKA( playerid, " U ovom slotu nemate kupljeni objekt." );
			new Float:X, Float:Y, Float:Z, Float:A, i = (MAX_X_OBJECTS+2), hid = inProperty[ playerid ];
			GetPlayerPos( playerid, X, Y, Z ); GetPlayerFacingAngle( playerid, A );
			if( inProperty[ playerid ] == -1 ) return GRESKA( playerid, " Niste u vasoj kuci/stanu/vikendici." );
			if( strcmp( ImeIgraca( playerid ), II[ inProperty[ playerid ] ][ iOwner ], true ) == 0 )
			{
				for( new a = 0; a < MAX_X_OBJECTS; a++ ) {
					if( !Furniture[ hid ][ a ][ f_Model ] ) {
						i = a;
						break;
					} else continue;
				}

				if( i != (MAX_X_OBJECTS+2) ) {
					if( modelid == PlayerInfo[ playerid ][ xObject ][ 0 ] ) { PlayerInfo[ playerid ][ xObject ][ 0 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 1 ] ) { PlayerInfo[ playerid ][ xObject ][ 1 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 2 ] ) { PlayerInfo[ playerid ][ xObject ][ 2 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 3 ] ) { PlayerInfo[ playerid ][ xObject ][ 3 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 4 ] ) { PlayerInfo[ playerid ][ xObject ][ 4 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 5 ] ) { PlayerInfo[ playerid ][ xObject ][ 5 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 6 ] ) { PlayerInfo[ playerid ][ xObject ][ 6 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 7 ] ) { PlayerInfo[ playerid ][ xObject ][ 7 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 8 ] ) { PlayerInfo[ playerid ][ xObject ][ 8 ] = -1; }
					else if( modelid == PlayerInfo[ playerid ][ xObject ][ 9 ] ) { PlayerInfo[ playerid ][ xObject ][ 9 ] = -1; }
					Furniture[ hid ][ i ][ f_Model ] = modelid;
					Furniture[ hid ][ i ][ f_X ] = X;
					Furniture[ hid ][ i ][ f_Y ] = Y;
					Furniture[ hid ][ i ][ f_Z ] = Z;
					Furniture[ hid ][ i ][ f_rX ] = 0.0;
					Furniture[ hid ][ i ][ f_rY ] = 0.0;
					Furniture[ hid ][ i ][ f_rZ ] = A;
					Furniture[ hid ][ i ][ f_VW ] = GetPlayerVirtualWorld( playerid );
					Furniture[ hid ][ i ][ f_Object ] = CreateDynamicObject( Furniture[ hid ][ i ][ f_Model ], Furniture[ hid ][ i ][ f_X ]+2, Furniture[ hid ][ i ][ f_Y ], Furniture[ hid ][ i ][ f_Z ]+ 0.6, Furniture[ hid ][ i ][ f_rX ], Furniture[ hid ][ i ][ f_rY ], Furniture[ hid ][ i ][ f_rZ ], II[ hid ][ iVW ], II[ hid ][ iInterior ], -1, 200.0 );
					Streamer_Update( playerid );
					PlayerEditObject( playerid, Furniture[ hid ][ i ][ f_Object ] );
					SendClientMessagee( playerid, UGBOJA, "Pozicioniraj namestaj.");
					SendClientMessagee( playerid, BELA, "Koristite ~k~~PED_SPRINT~ da bi pomerali kameru." );
					SaveFurniture( hid ); ObjectEdition_TYPE[ playerid ] = i;
				} else {
					GRESKA( playerid, "Svi slotovi su zauzeti");
					GRESKA( playerid, "/namestaj izbrisi za brisanje");
				}
			} else GRESKA( playerid, "Ova imovina nije vasa.." );
		}
	}
	else if( extraid == 7 ) {
	
		if( response ) {
		
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_HELMET, modelid, 2, 0.070000, 0.000000, 0.000000, 88.000000, 77.000000, 0.000000 );
			EditAttachedObject( playerid, OBJECT_SLOT_HELMET ); EditingBody[ playerid ] = 6;
			PlayerInfo[ playerid ][ xHelmet ] = modelid; SavePlayer( playerid ); DajIgracuNovac( playerid, -100 );
			HelmetOn[ playerid ] = true;
		}
	}
	return 1;
}
//------------------------------------------------------------------------------

public PorukaRadius( Float:radi, playerid, string[ ], col1 )
{
	if( IsPlayerConnected( playerid ) )
	{
		new Float:posx,
			Float:posy,
			Float:posz,
			Float:oldposx,
			Float:oldposy,
			Float:oldposz,
			Float:tempposx,
			Float:tempposy,
			Float:tempposz,
			vehicleid = GetPlayerVehicleID(playerid),
			modelid = GetVehicleModel( vehicleid),
			vehicleid2,
			modelid2;

		GetPlayerPos( playerid, oldposx, oldposy, oldposz );

		for(new i; i < MAX_PLAYERS; i++)
		{
			if( IsPlayerConnected( i ) )
			{
				if( GetPlayerVirtualWorld( playerid ) == GetPlayerVirtualWorld( i ) )
				{
					if(!GetPVarInt(i, "BigEar"))
					{
						GetPlayerPos( i, posx, posy, posz );
						tempposx = ( oldposx -posx );
						tempposy = ( oldposy -posy );
						tempposz = ( oldposz -posz );

						if( IsPlayerInAnyVehicle( playerid ) && !IsACabrio( modelid ) && VehicleWindows[ vehicleid ] == 0)
						{
							if( IsPlayerInVehicle( i, vehicleid ) )
							{
								SendClientMessage( i, col1, string );
							}
						}
						else
						{
							vehicleid2 = GetPlayerVehicleID(i);
							modelid2 = GetVehicleModel( vehicleid2);

							if( !IsPlayerInAnyVehicle( i ) || IsACabrio( modelid2 ) || VehicleWindows[ vehicleid2 ] != 0 )
							{
								if(((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
								{
									SendClientMessage(i, col1, string);
								}
								else if(((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
								{
									SendClientMessage(i, col1, string);
								}
								else if(((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
								{
									SendClientMessage(i, col1, string);
								}
								else if(((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
								{
									SendClientMessage(i, col1, string);
								}
								else if(((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
								{
									SendClientMessage(i, col1, string);
								}
							}
						}
					}
					else
					{
						SendClientMessage(i, col1, string);
					}
				}
			}
		}
	}
	return 1;
}

//------------------------------------------------------------------------------
forward SkiniSnegGrudavnje( playerid );
public SkiniSnegGrudavnje( playerid ) {
	DestroyObject( Obj[ playerid ] );
	AlreadyShooted[ playerid ] = false;
}
//------------------------------------------------------------------------------
public SlobodnoSada( playerid ) {
	if( PlayerCP[ playerid ] == 0 )
		TogglePlayerControllable( playerid, true );
}
//------------------------------------------------------------------------------
forward IzlecenOdZavisnosti( playerid );
public IzlecenOdZavisnosti( playerid )
{
	Dimi_KillTimer( BolnicaTimer[ playerid ] );

	TogglePlayerControllable( playerid, true );
	SetPlayerInterior( playerid, 1 );
	SetPlayerVirtualWorld( playerid, 3 );
	new rand = random( sizeof( SpawnBolnicaNakonLijecenja ) );
	Dimi_SetPlayerPos( playerid, SpawnBolnicaNakonLijecenja[ rand ][ 0 ], SpawnBolnicaNakonLijecenja[ rand ][ 1 ], SpawnBolnicaNakonLijecenja[ rand ][ 2 ] );
	SetCameraBehindPlayer( playerid );
	VremeTDControl( playerid, false );

	SendClientMessagee( playerid, SVETLOPLAVA, "[Doktor]: {FFFFFF}Izlijecili smo vasu ovisnost 25000$ | Prijatan dan." );
	return 1;
}
//------------------------------------------------------------------------------
forward PustenIzBolnice( playerid );
public PustenIzBolnice( playerid )
{
	Dimi_KillTimer( BolnicaTimer[ playerid ] );
	if( PlayerInfo[ playerid ][ xUbijen ] == 1 )
	{
		PlayerInfo[ playerid ][ xUbijen ] = 0;
		TogglePlayerControllable( playerid, true );
		SetPlayerInterior( playerid, 1 );
		SetPlayerVirtualWorld( playerid, 3 );
		new rand = random( sizeof( SpawnBolnicaNakonLijecenja ) );
		Dimi_SetPlayerPos( playerid, SpawnBolnicaNakonLijecenja[ rand ][ 0 ], SpawnBolnicaNakonLijecenja[ rand ][ 1 ], SpawnBolnicaNakonLijecenja[ rand ][ 2 ] );
		SetCameraBehindPlayer( playerid );
		SendClientMessagee( playerid, SVETLOPLAVA, "[Doktor]: {FFFFFF}Vas bolnicki racun iznosi 200$ | Prijatan dan." );
		DajIgracuNovac( playerid, -200 );
		VremeTDControl( playerid, false );
	}
	hidectd(playerid);
	return 1;
}
//------------------------------------------------------------------------------
public PostaviSpawn( playerid )
{
	if(Modern[playerid] == 1)
	{
		HideBGTextdraw(playerid);
		HideBGTextdraw(playerid);
		HideBGTextdraw(playerid);
		ShowBGTextdraw(playerid);
	}
	TextDrawHideForPlayer(playerid,connect0);
	TextDrawHideForPlayer(playerid,connect1);
	TextDrawHideForPlayer(playerid,connect2);
	TextDrawHideForPlayer(playerid,connect3);
	TextDrawHideForPlayer(playerid,connect4);
	TextDrawHideForPlayer(playerid,connect5);
	hidectd(playerid);
	hidehb(playerid);
	Dimi_SetPlayerCheckpoint(playerid,0,0,0,1);
	CheckpointStatus[playerid] = 15;
	CheckpointStatus[ playerid ] = 0;
	PlayerTextDrawHide(playerid, PlayerGpsRadarText[ playerid ] );
	if( IsValidDynamicMapIcon( PlayerGpsRadar[ playerid ][_pgrIconId ] ) )
	{
		DestroyDynamicMapIcon( PlayerGpsRadar[ playerid ][_pgrIconId] );
	}
	PlayerGpsRadar[ playerid ][_pgrIconId] = -1;
	if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][_pgrObject ] ) )
	{
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][_pgrObject] );
	}
	PlayerGpsRadar[ playerid ][_pgrObject] = -1;
	Dimi_DisablePlayerCheckpoint(playerid);
	new OrgID = PlayerInfo[ playerid ][ xClan ];
	if( IsPlayerConnected( playerid ) )
	{
		if( PlayerInfo[ playerid ][ xUbijen ] == 1 )
		{
			TogglePlayerControllable( playerid, false );
		
			Dimi_SetPlayerHealth( playerid, 80.0 );
			SetPlayerInterior( playerid, 1 );
			SetPlayerVirtualWorld( playerid, playerid );
			
			new rand = random( sizeof( SpawnBolnica ) );
			Dimi_SetPlayerPos( playerid, SpawnBolnica[ rand ][ 0 ], SpawnBolnica[ rand ][ 1 ], SpawnBolnica[ rand ][ 2 ] );
			SetPlayerFacingAngle( playerid, 0.000 );

			ApplyAnimation( playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0 );
			//announcement( playerid, "~n~~w~Bicete izlijeceni za ~y~10 ~w~sekundi", 4000, 4 );
			
			SetPlayerCameraPos(playerid, 1156.9934, -1333.7917, 806.4727);
			SetPlayerCameraLookAt(playerid, 1156.4050, -1334.6035, 806.1156);
			// PLAYER_STATE_WASTED:old.code(id=1)
			Ranjen[playerid] = 0;
			BunnyHop[playerid] = 0;
			KillTimer(BHKrajTimer[playerid]);
			hidedmtd(playerid);
			ClearChat(playerid,50);
			hidebatd(playerid);
			//KillTimer(deathafterinjury(playerid));
			KillTimer(DeathAfterInjury[playerid]);
			hideinjurytd(playerid);
			showdt(playerid);
			SetPlayerInterior(playerid,0);

			TogHud[ playerid ] = false;

			TogPlayerHud(playerid);
			if(Modern[playerid] == 0)
			{
				ShowLogo(playerid);
			}
			PlayerInfo[playerid][xDeathScreen] = 1;

			SetTimerEx( "spawnplayer", 10000, false, "i", playerid );
			
			BolnicaTimer[ playerid ] = SetTimerEx( "PustenIzBolnice", 10000, false, "i", playerid );
		}
		else
		{
			if( PlayerInfo[ playerid ][ xZatvor ] == OBICAN_ZATVOR )
			{
				new rand = random( sizeof( RandomZatvor ) );
				Dimi_SetPlayerPos( playerid, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ],RandomZatvor[ rand ][ 2 ] );
				SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				TogglePlayerControllable( playerid, false );
				SendInfoMessage( playerid, "Nedovrsena zatvorska kazna, natrag u zatvor.");
				SetCameraBehindPlayer( playerid );
				SetPlayerInterior( playerid, 1 );
				SetPlayerVirtualWorld( playerid, 1 );

			}
			else if( PlayerInfo[ playerid ][ xZatvor ] == ALKATRAZ )///jese
			{
				Dimi_SetPlayerPos( playerid, 268.66840, 1882.33179, -29.90740 );
				SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
				ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				TogglePlayerControllable( playerid, false );
				SendClientMessagee( playerid, CRVENA, "{FF0000}AREA | {FFFFFF}Niste odsluzili svoju kaznu i vraceni ste u Areu!");
				SetCameraBehindPlayer( playerid );
				SetPlayerInterior( playerid, 0 );
				SetPlayerVirtualWorld( playerid, 1 );
				SetPlayerWorldBounds( playerid, 337.5694,101.5826,1940.9759,1798.7453 );

			}
			else
			{
			
				if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_ADMIN )
				{
					if( PlayerInfo[ playerid ][ xAdmin ] >= 1 )
					{
						Dimi_SetPlayerPos( playerid, 2570.1541,1567.2025,11.2616 );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
					}
					else
					{
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_VIP )
				{
					if( PlayerInfo[ playerid ][ xVIPLevel ] >= 1 )
					{
						Dimi_SetPlayerPos( playerid, 2834.4917,-1560.6304,11.0998 );
						SetPlayerFacingAngle( playerid, 7.8334 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
					}
					else
					{
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_HELPER )
				{
					if( PlayerInfo[ playerid ][ xHelper ] >= 1 )
					{
						Dimi_SetPlayerPos( playerid, 2570.1541,1567.2025,11.2616 );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
					}
					else
					{
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_OBICAN_LS_1 ) {
					new rand = random( sizeof( RandomLSSpawn1 ) );
					Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ],RandomLSSpawn1[ rand ][ 2 ] );
					SetPlayerFacingAngle( playerid, 360.000 );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, 0 );
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_BAZA ) {
					Dimi_SetPlayerPos( playerid, OI[ OrgID ][ oPozIntX ], OI[ OrgID ][ oPozIntY ] , OI[ OrgID ][ oPozIntZ ] );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, OI[ OrgID ][ oInt ] );
					SetPlayerVirtualWorld( playerid, OI[ OrgID ][ oVw ] );
					inOrgInt[ playerid ] = OrgID;
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_IMOVINA_1 ) {
					if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {
						new i = PlayerInfo[ playerid ][ xProperty ][ 0 ];

						Dimi_SetPlayerPos( playerid, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						SetCameraBehindPlayer( playerid );
						TogglePlayerControllable( playerid, false );
						SetPlayerInterior( playerid, II[ i ][ iInterior ] );
						SetPlayerVirtualWorld( playerid, II[ i ][ iVW ] );
						inProperty[ playerid ] = i;
					}
					else {
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ],RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}

				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_IMOVINA_2 ) {
					if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {
						new i = PlayerInfo[ playerid ][ xProperty ][ 1 ];

						Dimi_SetPlayerPos( playerid, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						SetCameraBehindPlayer( playerid );
						TogglePlayerControllable( playerid, false );
						SetPlayerInterior( playerid, II[ i ][ iInterior ] );
						SetPlayerVirtualWorld( playerid, II[ i ][ iVW ] );
						inProperty[ playerid ] = i;
					}
					else {
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ],RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}

				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_IMOVINA_3 ) {
					if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {
						new i = PlayerInfo[ playerid ][ xProperty ][ 2 ];

						Dimi_SetPlayerPos( playerid, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						SetCameraBehindPlayer( playerid );
						TogglePlayerControllable( playerid, false );
						SetPlayerInterior( playerid, II[ i ][ iInterior ] );
						SetPlayerVirtualWorld( playerid, II[ i ][ iVW ] );
						inProperty[ playerid ] = i;
					}
					else {
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ],RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}

				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_BELAKUCA ) {
					Dimi_SetPlayerPos( playerid, 1292.5704, -832.4692, 1085.6328 );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, 5 );
					SetPlayerVirtualWorld( playerid, 0 );
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_OBICAN_LS_2 ) {
					new rand = random( sizeof( RandomLSSpawn2 ) );
					Dimi_SetPlayerPos( playerid, RandomLSSpawn2[ rand ][ 0 ], RandomLSSpawn2[ rand ][ 1 ],RandomLSSpawn2[ rand ][ 2 ] );
					SetPlayerFacingAngle( playerid, 360.000 );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, 0 );
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_OBICAN_SF ) {
					new rand = random( sizeof( RandomSFSpawn ) );
					Dimi_SetPlayerPos( playerid, RandomSFSpawn[ rand ][ 0 ], RandomSFSpawn[ rand ][ 1 ],RandomSFSpawn[ rand ][ 2 ] );
					SetPlayerFacingAngle( playerid, 360.000 );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, 0 );
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_RENTHOTEL ) {
					if( PlayerInfo[ playerid ][ xHotelRoom ] != -1 ) {
						new i = PlayerInfo[ playerid ][ xHotelRoom ];

						if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_1 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2246.6826, -1160.8252, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_2 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2235.9670, -1158.5640, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_3 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2235.7524, -1169.7406, 1029.8043 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_4 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2227.1511, -1182.9784, 1029.8043 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_5 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2207.9285, -1194.5630, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_6 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2198.8984, -1174.5468, 1029.8043 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_7 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2188.1833, -1155.7197, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_8 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2198.7791, -1158.6515, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_9 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2188.1833, -1155.7197, 1029.7969 );
						}
						else if( strcmp( ImeIgraca( playerid ), hotelInfo[ i ][ hGuest_10 ], true ) == 0) {
							Dimi_SetPlayerPos( playerid, 2198.7791, -1158.6515, 1029.7969 );
						}
						else {
							PlayerInfo[ playerid ][ xHotelRoom ] = -1;
							SendClientMessagee( playerid, SVETLOPLAVA, "* Iseljeni ste iz hotela!");
							new rand = random( sizeof( RandomLSSpawn1 ) );
							Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ],RandomLSSpawn1[ rand ][ 2 ] );
							SetPlayerFacingAngle( playerid, 360.000 );
							SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
							ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
							TogglePlayerControllable( playerid, false );
							SetCameraBehindPlayer( playerid );
							SetPlayerInterior( playerid, 0 );
							PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
							return 1;
						}

						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						SetCameraBehindPlayer( playerid );
						TogglePlayerControllable( playerid, false );
						SetPlayerInterior( playerid, hotelInfo[ i ][ hInterior ] );
						SetPlayerVirtualWorld( playerid, hotelInfo[ i ][ hVW ] );
						inHotel[ playerid ] = i;
					}
					else {
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}

				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_PROMOTER )
				{
					if( PlayerInfo[ playerid ][ xPromoter ] >= 1 )
					{
						Dimi_SetPlayerPos( playerid, 725.6091, -1440.5584, 13.6136 );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
					}
					else
					{
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					} 
				}
				else if( PlayerInfo[ playerid ][ xSpawn ] == SPAWN_RENT ) {
					if( PlayerInfo[ playerid ][ xRentID ] != -1 ) {
						new i = PlayerInfo[ playerid ][ xRentID ];

						Dimi_SetPlayerPos( playerid, II[ i ][ iExit ][ 0 ], II[ i ][ iExit ][ 1 ], II[ i ][ iExit ][ 2 ] );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						SetCameraBehindPlayer( playerid );
						TogglePlayerControllable( playerid, false );
						SetPlayerInterior( playerid, II[ i ][ iInterior ] );
						SetPlayerVirtualWorld( playerid, II[ i ][ iVW ] );
						inProperty[ playerid ] = i;
					}
					else {
						new rand = random( sizeof( RandomLSSpawn1 ) );
						Dimi_SetPlayerPos( playerid, RandomLSSpawn1[ rand ][ 0 ], RandomLSSpawn1[ rand ][ 1 ], RandomLSSpawn1[ rand ][ 2 ] );
						SetPlayerFacingAngle( playerid, 360.000 );
						SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
						ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
						TogglePlayerControllable( playerid, false );
						SetCameraBehindPlayer( playerid );
						SetPlayerInterior( playerid, 0 );
						PlayerInfo[ playerid ][ xSpawn ] = SPAWN_OBICAN_LS_1;
					}
				}
				else if( PlayerInfo[playerid][xSpawn] == SPAWN_NERP )
				{
					new rand = random( sizeof( RandomLSSpawn2 ) );
					Dimi_SetPlayerPos( playerid, RandomLSSpawn2[ rand ][ 0 ], RandomLSSpawn2[ rand ][ 1 ],RandomLSSpawn2[ rand ][ 2 ] );
					SetPlayerFacingAngle( playerid, 360.000 );
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
					TogglePlayerControllable( playerid, false );
					SetCameraBehindPlayer( playerid );
					SetPlayerInterior( playerid, 0 );
				}
				else if(PlayerInfo[playerid][xAdmin] == 0 && \
					PlayerInfo[playerid][xHelper] == 0 && \
					PlayerInfo[playerid][xClan] == 0 && \
					PlayerInfo[playerid][xLevel] >= 5 && \
					PlayerInfo[playerid][xProperty][0] == -1 &&\
					PlayerInfo[playerid][xProperty][1] == -1 &&\
					PlayerInfo[playerid][xProperty][2] == -1
				)
				{
					Dimi_SetPlayerPos(playerid,1727.0195,-1633.9911,20.2159);
					SetPlayerSkin(playerid,137);
					SendInfoMessage(playerid,"Ti si beskucnik i spawnao si se u domu za beskucnike!");
					SendInfoMessage(playerid,"Ti nemas imovine, nisi clan neke organizacije,level si 5+.");
					SetTimerEx( "SlobodnoSada", 4000, false, "i", playerid );
					ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
				}
			}
		}
	}
	SetTimerEx( "hidektdd", 2000, false, "i", playerid );
	return true;
}


//------------------------------------------------------------------------------
forward RemoveAttachedObject( playerid, slot );
public RemoveAttachedObject( playerid, slot ) {
	if( IsPlayerConnected( playerid ) && IsPlayerAttachedObjectSlotUsed( playerid, slot ) ) {
		RemovePlayerAttachedObject( playerid, slot );
	}
	return true;
}
//------------------------------------------------------------------------------

IsInventoryWeapon( name[] ) 
{

	for( new i = 0; i < 47; i++) {

		if( strcmp( WeaponInfos[ i ][ wName ], name, true ) == 0 ) { return true; }
	}
	return false;
}

forward OnPlayerUseItem( playerid, itemid, name[] );
public OnPlayerUseItem( playerid, itemid, name[] ) {

	if( !strcmp( name, "Pizza", true ) ) {
	
		DajIgracuGlad( playerid, 9 );
		Dimi_SetPlayerHealth( playerid, 50 );

		if( !IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) {
			SetPlayerAttachedObject(playerid, OBJECT_SLOT_RHAND, 2702, 6, 0.173041, 0.049197, 0.056789, 0.000000, 274.166107, 299.057983, 1.000000, 1.000000, 1.000000);
			SetTimerEx( "RemoveAttachedObject", 3000, false, "dd", playerid, OBJECT_SLOT_RHAND );
		}

		Inventory_Remove(playerid, "Pizza" );

		ApplyAnimation( playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1 );
		format( globalstring, sizeof( globalstring ), "%s jede picu.", ImeIgraca( playerid ) );
		PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
	}
	else if( !strcmp(name, "Hamburger", true ) ) {
	
		DajIgracuGlad( playerid, 5 );
		Dimi_SetPlayerHealth( playerid, 35 );
		
		if( !IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) {
			SetPlayerAttachedObject(playerid, OBJECT_SLOT_RHAND, 2703, 6, 0.078287, 0.019677, -0.001004, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			SetTimerEx("RemoveAttachedObject", 3000, false, "dd", playerid, OBJECT_SLOT_RHAND );
		}

		Inventory_Remove(playerid, "Hamburger");

		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		format( globalstring, sizeof( globalstring ), "%s jede hamburger.", ImeIgraca( playerid ) );
		PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
	}
	else if( !strcmp( name, "Piletina", true ) ) {
	
		DajIgracuGlad( playerid, 20 );
		Dimi_SetPlayerHealth( playerid, 100 );

		Inventory_Remove(playerid, "Piletina");

		ApplyAnimation(playerid, "VENDING", "VEND_Eat_P", 4.1, 0, 0, 0, 0, 0, 1);
		format( globalstring, sizeof( globalstring ), "%s jede piletinu.", ImeIgraca( playerid ) );
		PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
	}
	else if( !strcmp( name, "Sok", true ) ) {
		DajIgracuGlad( playerid, 1 );
		
		format( globalstring, sizeof( globalstring ), "* %s pije sok.", ImeIgraca( playerid ) );
		PorukaRadius(15.0, playerid, globalstring, LJUBICASTA );

		Inventory_Remove(playerid, "Sok");

		SetPlayerSpecialAction( playerid, SPECIAL_ACTION_DRINK_SPRUNK );
	}
	else if( !strcmp( name, "Pivo", true ) ) {
		DajIgracuGlad( playerid, 8 );
		
		new drunklevel = GetPlayerDrunkLevel( playerid );
		
		SetPlayerDrunkLevel( playerid, drunklevel + 200);
		
		if( drunklevel > 2000 ) {
			announcement( playerid, "~p~Pijani ste", 3500, 1);
		}
		format( globalstring, sizeof( globalstring ), "* %s pije pivo.", ImeIgraca( playerid ) );
		PorukaRadius(15.0, playerid, globalstring, LJUBICASTA );
		
		Inventory_Remove(playerid, "Pivo");
		
		SetPlayerSpecialAction( playerid, SPECIAL_ACTION_DRINK_WINE );
	}
	else if( !strcmp( name, "Kantica", true ) ) {
		if( ImaKanticu[ playerid ] == true ) return GRESKA( playerid, "Vec imas kanticu u ruci." );
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) return GRESKA( playerid, "Vec imate jedan objekt u desnoj ruci.");

		ImaKanticu[ playerid ] = true;
		SendJobMessage( playerid, "Uzeli ste kanticu sa gorivom iz inventorija. " );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 1650, 6, 0.145482, 0.035119, 0.040793, 8.881844, 276.183959, 329.795593, 1.561557, 1.177534, 1.265636 );

		Inventory_Remove( playerid, "Kantica" );
	}
	else if( !strcmp( name, "Maska", true ) ) {
		SendInfoMessage( playerid, "Koristi /maskon i /maskoff." );
	}
	else if( !strcmp( name, "Srafciger", true ) ) {

		if( NosiObjekt[ playerid ][ 0 ] == true ) return GRESKA( playerid, "Vec imas srafciger u rukama." );
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_LHAND ) ) return GRESKA( playerid, "Vec imas neki objekt u lijevoj ruci!");

		SetPlayerAttachedObject( playerid, OBJECT_SLOT_LHAND, 18644, 5, 0.082183, 0.021501, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
		NosiObjekt[ playerid ][ 0 ] = true;
		SendClientMessagee( playerid, ZUTA, "Uzeo si srafciger." );
		
		Inventory_Remove( playerid, "Srafciger" );
	}
	else if( !strcmp( name, "Pajser", true ) ) {
	
		if( NosiObjekt[ playerid ][ 1 ] == true ) return GRESKA( playerid, "Vec imas pajser u rukama." );
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_LHAND ) ) return GRESKA( playerid, "Vec imas neki objekt u lijevoj ruci!");

		SetPlayerAttachedObject( playerid, OBJECT_SLOT_LHAND, 18634, 5, 0.083787, 0.042288, 0.124473, 359.138671, 273.522338, 93.422569, 1.000000, 1.000000, 1.000000 );
		NosiObjekt[ playerid ][ 1 ] = true;
		SendClientMessagee( playerid, ZUTA, "Uzeo si pajser." );
		
		Inventory_Remove( playerid, "Pajser" );
	}
	else if( !strcmp( name, "Cekic", true ) ) {

		if( NosiObjekt[ playerid ][ 2 ] == true ) return GRESKA( playerid, "Vec imas cekic u rukama." );
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_LHAND ) ) return GRESKA( playerid, "Vec imas neki objekt u lijevoj ruci!");

		SetPlayerAttachedObject( playerid, OBJECT_SLOT_LHAND, 18635, 5, 0.006891, 0.061260, 0.000000, 171.156280, 0.000000, 350.823333, 1.000000, 1.000000, 1.000000 );
		NosiObjekt[ playerid ][ 2 ] = true;
		SendClientMessagee( playerid, ZUTA, "Uzeo si cekic." );

		Inventory_Remove( playerid, "Cekic" );
	}
	else if( !strcmp( name, "Dinamit", true ) ) { 
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) return GRESKA( playerid, "Vec imate objekt u desnoj ruci.");
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 1654, 6, 0.09, 0.02, -0.00, 0.0, 0.0, 0.0, 1.00, 1.00, 1.00 );
		Dinamit[ playerid ] = true;
		SendClientMessagee( playerid, ZUTA, "Izvadio si dinamit iz inventorija." );
		
		Inventory_Remove( playerid, "Dinamit" );
	}
	else if( !strcmp( name, "Laptop", true ) ) {
		if( IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_RHAND ) ) return GRESKA( playerid, "Vec imate objekt u desnoj ruci.");
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19893, 6, 0.04, -0.00, -0.13, -109.0, -2.0, -94.0, 1.00, 1.00, 1.00 );
		LaptopRuke[ playerid ] = true;
		ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
		SendClientMessagee( playerid, ZUTA, "Izvadio si laptop iz inventorija." );

		Inventory_Remove( playerid, "Laptop" );
	}
	// edit ovo dodano = else if( !strcmp( name, "Jabuke", true ) ) {
	else
	{
		new gunid = -1;
		for( new i = 0; i < 47; i++ )
		{
			if( !strcmp( name, WeaponInfos[ i ][ wName ], true ) )
			{
				gunid = i;
				break;
			}
		}
		if( gunid != -1 )
		{
			new slot = WeaponInfos[ gunid ][ wSlot ];
			new weapon, bullet;
			GetPlayerWeaponData( playerid, slot, weapon, bullet );
			if( bullet != 0 ) return GRESKA( playerid, "Vec imas oruzje u tom slotu." );
			GiveWeaponToPlayer( playerid, WeaponInfos[ gunid ][ wID ], inventoryInfo[ playerid ][ itemid ][ invQuantity ] );
			//Inventory_Remove( playerid, WeaponInfos[ gunid ][ wName ], inventoryInfo[ playerid ][ itemid ][ invQuantity ] );
			Inventory_Remove_2( playerid, itemid, inventoryInfo[ playerid ][ itemid ][ invQuantity ] );
			OruzjeUInventoriju[ playerid ]--;
			format( globalstring, sizeof( globalstring ), "* %s vadi %s iz inventorija.", ImeIgraca( playerid ), WeaponInfos[ gunid ][ wName ] );
			PorukaRadius(20.0 , playerid, globalstring, LJUBICASTA );
			SendInfoMessage( playerid, "Uspjesno ste izvadili iz inventorija %s.", WeaponInfos[ gunid ][ wName ] );
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
forward OpenInventory(playerid);
public OpenInventory(playerid)
{
	if( !IsPlayerConnected( playerid ) )
		return false;

	static
		items[ MAX_INVENTORY ],
		amounts[ MAX_INVENTORY ];

	for( new i = 0; i < 20; i++ )
	{
		if( inventoryInfo[ playerid ][ i ][ invExists ] )
		 {
			items[ i ] = inventoryInfo[ playerid ][ i ][ invModel ];
			amounts[ i ] = inventoryInfo[ playerid ][ i ][ invQuantity ];
		}
		else
		{
			items[ i ] = -1;
			amounts[ i ] = -1;
		}
	}
	
	return ShowModelESelectionMenu(playerid, "Vas inventar:", 1, items, sizeof(items), 0.0, 0.0, 0.0, 1.0, -1, true, amounts);
}
//------------------------------------------------------------------------------
stock Inventory_Add( playerid, item[], model, quantity = 1 ) {
	new
		itemid = Inventory_GetItemID( playerid, item );

	if( itemid == -1 || ( model >= 321 && model <= 372 ) ) {
		itemid = Inventory_GetFreeID( playerid );

		if( itemid != -1 ) {
			inventoryInfo[ playerid ][ itemid ][ invExists ] = true;
			inventoryInfo[ playerid ][ itemid ][ invModel ] = model;
			inventoryInfo[ playerid ][ itemid ][ invQuantity ] = quantity;

			strmid( inventoryInfo[ playerid ][ itemid ][ invItem ], item, 0, strlen( item ), 32 );

			SaveInventory( playerid );
			return itemid;
		}
		return -1;
	}
	else { 
		inventoryInfo[ playerid ][ itemid ][ invQuantity ] += quantity;
		
		SaveInventory( playerid );
	}
	return itemid;
}
stock Inventory_GetItemID( playerid, item[] )
{
	for( new i = 0; i < MAX_INVENTORY; i++ ) {
		if( !inventoryInfo[ playerid ][ i ][ invExists ] )
			continue;

		if( !strcmp( inventoryInfo[ playerid ][ i ][ invItem ], item ) ) return i;
	}
	return -1;
}

stock Inventory_GetFreeID( playerid ) {
	if( Inventory_Items( playerid ) >= 20 )
		return -1;

	for( new i = 0; i < MAX_INVENTORY; i++ ) {
		if( !inventoryInfo[ playerid ][ i ][ invExists ] )
			return i;
	}
	return -1;
}

stock Inventory_Items( playerid ) {
	new count;

	for( new i = 0; i != MAX_INVENTORY; i++ ) if( inventoryInfo[ playerid ][ i ][ invExists ] ) {
		count++;
	}
	return count;
}

stock Inventory_Count( playerid, item[] ) {
	new itemid = Inventory_GetItemID( playerid, item );

	if( itemid != -1 )
		return inventoryInfo[ playerid ][ itemid ][ invQuantity ];

	return false;
}

stock Inventory_HasItem( playerid, item[] ) {
	return ( Inventory_GetItemID( playerid, item ) != -1 );
}

stock Inventory_SetQuantity( playerid, item[], quantity ) {
	new
		itemid = Inventory_GetItemID( playerid, item ),
		string[ 128 ];

	if( itemid != -1 ) {
		inventoryInfo[ playerid ][ itemid ][ invQuantity ] = quantity;
		
		SaveInventory( playerid );
	}
	return true;
}

stock Inventory_Remove( playerid, item[], quantity = 1 ) {
	new
		itemid = Inventory_GetItemID( playerid, item );

	if( itemid != -1 ) {
		if( inventoryInfo[ playerid ][ itemid ][ invQuantity ] > 0 ) {
			inventoryInfo[ playerid ][ itemid ][ invQuantity ] -= quantity;
		}
		if( quantity == -1 || inventoryInfo[ playerid ][ itemid ][ invQuantity ] < 1 ) {
			inventoryInfo[ playerid ][ itemid ][ invExists ] = false;
			inventoryInfo[ playerid ][ itemid ][ invModel ] = 0;
			inventoryInfo[ playerid ][ itemid ][ invQuantity ] = 0;
			strmid( inventoryInfo[ playerid ][ itemid ][ invItem ], "None", 0, strlen( "None" ), 32 );

			SaveInventory( playerid );
		}
		else if( quantity != -1 && inventoryInfo[ playerid ][ itemid ][ invQuantity ] > 0 ) { 
			
			SaveInventory( playerid );
		}
		return true;
	}
	return false;
}

stock Inventory_Remove_2( playerid, itemid, quantity = 1 ) {

	if( itemid != -1 ) {
		if( inventoryInfo[ playerid ][ itemid ][ invQuantity ] > 0 ) {
			inventoryInfo[ playerid ][ itemid ][ invQuantity ] -= quantity;
		}
		if( quantity == -1 || inventoryInfo[ playerid ][ itemid ][ invQuantity ] < 1 ) {
			inventoryInfo[ playerid ][ itemid ][ invExists ] = false;
			inventoryInfo[ playerid ][ itemid ][ invModel ] = 0;
			inventoryInfo[ playerid ][ itemid ][ invQuantity ] = 0;
			strmid( inventoryInfo[ playerid ][ itemid ][ invItem ], "None", 0, strlen( "None" ), 32 );

			SaveInventory( playerid );
		}
		else if( quantity != -1 && inventoryInfo[ playerid ][ itemid ][ invQuantity ] > 0 ) {

			SaveInventory( playerid );
		}
		return true;
	}
	return false;
}

stock Inventory_Clear( playerid ) {

	for( new i = 0; i < MAX_INVENTORY; i ++) {
		if( inventoryInfo[ playerid ][ i ][ invExists ] ) {
			inventoryInfo[ playerid ][ i ][ invExists ] = false;
			inventoryInfo[ playerid ][ i ][ invModel ] = 0;
			inventoryInfo[ playerid ][ i ][ invQuantity ] = 0;
		}
	}
	
	SaveInventory( playerid );
	
}

stock Inventory_Set( playerid, item[], model, amount ) {
	new itemid = Inventory_GetItemID( playerid, item );

	if( itemid == -1 && amount > 0 )
		Inventory_Add( playerid, item, model, amount );

	else if( amount > 0 && itemid != -1 )
		Inventory_SetQuantity( playerid, item, amount );

	else if( amount < 1 && itemid != -1 )
		Inventory_Remove( playerid, item, -1 );

	return true;
}

//------------------------------------------------------------------------------
ResetujAdmina( playerid ) {
	AI[ playerid ][ aTBan ] = 0;
	AI[ playerid ][ aTWarn ] = 0;
	AI[ playerid ][ aTKick ] = 0;
	AI[ playerid ][ aTCharge ] = 0;
	AI[ playerid ][ aTJail ] = 0;
	AI[ playerid ][ aTUnjail ] = 0;
	AI[ playerid ][ aTUnwarn ] = 0;
	AI[ playerid ][ aTUnban ] = 0;
	AI[ playerid ][ aTPM ] = 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
SavePlayer(playerid); public SavePlayer(playerid) 
{
		new INI:File = INI_Open( Korisnici( playerid ) );
		INI_SetTag( File, "Informacije" );
		INI_WriteString( File, "Lozinka", PlayerInfo[ playerid ][ xLozinka ] );
		INI_WriteInt( File, "Pol", PlayerInfo[ playerid ][ xPol ] );
		INI_WriteInt( File, "Godine", PlayerInfo[ playerid ][ xGodine ] );
		INI_WriteInt( File, "Novac", PlayerInfo[ playerid ][ xNovac ] );
		INI_WriteInt( File, "Level", PlayerInfo[ playerid ][ xLevel ] );
		INI_WriteInt( File, "Respekt", PlayerInfo[ playerid ][ xRespekt ] );
		INI_WriteInt( File, "Poboljsanja", PlayerInfo[ playerid ][ xPoboljsanja ] );
		INI_WriteInt( File, "PayDay", PlayerInfo[ playerid ][ xPayDay ] );
		INI_WriteInt( File, "Admin", PlayerInfo[ playerid ][ xAdmin ] );
		INI_WriteInt( File, "Skin", PlayerInfo[ playerid ][ xSkin ] );
		INI_WriteInt( File, "Spawn", PlayerInfo[ playerid ][ xSpawn ] );
		INI_WriteInt( File, "Lider", PlayerInfo[ playerid ][ xLider ] );
		INI_WriteInt( File, "Clan", PlayerInfo[ playerid ][ xClan ] );
		INI_WriteInt( File, "Rank", PlayerInfo[ playerid ][ xRank ] );
		INI_WriteInt( File, "VoziloID1", PlayerInfo[ playerid ][ xVoziloID ][ 0 ] );
		INI_WriteInt( File, "VoziloID2", PlayerInfo[ playerid ][ xVoziloID ][ 1 ] );
		INI_WriteInt( File, "VoziloID3", PlayerInfo[ playerid ][ xVoziloID ][ 2 ] );
		INI_WriteInt( File, "VoziloID4", PlayerInfo[ playerid ][ xVoziloID ][ 3 ] );
		INI_WriteInt( File, "Materijali", PlayerInfo[ playerid ][ xMaterijali ] );
		INI_WriteInt( File, "FirmaID", PlayerInfo[ playerid ][ xFirmaID ] );
		INI_WriteInt( File, "Posao", PlayerInfo[ playerid ][ xPosao ] );
		INI_WriteInt( File, "Ugovor", PlayerInfo[ playerid ][ xUgovor ] );
		INI_WriteInt( File, "MehSkill", PlayerInfo[ playerid ][ xMehSkill ] );
		INI_WriteInt( File, "MDelovi", PlayerInfo[ playerid ][ xMDelovi ] );
		INI_WriteInt( File, "Head", PlayerInfo[ playerid ][ xHead ] );
		INI_WriteFloat( File, "HeadPos1", PlayerInfo[ playerid ][ xHeadPos ][ 0 ] );
		INI_WriteFloat( File, "HeadPos2", PlayerInfo[ playerid ][ xHeadPos ][ 1 ] );
		INI_WriteFloat( File, "HeadPos3", PlayerInfo[ playerid ][ xHeadPos ][ 2 ] );
		INI_WriteFloat( File, "HeadPos4", PlayerInfo[ playerid ][ xHeadPos ][ 3 ] );
		INI_WriteFloat( File, "HeadPos5", PlayerInfo[ playerid ][ xHeadPos ][ 4 ] );
		INI_WriteFloat( File, "HeadPos6", PlayerInfo[ playerid ][ xHeadPos ][ 5 ] );
		INI_WriteFloat( File, "HeadPos7", PlayerInfo[ playerid ][ xHeadPos ][ 6 ] );
		INI_WriteFloat( File, "HeadPos8", PlayerInfo[ playerid ][ xHeadPos ][ 7 ] );
		INI_WriteFloat( File, "HeadPos9", PlayerInfo[ playerid ][ xHeadPos ][ 8 ] );
		INI_WriteInt( File, "Face", PlayerInfo[ playerid ][ xFace ] );
		INI_WriteFloat( File, "FacePos1", PlayerInfo[ playerid ][ xFacePos ][ 0 ] );
		INI_WriteFloat( File, "FacePos2", PlayerInfo[ playerid ][ xFacePos ][ 1 ] );
		INI_WriteFloat( File, "FacePos3", PlayerInfo[ playerid ][ xFacePos ][ 2 ] );
		INI_WriteFloat( File, "FacePos4", PlayerInfo[ playerid ][ xFacePos ][ 3 ] );
		INI_WriteFloat( File, "FacePos5", PlayerInfo[ playerid ][ xFacePos ][ 4 ] );
		INI_WriteFloat( File, "FacePos6", PlayerInfo[ playerid ][ xFacePos ][ 5 ] );
		INI_WriteFloat( File, "FacePos7", PlayerInfo[ playerid ][ xFacePos ][ 6 ] );
		INI_WriteFloat( File, "FacePos8", PlayerInfo[ playerid ][ xFacePos ][ 7 ] );
		INI_WriteFloat( File, "FacePos9", PlayerInfo[ playerid ][ xFacePos ][ 8 ] );
		INI_WriteInt( File, "SungMask", PlayerInfo[ playerid ][ xSungMask ] );
		INI_WriteFloat( File, "SungMaskPos1", PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ] );
		INI_WriteFloat( File, "SungMaskPos2", PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ] );
		INI_WriteFloat( File, "SungMaskPos3", PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ] );
		INI_WriteFloat( File, "SungMaskPos4", PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ] );
		INI_WriteFloat( File, "SungMaskPos5", PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ] );
		INI_WriteFloat( File, "SungMaskPos6", PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ] );
		INI_WriteFloat( File, "SungMaskPos7", PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] );
		INI_WriteFloat( File, "SungMaskPos8", PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] );
		INI_WriteFloat( File, "SungMaskPos9", PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] );
		INI_WriteInt( File, "Cigare", PlayerInfo[ playerid ][ xCigare ] );
		INI_WriteInt( File, "Upaljac", PlayerInfo[ playerid ][ xUpaljac ] );
		INI_WriteInt( File, "BStil", PlayerInfo[ playerid ][ xBStil ] );
		INI_WriteInt( File, "Registrovan", PlayerInfo[ playerid ][ xRegistrovan ] );
		INI_WriteFloat( File, "SHealth", PlayerInfo[ playerid ][ xSHealth ] );
		INI_WriteInt( File, "BrojTelefona", PlayerInfo[ playerid ][ xBrojTelefona ] );
		INI_WriteInt( File, "Vozacka", PlayerInfo[ playerid ][ xVozacka ] );
		INI_WriteInt( File, "Licna", PlayerInfo[ playerid ][ xLicna ] );
		INI_WriteInt( File, "TaxiLicenca", PlayerInfo[ playerid ][ xTaxLic ] );
		INI_WriteInt( File, "Pasos", PlayerInfo[ playerid ][ xPasos ] );
		INI_WriteInt( File, "JMBG", PlayerInfo[ playerid ][ xJMBG ] );
		INI_WriteInt( File, "BrojLicne", PlayerInfo[ playerid ][ xBrojLk ] );
		INI_WriteInt( File, "BrojPasosa", PlayerInfo[ playerid ][ xBrojPasosa ] );
		INI_WriteInt( File, "Motorska", PlayerInfo[ playerid ][ xMotorska ] );
		INI_WriteInt( File, "KamionskaC1", PlayerInfo[ playerid ][ xKamionskaC1 ] );
		INI_WriteInt( File, "KamionskaC2", PlayerInfo[ playerid ][ xKamionskaC2 ] );
		INI_WriteInt( File, "KamionskaC3", PlayerInfo[ playerid ][ xKamionskaC3 ] );
		INI_WriteInt( File, "Brodska", PlayerInfo[ playerid ][ xBrodska ] );
		INI_WriteInt( File, "Letelica", PlayerInfo[ playerid ][ xLetelica ] );
		INI_WriteInt( File, "Osnovna", PlayerInfo[ playerid ][ xOsnovna ] );
		INI_WriteInt( File, "Srednja", PlayerInfo[ playerid ][ xSrednja ] );
		INI_WriteInt( File, "Fakultet", PlayerInfo[ playerid ][ xFakultet ] );
		INI_WriteInt( File, "SkolaLimit", PlayerInfo[ playerid ][ xSkolaLimit ] );
		INI_WriteInt( File, "Ubijen", PlayerInfo[ playerid ][ xUbijen ] );
		#if nerp_droga == 1
		INI_WriteInt( File, "Drug1", PlayerInfo[ playerid ][ xDrug ][ 0 ] );
		INI_WriteInt( File, "Drug2", PlayerInfo[ playerid ][ xDrug ][ 1 ] );
		INI_WriteInt( File, "Drug3", PlayerInfo[ playerid ][ xDrug ][ 2 ] );
		INI_WriteInt( File, "Drug4", PlayerInfo[ playerid ][ xDrug ][ 3 ] );
		INI_WriteInt( File, "Drug5", PlayerInfo[ playerid ][ xDrug ][ 4 ] );
		INI_WriteInt( File, "DrugCode1", PlayerInfo[ playerid ][ xDrugCode ][ 0 ] );
		INI_WriteInt( File, "DrugCode2", PlayerInfo[ playerid ][ xDrugCode ][ 1 ] );
		INI_WriteInt( File, "DrugCode3", PlayerInfo[ playerid ][ xDrugCode ][ 2 ] );
		INI_WriteInt( File, "DrugCode4", PlayerInfo[ playerid ][ xDrugCode ][ 3 ] );
		INI_WriteInt( File, "DrugCode5", PlayerInfo[ playerid ][ xDrugCode ][ 4 ] );
		#endif
		INI_WriteInt( File, "Solna", PlayerInfo[ playerid ][ xSolna ] );
		INI_WriteInt( File, "Pseudo", PlayerInfo[ playerid ][ xPseudo ] );
		INI_WriteInt( File, "SodaB", PlayerInfo[ playerid ][ xSodaB ] );
		INI_WriteInt( File, "CrveniF", PlayerInfo[ playerid ][ xCrveniF ] );
		INI_WriteInt( File, "LysAcid", PlayerInfo[ playerid ][ xLysAcid ] );
		INI_WriteInt( File, "DesVoda", PlayerInfo[ playerid ][ xDesVoda ] );
		INI_WriteInt( File, "Marihuana", PlayerInfo[ playerid ][ xMarihuana ] );
		INI_WriteInt( File, "Opium", PlayerInfo[ playerid ][ xOpium ] );
		INI_WriteInt( File, "Kalcijum", PlayerInfo[ playerid ][ xKalcij ] );
		INI_WriteInt( File, "AmonijumHlorid", PlayerInfo[ playerid ][ xAmonijH ] );
		INI_WriteInt( File, "Kokain", PlayerInfo[ playerid ][ xKokain ] );
		INI_WriteInt( File, "Kokain2", PlayerInfo[ playerid ][ xKokain2 ] );
		INI_WriteInt( File, "MetilAmin", PlayerInfo[ playerid ][ xMetilAmin ] );
		INI_WriteInt( File, "Hunger", PlayerInfo[ playerid ][ xHunger ] );
		INI_WriteInt( File, "Toilet", PlayerInfo[ playerid ][ xToilet ] );
		INI_WriteBool( File, "HeroinAddict", PlayerInfo[ playerid ][ xHeroinAddict ] );
		INI_WriteInt( File, "HeroinUsed", PlayerInfo[ playerid ][ xHeroinUsed ] );
		INI_WriteInt( File, "HeroinIndicator", PlayerInfo[ playerid ][ xHeroinIndicator ] );
		INI_WriteBool( File, "CokeCrackAddict", PlayerInfo[ playerid ][ xCokeCrackAddict ] );
		INI_WriteInt( File, "CokeCrackUsed", PlayerInfo[ playerid ][ xCokeCrackUsed ] );
		INI_WriteInt( File, "CokeCrackIndicator", PlayerInfo[ playerid ][ xCokeCrackIndicator ] );
		INI_WriteBool( File, "MethAddict", PlayerInfo[ playerid ][ xMethAddict ] );
		INI_WriteInt( File, "MethIndicator", PlayerInfo[ playerid ][ xMethIndicator ] );
		INI_WriteInt( File, "MethUsed", PlayerInfo[ playerid ][ xMethUsed ] );
		INI_WriteBool( File, "Inekcija", PlayerInfo[ playerid ][ xInekcija ] );
		INI_WriteBool( File, "Toolkit", PlayerInfo[ playerid ][ xToolkit ] );
		INI_WriteInt( File, "Property1", PlayerInfo[ playerid ][ xProperty ][ 0 ] );
		INI_WriteInt( File, "Property2", PlayerInfo[ playerid ][ xProperty ][ 1 ] );
		INI_WriteInt( File, "Property3", PlayerInfo[ playerid ][ xProperty ][ 2 ] );
		INI_WriteBool( File, "GunLicense", PlayerInfo[ playerid ][ xGunLicense ] );
		INI_WriteInt( File, "TelefonBon", PlayerInfo[ playerid ][ xTelefonBon ] );
		INI_WriteInt( File, "ModelTelefona", PlayerInfo[ playerid ][ xModelTelefona ] );
		INI_WriteInt( File, "Snaga", PlayerInfo[ playerid ][ xSnaga ] );
		INI_WriteInt( File, "Zatvor", PlayerInfo[ playerid ][ xZatvor ] );
		INI_WriteInt( File, "ZatvorVreme", PlayerInfo[ playerid ][ xZatvorVreme ] );
		INI_WriteInt( File, "Wanted", PlayerInfo[ playerid ][ xWanted ] );
		INI_WriteInt( File, "Uhapsen", PlayerInfo[ playerid ][ xUhapsen ] );
		INI_WriteInt( File, "PDUhapsio", PlayerInfo[ playerid ][ xPDUhapsio ] );
		INI_WriteInt( File, "PDStatsTicket", PlayerInfo[ playerid ][ xPDStatsTicket ] );
		INI_WriteInt( File, "PDStatsTicketMoney", PlayerInfo[ playerid ][ xPDStatsTicketMoney ] );
		INI_WriteInt( File, "TakenWeps", PlayerInfo[ playerid ][ xTakenWeps ] );
		#if nerp_droga == 1 
		INI_WriteInt( File, "TakenDrugs", PlayerInfo[ playerid ][ xTakenDrugs ] );
		#endif
		INI_WriteInt( File, "PocetniTut", PlayerInfo[ playerid ][ xPocetniTut ] );
		INI_WriteInt( File, "AKod", PlayerInfo[ playerid ][ xAKod ] );
		INI_WriteInt( File, "Sat", PlayerInfo[ playerid ][ xSat ] );
		INI_WriteInt( File, "MaskID", PlayerInfo[ playerid ][ xMaskID ] );
		INI_WriteInt( File, "BRacun", PlayerInfo[ playerid ][ xBRacun ] );
		INI_WriteInt( File, "PreostaloZaOtplatu", PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] );
		INI_WriteInt( File, "IznosRate", PlayerInfo[ playerid ][ xIznosRate ] );
		INI_WriteInt( File, "IznosKredita", PlayerInfo[ playerid ][ xIznosKredita ] );
		INI_WriteInt( File, "OnlineSati", PlayerInfo[ playerid ][ xOnlineSati ] );
		INI_WriteInt( File, "Helper", PlayerInfo[ playerid ][ xHelper ] );
		INI_WriteInt( File, "RPLearn", PlayerInfo[ playerid ][ xRPLearn ] );
		INI_WriteInt( File, "Warn", PlayerInfo[ playerid ][ xWarn ] );
		INI_WriteInt( File, "Mute", PlayerInfo[ playerid ][ xMute ] );
		INI_WriteFloat( File, "Marker1", PlayerInfo[ playerid ][ xMarker ][ 0 ] );
		INI_WriteFloat( File, "Marker2", PlayerInfo[ playerid ][ xMarker ][ 1 ] );
		INI_WriteFloat( File, "Marker3", PlayerInfo[ playerid ][ xMarker ][ 2 ] );
		INI_WriteInt( File, "BrojNews", PlayerInfo[ playerid ][ xBrojNews ] );
		INI_WriteInt( File, "OrgUgovor", PlayerInfo[ playerid ][ xOrgUgovor ] );
		INI_WriteInt( File, "GpsLevel", PlayerInfo[ playerid ][ xGpsLevel ] );
		INI_WriteInt( File, "Helmet", PlayerInfo[ playerid ][ xHelmet ] );
		INI_WriteInt( File, "BanDays", PlayerInfo[ playerid ][ xBDays ] );
		INI_WriteInt( File, "BanMonths", PlayerInfo[ playerid ][ xBMonths ] );
		INI_WriteInt( File, "BanYear", PlayerInfo[ playerid ][ xBYears ] );
		INI_WriteInt( File, "GradRank", PlayerInfo[ playerid ][ xGradRank ] );
		INI_WriteInt( File, "SkriptaRank", PlayerInfo[ playerid ][ xSkriptaRank ] );
		INI_WriteInt( File, "UlazBL", PlayerInfo[ playerid ][ xUlazBL ] );
		INI_WriteBool( File, "Boombox", PlayerInfo[ playerid ][ xBoombox ] );
		INI_WriteFloat( File, "HelmetPos1", PlayerInfo[ playerid ][ xHelmetPos ][ 0 ] );
		INI_WriteFloat( File, "HelmetPos2", PlayerInfo[ playerid ][ xHelmetPos ][ 1 ] );
		INI_WriteFloat( File, "HelmetPos3", PlayerInfo[ playerid ][ xHelmetPos ][ 2 ] );
		INI_WriteFloat( File, "HelmetPos4", PlayerInfo[ playerid ][ xHelmetPos ][ 3 ] );
		INI_WriteFloat( File, "HelmetPos5", PlayerInfo[ playerid ][ xHelmetPos ][ 4 ] );
		INI_WriteFloat( File, "HelmetPos6", PlayerInfo[ playerid ][ xHelmetPos ][ 5 ] );
		INI_WriteFloat( File, "HelmetPos7", PlayerInfo[ playerid ][ xHelmetPos ][ 6 ] );
		INI_WriteFloat( File, "HelmetPos8", PlayerInfo[ playerid ][ xHelmetPos ][ 7 ] );
		INI_WriteFloat( File, "HelmetPos9", PlayerInfo[ playerid ][ xHelmetPos ][ 8 ] );
		INI_WriteInt( File, "Drzava", PlayerInfo[ playerid ][ xDrzava ] );
		INI_WriteString( File, "Email", PlayerInfo[ playerid ][ xEmail ] );
		INI_WriteInt( File, "VIPLevel", PlayerInfo[ playerid ][ xVIPLevel ] );
		INI_WriteInt( File, "HitmenCena", PlayerInfo[ playerid ][ xHitmenCena ] );
		INI_WriteInt( File, "Objekt1", PlayerInfo[ playerid ][ xObject ][ 0 ] );
		INI_WriteInt( File, "Objekt2", PlayerInfo[ playerid ][ xObject ][ 1 ] );
		INI_WriteInt( File, "Objekt3", PlayerInfo[ playerid ][ xObject ][ 2 ] );
		INI_WriteInt( File, "Objekt4", PlayerInfo[ playerid ][ xObject ][ 3 ] );
		INI_WriteInt( File, "Objekt5", PlayerInfo[ playerid ][ xObject ][ 4 ] );
		INI_WriteInt( File, "Objekt6", PlayerInfo[ playerid ][ xObject ][ 5 ] );
		INI_WriteInt( File, "Objekt7", PlayerInfo[ playerid ][ xObject ][ 6 ] );
		INI_WriteInt( File, "Objekt8", PlayerInfo[ playerid ][ xObject ][ 7 ] );
		INI_WriteInt( File, "Objekt9", PlayerInfo[ playerid ][ xObject ][ 8 ] );
		INI_WriteInt( File, "Objekt10", PlayerInfo[ playerid ][ xObject ][ 9 ] );
		INI_WriteInt( File, "LesLimit", PlayerInfo[ playerid ][ xLesLimit ] );
		INI_WriteInt( File, "KazneniUgovor", PlayerInfo[ playerid ][ xKazneniUgovor ] );
		INI_WriteString( File, "OffPJail", PlayerInfo[ playerid ][ xOffPJail ] );
		INI_WriteString( File, "OffPPrison", PlayerInfo[ playerid ][ xOffPPrison ] );
		INI_WriteString( File, "OffPMute", PlayerInfo[ playerid ][ xOffPMute ] );
		INI_WriteInt( File, "StaffMin", PlayerInfo[ playerid ][ xStaffMin ] );
		INI_WriteString( File, "LastLogin", PlayerInfo[ playerid ][ xLastLogin ] );
		INI_WriteBool( File, "Married", PlayerInfo[ playerid ][ xMarried ] );
		INI_WriteString( File, "MarriedTo", PlayerInfo[ playerid ][ xMarriedTo ] );
		INI_WriteBool( File, "TogMob", PlayerInfo[ playerid ][ xTogMob ] );
		INI_WriteInt( File, "HotelID", PlayerInfo[ playerid ][ xHotelID ] );
		INI_WriteInt( File, "HotelRoom", PlayerInfo[ playerid ][ xHotelRoom ] );
		INI_WriteInt( File, "Promoter", PlayerInfo[ playerid ][ xPromoter ] );
		INI_WriteInt( File, "FieldID", PlayerInfo[ playerid ][ xFieldID ] );
		INI_WriteInt( File, "Sljive", PlayerInfo[ playerid ][ xSljive ] );
		INI_WriteInt( File, "Kruske", PlayerInfo[ playerid ][ xKruske ] );
		INI_WriteInt( File, "Jabuke", PlayerInfo[ playerid ][ xJabuke ] );
		INI_WriteInt( File, "Kupus", PlayerInfo[ playerid ][ xKupus ] );
		INI_WriteInt( File, "Ruze", PlayerInfo[ playerid ][ xRuze ] );
		INI_WriteInt( File, "SemeSljive", PlayerInfo[ playerid ][ xSemeSljive ] );
		INI_WriteInt( File, "SemeKruske", PlayerInfo[ playerid ][ xSemeKruske ] );
		INI_WriteInt( File, "SemeJabuke", PlayerInfo[ playerid ][ xSemeJabuke ] );
		INI_WriteInt( File, "SemeKupusa", PlayerInfo[ playerid ][ xSemeKupusa ] );
		INI_WriteInt( File, "SemeRuze", PlayerInfo[ playerid ][ xSemeRuze ] );
		INI_WriteInt( File, "LottoNumber", PlayerInfo[ playerid ][ xLottoNumber ] );
		INI_WriteInt( File, "LottoMoney", PlayerInfo[ playerid ][ xLottoMoney ] );
		INI_WriteInt( File, "GarageID", PlayerInfo[ playerid ][ xGarageID ] );
		INI_WriteBool( File, "ImaBRacun", PlayerInfo[ playerid ][ xImaBRacun ] );
		INI_WriteInt( File, "PlatniRacun", PlayerInfo[ playerid ][ xPlatniRacun ] );
		INI_WriteBool( File, "DonatorSlot", PlayerInfo[ playerid ][ xDonatorSlot ] );
		INI_WriteInt( File, "PljackaVreme", PlayerInfo[ playerid ][ xPljackaVreme ] );
		INI_WriteBool( File, "LeaveJail", PlayerInfo[ playerid ][ xLeaveJail ] );
		INI_WriteInt( File, "BailPrice", PlayerInfo[ playerid ][ xBailPrice ] );
		INI_WriteInt( File, "HangarTime", PlayerInfo[ playerid ][ xHangarTime ] );
		INI_WriteInt( File, "Event1Mesto", PlayerInfo[ playerid ][ xEvent1Mesto ] );
		INI_WriteInt( File, "Event2Mesto", PlayerInfo[ playerid ][ xEvent2Mesto ] );
		INI_WriteInt( File, "Event3Mesto", PlayerInfo[ playerid ][ xEvent3Mesto ] );
		INI_WriteInt( File, "DMEventUbistva", PlayerInfo[ playerid ][ xDMEventUbistva ] );
		INI_WriteInt( File, "RentID", PlayerInfo[ playerid ][ xRentID ] );
		INI_WriteInt( File, "Zlato", PlayerInfo[ playerid ][ xZlato ] );
		INI_WriteInt( File, "RezervniKljucevi", PlayerInfo[ playerid ][ xRezervniKljucevi ] );
		INI_WriteInt( File, "RadarBodovi", PlayerInfo[ playerid ][ xRadarBodovi ] );
		INI_WriteBool( File, "DBO", PlayerInfo[ playerid ][ xDBO ] );
		INI_WriteInt( File, "DBoja", PlayerInfo[ playerid ][ xDBoja ] );
		INI_WriteInt( File, "RPPoen", PlayerInfo[ playerid ][ xRPPoen ] );
		INI_WriteInt( File, "PodApoeni", PlayerInfo[ playerid ][ xPodApoeni ] );
		INI_WriteInt( File, "Apoeni", PlayerInfo[ playerid ][ xApoeni ] );
		INI_WriteFloat( File, "VipTime", PlayerInfo[ playerid ][ xVipTime ] );
		INI_WriteInt( File, "ZauzimanjeVreme", PlayerInfo[ playerid ][ xZauzimanjeVreme ] );
		INI_WriteInt( File, "Poklon", PlayerInfo[ playerid ][ xPoklon ] );
		INI_WriteBool( File, "Paketic", PlayerInfo[ playerid ][ xPaketic ] );
		INI_WriteString( File, "KljucKapije", PlayerInfo[ playerid ][ xKljucKapije ] );
		INI_WriteInt( File, "Svercer", PlayerInfo[ playerid ][ xSvercer ] );
		INI_WriteInt(File, "BHD", PlayerInfo[playerid][xBHD]);
		INI_WriteInt(File, "RCON", PlayerInfo[playerid][xRCON]);
		INI_WriteInt(File, "Togn", PlayerInfo[playerid][xTogn]);
		INI_WriteInt(File, "Ranac", PlayerInfo[playerid][xRanac]);

		INI_WriteInt(File, "ZM", PlayerInfo[playerid][xZMaska]);
		INI_WriteInt(File, "Knjizica", PlayerInfo[playerid][xKnjizica]);
		INI_WriteInt(File, "Vakcina", PlayerInfo[playerid][xVakcina]);
		INI_WriteInt(File, "Uputnica", PlayerInfo[playerid][xUputnica]);

		INI_WriteInt(File, "Pin", PlayerInfo[playerid][xPin]);
		INI_WriteInt(File, "DutyTime", PlayerInfo[playerid][xDutyTime]);
		INI_WriteInt(File, "DJ", PlayerInfo[playerid][xDJ]);
		INI_WriteInt(File, "OTD", PlayerInfo[playerid][xOTD]);
		INI_WriteInt(File, "Tdstil", PlayerInfo[playerid][xTdstil]);
		INI_WriteInt(File, "VokiToki", PlayerInfo[playerid][xVokiToki]);
		INI_WriteInt(File, "Papagaj", PlayerInfo[playerid][xPapagaj]);
		INI_WriteInt(File, "Banovan", PlayerInfo[playerid][xBanovan]);
		INI_WriteInt(File, "BD0", PlayerInfo[playerid][xBDatum][0]);
		INI_WriteInt(File, "BD1", PlayerInfo[playerid][xBDatum][1]);
		INI_WriteInt(File, "BD2", PlayerInfo[playerid][xBDatum][2]);
		INI_WriteString( File, "BReason", PlayerInfo[ playerid ][ xBReason ] );
		INI_WriteInt(File, "SniperHeadshots", PlayerInfo[ playerid ][xSniperHeadshots]);
		INI_WriteInt(File, "PUBGKills", PlayerInfo[playerid][xPUBGKillsTotal]);
		INI_WriteInt( File, "ZombieKills", PlayerInfo[ playerid ][ xZombieEventKills ] );
		INI_Close( File );
		return true;
}

//------------------------------------------------------------------------------
#if kladionica == 1
forward LoadStareParove( name[ ], value[ ] );
public LoadStareParove( name[ ], value[ ] ) {

	new string[ 30 ];

	for( new i = 0; i < 10; i++) {

		format( string, sizeof( string ), "par1ID%d", i );
		INI_Int( string, StariParovi[ i ][ parID ][ 0 ] );
		
		format( string, sizeof( string ), "par2ID%d", i );
		INI_Int( string, StariParovi[ i ][ parID ][ 1 ] );

		format( string, sizeof( string ), "Rezultat1%d", i );
		INI_Int( string, StariParovi[ i ][ Rezultat ][ 0 ] );
		
		format( string, sizeof( string ), "Rezultat2%d", i );
		INI_Int( string, StariParovi[ i ][ Rezultat ][ 1 ] );

		format( string, sizeof( string ), "Kvota%d", i );
		INI_Float( string, StariParovi[ i ][ Kvota ] );
		
		format( string, sizeof( string ), "HourPobeda%d", i );
		INI_String( string, StariParovi[ i ][ HourPobeda ], 24 );

	}

	return 1;
}

forward SaveStareParove( );
public SaveStareParove( ) {

	new string[ 30 ];

	new INI:File = INI_Open( "Ostalo/StariParovi.ini" );
	
	INI_SetTag( File, "Informacije" );
	
	for( new i = 0; i < 10; i++) {

		format( string, sizeof( string ), "par1ID%d", i );
		INI_WriteInt( File, string, StariParovi[ i ][ parID ][ 0 ] );

		format( string, sizeof( string ), "par2ID%d", i );
		INI_WriteInt( File, string, StariParovi[ i ][ parID ][ 1 ] );

		format( string, sizeof( string ), "Rezultat1%d", i );
		INI_WriteInt( File, string, StariParovi[ i ][ Rezultat ][ 0 ] );

		format( string, sizeof( string ), "Rezultat2%d", i );
		INI_WriteInt( File, string, StariParovi[ i ][ Rezultat ][ 1 ] );

		format( string, sizeof( string ), "Kvota%d", i );
		INI_WriteFloat( File, string, StariParovi[ i ][ Kvota ] );

		format( string, sizeof( string ), "HourPobeda%d", i );
		INI_WriteString( File, string, StariParovi[ i ][ HourPobeda ] );

	}
	
	INI_Close( File );
	return true;
}
#endif
//-----------------------------------------------------------------------------

//------------------------------------------------------------------------------


/////////////////



//------------------------------------------------------------------------------
DefineGatesAndDoors( ); public DefineGatesAndDoors( )
{
	printf("[NE:RP] - Nova Era | Ucitavanje sistema za ulaze i izlaze!");
	glavniobjekt = CreateObject( OBPR[ 0 ][ 0 ], OBPR1[ 0 ][ 0 ], OBPR1[ 0 ][ 1 ], OBPR1[ 0 ][ 2 ],  OBPR1[ 0 ][ 3 ], OBPR1[ 0 ][4], OBPR1[ 0 ][5] );

	gradjkapija = CreateDynamicObject(976,1861.8921, -1384.9541, 12.5581,0.0000, 0.0000, 90.0000);//Uradjeno


	rudzllift = CreateDynamicObject(18755, 488.46259, 772.26239, 1002.35498,   0.00000, 0.00000, 180.00000);//lift gore
	rudnikgate1 = CreateDynamicObject(19912,490.4233, 774.5048, 1005.8767,0.0000, 0.0000, 90.0000);//gornja dignuta
	rudnikgate2 = CreateDynamicObject(19912,490.5960, 775.6660, 967.0025,0.0000, 0.0000, 90.0000);//donja ograda lifta spustena
	RudnikLift = false;
	RudnikLiftuPokretu = false;
	
	vrataPD = false;
	vrataPDobject = CreateDynamicObject(1569, 239.59669, 116.85300, 1020.30981,   0.00000, 0.00000, 90.00000);
	
	celija[ 0 ] = CreateDynamicObject(19303, 222.21609, 1649.47095, -99.00210,   0.00000, 0.00000, 0.00000);
	celija[ 1 ] = CreateDynamicObject(19303, 228.61610, 1656.74536, -99.00210,   0.00000, 0.00000, 0.00000);
	celija[ 2 ] = CreateDynamicObject(19303, 234.99609, 1656.74536, -99.00210,   0.00000, 0.00000, 0.00000);
	celija[ 3 ] = CreateDynamicObject(19303, 235.01230, 1649.47095, -99.00210,   0.00000, 0.00000, 0.00000);
	celija[ 4 ] = CreateDynamicObject(19303, 228.61850, 1649.47095, -99.00210,   0.00000, 0.00000, 0.00000);
	celija[ 5 ] = CreateDynamicObject(19303, 235.18910, 1656.74634, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 6 ] = CreateDynamicObject(19303, 238.18640, 1649.42944, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 7 ] = CreateDynamicObject(19303, 231.79469, 1649.42944, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 8 ] = CreateDynamicObject(19303, 225.38989, 1649.42944, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 9 ] = CreateDynamicObject(19303, 222.35910, 1656.74634, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 10 ] = CreateDynamicObject(19303, 228.75900, 1656.74634, -95.48680,   0.00000, 0.00000, 0.00000);
	celija[ 11 ] = CreateDynamicObject(19303, 222.19710, 1656.74536, -99.00210,   0.00000, 0.00000, 0.00000);
	VremeZatvaranjaCelija = -1;
	OtvoreneCelije = false;

	ZlataraUToku = false;
	ZlataraOpljackana = false;

	LaseriBanka[ 0 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2044.71631,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 1 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2045.30627,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 2 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2045.89624,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 3 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2046.48633,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 4 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2047.07629,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 5 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2047.66626,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 6 ] = CreateDynamicObject(18643, 1485.53259, -1006.33038, 2048.25635,   0.00000, 0.00000, 180.00000);
	LaseriBanka[ 7 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2048.25635,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 8 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2047.66626,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 9 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2047.07629,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 10 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2046.48633,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 11 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2045.89624,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 12 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2045.30627,   0.00000, 0.00000, 0.00000);
	LaseriBanka[ 13 ] = CreateDynamicObject(18643, 1456.26855, -1006.33038, 2044.71631,   0.00000, 0.00000, 0.00000);

	SruseniLaseri = false;
	BankaOpljackana = false;
	PljackaUToku = false;

	VrataSefaBanke = CreateDynamicObject(2634, 1470.7053, -1015.7482, 2046.0902,   0.0000, 0.0000, 0.0000);//normala
	VrataBankeSrusena = false;
	
	
	rampagranice1_1 = CreateDynamicObject(968, 55.9345, -1536.2976, 4.8009,   0.0000, -90.0000, 82.2394);//newara
	rampagranice1_2 = CreateDynamicObject(968, 48.9824, -1527.1849, 4.9181,   0.0000, 90.0000, 80.1310);//newara
	
	rampagranice2_1 = CreateDynamicObject(968, 1748.3174, 535.2873, 27.1845,  0.0000, 90.0000, -19.2145);//newara
	rampagranice2_3 = CreateDynamicObject(968, 1728.9937, 530.8777, 27.6405,   0.0000, 90.0000, -19.0000);//newara

	
	return 1;
	
	
}

//------------------------------------------------------------------------------

public OnPlayerPickUpDynamicPickup( playerid, pickupid )
{
	if( pickupid == komunalac1pickup )
	{
		ChosenJob[ playerid ] = POSAO_KOMUNALAC;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,0,1,3);
		
	}
	if( pickupid == komunalac2pickup )
	{
		ChosenJob[ playerid ] = POSAO_KOMUNALAC;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,0,1,3);
	}
	if( pickupid == komunalac3pickup )
	{
		ChosenJob[ playerid ] = POSAO_KOMUNALAC;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,0,1,3);

	}
	if( pickupid == mehanicarpickup )
	{
		ChosenJob[ playerid ] = POSAO_MEHANICAR;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
		
	}
	if( pickupid == prevoznik1pickup )
	{
		ChosenJob[ playerid ] = POSAO_PREVOZNIK;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == prevoznik2pickup )
	{
		ChosenJob[ playerid ] = POSAO_PREVOZNIK;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	
	}
	if( pickupid == prevoznik3pickup )
	{
		ChosenJob[ playerid ] = POSAO_PREVOZNIK;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == masinovodjapickup )
	{
		ChosenJob[ playerid ] = POSAO_MASINOVODJA;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == kosactravepickup )
	{
		ChosenJob[ playerid ] = POSAO_KOSAC;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,0,1,0,1,3);
		
	}
	if( pickupid == taxipickup )
	{
		ChosenJob[ playerid ] = POSAO_TAXI;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);

	}
	if( pickupid == gradjevinarpickup )
	{
		ChosenJob[ playerid ] = POSAO_GRADJEVINAR;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == dostavljacpicapickup )
	{
		ChosenJob[ playerid ] = POSAO_PIZZA;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,0,1,3);
	}
	if( pickupid == farmerpickup )
	{
		ChosenJob[ playerid ] = POSAO_FARMER;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,0,1,3);
	}
	if( pickupid == pilotpickup )
	{
		ChosenJob[ playerid ] = POSAO_PILOT;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == busvozacpickup )
	{
		ChosenJob[ playerid ] = POSAO_BUSVOZAC;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == rudarpickup )
	{
		ChosenJob[ playerid ] = POSAO_RUDAR;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == prevoznovcapickup )
	{
		ChosenJob[ playerid ] = POSAO_PREVOZNOVCA;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == ribarpickup )
	{
		ChosenJob[ playerid ] = POSAO_RIBAR;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == pnamestajapickup )
	{
		ChosenJob[ playerid ] = POSAO_PNAMESTAJA;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	if( pickupid == pepsiposaopickup )
	{
		ChosenJob[ playerid ] = POSAO_TEMPODOSTAVA;
		//playerid,vozacka,licna,pasos,iskustvo,ugovor
		ZaposljavanjeDialog(playerid,1,1,1,1,3);
	}
	return 1;
}
//------------------------------------------------------------------------------

///////////////////////



stock CheckWeapons( i )
{
	if( antiCheatSS[ antiWeaponH ] == true )
	{
		if( antiCheatCS[ i ][ WeaponDetect ] <= 0 )
		{
			if( NaDmEventu[ i ] == false && antiCheatCS[ i ][ WeaponCheck ] == 1 && WARPInfo[ i ][ WARIgrac ] == -1 && GetPlayerSpecialAction( i ) != SPECIAL_ACTION_ENTER_VEHICLE && GetPlayerSpecialAction( i ) != SPECIAL_ACTION_EXIT_VEHICLE ) {

				new bullets[ MAX_W_SLOTS ], weapon[ MAX_W_SLOTS ];
				for( new slot = 0; slot < MAX_W_SLOTS; slot++ )
				{

					bullets[ slot ] = 0; weapon[ slot ] = 0;

					GetPlayerWeaponData( i, slot, weapon[ slot ], bullets[ slot ] );

					if( IsValidWeapon( weapon[ slot ] ) && !Dimi_IsGiveVehicleWeapon( weapon[ slot ] ) )
					{ 

						if( antiCheatCS[ i ][ Weapon ][ slot ] != weapon[ slot ] && weapon[ slot ] != 0 && bullets[ slot ] != 0 )
						{

							antiCheatCS[ i ][ TakenWeapon ] = weapon[ slot ];
							OnPlayerCheat( i, DETECT_WEAPON_HACK, 0, 0 );
						}
						else if( ( ( antiCheatCS[ i ][ Ammo ][ slot ] - bullets[ slot ] ) < 0 ) && Dimi_IsNotWeaponNoAmmo( weapon[ slot ] ) && weapon[ slot ] != 0 )
						{

							antiCheatCS[ i ][ TakenWeapon ] = weapon[ slot ];
							OnPlayerCheat( i, DETECT_AMMO_HACK, bullets[ slot ], antiCheatCS[ i ][ Ammo ][ slot ]  );
						}
						else if( antiCheatCS[ i ][ Weapon ][ slot ] != 0 && weapon[ slot ] == 0 && bullets[ slot ] == 0 )
						{
						
							antiCheatCS[ i ][ Weapon ][ slot ] = 0;
							antiCheatCS[ i ][ Ammo ][ slot ] = 0;
						}
						else if( bullets[ slot ] != 0 ) antiCheatCS[ i ][ Ammo ][ slot ] = bullets[ slot ];

					}
				}
			}
		}
		else {
			antiCheatCS[ i ][ WeaponDetect ]--;
		}

	}
}

stock GetXYZInFrontOfPlayer(playerid, &Float: xbr, &Float: ybr, &Float: zbr, Float: distance) {
	new Float: a;

	GetPlayerPos (playerid, xbr, ybr, zbr);
	GetPlayerFacingAngle (playerid, a);

	xbr += (distance * floatsin (-a, degrees));
	ybr += (distance * floatcos (-a, degrees));
}

public OnUnoccupiedVehicleUpdate( vehicleid, playerid, passenger_seat ) 
{
	new Float:x, Float:y, Float:z;
	GetVehiclePos( vehicleid, x, y, z );
	
	if( RealVehiclePositions[ vehicleid ][ 0 ] != 0 && RealVehiclePositions[ vehicleid ][ 1 ] != 0 && RealVehiclePositions[ vehicleid ][ 2 ] != 0 ) {
		if( IsVehiclePrikolica( vehicleid ) ) {
			if( IsValidVehicle( LastPullingVehicle[ vehicleid ] ) ) {
				new Float:distance = GetVehicleDistanceFromPoint( LastPullingVehicle[ vehicleid ], x, y, z );
				if( distance <= 15 ) {
					RealVehiclePositions[ vehicleid ][ 0 ] = x;
					RealVehiclePositions[ vehicleid ][ 1 ] = y;
					RealVehiclePositions[ vehicleid ][ 2 ] = z;
					return 1;
				}
			}
		}
		if( GetVehicleDistanceFromPoint( vehicleid, RealVehiclePositions[ vehicleid ][ 0 ], RealVehiclePositions[ vehicleid ][ 1 ], RealVehiclePositions[ vehicleid ][ 2 ] ) > 50.0 ) {

			SetVehiclePos( vehicleid, RealVehiclePositions[ vehicleid ][ 0 ], RealVehiclePositions[ vehicleid ][ 1 ], RealVehiclePositions[ vehicleid ][ 2 ] );
			return 0;
		}
	}
	GetVehiclePos( vehicleid, RealVehiclePositions[ vehicleid ][ 0 ], RealVehiclePositions[ vehicleid ][ 1 ], RealVehiclePositions[ vehicleid ][ 2 ] );
	return 1;
}

stock CheckTeleports( i )
{
	if( antiCheatSS[ antiFlyH ] == true )
	{
		if( antiCheatCS[ i ][ TeleportCheck ] <= 0 && WatchingTV{ i } == 0 && GetPlayerState( i ) == PLAYER_STATE_ONFOOT )
		{
			if( !AdminDuty[ i ] && GetPlayerSpecialAction( i ) != SPECIAL_ACTION_USEJETPACK && GetPlayerWeapon( i ) != 46 )
			{
				if( GetPlayerAnimationIndex( i ) != 1195 && GetPlayerAnimationIndex( i ) != 1130 )
				{
					if( GetPlayerSurfingVehicleID( i ) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID( i ) == INVALID_OBJECT_ID && GetPlayerInterior( i ) == 0 && GetPlayerVirtualWorld( i ) == 0  )
					{
						if( !IsPlayerInDynamicArea( i, GradjPosao ) &&
							!IsPlayerInDynamicArea( i, FarmerPosao ) &&
							!IsPlayerInDynamicArea( i, SpawnZona ) &&
							!IsPlayerInDynamicArea( i, SSB ) &&
							!IsPlayerInDynamicArea( i, KosacMost ) &&
							!IsPlayerInDynamicArea( i, AdminBaza ) &&
							!IsPlayerInDynamicArea( i, ZgradaNeka ) &&
							!IsPlayerInDynamicArea( i, GSFMost ) &&
							!IsPlayerInDynamicArea( i, VineWoodArea ) &&
							!IsPlayerInDynamicArea( i, SAJBaza ))
							
						{

							new Float:Pos[ 5 ];
							GetPlayerPos( i, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
							MapAndreas_FindZ_For2DCoord( Pos[ 0 ], Pos[ 1 ], Pos[ 3 ] );
							Pos[ 4 ] = floatsub( Pos[ 2 ], Pos[ 3 ] );
							if( Pos[ 4 ] > 10 )
							{
								OnPlayerCheat( i, DETECT_FLY_HACK, 0, 0 );
							}
						}
					}
				}
			}
		}
	}

	if( antiCheatSS[ antiTeleportH ] == true ) {
		new Float:Pos[ 3 ];
		GetPlayerPos( i, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

		if( antiCheatCS[ i ][ TeleportCheck ] <= 0 ) {
			if( ( Pos[ 2 ] < 900.0 ) == ( antiCheatCS[ i ][ TeleportPos ][ 2 ] < 900.0 ) ) {

				if( GetPlayerState( i ) != PLAYER_STATE_PASSENGER && WatchingTV{ i } == 0 && GetPlayerSurfingVehicleID( i ) == INVALID_VEHICLE_ID && PlayerInfo[ i ][ xRPLearn ] <= 0 && PlayerInfo[ i ][ xPocetniTut ] == 1 && !IsVehicleLetelica( GetPlayerVehicleID( i ) ) ) {

					if( !IsPlayerInRangeOfPoint( i, 100.0, antiCheatCS[ i ][ TeleportPos ][ 0 ], antiCheatCS[ i ][ TeleportPos ][ 1 ], antiCheatCS[ i ][ TeleportPos ][ 2 ] ) ) {

						antiCheatCS[ i ][ TeleportHack ]++;
						if( antiCheatCS[ i ][ TeleportHack ] >= 3 || IsCheatPosition( i ) ) {
							OnPlayerCheat( i, DETECT_TELEPORT_HACK, 0, 0 );
						}
					}
				}
			}
		}
		else {
			antiCheatCS[ i ][ TeleportCheck ]--;
		}
		antiCheatCS[ i ][ TeleportPos ][ 0 ] = Pos[ 0 ];
		antiCheatCS[ i ][ TeleportPos ][ 1 ] = Pos[ 1 ];
		antiCheatCS[ i ][ TeleportPos ][ 2 ] = Pos[ 2 ];
	}
}

public OnPlayerRequestClass( playerid, classid) {
	if( PlayerLogged[ playerid ] == true ) {
		Dimi_SetSpawnInfo( playerid );
		SpawnPlayer( playerid );
	}
	else return false;
	return true;
}

forward Login( playerid );
public Login( playerid )
{
	hidectd(playerid);
	TextDrawHideForPlayer(playerid,connect0);
	TextDrawHideForPlayer(playerid,connect1);
	TextDrawHideForPlayer(playerid,connect2);
	TextDrawHideForPlayer(playerid,connect3);
	TextDrawHideForPlayer(playerid,connect4);
	TextDrawHideForPlayer(playerid,connect5);
	/*TogglePlayerSpectating( playerid, true );
	InterpolateCameraPos(playerid, 1364.831787, -859.197448, 82.750671, 1431.409790, -859.941406, 82.750671, 10000);
	InterpolateCameraLookAt(playerid, 1364.887695, -854.197875, 82.712821, 1431.465698, -854.941833, 82.712821, 10000);*/
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
	
	ClearChat( playerid, 25 );

	LoginTDControl( playerid, true );
	//SelectTextDraw( playerid, UGBOJA );

	PrviSpawn[ playerid ] = 1;
	new logg[400];
	format(logg,sizeof(logg),"{FFFFFF}Dobrodosli na "col_balkanstory"Nova Era - RolePlay!\n\n"col_balkanstory"||------------------------------------------------------------||\n\n"col_balkanstory"-Vase Ime: {FFFFFF}%s\n\n"col_balkanstory"-Discord: {FFFFFF}USKORO\n\n"col_balkanstory"-Account: {FFFFFF}Vas account je registrovan\n\n"col_balkanstory"-Unesite vas {FFFFFF}password!\n\n"col_balkanstory"||------------------------------------------------------------||",ImeIgraca(playerid));
	ShowPlayerDialog(playerid,dialog_LOGIN, DSP, "Nova Era RolePlay | Login",logg, "Prijava", "Odustani");
	return 1;
}

public Register( playerid )
{
	hidectd(playerid);
	TextDrawHideForPlayer(playerid,connect0);
	TextDrawHideForPlayer(playerid,connect1);
	TextDrawHideForPlayer(playerid,connect2);
	TextDrawHideForPlayer(playerid,connect3);
	TextDrawHideForPlayer(playerid,connect4);
	TextDrawHideForPlayer(playerid,connect5);
	/*TogglePlayerSpectating( playerid, true );
	InterpolateCameraPos(playerid, 1364.831787, -859.197448, 82.750671, 1431.409790, -859.941406, 82.750671, 10000);
	InterpolateCameraLookAt(playerid, 1364.887695, -854.197875, 82.712821, 1431.465698, -854.941833, 82.712821, 10000);*/
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
	
	ClearChat( playerid, 25 );
	RegisterTDControl( playerid, true );
	IgracSeRegistruje[ playerid ] = true;
	SelectTextDraw( playerid, UGBOJA );
	LoginTDControl( playerid, false );
	return true;
}

forward Dimi_Kick( playerid );
public Dimi_Kick( playerid ) 
{
	SetTimerEx( "KickIgraca", 1000, 0, "d", playerid );
}

CheckRekord( ) 
{
	if( ServerInfo[ RekordServera ] < NumberOfConnectedPlayers( ) ) {
		ServerInfo[ RekordServera ] = NumberOfConnectedPlayers( );
		//new NoviRekString[ 128 ];
		//format( NoviRekString, sizeof( NoviRekString ), ""col_balkanstory"SM"col_white":"col_balkanstory"RP"col_white" Novi rekord na serveru je: "col_balkanstory"%d.", ServerInfo[ RekordServera ] );
		//SendClientMessageToAll( -1, NoviRekString );
	}
}

stock RETARDII()
{
	return 1;
}

NumberOfConnectedPlayers( ) {
	new Connected = 0;
	for(new i; i < MAX_PLAYERS; i++) if( IsPlayerConnected( i ) && !IsPlayerNPC( i ) ) Connected++;
	return Connected;
}

stock GPSpeed( playerid ) {

	new Float:ST[4];
	if(IsPlayerInAnyVehicle(playerid))
	GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
	else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
	ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
	return floatround(ST[3]);
}

forward ActionEffect( playerid );
public ActionEffect( playerid ) {

	#if NERP_ZIMSKI_MOD  == 1
	if( PlayerLogged[ playerid ] == true ) {

		if( GetPlayerInterior( playerid ) == 0 && GetPlayerVirtualWorld( playerid ) == 0 )
		{

			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_FREE );
			PlayerEffect[ playerid ] = SetPlayerAttachedObject( playerid, OBJECT_SLOT_FREE, 18696, 2,0.0,0.1,-0.2,-25.5000,0.0,0.0,0.10,0.3,0.15);
			if( GPSpeed( playerid ) > 10 && PlayerRun[ playerid ] == 0 )
			{

				Dimi_KillTimer( EffectTimer[ playerid ] );
				EffectTimer[ playerid ] = SetTimerEx("ActionEffect", 890, true, "d", playerid );
				PlayerRun[ playerid ] = 1;
			}
			else if( GPSpeed( playerid ) < 10 && PlayerRun[ playerid ] == 1 )
			{

				Dimi_KillTimer( EffectTimer[ playerid ] );
				EffectTimer[ playerid ] = SetTimerEx( "ActionEffect", 1900, true, "d", playerid );
				PlayerRun[ playerid ] = 0;
			}
		}
	}
	#endif
}


ClientSelectionTimer(playerid,id);
public ClientSelectionTimer(playerid,id)
{
	if(id == 0)
	{
		TextDrawHideForPlayer(playerid,connect0);
		TextDrawHideForPlayer(playerid,connect1);
		TextDrawHideForPlayer(playerid,connect2);
		TextDrawHideForPlayer(playerid,connect3);
		TextDrawHideForPlayer(playerid,connect4);
		TextDrawHideForPlayer(playerid,connect5);
		SetTimerEx("ClientSelectionTimer", 1000, false, "ii", playerid, 1);
	}
	if(id == 1)
	{
		ClientSelectControl(playerid, true);
		SelectTextDraw(playerid, UGBOJA);
	}
	return 1;
}


LogRegSelectionTimer(playerid,id);
public LogRegSelectionTimer(playerid,id)
{
	if(id == 0)
	{
		SetTimerEx("LogRegSelectionTimer", 1000, false, "ii", playerid, 1);
	}
	if(id == 1)
	{
		LogRegSelectControl(playerid, true);
		SelectTextDraw(playerid, UGBOJA);
	}
	return 1;
}



UpdateBankTD(playerid)
{ 
	#pragma unused playerid 
	return 1;
}

UpdateZlatoTD(playerid)
{ 
	#pragma unused playerid 
	return 1;
}

UpdatePlataTD( playerid )
{
	SendJobMessage(playerid, "Plata je legla na Vas racun!");
	return 1;
}

SetPlayerTDStats( playerid ) {

	LoginTDControl( playerid, false );
	new stringic[ 40 ];

	format( stringic, sizeof( stringic ), "G: %d", PlayerInfo[ playerid ][ xHunger ] );
	PlayerTextDrawSetString( playerid, GladIgraca[ playerid ], stringic );
	
	format( stringic, sizeof( stringic ), "WC: %d", PlayerInfo[ playerid ][ xToilet ] );
	PlayerTextDrawSetString( playerid, WcIgraca[ playerid ], stringic );

	if(ClientType[playerid] == CLIENT_PC) PlayerTextDrawShow( playerid, GladIgraca[ playerid ] );
	if(ClientType[playerid] == CLIENT_PC) PlayerTextDrawShow( playerid, WcIgraca[ playerid ] );
	if(ClientType[playerid] == CLIENT_PC) PlayerTextDrawShow( playerid, LokacijaIgracaTD[ playerid ] );
	if(ClientType[playerid] == CLIENT_PC) PlayerTextDrawShow( playerid, GradIgracaTD[ playerid ] );

	ShowBGTextdraw(playerid);

	Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
}

stock DonatorBoja( playerid ) {

	if( PlayerInfo[ playerid ][ xDBO ] ) {
	
		if( PlayerInfo[ playerid ][ xDBoja ] == 0 ) {
			SetPlayerColor( playerid, 0xFFFFFF00 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 1 ) {
		
			SetPlayerColor(playerid, 0xFF808000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 2 ) {
		
			SetPlayerColor(playerid, 0xFF000000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 3 ) {
		
			SetPlayerColor(playerid, 0x80FFFF00 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 4 ) {
		
			SetPlayerColor(playerid, 0xFF804000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 5 ) {
		
			SetPlayerColor(playerid, 0xFF62B000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 6 ) {
		
			SetPlayerColor(playerid, 0xC0C0C000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 7 ) {
		
			SetPlayerColor(playerid, 0x00FF0000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 8 ) {
		
			SetPlayerColor(playerid, 0xFFFF0000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 9 ) {
		
			SetPlayerColor(playerid, 0x00800000 );
		}
		else if( PlayerInfo[ playerid ][ xDBoja ] == 10 ) {
		
			SetPlayerColor(playerid, 0x0000FF00 );
		}
	}
}

forward Danecrkne(playerid); public Danecrkne(playerid) 
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	if( !success ) return 1;
	new ip2[ 32 ];
	if( success ) {

		for(new i; i < MAX_PLAYERS; i++) {

			GetPlayerIp( i, ip2, sizeof( ip2 ) );
			if( !strcmp( ip, ip2, true ) ) {
				if(PlayerInfo[ i ][ xRCON ] == 0)
				{
					new rcon_admin_login_log[200];
					format( rcon_admin_login_log, sizeof( rcon_admin_login_log ), "[RCON Login | KICK]: {ffffff}Igrac %s je izbacen sa servera! Razlog: Ne posjedovanje RCON dozvole!", ImeIgraca( i ) );
					AdminPoruka( ZUTA, rcon_admin_login_log );
					Kickovanje( i, "Izbacen si sa servera jer si se pokusao ulogovat na rcon a nemas rcon admina! staff je obavesten!!!" );
				}
				else if(PlayerInfo[ i ][ xRCON ] == 1)
				{
					if(!RconAdmin[ i ]) {
						SendInfoMessage(i,"Uspjesno si se ulogovao na admin sistem!");
						new d[300];
						format(d,sizeof(d),""col_red"RCON ||: "col_yellow"Igrac %s se ulogovao na admin sistem!",ImeIgraca(i));
						AdminPoruka(-1,d);
						RconAdmin[ i ] = true;
						return 1;
					}
					else if(RconAdmin[ i ]) {
						SendClientMessagee(i,-1,"Vi ste vec ulogovani na admin sistem!");
						return 1;
					}
				}
			}
		}
	}
	return true;
}
nsdunep(playerid);
public nsdunep(playerid)
{
	ShowPlayerDialog(playerid, DEntisT_invalid_dialogid, DIALOG_STYLE_MSGBOX, "Nova Era | Security - pin nije ukucan na vreme", "Niste stigli unijeti Nova Era pin za 15 \nsekundi, dobili se kick iz igre - nakon reloga na server \npokusajte ponovo!", "U redu", "");
	Kickovanje(playerid,"Zastitni Nova Era pin nije ukucan za 15s.");
	return 1;
}
/*
public OnPlayerObjectMoved(playerid, objectid)
{
	printf("Player object moved: objectid: %d playerid: %d", objectid, playerid);
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	printf("Player %d left a race checkpoint!", playerid);
	return 1;
}*/

stock ShowInteractiveMenu(playerid)
{
	TextDrawShowForPlayer(playerid,TDEditor_TD[52]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[53]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[54]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[55]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[56]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[57]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[58]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[59]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[60]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[61]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[62]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[63]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[64]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[65]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[66]);
	TextDrawShowForPlayer(playerid,TDEditor_TD[67]);
}

stock HideInteractiveMenu(playerid)
{
	TextDrawHideForPlayer(playerid,TDEditor_TD[52]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[53]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[54]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[55]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[56]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[57]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[58]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[59]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[60]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[61]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[62]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[63]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[64]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[65]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[66]);
	TextDrawHideForPlayer(playerid,TDEditor_TD[67]);
}

hidebetatd(playerid); public hidebetatd(playerid)
{
	hidebatd(playerid);
	return 1;
}

public OnPlayerSpawn( playerid ) 
{
	CallLocalFunction("ANIM_OnPlayerSpawn", "i", playerid);
	LoginTDControl( playerid, false );
	//Modern[playerid] = 1; //da se makso ne ljuti :DD
	Dimi_DisablePlayerCheckpoint(playerid);
	TogglePlayerSpectating(playerid,0);
	if(!gPlayerAnimLibsPreloaded[playerid])
	{
		PreloadAnimLib(playerid,"BOMBER");
		PreloadAnimLib(playerid,"RAPPING");
		PreloadAnimLib(playerid,"SHOP");
		PreloadAnimLib(playerid,"BEACH");
		PreloadAnimLib(playerid,"SMOKING");
		PreloadAnimLib(playerid,"FOOD");
		PreloadAnimLib(playerid,"ON_LOOKERS");
		PreloadAnimLib(playerid,"DEALER");
		PreloadAnimLib(playerid,"CRACK");
		PreloadAnimLib(playerid,"CARRY");
		PreloadAnimLib(playerid,"COP_AMBIENT");
		PreloadAnimLib(playerid,"PARK");
		PreloadAnimLib(playerid,"INT_HOUSE");
		PreloadAnimLib(playerid,"FOOD");
		PreloadAnimLib(playerid,"PED");
		gPlayerAnimLibsPreloaded[playerid] = 1;
	}
	SetTimerEx("phidetdtd", 1500, false, "i", playerid);
	SetTimerEx("hidebetatd", 10000, false, "i", playerid);
	//if(PrviSpawn[playerid] == 0) announcement(playerid,"Spawnovani ste!");
	PlayerTextDrawSetPreviewModel(playerid,SkinIgraca[playerid], PlayerInfo[playerid][xSkin]);
	for( new i = 0; i < 100; i ++)
	{
		TextDrawShowForPlayer( playerid, TDEditor_TD[ i ] );
	}
	#if defined retardirani_textdrawi
	if(Modern[playerid] == 1)
	{
		moderntd(playerid,true);
		for( new i = 0; i < 100; i ++)
		{
			TextDrawHideForPlayer( playerid, TDEditor_TD[ i ] );
		}
		for( new  i = 0; i < 100; i ++)
		{
			TextDrawHideForPlayer( playerid, TDEditor_TD[ i ] );
		}
		/*for( new i = 0; i < 15; i ++)
		{
			TextDrawHideForPlayer( playerid, GPSIGTD[ i ] );
		}*/
		TextDrawHideForPlayer( playerid, GladTDPizza);
		TextDrawHideForPlayer( playerid, WcTDSolja);
		PlayerTextDrawHide( playerid, GladIgraca[ playerid ] );
		PlayerTextDrawHide( playerid, WcIgraca[ playerid ] );
		PlayerTextDrawHide( playerid, LokacijaIgracaTD[ playerid ] );
		PlayerTextDrawHide( playerid, GradIgracaTD[ playerid ] );
		PlayerTextDrawHide( playerid, BankaIgraca[ playerid ] );
		//PlayerTextDrawHide( playerid, PlataIgraca[ playerid ] );
		PlayerTextDrawHide( playerid, ZlatoIgraca[ playerid ] );
		HideBGTextdraw(playerid);
		//PlayerTextDrawHide(playerid, Textdraw3[playerid]);
		PlayerTextDrawHide(playerid, Textdraw1[playerid]);
		PlayerTextDrawHide(playerid, Textdraw2[playerid]);
		PlayerTextDrawHide(playerid, Textdraw3[playerid]);
		TogHud[ playerid ] = true;
		hidehjhh(playerid);
		
		ShowInteractiveMenu(playerid);
	}
	#endif
	TextDrawShowForPlayer(playerid,healthbar0);
	TextDrawShowForPlayer(playerid,healthbar1);
	TextDrawShowForPlayer(playerid,healthbar2);
	TextDrawShowForPlayer(playerid,healthbar0);
	TextDrawShowForPlayer(playerid,healthbar1);
	TextDrawShowForPlayer(playerid,healthbar2);
	showhb(playerid);
	#if defined script_init_taskkill
	hidedt(playerid);
	#endif
	#if BETA_BUILD == 1
	hidebatd(playerid);
	showbatd(playerid);
	#endif
	TextDrawHideForPlayer(playerid,connect0);
	TextDrawHideForPlayer(playerid,connect1);
	TextDrawHideForPlayer(playerid,connect2);
	TextDrawHideForPlayer(playerid,connect3);
	TextDrawHideForPlayer(playerid,connect4);
	TextDrawHideForPlayer(playerid,connect5);
	hidectd(playerid);

	hidektd(playerid);

	hidedmtd(playerid);
	if( NaDmEventu[ playerid ] == true )
	{
		showdmtd(playerid);
	}

	RconAdmin[playerid] = false;
	if(PlayerInfo[playerid][xRCON] == 1) {
		RconAdmin[playerid] = true;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	new skinid = GetPlayerSkin(playerid);
	printf("[spawn] %s ( playerid=%i ) has spawned on coordinates: x=%f, y=%f, z=%f with weaponid=0 and skin id=%i!",ImeIgraca(playerid),playerid,x,y,z,skinid);
	Dimi_SetPlayerHealth( playerid, 50.0+PlayerInfo[ playerid ][ xSHealth ] );
	if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 ) {
		Dimi_SetPlayerHealth( playerid, 100.00 );
	}
	
	SetPlayerColor( playerid, 0xFFFFFF00 );
	for( new i = 0; i < 13; i++ ) {
		antiCheatCS[ playerid ][ Weapon ][ i ] = 0;
		antiCheatCS[ playerid ][ Ammo ][ i ] = 0;
	}

	PlayerLogged[playerid] = true;

	Reklamirao[playerid] = false;
	SetPlayerTDStats( playerid );
	PocetniNovac( playerid, PlayerInfo[ playerid ][ xNovac ] );
	SetPlayerScore( playerid, PlayerInfo[ playerid ][ xLevel ] );
	SetPlayerSkin( playerid, PlayerInfo[ playerid ][ xSkin ] );
	SetPlayerInterior( playerid, 0 );
	SetPlayerVirtualWorld( playerid, 0 );
	
	if( PlayerInfo[playerid][xRanac] == 1 )
	{
		//SetPlayerAttachedObject( playerid, OBJECT_SLOT_BACKPACK, 3026, 1, -0.134207, -0.093048, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_BACKPACK, 371, 1, 0.087999, -0.125000, -0.014000, 3.299999, 86.200019, -5.300003, 1.000000, 1.000000, 1.000000 );
	}

	antiCheatCS[ playerid ][ TeleportCheck ] = 4;
	antiCheatCS[ playerid ][ WeaponDetect ] = 4;
	antiCheatCS[ playerid ][ EnteredVehicle ] = INVALID_VEHICLE_ID;
	
	if( AdminVozilo[ playerid ] != -1 ) Dimi_DestroyVehicle( AdminVozilo[ playerid ] ), AdminVozilo[ playerid ] = -1;

	if( TrkaVozilo[ playerid ] != -1 ) Dimi_DestroyVehicle( TrkaVozilo[ playerid ] ), TrkaVozilo[ playerid ] = -1;
	
	DonatorBoja( playerid );
	
	for( new id = 1; id < MAX_GZONE; id++ ) {

		new filename[ 32 ], stringic[ 24 ];
		format( filename, sizeof( filename ), F_GZONE, id );

		if( fexist( filename ) ) {

			format( stringic, sizeof( stringic ), "0x%s66", gZoneInfo[ id ][ gZoneColor ] );
			GangZoneShowForPlayer( playerid, gZoneInfo[ id ][ gZoneID ], HexToInt( stringic ) );
		}
	}
	
	if( WARPInfo[ playerid ][ WARIgrac ] != -1 ) {
		new w = WARPInfo[ playerid ][ WARIgrac ];

		SetPlayerVirtualWorld( playerid, w );
		Dimi_SetPlayerHealth( playerid, 100 );
		Dimi_SetPlayerArmour( playerid, 100 );
		antiCheatCS[ playerid ][ TeleportCheck ] = 4;
		antiCheatCS[ playerid ][ WeaponDetect ] = 4;
		if( WARInfo[ w ][ WARMapa ] == 1 ) {
			new rand1 = random( sizeof( RandomWARMapa11 ) );
			new rand2 = random( sizeof( RandomWARMapa12 ) );
			if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa11[ rand1 ][ 0 ], RandomWARMapa11[ rand1 ][ 1 ],RandomWARMapa11[ rand1 ][ 2 ] ); }
			else if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa12[ rand2 ][ 0 ], RandomWARMapa12[ rand2 ][ 1 ],RandomWARMapa12[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ WARMapa ] == 2 ) {
			new rand1 = random( sizeof( RandomWARMapa21 ) );
			new rand2 = random( sizeof( RandomWARMapa22 ) );
			if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa21[ rand1 ][ 0 ], RandomWARMapa21[ rand1 ][ 1 ],RandomWARMapa21[ rand1 ][ 2 ] ); }
			else if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa22[ rand2 ][ 0 ], RandomWARMapa22[ rand2 ][ 1 ],RandomWARMapa22[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 10 );
		}
		else if( WARInfo[ w ][ WARMapa ] == 3 ) {
			new rand1 = random( sizeof( RandomWARMapa31 ) );
			new rand2 = random( sizeof( RandomWARMapa32 ) );
			if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa31[ rand1 ][ 0 ], RandomWARMapa31[ rand1 ][ 1 ],RandomWARMapa31[ rand1 ][ 2 ] ); }
			else if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa32[ rand2 ][ 0 ], RandomWARMapa32[ rand2 ][ 1 ],RandomWARMapa32[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ WARMapa ] == 4 ) {
			new rand1 = random( sizeof( RandomWARMapa41 ) );
			new rand2 = random( sizeof( RandomWARMapa42 ) );
			if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa41[ rand1 ][ 0 ], RandomWARMapa41[ rand1 ][ 1 ], RandomWARMapa41[ rand1 ][ 2 ] ); }
			else if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa42[ rand2 ][ 0 ], RandomWARMapa42[ rand2 ][ 1 ], RandomWARMapa42[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ WARMapa ] == 5 ) {
			new rand1 = random( sizeof( RandomWARMapa51 ) );
			new rand2 = random( sizeof( RandomWARMapa52 ) );
			if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa51[ rand1 ][ 0 ], RandomWARMapa51[ rand1 ][ 1 ],RandomWARMapa51[ rand1 ][ 2 ] ); }
			else if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) { Dimi_SetPlayerPos( playerid, RandomWARMapa52[ rand2 ][ 0 ], RandomWARMapa52[ rand2 ][ 1 ],RandomWARMapa52[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 0 );
		}
		GiveWeaponToPlayer( playerid, WARInfo[ w ][ WAROruzje ][ 0 ], 300 );
		GiveWeaponToPlayer( playerid, WARInfo[ w ][ WAROruzje ][ 1 ], 300 );
		GiveWeaponToPlayer( playerid, WARInfo[ w ][ WAROruzje ][ 2 ], 300 );
		GiveWeaponToPlayer( playerid, WARInfo[ w ][ WAROruzje ][ 3 ], 300 );
		
		PlayerInfo[ playerid ][ xSpawned ] = 1;
		
		return true;
	}
	else if( NaDmEventu[ playerid ] == true ) {
		
		new rand = random( sizeof( RandomDMPos ) );
		Dimi_SetPlayerPos( playerid, RandomDMPos[ rand ][ 0 ], RandomDMPos[ rand ][ 1 ],RandomDMPos[ rand ][ 2 ] );
		SetPlayerFacingAngle( playerid, 360.000 );
		SetCameraBehindPlayer( playerid );
		SetPlayerInterior( playerid, 0 );
		SetPlayerVirtualWorld( playerid, 10 );

		PlayerInfo[ playerid ][ xSpawned ] = 1;

		if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 4500 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 26, 150 );
			GiveWeaponToPlayer( playerid, 28, 400 );
			GiveWeaponToPlayer( playerid, 31, 400 );
			SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
			SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 4000 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 27, 150 );
			GiveWeaponToPlayer( playerid, 32, 800 );
			GiveWeaponToPlayer( playerid, 31, 400 );
			SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 3500 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 27, 150 );
			GiveWeaponToPlayer( playerid, 28, 800 );
			GiveWeaponToPlayer( playerid, 31, 400 );
			SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 3000 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 27, 150 );
			GiveWeaponToPlayer( playerid, 29, 400 );
			GiveWeaponToPlayer( playerid, 31, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 2500 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 26, 150 );
			GiveWeaponToPlayer( playerid, 29, 400 );
			GiveWeaponToPlayer( playerid, 31, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 2000 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 26, 150 );
			GiveWeaponToPlayer( playerid, 29, 400 );
			GiveWeaponToPlayer( playerid, 30, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 1500 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 25, 100 );
			GiveWeaponToPlayer( playerid, 29, 400 );
			GiveWeaponToPlayer( playerid, 31, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 1000 ) {
			GiveWeaponToPlayer( playerid, 24, 150 );
			GiveWeaponToPlayer( playerid, 25, 100 );
			GiveWeaponToPlayer( playerid, 29, 400 );
			GiveWeaponToPlayer( playerid, 30, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 500 ) {
			GiveWeaponToPlayer( playerid, 24, 200 );
			GiveWeaponToPlayer( playerid, 25, 100 );
			GiveWeaponToPlayer( playerid, 29, 400 );
		}
		else if( PlayerInfo[ playerid ][ xDMEventUbistva ] >= 0 ) {
			GiveWeaponToPlayer( playerid, 24, 200 );
			GiveWeaponToPlayer( playerid, 25, 100 );
		}
		
		Dimi_SetPlayerHealth( playerid, 100 );
		Dimi_SetPlayerArmour( playerid, 100 );
		return true;
	}
	else {
		
		PlayerInfo[ playerid ][ xSpawned ] = 1;
		PostaviSpawn( playerid );
		// PLAYER_STATE_WASTED:old.code
		#if defined postavispawn_sjeban
		Ranjen[playerid] = 0;
		BunnyHop[playerid] = 0;
		KillTimer(BHKrajTimer[playerid]);
		hidedmtd(playerid);
		ClearChat(playerid,50);
		hidebatd(playerid);
		//KillTimer(deathafterinjury(playerid));
		KillTimer(DeathAfterInjury[playerid]);
		hideinjurytd(playerid);
		showdt(playerid);
		SetPlayerInterior(playerid,0);

		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		ShowLogo(playerid);
		PlayerInfo[playerid][xDeathScreen] = 1;

		SetTimerEx( "spawnplayer", 10000, false, "i", playerid );
		#endif
		// psops
	}

	PlayerInfo[ playerid ][ xSpawned ] = 1;

	if( PlayerInfo[ playerid ][ xWanted ] != 0 ) {
		strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nepoznato", 0, strlen( "Nepoznato" ), 255);
		strmid( ZlocinInfo[ playerid ][ zPocinio ], ImeIgraca( playerid ), 0, strlen( ImeIgraca( playerid ) ), 255);
		strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nepoznato", 0, strlen( "Nepoznato" ), 255);
		Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
	}
	if( PrviSpawn[ playerid ] == 1 )
	{
	
		if( PlayerLogged[ playerid ] == true ) 
		{
			#if NERP_ZIMSKI_MOD  == 1
			SendPlayerNotification(playerid, true, "Dobrodosli na server! Zelimo srecne praznike!");
			#elseif NERP_ZIMSKI_MOD == 0
			SendPlayerNotification(playerid, true, "Dobrodosli na server!");
			#endif
			//TogPlayerHud(playerid); //ovo na odabiru tdova se pojavljuju tdovi
			#if BETA_BUILD == 1
			hidebatd(playerid);
			showbatd(playerid);
			#endif
			new h,mi,sec,dan,mesec,godina;
			getdate(dan,mesec,godina);
			gettimeEx(h,mi,sec);
			FixHour( h );
			h = shifthour;
			StopAudioStreamForPlayer( playerid );
			
			Dimi_SetPlayerHealth(playerid, 100000.0); // stavlja igracu 10000 helta tako da ga niko nemoze ubiti
			//SendClientMessage(playerid, 0x33CCFFAA, "Imate 5 sekundi anti spawn-kill protekcije."); // salje igracu poruku da imaju anti spawn-kill protekciju
			SetTimerEx("antisk",5000,0,"i",playerid); // broj 5000 (5 sekundi) mozete promijeniti sa svojim (npr. ako promijenite 5000 sa 10000 anti spawn-kill ce trajati 10 sekundi).
			SendClientMessageEx( playerid, -1, ""col_white"Level: "col_balkanstory"%d "col_white"| Novac u dzepu: "col_balkanstory"$%d "col_white"| Novac u banci: "col_balkanstory"$%d"col_white".", PlayerInfo[ playerid ][ xLevel ], GetPlayerMoney( playerid ), PlayerInfo[ playerid ][ xBRacun ] );

			new orgclan_join_string[300];
			format(orgclan_join_string,sizeof(orgclan_join_string),"** (%s) Clan %s je upravo usao na server!",OI[ PlayerInfo[ playerid ][ xClan ] ][ oPreFix ],ImeIgraca(playerid));
			OrgPoruka(PlayerInfo[playerid][xClan],NARANDZASTA,orgclan_join_string);
			ClearChat( playerid, 50 );

			new welcome_message[300];
			format(welcome_message,sizeof(welcome_message),"** Postovanje i pozdrav, %s - dobro nam dosli nazad na Nova Era!",ImeIgraca(playerid));
			SendClientMessage(playerid,-1,welcome_message);

			/*if( ServerInfo[ HappyHours ] == true )
			{
				SendClientMessagee( playerid, -1, ""col_balkanstory"HH - Srecni sati i dupli respekti: {FFFFFF}Ukljuceni");
			}
			else if( ServerInfo[ HappyHours ] == false )
			{
				SendClientMessagee( playerid, -1, ""col_balkanstory"HH - Srecni sati i dupli respekti: {FFFFFF}Iskljuceni");
			}
			if( ServerInfo[ HappyJobs ] == true )
			{
				SendClientMessagee( playerid, -1, ""col_balkanstory"HJ - Srecne plate na racunu: {FFFFFF}Ukljuceno");
			}
			else if( ServerInfo[ HappyJobs ] == false )
			{
				SendClientMessagee( playerid, -1, ""col_balkanstory"HJ - Srecne plate na racunu: {FFFFFF}Iskljuceno");
			}*/
			SendClientMessage(playerid,-1,""col_balkanstory"NOVA ERA Pin ||: {ffffff}Da zastite racun od kradje - mozete dodati pin za sigurnost racuna! "col_red"(("col_yellow"/nepin"col_red"))");
			//SendClientMessage( playerid, -1, ""col_balkanstory"___________________________________________________________");
		
			#if defined script_init_taskkill
			hidedt(playerid);
			#endif

			//announcement(playerid,"Dobrodosli!");

			hidektd(playerid);

			hidedmtd(playerid);
			if( NaDmEventu[ playerid ] == true )
			{
				showdmtd(playerid);
			}
			//announcement(playerid,"~w~Dobrodosli nazad!", 5000, 5);
			PlayerInfo[playerid][xPP] = 0;
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) {

				if( PlayerInfo[ playerid ][ xAdmin ] < 1338 ) {
				
					new adminstring[ 128 ];
					if( PlayerInfo[ playerid ][ xAdmin ] == 1337 ) {
					
						SendClientMessage( playerid, BELA, ""col_balkanstory"| NE-A | "col_white"Ulogovali ste se kao "col_balkanstory"Direktor!" );
						format( adminstring, sizeof( adminstring ), "{FF0000}|| DIRECTOR ||"SERVERBOJA_AQUA" %s {FFFFFF}se prijavio na server!", ImeIgraca( playerid ) );
					}
					else if( PlayerInfo[ playerid ][ xAdmin ] == 6 ) {
					
						SendClientMessage( playerid, BELA, ""col_balkanstory"| NE-A | "col_white"Ulogovali ste se kao "col_balkanstory"Glavni Admin!" );
						format( adminstring, sizeof( adminstring ), "{FF0000}|| H-ADMIN ||"SERVERBOJA_AQUA" %s {FFFFFF}se prijavio na server!", ImeIgraca( playerid ) );
					}
					else if( PlayerInfo[ playerid ][ xAdmin ] >= 1 && PlayerInfo[ playerid ][ xAdmin ] <= 5 ) {
					
						SendClientMessage( playerid, BELA, ""col_balkanstory"| NE-A | "col_white"Ulogovali ste se kao "col_balkanstory"Admin!" );
						format( adminstring, sizeof( adminstring ), "{FF0000}|| ADMIN ||"SERVERBOJA_AQUA" %s {FFFFFF}se prijavio na server!", ImeIgraca( playerid ) );
					}
					/*if(PlayerInfo[playerid][xRCON] == 1) {
						SendInfoMessage(playerid, "Vi ste ulogovani kao RCON administrator!"); }*/
						
					AdminPoruka( 0x6495EDAA, adminstring );
					
				}
				else if( PlayerInfo[ playerid ][ xAdmin ] >= 1339 ) {
				
					SendClientMessage( playerid, BELA, ""col_balkanstory"| RP | "col_white"Ulogovali ste se kao "col_balkanstory"Vlasnik!" );

					for(new i; i < MAX_PLAYERS; i++) {
						if( PlayerInfo[ i ][ xAdmin ] >= 1339 ) {
							format( globalstring, sizeof( globalstring ), "{FF0000}|| OWNER ||"SERVERBOJA_AQUA" %s {FFFFFF}se prijavio na server!", ImeIgraca( playerid ) );
							SendClientMessage( i, 0xFF6347AA, globalstring );
						}
					}
				}
			}
			else if( PlayerInfo[ playerid ][ xHelper ] >= 1 ) {
				SendClientMessageEx( playerid, BELA, ""col_balkanstory"| SERVER | "col_white"Ulogovali ste se kao "col_balkanstory"%d "col_white"Level Helpera!", PlayerInfo[ playerid ][ xHelper ] );
				format( globalstring, sizeof( globalstring ), "{FF0000}|| GM || "SERVERBOJA_AQUA"|%d| %s {FFFFFF}se prijavio na server!", PlayerInfo[ playerid ][ xHelper ], ImeIgraca( playerid ) );
				RPTChat( 0x32CD32AA, globalstring );
			}
			// ne pin
			
			if( PlayerInfo[ playerid ][ xVoziloID ][ 0 ] != -1 ) {
			
				if(strcmp( VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 0 ] ][ vOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Vozilo 1 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xVoziloID ][ 0 ]=-1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xVoziloID ][ 1 ] != -1 ) {

				if(strcmp( VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 1 ] ][ vOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Vozilo 2 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xVoziloID ][ 1 ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xVoziloID ][ 2 ] != -1 ) {

				if(strcmp( VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 2 ] ][ vOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Vozilo 3 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xVoziloID ][ 2 ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xVoziloID ][ 3 ] != -1 ) {

				if(strcmp( VehicleInfo[ PlayerInfo[ playerid ][ xVoziloID ][ 3 ] ][ vOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Vozilo 4 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xVoziloID ][ 3 ] = -1;
					SavePlayer( playerid );
				}
			}
			
			if( PlayerInfo[ playerid ][ xProperty ][ 0 ] != -1 ) {

				if( strcmp( II[ PlayerInfo[ playerid ][ xProperty ][ 0 ] ][ iOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Imovina 1 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xProperty ][ 0 ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xProperty ][ 1 ] != -1 ) {

				if( strcmp( II[ PlayerInfo[ playerid ][ xProperty ][ 1 ] ][ iOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Imovina 2 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xProperty ][ 1 ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xProperty ][ 2 ] != -1 ) {

				if( strcmp( II[ PlayerInfo[ playerid ][ xProperty ][ 2 ] ][ iOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Imovina 3 vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xProperty ][ 2 ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xGarageID ] != -1 ) {

				if( strcmp( garageInfo[ PlayerInfo[ playerid ][ xGarageID ] ][ garageOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Garaza vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h." );
					PlayerInfo[ playerid ][ xGarageID ] = -1;
					SavePlayer( playerid );
				}
			}
			if( PlayerInfo[ playerid ][ xFirmaID ] != -1 ) {

				if( strcmp( BussinesInfo[ PlayerInfo[ playerid ][ xFirmaID ] ][ bOwner ], ImeIgraca( playerid ), true ) ) {

					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Firma vise nije u vasem vlasnistvu, obratite se na forumu ako mislite je greska." );
					SendClientMessagee( playerid, ANTICHEAT, "{FF0000}| AC |:"col_white" Jedan od razloga moze biti i vasa neaktivnost od 500h ili nedostatak faktura." );
					PlayerInfo[ playerid ][ xFirmaID ] = -1;
					SavePlayer( playerid );
				}
			}
		}
		PrviSpawn[ playerid ] = 0;
	}
	if( PlayerInfo[ playerid ][ xBStil ] == 0) { SetPlayerFightingStyle ( playerid, FIGHT_STYLE_NORMAL); }
	else if( PlayerInfo[ playerid ][ xBStil ] == 1) { SetPlayerFightingStyle ( playerid, FIGHT_STYLE_BOXING); }
	else if( PlayerInfo[ playerid ][ xBStil ] == 2) { SetPlayerFightingStyle ( playerid, FIGHT_STYLE_KUNGFU); }
	else if( PlayerInfo[ playerid ][ xBStil ] == 3) { SetPlayerFightingStyle ( playerid, FIGHT_STYLE_KNEEHEAD); }
	else if( PlayerInfo[ playerid ][ xBStil ] == 4) { SetPlayerFightingStyle ( playerid, FIGHT_STYLE_GRABKICK); }

	SetPlayerSkillLevel( playerid, WEAPONSKILL_DESERT_EAGLE, 999 );
	SetPlayerSkillLevel( playerid, WEAPONSKILL_MP5, 999 );
	SetPlayerSkillLevel( playerid, WEAPONSKILL_AK47, 999 );
	SetPlayerSkillLevel( playerid, WEAPONSKILL_M4, 999 );

	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_FREE );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_LHAND );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_HELMET );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_MASK );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_WINTERCAP );

	if( HeadOn[ playerid ] ) SetPlayerAttachedObject( playerid, OBJECT_SLOT_HEAD, PlayerInfo[ playerid ][ xHead ],2,PlayerInfo[ playerid ][ xHeadPos ][ 0 ],PlayerInfo[ playerid ][ xHeadPos ][ 1 ],PlayerInfo[ playerid ][ xHeadPos ][ 2 ],PlayerInfo[ playerid ][ xHeadPos ][ 3 ],PlayerInfo[ playerid ][ xHeadPos ][ 4 ],PlayerInfo[ playerid ][ xHeadPos ][ 5 ],PlayerInfo[ playerid ][ xHeadPos ][ 6 ],PlayerInfo[ playerid ][ xHeadPos ][ 7 ],PlayerInfo[ playerid ][ xHeadPos ][ 8 ], 0, 0);
	if( SungOn[ playerid ] ) {
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_MASKSUNGL, PlayerInfo[ playerid ][ xSungMask ],2,PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ],PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ], 0, 0);
	}
	if( FaceOn[ playerid ] ) SetPlayerAttachedObject( playerid, OBJECT_SLOT_BANDANA, PlayerInfo[ playerid ][ xFace ],2,PlayerInfo[ playerid ][ xFacePos ][ 0 ],PlayerInfo[ playerid ][ xFacePos ][ 1 ],PlayerInfo[ playerid ][ xFacePos ][ 2 ],PlayerInfo[ playerid ][ xFacePos ][ 3 ],PlayerInfo[ playerid ][ xFacePos ][ 4 ],PlayerInfo[ playerid ][ xFacePos ][ 5 ],PlayerInfo[ playerid ][ xFacePos ][ 6 ],PlayerInfo[ playerid ][ xFacePos ][ 7 ],PlayerInfo[ playerid ][ xFacePos ][ 8 ], 0, 0);
	
	PlayerCuffed[ playerid ] = 0; 
	PoliceDuty[ playerid ] = false;
	NosiObjekt[ playerid ][ 0 ] = false; 
	NosiObjekt[ playerid ][ 1 ] = false; 
	NosiObjekt[ playerid ][ 2 ] = false;
	UzeoPicu[ playerid ] = false;
	NosiPaketOruzja[ playerid ] = false; 
	garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
	farmerInfo[ playerid ][ fiHaveGajbica ] = false; 
	farmerInfo[ playerid ][ fiHaveFruits ] = false;
	farmerInfo[ playerid ][ fiHaveBucket ] = false; 
	RiotShield[ playerid ] = false;
	Dinamit[ playerid ] = false; 
	LaptopRuke[ playerid ] = false;
	PuniGorivo[ playerid ] = false; 
	IgracZavezan[ playerid ] = false;

	SetPlayerName( playerid, RealName[ playerid ] );
	Maskuse[ playerid ] = false;

	if( PlayerBuyingAS[ playerid ] != -1 ) 
	{
		AutoSalon[ PlayerBuyingAS[ playerid ] ][ AlreadyBuying ] = false;
		PlayerBuyingAS[ playerid ] = -1;
	}

	farmerInfo[ playerid ][ fiCowNumber ] = 0;
	farmerInfo[ playerid ][ fiFruitNumber ] = 0;
	farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 0;

	if( farmerInfo[ playerid ][ fiVehicleBucket ] != -1 )
	{
		new farmvehicle = farmerInfo[ playerid ][ fiVehicleBucket ];

		farmerVehicles[ farmvehicle ][ fvMilk ] = false;
		farmerVehicles[ farmvehicle ][ fvMilkpID ] = -1;
	}

	SetPlayerSkillLevel( playerid, WEAPONSKILL_PISTOL, 1 );
	SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 1 );

	SetPlayerSpecialAction( playerid, SPECIAL_ACTION_NONE );
	
	Dimi_KillTimer( atmrobTimer[ playerid ] );

	if( PlayerInfo[ playerid ][ xRPLearn ] == 1 )
	{
		TimerLearn[ playerid ] = SetTimerEx( "RolePlayTut", 3000, 0, "ii", playerid, 1);
		SendClientMessagee( playerid, SVETLOCRVENA, "Nisi zavrsio tutorijal, pa si ponovno vracen da ga odgledas!" );
	}

	if( PlayerInfo[ playerid ][ xZatvor ] == OBICAN_ZATVOR )
	{
		if( PlayerInfo[ playerid ][ xLeaveJail ] == true )
		{
			SendClientMessageEx( playerid, UGBOJA, "ZATVOR |"col_white" %s stavljen si u jail na %d minuta i izgubio si %d$!", ImeIgraca( playerid ), PlayerInfo[ playerid ][ xZatvorVreme ], ((PlayerInfo[ playerid ][ xZatvorVreme ]/10)*1000) );
			SendClientMessagee( playerid, UGBOJA, "JAIL:"col_white" Razlog: 'Izalazak sa servera sa Wanted Levelom'");
			PlayerInfo[ playerid ][ xLeaveJail ] = false;
		}
	}

	if( PlayerInfo[ playerid ][ xZatvor ] == OBICAN_ZATVOR )
	{
		if( strlen( PlayerInfo[ playerid ][ xOffPJail ] ) > 2 )
		{
			SendClientMessageEx( playerid, UGBOJA, "OFF ZATVOR |"col_white" Stavljen si u zatvor na %d minuta od strane Admina tima!", PlayerInfo[ playerid ][ xZatvorVreme ] );
			SendClientMessageEx( playerid, UGBOJA, "OFF ZATVOR |"col_white" Razlog: '%s'", PlayerInfo[ playerid ][ xOffPJail ] );
			strmid( PlayerInfo[ playerid ][ xOffPJail ], "N", 0, strlen("N"), 2 );
		}
	}
	if( PlayerInfo[ playerid ][ xMute ] > 0 )
	{
		if( strlen( PlayerInfo[ playerid ][ xOffPMute ] ) > 2 )
		{
			SendClientMessageEx( playerid, UGBOJA, "{FF0000}OFF MUTE |"col_white" Mutirani ste na %d minuta od strane Admin tima!", PlayerInfo[ playerid ][ xMute ]/60 );
			SendClientMessageEx( playerid, UGBOJA, "{FF0000}OFF MUTE |"col_white" Razlog: '%s'", PlayerInfo[ playerid ][ xOffPMute ] );
			strmid( PlayerInfo[ playerid ][ xOffPMute ], "N", 0, strlen("N"), 2 );
		}
	}
	if( PlayerInfo[ playerid ][ xZatvor ] == ALKATRAZ )//jese
	{
		if( strlen( PlayerInfo[ playerid ][ xOffPPrison ] ) > 2 )
		{
			SendClientMessageEx( playerid, -1, "{FF0000}OFF AREA |"col_white" Stavljeni ste u Areu od strane Admin tima na %d minuta!", PlayerInfo[ playerid ][ xZatvorVreme ]/60 );
			SendClientMessageEx( playerid, -1, "{FF0000}OFF AREA |"col_white" Razlog: '%s'", PlayerInfo[ playerid ][ xOffPPrison ] );
			strmid( PlayerInfo[ playerid ][ xOffPPrison ], "N", 0, strlen("N"), 2 );
		}
	}
	
	if( SpecPos[ playerid ][ 0 ] != 0.0 && SpecPos[ playerid ][ 1 ] != 0.0 )
	{
		Dimi_SetPlayerPos( playerid, SpecPos[ playerid ][ 0 ], SpecPos[ playerid ][ 1 ],  SpecPos[ playerid ][ 2 ] );
		SetPlayerVirtualWorld( playerid, SpecVW[ playerid ] );
		SetPlayerInterior( playerid, SpecInt[ playerid ] );
		
		if( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 1339 && PlayerInfo[ playerid ][ xPol ] == 1 ) {
			SetPlayerSkin( playerid, 294 );
		}
		else if( PlayerInfo[ playerid ][ xHelper ] > 0 && PlayerInfo[ playerid ][ xPol ] == 1 ) {
			SetPlayerSkin( playerid, 59 );
		}
		
		SpecPos[ playerid ][ 0 ] = 0.0;
		SpecPos[ playerid ][ 1 ] = 0.0;
		SpecPos[ playerid ][ 2 ] = 0.0;
	}

	LoginTDControl( playerid, false );
	if( PlayerInfo[playerid][xRanac] == 1 )
	{
		//SetPlayerAttachedObject( playerid, OBJECT_SLOT_BACKPACK, 3026/*3026*/, 1, -0.134207, -0.093048, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
		SetPlayerAttachedObject( playerid, OBJECT_SLOT_BACKPACK, 371, 1, 0.087999, -0.125000, -0.014000, 3.299999, 86.200019, -5.300003, 1.000000, 1.000000, 1.000000 );
	}

	#if defined script_init_taskkill
	hidedt(playerid);
	#endif

	hidektd(playerid);

	hidedmtd(playerid);
	if( NaDmEventu[ playerid ] == true )
	{
		showdmtd(playerid);
	}
	hidectd(playerid);
	return true;
}

spawnplayer(playerid); public spawnplayer(playerid)
{
	PlayerInfo[playerid][xDeathScreen] = 0;
	hidedt(playerid);

	if( WatchingTV{ playerid } == 1 )
	{
		WatchingTV{ playerid } = 0;

		TogglePlayerSpectating( playerid, 0 );
		TogglePlayerControllable( playerid, true );

		Spectate[ playerid ] = -1;
		PlayerPlaySound( playerid, 1145, 0.0, 0.0, 0.0);
								
	}
	SendInfoMessage(playerid,"Uspjesno vam je iskljucen death screen!");

	TogPlayerHud(playerid);
	
	//SpawnPlayer(playerid);
	return 1;
}


public OnPlayerDeath( playerid, killerid, reason )
{
	CallLocalFunction("ANIM_OnPlayerDeath", "iii",playerid,killerid, reason);
	if(NaZombieEventu[playerid])
	{
		CallLocalFunction("ZombieEvent_OnPlayerDeath", "i", playerid);
		return 1;
	}
	if(PlayerInfo[playerid][xPUBG] == 1)
	{
		PlayerInfo[playerid][xPUBG] = 0;
		PUBGenum[xIgraMatch]--;
		SendInfoMessage(playerid,"Umrli ste na PUBG matchu, bit cete spawnovani za 10s.");
		endmatch[playerid] = SetTimerEx("matchend", 10000, false, "ii", playerid, 0);
		PlayerSpectatePlayer(playerid,killerid);
		Dimi_SetPlayerHealth(playerid,0);
		hideinjuredtd(playerid);
		hidehb(playerid);
		Ranjen[playerid] = 0;
		PlayerInfo[killerid][xPUBGKills]++;
		PlayerInfo[killerid][xPUBGKillsTotal]++;
		SendScreenMessage(killerid, "~y~PUBG:~w~ Dobili ste 1 kill!");
		PubgEventTDControl(playerid, false);
		if(PlayerInfo[playerid][xPUBGKills] != 0)
		{
			new nagrada = PlayerInfo[playerid][xPUBGKills] * 500;
			DajIgracuNovac(playerid, nagrada);
			SendInfoMessage(playerid, "Dobili ste %i$ za %i kill-ova koje ste dobili.", nagrada,PlayerInfo[playerid][xPUBGKills]);
		}
		return 1;
	}
	if(gPlayerUsingLoopingAnim[playerid])
	{
		gPlayerUsingLoopingAnim[playerid] = 0;
	}
	//PlayerSpectatePlayer(playerid,killerid);
	//////////////////////////////////
	for( new w = 1; w < MAX_WARS; w ++) {
		if( killerid != INVALID_PLAYER_ID ) {
			if( WARInfo[ w ][ WARAktivan ] == true && WARPInfo[ playerid ][ WARIgrac ] == w && WARPInfo[ killerid ][ WARIgrac ] == w ) {
				WARPInfo[ killerid ][ WARUbistva ]++;
				WARPInfo[ playerid ][ WARSmrti ]++;
				new scm_string[ 128 ];
				if( WARPInfo[ playerid ][ WARTim ][ 0 ] == true && WARPInfo[ killerid ][ WARTim ][ 0 ] == true ) {
					WARInfo[ w ][ WARTimSkor ][ 0 ] -= 3;
					format( scm_string, sizeof( scm_string ), "(WAR) %s je ubio svog saigraca %s, te je njegov tim dobio -3 poena.", ImeIgraca( killerid ), ImeIgraca( playerid ) );
					WARPoruka( w, WARLJUB, scm_string );
					SetWarStatsTD( w );

					Dimi_SetPlayerHealth(playerid,0);
					hideinjuredtd(playerid);
					hidehb(playerid);
					Ranjen[playerid] = 0;
					KillTimer(DeathAfterInjury[playerid]);
				}
				if( WARPInfo[ playerid ][ WARTim ][ 1 ] == true && WARPInfo[ killerid ][ WARTim ][ 1 ] == true ) {
					WARInfo[ w ][ WARTimSkor ][ 1 ] -= 3;
					format( scm_string, sizeof( scm_string ), "(WAR) %s je ubio svog saigraca %s, te je njegov tim dobio -3 poena.", ImeIgraca( killerid ), ImeIgraca( playerid ) );
					WARPoruka( w, WARLJUB, scm_string);
					SetWarStatsTD( w );

					Dimi_SetPlayerHealth(playerid,0);
					hideinjuredtd(playerid);
					hidehb(playerid);
					Ranjen[playerid] = 0;
					KillTimer(DeathAfterInjury[playerid]);
				}
				if( WARPInfo[ killerid ][ WARTim ][ 0 ] == true && WARPInfo[ playerid ][ WARTim ][ 1 ] == true ) {
					WARInfo[ w ][ WARTimSkor ][ 0 ]++;
					format( scm_string, sizeof( scm_string ),"(WAR) %s je ubio protivnika %s!", ImeIgraca( killerid ), ImeIgraca( playerid ) );
					WARPoruka( w, WARLJUB, scm_string );
					SetWarStatsTD( w );

					Dimi_SetPlayerHealth(playerid,0);
					hideinjuredtd(playerid);
					hidehb(playerid);
					Ranjen[playerid] = 0;
					KillTimer(DeathAfterInjury[playerid]);
				}
				if( WARPInfo[ killerid ][ WARTim ][ 1 ] == true && WARPInfo[ playerid ][ WARTim ][ 0 ] == true ) {
					WARInfo[ w ][ WARTimSkor ][ 1 ]++;
					format( scm_string, sizeof( scm_string ),"(WAR) %s je ubio protivnika %s!", ImeIgraca( killerid ), ImeIgraca( playerid ) );
					WARPoruka( w, WARLJUB, scm_string );
					SetWarStatsTD( w );

					Dimi_SetPlayerHealth(playerid,0);
					hideinjuredtd(playerid);
					hidehb(playerid);
					Ranjen[playerid] = 0;
					KillTimer(DeathAfterInjury[playerid]);
				}
				return 1;
			}
		}
	}
	PlayerInfo[ playerid ][ xSpawned ] = 0;

	
	if( NaDmEventu[ playerid ] == true ) {
		new scm_string[ 128 ];
		if( killerid != INVALID_PLAYER_ID && NaDmEventu[ killerid ] == true ) { 
			PlayerInfo[ killerid ][ xDMEventUbistva ]++;
			format( scm_string, sizeof( scm_string ),"(DM Zona) %s je ubio %s!", ImeIgraca( killerid ), ImeIgraca( playerid ) );
			DMZPoruka( WARLJUB, scm_string );

			Dimi_SetPlayerHealth(playerid,0);
			hideinjuredtd(playerid);
			hidehb(playerid);
			Ranjen[playerid] = 0;
			KillTimer(DeathAfterInjury[playerid]);
		}
		return 1;
	}

	if( NaZombieEventu[ playerid ] == true ) 
	{
		if( killerid == INVALID_PLAYER_ID && NaZombieEventu[ killerid ] == true ) 
		{
			SendInfoMessage(playerid,"Ubijeni ste!");
			Dimi_SetPlayerHealth(playerid,0);
			hideinjuredtd(playerid);
			hidehb(playerid);
			Ranjen[playerid] = 0;
			KillTimer(DeathAfterInjury[playerid]);
		}
		return 1;
	}
	
	if( PlayerInBlowJob[ playerid ] != 0 ) {

		switch( PlayerInBlowJob[ playerid ] ) {

			case 1: {

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
	
	antiCheatCS[ playerid ][ TeleportCheck ] = 2;
	antiCheatCS[ playerid ][ WeaponDetect ] = 2;
	
	Dimi_KillTimer( fishermanInfo[ playerid ][ fsTimer ] );
	
	if( SearchNadji[ playerid ] != -1 ) {
	
		SearchNadji[ playerid ] = -1;
		Dimi_DisablePlayerCheckpoint( playerid );
	}
	#if kladionica == 1
	if( ListaPrikazana[ playerid ] ) {
		KladionicaTDControl( playerid, false );
	}
	if( MojListicPrikazan[ playerid ] ) {
		KladionicaListicTDControl( playerid, false );
	}
	if( RezultatiPrikazana[ playerid ] ) {
		RezultatiTDControl( playerid, false );
	}
	#endif
	if( ( gettime( ) - FakeKillTime[ playerid ] ) < 5 ) {

		FakeKillPlus[ playerid ]++;
		if( FakeKillPlus[ playerid ] >= 3 ) {
			
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Fake kill", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Fake kill");
		}
		FakeKillTime[ playerid ] = gettime( );
		return 0;
	}

	FakeKillTime[ playerid ] = gettime( );
	
	
	if( gZone_ID[ playerid ] != -1 ) {

		new gZone__ID = gZone_ID[ playerid ];

		GangZoneStopFlashForAll( gZoneInfo[ gZone__ID ][ gZoneID ] );
		gZone_Time[ playerid ] = 0;
		Dimi_KillTimer( gZone_Timer[ playerid ] );


		if( gZoneInfo[ gZone__ID ][ gZoneGangID ] != -1 ) {

			format( globalstring, sizeof( globalstring ), "[TERITORIJA] Clan suparnicke bande %s koji je zauzimao teritoriju je ubijen.", OI[ PlayerInfo[ playerid ][ xClan ] ][ oName ] );
			OrgPoruka( gZoneInfo[ gZone__ID ][ gZoneGangID ], 0x95b4a2FF, globalstring );
		}

		format( globalstring, sizeof( globalstring ), "[TERITORIJA] Clan %s je ubijen te je prestao sa zauzimanjem.", ImeIgraca( playerid ) );
		OrgPoruka( PlayerInfo[ playerid ][ xClan ], 0x95b4a2FF, globalstring );

		gZone_ID[ playerid ] = -1;

	}
	
	if( zauzimanje_firme_ID[ playerid ] != -1 ) {

		new bussinesID = zauzimanje_firme_ID[ playerid ];

		zauzimanje_firme_Vreme[ playerid ] = 0;
		Dimi_KillTimer( zauzimanje_firme_Timer[ playerid ] );

		format( globalstring, sizeof( globalstring ), "[ZAUZIMANJE] Clan %s je ubijen te je prestao sa zauzimanjem firme.", ImeIgraca( playerid ) );
		OrgPoruka( PlayerInfo[ playerid ][ xClan ], 0x95b4a2FF, globalstring );

		BussinesInfo[ bussinesID ][ bReket ] = -1;

		BussinesInfo[ bussinesID ][ bReketTime ] = 0;

		SaveBussines( bussinesID );
		Bussines_Refresh( bussinesID );

		zauzimanje_firme_ID[ playerid ] = -1;

	}
	
	
	if( PlayerCement[ playerid ] != -1 ) VehCement[ PlayerCement[ playerid ] ] = false;
	
	if( DeliverCar[ playerid ] != -1 ) KamionUsed[ DeliverCar[ playerid ] ] = -1, StateBox[ DeliverCar[ playerid ] ] = 0;
	
	if(IDBusaKojiVozi[ playerid ] != -1) IDIgracaKojiVoziBus[ IDBusaKojiVozi[ playerid ] ] = -1;
	
	if( IDVozilaKojimSverca[ playerid ] != -1 ) KutijaMatsa[ IDVozilaKojimSverca[ playerid ] ] = false;
	
	if( PlayerPrevozNovca[ playerid ] != -1 ) VehNovac[ PlayerPrevozNovca[ playerid ] ] = false;

	if( PlayerInfo[ playerid ][ xHitmenCena ] > 0 ) {
		if( IsPlayerConnected( killerid ) ) {
			if( OI[ PlayerInfo[ killerid ][ xClan ] ][ oTip ] == ORG_TIP_HITM ) {
				if( HitmanInfo[ killerid ][ GoChase ] == playerid ) {
					DajIgracuNovac( killerid, PlayerInfo[ playerid ][ xHitmenCena ] );
					for( new id = 1; id < MAX_ORG; id++) {
						if( OI[ id ][ oTip ] == ORG_TIP_HITM ) {
							format( globalstring, sizeof( globalstring ), "Agent %s je izvrsio svoju narudzbu %s i zaradio $%d", ImeIgraca( killerid ), ImeIgraca( playerid ), PlayerInfo[ playerid ][ xHitmenCena ] );
							OrgPoruka( id, ZUTA, globalstring );
						}
					}
					format( globalstring, sizeof( globalstring ), "|Hitman| %s je ubio: %s", ImeIgraca( killerid ), ImeIgraca( playerid ) );
					AdminPoruka( 0x83BFBFAA, globalstring );
					PlayerInfo[ playerid ][ xHitmenCena ] = 0;
					HitmanInfo[ killerid ][ GoChase ] = 999;
					HitmanInfo[ playerid ][ GetChased ] = 999;
					HitmanInfo[ playerid ][ GotHit ] = 0;
				}
			}
		}
	}

	if( PlayerInfo[ playerid ][ xLevel ] >= 5 && NaDmEventu[ playerid ] == false && WARPInfo[ playerid ][ WARIgrac ] == -1 && GetFactionType( playerid ) != ORG_TIP_PD ) {
		new Float:pPosX, Float:pPosY, Float:pPosZ;
		GetPlayerPos( playerid, pPosX, pPosY, pPosZ );
		new weaponsa[ 13 ][ 2 ];
		for( new i_slot = 0; i_slot < 13; i_slot++ ) {
			GetPlayerWeaponData( playerid, i_slot, weaponsa[ i_slot ][ 0 ], weaponsa[ i_slot ][ 1 ] );
			if( weaponsa[ i_slot ][ 0 ] != 0 && weaponsa[ i_slot ][ 1 ] != 0 ) CreateDroppedGun( weaponsa[ i_slot ][ 0 ], weaponsa[ i_slot ][ 1 ], pPosX+random(2)-random(2), pPosY+random(2)-random(2), pPosZ );
		}
	}
	
	SetPVarInt( playerid, "OfficerUndercover", 0 );
	ElectricOprema[ playerid ] = false;

	if( PljackaNovac[ playerid ] > 0 ) {
		PljackaNovac[ playerid ] = 0;
		VremeZaNovac[ playerid ] = 0;
		PljackaVreme[ playerid ] = 0;
		SendClientMessagee( playerid, -1, "{005B88}|| Pljacka || {FFFFFF}Niste prezivjeli 2 minuta i vasa pljacka je neuspjesna!" );
	}

	if( PljackaVreme[ playerid ] > 0 ) Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] ), PljackaUToku = false;
	
	if( PljackaZlato[ playerid ] > 0 ) {
		PljackaZlato[ playerid ] = 0;
		VremeZaZlato[ playerid ] = 0;
		ZlatoVreme[ playerid ] = 0;
		SendClientMessagee( playerid, -1, "{005B88}|| Pljacka || {FFFFFF}Niste prezivjeli 2 minuta i vasa pljacka je neuspjesna!" );
	}

	if( ZlatoVreme[ playerid ] > 0 ) Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] ), ZlataraUToku = false;
	
	if( farmerInfo[ playerid ][ fiVehicleBucket ] != -1 ) {
		new farmvehicle = farmerInfo[ playerid ][ fiVehicleBucket ];

		farmerVehicles[ farmvehicle ][ fvMilk ] = false;
		farmerVehicles[ farmvehicle ][ fvMilkpID ] = -1;
	}
	
	if( killerid == IPI ) {
	
		if( PlayerInfo[ playerid ][ xWanted ] > 0 && PlayerInfo[ playerid ][ xZatvor ] == 0 ) {
		
			new price = PlayerInfo[ playerid ][ xWanted ] * 1000;
			SendClientMessageEx( playerid, SVETLOCRVENA, "Gubite %d$ jer ste izvrsili samoubistvo dok sa %d wl ste bezali od policije.", price, PlayerInfo[ playerid ][ xWanted ] );
		
			DajIgracuNovac( playerid, -price );
		
			PlayerInfo[ playerid ][ xWanted ] = 0;
			Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
			strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
			SavePlayer( playerid );

			for( new id = 1; id < MAX_ORG; id++) {
				if( OI[ id ][ oTip ] == ORG_TIP_PD ) {
					format( globalstring,sizeof( globalstring ),"HQ: Osumniceni %s je izvrsio samoubistvo i izgubio %d$, prijem...", ImeIgraca( playerid ), price );
					OrgPoruka( id, 0x2641FEAA, globalstring );
				}
			}
		}
	}
	
	if( killerid != INVALID_PLAYER_ID && GetPlayerState( killerid ) == PLAYER_STATE_DRIVER ) {
	
		format( globalstring, sizeof( globalstring ), "DRIVE BY | [%d] %s je ubio %s [%d]!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
		AdminPoruka( 0xFFE65AAA, globalstring );
	}
	
	if( ( reason >= 0 && reason <= 34 ) || reason == 49 ) {
		
		if( killerid != INVALID_PLAYER_ID && GetFactionType( killerid ) != ORG_TIP_PD ) {

			if( PlayerInfo[ killerid ][ xZatvor ] != 0 ) {
			
				SendClientMessagee( killerid, SVETLOCRVENA, "ZATVOR | Ubili ste igraca u zatvoru i dobili 10 minuta dodatne kazne!");
				PlayerInfo[ killerid ][ xZatvorVreme ] += 10;
			}
			else {
				PostaviWanted( killerid, "Ubistvo prvog stepena", "Nepoznati", 5 );
			}

			if( PlayerInfo[ playerid ][ xLevel ] == 1 ) {
			
				format( globalstring, sizeof( globalstring ), "[id %d] %s je ubio NOVAJLIJU %s [id %d]!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
				AdminPoruka( 0xFFE65AAA, globalstring );
			}
			else if( PlayerInfo[ playerid ][ xClan ] == 0 ) {

				format( globalstring, sizeof( globalstring ), "[id %d] %s je ubio CIVILA %s [id %d]!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
				AdminPoruka( 0xFFE65AAA, globalstring );
			}
			else {
				format( globalstring, sizeof( globalstring ), "[id %d] %s je ubio igraca %s [id %d]!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
				AdminPoruka( 0xFFE65AAA, globalstring );
			}
		}
		else if( killerid != INVALID_PLAYER_ID && GetFactionType( killerid ) == ORG_TIP_PD ) {
		
			if( PlayerInfo[ playerid ][ xWanted ] >= 1 ) {
			
				new price = PlayerInfo[ playerid ][ xWanted ] * 500;
				new price1 = PlayerInfo[ playerid ][ xWanted ] * 200;
				
				announcement( killerid, "~w~Osumnjiceni ~r~ubijen!", 5000, 1 );
				PlayerPlaySound( killerid, 1058, 0.0, 0.0, 0.0 );

				DajIgracuNovac( playerid, -price );
				DajIgracuNovac( killerid, price1 );
				SendClientMessageEx( killerid, SVETLOCRVENA, "BS: Dobili ste %d$ jer ste ubili osumnicenog koji je imao %d Wanted levela.", price1, PlayerInfo[ playerid ][ xWanted ] );
				SendClientMessageEx( playerid, SVETLOCRVENA, "BS: Gubite %d$ jer ste bezali od policije a policajac vas je ubio.", price );

				for( new id = 1; id < MAX_ORG; id++) {
					if( OI[ id ][ oTip ] == ORG_TIP_PD ) {
						format( globalstring,sizeof( globalstring ),"HQ: Officer %s je ubio osumnicenog %s(-%d$), prijem...", ImeIgraca( killerid ), ImeIgraca( playerid ), price );
						OrgPoruka( id, 0x2641FEAA, globalstring );
					}
				}

				PlayerInfo[ playerid ][ xWanted ] = 0;
				Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
				strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
				strmid( ZlocinInfo[ playerid ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
				strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
				SavePlayer( playerid );
				
				format( globalstring, sizeof( globalstring ), "PD/SAJ/CIA | [%d] %s je ubio igraca %s [%d] sa WL!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
				AdminPoruka( 0xFFE65AAA, globalstring );
			}
			else if( PlayerInfo[ playerid ][ xWanted ] <= 0 ) {
			
				format( globalstring, sizeof( globalstring ), "PD/SAJ | [%d] %s je ubio igraca %s [%d] bez WL!", killerid, ImeIgraca( killerid ), ImeIgraca( playerid ), playerid );
				AdminPoruka( 0xFFE65AAA, globalstring );
				
				if( PlayerInfo[ playerid ][ xLevel ] == 1 ) {
					AdminPoruka( 0xFFE65AAA, "PD/SAJ | UBIJENI IGRAC JE NOVAJLIJA" );
				}
				else if( PlayerInfo[ playerid ][ xClan ] == 0 ) {
					AdminPoruka( 0xFFE65AAA, "PD/SAJ | UBIJENI IGRAC JE CIVIL" );
				}
			}
		}
	}
	//wtf
	if( PlayerInfo[ playerid ][ xZatvor ] == 0 /*&& PlayerInfo[ playerid ][ xAdmin ] == 0*/ ) PlayerInfo[ playerid ][ xUbijen ] = 1;
	
	if( PlayerInfo[ playerid ][ xWanted ] >= 1 ) {
		new price = PlayerInfo[ playerid ][ xWanted ] * 500;
		DajIgracuNovac( playerid, -price );
		SendClientMessageEx( playerid, ZUTA, "Umrli ste sa wanted levelom i oduzeto vam je %d$.", price );
		PlayerInfo[ playerid ][ xWanted ] = 0;
	}

	if( Maskuse[ playerid ] == true ) {
		Inventory_Remove( playerid, "Maska" );
		Maskuse[ playerid ] = false;
		SetPlayerName( playerid, RealName[ playerid ] );
	}

	if( Draged[ playerid ] != -1 ) {
		Dimi_KillTimer( DragTimer[ Draged[ playerid ] ] );
		DragedPlayerID[ Draged[ playerid ] ] = -1;
		Draged[ playerid ] = -1;
	}
	if( DragedPlayerID[ playerid ] != -1) {
		Dimi_KillTimer( DragTimer[ playerid ] );
		DragedPlayerID[ playerid ] = -1;
		Draged[ DragedPlayerID[ playerid ] ] = -1;
	}

	if( IsValidDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] ) ) {
		DestroyDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] );
	}

	if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] ) ) {
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
	}

	if( IsValidDynamicCP( PlayerGpsRadar[ playerid ][ _pgrCheckPointId ] ) ) {
		DestroyDynamicCP( PlayerGpsRadar[ playerid ][ _pgrCheckPointId ] );
	}
	
	Dimi_KillTimer( atmrobTimer[ playerid ] );
	
	PlayerGpsRadar[ playerid ][ _pgrIconId ] = -1;
	PlayerGpsRadar[ playerid ][ _pgrObject ] = -1;
	PlayerTextDrawHide(playerid, PlayerGpsRadarText[ playerid ] );

	if( PlayerBuyingAS[ playerid ] != -1 ) {
		AutoSalon[ PlayerBuyingAS[ playerid ] ][ AlreadyBuying ] = false;
		PlayerBuyingAS[ playerid ] = -1;
	}

	if( antiCheatCS[ playerid ][ TakeVehicle ] != INVALID_VEHICLE_ID ) {
		BusyVehicle[ antiCheatCS[ playerid ][ TakeVehicle ] ] = -1;
	}

	if( CistacPosao[ playerid ] == true ) {
		PlayerInfo[ playerid ][ xPlatniRacun ] += cistacnovac[ playerid ];
		SavePlayer( playerid ); UpdatePlataTD( playerid );
		
		#if NERP_ZIMSKI_MOD  == 1
		SendJobMessage( playerid, "Zaradio si "col_white"%d$ "col_job" za predjenih %dkm kao cistac snega.", cistacnovac[ playerid ], cistackilometri[ playerid ] );
		#else
		SendJobMessage( playerid, "Zaradio si "col_white"%d$ "col_job" za predjenih %dkm kao cistac ulica.", cistacnovac[ playerid ], cistackilometri[ playerid ] );
		#endif

		SetVehicleToRespawn( cistacvozilo[ playerid ] );
		BussinesJobMoney( POSAO_KOMUNALAC, cistacnovac[ playerid ]/10 );
		cistacvozilo[ playerid ] = -1;
		CistacPosao[ playerid ] = false;
		cistackilometri[ playerid ] = 0;
		cistacmetri[ playerid ] = 0;
		cistacnovac[ playerid ] = 0;
		CistacWarning[ playerid ] = 0;
		Dimi_KillTimer( CistacTimer[ playerid ] );
		CKilometriTDControl( playerid, false );
	}
	
	if( garbagemanInfo[ playerid ][ gmiJob ] == true ) {
	
		new vehicleid = garbagemanInfo[ playerid ][ gmiVehicleID ];
	
		Dimi_DisablePlayerCheckpoint( playerid );
		CheckpointStatus[ playerid ] = 0;
		garbagemanInfo[ playerid ][ gmiDuty ] = false;
		garbagemanInfo[ playerid ][ gmiReadyToDump ] = false;
		garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
		garbagemanInfo[ playerid ][ gmiJob ] = false;
		garbagemanInfo[ playerid ][ gmiContainerID ] = 0;
		garbagemanInfo[ playerid ][ gmiVehicleID ] = -1;
		AktivanKontejner[ playerid ] = -1;
		RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
		DestroyPlayerObject(playerid, smeceobject1[playerid]);

		garbagemanVehicles[ vehicleid ][ gGarbages ] = 0;
		garbagemanVehicles[ vehicleid ][ gPlayerID ] = -1;
		isprazniovreca[playerid] = 0;
		zasmeceobject1[playerid] = 0;

		SetVehicleToRespawn( vehicleid );
		TogglePlayerControllable( playerid, true);
		SendJobMessage( playerid, "Zavrsili ste sa poslom, vase vozilo je respavnovano!");
	}

	if( KupujeNamestaj[ playerid ] == 1 )
	{
		nekokupujenamestaj = 0;
		KupujeNamestaj[ playerid ] = 0;
	}

	if( Uciskolu[ playerid ] == true ) { Dimi_KillTimer( SkolaTimer[ playerid ] ); }

	InAmbu[ playerid ] = -1;

	if( TrashSearch[ playerid ] == 1 )  { Dimi_KillTimer( TrashTimer[ playerid ] ); TrashSearch[ playerid ] = 0; }

	if(GetPVarInt( playerid, "CuffTimerCalled") == 1 )
	{
		Dimi_KillTimer( TazerTimer[ playerid ] );
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

	if( taxiDuty[ playerid ] == true )
	{//vodje
		TaximetarUkljucen[ playerid ] = false;

		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 0 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 1 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 2 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 3 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 4 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 5 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 6 ] );
		PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 7 ] );

		CenaVoznje[ playerid ] = 0;
		VoziIgracaID[ playerid ] = INVALID_PLAYER_ID;
		offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
	}


	new caller = GetPVarInt( playerid, "Mobile" );

	if( caller != -1 )
	{
		if( caller < 500 )
		{
			SendClientMessagee( caller,  0xBFC0C2FF, "   Linija prekinuta....");
			SetPVarInt( caller, "CellTime", 0 );
			SetPVarInt( playerid, "CellTime", 0 );
			SetPVarInt( caller, "Mobile", -1 );
		}
		SetPVarInt( playerid, "Mobile", -1 );
		SetPVarInt( playerid, "CellTime", 0 );
	}

	UzeoOpremu[ playerid ] = false;
	if( AdminDuty[ playerid ] ) {
		AdminDuty[ playerid ] = false;
	}
	if( PDuty[playerid] ) {
		PDuty[playerid] = false;
	}
	//======| MRTVO TIJELO SISTEM |=======
	for( new i = 1; i < MAX_BODIES; i++ ) {
		new Float:angle;
		new fileauta[ 40 ];
		new deadbodyid = i;
		//new ko = i;
		format(fileauta, sizeof( fileauta ), BODY_FILE, i);
		if( !fexist( fileauta ) ) {
			new Float:x, Float:y, Float:z;
			GetPlayerFacingAngle(playerid,angle);
			GetPlayerPos( playerid, x, y, z);
			bodyInfo[ i ][ bodyObjPos ][ 0 ] = x;
			bodyInfo[ i ][ bodyObjPos ][ 1 ] = y;
			bodyInfo[ i ][ bodyObjPos ][ 2 ] = z;
			bodyInfo[ i ][ bodyObjID ] = CreateDynamicObject( 3092, x, y, z, 93.7, 120.0, random(360) );
			
			new ko = i;
			
			new deadbody_text_label[500];
			//format(deadbody_text_label,sizeof(deadbody_text_label),
				//""col_balkanstory"|| DEATHPOINT IGRACA - Mrtvo tijelo: %d ||\n\n{
				//FFFFFF}Ovo telo je sveze!\nIme mrtvog igraca: "col_balkansto
				//ry"%s\n(("SERVERBOJA_SIVA" Ovaj igrac je ubijen - ovo je njego
				//vo mrtvo tijelo,\nda prijavite zlocin, pozovite policiju!"col
				//_balkanstory" ))\n\n|| Admin nivo 1337+ moze ocistiti tijela na serveru
				//, komanda: /ddt,\nukoliko radite poslovnu misiju grobar, kucajte: /pokupitelo ||",ko,ImeIgraca(playerid));
			format(deadbody_text_label,sizeof(deadbody_text_label),
				""col_balkanstory"[MRTVO TELO >> ID - %i]\n\n{ffffff}Ovo telo je sveze!\nIme mrtvog igraca:"col_balkanstory"%s\n\n{ffffff}[ /ddt, /pokupitelo ]",ko,ImeIgraca(playerid));
			bodyInfo[deadbodyid][bodyText3D] = CreateDynamic3DTextLabel( deadbody_text_label, -1, bodyInfo[ i ][bodyObjPos][0], bodyInfo[ i ][bodyObjPos][1], bodyInfo[ i ][bodyObjPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
			Streamer_Update( playerid );
			//PlayerEditObject( playerid, atmInfo[ i ][ atmObject ] ); EditATM[ playerid ] = i;
			SacuvajMrtvoTelo( i );
			break;
		}
	}
	//===================================*/
	if( PlayerInfo[playerid][xPokupioAuto] == 1 )
	{
		announcement( playerid, "~w~Misija ~y~'Dostava Vozila' ~w~neuspjesna!", 3000, 5 );
		SendInfoMessage(playerid,"Misija neuspjesna - oduzeto Vam je 100$.");
		DajIgracuNovac(playerid,-100);
		
		Dimi_DestroyVehicle( AdminVozilo[ playerid ] );
		AdminVozilo[ playerid ] = -1;
		ServerInfo[ VoziloDostavljeno ] = false;
		
		for(new i; i < MAX_PLAYERS; i++) {
			notfi(i,"Dojava","Covjek koji je preuzeo vozilo je poginuo u saobracaju!");
			notfi(i,"Dojava","Vozilo ce biti ponovno dostavljeno na tajnu lokaciju!");
		}
		
		PlayerInfo[playerid][xPokupioAuto] = 0;
	}
	else if( PlayerInfo[playerid][xPokupioAuto] != 1 ) {
		//announcement(playerid,"~y~WASTED...",5000,5);
		SendInfoMessage(playerid,"Umrli ste!");
	}
	PlayerSpectatePlayer(playerid,killerid);
	return true;
}

////////////////////


public OnVehicleSpawn( vehicleid )
{

	antiCheatVS[ vehicleid ][ VehTrueHealth ] = 1000;
	antiCheatVS[ vehicleid ][ VehCheck ] = 1;
	new engine, lights, alarm, doors, bonnet, boot, objective;

	if( ScriptIDVozila[ vehicleid ] != -1 ) SetVehicleLabels( ScriptIDVozila[ vehicleid ] );

	new Float:x,Float:y,Float:z;
	GetVehiclePos( vehicleid, x, y, z );
	RealVehiclePositions[ vehicleid ][ 0 ] = x;
	RealVehiclePositions[ vehicleid ][ 1 ] = y;
	RealVehiclePositions[ vehicleid ][ 2 ] = z;

	GetVehicleParamsEx( vehicleid, engine, lights, alarm, doors, bonnet, boot, objective );
	SetVehicleParamsEx( vehicleid, engine, 0, alarm, 0, 0, 0, objective );
	SetVehicleLabels( vehicleid );

	if( TipVozila[ vehicleid ] == PRIVATNO_VOZILO || TipVozila[ vehicleid ] == NAPRODAJU_VOZILO  )
	{
		GetVehicleParamsEx( vehicleid, engine, lights, alarm, doors, bonnet, boot, objective );
		SetVehicleParamsEx( vehicleid, engine, 0, alarm, VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ vLocked ], 0, 0, objective );

		LinkVehicleToInterior( vehicleid, VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ vInterior ] );
		SetVehicleVirtualWorld( vehicleid, VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ vVirtualWorld ] );
	}

	TuneVehicle( ScriptIDVozila[ vehicleid ] );

	vCanDrive[ vehicleid ] = 1;
	VehicleObjectCheck( vehicleid );
	ResetVehicleStatistics( vehicleid );
	if( IsVehicleBajs( vehicleid ) ) {
		GetVehicleParamsEx( vehicleid, engine, lights, alarm, doors, bonnet, boot, objective );
		SetVehicleParamsEx( vehicleid, 1, 0, alarm, doors, 0, 0, objective );
	}
	
	
	
	#if NERP_ZIMSKI_MOD  == 1
	if( PosaoVozila[ vehicleid ] == POSAO_KOMUNALAC && GetVehicleModel( vehicleid ) == 455 ) {

		SnowObjects[ vehicleid ] = true;

		SnowObject1[ vehicleid ] = CreateDynamicObject( 19601, 0, 0, 1500, 0, 0, 0 );
		AttachDynamicObjectToVehicle( SnowObject1[ vehicleid ], vehicleid, 0.000000, 4.200001, -1.049999, 13.500000, 0.000000, 180.000 );

		SnowObject2[ vehicleid ] = CreateDynamicObject( 18646, 0, 0, 1500, 0, 0, 0 );
		AttachDynamicObjectToVehicle( SnowObject2[ vehicleid ], vehicleid, 0.749999, 1.575000, 1.725000, 0.000000, 0.000000, 0.000000 );

	}
	#endif
	return true;
}

public OnVehicleDeath( vehicleid, killerid ) {
	//new ownerid = gLastDriver[ vehicleid ];
	VehicleObjectCheck( vehicleid );
	ResetVehicleStatistics( vehicleid );
	return true;
}

public OnPlayerText( playerid, text[] )
{
	new tmp[ 128 ];
	if(PlayerInfo[playerid][xDeathScreen] == 1)
	{
		greska(playerid,"Ne mozes pricati dok ti je ukljucen death screen!");
		return 0;
	}
	if( PlayerInfo[ playerid ][ xMute ] != 0 )
	{
		GRESKA( playerid, "Ne mozete pricati, usutkani ste.");
		return 0;
	}
	if( PlayerCuffed[ playerid ] >= 1 )
	{
		GRESKA( playerid, "Ne mozes pricati kad si cuffovan ili tazovan.");
		return 0;
	}
	if( PlayerInfo[ playerid ][ xAdmin ] < 1 && PlayerInfo[ playerid ][ xHelper ] < 1 )
	{
		if( antiCheatCS[ playerid ][ SpamChat ] > 0)
		 {
			SendClientMessagee( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Ne mozes spamati komande svakih 2 sec!");
			return 0;
		}
		antiCheatCS[ playerid ][ SpamChat ] += 2;
	}

	if( reactionTest )
	{
		if( strlen( reactionMessage[ 0 ] ) )
		{
			if( !strcmp( text, reactionMessage[ 0 ], false ) )
			{
				EndReaction( playerid );
				return 0;
			}
		}
	}
	else
	{

		if( !strcmp(text, reactionMessage[ 0 ], false ) && reactionWon )
		{

			if( !strcmp( reactionWinner, ImeIgraca( playerid ), false ) ) return GRESKA( playerid, "Vec ste reagovali sacekajte sljedecu reakciju!");
			else return SendInfoMessage( playerid, "Igrac %s je reaogovao vec!", reactionWinner);
			//SendClientMessage( playerid, -1, reactionMessage[ 1 ] );
			//return 0;
		}
	}
	
	for( new b = 0; b < sizeof( ZabranjeneReci ); b++)
	{
		if( strfind( text, ZabranjeneReci[ b ], true ) != -1 )
		{

			new string[ 128 ];
			if( IsPlayerInAnyVehicle( playerid ) && !IsACabrio( GetVehicleModel( GetPlayerVehicleID( playerid ) ) ) )
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}Maska_%d kaze (vozilo): *******", PlayerInfo[ playerid ][ xMaskID ] );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}%s kaze (vozilo): *******", ImeIgraca( playerid ) );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );

				new string1[ 128 ];
				format( string1, sizeof( string1 ), "Igrac %s: %s", ImeIgraca( playerid ), text );
				LogSave( "Ostalo/LogICChat.log", string1 );
			}
			else
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}Maska_%d kaze: *******", PlayerInfo[ playerid ][ xMaskID ] );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}%s kaze: *******", ImeIgraca( playerid ) );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );

				new string1[ 128 ];
				format( string1, sizeof( string1 ), "Igrac %s: %s", ImeIgraca( playerid ), text );
				LogSave( "Ostalo/LogICChat.log", string1 );
			}

			format( globalstring, sizeof( globalstring ), "[!]%s[%d]: %s", ImeIgraca( playerid ), playerid, text );
			AdminPoruka( 0x808000AA, globalstring );
			return 0;
		}
	}
	
	if( GetPVarInt( playerid, "TalkingLive" ) != 255 )
	{
		if( GetFactionType( playerid ) == ORG_TIP_CNN )
		{
			format( globalstring, sizeof( globalstring ), "{3399FF}| LIVE |:Reporter (Uzivo) %s: "col_white"%s", ImeIgraca( playerid ), text );
			OOCNews( 0xE79E03AA, globalstring );
		}
		else
		{
			format( globalstring, sizeof( globalstring ), "{3399FF}| LIVE |:Gost (Uzivo) %s: "col_white"%s", ImeIgraca( playerid ), text );
			OOCNews( 0xE79E03AA, globalstring );
		}
		return 0;
	}
	if( MarriageCeremoney{ playerid } > 0 )
	{
		new idx;
		tmp = strtok( text, idx );
		if( ( strcmp( "da", tmp, true, strlen( tmp ) ) == 0) && ( strlen( tmp ) == strlen( "da" ) ) )
		{
			if( GotProposedBy[ playerid ] < 999 )
			{
				if( IsPlayerConnected( GotProposedBy[ playerid ] ) )
				{
					format( globalstring, sizeof( globalstring ), "Maticar: %s da li vi uzimate %s za vasu voljenu zenu? (Ukoliko zelite to ukucajte 'da').", ImeIgraca( GotProposedBy[ playerid ] ), ImeIgraca( playerid ) );
					SendClientMessagee( GotProposedBy[ playerid ], BELA, globalstring );
					MarriageCeremoney{ GotProposedBy[ playerid ] } = 1;
					MarriageCeremoney{ playerid } = 0;
					GotProposedBy[ playerid ] = 999;
					return 0;
				}
				else
				{
					MarriageCeremoney{ playerid } = 0;
					GotProposedBy[ playerid ] = 999;
					return 0;
				}
			}
			else if( ProposedTo[ playerid ] < 999 )
			{
				if( IsPlayerConnected( ProposedTo[ playerid ] ) )
				{
					format( globalstring, sizeof( globalstring ), "Maticar: %s i %s proglasavam vas za...Muza i Zenu, Mozete poljubiti mladu.", ImeIgraca( playerid ), ImeIgraca( ProposedTo[ playerid ] ));
					SendClientMessagee( playerid, BELA, globalstring );
					format( globalstring, sizeof( globalstring ), "Maticar: %s i %s proglasavam vas za...Muza i Zenu, Mozete poljubiti mladozenju.", ImeIgraca( ProposedTo[ playerid ] ), ImeIgraca( playerid ));
					SendClientMessagee( ProposedTo[ playerid ], BELA, globalstring );
					format( globalstring, sizeof( globalstring ), "Najnovije vesti: Imamo novi srecni par, %s i %s su se upravo vencali.", ImeIgraca( playerid ), ImeIgraca( ProposedTo[ playerid ] ) );
					OOCNews( BELA, globalstring );

					//MarriageCeremoney[ProposedTo[ playerid ]] = 1;
					MarriageCeremoney{ ProposedTo[ playerid ] } = 0;
					MarriageCeremoney{ playerid } = 0;
					new namestring[ 24 ];
					format( namestring, sizeof( namestring ), "%s", ImeIgraca( playerid ) );
					strmid( PlayerInfo[ ProposedTo[ playerid ] ][ xMarriedTo ], namestring, 0, strlen( namestring ), 24 );
					format( namestring, sizeof( namestring), "%s", ImeIgraca( ProposedTo[ playerid ] ) );
					strmid( PlayerInfo[ playerid ][ xMarriedTo ], namestring, 0, strlen( namestring ), 24 );
					DajIgracuNovac( playerid, -10000 );
					PlayerInfo[ playerid ][ xMarried ] = true;
					PlayerInfo[ ProposedTo[ playerid ] ][ xMarried ] = true;
					ProposedTo[ playerid ] = 999;
					MarriageCeremoney{ playerid } = 0;
					return 0;
				}
				else
				{
					MarriageCeremoney{ playerid } = 0;
					ProposedTo[ playerid ] = 999;
					return 0;
				}
			}
		}
		else {
			if( GotProposedBy[ playerid ] < 999 ) {
				if( IsPlayerConnected( GotProposedBy[ playerid ] ) ) {
					format( globalstring, sizeof( globalstring ), "* Niste zeleli da se udate za %s, niste izgovorili 'da'.", ImeIgraca( GotProposedBy[ playerid ] ) );
					SendClientMessagee( playerid, ZUTA, globalstring );
					format( globalstring, sizeof( globalstring ), "* %s nije izgovorio 'da'.", ImeIgraca( playerid ) );
					SendClientMessagee( GotProposedBy[ playerid ], ZUTA, globalstring );
					return 0;
				}
				else {
					MarriageCeremoney{ playerid } = 0;
					GotProposedBy[ playerid ] = 999;
					return 0;
				}
			}
			else if( ProposedTo[ playerid ] < 999 ) {
				if( IsPlayerConnected( ProposedTo[ playerid ] ) ) {
					format( globalstring, sizeof( globalstring ), "* Niste zeleli da se udate za %s, niste izgovorili 'da'.", ImeIgraca( ProposedTo[ playerid ] ) );
					SendClientMessagee( playerid, ZUTA, globalstring );
					format( globalstring, sizeof( globalstring ), "* %s nije izgovorila 'da'.", ImeIgraca( playerid ) );
					SendClientMessagee( ProposedTo[ playerid ], ZUTA, globalstring );
					return 0;
				}
				else {
					MarriageCeremoney{ playerid } = 0;
					ProposedTo[ playerid ] = 999;
					return 0;
				}
			}
		}
		return 0;
	}
	if(GetPVarInt( playerid, "Mobile") != -1 ) {
		new idx;
		tmp = strtok(text, idx);
		format( globalstring, sizeof( globalstring ), "[Mobitel] %s kaze:"col_white" %s", ImeIgraca( playerid ), text );
		PorukaRadius( 20.0, playerid, globalstring, 0xE6E6E6E6 );
		if( GetPVarInt( playerid, "Mobile") == 915 ) {
		
			if( !strlen( tmp ) ) {
			
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite ali nerazumijem?");
				return 0;
			}
			
			new wanted[128];
			SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Obavijestili smo sve jedinice u tom podrucju.");
			
			for( new id = 1; id < MAX_ORG; id++)
			{
			
				if( OI[ id ][ oTip ] == ORG_TIP_MD )
				{
				
					format(wanted, sizeof(wanted), "HITNA LINIJA: Svim jedinicama, Pozivatelj: Nepoznat (( %s ))", ImeIgraca( playerid ) );
					OrgPorukaMD( id, 0xFF8282AA, wanted );
					format(wanted, sizeof(wanted), "HITNA LINIJA: Incident: %s", text);
					OrgPorukaMD( id, 0xFF8282AA, wanted );
					format(wanted, sizeof(wanted), "HITNA LINIJA: Lokacija: %s", PlayerInjured[ playerid ][ pVictimLocation ] );
					OrgPorukaMD( id, 0xFF8282AA, wanted );
				}
			}
			SendClientMessagee( playerid, 0xBFC0C2FF, "Prekinuli su...");
			SetPVarInt( playerid, "Mobile", -1 );
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
			SetPlayerSpecialAction( playerid, SPECIAL_ACTION_STOPUSECELLPHONE );
			return 0;
		}
		if( GetPVarInt( playerid, "Mobile" ) == 913 ) {
		
			if(!strlen(tmp)) {
			
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite ali nerazumijem?");
				return 0;
			}
			new wanted[128];
			strmid( PlayerCrime[ playerid ][ pAccusing ], text, 0, strlen(text), 255 );
			PlayerCrime[ playerid ][ pDone ] = 1;
			SendClientMessagee( playerid, 0x2641FEAA, "Policija: Obavijestili smo sve jedinice u tom podrucju.");
			SendClientMessagee( playerid, 0x2641FEAA, "Zahvaljujemo na prijavi zlocina");
			
			for( new id = 1; id < MAX_ORG; id++) {
			
				if( OI[ id ][ oTip ] == ORG_TIP_PD ) {
				
					OrgPoruka( id, 0x83BFBFFF, "|__________________911 Poziv__________________|");
					format(wanted, sizeof(wanted), "Pozivaoc: %s | Broj: %d", ImeIgraca( playerid ), PlayerInfo[ playerid ][ xBrojTelefona ] );
					OrgPoruka( id, 0x83BFBFFF, wanted );
					format(wanted, sizeof(wanted), "Lokacija: %s",PlayerCrime[ playerid ][ pLocation ] );
					OrgPoruka( id, 0x83BFBFFF, wanted );
					format(wanted, sizeof(wanted), "Zlocin: %s",PlayerCrime[ playerid ][ pAccusing ] );
					OrgPoruka( id, 0x83BFBFFF, wanted );
					format(wanted, sizeof(wanted), "Trag Mobitela: %s", GetPlayerLocation( playerid ) );
					OrgPoruka( id, 0x83BFBFFF, wanted );
				}
			}
			SendClientMessagee( playerid, 0xBFC0C2FF, "Prekinuli su..." );
			SetPVarInt( playerid, "Mobile", -1 );
			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
			SetPlayerSpecialAction( playerid, SPECIAL_ACTION_STOPUSECELLPHONE );
			return 0;
		}
		if( GetPVarInt( playerid, "Mobile") == 912 ) {
			if(!strlen(tmp)) {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite ali nerazumijem?");
				return 0;
			}
			strmid( PlayerCrime[ playerid ][ pLocation ], text, 0, strlen(text), 255);
			SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA:Molimo vas ukratko opisite zlocin.");
			SetPVarInt( playerid, "Mobile", 913 );
			return 0;
		}
		if( GetPVarInt( playerid, "Mobile" ) == 555 ) {
			if(!strlen(tmp)) {
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Oprostite ali nerazumijem?");
				return 0;
			}
			strmid( PlayerNeedMechanic[ playerid ][ pMechanicLocation ], text, 0, strlen(text), 255 );
			SendClientMessagee( playerid, 0xFF8282AA, "Tajnica:Molimo vas ukratko opisite sto trebate(Popravak/Gorivo).");
			SetPVarInt( playerid, "Mobile", 556 );
			return 0;
		}
		if( GetPVarInt( playerid, "Mobile") == 556 ) {
			if(!strlen(tmp)) {
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Oprostite nerazumijem, da li trebate popravak ili gorivo?");
				return 0;
			}
			else if((strcmp("popravak", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("popravak"))) {
				SetPVarInt( playerid, "Mobile", -1 );
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Obavijestili smo sve mehanicare na duznosti.");
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Zahvaljujemo na ukazanom povjerenju i koristenju nasih usluga.");
				format( globalstring, sizeof( globalstring ), "TAJNICA: Svim mehanicarima na duznosti, Pozivatelj: %s", ImeIgraca( playerid ) );
				SendMechanicMessage( 0xFF8282AA, globalstring);
				SendMechanicMessage( 0xFF8282AA, "TAJNICA: Potrebno: Popravak!");
				format( globalstring, sizeof( globalstring ), "TAJNICA: Lokacija: %s", PlayerNeedMechanic[ playerid ][ pMechanicLocation ] );
				SendMechanicMessage( 0xFF8282AA, globalstring);
				SendClientMessagee( playerid, 0xBFC0C2FF, "   Prekinuli su...");
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
				SetPlayerSpecialAction( playerid, SPECIAL_ACTION_STOPUSECELLPHONE );
				return 0;
			}
			else if((strcmp("gorivo", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("gorivo"))) {
				SetPVarInt( playerid, "Mobile", -1 );
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Obavijestili smo sve mehanicare na duznosti.");
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Zahvaljujemo na ukazanom povjerenju i koristenju nasih usluga.");
				format( globalstring, sizeof( globalstring ), "TAJNICA: Svim mehanicarima na duznosti, Pozivatelj: %s", ImeIgraca( playerid ) );
				SendMechanicMessage(0xFF8282AA, globalstring);
				SendMechanicMessage(0xFF8282AA, "TAJNICA: Potrebno: Gorivo!");
				format( globalstring, sizeof( globalstring ), "TAJNICA: Lokacija: %s", PlayerNeedMechanic[ playerid ][ pMechanicLocation ] );
				SendMechanicMessage(0xFF8282AA, globalstring);
				SendClientMessagee( playerid, 0xBFC0C2FF, "   Prekinuli su...");
				RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
				SetPlayerSpecialAction( playerid, SPECIAL_ACTION_STOPUSECELLPHONE );
				return 0;
			}
			else {
				SendClientMessagee( playerid, 0xFF8282AA, "Tajnica: Oprostite ne razumijem, da li trebate popravak ili gorivo?");
				return 0;
			}
		}
		if(GetPVarInt( playerid, "Mobile") == 916) {
			if(!strlen(tmp)) {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite ali nerazumijem?");
				return 0;
			}
			strmid( PlayerInjured[ playerid ][pVictimLocation], text, 0, strlen(text), 255);
			SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA:Molimo vas ukratko opisite incident.");
			SetPVarInt( playerid, "Mobile", 915 );
			return 0;
		}
		if(GetPVarInt( playerid, "Mobile") == 911) {
			if(!strlen(tmp)) {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite nerazumijem, da li trebate policiju ili hitnu pomoc?");
				return 0;
			}
			else if((strcmp("police", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("police"))) {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Spajam vas sa policijom, ostanite na liniji.");
				SetPVarInt( playerid, "Mobile", 912);
				SendClientMessagee( playerid, 0x2641FEAA, "HITNA LINIJA: Molimo Vas recite nam svoju lokaciju.");
				return 0;
			}
			else if((strcmp("paramedic", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("paramedic"))) {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Spajam vas sa bolnicom, ostanite na liniji.");
				SetPVarInt( playerid, "Mobile", 916);
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Molimo Vas recite nam svoju lokaciju.");
				return 0;
			}
			else {
				SendClientMessagee( playerid, 0xFF8282AA, "HITNA LINIJA: Oprostite ne razumijem, da li trebate police ili paramedic?");
				return 0;
			}
		}
		if( IsPlayerConnected( GetPVarInt( playerid, "Mobile" ) ) ) {
			if( GetPVarInt( GetPVarInt( playerid, "Mobile" ), "Mobile" ) == playerid ) {
				SendClientMessagee( GetPVarInt( playerid, "Mobile" ), ZUTA , globalstring);
			}
		}
		else {
			SendClientMessagee( playerid, ZUTA,"Nema nikoga tamo.");
		}
		return 0;
	}
	if( realchat ) {
		if( PlayerLogged[ playerid ] != true ) {
			SendErrorMessage(playerid,"Ne mozes koristiti chat ako nisi ulogovan!");
			return 0;
		}
		if(PlayerInfo[playerid][xAdmin] >= 1 && AdminDuty[playerid])
		{
			new string[300];
			format(string,sizeof(string),""col_white"(( "col_balkanstory"[A-OOC] | "col_red"%s{ffffff}: %s ))",ImeIgraca(playerid),text);
			PorukaRadius(20.0,playerid,string,-1);
			return 0;
		}
		if( !IsPlayerInAnyVehicle( playerid ) && GetPlayerSpecialAction( playerid ) != SPECIAL_ACTION_USEJETPACK )
		  {
			if( GetPVarInt( playerid, "ToggedAnim" ) == 0 && PosaoRudar[ playerid ] == 0 )
			{
				if(strlen(text) > 0 && strlen(text) < 10)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,500,1);
				else if(strlen(text) >= 10 && strlen(text) < 20)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,1000,1);
				else if(strlen(text) >= 20 && strlen(text) < 30)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,1500,1);
				else if(strlen(text) >= 30 && strlen(text) < 40)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,2000,1);
				else if(strlen(text) >= 40 && strlen(text) < 50)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,2500,1);
				else if(strlen(text) >= 50 && strlen(text) < 61)
					ApplyAnimation( playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,3000,1);
			}
		}
		new string[ 128 ];
		if( IsPlayerInAnyVehicle( playerid ) && !IsACabrio( GetVehicleModel( GetPlayerVehicleID( playerid ) ) ) )
		{
			//PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xHelper ] >= 1

			if(PlayerInfo[ playerid ][ xAdmin ] >= 1 && AdminDuty[playerid])
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FF0000}Maska_%d {FFFFFF}kaze (vozilo): %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FF0000}%s {FFFFFF}kaze (vozilo): %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );
			}
			else if(PlayerInfo[ playerid ][ xHelper ] >= 1 && AdminDuty[playerid])
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | "col_balkanstory"Maska_%d {FFFFFF}kaze (vozilo): %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | "col_balkanstory"%s {FFFFFF}kaze (vozilo): %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );
			}
			else
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}Maska_%d kaze (vozilo): %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}%s kaze (vozilo): %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );

				new string1[ 128 ];
				format( string1, sizeof( string1 ), "Igrac %s: %s", ImeIgraca( playerid ), text );
				LogSave( "Ostalo/LogICChat.log", string1 );
				
			}
		}
		//---------------------------------------------------------------------------------------------------------------------
		else
		{
			if(PlayerInfo[ playerid ][ xHelper ] >= 1 && AdminDuty[playerid])
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FF0000}Maska_%d {FFFFFF}kaze: %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FF0000}%s {FFFFFF}kaze: %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );
			}
			else if(PlayerInfo[ playerid ][ xHelper ] >= 1 && AdminDuty[playerid])
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | "col_balkanstory"Maska_%d {FFFFFF}kaze: %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | "col_balkanstory"%s {FFFFFF}kaze: %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );
			}
			else
			{
				if( Maskuse[ playerid ] == true )
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}Maska_%d kaze: %s", PlayerInfo[ playerid ][ xMaskID ], text );
				else
					format( string, sizeof( string ), ""col_yelow"IC | {FFFFFF}%s kaze: %s", ImeIgraca( playerid ), text );
				PorukaRadius( 20.0 , playerid, string, -1 );
				SetPlayerChatBubble( playerid, text, 0xFF0000FF, 20.0, 7000 );

				new string1[ 128 ];
				format( string1, sizeof( string1 ), "Igrac %s: %s", ImeIgraca( playerid ), text );
				LogSave( "Ostalo/LogICChat.log", string1 );
			}
		}
		return 0;
	}
	CallLocalFunction("NERP_OPT","ii",playerid, text);
	return 0;
}

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
#define OnPlayerText NERP_OPTee

forward NERP_OPTee(playerid, text[]);

public OnPlayerCommandReceived( playerid, cmdtext[])
{
	if(!IsPlayerConnected( playerid )) return 0;

	if( PlayerInfo[ playerid ][ xAdmin ] < 1 ) {
		if( antiCheatCS[ playerid ][ SpamCommand ] > 0) {
			SendClientMessagee( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Komande je moguce upotrebljavati samo svakih dvije sekunde!");
			return 0;
		}
		antiCheatCS[ playerid ][ SpamCommand ] += 2;
	}

	if( PlayerLogged[ playerid ] != true )
	{
		GRESKA( playerid, "Niste prijavljeni, ne mozete koristiti komande!");
		return 0;
	}
	if(PlayerInfo[playerid][xDeathScreen] == 1)
	{
		greska(playerid,"Ne mozes kucati komande dok ti je ukljucen death screen!");
		return 0;
	}
	if(Ranjen[playerid] == 1)
	{
		greska(playerid,"Ne mozes kucati komande dok si ranjen.");
		return 0;
	}
	return 1;
}

HideUnkCmd(playerid); public HideUnkCmd(playerid)
{
	UnknownCmdControl(playerid, false);
	return 1;
}

public OnPlayerCommandPerformed( playerid, cmdtext[], success)
{
	if( !success )
	{
		GRESKA( playerid, "{ffffff}Komanda "col_red"'%s'{ffffff} ne postoji ili ste unijeli varijable koje nisu validne! [/pomoc]", cmdtext);
		
		UnknownCmdControl(playerid, true);
		SetTimerEx("HideUnkCmd", 3500, false, "i", playerid);

		for(new i; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i))
			{
				scmalt[i]("Igrac %s [ID: %i] je pokusao iskoristiti komandu: %s", ImeIgraca(playerid), playerid, cmdtext);
			}
		}
		return 1;
	}
	/*if( success )
	{
		new success_command_report[300];
		format(success_command_report,sizeof(success_command_report),""col_balkanstory"[ COMMAND ]{ffffff}: Igrac %s je iskoristio cmd '%s'! "col_sanm"(/pm)",ImeIgraca(playerid),cmdtext);
		AdminPoruka(-1,success_command_report);
	}*/
	new string[ 128 ]; format( string, sizeof( string ), "Igrac %s | Komanda: %s", ImeIgraca( playerid ), cmdtext ); LogSave( "Ostalo/LogKomandi.log", string );
	CallLocalFunction("discordbot_cmds","isi",playerid, cmdtext, success);
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			scmalt[i]("Igrac %s [ID: %i] je iskoristio komandu: %s", ImeIgraca(playerid), playerid, cmdtext);
		}
	}
	return true;
}

public OnPlayerEnterVehicle( playerid, vehicleid, ispassenger) 
{
	new Float:pozicija[ 4 ];
	if (BunnyHop [playerid] == 1)
	{
		GetPlayerPos( playerid, pozicija[1], pozicija[2], pozicija[3]);
		SendClientMessage( playerid,-1,"Ne mozete uci u vozilo dok vam je uganut clanak!");
		SetPlayerPos( playerid, pozicija[1], pozicija[2], pozicija[3]);
	}
	if( ServerInfo[ RRVehicle ] == true ) {
		if( !occupied[ vehicleid ] )
			occupied[ vehicleid ] = true;
	}
	SendInfoMessage(playerid,"Da vidite cije je ovo vozilo, koristite '/papirivozila'.");
	antiCheatCS[ playerid ][ EnteredVehicle ] = vehicleid;
	if( ispassenger == 0 ) {
		if( BusyVehicle[ vehicleid ] > -1 ) {
			if( BusyVehicle[ vehicleid ] == playerid ) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
				SendClientMessagee( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Zabranjeno je otimati vozila drugim igracima!");
			}
		}
	}
	return true;
}

public OnPlayerExitVehicle( playerid, vehicleid ) {

	new Float:x,Float:y,Float:z;
	GetVehiclePos( vehicleid,x, y, z );
	RealVehiclePositions[ vehicleid ][ 0 ] = x;
	RealVehiclePositions[ vehicleid ][ 1 ] = y;
	RealVehiclePositions[ vehicleid ][ 2 ] = z;
	
	if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {

		if( CistacPosao[ playerid ] == true ) {
			PlayerInfo[ playerid ][ xPlatniRacun ] += cistacnovac[ playerid ];
			SavePlayer( playerid ); UpdatePlataTD( playerid );
			SendJobMessage( playerid, "Zaradio si "col_white"%d$ "col_job" za predjenih %dkm.", cistacnovac[ playerid ], cistackilometri[ playerid ] );
			SetVehicleToRespawn( cistacvozilo[ playerid ] );
			BussinesJobMoney( POSAO_KOMUNALAC, cistacnovac[ playerid ]/10 );
			cistacvozilo[ playerid ] = -1;
			CistacPosao[ playerid ] = false;
			cistackilometri[ playerid ] = 0;
			cistacmetri[ playerid ] = 0;
			cistacnovac[ playerid ] = 0;
			CistacWarning[ playerid ] = 0;
			Dimi_KillTimer( CistacTimer[ playerid ] );
			CKilometriTDControl( playerid, false );
		}
	}
	if( Pojas[ playerid ] == true ) {
		format( globalstring, sizeof( globalstring ), "* %s se hvata za pojas, te ga skida.", ImeIgraca( playerid ) );
		PorukaRadius(30.0, playerid, globalstring, LJUBICASTA );
		Pojas[ playerid ] = false;
	}
	if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] ) ) {
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
		PlayerGpsRadar[ playerid ][ _pgrObject ] = -1;
	}
	return true;
}


public OnPlayerStateChange( playerid, newstate, oldstate )
{
	CallLocalFunction("NOVASECURITY_STATECHANGE", "iii", playerid,newstate,oldstate);
	

	if(newstate == PLAYER_STATE_ONFOOT)
	{
		for(new i; i < 20; i++) PlayerTextDrawHide(playerid, KILOMETARSATTD[playerid][i]);
	}
	if( newstate == PLAYER_STATE_DRIVER )
	{
		PlayerTextDrawHide(playerid, KILOMETARSATTD[playerid][5]);
		PlayerTextDrawShow(playerid, KILOMETARSATTD[playerid][5]);
		PlayerTextDrawSetPreviewModel(playerid, KILOMETARSATTD[playerid][5], GetVehicleModel(GetPlayerVehicleID(playerid)));
		new engine, lights, alarm, doors, bonnet, boot, objective;
		gLastDriver[ GetPlayerVehicleID( playerid ) ] = playerid;
		LastCar[ playerid ] = GetPlayerVehicleID( playerid );
		antiCheatCS[ playerid ][ EnterVehTime ] = GetTickCount();
		/*if(ServerInfo[HappyJobs]==true)
		{
			TextDrawHideForPlayer(playerid,HappyJobsTD);
		}*/
		
		if( !IsVehicleBajs( GetPlayerVehicleID( playerid ) ) )
		{

			for( new i = 0; i < 3; i ++)
			{
				PlayerTextDrawShow( playerid, KILOMETARSATPLAYER[ playerid ][ i ] );

			}

			for( new i = 0; i < 24; i ++)
			{
				PlayerTextDrawShow( playerid, KILOMETARSATTD[ playerid ][ i ] );

			}


		}
		
		if( ServerInfo[ RRVehicle ] == true )
		{
			if( !occupied[ GetPlayerVehicleID( playerid ) ] )
				occupied[ GetPlayerVehicleID( playerid ) ] = true;
		}
		if( HavePlayerWeapon( playerid ) )
		{
			SetPlayerArmedWeapon( playerid, 0 );
		}
	
		if( GetPlayerVehicleID( playerid ) != antiCheatCS[ playerid ][ CWVehID ] )
		{
			if( antiCheatCS[ playerid ][ CWTime ] > gettime( ) )
			{
				format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Car Warp", ImeIgraca( playerid ) );
				AdminPoruka( SVETLOCRVENA, globalstring );
				Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Car Warp");
				return 1;
			}
			antiCheatCS[ playerid ][ CWTime ] = gettime( ) + 1;
			antiCheatCS[ playerid ][ CWVehID ] = GetPlayerVehicleID( playerid );
		}

		if( BusyVehicle[ GetPlayerVehicleID( playerid ) ] > -1 )
		{
			if( BusyVehicle[ GetPlayerVehicleID( playerid ) ] == playerid ) { }
			else
			{
				new Float:Pos[ 3 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				Dimi_SetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Zboga moguce kradje vozila izbacen si iz njega!" );
			}
		}
		else {
			BusyVehicle[ GetPlayerVehicleID( playerid ) ] = playerid;
			antiCheatCS[ playerid ][ TakeVehicle ] = GetPlayerVehicleID( playerid );
		}
		
		if( Parked[ GetPlayerVehicleID( playerid ) ] != -1 ) {
		
			ShowPlayerDialog( playerid, dialog_PARKING_3, DSMSG, D_NASLOV, ""col_white"Za ovo vozilo je placeno parkiranje.\nZelis da prekines parking i uzmes svoje vozilo.", "Da", "Ne" );
		
		}
		
		if( garbagemanVehicles[ GetPlayerVehicleID( playerid ) ][ gPlayerID ] != -1 ) {
			if( garbagemanVehicles[ GetPlayerVehicleID( playerid ) ][ gPlayerID ] == playerid ) { }
			else {
				new Float:Pos[ 3 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				Dimi_SetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Ovo vozilo vec neko koristi za posao ne mozete uci!" );
			}
		}
		
		if( farmerVehicles[ GetPlayerVehicleID( playerid ) ][ fvMilk ] == true )
		{
			if( farmerVehicles[ GetPlayerVehicleID( playerid ) ][ fvMilkpID ] == playerid ) { }
			else
			{
				new Float:Pos[ 3 ];
				GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				Dimi_SetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
				SendClientMessage( playerid, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Ovo vozilo vec neko koristi za posao ne mozete uci!" );
			}
		}
//dialozi za pocinjanje poslova kad sjedne u vozilo
//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_KOMUNALAC && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{
			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if( UzeoOpremu[ playerid ] == true )
			{
				if( CheckpointStatus[ playerid ] > 0 || garbagemanInfo [playerid ][ gmiJob ] == true || CistacPosao[ playerid ] == true )
				{ }
				else
				{
					#if NERP_ZIMSKI_MOD  == 1
					if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 455 )//kamion za ciscenje snijega
					{
						ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO3, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite cistiti snijeg sa ulica?\n","Da","Ne");
					}

					#else
					if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 574 )//cistilica mower
					{
						ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO2, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite cistiti ulice?\n","Da","Ne");
					}
					
					if( GetVehicleModel( GetPlayerVehicleID(playerid) ) == 408 )//kamion za smece
					{
						ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite skupljati smece?\n","Da","Ne");
					}

					#endif

				}

			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
		}
//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_BUSVOZAC && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{

			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}

			if( UzeoOpremu[ playerid ] == true )
			{
				if(IDIgracaKojiVoziBus[ GetPlayerVehicleID(playerid) ] != -1)
				{
					if(IDIgracaKojiVoziBus[ GetPlayerVehicleID(playerid) ] != playerid)
					{
						GRESKA( playerid, "Ovaj autobus vec neko koristi za posao (ID: %d)",IDIgracaKojiVoziBus[ GetPlayerVehicleID(playerid) ]);
						Dimi_RemovePlayerFromVehicle( playerid );
						return 1;
					}

				}

				if( VoziBeogradStanicu[playerid] > 0 || VoziSarajevoStanicu[ playerid ] > 0)
				{ }
				else
				{
					ShowPlayerDialog( playerid, dialog_BUSVOZACPOSAO, DSL, "Bus linije", ""col_balkanstory"(1). "col_white"Linija - Beograd\n"col_balkanstory"(2). "col_white"Linija BG - SA", D_ODABERI, D_ODUSTANI );
				}

			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
		}

//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_GRADJEVINAR && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{

			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if( UzeoOpremu[ playerid ] == true )
			{
				if( CheckpointStatus[ playerid ] > 0 )
				{ }
				else
				{
					if( GetVehicleModel( GetPlayerVehicleID(playerid) ) == 524 && VehCement[ GetPlayerVehicleID( playerid ) ] == false )//mjesalica za beton
					{
						ShowPlayerDialog(playerid, dialog_GRADJEVINARPOSAO, DSMSG, ""col_white"Gradjevinar",""col_white"Da li zelite prevoziti beton?\n","Da","Ne");
						return 1;

					}
					if( GetVehicleModel( GetPlayerVehicleID(playerid) ) == 486 )//bager
					{
						ShowPlayerDialog(playerid, dialog_GRADJEVINARPOSAO2, DSMSG, ""col_white"Gradjevinar",""col_white"Da li zelite ravnati zemlju?\n","Da","Ne");
						return 1;

					}
				
				
				}

			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
		}
//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_KOSAC && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{
			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if( UzeoOpremu[ playerid ] == true )
			{
				if( KrenuoKosenje[ playerid ] ) 
				{  }
				else
				{
					ShowPlayerDialog(playerid, dialog_KOSACPOSAO, DSMSG, ""col_white"Kosac trave",""col_white"Da li zelite kositi travu?\n","Da","Ne");

				}

			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
		}
//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_FARMER && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{

			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if(GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 532 )
			{
				if( UzeoOpremu[ playerid ] == true )
				{
					if( KrenuoZetvu[ playerid ] )
					{  }
					else
					{
						ShowPlayerDialog(playerid, dialog_ZETVAZITA, DSMSG, ""col_white"Vrsenje zita",""col_white"Da li zelite vrsiti zito?\n","Da","Ne");

					}

				} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
			}
		}
//========================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PILOT && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{

			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if( UzeoOpremu[ playerid ] == true )
			{
				if( LetSF[ playerid ] > 0 || LetLV[ playerid ] > 0 )
				{  }
				else
				{
					ShowPlayerDialog( playerid, dialog_PILOT, DSL, "Pilot", ""col_balkanstory"(1). "col_white"Let BG - ZG\n"col_balkanstory"(2). "col_white"Let BG - SA", D_ODABERI, D_ODUSTANI );

				}
				
			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli raditi." );
		}
//=============================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RIBAR && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ] )
		{

			if( UzeoOpremu[ playerid ] == true )
			{
			
				if( !fishermanInfo[ playerid ][ StartedFishing ] && !fishermanInfo[ playerid ][ Fishing ] )
				{

					new id = random( sizeof( RibarPosition ) );
					fishermanInfo[ playerid ][ Fisherman ] = id;
					fishermanInfo[ playerid ][ StartedFishing ] = true;
					fishermanInfo[ playerid ][ fLastVeh ] = GetPlayerVehicleID( playerid );
					Dimi_SetPlayerCheckpoint( playerid, RibarPosition[ id ][ 0 ], RibarPosition[ id ][ 1 ], RibarPosition[ id ][ 2 ], 5.0 );
					SendJobMessage( playerid, "Vozite do lokacije oznacene na mapi." );
					SendJobMessage( playerid, "Kada stignete zapocnite sa pecanjem komandom "col_job"/pecaj"col_white"(marker ce ostati)." );
					
				}
			} else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli voziti camac." );
		}
//=============================================================================================================================================
		if( PlayerInfo[ playerid ][ xPosao ] == POSAO_TEMPODOSTAVA && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ])
		{

			if( ( PlayerInfo[ playerid ][ xAdmin ] > 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 ) || PlayerInfo[ playerid ][ xHelper ] > 0 )
			{
				new hour, minute, seconds;
				gettimeEx( hour, minute, seconds );
				FixHour( hour );
				hour = shifthour;
				if( ( hour >= 08 ) && ( hour <= 05 ) ) { }
				else
				{
					GRESKA( playerid, "Staff team moze raditi samo od 08h do 05h!" );
					Dimi_RemovePlayerFromVehicle( playerid );
					return 1;
				}
			}
			if( UzeoOpremu[ playerid ] == true )
			{

				if( KamionUsed[ GetPlayerVehicleID( playerid ) ] != -1 )
				{
				
					if( KamionUsed[ GetPlayerVehicleID( playerid ) ] != playerid )
					{
						announcement( playerid, "~r~Taj kamion je zauzet", 5000, 6);
						Dimi_RemovePlayerFromVehicle( playerid );
						return true;
					}
				}
				if( DeliverCar[ playerid ] != -1 )
				{
				
					if( DeliverCar[ playerid ] != GetPlayerVehicleID( playerid ) )
					{
					
						SendJobMessage( playerid, "To nije Vas kamion sa kojim ste zapoceli razvoz robe!");
						announcement( playerid, "~r~To nije vas kamion", 5000, 6 );
						Dimi_RemovePlayerFromVehicle( playerid );
						return 1;
					}
				}

				if( DeliverLevel[ playerid ] == 0 ) ShowPlayerDialog(playerid, dialog_DELIVERPEPSI, DSMSG, ""col_white"Dostava robe",""col_white"Da li ste sigurni da zelite da\npokrenete dostavu robe?","Da","Ne");

			}
			else return Dimi_RemovePlayerFromVehicle( playerid ), GRESKA( playerid, "Morate imati opremu da bi mogli voziti." );
		}
//=============================================================================================================================================
		if( GetPlayerVehicleID( playerid ) != antiCheatCS[ playerid ][ EnteredVehicle ] && antiCheatCS[ playerid ][ RemoveVehicle ] == false )
		{
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc SPAM/Port VOZILA!!! || "SERVERBOJA_AQUA"%s[ID: %d] |LVL: |%d|"col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ] );
			AdminPoruka( -1, globalstring );
		}
		
		if( vCanDrive[ GetPlayerVehicleID( playerid ) ] == 0 )
		{
			SetCameraBehindPlayer( playerid );
			SendClientMessagee( playerid, CRVENA, "Ovo vozilo je unisteno. Pozovite mehanicara!");
			GetVehicleParamsEx( GetPlayerVehicleID( playerid ),engine, lights, alarm, doors, bonnet, boot, objective );
			SetVehicleParamsEx( GetPlayerVehicleID( playerid ),0,lights,alarm,doors,bonnet,boot,objective);
		}


		if( Fuel[ GetPlayerVehicleID( playerid ) ] < 1 )
		{
			if(!IsVehicleBajs( GetPlayerVehicleID( playerid ) ) && !IsVehicleLetelica( GetPlayerVehicleID( playerid ) ) && !IsVehicleBrod( GetPlayerVehicleID( playerid ) ) )
			{
				SetCameraBehindPlayer( playerid );
				SetPVarInt( playerid, "NoFuel", 1);
				SendClientMessagee( playerid, CRVENA, "Ovo vozilo nema goriva. Koristite /exit da biste izasli.");
				GetVehicleParamsEx( GetPlayerVehicleID( playerid ), engine, lights, alarm, doors, bonnet, boot, objective );
				SetVehicleParamsEx( GetPlayerVehicleID( playerid ), 0,lights,alarm,doors,bonnet,boot,objective);
			}
		}
		GetVehicleParamsEx( GetPlayerVehicleID( playerid ), engine, lights, alarm, doors, bonnet, boot, objective );
		if( engine == 0 )
		{
			SendClientMessagee( playerid, UGBOJA, "Da upalite vozilo koristite "col_white"/upali "col_balkanstory"ili tipku "col_white"2." );
		}

		antiCheatCS[ playerid ][ EnteredVehicle ] = GetPlayerVehicleID( playerid );

		if( oldstate == PLAYER_STATE_ONFOOT )
		{
			if( PlayerInfo[ playerid ][ xPosao ] == POSAO_TAXI )
			{
				if( taxiDuty[ playerid ] == true && VoziIgracaID[ playerid ] == INVALID_PLAYER_ID && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && PosaoVozila[ GetPlayerVehicleID( playerid ) ] == POSAO_TAXI )
				{
					TaximetarUkljucen[ playerid ] = false;

					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 0 ] );//vodje
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 1 ] );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 2 ] );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 3 ] );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 4 ] );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 6 ] );


					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 7 ], "N/A" );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 7 ] );
					
					PlayerTextDrawSetString( playerid, TaxistaTD[ playerid ][ 5 ], "N/A" );
					PlayerTextDrawShow( playerid, TaxistaTD[ playerid ][ 5 ] );

					CenaVoznje[ playerid ] = 0;
					VoziIgracaID[ playerid ] = INVALID_PLAYER_ID;
					offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
				}
			}
		}

		if( PlayerInfo[ playerid ][ xAdmin ] >= 6 )
		{
			SendClientMessageEx( playerid, -1, "Usli ste u vozilo ID: %d", ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] );
		}

		if( TipVozila[ GetPlayerVehicleID( playerid ) ] == PRIVATNO_VOZILO )
		{
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 )
			{
				SendClientMessageEx( playerid, -1, "Ulazite u privatno vozilo, vlasnik:  %s", VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vOwner ] );
			}
		}
		
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == NAPRODAJU_VOZILO )
		{
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1339 && AdminDuty[ playerid ] )
			{
				SendClientMessageEx( playerid, -1, "Vi ste vlasnik na duznosti i nece vam biti prikazan dialog za kupnju!");
			}
			else
			{
				new izbor = ScriptIDVozila[ GetPlayerVehicleID( playerid ) ];
				new rentstr[ 300 ];
				format(rentstr,sizeof(rentstr),""col_balkanstory"-------------------------------------------------------------------------\n\n\
				"col_balkanstory"Model: {FFFFFF}%s\n"col_balkanstory"Gorivo: {FFFFFF}%s\n"col_balkanstory"Cijena: {FFFFFF}$%d\n\n\
				"col_balkanstory"-------------------------------------------------------------------------",ImeVozila[ VehicleInfo[ izbor ][ vModel ]-400 ],GetVehicleFuelType( izbor ),VehicleInfo[ izbor ][ vPrice ]);
				ShowPlayerDialog(playerid,dialog_KUPUJEAUTONAPIJACI ,DSMSG,"Auto pijaca",rentstr,"Kupi","Izlaz");
			}

			//SendInfoMessage
		}
		
		
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == ORGANIZACIJSKO_VOZILO )
		{
			if( PlayerInfo[ playerid ][ xAdmin ] >= 6 && AdminDuty[ playerid ] ) { }
			else
			{
				if( OrgaVozila[ GetPlayerVehicleID( playerid ) ] != PlayerInfo[ playerid ][ xClan ] )
				{
					new Float:Poz[ 3 ];
					GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
					Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
					Dimi_RemovePlayerFromVehicle( playerid );
					GRESKA( playerid, "Nemas kljuc ovog vozila." );
				}
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO )
		{
			if( PlayerInfo[ playerid ][ xAdmin ] >= 6 && AdminDuty[ playerid ] ) { }
			else
			{
				if( PosaoVozila[ GetPlayerVehicleID( playerid ) ] != PlayerInfo[ playerid ][ xPosao ] )
				{
					new Float:Poz[ 3 ];
					GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
					Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
					Dimi_RemovePlayerFromVehicle( playerid );
					GRESKA( playerid, "Nemate posao %s.", getJobName( PosaoVozila[ GetPlayerVehicleID( playerid ) ] ) );
				}
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == RENTANO_VOZILO )
		{
			if( Rentano[ playerid ] != GetPlayerVehicleID( playerid ) )
			{
				new price;
				if( IsVehicleBajs( GetPlayerVehicleID( playerid ) ) ) price = 5;
				else if( IsVehicleMotor( GetPlayerVehicleID( playerid ) ) ) price = 10;
				else if( IsVehicleAuto( GetPlayerVehicleID( playerid ) ) ) price = 15;
				new rentstr[ 300 ];
				format(rentstr,sizeof(rentstr),""col_balkanstory"-------------------------------------------------------------------------\n\n\
				{FFFFFF}Unesite koliko minuta zelite rentati ovo vozilo.\n1 minut = %d$\nKomande: /lock /unrent\n\n\
				"col_balkanstory"-------------------------------------------------------------------------",price);
				ShowPlayerDialog(playerid,dialog_RENTANJE,DSI,"RENT",rentstr,"Uredu","Izlaz");
				TogglePlayerControllable( playerid, false );
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == GRADONACELNIKOVO_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 && AdminDuty[ playerid ] ) { }
			else {
				if( PlayerInfo[ playerid ][ xGradRank ] != GRAD_DRIVER || PlayerInfo[ playerid ][ xGradRank ] != GRAD_LDRIVER ) {
					if( !VozacUniforma[ playerid ] ) {
						new Float:Poz[ 3 ];
						GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
						Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
						Dimi_RemovePlayerFromVehicle( playerid );
						GRESKA( playerid, "Nemate kljuceve od ovog vozila ili uniformu vozaca gradonacelnika!");
						return 1;
					}
				}
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == IZLOZBENO_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] != 7 ) {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == ADMIN_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 ) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == HELPER_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xHelper ] >= 1 || PlayerInfo[ playerid ][ xSkriptaRank ] == 2) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == PROMOTER_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || PlayerInfo[ playerid ][ xPromoter ] >= 1 ) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == VIP_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || PlayerInfo[ playerid ][ xVIPLevel ] >= 1 ) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == POLAGANJE_VOZILO ) { 
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 || Polaganje[ playerid ] >= 1 ) { }
			else {
				new Float:Poz[ 3 ];
				GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
				Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
				Dimi_RemovePlayerFromVehicle( playerid );
				GRESKA( playerid, "Nemate kljuceve od ovog vozila!");
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == PUMPA_VOZILO ) {
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 && AdminDuty[ playerid ] ) { }
			else {
				if( PumpaImanjeVozilo[ GetPlayerVehicleID( playerid ) ] != PlayerInfo[ playerid ][ xFirmaID ] ) {
					new Float:Poz[ 3 ];
					GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
					Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
					Dimi_RemovePlayerFromVehicle( playerid );
					GRESKA( playerid, "Nemate kljuceve ovog vozila." );
				}
			}
		}
		else if( TipVozila[ GetPlayerVehicleID( playerid ) ] == IMANJE_VOZILO ) { // edit ovo dodano
			if( PlayerInfo[ playerid ][ xAdmin ] >= 5 && AdminDuty[ playerid ] ) { }
			else {
				if( PumpaImanjeVozilo[ GetPlayerVehicleID( playerid ) ] != PlayerInfo[ playerid ][ xFieldID ] ) {
					new Float:Poz[ 3 ];
					GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
					Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
					Dimi_RemovePlayerFromVehicle( playerid );
					GRESKA( playerid, "Nemate kljuceve ovog vozila." );
				}
			}
		}
		
		//
		new vehicleid = GetPlayerVehicleID( playerid );
		if( IsVehicleMotor( vehicleid ) ) {
			if( PlayerInfo[ playerid ][ xMotorska ] == 0 ) {
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju motora - pazite se policije!");
			}
		}

		if( IsVehicleAuto( vehicleid ) ) {
			if( PlayerInfo[ playerid ][ xVozacka ] == 0 ) {
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju auta - pazite se policije!");
			}
		}

		if( TipVozila[ vehicleid ] == POSLOVNO_VOZILO ) {
			if( PosaoVozila[ vehicleid ] == POSAO_PIZZA ) {
				if( UzeoOpremu[ playerid ] == true ) { }
				else {
					new Float:Poz[ 3 ];
					GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
					Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
					Dimi_RemovePlayerFromVehicle( playerid );
					GRESKA( playerid, "Morate imati opremu da bi vozili ovo vozilo!");
				}
			}
			else if( PosaoVozila[ vehicleid ] == POSAO_GRADJEVINAR )
			{



			}
		}

		if( IsVehicleC1( vehicleid ) ) {
			if( PlayerInfo[ playerid ][ xKamionskaC1 ] == 0 ) {
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju kombija - pazite se policije!");
			}
		}

		if( IsVehicleC2( vehicleid ) ) {
			if( PlayerInfo[ playerid ][ xKamionskaC2 ] == 0 ) {
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju kamiona - pazite se policije!");
			}
		}

		if( IsVehicleC3( vehicleid ) )
		  {
			if( PlayerInfo[ playerid ][ xKamionskaC3 ] == 0 )
			{
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju kamiona sa prikolicom - pazite se policije!");
			}
		}

		if( IsVehicleBrod( vehicleid ) )
		  {
			if( PlayerInfo[ playerid ][ xBrodska ] == 0 )
			{
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju broda - pazite se policije!");
			}
		}

		if( IsVehicleLetelica( vehicleid ) )
		  {
			if( PlayerInfo[ playerid ][ xLetelica ] == 0 )
			{
				SendClientMessagee( playerid, UGBOJA, "Nemate dozvolu za voznju aviona - pazite se policije!");
			}
		}
		
		if( garbagemanInfo[ playerid ][ gmiHasGarbage ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa smecem u vozilo!" );
		}

		if( fishermanInfo[ playerid ][ Fishing ] ) {
		
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes voziti dok pecas kucaj /zavrsipecanje pa onda!" );
		}

		if( farmerInfo[ playerid ][ fiHaveBucket ] == true )
		{
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa kantom u vozilo!" );
		}
		if( farmerInfo[ playerid ][ fiHaveGajbica ] == true || farmerInfo[ playerid ][ fiHaveFruits ] == true )
		{
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa gajbicom u vozilo!" );
		}
		
		
		
		if( farmerInfo[ playerid ][ fiFarmerPickupedBale ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa usevom u vozilo!" );
		}

		if( NosiPaketOruzja[ playerid ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa paketom u vozilo!" );
		}

		if( UzeoPicu[ playerid ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa picom u vozilo!" );
		}

	}
	else if( newstate == PLAYER_STATE_ONFOOT )
	{

		for( new i = 0; i < 3; i ++)
		{
			PlayerTextDrawHide( playerid, KILOMETARSATPLAYER[ playerid ][ i ] );
		}

		for( new i = 0; i < 24; i ++)
		{
			PlayerTextDrawHide( playerid, KILOMETARSATTD[ playerid ][ i ] );
		}
		
		if( oldstate == PLAYER_STATE_PASSENGER )
		{
			if( offeredByCabbie[ playerid ] != INVALID_PLAYER_ID )
			{
				TaximetarUkljucen[ offeredByCabbie[ playerid ] ] = false;
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 0 ] );//vodje
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 1 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 2 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 3 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 4 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 5 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 6 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 7 ] );

				DajIgracuNovac( playerid, -CenaVoznje[ offeredByCabbie[ playerid ] ] );
				DajIgracuNovac( offeredByCabbie[ playerid ], CenaVoznje[ offeredByCabbie[ playerid ] ] );

				SendClientMessageEx( playerid, ZUTA, "Stigli ste do lokacije i platili %d$ za voznju", CenaVoznje[ offeredByCabbie[ playerid ] ] );
				SendClientMessageEx( offeredByCabbie[ playerid ], ZUTA, "Stigli ste do lokacije na koju je igrac htio i naplatili %d$ za voznju", CenaVoznje[ offeredByCabbie[ playerid ] ] );

				PlayerTextDrawSetString( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 7 ], "N/A" );
				PlayerTextDrawShow( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 7 ] );
				
				PlayerTextDrawSetString( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 5 ], "N/A" );
				PlayerTextDrawShow( offeredByCabbie[ playerid ], TaxistaTD[ offeredByCabbie[ playerid ] ][ 5 ] );

				CenaVoznje[ offeredByCabbie[ playerid ] ] = 0;
				Dimi_KillTimer( TaxiTimer[ offeredByCabbie[ playerid ] ] );
				VoziIgracaID[ offeredByCabbie[ playerid ] ] = INVALID_PLAYER_ID;
				offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
			}
		}

		antiCheatCS[ playerid ][ EnteredVehicle ] = INVALID_VEHICLE_ID;

		if( oldstate == PLAYER_STATE_DRIVER )
		{
			new lastveh = LastCar[ playerid ];
			new Float:x, Float:y, Float:z;
			GetVehiclePos( lastveh, x, y, z );
			RealVehiclePositions[ lastveh ][ 0 ] = x;
			RealVehiclePositions[ lastveh ][ 1 ] = y;
			RealVehiclePositions[ lastveh ][ 2 ] = z;
			
			antiCheatCS[ playerid ][ EnteredVehicle ] = INVALID_VEHICLE_ID;
			
			if( taxiDuty[ playerid ] == true && VoziIgracaID[ playerid ] == INVALID_PLAYER_ID )
			{
				TaximetarUkljucen[ playerid ] = false;

				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 0 ] );//vodje
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 1 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 2 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 3 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 4 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 5 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 6 ] );
				PlayerTextDrawHide( playerid, TaxistaTD[ playerid ][ 7 ] );

				CenaVoznje[ playerid ] = 0;
				VoziIgracaID[ playerid ] = INVALID_PLAYER_ID;
				offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
			}
		}

		if(GetPVarInt( playerid, "gGas") == 1)
		{

			for( new i = 0; i < 3; i ++)
			{
				PlayerTextDrawHide( playerid, KILOMETARSATPLAYER[ playerid ][ i ] );

			}

			for( new i = 0; i < 24; i ++)
			{
				PlayerTextDrawHide( playerid, KILOMETARSATTD[ playerid ][ i ] );
			}
		}
	}
	else if( newstate == PLAYER_STATE_SPAWNED ) {
		Dimi_SetPlayerHealth( playerid, 50.0+PlayerInfo[ playerid ][ xSHealth ] );
		if( PlayerInfo[ playerid ][ xVIPLevel ] >= 5 ) {
			Dimi_SetPlayerHealth( playerid, 100.00 );
		}
	}
	else if( newstate == PLAYER_STATE_WASTED )
	{
		//if(NaZombieEventu[playerid]) return ZombieEvent_OnPlayerDeath(playerid);
		#if defined cicibanbre
		Ranjen[playerid] = 0;
		BunnyHop[playerid] = 0;
		KillTimer(BHKrajTimer[playerid]);
		hidedmtd(playerid);
		ClearChat(playerid,50);
		hidebatd(playerid);
		//KillTimer(deathafterinjury(playerid));
		KillTimer(DeathAfterInjury[playerid]);
		hideinjurytd(playerid);
		showdt(playerid);
		SetPlayerInterior(playerid,0);

		TogHud[ playerid ] = false;

		TogPlayerHud(playerid);
		ShowLogo(playerid);
		PlayerInfo[playerid][xDeathScreen] = 1;

		SetTimerEx( "spawnplayer", 10000, false, "i", playerid );

		// bezveze code haha:

		#if defined injury_system_failure
		new camview = random(3);
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
		#endif

		#endif
	}
	//
	else if( newstate == PLAYER_STATE_PASSENGER ) {
		if( HavePlayerWeapon( playerid ) ) {
			SetPlayerArmedWeapon( playerid, 0 );
		}
	   // SendInfoMessage(playerid,"Da vidite cije je ovo vozilo, koristite '/papirivozila'.");
		/*if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 416 && GetPlayerVehicleSeat( playerid ) != 1 )Ubagovana hitna pa te baci na nebo
		{
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			Dimi_SetPlayerPos( playerid, 2003.3, 2284.2, 1011.1 );
			SetPlayerFacingAngle( playerid, 0 );
			SetCameraBehindPlayer( playerid );
			TogglePlayerControllable( playerid, false );
			SetPlayerInterior( playerid, 1 );
			InAmbu[ playerid ] = GetPlayerVehicleID( playerid );
		}*/
		
		if( farmerInfo[ playerid ][ fiHaveBucket ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa kantom u vozilo!" );
		}
		
		if( farmerInfo[ playerid ][ fiHaveGajbica ] == true || farmerInfo[ playerid ][ fiHaveFruits ] == true )
		{
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa gajbicom u vozilo!" );
		}

		if( farmerInfo[ playerid ][ fiFarmerPickupedBale ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa usevom u vozilo!" );
		}
		
		if( UzeoPicu[ playerid ] == true ) {
			new Float:Poz[ 3 ];
			GetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ] );
			Dimi_SetPlayerPos( playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]+2 );
			GRESKA( playerid, "Ne mozes uci sa picom u vozilo!" );
		}
		
		/*if( PlayerCuffed[ playerid ] > 0 ) {

			PlayerInfo[ playerid ][ xZatvor ] = OBICAN_ZATVOR;
			PlayerInfo[ playerid ][ xZatvorVreme ] = 30;
			DajIgracuNovac( playerid, -2500 );

			SendClientMessagee( playerid, SVETLOCRVENA, "{FF0000}| AC |:"SERVERBOJA_AQUA" Zbog G Abusea sa lisicama otisli ste u zatvor na 30 minuta, cena 2500$!");
			
			new rand = random( sizeof( RandomZatvor ) );
			Dimi_SetPlayerPos( playerid, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ],RandomZatvor[ rand ][ 2 ] );
			PlayerInfo[ playerid ][ xWanted ] = 0;
			Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ] );
			strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
			strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
			ShowLoadingTextdraws(playerid, true); SendAcMessage(playerid, ""SERVERBOJA_AQUA"Anti-SK"col_white" zastita za Vas je pokrenuta, sacekajte - istice za nekoliko sekundi!");
			SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
			SetCameraBehindPlayer( playerid ); SetPlayerInterior( playerid, 0);
			SetPlayerVirtualWorld( playerid, 0);
			TogglePlayerControllable( playerid, 0 );
			SavePlayer( playerid );
		}*/ // edit
	}
	return true;
}


public OnPlayerEnterRaceCheckpoint( playerid )
{
	new cpid = PlayerCP[ playerid ];
	new nextcpid = PlayerCP[ playerid ]+1;
	new eventid = EventInfo[ eID ];
	if( cpid >= 2 )
	{
		if( GetPlayerVehicleID( playerid ) == EventInfo[ Vehicle ][ PlayerEventVehID[ playerid ] ] ) {
			//SendClientMessageEx( playerid, 0x83BFBFAA, "-> || %s || Checkpoint %d/%d || %s || < -", Event[ eventid ][ Name ], (cpid-1), (Event[ eventid ][ MaxCP ]-1), ImeIgraca( playerid ) );
			PlayerCP[ playerid ]++;
			if( CheckPoint[ eventid ][ nextcpid ][ CPX ] == 0.0 && CheckPoint[ eventid ][ nextcpid ][ CPY ] == 0 )
			{
				if( EventInfo[ Position ] <= 3 )
				{
					new Price = 0;
					EventInfo[ Position ]++;
					
					if( EventInfo[ Position ] == 1 )
					{
						PlayerInfo[ playerid ][ xEvent1Mesto ]++;
						Price = 3000;
					}
					if( EventInfo[ Position ] == 2 )
					{
						PlayerInfo[ playerid ][ xEvent2Mesto ]++;
						Price = 2000;
					}
					if( EventInfo[ Position ] == 3 )
					{
						PlayerInfo[ playerid ][ xEvent3Mesto ]++;
						Price = 1000;
					}
					
					DajIgracuNovac( playerid, Price );
					
					
					new strinsa[300];
					format( strinsa, sizeof( strinsa ), ""col_balkanstory"%s | {FFFFFF}Igrac %s je zavrsio sa pozicijom %d. | Nagrada: %d$", Event[ eventid ][ Name ],ImeIgraca( playerid ), EventInfo[ Position ],Price );
					SCMA( -1, strinsa );
					
					PlayerCP[ playerid ] = 0;
					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					SetPlayerVirtualWorld( playerid, 0 );
					TogglePlayerControllable( playerid, true );
					DisablePlayerRaceCheckpoint( playerid );
					
					Dimi_SetPlayerPos( playerid, PlayerPos[ playerid ][ 0 ], PlayerPos[ playerid ][ 1 ],  PlayerPos[ playerid ][ 2 ] );
					SetPlayerVirtualWorld( playerid, PlayerPosVW[ playerid ] );
					SetPlayerInterior( playerid, PlayerPosInt[ playerid ] );
					
					if( EventInfo[ Position ] == 3 ) {
					
						new strinss[300];
						format( strinss, sizeof( strinss ), ""col_balkanstory"%s | {FFFFFF} Event je zavrsen, cestitke pobjednicima!", Event[ eventid ][ Name ] );
						SCMA( -1, strinss );
					
						EventInfo[ Position ] = 0;
						EventInfo[ Drivers ] = 0;

						Event[ EventInfo[ eID ] ][ PrivremeniX1 ] = Event[ EventInfo[ eID ] ][ TCPX ];
						Event[ EventInfo[ eID ] ][ PrivremeniY1 ] = Event[ EventInfo[ eID ] ][ TCPY ];
						Event[ EventInfo[ eID ] ][ PrivremeniX2 ] = Event[ EventInfo[ eID ] ][ TCPX2 ];
						Event[ EventInfo[ eID ] ][ PrivremeniY2 ] = Event[ EventInfo[ eID ] ][ TCPY2 ];

						EventInfo[ eID ] = 0;

						for( new i = 0; i < 30; i++) {
							if( EventInfo[ Vehicle ][ i ] != INVALID_VEHICLE_ID ) SetVehicleToRespawn( EventInfo[ Vehicle ][ i ] );
						}

						for(new i; i < MAX_PLAYERS; i++){
							if( PlayerCP[ i ] > 0 ) {
							
								PlayerCP[ i ] = 0;
								SetPlayerVirtualWorld( i, 0 );
								TogglePlayerControllable( i, true );
								DisablePlayerRaceCheckpoint( i );
								PlayerEventVehID[ i ] = -1;

								Dimi_SetPlayerPos( i, PlayerPos[ i ][ 0 ], PlayerPos[ i ][ 1 ],  PlayerPos[ i ][ 2 ] );
								SetPlayerVirtualWorld( i, PlayerPosVW[ i ] );
								SetPlayerInterior( i, PlayerPosInt[ i ] );
							}
						}
					}
				}
				return 1;
			}
			if( nextcpid != Event[ eventid ][ MaxCP ] ) SetPlayerRaceCheckpoint( playerid, 0, CheckPoint[ eventid ][ nextcpid ][ CPX ], CheckPoint[ eventid ][ nextcpid ][ CPY ], CheckPoint[ eventid ][ nextcpid ][ CPZ ], CheckPoint[ eventid ][ nextcpid+1 ][ CPX ], CheckPoint[ eventid ][ nextcpid+1 ][ CPY ], CheckPoint[ eventid ][ nextcpid+1 ][ CPZ ], 7.0 );
			else SetPlayerRaceCheckpoint( playerid, 1, CheckPoint[ eventid ][ nextcpid ][ CPX], CheckPoint[ eventid ][ nextcpid ][ CPY ], CheckPoint[ eventid ][ nextcpid ][ CPZ ], CheckPoint[ eventid ][ nextcpid ][ CPX ], CheckPoint[ eventid ][ nextcpid ][ CPY ], CheckPoint[ eventid ][ nextcpid ][ CPZ ], 7.0 );
		}
	}
	
	if( TrkaCheckpoint[ playerid ] != 0 ) {
		switch( TrkaCheckpoint[ playerid ] ) {
			case 1: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
					TrkaCheckpoint[ playerid ] = 2;
					SetPlayerRaceCheckpoint( playerid, 0, -1456.4524, -282.5754, 1050.6942, -1396.2809, -190.8598, 1051.4340, 7.0 );
				}
			}
			case 2: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
					TrkaCheckpoint[ playerid ] = 3;
					SetPlayerRaceCheckpoint( playerid, 0, -1396.2809, -190.8598, 1051.4340, -1302.6482, -147.4566, 1050.1260, 7.0 );
				}
			}
			case 3: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
					TrkaCheckpoint[ playerid ] = 4;
					SetPlayerRaceCheckpoint( playerid, 0, -1302.6482, -147.4566, 1050.1260, -1297.8522, -263.9526, 1048.8831, 7.0 );
				}
			}
			case 4: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
					TrkaCheckpoint[ playerid ] = 5;
					SetPlayerRaceCheckpoint( playerid, 0, -1297.8522, -263.9526, 1048.8831, -1389.8533, -254.1669, 1043.3276, 7.0 );
				}
			}
			case 5: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
					TrkaCheckpoint[ playerid ] = 6;
					SetPlayerRaceCheckpoint( playerid, 1, -1389.8533, -254.1669, 1043.3276, -1431.3984, -129.8569, 1045.4110, 7.0 );
				}
			}
			case 6: {
				if( IsPlayerInVehicle( playerid, TrkaVozilo[ playerid ] ) && NaUtrci[ playerid ] && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
				
					SetPlayerRaceCheckpoint( playerid, 0, -1431.3984, -129.8569, 1045.4110, -1456.4524, -282.5754, 1050.6942, 7.0 );
					TrkaCheckpoint[ playerid ] = 1;

					Krugovi[ playerid ]++;
					SendClientMessageEx( playerid, 0x83BFBFAA, "-> || Trka || Krug %d/5 || %s || < -", Krugovi[ playerid ], ImeIgraca( playerid ) );
					if( Krugovi[ playerid ] == 5 ) {
						new izazivac = PonudioIgrac[ playerid ];

						DisablePlayerRaceCheckpoint( playerid );
						NaUtrci[ playerid ] = false; Krugovi[ playerid ] = 0; TrkaIzazov[ playerid ] = 0; StaroVreme[ playerid ] = 0;
						Dimi_DestroyVehicle( TrkaVozilo[ playerid ] ); TrkaVozilo[ playerid ] = -1;
						Dimi_SetPlayerPos( playerid, PlayerPos[ playerid ][ 0 ], PlayerPos[ playerid ][ 1 ],  PlayerPos[ playerid ][ 2 ] );
						SetPlayerVirtualWorld( playerid, PlayerPosVW[ playerid ] );
						SetPlayerInterior( playerid, PlayerPosInt[ playerid ] ); TrkaCheckpoint[ playerid ] = 0;
						DajIgracuNovac( playerid, ( UlogTrke[ playerid ]*2 ) );
						SendInfoMessage( playerid, "Pobedili ste na trci i osvojili %d$.", ( UlogTrke[ playerid ]*2 ) );

						if( izazivac != IPI ) {
						
							DisablePlayerRaceCheckpoint( izazivac );
							SendInfoMessage( izazivac, "Izgubili ste na trci i izgubili %d$.", UlogTrke[ playerid ] );
							NaUtrci[ izazivac ] = false; Krugovi[ izazivac ] = 0; TrkaIzazov[ izazivac ] = 0; StaroVreme[ izazivac ] = 0;
							Dimi_DestroyVehicle( TrkaVozilo[ izazivac ] ); TrkaVozilo[ izazivac ] = -1;
							Dimi_SetPlayerPos( izazivac, PlayerPos[ izazivac ][ 0 ], PlayerPos[ izazivac ][ 1 ],  PlayerPos[ izazivac ][ 2 ] );
							SetPlayerVirtualWorld( izazivac, PlayerPosVW[ izazivac ] );
							SetPlayerInterior( izazivac, PlayerPosInt[ izazivac ] ); TrkaCheckpoint[ izazivac ] = 0;
						}
					}
				}
			}
		}
	}
	return true;
}

public OnPlayerRequestSpawn( playerid )
{
	if( PlayerLogged[ playerid ] == true )
	{
		//PostaviSpawn( playerid );
		Dimi_SetSpawnInfo( playerid );
		SpawnPlayer( playerid );
	}
	else return false;
	return true;
}

public OnObjectMoved(objectid)
{
	return true;
}

public OnPlayerObjectMoved( playerid, objectid)
{
	return true;
}

public OnPlayerPickUpPickup( playerid, pickupid)
{
	return true;
}

public OnEnterExitModShop( playerid, enterexit, interiorid)
{
	if( enterexit == 1 ) {
		antiCheatCS[ playerid ][ InTuningGarage ] = true;
	}
	else if( enterexit == 0 ) {
		antiCheatCS[ playerid ][ InTuningGarage ] = false;
	}
	return 1;
}

public OnVehicleMod( playerid, vehicleid, componentid )
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	new i = ScriptIDVozila[ vehicleid ];
	if( antiCheatCS[ playerid ][ InTuningGarage ] )
	{
		if( TipVozila[ vehicleid ] == PRIVATNO_VOZILO )
		{
			if( strcmp( ImeIgraca( playerid ), VehicleInfo[ i ][ vOwner ], true) == 0 )
			{
				SavePlayerVehicleTuning( i, componentid );
				VehicleInfo[ i ][ vTuned ] = 1;
				if( !IsComponentidCompatible( GetVehicleModel( vehicleid ), componentid ) ) RemoveVehicleComponent( vehicleid, componentid);
			}
		}
	}
	else
	{
		if( !PlayerTuningCar[ playerid ] )
		{
			Dimi_DestroyVehicle( vehicleid );
			if( i != -1 )
			{
			
				VehicleInfo[ i ][ vID ] = Dimi_CreateVehicle( i, VehicleInfo[ i ][ vUsage ], VehicleInfo[ i ][ vOrganization ], VehicleInfo[ i ][ vJob ], VehicleInfo[ i ][ vFuelProperty ], VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ]+1.0, VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vVirtualWorld ] );
				vCanDrive[ VehicleInfo[ i ][ vID ] ] = 1;

				if( VehicleInfo[ i ][ vUsage ] == POSLOVNO_VOZILO ) {
					VehicleInfo[ i ][ vFuel ] = 100;
					Fuel[ VehicleInfo[ i ][ vID ] ] = 100;
				}

				GetVehicleParamsEx( vehicleid, engine, lights, alarm, doors, bonnet, boot, objective );
				SetVehicleParamsEx( vehicleid, 0, lights, alarm,doors, 0, 0, objective );
			}
			SendClientMessagee( playerid, -1, "Ukoliko mislis da si kickovan greskom slikaj ovo i postavi na forum!");
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Tuning hack", ImeIgraca( playerid ) );
			SendClientMessageToAll( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Tuning hack");
			return 1;
		}
	}
	return true;
}

public OnVehiclePaintjob( playerid, vehicleid, paintjobid)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	new i = ScriptIDVozila[ vehicleid ];
	if( antiCheatCS[ playerid ][ InTuningGarage ] ) {
		if( TipVozila[ vehicleid ] == PRIVATNO_VOZILO ) {
			if( strcmp( ImeIgraca( playerid ), VehicleInfo[ i ][ vOwner ], true) == 0 ) {
				VehicleInfo[ i ][ vPaintJob ] = paintjobid;
				VehicleInfo[ i ][ vTuned ] = 1; SaveVehicle( i );
			}
		}
	}
	else {
		if( !PlayerTuningCar[ playerid ] ) {
			Dimi_DestroyVehicle( vehicleid );
			if( i != -1 ) {
				VehicleInfo[ i ][ vID ] = Dimi_CreateVehicle( i, VehicleInfo[ i ][ vUsage ], VehicleInfo[ i ][ vOrganization ], VehicleInfo[ i ][ vJob ], VehicleInfo[ i ][ vFuelProperty ], VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ]+1.0, VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vVirtualWorld ] );
				vCanDrive[ VehicleInfo[ i ][ vID ] ] = 1;


				if( VehicleInfo[ i ][ vUsage ] == POSLOVNO_VOZILO ) {
					VehicleInfo[ i ][ vFuel ] = 100;
					Fuel[ VehicleInfo[ i ][ vID ] ] = 100;
				}


				GetVehicleParamsEx( vehicleid, engine, lights, alarm, doors, bonnet, boot, objective );
				SetVehicleParamsEx( vehicleid, 0, lights, alarm,doors, 0, 0, objective );
			}
			SendClientMessagee( playerid, -1, "Ukoliko mislis da si kickovan greskom slikaj ovo i postavi na forum!");
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Tuning hack", ImeIgraca( playerid ) );
			SendClientMessageToAll( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Tuning hack");
			return 1;
		}
	}
	return true;
}

public OnVehicleRespray( playerid, vehicleid, color1, color2) 
{
	new i = ScriptIDVozila[ vehicleid ];
	if( TipVozila[ vehicleid ] == PRIVATNO_VOZILO ) {
		if( strcmp( ImeIgraca( playerid ), VehicleInfo[ i ][ vOwner ], true) == 0 ) {
			VehicleInfo[ i ][ vColor1 ] = color1;
			VehicleInfo[ i ][ vColor2 ] = color2;
			SaveVehicle( i );
		}
	}
	return true;
}

forward __check( playerid );
public __check( playerid )
{
	if( GetPlayerSpecialAction( playerid ) == SPECIAL_ACTION_DUCK )
		return 1;

	new Float:Zivot;
	GetPlayerHealth( playerid, Zivot );
	Dimi_SetPlayerHealth( playerid, Zivot-30 );

	announcement( playerid, "~r~Prestani da radis C-Bug!", 1000, 3 );

	antiCheatCS[ playerid ][ LastWShot ] = -1;

	return 1;
}

stock IsCbugWeapon( playerid ) 
{
	new weaponID = GetPlayerWeapon( playerid );
	if( weaponID == 22 || weaponID == 24 || weaponID == 25 || weaponID == 27 ) {
		return true;
	}
	return false;
}

GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance) 
{
	new Float:a;
	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);
	if (GetPlayerVehicleID(playerid))
	{
	  GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	}
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

forward CheckSnow( playerid );
public CheckSnow( playerid ) {

	Shoot[ playerid ] = 0;
	for( new i = 0; i < 30; i++ ) {

		new Float:X, Float:Y;
		GetXYInFrontOfPlayer( playerid, X, Y, i );

		for( new z = 0; z < MAX_PLAYERS; z++ ) {
		
			if( z != playerid && Shoot[ playerid ] == 0 && AlreadyShooted[ z ] == false ) {
			
				if( IsPlayerInRangeOfPoint( z, 1.0, X, Y, 9.69999981 ) ) {
				
					Shoot[ playerid ] = 0;

					new Float:pX, Float:pY, Float:pZ, Float:tX, Float:tY, Float:tZ;
					GetPlayerPos( playerid, pX, pY, pZ );
					GetPlayerPos( z, tX, tY, tZ );
					Obj[ z ] = CreateObject( 2709, pX, pY, pZ+0.5,0.0,0.0,0.0,30);
					MoveObject( Obj[ z ], tX, tY, tZ-0.9, 25.0 );
					
					AlreadyShooted[ z ] = true;
					SetTimerEx( "SkiniSnegGrudavnje", 2000, false, "i", z );
					
					new string[ 128 ];
					format( string, sizeof( string ), "{6ef83c}GRUDVANJE | "col_white"%s je pogodio %s.", ImeIgraca( playerid ), ImeIgraca( z ) );
					GrudvanjePoruka( -1, string );

					Charged[ playerid ] = 0;
					
					ApplyAnimation( playerid, "GRENADE", "WEAPON_throw", 4.1, 0, 1, 1, 0, 1000, 1 );
					ApplyAnimation( z, "PED", "KO_skid_front", 4.1, 0, 1, 1, 0, 2000, 1 );
				}
			}
		}
	}
	//if( Shoot[ playerid ] == 0 ) announcement(playerid,"~R~Nema ~G~Mete~y~!",1000,1);
	return 1;
}

animacijabh(playerid); public animacijabh(playerid)
{
	LoopingAnim(playerid,"PED","IDLE_tired",3.0,1,0,0,0,0);
}

stock PreloadAnimationLibrary(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0, 1);
}

SelectTextdrawSys(player);
public SelectTextdrawSys(player)
{
	if(PosaoTDShowed[ player ] == true ||
		MessageBoxShowed[ player ] == true ||
		StatsTDShowed[ player ] == true ||
		OdjecaTDShowed[ player ] == true ||
		PUBGTDShowed[ player ] == true || 
		BuyCarTDShowed[ player ] == true  || 
		BojaVozilaTDShowed[ player ] == true ||
		LogRegShowed[player] == 1)
	{
		SelectTextDraw( player, UGBOJA );
	}
	return 1;
}

public ResprayTimer( playerid, autoid )
{
	Dimi_KillTimer( FarbanjeTimer[ playerid ] );
	if( !IsPlayerInVehicle( playerid, VehicleInfo[ autoid ][ vID ] ) ) return GRESKA( playerid, "Morate biti u svom vozilu!");
	new repairman = GetPVarInt( playerid, "ResprayOffer" );
	new newkeys,ud,lr;
	GetPlayerKeys( repairman, newkeys, ud, lr );
	if( HOLDING( KEY_FIRE ) )
	{
		if( GetPVarInt( playerid, "ResprayOffer" )  < 999 )
		{
			if( PlayerInfo[ playerid ][ xNovac ] >= GetPVarInt( playerid, "ResprayPrice" ) )
			{
				if( IsPlayerInAnyVehicle( playerid ) )
				{
					if( IsPlayerConnected( repairman ) )
					{
						if( PlayerInfo[ repairman ][ xMDelovi ] < 5 )
						{
							SendClientMessagee( repairman, CRVENA, "Nemate delova!");
							SendClientMessagee( playerid, CRVENA, "Mehanicar nema delova!");
							return 1;
						}
						else
						{
							if( IsPlayerInRangeOfPoint( playerid, 15.0, 1978.9244, -1585.0405, 13.3126 ) )
							{
								if( IsPlayerNearPlayer( 10.0, playerid, repairman ) )
								{
									//if( VehicleInfo[ autoid ][ vUsage ] != PRIVATNO_VOZILO ) return GRESKA( playerid, "Mozete farbati samo privatna vozila." );
									if( strcmp( ImeIgraca( playerid ), VehicleInfo[ autoid ][ vOwner ], true) == 0 )
									{
										VehicleInfo[ autoid ][ vColor1 ] = ResprayColor1[ repairman ];
										VehicleInfo[ autoid ][ vColor2 ] = ResprayColor2[ repairman ];
										ChangeVehicleColor( GetPlayerVehicleID( playerid ), ResprayColor1[ repairman ], ResprayColor2[ repairman ] );
										SaveVehicle( autoid );

										SendClientMessageEx( playerid, SVETLOPLAVA, "* Vase vozilo je prefarbano za $%d od strane AutoMehanicara %s.", GetPVarInt( playerid, "ResprayPrice" ), ImeIgraca( repairman ) );
										SendClientMessageEx(repairman, SVETLOPLAVA, "* Prefarbali ste  %s vozilo. Zaradili ste $%d.", ImeIgraca( playerid ), GetPVarInt( playerid, "ResprayPrice" ) );

										PlayerInfo[ repairman ][ xMehSkill ] += 1;
										if(PlayerInfo[ repairman ][ xMehSkill ] == 50)
										{ SendClientMessagee(repairman, ZUTA, "* Vasa vestina kao Auto Mehanicar sada je Level 2, sada imate vise opcija u svom poslu."); }
										else if(PlayerInfo[ repairman ][ xMehSkill ] == 100)
										{ SendClientMessagee(repairman, ZUTA, "* Vasa vestina kao Auto Mehanicar sada je Level 3, sada imate vise opcija u svom poslu."); }
										else if(PlayerInfo[ repairman ][ xMehSkill ] == 200)
										{ SendClientMessagee(repairman, ZUTA, "* Vasa vestina kao Auto Mehanicar sada je Level 4, sada imate vise opcija u svom poslu."); }
										else if(PlayerInfo[ repairman ][ xMehSkill ] == 400)
										{ SendClientMessagee(repairman, ZUTA, "* Vasa vestina kao Auto Mehanicar sada je Level 5, sada imate vise opcija u svom poslu."); }

										PlayerInfo[ repairman ][ xMDelovi ] -= 5;
										DajIgracuNovac( repairman, GetPVarInt( playerid, "ResprayPrice" ) );
										DajIgracuNovac( playerid, -GetPVarInt( playerid, "ResprayPrice" ) );
										BussinesJobMoney( POSAO_MEHANICAR, (GetPVarInt( playerid, "ResprayPrice" )/10) );
										SetPVarInt( playerid, "ResprayOffer", 999 );
										SetPVarInt( playerid, "ResprayPrice", 0 );
										SetPVarInt( playerid, "ResprayvID", -1 );
										SetPVarInt( repairman, "ResprayvID", -1 );
										SetPVarInt( repairman, "ResprayDozvola", 999 );
										SetPVarInt( repairman, "RespraySpray", 0 );
										ResprayColor1[ repairman ] = -1;
										ResprayColor2[ repairman ] = -1;
										RemovePlayerWeapon( repairman, 41 );
									}
									else GRESKA( playerid, "Nisi vlasnik ovog vozila!");
								} else GRESKA( playerid, "Nisi blizu igraca koji ti je ponudio popravku guma vozila!");
							} else SendClientMessagee( playerid, CRVENA, "Auto mozete farbati samo u mehanicarskoj garazi!");
						}
					}
					return 1;
				}
				return 1;
			} else GRESKA( playerid, "Nemate dovoljno novca!" );
		}
	}
	return 1;
}


forward deathafterinjury(playerid);
public deathafterinjury(playerid)
{
	new death_health;
	death_health = 0;
	Dimi_SetPlayerHealth(playerid,death_health);
	hideinjuredtd(playerid);
	hidehb(playerid);
	Ranjen[playerid] = 0;
	//SetTimerEx( "PocetniTut", 35000, false, "ii", playerid, 1 );
	return 1;
}

animbre(playerid); public animbre(playerid)
{
	if(Ranjen[playerid] == 0)
	{
		KillTimer(animtimer2[playerid]);
	}

	LoopingAnim(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}


public OnPlayerStreamIn( playerid, forplayerid ) 
{
	if( Maskuse[ forplayerid ] == true ) {
		if( PlayerInfo[ playerid ][ xAdmin ] > 0 && AdminDuty[ playerid ] )
			ShowPlayerNameTagForPlayer( playerid, forplayerid, true );
		else
			ShowPlayerNameTagForPlayer( playerid, forplayerid, false );
	}
	else {
		ShowPlayerNameTagForPlayer( playerid, forplayerid, true );
	}
	return true;
}

public OnPlayerStreamOut( playerid, forplayerid)
{
	return true;
}

public OnVehicleStreamIn( vehicleid, forplayerid)
{
	return true;
}

public OnVehicleStreamOut( vehicleid, forplayerid)
{
	return true;
}

public ZaustaviWAR( w ) 
{
	WARInfo[ w ][ WARAktivan ] = false;
	WARInfo[ w ][ WARKreiranje ] = false;
	Dimi_KillTimer( WARInfo[ w ][ WARTimer ] );
	
	if( WARInfo[ w ][ WARTimSkor ][ 0 ] > WARInfo[ w ][ WARTimSkor ][ 1 ] ) {
		DajIgracuNovac( WARInfo[ w ][ WARTimLider ][ 0 ], (WARInfo[ w ][ WARCena ]*2) );
	}

	if( WARInfo[ w ][ WARTimSkor ][ 1 ] > WARInfo[ w ][ WARTimSkor ][ 0 ] ) {
		DajIgracuNovac( WARInfo[ w ][ WARTimLider ][ 1 ], (WARInfo[ w ][ WARCena ]*2) );
	}
	
	if( WARInfo[ w ][ WARTimSkor ][ 0 ] == WARInfo[ w ][ WARTimSkor ][ 1 ] ) {
		DajIgracuNovac( WARInfo[ w ][ WARTimLider ][ 0 ], WARInfo[ w ][ WARCena ] );
		DajIgracuNovac( WARInfo[ w ][ WARTimLider ][ 1 ], WARInfo[ w ][ WARCena ] );
	}
	
	for(new i; i < MAX_PLAYERS; i++) {
		if( WARPInfo[ i ][ WARIgrac ] == w ) {

			if( WARInfo[ w ][ WARTimSkor ][ 0 ] > WARInfo[ w ][ WARTimSkor ][ 1 ] ) {
				if( WARPInfo[ i ][ WARTim ][ 0 ] ) {
					SendClientMessageEx( i, -1, "{FFAF00}WAR {FFFFFF}| {FFAF00}Pobedili ste i vasa organizacija je dobila {FFFFFF}%d!", (WARInfo[ w ][ WARCena ]*2) );
				}
			}

			if( WARInfo[ w ][ WARTimSkor ][ 1 ] > WARInfo[ w ][ WARTimSkor ][ 0 ] ) {
				if( WARPInfo[ i ][ WARTim ][ 1 ] ) {
					SendClientMessageEx( i, -1, "{FFAF00}WAR {FFFFFF}| {FFAF00}Pobedili ste i vasa organizacija je dobila {FFFFFF}%d!", (WARInfo[ w ][ WARCena ]*2) );
				}
			}


			new string[ 128 ];
			SendClientMessagee( i, -1, string );
			format( string, sizeof( string ), ""col_orange"WAR "col_white"| "col_orange"Tvoj Skor "col_white"|  "col_orange"Ubistva: "col_white"%d "col_white"| "col_orange"Smrti: "col_white"%d", WARPInfo[ i ][ WARUbistva ], WARPInfo[ i ][ WARSmrti ] );
			SendClientMessagee( i, -1, string);
			format( string, sizeof( string ), ""col_orange"WAR "col_white"| "col_orange"Tim 1: "col_white"%s "col_white"| "col_orange"Tim 2: "col_white"%s", getOrgName( WARInfo[ w ][ WARTeamID ][ 0 ] ), getOrgName( WARInfo[ w ][ WARTeamID ][ 1 ] ) );
			SendClientMessagee( i, -1, string );
			format( string, sizeof( string ), ""col_orange"WAR zavrsen "col_white"| {F81414}Tim 1: "col_white"%d | "col_balkanstory"Tim 2: "col_white"%d", WARInfo[ w ][ WARTimSkor ][ 0 ], WARInfo[ w ][ WARTimSkor ][ 1 ]  );
			SendClientMessagee( i, -1, string );

			Dimi_SetPlayerHealth( i, 100 );
			Dimi_SetPlayerArmour( i, 0 );

			antiCheatCS[ i ][ TeleportCheck ] = 4;
			antiCheatCS[ i ][ WeaponDetect ] = 3;

			Dimi_SetPlayerPos( i, PozicijaWAR[ i ][ 0 ], PozicijaWAR[ i ][ 1 ],  PozicijaWAR[ i ][ 2 ] );
			SetPlayerVirtualWorld( i, VirtualWWAR[ i ] );
			SetPlayerInterior( i, InteriorWAR[ i ] );

			ResetAllWeapons( i );

			WARPInfo[ i ][ WARIgrac ] = -1;

			ResetujWarIgraca( i );

			WarTDControl( i, false );
		}
	}
	WARInfo[ w ][ WARCena ] = 0;
	WARInfo[ w ][ WARMaxClanova ] = 0;
	WARInfo[ w ][ WARTimClanovi ][ 0 ] = 0;
	WARInfo[ w ][ WARTimClanovi ][ 1 ] = 0;
	WARInfo[ w ][ WARTimSkor ][ 0 ] = 0;
	WARInfo[ w ][ WARTimSkor ][ 1 ] = 0;
	WARInfo[ w ][ WARTeamID ][ 0 ] = -1;
	WARInfo[ w ][ WARTeamID ][ 1 ] = -1;
	return true;
}

public TimerWAROstaloVremeB( w ) 
{
	if( WARInfo[ w ][ WARAktivan ] == false ) { WARInfo[ w ][ TimerWARMin ] = 1; WARInfo[ w ][ TimerWARSec ] =0; Dimi_KillTimer( WARInfo[ w ][ TimerWAROstaloVreme ] ); }
	WARInfo[ w ][ TimerWARSec ]++;
	if( WARInfo[ w ][ TimerWARSec ] == 60 ) { WARInfo[ w ][ TimerWARMin ]++; WARInfo[ w ][ TimerWARSec ] = 0; }
	for(new i; i < MAX_PLAYERS; i++) {
		if( WARPInfo[ i ][WARIgrac] == w ) {
			new vreme_string[ 10 ];
			if( WARInfo[ w ][ TimerWARSec ] >= 51 ) {
				format( vreme_string, sizeof( vreme_string ), "%d:0%d",10*60000/60000 - WARInfo[ w ][ TimerWARMin ], 10*60000/10000 - WARInfo[ w ][ TimerWARSec ] );
			}
			else if( WARInfo[ w ][ TimerWARMin ] >= 6 ) {
				format( vreme_string, sizeof( vreme_string ), "0%d:%d",10*60000/60000 - WARInfo[ w ][ TimerWARMin ], 10*60000/10000 - WARInfo[ w ][ TimerWARSec ] );
			}
			else if( WARInfo[ w ][ TimerWARSec ] >= 51 && WARInfo[ w ][ TimerWARMin ] >= 6) {
				format( vreme_string, sizeof( vreme_string ), "0%d:0%d",10*60000/60000 - WARInfo[ w ][ TimerWARMin ], 10*60000/10000 - WARInfo[ w ][ TimerWARSec ] );
			}
			else {
				format( vreme_string, sizeof( vreme_string ), "%d:%d",10*60000/60000 - WARInfo[ w ][ TimerWARMin ], 10*60000/10000 - WARInfo[ w ][ TimerWARSec ] );
			}
			PlayerTextDrawSetString( i, WARTextDraw[ i ][ 8 ],  vreme_string );
		}
	}
	return 1;
}

stock GetPlayerIdFromName( playername[] )
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if( IsPlayerConnected( i ) )
		{
			new playername2[ MAX_PLAYER_NAME ] ;
			GetPlayerName(i, playername2, sizeof( playername2));
			if( strcmp( playername2, playername, true, strlen( playername) ) == 0 )
			{
				return i;
			}
		}
	}
	return INVALID_PLAYER_ID;
}

public OnPlayerClickPlayer( playerid, clickedplayerid, source )
{
	new string[ 256 ], name[ MAX_PLAYER_NAME ];
	GetPlayerName( clickedplayerid, name, sizeof( name ) );
	
	format( string, sizeof( string ), ""col_balkanstory"Ime: {FFFFFF}%s\n"col_balkanstory"Telefon: {FFFFFF}%d\n"col_balkanstory"Level: {FFFFFF}%d\n"col_balkanstory"Ping: {FFFFFF}%d", name, PlayerInfo[ clickedplayerid ][ xBrojTelefona ],PlayerInfo[ clickedplayerid ][ xLevel ],GetPlayerPing(clickedplayerid) );
	ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, string, "U redu", "" );
	return true;
}

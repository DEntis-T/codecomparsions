
public OnPlayerUpdate( playerid )
{
	CallLocalFunction("NERP_ONPLAYERUPDATE", "i", playerid);

	/*for( new b = 0; b < MAX_DEALERS; b++ )
	{
        if( IsPlayerInRangeOfPoint( playerid, 10.0, 
        	DealerInfo[b][dealerPos][0],
        	DealerInfo[b][dealerPos][1],
        	DealerInfo[b][dealerPos][2] ) )
        {
        	Dileri3D(b, false, playerid);
        }
	}*/
	
	new weapon_found = -1;
	for( new a = 0; a < MAX_GOBJ; a++ )
	{
		if( IsPlayerInRangeOfPoint( playerid, 5.0, 
			dGunData[ a ][ ObjPos ][ 0 ], 
			dGunData[ a ][ ObjPos ][ 1 ], 
			dGunData[ a ][ ObjPos ][ 2 ] ) )
		{
			if(PlayerInfo[playerid][xPUBG] == 1)
			{
				if(dGunData[a][PUBG] == 0) weapon_found = -1;
				else if(dGunData[a][PUBG] == 1) weapon_found = a;
			}
			else if(PlayerInfo[pid][xPUBG] == 0)
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

			ShowPlayerNearbyItem(playerid, true,
				WeaponInfos[ found_weaponid ][ wTXDName ],
				WeaponInfos[ found_weaponid ][ wName ],
				WeaponInfos[ found_weaponid ][ wAmmoName ],
				dGunData[ weapon_found ][ ObjData ][ 1 ]);
		}
	}

	
	if(GetPlayerPing(playerid) > 100)
	{
		SendScreenMessage(playerid, "Imate probleme sa internetom, molimo sacekajte!");
	}
	if(AdminDuty[playerid] && IsPlayerInAnyVehicle(playerid))
	{
		new Float:X, Float:Y, Float:Z;
		GetPlayerPos( playerid, X, Y, Z );
		//GetVehicleZAngle( GetPlayerVehicleID( playerid ), A );
		//SetVehicleZAngle( GetPlayerVehicleID( playerid ), A );
		Dimi_RepairVehicle( playerid, GetPlayerVehicleID( playerid ) );
		Dimi_SetVehicleHealth( GetPlayerVehicleID( playerid ), 1000.0 );
		//antiCheatCS[ playerid ][ VehRepairTime ] = 3;
		vCanDrive[ GetPlayerVehicleID( playerid ) ] = 1;
	}
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		new weap = GetPlayerWeapon(playerid);

		if(weap != 0)
		{
			PlayerTextDrawHide(pid,OruzjeIgraca[playerid][4]);
			new ammo[10];
			format(ammo, sizeof ammo, "%i", GetPlayerAmmo(pid));
			PlayerTextDrawSetString(pid, OruzjeIgraca[playerid][4], ammo);
			PlayerTextDrawShow(pid,OruzjeIgraca[playerid][4]);
		}

	    if(HoldingWeapon[playerid] != weap)
	    {
	        // CallLocalFunction("OnPlayerWeaponChange", "iii", playerid, HoldingWeapon[playerid], weap);
	    	if(weap != 0)
		    {
		    	WeaponTextDrawControl(playerid, false);
		    	PlayerTextDrawSetString(pid, OruzjeIgraca[playerid][1], 
		    		WeaponInfos[ GetPlayerWeapon(pid) ][ wTXDName ]);
		    	//ime oruzja:OruzjeIgraca[playerid][2]
		    	new ammoname[20];
				Weapon_GetAmmoName(weap, ammoname);
				PlayerTextDrawSetString(pid, OruzjeIgraca[playerid][5], ammoname);
				//ammo: OruzjeIgraca[playerid][4]
				PlayerTextDrawSetString(pid, OruzjeIgraca[playerid][2], 
					WeaponInfos[ GetPlayerWeapon(pid) ][ wName ]);
				WeaponTextDrawControl(playerid, true);
			}
			else if(weap == 0)
			{
				//PlayerTextDrawSetPreviewModel(pid, OruzjeIgraca1[pid], WeaponInfos[ GetPlayerWeapon(pid) ][ wModel ]);
		    	WeaponTextDrawControl(playerid, false);
		    }
	    }
	    HoldingWeapon[playerid] = weap;
	}
	else if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		WeaponTextDrawControl(playerid, false);
	}
	if(PlayerLogged[pid] == true && ClientType[playerid] == CLIENT_PC)
	{
		PlayerTextDrawShow(pid,MoneyBar[pid]);
		//if(PlayerInfo[pid][xDeathScreen] == 1) PlayerTextDrawHide(pid,LevelIgraca[pid]);
		//if(PlayerInfo[pid][xDeathScreen] == 0) PlayerTextDrawShow(pid,LevelIgraca[pid]);
	}
	if(PlayerInfo[pid][xPUBG] == 1)
	{
		if(PUBGenum[xIgraMatch] == 1)
		{
			announcement(pid,"Winner Winner Chicken Dinner - cestitamo!");
			PlayerInfo[pid][xPUBG] = 0;
			new winner_title[300];
			//PUBGenum[xIgraMatch] = 0;
			format(winner_title,sizeof(winner_title),
				""col_balkanstory"[PUBG INFO]{ffffff}: Pobjednik PUBG eventa je %s - cestitamo!",
				ImeIgraca(pid));
			SCMA(-1,winner_title);
			new nagrada = random(10000)+5000;
			SendInfoMessage(pid,"Match se zavrsava za 10 sekundi.");
			DajIgracuNovac(pid,nagrada);
			SendInfoMessage(pid,"Dobio si $%i kao nagradu za pobjedu!",nagrada);
			endmatch[pid] = SetTimerEx("matchend", 10000, false, "ii", playerid, 1);
		}
	}
	//new i = playerid;
	new Float:health, health_string[100];
	GetPlayerHealth(pid,health);
	if(PlayerLogged[pid] == true) {
		format(health_string,sizeof(health_string),"HEALTH: %.0f",health);
		PlayerTextDrawSetString(pid,phealthbar0[pid],health_string);
	}
	if(!BRACETMLogoShowed[playerid] && PlayerLogged[playerid])
	{
		if( Ranjen[pid] == 1 )
		{
			phidehb(pid);
			showhb(pid);
		}
		else if( Ranjen[pid] == 0 )
		{
			hidehb(pid);
			pshowhb(pid);
		}
	}
	PlayerTextDrawSetPreviewModel(pid,SkinIgraca[pid], PlayerInfo[pid][xSkin]);
	new Float:player_health;
	GetPlayerHealth(playerid,player_health);
	if(Ranjen[playerid] == 0 && player_health <= 30 && player_health > 0 )
	{
		SetPlayerChatBubble( pid, "(( Ovaj igrac je trenutno ranjen... Umire tacno za 20 sekundi! - /pomozi ))", PLAVA, 40.0, 10000);
		RemovePlayerFromVehicle(playerid);
		TogglePlayerControllable(playerid,0);
		LoopingAnim(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
		Dimi_SetPlayerHealth(playerid,100);
		SendInfoMessage(pid,"Ranjen si i ne mozes se kretati, umires za 20s.");
		DeathAfterInjury[playerid] = SetTimerEx( "deathafterinjury", 20000, false, "i", playerid );
		Ranjen[pid] = 1;
		showhb(pid);
		animtimer2[pid] = SetTimerEx("animbre", 100, false, "i", playerid); 
		showinjuredtd(pid);
	}
	// org vozila announcement
	if(!IsPlayerInAnyVehicle(playerid) && PlayerLogged[playerid])
	{
		new vehicleid, 
			found = 0, 
			org_veh_annc[256];
	    for( new i = 0; i < MAX_VEHICLES; i++ )
		{
	        new Float:x, Float:y, Float:z;
	        GetVehiclePos( i, x, y, z );
	        if( IsPlayerInRangeOfPoint( playerid, 5.0, x, y, z ) )
			{
	            vehicleid = i;
	            found = 1;
	            break;
	        }
	        else
	        {
	        	continue;
	        }
	    }
	    if(found == 1)
		{
			if(VehicleInfo[ vehicleid ][ vUsage ] == ORGANIZACIJSKO_VOZILO)
			{
				if(LastOrgVehDetected[playerid] != vehicleid)
				{
			        format(org_veh_annc,sizeof org_veh_annc, "%s~w~ (%i)~n~%s",
			        	GetVehicleNameEx( GetVehicleModel( vehicleid ) ),
			        	vehicleid,
			        	OI[ VehicleInfo[ vehicleid ][ vOrganization ] ][ oPreFix ]);
			        announcement(playerid,org_veh_annc);
			        OrgVehAnncSeen[playerid] = true;
			        LastOrgVehDetected[playerid] = vehicleid;
			    }
		    }
	    }
	}
	//brzinomjer
    if( IsPlayerInAnyVehicle( playerid ) && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER )
    {
	    new vehicle = GetPlayerVehicleID( playerid );
	    new string[ 30 ];
	    new stringic[ 30 ];
	    new stringic1[ 30 ];
	    new stringic123[ 30 ];
	    new Float:H; GetVehicleHealth( vehicle, H );
		new motor,
			svjetla, 
			alarm, 
			vrata, 
			hauba, 
			tockovi, 
			objective;

	    if(IsVehicleBajs( vehicle ))// && !IsVehicleBrod( vehicle ) && !IsVehicleLetelica( vehicle ) ) 
	    {
			format( string, sizeof( string ), "%d km/h", GetSpeed( playerid ) );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][8], string );
			format( stringic, sizeof( stringic ), "N / A");
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][11], stringic );
			
			format( stringic1, sizeof( stringic1 ),"N / A");
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][14], stringic1 );

			GetVehicleParamsEx(vehicle, motor, svjetla, alarm, vrata, hauba, tockovi, objective);

			format( stringic123, sizeof( stringic123 ), "%.0f",H);
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][15], stringic123 ); 
		}
		if(IsVehicleBrod( vehicle ))// && !IsVehicleBrod( vehicle ) && !IsVehicleLetelica( vehicle ) ) 
	    {
			format( string, sizeof( string ), "%d km/h", GetSpeed( playerid ) );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][8], string );
			format( stringic, sizeof( stringic ), "%d l", Fuel[ vehicle ] );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][11], stringic );
			format( stringic1, sizeof( stringic1 ), "N / A");
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][14], stringic1 );

			GetVehicleParamsEx(vehicle, motor, svjetla, alarm, vrata, hauba, tockovi, objective);

			format( stringic123, sizeof( stringic123 ), "%.0f",H);
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][15], stringic123 ); 
		}
		if(IsVehicleLetelica( vehicle ))// && !IsVehicleBrod( vehicle ) && !IsVehicleLetelica( vehicle ) ) 
	    {
			format( string, sizeof( string ), "%d km/h", GetSpeed( playerid ) );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][8], string );
			format( stringic, sizeof( stringic ), "%d l", Fuel[ vehicle ] );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][11], stringic );
			format( stringic1, sizeof( stringic1 ), "N / A");
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][14], stringic1 );

			GetVehicleParamsEx(vehicle, motor, svjetla, alarm, vrata, hauba, tockovi, objective);

			format( stringic123, sizeof( stringic123 ), "%.0f",H);
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][15], stringic123 ); 
		}
		else
		{
			format( string, sizeof( string ), "%d km/h", GetSpeed( playerid ) );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][8], string );
			
			format( stringic, sizeof( stringic ), "%d l", Fuel[ vehicle ] );
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][11], stringic );
			format( stringic1, sizeof( stringic1 ), "%s", GetVehicleFuelType(vehicle));
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][14], stringic1 );

			GetVehicleParamsEx(vehicle, motor, svjetla, alarm, vrata, hauba, tockovi, objective);

			format( stringic123, sizeof( stringic123 ), "%.0f",H);
			PlayerTextDrawSetString( playerid, KILOMETARSATTD[ playerid ][15], stringic123 ); 
		}
	}
    if( RadioAktiviran[ playerid ] == 1 && !IsPlayerInAnyVehicle( playerid ) ) return RadioAktiviran[ playerid ] = 0, StopAudioStreamForPlayer( playerid );
    if( AdminDuty[ playerid ] ) {
		new Float:H; GetPlayerHealth( playerid, H );
		new Float:Armour; GetPlayerArmour( playerid, Armour );
		if( H < 99.0 )	Dimi_SetPlayerHealth( playerid, 100 );
		if( Armour < 99.0 )	Dimi_SetPlayerArmour( playerid, 100 );
	}

	if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && antiCheatCS[ playerid ][ RemoveVehicle ] == false ) {
		if( GetPlayerVehicleID( playerid ) != antiCheatCS[ playerid ][ EnteredVehicle ] && GetPlayerVehicleID( playerid ) > 0 ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc SPAM/Port vozila!!! || "SERVERBOJA_AQUA"%s[ID: %d] |LVL: |%d|"col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ] );
			AdminPoruka( -1, globalstring );
			Dimi_RemovePlayerFromVehicle( playerid );
		}
	}

	if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
	
        for( new i = 0; i < sizeof( Roadblocks ); i++ ) {
        
			if( IsPlayerInRangeOfPoint( playerid, 3.0, Roadblocks[ i ][ sX ], Roadblocks[ i ][ sY ], Roadblocks[ i ][ sZ ] ) ) {

				if( Roadblocks[ i ][ sCreated ] == 1 && Roadblocks[ i ][ sSpike ] ) {
                
                    new panels, tires, doors, lights;
                    new carid = GetPlayerVehicleID( playerid );
					GetVehicleDamageStatus( carid, panels, doors, lights, tires );
					UpdateVehicleDamageStatus( carid, panels, doors, lights, 15 );
					return 0;
				}
			}
		}
    }

  	if( GetPlayerCameraMode( playerid ) == 53 ) {
        new Float:kLibPos[ 3 ];
        GetPlayerCameraPos( playerid, kLibPos[ 0 ], kLibPos[ 1 ], kLibPos[ 2 ] );
        if( kLibPos[ 2 ] < -50000.0 || kLibPos[ 2 ] > 50000.0 ) {
            format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Weapon Crash", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Weapon Crash");
            return 0;
        }
    }
	
	if( PlayerLogged[ playerid ] == true )
	{
	
	    #if NERP_ZIMSKI_MOD  == 1
		if( Snow[ playerid ] ) {
		
	        if( GetPlayerInterior( playerid ) == 0 && GetPlayerVirtualWorld( playerid ) == 0 ) {

				new Float:Pos[ 3 ];
	        	GetPlayerCameraPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
	        	MovePlayerObject( playerid, SnowObject[ playerid ], Pos[ 0 ], Pos[ 1 ], Pos[ 2 ]-2.5, 4000.0 );
	        }
	  	}
  		#endif
	}
	
	static
		Float: X, 	Float: Y, 	Float: Z,
		Float: vX,	Float: vY, 	Float: vZ;
	
	if( IsPlayerInAnyVehicle( playerid ) && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
		GetPlayerPos( playerid, X, Y, Z );
  		GetVehicleVelocity( GetPlayerVehicleID( playerid ), vX, vY, vZ );
		if( ( vX > 3.0 || vY > 3.0 || vZ > 3.0 || vX < -3.0 || vY < -3.0 || vZ < -3.0 ) && ( vX != X && vY != Y && vZ != Z ) ) {
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s je kickovan sa servera. Razlog: "col_white"Cleo Car Swing", ImeIgraca( playerid ) );
			AdminPoruka( SVETLOCRVENA, globalstring );
			Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Cleo Car Swing");
			return 1;
		}
	}
	
  	if( flymodecamera[ playerid ][ cameramode ] == true ) {
		new keys,ud,lr;
		GetPlayerKeys(playerid,keys,ud,lr);

		if(flymodecamera[ playerid ][mode] && (GetTickCount() - flymodecamera[ playerid ][ lastmove ] > 100))
		{
		    MoveCamera(playerid);
		}
		if(flymodecamera[ playerid ][udold] != ud || flymodecamera[ playerid ][lrold] != lr)
		{
			if((flymodecamera[ playerid ][udold] != 0 || flymodecamera[ playerid ][lrold] != 0) && ud == 0 && lr == 0){
				StopPlayerObject(playerid, flymodecamera[ playerid ][flyobject] );
				flymodecamera[ playerid ][mode]      = 0;
				flymodecamera[ playerid ][accelmul]  = 0.0;
			}
			else
			{
				flymodecamera[ playerid ][mode] = GetMoveDirectionFromKeys(ud, lr);
				MoveCamera(playerid);
			}
		}
		flymodecamera[ playerid ][udold] = ud; flymodecamera[ playerid ][lrold] = lr;
		return 0;
	}
	return true;
}

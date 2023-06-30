
GlobalTimer();
public GlobalTimer()
{
	new id = -1;
    if( cseconds ) {

        format( cstring, 6, "~w~%d", cseconds-1 );
        GameTextForAll( cstring, 1100, 4 );
        SoundForAll( 1056 );

        cseconds --;

        if( !cseconds )
        {
            GameTextForAll( "~r~~y~MOZES KRENUTI - SAD!", 2000, 4 );
            SoundForAll( 1057 );
        }
    }



    for(new i; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if( GetPlayerInterior( i ) == 0 && GetPlayerVirtualWorld( i ) == 0 )
		{
			if (PlayerLogged[i] == true) 
			{
				if(!TogHud[ i ])
				{
					new stringzone[ MAX_ZONE_NAME ];
					new stringgrada[ MAX_ZONE_NAME11 ];
		        	format( stringzone, sizeof( stringzone ), "%s", GetPlayerLocation( i ) );
		        	PlayerTextDrawSetString( i, LokacijaIgracaTD[ i ], stringzone );
		        	PlayerTextDrawShow( i, LokacijaIgracaTD[ i ] );
		        	format( stringgrada, sizeof( stringgrada ), "%s", GetPlayerLocation11( i ) );
		        	PlayerTextDrawSetString( i, GradIgracaTD[ i ], stringgrada );
		        	PlayerTextDrawShow( i, GradIgracaTD[ i ] );
				}
				else if(TogHud[ i ])
				{
				    PlayerTextDrawHide(i,LokacijaIgracaTD[ i ] );
				    PlayerTextDrawHide(i,GradIgracaTD[ i ] );
				}
			}
        	
		}
		else
		{
			if (PlayerLogged[i] == true)
			{
				if(!TogHud[ i ])
				{
			    	PlayerTextDrawSetString( i, LokacijaIgracaTD[ i ],"Nema informacija..." );
			    	PlayerTextDrawSetString( i, GradIgracaTD[ i ],"Signal - nedostizan!" );
				}
				else if(TogHud[ i ])
				{
				    PlayerTextDrawHide(i,LokacijaIgracaTD[ i ] );
				    PlayerTextDrawHide(i,GradIgracaTD[ i ] );
				}
			}

		}
		
		if( SearchNadji[ i ] != -1 )
		{
		
		    if( IsPlayerConnected( SearchNadji[ i ] ) )
			{
		
	        	new Float:X, Float:Y, Float:Z;
				GetPlayerPos( SearchNadji[ i ], X, Y, Z );
				Dimi_SetPlayerCheckpoint( i, X, Y, Z, 6 );
			}
			else if( !IsPlayerConnected( SearchNadji[ i ] ) ) SearchNadji[ i ] = -1;

        }
 
		

        if( PlayerInfo[ i ][ xMute ] != 0 )
		{
			PlayerInfo[ i ][ xMute ]--;
			if( PlayerInfo[ i ][ xMute ] <= 0 )
			{
			    PlayerInfo[ i ][ xMute ] = 0;
			}
		}

        if( VremeZaNovac[ i ] != 0 )
		{
            VremeZaNovac[ i ]--;
            if( VremeZaNovac[ i ] == 0 )
			{
                SendClientMessageEx( i, -1, "{005B88}|| Pljacka || {FFFFFF}Ostali ste zivi 2 minuta i dobili "SERVERBOJA_AQUA"$%d {FFFFFF}od pljacke!", PljackaNovac[ i ] );
				DajIgracuNovac( i, PljackaNovac[ i ] );
				PljackaNovac[ i ] = 0;
			}
        }

        if( VremeZaZlato[ i ] != 0 )
		{
            VremeZaZlato[ i ]--;
            if( VremeZaZlato[ i ] == 0 )
			{
                SendClientMessageEx( i, -1, "{005B88}|| Pljacka || {FFFFFF}Ostali ste zivi 2 minuta i dobili "SERVERBOJA_AQUA"%dg {FFFFFF}zlata od pljacke!", PljackaZlato[ i ] );
				PlayerInfo[ i ][ xZlato ] += PljackaZlato[ i ];
				SavePlayer( i );
				PljackaZlato[ i ] = 0;
				UpdateZlatoTD( i );
			}
        }

        if( Polaganje[ i ] >= 1 )
		{
			if( IsPlayerInAnyVehicle( i ) )
			{
	     	    if( GetSpeed( i ) > 100 )
				 {
	     	        GreskaVoznja[ i ]++;
	     	        SendClientMessagee( i, -1, ""col_orange"[Instruktor]: "col_white"Prekoracili ste brzinu od 100km/h na gradskoj voznji i dobili gresku!");
	     	        if( GreskaVoznja[ i ] == 3 )
					 {
		     	        Polaganje[ i ] = 0;
		     	        GreskaVoznja[ i ] = 0;
		    			Dimi_DisablePlayerCheckpoint( i );
						Dimi_RemovePlayerFromVehicle( i );
						SendClientMessagee( i, -1, ""col_orange"[Instruktor]: "col_white"Pali ste na vozackom ispitu jer ste prekoracili brzinu od 100km/h 3 puta!");
		    			SetVehicleToRespawn( GetPlayerVehicleID( i ) );
					}
				}
			}
		}
        if( IsPlayerInAnyVehicle( i ) && GetPlayerState( i ) == PLAYER_STATE_DRIVER && GetSpeed( i ) > 10 )
		{

            new autoid = ScriptIDVozila[ GetPlayerVehicleID( i ) ];
            
            if( autoid != -1 )
			{
            
			    VehicleInfo[ autoid ][ vMetri ] += ( GetSpeed( i )*10 )/36;
			    if( VehicleInfo[ autoid ][ vMetri ] > 999 )
				{
					VehicleInfo[ autoid ][ vKilometri ]++;
					VehicleInfo[ autoid ][ vMetri ] = 0;
				}
			}
		}

        if( ReportGlobal[ i ] > 0 ) ReportGlobal[ i ]--;
        
        if( VIPPort[ i ] > 0 ) VIPPort[ i ]--;
        
        if( PromoterPort[ i ] > 0 ) PromoterPort[ i ]--;

		if( PomocGlobal[ i ] > 0 ) PomocGlobal[ i ]--;
		
		if( NewGlobal[ i ] > 0 ) NewGlobal[ i ]--;

        if( antiCheatCS[ i ][ SpamChat ] > 0 ) antiCheatCS[ i ][ SpamChat ]--;

		if( antiCheatCS[ i ][ SpamCommand ] > 0 ) antiCheatCS[ i ][ SpamCommand ]--;
		
		if( DropedGun[ i ] > 0 ) DropedGun[ i ]--;

		CarDamageTimer( i );
		
		CheckWeapons( i );

		CheckTeleports( i );

		#if nerp_droga == 1
		DrugCheck( i );
		#endif

		AntiCheat( i );

		CellphoneCheck( i );

        if( GetFactionType( i ) != ORG_TIP_PD && !IsPlayerInAnyVehicle( i ) )
		{

			if( GetPlayerWeapon( i ) >= 24 && GetPlayerWeapon( i ) <= 40 )
			{

				if( Javno3( i ) || Javno4( i ) || Javno5( i ) || Javno6( i ) || Javno7( i ) || Javno8( i ) || IsPlayerInRangeOfPoint( i, 10, 1133.5189, -936.0316, 47.7939 ) ) {

					if( antiCheatCS[ i ][ ArmedWeapon ] < 3 )
					{
						SetPlayerArmedWeapon( i, 0 );
						antiCheatCS[ i ][ ArmedWeapon ] ++;
						SendClientMessageEx( i, ANTICHEAT, "Oruzije se ne moze koristiti na javnim mjestima! Upozorenje %d/3.", antiCheatCS[ i ][ ArmedWeapon ] );
					}
					if( antiCheatCS[ i ][ ArmedWeapon ] == 3 )
					{
					
						SendClientMessageEx( i, ANTICHEAT, "Oruzije se ne moze koristiti na javnim mjestima! Upozorenje %d/3.", antiCheatCS[ i ][ ArmedWeapon ] );
						antiCheatCS[ i ][ ArmedWeapon ] = 0;
						announcement( i, "~r~Oruzje vam je oduzeto!", 2500, 1 );
						ResetAllWeapons( i );
						return 1;
					}
				}
				if( Snow_F[ i ] )
				{
				
				    if( antiCheatCS[ i ][ ArmedWeapon ] < 3 )
					{
						SetPlayerArmedWeapon( i, 0 );
						antiCheatCS[ i ][ ArmedWeapon ] ++;
						SendClientMessageEx( i, ANTICHEAT, "Oruzije se ne moze koristiti u areni za grudvanje! Upozorenje %d/3.", antiCheatCS[ i ][ ArmedWeapon ] );
					}
					if( antiCheatCS[ i ][ ArmedWeapon ] == 3 )
					{

						SendClientMessageEx( i, ANTICHEAT, "Oruzije se ne moze koristiti u areni za grudvanje! Upozorenje %d/3.", antiCheatCS[ i ][ ArmedWeapon ] );
						antiCheatCS[ i ][ ArmedWeapon ] = 0;
						announcement( i, "~r~Oruzje vam je oduzeto!", 2500, 1 );
						ResetAllWeapons( i );
						return 1;
					}
				}
			}
		}

		if( TrashLimit[ i ] != 0 )
		{
		    TrashLimit[ i ]--;
		}

		if( Odbrojavanje[ i ] != 0 )
		{
			format( globalstring, sizeof( globalstring ), "~w~Pricekajte, Vrijeme: ~r~%d", Odbrojavanje[ i ] );
			PlayerTextDrawSetString( i, PVreme[ i ], globalstring );
			Odbrojavanje[ i ]--;
		}

		if( ( id = Boombox_Nearest(i)) != INVALID_PLAYER_ID && Boombox[ i ] != id && strlen (BoomboxInfo[ id ][ boomboxURL ] ) && !IsPlayerInAnyVehicle( i ) )
		{
		    new boomboxstr[ 128 ];
		    strunpack(boomboxstr, BoomboxInfo[ id ][ boomboxURL ] );
		    Boombox[ i ] = id;

		    StopAudioStreamForPlayer( i );
		    PlayAudioStreamForPlayer( i, boomboxstr, BoomboxInfo[ id ][ boomboxPos ][ 0 ], BoomboxInfo[ id ][ boomboxPos ][ 1 ], BoomboxInfo[ id ][ boomboxPos ][ 2 ], 30.0, 1);
		}
		else if( Boombox[ i ] != INVALID_PLAYER_ID && !IsPlayerInRangeOfPoint( i, 30.0, BoomboxInfo[ Boombox[ i ] ][ boomboxPos ][ 0 ], BoomboxInfo[ Boombox[ i ] ][ boomboxPos ][ 1 ], BoomboxInfo[ Boombox[ i ] ][boomboxPos][ 2 ] ) )
		{
		    Boombox[ i ] = INVALID_PLAYER_ID;
		    StopAudioStreamForPlayer(i);
		}

		if( PlayerInfo[ i ][ xLevel ] < 3 && GetFactionType( i ) != ORG_TIP_PD)
		{
			for( new g = 0; g < 13; g++)
			{
	    	    new sweapon, sammo;
   				GetPlayerWeaponData( i, g, sweapon, sammo );
        		if( sweapon != 0 && sammo != 0 )
				{
 		    		ResetAllWeapons( i );
 		    		announcement( i, "~w~Ti si Level 1-2 ne mozes~n~~y~posedovati oruzje!", 5000, 3 );
 		    		format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Oruzje || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Level manji od 3 !", ImeIgraca( i ), i );
			        AdminPoruka( ANTICHEAT, globalstring );
			    }
			}
		}
		


		
		if( IsPlayerInRangeOfPoint( i, 10.0, 1862.0596, -1380.8535, 13.4618 ) )
		{
		    if( PlayerInfo[ i ][ xAdmin ] >= 6 || PlayerInfo[ i ][ xPosao ] == POSAO_GRADJEVINAR )
			{
				MoveDynamicObject( gradjkapija, 1861.8921, -1376.4141, 12.5581, 2.0 );
				SetTimer( "GradjevinarKapijaClose", 7000, 0 );
			}
		}
		
		if( GetPlayerSurfingVehicleID( i ) != INVALID_VEHICLE_ID &&
			!AdminDuty[ i ] &&
			GetSpeed( i ) > 50 &&
			!IsVehicleBrod( GetPlayerSurfingVehicleID( i ) ) &&
			GetVehicleModel( GetPlayerSurfingVehicleID( i ) ) != 406 &&
			GetVehicleModel( GetPlayerSurfingVehicleID( i ) ) != 422 &&
			GetVehicleModel( GetPlayerSurfingVehicleID( i ) ) != 433 ) {
			
			new Float:slx, Float:sly, Float:slz;
            GetPlayerPos( i, slx, sly, slz );
            SetPlayerPos( i, slx, sly, slz+5 );
            
            SendClientMessagee( i, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Ne smijes se voziti na autu!");
		}

	}
	return 1;
}

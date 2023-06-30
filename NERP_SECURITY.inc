/*

	NERP

	NovaSecurity

	DEntisT

	v1.0

*/

SetupNovaSecurity(playerid);
public SetupNovaSecurity(playerid)
{
	print("NovaSecurity loaded");

	NovaSecurity[playerid][0] = CreatePlayerTextDraw(playerid, 268.444427, 169.244476, "ld_beat:chit");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, NovaSecurity[playerid][0], 94.666641, 94.577796);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][0], 2);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][0], tdboja);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][0], 0);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][0], 4);

	NovaSecurity[playerid][1] = CreatePlayerTextDraw(playerid, 317.777893, 173.226684, "!");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][1], 1.535333, 8.414577);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][1], 2);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][1], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][1], 1);

	NovaSecurity[playerid][2] = CreatePlayerTextDraw(playerid, 333.333374, 186.168930, "hud:radar_enemyattack");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, NovaSecurity[playerid][2], 15.555547, 14.435541);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][2], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][2], 0);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][2], 4);

	NovaSecurity[playerid][3] = CreatePlayerTextDraw(playerid, 277.777679, 242.417770, "Nova");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][3], 0.493555, 2.530844);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][3], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][3], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][3], 3);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][3], 1);

	NovaSecurity[playerid][4] = CreatePlayerTextDraw(playerid, 308.444396, 259.839935, "Security");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][4], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][4], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][4], tdboja);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][4], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][4], 0);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][4], 1);

	NovaSecurity[playerid][5] = CreatePlayerTextDraw(playerid, 321.333282, 252.871139, "v1.0");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][5], 0.226444, 1.067377);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][5], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][5], -1061109505);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][5], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][5], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][5], 1);

	NovaSecurity[playerid][6] = CreatePlayerTextDraw(playerid, 395.777740, 284.735565, "usebox");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][6], 0.000000, 1.529258);
	PlayerTextDrawTextSize(playerid, NovaSecurity[playerid][6], 242.444458, 0.000000);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][6], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][6], 0);
	PlayerTextDrawUseBox(playerid, NovaSecurity[playerid][6], true);
	PlayerTextDrawBoxColor(playerid, NovaSecurity[playerid][6], 102);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][6], 0);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][6], 0);

	NovaSecurity[playerid][7] = CreatePlayerTextDraw(playerid, 318.666778, 285.226745, "Sistem je detektovao greske!");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][7], 0.193555, 1.112178);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][7], 2);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][7], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][7], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][7], 1);

	NovaSecurity[playerid][8] = CreatePlayerTextDraw(playerid, 324.000213, 314.097747, "Mjesto za text, Mjesto za text, Mjesto za text, ~n~Mjesto za text, Mjesto za text, Mjesto za text, ~n~Mjesto za text, Mjesto za");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][8], 0.167333, 0.793600);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][8], 2);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][8], 1);
	PlayerTextDrawBackgroundColor(playerid, NovaSecurity[playerid][8], 51);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, NovaSecurity[playerid][8], 1);

	NovaSecurity[playerid][9] = CreatePlayerTextDraw(playerid, 433.555541, 310.619995, "usebox");
	PlayerTextDrawLetterSize(playerid, NovaSecurity[playerid][9], 0.000000, 2.780619);
	PlayerTextDrawTextSize(playerid, NovaSecurity[playerid][9], 209.555557, 0.000000);
	PlayerTextDrawAlignment(playerid, NovaSecurity[playerid][9], 1);
	PlayerTextDrawColor(playerid, NovaSecurity[playerid][9], 0);
	PlayerTextDrawUseBox(playerid, NovaSecurity[playerid][9], true);
	PlayerTextDrawBoxColor(playerid, NovaSecurity[playerid][9], 102);
	PlayerTextDrawSetShadow(playerid, NovaSecurity[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, NovaSecurity[playerid][9], 0);
	PlayerTextDrawFont(playerid, NovaSecurity[playerid][9], 0);


	return 1;
}

SendSecurityMessage(playerid,text[]);
public SendSecurityMessage(playerid,text[])
{
	for(new i; i < 20; i++)
	{
		PlayerTextDrawHide(playerid, NovaSecurity[playerid][i]);
	}
	PlayerTextDrawSetString(playerid, NovaSecurity[playerid][8], text);
	for(new i; i < 20; i++)
	{
		PlayerTextDrawShow(playerid, NovaSecurity[playerid][i]);
	}
	SetTimerEx("HideSecurityMsg", 5000, false, "i", playerid);
	return 1;
}

HideSecurityMsg(playerid);public HideSecurityMsg(playerid)
{
	for(new i; i < 20; i++)
	{
		PlayerTextDrawHide(playerid, NovaSecurity[playerid][i]);
	}
	return 1;
}

//////////AC///////////////

//OnPlayerStateChange
NOVASECURITY_STATECHANGE(playerid, newstate, oldstate);
public NOVASECURITY_STATECHANGE(playerid, newstate, oldstate)
{
	if( antiCheatSS[ antiVehRepair ] == true )
	{
		new vehicleid = GetPlayerVehicleID( playerid );
	    GetVehicleHealth( vehicleid, antiCheatVS[ vehicleid ][ VehTrueHealth ] );
	    antiCheatVS[ vehicleid ][ VehCheck ] = 1;
	}

    if( oldstate == PLAYER_STATE_DRIVER && antiCheatCS[ playerid ][ RemoveVehicle ] == false )
	{
        if( ( GetTickCount() - antiCheatCS[ playerid ][ EnterVehTime ] ) < 220 )
		{
            antiCheatCS[ playerid ][ SpamVehicle ]++;
	    	if( antiCheatCS[ playerid ][ SpamVehicle ] >= 2 )
			{
            	format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc SPAM VOZILA!!! || "SERVERBOJA_AQUA"%s[ID: %d] |LVL: |%d|"col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid, PlayerInfo[ playerid ][ xLevel ] );
				AdminPoruka( -1, globalstring );
			}
        }
    }

	if( antiCheatCS[ playerid ][ TakeVehicle ] != INVALID_VEHICLE_ID )
	{
    	BusyVehicle[ antiCheatCS[ playerid ][ TakeVehicle ] ] = -1;
        antiCheatCS[ playerid ][ TakeVehicle ] = INVALID_VEHICLE_ID;
    }

	return 1;
}

//////////////////////////////

forward OnPlayerCheat( playerid, type, source, source2 );
public OnPlayerCheat( playerid, type, source, source2 )
{
	CallLocalFunction("SendSecurityMessage", "is", playerid, "Sistem je detektovao greske~n~na vasem racunu!~n~Pod nadzorom ste administracije.");
    switch( type ) {
        case DETECT_WEAPON_HACK: {
            if( antiCheatSS[ antiWeaponH ] == true ) {
				switch( antiCheatSS[ WeaponHRezimRada ] ) {
				    case AC_ADMINPORUKA: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |: "col_white"Oruzje || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| %s: !", ImeIgraca( playerid ), playerid, WeapNames[ antiCheatCS[ playerid ][ TakenWeapon ] ] );
			            AdminPoruka( ANTICHEAT, globalstring );

						ResetAllWeapons( playerid );
				    }
				    case AC_KICK: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Weapon hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );
						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Weapon hack");

				    }
				    case AC_BAN: {
				        ResetAllWeapons( playerid );
	                    antiCheatCS[ playerid ][ WeaponHack ]++;
		                if( antiCheatCS[ playerid ][ WeaponHack ] >= 3 ) {
					        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Weapon hack", ImeIgraca( playerid ) );
							AdminPoruka( SVETLOCRVENA, globalstring );

						    CreateBanFile( playerid, "Weapon Hack", "AntiCheat" );

							Kickovanje( playerid, ""col_white"Ti si banovan sa servera. Razlog: "col_balkanstory"Weapon hack");
						}
					}
				}
			}
        }
        case DETECT_AMMO_HACK: {
            if( antiCheatSS[ antiWeaponH ] == true ) {
				switch( antiCheatSS[ WeaponHRezimRada ] ) {
				    case AC_ADMINPORUKA: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Municija || "SERVERBOJA_AQUA"%s[ID: %d] | %s: %d "col_white"| Max moze imati: "SERVERBOJA_AQUA"%d!", ImeIgraca( playerid ), playerid, WeapNames[ antiCheatCS[ playerid ][ TakenWeapon ] ], source, source2 );
				        AdminPoruka( ANTICHEAT, globalstring );

		                ResetAllWeapons( playerid );
				    }
				    case AC_KICK: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Ammo hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );
						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Ammo hack");

				    }
				    case AC_BAN: {
				        ResetAllWeapons( playerid );
		                antiCheatCS[ playerid ][ WeaponHack ]++;
			            if( antiCheatCS[ playerid ][ WeaponHack ] >= 3 ) {
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Ammo hack", ImeIgraca( playerid ) );
							AdminPoruka( SVETLOCRVENA, globalstring );

                            CreateBanFile( playerid, "Ammo Hack", "AntiCheat" );

							Kickovanje( playerid, ""col_white"Ti si banovan sa servera. Razlog: "col_balkanstory"Ammo hack");
						}
					}
				}
			}
		}
		case DETECT_TELEPORT_HACK: {
		    if( antiCheatSS[ antiTeleportH ] == true ) {
		    	switch( antiCheatSS[ TeleportHRezimRada ] ) {
				    case AC_ADMINPORUKA: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguce portanje || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
		        		AdminPoruka( ANTICHEAT, globalstring );

				    }
				    case AC_KICK: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Teleport hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );
						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Teleport hack");

				    }
				  	case AC_BAN: {

				  	    format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Teleport hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

                        CreateBanFile( playerid, "Teleport Hack", "AntiCheat" );

						Kickovanje( playerid, ""col_white"Ti si banovan sa servera. Razlog: "col_balkanstory"Teleport hack");

				  	}
				}
			}
		}
		case DETECT_FLY_HACK:
		{
            if( antiCheatSS[ antiFlyH ] == true )
			{
				switch( antiCheatSS[ FlyHRezimRada ] )
				{
				    case AC_ADMINPORUKA:
					{
				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc fly hack || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
		        		AdminPoruka( ANTICHEAT, globalstring );
				    }
				    case AC_KICK: {
				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Fly hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );
						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Fly hack");
				    }
				  	case AC_BAN: {
				  	    format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Fly hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

                        CreateBanFile( playerid, "Fly Hack", "AntiCheat" );

						Kickovanje( playerid, ""col_white"Ti si banovan sa servera. Razlog: "col_balkanstory"Fly hack");
				  	}
				}
			}
		}
		case DETECT_SPEED_HACK: {
            if( antiCheatSS[ antiSpeedH ] == true ) {
				switch( antiCheatSS[ SpeedHRezimRada ] ) {
				    case AC_ADMINPORUKA: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc speed hack || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
			   			AdminPoruka( ANTICHEAT, globalstring);

				    }
				    case AC_KICK: {
				        antiCheatCS[ playerid ][ SpeedHack ]++;
						if( antiCheatCS[ playerid ][ SpeedHack ] == 3 ) {

							antiCheatCS[ playerid ][ SpeedHack ] = 0;

							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Speed hack", ImeIgraca( playerid ) );
							AdminPoruka( SVETLOCRVENA, globalstring );

							Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Speed hack");
						}
				    }
				    case AC_BAN: {
				        antiCheatCS[ playerid ][ SpeedHack ]++;
						if( antiCheatCS[ playerid ][ SpeedHack ] == 3 ) {

							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Speed hack", ImeIgraca( playerid ) );
							AdminPoruka( SVETLOCRVENA, globalstring );

							CreateBanFile( playerid, "Speed Hack", "AntiCheat" );

							Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Speed hack");
						}
				    }
				}
			}
		}
		case DETECT_JETPACK_HACK: {
		    if( antiCheatSS[ antiJetPackH ] == true ) {
		        switch( antiCheatSS[ JetPackHRezimRada ] ) {
				    case AC_ADMINPORUKA: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc JetPack hack || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
			   			AdminPoruka( ANTICHEAT, globalstring);

			   			SetPlayerSpecialAction( playerid, SPECIAL_ACTION_NONE );

				    }
				    case AC_KICK: {

						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"JetPack hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"JetPack hack");
				    }
				    case AC_BAN: {

						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"JetPack hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

						CreateBanFile( playerid, "JetPack Hack", "AntiCheat" );

						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"JetPack hack");
				    }
				}
			}
		}
		case DETECT_VEHREPAIR_HACK: {
		    if( antiCheatSS[ antiVehRepair ] == true ) {
		        switch( antiCheatSS[ VehRepRezimRada ] ) {
				    case AC_ADMINPORUKA: {
				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguc Vehicle Repair hack || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
			   			AdminPoruka( ANTICHEAT, globalstring );
				    }
				    case AC_KICK: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je kickovan sa servera. Razlog: "SERVERBOJA_AQUA"Vehicle Repair hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Vehicle Repair hack");

				    }
				    case AC_BAN: {

				        format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s "col_white"je banovan sa servera. Razlog: "SERVERBOJA_AQUA"Vehicle Repair hack", ImeIgraca( playerid ) );
						AdminPoruka( SVETLOCRVENA, globalstring );

						CreateBanFile( playerid, "Vehicle Repair Hack", "AntiCheat" );

						Kickovanje( playerid, ""col_white"Ti si kickovan sa servera. Razlog: "col_balkanstory"Vehicle Repair hack");

				    }
				}
			}
		}
    }
	return 1;
}
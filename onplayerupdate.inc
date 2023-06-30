
GlobalTimer();
public GlobalTimer()
{
    new id = -1;

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

    new igra[10], kills[10];
	format(igra,10,"%i", PUBGenum[xCekaIgraca] + PUBGenum[xIgraMatch]);
/*
	if(ServerInfo[HappyJobs] == true)
    {
        for(new i; i < MAX_PLAYERS; i++) 
        	PlayerTextDrawSetString(i, StatsPreviewTD[i][14], "Happy jobs: da");
	}
	else if(ServerInfo[HappyJobs] == false)
    {
        for(new i; i < MAX_PLAYERS; i++) 
        	PlayerTextDrawSetString(i,StatsPreviewTD[i][14], "Happy jobs: ne");
	}
	if(ServerInfo[HappyHours] == true)
    {
        for(new i; i < MAX_PLAYERS; i++) 
        	PlayerTextDrawSetString(i,StatsPreviewTD[i][15], "Happy hours: da");
	}
	else if(ServerInfo[HappyHours] == false)
    {
        for(new i; i < MAX_PLAYERS; i++) 
        	PlayerTextDrawSetString(i,StatsPreviewTD[i][15], "Happy hours: ne");
	}
*/
	for(new pubg_playerid; pubg_playerid < MAX_PLAYERS; pubg_playerid++)
	{
		if(PlayerInfo[pubg_playerid][xPUBG] == 1)
		{
			TextDrawSetString(PubgEventTd[5], igra);

			format(kills,10,"%i", PlayerInfo[pubg_playerid][xPUBGKills]);
			PlayerTextDrawSetString(pubg_playerid, PubgEventKills[pubg_playerid], kills);
		}
	}

	/*for(new i; i < MAX_DEALERS; i++)
	{
		if(IsValidActor(DealerActor[i]))
		{
			new Float:x,Float:y,Float:z;
			GetActorPos(DealerActor[i],x,y,z);
			if(x!=DealerInfo[i][dealerPos][0] || y!=DealerInfo[i][dealerPos][1])
			{
				Dileri3D(i);
			}
		}
	}*/

    for(new i; i < MAX_PLAYERS; i++)
	{
		if(PUBGTDShowed[i])
		{
			PlayerTextDrawHide(i,PUBGTextdraw[2][i]);
			PlayerTextDrawSetPreviewModel(i,PUBGTextdraw[2][i],PlayerInfo[i][xSkin]);
			PlayerTextDrawShow(i,PUBGTextdraw[2][i]);
		}
		if(!PUBGTDShowed[i])
		{
			PlayerTextDrawHide(i,PUBGTextdraw[2][i]);
		}
		if(OdjecaTDShowed[i])
		{
			PlayerTextDrawHide(i, OdjecaTextdraw[10][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[11][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[12][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[13][i]);

			if(PlayerInfo[i][xHead] != 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[10][i], 0.0, -90.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[10][i],PlayerInfo[i][xHead]);
			}
			if(PlayerInfo[i][xSungMask] != 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[11][i], 0.0, 0.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[11][i],PlayerInfo[i][xSungMask]);
			}
			if(PlayerInfo[i][xFace] != 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[12][i], 0.0, -90.0, 0.0, 1.0);			
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[12][i],PlayerInfo[i][xFace]);
			}
			if(PlayerInfo[i][xPapagaj] != 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[13][i], 0.0, -90.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[13][i],19078);
			}

			if(PlayerInfo[i][xHead] == 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[10][i], 0.0, 0.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[10][i],18631);
			}
			if(PlayerInfo[i][xSungMask] == 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[11][i], 0.0, 0.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[11][i],18631);
			}
			if(PlayerInfo[i][xFace] == 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[12][i], 0.0, 0.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[12][i],18631);
			}
			if(PlayerInfo[i][xPapagaj] == 0)
			{
				PlayerTextDrawSetPreviewRot(i, OdjecaTextdraw[13][i], 0.0, 0.0, 0.0, 1.0);
				PlayerTextDrawSetPreviewModel(i,OdjecaTextdraw[13][i],18631);
			}

			PlayerTextDrawShow(i, OdjecaTextdraw[10][i]);
			PlayerTextDrawShow(i, OdjecaTextdraw[11][i]);
			PlayerTextDrawShow(i, OdjecaTextdraw[12][i]);
			PlayerTextDrawShow(i, OdjecaTextdraw[13][i]);
		}
		if(!OdjecaTDShowed[i])
		{
			PlayerTextDrawHide(i, OdjecaTextdraw[10][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[11][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[12][i]);
			PlayerTextDrawHide(i, OdjecaTextdraw[13][i]);
			OdjecaTDControl(i, false);
		}

		//new player_weapon = WeaponInfos[ GetPlayerWeapon( i ) ][ wModel ];
		
		new player_ingame_nickname[100];
		format(player_ingame_nickname,sizeof(player_ingame_nickname),"%s",ImeIgraca(i));
		PlayerTextDrawSetString( i, NickIgraca[ i ], player_ingame_nickname );
		if(StatsTDShowed[i])
		{
			PlayerTextDrawHide(i, SkinIgraca[i]);
			PlayerTextDrawSetPreviewModel(i,SkinIgraca[i], PlayerInfo[i][xSkin]);
			PlayerTextDrawShow(i, SkinIgraca[i]);
		}
		if(!StatsTDShowed[i])
		{
			PlayerTextDrawHide(i, SkinIgraca[i]);
		}

		new nxtlevel = PlayerInfo[ i ][ xLevel ]+1,
		    expamount = nxtlevel*levelexp,
			exp = PlayerInfo[ i ][ xRespekt ],
			str[ 1024 ];

	 	format( str, sizeof( str ), 
	 		"~w~Level: ~r~%d\
	 		~n~~w~Sati igranja: ~r~%d\
	 		~n~~w~Respekti: ~r~%d/%d\
	 		~n~~w~Spawn Health: ~r~%.0f\
	 		~n~~w~Admin lvl: ~r~%d\
	 		~n~~w~GM lvl: ~r~%d\
	 		~n~~w~VIP lvl: ~r~%d\
	 		~n~~w~do plate: ~r~%d min\
	 		~n~~w~Upozorenja ~r~%d/5\
	 		~n~~w~Promoter: ~r~%i\
	 		~n~~w~RP Poeni: ~r~%d",
			PlayerInfo[ i ][ xLevel ],
			PlayerInfo[ i ][ xOnlineSati ],
			exp,
			expamount,
			(50+PlayerInfo[ i ][ xSHealth ]),
			PlayerInfo[ i ][ xAdmin ],
			PlayerInfo[ i ][ xHelper ],
			PlayerInfo[ i ][ xVIPLevel ],
			(60-PlayerInfo[ i ][ xPayDay ]),
			PlayerInfo[ i ][ xWarn ],
			PlayerInfo[ i ][ xPromoter ],
			PlayerInfo[ i ][ xRPPoen ] );

		PlayerTextDrawSetString(i,PlayerStats[3][i],str);

		format( str, sizeof( str ), 
	 		"~n~~n~apoeni: %i\
	 		~n~posao:~n~%s\
	 		~n~ugovor: %ih\
	 		~n~novac: %i $\
	 		~n~banka: %i $",
			PlayerInfo[ i ][ xApoeni ],
			getJobName(PlayerInfo[ i ][ xPosao ]),
			PlayerInfo[ i ][ xUgovor ],
			PlayerInfo[ i ][ xNovac ],
			PlayerInfo[ i ][ xBRacun ]);

		PlayerTextDrawSetString(i,PlayerStats[4][i],str);
		//6"zlato: 999999g~n~materijali: 9999~n~tel br: 999999~n~brak: ~n~~y~mustafa_kulovac~n~hapsenja: 999"
		format( str, sizeof( str ), 
	 		"zlato: %i g\
	 		~n~materijali: %i\
	 		~n~tel br: %i\
	 		~n~brak: \
	 		~n~~y~%s\
	 		~n~hapsenja: %i",
			PlayerInfo[ i ][ xZlato ],
			PlayerInfo[ i ][ xMaterijali ],
			PlayerInfo[ i ][ xBrojTelefona ],
			PlayerInfo[ i ][ xMarriedTo ],
			PlayerInfo[ i ][ xUhapsen ]);

		PlayerTextDrawSetString(i,PlayerStats[6][i],str);
		//7"organizacija:~n~~y~saobracajna policija~n~~w~org rank: 6~n~org kazna: 7h"
		format( str, sizeof( str ), 
	 		"organizacija:~n~\
	 		~y~%s\
	 		~n~~w~org rank: %i\
	 		~n~org kazna: %ih",
			OI[PlayerInfo[i][xClan]][oName],
			PlayerInfo[ i ][ xRank ],
			PlayerInfo[ i ][ xKazneniUgovor ]);

		PlayerTextDrawSetString(i,PlayerStats[7][i],str);


		//8"vozilo 1: nema~n~vozilo 2: nema~n~vozilo 3: nema~n~vozilo 4: nema~n~"
		format( str, sizeof( str ), 
	 		"~w~vozilo 1: ~y~%i\
	 		~n~~w~vozilo 2: ~y~%i\
	 		~n~~w~vozilo 3: ~y~%i\
	 		~n~~w~vozilo 4: ~y~%i~n~",
			PlayerInfo[ i ][ xVoziloID ][ 0 ],
			PlayerInfo[ i ][ xVoziloID ][ 1 ],
			PlayerInfo[ i ][ xVoziloID ][ 2 ],
			PlayerInfo[ i ][ xVoziloID ][ 3 ]);

		PlayerTextDrawSetString(i,PlayerStats[8][i],str);

		//10"imovina 1: nema~n~imovina 2: nema~n~imovina 3: nema"
		format( str, sizeof( str ), 
	 		"~w~imovina 1: ~y~%i\
	 		~n~~w~imovina 2: ~y~%i\
	 		~n~~w~imovina 3: ~y~%i",
			PlayerInfo[ i ][ xProperty ][ 0 ],
			PlayerInfo[ i ][ xProperty ][ 1 ],
			PlayerInfo[ i ][ xProperty ][ 2 ]);

		PlayerTextDrawSetString(i,PlayerStats[10][i],str);
		//11"firma: nema~n~garaza: nema~n~imanje: nema"
		format( str, sizeof( str ), 
	 		"~w~firma: ~y~%i\
	 		~n~~w~garaza: ~y~%i\
	 		~n~~w~imanje: ~y~%i",
			PlayerInfo[ i ][ xFirmaID ],
			PlayerInfo[ i ][ xGarageID ],
			PlayerInfo[ i ][ xFieldID ]);

		PlayerTextDrawSetString(i,PlayerStats[11][i],str);

		if(PlayerLogged[i]) LoginTDControl(i, false);

		if(PlayerInfo[i][xPUBG] == 0)
		{
			PubgEventTDControl(i, false);
		}

		if(PlayerInfo[i][xPUBG] == 1)
		{
			PubgEventTDControl(i, false);
			PubgEventTDControl(i, true);
		}

		if( PlayerLogged[ i ] == true && ClientType[i] == CLIENT_PC)
		{

			//new levelstring[10];
			//format(levelstring,sizeof(levelstring),"%i",PlayerInfo[i][xLevel]);
			//PlayerTextDrawSetString( i, LevelIgraca[ i ], levelstring );
			
			PlayerTextDrawShow(i,MoneyBar[i]);
			//if(PlayerInfo[i][xDeathScreen] == 0) PlayerTextDrawShow(i,LevelIgraca[i]);

			new moneybarstring[20];

			if(PlayerInfo[ i ][ xNovac ] >= 0 && PlayerInfo[ i ][ xNovac ] < 10)
			{
				format(moneybarstring, 20, "$00000000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 10 && PlayerInfo[ i ][ xNovac ] < 100)
			{
				format(moneybarstring, 20, "$0000000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 100 && PlayerInfo[ i ][ xNovac ] < 1000)
			{
				format(moneybarstring, 20, "$000000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 1000 && PlayerInfo[ i ][ xNovac ] < 10000)
			{
				format(moneybarstring, 20, "$00000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 10000 && PlayerInfo[ i ][ xNovac ] < 100000)
			{
				format(moneybarstring, 20, "$0000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 100000 && PlayerInfo[ i ][ xNovac ] < 1000000)
			{
				format(moneybarstring, 20, "$000%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 1000000 && PlayerInfo[ i ][ xNovac ] < 10000000)
			{
				format(moneybarstring, 20, "$00%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 10000000 && PlayerInfo[ i ][ xNovac ] < 100000000)
			{
				format(moneybarstring, 20, "$0%i", PlayerInfo[ i ][ xNovac ]);
			}
			if(PlayerInfo[ i ][ xNovac ] >= 100000000 && PlayerInfo[ i ][ xNovac ] < 999999999)
			{
				format(moneybarstring, 20, "$%i", PlayerInfo[ i ][ xNovac ]);
			}

			PlayerTextDrawSetString( i, MoneyBar[ i ], moneybarstring );
		}//Ostalo
		if( GetPlayerInterior( i ) == 0 && GetPlayerVirtualWorld( i ) == 0 )
		{
			if (PlayerLogged[i] == true) {

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
			if (PlayerLogged[i] == true) {
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
        
        if( BlowJobCount[ i ] != 0 )
		{

            BlowJobCount[ i ]--;
            new stringic[ 10 ];
            format( stringic, sizeof( stringic ), "%d", BlowJobCount[ i ] );
            PlayerTextDrawSetString( i, BLOWJOBCOVER[ i ][ 4 ], stringic );
		}

		if( NaDmEventu[ i ] == false && WARPInfo[ i ][ WARIgrac ] == -1 && Ranjen[i] == 0 )
		{
			if( PlayerInfo[i][xAdmin] == 0 && \
				PlayerInfo[i][xHelper] == 0 && \
				PlayerInfo[i][xClan] == 0 && \
				PlayerInfo[i][xLevel] >= 5 && \
				PlayerInfo[i][xProperty][0] == -1 &&\
				PlayerInfo[i][xProperty][1] == -1 &&\
				PlayerInfo[i][xProperty][2] == -1
			)
			{
				SetPlayerChatBubble( i, "[ BESKUCNIK ]", PLAVA, 40.0, 10000);
			}
	        else if( PlayerInfo[ i ][ xSkriptaRank ] == 1 && AdminDuty[i])
			{
				SetPlayerChatBubble( i, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 1 && !AdminDuty[i])
			{
				SetPlayerChatBubble( i, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 2 )
			{
				SetPlayerChatBubble( i, "[ DIZAJNER ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xVIPLevel ] == 5  )
			{
				//SetPlayerColor( i, 0xB7B700FF );
				SetPlayerChatBubble( i, "[ MASTER DONATOR ]", tdboja, 40.0, 10000);
				//A_GSDutyLabel[ i ] = Create3DTextLabel("_-=|| Ovaj igrac je Master Donator, \nsto znaci da je pomocnik osoblja servera\n ili da je donirao serveru veliki novac! ||=-_", ZELENA, 0.0, 0.0, 150.0, 50.0, -1, 1);
				//Attach3DTextLabelToPlayer( A_GSDutyLabel[ i ], i, 0.0, 0.0, 0.6);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 1 && AdminDuty[i])
			{
				SetPlayerChatBubble( i, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 1 && !AdminDuty[i])
			{
				SetPlayerChatBubble( i, "[ SKRIPTER ]\n"SERVERBOJA_AQUA"Administrator\n\n\n", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 3 )
			{
				SetPlayerChatBubble( i, "[ MAPPER ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xSkriptaRank ] == 6 )
			{
				SetPlayerChatBubble( i, "[ SU-VLASNIK ]", tdboja, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ i ][ xAdmin ] >= 1 && PlayerInfo[ i ][ xAdmin ] <= 5 )
			{
				SetPlayerChatBubble( i, "[ ADMIN ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xAdmin ] == 6 )
			{
				SetPlayerChatBubble( i, "[ HEAD ADMIN ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xAdmin ] == 1337 )
			{
				SetPlayerChatBubble( i, "[ DIREKTOR ]", tdboja, 40.0, 10000);
			}
			
	        else if( PlayerInfo[ i ][ xAdmin ] == 1339)
			{
				SetPlayerChatBubble( i, "[ VLASNIK ]", tdboja, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ i ][ xHelper ] >= 1 && PlayerInfo[ i ][ xHelper ] <= 3)
			{
				SetPlayerChatBubble( i, "[ GameMaster ]", tdboja, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xHelper ] == 4 )
			{
				SetPlayerChatBubble( i, "[ Vodja GameMastera ]", tdboja, 40.0, 10000);
			}

			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ i ][ xVIPLevel ] >= 1 && PlayerInfo[ i ][ xWanted ] == 0 )
			{
			
				SetPlayerChatBubble( i, "[ DONATORSKI V.I.P. ]", tdboja, 40.0, 10000);
				
				/*if( PlayerInfo[ i ][ xVIPLevel ] >= 5 && !PlayerInfo[ i ][ xDBO ] )
				{
	   				SetPlayerColor( i, 0xB7B700FF );
				}*/
			}
			////////////////////////////////////////////////////////////////////
			else if( PlayerInfo[ i ][ xPromoter ] == 1 )
			{
				SetPlayerChatBubble( i, "[ PROMOTER ]", tdboja, 40.0, 10000);
			}
			////////////////////////////////////////////////////////////////////
			else if( Ranjen[i] == 1)
			{
				SetPlayerChatBubble( i, "(( Ovaj igrac je trenutno ranjen... Umire tacno za 20 sekundi! - /pomozi ))", PLAVA, 40.0, 10000);
			}
			else if( PlayerInfo[ i ][ xLevel ] == 1  )
			{
				SetPlayerChatBubble( i, "[ Pocetnik ]", PLAVA, 40.0, 10000);
			}
		
		}
		if( Ranjen[i] == 1 )
		{
			if( Ranjen[i] == 1)
			{
				SetPlayerChatBubble( i, "(( Ovaj igrac je trenutno ranjen... Umire tacno za 20 sekundi! - /pomozi ))", PLAVA, 40.0, 10000);
			}
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
            
            SendClientMessagee( i, SVETLOCRVENA, "{FF0000}| AC |:"col_white" Ne smijes se voziti na auto!");
		}

	}
	return 1;
}

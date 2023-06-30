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

new tdsector;

stock CreateLoadingTextDraws()
{
	tdsector++;printf("[NE:RP] - Nova Era | Ucitavanje sistema za TDove pod sektorom : %i", tdsector);
	//pubg
	PubgEventTd[0] = TextDrawCreate(506.222229, 229.973327, "LD_SPAC:white");
	TextDrawLetterSize(PubgEventTd[0], 0.000000, 0.000000);
	TextDrawTextSize(PubgEventTd[0], 116.444458, 11.448883);
	TextDrawAlignment(PubgEventTd[0], 1);
	TextDrawColor(PubgEventTd[0], tdboja);
	TextDrawSetShadow(PubgEventTd[0], 0);
	TextDrawSetOutline(PubgEventTd[0], 0);
	TextDrawFont(PubgEventTd[0], 4);

	PubgEventTd[1] = TextDrawCreate(564.222229, 242.922210, "usebox");
	TextDrawLetterSize(PubgEventTd[1], 0.000000, 1.287283);
	TextDrawTextSize(PubgEventTd[1], 504.666687, 0.000000);
	TextDrawAlignment(PubgEventTd[1], 1);
	TextDrawColor(PubgEventTd[1], 0);
	TextDrawUseBox(PubgEventTd[1], true);
	TextDrawBoxColor(PubgEventTd[1], 102);
	TextDrawSetShadow(PubgEventTd[1], 0);
	TextDrawSetOutline(PubgEventTd[1], 0);
	TextDrawFont(PubgEventTd[1], 0);

	PubgEventTd[2] = TextDrawCreate(623.777770, 242.922210, "usebox");
	TextDrawLetterSize(PubgEventTd[2], 0.000000, 1.342594);
	TextDrawTextSize(PubgEventTd[2], 562.888854, 0.000000);
	TextDrawAlignment(PubgEventTd[2], 1);
	TextDrawColor(PubgEventTd[2], 0);
	TextDrawUseBox(PubgEventTd[2], true);
	TextDrawBoxColor(PubgEventTd[2], 102);
	TextDrawSetShadow(PubgEventTd[2], 0);
	TextDrawSetOutline(PubgEventTd[2], 0);
	TextDrawFont(PubgEventTd[2], 0);

	PubgEventTd[3] = TextDrawCreate(509.778106, 228.480072, "PUBG Stats");
	TextDrawLetterSize(PubgEventTd[3], 0.250888, 1.281422);
	TextDrawAlignment(PubgEventTd[3], 1);
	TextDrawColor(PubgEventTd[3], -1);
	TextDrawSetShadow(PubgEventTd[3], 0);
	TextDrawSetOutline(PubgEventTd[3], 1);
	TextDrawBackgroundColor(PubgEventTd[3], 51);
	TextDrawFont(PubgEventTd[3], 3);
	TextDrawSetProportional(PubgEventTd[3], 1);

	PubgEventTd[4] = TextDrawCreate(512.444458, 243.911056, "ZIVIH:");
	TextDrawLetterSize(PubgEventTd[4], 0.207777, 1.062400);
	TextDrawAlignment(PubgEventTd[4], 1);
	TextDrawColor(PubgEventTd[4], -1);
	TextDrawSetShadow(PubgEventTd[4], 0);
	TextDrawSetOutline(PubgEventTd[4], 1);
	TextDrawBackgroundColor(PubgEventTd[4], 51);
	TextDrawFont(PubgEventTd[4], 1);
	TextDrawSetProportional(PubgEventTd[4], 1);

	PubgEventTd[5] = TextDrawCreate(538.222229, 241.422210, "0");
	TextDrawLetterSize(PubgEventTd[5], 0.307333, 1.659733);
	TextDrawAlignment(PubgEventTd[5], 1);
	TextDrawColor(PubgEventTd[5], -1);
	TextDrawSetShadow(PubgEventTd[5], 0);
	TextDrawSetOutline(PubgEventTd[5], 1);
	TextDrawBackgroundColor(PubgEventTd[5], 51);
	TextDrawFont(PubgEventTd[5], 1);
	TextDrawSetProportional(PubgEventTd[5], 1);

	PubgEventTd[6] = TextDrawCreate(569.333312, 242.915634, "KILLS:");
	TextDrawLetterSize(PubgEventTd[6], 0.222888, 1.311288);
	TextDrawAlignment(PubgEventTd[6], 1);
	TextDrawColor(PubgEventTd[6], -1);
	TextDrawSetShadow(PubgEventTd[6], 0);
	TextDrawSetOutline(PubgEventTd[6], 1);
	TextDrawBackgroundColor(PubgEventTd[6], 51);
	TextDrawFont(PubgEventTd[6], 1);
	TextDrawSetProportional(PubgEventTd[6], 1);

	//ucitavanje

	UcitavanjeTextdraw[0] = TextDrawCreate(545.111083, 100.557777, "usebox");
	TextDrawLetterSize(UcitavanjeTextdraw[0], 0.000000, 29.826541);
	TextDrawTextSize(UcitavanjeTextdraw[0], 84.666671, 0.000000);
	TextDrawAlignment(UcitavanjeTextdraw[0], 1);
	TextDrawColor(UcitavanjeTextdraw[0], 0);
	TextDrawUseBox(UcitavanjeTextdraw[0], true);
	TextDrawBoxColor(UcitavanjeTextdraw[0], 102);
	TextDrawSetShadow(UcitavanjeTextdraw[0], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[0], 0);
	TextDrawFont(UcitavanjeTextdraw[0], 0);

	UcitavanjeTextdraw[1] = TextDrawCreate(293.333251, 214.044494, NERP_KRUG);
	TextDrawLetterSize(UcitavanjeTextdraw[1], -0.000000, 0.124444);
	TextDrawTextSize(UcitavanjeTextdraw[1], 50.666656, 58.239974);
	TextDrawAlignment(UcitavanjeTextdraw[1], 1);
	TextDrawColor(UcitavanjeTextdraw[1], tdboja);
	TextDrawSetShadow(UcitavanjeTextdraw[1], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[1], 0);
	TextDrawFont(UcitavanjeTextdraw[1], 4);

	UcitavanjeTextdraw[2] = TextDrawCreate(307.555572, 224.995605, "N");
	TextDrawLetterSize(UcitavanjeTextdraw[2], 0.858444, 3.725511);
	TextDrawAlignment(UcitavanjeTextdraw[2], 1);
	TextDrawColor(UcitavanjeTextdraw[2], -1);
	TextDrawSetShadow(UcitavanjeTextdraw[2], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[2], 2);
	TextDrawBackgroundColor(UcitavanjeTextdraw[2], 51);
	TextDrawFont(UcitavanjeTextdraw[2], 2);
	TextDrawSetProportional(UcitavanjeTextdraw[2], 1);

	UcitavanjeTextdraw[3] = TextDrawCreate(353.111114, 266.317749, "usebox");
	TextDrawLetterSize(UcitavanjeTextdraw[3], 0.000000, 2.614692);
	TextDrawTextSize(UcitavanjeTextdraw[3], 283.333312, 0.000000);
	TextDrawAlignment(UcitavanjeTextdraw[3], 1);
	TextDrawColor(UcitavanjeTextdraw[3], 0);
	TextDrawUseBox(UcitavanjeTextdraw[3], true);
	TextDrawBoxColor(UcitavanjeTextdraw[3], 102);
	TextDrawSetShadow(UcitavanjeTextdraw[3], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[3], 0);
	TextDrawFont(UcitavanjeTextdraw[3], 0);

	UcitavanjeTextdraw[4] = TextDrawCreate(319.111083, 266.808959, "Ucitavanje!");
	TextDrawLetterSize(UcitavanjeTextdraw[4], 0.164222, 1.052444);
	TextDrawAlignment(UcitavanjeTextdraw[4], 2);
	TextDrawColor(UcitavanjeTextdraw[4], -1);
	TextDrawSetShadow(UcitavanjeTextdraw[4], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[4], 1);
	TextDrawBackgroundColor(UcitavanjeTextdraw[4], 51);
	TextDrawFont(UcitavanjeTextdraw[4], 2);
	TextDrawSetProportional(UcitavanjeTextdraw[4], 1);

	UcitavanjeTextdraw[5] = TextDrawCreate(320.000061, 259.840026, "...");
	TextDrawLetterSize(UcitavanjeTextdraw[5], 0.753111, 3.148088);
	TextDrawAlignment(UcitavanjeTextdraw[5], 2);
	TextDrawColor(UcitavanjeTextdraw[5], tdboja);
	TextDrawSetShadow(UcitavanjeTextdraw[5], 0);
	TextDrawSetOutline(UcitavanjeTextdraw[5], 1);
	TextDrawBackgroundColor(UcitavanjeTextdraw[5], 51);
	TextDrawFont(UcitavanjeTextdraw[5], 3);
	TextDrawSetProportional(UcitavanjeTextdraw[5], 1);
}

stock CreateBRACETMLogo()
{
	tdsector++;printf("[NE:RP] - Nova Era | Ucitavanje sistema za TDove pod sektorom : %i", tdsector);
	BraceTeam[0] = TextDrawCreate(0.000000, 0.000000, "LD_SPAC:white");
	TextDrawLetterSize(BraceTeam[0], 0.000000, 0.000000);
	TextDrawTextSize(BraceTeam[0], 640.000000, 448.000000);
	TextDrawAlignment(BraceTeam[0], 1);
	TextDrawColor(BraceTeam[0], 255);
	TextDrawSetShadow(BraceTeam[0], 0);
	TextDrawSetOutline(BraceTeam[0], 0);
	TextDrawFont(BraceTeam[0], 4);

	BraceTeam[1] = TextDrawCreate(174.222351, 163.271163, "BRACE");
	TextDrawLetterSize(BraceTeam[1], 1.405110, 7.991466);
	TextDrawAlignment(BraceTeam[1], 1);
	TextDrawColor(BraceTeam[1], -1);
	TextDrawSetShadow(BraceTeam[1], 0);
	TextDrawSetOutline(BraceTeam[1], 1);
	TextDrawBackgroundColor(BraceTeam[1], 51);
	TextDrawFont(BraceTeam[1], 2);
	TextDrawSetProportional(BraceTeam[1], 1);

	BraceTeam[2] = TextDrawCreate(376.000000, 184.177795, "TM");
	TextDrawLetterSize(BraceTeam[2], 0.991333, 4.044088);
	TextDrawAlignment(BraceTeam[2], 1);
	TextDrawColor(BraceTeam[2], -1);
	TextDrawSetShadow(BraceTeam[2], 0);
	TextDrawSetOutline(BraceTeam[2], 1);
	TextDrawBackgroundColor(BraceTeam[2], 51);
	TextDrawFont(BraceTeam[2], 1);
	TextDrawSetProportional(BraceTeam[2], 1);

	BraceTeam[3] = TextDrawCreate(168.888885, 236.444458, "LD_SPAC:white");
	TextDrawLetterSize(BraceTeam[3], 0.000000, 0.000000);
	TextDrawTextSize(BraceTeam[3], 270.666656, -4.480010);
	TextDrawAlignment(BraceTeam[3], 1);
	TextDrawColor(BraceTeam[3], -1);
	TextDrawSetShadow(BraceTeam[3], 0);
	TextDrawSetOutline(BraceTeam[3], 0);
	TextDrawFont(BraceTeam[3], 4);

	BraceTeam[4] = TextDrawCreate(358.222229, 176.213317, "(R)");
	TextDrawLetterSize(BraceTeam[4], 0.247333, 1.012622);
	TextDrawAlignment(BraceTeam[4], 1);
	TextDrawColor(BraceTeam[4], -1);
	TextDrawSetShadow(BraceTeam[4], 0);
	TextDrawSetOutline(BraceTeam[4], 1);
	TextDrawBackgroundColor(BraceTeam[4], 51);
	TextDrawFont(BraceTeam[4], 1);
	TextDrawSetProportional(BraceTeam[4], 1);

	BraceTeam[5] = TextDrawCreate(169.333374, 232.462203, "...................................................");
	TextDrawLetterSize(BraceTeam[5], 0.409555, 1.535288);
	TextDrawAlignment(BraceTeam[5], 1);
	TextDrawColor(BraceTeam[5], -1);
	TextDrawSetShadow(BraceTeam[5], 0);
	TextDrawSetOutline(BraceTeam[5], 1);
	TextDrawBackgroundColor(BraceTeam[5], 51);
	TextDrawFont(BraceTeam[5], 1);
	TextDrawSetProportional(BraceTeam[5], 1);

	BraceTeam[6] = TextDrawCreate(262.222106, 256.355590, "Since 2022.");
	TextDrawLetterSize(BraceTeam[6], 0.449999, 1.600000);
	TextDrawAlignment(BraceTeam[6], 1);
	TextDrawColor(BraceTeam[6], -1);
	TextDrawSetShadow(BraceTeam[6], 0);
	TextDrawSetOutline(BraceTeam[6], 1);
	TextDrawBackgroundColor(BraceTeam[6], 51);
	TextDrawFont(BraceTeam[6], 0);
	TextDrawSetProportional(BraceTeam[6], 1);

	BraceTeam[7] = TextDrawCreate(402.500000, 357.875000, "presents...");
	TextDrawLetterSize(BraceTeam[7], 0.593499, 2.229999);
	TextDrawAlignment(BraceTeam[7], 1);
	TextDrawColor(BraceTeam[7], -1);
	TextDrawSetShadow(BraceTeam[7], 0);
	TextDrawSetOutline(BraceTeam[7], 1);
	TextDrawBackgroundColor(BraceTeam[7], 51);
	TextDrawFont(BraceTeam[7], 0);
	TextDrawSetProportional(BraceTeam[7], 1);
	return 1;
}

stock CreateTextDraws( ) 
{
	tdsector++;printf("[NE:RP] - Nova Era | Ucitavanje sistema za TDove pod sektorom : %i", tdsector);
	LoginTextdraws[0] = TextDrawCreate(641.500000, 1.500000, "usebox");
	TextDrawLetterSize(LoginTextdraws[0], 0.000000, 11.009721);
	TextDrawTextSize(LoginTextdraws[0], -2.000000, 0.000000);
	TextDrawAlignment(LoginTextdraws[0], 1);
	TextDrawColor(LoginTextdraws[0], 0);
	TextDrawUseBox(LoginTextdraws[0], true);
	TextDrawBoxColor(LoginTextdraws[0], 102);
	TextDrawSetShadow(LoginTextdraws[0], 0);
	TextDrawSetOutline(LoginTextdraws[0], 0);
	TextDrawFont(LoginTextdraws[0], 0);

	LoginTextdraws[1] = TextDrawCreate(183.000000, -0.875000, NERP_KRUG);
	TextDrawLetterSize(LoginTextdraws[1], 0.000000, 0.000000);
	TextDrawTextSize(LoginTextdraws[1], 99.500000, 98.437500);
	TextDrawAlignment(LoginTextdraws[1], 1);
	TextDrawColor(LoginTextdraws[1], tdboja);
	TextDrawSetShadow(LoginTextdraws[1], 0);
	TextDrawSetOutline(LoginTextdraws[1], 0);
	TextDrawFont(LoginTextdraws[1], 4);

	LoginTextdraws[2] = TextDrawCreate(229.000000, 16.187500, "LD_SPAC:white");
	TextDrawLetterSize(LoginTextdraws[2], 0.000000, 0.000000);
	TextDrawTextSize(LoginTextdraws[2], 153.000000, 3.062500);
	TextDrawAlignment(LoginTextdraws[2], 1);
	TextDrawColor(LoginTextdraws[2], tdboja);
	TextDrawSetShadow(LoginTextdraws[2], 0);
	TextDrawSetOutline(LoginTextdraws[2], 0);
	TextDrawFont(LoginTextdraws[2], 4);

	LoginTextdraws[3] = TextDrawCreate(373.500000, 3.937500, "]");
	TextDrawLetterSize(LoginTextdraws[3], 0.619998, 2.663124);
	TextDrawAlignment(LoginTextdraws[3], 1);
	TextDrawColor(LoginTextdraws[3], tdboja);
	TextDrawSetShadow(LoginTextdraws[3], 0);
	TextDrawSetOutline(LoginTextdraws[3], 1);
	TextDrawBackgroundColor(LoginTextdraws[3], 51);
	TextDrawFont(LoginTextdraws[3], 2);
	TextDrawSetProportional(LoginTextdraws[3], 1);

	LoginTextdraws[4] = TextDrawCreate(211.500000, 14.875000, "N");
	TextDrawLetterSize(LoginTextdraws[4], 1.534499, 6.499992);
	TextDrawAlignment(LoginTextdraws[4], 1);
	TextDrawColor(LoginTextdraws[4], -1);
	TextDrawSetShadow(LoginTextdraws[4], 0);
	TextDrawSetOutline(LoginTextdraws[4], 1);
	TextDrawBackgroundColor(LoginTextdraws[4], 51);
	TextDrawFont(LoginTextdraws[4], 2);
	TextDrawSetProportional(LoginTextdraws[4], 1);

	LoginTextdraws[5] = TextDrawCreate(262.000000, 19.687500, "]]]]]]]]]]]]]]]");
	TextDrawLetterSize(LoginTextdraws[5], 0.222498, 0.978749);
	TextDrawAlignment(LoginTextdraws[5], 1);
	TextDrawColor(LoginTextdraws[5], -1);
	TextDrawSetShadow(LoginTextdraws[5], 0);
	TextDrawSetOutline(LoginTextdraws[5], 1);
	TextDrawBackgroundColor(LoginTextdraws[5], 51);
	TextDrawFont(LoginTextdraws[5], 2);
	TextDrawSetProportional(LoginTextdraws[5], 1);

	LoginTextdraws[6] = TextDrawCreate(289.000000, 32.375000, "Nova Era");
	TextDrawLetterSize(LoginTextdraws[6], 0.654999, 2.400624);
	TextDrawAlignment(LoginTextdraws[6], 1);
	TextDrawColor(LoginTextdraws[6], tdboja);
	TextDrawSetShadow(LoginTextdraws[6], 0);
	TextDrawSetOutline(LoginTextdraws[6], 1);
	TextDrawBackgroundColor(LoginTextdraws[6], 51);
	TextDrawFont(LoginTextdraws[6], 0);
	TextDrawSetProportional(LoginTextdraws[6], 1);

	LoginTextdraws[7] = TextDrawCreate(278.000000, 56.875000, "Online Gaming Community");
	TextDrawLetterSize(LoginTextdraws[7], 0.188500, 0.847500);
	TextDrawAlignment(LoginTextdraws[7], 1);
	TextDrawColor(LoginTextdraws[7], -1);
	TextDrawSetShadow(LoginTextdraws[7], 0);
	TextDrawSetOutline(LoginTextdraws[7], 1);
	TextDrawBackgroundColor(LoginTextdraws[7], 51);
	TextDrawFont(LoginTextdraws[7], 2);
	TextDrawSetProportional(LoginTextdraws[7], 1);

	LoginTextdraws[8] = TextDrawCreate(395.500000, 33.437500, "usebox");
	TextDrawLetterSize(LoginTextdraws[8], 0.000000, 4.252777);
	TextDrawTextSize(LoginTextdraws[8], 269.500000, 0.000000);
	TextDrawAlignment(LoginTextdraws[8], 1);
	TextDrawColor(LoginTextdraws[8], 0);
	TextDrawUseBox(LoginTextdraws[8], true);
	TextDrawBoxColor(LoginTextdraws[8], 102);
	TextDrawSetShadow(LoginTextdraws[8], 0);
	TextDrawSetOutline(LoginTextdraws[8], 0);
	TextDrawFont(LoginTextdraws[8], 0);

	betaversiontd = TextDrawCreate(317.778167, 7.466666, betaver);	
	TextDrawLetterSize(betaversiontd, 0.136222, 0.818488);
	TextDrawAlignment(betaversiontd, 2);
	TextDrawColor(betaversiontd, tdboja);
	TextDrawSetShadow(betaversiontd, 0);
	TextDrawSetOutline(betaversiontd, 1);
	TextDrawBackgroundColor(betaversiontd, 51);
	TextDrawFont(betaversiontd, 1);
	TextDrawSetProportional(betaversiontd, 1);

	gamemodetd[0] = TextDrawCreate(50.941173, 327.250244, "LD_SPAC:white");
	TextDrawLetterSize(gamemodetd[0], 0.000000, 0.000000);
	TextDrawTextSize(gamemodetd[0], 127.529418, 43.750000);
	TextDrawAlignment(gamemodetd[0], 1);
	TextDrawColor(gamemodetd[0], tdboja);
	TextDrawSetShadow(gamemodetd[0], 0);
	TextDrawSetOutline(gamemodetd[0], 0);
	TextDrawFont(gamemodetd[0], 4);

	gamemodetd[1] = TextDrawCreate(73.411689, 327.833374, "PLAY");
	TextDrawLetterSize(gamemodetd[1], 1.070705, 4.633332);
	TextDrawAlignment(gamemodetd[1], 1);
	TextDrawColor(gamemodetd[1], -1);
	TextDrawSetShadow(gamemodetd[1], 0);
	TextDrawSetOutline(gamemodetd[1], 1);
	TextDrawBackgroundColor(gamemodetd[1], 51);
	TextDrawFont(gamemodetd[1], 3);
	TextDrawSetProportional(gamemodetd[1], 1);
	TextDrawSetSelectable(gamemodetd[1], true);

	gamemodetd[2] = TextDrawCreate(153.058898, 305.416687, "usebox");
	TextDrawLetterSize(gamemodetd[2], 0.000000, 1.804466);
	TextDrawTextSize(gamemodetd[2], 49.294090, 0.000000);
	TextDrawAlignment(gamemodetd[2], 1);
	TextDrawColor(gamemodetd[2], 0);
	TextDrawUseBox(gamemodetd[2], true);
	TextDrawBoxColor(gamemodetd[2], 102);
	TextDrawSetShadow(gamemodetd[2], 0);
	TextDrawSetOutline(gamemodetd[2], 0);
	TextDrawFont(gamemodetd[2], 0);

	gamemodetd[3] = TextDrawCreate(51.764659, 266.583374, "Odaberite game mode koji zelite igrati.~n~Gamemodove (evente) mozete mijenjati ingame komandama.~n~Default game mode: RolePlay");
	TextDrawLetterSize(gamemodetd[3], 0.152117, 1.110000);
	TextDrawAlignment(gamemodetd[3], 1);
	TextDrawColor(gamemodetd[3], -1);
	TextDrawSetShadow(gamemodetd[3], 0);
	TextDrawSetOutline(gamemodetd[3], 1);
	TextDrawBackgroundColor(gamemodetd[3], 51);
	TextDrawFont(gamemodetd[3], 2);
	TextDrawSetProportional(gamemodetd[3], 1);

	gamemodetd[4] = TextDrawCreate(150.117645, 293.416717, NERP_KRUG);
	TextDrawLetterSize(gamemodetd[4], 0.000000, 0.000000);
	TextDrawTextSize(gamemodetd[4], 32.470550, 36.749969);
	TextDrawAlignment(gamemodetd[4], 1);
	TextDrawColor(gamemodetd[4], tdboja);
	TextDrawSetShadow(gamemodetd[4], 0);
	TextDrawSetOutline(gamemodetd[4], 0);
	TextDrawBackgroundColor(gamemodetd[4], -1061109505);
	TextDrawFont(gamemodetd[4], 4);

	gamemodetd[5] = TextDrawCreate(161.411758, 313.833312, "LD_SPAC:white");
	TextDrawLetterSize(gamemodetd[5], 0.000000, 0.000000);
	TextDrawTextSize(gamemodetd[5], 8.941177, 20.416687);
	TextDrawAlignment(gamemodetd[5], 1);
	TextDrawColor(gamemodetd[5], tdboja);
	TextDrawSetShadow(gamemodetd[5], 0);
	TextDrawSetOutline(gamemodetd[5], 0);
	TextDrawFont(gamemodetd[5], 4);

	gamemodetd[6] = TextDrawCreate(160.470626, 298.083374, "?");
	TextDrawLetterSize(gamemodetd[6], 0.744587, 2.941666);
	TextDrawAlignment(gamemodetd[6], 1);
	TextDrawColor(gamemodetd[6], -1);
	TextDrawSetShadow(gamemodetd[6], 0);
	TextDrawSetOutline(gamemodetd[6], 1);
	TextDrawBackgroundColor(gamemodetd[6], 51);
	TextDrawFont(gamemodetd[6], 1);
	TextDrawSetProportional(gamemodetd[6], 1);
	TextDrawSetSelectable(gamemodetd[6], true);

	gamemodetd[7] = TextDrawCreate(653.293884, 185.250000, "usebox");
	TextDrawLetterSize(gamemodetd[7], 0.000000, 20.704565);
	TextDrawTextSize(gamemodetd[7], 288.823547, 0.000000);
	TextDrawAlignment(gamemodetd[7], 1);
	TextDrawColor(gamemodetd[7], 0);
	TextDrawUseBox(gamemodetd[7], true);
	TextDrawBoxColor(gamemodetd[7], 102);
	TextDrawSetShadow(gamemodetd[7], 0);
	TextDrawSetOutline(gamemodetd[7], 0);
	TextDrawFont(gamemodetd[7], 0);

	gamemodetd[8] = TextDrawCreate(297.411743, 187.833343, "RolePlay");
	TextDrawLetterSize(gamemodetd[8], 0.467882, 1.844999);
	TextDrawAlignment(gamemodetd[8], 1);
	TextDrawColor(gamemodetd[8], -1);
	TextDrawSetShadow(gamemodetd[8], 0);
	TextDrawSetOutline(gamemodetd[8], 1);
	TextDrawBackgroundColor(gamemodetd[8], 51);
	TextDrawFont(gamemodetd[8], 0);
	TextDrawSetProportional(gamemodetd[8], 1);

	gamemodetd[9] = TextDrawCreate(299.294097, 211.750000, "- Ovo je classic i default game mode. Mozete posjedovati svoje vozilo, biti u organizaciji ili jednostavno imati posao.");
	TextDrawLetterSize(gamemodetd[9], 0.108352, 1.454165);
	TextDrawAlignment(gamemodetd[9], 1);
	TextDrawColor(gamemodetd[9], -1);
	TextDrawSetShadow(gamemodetd[9], 0);
	TextDrawSetOutline(gamemodetd[9], 1);
	TextDrawBackgroundColor(gamemodetd[9], 51);
	TextDrawFont(gamemodetd[9], 2);
	TextDrawSetProportional(gamemodetd[9], 1);

	gamemodetd[10] = TextDrawCreate(299.764739, 222.833374, "- U roleplay modu, imate razne mogucnosti i komande, mozete biti mafijas, prodavati stvari, imati kucu i jos mnogo toga.");
	TextDrawLetterSize(gamemodetd[10], 0.113999, 1.477500);
	TextDrawAlignment(gamemodetd[10], 1);
	TextDrawColor(gamemodetd[10], -1);
	TextDrawSetShadow(gamemodetd[10], 0);
	TextDrawSetOutline(gamemodetd[10], 1);
	TextDrawBackgroundColor(gamemodetd[10], 51);
	TextDrawFont(gamemodetd[10], 2);
	TextDrawSetProportional(gamemodetd[10], 1);

	gamemodetd[11] = TextDrawCreate(298.823577, 254.333328, "DeathMatch");
	TextDrawLetterSize(gamemodetd[11], 0.449999, 1.600000);
	TextDrawAlignment(gamemodetd[11], 1);
	TextDrawColor(gamemodetd[11], -1);
	TextDrawSetShadow(gamemodetd[11], 0);
	TextDrawSetOutline(gamemodetd[11], 1);
	TextDrawBackgroundColor(gamemodetd[11], 51);
	TextDrawFont(gamemodetd[11], 3);
	TextDrawSetProportional(gamemodetd[11], 1);

	gamemodetd[12] = TextDrawCreate(302.588287, 275.333343, "- Na deathmatch game modeu se pucate sa ostalim igracima. ~n~Oruzje koje koristite dobijate na osnovu ranka (nivoa).");
	TextDrawLetterSize(gamemodetd[12], 0.153999, 1.127498);
	TextDrawAlignment(gamemodetd[12], 1);
	TextDrawColor(gamemodetd[12], -1);
	TextDrawSetShadow(gamemodetd[12], 0);
	TextDrawSetOutline(gamemodetd[12], 1);
	TextDrawBackgroundColor(gamemodetd[12], 51);
	TextDrawFont(gamemodetd[12], 2);
	TextDrawSetProportional(gamemodetd[12], 1);

	gamemodetd[13] = TextDrawCreate(300.676483, 311.937438, "PUBG");
	TextDrawLetterSize(gamemodetd[13], 0.449999, 1.600000);
	TextDrawAlignment(gamemodetd[13], 1);
	TextDrawColor(gamemodetd[13], -1);
	TextDrawSetShadow(gamemodetd[13], 0);
	TextDrawSetOutline(gamemodetd[13], 1);
	TextDrawBackgroundColor(gamemodetd[13], 51);
	TextDrawFont(gamemodetd[13], 1);
	TextDrawSetProportional(gamemodetd[13], 1);

	gamemodetd[14] = TextDrawCreate(338.352813, 320.833343, "BETA");
	TextDrawLetterSize(gamemodetd[14], 0.162470, 1.016666);
	TextDrawAlignment(gamemodetd[14], 1);
	TextDrawColor(gamemodetd[14], tdboja);
	TextDrawSetShadow(gamemodetd[14], 0);
	TextDrawSetOutline(gamemodetd[14], 1);
	TextDrawBackgroundColor(gamemodetd[14], 51);
	TextDrawFont(gamemodetd[14], 2);
	TextDrawSetProportional(gamemodetd[14], 1);

	gamemodetd[15] = TextDrawCreate(303.529449, 331.916717, "- Battle royale mode, pronadjite oruzje sirom San Andreasa, vozite se i pucajte se sa ostalim igracima!");
	TextDrawLetterSize(gamemodetd[15], 0.127646, 1.389999);
	TextDrawAlignment(gamemodetd[15], 1);
	TextDrawColor(gamemodetd[15], -1);
	TextDrawSetShadow(gamemodetd[15], 0);
	TextDrawSetOutline(gamemodetd[15], 1);
	TextDrawBackgroundColor(gamemodetd[15], 51);
	TextDrawFont(gamemodetd[15], 2);
	TextDrawSetProportional(gamemodetd[15], 1);

	gamemodetd[16] = TextDrawCreate(308.235229, 342.416687, "Zadnji igrac koji je opstao pobjedjuje match!");
	TextDrawLetterSize(gamemodetd[16], 0.134705, 1.267499);
	TextDrawAlignment(gamemodetd[16], 1);
	TextDrawColor(gamemodetd[16], -1);
	TextDrawSetShadow(gamemodetd[16], 0);
	TextDrawSetOutline(gamemodetd[16], 1);
	TextDrawBackgroundColor(gamemodetd[16], 51);
	TextDrawFont(gamemodetd[16], 2);
	TextDrawSetProportional(gamemodetd[16], 1);

	gamemodetd[17] = TextDrawCreate(521.882385, 191.333343, "ODABRAO SAM GAMEMODE");
	TextDrawLetterSize(gamemodetd[17], 0.168117, 1.086665);
	TextDrawAlignment(gamemodetd[17], 1);
	TextDrawColor(gamemodetd[17], -1);
	TextDrawSetShadow(gamemodetd[17], 0);
	TextDrawSetOutline(gamemodetd[17], 1);
	TextDrawBackgroundColor(gamemodetd[17], 51);
	TextDrawFont(gamemodetd[17], 2);
	TextDrawSetProportional(gamemodetd[17], 1);

	gamemodetd[18] = TextDrawCreate(618.470581, 192.833343, "usebox");
	TextDrawLetterSize(gamemodetd[18], 0.000000, 1.044444);
	TextDrawTextSize(gamemodetd[18], 514.235290, 0.000000);
	TextDrawAlignment(gamemodetd[18], 1);
	TextDrawColor(gamemodetd[18], 0);
	TextDrawUseBox(gamemodetd[18], true);
	TextDrawBoxColor(gamemodetd[18], 102);
	TextDrawSetShadow(gamemodetd[18], 0);
	TextDrawSetOutline(gamemodetd[18], 0);
	TextDrawFont(gamemodetd[18], 0);

   
	// PARE/MONEY TD
	moneytd0 = TextDrawCreate(366.444427, 363.882232,"");// "usebox");
	TextDrawLetterSize(moneytd0, 0.000000, 1.840366);
	TextDrawTextSize(moneytd0, 267.333312, 0.000000);
	TextDrawAlignment(moneytd0, 1);
	TextDrawColor(moneytd0, 0);
	//TextDrawUseBox(moneytd0, true);
	TextDrawBoxColor(moneytd0, 102);
	TextDrawSetShadow(moneytd0, 0);
	TextDrawSetOutline(moneytd0, 0);
	TextDrawFont(moneytd0, 0);

	moneytd1 = TextDrawCreate(265.333374, 362.879974, "$");
	TextDrawLetterSize(moneytd1, 0.485555, 1.908622);
	TextDrawAlignment(moneytd1, 1);
	TextDrawColor(moneytd1, tdboja);
	TextDrawSetShadow(moneytd1, 0);
	TextDrawSetOutline(moneytd1, 1);
	TextDrawBackgroundColor(moneytd1, 51);
	TextDrawFont(moneytd1, 3);
	TextDrawSetProportional(moneytd1, 1);

	// BETA ANNOUNCEMENT
	betatextdraw0 = TextDrawCreate(312.400024, 120.966674, "usebox");
	TextDrawLetterSize(betatextdraw0, 0.000000, 3.416665);
	TextDrawTextSize(betatextdraw0, 34.000000, 0.000000);
	TextDrawAlignment(betatextdraw0, 1);
	TextDrawColor(betatextdraw0, 0);
	TextDrawUseBox(betatextdraw0, true);
	TextDrawBoxColor(betatextdraw0, 102);
	TextDrawSetShadow(betatextdraw0, 0);
	TextDrawSetOutline(betatextdraw0, 0);
	TextDrawFont(betatextdraw0, 0);

	betatextdraw1 = TextDrawCreate(24.000019, 119.466674, NERP_KRUG);
	TextDrawLetterSize(betatextdraw1, 0.000000, 0.000000);
	TextDrawTextSize(betatextdraw1, 27.999963, 32.853298);
	TextDrawAlignment(betatextdraw1, 1);
	TextDrawColor(betatextdraw1, tdboja);
	TextDrawSetShadow(betatextdraw1, 0);
	TextDrawSetOutline(betatextdraw1, 0);
	TextDrawFont(betatextdraw1, 4);

	betatextdraw2 = TextDrawCreate(33.600009, 124.693344, "!");
	TextDrawLetterSize(betatextdraw2, 0.777200, 2.264532);
	TextDrawAlignment(betatextdraw2, 1);
	TextDrawColor(betatextdraw2, -1);
	TextDrawSetShadow(betatextdraw2, 0);
	TextDrawSetOutline(betatextdraw2, 1);
	TextDrawBackgroundColor(betatextdraw2, 51);
	TextDrawFont(betatextdraw2, 1);
	TextDrawSetProportional(betatextdraw2, 1);

	betatextdraw3 = TextDrawCreate(48.799999, 116.479972, "Nova Era - RolePlay");
	TextDrawLetterSize(betatextdraw3, 0.449999, 1.600000);
	TextDrawAlignment(betatextdraw3, 1);
	TextDrawColor(betatextdraw3, tdboja);
	TextDrawSetShadow(betatextdraw3, 0);
	TextDrawSetOutline(betatextdraw3, 1);
	TextDrawBackgroundColor(betatextdraw3, 51);
	TextDrawFont(betatextdraw3, 0);
	TextDrawSetProportional(betatextdraw3, 1);

	betatextdraw4 = TextDrawCreate(53.599979, 132.160049, "- Postovani, uzmite u obzir da trenuntno~n~ne igrate na finajlnoj verziji.");
	TextDrawLetterSize(betatextdraw4, 0.181199, 0.756266);
	TextDrawAlignment(betatextdraw4, 1);
	TextDrawColor(betatextdraw4, -1);
	TextDrawSetShadow(betatextdraw4, 0);
	TextDrawSetOutline(betatextdraw4, 1);
	TextDrawBackgroundColor(betatextdraw4, 51);
	TextDrawFont(betatextdraw4, 2);
	TextDrawSetProportional(betatextdraw4, 1);

	betatextdraw5 = TextDrawCreate(52.800010, 144.106689, "- Trenutna verzija ne reprezentira konacne rezultate.");
	TextDrawLetterSize(betatextdraw5, 0.141199, 1.144532);
	TextDrawAlignment(betatextdraw5, 1);
	TextDrawColor(betatextdraw5, -1);
	TextDrawSetShadow(betatextdraw5, 0);
	TextDrawSetOutline(betatextdraw5, 1);
	TextDrawBackgroundColor(betatextdraw5, 51);
	TextDrawFont(betatextdraw5, 2);
	TextDrawSetProportional(betatextdraw5, 1);

	betatextdraw6 = TextDrawCreate(244.799987, 147.839920, "/report");
	TextDrawLetterSize(betatextdraw6, 0.449999, 1.600000);
	TextDrawAlignment(betatextdraw6, 1);
	TextDrawColor(betatextdraw6, tdboja);
	TextDrawSetShadow(betatextdraw6, 0);
	TextDrawSetOutline(betatextdraw6, 1);
	TextDrawBackgroundColor(betatextdraw6, 51);
	TextDrawFont(betatextdraw6, 3);
	TextDrawSetProportional(betatextdraw6, 1);

	// HEALTH BAR
	healthbar0 = TextDrawCreate(546.666564, 67.697784, "LD_SPAC:white");
	TextDrawLetterSize(healthbar0, 0.000000, 0.000000);
	TextDrawTextSize(healthbar0, 60.888912, 9.955554);
	TextDrawAlignment(healthbar0, 1);
	TextDrawColor(healthbar0, 255);
	TextDrawSetShadow(healthbar0, 0);
	TextDrawSetOutline(healthbar0, 0);
	TextDrawFont(healthbar0, 4);

	healthbar1 = TextDrawCreate(548.444458, 69.688888, "LD_SPAC:white");
	TextDrawLetterSize(healthbar1, 0.000000, 0.000000);
	TextDrawTextSize(healthbar1, 56.444396, 5.973327);
	TextDrawAlignment(healthbar1, 1);
	TextDrawColor(healthbar1, tdboja);
	TextDrawSetShadow(healthbar1, 0);
	TextDrawSetOutline(healthbar1, 0);
	TextDrawFont(healthbar1, 4);

	healthbar2 = TextDrawCreate(558.222167, 69.688865, "Ranjen si...");
	TextDrawLetterSize(healthbar2, 0.142000, 0.699022);
	TextDrawAlignment(healthbar2, 1);
	TextDrawColor(healthbar2, -1);
	TextDrawSetShadow(healthbar2, 0);
	TextDrawSetOutline(healthbar2, 1);
	TextDrawBackgroundColor(healthbar2, 51);
	TextDrawFont(healthbar2, 2);
	TextDrawSetProportional(healthbar2, 1);
	// INJURY
	injured0 = TextDrawCreate(418.444427, 169.251113, "usebox");
	TextDrawLetterSize(injured0, 0.000000, 1.342592);
	TextDrawTextSize(injured0, 204.666656, 0.000000);
	TextDrawAlignment(injured0, 1);
	TextDrawColor(injured0, 0);
	TextDrawUseBox(injured0, true);
	TextDrawBoxColor(injured0, 102);
	TextDrawSetShadow(injured0, 0);
	TextDrawSetOutline(injured0, 0);
	TextDrawFont(injured0, 0);

	injured1 = TextDrawCreate(418.888885, 191.651107, "usebox");
	TextDrawLetterSize(injured1, 0.000000, 11.242841);
	TextDrawTextSize(injured1, 204.666656, 0.000000);
	TextDrawAlignment(injured1, 1);
	TextDrawColor(injured1, 0);
	TextDrawUseBox(injured1, true);
	TextDrawBoxColor(injured1, 102);
	TextDrawSetShadow(injured1, 0);
	TextDrawSetOutline(injured1, 0);
	TextDrawFont(injured1, 0);

	injured2 = TextDrawCreate(208.888839, 167.751113, "LD_CHAT:badchat");
	TextDrawLetterSize(injured2, 0.000000, 0.000000);
	TextDrawTextSize(injured2, 11.555562, 13.440010);
	TextDrawAlignment(injured2, 1);
	TextDrawColor(injured2, -1);
	TextDrawSetShadow(injured2, 0);
	TextDrawSetOutline(injured2, 0);
	TextDrawFont(injured2, 4);

	injured3 = TextDrawCreate(224.000045, 162.773345, "Ranjeni ste!");
	TextDrawLetterSize(injured3, 0.613111, 2.177422);
	TextDrawAlignment(injured3, 1);
	TextDrawColor(injured3, tdboja);
	TextDrawSetShadow(injured3, 0);
	TextDrawSetOutline(injured3, 1);
	TextDrawBackgroundColor(injured3, 51);
	TextDrawFont(injured3, 0);
	TextDrawSetProportional(injured3, 1);

	injured4 = TextDrawCreate(218.222213, 205.582214, "- Vi ste trenutno ranjeni...");
	TextDrawLetterSize(injured4, 0.194444, 0.947910);
	TextDrawAlignment(injured4, 1);
	TextDrawColor(injured4, -1);
	TextDrawSetShadow(injured4, 0);
	TextDrawSetOutline(injured4, 1);
	TextDrawBackgroundColor(injured4, 51);
	TextDrawFont(injured4, 2);
	TextDrawSetProportional(injured4, 1);

	injured5 = TextDrawCreate(218.666702, 224.000000, "- Ne mozete se kretati dok ste ranjeni.");
	TextDrawLetterSize(injured5, 0.191333, 1.007645);
	TextDrawAlignment(injured5, 1);
	TextDrawColor(injured5, -1);
	TextDrawSetShadow(injured5, 0);
	TextDrawSetOutline(injured5, 1);
	TextDrawBackgroundColor(injured5, 51);
	TextDrawFont(injured5, 2);
	TextDrawSetProportional(injured5, 1);

	injured6 = TextDrawCreate(218.666625, 267.804351, "- Umirete za 20 sekundi, sacekajte...");
	TextDrawLetterSize(injured6, 0.200222, 0.982756);
	TextDrawAlignment(injured6, 1);
	TextDrawColor(injured6, -1);
	TextDrawSetShadow(injured6, 0);
	TextDrawSetOutline(injured6, 1);
	TextDrawBackgroundColor(injured6, 51);
	TextDrawFont(injured6, 2);
	TextDrawSetProportional(injured6, 1);
	// CONNECT TD
	connect0 = TextDrawCreate(205.777770, 157.297775, "Dobrodosli na...");
	TextDrawLetterSize(connect0, 0.670444, 4.083911);
	TextDrawAlignment(connect0, 1);
	TextDrawColor(connect0, -1);
	TextDrawSetShadow(connect0, 0);
	TextDrawSetOutline(connect0, 2);
	TextDrawBackgroundColor(connect0, 51);
	TextDrawFont(connect0, 0);
	TextDrawSetProportional(connect0, 1);

	connect1 = TextDrawCreate(280.888854, 214.044448, "Nova Era");
	TextDrawLetterSize(connect1, 0.879333, 5.706667);
	TextDrawAlignment(connect1, 1);
	TextDrawColor(connect1, tdboja);
	TextDrawSetShadow(connect1, 0);
	TextDrawSetOutline(connect1, 1);
	TextDrawBackgroundColor(connect1, 51);
	TextDrawFont(connect1, 3);
	TextDrawSetProportional(connect1, 1);

	connect2 = TextDrawCreate(297.777770, 252.871139, "Online Gaming Community");
	TextDrawLetterSize(connect2, 0.183777, 1.470577);
	TextDrawAlignment(connect2, 1);
	TextDrawColor(connect2, -1);
	TextDrawSetShadow(connect2, 0);
	TextDrawSetOutline(connect2, 1);
	TextDrawBackgroundColor(connect2, 51);
	TextDrawFont(connect2, 2);
	TextDrawSetProportional(connect2, 1);

	#if defined papadudbrkbre

	new srwver1[200];
	format(srwver1,sizeof(srwver1),"%s",verzija);

	#endif

	connect3 = TextDrawCreate(230.222229, 290.702239, NERP_VERZIJA);
	TextDrawLetterSize(connect3, 0.485111, 4.297956);
	TextDrawAlignment(connect3, 1);
	TextDrawColor(connect3, tdboja);
	TextDrawSetShadow(connect3, 0);
	TextDrawSetOutline(connect3, 1);
	TextDrawBackgroundColor(connect3, 51);
	TextDrawFont(connect3, 3);
	TextDrawSetProportional(connect3, 1);

	connect4 = TextDrawCreate(192.444503, 196.622268, NERP_KRUG);
	TextDrawLetterSize(connect4, 0.000000, 0.000000);
	TextDrawTextSize(connect4, 89.777786, 98.559982);
	TextDrawAlignment(connect4, 1);
	TextDrawColor(connect4, tdboja);
	TextDrawSetShadow(connect4, 0);
	TextDrawSetOutline(connect4, 0);
	TextDrawFont(connect4, 4);

	connect5 = TextDrawCreate(216.888885, 213.546691, "N");
	TextDrawLetterSize(connect5, 1.558889, 6.358756);
	TextDrawAlignment(connect5, 1);
	TextDrawColor(connect5, -1);
	TextDrawSetShadow(connect5, 0);
	TextDrawSetOutline(connect5, 1);
	TextDrawBackgroundColor(connect5, 51);
	TextDrawFont(connect5, 2);
	TextDrawSetProportional(connect5, 1);

	// KLADIONICA SISTEM
	kladionica0 = TextDrawCreate(439.777770, 169.748886, "usebox");
	TextDrawLetterSize(kladionica0, 0.000000, 16.165309);
	TextDrawTextSize(kladionica0, 217.111114, 0.000000);
	TextDrawAlignment(kladionica0, 1);
	TextDrawColor(kladionica0, 0);
	TextDrawUseBox(kladionica0, true);
	TextDrawBoxColor(kladionica0, 102);
	TextDrawSetShadow(kladionica0, 0);
	TextDrawSetOutline(kladionica0, 0);
	TextDrawFont(kladionica0, 0);

	kladionica1 = TextDrawCreate(423.111236, 163.768936, "LD_CHAT:badchat");
	TextDrawLetterSize(kladionica1, 0.000000, 0.000000);
	TextDrawTextSize(kladionica1, 18.222202, 18.417791);
	TextDrawAlignment(kladionica1, 1);
	TextDrawColor(kladionica1, -1);
	TextDrawSetShadow(kladionica1, 0);
	TextDrawSetOutline(kladionica1, 0);
	TextDrawFont(kladionica1, 4);

	kladionica2 = TextDrawCreate(171.555572, 188.160018, NERP_KRUG);
	TextDrawLetterSize(kladionica2, 0.000000, 0.000000);
	TextDrawTextSize(kladionica2, 313.333282, 4.977791);
	TextDrawAlignment(kladionica2, 1);
	TextDrawColor(kladionica2, tdboja);
	TextDrawSetShadow(kladionica2, 0);
	TextDrawSetOutline(kladionica2, 0);
	TextDrawFont(kladionica2, 4);

	kladionica3 = TextDrawCreate(284.888854, 165.760040, "Kladionica");
	TextDrawLetterSize(kladionica3, 0.766444, 2.834489);
	TextDrawAlignment(kladionica3, 1);
	TextDrawColor(kladionica3, -1);
	TextDrawSetShadow(kladionica3, 0);
	TextDrawSetOutline(kladionica3, 1);
	TextDrawBackgroundColor(kladionica3, 51);
	TextDrawFont(kladionica3, 0);
	TextDrawSetProportional(kladionica3, 1);

	kladionica4 = TextDrawCreate(381.777832, 246.399978, "LD_CHAT:goodcha");
	TextDrawLetterSize(kladionica4, 0.000000, 0.000000);
	TextDrawTextSize(kladionica4, 15.999997, 18.915544);
	TextDrawAlignment(kladionica4, 1);
	TextDrawColor(kladionica4, -1);
	TextDrawSetShadow(kladionica4, 0);
	TextDrawSetOutline(kladionica4, 0);
	TextDrawFont(kladionica4, 4);

	kladionica5 = TextDrawCreate(231.555603, 205.084503, "- Uspjesno ste zavrtili~n~kolo srece!");
	TextDrawLetterSize(kladionica5, 0.449999, 1.600000);
	TextDrawAlignment(kladionica5, 1);
	TextDrawColor(kladionica5, -1);
	TextDrawSetShadow(kladionica5, 0);
	TextDrawSetOutline(kladionica5, 1);
	TextDrawBackgroundColor(kladionica5, 51);
	TextDrawFont(kladionica5, 3);
	TextDrawSetProportional(kladionica5, 1);

	kladionica6 = TextDrawCreate(236.444427, 249.884429, "Cestitamo Vam na osvojenoj nagradi!");
	TextDrawLetterSize(kladionica6, 0.210444, 1.201778);
	TextDrawAlignment(kladionica6, 1);
	TextDrawColor(kladionica6, -1);
	TextDrawSetShadow(kladionica6, 0);
	TextDrawSetOutline(kladionica6, 1);
	TextDrawBackgroundColor(kladionica6, 51);
	TextDrawFont(kladionica6, 3);
	TextDrawSetProportional(kladionica6, 1);
	//dm sistem
	dmtext0 = TextDrawCreate(454.888854, 347.455566, "usebox");
	TextDrawLetterSize(dmtext0, 0.000000, 4.827037);
	TextDrawTextSize(dmtext0, 206.444442, 0.000000);
	TextDrawAlignment(dmtext0, 1);
	TextDrawColor(dmtext0, 0);
	TextDrawUseBox(dmtext0, true);
	TextDrawBoxColor(dmtext0, 102);
	TextDrawSetShadow(dmtext0, 0);
	TextDrawSetOutline(dmtext0, 0);
	TextDrawFont(dmtext0, 0);

	dmtext1 = TextDrawCreate(173.333343, 348.444427, NERP_KRUG);
	TextDrawLetterSize(dmtext1, 0.000000, 0.000000);
	TextDrawTextSize(dmtext1, 316.889068, -3.982220);
	TextDrawAlignment(dmtext1, 1);
	TextDrawColor(dmtext1, -1);
	TextDrawSetShadow(dmtext1, 0);
	TextDrawSetOutline(dmtext1, 0);
	TextDrawFont(dmtext1, 4);

	dmtext2 = TextDrawCreate(200.888824, 331.519989, NERP_KRUG);
	TextDrawLetterSize(dmtext2, 0.000000, 0.000000);
	TextDrawTextSize(dmtext2, 29.777824, 29.866674);
	TextDrawAlignment(dmtext2, 1);
	TextDrawColor(dmtext2, -1);
	TextDrawSetShadow(dmtext2, 0);
	TextDrawSetOutline(dmtext2, 0);
	TextDrawFont(dmtext2, 4);

	dmtext3 = TextDrawCreate(212.888854, 336.497711, "i");
	TextDrawLetterSize(dmtext3, 0.528222, 2.057955);
	TextDrawAlignment(dmtext3, 1);
	TextDrawColor(dmtext3, tdboja);
	TextDrawSetShadow(dmtext3, -1);
	TextDrawSetOutline(dmtext3, 0);
	TextDrawBackgroundColor(dmtext3, 51);
	TextDrawFont(dmtext3, 3);
	TextDrawSetProportional(dmtext3, 1);

	dmtext4 = TextDrawCreate(254.222229, 334.008911, "Informacija");
	TextDrawLetterSize(dmtext4, 0.449999, 1.600000);
	TextDrawAlignment(dmtext4, 1);
	TextDrawColor(dmtext4, tdboja);
	TextDrawSetShadow(dmtext4, 0);
	TextDrawSetOutline(dmtext4, 1);
	TextDrawBackgroundColor(dmtext4, 51);
	TextDrawFont(dmtext4, 0);
	TextDrawSetProportional(dmtext4, 1);

	dmtext5 = TextDrawCreate(229.777770, 355.911102, "- Vi ste na DeathMatch zoni, da izadjete kucajte:");
	TextDrawLetterSize(dmtext5, 0.125999, 1.400888);
	TextDrawAlignment(dmtext5, 1);
	TextDrawColor(dmtext5, -1);
	TextDrawSetShadow(dmtext5, 0);
	TextDrawSetOutline(dmtext5, 1);
	TextDrawBackgroundColor(dmtext5, 51);
	TextDrawFont(dmtext5, 2);
	TextDrawSetProportional(dmtext5, 1);

	dmtext6 = TextDrawCreate(348.888885, 378.808898, "/izadjisadm");
	TextDrawLetterSize(dmtext6, 0.348666, 1.122133);
	TextDrawAlignment(dmtext6, 1);
	TextDrawColor(dmtext6, tdboja);
	TextDrawSetShadow(dmtext6, 0);
	TextDrawSetOutline(dmtext6, 1);
	TextDrawBackgroundColor(dmtext6, 51);
	TextDrawFont(dmtext6, 3);
	TextDrawSetProportional(dmtext6, 1);

	dmtext7 = TextDrawCreate(435.556030, 373.831085, "LD_CHAT:thumbup");
	TextDrawLetterSize(dmtext7, -0.032888, -0.114488);
	TextDrawTextSize(dmtext7, 21.333374, 19.911123);
	TextDrawAlignment(dmtext7, 1);
	TextDrawColor(dmtext7, -1);
	TextDrawSetShadow(dmtext7, 0);
	TextDrawSetOutline(dmtext7, 0);
	TextDrawFont(dmtext7, 4);
// death sistem
	Deathtext0 = TextDrawCreate(641.555541, 108.024444, "usebox");
	TextDrawLetterSize(Deathtext0, 0.000000, 28.111976);
	TextDrawTextSize(Deathtext0, -2.000000, 0.000000);
	TextDrawAlignment(Deathtext0, 1);
	TextDrawColor(Deathtext0, 0);
	TextDrawUseBox(Deathtext0, true);
	TextDrawBoxColor(Deathtext0, 102);
	TextDrawSetShadow(Deathtext0, 0);
	TextDrawSetOutline(Deathtext0, 0);
	TextDrawFont(Deathtext0, 0);

	Deathtext1 = TextDrawCreate(135.555572, 143.857788, "WASTED");
	TextDrawLetterSize(Deathtext1, 1.046445, 4.890307);
	TextDrawAlignment(Deathtext1, 1);
	TextDrawColor(Deathtext1, tdboja);
	TextDrawSetShadow(Deathtext1, 0);
	TextDrawSetOutline(Deathtext1, 2);
	TextDrawBackgroundColor(Deathtext1, 51);
	TextDrawFont(Deathtext1, 3);
	TextDrawSetProportional(Deathtext1, 1);

	Deathtext2 = TextDrawCreate(92.888900, 187.164428, NERP_KRUG);
	TextDrawLetterSize(Deathtext2, 0.000000, 0.000000);
	TextDrawTextSize(Deathtext2, 233.333297, -3.982242);
	TextDrawAlignment(Deathtext2, 1);
	TextDrawColor(Deathtext2, -1378294017);
	TextDrawSetShadow(Deathtext2, 0);
	TextDrawSetOutline(Deathtext2, 0);
	TextDrawFont(Deathtext2, 4);

	Deathtext3 = TextDrawCreate(106.666679, 231.466629, "LD_CHAT:badchat");
	TextDrawLetterSize(Deathtext3, 0.000000, 0.000000);
	TextDrawTextSize(Deathtext3, 34.666671, 47.288898);
	TextDrawAlignment(Deathtext3, 1);
	TextDrawColor(Deathtext3, -1);
	TextDrawSetShadow(Deathtext3, 0);
	TextDrawSetOutline(Deathtext3, 0);
	TextDrawFont(Deathtext3, 4);

	Deathtext4 = TextDrawCreate(144.444396, 237.440002, "- Umrli ste!");
	TextDrawLetterSize(Deathtext4, 0.449999, 1.600000);
	TextDrawAlignment(Deathtext4, 1);
	TextDrawColor(Deathtext4, tdboja);
	TextDrawSetShadow(Deathtext4, 0);
	TextDrawSetOutline(Deathtext4, 1);
	TextDrawBackgroundColor(Deathtext4, 51);
	TextDrawFont(Deathtext4, 2);
	TextDrawSetProportional(Deathtext4, 1);

	Deathtext5 = TextDrawCreate(144.444519, 253.866653, "- Uskoro cete biti respawnovani");
	TextDrawLetterSize(Deathtext5, 0.174887, 1.132087);
	TextDrawAlignment(Deathtext5, 1);
	TextDrawColor(Deathtext5, -1);
	TextDrawSetShadow(Deathtext5, 0);
	TextDrawSetOutline(Deathtext5, 1);
	TextDrawBackgroundColor(Deathtext5, 51);
	TextDrawFont(Deathtext5, 2);
	TextDrawSetProportional(Deathtext5, 1);

	Deathtext6 = TextDrawCreate(148.888916, 264.817901, "od strane servera!");
	TextDrawLetterSize(Deathtext6, 0.169109, 1.077332);
	TextDrawAlignment(Deathtext6, 1);
	TextDrawColor(Deathtext6, -1);
	TextDrawSetShadow(Deathtext6, 0);
	TextDrawSetOutline(Deathtext6, 1);
	TextDrawBackgroundColor(Deathtext6, 51);
	TextDrawFont(Deathtext6, 2);
	TextDrawSetProportional(Deathtext6, 1);

	Deathtext7 = TextDrawCreate(229.066680, 317.582153, "Da prijavite DeathMatch ili slicno, kucajte:");
	TextDrawLetterSize(Deathtext7, 0.149998, 1.281422);
	TextDrawAlignment(Deathtext7, 1);
	TextDrawColor(Deathtext7, -1);
	TextDrawSetShadow(Deathtext7, 0);
	TextDrawSetOutline(Deathtext7, 1);
	TextDrawBackgroundColor(Deathtext7, 51);
	TextDrawFont(Deathtext7, 2);
	TextDrawSetProportional(Deathtext7, 1);

	Deathtext8 = TextDrawCreate(283.111114, 337.493347, "/forum");
	TextDrawLetterSize(Deathtext8, 0.449999, 1.600000);
	TextDrawAlignment(Deathtext8, 1);
	TextDrawColor(Deathtext8, tdboja);
	TextDrawSetShadow(Deathtext8, 0);
	TextDrawSetOutline(Deathtext8, 1);
	TextDrawBackgroundColor(Deathtext8, 51);
	TextDrawFont(Deathtext8, 3);
	TextDrawSetProportional(Deathtext8, 1);

	Deathtext9 = TextDrawCreate(-19.555549, 332.017761, NERP_KRUG);
	TextDrawLetterSize(Deathtext9, 0.000000, 0.000000);
	TextDrawTextSize(Deathtext9, 630.222473, 3.484452);
	TextDrawAlignment(Deathtext9, 1);
	TextDrawColor(Deathtext9, -1);
	TextDrawSetShadow(Deathtext9, 0);
	TextDrawSetOutline(Deathtext9, 0);
	TextDrawFont(Deathtext9, 4);

	// UCITAVANJE OBJEKATA

	UO0 = TextDrawCreate(126.444442, 175.224441, "usebox");
	TextDrawLetterSize(UO0, 0.000000, 4.882345);
	TextDrawTextSize(UO0, 15.333333, 0.000000);
	TextDrawAlignment(UO0, 1);
	TextDrawColor(UO0, 0);
	TextDrawUseBox(UO0, true);
	TextDrawBoxColor(UO0, 102);
	TextDrawSetShadow(UO0, 0);
	TextDrawSetOutline(UO0, 0);
	TextDrawFont(UO0, 0);

	UO1 = TextDrawCreate(-15.555563, 220.515594, NERP_KRUG);
	TextDrawLetterSize(UO1, 0.000000, 0.000000);
	TextDrawTextSize(UO1, 159.111145, 1.493334);
	TextDrawAlignment(UO1, 1);
	TextDrawColor(UO1, tdboja);
	TextDrawSetShadow(UO1, 0);
	TextDrawSetOutline(UO1, 0);
	TextDrawFont(UO1, 4);

	UO2 = TextDrawCreate(-0.000044, 174.222274, NERP_KRUG);
	TextDrawLetterSize(UO2, 0.000000, 0.000000);
	TextDrawTextSize(UO2, 151.111053, -1.991120);
	TextDrawAlignment(UO2, 1);
	TextDrawColor(UO2, tdboja);
	TextDrawSetShadow(UO2, 0);
	TextDrawSetOutline(UO2, 0);
	TextDrawFont(UO2, 4);

	UO3 = TextDrawCreate(2.222169, 179.200088, NERP_KRUG);
	TextDrawLetterSize(UO3, 0.000000, 0.000000);
	TextDrawTextSize(UO3, 33.333385, 33.848888);
	TextDrawAlignment(UO3, 1);
	TextDrawColor(UO3, -1378294017);
	TextDrawSetShadow(UO3, 0);
	TextDrawSetOutline(UO3, 0);
	TextDrawFont(UO3, 4);

	UO4 = TextDrawCreate(16.444412, 184.177688, "i");
	TextDrawLetterSize(UO4, 0.589555, 2.346666);
	TextDrawAlignment(UO4, 1);
	TextDrawColor(UO4, tdboja);
	TextDrawSetShadow(UO4, 0);
	TextDrawSetOutline(UO4, 1);
	TextDrawBackgroundColor(UO4, 51);
	TextDrawFont(UO4, 3);
	TextDrawSetProportional(UO4, 1);

	UO5 = TextDrawCreate(31.555532, 176.213363, "Nova Era");
	TextDrawLetterSize(UO5, 0.297111, 1.181867);
	TextDrawAlignment(UO5, 1);
	TextDrawColor(UO5, tdboja);
	TextDrawSetShadow(UO5, 0);
	TextDrawSetOutline(UO5, 1);
	TextDrawBackgroundColor(UO5, 51);
	TextDrawFont(UO5, 0);
	TextDrawSetProportional(UO5, 1);

	UO6 = TextDrawCreate(12.000006, 186.666671, NERP_KRUG);
	TextDrawLetterSize(UO6, 0.000000, 0.000000);
	TextDrawTextSize(UO6, 103.111083, 2.986679);
	TextDrawAlignment(UO6, 1);
	TextDrawColor(UO6, tdboja);
	TextDrawSetShadow(UO6, 0);
	TextDrawSetOutline(UO6, 0);
	TextDrawFont(UO6, 4);

	UO7 = TextDrawCreate(35.555564, 189.653396, "- Ucitavanje");
	TextDrawLetterSize(UO7, 0.221555, 1.037510);
	TextDrawAlignment(UO7, 1);
	TextDrawColor(UO7, -1);
	TextDrawSetShadow(UO7, 0);
	TextDrawSetOutline(UO7, 1);
	TextDrawBackgroundColor(UO7, 51);
	TextDrawFont(UO7, 2);
	TextDrawSetProportional(UO7, 1);

	UO8 = TextDrawCreate(35.111095, 196.124450, "objekata!");
	TextDrawLetterSize(UO8, 0.237999, 1.132088);
	TextDrawAlignment(UO8, 1);
	TextDrawColor(UO8, -1);
	TextDrawSetShadow(UO8, 0);
	TextDrawSetOutline(UO8, 1);
	TextDrawBackgroundColor(UO8, 51);
	TextDrawFont(UO8, 2);
	TextDrawSetProportional(UO8, 1);

	UO9 = TextDrawCreate(40.000007, 212.053359, "");
	TextDrawLetterSize(UO9, 0.449999, 1.600000);
	TextDrawAlignment(UO9, 1);
	TextDrawColor(UO9, -1378294017);
	TextDrawSetShadow(UO9, 0);
	TextDrawSetOutline(UO9, 1);
	TextDrawBackgroundColor(UO9, 51);
	TextDrawFont(UO9, 0);
	TextDrawSetProportional(UO9, 1);

	UO10 = TextDrawCreate(37.599975, 205.333297, "Sacekajte malo...");
	TextDrawLetterSize(UO10, 0.205200, 0.905599);
	TextDrawAlignment(UO10, 1);
	TextDrawColor(UO10, -1);
	TextDrawSetShadow(UO10, 0);
	TextDrawSetOutline(UO10, 1);
	TextDrawBackgroundColor(UO10, 51);
	TextDrawFont(UO10, 1);
	TextDrawSetProportional(UO10, 1);

	UnknownCommand[0] = TextDrawCreate(322.666809, 137.884445, "</>");
	TextDrawLetterSize(UnknownCommand[0], 0.983776, 5.328354);
	TextDrawAlignment(UnknownCommand[0], 2);
	TextDrawColor(UnknownCommand[0], tdboja);
	TextDrawSetShadow(UnknownCommand[0], 0);
	TextDrawSetOutline(UnknownCommand[0], 2);
	TextDrawBackgroundColor(UnknownCommand[0], 51);
	TextDrawFont(UnknownCommand[0], 2);
	TextDrawSetProportional(UnknownCommand[0], 1);

	UnknownCommand[1] = TextDrawCreate(347.555664, 133.404541, "ld_chat:thumbdn");
	TextDrawLetterSize(UnknownCommand[1], 0.000000, 0.000000);
	TextDrawTextSize(UnknownCommand[1], 15.111113, 17.920001);
	TextDrawAlignment(UnknownCommand[1], 1);
	TextDrawColor(UnknownCommand[1], -1);
	TextDrawSetShadow(UnknownCommand[1], 0);
	TextDrawSetOutline(UnknownCommand[1], 0);
	TextDrawFont(UnknownCommand[1], 4);

	UnknownCommand[2] = TextDrawCreate(417.555572, 200.611114, "usebox");
	TextDrawLetterSize(UnknownCommand[2], 0.000000, 2.669998);
	TextDrawTextSize(UnknownCommand[2], 224.666656, 0.000000);
	TextDrawAlignment(UnknownCommand[2], 1);
	TextDrawColor(UnknownCommand[2], 0);
	TextDrawUseBox(UnknownCommand[2], true);
	TextDrawBoxColor(UnknownCommand[2], 102);
	TextDrawSetShadow(UnknownCommand[2], 0);
	TextDrawSetOutline(UnknownCommand[2], 0);
	TextDrawFont(UnknownCommand[2], 0);

	UnknownCommand[3] = TextDrawCreate(173.333358, 198.613296, NERP_KRUG);
	TextDrawLetterSize(UnknownCommand[3], 0.000000, 0.000000);
	TextDrawTextSize(UnknownCommand[3], 296.444549, 1.493340);
	TextDrawAlignment(UnknownCommand[3], 1);
	TextDrawColor(UnknownCommand[3], tdboja);
	TextDrawSetShadow(UnknownCommand[3], 0);
	TextDrawSetOutline(UnknownCommand[3], 0);
	TextDrawFont(UnknownCommand[3], 4);

	UnknownCommand[4] = TextDrawCreate(197.333389, 225.991180, NERP_KRUG);
	TextDrawLetterSize(UnknownCommand[4], 0.000000, 0.000000);
	TextDrawTextSize(UnknownCommand[4], 250.666519, 0.995553);
	TextDrawAlignment(UnknownCommand[4], 1);
	TextDrawColor(UnknownCommand[4], tdboja);
	TextDrawSetShadow(UnknownCommand[4], 0);
	TextDrawSetOutline(UnknownCommand[4], 0);
	TextDrawFont(UnknownCommand[4], 4);

	UnknownCommand[5] = TextDrawCreate(321.777801, 204.088912, "Komanda koju ste unijeli, ili parametri~n~koje ste upotrijebili su nevazeci!~n~Pokusajte ponovo...");
	TextDrawLetterSize(UnknownCommand[5], 0.136666, 0.659200);
	TextDrawAlignment(UnknownCommand[5], 2);
	TextDrawColor(UnknownCommand[5], -1);
	TextDrawSetShadow(UnknownCommand[5], 0);
	TextDrawSetOutline(UnknownCommand[5], 1);
	TextDrawBackgroundColor(UnknownCommand[5], 51);
	TextDrawFont(UnknownCommand[5], 2);
	TextDrawSetProportional(UnknownCommand[5], 1);

	//logo

	new Float:MobileNERPLogoOffset = -15.0;

	MobileNERPLogo[0] = TextDrawCreate(600.888732 + MobileNERPLogoOffset, 0.995549, NERP_KRUG);
	TextDrawLetterSize(MobileNERPLogo[0], 0.000000, 0.000000);
	TextDrawTextSize(MobileNERPLogo[0], 37.333335, 40.319972);
	TextDrawAlignment(MobileNERPLogo[0], 1);
	TextDrawColor(MobileNERPLogo[0], tdboja);
	TextDrawSetShadow(MobileNERPLogo[0], 0);
	TextDrawSetOutline(MobileNERPLogo[0], 0);
	TextDrawFont(MobileNERPLogo[0], 4);

	MobileNERPLogo[1] = TextDrawCreate(604.889160 + MobileNERPLogoOffset, 5.973307, NERP_KRUG);
	TextDrawLetterSize(MobileNERPLogo[1], 0.000000, 0.000000);
	TextDrawTextSize(MobileNERPLogo[1], 29.333341, 31.360019);
	TextDrawAlignment(MobileNERPLogo[1], 1);
	TextDrawColor(MobileNERPLogo[1], tdboja);
	TextDrawSetShadow(MobileNERPLogo[1], 0);
	TextDrawSetOutline(MobileNERPLogo[1], 0);
	TextDrawFont(MobileNERPLogo[1], 4);

	MobileNERPLogo[2] = TextDrawCreate(612.444152 + MobileNERPLogoOffset, 9.955560, "N");
	TextDrawLetterSize(MobileNERPLogo[2], 0.539777, 2.271999);
	TextDrawAlignment(MobileNERPLogo[2], 1);
	TextDrawColor(MobileNERPLogo[2], -1);
	TextDrawSetShadow(MobileNERPLogo[2], 0);
	TextDrawSetOutline(MobileNERPLogo[2], 1);
	TextDrawBackgroundColor(MobileNERPLogo[2], 51);
	TextDrawFont(MobileNERPLogo[2], 2);
	TextDrawSetProportional(MobileNERPLogo[2], 1);

	MobileNERPLogo[3] = TextDrawCreate(541.778259 + MobileNERPLogoOffset, 8.462200, "LD_SPAC:white");
	TextDrawLetterSize(MobileNERPLogo[3], 0.000000, 0.000000);
	TextDrawTextSize(MobileNERPLogo[3], 77.777770, 1.991104);
	TextDrawAlignment(MobileNERPLogo[3], 1);
	TextDrawColor(MobileNERPLogo[3], tdboja);
	TextDrawSetShadow(MobileNERPLogo[3], 0);
	TextDrawSetOutline(MobileNERPLogo[3], 0);
	TextDrawFont(MobileNERPLogo[3], 4);

	MobileNERPLogo[4] = TextDrawCreate(542.667114 + MobileNERPLogoOffset, 9.955591, "]]]]]]]]]]]]");
	TextDrawLetterSize(MobileNERPLogo[4], 0.161111, 0.758755);
	TextDrawAlignment(MobileNERPLogo[4], 1);
	TextDrawColor(MobileNERPLogo[4], -1);
	TextDrawSetShadow(MobileNERPLogo[4], 0);
	TextDrawSetOutline(MobileNERPLogo[4], 1);
	TextDrawBackgroundColor(MobileNERPLogo[4], 51);
	TextDrawFont(MobileNERPLogo[4], 2);
	TextDrawSetProportional(MobileNERPLogo[4], 1);

	MobileNERPLogo[5] = TextDrawCreate(547.555480 + MobileNERPLogoOffset, 13.937742, "Nova Era");
	TextDrawLetterSize(MobileNERPLogo[5], 0.359777, 1.774222);
	TextDrawAlignment(MobileNERPLogo[5], 1);
	TextDrawColor(MobileNERPLogo[5], tdboja);
	TextDrawSetShadow(MobileNERPLogo[5], 0);
	TextDrawSetOutline(MobileNERPLogo[5], 1);
	TextDrawBackgroundColor(MobileNERPLogo[5], 51);
	TextDrawFont(MobileNERPLogo[5], 3);//0);
	TextDrawSetProportional(MobileNERPLogo[5], 1);

	MobileNERPLogo[6] = TextDrawCreate(547.555603 + MobileNERPLogoOffset, 29.368885, "Online Gaming Community");
	TextDrawLetterSize(MobileNERPLogo[6], 0.106888, 0.654222);
	TextDrawAlignment(MobileNERPLogo[6], 1);
	TextDrawColor(MobileNERPLogo[6], -1);
	TextDrawSetShadow(MobileNERPLogo[6], 0);
	TextDrawSetOutline(MobileNERPLogo[6], 1);
	TextDrawBackgroundColor(MobileNERPLogo[6], 51);
	TextDrawFont(MobileNERPLogo[6], 2);
	TextDrawSetProportional(MobileNERPLogo[6], 1);

	MobileNERPLogo[7] = TextDrawCreate(534.222412 + MobileNERPLogoOffset, 2.986679, "]");
	TextDrawLetterSize(MobileNERPLogo[7], 0.323777, 1.181867);
	TextDrawAlignment(MobileNERPLogo[7], 1);
	TextDrawColor(MobileNERPLogo[7], tdboja);
	TextDrawSetShadow(MobileNERPLogo[7], 0);
	TextDrawSetOutline(MobileNERPLogo[7], 1);
	TextDrawBackgroundColor(MobileNERPLogo[7], 51);
	TextDrawFont(MobileNERPLogo[7], 0);
	TextDrawSetProportional(MobileNERPLogo[7], 1);

	PCNERPLogo[0] = TextDrawCreate(600.888732, 0.995549, NERP_KRUG);
	TextDrawLetterSize(PCNERPLogo[0], 0.000000, 0.000000);
	TextDrawTextSize(PCNERPLogo[0], 37.333335, 40.319972);
	TextDrawAlignment(PCNERPLogo[0], 1);
	TextDrawColor(PCNERPLogo[0], tdboja);
	TextDrawSetShadow(PCNERPLogo[0], 0);
	TextDrawSetOutline(PCNERPLogo[0], 0);
	TextDrawFont(PCNERPLogo[0], 4);

	PCNERPLogo[1] = TextDrawCreate(604.889160, 5.973307, NERP_KRUG);
	TextDrawLetterSize(PCNERPLogo[1], 0.000000, 0.000000);
	TextDrawTextSize(PCNERPLogo[1], 29.333341, 31.360019);
	TextDrawAlignment(PCNERPLogo[1], 1);
	TextDrawColor(PCNERPLogo[1], tdboja);
	TextDrawSetShadow(PCNERPLogo[1], 0);
	TextDrawSetOutline(PCNERPLogo[1], 0);
	TextDrawFont(PCNERPLogo[1], 4);

	PCNERPLogo[2] = TextDrawCreate(612.444152, 9.955560, "N");
	TextDrawLetterSize(PCNERPLogo[2], 0.539777, 2.271999);
	TextDrawAlignment(PCNERPLogo[2], 1);
	TextDrawColor(PCNERPLogo[2], -1);
	TextDrawSetShadow(PCNERPLogo[2], 0);
	TextDrawSetOutline(PCNERPLogo[2], 1);
	TextDrawBackgroundColor(PCNERPLogo[2], 51);
	TextDrawFont(PCNERPLogo[2], 2);
	TextDrawSetProportional(PCNERPLogo[2], 1);

	PCNERPLogo[3] = TextDrawCreate(541.778259, 8.462200, "LD_SPAC:white");
	TextDrawLetterSize(PCNERPLogo[3], 0.000000, 0.000000);
	TextDrawTextSize(PCNERPLogo[3], 77.777770, 1.991104);
	TextDrawAlignment(PCNERPLogo[3], 1);
	TextDrawColor(PCNERPLogo[3], tdboja);
	TextDrawSetShadow(PCNERPLogo[3], 0);
	TextDrawSetOutline(PCNERPLogo[3], 0);
	TextDrawFont(PCNERPLogo[3], 4);

	PCNERPLogo[4] = TextDrawCreate(542.667114, 9.955591, "]]]]]]]]]]]]");
	TextDrawLetterSize(PCNERPLogo[4], 0.161111, 0.758755);
	TextDrawAlignment(PCNERPLogo[4], 1);
	TextDrawColor(PCNERPLogo[4], -1);
	TextDrawSetShadow(PCNERPLogo[4], 0);
	TextDrawSetOutline(PCNERPLogo[4], 1);
	TextDrawBackgroundColor(PCNERPLogo[4], 51);
	TextDrawFont(PCNERPLogo[4], 2);
	TextDrawSetProportional(PCNERPLogo[4], 1);

	PCNERPLogo[5] = TextDrawCreate(547.555480, 13.937742, "Nova Era");
	TextDrawLetterSize(PCNERPLogo[5], 0.359777, 1.774222);
	TextDrawAlignment(PCNERPLogo[5], 1);
	TextDrawColor(PCNERPLogo[5], tdboja);
	TextDrawSetShadow(PCNERPLogo[5], 0);
	TextDrawSetOutline(PCNERPLogo[5], 1);
	TextDrawBackgroundColor(PCNERPLogo[5], 51);
	TextDrawFont(PCNERPLogo[5], 3);//0);
	TextDrawSetProportional(PCNERPLogo[5], 1);

	PCNERPLogo[6] = TextDrawCreate(547.555603, 29.368885, "Online Gaming Community");
	TextDrawLetterSize(PCNERPLogo[6], 0.106888, 0.654222);
	TextDrawAlignment(PCNERPLogo[6], 1);
	TextDrawColor(PCNERPLogo[6], -1);
	TextDrawSetShadow(PCNERPLogo[6], 0);
	TextDrawSetOutline(PCNERPLogo[6], 1);
	TextDrawBackgroundColor(PCNERPLogo[6], 51);
	TextDrawFont(PCNERPLogo[6], 2);
	TextDrawSetProportional(PCNERPLogo[6], 1);

	PCNERPLogo[7] = TextDrawCreate(534.222412, 2.986679, "]");
	TextDrawLetterSize(PCNERPLogo[7], 0.323777, 1.181867);
	TextDrawAlignment(PCNERPLogo[7], 1);
	TextDrawColor(PCNERPLogo[7], tdboja);
	TextDrawSetShadow(PCNERPLogo[7], 0);
	TextDrawSetOutline(PCNERPLogo[7], 1);
	TextDrawBackgroundColor(PCNERPLogo[7], 51);
	TextDrawFont(PCNERPLogo[7], 0);
	TextDrawSetProportional(PCNERPLogo[7], 1);

	/// =================================[ Nova Era IN GAME TD ]=====================================================
	
	/*TDEditor_TD[0] = TextDrawCreate(600.888732, 0.995549, NERP_KRUG);
	TextDrawLetterSize(TDEditor_TD[0], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[0], 37.333335, 40.319972);
	TextDrawAlignment(TDEditor_TD[0], 1);
	TextDrawColor(TDEditor_TD[0], tdboja);
	TextDrawSetShadow(TDEditor_TD[0], 0);
	TextDrawSetOutline(TDEditor_TD[0], 0);
	TextDrawFont(TDEditor_TD[0], 4);

	TDEditor_TD[1] = TextDrawCreate(604.889160, 5.973307, NERP_KRUG);
	TextDrawLetterSize(TDEditor_TD[1], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[1], 29.333341, 31.360019);
	TextDrawAlignment(TDEditor_TD[1], 1);
	TextDrawColor(TDEditor_TD[1], tdboja);
	TextDrawSetShadow(TDEditor_TD[1], 0);
	TextDrawSetOutline(TDEditor_TD[1], 0);
	TextDrawFont(TDEditor_TD[1], 4);

	TDEditor_TD[2] = TextDrawCreate(612.444152, 9.955560, "N");
	TextDrawLetterSize(TDEditor_TD[2], 0.539777, 2.271999);
	TextDrawAlignment(TDEditor_TD[2], 1);
	TextDrawColor(TDEditor_TD[2], -1);
	TextDrawSetShadow(TDEditor_TD[2], 0);
	TextDrawSetOutline(TDEditor_TD[2], 1);
	TextDrawBackgroundColor(TDEditor_TD[2], 51);
	TextDrawFont(TDEditor_TD[2], 2);
	TextDrawSetProportional(TDEditor_TD[2], 1);

	TDEditor_TD[3] = TextDrawCreate(541.778259, 8.462200, "LD_SPAC:white");
	TextDrawLetterSize(TDEditor_TD[3], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[3], 77.777770, 1.991104);
	TextDrawAlignment(TDEditor_TD[3], 1);
	TextDrawColor(TDEditor_TD[3], tdboja);
	TextDrawSetShadow(TDEditor_TD[3], 0);
	TextDrawSetOutline(TDEditor_TD[3], 0);
	TextDrawFont(TDEditor_TD[3], 4);

	TDEditor_TD[4] = TextDrawCreate(542.667114, 9.955591, "]]]]]]]]]]]]");
	TextDrawLetterSize(TDEditor_TD[4], 0.161111, 0.758755);
	TextDrawAlignment(TDEditor_TD[4], 1);
	TextDrawColor(TDEditor_TD[4], -1);
	TextDrawSetShadow(TDEditor_TD[4], 0);
	TextDrawSetOutline(TDEditor_TD[4], 1);
	TextDrawBackgroundColor(TDEditor_TD[4], 51);
	TextDrawFont(TDEditor_TD[4], 2);
	TextDrawSetProportional(TDEditor_TD[4], 1);

	TDEditor_TD[5] = TextDrawCreate(547.555480, 13.937742, "Nova Era");
	TextDrawLetterSize(TDEditor_TD[5], 0.359777, 1.774222);
	TextDrawAlignment(TDEditor_TD[5], 1);
	TextDrawColor(TDEditor_TD[5], tdboja);
	TextDrawSetShadow(TDEditor_TD[5], 0);
	TextDrawSetOutline(TDEditor_TD[5], 1);
	TextDrawBackgroundColor(TDEditor_TD[5], 51);
	TextDrawFont(TDEditor_TD[5], 3);//0);
	TextDrawSetProportional(TDEditor_TD[5], 1);

	TDEditor_TD[6] = TextDrawCreate(547.555603, 29.368885, "Online Gaming Community");
	TextDrawLetterSize(TDEditor_TD[6], 0.106888, 0.654222);
	TextDrawAlignment(TDEditor_TD[6], 1);
	TextDrawColor(TDEditor_TD[6], -1);
	TextDrawSetShadow(TDEditor_TD[6], 0);
	TextDrawSetOutline(TDEditor_TD[6], 1);
	TextDrawBackgroundColor(TDEditor_TD[6], 51);
	TextDrawFont(TDEditor_TD[6], 2);
	TextDrawSetProportional(TDEditor_TD[6], 1);

	TDEditor_TD[7] = TextDrawCreate(534.222412, 2.986679, "]");
	TextDrawLetterSize(TDEditor_TD[7], 0.323777, 1.181867);
	TextDrawAlignment(TDEditor_TD[7], 1);
	TextDrawColor(TDEditor_TD[7], tdboja);
	TextDrawSetShadow(TDEditor_TD[7], 0);
	TextDrawSetOutline(TDEditor_TD[7], 1);
	TextDrawBackgroundColor(TDEditor_TD[7], 51);
	TextDrawFont(TDEditor_TD[7], 0);
	TextDrawSetProportional(TDEditor_TD[7], 1);*/

	TDEditor_TD[16] = TextDrawCreate(-7.444465, 433.469177, "LD_SPAC:white");//sumnjvo
	TextDrawLetterSize(TDEditor_TD[16], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[16], 649.000000, 12.000000);
	TextDrawAlignment(TDEditor_TD[16], 1);
	TextDrawColor(TDEditor_TD[16], 102);
	TextDrawSetShadow(TDEditor_TD[16], 0);
	TextDrawSetOutline(TDEditor_TD[16], 0);
	TextDrawBackgroundColor(TDEditor_TD[16], 102);
	TextDrawFont(TDEditor_TD[16], 4);
	TextDrawSetProportional(TDEditor_TD[16], 0);
	TextDrawSetShadow(TDEditor_TD[16], 0);

	TDEditor_TD[17] = TextDrawCreate(1.044381, 433.871185, "particle:lamp_shad_64");//sumnjivo
	TextDrawLetterSize(TDEditor_TD[17], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[17], 657.000000, 11.000000);
	TextDrawAlignment(TDEditor_TD[17], 1);
	TextDrawColor(TDEditor_TD[17], 102);
	TextDrawSetShadow(TDEditor_TD[17], 0);
	TextDrawSetOutline(TDEditor_TD[17], 0);
	TextDrawBackgroundColor(TDEditor_TD[17], 255);
	TextDrawFont(TDEditor_TD[17], 4);
	TextDrawSetProportional(TDEditor_TD[17], 0);
	TextDrawSetShadow(TDEditor_TD[17], 0);

	TDEditor_TD[18] = TextDrawCreate(281.777740, 421.119995, "www.             .com");
	TextDrawLetterSize(TDEditor_TD[18], 0.184666, 0.708977);
	TextDrawAlignment(TDEditor_TD[18], 1);
	TextDrawColor(TDEditor_TD[18], -1);
	TextDrawSetShadow(TDEditor_TD[18], 0);
	TextDrawSetOutline(TDEditor_TD[18], 1);
	TextDrawBackgroundColor(TDEditor_TD[18], 51);
	TextDrawFont(TDEditor_TD[18], 2);
	TextDrawSetProportional(TDEditor_TD[18], 1);


	TDEditor_TD[19] = TextDrawCreate(301.333648, 417.137756, "Nova Era");
	TextDrawLetterSize(TDEditor_TD[19], 0.244666, 1.067377);
	TextDrawAlignment(TDEditor_TD[19], 1);
	TextDrawColor(TDEditor_TD[19], tdboja);
	TextDrawSetShadow(TDEditor_TD[19], 0);
	TextDrawSetOutline(TDEditor_TD[19], 1);
	TextDrawBackgroundColor(TDEditor_TD[19], 51);
	TextDrawFont(TDEditor_TD[19], 0);
	TextDrawSetProportional(TDEditor_TD[19], 1);

	TDEditor_TD[22] = TextDrawCreate(-4.888874, 447.502166, "LD_SPAC:white");
	TextDrawLetterSize(TDEditor_TD[22], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[22], 692.000061, -1.493343);
	TextDrawAlignment(TDEditor_TD[22], 1);
	TextDrawColor(TDEditor_TD[22], tdboja);
	TextDrawSetShadow(TDEditor_TD[22], 0);
	TextDrawSetOutline(TDEditor_TD[22], 0);
	TextDrawFont(TDEditor_TD[22], 4);

	TDEditor_TD[23] = TextDrawCreate(2.822221, 437.540039, "LD_SPAC:white");
	TextDrawLetterSize(TDEditor_TD[23], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[23], 15.889996, 5.000000);
	TextDrawAlignment(TDEditor_TD[23], 1);
	TextDrawColor(TDEditor_TD[23], tdboja);
	TextDrawSetShadow(TDEditor_TD[23], 0);
	TextDrawSetOutline(TDEditor_TD[23], 0);
	TextDrawBackgroundColor(TDEditor_TD[23], 255);
	TextDrawFont(TDEditor_TD[23], 4);
	TextDrawSetProportional(TDEditor_TD[23], 0);
	TextDrawSetShadow(TDEditor_TD[23], 0);

	TDEditor_TD[24] = TextDrawCreate(17.066658, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[24], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[24], 1);
	TextDrawColor(TDEditor_TD[24], tdboja);
	TextDrawSetShadow(TDEditor_TD[24], 0);
	TextDrawSetOutline(TDEditor_TD[24], 0);
	TextDrawBackgroundColor(TDEditor_TD[24], 255);
	TextDrawFont(TDEditor_TD[24], 1);
	TextDrawSetProportional(TDEditor_TD[24], 1);
	TextDrawSetShadow(TDEditor_TD[24], 0);

	TDEditor_TD[25] = TextDrawCreate(17.066658, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[25], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[25], 1);
	TextDrawColor(TDEditor_TD[25], tdboja);
	TextDrawSetShadow(TDEditor_TD[25], 0);
	TextDrawSetOutline(TDEditor_TD[25], 0);
	TextDrawBackgroundColor(TDEditor_TD[25], 255);
	TextDrawFont(TDEditor_TD[25], 1);
	TextDrawSetProportional(TDEditor_TD[25], 1);
	TextDrawSetShadow(TDEditor_TD[25], 0);

	TDEditor_TD[26] = TextDrawCreate(15.866653, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[26], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[26], 1);
	TextDrawColor(TDEditor_TD[26], tdboja);
	TextDrawSetShadow(TDEditor_TD[26], 0);
	TextDrawSetOutline(TDEditor_TD[26], 0);
	TextDrawBackgroundColor(TDEditor_TD[26], 255);
	TextDrawFont(TDEditor_TD[26], 1);
	TextDrawSetProportional(TDEditor_TD[26], 1);
	TextDrawSetShadow(TDEditor_TD[26], 0);

	TDEditor_TD[27] = TextDrawCreate(15.866653, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[27], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[27], 1);
	TextDrawColor(TDEditor_TD[27], tdboja);
	TextDrawSetShadow(TDEditor_TD[27], 0);
	TextDrawSetOutline(TDEditor_TD[27], 0);
	TextDrawBackgroundColor(TDEditor_TD[27], 255);
	TextDrawFont(TDEditor_TD[27], 1);
	TextDrawSetProportional(TDEditor_TD[27], 1);
	TextDrawSetShadow(TDEditor_TD[27], 0);

	TDEditor_TD[28] = TextDrawCreate(0.211096, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[28], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[28], 1);
	TextDrawColor(TDEditor_TD[28], tdboja);
	TextDrawSetShadow(TDEditor_TD[28], 0);
	TextDrawSetOutline(TDEditor_TD[28], 0);
	TextDrawBackgroundColor(TDEditor_TD[28], 255);
	TextDrawFont(TDEditor_TD[28], 1);
	TextDrawSetProportional(TDEditor_TD[28], 1);
	TextDrawSetShadow(TDEditor_TD[28], 0);

	TDEditor_TD[29] = TextDrawCreate(0.211096, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[29], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[29], 1);
	TextDrawColor(TDEditor_TD[29], tdboja);
	TextDrawSetShadow(TDEditor_TD[29], 0);
	TextDrawSetOutline(TDEditor_TD[29], 0);
	TextDrawBackgroundColor(TDEditor_TD[29], 255);
	TextDrawFont(TDEditor_TD[29], 1);
	TextDrawSetProportional(TDEditor_TD[29], 1);
	TextDrawSetShadow(TDEditor_TD[29], 0);

	TDEditor_TD[30] = TextDrawCreate(1.311097, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[30], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[30], 1);
	TextDrawColor(TDEditor_TD[30], tdboja);
	TextDrawSetShadow(TDEditor_TD[30], 0);
	TextDrawSetOutline(TDEditor_TD[30], 0);
	TextDrawBackgroundColor(TDEditor_TD[30], 255);
	TextDrawFont(TDEditor_TD[30], 1);
	TextDrawSetProportional(TDEditor_TD[30], 1);
	TextDrawSetShadow(TDEditor_TD[30], 0);

	TDEditor_TD[31] = TextDrawCreate(1.311097, 435.902374, "/");
	TextDrawLetterSize(TDEditor_TD[31], 0.323110, 0.753777);
	TextDrawAlignment(TDEditor_TD[31], 1);
	TextDrawColor(TDEditor_TD[31], tdboja);
	TextDrawSetShadow(TDEditor_TD[31], 0);
	TextDrawSetOutline(TDEditor_TD[31], 0);
	TextDrawBackgroundColor(TDEditor_TD[31], 255);
	TextDrawFont(TDEditor_TD[31], 1);
	TextDrawSetProportional(TDEditor_TD[31], 1);
	TextDrawSetShadow(TDEditor_TD[31], 0);

	TDEditor_TD[32] = TextDrawCreate(11.033321, 436.897827, "Nova Era");
	TextDrawLetterSize(TDEditor_TD[32], 0.136776, 0.529865);
	TextDrawAlignment(TDEditor_TD[32], 2);
	TextDrawColor(TDEditor_TD[32], -1);
	TextDrawSetShadow(TDEditor_TD[32], 0);
	TextDrawSetOutline(TDEditor_TD[32], 0);
	TextDrawBackgroundColor(TDEditor_TD[32], 255);
	TextDrawFont(TDEditor_TD[32], 3);
	TextDrawSetProportional(TDEditor_TD[32], 1);
	TextDrawSetShadow(TDEditor_TD[32], 0);

	TDEditor_TD[33] = TextDrawCreate(10.833319, 440.798065, "RolePlay");
	TextDrawLetterSize(TDEditor_TD[33], 0.076333, 0.325778);
	TextDrawAlignment(TDEditor_TD[33], 2);
	TextDrawColor(TDEditor_TD[33], -1);
	TextDrawSetShadow(TDEditor_TD[33], 0);
	TextDrawSetOutline(TDEditor_TD[33], 0);
	TextDrawBackgroundColor(TDEditor_TD[33], 255);
	TextDrawFont(TDEditor_TD[33], 1);
	TextDrawSetProportional(TDEditor_TD[33], 1);
	TextDrawSetShadow(TDEditor_TD[33], 0);

	TDEditor_TD[34] = TextDrawCreate(32.333225, 433.813537, "/");
	TextDrawLetterSize(TDEditor_TD[34], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[34], 1);
	TextDrawColor(TDEditor_TD[34], tdboja);
	TextDrawSetShadow(TDEditor_TD[34], 0);
	TextDrawSetOutline(TDEditor_TD[34], 0);
	TextDrawBackgroundColor(TDEditor_TD[34], 255);
	TextDrawFont(TDEditor_TD[34], 0);
	TextDrawSetProportional(TDEditor_TD[34], 1);
	TextDrawSetShadow(TDEditor_TD[34], 0);

	TDEditor_TD[35] = TextDrawCreate(56.222190, 435.904479, "15:25:35");
	TextDrawLetterSize(TDEditor_TD[35], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[35], 2);
	TextDrawColor(TDEditor_TD[35], -1);
	TextDrawSetShadow(TDEditor_TD[35], 0);
	TextDrawSetOutline(TDEditor_TD[35], 0);
	TextDrawBackgroundColor(TDEditor_TD[35], 255);
	TextDrawFont(TDEditor_TD[35], 2);
	TextDrawSetProportional(TDEditor_TD[35], 1);
	TextDrawSetShadow(TDEditor_TD[35], 0);

	TDEditor_TD[36] = TextDrawCreate(86.921722, 435.904479, "24/03/2020");
	TextDrawLetterSize(TDEditor_TD[36], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[36], 2);
	TextDrawColor(TDEditor_TD[36], -1);
	TextDrawSetShadow(TDEditor_TD[36], 0);
	TextDrawSetOutline(TDEditor_TD[36], 0);
	TextDrawBackgroundColor(TDEditor_TD[36], 255);
	TextDrawFont(TDEditor_TD[36], 2);
	TextDrawSetProportional(TDEditor_TD[36], 1);
	TextDrawSetShadow(TDEditor_TD[36], 0);

	TDEditor_TD[37] = TextDrawCreate(107.377433, 433.813537, "/");
	TextDrawLetterSize(TDEditor_TD[37], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[37], 1);
	TextDrawColor(TDEditor_TD[37], tdboja);
	TextDrawSetShadow(TDEditor_TD[37], 0);
	TextDrawSetOutline(TDEditor_TD[37], 0);
	TextDrawBackgroundColor(TDEditor_TD[37], 255);
	TextDrawFont(TDEditor_TD[37], 0);
	TextDrawSetProportional(TDEditor_TD[37], 1);
	TextDrawSetShadow(TDEditor_TD[37], 0);

	TDEditor_TD[38] = TextDrawCreate(119.521224, 435.904479, "Uzivajte!");
	TextDrawLetterSize(TDEditor_TD[38], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[38], 1);
	TextDrawColor(TDEditor_TD[38], -1);
	TextDrawSetShadow(TDEditor_TD[38], 0);
	TextDrawSetOutline(TDEditor_TD[38], 0);
	TextDrawBackgroundColor(TDEditor_TD[38], 255);
	TextDrawFont(TDEditor_TD[38], 2);
	TextDrawSetProportional(TDEditor_TD[38], 1);
	TextDrawSetShadow(TDEditor_TD[38], 0);

	TDEditor_TD[39] = TextDrawCreate(177.599441, 435.904479, "REKORD:_40");
	TextDrawLetterSize(TDEditor_TD[39], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[39], 3);
	TextDrawColor(TDEditor_TD[39], -1);
	TextDrawSetShadow(TDEditor_TD[39], 0);
	TextDrawSetOutline(TDEditor_TD[39], 0);
	TextDrawBackgroundColor(TDEditor_TD[39], 255);
	TextDrawFont(TDEditor_TD[39], 2);
	TextDrawSetProportional(TDEditor_TD[39], 1);
	TextDrawSetShadow(TDEditor_TD[39], 0);

	TDEditor_TD[40] = TextDrawCreate(197.167312, 435.846649, "LD_SPAC:white");//sumnjivo
	TextDrawLetterSize(TDEditor_TD[40], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[40], 238.000000, 7.710015);
	TextDrawAlignment(TDEditor_TD[40], 1);
	TextDrawColor(TDEditor_TD[40], 336860415);
	TextDrawSetShadow(TDEditor_TD[40], 0);
	TextDrawSetOutline(TDEditor_TD[40], 0);
	TextDrawBackgroundColor(TDEditor_TD[40], 255);
	TextDrawFont(TDEditor_TD[40], 4);
	TextDrawSetProportional(TDEditor_TD[40], 0);
	TextDrawSetShadow(TDEditor_TD[40], 0);

	TDEditor_TD[41] = TextDrawCreate(183.266464, 433.915802, "/");
	TextDrawLetterSize(TDEditor_TD[41], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[41], 1);
	TextDrawColor(TDEditor_TD[41], tdboja);
	TextDrawSetShadow(TDEditor_TD[41], 0);
	TextDrawSetOutline(TDEditor_TD[41], 0);
	TextDrawBackgroundColor(TDEditor_TD[41], 255);
	TextDrawFont(TDEditor_TD[41], 0);
	TextDrawSetProportional(TDEditor_TD[41], 1);
	TextDrawSetShadow(TDEditor_TD[41], 0);

	TDEditor_TD[42] = TextDrawCreate(198.944580, 436.346710, "LD_CHAT:thumbup");
	TextDrawLetterSize(TDEditor_TD[42], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[42], 6.000000, 7.000000);
	TextDrawAlignment(TDEditor_TD[42], 1);
	TextDrawColor(TDEditor_TD[42], -1);
	TextDrawSetShadow(TDEditor_TD[42], 0);
	TextDrawSetOutline(TDEditor_TD[42], 0);
	TextDrawBackgroundColor(TDEditor_TD[42], 255);
	TextDrawFont(TDEditor_TD[42], 4);
	TextDrawSetProportional(TDEditor_TD[42], 0);
	TextDrawSetShadow(TDEditor_TD[42], 0);

	TDEditor_TD[43] = TextDrawCreate(312.312011, 436.995574, "SVE_NEPOZNATE_KOMANDE_MOZETE_PRONACI_NA_/KOMANDE");
	TextDrawLetterSize(TDEditor_TD[43], 0.086443, 0.584222);
	TextDrawAlignment(TDEditor_TD[43], 2);
	TextDrawColor(TDEditor_TD[43], -1);
	TextDrawSetShadow(TDEditor_TD[43], 0);
	TextDrawSetOutline(TDEditor_TD[43], 0);
	TextDrawBackgroundColor(TDEditor_TD[43], 255);
	TextDrawFont(TDEditor_TD[43], 2);
	TextDrawSetProportional(TDEditor_TD[43], 1);
	TextDrawSetShadow(TDEditor_TD[43], 0);

	TDEditor_TD[44] = TextDrawCreate(444.477966, 433.713470, "/");
	TextDrawLetterSize(TDEditor_TD[44], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[44], 1);
	TextDrawColor(TDEditor_TD[44], tdboja);
	TextDrawSetShadow(TDEditor_TD[44], 0);
	TextDrawSetOutline(TDEditor_TD[44], 0);
	TextDrawBackgroundColor(TDEditor_TD[44], 255);
	TextDrawFont(TDEditor_TD[44], 0);
	TextDrawSetProportional(TDEditor_TD[44], 1);
	TextDrawSetShadow(TDEditor_TD[44], 0);

	TDEditor_TD[45] = TextDrawCreate(481.821563, 435.904479, "DAILY_TIPS");
	TextDrawLetterSize(TDEditor_TD[45], 0.089443, 0.654222);
	TextDrawAlignment(TDEditor_TD[45], 2);
	TextDrawColor(TDEditor_TD[45], -1);
	TextDrawSetShadow(TDEditor_TD[45], 0);
	TextDrawSetOutline(TDEditor_TD[45], 0);
	TextDrawBackgroundColor(TDEditor_TD[45], 255);
	TextDrawFont(TDEditor_TD[45], 2);
	TextDrawSetProportional(TDEditor_TD[45], 1);
	TextDrawSetShadow(TDEditor_TD[45], 0);

	TDEditor_TD[46] = TextDrawCreate(512.544616, 433.711212, "/");
	TextDrawLetterSize(TDEditor_TD[46], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[46], 1);
	TextDrawColor(TDEditor_TD[46], tdboja);
	TextDrawSetShadow(TDEditor_TD[46], 0);
	TextDrawSetOutline(TDEditor_TD[46], 0);
	TextDrawBackgroundColor(TDEditor_TD[46], 255);
	TextDrawFont(TDEditor_TD[46], 0);
	TextDrawSetProportional(TDEditor_TD[46], 1);
	TextDrawSetShadow(TDEditor_TD[46], 0);

	TDEditor_TD[47] = TextDrawCreate(539.150817, 433.606658, "Dobrodosli!");
	TextDrawLetterSize(TDEditor_TD[47], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[47], 2);
	TextDrawColor(TDEditor_TD[47], -1);
	TextDrawSetShadow(TDEditor_TD[47], 0);
	TextDrawSetOutline(TDEditor_TD[47], 0);
	TextDrawBackgroundColor(TDEditor_TD[47], 255);
	TextDrawFont(TDEditor_TD[47], 2);
	TextDrawSetProportional(TDEditor_TD[47], 1);
	TextDrawSetShadow(TDEditor_TD[47], 0);

	TDEditor_TD[48] = TextDrawCreate(558.688842, 433.606658, "/");
	TextDrawLetterSize(TDEditor_TD[48], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[48], 1);
	TextDrawColor(TDEditor_TD[48], tdboja);
	TextDrawSetShadow(TDEditor_TD[48], 0);
	TextDrawSetOutline(TDEditor_TD[48], 0);
	TextDrawBackgroundColor(TDEditor_TD[48], 255);
	TextDrawFont(TDEditor_TD[48], 0);
	TextDrawSetProportional(TDEditor_TD[48], 1);
	TextDrawSetShadow(TDEditor_TD[48], 0);

	TDEditor_TD[49] = TextDrawCreate(585.039611, 433.606658, "Verzija:~n~"NERP_VERZIJA"");
	TextDrawLetterSize(TDEditor_TD[49], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[49], 2);
	TextDrawColor(TDEditor_TD[49], -1);
	TextDrawSetShadow(TDEditor_TD[49], 0);
	TextDrawSetOutline(TDEditor_TD[49], 0);
	TextDrawBackgroundColor(TDEditor_TD[49], 255);
	TextDrawFont(TDEditor_TD[49], 2);
	TextDrawSetProportional(TDEditor_TD[49], 1);
	TextDrawSetShadow(TDEditor_TD[49], 0);

	TDEditor_TD[50] = TextDrawCreate(603.977783, 433.606658, "/");
	TextDrawLetterSize(TDEditor_TD[50], 0.177777, 0.818488);
	TextDrawAlignment(TDEditor_TD[50], 1);
	TextDrawColor(TDEditor_TD[50], tdboja);
	TextDrawSetShadow(TDEditor_TD[50], 0);
	TextDrawSetOutline(TDEditor_TD[50], 0);
	TextDrawBackgroundColor(TDEditor_TD[50], 255);
	TextDrawFont(TDEditor_TD[50], 0);
	TextDrawSetProportional(TDEditor_TD[50], 1);
	TextDrawSetShadow(TDEditor_TD[50], 0);

	#if defined papadudbrkfazon

	new srwver[200];
	format(srwver,sizeof(srwver),"%s",verzija);
	
	#endif 
	TDEditor_TD[51] = TextDrawCreate(623.930114, 436.004516, "");
	TextDrawLetterSize(TDEditor_TD[51], 0.100443, 0.654222);
	TextDrawAlignment(TDEditor_TD[51], 2);
	TextDrawColor(TDEditor_TD[51], -1);
	TextDrawSetShadow(TDEditor_TD[51], 0);
	TextDrawSetOutline(TDEditor_TD[51], 0);
	TextDrawBackgroundColor(TDEditor_TD[51], 255);
	TextDrawFont(TDEditor_TD[51], 2);
	TextDrawSetProportional(TDEditor_TD[51], 1);
	TextDrawSetShadow(TDEditor_TD[51], 0);

	new Float:INTERAKTIVNI_TD_OFF = -3.5;

	TDEditor_TD[52] = TextDrawCreate(447.777374, 395.242218 + INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[52], 0.000000, 4.329257);
	TextDrawTextSize(TDEditor_TD[52], 636.666748, 0.000000);
	TextDrawAlignment(TDEditor_TD[52], 1);
	TextDrawColor(TDEditor_TD[52], 0);
	TextDrawUseBox(TDEditor_TD[52], true);
	TextDrawBoxColor(TDEditor_TD[52], 102);
	TextDrawSetShadow(TDEditor_TD[52], 0);
	TextDrawSetOutline(TDEditor_TD[52], 0);
	TextDrawFont(TDEditor_TD[52], 0);

	TDEditor_TD[53] = TextDrawCreate(634.444458, 400.717773+ INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[53], 0.000000, 3.223087);
	TextDrawTextSize(TDEditor_TD[53], 599.777770, 0.000000);
	TextDrawAlignment(TDEditor_TD[53], 1);
	TextDrawColor(TDEditor_TD[53], 0);
	TextDrawUseBox(TDEditor_TD[53], true);
	TextDrawBoxColor(TDEditor_TD[53], 102);
	TextDrawSetShadow(TDEditor_TD[53], 0);
	TextDrawSetOutline(TDEditor_TD[53], 0);
	TextDrawFont(TDEditor_TD[53], 0);

	TDEditor_TD[54] = TextDrawCreate(565.555603, 400.717773+ INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[54], 0.000000, 3.167779);
	TextDrawTextSize(TDEditor_TD[54], 596.222290, 0.000000);
	TextDrawAlignment(TDEditor_TD[54], 1);
	TextDrawColor(TDEditor_TD[54], 0);
	TextDrawUseBox(TDEditor_TD[54], true);
	TextDrawBoxColor(TDEditor_TD[54], 102);
	TextDrawSetShadow(TDEditor_TD[54], 0);
	TextDrawSetOutline(TDEditor_TD[54], 0);
	TextDrawFont(TDEditor_TD[54], 0);

	TDEditor_TD[55] = TextDrawCreate(529.555664, 401.713317+ INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[55], 0.000000, 3.167779);
	TextDrawTextSize(TDEditor_TD[55], 558.000061, 0.000000);
	TextDrawAlignment(TDEditor_TD[55], 1);
	TextDrawColor(TDEditor_TD[55], 0);
	TextDrawUseBox(TDEditor_TD[55], true);
	TextDrawBoxColor(TDEditor_TD[55], 102);
	TextDrawSetShadow(TDEditor_TD[55], 0);
	TextDrawSetOutline(TDEditor_TD[55], 0);
	TextDrawFont(TDEditor_TD[55], 0);

	TDEditor_TD[56] = TextDrawCreate(494.000091, 402.211090+ INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[56], 0.000000, 3.112471);
	TextDrawTextSize(TDEditor_TD[56], 522.889038, 0.000000);
	TextDrawAlignment(TDEditor_TD[56], 1);
	TextDrawColor(TDEditor_TD[56], 0);
	TextDrawUseBox(TDEditor_TD[56], true);
	TextDrawBoxColor(TDEditor_TD[56], 102);
	TextDrawSetShadow(TDEditor_TD[56], 0);
	TextDrawSetOutline(TDEditor_TD[56], 0);
	TextDrawFont(TDEditor_TD[56], 0);

	TDEditor_TD[57] = TextDrawCreate(610.222412, 423.111175+ INTERAKTIVNI_TD_OFF, "ASKQ");
	TextDrawLetterSize(TDEditor_TD[57], 0.139777, 0.992711);
	TextDrawAlignment(TDEditor_TD[57], 1);
	TextDrawColor(TDEditor_TD[57], -1);
	TextDrawSetShadow(TDEditor_TD[57], 0);
	TextDrawSetOutline(TDEditor_TD[57], 1);
	TextDrawBackgroundColor(TDEditor_TD[57], 51);
	TextDrawFont(TDEditor_TD[57], 2);
	TextDrawSetProportional(TDEditor_TD[57], 1);

	TDEditor_TD[58] = TextDrawCreate(567.555664, 424.106628+ INTERAKTIVNI_TD_OFF, "KOMANDE");
	TextDrawLetterSize(TDEditor_TD[58], 0.137999, 0.982755);
	TextDrawAlignment(TDEditor_TD[58], 1);
	TextDrawColor(TDEditor_TD[58], -1);
	TextDrawSetShadow(TDEditor_TD[58], 0);
	TextDrawSetOutline(TDEditor_TD[58], 1);
	TextDrawBackgroundColor(TDEditor_TD[58], 51);
	TextDrawFont(TDEditor_TD[58], 2);
	TextDrawSetProportional(TDEditor_TD[58], 1);

	TDEditor_TD[59] = TextDrawCreate(535.111145, 425.102203+ INTERAKTIVNI_TD_OFF, "STATS");
	TextDrawLetterSize(TDEditor_TD[59], 0.124222, 0.937955);
	TextDrawAlignment(TDEditor_TD[59], 1);
	TextDrawColor(TDEditor_TD[59], -1);
	TextDrawSetShadow(TDEditor_TD[59], 0);
	TextDrawSetOutline(TDEditor_TD[59], 1);
	TextDrawBackgroundColor(TDEditor_TD[59], 51);
	TextDrawFont(TDEditor_TD[59], 2);
	TextDrawSetProportional(TDEditor_TD[59], 1);

	TDEditor_TD[60] = TextDrawCreate(495.111297, 424.604431+ INTERAKTIVNI_TD_OFF, "inventory");
	TextDrawLetterSize(TDEditor_TD[60], 0.121555, 0.982755);
	TextDrawAlignment(TDEditor_TD[60], 1);
	TextDrawColor(TDEditor_TD[60], -1);
	TextDrawSetShadow(TDEditor_TD[60], 0);
	TextDrawSetOutline(TDEditor_TD[60], 1);
	TextDrawBackgroundColor(TDEditor_TD[60], 51);
	TextDrawFont(TDEditor_TD[60], 2);
	TextDrawSetProportional(TDEditor_TD[60], 1);

	TDEditor_TD[61] = TextDrawCreate(489.111236, 402.211120+ INTERAKTIVNI_TD_OFF, "usebox");
	TextDrawLetterSize(TDEditor_TD[61], 0.000000, 3.167776);
	TextDrawTextSize(TDEditor_TD[61], 452.666778, 0.000000);
	TextDrawAlignment(TDEditor_TD[61], 1);
	TextDrawColor(TDEditor_TD[61], 0);
	TextDrawUseBox(TDEditor_TD[61], true);
	TextDrawBoxColor(TDEditor_TD[61], 102);
	TextDrawSetShadow(TDEditor_TD[61], 0);
	TextDrawSetOutline(TDEditor_TD[61], 0);
	TextDrawFont(TDEditor_TD[61], 0);

	TDEditor_TD[62] = TextDrawCreate(457.777801, 424.604583+ INTERAKTIVNI_TD_OFF, "Vise opcija");
	TextDrawLetterSize(TDEditor_TD[62], 0.109555, 0.982754);
	TextDrawAlignment(TDEditor_TD[62], 1);
	TextDrawColor(TDEditor_TD[62], -1);
	TextDrawSetShadow(TDEditor_TD[62], 0);
	TextDrawSetOutline(TDEditor_TD[62], 1);
	TextDrawBackgroundColor(TDEditor_TD[62], 51);
	TextDrawFont(TDEditor_TD[62], 2);
	TextDrawSetProportional(TDEditor_TD[62], 1);

	TDEditor_TD[63] = TextDrawCreate(604.444458, 401.706665+ INTERAKTIVNI_TD_OFF, "LD_SPAC:white"); //askq
	TextDrawLetterSize(TDEditor_TD[63], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[63], 24.888916, 22.897766);
	TextDrawAlignment(TDEditor_TD[63], 0);
	TextDrawSetShadow(TDEditor_TD[63], 0);
	TextDrawSetOutline(TDEditor_TD[63], 0);
	TextDrawFont(TDEditor_TD[63], 5);
	TextDrawSetSelectable(TDEditor_TD[63], true);

	TextDrawFont(TDEditor_TD[63], 5);
	TextDrawSetProportional(TDEditor_TD[63], 0);
	TextDrawSetPreviewModel(TDEditor_TD[63], 18631);
	TextDrawSetPreviewRot(TDEditor_TD[63], 0.000000, 0.000000, 0.000000, 1.000000);
	TextDrawBackgroundColor(TDEditor_TD[63], 0xFFFFFFFF00);

	TDEditor_TD[64] = TextDrawCreate(566.222229, 401.706665+ INTERAKTIVNI_TD_OFF, "LD_SPAC:white"); //komande
	TextDrawLetterSize(TDEditor_TD[64], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[64], 28.444458, 22.897766);
	TextDrawAlignment(TDEditor_TD[64], 0);
	TextDrawSetShadow(TDEditor_TD[64], 0);
	TextDrawSetOutline(TDEditor_TD[64], 0);
	TextDrawFont(TDEditor_TD[64], 4);
	TextDrawSetSelectable(TDEditor_TD[64], true);

	TextDrawFont(TDEditor_TD[64], 5);
	TextDrawSetProportional(TDEditor_TD[64], 0);
	TextDrawSetPreviewModel(TDEditor_TD[64], 1239);
	TextDrawSetPreviewRot(TDEditor_TD[64], 0.000000, 0.000000, 0.000000, 1.000000);
	TextDrawBackgroundColor(TDEditor_TD[64], 0xFFFFFFFF00);

	TDEditor_TD[65] = TextDrawCreate(529.777770, 402.204467+ INTERAKTIVNI_TD_OFF, "LD_SPAC:white"); //stats 
	TextDrawLetterSize(TDEditor_TD[65], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[65], 27.111145, 23.893310);
	TextDrawAlignment(TDEditor_TD[65], 0);
	TextDrawSetShadow(TDEditor_TD[65], 0);
	TextDrawSetOutline(TDEditor_TD[65], 0);
	TextDrawFont(TDEditor_TD[65], 4);
	TextDrawSetSelectable(TDEditor_TD[65], true);

	TextDrawFont(TDEditor_TD[65], 5);
	TextDrawSetProportional(TDEditor_TD[65], 0);
	TextDrawSetPreviewModel(TDEditor_TD[65], 1314);
	TextDrawSetPreviewRot(TDEditor_TD[65], 0.000000, 0.000000, 0.000000, 1.000000);
	TextDrawBackgroundColor(TDEditor_TD[65], 0xFFFFFFFF00);

	TDEditor_TD[66] = TextDrawCreate(493.777770, 404.195556+ INTERAKTIVNI_TD_OFF, "LD_SPAC:white"); //inv 
	TextDrawLetterSize(TDEditor_TD[66], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[66], 28.444458, 21.404449);
	TextDrawAlignment(TDEditor_TD[66], 0);
	TextDrawSetShadow(TDEditor_TD[66], 0);
	TextDrawSetOutline(TDEditor_TD[66], 0);
	TextDrawFont(TDEditor_TD[66], 4);
	TextDrawSetSelectable(TDEditor_TD[66], true);

	TextDrawFont(TDEditor_TD[66], 5);
	TextDrawSetProportional(TDEditor_TD[66], 0);
	TextDrawSetPreviewModel(TDEditor_TD[66], 371);
	TextDrawSetPreviewRot(TDEditor_TD[66], 0.000000, 0.000000, 0.000000, 1.000000);
	TextDrawBackgroundColor(TDEditor_TD[66], 0xFFFFFFFF00);

	TDEditor_TD[67] = TextDrawCreate(455.555572, 401.706665+ INTERAKTIVNI_TD_OFF, "LD_SPAC:white"); //vise
	TextDrawLetterSize(TDEditor_TD[67], 0.000000, 0.000000);
	TextDrawTextSize(TDEditor_TD[67], 29.777740, 23.395568);
	TextDrawAlignment(TDEditor_TD[67], 0);
	TextDrawSetShadow(TDEditor_TD[67], 0);
	TextDrawSetOutline(TDEditor_TD[67], 0);
	TextDrawFont(TDEditor_TD[67], 4);
	TextDrawSetSelectable(TDEditor_TD[67], true);

	TextDrawFont(TDEditor_TD[67], 5);
	TextDrawSetProportional(TDEditor_TD[67], 0);
	TextDrawSetPreviewModel(TDEditor_TD[67], 1277);
	TextDrawSetPreviewRot(TDEditor_TD[67], 0.000000, 0.000000, 0.000000, 1.000000);
	TextDrawBackgroundColor(TDEditor_TD[67], 0xFFFFFFFF00);
	/*Interaktivni tdovi idu od

	TDEditor_TD[54] - [67]*/

	
	GladTDPizza = TextDrawCreate(519.000000, 101.000000, "_");//Pizza TD 
	TextDrawBackgroundColor(GladTDPizza, 0);
	TextDrawFont(GladTDPizza, 5);
	TextDrawLetterSize(GladTDPizza, 0.800000, 9.799999);
	TextDrawColor(GladTDPizza, -65281);
	TextDrawSetOutline(GladTDPizza, 1);
	TextDrawSetProportional(GladTDPizza, 1);
	TextDrawUseBox(GladTDPizza, 1);
	TextDrawBoxColor(GladTDPizza, 255);
	TextDrawTextSize(GladTDPizza, 61.000000, -82.000000);
	TextDrawSetSelectable(GladTDPizza, 0);
	TextDrawSetPreviewModel(GladTDPizza, 19580);
	TextDrawSetPreviewRot(GladTDPizza,-50.000000, 0.000000, 0.000000, 4.000000);


	WcTDSolja = TextDrawCreate(572.000000, 96.000000, "_");//wc solja
	TextDrawFont(WcTDSolja, 5);
	TextDrawLetterSize(WcTDSolja, 0.819999, 14.199999);
	TextDrawColor(WcTDSolja, -1);
	TextDrawSetOutline(WcTDSolja, 1);
	TextDrawSetProportional(WcTDSolja, 1);
	TextDrawUseBox(WcTDSolja, 1);
	TextDrawBoxColor(WcTDSolja, 255);
	TextDrawTextSize(WcTDSolja, 61.000000, -58.000000);
	TextDrawSetSelectable(WcTDSolja, 0);
	TextDrawSetPreviewModel(WcTDSolja, 2528);
	TextDrawBackgroundColor(WcTDSolja, 0);
	TextDrawSetPreviewRot(WcTDSolja,-180.000000, 0.000000, 90.000000, 4.000000);
	

	takedamage0 = TextDrawCreate(0.000000, 313.600006, "LD_SPAC:white");
	TextDrawLetterSize(takedamage0, 0.000000, 0.000000);
	TextDrawTextSize(takedamage0, 640.000000, 36.337768);
	TextDrawAlignment(takedamage0, 1);
	TextDrawColor(takedamage0, tdboja);
	TextDrawSetShadow(takedamage0, 0);
	TextDrawSetOutline(takedamage0, 0);
	TextDrawFont(takedamage0, 4);

	takedamage1 = TextDrawCreate(79.111129, 323.057739, "    - Primili ste stetu (damage)!");
	TextDrawLetterSize(takedamage1, 0.449999, 1.600000);
	TextDrawAlignment(takedamage1, 1);
	TextDrawColor(takedamage1, -1);
	TextDrawSetShadow(takedamage1, 0);
	TextDrawSetOutline(takedamage1, 1);
	TextDrawBackgroundColor(takedamage1, 51);
	TextDrawFont(takedamage1, 3);
	TextDrawSetProportional(takedamage1, 1);
	
	LogRegSelection[0] = TextDrawCreate(464.666870, 252.380081, "usebox");
	TextDrawLetterSize(LogRegSelection[0], 0.000000, 10.468517);
	TextDrawTextSize(LogRegSelection[0], 174.888870, 0.000000);
	TextDrawAlignment(LogRegSelection[0], 1);
	TextDrawColor(LogRegSelection[0], 0);
	TextDrawUseBox(LogRegSelection[0], true);
	TextDrawBoxColor(LogRegSelection[0], 102);
	TextDrawSetShadow(LogRegSelection[0], 0);
	TextDrawSetOutline(LogRegSelection[0], 0);
	TextDrawFont(LogRegSelection[0], 0);

	LogRegSelection[1] = TextDrawCreate(318.666717, 254.862213, "Dobrodosli na Nova Era server!");
	TextDrawLetterSize(LogRegSelection[1], 0.449999, 1.600000);
	TextDrawAlignment(LogRegSelection[1], 2);
	TextDrawColor(LogRegSelection[1], -1);
	TextDrawSetShadow(LogRegSelection[1], 0);
	TextDrawSetOutline(LogRegSelection[1], 1);
	TextDrawBackgroundColor(LogRegSelection[1], 51);
	TextDrawFont(LogRegSelection[1], 0);
	TextDrawSetProportional(LogRegSelection[1], 1);

	LogRegSelection[2] = TextDrawCreate(146.666778, 274.773376, NERP_KRUG);
	TextDrawLetterSize(LogRegSelection[2], 0.000000, 0.000000);
	TextDrawTextSize(LogRegSelection[2], 345.333312, 2.986650);
	TextDrawAlignment(LogRegSelection[2], 1);
	TextDrawColor(LogRegSelection[2], tdboja);
	TextDrawSetShadow(LogRegSelection[2], 0);
	TextDrawSetOutline(LogRegSelection[2], 0);
	TextDrawFont(LogRegSelection[2], 4);

	LogRegSelection[3] = TextDrawCreate(231.111114, 305.635559, "LD_SPAC:white");
	TextDrawLetterSize(LogRegSelection[3], 0.000000, 0.000000);
	TextDrawTextSize(LogRegSelection[3], 58.666656, 19.413330);
	TextDrawAlignment(LogRegSelection[3], 1);
	TextDrawColor(LogRegSelection[3], tdboja);
	TextDrawSetShadow(LogRegSelection[3], 0);
	TextDrawSetOutline(LogRegSelection[3], 0);
	TextDrawFont(LogRegSelection[3], 4);
	TextDrawSetSelectable(LogRegSelection[3], true);

	LogRegSelection[4] = TextDrawCreate(347.111389, 307.128814, "LD_SPAC:white");
	TextDrawLetterSize(LogRegSelection[4], 0.000000, 0.000000);
	TextDrawTextSize(LogRegSelection[4], 63.111114, 19.413360);
	TextDrawAlignment(LogRegSelection[4], 1);
	TextDrawColor(LogRegSelection[4], tdboja);
	TextDrawSetShadow(LogRegSelection[4], 0);
	TextDrawSetOutline(LogRegSelection[4], 0);
	TextDrawFont(LogRegSelection[4], 4);
	TextDrawSetSelectable(LogRegSelection[4], true);

	LogRegSelection[5] = TextDrawCreate(260.444366, 310.115570, "LOGIN");
	TextDrawLetterSize(LogRegSelection[5], 0.220222, 1.067377);
	TextDrawAlignment(LogRegSelection[5], 2);
	TextDrawColor(LogRegSelection[5], -1);
	TextDrawSetShadow(LogRegSelection[5], 0);
	TextDrawSetOutline(LogRegSelection[5], 1);
	TextDrawBackgroundColor(LogRegSelection[5], 51);
	TextDrawFont(LogRegSelection[5], 2);
	TextDrawSetProportional(LogRegSelection[5], 1);

	LogRegSelection[6] = TextDrawCreate(379.555541, 310.115509, "REGISTER");
	TextDrawLetterSize(LogRegSelection[6], 0.195777, 1.142044);
	TextDrawAlignment(LogRegSelection[6], 2);
	TextDrawColor(LogRegSelection[6], -1);
	TextDrawSetShadow(LogRegSelection[6], 0);
	TextDrawSetOutline(LogRegSelection[6], 1);
	TextDrawBackgroundColor(LogRegSelection[6], 51);
	TextDrawFont(LogRegSelection[6], 2);
	TextDrawSetProportional(LogRegSelection[6], 1);

	LogRegSelection[7] = TextDrawCreate(316.444488, 286.720031, "Odaberite opciju koju zelite:");
	TextDrawLetterSize(LogRegSelection[7], 0.161111, 0.913066);
	TextDrawAlignment(LogRegSelection[7], 2);
	TextDrawColor(LogRegSelection[7], -1);
	TextDrawSetShadow(LogRegSelection[7], 0);
	TextDrawSetOutline(LogRegSelection[7], 1);
	TextDrawBackgroundColor(LogRegSelection[7], 51);
	TextDrawFont(LogRegSelection[7], 2);
	TextDrawSetProportional(LogRegSelection[7], 1);

	LogRegSelection[8] = TextDrawCreate(312.000091, 307.128845, "ili");
	TextDrawLetterSize(LogRegSelection[8], 0.449999, 1.600000);
	TextDrawAlignment(LogRegSelection[8], 1);
	TextDrawColor(LogRegSelection[8], -1);
	TextDrawSetShadow(LogRegSelection[8], 0);
	TextDrawSetOutline(LogRegSelection[8], 1);
	TextDrawBackgroundColor(LogRegSelection[8], 51);
	TextDrawFont(LogRegSelection[8], 0);
	TextDrawSetProportional(LogRegSelection[8], 1);
	
	EditObjectTextdraw[0] = TextDrawCreate(550.888916, 221.517776, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[0], 0.000000, 9.141109);
	TextDrawTextSize(EditObjectTextdraw[0], 467.777801, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[0], 1);
	TextDrawColor(EditObjectTextdraw[0], 0);
	TextDrawUseBox(EditObjectTextdraw[0], true);
	TextDrawBoxColor(EditObjectTextdraw[0], 102);
	TextDrawSetShadow(EditObjectTextdraw[0], 0);
	TextDrawSetOutline(EditObjectTextdraw[0], 0);
	TextDrawFont(EditObjectTextdraw[0], 0);

	EditObjectTextdraw[1] = TextDrawCreate(474.666717, 249.386718, "X");
	TextDrawLetterSize(EditObjectTextdraw[1], 0.449999, 1.600000);
	TextDrawAlignment(EditObjectTextdraw[1], 1);
	TextDrawColor(EditObjectTextdraw[1], -1);
	TextDrawSetShadow(EditObjectTextdraw[1], 0);
	TextDrawSetOutline(EditObjectTextdraw[1], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[1], 51);
	TextDrawFont(EditObjectTextdraw[1], 2);
	TextDrawSetProportional(EditObjectTextdraw[1], 1);

	EditObjectTextdraw[2] = TextDrawCreate(475.111114, 267.804473, "Y");
	TextDrawLetterSize(EditObjectTextdraw[2], 0.449999, 1.600000);
	TextDrawAlignment(EditObjectTextdraw[2], 1);
	TextDrawColor(EditObjectTextdraw[2], -1);
	TextDrawSetShadow(EditObjectTextdraw[2], 0);
	TextDrawSetOutline(EditObjectTextdraw[2], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[2], 51);
	TextDrawFont(EditObjectTextdraw[2], 2);
	TextDrawSetProportional(EditObjectTextdraw[2], 1);

	EditObjectTextdraw[3] = TextDrawCreate(475.555603, 285.226684, "Z");
	TextDrawLetterSize(EditObjectTextdraw[3], 0.449999, 1.600000);
	TextDrawAlignment(EditObjectTextdraw[3], 1);
	TextDrawColor(EditObjectTextdraw[3], -1);
	TextDrawSetShadow(EditObjectTextdraw[3], 0);
	TextDrawSetOutline(EditObjectTextdraw[3], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[3], 51);
	TextDrawFont(EditObjectTextdraw[3], 2);
	TextDrawSetProportional(EditObjectTextdraw[3], 1);

	EditObjectTextdraw[4] = TextDrawCreate(545.111083, 251.384429, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[4], 0.000000, 1.453210);
	TextDrawTextSize(EditObjectTextdraw[4], 487.333343, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[4], 1);
	TextDrawColor(EditObjectTextdraw[4], 0);
	TextDrawUseBox(EditObjectTextdraw[4], true);
	TextDrawBoxColor(EditObjectTextdraw[4], 102);
	TextDrawSetShadow(EditObjectTextdraw[4], 0);
	TextDrawSetOutline(EditObjectTextdraw[4], 0);
	TextDrawFont(EditObjectTextdraw[4], 0);

	EditObjectTextdraw[5] = TextDrawCreate(545.555541, 270.300018, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[5], 0.000000, 1.397899);
	TextDrawTextSize(EditObjectTextdraw[5], 487.777801, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[5], 1);
	TextDrawColor(EditObjectTextdraw[5], 0);
	TextDrawUseBox(EditObjectTextdraw[5], true);
	TextDrawBoxColor(EditObjectTextdraw[5], 102);
	TextDrawSetShadow(EditObjectTextdraw[5], 0);
	TextDrawSetOutline(EditObjectTextdraw[5], 0);
	TextDrawFont(EditObjectTextdraw[5], 0);

	EditObjectTextdraw[6] = TextDrawCreate(545.111083, 289.215545, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[6], 0.000000, 1.231978);
	TextDrawTextSize(EditObjectTextdraw[6], 488.222198, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[6], 1);
	TextDrawColor(EditObjectTextdraw[6], 0);
	TextDrawUseBox(EditObjectTextdraw[6], true);
	TextDrawBoxColor(EditObjectTextdraw[6], 102);
	TextDrawSetShadow(EditObjectTextdraw[6], 0);
	TextDrawSetOutline(EditObjectTextdraw[6], 0);
	TextDrawFont(EditObjectTextdraw[6], 0);

	EditObjectTextdraw[7] = TextDrawCreate(475.111114, 229.973327, "LD_SPAC:white");
	TextDrawLetterSize(EditObjectTextdraw[7], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[7], 31.111114, 12.942214);
	TextDrawAlignment(EditObjectTextdraw[7], 1);
	TextDrawColor(EditObjectTextdraw[7], tdboja);
	TextDrawSetShadow(EditObjectTextdraw[7], 0);
	TextDrawSetOutline(EditObjectTextdraw[7], 0);
	TextDrawFont(EditObjectTextdraw[7], 4);
	TextDrawSetSelectable(EditObjectTextdraw[7], true);

	EditObjectTextdraw[8] = TextDrawCreate(510.666564, 229.973342, "LD_SPAC:white");
	TextDrawLetterSize(EditObjectTextdraw[8], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[8], 33.333316, 12.444461);
	TextDrawAlignment(EditObjectTextdraw[8], 1);
	TextDrawColor(EditObjectTextdraw[8], tdboja);
	TextDrawSetShadow(EditObjectTextdraw[8], 0);
	TextDrawSetOutline(EditObjectTextdraw[8], 0);
	TextDrawFont(EditObjectTextdraw[8], 4);
	TextDrawSetSelectable(EditObjectTextdraw[8], true);

	EditObjectTextdraw[9] = TextDrawCreate(479.555572, 231.466735, "POS");
	TextDrawLetterSize(EditObjectTextdraw[9], 0.266889, 0.893155);
	TextDrawAlignment(EditObjectTextdraw[9], 1);
	TextDrawColor(EditObjectTextdraw[9], -1);
	TextDrawSetShadow(EditObjectTextdraw[9], 0);
	TextDrawSetOutline(EditObjectTextdraw[9], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[9], 51);
	TextDrawFont(EditObjectTextdraw[9], 2);
	TextDrawSetProportional(EditObjectTextdraw[9], 1);

	EditObjectTextdraw[10] = TextDrawCreate(517.333007, 230.471191, "ROT");
	TextDrawLetterSize(EditObjectTextdraw[10], 0.238000, 1.012621);
	TextDrawAlignment(EditObjectTextdraw[10], 1);
	TextDrawColor(EditObjectTextdraw[10], -1);
	TextDrawSetShadow(EditObjectTextdraw[10], 0);
	TextDrawSetOutline(EditObjectTextdraw[10], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[10], 51);
	TextDrawFont(EditObjectTextdraw[10], 2);
	TextDrawSetProportional(EditObjectTextdraw[10], 1);

	EditObjectTextdraw[11] = TextDrawCreate(492.888885, 251.875549, "ld_beat:left");
	TextDrawLetterSize(EditObjectTextdraw[11], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[11], 17.777811, 15.431104);
	TextDrawAlignment(EditObjectTextdraw[11], 1);
	TextDrawColor(EditObjectTextdraw[11], -1);
	TextDrawSetShadow(EditObjectTextdraw[11], 0);
	TextDrawSetOutline(EditObjectTextdraw[11], 0);
	TextDrawFont(EditObjectTextdraw[11], 4);
	TextDrawSetSelectable(EditObjectTextdraw[11], true);

	EditObjectTextdraw[12] = TextDrawCreate(521.333618, 250.382232, "ld_beat:right");
	TextDrawLetterSize(EditObjectTextdraw[12], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[12], 19.111135, 16.426673);
	TextDrawAlignment(EditObjectTextdraw[12], 1);
	TextDrawColor(EditObjectTextdraw[12], -1);
	TextDrawSetShadow(EditObjectTextdraw[12], 0);
	TextDrawSetOutline(EditObjectTextdraw[12], 0);
	TextDrawFont(EditObjectTextdraw[12], 4);
	TextDrawSetSelectable(EditObjectTextdraw[12], true);

	EditObjectTextdraw[13] = TextDrawCreate(491.555633, 268.799957, "ld_beat:left");
	TextDrawLetterSize(EditObjectTextdraw[13], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[13], 17.777769, 14.933345);
	TextDrawAlignment(EditObjectTextdraw[13], 1);
	TextDrawColor(EditObjectTextdraw[13], -1);
	TextDrawSetShadow(EditObjectTextdraw[13], 0);
	TextDrawSetOutline(EditObjectTextdraw[13], 0);
	TextDrawFont(EditObjectTextdraw[13], 4);
	TextDrawSetSelectable(EditObjectTextdraw[13], true);

	EditObjectTextdraw[14] = TextDrawCreate(522.666809, 268.302215, "ld_beat:right");
	TextDrawLetterSize(EditObjectTextdraw[14], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[14], 17.333328, 16.924436);
	TextDrawAlignment(EditObjectTextdraw[14], 1);
	TextDrawColor(EditObjectTextdraw[14], -1);
	TextDrawSetShadow(EditObjectTextdraw[14], 0);
	TextDrawSetOutline(EditObjectTextdraw[14], 0);
	TextDrawFont(EditObjectTextdraw[14], 4);
	TextDrawSetSelectable(EditObjectTextdraw[14], true);

	EditObjectTextdraw[15] = TextDrawCreate(491.111053, 287.217864, "ld_beat:left");
	TextDrawLetterSize(EditObjectTextdraw[15], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[15], 17.777759, 15.928884);
	TextDrawAlignment(EditObjectTextdraw[15], 1);
	TextDrawColor(EditObjectTextdraw[15], -1);
	TextDrawSetShadow(EditObjectTextdraw[15], 0);
	TextDrawSetOutline(EditObjectTextdraw[15], 0);
	TextDrawFont(EditObjectTextdraw[15], 4);
	TextDrawSetSelectable(EditObjectTextdraw[15], true);

	EditObjectTextdraw[16] = TextDrawCreate(523.555480, 288.213256, "ld_beat:right");
	TextDrawLetterSize(EditObjectTextdraw[16], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[16], 17.333328, 14.933338);
	TextDrawAlignment(EditObjectTextdraw[16], 1);
	TextDrawColor(EditObjectTextdraw[16], -1);
	TextDrawSetShadow(EditObjectTextdraw[16], 0);
	TextDrawSetOutline(EditObjectTextdraw[16], 0);
	TextDrawFont(EditObjectTextdraw[16], 4);
	TextDrawSetSelectable(EditObjectTextdraw[16], true);

	EditObjectTextdraw[17] = TextDrawCreate(472.888977, 209.066726, "Nova Era ~w~Edit");
	TextDrawLetterSize(EditObjectTextdraw[17], 0.366889, 1.719466);
	TextDrawAlignment(EditObjectTextdraw[17], 1);
	TextDrawColor(EditObjectTextdraw[17], tdboja);
	TextDrawSetShadow(EditObjectTextdraw[17], 0);
	TextDrawSetOutline(EditObjectTextdraw[17], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[17], 51);
	TextDrawFont(EditObjectTextdraw[17], 0);
	TextDrawSetProportional(EditObjectTextdraw[17], 1);

	EditObjectTextdraw[18] = TextDrawCreate(530.222534, 334.506500, "ld_chat:thumbup");
	TextDrawLetterSize(EditObjectTextdraw[18], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[18], 15.555522, 16.426633);
	TextDrawAlignment(EditObjectTextdraw[18], 1);
	TextDrawColor(EditObjectTextdraw[18], -1);
	TextDrawSetShadow(EditObjectTextdraw[18], 0);
	TextDrawSetOutline(EditObjectTextdraw[18], 0);
	TextDrawFont(EditObjectTextdraw[18], 4);
	TextDrawSetSelectable(EditObjectTextdraw[18], true);

	EditObjectTextdraw[19] = TextDrawCreate(508.444335, 334.506622, "ld_chat:thumbdn");
	TextDrawLetterSize(EditObjectTextdraw[19], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[19], 16.444488, 16.924453);
	TextDrawAlignment(EditObjectTextdraw[19], 1);
	TextDrawColor(EditObjectTextdraw[19], -1);
	TextDrawSetShadow(EditObjectTextdraw[19], 0);
	TextDrawSetOutline(EditObjectTextdraw[19], 0);
	TextDrawFont(EditObjectTextdraw[19], 4);
	TextDrawSetSelectable(EditObjectTextdraw[19], true);
	
	EditObjectTextdraw[20] = TextDrawCreate(551.332702, 309.624511, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[20], 0.000000, 2.238393);
	TextDrawTextSize(EditObjectTextdraw[20], 467.777618, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[20], 1);
	TextDrawColor(EditObjectTextdraw[20], 0);
	TextDrawUseBox(EditObjectTextdraw[20], true);
	TextDrawBoxColor(EditObjectTextdraw[20], 102);
	TextDrawSetShadow(EditObjectTextdraw[20], 0);
	TextDrawSetOutline(EditObjectTextdraw[20], 0);
	TextDrawFont(EditObjectTextdraw[20], 0);

	EditObjectTextdraw[21] = TextDrawCreate(485.333404, 311.608947, "Update~n~rate");
	TextDrawLetterSize(EditObjectTextdraw[21], 0.129555, 0.853333);
	TextDrawAlignment(EditObjectTextdraw[21], 2);
	TextDrawColor(EditObjectTextdraw[21], -1);
	TextDrawSetShadow(EditObjectTextdraw[21], 0);
	TextDrawSetOutline(EditObjectTextdraw[21], 1);
	TextDrawBackgroundColor(EditObjectTextdraw[21], 51);
	TextDrawFont(EditObjectTextdraw[21], 2);
	TextDrawSetProportional(EditObjectTextdraw[21], 1);

	EditObjectTextdraw[22] = TextDrawCreate(546.000000, 313.606658, "usebox");
	TextDrawLetterSize(EditObjectTextdraw[22], 0.000000, 1.287283);
	TextDrawTextSize(EditObjectTextdraw[22], 497.111083, 0.000000);
	TextDrawAlignment(EditObjectTextdraw[22], 1);
	TextDrawColor(EditObjectTextdraw[22], 0);
	TextDrawUseBox(EditObjectTextdraw[22], true);
	TextDrawBoxColor(EditObjectTextdraw[22], 102);
	TextDrawSetShadow(EditObjectTextdraw[22], 0);
	TextDrawSetOutline(EditObjectTextdraw[22], 0);
	TextDrawFont(EditObjectTextdraw[22], 0);

	EditObjectTextdraw[23] = TextDrawCreate(501.777954, 312.106658, "ld_beat:left");
	TextDrawLetterSize(EditObjectTextdraw[23], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[23], 17.333320, 15.431093);
	TextDrawAlignment(EditObjectTextdraw[23], 1);
	TextDrawColor(EditObjectTextdraw[23], -1);
	TextDrawSetShadow(EditObjectTextdraw[23], 0);
	TextDrawSetOutline(EditObjectTextdraw[23], 0);
	TextDrawFont(EditObjectTextdraw[23], 4);
	TextDrawSetSelectable(EditObjectTextdraw[23], true);

	EditObjectTextdraw[24] = TextDrawCreate(525.777893, 311.608917, "ld_beat:right");
	TextDrawLetterSize(EditObjectTextdraw[24], 0.000000, 0.000000);
	TextDrawTextSize(EditObjectTextdraw[24], 17.333330, 16.426651);
	TextDrawAlignment(EditObjectTextdraw[24], 1);
	TextDrawColor(EditObjectTextdraw[24], -1);
	TextDrawSetShadow(EditObjectTextdraw[24], 0);
	TextDrawSetOutline(EditObjectTextdraw[24], 0);
	TextDrawFont(EditObjectTextdraw[24], 4);
	TextDrawSetSelectable(EditObjectTextdraw[24], true);

	ClientSelection[0] = TextDrawCreate(464.666870, 252.380081, "usebox");
	TextDrawLetterSize(ClientSelection[0], 0.000000, 10.468517);
	TextDrawTextSize(ClientSelection[0], 174.888870, 0.000000);
	TextDrawAlignment(ClientSelection[0], 1);
	TextDrawColor(ClientSelection[0], 0);
	TextDrawUseBox(ClientSelection[0], true);
	TextDrawBoxColor(ClientSelection[0], 102);
	TextDrawSetShadow(ClientSelection[0], 0);
	TextDrawSetOutline(ClientSelection[0], 0);
	TextDrawFont(ClientSelection[0], 0);

	ClientSelection[1] = TextDrawCreate(318.666717, 254.862213, "Dobrodosli na Nova Era server!");
	TextDrawLetterSize(ClientSelection[1], 0.449999, 1.600000);
	TextDrawAlignment(ClientSelection[1], 2);
	TextDrawColor(ClientSelection[1], -1);
	TextDrawSetShadow(ClientSelection[1], 0);
	TextDrawSetOutline(ClientSelection[1], 1);
	TextDrawBackgroundColor(ClientSelection[1], 51);
	TextDrawFont(ClientSelection[1], 0);
	TextDrawSetProportional(ClientSelection[1], 1);

	ClientSelection[2] = TextDrawCreate(146.666778, 274.773376, NERP_KRUG);
	TextDrawLetterSize(ClientSelection[2], 0.000000, 0.000000);
	TextDrawTextSize(ClientSelection[2], 345.333312, 2.986650);
	TextDrawAlignment(ClientSelection[2], 1);
	TextDrawColor(ClientSelection[2], tdboja);
	TextDrawSetShadow(ClientSelection[2], 0);
	TextDrawSetOutline(ClientSelection[2], 0);
	TextDrawFont(ClientSelection[2], 4);

	ClientSelection[3] = TextDrawCreate(231.111114, 305.635559, "LD_SPAC:white");
	TextDrawLetterSize(ClientSelection[3], 0.000000, 0.000000);
	TextDrawTextSize(ClientSelection[3], 58.666656, 19.413330);
	TextDrawAlignment(ClientSelection[3], 1);
	TextDrawColor(ClientSelection[3], tdboja);
	TextDrawSetShadow(ClientSelection[3], 0);
	TextDrawSetOutline(ClientSelection[3], 0);
	TextDrawFont(ClientSelection[3], 4);
	TextDrawSetSelectable(ClientSelection[3], true);

	ClientSelection[4] = TextDrawCreate(347.111389, 307.128814, "LD_SPAC:white");
	TextDrawLetterSize(ClientSelection[4], 0.000000, 0.000000);
	TextDrawTextSize(ClientSelection[4], 63.111114, 19.413360);
	TextDrawAlignment(ClientSelection[4], 1);
	TextDrawColor(ClientSelection[4], tdboja);
	TextDrawSetShadow(ClientSelection[4], 0);
	TextDrawSetOutline(ClientSelection[4], 0);
	TextDrawFont(ClientSelection[4], 4);
	TextDrawSetSelectable(ClientSelection[4], true);

	ClientSelection[5] = TextDrawCreate(260.444366, 310.115570, "PC");
	TextDrawLetterSize(ClientSelection[5], 0.220222, 1.067377);
	TextDrawAlignment(ClientSelection[5], 2);
	TextDrawColor(ClientSelection[5], -1);
	TextDrawSetShadow(ClientSelection[5], 0);
	TextDrawSetOutline(ClientSelection[5], 1);
	TextDrawBackgroundColor(ClientSelection[5], 51);
	TextDrawFont(ClientSelection[5], 2);
	TextDrawSetProportional(ClientSelection[5], 1);

	ClientSelection[6] = TextDrawCreate(379.555541, 310.115509, "MOBILE");
	TextDrawLetterSize(ClientSelection[6], 0.195777, 1.142044);
	TextDrawAlignment(ClientSelection[6], 2);
	TextDrawColor(ClientSelection[6], -1);
	TextDrawSetShadow(ClientSelection[6], 0);
	TextDrawSetOutline(ClientSelection[6], 1);
	TextDrawBackgroundColor(ClientSelection[6], 51);
	TextDrawFont(ClientSelection[6], 2);
	TextDrawSetProportional(ClientSelection[6], 1);

	ClientSelection[7] = TextDrawCreate(316.444488, 286.720031, "Odaberite vrstu klijenta koji koristite:");
	TextDrawLetterSize(ClientSelection[7], 0.161111, 0.913066);
	TextDrawAlignment(ClientSelection[7], 2);
	TextDrawColor(ClientSelection[7], -1);
	TextDrawSetShadow(ClientSelection[7], 0);
	TextDrawSetOutline(ClientSelection[7], 1);
	TextDrawBackgroundColor(ClientSelection[7], 51);
	TextDrawFont(ClientSelection[7], 2);
	TextDrawSetProportional(ClientSelection[7], 1);

	ClientSelection[8] = TextDrawCreate(312.000091, 307.128845, "ili");
	TextDrawLetterSize(ClientSelection[8], 0.449999, 1.600000);
	TextDrawAlignment(ClientSelection[8], 1);
	TextDrawColor(ClientSelection[8], -1);
	TextDrawSetShadow(ClientSelection[8], 0);
	TextDrawSetOutline(ClientSelection[8], 1);
	TextDrawBackgroundColor(ClientSelection[8], 51);
	TextDrawFont(ClientSelection[8], 0);
	TextDrawSetProportional(ClientSelection[8], 1);

	CreateLoadingTextDraws();
	return CreateBRACETMLogo();
}


stock createzombietd(playerid)
{
	tdsector++;printf("[NE:RP] - Nova Era | Ucitavanje sistema za TDove pod sektorom : %i", tdsector);
	ZombieEventTextdraw[0][playerid] = CreatePlayerTextDraw(playerid, 11.111099, 147.342178, "Zombie");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[0][playerid], 0.513555, 2.023110);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[0][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[0][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[0][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[0][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[0][playerid], 1);

	ZombieEventTextdraw[1][playerid] = CreatePlayerTextDraw(playerid, 35.999893, 162.275680, "event");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[1][playerid], 0.331777, 1.122133);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[1][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[1][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[1][playerid], 3);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[1][playerid], 1);

	ZombieEventTextdraw[2][playerid] = CreatePlayerTextDraw(playerid, 80.666671, 168.255554, "usebox");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[2][playerid], 0.000000, 6.043827);
	PlayerTextDrawTextSize(playerid, ZombieEventTextdraw[2][playerid], 10.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[2][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[2][playerid], 0);
	PlayerTextDrawUseBox(playerid, ZombieEventTextdraw[2][playerid], true);
	PlayerTextDrawBoxColor(playerid, ZombieEventTextdraw[2][playerid], 102);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[2][playerid], 0);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[2][playerid], 0);

	ZombieEventTextdraw[3][playerid] = CreatePlayerTextDraw(playerid, 15.555555, 181.688888, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[3][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ZombieEventTextdraw[3][playerid], 17.333333, 17.919998);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[3][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[3][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[3][playerid], 0);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[3][playerid], 4);

	ZombieEventTextdraw[4][playerid] = CreatePlayerTextDraw(playerid, 15.555555, 204.088897, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[4][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ZombieEventTextdraw[4][playerid], 16.888887, 16.426666);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[4][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[4][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[4][playerid], 0);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[4][playerid], 4);

	ZombieEventTextdraw[5][playerid] = CreatePlayerTextDraw(playerid, 36.888912, 184.177825, "zombija");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[5][playerid], 0.198888, 1.281422);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[5][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[5][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[5][playerid], 1);

	ZombieEventTextdraw[6][playerid] = CreatePlayerTextDraw(playerid, 36.444454, 205.084426, "igraca");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[6][playerid], 0.203778, 1.137066);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[6][playerid], 1);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[6][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[6][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[6][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[6][playerid], 1);

	ZombieEventTextdraw[7][playerid] = CreatePlayerTextDraw(playerid, 23.555549, 183.182205, "10");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[7][playerid], 0.168222, 1.535288);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[7][playerid], 2);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[7][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[7][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[7][playerid], 1);

	ZombieEventTextdraw[8][playerid] = CreatePlayerTextDraw(playerid, 23.555522, 204.586639, "999");
	PlayerTextDrawLetterSize(playerid, ZombieEventTextdraw[8][playerid], 0.164666, 1.465599);
	PlayerTextDrawAlignment(playerid, ZombieEventTextdraw[8][playerid], 2);
	PlayerTextDrawColor(playerid, ZombieEventTextdraw[8][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ZombieEventTextdraw[8][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ZombieEventTextdraw[8][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ZombieEventTextdraw[8][playerid], 51);
	PlayerTextDrawFont(playerid, ZombieEventTextdraw[8][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ZombieEventTextdraw[8][playerid], 1);
	return 1;
}

stock CreatePlayerTextDraws( playerid )
{
	tdsector++;printf("[NE:RP] - Nova Era | Ucitavanje sistema za TDove pod sektorom : %i", tdsector);
	//register
	td0[playerid] = CreatePlayerTextDraw(playerid, 183.555526, 175.217819, "...");
	PlayerTextDrawLetterSize(playerid, td0[playerid], 0.352666, 1.336177);
	PlayerTextDrawAlignment(playerid, td0[playerid], 1);
	PlayerTextDrawColor(playerid, td0[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td0[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td0[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td0[playerid], 51);
	PlayerTextDrawFont(playerid, td0[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td0[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td0[playerid], true);

	td1[playerid] = CreatePlayerTextDraw(playerid, 185.333343, 198.613327, "...");
	PlayerTextDrawLetterSize(playerid, td1[playerid], 0.384222, 1.236621);
	PlayerTextDrawAlignment(playerid, td1[playerid], 1);
	PlayerTextDrawColor(playerid, td1[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td1[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td1[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td1[playerid], 51);
	PlayerTextDrawFont(playerid, td1[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td1[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td1[playerid], true);

	td2[playerid] = CreatePlayerTextDraw(playerid, 195.111099, 219.022232, "...");
	PlayerTextDrawLetterSize(playerid, td2[playerid], 0.381555, 1.440711);
	PlayerTextDrawAlignment(playerid, td2[playerid], 1);
	PlayerTextDrawColor(playerid, td2[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td2[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td2[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td2[playerid], 51);
	PlayerTextDrawFont(playerid, td2[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td2[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td2[playerid], true);

	td3[playerid] = CreatePlayerTextDraw(playerid, 184.444473, 243.413330, "...");
	PlayerTextDrawLetterSize(playerid, td3[playerid], 0.368222, 1.261511);
	PlayerTextDrawAlignment(playerid, td3[playerid], 1);
	PlayerTextDrawColor(playerid, td3[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td3[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td3[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td3[playerid], 51);
	PlayerTextDrawFont(playerid, td3[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td3[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td3[playerid], true);

	td4[playerid] = CreatePlayerTextDraw(playerid, 185.777816, 264.817779, "...");
	PlayerTextDrawLetterSize(playerid, td4[playerid], 0.368666, 1.405866);
	PlayerTextDrawAlignment(playerid, td4[playerid], 1);
	PlayerTextDrawColor(playerid, td4[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td4[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td4[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td4[playerid], 51);
	PlayerTextDrawFont(playerid, td4[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td4[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td4[playerid], true);

	td5[playerid] = CreatePlayerTextDraw(playerid, 187.555511, 284.728912, "...");
	PlayerTextDrawLetterSize(playerid, td5[playerid], 0.341555, 1.530310);
	PlayerTextDrawAlignment(playerid, td5[playerid], 1);
	PlayerTextDrawColor(playerid, td5[playerid],tdboja);
	PlayerTextDrawSetShadow(playerid, td5[playerid], 0);
	PlayerTextDrawSetOutline(playerid, td5[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, td5[playerid], 51);
	PlayerTextDrawFont(playerid, td5[playerid], 2);
	PlayerTextDrawSetProportional(playerid, td5[playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, td5[playerid], true);
	//money
	playermoneytd0[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "_");
	PlayerTextDrawLetterSize(playerid, playermoneytd0[playerid], 0.201111, 1.346133);
	PlayerTextDrawAlignment(playerid, playermoneytd0[playerid], 2);
	PlayerTextDrawColor(playerid, playermoneytd0[playerid], -1);
	PlayerTextDrawSetShadow(playerid, playermoneytd0[playerid], 0);
	PlayerTextDrawSetOutline(playerid, playermoneytd0[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, playermoneytd0[playerid], 51);
	PlayerTextDrawFont(playerid, playermoneytd0[playerid], 2);
	PlayerTextDrawSetProportional(playerid, playermoneytd0[playerid], 1);
	
	//wifi
	WifiConnection[0][playerid] = CreatePlayerTextDraw(playerid, 29.110971, 397.731170, "usebox");
	PlayerTextDrawLetterSize(playerid, WifiConnection[0][playerid], 0.000000, 3.792963);
	PlayerTextDrawTextSize(playerid, WifiConnection[0][playerid], -8.222265, 0.000000);
	PlayerTextDrawAlignment(playerid, WifiConnection[0][playerid], 1);
	PlayerTextDrawColor(playerid, WifiConnection[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, WifiConnection[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, WifiConnection[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, WifiConnection[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[0][playerid], 0);
	PlayerTextDrawFont(playerid, WifiConnection[0][playerid], 0);

	WifiConnection[1][playerid] = CreatePlayerTextDraw(playerid, 4.977777, 407.182189, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, WifiConnection[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, WifiConnection[1][playerid], 2.399999, 9.706665);
	PlayerTextDrawAlignment(playerid, WifiConnection[1][playerid], 1);
	PlayerTextDrawColor(playerid, WifiConnection[1][playerid], SIVA);
	PlayerTextDrawSetShadow(playerid, WifiConnection[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[1][playerid], 0);
	PlayerTextDrawFont(playerid, WifiConnection[1][playerid], 4);

	WifiConnection[2][playerid] = CreatePlayerTextDraw(playerid, 9.333332, 404.942199, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, WifiConnection[2][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, WifiConnection[2][playerid], 2.400000, 11.946685);
	PlayerTextDrawAlignment(playerid, WifiConnection[2][playerid], 1);
	PlayerTextDrawColor(playerid, WifiConnection[2][playerid], SIVA);
	PlayerTextDrawSetShadow(playerid, WifiConnection[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[2][playerid], 0);
	PlayerTextDrawFont(playerid, WifiConnection[2][playerid], 4);

	WifiConnection[3][playerid] = CreatePlayerTextDraw(playerid, 13.688886, 402.702178, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, WifiConnection[3][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, WifiConnection[3][playerid], 2.399999, 14.186658);
	PlayerTextDrawAlignment(playerid, WifiConnection[3][playerid], 1);
	PlayerTextDrawColor(playerid, WifiConnection[3][playerid], SIVA);
	PlayerTextDrawSetShadow(playerid, WifiConnection[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[3][playerid], 0);
	PlayerTextDrawFont(playerid, WifiConnection[3][playerid], 4);

	WifiConnection[4][playerid] = CreatePlayerTextDraw(playerid, 18.222223, 400.711090, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, WifiConnection[4][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, WifiConnection[4][playerid], 3.111110, 16.426696);
	PlayerTextDrawAlignment(playerid, WifiConnection[4][playerid], 1);
	PlayerTextDrawColor(playerid, WifiConnection[4][playerid], SIVA);
	PlayerTextDrawSetShadow(playerid, WifiConnection[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[4][playerid], 0);
	PlayerTextDrawFont(playerid, WifiConnection[4][playerid], 4);

	WifiConnection[5][playerid] = CreatePlayerTextDraw(playerid, 13.777760, 418.133270, "9999 ms");
	PlayerTextDrawLetterSize(playerid, WifiConnection[5][playerid], 0.109555, 1.530310);
	PlayerTextDrawAlignment(playerid, WifiConnection[5][playerid], 2);
	PlayerTextDrawColor(playerid, WifiConnection[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, WifiConnection[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, WifiConnection[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, WifiConnection[5][playerid], 51);
	PlayerTextDrawFont(playerid, WifiConnection[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, WifiConnection[5][playerid], 1);
	//wl
	WantedIgraca[playerid] = CreatePlayerTextDraw(playerid, 556.444335, 102.542243, "");
	PlayerTextDrawLetterSize(playerid, WantedIgraca[playerid], 0.323333, 1.440711);
	PlayerTextDrawAlignment(playerid, WantedIgraca[playerid], 2);
	PlayerTextDrawColor(playerid, WantedIgraca[playerid], -2147483393);
	PlayerTextDrawSetShadow(playerid, WantedIgraca[playerid], 0);
	PlayerTextDrawSetOutline(playerid, WantedIgraca[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, WantedIgraca[playerid], 51);
	PlayerTextDrawFont(playerid, WantedIgraca[playerid], 2);
	PlayerTextDrawSetProportional(playerid, WantedIgraca[playerid], 1);
	//screen msg
	ScreenMsgTextdraw[0][playerid] = CreatePlayerTextDraw(playerid, 432.222351, 146.851181, "usebox");
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[0][playerid], 0.000000, 1.397899);
	PlayerTextDrawTextSize(playerid, ScreenMsgTextdraw[0][playerid], 192.666671, 0.000000);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[0][playerid], 1);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, ScreenMsgTextdraw[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, ScreenMsgTextdraw[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[0][playerid], 0);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[0][playerid], 0);

	ScreenMsgTextdraw[1][playerid] = CreatePlayerTextDraw(playerid, 172.888931, 137.884429, NERP_KRUG);
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ScreenMsgTextdraw[1][playerid], 31.999950, 31.359991);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[1][playerid], 1);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[1][playerid], 0);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[1][playerid], 4);

	ScreenMsgTextdraw[2][playerid] = CreatePlayerTextDraw(playerid, 182.222259, 143.359985, "N");
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[2][playerid], 0.499777, 2.043022);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[2][playerid], 1);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ScreenMsgTextdraw[2][playerid], 51);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ScreenMsgTextdraw[2][playerid], 1);

	ScreenMsgTextdraw[3][playerid] = CreatePlayerTextDraw(playerid, 420.444671, 143.360092, "LD_CHAT:badchat");
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[3][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ScreenMsgTextdraw[3][playerid], 15.555535, 18.417776);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[3][playerid], 1);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[3][playerid], 0);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[3][playerid], 4);

	ScreenMsgTextdraw[4][playerid] = CreatePlayerTextDraw(playerid, 188.888885, 144.853332, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[4][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ScreenMsgTextdraw[4][playerid], 212.000030, 1.493331);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[4][playerid], 1);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[4][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[4][playerid], 0);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[4][playerid], 4);

	ScreenMsgTextdraw[5][playerid] = CreatePlayerTextDraw(playerid, 312.444702, 148.835571, "--------------");
	PlayerTextDrawLetterSize(playerid, ScreenMsgTextdraw[5][playerid], 0.118888, 1.117156);
	PlayerTextDrawAlignment(playerid, ScreenMsgTextdraw[5][playerid], 2);
	PlayerTextDrawColor(playerid, ScreenMsgTextdraw[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ScreenMsgTextdraw[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ScreenMsgTextdraw[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ScreenMsgTextdraw[5][playerid], 51);
	PlayerTextDrawFont(playerid, ScreenMsgTextdraw[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ScreenMsgTextdraw[5][playerid], 1);
	//spec
	SpecTextdraw[0][playerid] = CreatePlayerTextDraw(playerid, 381.999938, 319.579895, "usebox");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[0][playerid], 0.000000, 6.541605);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[0][playerid], 240.222259, 0.000000);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[0][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, SpecTextdraw[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, SpecTextdraw[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[0][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[0][playerid], 0);

	SpecTextdraw[1][playerid] = CreatePlayerTextDraw(playerid, 236.444427, 291.697784, NERP_KRUG);
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[1][playerid], 24.888898, 27.377784);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[1][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[1][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[1][playerid], 4);

	SpecTextdraw[2][playerid] = CreatePlayerTextDraw(playerid, 248.444412, 298.168975, "?");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[2][playerid], 0.165999, 1.405866);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[2][playerid], 2);
	PlayerTextDrawColor(playerid, SpecTextdraw[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[2][playerid], 51);
	PlayerTextDrawFont(playerid, SpecTextdraw[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[2][playerid], 1);

	SpecTextdraw[3][playerid] = CreatePlayerTextDraw(playerid, 261.333343, 296.675567, "Ucitavanje imena [...]");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[3][playerid], 0.151333, 0.898133);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[3][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[3][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[3][playerid], 51);
	PlayerTextDrawFont(playerid, SpecTextdraw[3][playerid], 2);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[3][playerid], 1);

	SpecTextdraw[4][playerid] = CreatePlayerTextDraw(playerid, 261.777709, 304.640014, "0$");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[4][playerid], 0.271777, 1.072355);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[4][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[4][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[4][playerid], 51);
	PlayerTextDrawFont(playerid, SpecTextdraw[4][playerid], 3);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[4][playerid], 1);

	SpecTextdraw[5][playerid] = CreatePlayerTextDraw(playerid, 246.222229, 323.555541, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[5][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[5][playerid], 63.111083, 9.955566);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[5][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[5][playerid], 255);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[5][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[5][playerid], 4);

	SpecTextdraw[6][playerid] = CreatePlayerTextDraw(playerid, 248.444442, 326.044464, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[6][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[6][playerid], 59.111114, 4.977752);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[6][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[6][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[6][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[6][playerid], 4);

	SpecTextdraw[7][playerid] = CreatePlayerTextDraw(playerid, 278.666595, 324.053283, "99.9999");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[7][playerid], 0.151333, 0.803555);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[7][playerid], 2);
	PlayerTextDrawColor(playerid, SpecTextdraw[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[7][playerid], 51);
	PlayerTextDrawFont(playerid, SpecTextdraw[7][playerid], 2);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[7][playerid], 1);

	SpecTextdraw[8][playerid] = CreatePlayerTextDraw(playerid, 331.333343, 338.495574, "usebox");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[8][playerid], 0.000000, 3.997403);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[8][playerid], 244.222229, 0.000000);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[8][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[8][playerid], 0);
	PlayerTextDrawUseBox(playerid, SpecTextdraw[8][playerid], true);
	PlayerTextDrawBoxColor(playerid, SpecTextdraw[8][playerid], 102);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[8][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[8][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[8][playerid], 0);

	SpecTextdraw[9][playerid] = CreatePlayerTextDraw(playerid, 249.777770, 343.466674, "hud:fist");//oruzje
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[9][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[9][playerid], 73.333343, 24.888885);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[9][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[9][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[9][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[9][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[9][playerid], 4);

	/*PlayerTextDrawFont(playerid, SpecTextdraw[9][playerid], 5);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[9][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, SpecTextdraw[9][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, SpecTextdraw[9][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[9][playerid], 0xFFFFFFFF00);*/

	SpecTextdraw[10][playerid] = CreatePlayerTextDraw(playerid, 259.555480, 365.866607, "0");
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[10][playerid], 0.243333, 0.942933);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[10][playerid], 2);
	PlayerTextDrawColor(playerid, SpecTextdraw[10][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[10][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[10][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[10][playerid], 51);
	PlayerTextDrawFont(playerid, SpecTextdraw[10][playerid], 3);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[10][playerid], 1);

	SpecTextdraw[11][playerid] = CreatePlayerTextDraw(playerid, 335.111114, 321.564453, "LD_SPAC:white");//skin
	PlayerTextDrawLetterSize(playerid, SpecTextdraw[11][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SpecTextdraw[11][playerid], 40.888885, 52.266662);
	PlayerTextDrawAlignment(playerid, SpecTextdraw[11][playerid], 1);
	PlayerTextDrawColor(playerid, SpecTextdraw[11][playerid], -1);
	PlayerTextDrawSetShadow(playerid, SpecTextdraw[11][playerid], 0);
	PlayerTextDrawSetOutline(playerid, SpecTextdraw[11][playerid], 0);
	PlayerTextDrawFont(playerid, SpecTextdraw[11][playerid], 4);

	PlayerTextDrawFont(playerid, SpecTextdraw[11][playerid], 5);
	PlayerTextDrawSetProportional(playerid, SpecTextdraw[11][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, SpecTextdraw[11][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, SpecTextdraw[11][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, SpecTextdraw[11][playerid], 0xFFFFFFFF00);
	//pare
	MoneyBar[playerid] = CreatePlayerTextDraw(playerid, 499.000000, 75.662246, "$000000000");
	PlayerTextDrawLetterSize(playerid, MoneyBar[playerid], 0.522888, 2.461156);
	PlayerTextDrawAlignment(playerid, MoneyBar[playerid], 1);
	PlayerTextDrawColor(playerid, MoneyBar[playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, MoneyBar[playerid], 0);
	PlayerTextDrawSetOutline(playerid, MoneyBar[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MoneyBar[playerid], 51);
	PlayerTextDrawFont(playerid, MoneyBar[playerid], 3);
	PlayerTextDrawSetProportional(playerid, MoneyBar[playerid], 1);
	//pubg meni
	/*PUBGTextdraw[0][playerid] = CreatePlayerTextDraw(playerid, 5.333333, 375.324462, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[0][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PUBGTextdraw[0][playerid], 109.777778, 66.204406);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[0][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[0][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[0][playerid], 0);
	PlayerTextDrawFont(playerid, PUBGTextdraw[0][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, PUBGTextdraw[0][playerid], true);

	PUBGTextdraw[1][playerid] = CreatePlayerTextDraw(playerid, 30.666706, 376.320068, "START");
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[1][playerid], 0.462444, 6.084977);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[1][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PUBGTextdraw[1][playerid], 51);
	PlayerTextDrawFont(playerid, PUBGTextdraw[1][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PUBGTextdraw[1][playerid], 1);

	PUBGTextdraw[2][playerid] = CreatePlayerTextDraw(playerid, 269.333282, 97.066665, "LD_SPAC:white");//skin
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[2][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PUBGTextdraw[2][playerid], 168.000000, 289.208923);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[2][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[2][playerid], 0);
	PlayerTextDrawFont(playerid, PUBGTextdraw[2][playerid], 4);

	PlayerTextDrawFont(playerid, PUBGTextdraw[2][playerid], 5);
	PlayerTextDrawSetProportional(playerid, PUBGTextdraw[2][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, PUBGTextdraw[2][playerid], 1277);
	PlayerTextDrawSetPreviewRot(playerid, PUBGTextdraw[2][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, PUBGTextdraw[2][playerid], 0xFFFFFFFF00);

	PUBGTextdraw[3][playerid] = CreatePlayerTextDraw(playerid, 116.666641, 334.015563, "usebox");
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[3][playerid], 0.000000, 3.665555);
	PlayerTextDrawTextSize(playerid, PUBGTextdraw[3][playerid], 2.888895, 0.000000);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[3][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[3][playerid], 0);
	PlayerTextDrawUseBox(playerid, PUBGTextdraw[3][playerid], true);
	PlayerTextDrawBoxColor(playerid, PUBGTextdraw[3][playerid], 102);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[3][playerid], 0);
	PlayerTextDrawFont(playerid, PUBGTextdraw[3][playerid], 0);

	PUBGTextdraw[4][playerid] = CreatePlayerTextDraw(playerid, 32.444469, 340.479888, "Vratite se na pocetni~n~meni za odabir moda.");
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[4][playerid], 0.152222, 1.082310);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[4][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PUBGTextdraw[4][playerid], 51);
	PlayerTextDrawFont(playerid, PUBGTextdraw[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PUBGTextdraw[4][playerid], 1);

	PUBGTextdraw[5][playerid] = CreatePlayerTextDraw(playerid, 7.555555, 335.502227, "LD_BEAT:LEFT");
	PlayerTextDrawLetterSize(playerid, PUBGTextdraw[5][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PUBGTextdraw[5][playerid], 22.666667, 31.360015);
	PlayerTextDrawAlignment(playerid, PUBGTextdraw[5][playerid], 1);
	PlayerTextDrawColor(playerid, PUBGTextdraw[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PUBGTextdraw[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PUBGTextdraw[5][playerid], 0);
	PlayerTextDrawFont(playerid, PUBGTextdraw[5][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, PUBGTextdraw[5][playerid], true);*/
	//odjeca
	OdjecaTextdraw[0][playerid] = CreatePlayerTextDraw(playerid, 436.666809, 154.317825, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[0][playerid], 0.000000, 11.161857);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[0][playerid], 198.888900, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[0][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[0][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[0][playerid], 0);

	OdjecaTextdraw[1][playerid] = CreatePlayerTextDraw(playerid, 204.000000, 139.875579, "Dodaci na odjeci");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[1][playerid], 0.497999, 2.366577);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[1][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[1][playerid], 51);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[1][playerid], 1);

	OdjecaTextdraw[2][playerid] = CreatePlayerTextDraw(playerid, 149.777954, 162.773361, NERP_KRUG);
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[2][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[2][playerid], 305.778167, 2.488870);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[2][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[2][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[2][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[2][playerid], 4);

	OdjecaTextdraw[3][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 178.708892, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[3][playerid], 0.000000, 5.822591);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[3][playerid], 205.111114, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[3][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[3][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[3][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[3][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[3][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[3][playerid], 0);

	OdjecaTextdraw[4][playerid] = CreatePlayerTextDraw(playerid, 320.666656, 179.206665, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[4][playerid], 0.000000, 5.767283);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[4][playerid], 262.888885, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[4][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[4][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[4][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[4][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[4][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[4][playerid], 0);

	OdjecaTextdraw[5][playerid] = CreatePlayerTextDraw(playerid, 376.222229, 179.704437, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[5][playerid], 0.000000, 5.546050);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[5][playerid], 324.666687, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[5][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[5][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[5][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[5][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[5][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[5][playerid], 0);

	OdjecaTextdraw[6][playerid] = CreatePlayerTextDraw(playerid, 429.111145, 180.202224, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[6][playerid], 0.000000, 5.435433);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[6][playerid], 376.222229, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[6][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[6][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[6][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[6][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[6][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[6][playerid], 0);

	OdjecaTextdraw[7][playerid] = CreatePlayerTextDraw(playerid, 415.111145, 152.817794, "X");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[7][playerid], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[7][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[7][playerid], 51);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[7][playerid], 2);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[7][playerid], true);

	OdjecaTextdraw[8][playerid] = CreatePlayerTextDraw(playerid, 428.222381, 240.433319, "usebox");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[8][playerid], 0.000000, 1.066050);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[8][playerid], 352.666809, 0.000000);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[8][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[8][playerid], 0);
	PlayerTextDrawUseBox(playerid, OdjecaTextdraw[8][playerid], true);
	PlayerTextDrawBoxColor(playerid, OdjecaTextdraw[8][playerid], 102);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[8][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[8][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[8][playerid], 0);

	OdjecaTextdraw[9][playerid] = CreatePlayerTextDraw(playerid, 369.777862, 239.928878, "Stavi sve");
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[9][playerid], 0.241111, 1.017600);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[9][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[9][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[9][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[9][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[9][playerid], 51);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[9][playerid], 1);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[9][playerid], true);

	OdjecaTextdraw[10][playerid] = CreatePlayerTextDraw(playerid, 209.777770, 179.697784, "LD_SPAC:white");//sesir
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[10][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[10][playerid], 48.888885, 51.768875);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[10][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[10][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[10][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[10][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[10][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[10][playerid], true);

	PlayerTextDrawFont(playerid, OdjecaTextdraw[10][playerid], 5);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[10][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, OdjecaTextdraw[10][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[10][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[10][playerid], 0xFFFFFFFF00);

	OdjecaTextdraw[11][playerid] = CreatePlayerTextDraw(playerid, 266.666656, 179.199996, "LD_SPAC:white");//naocale
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[11][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[11][playerid], 49.333343, 51.271133);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[11][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[11][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[11][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[11][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[11][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[11][playerid], true);

	PlayerTextDrawFont(playerid, OdjecaTextdraw[11][playerid], 5);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[11][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, OdjecaTextdraw[11][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[11][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[11][playerid], 0xFFFFFFFF00);

	OdjecaTextdraw[12][playerid] = CreatePlayerTextDraw(playerid, 328.000000, 180.195556, "LD_SPAC:white");//bandana
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[12][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[12][playerid], 44.444458, 48.782226);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[12][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[12][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[12][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[12][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[12][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[12][playerid], true);

	PlayerTextDrawFont(playerid, OdjecaTextdraw[12][playerid], 5);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[12][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, OdjecaTextdraw[12][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[12][playerid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[12][playerid], 0xFFFFFFFF00);

	OdjecaTextdraw[13][playerid] = CreatePlayerTextDraw(playerid, 379.555541, 180.693328, "LD_SPAC:white");//papagaj
	PlayerTextDrawLetterSize(playerid, OdjecaTextdraw[13][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OdjecaTextdraw[13][playerid], 45.777770, 47.786666);
	PlayerTextDrawAlignment(playerid, OdjecaTextdraw[13][playerid], 1);
	PlayerTextDrawColor(playerid, OdjecaTextdraw[13][playerid], -1);
	PlayerTextDrawSetShadow(playerid, OdjecaTextdraw[13][playerid], 0);
	PlayerTextDrawSetOutline(playerid, OdjecaTextdraw[13][playerid], 0);
	PlayerTextDrawFont(playerid, OdjecaTextdraw[13][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, OdjecaTextdraw[13][playerid], true);

	PlayerTextDrawFont(playerid, OdjecaTextdraw[13][playerid], 5);
	PlayerTextDrawSetProportional(playerid, OdjecaTextdraw[13][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, OdjecaTextdraw[13][playerid], 18631);
	PlayerTextDrawSetPreviewRot(playerid, OdjecaTextdraw[13][playerid], 0.0, 0.0, 0.0, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, OdjecaTextdraw[13][playerid], 0xFFFFFFFF00);
	//tut
	TutorijalTD[0][playerid] = CreatePlayerTextDraw(playerid, 311.500000, 183.062500, 
			"usebox");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[0][playerid], 0.000000, 14.913890);
	PlayerTextDrawTextSize(playerid, TutorijalTD[0][playerid], -2.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, TutorijalTD[0][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, TutorijalTD[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, TutorijalTD[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[0][playerid], 0);
	PlayerTextDrawFont(playerid, TutorijalTD[0][playerid], 0);

	TutorijalTD[1][playerid] = CreatePlayerTextDraw(playerid, 16.000000, 161.875000, 
		"Dobrodosli!");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[1][playerid], 0.964500, 3.240625);
	PlayerTextDrawAlignment(playerid, TutorijalTD[1][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[1][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[1][playerid], 1);

	TutorijalTD[2][playerid] = CreatePlayerTextDraw(playerid, 21.000000, 193.375000, 
		"]]]]]]]]]]]]]");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[2][playerid], 0.165499, 0.685625);
	PlayerTextDrawAlignment(playerid, TutorijalTD[2][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[2][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[2][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[2][playerid], 1);

	TutorijalTD[3][playerid] = CreatePlayerTextDraw(playerid, 14.000000, 207.375000, 
		"Prije svega - dobro nam dosli na Nova Era Online Gaming Community!");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[3][playerid], 0.224500, 1.193124);
	PlayerTextDrawAlignment(playerid, TutorijalTD[3][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[3][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[3][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[3][playerid], 1);

	TutorijalTD[4][playerid] = CreatePlayerTextDraw(playerid, 14.500000, 223.562500, 
		"Sada slijedi kratak tutorial/uvod u server.");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[4][playerid], 0.223999, 1.232500);
	PlayerTextDrawAlignment(playerid, TutorijalTD[4][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[4][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[4][playerid], 1);

	TutorijalTD[5][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 240.187500, 
		"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[5][playerid], 0.225000, 1.206250);
	PlayerTextDrawAlignment(playerid, TutorijalTD[5][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[5][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[5][playerid], 1);

	TutorijalTD[6][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 257.687500, 
		"Da ne duzimo mnogo ostanite sa nama do kraja tutorijala.");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[6][playerid], 0.224499, 1.197501);
	PlayerTextDrawAlignment(playerid, TutorijalTD[6][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[6][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[6][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[6][playerid], 1);

	TutorijalTD[7][playerid] = CreatePlayerTextDraw(playerid, 13.000000, 274.312500, 
		"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[7][playerid], 0.224999, 1.250001);
	PlayerTextDrawAlignment(playerid, TutorijalTD[7][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[7][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[7][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[7][playerid], 1);

	TutorijalTD[8][playerid] = CreatePlayerTextDraw(playerid, 12.000000, 290.500000, 
		"Nova Era Community Staff team.");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	PlayerTextDrawLetterSize(playerid, TutorijalTD[8][playerid], 0.225999, 1.254374);
	PlayerTextDrawAlignment(playerid, TutorijalTD[8][playerid], 1);
	PlayerTextDrawColor(playerid, TutorijalTD[8][playerid], -1);
	PlayerTextDrawSetShadow(playerid, TutorijalTD[8][playerid], 0);
	PlayerTextDrawSetOutline(playerid, TutorijalTD[8][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TutorijalTD[8][playerid], 51);
	PlayerTextDrawFont(playerid, TutorijalTD[8][playerid], 1);
	PlayerTextDrawSetProportional(playerid, TutorijalTD[8][playerid], 1);
	//weaps
	OruzjeIgraca[playerid][0] = CreatePlayerTextDraw(playerid, 503.000000, 307.750000, "usebox");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][0], 0.000000, 6.294444);
	PlayerTextDrawTextSize(playerid, OruzjeIgraca[playerid][0], 637.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][0], 1);
	PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, OruzjeIgraca[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, OruzjeIgraca[playerid][0], 102);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][0], 0);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][0], 0);

	OruzjeIgraca[playerid][1] = CreatePlayerTextDraw(playerid, 506.000000, 320.687500, "hud:fist");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, OruzjeIgraca[playerid][1], 95.000000, 39.812500);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][1], 0);
	//PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][1], 0);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][1], 4);
	PlayerTextDrawBackgroundColor(pid,OruzjeIgraca[playerid][1], 0xFFFFFFFF00);
	//PlayerTextDrawSetPreviewModel(pid,OruzjeIgraca[playerid][1], 294);
	//PlayerTextDrawSetPreviewRot(pid,OruzjeIgraca[playerid][1], 0.000000, 0.000000, 30.000000, -2.000000);

	
	/*OruzjeIgraca1[pid] = CreatePlayerTextDraw(pid,501.333343, 28.871110, "");
		PlayerTextDrawTextSize(pid,OruzjeIgraca1[pid], 40.000030, 35.840003);
		PlayerTextDrawAlignment(pid,OruzjeIgraca1[pid], 0);
		PlayerTextDrawBackgroundColor(pid,OruzjeIgraca1[pid], 0xFFFFFFFF00);
		PlayerTextDrawSetShadow(pid,OruzjeIgraca1[pid], 0);
		PlayerTextDrawFont(pid,OruzjeIgraca1[pid], 5);
		PlayerTextDrawSetProportional(pid,OruzjeIgraca1[pid], 0);
		PlayerTextDrawSetPreviewModel(pid,OruzjeIgraca1[pid], 294);
		PlayerTextDrawSetPreviewRot(pid,OruzjeIgraca1[pid], 0.000000, 0.000000, 0.000000, 1.000000);
		PlayerTextDrawSetSelectable(pid,OruzjeIgraca1[pid], true);*/

	OruzjeIgraca[playerid][2] = CreatePlayerTextDraw(playerid, 506.000000, 298.375000, "Kar-98 k");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][2], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][2], 1);
	PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][2], tdboja);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, OruzjeIgraca[playerid][2], 51);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][2], 3);
	PlayerTextDrawSetProportional(playerid, OruzjeIgraca[playerid][2], 1);

	OruzjeIgraca[playerid][3] = CreatePlayerTextDraw(playerid, 608.000000, 310.187500, "Ammo:");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][3], 0.216500, 1.236875);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][3], 1);
	PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, OruzjeIgraca[playerid][3], 51);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, OruzjeIgraca[playerid][3], 1);

	OruzjeIgraca[playerid][4] = CreatePlayerTextDraw(playerid, 610.500000, 331.187500, "69");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][4], 0.216500, 1.236875);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][4], 1);
	PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, OruzjeIgraca[playerid][4], 51);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, OruzjeIgraca[playerid][4], 1);

	OruzjeIgraca[playerid][5] = CreatePlayerTextDraw(playerid, 550.000000, 351.750000, ".300 Magnum");
	PlayerTextDrawLetterSize(playerid, OruzjeIgraca[playerid][5], 0.372999, 1.359374);
	PlayerTextDrawAlignment(playerid, OruzjeIgraca[playerid][5], 2);
	PlayerTextDrawColor(playerid, OruzjeIgraca[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, OruzjeIgraca[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, OruzjeIgraca[playerid][5], 1);
	PlayerTextDrawBackgroundColor(playerid, OruzjeIgraca[playerid][5], 51);
	PlayerTextDrawFont(playerid, OruzjeIgraca[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, OruzjeIgraca[playerid][5], 1);

	//stats
	PlayerStats[0] [playerid] = CreatePlayerTextDraw(playerid, 448.666687, 152.326675, "usebox");
	PlayerTextDrawLetterSize(playerid, PlayerStats[0] [playerid], 0.000000, 17.935182);
	PlayerTextDrawTextSize(playerid, PlayerStats[0] [playerid], 169.555557, 0.000000);
	PlayerTextDrawAlignment(playerid, PlayerStats[0] [playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[0] [playerid], 0);
	PlayerTextDrawUseBox(playerid, PlayerStats[0] [playerid], true);
	PlayerTextDrawBoxColor(playerid, PlayerStats[0] [playerid], 102);
	PlayerTextDrawSetShadow(playerid, PlayerStats[0] [playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[0] [playerid], 0);
	PlayerTextDrawFont(playerid, PlayerStats[0] [playerid], 0);

	PlayerStats[1] [playerid] = CreatePlayerTextDraw(playerid, 172.444412, 133.404403, "Vasa statistika");
	PlayerTextDrawLetterSize(playerid, PlayerStats[1] [playerid], 0.634444, 3.272533);
	PlayerTextDrawAlignment(playerid, PlayerStats[1] [playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[1] [playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, PlayerStats[1] [playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[1] [playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[1] [playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[1] [playerid], 0);
	PlayerTextDrawSetProportional(playerid, PlayerStats[1] [playerid], 1);

	PlayerStats[2] [playerid] = CreatePlayerTextDraw(playerid, 108.000045, 170.240020, NERP_KRUG);
	PlayerTextDrawLetterSize(playerid, PlayerStats[2] [playerid], -0.045333, -0.099555);
	PlayerTextDrawTextSize(playerid, PlayerStats[2] [playerid], 402.222167, 2.488878);
	PlayerTextDrawAlignment(playerid, PlayerStats[2] [playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[2] [playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, PlayerStats[2] [playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[2] [playerid], 0);
	PlayerTextDrawFont(playerid, PlayerStats[2] [playerid], 4);

	PlayerStats[3][playerid] = CreatePlayerTextDraw(playerid, 179.111145, 178.204452, 
		"Ucitavanje...");//"level: 1~n~respekti: 1~n~online sati: 1~n~upozorenja: 1~n~admin lvl: 1~n~gm lvl: 1~n~vip lvl: 1~n~promoter: 1~n~rp poeni: 1");
	PlayerTextDrawLetterSize(playerid, PlayerStats[3][playerid], 0.163777, 0.838400);
	PlayerTextDrawAlignment(playerid, PlayerStats[3][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[3][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[3][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[3][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[3][playerid], 1);

	PlayerStats[4][playerid] = CreatePlayerTextDraw(playerid, 179.111160, 246.897735, 
		"Ucitavanje...");//"apoeni: 1~n~posao: raspali motokultivator~n~ugovor: 37h~n~do plate: 73723h~n~novac: 128762187$~n~banka: 128762187$");
	PlayerTextDrawLetterSize(playerid, PlayerStats[4][playerid], 0.135777, 0.947910);
	PlayerTextDrawAlignment(playerid, PlayerStats[4][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[4][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[4][playerid], 1);

	PlayerStats[5][playerid] = CreatePlayerTextDraw(playerid, 256.000000, 177.208892, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerStats[5][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerStats[5][playerid], 0.888885, 127.431121);
	PlayerTextDrawAlignment(playerid, PlayerStats[5][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[5][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, PlayerStats[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[5][playerid], 0);
	PlayerTextDrawFont(playerid, PlayerStats[5][playerid], 4);

	PlayerStats[6][playerid] = CreatePlayerTextDraw(playerid, 263.111053, 178.702209, 
		"Ucitavanje...");//"zlato: 999999g~n~materijali: 9999~n~tel br: 999999~n~brak: ~n~~y~mustafa_kulovac~n~hapsenja: 999");
	PlayerTextDrawLetterSize(playerid, PlayerStats[6][playerid], 0.149111, 0.694044);
	PlayerTextDrawAlignment(playerid, PlayerStats[6][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[6][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[6][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[6][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[6][playerid], 1);

	PlayerStats[7][playerid] = CreatePlayerTextDraw(playerid, 264.444427, 219.519958, 
		"Ucitavanje...");//"organizacija:~n~~y~saobracajna policija~n~~w~org rank: 6~n~org kazna: 7h");
	PlayerTextDrawLetterSize(playerid, PlayerStats[7][playerid], 0.146444, 0.878222);
	PlayerTextDrawAlignment(playerid, PlayerStats[7][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[7][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[7][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[7][playerid], 1);

	PlayerStats[8][playerid] = CreatePlayerTextDraw(playerid, 264.888977, 254.862289, 
		"Ucitavanje...");//"vozilo 1: nema~n~vozilo 2: nema~n~vozilo 3: nema~n~vozilo 4: nema~n~");
	PlayerTextDrawLetterSize(playerid, PlayerStats[8][playerid], 0.163777, 0.778666);
	PlayerTextDrawAlignment(playerid, PlayerStats[8][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[8][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[8][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[8][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[8][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[8][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[8][playerid], 1);

	PlayerStats[9][playerid] = CreatePlayerTextDraw(playerid, 348.444458, 178.702224, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerStats[9][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerStats[9][playerid], 0.888885, 123.946640);
	PlayerTextDrawAlignment(playerid, PlayerStats[9][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[9][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, PlayerStats[9][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[9][playerid], 0);
	PlayerTextDrawFont(playerid, PlayerStats[9][playerid], 4);

	PlayerStats[10][playerid] = CreatePlayerTextDraw(playerid, 358.222259, 179.200057, 
		"Ucitavanje...");//"imovina 1: nema~n~imovina 2: nema~n~imovina 3: nema");
	PlayerTextDrawLetterSize(playerid, PlayerStats[10][playerid], 0.164222, 0.803555);
	PlayerTextDrawAlignment(playerid, PlayerStats[10][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[10][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[10][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[10][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[10][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[10][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[10][playerid], 1);

	PlayerStats[11][playerid] = CreatePlayerTextDraw(playerid, 359.555603, 206.080017, 
		"Ucitavanje...");//"firma: nema~n~garaza: nema~n~imanje: nema");
	PlayerTextDrawLetterSize(playerid, PlayerStats[11][playerid], 0.158444, 0.778666);
	PlayerTextDrawAlignment(playerid, PlayerStats[11][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[11][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[11][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[11][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[11][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[11][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[11][playerid], 1);

	SkinIgraca[playerid] = CreatePlayerTextDraw(playerid, 367.111145, 243.911102, "LD_SPAC:white");
	//PlayerTextDrawLetterSize(playerid, SkinIgraca[playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, SkinIgraca[playerid], 56.444427, 59.733337);
	PlayerTextDrawAlignment(playerid, SkinIgraca[playerid], 0);
	PlayerTextDrawBackgroundColor(pid,SkinIgraca[pid], 0xFFFFFFFF00);
	//PlayerTextDrawColor(playerid, SkinIgraca[playerid], -1);
	PlayerTextDrawSetShadow(playerid, SkinIgraca[playerid], 0);
	//PlayerTextDrawSetOutline(playerid, SkinIgraca[playerid], 0);
	PlayerTextDrawFont(playerid, SkinIgraca[playerid], 5);
	PlayerTextDrawSetProportional(pid,SkinIgraca[pid], 0);
	PlayerTextDrawSetPreviewModel(pid,SkinIgraca[pid], 294);
	PlayerTextDrawSetPreviewRot(pid,SkinIgraca[pid], 0.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawSetSelectable(pid,SkinIgraca[pid], true);

	NickIgraca[playerid] = CreatePlayerTextDraw(playerid, 296.000000, 148.337875, "Ucitavanje...");
	PlayerTextDrawLetterSize(playerid, NickIgraca[playerid], 0.211333, 1.311288);
	PlayerTextDrawAlignment(playerid, NickIgraca[playerid], 1);
	PlayerTextDrawColor(playerid, NickIgraca[playerid], -1);
	PlayerTextDrawSetShadow(playerid, NickIgraca[playerid], 0);
	PlayerTextDrawSetOutline(playerid, NickIgraca[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, NickIgraca[playerid], 51);
	PlayerTextDrawFont(playerid, NickIgraca[playerid], 3);
	PlayerTextDrawSetProportional(playerid, NickIgraca[playerid], 1);

	PlayerStats[14][playerid] = CreatePlayerTextDraw(playerid, 289.333343, 144.355575, ".");
	PlayerTextDrawLetterSize(playerid, PlayerStats[14][playerid], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, PlayerStats[14][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[14][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[14][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[14][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[14][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[14][playerid], 1);
	PlayerTextDrawSetProportional(playerid, PlayerStats[14][playerid], 1);

	PlayerStats[15][playerid] = CreatePlayerTextDraw(playerid, 430.666473, 150.826614, "X");
	PlayerTextDrawLetterSize(playerid, PlayerStats[15][playerid], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, PlayerStats[15][playerid], 1);
	PlayerTextDrawColor(playerid, PlayerStats[15][playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerStats[15][playerid], 0);
	PlayerTextDrawSetOutline(playerid, PlayerStats[15][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerStats[15][playerid], 51);
	PlayerTextDrawFont(playerid, PlayerStats[15][playerid], 2);
	PlayerTextDrawSetProportional(playerid, PlayerStats[15][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerStats[15][playerid], 1);
	// HEALTH BAR pid,phealthbar0[pid]
	Notification[0][playerid] = CreatePlayerTextDraw(playerid, 504.221954, 113.002189, "usebox");
	PlayerTextDrawLetterSize(playerid, Notification[0][playerid], 0.000000, 1.981606);
	PlayerTextDrawTextSize(playerid, Notification[0][playerid], 634.444396, 0.000000);
	PlayerTextDrawAlignment(playerid, Notification[0][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, Notification[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, Notification[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, Notification[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, Notification[0][playerid], 0);
	PlayerTextDrawFont(playerid, Notification[0][playerid], 0);

	Notification[1][playerid] = CreatePlayerTextDraw(playerid, 485.777740, 103.040000, NERP_KRUG);
	PlayerTextDrawLetterSize(playerid, Notification[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, Notification[1][playerid], 34.666683, 38.328903);
	PlayerTextDrawAlignment(playerid, Notification[1][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, Notification[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, Notification[1][playerid], 0);
	PlayerTextDrawFont(playerid, Notification[1][playerid], 4);

	Notification[2][playerid] = CreatePlayerTextDraw(playerid, 495.999877, 111.004425, "N");
	PlayerTextDrawLetterSize(playerid, Notification[2][playerid], 0.542000, 2.062933);
	PlayerTextDrawAlignment(playerid, Notification[2][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, Notification[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, Notification[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, Notification[2][playerid], 51);
	PlayerTextDrawFont(playerid, Notification[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, Notification[2][playerid], 1);

	Notification[3][playerid] = CreatePlayerTextDraw(playerid, 503.999786, 103.537712, "ld_chat:badchat");
	PlayerTextDrawLetterSize(playerid, Notification[3][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, Notification[3][playerid], 9.777732, 10.951116);
	PlayerTextDrawAlignment(playerid, Notification[3][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, Notification[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, Notification[3][playerid], 0);
	PlayerTextDrawFont(playerid, Notification[3][playerid], 4);

	Notification[4][playerid] = CreatePlayerTextDraw(playerid, 518.222473, 114.488960, "Ucitavanje...");//"Mjesto za tekst, mjesto za tekst,~n~Mjesto za tekst, mjesto za tekst.");
	PlayerTextDrawLetterSize(playerid, Notification[4][playerid], 0.138888, 0.848356);
	PlayerTextDrawAlignment(playerid, Notification[4][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, Notification[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, Notification[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, Notification[4][playerid], 51);
	PlayerTextDrawFont(playerid, Notification[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, Notification[4][playerid], 1);
	//REISTRACIJA
	
    FishermangTD[0][playerid] = CreatePlayerTextDraw(playerid, 617.000000, 253.500000, "usebox");
	PlayerTextDrawLetterSize(playerid, FishermangTD[0][playerid], 0.000000, 2.924076);
	PlayerTextDrawTextSize(playerid, FishermangTD[0][playerid], 478.625000, 0.000000);
	PlayerTextDrawAlignment(playerid, FishermangTD[0][playerid], 1);
	PlayerTextDrawColor(playerid, FishermangTD[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, FishermangTD[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, FishermangTD[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, FishermangTD[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, FishermangTD[0][playerid], 0);
	PlayerTextDrawFont(playerid, FishermangTD[0][playerid], 0);

	FishermangTD[1][playerid] = CreatePlayerTextDraw(playerid, 546.250000, 252.583343, "~w~riba: ~r~50/50kg");
	PlayerTextDrawLetterSize(playerid, FishermangTD[1][playerid], 0.332499, 0.888332);
	PlayerTextDrawAlignment(playerid, FishermangTD[1][playerid], 2);
	PlayerTextDrawColor(playerid, FishermangTD[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, FishermangTD[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, FishermangTD[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, FishermangTD[1][playerid], 51);
	PlayerTextDrawFont(playerid, FishermangTD[1][playerid], 2);
	PlayerTextDrawSetProportional(playerid, FishermangTD[1][playerid], 1);


	LokacijaIgracaTD[ playerid ] = CreatePlayerTextDraw(playerid,89.888946, 326.048919, "Vozdovac");
	PlayerTextDrawLetterSize(playerid,LokacijaIgracaTD[ playerid ], 0.191777, 0.992711);
	PlayerTextDrawAlignment(playerid,LokacijaIgracaTD[ playerid ], 2);
	PlayerTextDrawColor(playerid,LokacijaIgracaTD[ playerid ], tdboja);
	PlayerTextDrawSetShadow(playerid,LokacijaIgracaTD[ playerid ], 0);
	PlayerTextDrawSetOutline(playerid,LokacijaIgracaTD[ playerid ], 1);
	PlayerTextDrawBackgroundColor(playerid,LokacijaIgracaTD[ playerid ], 51);
	PlayerTextDrawFont(playerid,LokacijaIgracaTD[ playerid ], 1);
	PlayerTextDrawSetProportional(playerid,LokacijaIgracaTD[ playerid ], 1);
	
	GradIgracaTD[ playerid ] = CreatePlayerTextDraw(playerid,91.555603, 312.106689, "TUNGUZOVAC");
	PlayerTextDrawLetterSize(playerid,GradIgracaTD[ playerid ], 0.215777, 0.888177);
	PlayerTextDrawAlignment(playerid,GradIgracaTD[ playerid ], 2);
	PlayerTextDrawColor(playerid,GradIgracaTD[ playerid ], tdboja);
	PlayerTextDrawUseBox(playerid,GradIgracaTD[ playerid ], true);
	PlayerTextDrawBoxColor(playerid,GradIgracaTD[ playerid ], 0);
	PlayerTextDrawSetShadow(playerid,GradIgracaTD[ playerid ], 0);
	PlayerTextDrawSetOutline(playerid,GradIgracaTD[ playerid ], 1);
	PlayerTextDrawBackgroundColor(playerid,GradIgracaTD[ playerid ], 102);
	PlayerTextDrawFont(playerid,GradIgracaTD[ playerid ], 3);
	PlayerTextDrawSetProportional(playerid,GradIgracaTD[ playerid ], 1);
	
	RadarCol[ playerid ] = CreatePlayerTextDraw( playerid, -5.000, -2.000, "~n~");
    PlayerTextDrawFont(playerid, RadarCol[ playerid ], 3);
    PlayerTextDrawUseBox(playerid, RadarCol[ playerid ], 1);
    PlayerTextDrawLetterSize(playerid, RadarCol[ playerid ], 0.500000, 50.300003);
    PlayerTextDrawBoxColor(playerid, RadarCol[ playerid ], 0xFF0000FF);
    PlayerTextDrawTextSize(playerid, RadarCol[ playerid ], 655.000, 625.000);
    PlayerTextDrawColor(playerid, RadarCol[ playerid ], -1);
	
	GladIgraca[ playerid ] = CreatePlayerTextDraw(playerid, 566.222290, 55.751094, "73");//glad broj
	PlayerTextDrawLetterSize(playerid, GladIgraca[ playerid ], 0.137555, 0.753777);
	PlayerTextDrawAlignment(playerid, GladIgraca[ playerid ], 2);
	PlayerTextDrawColor(playerid, GladIgraca[ playerid ], -1);
	PlayerTextDrawSetShadow(playerid, GladIgraca[ playerid ], 0);
	PlayerTextDrawSetOutline(playerid, GladIgraca[ playerid ], 1);
	PlayerTextDrawBackgroundColor(playerid, GladIgraca[ playerid ], 51);
	PlayerTextDrawFont(playerid, GladIgraca[ playerid ], 2);
	PlayerTextDrawSetProportional(playerid, GladIgraca[ playerid ], 1);
	
	WcIgraca[ playerid ] = CreatePlayerTextDraw(playerid, 586.778015, 55.755542, "73");//wc broj
	PlayerTextDrawLetterSize(playerid, WcIgraca[ playerid ], 0.137555, 0.753777);
	PlayerTextDrawAlignment(playerid, WcIgraca[ playerid ], 2);
	PlayerTextDrawColor(playerid, WcIgraca[ playerid ], -1);
	PlayerTextDrawSetShadow(playerid, WcIgraca[ playerid ], 0);
	PlayerTextDrawSetOutline(playerid, WcIgraca[ playerid ], 1);
	PlayerTextDrawBackgroundColor(playerid, WcIgraca[ playerid ], 51);
	PlayerTextDrawFont(playerid, WcIgraca[ playerid ], 2);
	PlayerTextDrawSetProportional(playerid, WcIgraca[ playerid ], 1);
	


	Textdraw0[playerid] = CreatePlayerTextDraw(playerid, 495.555572, 99.555549, "");

	Textdraw1[playerid] = CreatePlayerTextDraw(playerid, 484.444610, 92.088912, "");

	Textdraw2[playerid] = CreatePlayerTextDraw(playerid, 487.111389, 94.577789, "");

	Textdraw3[playerid] = CreatePlayerTextDraw(playerid, 494.222320, 98.560005, "");

	Textdraw4[playerid] = CreatePlayerTextDraw(playerid, 554.222351, 92.088867, "");

	Textdraw5[playerid] = CreatePlayerTextDraw(playerid, 556.444091, 94.577766, "");

	Textdraw6[playerid] = CreatePlayerTextDraw(playerid, 564.444396, 100.551177, "");

	
	//
    PlayerGpsRadarText[ playerid ] = CreatePlayerTextDraw(playerid,320.000000, 380.000000, "Udaljenost: 0.0 metara~n~nigde");
	PlayerTextDrawAlignment(playerid,PlayerGpsRadarText[ playerid ], 2);
	PlayerTextDrawBackgroundColor(playerid,PlayerGpsRadarText[ playerid ], 255);
	PlayerTextDrawFont(playerid,PlayerGpsRadarText[ playerid ], 2);
	PlayerTextDrawLetterSize(playerid,PlayerGpsRadarText[ playerid ], 0.370000, 0.799999);
	PlayerTextDrawColor(playerid,PlayerGpsRadarText[ playerid ], -1);
	PlayerTextDrawSetOutline(playerid,PlayerGpsRadarText[ playerid ], 0);
	PlayerTextDrawSetProportional(playerid,PlayerGpsRadarText[ playerid ], 1);
	PlayerTextDrawSetShadow(playerid,PlayerGpsRadarText[ playerid ], 1);
	PlayerTextDrawSetSelectable(playerid,PlayerGpsRadarText[ playerid ], 0);
	PlayerTextDrawHide(playerid, PlayerGpsRadarText[ playerid ] );
	
	/////JAIL TD
	JailTD[playerid] = CreatePlayerTextDraw(playerid, 316.444580, 27.377779, "~r~Do slobode: ~w~20 ~r~min");
	PlayerTextDrawLetterSize(playerid, JailTD[playerid], 0.341555, 1.385954);
	PlayerTextDrawAlignment(playerid, JailTD[playerid], 2);
	PlayerTextDrawColor(playerid, JailTD[playerid], -16776961);
	PlayerTextDrawSetShadow(playerid, JailTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, JailTD[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, JailTD[playerid], 51);
	PlayerTextDrawFont(playerid, JailTD[playerid], 3);
	PlayerTextDrawSetProportional(playerid, JailTD[playerid], 1);
	//================================================================

	new Float:BRZINOMJER_OFFSET = -2.5;

	KILOMETARSATTD[playerid][0] = CreatePlayerTextDraw(playerid, 660.000000, 305.562500 + BRZINOMJER_OFFSET, "usebox");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][0], 0.000000, 9.301394);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][0], 498.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, KILOMETARSATTD[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, KILOMETARSATTD[playerid][0], 102);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][0], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][0], 0);

	KILOMETARSATTD[playerid][1] = CreatePlayerTextDraw(playerid, 507.000000, 319.375000 + BRZINOMJER_OFFSET, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][1], 1.500000, 56.437500);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][1], tdboja);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][1], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][1], 4);

	KILOMETARSATTD[playerid][2] = CreatePlayerTextDraw(playerid, 507.000000, 319.375000 + BRZINOMJER_OFFSET, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][2], 75.500000, 1.750000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][2], tdboja);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][2], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][2], 4);

	KILOMETARSATTD[playerid][3] = CreatePlayerTextDraw(playerid, 508.000000, 373.625000 + BRZINOMJER_OFFSET, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][3], 74.000000, 2.187500);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][3], tdboja);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][3], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][3], 4);

	KILOMETARSATTD[playerid][4] = CreatePlayerTextDraw(playerid, 580.000000, 321.125000 + BRZINOMJER_OFFSET, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][4], 2.000000, 55.125000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][4], tdboja);
	PlayerTextDrawUseBox(playerid, KILOMETARSATTD[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, KILOMETARSATTD[playerid][4], 102);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][4], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][4], 4);

	KILOMETARSATTD[playerid][5] = CreatePlayerTextDraw(playerid, 510.500000, 323.750000 + BRZINOMJER_OFFSET, "LD_SPAC:white");
	//PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][5], 67.500000, 48.125000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][5], 1);
	//PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][5], 0);
	//PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][5], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][5], 5);
	PlayerTextDrawBackgroundColor(pid,KILOMETARSATTD[playerid][5], 0xFFFFFFFF00);
	PlayerTextDrawSetPreviewModel(pid,KILOMETARSATTD[playerid][5], 294);
	PlayerTextDrawSetPreviewRot(pid,KILOMETARSATTD[playerid][5], 0.000000, 0.000000, 90.000000, 1.000000);

	KILOMETARSATTD[playerid][6] = CreatePlayerTextDraw(playerid, 586.000000, 318.937500 + BRZINOMJER_OFFSET, "Brzina");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][6], 0.167000, 0.738125);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][6], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][6], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][6], 1);

	KILOMETARSATTD[playerid][7] = CreatePlayerTextDraw(playerid, 634.500000, 328.750000 + BRZINOMJER_OFFSET, "usebox");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][7], 0.000000, 0.995833);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][7], 585.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][7], 0);
	PlayerTextDrawUseBox(playerid, KILOMETARSATTD[playerid][7], true);
	PlayerTextDrawBoxColor(playerid, KILOMETARSATTD[playerid][7], 102);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][7], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][7], 0);

	KILOMETARSATTD[playerid][8] = CreatePlayerTextDraw(playerid, 609.500000, 327.687500 + BRZINOMJER_OFFSET, "100 km/h");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][8], 0.194499, 1.018125);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][8], 2);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][8], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][8], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][8], 1);

	KILOMETARSATTD[playerid][9] = CreatePlayerTextDraw(playerid, 587.000000, 339.937500 + BRZINOMJER_OFFSET, "Rezervoar");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][9], 0.153499, 0.759999);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][9], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][9], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][9], 1);

	KILOMETARSATTD[playerid][10] = CreatePlayerTextDraw(playerid, 635.500000, 349.312500 + BRZINOMJER_OFFSET, "usebox");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][10], 0.000000, 1.093055);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][10], 585.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][10], 0);
	PlayerTextDrawUseBox(playerid, KILOMETARSATTD[playerid][10], true);
	PlayerTextDrawBoxColor(playerid, KILOMETARSATTD[playerid][10], 102);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][10], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][10], 0);

	KILOMETARSATTD[playerid][11] = CreatePlayerTextDraw(playerid, 609.000000, 349.562500 + BRZINOMJER_OFFSET, "100 l");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][11], 0.190000, 1.044375);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][11], 2);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][11], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][11], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][11], 1);

	KILOMETARSATTD[playerid][12] = CreatePlayerTextDraw(playerid, 588.000000, 360.937500 + BRZINOMJER_OFFSET, "Vrsta goriva");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][12], 0.150499, 0.751250);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][12], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][12], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][12], 2);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][12], 1);

	KILOMETARSATTD[playerid][13] = CreatePlayerTextDraw(playerid, 636.000000, 370.750000 + BRZINOMJER_OFFSET, "usebox");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][13], 0.000000, 0.995833);
	PlayerTextDrawTextSize(playerid, KILOMETARSATTD[playerid][13], 585.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][13], 0);
	PlayerTextDrawUseBox(playerid, KILOMETARSATTD[playerid][13], true);
	PlayerTextDrawBoxColor(playerid, KILOMETARSATTD[playerid][13], 102);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][13], 0);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][13], 0);

	KILOMETARSATTD[playerid][14] = CreatePlayerTextDraw(playerid, 609.000000, 371.000000 + BRZINOMJER_OFFSET, "Dizel");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][14], 0.213499, 1.004999);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][14], 2);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][14], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][14], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][14], 1);

	KILOMETARSATTD[playerid][15] = CreatePlayerTextDraw(playerid, 544.500000, 372.312500 + BRZINOMJER_OFFSET, "1000");
	PlayerTextDrawLetterSize(playerid, KILOMETARSATTD[playerid][15], 0.284000, 1.092500);
	PlayerTextDrawAlignment(playerid, KILOMETARSATTD[playerid][15], 2);
	PlayerTextDrawColor(playerid, KILOMETARSATTD[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, KILOMETARSATTD[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, KILOMETARSATTD[playerid][15], 1);
	PlayerTextDrawBackgroundColor(playerid, KILOMETARSATTD[playerid][15], 51);
	PlayerTextDrawFont(playerid, KILOMETARSATTD[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, KILOMETARSATTD[playerid][15], 1);



	
	//==========================================================================
	
	//------------------------------------------------------------------------------------
    
	new Float:TAXISTATD_OFFSET = -20.0;

	TaxistaTD[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid, 638.889282, 256.362152 + TAXISTATD_OFFSET, "usebox");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 0 ], 0.000000, 8.381603);
	PlayerTextDrawTextSize(playerid, TaxistaTD[ playerid ][ 0 ], 504.222473, 0.000000);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 0 ], 1);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 0 ], 0);
	PlayerTextDrawUseBox(playerid, TaxistaTD[ playerid ][ 0 ], true);
	PlayerTextDrawBoxColor(playerid, TaxistaTD[ playerid ][ 0 ], 102);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 0 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 0 ], 0);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 0 ], 0);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 0 ], 1);

	TaxistaTD[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid, 541.777770, 227.982269 + TAXISTATD_OFFSET, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 1 ], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TaxistaTD[ playerid ][ 1 ], 60.888923, 46.791107);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 1 ], 1);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 1 ], -1);
	PlayerTextDrawUseBox(playerid, TaxistaTD[ playerid ][ 1 ], true);
	PlayerTextDrawBoxColor(playerid, TaxistaTD[ playerid ][ 1 ], 0);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 1 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 1 ], 0);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 1 ], 5);
	PlayerTextDrawSetPreviewModel(playerid, TaxistaTD[ playerid ][ 1 ], 19311);
	PlayerTextDrawSetPreviewRot(playerid, TaxistaTD[ playerid ][ 1 ],0.000000, 0.000000, 90.000000, 1.000000);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 1 ], 0);
	

	TaxistaTD[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid, 500.889038, 255.360137 + TAXISTATD_OFFSET, "-");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 2 ], 11.557997, 1.376000);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 2 ], 1);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 2 ], tdboja);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 2 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 2 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 2 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 2 ], 2);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 2 ], 1);

	TaxistaTD[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid, 502.333618, 318.084533 + TAXISTATD_OFFSET, "-");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 3 ], 11.557997, 1.376000);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 3 ], 1);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 3 ], tdboja);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 3 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 3 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 3 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 3 ], 2);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 3 ], 1);

	TaxistaTD[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid, 571.999816, 270.293426 + TAXISTATD_OFFSET, "Cijena voznje");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 4 ], 0.318888, 0.788621);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 4 ], 2);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 4 ], tdboja);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 4 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 4 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 4 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 4 ], 3);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 4 ], 1);

	TaxistaTD[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid, 573.444274, 281.746765 + TAXISTATD_OFFSET, "20$");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 5 ], 0.318888, 0.788621);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 5 ], 2);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 5 ], -1);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 5 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 5 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 5 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 5 ], 3);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 5 ], 1);

	TaxistaTD[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid, 572.555358, 293.693481 + TAXISTATD_OFFSET, "Vasa Lokacija");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 6 ], 0.318888, 0.788621);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 6 ], 2);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 6 ], tdboja);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 6 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 6 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 6 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 6 ], 3);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 6 ], 1);

	TaxistaTD[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid, 572.666442, 308.133544 + TAXISTATD_OFFSET, "Commerce");
	PlayerTextDrawLetterSize(playerid, TaxistaTD[ playerid ][ 7 ], 0.217555, 0.928000);
	PlayerTextDrawAlignment(playerid, TaxistaTD[ playerid ][ 7 ], 2);
	PlayerTextDrawColor(playerid, TaxistaTD[ playerid ][ 7 ], -1);
	PlayerTextDrawSetShadow(playerid, TaxistaTD[ playerid ][ 7 ], 0);
	PlayerTextDrawSetOutline(playerid, TaxistaTD[ playerid ][ 7 ], 1);
	PlayerTextDrawBackgroundColor(playerid, TaxistaTD[ playerid ][ 7 ], 51);
	PlayerTextDrawFont(playerid, TaxistaTD[ playerid ][ 7 ], 3);
	PlayerTextDrawSetProportional(playerid, TaxistaTD[ playerid ][ 7 ], 1);

	MessageBox[0][playerid] = CreatePlayerTextDraw(playerid, 423.333435, 156.308898, "usebox");
	PlayerTextDrawLetterSize(playerid, MessageBox[0][playerid], 0.000000, 16.110000);
	PlayerTextDrawTextSize(playerid, MessageBox[0][playerid], 208.666656, 0.000000);
	PlayerTextDrawAlignment(playerid, MessageBox[0][playerid], 1);
	PlayerTextDrawColor(playerid, MessageBox[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, MessageBox[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, MessageBox[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, MessageBox[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[0][playerid], 0);
	PlayerTextDrawFont(playerid, MessageBox[0][playerid], 0);

	MessageBox[1][playerid] = CreatePlayerTextDraw(playerid, 207.555572, 142.364456, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, MessageBox[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, MessageBox[1][playerid], 218.666610, 17.919998);
	PlayerTextDrawAlignment(playerid, MessageBox[1][playerid], 1);
	PlayerTextDrawColor(playerid, MessageBox[1][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, MessageBox[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[1][playerid], 0);
	PlayerTextDrawFont(playerid, MessageBox[1][playerid], 4);

	MessageBox[2][playerid] = CreatePlayerTextDraw(playerid, 219.111083, 142.364532, "Naslov");
	PlayerTextDrawLetterSize(playerid, MessageBox[2][playerid], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, MessageBox[2][playerid], 1);
	PlayerTextDrawColor(playerid, MessageBox[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MessageBox[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MessageBox[2][playerid], 51);
	PlayerTextDrawFont(playerid, MessageBox[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, MessageBox[2][playerid], 1);

	MessageBox[3][playerid] = CreatePlayerTextDraw(playerid, 296.000122, 281.742248, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, MessageBox[3][playerid], -0.099111, -0.258844);
	PlayerTextDrawTextSize(playerid, MessageBox[3][playerid], 40.444435, 14.435567);
	PlayerTextDrawAlignment(playerid, MessageBox[3][playerid], 1);
	PlayerTextDrawColor(playerid, MessageBox[3][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, MessageBox[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[3][playerid], 0);
	PlayerTextDrawFont(playerid, MessageBox[3][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, MessageBox[3][playerid], true);

	MessageBox[4][playerid] = CreatePlayerTextDraw(playerid, 315.111145, 283.235534, "U REDU");
	PlayerTextDrawLetterSize(playerid, MessageBox[4][playerid], 0.181555, 1.107199);
	PlayerTextDrawAlignment(playerid, MessageBox[4][playerid], 2);
	PlayerTextDrawColor(playerid, MessageBox[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MessageBox[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MessageBox[4][playerid], 51);
	PlayerTextDrawFont(playerid, MessageBox[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, MessageBox[4][playerid], 1);
	//PlayerTextDrawSetSelectable(playerid, MessageBox[4][playerid], true);

	MessageBox[5][playerid] = CreatePlayerTextDraw(playerid, 315.110961, 175.715576-10.0, "Mjesto za text, mjesto za text, mjesto za text~n~Mjesto za text, mjesto za text, mjesto za text~n~Mjesto za text, mjesto za tex");
	PlayerTextDrawLetterSize(playerid, MessageBox[5][playerid], 0.135333, 1.003732);
	PlayerTextDrawAlignment(playerid, MessageBox[5][playerid], 2);
	PlayerTextDrawColor(playerid, MessageBox[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MessageBox[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MessageBox[5][playerid], 51);
	PlayerTextDrawFont(playerid, MessageBox[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, MessageBox[5][playerid], 1);

	MessageBox[6][playerid] = CreatePlayerTextDraw(playerid, 406.222137, 143.360000, "X");
	PlayerTextDrawLetterSize(playerid, MessageBox[6][playerid], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, MessageBox[6][playerid], 1);
	PlayerTextDrawColor(playerid, MessageBox[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MessageBox[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MessageBox[6][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MessageBox[6][playerid], 51);
	PlayerTextDrawFont(playerid, MessageBox[6][playerid], 2);
	PlayerTextDrawSetProportional(playerid, MessageBox[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MessageBox[6][playerid], true);


	DamageTextdraw[playerid] = CreatePlayerTextDraw(playerid, 351.555511, 229.475570, "-100.0");
	PlayerTextDrawLetterSize(playerid, DamageTextdraw[playerid], 0.286444, 1.047466);
	PlayerTextDrawAlignment(playerid, DamageTextdraw[playerid], 1);
	PlayerTextDrawColor(playerid, DamageTextdraw[playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, DamageTextdraw[playerid], 0);
	PlayerTextDrawSetOutline(playerid, DamageTextdraw[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, DamageTextdraw[playerid], 51);
	PlayerTextDrawFont(playerid, DamageTextdraw[playerid], 3);
	PlayerTextDrawSetProportional(playerid, DamageTextdraw[playerid], 1);

	phealthbar0[pid] = CreatePlayerTextDraw(pid,558.222167, 69.688865, "10");
	PlayerTextDrawLetterSize(pid,phealthbar0[pid], 0.142000, 0.699022);
	PlayerTextDrawAlignment(pid,phealthbar0[pid], 1);
	PlayerTextDrawColor(pid,phealthbar0[pid], -1);
	PlayerTextDrawSetShadow(pid,phealthbar0[pid], 0);
	PlayerTextDrawSetOutline(pid,phealthbar0[pid], 1);
	PlayerTextDrawBackgroundColor(pid,phealthbar0[pid], 51);
	PlayerTextDrawFont(pid,phealthbar0[pid], 2);
	PlayerTextDrawSetProportional(pid,phealthbar0[pid], 1);

	PubgEventKills[playerid] = CreatePlayerTextDraw(playerid, 596.444580, 242.417724, "0");
	PlayerTextDrawLetterSize(playerid, PubgEventKills[playerid], 0.298000, 1.530311);
	PlayerTextDrawAlignment(playerid, PubgEventKills[playerid], 1);
	PlayerTextDrawColor(playerid, PubgEventKills[playerid], -1);
	PlayerTextDrawSetShadow(playerid, PubgEventKills[playerid], 0);
	PlayerTextDrawSetOutline(playerid, PubgEventKills[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PubgEventKills[playerid], 51);
	PlayerTextDrawFont(playerid, PubgEventKills[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PubgEventKills[playerid], 1);

	ItemNearby[0][playerid] = CreatePlayerTextDraw(playerid, 483.333465, 238.442214, "usebox");
	PlayerTextDrawLetterSize(playerid, ItemNearby[0][playerid], 0.000000, 3.256666);
	PlayerTextDrawTextSize(playerid, ItemNearby[0][playerid], 382.444427, 0.000000);
	PlayerTextDrawAlignment(playerid, ItemNearby[0][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[0][playerid], 0);
	PlayerTextDrawUseBox(playerid, ItemNearby[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, ItemNearby[0][playerid], 102);
	PlayerTextDrawSetShadow(playerid, ItemNearby[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[0][playerid], 0);
	PlayerTextDrawFont(playerid, ItemNearby[0][playerid], 0);

	ItemNearby[1][playerid] = CreatePlayerTextDraw(playerid, 385.333312, 238.435546, "hud:fist");
	PlayerTextDrawLetterSize(playerid, ItemNearby[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ItemNearby[1][playerid], 28.000000, 29.866668);
	PlayerTextDrawAlignment(playerid, ItemNearby[1][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ItemNearby[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[1][playerid], 0);
	PlayerTextDrawFont(playerid, ItemNearby[1][playerid], 4);

	ItemNearby[2][playerid] = CreatePlayerTextDraw(playerid, 415.111083, 239.928970, "Combat shotgun");
	PlayerTextDrawLetterSize(playerid, ItemNearby[2][playerid], 0.184222, 1.002666);
	PlayerTextDrawAlignment(playerid, ItemNearby[2][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[2][playerid], tdboja);
	PlayerTextDrawSetShadow(playerid, ItemNearby[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ItemNearby[2][playerid], 51);
	PlayerTextDrawFont(playerid, ItemNearby[2][playerid], 3);
	PlayerTextDrawSetProportional(playerid, ItemNearby[2][playerid], 1);

	ItemNearby[3][playerid] = CreatePlayerTextDraw(playerid, 415.111083, 252.373336, "12 Guage");
	PlayerTextDrawLetterSize(playerid, ItemNearby[3][playerid], 0.202888, 0.848355);
	PlayerTextDrawAlignment(playerid, ItemNearby[3][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ItemNearby[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[3][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ItemNearby[3][playerid], 51);
	PlayerTextDrawFont(playerid, ItemNearby[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ItemNearby[3][playerid], 1);

	ItemNearby[4][playerid] = CreatePlayerTextDraw(playerid, 471.111114, 257.848846, "999");
	PlayerTextDrawLetterSize(playerid, ItemNearby[4][playerid], 0.150444, 1.057421);
	PlayerTextDrawAlignment(playerid, ItemNearby[4][playerid], 2);
	PlayerTextDrawColor(playerid, ItemNearby[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ItemNearby[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ItemNearby[4][playerid], 51);
	PlayerTextDrawFont(playerid, ItemNearby[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ItemNearby[4][playerid], 1);

	ItemNearby[5][playerid] = CreatePlayerTextDraw(playerid, 384.888946, 227.484405, "U vasoj blizini:");
	PlayerTextDrawLetterSize(playerid, ItemNearby[5][playerid], 0.167777, 0.853333);
	PlayerTextDrawAlignment(playerid, ItemNearby[5][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ItemNearby[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ItemNearby[5][playerid], 51);
	PlayerTextDrawFont(playerid, ItemNearby[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, ItemNearby[5][playerid], 1);

	ItemNearby[6][playerid] = CreatePlayerTextDraw(playerid, 483.777770, 273.286682, "usebox");
	PlayerTextDrawLetterSize(playerid, ItemNearby[6][playerid], 0.000000, 0.900120);
	PlayerTextDrawTextSize(playerid, ItemNearby[6][playerid], 382.888885, 0.000000);
	PlayerTextDrawAlignment(playerid, ItemNearby[6][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[6][playerid], 0);
	PlayerTextDrawUseBox(playerid, ItemNearby[6][playerid], true);
	PlayerTextDrawBoxColor(playerid, ItemNearby[6][playerid], 102);
	PlayerTextDrawSetShadow(playerid, ItemNearby[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[6][playerid], 0);
	PlayerTextDrawFont(playerid, ItemNearby[6][playerid], 0);

	ItemNearby[7][playerid] = CreatePlayerTextDraw(playerid, 386.666564, 271.786651, "/podignioruzje");
	PlayerTextDrawLetterSize(playerid, ItemNearby[7][playerid], 0.226888, 0.962844);
	PlayerTextDrawAlignment(playerid, ItemNearby[7][playerid], 1);
	PlayerTextDrawColor(playerid, ItemNearby[7][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ItemNearby[7][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ItemNearby[7][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ItemNearby[7][playerid], 51);
	PlayerTextDrawFont(playerid, ItemNearby[7][playerid], 3);
	PlayerTextDrawSetProportional(playerid, ItemNearby[7][playerid], 1);

	createzombietd(playerid);
	CallLocalFunction("SetupNovaSecurity", "i", playerid);
	return 1;
}
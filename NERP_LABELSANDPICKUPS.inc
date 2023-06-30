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

CreatePickupsAnd3Ds( ) 
{
	//GARAGE PICKUPS
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n{FFFFFF}Da izadjete iz prostorije, stisnite\n"col_balkanstory"F", 
		GarageCoords,
		-1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ PAKET ZA FIX VOZILA ]\n"col_white"Da kupite paket za\nfixanje vozila, kucajte:\n\n"col_balkanstory"/kupipaketzafix - 3000$", 
		2540.9734,-1541.6760,2023.5839, 
		-1, -1, 19832, 5.0 );
	//DRUG LABS PICKUPS
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n{FFFFFF}Da izadjete iz prostorije, stisnite\n"col_balkanstory"F", 
		DrugFactoryCoords,
		-1, -1, 1239, 2.0 );
	// AddPlayerClass(23,2261.4402,-1151.2351,542.5454,162.4980,0,0,0,0,0,0); // mjesto za susenje
	Create3DandP(""col_balkanstory"[ MJESTO ZA SUSENJE ]\n"col_white"Da susite drogu,\nkucajte:\n\n"col_balkanstory"/osusidrogu", 
		2261.4402,-1151.2351,542.5454, 
		-1, -1, 1239, 5.0 );
	// AddPlayerClass(23,2257.0254,-1157.7039,542.5454,50.0014,0,0,0,0,0,0); // kupovina supstanci
	Create3DandP(""col_balkanstory"[ KUPOVINA SUPSTANCI ]\n"col_white"Da kupite neke supstance,\nkucajte:\n\n"col_balkanstory"/kupisupstance", 
		2257.0254,-1157.7039,542.5454, 
		-1, -1, 1239, 5.0 );
	//2258.4045,-1146.3474,542.5454
	Create3DandP(""col_balkanstory"[ RADNI STOL ]\n"col_white"Da pravite druge vrste droge,\nkucajte:\n\n"col_balkanstory"/napravidrogu", 
		2258.4045,-1146.3474,542.5454, 
		-1, -1, 1239, 5.0 );
	//SKOK IZ AVIONA --------> 3.1570,22.9483,1199.5938
	Create3DandP(""col_balkanstory"[ SKOK U ARENU ]\n"col_white"PUBG match je poceo, ne mozete svo\nvrijeme biti u avionu.\nMorate iskociti da odigrate event,\nkucajte:\n\n"col_balkanstory"/skoci", 3.1570,22.9483,1199.5938, -1, -1, 1247, 5.0 ); 
	//creditsi
    Create3DTextLabel(""col_balkanstory"[ NOVA ERA SPAWN ]{FFFFFF}\nDoborodosli na Nova Era Online Gaming Community!\nSince: 2020\n\n© All rights reserved.\n\nBy: DEntisT", 0x008080FF, 1714.9609, -1911.9082, 14.8019, 20.0, 0, 0);
	//kladionica
	//1824.9116,-1544.8605,13.4521
	Create3DandP(""col_balkanstory"[ PRIJAVA SUDIONIKA ]\n"col_white"Da prijavite sudionika u\nvasem zlocinu - ukoliko ga imate,\nkucajte:\n\n"col_balkanstory"/reportaj", 1824.9116,-1544.8605,13.4521, -1, -1, 1247, 5.0 );
    // beskucnici
    Create3DandP(""col_balkanstory"[ DOM ZA BESKUCNIKE ]\n\n"col_white"Ovo je dom i ujedno glavni spawn\nza beskucnike.\n\nBeskucnici su igraci koji:\n- su level 5+\n- nemaju nepokretne imovine\n- nisu clan organizacije", 1727.0195,-1633.9911,20.2159, -1, -1, 1254, 5.0 );
    //1727.0195,-1633.9911,20.2159
    Create3DandP(""col_balkanstory"[ HRANA I PICE ]\n\n"col_white"Ukoliko ste beskucnik, ovdje\nmozete uzeti hranu i pice!\n\nKuca casti, kucajte:\n"col_balkanstory"[ /supplies ]", 1721.9539,-1625.9147,20.2120, -1, -1, 1254, 5.0 );
    //1721.9539,-1625.9147,20.2120
	//sms igra
	Create3DandP(""col_balkanstory"[ DOSTAVA VOZILA - SMS igra ]\n\n"col_white"Da pokupite vozilo za dostavu, kucajte:\n"col_balkanstory"[ /pokupivozilo ]", 1723.1270,-1118.6689,24.0859, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"[ DOSTAVA VOZILA - SMS igra ]\n\n"col_white"Da zavrsite dostavu, kucajte:\n"col_balkanstory"[ /zavrsidostavu ]", 1315.6945,-1241.9543,13.5469, -1, -1, 1239, 5.0 );
	#if kladionica == 1
	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da uplatite listic\n"col_balkanstory"/uplatilistic", 1669.3000,-1353.0726,20163.0254, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da podignete dobitak\n"col_balkanstory"/podignidobitak", 1671.2402,-1353.0724,20163.0254, -1, -1, 1239, 5.0 );

	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da pogledate rezultate\n"col_balkanstory"/rezultati", 1666.5770,-1349.5175,20163.0254, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da pogledate rezultate\n"col_balkanstory"/rezultati", 1666.5890,-1345.4174,20163.0254, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da pogledate rezultate\n"col_balkanstory"/rezultati", 1673.8016,-1345.4181,20163.0254, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| WWin kladionica ||\n"col_white"Da pogledate rezultate\n"col_balkanstory"/rezultati", 1673.8197,-1349.5165,20163.0254, -1, -1, 1239, 5.0 );
    //granica
    #endif
    Create3DandP(""col_white"Da predjete granicu kucajte\n"col_balkanstory"[ /granica ]", 
    	50.8649, -1539.2595, 5.2322, -1, -1, 1239, 20.0 );
    Create3DandP(""col_white"Da predjete granicu kucajte\n"col_balkanstory"[ /granica ]", 53.5893, -1523.9884, 5.1619, -1, -1, 1239, 20.0 );
    Create3DandP(""col_white"Da predjete granicu kucajte\n"col_balkanstory"[ /granica ]", 1750.5269, 530.3855, 27.3948, -1, -1, 1239, 20.0 );
    Create3DandP(""col_white"Da predjete granicu kucajte\n"col_balkanstory"[ /granica ]", 1733.2133, 532.8638, 27.5273, -1, -1, 1239, 20.0 );
    //kladionica
    Create3DandP(""col_balkanstory"[ KLADJENJE ]\n"col_white"Da zavrtite kolo srece, kucajte:\n"col_balkanstory"/kladjenje", 1669.3000,-1353.0726,20163.0254, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"[ KLADJENJE ]\n"col_white"Da zavrtite kolo srece, kucajte:\n"col_balkanstory"/kladjenje", 1671.2402,-1353.0724,20163.0254, -1, -1, 1239, 5.0 );

    //pljacka banke update
    Create3DandP(""col_balkanstory"[ ULAZ U SEF BANKE ]\n{ffffff}Da udjete u sef banke, morate\npostaviti dinamit - kucajte:\n\n"col_red"[ /postavidinamit ]", 1470.9214,-1013.8781,2045.5367, -1, -1, 1239, 20.0 );
    Create3DandP(""col_balkanstory"[ KANALIZACIJA ZA BIJEG ]\n{ffffff}Da pobjegnete iz sefa banke, morate\nproci kroz kanalizaciju - kucajte:\n\n"col_red"[ /kanalizacija ]", 1470.6722,-1031.0518,2045.4248, -1, -1, 1239, 20.0 );
    Create3DandP(""col_balkanstory"[ IZLAZ IZ SEFA BANKE ]\n{ffffff}Uspjesno ste pobjegli\nod policije kroz kanalizaciju.\n\n"col_red"PAZITE SE!", 1417.6226,-1131.4406,22.2853, -1, -1, 1239, 20.0 );
	// Poslovi
	mehanicarpickup = CreateDynamicPickup( 1274, 2, 1942.1483,-1988.2566,13.5469, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Mehanicar\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Mehanicar\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1942.1483,-1988.2566,13.5469, 10.0, 0, 0);

    //1144.2695,-1336.0710,804.5207
    Create3DandP(""col_balkanstory"[ ZDRAVSTVENA KNJIZICA ]\n\n"col_white"Da ovjerite Vasu zdravstvenu knjizicu, kucajte:\n"col_balkanstory"[ /ovjeriknjizicu ]",1144.2695,-1336.0710,804.5207, -1, -1, 11736, 5.0 );
    //1157.3193,-1314.4224,804.5207
    Create3DandP(""col_balkanstory"[ VAKCINACIJA ]\n\n"col_white"Da se vakcinisete i izlijecite, kucajte:\n"col_balkanstory"[ /vakcinacija ]",1157.3193,-1314.4224,804.5207, -1, -1, 1240, 5.0 );
    //prevoznik1pickup = CreateDynamicPickup( 1274, 2, -76.7671, -1136.5931, 1.0781, -1, -1 );
    //Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Prevoznik\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Prevoznik\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, -76.7671, -1136.5931, 1.0781, 10.0, 0, 0);
    Create3DandP(""col_balkanstory"[ PAKET ZA PRVU POMOC ]\n\n"col_white"Da bi ste kupili paket za prvu pomoc,\nkucajte komandu:\n\n"col_balkanstory"[ /kupiprvupomoc ]", 1138.2598,-1322.7903,804.5207, -1, -1, 11738, 5.0 );
    //masinovodjapickup = CreateDynamicPickup( 1274, 2, 1734.9646, -1943.5743, 13.5698, -1, -1 );
    //Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Masinovodja\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Masinovodja\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1734.9646, -1943.5743, 13.5698, 10.0, 0, 0);

	taxipickup = CreateDynamicPickup( 1274, 2, 1220.0405,-1811.7588,16.5937, -1, -1 );
	Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Taxi vozac\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Taxi vozac\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1220.0405,-1811.7588,16.5937, 10.0, 0, 0);

	kosactravepickup = CreateDynamicPickup( 1274, 2, 1944.5791,-1200.7910,19.4600, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Kosac Trave\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Kosac Trave\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1944.5791,-1200.7910,19.4600, 10.0, 0, 0);

    komunalac1pickup = CreateDynamicPickup( 1274, 2, 2093.6064,-2046.0259,13.5469, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Komunalac\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Komunalacr\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 2093.6064,-2046.0259,13.5469, 10.0, 0, 0);

	gradjevinarpickup = CreateDynamicPickup( 1274, 2, 1972.4150,-1359.0519,14.1548, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Gradjevinar\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Gradjevinar\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1972.4150,-1359.0519,14.1548, 10.0, 0, 0);

 	dostavljacpicapickup = CreateDynamicPickup( 1274, 2, 1203.5619,-898.7397,1059.3329, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Pizza dostavljac\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Pizza dostavljac\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1203.5619,-898.7397,1059.3329, 10.0, 0, 0);

    farmerpickup = CreateDynamicPickup( 1274, 2, -1061.3511, -1205.4149, 129.7565, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Farmer\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Farmer\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, -1061.3511, -1205.4149, 129.7565, 10.0, 0, 0);

	pilotpickup = CreateDynamicPickup( 1274, 2, 1885.6949,-2231.7097,13.5469, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Pilot\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Pilot\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1885.6949,-2231.7097,13.5469, 10.0, 0, 0);

    busvozacpickup = CreateDynamicPickup( 1274, 2, 1770.9740,-1912.4221,13.9367, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Bus vozac\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Bus vozac\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1770.9740,-1912.4221,13.9367, 10.0, 0, 0);

    rudarpickup = CreateDynamicPickup( 1274, 2, 489.8073,790.9997,-22.0648, -1, -1 );
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Rudar\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Rudar\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 489.8073,790.9997,-22.0648, 10.0, 0, 0);

    //prevoznovcapickup = CreateDynamicPickup( 1274, 2, -72.1089, 1151.2772, -30.0369, -1, -1 );
    //Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Prevoznik novca\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Prevoznik novca\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, -72.1089, 1151.2772, -30.0369, 10.0, 0, 0);

    //ribarpickup = CreateDynamicPickup( 1274, 2, 2117.2278, 193.4166, 1.9107, -1, -1 );
    //Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Ribar\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Ribar\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 2117.2278, 193.4166, 1.9107, 10.0, 0, 0);

    //pnamestajapickup = CreateDynamicPickup( 1274, 2, 2147.8884,-2286.4146,14.7734, -1, -1 ); // edit
    //Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Proiz. namjestaja\n"col_sanm"Ugovor:{FFFFFF} 1h\n"col_sanm"Da se zaposlite kao Proiz. namjestaja\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 2147.8884,-2286.4146,14.7734, 10.0, 0, 0);

    pepsiposaopickup = CreateDynamicPickup( 1274, 2, 1095.5222,-1318.4564,12.8617, -1, -1 ); // edit
    Create3DTextLabel(""col_sanm"[ {FFFFFF}ZAPOSLJAVANJE "col_sanm"]\nPosao:{FFFFFF} Tempo Dostavljac\n"col_sanm"Ugovor:{FFFFFF} 3h\n"col_sanm"Da se zaposlite kao Tempo Dostavljac\n {FFFFFF}Stanite ovdje pokraj vrata firme i sacekajte momenat!", 0x008080FF, 1095.5222,-1318.4564,12.8617, 10.0, 0, 0);
	//Uniforme
	for( new i = 0; i < MAX_JOBS; i++)
	{ // edit ovo nije sredjeno kod marka

        if( jobsInfos[ i ][ jUniformPos ][ 0 ] != 0 )
         //Create3DandP(""col_white"Da uzmete/ostavite uniformu kucajte\n"col_balkanstory"[ /uniforma ]",  jobsInfos[ i ][ jUniformPos ][ 0 ], jobsInfos[ i ][  jUniformPos ][ 1 ], jobsInfos[ i ][ jUniformPos ][ 2 ], -1, -1, 1275, 2.0 );
		Create3DandP(""col_balkanstory"|| OPREMA ||\n"col_white"Da uzmete, ili ostavite, opremu za posao - kucajte komandu:\n"col_balkanstory"/uniforma",  jobsInfos[ i ][ jUniformPos ][ 0 ], jobsInfos[ i ][  jUniformPos ][ 1 ], jobsInfos[ i ][ jUniformPos ][ 2 ], -1, -1, 1275, 2.0 );

	}

	// grobar

	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zapocnite ovdje ]\n{FFFFFF}Ime misije: Grobar\nDa bi se zaposlili, uzeli/ostavili opemu,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /misijaoprema ]", 940.6663,-1085.2749,24.2962, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zadatak ]\n{FFFFFF}Ime misije: Grobar\nDa bi si uzeli poslovno vozilo,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /uzmivozilo ]", 930.6531,-1120.0939,24.0440, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zadatak ]\n{FFFFFF}Ime misije: Grobar\nDa ostavite tijelo koje ste pokupili,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /ostavitelo ]", 898.8851,-1068.6992,24.4808, -1, -1, 1239, 2.0 );

	// pekar

	Create3DandP(""col_balkanstory"|| DOBRODOSLI U PEKARU! ||\n\n"col_white"Da kupite nesto iz pekare, kucajte:\n"col_balkanstory"[ /pekara ]", pekara_x,pekara_y,pekara_z, -1, -1, 1239, 5.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zapocnite ovdje ]\n{FFFFFF}Ime misije: Pekar\nDa bi se zaposlili, uzeli/ostavili opremu,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /pekaroprema ]", pekara_ulaz_x,pekara_ulaz_y,pekara_ulaz_z, -1, -1, 1239, 5.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zadatak ]\n{FFFFFF}Ime misije: Pekar\nDa uzmete tjesto za proizvodnju,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /preuzmitjesto ]", pekara_mlin_x,pekara_mlin_y,pekara_mlin_z, -1, -1, 1239, 5.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zadatak ]\n{FFFFFF}Ime misije: Pekar\nDa dostavite tjesto za proizvodnju,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /dostavitjesto ]", pekara_dostava_x,pekara_dostava_y,pekara_dostava_z, -1, -1, 1239, 5.0 );
	
	// dzeparos

	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Zapocnite ovdje ]\n{FFFFFF}Ime misije: Dzeparos\nDa uzmete opremu za poslovnu misiju,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /dzeparosoprema ]", 1126.7860,-1489.7051,22.7690, -1, -1, 1239, 5.0 );
	Create3DandP(""col_yelow"[ PRIVREMENA POSLOVNA MISIJA - Informacija ]\n{FFFFFF}Ime misije: Dzeparos\nMisija 'Dzeparos' se bazira na\nkradji novca od ostalih\nigraca - da bi ste pokrali nekoga,\nkucajte komandu ispod ovog teksta!\nKomanda: \n[ /pokradinovcanik ]", 1135.2458,-1489.8125,22.7690, -1, -1, 1239, 5.0 );

	//gigatron
	Create3DandP(""col_balkanstory"[ DOBRODOSLI U GIGATRON! ]\n\n"col_white"Da udjete u interijer, stisnite:\n"col_balkanstory"[ F ]", 1420.5889,-1178.2612,25.9932, -1, -1, 19133, 5.0 );
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n\n"col_white"Da izadjete iz interijera, stisnite:\n"col_balkanstory"[ F ]", 1395.9165,-1200.2422,2002.9253, -1, -1, 19133, 5.0 );

	//===================| LABELI u Opstini Beograd |=================================
	//
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da izvadite licnu kartu\n"col_yelow"/izvadilicnu", 361.1285,171.3450,1008.3828, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da izvadite pasos\n"col_yelow"/izvadipasos", 361.3038,175.5968,1008.3846, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da date otkaz na poslu\n"col_yelow"/otkaz", 358.2381,178.5836,1008.3837, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da platite organizacijsku kaznu\n"col_yelow"/platiorgkaznu", 358.2363,166.2383,1008.3837, -1, -1, 1239, 2.0 );

	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da kupite taxi licencu\n"col_yelow"/taxilic", 358.2364,182.5580,1008.3837, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da napustite organizaciju\n"col_yelow"/orgizlaz", 358.2364,169.1037,1008.3837, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da kupite fakture\n"col_yelow" /kupifakture", 358.2514,186.5351,1008.3837, -1, -1, 1239, 2.0 );
	Create3DandP(""col_yelow"[ GRADSKA OPSTINA ]\n{FFFFFF}Da registrujete vozilo\n"col_yelow"/registrujvozilo", 362.0341,173.6739,1008.3828, -1, -1, 1239, 2.0 );

	//==================| LABELI u Birou Beograd |==================================
	Create3DTextLabel(""col_yelow"[ BIRO ]\n{FFFFFF}Da vidite listu poslova\n"col_yelow"/poslovi", 0x008080FF, 1324.7750,-862.5375,1407.5430, 10.0, 1, 0);
	Create3DTextLabel(""col_yelow"[ BIRO ]\n{FFFFFF}Da vidite listu poslova\n"col_yelow"/poslovi", 0x008080FF, 1324.6605,-859.2570,1407.5430, 10.0, 1, 0);
	//==============================================================================

	//================| LABELI LOTTO BEOGRAD |=======================================

	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da uplatite lotto listic kucajte\n"col_balkanstory"/lotto", 1732.0049,-1274.3639,13.5640, -1, -1, 1276, 2.0 );
	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da uplatite lotto listic kucajte\n"col_balkanstory"/lotto", 1730.5156,-1272.9764,13.5476, -1, -1, 1276, 2.0 );
	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da uplatite lotto listic kucajte\n"col_balkanstory"/lotto", 1728.9086,-1271.4746,13.5461, -1, -1, 1276, 2.0 );

	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da podignete lotto dobitak kucajte\n"col_balkanstory"/dobitak", 1726.3292,-1261.1490,13.5469, -1, -1, 1274, 2.0 );
	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da podignete lotto dobitak kucajte\n"col_balkanstory"/dobitak", 1726.2458,-1264.1096,13.5469, -1, -1, 1274, 2.0 );
	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da podignete lotto dobitak kucajte\n"col_balkanstory"/dobitak", 1739.3099,-1276.7129,13.5481, -1, -1, 1274, 2.0 );
	Create3DandP(""col_balkanstory"[ LUTRIJA ]\n"col_white"Da podignete lotto dobitak kucajte\n"col_balkanstory"/dobitak", 1742.0348,-1276.4623,13.5466, -1, -1, 1274, 2.0 );

	//=========================| Ulazi za objekte |==============================================
	Create3DandP(""col_balkanstory"[ GRADSKA OPSTINA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1481.0422,-1771.4331,18.7958, -1, -1, 19133, 2.0);
	//Create3DandP(""col_balkanstory"|| Centar Urgentne Medicine ||\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 2034.0833, -1401.7124, 17.3742, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ AUTO SKOLA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 2052.4143,-1897.3738,13.5585, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"|| Apoteka Betty ||\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]",  938.22638, -1720.29016, 13.62720, -1, -1, 19133, 2.0);
    Create3DandP(""col_balkanstory"|| Rudnik ||\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 493.1782,788.5486,-22.1103, -1, -1, 19133, 2.0);//rudnik ulaz
    Create3DandP(""col_balkanstory"[ BIRO RADA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1268.5072,-1543.9985,13.5690, -1, -1, 19133, 2.0);//biro ulaz
    //Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1461.3623, -1020.5203, 24.3023, -1, -1, 19133, 2.0);
    Create3DandP(""col_balkanstory"[ GRADSKI ZATVOR ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1824.5696,-1538.0585,13.5469, -1, -1, 19133, 2.0);
    //Create3DandP(""col_balkanstory"[ Promoter baza ]\n"col_white"'ENTER' za ulaz", 1673.9718, 1967.7209, 10.8203, -1, -1, 19133, 2.0);
    Create3DandP(""col_balkanstory"[ AFK ZONA ]\n"col_white"Da izadjete iz interijera, stisnite:\n\n[ F ]", 1700.5277, -1667.7759, 20.2188, -1, -1, 19197, 10.0 );
	Create3DandP(""col_balkanstory"[ AFK ZONA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1733.2987,-1912.1025,13.6621, -1, -1, 19197, 10.0 );
	Create3DandP(""col_balkanstory"[ JAVNI TOALET ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1136.1217,-897.1509,43.3906, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ ZLATARA ]]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", 1231.7878,-1428.6324,13.6951, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]", banka_ulaz_x,banka_ulaz_y,banka_ulaz_z, -1, -1, 19133, 2.0);
	//============================================================================

	Create3DandP(""col_balkanstory"[ GRANICNI PRELAZ ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]",
		1743.9816,538.1619,26.9405
		, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n"col_white"Da izadjete u interijera, stisnite:\n\n[ F ]",
		1742.4491,533.6021,27.2972
		, -1, -1, 19133, 2.0);

	Create3DandP(""col_balkanstory"[ GRANICNI PRELAZ ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]",
		58.7620,-1532.6776,5.2208
		, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n"col_white"Da izadjete u interijera, stisnite:\n\n[ F ]",
		55.0628,-1532.0175,5.2585
		, -1, -1, 19133, 2.0);

	//Create3DandP(""col_white"Da uzmete/ostavite uniformu kucajte\n"col_balkanstory"[ /pizza uniforma ]",  368.9966, -114.5767, 1001.4995, -1, -1, 1275, 2.0 );
	Create3DandP(""col_white"Da narucite picu kucajte\n"col_balkanstory"/pizza preuzmi",  1197.2174,-896.6176,1059.3329, -1, -1, 1239, 2.0 );
    //Create3DandP(""col_white"Da uzmete/ostavite uniformu kucajte\n"col_balkanstory"[ /taxi duty ]",  2766.1035, -1583.2134, -48.5485, -1, -1, 1239, 2.0 );

	//
    new zlatonovacstring[ 256 ];

 	format( zlatonovacstring, sizeof( zlatonovacstring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Da opljackate banku kucajte\n"col_balkanstory"/pljackajbanku", ServerInfo[ NovacBanka ] );
    ServerInfo[ NovacLabel ] = CreateDynamic3DTextLabel( zlatonovacstring, -1, 1467.8094,-1025.8485,2045.4248, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );

    format( zlatonovacstring, sizeof( zlatonovacstring ), ""col_white"[ STANJE NOVCA ]\n"col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Maksimalno moze imati "col_balkanstory"1 000 000$\n"col_balkanstory"", ServerInfo[ NovacBanka ] );
	ServerInfo[ NovacLabel2 ] = CreateDynamic3DTextLabel( zlatonovacstring, -1, 1505.6422, -1020.9277, 23.8281, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );

	//
	format( zlatonovacstring, sizeof( zlatonovacstring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%dg "col_white"zlata\n"col_white"Da opljackate zlataru kucajte\n"col_balkanstory"[ /pljackajzlataru ]", ServerInfo[ Zlato ] );
    ServerInfo[ ZlatoLabel ] = CreateDynamic3DTextLabel( zlatonovacstring, -1, 916.2475,-1010.8062,-47.9101, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	CreateDynamicPickup( 1239, 2, 916.2475,-1010.8062,-47.9101, -1, -1 );
	//
	Create3DandP(""col_sanm"[ KUTIJE SA ROBOM ]\n"col_white"Da uzmete kutiju sa robom kucajte\n"col_sanm"[ /uzmikutiju ]", -494.7044,-501.1635,26.0205, -1, -1, 1318, 20.0 );

	//PaySpray
 	Create3DandP(""col_balkanstory"[ RESPRAY ]\n"col_white"Da popravite vase vozilo\n"col_balkanstory"/enter\n"col_white"Cijena: 500$", 1099.1404, -824.9033, 181.2554, -1, -1, 1239, 10.0 );
	Create3DandP(""col_balkanstory"[ RESPRAY ]\n"col_white"Da popravite vase vozilo\n"col_balkanstory"/enter\n"col_white"Cijena: 500$", 1024.9756, -1030.7930, 32.0257, -1, -1, 1239, 10.0 );
	Create3DandP(""col_balkanstory"[ RESPRAY ]\n"col_white"Da popravite vase vozilo\n"col_balkanstory"/enter\n"col_white"Cijena: 500$", 488.3819, -1733.0563, 11.1752, -1, -1, 1239, 10.0 );
	Create3DandP(""col_balkanstory"[ RESPRAY ]\n"col_white"Da popravite vase vozilo\n"col_balkanstory"/enter\n"col_white"Cijena: 500$", 719.8940, -464.8272, 16.3359, -1, -1, 1239, 10.0 );
	//komercijalna
	Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"/stanje\n/podigni\n/ostavi", 1467.1327,-1006.9041,2058.0039, -1, -1, 1239, 3.0 );
	Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"/otvoriracun\n/prebaci", 1458.0945,-1004.9053,2058.0039, -1, -1, 1239, 3.0 );
	Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"/kredit\n/podignikredit", 1476.6707,-1005.0105,2058.0039, -1, -1, 1239, 3.0 );
	
	Create3DandP(""col_balkanstory"[ BANKA ]\n"col_white"Da hakujete lasere i sistem istih:\n/provalilozinku\n/unesilozinku", 1464.5374, -1005.3227, 2045.4697, -1, -1, 1239, 3.0 );
	
	//gigatron
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite mobitel\n/kupitelefon", 1386.9498,-1201.6807,2002.9253, -1, -1, 1239, 2.0 );
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite SIM karticu\n/kupisim", 1383.9934,-1198.6146,2002.9253, -1, -1, 1239, 2.0 );
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite GPS\n/kupigps", 1386.8595,-1203.2513,2002.9253, -1, -1, 1239, 2.0 );
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite radio\n/kupiradio", 1391.6458,-1201.6808,2002.9253, -1, -1, 1239, 2.0 );
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite laptop\n/kupilaptop", 1386.8506,-1195.1772,2002.9253, -1, -1, 1239, 2.0 );
 	Create3DandP(""col_balkanstory"[ ELEKTRONIK ]\n"col_white"Da kupite laptop\n/kupilaptop", 1391.5359,-1195.1759,2002.9253, -1, -1, 1239, 2.0 );
	//zlatara
	Create3DandP(""col_balkanstory"[ ZLATARA ]\n"col_white"Da kupite zlato\n/kupizlato", 914.5087,-1009.1017,-47.9101, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ ZLATARA ]\n"col_white"Da prodate zlato\n/prodajzlato", 918.3580,-1009.1941,-47.9101, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ ZLATARA ]\n"col_white"Da kupite zlatni sat\n/kupisat", 909.6122,-1004.8207,-47.9101, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ ZLATARA ]\n"col_white"Da kupite prsten\n/kupiprsten", 922.9607,-1004.9011,-47.9101, -1, -1, 1239, 2.0 );
	
	// imanje
	Create3DandP(""col_white"Da kupite praznu gajbicu kucajte\n"col_balkanstory"[ /kupigajbicu ]", 1887.3665, -1863.7323, 13.5765, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da kupite sjemena za imanje kucajte\n"col_balkanstory"[ /kupiseme ]", 1884.6896, -1872.3599, 13.5392, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da prodate kupus kucajte\n"col_balkanstory"[ /prodajkupus ]", 1876.8926, -1862.6066, 13.5788, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da prodate ruze kucajte\n"col_balkanstory"[ /prodajruze ]", 426.6609, -1791.3032, 5.6260, -1, -1, 1239, 2.0 );
	
	// 24/7 system
	//default int
	Create3DandP(""col_white"Da kupite stvari iz korpe kucajte\n"col_balkanstory"[ /buy ]", -28.0849,-89.9528,1003.5469, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Pizza - "col_balkanstory" 100$", -14.8936,-85.8825,1003.5469, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Uze - "col_balkanstory" 200$", -19.8782,-81.7753,1003.5469, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Maska - "col_balkanstory" 800$", -19.8783,-77.0707,1003.5542, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Sok - "col_balkanstory" 40$", -25.0427,-74.3232,1003.5469, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Pivo - "col_balkanstory" 55$", -17.9551,-74.3143,1003.5542, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Hamburger - "col_balkanstory" 65$", -31.8768,-77.5130,1003.5469, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Piletina - "col_balkanstory" 250$", -17.2291,-81.3823,1003.5469, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Cigare - "col_balkanstory" 35$", -37.3030,-76.5274,1003.5469, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Upaljac - "col_balkanstory" 25$", -34.9580,-74.3164,1003.5469, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"SodaB - "col_balkanstory" 80$", -37.3028,-84.8486,1003.5469, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"DesVoda - "col_balkanstory" 40$", -37.2162,-80.3907,1003.5469, -1, -1, 1239, 2.0 );
	//tempo
	Create3DandP("{FF8040}|| KASA ||\n"col_white"Da platite vasu robu\n{FF8040}/buy", 80.1054,1947.5295,-46.5000, -1, -1, 1239, 2.0 );//1
	Create3DandP("{FF8040}|| KASA ||\n"col_white"Da platite vasu robu\n{FF8040}/buy", 80.2422,1944.5304,-46.5000, -1, -1, 1239, 2.0 );//2
	Create3DandP("{FF8040}|| KASA ||\n"col_white"Da platite vasu robu\n{FF8040}/buy", 80.1232,1941.5316,-46.5000, -1, -1, 1239, 2.0 );//3
	Create3DandP("{FF8040}|| KASA ||\n"col_white"Da platite vasu robu\n{FF8040}/buy", 80.1526,1938.2695,-46.5000, -1, -1, 1239, 2.0 );//4
	//
	Create3DandP("{FF8040}|| PIZZA ||\n"col_white"Cijena: 100$", 79.0627,1934.9912,-46.5000, -1, -1, 1239, 2.0 );
	Create3DandP("{FF8040}|| UZE ||\n"col_white"Cijena: 200$", 62.5906,1950.4758,-46.5000, -1, -1, 1239, 2.0 );
	Create3DandP("{FF8040}|| MASKA ||\n"col_white"Cijena: 800$", 85.7592,1939.5144,-46.5000, -1, -1, 1239, 2.0 );
	Create3DandP("{FF8040}|| SOK ||\n"col_white"Cijena: 40$", 74.4506,1945.6547,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| PIVO ||\n"col_white"Cijena: 55$", 80.7565,1934.8174,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| HAMBURGER ||\n"col_white"Cijena: 65$", 68.2727,1939.4718,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| PILETINA ||\n"col_white"Cijena: 250$", 67.9707,1948.0797,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| CIGARETE ||\n"col_white"Cijena: 35$", 71.8576,1951.2085,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| UPALJAC ||\n"col_white"Cijena: 25$", 77.1649,1935.0197,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| SODA BIKARBONA ||\n"col_white"Cijena: 80$", 64.0953,1935.0474,-46.5000, -1, -1, 1239, 2.0 );
    Create3DandP("{FF8040}|| D.VODA ||\n"col_white"Cijena: 40$", 62.4464,1937.7119,-46.5000, -1, -1, 1239, 2.0 );
    //komunalac
    Create3DandP(""col_balkanstory"|| DEPONIJA ||\n"col_white"Da ispraznite kamion\n"col_balkanstory"/ispraznikamion", 2070.6895,-1984.1779,13.5544, -1, -1, 1239, 3.0 );
    Create3DandP(""col_balkanstory"|| DEPONIJA ||\n"col_white"Da ispraznite cistilicu\n"col_balkanstory"/ispraznicistilicu", 2073.8306,-1994.5646,13.6748, -1, -1, 1239, 3.0 );

	//auto servis
    Create3DandP(""col_balkanstory"[ AUTO SERVIS ]\n"col_white"Usluge auto servisa:\n"col_balkanstory"/popravimotor\n/popravisasiju\n/popravigume", 1936.0375,-2016.8180,13.7771, -1, -1, 1239, 3.0 );
    Create3DandP(""col_balkanstory"[ AUTO SERVIS ]\n"col_white"Usluge auto servisa:\n"col_balkanstory"/tehnickipregled\n/farbanje\n/neonshop", 1935.0571,-2025.8098,14.2209, -1, -1, 1239, 3.0 );
    Create3DandP(""col_balkanstory"[ AUTO SERVIS ]\n"col_white"Usluge auto servisa:\n"col_balkanstory"/ugradialarm\n/ugradibravu\n/natocigorivo", 1935.2322,-2007.9379,14.2209, -1, -1, 1239, 3.0 );
	//farma
	Create3DandP(""col_balkanstory"|| KANTE ||\n"col_white"Da uzmete kantu za mlijeko\n"col_balkanstory"/uzmikantu", -1079.7056,-1207.0790,129.2188, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| OSTAVA ||\n"col_white"Da uzmete praznu gajbu ili da uzmete voce\n"col_balkanstory"/uzmigajbu\n/uzmivoce", -1073.9840,-1209.5349,129.2188, -1, -1, 1239, 5.0 );
	Create3DandP(""col_balkanstory"|| PAKOVANJE MLIJEKA ||\n"col_white"Da upakujete mlijeko za preradu\n"col_balkanstory"LMB", -1081.7942,-1208.5925,129.2188, -1, -1, 1239, 5.0 );

	//auto skola
	Create3DandP(""col_balkanstory"|| Vozacki ispit ||\n"col_white"Da polazete vozacke ispite\n"col_balkanstory"/polaganje\n/aviondozvola\n/broddozvola", 2906.8472,-2060.8962,1002.2381, -1, -1, 1239, 2.0 );

	//oglasi
	Create3DandP(""col_balkanstory"[ OGLASI ]\n"col_white"Da postavite oglas\n"col_balkanstory"/oglas", 1709.3073,296.7236,1004.9067, -1, -1, 1239, 2.0 );

	//cnn studio
    Create3DandP(""col_balkanstory"[ OGLASI ]\n"col_white"Da postavite oglas\n"col_balkanstory"/oglasi", 727.9562,-1366.0109,1001.6613, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ OGLASI ]\n"col_white"Da postavite oglas\n"col_balkanstory"/oglasi", 725.8447,-1366.0070,1001.6613, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ OGLASI ]\n"col_white"Da postavite oglas\n"col_balkanstory"/oglasi", 723.9621,-1366.0051,1001.6613, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"|| LIVE ||\n"col_white"Da idete uzivo u program\n"col_balkanstory"/live", 744.3063,-1358.3914,1001.6753, -1, -1, 1239, 4.0 );
    
    
	//mup bg //1560.9031,-1714.8241,33.7242,
	Create3DandP(""col_balkanstory"|| KAZNE ||\n"col_white"Da platite kaznu\n"col_balkanstory"/platikaznu", 242.4187,118.5378,1021.4188, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| DOZVOLE ||\n"col_white"Da kupite dozvolu za oruzje\n"col_balkanstory"/oruzjedozvola", 246.4686,118.5370,1021.4188, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| TABLICE ||\n"col_white"Da preuzmete tablice vozila\n"col_balkanstory"/preuzmitablice", 250.6540,118.5352,1021.4188, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| DATABAZA ||\n"col_white"Da udjete u databazu\n"col_balkanstory"/databaza", 237.1855,123.7179,1021.4188, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| DOSIJE ||\n"col_white"Da ocistite dosije\n"col_balkanstory"/ocistidosije", 237.4014,125.8673,1021.4188, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| HAPSENJE ||\n"col_white"Da uhapsite osumnjicenog\n"col_balkanstory"/uhapsi\n"col_white"Da udjete u zgradu MUP-a\n"col_balkanstory"F", 1568.7417,-1690.5629,5.8906, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"|| MUP ||\n"col_white"Izlaz na krov/parking\n"col_balkanstory"F", 252.7960,125.2640,1021.4188, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"|| MUP ||\n"col_white"Ulaz u zgradu\n"col_balkanstory"F", 1564.4135,-1685.2876,28.3956,/*1562.6088,-1644.3645,25.7141,*/ -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"|| MUP ||\n"col_white"Ulaz u zgradu\n"col_balkanstory"F", 1565.2023,-1665.9219,28.3956,/*1562.9261,-1702.0176,25.7141,*/ -1, -1, 1239, 2.0 );

	//saj bg
	Create3DandP(""col_balkanstory"|| KAZNE ||\n"col_white"Da platite kaznu\n"col_balkanstory"/platikaznu", 230.2321,1718.2751,-41.1981, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| DOZVOLE ||\n"col_white"Da kupite dozvolu za oruzje\n"col_balkanstory"/oruzjedozvola", 232.7058,1718.2849,-41.1981, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| TABLICE ||\n"col_white"Da preuzmete tablice vozila\n"col_balkanstory"/preuzmitablice", 235.2786,1718.2629,-41.1981, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| DATABAZA ||\n"col_white"Da udjete u databazu\n"col_balkanstory"/databaza", 222.3049,1746.9291,-37.4751, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"|| HAPSENJE ||\n"col_white"Da uhapsite osumnjicenog\n"col_balkanstory"/uhapsi", 1262.3292,-1197.8417,23.8832, -1, -1, 1239, 2.0 );

	//apoteka
	Create3DandP(""col_balkanstory"|| APOTEKA ||\n"col_white"Da kupite sastojke\n"col_balkanstory"/apoteka", -426.4587,-1725.0701,2244.3611, -1, -1, 1239, 2.0 );

	//crno trziste
	#if nerp_droga == 1
	Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da kupite sjeme za drogu\n"col_balkanstory"/kupisjeme", 2611.6262,-1486.9033,16.5176, -1, -1, 1239, 2.0 );
    #endif
    Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da kupite spric\n"col_balkanstory"/kupispric", 2621.4048,-1486.9042,16.5247, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da kupite alat za obijanje\n"col_balkanstory"/kupialat", 2608.3884,-1506.7689,15.6666, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da kupite dinamit\n"col_balkanstory"/kupidinamit", 2616.4929,-1486.9813,16.5199, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da napravite oruzje\n"col_balkanstory"/napravioruzje", 2608.6785,-1515.3672,14.9451, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ CRNO TRZISTE ]\n"col_white"Da kupite alatku\n"col_balkanstory"/kupialatku", 2608.6675,-1511.3711,15.2827, -1, -1, 1239, 2.0 );
	//hangar  
	Create3DandP(""col_balkanstory"[ HANGAR ]\n"col_white"Da uzmete paket oruzja\n"col_balkanstory"/hangar", 2799.9172,-2418.4441,13.6307, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ HANGAR ]\n"col_white"Da kupite ilegalnu supstancu\n"col_balkanstory"/ilsupstance", 2794.4043,-2411.6677,13.6320, -1, -1, 1239, 2.0 );


	// clothing system
    Create3DandP(""col_balkanstory"[ SESIRI ]\n"col_white"Da kupite sesir\n"col_balkanstory"/buyhats", 205.0401, -100.3267, 1005.2578, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ BANDANA ]\n"col_white"Da kupite bandanu za glavu\n"col_balkanstory"/buyhbandanas", 171.4970, -92.8723, 1001.8047, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ BANDANA ]\n"col_white"Da kupite bandanu za lice\n"col_balkanstory"/buyfbandanas", 151.2055, -92.5647, 1001.8047, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ NAOCARE ]\n"col_white"Da kupite naocare\n"col_balkanstory"/buyglasses", 209.8154, -33.7277, 1001.9297, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ KACKETI ]\n"col_white"Da kupite kacket\n"col_balkanstory"/buycaps", 209.3052, -7.9960, 1005.2109, -1, -1, 1239, 2.0 );
    
    Create3DandP(""col_balkanstory"[ SALON ODJECE ]\n"col_white"Da kupite odjecu, ili ranac - kucajte:\n"col_balkanstory"/kupiodecu /kupiranac", 206.3761, -8.1491, 1001.2109, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ SALON ODJECE ]\n"col_white"Da kupite odjecu, ili ranac - kucajte:\n"col_balkanstory"/kupiodecu /kupiranac", 161.1792, -83.2523, 1001.8047, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ SALON ODJECE ]\n"col_white"Da kupite odjecu, ili ranac - kucajte:\n"col_balkanstory"/kupiodecu /kupiranac", 208.0208, -100.3269, 1005.2578, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ SALON ODJECE ]\n"col_white"Da kupite odjecu, ili ranac - kucajte:\n"col_balkanstory"/kupiodecu /kupiranac", 203.7806, -43.2623, 1001.8047, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ SALON ODJECE ]\n"col_white"Da kupite odjecu, ili ranac - kucajte:\n"col_balkanstory"/kupiodecu /kupiranac", 1309.6923, -882.9189, 39.5781, -1, -1, 1239, 2.0 );
	//
    Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /gamble ]", 1120.2582, -37.3042, 994.1146, -1, -1, 1239, 2.0 );
	Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /gamble ]", 1111.9668, -37.4637, 994.1146, -1, -1, 1239, 2.0 );
	Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /poker ]", 1112.5039, -64.2058, 994.1146, -1, -1, 1239, 2.0 );
	Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /poker ]", 1119.7524, -64.1777, 994.1146, -1, -1, 1239, 2.0 );
	Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /rulet ]", 1116.2321, -61.3468, 994.1146, -1, -1, 1239, 2.0 );
    Create3DandP( ""col_white"Kasino\n"col_balkanstory"[ /rulet ]", 1115.0347, -39.7942, 994.1146, -1, -1, 1239, 2.0 );
	//
  	Create3DTextLabel( "[/hpboks da napunis healte za Boks event]", 0xFFFF00FF, 1663.1982, -1386.0392, 65.0921, 23, 0, 1 );
    Create3DTextLabel( "[Pobednici, nakon borbe dolaze i staju ovde!]", 0xFFFF00FF, 1655.2023, -1381.6261, 66.1093, 23, 0, 1 );
    Create3DTextLabel( "[Ucesnici koji cekaju da ih prozovu!]", 0xFFFF00FF, 1636.8462, -1381.4254, 66.0894, 23, 0, 1 );
    Create3DTextLabel( "[Publika]", 0xFFFF00FF, 1646.9358, -1390.5105, 66.1855, 23, 0, 1 );
	// kiosci
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 354.3248,-2030.7961,7.9078, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1912.2021,-1734.6825,13.3773, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1886.4380,-1646.7341,13.3773, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1696.2340,-1887.5942,13.5517, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1420.1433,-1718.0017,13.5469, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1439.3855,-1043.3324,23.8281, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1194.2517,-954.1796,42.8990, -1, -1, 1239, 5.0 );
	Create3DandP( ""col_balkanstory"[ KIOSK / TRAFIKA ]\n"col_white"Da kupite nesto na trafici\n"col_balkanstory"/trafika", 1325.0109,-1389.5940,13.5681, -1, -1, 1239, 5.0 );
	
	// kurve
	CreateDynamic3DTextLabel(""col_red"Lisa: "col_white"Spremna sam za tebe, duso.\nDa krenete kucajte "col_red"/blowjob\n"col_balkanstory"1500$", -1, -2436.4424, 995.2935, -20.5350, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	CreateDynamic3DTextLabel(""col_red"Angelina: "col_white"Zelim da stavim nesto ukusno u usta.\nDa krenete kucajte "col_red"/blowjob\n"col_balkanstory"1500$",-1, -2436.6335, 1006.5629, -20.5350, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	CreateDynamic3DTextLabel(""col_red"Mia: "col_white"Spremna sam za tebe.\nDa krenete kucajte "col_red"/blowjob\n"col_balkanstory"1500$", -1, -2448.6267, 1006.4838, -20.5350, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	CreateDynamic3DTextLabel(""col_red"Sendy: "col_white"Zelis li malo zabave duso?.\nDa krenete kucajte "col_red"/blowjob\n"col_balkanstory"1500$", -1, -2448.4248, 996.1221, -20.5350, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	//
	CreateDynamic3DTextLabel("[ BANDERA SRECE ]\n\nStanite ovde i gledajte banderu\nkada neko donira gradu\nobogaticete se.", -1, 1133.5189, -936.0316, 47.7939, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
//	CreateDynamic3DTextLabel("[SNESKO BELIC]\n\nOd prvog do treceg januara 2021 godine\nsnesko belic vam daje vredne poklone\n/sneskobelic", -1, 1480.0776, -1621.1813, 18.6354, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
    CreateDynamic3DTextLabel("[ TAJNI ULAZ ]\n\nUlaz za PD/SAJ/CIA!\nZa ulaz pritisnite tipku - \n[ENTER]", -1, 1462.6173, -1005.6067, 57.5132, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1 );
	// firme
    Create3DandP(""col_balkanstory"[ JELA ]\n"col_white"Da narucite jelo\n"col_balkanstory"/menu", 378.1259, -67.7236, 1001.5151, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ JELA ]\n"col_white"Da narucite jelo\n"col_balkanstory"/menu", 369.4863, -6.0172, 1001.8589, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ JELA ]\n"col_white"Da narucite jelo\n"col_balkanstory"/menu", 450.3892, -83.6542, 999.5547, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ JELA ]\n"col_white"Da narucite jelo\n"col_balkanstory"/menu", -786.3990, 500.0740, 1371.7422, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ JELA ]\n"col_white"Da narucite jelo\n"col_balkanstory"/menu", 375.6081, -118.8045, 1001.4995, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2656.1489, 1405.1801, 906.2734, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2662.1855, 1405.1818, 906.2734, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2662.1685, 1415.4471, 906.2734, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2656.0698, 1415.4480, 906.2734, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", 499.9696, -20.6968, 1000.6797, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2394.6497, 1000.6146, -20.5350, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2400.5559, 1006.5995, -20.5350, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2406.7527,1000.5036,-20.5350, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ PICE ]\n"col_white"Da narucite pice\n"col_balkanstory"/drink", -2400.6563, 994.4063, -20.5350, -1, -1, 1239, 2.0 );
	//auto pijaca
	Create3DandP(""col_balkanstory"[ AUTO PIJACA ]\n"col_white"Ovdje mozete prodati Vase vozilo, kupiti necije\nvozilo i postavljati oglase za vozila!", 1756.0203,-1053.7484,23.9609, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ AUTO PIJACA ]\n"col_white"Ovdje mozete prodati Vase vozilo, kupiti necije\nvozilo i postavljati oglase za vozila!", 1704.0953,-1053.0139,23.9063, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ AUTO PIJACA ]\n"col_white"Ovdje mozete prodati Vase vozilo, kupiti necije\nvozilo i postavljati oglase za vozila!", 1648.4869,-1055.3829,23.8984, -1, -1, 1239, 2.0 );
	Create3DandP(""col_balkanstory"[ AUTO PIJACA ]\n"col_white"Ovdje mozete prodati Vase vozilo, kupiti necije\nvozilo i postavljati oglase za vozila!", 1639.3483,-1095.2971,23.9063, -1, -1, 1239, 2.0 );




	Create3DandP(""col_balkanstory"[ TERETANA ]\n"col_white"Da naucite novi stil borbe\n"col_balkanstory"/treniraj", 771.0096,13.4834,1000.6988, -1, -1, 1239, 2.0 );
    Create3DandP(""col_balkanstory"[ ORUZJE ]]\n"col_white"Da kupite oruzje\n/kupioruzje", 308.2903,-141.4637,999.6016, -1, -1, 1239, 2.0 );

    
	// Prevoznik
    Create3DandP(""col_white"Da utovarite drvece kucajte\n"col_balkanstory"[ /prevozdrveca ]", -569.0004, -93.3358, 63.9587, -1, -1, 1318, 10.0 );
	Create3DandP(""col_white"Da utovarite sljunak kucajte\n"col_balkanstory"[ /prevozsljunka ]", 620.8951, 832.1742, -42.9609, -1, -1, 1318, 10.0 );


    Create3DandP(""col_white"Da prodate vase mlijeko kliknite\n"col_balkanstory"[ LMB ]",156.6077, -22.2604, 1.5781, -1, -1, 1318, 5.0 );
	Create3DandP(""col_white"Da ostavite pokupljene useve kliknite\n"col_balkanstory"[ LMB ]", -1100.0110, -1142.8070, 129.2188, -1, -1, 1318, 5.0 );
	Create3DandP(""col_white"Da uzmete dzak sjemenki kucajte\n"col_balkanstory"[ /uzmisemenke ]", -1115.5098, -1246.7819, 129.2188, -1, -1, 1318, 5.0 );

    Create3DandP(""col_white"Da udjete u DM zonu kucajte\n"col_balkanstory"[ /udjinadm ]", 1382.1486, -1088.6586, 28.2120, -1, -1, 1239, 10.0 );
    Create3DandP(""col_white"Da udjete u arenu za grudvanje kucajte\n"col_balkanstory"[ /grudvanje ]", 511.7566, -1511.0818, 14.5677, -1, -1, 1239, 10.0 );
	Create3DandP(""col_white"Cena 5 fakturi je "col_balkanstory"500$\n"col_white"Da kupite fakture za firmu kucajte\n"col_balkanstory"[ /kupifakture ]",  641.9232, -108.9481, -78.9141, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Da uznajmite/odjavite sobu kucajte\n"col_balkanstory"[ /iznajmisobu /odjavisobu ]",  2217.3083, -1146.4053, 1025.7969, -1, -1, 1239, 5.0 );
	Create3DandP(""col_white"Da ozenite neku devojku kucajte\n"col_balkanstory"[ /zaprosi ]", 725.3050, -1597.1079, 3.4530, -1, -1, 1239, 5.0 );
	Create3DandP(""col_white"Da kupite kanticu( 200$ ) kucajte\n"col_balkanstory"[ /kupikanticu ]", -23.5164, -55.6298, 1003.5469, -1, -1, 1239, 10.0 );

   
	Create3DandP(""col_white"Da uzmete paket kucajte\n"col_balkanstory"[ /uzmipaket ]", 2612.3220, -2171.1863, -0.1676, -1, -1, 1239, 10.0 );

	Create3DandP(""col_white"Skladiste drva\n"col_balkanstory"[ /uzmidrvo ]", 2159.8730, -2296.4348, 13.4891, -1, -1, 1239, 10.0 );
	Create3DandP(""col_white"Da postavite drvo na masinu\n"col_balkanstory"[ TIPKA Y ]", 2149.6013, -2273.1235, 13.3047, -1, -1, 1239, 10.0 );
	Create3DandP(""col_white"Da uzmete drvo sa masine\n"col_balkanstory"[ TIPKA N ]", 2144.5337, -2267.7898, 13.2944, -1, -1, 1239, 10.0 );
	Create3DandP(""col_white"Da postavite drvo na zanatski sto\n"col_balkanstory"[ /ostavidrvo ]", 2129.8132, -2282.4976, 14.7825, -1, -1, 1239, 10.0 );
    Create3DandP(""col_white"Da postavite drvo na zanatski sto\n"col_balkanstory"[ /ostavidrvo ]", 2125.7715, -2278.3010, 14.7825, -1, -1, 1239, 10.0 );
    Create3DandP(""col_white"Da postavite drvo na zanatski sto\n"col_balkanstory"[ /ostavidrvo ]", 2121.8728, -2274.6519, 14.7825, -1, -1, 1239, 10.0 );
    
    Create3DandP(""col_white"Da natocite gorivo u cisternu\n"col_balkanstory"[ /natocicisternu ]", 269.1654, 1465.2311, 10.5859, -1, -1, 1239, 10.0 );
//if( IsPlayerInRangeOfPoint( playerid, 3.0, 1935.0571,-2025.8098,14.2209 ) || IsPlayerInRangeOfPoint( playerid, 2.5, 699.1390, -1183.1641, 16.0707 ) || IsPlayerInRangeOfPoint( playerid, 9.0, 695.6638, -1189.9620, 16.0697 ) )
    Create3DandP(""col_white"[ NEON SHOP ]\n"col_balkanstory"[ /neonshop ]", 695.6638, -1189.9620, 16.0697, -1, -1, 1239, 20.0 );
	Create3DandP(""col_white"[ NEON SHOP ]\n"col_balkanstory"[ /neonshop ]", 699.1390, -1183.1641, 16.0707, -1, -1, 1239, 20.0 );
	
	// PAYSPRAY
	

	Create3DandP(""col_white"Da popravite avion kucajte\n"col_balkanstory"[ /popraviavion ]\n"col_white"Cena: 500$", 1865.6421, -2390.7712, 14.4759, -1, -1, 1239, 20.0 );
	Create3DandP(""col_white"Da popravite avion kucajte\n"col_balkanstory"[ /popraviavion ]\n"col_white"Cena: 500$", -1525.4755, -81.9020, 15.0702, -1, -1, 1239, 20.0 );
	Create3DandP(""col_white"Da popravite avion kucajte\n"col_balkanstory"[ /popraviavion ]\n"col_white"Cena: 500$", 1433.4257, 1379.8014, 11.7424, -1, -1, 1239, 20.0 );
	// Ostalo

	Create3DandP("\n", 1924.3861,-1524.3082,2429.4849, -1, -1, 1239, 2.0 );
    Create3DandP("\n", 1917.1879,-1533.8624,2429.4897, -1, -1, 1239, 2.0 );
	Create3DandP("\n", 1879.1925, 2339.4995, 10.9799, -1, -1, 1239, 2.0 );
    Create3DandP("\n", 1871.5922, 2332.8225, 14.7813, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"Da prodate vozilo kucajte\n"col_balkanstory"[ /vozilo - Prodaja otpad ]", 732.3741, -96.0712, 21.4718, -1, -1, 1239, 4.0 );
    Create3DandP(""col_white"Da kupite dozvolu za avion/brod kucajte\n"col_balkanstory"[ /kupidozvoluzaavion /kupidozvoluzabrod ]", 209.2555, -197.1659, 1000.5235, -1, -1, 1239, 2.0 );
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    #if nerp_droga == 1
    Create3DandP(""col_white"Da kupite seme droge kucajte\n"col_balkanstory"[ /droga buyseeds ]", 870.3927, -24.9189, 63.9863, -1, -1, 1239, 2.0 );
	#endif
	Create3DandP(""col_white"Da kupite namestaj kucajte\n"col_balkanstory"[ /namestaj kupi ]", 1004.7539, -1610.4541, 14.5139, -1, -1, 1239, 2.0 );
  	Create3DandP(""col_white"Ukoliko zelite popraviti vozilo\n"col_balkanstory"[ /govrepair ]", 1585.6813, -1676.1810, 5.8968, 0, 0, 1239, 5.0 );
  	Create3DandP(""col_white"Ukoliko zelite popraviti vozilo\n"col_balkanstory"[ /govrepair ]", 656.7003, -1339.4277, 13.5459, 0, 0, 1239, 5.0 );
   	Create3DandP(""col_white"Ukoliko zelite popraviti vozilo\n"col_balkanstory"[ /govrepair ]", 2795.0320, -1615.6310, 10.9219, 0, 0, 1239, 5.0 );


    Create3DandP(""col_white"[ /mduty ]\n"col_balkanstory"[ /muniform ]",  1137.859497, -1324.926879, 804.520690, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da se izlecite kucajte\n"col_balkanstory"[ /lek ]", 1141.415771, -1329.014282, 804.520690, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da izlecite zavisnost za 25.000$ kucajte\n"col_balkanstory"[ /izlecizavisnost ]", 1138.682739, -1329.014282, 804.520690, -1, -1, 1239, 2.0 );
    #if nerp_droga == 1
	Create3DandP(""col_white"[ /droga osusi marihuana ]\n"col_balkanstory"[ /droga osusi kokain ]", -1477.9165, 2617.5532, 58.7813, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"[ /droga osusi marihuana ]\n"col_balkanstory"[ /droga osusi kokain ]", -1478.0580, 2623.5916, 58.7813, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"[ /droga osusi marihuana ]\n"col_balkanstory"[ /droga osusi kokain ]", -1478.0391, 2628.3794, 58.7813, -1, -1, 1239, 2.0 );
	Create3DandP(""col_white"[ /droga osusi marihuana ]\n"col_balkanstory"[ /droga osusi kokain ]", -1478.0297, 2634.2178, 58.7879, -1, -1, 1239, 2.0 );
	#endif
    Create3DandP(""col_white"Tehnicki pregled - 1000$\n"col_balkanstory"[ /tehnickipregled ]", 2016.3533, -1586.2186, 13.6547, -1, -1, 1581, 10.0 );

    Create3DandP(""col_white"Da kupite objekte kucajte\n"col_balkanstory"[ /objects kupi ]", 697.4481, -92.3247, 21.4892, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Ukoliko zelite da obucete uniformu tjelohranitelja\n"col_balkanstory"[ /uniformbodyguard ]", 1271.9607, -814.5180, 1089.9375, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Ukoliko zelite da obucete uniformu vozaca\n"col_balkanstory"[ /uniformdriver ]", 1271.9609, -812.2278, 1089.9375, -1, -1, 1239, 2.0 );
    Create3DandP(""col_white"Da kupite kacigu kucajte\n"col_balkanstory"[ /buyhelmet ]", 1990.9835, -2065.2139, 13.9252, -1, -1, 1239, 2.0 );
}
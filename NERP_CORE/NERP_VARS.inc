

//===============================[ Boje ]=======================================

#define CRVENA                                                        0xfa5555AA
#define ZELENA                                                     	  0x33AA33AA
#define BELA                                                          0xFFFFFFFF
#define CRNA 														  0x000000FF
//#define PLAVA                                                         0xA9C4E4FF
#define NARANDZASTA1                        						  0xFF9933AA
#define SIVA                                                          0xAFAFAFAA
#define ZUTA                                                          0xFFFF00AA
#define HELPER 													      0xDABB3EAA
#define NARANDZASTA                                                   0xFFAF00FF
#define LJUBICASTA                  								  0xC2A2DAAA
#define SVETLOPLAVA                  								  tdboja//0x33CCFFAA
#define SVETLOCRVENA  												  0xFF6347AA
#define UGBOJA                                                        tdboja//0x0080C0FF
#define ANTICHEAT 													  0xDC143CAA
#define NARACRVENA 	                                                  0xFF4500AA
#define WARLJUB 										  			  0x8B008BAA
#define PLAVA                                                         UGBOJA
#define ROZA                                                          SVETLOCRVENA


#define col_job                           "{5371ff}"//"{5371ff}"//"{CDDC39}"//"{36AB00}"
#define col_white                         "{FFFFFF}"
#define col_balkanstory col_orange//                      "{0073AA}"
#define col_sanm col_orange//                          "{2e9cd1}"
#define col_crvena                        "{FF0000}"
#define col_ljub						  "{9000FF}"
#define col_orange "{5371ff}"//"{2e9cd1}"
//"{3d69f0}"//"{2758ed}" //"{2e9cd1}"//GANTON OGC "{91d216}"NARANDZASTA "{FFAF00}"
#define col_red                           "{FF0000}"
#define col_yelow                         "{FFFF00}"
#define col_yellow col_yelow

#define col_green "{00FF40}"

#include <sampvoice>

#include "NERP_SUBSCRIPTS.inc"

//optidraw
//#define _streamer_included 1
#define OD_METHOD METHOD_BOX
#tryinclude <OP\optidraw>

#include <DentisT_Credits.inc>

#pragma dynamic 270000000000000
//#pragma disablerecursion

#pragma library breh

#pragma warning disable 217

new Text3D:grobar_car_label[MAX_PLAYERS];
new grobar_car[MAX_PLAYERS];
new HoldingWeapon[MAX_PLAYERS];
#if defined UCITAJMAPUSISTEMA
new tmpobjid;
new diglevent;
new kucamoja;
new motosalon;
new sicilianmafia;
new bsznak;
new tmpobjid2;

//new prodavnicacentar;
#endif
#define DEntisT_KillTimer Dimi_KillTimer

//Fcmd#define CMD: dentistcmd:
#define DEntisT_invalid_dialogid 500

#define pid playerid

#pragma unused ReturnUser

// DEntisT dodo ovo ispod sad:
/*#define DEntisT_pdr 1

#if defined DEntisT_pdr || DEntisT_pdr == 1
	#pragma disablerecursion
#elseif !defined DEntisT_pdr
	#error DEFINISI DEntisT_pdr == 1
#endif*/

//==================================[ Igraci ]==================================

#define MAX_POKUSAJ_LOGINA                                                     3
#define I_FILE                                  			  "Korisnici/%s.ini"
#define FILE_BAN                                			   "Banovani/%s.ini"
#define A_FILE                                  			  	 "Admini/%s.ini"
#define LOZINKA_STRING 														  50

#define OBICAN_ZATVOR 1
#define ALKATRAZ 2

#define PovecajPVarInt(%0,%1,%2)     SetPVarInt(%0, %1, GetPVarInt(%0, %1) + %2)
#define ClearChat(%0,%1)  for( new n=0; n<%1; n++) SendClientMessage(%0, -1, " ")

#define HOLDING(%0) 							((newkeys & (%0)) == (%0))
#if !defined PRESSED
	#define PRESSED(%0) 						(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif

#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

native IsValidVehicle( vehicleid );

#define gettimeEx(%0,%1,%2) gettime(%0,%1,%2)
//; %0 -= 1

//==================================[ Igraci ]==================================

#define OBJECT_SLOT_MASKSUNGL              								       0
#define OBJECT_SLOT_HEAD 		            								   1
#define OBJECT_SLOT_BANDANA                 								   2
#define OBJECT_SLOT_FREE                 								       3
#define OBJECT_SLOT_RHAND                 								       4
#define OBJECT_SLOT_LHAND                 								       5
#define OBJECT_SLOT_HELMET                								       6
#define OBJECT_SLOT_MASK                								       7
#define OBJECT_SLOT_BADGE                								       8
#define OBJECT_SLOT_WINTERCAP                               	  	 	 	   9
#define OBJECT_SLOT_BACKPACK                                	  	 	 	   9

#define POSAO_NEMA                  								       	   0
#define POSAO_KOSAC 														   1//DIALOG++
#define POSAO_GRADJEVINAR													   2//DIALOG++ / dodat sistem ravnanja kao na GH
#define POSAO_RUDAR														       3//DIALOG-- / dodat jos da vozi zlato u zlataru
#define POSAO_KOMUNALAC                                                        4//DIALOG++ / dodat provjeru anticheata na kupljenju smeca
#define POSAO_TEMPODOSTAVA                                                     5//DIALOG++ / dodat natpise na vozila
#define POSAO_PILOT 														   6//DIALOG++ / dodat liniju za pustinju tamo
#define POSAO_BUSVOZAC														   7//DIALOG++ / dodat jos linije za ZG i SA
#define POSAO_MEHANICAR                                                        8
#define POSAO_FARMER														   9
#define POSAO_PIZZA															  10
#define POSAO_TAXI              								       	  	  11
#define POSAO_PREVOZNOVCA                                                     12
#define POSAO_RIBAR                                                    		  13
#define POSAO_PNAMESTAJA                                                      14
#define POSAO_MASINOVODJA                                                     15
#define POSAO_PREVOZNIK              								       	  16
//dialozi za pocinjanje poslova

//===========================[ ZA POSLOVE DEFINE ]===========================
#define AKTIV_KONTEJNERI                                                      13
#define AKTIV_TEMPOKUTIJE                                                      6
#define GRADJEVINARDOWNPOS                                               12.5000
#define GRADJEVINARHRPICE                                                     26

#define NEMA_PLATU 0
//==============================================================================

#define MAX_JOBS    15

enum jobData 
{

	jName[ 64 ],
	Float:jPos[ 3 ],
	jType,
	jUniformSkin_Male,
	jUniformSkin_Female,
	Float:jUniformPos[ 3 ]
};


new jobsInfos[ MAX_JOBS ][ jobData ] =
{
	{"Kosac Trave", {1944.5791,-1200.7910,19.4600}, POSAO_KOSAC, 37, 38, { 1944.2924,-1197.0725,19.4600 } },
	{"Gradjevinar", {1972.4150,-1359.0519,14.1548}, POSAO_GRADJEVINAR, 27, 191, { 1970.5193,-1356.5519,13.1260 } },
	{"Komunalac", {2093.6064,-2046.0259,13.5469}, POSAO_KOMUNALAC, 16, 69, { 2089.7065,-2049.7600,13.5469 } },
	{"Tempo Dostavljac", {1095.5222,-1318.4564,12.8617}, POSAO_TEMPODOSTAVA, 261, 69, { 1092.1212,-1318.4003,12.8617 } },
	{"Pilot", {1885.6949,-2231.7097,13.5469}, POSAO_PILOT, 61, 69, { 1899.3315,-2237.4270,13.5469 } },
	{"Bus vozac", {1770.9740,-1912.4221,13.9367}, POSAO_BUSVOZAC, 61, 69, { 1799.2095,-1884.8618,13.4034 } },
	{"Farmer", {-1047.9996,-1230.6726,128.6476}, POSAO_FARMER, 133, 31, { -1061.2531,-1195.5317,129.7647 } },
	{"Mehanicar", {1942.1483,-1988.2566,13.5469}, POSAO_MEHANICAR, 0, 0, { 0.0, 0.0, 0.0 } },
	{"Pizza Dostavljac", {1203.5619,-898.7397,1059.3329}, POSAO_PIZZA, 155, 155, { 1192.6371,-896.6752,1059.3329 } },
	{"Rudar", {489.8073,790.9997,-22.0648}, POSAO_RUDAR, 260, 69, { 492.4852,778.6744,1001.4630 } },
	{"Taxi vozac", {1220.0405,-1811.7588,16.5937}, POSAO_TAXI, 0, 0, { 0.0, 0.0, 0.0 } },
	
	{"Masinovodja", {1714.6831, -1941.8939, 13.5753}, POSAO_MASINOVODJA, 7, 69, { 1751.5702, -1943.7581, 13.5691 } },
	{"Prevoznik", {-76.7671, -1136.5931, 1.0781}, POSAO_PREVOZNIK, 206, 69, { -79.6867, -1140.4409, 1.0781 } },
	{"Prevoznik Novca", {1503.1981, -1028.9382, 23.8033}, POSAO_PREVOZNOVCA, 71, 69, { -64.8947, 1152.5828, -30.0369 } },
	{"Ribar", {2128.8340, 181.2520, 1.7772}, POSAO_RIBAR, 33, 69, { 2133.6624, 201.5592, 2.1109 } }
	//{"Proizvodjac Namestaja", {2170.9680, -2296.4177, 13.6469}, POSAO_PNAMESTAJA, 8, 69, { 2150.0945, -2284.2131, 14.7734 } }
};

new Text:BraceTeam[10];
new Text:LogRegSelection[10];
new Text:ClientSelection[10];
new PlayerText:MoneyBar[MAX_PLAYERS];
new PlayerText:OruzjeIgraca[MAX_PLAYERS][10];
//new PlayerText:LevelIgraca[MAX_PLAYERS];
new PlayerText:BanTD[MAX_PLAYERS][20];
new PlayerText:TutorijalTD[10][MAX_PLAYERS];
new PlayerText:p_gamemodetd[5][MAX_PLAYERS];
new PlayerText:Notification[10][MAX_PLAYERS];
new PlayerText:OdjecaTextdraw[20][MAX_PLAYERS];
new PlayerText:PUBGTextdraw[20][MAX_PLAYERS];
new PlayerText:SpecTextdraw[20][MAX_PLAYERS];
new PlayerText:ScreenMsgTextdraw[10][MAX_PLAYERS];
new PlayerText:WifiConnection[10][MAX_PLAYERS];
new PlayerText:MessageBox[10][MAX_PLAYERS];
new PlayerText:DamageTextdraw[MAX_PLAYERS];
new Text:EditObjectTextdraw[30];
new Text:UcitavanjeTextdraw[10];
new Text:MobileNERPLogo[10];
new Text:PCNERPLogo[10];
new Text:UnknownCommand[10];
new PlayerText:ZombieEventTextdraw[10][MAX_PLAYERS];
new PlayerText:ItemNearby[10][MAX_PLAYERS];
new PlayerText:NovaSecurity[MAX_PLAYERS][20];

////////////////////////////////////////////////
enum PUBGinfo
{
	xPokrenut,
	xTrebaIgraca,
	xPoceoMatch,
	xCekaIgraca,
	xIgraMatch,
	xZapocetoUcitavanje
}
////////////////////////////////////////////////
new PUBGenum[PUBGinfo];
new announcetimer[MAX_PLAYERS];

new pubg_srw;
#define pubg_server 364
new endmatch[MAX_PLAYERS];
new autoskok[MAX_PLAYERS];
new maintimer;
////////////////////////////////////////////////

#include "NERP_EDITSYS.inc"

//new PlayerText:StatsPreviewTD[MAX_PLAYERS][30];
//===============================[ RIBAR ]======================================

enum fishInfo {

	bool:Fishing,
	bool:StartedFishing,
	Fisherman,
	FishKG,
	fObject,
	fLastVeh,
	TriesFish,
	fsTimer
}
new fishermanInfo[ MAX_PLAYERS ][ fishInfo ];

new PlayerText:FishermangTD[ 2 ][ MAX_PLAYERS ];
new PlayerText:playermoneytd0[MAX_PLAYERS];
new Float:RibarPosition[ 7 ][ 3 ] = {

	{ 1927.3441, -106.7698, -0.2713 },
	{ 1705.4414, -15.0117, -0.2836 },
	{ 1565.3729, -207.2334, -0.2315 },
	{ 1280.1395, -246.1905, -0.2379 },
	{ 2164.4368, -206.1587, -0.2979 },
	{ 2140.0654, 385.9410, -0.3998 },
	{ 1946.1971, 521.6243, -0.2193 }
};
//new Text3D:A_GSDutyLabel[ MAX_PLAYERS ];
//============================[ KLADIONICA ]====================================
#define kladionica 0
#if kladionica == 1
enum s1cverqw {

	bool:Uplaceno,
	bool:Zavrseno,
	parID[ 10 ],
	teamID1[ 10 ],
	teamID2[ 10 ],
	keciksdva[ 10 ],
	Float:Kvota[ 10 ],
	Uplata,
	Float:Dobitak,
	bool:Status,
	HourPobeda[ 24 ]
};
new KladionicaListic[ MAX_PLAYERS ][ s1cverqw ];
new IzabraniPar[ MAX_PLAYERS ];

#define KLAD_FILE                                  			 "Kladionica/%s.ini"

enum celceeec {

	parID[ 2 ],
	Float:Kvota[ 3 ],
	Rezultat[ 3 ]
};
new Parovi[ 10 ][ celceeec ];

enum celceesec {

	parID[ 2 ],
	Rezultat[ 2 ],
	Float:Kvota,
	HourPobeda[ 24 ]
};
new StariParovi[ 10 ][ celceesec ];

new PlayerText:KladionicaSM[ MAX_PLAYERS ][ 32 ];
new PlayerText:KladListicSM[ MAX_PLAYERS ][ 9 ];

enum _bettingInfo {
	teamID,
	teamName[ 64 ],
	teamStrength
};
#endif
//////////////////////////////
//new bool:UzeoDPlatu[MAX_PLAYERS];
new bool:Reklamirao[MAX_PLAYERS];
new bool:RconAdmin[MAX_PLAYERS];

//--------------------|| PAROVI KLADIONICA ||----------------------------------
#if kladionica == 1
new bettingInfo[ 46 ][ _bettingInfo ] =
{

	{ 0, "Barcelona", 10 },
	{ 1, "Real Madrid", 10 },
	{ 2, "Atletico Madrid",9 },
	{ 3, "Chelsea", 9 },
	{ 4, "Manchester City", 9 },
	{ 5, "Arsenal", 9 },
	{ 6, "Bayern Munich", 10 },
	{ 7, "Wolfsburg", 10 },
	{ 8, "Monchengladbach", 8 },
	{ 9, "Juventus", 9 },
	{ 10, "Roma", 8 },
	{ 11, "Benfica", 7 },
	{ 12, "PSG", 9 },
	{ 13, "Porto", 8 },
	{ 14, "Lyon", 7 },
	{ 15, "Zenit", 7 },
	{ 16, "PSV Eindhoven", 7 },
	{ 17, "Dynamo Kyiv", 4 },
	{ 18, "Galatasaray", 8 },
	{ 19, "Olympiacos", 7 },
	{ 20, "Sevilla", 7 },
	{ 21, "Manchester United", 9 },
	{ 22, "Valencia", 7 },
	{ 23, "Lazio", 8 },
	{ 24, "Bayer Leverkusen", 8 },
	{ 25, "Sporting CP", 7 },
	{ 26, "Basel", 7 },
	{ 27, "Monaco", 8 },
	{ 28, "Club Brugge", 6 },
	{ 29, "Rapid Wien", 5 },
	{ 30, "Sparta Prague", 6 },
	{ 31, "Salzburg", 5 },
	{ 32, "CSKA Moscow", 7 },
	{ 33, "Fenerbahce", 6 },
	{ 34, "Panathinaikos", 5 },
	{ 35, "Viktoria Plzen", 3 },
	{ 36, "Ajax", 7 },
	{ 37, "Sarajevo", 6 },
	{ 38, "Partizan", 6 },
	{ 39, "Dinamo Zagreb", 6 },
	{ 40, "HJK", 5 },
	{ 41, "Maribor", 4 },
	{ 42, "BATE Borisov", 3 },
	{ 43, "Celtic", 4 },
	{ 44, "Crvena Zvezda", 6 },
	{ 45, "Hajduk", 6 }
};
#endif
//===============================[ Admin Ports ]======================================

new Text3D:adutylabel[MAX_PLAYERS];
new Text3D:gmdutylabel[MAX_PLAYERS];

//==================| ADMIN PORT BEOGRAD |======================================
#define MAX_BGAPORTS													     100
#define F_BGAPORT							     		 	  "AdminGmPortovi/BGaport.cfg"

enum BGaportData
{
	BGaportID,
	BGaportCreated,
	BGaportName[ 50 ],
	Float:BGaportPos[ 3 ]
};
new AportBGInfo[ MAX_BGAPORTS ][ BGaportData ];

//==================| ADMIN PORT SARAJEVO |======================================
#define MAX_SAAPORTS													     100
#define F_SAAPORT							     		 	  "AdminGmPortovi/SAaport.cfg"

enum SAaportData
{
	SAaportID,
	SAaportCreated,
	SAaportName[ 50 ],
	Float:SAaportPos[ 3 ]
};
new AportSAInfo[ MAX_SAAPORTS ][ SAaportData ];

//==================| ADMIN PORT ZAGREB |======================================
#define MAX_ZGAPORTS													     100
#define F_ZGAPORT							     		 	  "AdminGmPortovi/ZGaport.cfg"

enum ZGaportData
{
	ZGaportID,
	ZGaportCreated,
	ZGaportName[ 50 ],
	Float:ZGaportPos[ 3 ]
};
new AportZGInfo[ MAX_ZGAPORTS ][ ZGaportData ];

//==================| ADMIN PORT OSTALO |======================================
#define MAX_OSAPORTS													     100
#define F_OSAPORT							     		 	  "AdminGmPortovi/OSaport.cfg"

enum OSaportData
{
	OSaportID,
	OSaportCreated,
	OSaportName[ 50 ],
	Float:OSaportPos[ 3 ]
};
new AportOSInfo[ MAX_OSAPORTS ][ OSaportData ];


//==================| GM/SUPP PORT BEOGRAD |======================================
#define MAX_BGSPORTS													         100
#define F_BGSPORT							     		 		  "AdminGmPortovi/BGsport.cfg"

enum BGsupportData
{
	BGsupportID,
	BGsupportCreated,
	BGsupportName[ 50 ],
	Float:BGsupportPos[ 3 ]
};
new BGsupportInfo[ MAX_BGSPORTS ][ BGsupportData ];

//==================| GM/SUPP PORT Sarajevo |======================================
#define MAX_SASPORTS													         100
#define F_SASPORT							     		 		  "AdminGmPortovi/SAsport.cfg"

enum SAsupportData
{
	SAsupportID,
	SAsupportCreated,
	SAsupportName[ 50 ],
	Float:SAsupportPos[ 3 ]
};
new SAsupportInfo[ MAX_SASPORTS ][ SAsupportData ];



//==================| GM/SUPP PORT Zgareb |======================================
#define MAX_ZGSPORTS													         100
#define F_ZGSPORT							     		 		  "AdminGmPortovi/ZGsport.cfg"

enum ZGsupportData
{
	ZGsupportID,
	ZGsupportCreated,
	ZGsupportName[ 50 ],
	Float:ZGsupportPos[ 3 ]
};
new ZGsupportInfo[ MAX_ZGSPORTS ][ ZGsupportData ];



//==================| GM/SUPP PORT Ostale |======================================
#define MAX_OSSPORTS													         100
#define F_OSSPORT							     		 		  "AdminGmPortovi/OSsport.cfg"

enum OSsupportData
{
	OSsupportID,
	OSsupportCreated,
	OSsupportName[ 50 ],
	Float:OSsupportPos[ 3 ]
};
new OSsupportInfo[ MAX_OSSPORTS ][ OSsupportData ];




//=============================[ PARKING ]=======================================

#define PARKING_FILE                          "Parkinzi/Parking_%d.ini"
#define MAX_PARKINGS                          50
#define MAX_PARK_PL                           50

enum pf_info {

	bool:parkPlaced,
	Float:parkObjectPos[ 6 ],
	parkObject,
	parkInt,
	parkVW,
	Float:parkPickup_1_Pos[ 3 ],
	Float:parkPickup_2_Pos[ 3 ],
	Float:parkMaxX,
	Float:parkMinX,
	Float:parkMaxY,
	Float:parkMinY,
	parkMaxParkPlaces,
	parkPickup_1,
	parkPickup_2,
	Text3D:park3d_1,
	Text3D:park3d_2,
	parkRectAngle
}
new ParkingInfo[ MAX_PARKINGS ][ pf_info ];

enum pf_info_2 {

	bool:parkTaken,
	Float:parkPlace_X,
	Float:parkPlace_Y,
	Float:parkPlace_Z,
	Float:parkPlace_A
}
new ParkingPlaces[ MAX_PARKINGS ][ MAX_PARK_PL ][ pf_info_2 ];

//===============================[ ASKQ ]=======================================

#define MAX_ASKQS													          50

enum askqData {
	bool:askqSend,
	askqOwner[ MAX_PLAYER_NAME ],
	askqID,
	askqQuestion[ 128 ]
};
new askqList[ MAX_ASKQS ][ askqData ];

enum askqDataA {
	bool:askqSended,
	bool:askqAnswered,
	askqAdmin[ MAX_PLAYER_NAME ],
	askqAnswer[ 128 ]
};
new askqInfo[ MAX_PLAYERS ][ askqDataA ];

//==============================[ RADAR ]=======================================

#define MAX_RADARS											    	         100
#define F_RADARS							     		   "Radars/radar_%i.ini"

enum radarData {

	radarMaxSpeed,
	radarPrice,
	Float:radarPos[ 6 ],
	radarObject
};
new radarInfo[ MAX_RADARS ][ radarData ];

new PlayerText:RadarCol[ MAX_PLAYERS ],
	Timer_Radar[ MAX_PLAYERS ],
	bool:alreadyPictured[ MAX_PLAYERS ],
	Radar_Count[ MAX_PLAYERS ];
//

new pot[] = { 0, 0, 2, 3, 4, 5, 7, 20, 100, 250 };

#define POKERLAPS 52 // 4 * 13 laps (2, 3 ... K, A

#define TREFF           0b1 //1 // "clubs"
#define KARO            0b10 //2 // â€œdiamondsâ€
#define KOR             0b100 //4 // â€œheartsâ€
#define PIKK            0b1000 //8 // â€œspadesâ€ or â€œshieldsâ€

enum
{
		TWO = 2,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
};

enum
{
		HIGH_CARD = 0,
		ONE_PAIR,
		TWO_PAIR,
		THREE_OF_A_KIND,
		STRAIGHT,
		FLUSH,
		FULL_HOUSE,
		FOUR_OF_A_KIND,
		STRAIGHT_FLUSH,
		ROYAL_FLUSH
};

new Card_Value[ POKERLAPS ] =
{
		TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
		TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
		TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
		TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

new Bynary_Mask[ POKERLAPS ] =
{
		1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
		1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
		1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
		1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000
};

new Prim_Mask[ POKERLAPS ] =
{
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41
};

new Color_Mask[ POKERLAPS ] =
{
		TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF,
		KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO,
		KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR,
		PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK
};

new PlayerText:Start[ MAX_PLAYERS ];

new Text:ReadyText;
new Text:betaversiontd;
new Text:BetText[ MAX_PLAYERS ];

new Text:Box;
//TDOVI ZA ŠALTANJE GAMEMODA
new Text:gamemodetd[20];


//TDOVI ZA TAKE DAMAGE
//global
new Text:takedamage0;
new Text:takedamage1;

//pubg

new Text:PubgEventTd[10];
new PlayerText:PubgEventKills[MAX_PLAYERS];

//player
new PlayerText:ptakedamage0[MAX_PLAYERS];//ime
new PlayerText:ptakedamage1[MAX_PLAYERS];//health
new hideptakedamage[MAX_PLAYERS];

// PARE TDS
new Text:moneytd0;
new Text:moneytd1;
///////////////////BETA TEXTDRAWS//////////////////
new Text:betatextdraw0;
new Text:betatextdraw1;
new Text:betatextdraw2;
new Text:betatextdraw3;
new Text:betatextdraw4;
new Text:betatextdraw5;
new Text:betatextdraw6;



///////////////////////////////////////
new Text:LoginTextdraws[14];

new Text:Digit1[ 6 ];
new Text:Digit2[ 6 ];
new Text:Digit3[ 6 ];

new Slots[ MAX_PLAYERS ][3];
new SlotCounter[ MAX_PLAYERS ];
new Gambling[ MAX_PLAYERS ];
new isprazniovreca[MAX_PLAYERS];

new DeathAfterInjury[MAX_PLAYERS];

new RuletAccount[ MAX_PLAYERS ];

new SlotTimer[ MAX_PLAYERS ];
new GlobalnoVrijeme;
new GlobalniSat;

new BusActor1[MAX_PLAYERS];
new BusActor2[MAX_PLAYERS];
new BusActor3[MAX_PLAYERS];
new BusActor4[MAX_PLAYERS];
new BusActor5[MAX_PLAYERS];
new Bet[ MAX_PLAYERS ];
new Balance[ MAX_PLAYERS ];

new LD_POKE[ POKERLAPS ][] =
{
		{ "LD_POKE:cd2c" }, { "LD_POKE:cd3c" }, { "LD_POKE:cd4c" }, { "LD_POKE:cd5c" }, { "LD_POKE:cd6c" }, { "LD_POKE:cd7c" }, { "LD_POKE:cd8c" },
		{ "LD_POKE:cd9c" }, { "LD_POKE:cd10c" }, { "LD_POKE:cd11c" }, { "LD_POKE:cd12c" }, { "LD_POKE:cd13c" }, { "LD_POKE:cd1c" },

		{ "LD_POKE:cd2d" }, { "LD_POKE:cd3d" }, { "LD_POKE:cd4d" }, { "LD_POKE:cd5d" }, { "LD_POKE:cd6d" }, { "LD_POKE:cd7d" }, { "LD_POKE:cd8d" },
		{ "LD_POKE:cd9d" }, { "LD_POKE:cd10d" }, { "LD_POKE:cd11d" }, { "LD_POKE:cd12d" }, { "LD_POKE:cd13d" }, { "LD_POKE:cd1d" },

		{ "LD_POKE:cd2h" }, { "LD_POKE:cd3h" }, { "LD_POKE:cd4h" }, { "LD_POKE:cd5h" }, { "LD_POKE:cd6h" }, { "LD_POKE:cd7h" }, { "LD_POKE:cd8h" },
		{ "LD_POKE:cd9h" }, { "LD_POKE:cd10h" }, { "LD_POKE:cd11h" }, { "LD_POKE:cd12h" }, { "LD_POKE:cd13h" }, { "LD_POKE:cd1h" },

		{ "LD_POKE:cd2s" }, { "LD_POKE:cd3s" }, { "LD_POKE:cd4s" }, { "LD_POKE:cd5s" }, { "LD_POKE:cd6s" }, { "LD_POKE:cd7s" }, { "LD_POKE:cd8s" },
		{ "LD_POKE:cd9s" }, { "LD_POKE:cd10s" }, { "LD_POKE:cd11s" }, { "LD_POKE:cd12s" }, { "LD_POKE:cd13s" }, { "LD_POKE:cd1s" }
};

#define BACKGROUND                      Start[ playerid ]
#define CARDSTEXT                       Start[ playerid ] + PlayerText:1
#define HOLDSTEXT                       Start[ playerid ] + PlayerText:6
#define WIN_TEXT                        Start[ playerid ] + PlayerText:11
#define WINTEXT                         Start[ playerid ] + PlayerText:12
#define BETCREDITTEXT                   Start[ playerid ] + PlayerText:13
#define DEALSTEXT                       Start[ playerid ] + PlayerText:14
#define ADDCOINSTEXT                    Start[ playerid ] + PlayerText:15
#define EXITPOKER                       Start[ playerid ] + PlayerText:16
#define BETTEXT                         Start[ playerid ] + PlayerText:17
#define CHANGEBACKGROUND        	    Start[ playerid ] + PlayerText:18

#define FIRST_CLICKDEALTEXT             0
#define SECOND_CLICKDEALTEXT            1
#define WAIT_CLICKDEALTEXT              -1
#define HOLDON          (false)
#define HOLDOFF 	    (true)

forward TextDrawDizajn( playerid, index );
forward TextDrawDizajn2( playerid, win, rank, first, second );

new bool:rdy = false;

enum Poker_PlayerInfoEnum {

	fivecards_hand[10],
	bool:holdstate[5],
	click_dealbutton,
	PokerBet,
	Credit,
	LastBackGround
};

new PP_Info[ MAX_PLAYERS ][ Poker_PlayerInfoEnum ];

new BackGroundData[][] =
{
		{ "LOADSUK:loadscuk" }, { "LOADSUK:loadsc9" },  { "LOADSUK:loadsc8" },
		{ "LOADSUK:loadsc7" },  { "LOADSUK:loadsc6" },  { "LOADSUK:loadsc5" },
		{ "LOADSUK:loadsc4" },  { "LOADSUK:loadsc3" },  { "LOADSUK:loadsc2" },
		{ "LOADSUK:loadsc14" }, { "LOADSUK:loadsc13" }, { "LOADSUK:loadsc12" },
		{ "LOADSUK:loadsc11" }, { "LOADSUK:loadsc10" }, { "LOADSUK:loadsc1" },
		{ "intro1:intro1" },    { "intro2:intro2" },    { "intro3:intro3" },
		{ "intro4:intro4" },    { "ld_shtr:bstars" },   { " " }
};

//================================[ GPS ]=======================================

//-------------------------[ BEOGRADSKI GPS ]------------------------------------
#define MAX_BGGPS														         500
#define F_BGGPS							     		 			"GPS/BeogradskiGPS/BGgps_%i.ini"

enum BGgpsData
{
	BGgpsName[ 50 ],
	Float:BGgpsPos[ 3 ]
};
new BGgpsInfo[ MAX_BGGPS ][ BGgpsData ];

//-------------------------[ SARAJEVSKI GPS ]------------------------------------
#define MAX_SAGPS														         500
#define F_SAGPS							     		 			"GPS/SarajevskiGPS/SAgps_%i.ini"

enum SAgpsData
{
	SAgpsName[ 50 ],
	Float:SAgpsPos[ 3 ]
};
new SAgpsInfo[ MAX_SAGPS ][ SAgpsData ];


//-------------------------[ ZAGREBACKI GPS ]------------------------------------
#define MAX_ZGGPS														         500
#define F_ZGGPS							     		 			"GPS/ZagrebackiGPS/ZGgps_%i.ini"

enum ZGgpsData
{
	ZGgpsName[ 50 ],
	Float:ZGgpsPos[ 3 ]
};
new ZGgpsInfo[ MAX_ZGGPS ][ ZGgpsData ];


//-------------------------[ OSTALE LOKACIJE GPS ]------------------------------------
#define MAX_OSGPS														         500
#define F_OSGPS							     		 			"GPS/OstaleGPS/OSgps_%i.ini"

enum OSgpsData
{
	OSgpsName[ 50 ],
	Float:OSgpsPos[ 3 ]
};
new OSgpsInfo[ MAX_OSGPS ][ OSgpsData ];


#define GPS_TYPE_VAZNEL 1
#define GPS_TYPE_SALONI 2
#define GPS_TYPE_OSTALO 3

enum {
	SIMPLE_GPS, // obelezava samo na radaru
	MEDIUM_GPS, // simple + pravi checkpoint i ispisuje razdaljinu
	ADVANCED_GPS// simple + medius + pokazuje putanju do cilja
};

#define MAPPED_NONE     -1
#define MAPPED_IMPORTANT 0
#define MAPPED_HOUSE     1
#define MAPPED_BUSINESS  2
#define MAPPED_JOB       3

new pMappedType[ MAX_PLAYERS ] = {MAPPED_NONE, MAPPED_NONE, MAPPED_NONE, ...};

enum _pgr {
	_pgrIconId,
	Float:_pgrPos[ 3 ],
	_pgrCheckPointId,
	_pgrObject
}

new PlayerGpsRadar[ MAX_PLAYERS ][_pgr];
new PlayerText:PlayerGpsRadarText[ MAX_PLAYERS ];

//===============================[ Garaze ]=====================================

#define MAX_GARAGES														     200
#define F_GARAGE							     		 "Garages/Garage_%i.ini"

enum garageData {
	bool:garageOwned,
	garageOwner[ MAX_PLAYER_NAME ],
	garagePrice,
	garageLevel,
	bool:garageLocked,
	Float:garagePos[ 3 ],
	Float:garageVehiclePos[ 4 ],
	garageVW,
	garageType,
	Text3D:garage3D,
	garagePickup
};
new garageInfo[ MAX_GARAGES ][ garageData ];

new Float:GarageInteriors[][] = {
	{ 616.4642, -124.4003, 997.5993, 90.0, 3.0 }, // Small garage
	{ 617.0011, -74.6962, 997.8426, 90.0, 2.0 }, // Medium garage
	{ 606.4268, -9.9375, 1000.7485, 270.0, 1.0 } //Big garage

};

//===============================[ GangZone ]===================================

#define MAX_GZONE 														     100
#define F_GZONE								     		    "Zones/gZone_%i.ini"

enum gZoneData {

	bool:gZoneTaken,
	bool:gZoneTakeable,
	gZoneGangID,
	gZoneTime,
	
	Float:gZoneMaxX,
	Float:gZoneMinX,
	Float:gZoneMaxY,
	Float:gZoneMinY,

	gZoneColor[ 24 ],
	Text3D:gZone3D,
	gZonePickup,
	Float:gZonePickupPos[ 3 ],
	gZoneID,
	gZoneRectAngle
};
new gZoneInfo[ MAX_GZONE ][ gZoneData ];

new CreatingGZone[ MAX_PLAYERS ];
new CreatingGZoneID[ MAX_PLAYERS ];
new gZone_ID[ MAX_PLAYERS ];
new gZone_Time[ MAX_PLAYERS ];
new gZone_Timer[ MAX_PLAYERS ];

//================================[ Imanje ]====================================

#define MAX_FIELDS 														     500
#define MAX_STALKS													        5000
#define F_FIELD								     		   "Fields/Field_%i.ini"
#define F_STALK								     "Fields/Stabljike/Stalk_%i.ini"

#define BILJKA_SLJIVA 1
#define BILJKA_KRUSKA 2
#define BILJKA_JABUKA 3
#define BILJKA_KUPUS  4
#define BILJKA_RUZE   5

enum fieldData {
	bool:fieldOwned,
	fieldOwner[ MAX_PLAYER_NAME ],
	fieldPrice,
	fieldLevel,
	Float:fieldMaxX,
	Float:fieldMinX,
	Float:fieldMaxY,
	Float:fieldMinY,
	fieldObject,
	Float:fieldObjectPos[ 6 ],
	Text3D:field3D,
	fieldPickup,
	fieldStalkNumber,
	fieldRectAngle,
	fieldTractorID, // edit ovo dodano
	fieldAdditionID,
	fieldTruckID,
	
	bool:fieldCow_1_Placed,
	fieldCow_1_Object,
	Float:fieldCow_1_Pos[ 6 ],
	
	bool:fieldCow_2_Placed,
	fieldCow_2_Object,
	Float:fieldCow_2_Pos[ 6 ],// edit ovo dodano
	
	bool:fieldCow_3_Placed,
	fieldCow_3_Object,
	Float:fieldCow_3_Pos[ 6 ]
};
new fieldInfo[ MAX_FIELDS ][ fieldData ];

enum stalks {
	sfieldID,
	sObjectID,
	Float:sPos[ 3 ],
	bool:sPlanted,
	bool:sGrow,
	sType,
	sObject,
	sMinut,
	sHour,
	Text3D:s3D
};
new stalkInfo[ MAX_STALKS ][ stalks ];

new CreatingThing[ MAX_PLAYERS ];
new CreatingField[ MAX_PLAYERS ];
new Float:CreatingPos[ MAX_PLAYERS ][ 4 ];

//===============================[ Pumpe ]======================================

#define MAX_FSTATION      												      30
#define FSTATION_FILE     									"Pumpe/Pumpa_%d.ini"

enum FStation {

	bool:fsPlaced,
	fsBussinesID,
	fsGasolinePrice,
	fsGasolineL,
	fsDieselPrice,
	fsDieselL,
	fsGasPrice,
	fsGasL,
	fsGasOilPrice,
	fsGasOilL,
	fsName[ 64 ],
	Float:fsPos[ 3 ],
	fsTruckID,
	fsCisternID,
	fsPickup,
	Text3D:fs3d
};
new FuelStation[ MAX_FSTATION ][ FStation ];

//===============================[ Jelke ]======================================

#define MAX_CTREES      100
#define F_CTREES								  		    "Jelke/Jelka_%d.ini"
enum C_Tree {

	Float:ctPos[ 6 ],
	bool:ctPlaced,
	ctObject,
	Text3D:ct3d
};
new CTree[ MAX_CTREES ][ C_Tree ];

//===============================[ Lampe ]======================================

#define MAX_XORBS      200
#define F_XORBS								  		        "Lampe/Lampa_%d.ini"
enum XmasOrb {

	Float:xoPos[ 6 ],
	bool:xoPlaced,
	xoObject
};
new XmasOrbs[ MAX_XORBS ][ XmasOrb ];

//===============================[ ZIMA ]=======================================

#define NERP_ZIMSKI_MOD  0

//==============================[ Pokloni ]=====================================

#define MAX_PRESENTS       200

#define F_PRESENTS 								  		 "Pokloni/Poklon_%d.ini"

enum Presents {

	Float:presPos[ 6 ],
	bool:presPlaced,
	bool:presTaken,
	Text3D:pres3d,
	presObject
};
new presentsInfo[ MAX_PRESENTS ][ Presents ];

//==============================[ Organizacije ]================================

#define MAX_ORG 															  50
#define O_FILE 								  "Organizacije/Organizacija_%d.ini"
#define ORG_IME 															  64
#define ORG_RANK 															  64
#define ORG_CLAN  															  24
#define ORG_LIDER 															  24
#define PORT_FILE 							   "PortoviOrgi/Organizacija_%d.ini"

#define ORG_TIP_PD 	    1
#define ORG_TIP_BANDA 	2
#define ORG_TIP_MAFIJA  3
#define ORG_TIP_MC 		4
#define ORG_TIP_SR 		5
#define ORG_TIP_MD 		6
#define ORG_TIP_CNN 	7
#define ORG_TIP_HITM 	8
#define ORG_TIP_ELEK  	9
#define ORG_TIP_TAXI 	10
#define ORG_TIP_PS 	    11

#define CTIP_HEROIN    1
#define CTIP_KOKAIN    2
#define CTIP_BMETH     3
#define CTIP_MARIHUANA 4
#define CTIP_CRACK     5
#define CTIP_METH      6

enum oOrgInfo
{
	oID,
	oCreated,
	oName[ ORG_IME ],
	oPreFix[ 10 ],
	oColor[ 24 ],

	oTip,
	oSuspended,
	oMaxClanova,
	oUbacenihClanova,

	oSkin1,
	oSkin2,
	oSkin3,
	oSkin4,
	oSkin5,
	oSkin6,
	
	oZSkin1,
	oZSkin2,
	oZSkin3,
	oZSkin4,
	oZSkin5,
	oZSkin6,

	oLider1[ ORG_LIDER ],
	oLider2[ ORG_LIDER ],

	oClan1[ ORG_CLAN ],
	oClan2[ ORG_CLAN ],
	oClan3[ ORG_CLAN ],
	oClan4[ ORG_CLAN ],
	oClan5[ ORG_CLAN ],
	oClan6[ ORG_CLAN ],
	oClan7[ ORG_CLAN ],
	oClan8[ ORG_CLAN ],
	oClan9[ ORG_CLAN ],
	oClan10[ ORG_CLAN ],
	oClan11[ ORG_CLAN ],
	oClan12[ ORG_CLAN ],
	oClan13[ ORG_CLAN ],
	oClan14[ ORG_CLAN ],
	oClan15[ ORG_CLAN ],
	oClan16[ ORG_CLAN ],
	oClan17[ ORG_CLAN ],
	oClan18[ ORG_CLAN ],
	oClan19[ ORG_CLAN ],
	oClan20[ ORG_CLAN ],
	oClan21[ ORG_CLAN ],
	oClan22[ ORG_CLAN ],
	oClan23[ ORG_CLAN ],
	oClan24[ ORG_CLAN ],
	oClan25[ ORG_CLAN ],
	oClan26[ ORG_CLAN ],
	oClan27[ ORG_CLAN ],
	oClan28[ ORG_CLAN ],
	oClan29[ ORG_CLAN ],
	oClan30[ ORG_CLAN ],

	oRank1[ ORG_RANK ],
	oRank2[ ORG_RANK ],
	oRank3[ ORG_RANK ],
	oRank4[ ORG_RANK ],
	oRank5[ ORG_RANK ],
	oRank6[ ORG_RANK ],

	Float:oPozExtX,
	Float:oPozExtY,
	Float:oPozExtZ,

	Float:oPozIntX,
	Float:oPozIntY,
	Float:oPozIntZ,

	Float:oDutyPoint[ 3 ],
	oDutyInt,
	oDutyVW,
	Float:oEquipPoint[ 3 ],
	oEquipInt,
	oEquipVW,

	oSavez,
	
	oMaxPort,
	oControlType,
	Float:oDrugField[ 3 ],
	Float:oSafePos[ 3 ],
	oSafeMoney,
	#if nerp_droga == 1
	oSafeDrug[ 4 ],
	oSafeDrugCode[ 4 ],
	#endif
	oInt,
	oVw,
	ImaDrugFactory,
	Float:oDrugFactoryPos[3],
	ImaGarage,
	Float:oGaragePos[3]
}
new OI[ MAX_ORG ][ oOrgInfo ];
new OrgPickup[ MAX_ORG ];
new Text3D:Org3D[ MAX_ORG ];
new OrgPickup2[ MAX_ORG ];
new Text3D:Org3D2[ MAX_ORG ];
new Text3D:OrgDuty3D[ MAX_ORG ];
new Text3D:OrgEquip3D[ MAX_ORG ];
new DutyPointPickup[ MAX_ORG ];
new EquipPointPickup[ MAX_ORG ];
new OrgFieldPickup[ MAX_ORG ];
new Text3D:OrgField3d[ MAX_ORG ];
new OrgSafePickup[ MAX_ORG ];
new Text3D:OrgSafe3d[ MAX_ORG ];

new DrugFactoryPickup[ MAX_ORG ];
new DrugFactoryPickup2[ MAX_ORG ];

new GaragePickup[MAX_ORG];
new GaragePickup2[MAX_ORG];

new Text3D:DrugFactory3d[ MAX_ORG ];
new Text3D:DrugFactory3d2[ MAX_ORG ];
#define DrugFactoryCoords 2260.0447,-1158.3065,542.5454
#define DrugFactoryInt 0

new Text3D:Garage3d[ MAX_ORG ];
new Text3D:Garage3d2[ MAX_ORG ];
#define GarageCoords 2522.9365,-1546.1592,2023.5740
#define GarageInt 0

enum Portes {
	Float:Pos1[ 3 ],
	Float:Pos2[ 3 ],
	Int[ 2 ],
	VW[ 2 ],
	Pickup[ 2 ]
}
new PortOP[ MAX_ORG ][ 10 ][ Portes ];

//===============================[ Kapije ]=====================================

#define MAX_GATES 															 100
#define GATE_FILE 								  			"Kapije/Gate_%d.ini"

enum gateData {
	gateOwner[ MAX_PLAYER_NAME ],
	bool:gateOpened,
	gateFor,
	gateOrgID,
	gateModel,
	Float:gateSpeed,
	Float:gateRadius,
	gateTime,
	Float:gatePos[ 6 ],
	gateInterior,
	gateWorld,
	Float:gateMove[ 6 ],
	gateTimer,
	gateObject
};

new GateData[ MAX_GATES ][ gateData ];

new EditDGate[ MAX_PLAYERS ],
	EditDGateMove[ MAX_PLAYERS ];

//================================[ Droga ]=====================================

#if nerp_droga == 1

#define MAX_PLANTS                          701

enum PlantaInfo {
	wObjectID,
	wPlanted,
	wHoursPassed,
	wViwo,
	wType,
	wOwner[ MAX_PLAYER_NAME ],
	Float:Plantx,
	Float:Planty,
	Float:Plantz
};
new DrogaStab[ MAX_PLANTS ][ PlantaInfo ];

#endif
//==================================[ WAR ]=====================================

#define MAX_WARS 20

enum WAR {
	bool:WARKreiranje,
	bool:WARAktivan,
	WARTimSkor[ 2 ],
	WAROruzje[ 4 ],
	WARMapa,
	WARMaxClanova,
	WARTimClanovi[ 2 ],
	WARTimLider[ 2 ],
	WARTimer,
	WARTeamID[ 2 ],
	TimerWARSec,
	TimerWARMin,
	TimerWAROstaloVreme,
	WARCena
}
new WARInfo[ MAX_WARS ][ WAR ];

enum WARI {
	bool:WARTim[ 2 ],
	WARUbistva,
	WARSmrti,
	WARIgrac
}
new WARPInfo[ MAX_PLAYERS ][ WARI ];

new DailyTips[][] =
{
	"Owner: Skopsi",
	"Direktor: Mata",
	"Skripter: DEntisT",
	"Nova Era RolePlay",
	"Maper: Mata",
	"SuVlasnik: NE",
	"Hoster: Skopsi",
	"Lepo se provedite!",
	"Pomoc na: /pitaj",
	"Hvala Vam!",
	"Omogucio igru: Skopsi"
};

new PromenjljivePoruke[][] =
{
	"Ako vam treba pomoc pitajte na /pitaj...",
	"Listu lidera mozete vidjeti na /lideri...",
	"Postujte pravila i ta pravila ce postovati vas!",
	"Za ulazak u neku organizaciju morate biti level 3...",
	"Sve lokacije mozete naci na /gps.",
	"Nova Era: Online Gaming Community - dobrodosli na nas server!",
	"Listu RolePlay pravila pogledajte na listi pravila, kucajte komandu '/pravila'...",
	"Ako vam se svidja server pozovite i vase drugare",
	"Svaka vrsta vredjanja strogo se kaznjava",
	"Ako nemate posao zaposlite se u opstini i na birou rada!",
	"Hvala Vam sto podrzavate nas rad na serveru!"
};


//===============================[ Kontejneri ]=================================

#define KO_FILE 	 							     	     "Kontejneri/%i.ini"
#define MAX_KONT 														     100

enum kont {

	Float:koObjPos[ 3 ],
	Float:koObjRot[ 3 ],
	koObjID,
	Text3D:KontText3D
}
new KontInfo[ MAX_KONT ][ kont ];

//===============================[ Mrtvaci:) ]==================================

#define BODY_FILE                                             "MrtvaTela/%i.ini"
#define MAX_BODIES                                                   MAX_PLAYERS

#define IME_IGRACA_DUZINA_STRINGA                                            300

enum body {

	Float:bodyObjPos[3],
	bodyObjID,
	Text3D:bodyText3D,
	bodyImeIgraca[IME_IGRACA_DUZINA_STRINGA]
}
new bodyInfo[ MAX_BODIES ][ body ];

//new deadbody_dynamic_object[MAX_PLAYERS][MAX_BODIES];
//===============================[ Ulice ]==================================

#define STREET_FILE                                               "Ulice/%i.ini"
#define MAX_STREETS 100

enum street_data {

	Float:streetObjPos[3],
	Text3D:streetText3D
}
new streetInfo[ MAX_STREETS ][ street_data ];
new streetPickup[MAX_STREETS];
//===============================[ Rents ]==================================

#define RENT_PICKUPID 19131
#define RENT_FILE                                               "MestaZaRent/%i.ini"
#define MAX_RENTS 100

enum rent_data {

	Float:rentObjPos[3],
	Text3D:rentText3D
}
new rentInfo[ MAX_RENTS ][ rent_data ];
new rentPickup[MAX_RENTS];

//===============================[ Dileri ]==================================

#define DEALER_FILE                                  "Dileri/%i.ini"
#define MAX_DEALERS 100

enum dealer_data {

	Float:dealerPos[3],
	Text3D:dealerText3D,
	Organizacija
}
new DealerInfo[ MAX_DEALERS ][ dealer_data ];
new DealerActor[MAX_DEALERS];


//===============================[ Bankomati ]==================================

#define ATM_FILE 								     	      "Bankomati/%i.ini"
#define MAX_ATM 														     300

enum atmDataa {
	bool:atmPreseceneZice,
	bool:atmProbijenBios,
	atmVremeDoRoba,
	bool:atmExists,
	Float:atmPos[6],
	atmObject,
	Text3D:atmText3D
};
new atmInfo[ MAX_ATM ][ atmDataa ];

//new PlayerBar:playeratmBar[ MAX_PLAYERS ] = { INVALID_PLAYER_BAR_ID, ...},
new atmrobTimer[ MAX_PLAYERS ],
	robbingATMSeconds[ MAX_PLAYERS ],
	robbingATM[ MAX_PLAYERS ];


//================================[ Tuning ]====================================

enum PaintjobInfi {
	vehID,
	pNumber,
	pPrice,
	pNameBre[ 12 ]
};
#define NUMBER_TYPE_PAINTJOB 	36
new	pjInfo[ NUMBER_TYPE_PAINTJOB ][ PaintjobInfi ] = {
	{ 483, 0, 100, "Paintjob 1" },
	{ 534, 0, 100, "Paintjob 1" },
	{ 534, 1, 100, "Paintjob 2" },
	{ 534, 2, 100, "Paintjob 3" },
	{ 535, 0, 100, "Paintjob 1" },
	{ 535, 1, 100, "Paintjob 2" },
	{ 535, 2, 100, "Paintjob 3" },
	{ 536, 0, 100, "Paintjob 1" },
	{ 536, 1, 100, "Paintjob 2" },
	{ 536, 2, 100, "Paintjob 3" },
	{ 558, 0, 100, "Paintjob 1" },
	{ 558, 1, 100, "Paintjob 2" },
	{ 558, 2, 100, "Paintjob 3" },
	{ 559, 0, 100, "Paintjob 1" },
	{ 559, 1, 100, "Paintjob 2" },
	{ 559, 2, 100, "Paintjob 3" },
	{ 560, 0, 100, "Paintjob 1" },
	{ 560, 1, 100, "Paintjob 2" },
	{ 560, 2, 100, "Paintjob 3" },
	{ 561, 0, 100, "Paintjob 1" },
	{ 561, 1, 100, "Paintjob 2" },
	{ 561, 2, 100, "Paintjob 3" },
	{ 562, 0, 100, "Paintjob 1" },
	{ 562, 1, 100, "Paintjob 2" },
	{ 562, 2, 100, "Paintjob 3" },
	{ 565, 0, 100, "Paintjob 1" },
	{ 565, 1, 100, "Paintjob 2" },
	{ 565, 2, 100, "Paintjob 3" },
	{ 567, 0, 100, "Paintjob 1" },
	{ 567, 1, 100, "Paintjob 2" },
	{ 567, 2, 100, "Paintjob 3" },
	{ 575, 0, 100, "Paintjob 1" },
	{ 575, 1, 100, "Paintjob 2" },
	{ 576, 0, 100, "Paintjob 1" },
	{ 576, 1, 100, "Paintjob 2" },
	{ 576, 2, 100, "Paintjob 3" }
};

#if !defined YSI_WEAPDATA_MAX_STRING_SIZE
	#define YSI_WEAPDATA_MAX_STRING_SIZE (24)
#endif

#define WEAPONDATA_NO_AMMO 			"Nepoznat ammo"
#define WEAPONDATA_45ACP 			".45 ACP"
#define WEAPONDATA_9MM 				"9mm"
#define WEAPONDATA_12GUAGE			"12 Guage"
#define WEAPONDATA_556MM			"5.56mm"
#define WEAPONDATA_762MM			"7.62mm"
#define WEAPONDATA_300MAGNUM		".300 Magnum"
#define WEAPONDATA_ROCKET			"Rocket"
#define WEAPONDATA_INVALID_RETURN 	-1

stock YSI_g_WeaponAmmoNames[47][YSI_WEAPDATA_MAX_STRING_SIZE] = {
	WEAPONDATA_NO_AMMO, //{"Fist", 0, 0, 0 },
	WEAPONDATA_NO_AMMO, //{"Brass Knuckles", 1, 0, 331 },
	WEAPONDATA_NO_AMMO, //{"Golf Club", 2, 1, 333 },
	WEAPONDATA_NO_AMMO, //{"Nightstick", 3, 1, 334 },
	WEAPONDATA_NO_AMMO, //{"Knife", 4, 1, 335 },
	WEAPONDATA_NO_AMMO, //{"Baseball Bat", 5, 1, 336 },
	WEAPONDATA_NO_AMMO, //{"Shovel", 6, 1, 337 },
	WEAPONDATA_NO_AMMO, //{"Pool Cue", 7, 1, 338 },
	WEAPONDATA_NO_AMMO, //{"Katana", 8, 1, 339 },
	WEAPONDATA_NO_AMMO, //{"Chainsaw", 9, 1, 341 },
	WEAPONDATA_NO_AMMO, //{"Double-ended Dildo", 10, 10, 321 },
	WEAPONDATA_NO_AMMO, //{"Dildo", 11, 10, 321 },
	WEAPONDATA_NO_AMMO, //{"Vibrator", 12, 10, 323 },
	WEAPONDATA_NO_AMMO, //{"Silver Vibrator", 13, 10, 324 },
	WEAPONDATA_NO_AMMO, //{"Flowers", 14, 10, 325 },
	WEAPONDATA_NO_AMMO, //{"Cane", 15, 10, 326 },
	WEAPONDATA_NO_AMMO, //{"Grenade", 16, 8, 342 },
	WEAPONDATA_NO_AMMO, //{"Tear Gas", 17, 8, 343 },
	WEAPONDATA_NO_AMMO, //{"Molotov Cocktail", 18, 8, 344 },
	WEAPONDATA_NO_AMMO, //{"No gun", 19, -1, 0 },
	WEAPONDATA_NO_AMMO, //{"No gun", 20, -1, 0 },
	WEAPONDATA_NO_AMMO, //{"No gun", 21, -1, 0 },
	WEAPONDATA_45ACP, //{"Colt .45", 22, 2, 346 },
	WEAPONDATA_45ACP, //{"Silenced Colt .45", 23, 2, 347 },
	WEAPONDATA_45ACP, //{"Desert Eagle", 24, 2, 348 },
	WEAPONDATA_12GUAGE, //{"Shotgun", 25, 3, 349 },
	WEAPONDATA_12GUAGE, //{"Sawnoff Shotgun", 26, 3, 350 },
	WEAPONDATA_12GUAGE, //{"Combat Shotgun", 27, 3, 351 },
	WEAPONDATA_9MM, //{"Micro SMG", 28, 4, 352 },
	WEAPONDATA_9MM, //{"MP5", 29, 4, 353 },
	WEAPONDATA_762MM, //{"AK47", 30, 5, 355 },
	WEAPONDATA_556MM, //{"M4", 31, 5, 356 },
	WEAPONDATA_9MM, //{"Tec-9", 32, 4, 372 },
	WEAPONDATA_762MM, //{"Country Rifle", 33, 6, 357 },
	WEAPONDATA_300MAGNUM, //{"Sniper Rifle", 34, 6, 358 },
	WEAPONDATA_ROCKET, //{"RPG", 35, 7, 359 },
	WEAPONDATA_ROCKET, //{"HS Rocket", 36, 7, 360 },
	WEAPONDATA_NO_AMMO, //{"Flamethrower", 37, 7, 361 },
	WEAPONDATA_762MM, //{"Minigun", 38, 7, 362 },
	WEAPONDATA_NO_AMMO, //{"Satchel Charge", 39, 8, 363 },
	WEAPONDATA_NO_AMMO, //{"Detonator", 40, 12, 364 },
	WEAPONDATA_NO_AMMO, //{"Spraycan", 41, 9, 365 },
	WEAPONDATA_NO_AMMO, //{"Fire Extinguisher", 42, 9, 366 },
	WEAPONDATA_NO_AMMO, //{"Camera", 43, 9, 367 },
	WEAPONDATA_NO_AMMO, //{"Night Vis Goggles", 44, 11, 368 },
	WEAPONDATA_NO_AMMO, //{"Thermal Goggles", 45, 11, 369 },
	WEAPONDATA_NO_AMMO  //{"Parachute", 46, 11, 371 }
};


//==================================[ Server ]==================================

#if defined notverzija_jebise
new verzija[][] ={"v1.0"};
#endif
#define MAP_NAME    										   	        "Balkan"
#define D_ODABERI 												   	   "Potvrdi"
#define D_ODUSTANI 													  "Odustani"
#define D_NAZAD 													     "Nazad"
#define D_NASLOV                          ""col_sanm"N{FFFFFF}ova "col_sanm"E{FFFFFF}ra | Server panel"
#define UKLJUCEN 															   1
#define ISKLJUCEN 															   0

//==================================[ Script ]==================================

#define SPD                                                     ShowPlayerDialog
#define SCMA 											  SendClientMessageToAll
#define DSL 												   DIALOG_STYLE_LIST
#define IPI 												   INVALID_PLAYER_ID
#define DSI                                                   DIALOG_STYLE_INPUT
#define DSP                                                DIALOG_STYLE_PASSWORD
#define DSMSG 												 DIALOG_STYLE_MSGBOX

// SISTEMSKE DEFINICIJE: by - DEntisT

#define SERVERBOJA_ZELENA col_sanm //"{dea41f}""{2bde1f}"
#define SERVERBOJA_CRVENA "{de1f1f}" //neka lijepa crvena
#define SERVERBOJA_PLAVA "{1f50de}"
#define SERVERBOJA_BJELA "{ffffff}" // bijela braski
#define SERVERBOJA_MRKVA "{dea41f}" // narandzasta, mrsko mi bilo pisat i da definisem al jbg
#define SERVERBOJA_ZUTA "{e3e33a}"
#define SERVERBOJA_CRNA "{000000}"
#define SERVERBOJA_AQUA col_sanm//"{1fdedb}" // neka fina plava
#define SERVERBOJA_SIVA "{C0C7CD}"
#define SERVERBOJA_ME "{A080CC}" // ona ljubicasta za /me i /do
#define SERVERBOJA_TAMNOZELENA col_sanm// "{de1f1f}""{28792d}"
#define SERVERBOJA_SC "{d98056}" //ŠUAMURASTA BOJA (SC)
#define SERVERBOJA_SCZ "{CEE07B}" // sranje zelena neka
#define SERVERBOJA_AC "{B48CA3}" //anticit boja
#define SERVERBOJA_SCRVENA "{EB603F}" //svetlo crvena
#define SERVERBOJA_ROZA "{CF8CF5}"

#define scmex scmex_temp

#define GRESKA(%0,%1) \
	PlayerPlaySound(%0, 1057, 0.0, 0.0, 10.0), ascmex(%0, CRVENA, "[ERROR] {ffffff} "%1) //PlayerPlaySound(playerid, 1052, 0.0, 0.0, 10.0);
//PlayerPlaySound(playerid, 1052, 0.0, 0.0, 10.0);
#define SendErrorMessage GRESKA
#define greska GRESKA

#define SendJobMessage(%0,%1) \
	ascmex(%0, -1, ""col_job"[POSAO]{FFFFFF} "%1)
// CONNECT SISTEM
new Text:connect0;
new Text:connect1;
new Text:connect2;
new Text:connect3;
new Text:connect4;
new Text:connect5;

//=================================[ Imovina ]==================================

#define IM_FILE 								     			"Imovina/%i.ini"
#define MAX_IMOVINA 													    1500

#define IMOVINA_KUCA  													       1
#define IMOVINA_STAN 												   		   2
#define IMOVINA_VIKENDICA													   3


//------------------------------|| KUCE INFO ||---------------------------------

#define MALA_KUCA 													   		   1
#define SREDNJA_KUCA 													   	   2
#define VELIKA_KUCA 													   	   3
#define VILA_KUCA 													   		   4

//****************************************************************************** 

#define MALA_KUCA_X                                                     210.6244
#define MALA_KUCA_Y                                                    1753.7417
#define MALA_KUCA_Z                                                    3334.3245
#define MALA_KUCA_PRICE                                                   300000
#define MALA_KUCA_INT                                                          0

//******************************************************************************

#define SREDNJA_KUCA_X                                                  243.4017
#define SREDNJA_KUCA_Y                                                -1851.6646
#define SREDNJA_KUCA_Z                                                 3334.0142
#define SREDNJA_KUCA_PRICE                                                500000
#define SREDNJA_KUCA_INT                                                       0

//******************************************************************************  

#define VELIKA_KUCA_X                                                  1686.5939
#define VELIKA_KUCA_Y                                                  3843.7190
#define VELIKA_KUCA_Z 													  8.1524
#define VELIKA_KUCA_PRICE                                                 750000
#define VELIKA_KUCA_INT                                                       1

//****************************************************************************** 

#define VILA_KUCA_X                                                    2324.4497
#define VILA_KUCA_Y                                                   -1149.3311
#define VILA_KUCA_Z                                                    1050.7650
#define VILA_KUCA_PRICE                                                  1000000
#define VILA_KUCA_INT                                                         12



//------------------------------|| STANOVI INFO ||------------------------------

#define MALI_STAN 															   1
#define SREDNJI_STAN 														   2
#define VELIKI_STAN 														   3

//******************************************************************************  

#define MALI_STAN_X                                                    1697.2965
#define MALI_STAN_Y                                                   -1417.4133
#define MALI_STAN_Z                                                     37.3903
#define MALI_STAN_PRICE                                                   300000
#define MALI_STAN_INT                                                          2

//******************************************************************************

#define SREDNJI_STAN_X                                                  311.8771
#define SREDNJI_STAN_Y                                                 1798.1016
#define SREDNJI_STAN_Z                                                  646.6362
#define SREDNJI_STAN_PRICE                                                500000
#define SREDNJI_STAN_INT                                                       2

//******************************************************************************

#define VELIKI_STAN_X                                                    88.7848
#define VELIKI_STAN_Y                                                  1702.7692
#define VELIKI_STAN_Z 												 100001.3594
#define VELIKI_STAN_PRICE                                                 750000
#define VELIKI_STAN_INT                                                        2

//******************************************************************************



//------------------------------|| VIKENDICE INFO ||----------------------------

#define MALA_VIKENDICA 														   1
#define SREDNJA_VIKENDICA 													   2
#define VELIKA_VIKENDICA									   				   3

//******************************************************************************
// 2527.654052,-1679.388305,1015.498596
#define SREDNJA_VIKENDICA_X 2527.654052//2160.2871
#define SREDNJA_VIKENDICA_Y -1679.388305//-1172.6244
#define SREDNJA_VIKENDICA_Z 1015.498596//1029.8619
#define MALA_VIKENDICA_PRICE 300000
#define SREDNJA_VIKENDICA_INT 1

//******************************************************************************
//267.0919,305.1196,999.1484
#define MALA_VIKENDICA_X 267.0919
#define MALA_VIKENDICA_Y 305.1196
#define MALA_VIKENDICA_Z 999.1484
#define SREDNJA_VIKENDICA_PRICE 500000
#define MALA_VIKENDICA_INT 2

//******************************************************************************
// 2218.40 -1076.18 1050.48
#define VELIKA_VIKENDICA_X 2218.40
#define VELIKA_VIKENDICA_Y -1076.18
#define VELIKA_VIKENDICA_Z 1050.48
#define VELIKA_VIKENDICA_PRICE 750000
#define VELIKA_VIKENDICA_INT 1

//******************************************************************************
/*#define VIKENDICA_X                                                    2160.2871
#define VIKENDICA_Y                                                   -1172.6244
#define VIKENDICA_Z                                                    1029.8619
#define VIKENDICA_PRICE                                                   350000
#define VIKENDICA_INT 													       7*/
//------------------------------------------------------------------------------

// /xgoto 2160.2871, -1172.6244, 1029.8619


#define MAX_X_OBJECTS                                                       1200

new MozeNaMisiju[MAX_PLAYERS];
new bool:KoristioStuck[MAX_PLAYERS];
// RANJENJE HEALTH BAR
#define CLIENT_PC 0
#define CLIENT_MOBILE 1
new ClientType[MAX_PLAYERS];
new Text:healthbar0;
new Text:healthbar1;
new Text:healthbar2;
new PlayerText:phealthbar0[MAX_PLAYERS];
// RANJENJE
new Text:injured0;
new Text:injured1;
new Text:injured2;
new Text:injured3;
new Text:injured4;
new Text:injured5;
new Text:injured6;

// DEATHMATCH SISTEM
new Text:dmtext0;
new Text:dmtext1;
new Text:dmtext2;
new Text:dmtext3;
new Text:dmtext4;
new Text:dmtext5;
new Text:dmtext6;
new Text:dmtext7;

// DEATH SISTEM
new Text:Deathtext0;
new Text:Deathtext1;
new Text:Deathtext2;
new Text:Deathtext3;
new Text:Deathtext4;
new Text:Deathtext5;
new Text:Deathtext6;
new Text:Deathtext7;
new Text:Deathtext8;
new Text:Deathtext9;
// UCITAVANJE OBJEKATA
new Text:UO0;
new Text:UO1;
new Text:UO2;
new Text:UO3;
new Text:UO4;
new Text:UO5;
new Text:UO6;
new Text:UO7;
new Text:UO8;
new Text:UO9;
new Text:UO10;
// KLADIONICA SISTEM
new Text:kladionica0;
new Text:kladionica1;
new Text:kladionica2;
new Text:kladionica3;
new Text:kladionica4;
new Text:kladionica5;
new Text:kladionica6;
//#define SPECIAL_ACTION_PISSING      68


new gPlayerUsingLoopingAnim[ MAX_PLAYERS ];
new gPlayerAnimLibsPreloaded[ MAX_PLAYERS ];
new g_NERP_Animation[ MAX_PLAYERS ];
//new PlayerText:AnimacijeTD[MAX_PLAYERS];



enum ComponentsInfo {
	cID,
	cName[ 40 ],
	cPrice,
	cType
};

#define MAX_COMPONENTS	194

new	cInfo[ MAX_COMPONENTS ][ ComponentsInfo ] = {
	{ 1000, "Pro Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1001, "Win Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1002, "Drag Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1003, "Alpha Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1004, "Champ Scoop Hood", 100, CARMODTYPE_HOOD },
	{ 1005, "Fury Scoop Hood", 100, CARMODTYPE_HOOD },
	{ 1006, "Roof Scoop Roof", 100, CARMODTYPE_ROOF },
	{ 1007, "Right Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1008, "5x Nitrous", 100, CARMODTYPE_NITRO },
	{ 1009, "2x Nitrous", 100, CARMODTYPE_NITRO },
	{ 1010, "10x Nitrous", 100, CARMODTYPE_NITRO },
	{ 1011, "Race Scoop Hood", 100, CARMODTYPE_HOOD },
	{ 1012, "Worx Scoop Hood", 100, CARMODTYPE_HOOD },
	{ 1013, "Round Fog Lamp", 100, CARMODTYPE_LAMPS },
	{ 1014, "Champ Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1015, "Race Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1016, "Worx Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1017, "Left Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1018, "Upswept Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1019, "Twin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1020, "Large Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1021, "Medium Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1022, "Small Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1023, "Fury Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1024, "Square Fog Lamp", 100, CARMODTYPE_LAMPS },
	{ 1025, "Offroad Wheels", 100, CARMODTYPE_WHEELS },
	{ 1026, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1027, "Left Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1028, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1029, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1030, "Left X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1031, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1032, "Alien Roof Vent", 100, CARMODTYPE_ROOF },
	{ 1033, "X-Flow Roof Vent", 100, CARMODTYPE_ROOF },
	{ 1034, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1035, "X-Flow Roof Vent", 100, CARMODTYPE_ROOF },
	{ 1036, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1037, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1038, "Alien Roof Vent", 100, CARMODTYPE_ROOF },
	{ 1039, "Left X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1040, "Left Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1041, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1042, "Right Chrome Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1043, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1044, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1045, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1046, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1047, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1048, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1049, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1050, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1051, "Left Alien Sideskirt", 100, CARMODTYPE_SPOILER },
	{ 1052, "Left X-Flow Sideskirt", 100, CARMODTYPE_SPOILER },
	{ 1053, "X-Flow Roof", 100, CARMODTYPE_ROOF },
	{ 1054, "Alien Roof", 100, CARMODTYPE_ROOF },
	{ 1055, "Alien Roof", 100, CARMODTYPE_ROOF },
	{ 1056, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1057, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1058, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1059, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1060, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1061, "X-Flow Roof", 100, CARMODTYPE_ROOF },
	{ 1062, "Left Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1063, "Left X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1064, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1065, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1066, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1067, "Alien Roof", 100, CARMODTYPE_ROOF },
	{ 1068, "X-Flow Roof", 100, CARMODTYPE_ROOF },
	{ 1069, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1070, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1071, "Left Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1072, "Left X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1073, "Shadow Wheels", 100, CARMODTYPE_WHEELS },
	{ 1074, "Mega Wheels", 100, CARMODTYPE_WHEELS },
	{ 1075, "Rimshine Wheels", 100, CARMODTYPE_WHEELS },
	{ 1076, "Wires Wheels", 100, CARMODTYPE_WHEELS },
	{ 1077, "Classic Wheels", 100, CARMODTYPE_WHEELS },
	{ 1078, "Twist Wheels", 100, CARMODTYPE_WHEELS },
	{ 1079, "Cutter Wheels", 100, CARMODTYPE_WHEELS },
	{ 1080, "Switch Wheels", 100, CARMODTYPE_WHEELS },
	{ 1081, "Grove Wheels", 100, CARMODTYPE_WHEELS },
	{ 1082, "Import Wheels", 100, CARMODTYPE_WHEELS },
	{ 1083, "Dollar Wheels", 100, CARMODTYPE_WHEELS },
	{ 1084, "Trance Wheels", 100, CARMODTYPE_WHEELS },
	{ 1085, "Atomic Wheels", 100, CARMODTYPE_WHEELS },
	{ 1086, "Stereo Wheels", 100, CARMODTYPE_STEREO },
	{ 1087, "Hydraulics", 100, CARMODTYPE_HYDRAULICS },
	{ 1088, "Alien Roof", 100, CARMODTYPE_ROOF },
	{ 1089, "X-Flow Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1090, "Right Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1091, "X-Flow Roof", 100, CARMODTYPE_ROOF },
	{ 1092, "Alien Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1093, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1094, "Left Alien Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1095, "Right X-Flow Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1096, "Ahab Wheels", 100, CARMODTYPE_WHEELS },
	{ 1097, "Virtual Wheels", 100, CARMODTYPE_WHEELS },
	{ 1098, "Access Wheels", 100, CARMODTYPE_WHEELS },
	{ 1099, "Left Chrome Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1100, "Chrome Grill", 100, -1 }, // Bullbar
	{ 1101, "Left `Chrome Flames` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1102, "Left `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1103, "Covertible Roof", 100, CARMODTYPE_ROOF },
	{ 1104, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1105, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1106, "Right `Chrome Arches`", 100, CARMODTYPE_SIDESKIRT },
	{ 1107, "Left `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1108, "Right `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1109, "Chrome", 100, -1 }, // Bullbar
	{ 1110, "Slamin", 100, -1 }, // Bullbar
	{ 1111, "Little Sign?", 100, -1 }, // sig
	{ 1112, "Little Sign?", 100, -1 }, // sig
	{ 1113, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1114, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1115, "Chrome", 100, -1 }, // Bullbar
	{ 1116, "Slamin", 100, -1 }, // Bullbar
	{ 1117, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1118, "Right `Chrome Trim` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1119, "Right `Wheelcovers` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1120, "Left `Chrome Trim` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1121, "Left `Wheelcovers` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1122, "Right `Chrome Flames` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1123, "Bullbar Chrome Bars", 100, -1 }, // Bullbar
	{ 1124, "Left `Chrome Arches` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1125, "Bullbar Chrome Lights", 100, -1 }, // Bullbar
	{ 1126, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1127, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1128, "Vinyl Hardtop", 100, CARMODTYPE_ROOF },
	{ 1129, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1130, "Hardtop Roof", 100, CARMODTYPE_ROOF },
	{ 1131, "Softtop Roof", 100, CARMODTYPE_ROOF },
	{ 1132, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1133, "Right `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1134, "Right `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1135, "Slamin Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1136, "Chrome Exhaust", 100, CARMODTYPE_EXHAUST },
	{ 1137, "Left `Chrome Strip` Sideskirt", 100, CARMODTYPE_SIDESKIRT },
	{ 1138, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1139, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1140, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1141, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1142, "Left Oval Vents", 100, CARMODTYPE_VENT_LEFT },
	{ 1143, "Right Oval Vents", 100, CARMODTYPE_VENT_RIGHT },
	{ 1144, "Left Square Vents", 100, CARMODTYPE_VENT_LEFT },
	{ 1145, "Right Square Vents", 100, CARMODTYPE_VENT_RIGHT },
	{ 1146, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1147, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1148, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1149, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1150, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1151, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1152, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1153, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1154, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1155, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1156, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1157, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1158, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1159, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1160, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1161, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1162, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1163, "X-Flow Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1164, "Alien Spoiler", 100, CARMODTYPE_SPOILER },
	{ 1165, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1166, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1167, "X-Flow Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1168, "Alien Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1169, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1170, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1171, "Alien Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1172, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1173, "X-Flow Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1174, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1175, "Slamin Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1176, "Chrome Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1177, "Slamin Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1178, "Slamin Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1179, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1180, "Chrome Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1181, "Slamin Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1182, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1183, "Slamin Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1184, "Chrome Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1185, "Slamin Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1186, "Slamin Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1187, "Chrome Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1188, "Slamin Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1189, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1190, "Slamin Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1191, "Chrome Front Bumper", 100, CARMODTYPE_FRONT_BUMPER },
	{ 1192, "Chrome Rear Bumper", 100, CARMODTYPE_REAR_BUMPER },
	{ 1193, "Slamin Rear Bumper", 100, CARMODTYPE_REAR_BUMPER }
};


enum tpi {
	tID,
	tType,
	bool:tPaintjob,
	PJColor[ 2 ]
};
new TPInfo[ MAX_PLAYERS ][ tpi ];

#define MAX_GOBJ 3000
enum dGunEnum {
	Float:ObjPos[ 3 ],
	gObjID,
	ObjData[ 2 ],
	PUBG
};
new dGunData[ MAX_GOBJ ][ dGunEnum ];

////////////////////////ANIMACIJE////////////////////

new animtimer2[MAX_PLAYERS];

//=================================[ Vozila ]===================================

#define V_FILE 								     				 "Vozila/%i.ini"
#define MAX_CARS 															1500

#define PRIVATNO_VOZILO 													   1
#define ORGANIZACIJSKO_VOZILO 												   2
#define POSLOVNO_VOZILO 													   3
#define RENTANO_VOZILO 													   	   4
#define GRADONACELNIKOVO_VOZILO 											   5
#define IZLOZBENO_VOZILO 											   		   6
#define ADMIN_VOZILO 											   		       7
#define PROMOTER_VOZILO 											   		   8
#define VIP_VOZILO 											   		   		   9
#define POLAGANJE_VOZILO 											   		  10
#define HELPER_VOZILO 											   		      11
#define PUMPA_VOZILO 											   		      12
#define IMANJE_VOZILO                                              			  13 // edit ovo dodano
#define NAPRODAJU_VOZILO 													  14
#define PUBG_VOZILO                                                           15
#define RENT_VOZILO                                               RENTANO_VOZILO

enum vVoziloInfo {
	vOwned,
	vPrice,
	vOwner[ MAX_PLAYER_NAME ],
	vLocked,
	Float:vLokacijaX,
	Float:vLokacijaY,
	Float:vLokacijaZ,
	Float:vLokacijaA,
	vVirtualWorld,
	vInterior,
	vUsage,
	vJob,
	vOrganization,
	vFuelProperty,
	vColor1,
	vColor2,
	vModel,
	vTeh,
	vReg,
	vRegVreme,
	vTablice[ 16 ],
	vGPS,
	vOsiguranje,
	vLock,
	vAlarm,
	vFuel,
	vFuelType,
	vNeon,
	vTuned,
	vImobilizator,
	vSpoiler,
	vHood,
	vRoof,
	vSkirt,
	vLamps,
	vNitro,
	vExhaust,
	vWheels,
	vStereo,
	vHydraulics,
	vFrontBumper,
	vRearBumper,
	vVents,
	vPaintJob,
	vProvera,
	#if nerp_droga == 1
	vDrug[ 6 ],
	vDrugCode[ 6 ],
	#endif
	vMaterijali,
	vMelee,
	vWeap1,
	vAmmo1,
	vWeap2,
	vAmmo2,
	vGajbica[ 5 ],
	vGajbicaAmmount[ 5 ],
	vNeaktivnost,
	vKilometri,
	vMetri,
	bool:Validv3DText,
	Text3D:v3DText,
	vID

}
new VehicleInfo[ MAX_CARS ][ vVoziloInfo ];

new BHKrajTimer[MAX_PLAYERS];
new animtimer[MAX_PLAYERS];

enum obj_info
{

	f_Model,
	Float:f_X,
	Float:f_Y,
	Float:f_Z,
	Float:f_rX,
	Float:f_rY,
	Float:f_rZ,
	f_VW,
	f_Object
};
new Furniture[ MAX_IMOVINA ][ MAX_X_OBJECTS ][ obj_info ];

new ObjectEdition_TYPE[ MAX_PLAYERS ];

enum Imovina
{
	iOwned,
	iOwner[ MAX_PLAYER_NAME ],
	iUsage,
	Float:iEnter[ 3 ],
	Float:iExit[ 3 ],
	iPrice,
	iLocked,
	iInterior,
	iVW,
	iVrsta,
	iOrmar,
	iSkin[ 3 ],
	iSafeStatus,
	iSafePass,
	iOruzje[ 4 ],
	iMunicija[ 4 ],
	#if nerp_droga == 1
	iDrug[ 10 ],
	iDrugCode[ 10 ],
	#endif
	iDoorLevel,
	iAlarm,
	iLockLevel,
	iTime,
	Float:iPizzaTime,
	iLevel,
	iAdress[ 38 ],
	iNeaktivnost,
	iRentable,
	iRentPrice,
	iRentovano,
	iMats,
	iMoney
};
new II[ MAX_IMOVINA ][ Imovina ];
new ImovinaPickup[ MAX_IMOVINA ];
new Text3D:ImovinaLabel[ MAX_IMOVINA ];

//=================================[ Hoteli ]===================================

#define MAX_HOTELS 															 100
#define HOTEL_FILE 								     	    	 "Hoteli/%i.ini"

enum hotelData {
	hOwned,
	hOwner[ MAX_PLAYER_NAME ],
	Float:hEnter[ 3 ],
	Float:hExit[ 3 ],
	hInterior,
	hVW,
	hPrice,
	hLocked,
	hLevel,
	hAdress[ 38 ],
	hRoomPrice,
	hMoney,
	hGuest_1[ MAX_PLAYER_NAME ],
	hGuest_2[ MAX_PLAYER_NAME ],
	hGuest_3[ MAX_PLAYER_NAME ],
	hGuest_4[ MAX_PLAYER_NAME ],
	hGuest_5[ MAX_PLAYER_NAME ],
	hGuest_6[ MAX_PLAYER_NAME ],
	hGuest_7[ MAX_PLAYER_NAME ],
	hGuest_8[ MAX_PLAYER_NAME ],
	hGuest_9[ MAX_PLAYER_NAME ],
	hGuest_10[ MAX_PLAYER_NAME ],
	hPorez,
	hVrednostPoreza,
	hPickup,
	Text3D:h3DText
}
new hotelInfo[ MAX_HOTELS ][ hotelData ];

//================================[ Saloni ]====================================

#define MAX_AUTOS 															 100
#define AS_FILE 								     		 "AutoSaloni/%i.ini"

enum aVtoSalo
{
	aMaxVehModel,
	aVehModel[ 50 ],
	aVehAmmount[ 50 ],
	Float:aVehBuyedPos[ 4 ],
	Float:aPickupPos[ 3 ],
	Float:aCameraPos[ 3 ],
	Float:aCameraLookAt[ 3 ],
	Text3D:AutoSalon3D,
	AutoSalonPickup,
	aVW,
	aInt,
	aIzlogVeh,
	bool:AlreadyBuying
}
new AutoSalon[ MAX_AUTOS ][ aVtoSalo ];
new PlayerBuyingAS[ MAX_PLAYERS ];
new ModelCar[ MAX_PLAYERS ];
new AutoSalonBojaVozila[ MAX_PLAYERS ];

enum noclipenum {
	bool:cameramode,
	flyobject,
	mode,
	lrold,
	udold,
	lastmove,
	Float:accelmul
}
new flymodecamera[ MAX_PLAYERS ][noclipenum];

#define MOVE_FORWARD    		1
#define MOVE_BACK       		2
#define MOVE_LEFT       		3
#define MOVE_RIGHT      		4
#define MOVE_FORWARD_LEFT       5
#define MOVE_FORWARD_RIGHT      6
#define MOVE_BACK_LEFT          7
#define MOVE_BACK_RIGHT         8
#define MOVE_SPEED              100.0
#define ACCEL_RATE              0.03

//=================================[ Firme ]====================================

#define F_FILE 								     				  "Firme/%i.ini"
#define MAX_BUSSINES													     200
#define VRSTA_MARKET 														   1
#define VRSTA_JFIRMA 														   2
#define VRSTA_BURG 															   3
#define VRSTA_CLUCK															   4
#define VRSTA_BINCO															   5
#define VRSTA_ZIP														       6
#define VRSTA_VICTIM														   7
#define VRSTA_SUBURBAN														   8
#define VRSTA_GUNSHOP														   9
#define VRSTA_GYM														      10 
#define VRSTA_BAR														      11
#define VRSTA_RESTORAN														  12
#define VRSTA_PIZZA															  13
#define VRSTA_NKLUB 														  14
#define VRSTA_DISCO 														  15
#define VRSTA_ELEKTRONIK                                					  16
#define VRSTA_TRAFIKA                                					  	  17
#define VRSTA_POSAO                             					  	      18
#define VRSTA_RENT                             					  	      	  19
#define VRSTA_PUMPA                            					  	      	  20
#define VRSTA_JAVNAK                            					      	  21
#define VRSTA_KLAD                           					      	  	  22
#define VRSTA_OGLAS                         					      	  	  23
#define VRSTA_TELEKOM                         					      	  	  24
#define VRSTA_PAYSPRAY                         					      	  	  25
#define VRSTA_KOMUNALIJE                         					      	  26
#define VRSTA_VODOVOD                     					      	 		  27
#define VRSTA_ELEKTRANA                      					      	      28
#define VRSTA_LUTRIJA                     					      	          29
#define VRSTA_CASINO                   					      	              30
#define VRSTA_NEON                    					      	              31
#define VRSTA_RODA                   					      	              32

enum fInformacije
{
	bOwned,
	bPrice,
	bOwner[ MAX_PLAYER_NAME ],
	bType,
	bLocked,
	bMoney,
	Float:bEnterX,
	Float:bEnterY,
	Float:bEnterZ,
	Float:bExitX,
	Float:bExitY,
	Float:bExitZ,
	bInt,
	bVW,
	bInInt,
	bInVW,
	bName[ 64 ],
	bLevel,
	bJobID,
	bNeaktivnost,
	bFacture,
	bReket,
	Float:bReketTime
}
new BussinesInfo[ MAX_BUSSINES ][ fInformacije ];
new FirmaPickup[ MAX_BUSSINES ];
new Text3D:FirmaLabel[ MAX_BUSSINES ];

//=================================[ AntiCit ]==================================

#define ResetujBarNovac 									    ResetPlayerMoney
#define UpdejtujBarNovac 									     GivePlayerMoney
//==================================[ Anims ]===================================

stock SendUsageMessage(id, const str[] ) {
	//SendClientMessage(id, -1, "{CEE07B}|| UPOTREBA KOMANDE ||: "SERVERBOJA_SIVA"Niste upotrijebili komandu kako treba, te radnja nije izvrsena - probajte ovako!");
	new str2[200];
	format(str2, sizeof(str2), "#"col_balkanstory"NE-RP{ffffff} HELP"col_balkanstory": "SERVERBOJA_SIVA"Koristi ovako:{ffffff} %s", str);
	SendClientMessage(id, tdboja, str2 );
	PlayerPlaySound(id, 1052, 0.0, 0.0, 10.0);
	UnknownCmdControl(id, true);
	SetTimerEx("HideUnkCmd", 3500, false, "i", id);
	return 1;
}

/*#define SendUsageMessage(%0,%1) \
	showucmd(%0),SetTimerEx( "hideucmdd", 3000, false, "i", %0 ),PlayerPlaySound(%0, 1052, 0.0, 0.0, 10.0),SendClientMessageEx(%0, -1, ""SERVERBOJA_AQUA"[cmd] {FFFFFF}Koristenje: "%1)
*/
// ========================================
#define SendInfoMessage(%0,%1) \
	PlayerPlaySound(%0, 1055, 0.0, 0.0, 10.0), ascmex(%0, 0x86C6DBAA, "[INFO] {ffffff}"%1)
	//ascmex(%0, tdboja, "{ffffff}#"col_balkanstory"NOVA {ffffff}ERA"col_balkanstory":{FFFFFF} "%1) // plava {2e9cd1}

#define scminfo SendInfoMessage

#define SendClientMessageEx scmex

#define SendAcMessage(%0,%1) \
	SetTimerEx("antiskmsg",2000,0,"i",%0), PlayerPlaySound(%0, 1059, 0.0, 0.0, 10.0), ascmex(%0, CRVENA, "[INFO] {FFFFFF} "%1) // plava {2e9cd1}

/*lol*/

#define SendTipMessage(%0,%1) \
	ascmex(%0, -1, "{9000FF}[TIPS] {FFFFFF} "%1)

#define sms(%0,%1) \
	PlayerPlaySound(%0, 1057, 0.0, 0.0, 10.0), ascmex(%0, -1, ""SERVERBOJA_MRKVA"SMS - Telecom | Tekst:{FFFFFF} "%1)

#define SendOrgMessage(%0,%1) \
	ascmex(%0, -1, ""SERVERBOJA_AQUA"[org]{FFFFFF} "%1)

#define SendSrwMessage(%0,%1) \
	ascmex(%0, tdboja, "{ffffff}#"col_balkanstory"NOVA {ffffff}ERA"col_balkanstory": {ffffff}"%1)

// SISTEMSKE DEFINICIJE: by - DEntisT | KRAJ

stock DEntisT_num_dash( number ) 
{
	new dash = 2, num2 = 42, qwert = 23, i = 364;
	new DASHit = num2 * dash + qwert, DASHED_VALUE = DASHit / 7 + i;
	number = DASHED_VALUE;
	return number;
}

forward DRKANJE(playerid);

new bool:PDuty[MAX_PLAYERS];

#define CJ_SKIN 0

new RandomMSG [] [] =
{
	"Dobrodosli na nas server - zelimo Vam ugodnu i zabavnu igru!",
	"Reklamiranjem nase zajednice, mozete postati promoter!",
	"Specijalni V.I.P. paket mozete naruciti na nasem forumu!",
	"Listu komandi mozete dobiti kucajuci '/pomoc' komandu!",
	"Ukoliko ne poznajete ovaj virtualni svijet bas najboljie - koristite GPS! (/gps)",
	"Policija je tu da nadgleda grad i da Vas stiti od kriminalaca!",
	"Ne postovanje se kaznjava na nasem serveru!",
	"Pridruzite se nekoj od fascinantnih organizacija na nasem serveru!",
	"Postujte RolePlay pravila i zaradite RP poene!",
	"Staff Team Vam zeli ugodnu igru kod nas!",
	"Trebate li pomoc - kucajte komandu '/pitaj'.",
	"Promjenite Vasu odjecu u prodavaonicama za odjecu! ( Binco, Suburban, Zip itd... )",
	"Ukoliko trebate lijecenje, pozovite hitnu pomoc!",
	"Zapalili ste Vas dom? Ukoliko da, odmah - zovite vatrogasnu sluzbu!",
	"Posjetite nas Discord server, te se zabavite na istom uz muziku i igre!",
	"Zapratite nas na ostalim drustvenim mrezama!",
	"Ukoliko ga primjetite, molimo Vas - prijavite BUG staff timu!",
	"Zabavite se radeci razne poslove na nasem serveru!",
	"Promoteri mogu reklamirati svake 2 minute!",
	"Master V.I.P. paket ne moze isteci, preporucujemo - odmah ga nabavite! (9$ RL)",
	"Ukoliko zelite ugasiti ove poruke, mozete kucati '/togchat'.",
	"Unesite komandu '/odjecahelp' da bi ste manipulisali odjecom i dodacima na njoj!",
	"Na 'Newbie' (/n) chat-u cete moci pisati sve dok ne navrsite nivo 11. (/noff)",
	"'Newbie' chat je vidiljiv samo za staff i sve igrace ispod levela 10! (/togn)",
	"Svu aparaturu nabavite u Gigatronu...",
	"Posjetite nas forum, te se registrujte - hvala unaprijed! (www.uskoro.rs)",
	"Hvala Vam sto podrzavate nas rad!",
	"Greske u mapi servera prijavite maper timu zajednice!",
	"Komandom '/mojaplata' mozete pogledati koliko novca imate na platnom racunu!",
	"Najlepsu konfiguraciju chat-a mozete postignuti sa komandama: '/fontsize 0', '/pagesize 10'",
	"Ukoliko su vam ostali ukljuceni DM Zone tdovi >> /izadjisadm",
	"U bolnici mozete kupiti paket za prvu pomoc! >> /prvapomoc",
	"Admini su tu za vas! Kucajte: >> /pitaj",
	"Kucajte '/itds' za upravljanje interaktivnim textdrawovima!"
};
new RandomMSG2 [] [] =
{
	"Nogometni tim 'S.W.A.T.' je uspjesno odigrao trening utakmicu!",
	"Rukometski Tim 'Los Santos Vagos' je uspjesno odigrao trening utakmicu!",
	"Vaterpolo tim 'Groove Street Families' je uspjesno odigrao trening utakmicu!",
	"Nogometni tim 'Yakuza' je uspjesno odigrao trening utakmicu!",
	"Odbojkaski tim 'Da Nang Boys' je uspjesno odigrao trening utakmicu!",
	"Rukometski tim 'L.S.P.D.' je uspjesno odigrao trening utakmicu!",
	"Golf tim 'Ballas Family' je uspjesno odigrao trening utakmicu!",
	"Nogometni klub 'Los Actecaz' je uspjesno odigrao trening utakmicu!",
	"Kick-box klub 'The Rifa Gang' je upravo odrzao box mec!",
	"Radio: Nema informacija i novosti koje Vam mozemo sada saopstiti!"
};
new RandomMSG3 [] [] =
{
	"Opasni dileri - pazite se podmuklog podmicivanja!",
	"Uvoz novih artikala u firme je izvrsen!",
	"Strasno - upravo smo dobili dojavu da je u ratu bandi povredjeno nekoliko ljudi!",
	"Nova hapsenja su se dogodila u gradu!",
	"Hitna pomoc, policija i vatrogasna sluzba su tu za vas!",
	"Vecina firmi je otvorila vrata novim zaposlenicima!",
	"Hvala gradjanima koji redovno doniraju gradu!",
	"Molimo policiju da uhvate kriminalce koji svakodnevno haraju gradom!",
	"Gradonacelnik je upravo odrzao sastanak sa ministrom vijeca!",
	"NEMA VIJESTI - Trenutno nemamo novosti koje vam mozemo saopstiti!"
};

new RandomMSG4 [] [] =
{
	"Svi korisnicki racuni su sacuvani u bazi podataka!",
	"Firme su osvjezene u bazi podataka!",
	"'Un-Rent' i 'respawn' provjere vozila su uspjesno zavrsene!",
	"Igraci su uspjesno osvjezeni!",
	"Ucitavanje i azuriranje sistema servera je upravo zavrseno!",
	"Izvinjavamo se zbog LAG-a. | Ucitavanje objekata mape servera je upravo izvrseno!",
	"Datoteke organizacija u bazi podataka su upravo osvjezene!",
	"Databaza servera je uspjesno osvjezena!",
	"Kompilacijske greske u skripti nisu pronadjene - uzivajte u igranju!",
	"Preporucujemo administraciji da redovno odrzava server putem RCON sistema!",
	"Verzija servera: beta - by DEntisT | Hvala Vam sto ste sa nama!"
};

new RandomMSG5 [] [] =
{
	"[RASPRODAJA] Ukoliko stedite novac, market Tempo je pravo mjesto za vas!",
	"[RASPRODAJA] Prodavaonica Interex, mjesto sa najnizim cijenama!",
	"[OBAVESTENJE] Narodna banka - sigurnost Vaseg novca je na nama!",
	"[SNIZENJE] Ogromna snizenja cijena satova u zlatari su u toku!",
	"[SNIZENJE] Cijena odjece u Bincu je snizena cak i do 70 posto!",
	"[OBAVESTENJE] Mozete kupiti Vase naocale u optici Suburban!",
	"[SNIZENJE] Najljepsi sesiri u butiku Binco mogu biti vasi po cijeni od nekoliko dolara!",
	"[RASPRODAJA] Prodavaonica Zip vrsi rasprodaju zadnjih modela ranaca, kaciga i bandana!",
	"[SNIZENJE] Snizenja u butiku Victim na mnogobrojne artikle su ogromna!",
	"[OBAVESTENJE] SuperMarket Bingo - tu smo da Vam nudimo najkvalitetniju hranu!",
	"[SNIZENJE] Gradska apoteka - Vase zdravlje je nas zadatak!",
	"[VAZNO] Utovar i uvoz produkata u nove firme je u toku!"
};


//==============================[ Spawn ]=======================================

#define SPAWN_NERP 100
#define SPAWN_OBICAN_LS_1													   0
#define SPAWN_BAZA														   	   1
#define SPAWN_IMOVINA_1														   2
#define SPAWN_IMOVINA_2														   3
#define SPAWN_IMOVINA_3														   4
#define SPAWN_BELAKUCA 														   5
#define SPAWN_OBICAN_LS_2													   6
#define SPAWN_OBICAN_SF														   7
#define SPAWN_RENTHOTEL														   8
#define SPAWN_ADMIN														       9
#define SPAWN_PROMOTER													      10
#define SPAWN_RENT													      	  11
#define SPAWN_HELPER													   	  12
#define SPAWN_VIP													   	  	  13

//===========================[ Tekstdraws ]=====================================

new PlayerText:CKilometri[ MAX_PLAYERS ][ 4 ];
new PlayerText:BuyCar[ MAX_PLAYERS ][ 20 ];
new PlayerText:ASBojaVozila[ 21 ][ MAX_PLAYERS ];
new PlayerText:ZaposljavanjeTD[ MAX_PLAYERS ][ 9 ];
new PlayerText:WARTextDraw[ MAX_PLAYERS ][ 9 ];
new PlayerText:Ormar[ MAX_PLAYERS ][ 10 ];
new PlayerText:ObjektTD[ MAX_PLAYERS ][ 6 ];
new PlayerText:Police_TV[ MAX_PLAYERS ][ 15 ];
//new PlayerText:LoginTD[ MAX_PLAYERS ][ 29 ];
//new PlayerText:UGRegisterTD[ MAX_PLAYERS ][ 35 ];
new PlayerText:RegisterTD[ MAX_PLAYERS ][ 14 ];
new PlayerText:PVreme[ MAX_PLAYERS ];
new PlayerText:PlayerStats[ 32 ][ MAX_PLAYERS ];
new PlayerText:PizzaMenu[ MAX_PLAYERS ][ 25 ];
//new PlayerText:atmTD[ MAX_PLAYERS ][ 14 ];
new PlayerText:atmrobLoading[ MAX_PLAYERS ][ 2 ];
new PlayerText:buyWatch[ MAX_PLAYERS ][ 8 ];
new PlayerText:TuningBuy[ MAX_PLAYERS ][ 14 ];
new PlayerText:Fading[ MAX_PLAYERS ];
//new Text:TDEditor_PTD[MAX_PLAYERS][1];
// REGISTER SISTEM
new PlayerText:Regtd0[MAX_PLAYERS];
new PlayerText:Regtd1[MAX_PLAYERS];
new PlayerText:Regtd2[MAX_PLAYERS];
new PlayerText:Regtd3[MAX_PLAYERS];
new PlayerText:Regtd4[MAX_PLAYERS];
new PlayerText:Regtd5[MAX_PLAYERS];
new PlayerText:Regtd6[MAX_PLAYERS];
new PlayerText:Regtd7[MAX_PLAYERS];
new PlayerText:Regtd8[MAX_PLAYERS];
new PlayerText:Regtd9[MAX_PLAYERS];
new PlayerText:Regtd10[MAX_PLAYERS];
new PlayerText:Regtd11[MAX_PLAYERS];
new PlayerText:Regtd12[MAX_PLAYERS];
new PlayerText:Regtd13[MAX_PLAYERS];
new PlayerText:Regtd14[MAX_PLAYERS];
new PlayerText:Regtd15[MAX_PLAYERS];
new PlayerText:Regtd16[MAX_PLAYERS];
new PlayerText:Regtd17[MAX_PLAYERS];
new PlayerText:Regtd18[MAX_PLAYERS];
new PlayerText:Regtd19[MAX_PLAYERS];
new PlayerText:Regtd20[MAX_PLAYERS];
new PlayerText:Regtd21[MAX_PLAYERS];
new PlayerText:Regtd22[MAX_PLAYERS];
new PlayerText:Regtd23[MAX_PLAYERS];
new PlayerText:Regtd24[MAX_PLAYERS];
new PlayerText:Regtd25[MAX_PLAYERS];
new PlayerText:Regtd26[MAX_PLAYERS];
new PlayerText:Regtd27[MAX_PLAYERS];
new PlayerText:Regtd28[MAX_PLAYERS];

new PlayerText:td0[MAX_PLAYERS];
new PlayerText:td1[MAX_PLAYERS];
new PlayerText:td2[MAX_PLAYERS];
new PlayerText:td3[MAX_PLAYERS];
new PlayerText:td4[MAX_PLAYERS];
new PlayerText:td5[MAX_PLAYERS];
new komunalac1pickup,
	komunalac2pickup,
	komunalac3pickup,
	mehanicarpickup,
	prevoznik1pickup,
	prevoznik2pickup,
	prevoznik3pickup,
	masinovodjapickup,
	kosactravepickup,
	taxipickup,
	gradjevinarpickup,
	dostavljacpicapickup,
	farmerpickup,
	busvozacpickup,
	rudarpickup,
	prevoznovcapickup,
	ribarpickup,
	pnamestajapickup,
	pepsiposaopickup,
	pilotpickup;


//=============================[ Dialozi ]======================================

#define dialog_REGISTER 										   			   1
#define dialog_COUNTRY 										   				   2
#define dialog_AGE								       		   				   3
#define dialog_MAIL										   	   				   4
#define dialog_ORGANIZACIJA          										   5
#define dialog_PHARMACY           										   	   6
#define dialog_ORGCREATE          										       7
#define dialog_ORGTIP           										       8
#define dialog_MARKETBUY	          										   9
#define dialog_ORGRANK1           										      10
#define dialog_ORGRANK2           										      11
#define dialog_ORGRANK3           										      12
#define dialog_ORGRANK4           										      13
#define dialog_ORGRANK5           										      14
#define dialog_ORGRANK6          										      15
#define dialog_ORGINT1          										      16
#define dialog_ORGINT2          										      17
#define dialog_SERVERMI          										      18
#define dialog_NAPRAVISVE           										  19
#define dialog_IZBRISISVE          										      20
#define dialog_LIDER 														  21
#define dialog_UBACIUORG                                                      22
#define dialog_IZBACIIZORG                                                    23
#define dialog_DODELIRANK                                                     24
#define dialog_SVICLANOVI                                                     25
#define dialog_ORGDELETE 													  26
#define dialog_IZMENISVE 													  27
#define dialog_ORGEDIT 														  28
#define dialog_ORGNAME 	 													  29
#define dialog_ORGRANKS 													  30
#define dialog_CLUCKIN 														  31
#define dialog_RESTORAN														  32
#define dialog_PIZZA														  33
#define dialog_DRINK														  34
#define dialog_GUNSHOP														  35
#define dialog_FNAME														  36
#define dialog_FEDIT														  37
#define dialog_FSELL														  38
#define dialog_FOPEN														  39
#define dialog_FCLOSE														  40
#define dialog_APOENI														  41
#define dialog_M_ISPIT														  42
#define dialog_PCREATE														  43
#define dialog_VCREATE 														  44
#define dialog_KUPIKARTICU													  45
#define dialog_RADIO														  46
#define dialog_A_ISPIT														  47
#define dialog_K_ISPIT														  48
#define dialog_RENTANJE 													  49
#define dialog_RVCREATE 													  50
#define dialog_PROPERTYWEPTAKE 												  51
#define dialog_POSLOVIBG 													  52
#define dialog_EVENTSTART 													  53
#define dialog_CREATEEVENT													  54
#define dialog_CREATEEVENT2													  55
#define dialog_BUY_GPS 														  56
#define dialog_GPS		    												  57
#define dialog_FCREATE              										  58
#define dialog_FIRMA              										  	  59
#define dialog_FOMONEY              										  60
#define dialog_FPMONEY              										  61
#define dialog_FINFO              										  	  62
#define dialog_FLOCK              										  	  63
#define dialog_FCNAME              										  	  64
#define dialog_HVCREATE            										  	  65
#define dialog_ORGSPISAK													  66
#define dialog_BURGMENU 													  67
#define dialog_C2_ISPIT													      68
#define dialog_C3_ISPIT													      69
#define dialog_HELP 														  70
#define dialog_LOGIN 														  71
#define dialog_ORGLIST														  72
#define dialog_KREIRANJEKUCE												  73
#define dialog_ORMAR													  	  74
#define dialog_BUY_MOBILEPHONE												  75
#define dialog_SEARCH_NAME													  76
#define dialog_SEARCH_NUMBERPLATE											  77
#define dialog_POSTAVIPOTERU											      78
#define dialog_OCISTIDOSIJE											          79
#define dialog_OPREMA										          		  80
#define dialog_VEHICLEWEPTAKE									         	  81
#define dialog_MUNIFORM										          		  82
#define dialog_TAXIOFFER									          		  83
#define dialog_KIOSK									          		 	  84
#define dialog_SPAWNCHANGE									          		  85
#define dialog_PAYDAY 								          		  		  86
#define dialog_KREDIT								          		  		  87
#define dialog_INFOKREDIT								          		  	  88
#define dialog_PROMENARATEKREDITA								          	  89
#define dialog_BALANCE								          	  			  90
#define dialog_RPTEST								          	  			  91
#define dialog_BANSTATUS							          	  			  92
#define dialog_FDELETE						          	  			          93
#define dialog_IMDELETE					          	  			              94
#define dialog_OVCREATE				          	  			              	  95
#define dialog_CHANGEPASSWORD			          	  			              96
#define dialog_GPS_FIND     												  97
#define dialog_VEDIT    												      98
#define dialog_VPRICE    												      99
#define dialog_ICPRICE 														 100
#define dialog_IOPEN 														 101
#define dialog_ICLOSE 														 102
#define dialog_ISELL 														 103
#define dialog_ORGSKINS													     104
#define dialog_IEDIT 														 105
#define dialog_WAR														 	 106
#define dialog_WAR_ZAKAZI_1												 	 107
#define dialog_WAR_ZAKAZI_2												 	 108
#define dialog_WAR_ZAKAZI_3												 	 109
#define dialog_WAR_ZAKAZI_4												 	 110
#define dialog_WAR_ZAKAZI_5												 	 111
#define dialog_WAR_ZAKAZI_6												 	 112
#define dialog_WAR_ZAKAZI_7												 	 113
#define dialog_WAR_ZAKAZI_8												 	 114
#define dialog_WARUBACI													 	 115
#define dialog_WARIZBACI													 116
#define dialog_VIP	    													 117
#define dialog_IZMENABROJA 													 118
#define dialog_DOGLAS												 		 119
#define dialog_ORGPREFIX											 		 120
#define dialog_VCOLOR											 		     121
#define dialog_OFFIZBACIIZORG								 		         122
#define dialog_ORGDUTYP							 		         	 		 123
#define dialog_ORGEQUIPP						 		         	 		 124
#define dialog_PROPERTYLIST						 		         	 		 125
#define dialog_PROPCHOSEN						 		         	 		 126
#define dialog_PROPUNAPREDI						 		         	 		 127
#define dialog_SAFEPUTDRUG					 		         	 		     128
#define dialog_SAFETAKEDRUG					 		         	 		 	 129
#define dialog_SAFECHANGEPASS					 		         	 		 130
#define dialog_SAFEUNLOCK					 		         	 		 	 131
#define dialog_SAFEALL					 		         	 		 		 132
#define dialog_PROPSELLTP			 		         	 		 		 	 133
#define dialog_ACCEPTPROP			 		         	 		 		 	 134
#define dialog_ACCEPTFRIMA			 		         	 		 		 	 135
#define dialog_FIRMASELLTP			 		         	 		 		 	 136
#define dialog_ASMODEL			 		         	 		 		 	     137
#define dialog_ASMAXMODEL		 		         	 		 		 	     138
#define dialog_VEHCHOSEN		 		         	 		 		 	     139
#define dialog_VEHLIST		 		         	 		 		 	     	 140
#define dialog_VEHICLETAKEDRUG		         	 		 		 	     	 141
#define dialog_VEHICLEPUTDRUG		         	 		 		 	     	 142
#define dialog_GEPEKIZVADI  	 	 		 		 		 	 	      	 143
#define dialog_IVCREATE		         	 		 		 	     	 		 144
#define dialog_PORTABLE	         	 		 		 	     	 		 	 145
#define dialog_GIVEHIT	         	 		 		 	     	 		 	 146
#define dialog_HORDER	         	 		 		 	     	 		 	 147
#define dialog_RESETIRAJ	         	 		 		 	     	 		 148
#define dialog_SELECTSPORT	         	 		 		 	     	 		 149
#define dialog_CREATESPORT	         	 		 		 	     	 		 150
#define dialog_AVCREATE		         	 		 		 	     	 		 151
#define dialog_ANTICHEAT	         	 		 		 	     	 		 152
#define dialog_ANTICHEAT_2	         	 		 		 	     	 		 153
#define dialog_ANTICHEAT_3	         	 		 		 	     	 		 154
#define dialog_PROPSELLDRZAVA	         	 		 		 	     	 	 155
#define dialog_FIRMASELLDRZAVA	         	 		 		 	     	 	 156
#define dialog_POLVCREATE		 		 	     	 	 				     157
#define dialog_ORGPORTP 		 		 	     	 	 				     158
#define dialog_HOTEL		 		 	     	 	 				         159
#define dialog_HOTELRENTP	 		 	     	 	 				         160
#define dialog_HOTELIZBACI	 		 	     	 	 				         161
#define dialog_HPMONEY	 		 	     	 	 				          	 162
// DENTISTOVI DIALOZI:
#define dialog_HOMONEY	 		 	     	 	 				         	 163
#define dialog_HOTELLOCK 		 	     	 	 				         	 164
#define dialog_HOTELSELLDRZAVA	 	     	 	 				         	 165
#define dialog_HOTELSELLTP	 	     	 	 				         	 	 166
#define dialog_ACCEPTHOTEL	 	     	 	 				         	 	 167
#define dialog_HEDIT 	     	 	 				         	 	 		 168
#define dialog_HEPRICE 	     	 	 				         	 	 		 169
#define dialog_HELEVEL 	     	 	 				         	 	 		 170
#define dialog_POREZ	     	 	 				         	 	 		 171
#define dialog_POREZPAY	     	 	 				         	 	 		 172
#define dialog_EMAIL   	 	 				         	 	 		 		 173
#define dialog_CREATEGATE	 				         	 	 		 		 174
#define dialog_CREATEGATE_2 				         	 	 		 		 175
#define dialog_CREATEGATE_3 				         	 	 		 		 176
#define dialog_CREATEGATE_4 				         	 	 		 		 177
#define dialog_ORGZSKINS			         	 	 		 		 		 178
#define dialog_CREATEVEH			         	 	 		 		 		 179
#define dialog_GRCREATE			         	 	 		 		 		 	 180
#define dialog_ORGMAXMEMB	         	 	 		 		 		 	 	 181
#define dialog_PILOT	         	 	 		 		 		 	 	     182
#define dialog_CREATEFIELD         	 	 		 		 		 	 	     183
#define dialog_IMANJE       	 	 		 		 		 	 	         184
#define dialog_IMANJESELLDRZAVA	 		 		 		 	 	         	 185
#define dialog_IMANJESELLTP	 		 		 		 	 	         		 186
#define dialog_ACCEPTIMANJE	 		 		 		 	 	         		 187
#define dialog_IMEDIT       	 	 		 		 		 	 	         188
#define dialog_IMEPRICE       	 	 		 		 		 	 	         189
#define dialog_IMELEVEL       	 	 		 		 		 	 	         190
#define dialog_GEPEK      	 	 		 		 		 	 	        	 191
#define dialog_GEPEKOSTAVI      	 	 		 		 		 	 	     192
#define dialog_IZVADIGAJBICE  	 	 		 		 		 	 	     	 193
#define dialog_SERVERSTATS  	 	 		 		 		 	 	     	 194
#define dialog_SERVERSTATS_2	 	 		 		 		 	 	     	 195
#define dialog_SERVERSTATS_3	 	 		 		 		 	 	     	 196
#define dialog_SERVERSTATS_4	 	 		 		 		 	 	     	 197
#define dialog_CREATEGATE_5	 	 		 		 		 	 	     	 	 198
#define dialog_CREATEGATE_6	 	 		 		 		 	 	     	 	 199
#define dialog_CREATEGARAGE 	 		 		 		 	 	     	 	 200
#define dialog_GARAZA 	 		 		 		 	 	     	 	 		 201
#define dialog_GARAGELOCK	 		 		 		 	 	     	 	 	 202
#define dialog_ACCEPTGARAGE	 		 		 		 	 	     	 	 	 203
#define dialog_GARAGESELLDRZAVA	 		 		 		 	 	     	 	 204
#define dialog_GARAGESELLTP	 		 		 		 	 	     	 	 	 205
#define dialog_GEDIT		 		 		 	 	     	 	 	 		 206
#define dialog_GEPRICE		 		 		 	 	     	 	 	 		 207
#define dialog_GELEVEL		 		 		 	 	     	 	 	 		 208
#define dialog_CREATEGPS	 		 		 	 	     	 	 	 		 209
#define dialog_GPSEDIT	 		 		 	 	     	 	 	 		     210
#define dialog_IZMENAIMENAGPS	 		 		 	 	     	 	 	 	 211
#define dialog_IZMJENAIMENAGPSBG	 		 		 	 	     	 	 	 212
#define dialog_IZMENAPOZGPS	 		 		 	 	     	 	 	 		 213
#define dialog_CREATEAPORT 		 		 	 	     	 	 	 		     214
#define dialog_SELECTAPORT	 		 	 	     	 	 	 		     	 215
#define dialog_APORTEDIT		 	 	     	 	 	 		     	 	 216
#define dialog_IZMENAIMENAAPORT		 	 	     	 	 	 		     	 217
#define dialog_EDITAAPORTIMEBG		 	 	     	 	 	 		   	     218
#define dialog_IZMENAPOZAPORT		 	 	     	 	 	 		     	 219
#define dialog_SELECTVPORT		 	 	     	 	 	 		     	     220
#define dialog_SPORTEDIT	 	 	     	 	 	 		     	     	 221
#define dialog_IZMENAIMENASPORT	 	 	     	 	 	 		     	     222
#define dialog_IZMJENJENOIMESPORTBG	 	 	     	 	 	 		         223
#define dialog_IZMENAPOZSPORT	 	 	     	 	 	 		     	     224
#define dialog_CREATEJOBBUSSINES	 	 	     	 	 	 		         225
#define dialog_INVENTORY	 	 	     	 	 	 		         	     226
#define dialog_GIVEQUANTITY 	 	     	 	 	 		         	     227
#define dialog_GIVEITEM 	 	     	 	 	 		         	     	 228
#define dialog_ORGDRUGCHOSE	 	     	 	 	 		         	    	 229
#define dialog_ORGDRUGCHOSE_2	 	     	 	 	 		         	     230
#define dialog_PRCREATE	 	     	 	 	 		         	     		 231
#define dialog_ASAMMOUNT	 	     	 	 	 		         	     	 232
#define dialog_SELECTVGUN	 	     	 	 	 		         	     	 233
#define dialog_TUNING  	 	     	 	 	 		         	     	 	 234
#define dialog_TUNING_2	 	     	 	 	 		         	     	     235
#define dialog_VVCREATE	     	 	 	 		         	     	    	 236
#define dialog_UBACIUORG_2                                                   237
#define dialog_AUTOSEDIT                                                 	 238
#define dialog_ASEDITAMMOUNT                                                 239
#define dialog_BIRAJLOKACIJU                                                 240
#define dialog_VERIFIKACIJA                                                  241
#define dialog_CCTV                                                			 242
#define dialog_RADIOPLAY                                           			 243
#define dialog_LIDER_2                                          		 	 244
#define dialog_WAR_ZAKAZI_9                                     		 	 245
#define dialog_SELECTPPORT                                     		 	     246
#define dialog_IZAZOVITRKA                                     		 	     247
#define dialog_ORGSAFE                                    		 	         248
#define dialog_ORGSAFEPUT                                    		 	     249
#define dialog_ORGSAFETAKE                                    		 	     250
#define dialog_ORGSAFETMONEY                                    		     251
#define dialog_ORGSAFETDRUG                                    		 	     252
#define dialog_ORGSAFEPMONEY                                   		 	     253
#define dialog_ORGSAFEPDRUG                                   		 	     254
#define dialog_VEHCOLOR                                   		 	     	 255
#define dialog_VEHSELLTP                                  		 	     	 256
#define dialog_ACCEPTVEH                                  		 	     	 257
#define dialog_ASKLISTA                                 		 	     	 258
#define dialog_ASKLISTA_2                                 		 	     	 259
#define dialog_RENTABLE                                		 	     		 260
#define dialog_PROPTAKEMONEY                           		 	     		 261
#define dialog_PROPPUTMONEY                           		 	     		 262
#define dialog_ZAMENA_1                          		 	     		 	 263
#define dialog_ZAMENA_2                          		 	     		 	 264
#define dialog_ZAMENA_3                          		 	     		 	 265
#define dialog_ZAMENA_4                          		 	     		 	 266
#define dialog_RCONPROVERA                      		 	     		 	 267
#define dialog_CREATERADAR                     		 	     		 	 	 268
#define dialog_UPLATITIKET                    		 	     		 	 	 269
#define dialog_UPLATITIKET_2                    		 	     		 	 270
#define dialog_UPLATITIKET_3                    		 	     		 	 271
#define dialog_UPLATITIKET_4                    		 	     		 	 272
#define dialog_DONATORBOJA                    		 	     		 	     273
#define dialog_GANGZCOLOR                   		 	     		 	     274
#define dialog_ORGCOLOR                   		 	     		 	     	 275
#define dialog_GANGZEDIT                   		 	     		 	     	 276
#define dialog_GANGZCOLOREDIT                   		 	     		 	 277
#define dialog_GANGZID                   		 	     		 	     	 278
#define dialog_RULET_1                   		 	     		 	     	 279
#define dialog_RULET_2                   		 	     		 	     	 280
#define dialog_RULET_3                   		 	     		 	     	 281
#define dialog_RULET_4                   		 	     		 	     	 282
#define dialog_RULET_5                   		 	     		 	     	 283
#define dialog_SAVEZ                     		 	     		 	     	 284
#define dialog_VEHMONEYBUY               		 	     		 	     	 285
#define dialog_VEHGOLDBUY               		 	     		 	     	 286
#define dialog_IZABERITABLICE         		 	     		 	     	     287
#define dialog_IZABERITABLICE_2         		 	     		 	     	 288
#define dialog_DONATE         		 	     		 	     	 			 289
#define dialog_DONATE_1         		 	     		 	     	 		 290
#define dialog_VEHICLETAKEMATS  		 	     		 	     	 		 291
#define dialog_VEHICLEPUTMATS  		 	     		 	     	 		     292
#define dialog_SAFEPUTMATS   		 	     		 	     	 		     293
#define dialog_SAFETAKEMATS  		 	     		 	     	 		     294
#define dialog_CREATEFSTATION		 	     		 	     	 		     295
#define dialog_PUMPA        		 	     		 	     	 		     296
#define dialog_IMEPUMPE         		 	     		 	     	 	     297
#define dialog_DIZELCENA    		 	     		 	     	 		     298
#define dialog_BENZINCENA   		 	     		 	     	 		     299
#define dialog_GASNOCENA    		 	     		 	     	 		     300
#define dialog_FCORDEXIT    		 	     		 	     	 		     301
#define dialog_FEDITTYPE  		 	     		 	     	 		     	 302
#define dialog_DELIVERPEPSI	 	     		 	     	 		     	 	 303
#define dialog_NEONSHOP 	     		 	     	 		     	 		 304
#define dialog_PARKING	     		 	     	 		     	 		 	 305
#define dialog_PARKING_2	     		 	     	 		     	 		 306
#define dialog_PARKING_3	     		 	     	 		     	 		 307
#define dialog_fixcar                                                        308
#define dialog_fixcar2                                                       309
#define dialog_EDITPOSLOVA                                                   310

#define dialog_TG                                                         216372
#define dialog_ODJECA                                                     234234

//dialozi za poslove
#define dialog_KOSACPOSAO 													 311
#define dialog_GRADJEVINARPOSAO 											 312
#define dialog_GRADJEVINARPOSAO2 											 313
#define dialog_BUSVOZACPOSAO                                                 314
#define dialog_KOMUNALACPOSAO 												 315
#define dialog_KOMUNALACPOSAO2 												 316
#define dialog_KOMUNALACPOSAO3 												 317
#define dialog_ZAPOSLJAVANJE 												 318
//
#define dialog_KREIRANJESTANA                                                319
#define dialog_KREIRANJEVIKENDICE 											 320
#define dialog_PORTAJADMINABG 												 321
#define dialog_PORTAJADMINASA 												 322
#define dialog_PORTAJADMINAZG 												 323
#define dialog_PORTAJADMINAOS 												 324
#define dialog_EDITAPORTABG                                                  325
#define dialog_EDITAPORTASA                                                  326
#define dialog_EDITAPORTAZG                                                  327
#define dialog_EDITAPORTAOS                                                  328

#define dialog_EDITAPORTIMESA 												 329
#define dialog_EDITAPORTIMEZG 												 330
#define dialog_EDITAPORTIMEOS 												 331
#define dialog_EDITAPORTPOZICIJA                                             332
#define dialog_EDITAAPORTPOZBG 												 333
#define dialog_EDITAAPORTPOZSA 												 334
#define dialog_EDITAAPORTPOZZG 												 335
#define dialog_EDITAAPORTPOZOS 												 336

#define dialog_PORTAJGMABG 												 	 337
#define dialog_PORTAJGMASA 												 	 338
#define dialog_PORTAJGMAZG 												 	 339
#define dialog_PORTAJGMAOS 												 	 340

#define dialog_EDITIMENASPORTBG                                              341
#define dialog_EDITIMENASPORTSA                                              342
#define dialog_EDITIMENASPORTZG                                              343
#define dialog_EDITIMENASPORTOS                                              344


#define dialog_IZMJENJENOIMESPORTSA                                          345
#define dialog_IZMJENJENOIMESPORTZG                                          346
#define dialog_IZMJENJENOIMESPORTOS                                          347

#define dialog_IZMJENAPOZSPORTABG 											 348
#define dialog_IZMJENAPOZSPORTASA 											 349
#define dialog_IZMJENAPOZSPORTAZG 											 350
#define dialog_IZMJENAPOZSPORTAOS 											 351

#define dialog_BIRAGRADZAGPSLOC 											 352
#define dialog_BIRALOCGPSBG 												 353
#define dialog_BIRALOCGPSSA 												 354
#define dialog_BIRALOCGPSZG 												 355
#define dialog_BIRALOCGPSOS 												 356


#define dialog_BIRAGPSPOZBG 												 357
#define dialog_BIRAGPSPOZSA 												 358
#define dialog_BIRAGPSPOZZG 												 359
#define dialog_BIRAGPSPOZOS 												 360


#define dialog_IZMJENAIMENAGPSSA 											 361
#define dialog_IZMJENAIMENAGPSZG 											 362
#define dialog_IZMJENAIMENAGPSOS 											 363

#define dialog_PROMJENAPOZGPSBG 											 364
#define dialog_PROMJENAPOZGPSSA 											 365
#define dialog_PROMJENAPOZGPSZG 											 366
#define dialog_PROMJENAPOZGPSOS 											 367

#define dialog_FARBANJEVOZILAODABIR1 										 368
#define dialog_FARBANJEVOZILAODABIR2										 369
#define dialog_FARBANJEVOZILAODABIR3 										 370
#define dialog_FARBANJEVOZILAODABIR4 										 371
#define dialog_FARBANJEVOZILAODABIR5 										 372

#define dialog_BIRABRAVUVOZILA 												 373
#define dialog_BIRAALARMVOZILA 												 374
#define dialog_SIPAGORIVOUSERVISU 											 375

#define dialog_ZETVAZITA 													 376

//-------------------------za edit poslova
#define dialog_EDITKOSACA 													 377
#define dialog_EDITGRADJEVINARA 											 378
#define dialog_EDITRUDARA 													 379
#define dialog_EDITKOMUNALCA 												 380
#define dialog_EDITTEMPA 													 381
#define dialog_EDITDPIZZE 													 382
#define dialog_EDITMEHANICARA 												 383
#define dialog_EDITBUSVOZACA 												 384
#define dialog_EDITFARMERA 													 385
#define dialog_EDITPILOTA 													 386

#define dialog_EDITKOSACAPLATA 												 387
#define dialog_EDITKOSACABONUS 												 388


#define dialog_EDITGRADJEVINARAZEMLJAPLATA 									 389
#define dialog_EDITGRADJEVINARAZEMLJABONUS 									 390
#define dialog_EDITGRADJEVINARABETONPLATA 									 391
#define dialog_EDITGRADJEVINARABETONBONUS 									 392

#define dialog_EDITRUDARISKOP 												 393
#define dialog_EDITRUDARPREVOZPLATA 										 394
#define dialog_EDITRUDARPREVOZBONUS 										 395

#define dialog_EDITDJUBRETARPLATA 											 396
#define dialog_EDITDJUBRETARBONUS 											 397
#define dialog_EDITCISTACPLATA 												 398
#define dialog_EDITCISTACBONUS 												 399

#define dialog_EDITTEMPAPLATA 												 400
#define dialog_EDITTEMPABONUS 												 401

#define dialog_EDITPIZZADOSTAVAPLATA 										 402
#define dialog_EDITPIZZADOSTAVABONUS 										 403

#define dialog_EDITMEHANICARMOTOR 											 404
#define dialog_EDITMEHANICARGUME 											 405

#define dialog_EDITBUSBGPLATA 												 406
#define dialog_EDITBUSBGBONUS 												 407

#define dialog_EDITBUSSAPLATA 												 408
#define dialog_EDITBUSSABONUS 												 409

#define dialog_EDITBUSZGPLATA 												 410
#define dialog_EDITBUSZGBONUS 												 411

#define dialog_EDITFARMMLIJEKOPLATA 										 412
#define dialog_EDITFARMMLIJEKOBONUS 										 413

#define dialog_EDITFARMBERACPLATA 											 414
#define dialog_EDITFARMBERACBONUS 											 415

#define dialog_EDITFARMZITOPLATA 											 416
#define dialog_EDITFARMZITOBONUS 											 417

#define dialog_EDITPILOTBGPLATA 											 418
#define dialog_EDITPILOTBGBONUS 											 419

#define dialog_EDITPILOTSAPLATA  											 420
#define dialog_EDITPILOTSABONUS  											 421

#define dialog_EDITPILOTZGPLATA                                              422
#define dialog_EDITPILOTZGBONUS  											 423


#define dialog_PITAADMINA  											 		 424

#define dialog_BIRAILSUPSTANCE 												 425
#define dialog_KUPUJEILOPIUM 												 426
#define dialog_KUPUJEILMETH 												 427

#define dialog_UZIMAUHANGARU 												 428

#define dialog_DROGAIGRACA 													 429

#define dialog_PAPIRIZAREG 													 430
#define dialog_UZIMATABLE 													 431

#define dialog_LISTAKOMANDI 												 432
#define dialog_MJENJAIMESERVERA 											 433
#define dialog_MJENJASIFRUSERVERA 											 434

#define dialog_KUPUJEAUTONAPIJACI 											 435
#define dialog_IZLAZIIZPD 													 436

#define dialog_VIPOBJECTS 													 437
#define dialog_TELEFON                                                       438
#define dialog_TELAUTO                                                       439
#define dialog_PEKARA                                                        440

//#if defined retardirani_textdrawi
#define dialog_PIN 															441
//#endif
#define dialog_SPOL 														442
#define dialog_TDOVI 														443
#define dialog_BETA 														444
#define dialog_GAMEMODE 													445
#define dialog_KUPOVINASUPSTANCI 											446
#define dialog_OSTALOITDS 													447
#define dialog_EVENTS 														448
#define dialog_DILER														449
//============================[ HAPPY JOB SRANJA ]==============================
new HappyJobID;

#define GetJobName getJobName

//============================[ Varijable ]=====================================
//------------------------------------------------------------------------------
new gLastDriver[ MAX_VEHICLES ],
	Neon[ MAX_VEHICLES ],
	VehicleWindows[ MAX_VEHICLES ],
	Text3D:vehicle3Dtext[ MAX_VEHICLES ],
	CarSign[ MAX_VEHICLES ],
	TipVozila[ MAX_VEHICLES ],
	PumpaImanjeVozilo[ MAX_VEHICLES ],
	OrgaVozila[ MAX_VEHICLES ],
	PosaoVozila[ MAX_VEHICLES ],
	ScriptIDVozila[ MAX_VEHICLES ],
	bool:occupied[ MAX_VEHICLES ] = false,
	Fuel[ MAX_VEHICLES ],
	FuelTime[ MAX_VEHICLES ],
	vCanDrive[ MAX_VEHICLES ],
	Siren[MAX_VEHICLES],
	SirenObject[MAX_VEHICLES],
	StateBox[ MAX_VEHICLES ],
	KamionUsed[MAX_VEHICLES],
	CisternFuel[ MAX_VEHICLES ][ 4 ],
	ParkingTime[ MAX_VEHICLES ],
	Parked[ MAX_VEHICLES ],
	IDIgracaKojiVoziBus[ MAX_VEHICLES ],
	bool:KutijaMatsa[ MAX_VEHICLES ],
	bool:sljunak[ MAX_VEHICLES ],
	bool:VehCement[ MAX_VEHICLES ],
	bool:VehNovac[ MAX_VEHICLES ],
	bool:WOOD[ MAX_VEHICLES ],
	WOODObject[ MAX_VEHICLES ],
	NeonObject1[ MAX_VEHICLES ],
	NeonObject2[ MAX_VEHICLES ],
	#if NERP_ZIMSKI_MOD  == 1
	bool:SnowObjects[ MAX_VEHICLES ],
	SnowObject1[ MAX_VEHICLES ],
	SnowObject2[ MAX_VEHICLES ],
	#endif
	Kakica[MAX_VEHICLES];
//------------------------------------------------------------------------------
#define MAX_OBJ_FURNITURE 136
new
	OBPR[MAX_OBJ_FURNITURE][ 2 ] =
	{
		{936,  1160},
		{937, 1150},
		{1417, 1240},
		{1742, 1405},
		{1754, 1186},
		{1755, 1183},
		{1756, 1210},
		{1759, 1200},
		{1762, 1210},
		{1768, 1265},
		{1769, 1650},
		{1814, 1209},
		{1816, 1068},
		{1817, 1086},
		{1820, 1009},
		{1823, 1701},
		{2020, 1905},
		{2025, 1600},
		{2163, 1237},
		{2161, 1068},
		{2162, 2040},
		{2164, 1360},
		{2204, 1780},
		{2191, 1696},
		{2199, 1900},
		{2235, 1086},
		{2295, 906},
		{2291, 1204},
		{2292, 2208},
		{2306, 1050},
		{2200, 1630},
		{2307, 1300},
		{1481, 1120},
		{1518, 1806},
		{1700, 1802},
		{1701, 1703},
		{1771, 1500},
		{1719, 1240},
		{1736, 1210},
		{1745, 1080},
		{1749, 1216},
		{1750, 1180},
		{1783, 1159},
		{1786, 1189},
		{1788, 1204},
		{1790, 1228},
		{1793, 1600},
		{1795, 1558},
		{1796, 1600}, //
		{1798, 1630},
		{1799, 1624},
		{1828, 1150},
		{1802, 1615},
		{1809, 1150},
		{2028, 1306},
		{2099, 1450},
		{2002, 1090},
		{2100, 1450},
		{2101, 1150},
		{2102, 1180},
		{2103, 1165},
		{2104, 1186},
		{2090, 1780},
		{2093, 1480},
		{2226, 1267},
		{2296, 2020},
		{2299, 2200},
		{2302, 1600},
		{2312, 1180},
		{2316, 1165},
		{2566, 1350},
		{2575, 1290},
		{1432, 1360},
		{1433, 1300},
		{1704, 1186},
		{1671, 1105},
		{1663, 1190},
		{1705, 1210},
		{1708, 1180},
		{1711, 1120},
		{1720, 1275},
		{1721, 1260},
		{1827, 1264},
		{1723, 1360},
		{1724, 1240},
		{1726, 1390},
		{1727, 1270},
		{1728, 1300},
		{1729, 1210},
		{1739, 1240},
		{1746, 1189},
		{1805, 1230},
		{1806, 1460},
		{1810, 1515},
		{2206, 1369},
		{2207, 1870},
		{2169, 1750},
		{2311, 1240},
		{2315, 1249},
		{2370, 1150},
		{2635, 1186},
		{2346, 1267},
		{1825, 1564},
		{2173, 1390},
		{2205, 1680},
		{2313, 1870},
		{11682, 1656},
		{11683, 1257},
		{11684, 1237},
		{11685, 2374},
		{19916, 2375},
		{19922, 1277},
		{19923, 2572},
		{19925, 1238},
		{19926, 1654},
		{19927, 1328},
		{19928, 1234},
		{19929, 2231},
		{19930, 1122},
		{19931, 1185},
		{19932, 1154},
		{19933, 1411},
		{19934, 1562},
		{19935, 1154},
		{19936, 1185},
		{19937, 1128},
		{11717, 1185},
		{2514, 1234},
		{2516, 1865},
		{2517, 1876},
		{2518, 1237},
		{2522, 1234},
		{2524, 1235},
		{2525, 1651},
		{2526, 1272},
		{2528, 1278}
	};

new	Float:OBPR1[MAX_OBJ_FURNITURE][6] =
	{
		{985.1812, -1612.5311, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.4199, -1612.2356, 13.9000, 0.0000, 0.0000, 180.0000},
		{985.6398, -1612.1354, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3380, -1612.2081, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3380, -1612.2081, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.1592, -1612.1409, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7791, -1612.0621, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7994, -1612.1421, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.4605, -1612.1632, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7014, -1612.2042, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.1588, -1612.2169, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7025, -1612.1442, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.2178, -1611.3993, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.8425, -1612.1206, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7682, -1611.0809, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3271, -1612.6886, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.3271, -1612.6886, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.8297, -1610.2777, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.8297, -1610.2777, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.4120, -1612.9985, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.3685, -1612.3977, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3235, -1612.5359, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.7492, -1610.2462, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1707, -1612.8141, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7675, -1610.2645, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7675, -1610.2645, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3683, -1610.2153, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7675, -1610.2645, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7675, -1610.2645, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.2040, -1613.0731, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3683, -1610.2153, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7675, -1610.2645, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.0102, -1611.9490, 13.6000, 0.0000, 0.0000, 136.0000},
		{985.3785, -1612.4160, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.2769, -1612.5308, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7895, -1610.5222, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7895, -1610.5222, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3754, -1612.5759, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.3754, -1612.5759, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.8394, -1611.0984, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.8394, -1611.0984, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.2369, -1612.4530, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.2369, -1612.4530, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.6166, -1612.4792, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3542, -1612.6149, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.3542, -1612.6149, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.8156, -1612.5426, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.8156, -1612.5426, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.8156, -1612.5426, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3962, -1612.4957, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.3962, -1612.4957, 13.6000, 0.0000, 0.0000, 0.0000},
		{985.3962, -1612.4957, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.3157, -1612.5510, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.2299, -1612.9141, 14.5000, 0.0000, 0.0000, 270.0000},
		{985.2952, -1612.5946, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.2952, -1612.5946, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.2952, -1612.5946, 14.0000, 0.0000, 0.0000, 0.0000},
		{985.2952, -1612.5946, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.1595, -1612.4532, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.2145, -1611.7706, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.7672, -1612.1274, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.0518, -1612.2572, 14.0000, 0.0000, 0.0000, 180.0000},
		{986.0518, -1612.2572, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.6422, -1611.9918, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.3211, -1612.5044, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.8383, -1612.4248, 14.0000, 0.0000, 0.0000, 180.0000},
		{985.2675, -1612.6863, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.7662, -1612.6479, 13.6000, 0.0000, 0.0000, 180.0000},
		{986.0051, -1612.6191, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.9312, -1612.7821, 13.6000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 14.0000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.1812, -1612.5311, 13.5000, 0.0000, 0.0000, 270.0000},
		{985.2532, -1612.3744, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.1116, -1612.4293, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.8887, -1612.5164, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.0870, -1613.2367, 13.5000, 0.0000, 0.0000, 360.0000},
		{985.8043, -1612.3848, 13.5000, 0.0000, 0.0000, 180.0000},
		{984.4646, -1612.7347, 13.5000, 0.0000, 0.0000, 360.0000},
		{985.8815, -1612.3394, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.4637, -1612.3875, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.9271, -1612.7172, 13.5000, 0.0000, 0.0000, 180.0000},
		{985.3068, -1612.4385, 13.5000, 0.0000, 0.0000, 180.0000}
	};
//------------------------------------------------------------------------------
new bool:realchat 				 = true,
	Mechanics                    = 0,
	timeshift                    = 0,
	ghour                        = 0,
	gminute                      = 0,
	gsecond                      = 0,
	levelexp                     = 4,
	smscost                      = 10,
	cchargetime                  = 60,
	Medics                       = 0,
	callcost                     = 4,
	bool:realtime                = true,
	wtime                        = 12,
	addtimer                     = 60000,
	bool:adds                    = true,
	bool:ToggedG                 = true,
	TimerBankeVracanje,
	TimerZlatareVracanje,
	glavniobjekt,
	shifthour,
	carspawntimer;
new DialogStrgEx[ 2048 ],
	RealName[ MAX_PLAYERS ][ MAX_PLAYER_NAME ],
	globalstring[ 128 ];
new newsbre = 1,
	newstimer = 10000;
new bool:RiotShield[ MAX_PLAYERS ],
	bool:UzeoPicu[ MAX_PLAYERS ],
	bool:electricNACP[ MAX_PLAYERS ],
	bool:PoliceDuty[ MAX_PLAYERS ];
new lastweapon[ MAX_PLAYERS ][ 2 ];
new ReportGlobal[ MAX_PLAYERS ],
	VozPosao[ MAX_PLAYERS ],
	PosaoMasinovodja[ MAX_PLAYERS ],
	VIPPort[ MAX_PLAYERS ],
	PromoterPort[ MAX_PLAYERS ],
	PlacaPorez[ MAX_PLAYERS ],
	NewGlobal[ MAX_PLAYERS ],
	PomocGlobal[ MAX_PLAYERS ];
new Training[ MAX_PLAYERS ];
new bool:PlayerLogged[ MAX_PLAYERS ];
new EditKontejnera[ MAX_PLAYERS ],
	EditRadar[ MAX_PLAYERS ],
	EditPresents[ MAX_PLAYERS ],
	EditCTrees[ MAX_PLAYERS ],
	EditXOrbs[ MAX_PLAYERS ],
	EditATM[ MAX_PLAYERS ];
new cistacvodica[2][MAX_PLAYERS];
new cistackilometri[ MAX_PLAYERS ],
	ChosenJob[ MAX_PLAYERS ],
	LetSF[ MAX_PLAYERS ],
	PilotTimer[ MAX_PLAYERS ],
	FarbanjeTimer[ MAX_PLAYERS ],
	LetLV[ MAX_PLAYERS ],
	CistacTimer[ MAX_PLAYERS ],
	bool:CistacPosao[ MAX_PLAYERS ],
	Float:cistacpoz[ MAX_PLAYERS ][ 3 ],
	cistacnovac[ MAX_PLAYERS ],
	CistacWarning[ MAX_PLAYERS ],
	cistacvozilo[ MAX_PLAYERS ],
	cistacmetri[ MAX_PLAYERS ];
new VremeZaNovac[ MAX_PLAYERS ],
	VremeZaZlato[ MAX_PLAYERS ],
	CheckpointStatus[ MAX_PLAYERS ],
	ZlatoVreme[ MAX_PLAYERS ],
	PljackanjeZlatareTimer[ MAX_PLAYERS ],
	PljackaZlato[ MAX_PLAYERS ],
	PljackanjeBankeTimer[ MAX_PLAYERS ],
	PljackaVreme[ MAX_PLAYERS ],
	PljackaNovac[ MAX_PLAYERS ];

new Sex_Lisa, bool:WhoreLisa,
	Sex_Angelina, bool:WhoreAngelina,
	Sex_Mia, bool:WhoreMia,
	Sex_Sendy, bool:WhoreSendy;

new reactionMoney,
	reactionMessage[ 2 ][ 128 ],
	bool:reactionWon,
	reactionWinner[ MAX_PLAYER_NAME ],
	reactionTest,
	reactionTime = 0;
#if kladionica == 1
new IzabraniParovi1[ 10 ], IzabraniParovi2[ 10 ];

new bool:ListaPrikazana[ MAX_PLAYERS ],
	bool:RezultatiPrikazana[ MAX_PLAYERS ],
	bool:MojListicPrikazan[ MAX_PLAYERS ];
#endif
// PROMOTER i VIP goto
new bool:GotoOff[MAX_PLAYERS];

new Float:Degree[ MAX_PLAYERS ];
const Float: SelfieRadius = 1.4;
const Float: SelfieSpeed  = 1.25;
const Float: SelfieHeight = 1.0;
new Float:lX[ MAX_PLAYERS ];
new Float:lY[ MAX_PLAYERS ];
new Float:lZ[ MAX_PLAYERS ];

#if NERP_ZIMSKI_MOD  == 1
new SnowObject[ MAX_PLAYERS ];
new bool:Snow[ MAX_PLAYERS ];
#endif

new bool:Snow_F[ MAX_PLAYERS ];
new Obj[ MAX_PLAYERS ];
new Shoot[ MAX_PLAYERS ];
new bool:AlreadyShooted[ MAX_PLAYERS ];
new Charged[ MAX_PLAYERS ];
#if NERP_ZIMSKI_MOD  == 1
new PlayerEffect[ MAX_PLAYERS ], PlayerRun[ MAX_PLAYERS ], EffectTimer[ MAX_PLAYERS ];
#endif
new NamestajLevel[ MAX_PLAYERS ],
	NamestajTajmer[ MAX_PLAYERS ],
	NamestajTajmer2[ MAX_PLAYERS ],
	Objekat[ MAX_PLAYERS ],
	Rezanje[ MAX_PLAYERS ],
	KoristioRezanje[ MAX_PLAYERS ];
	
new AktivanKontejner[ MAX_PLAYERS ];
new smeceobject1[MAX_PLAYERS];
new zasmeceobject1[MAX_PLAYERS];
new betonobject1[MAX_PLAYERS];
new betonobject2[MAX_PLAYERS];
new pijesakhrpa[MAX_PLAYERS][26];
new ravnjanjetimer[MAX_PLAYERS];

new Seeds[ MAX_PLAYERS ],
	ParkingPlace[ MAX_PLAYERS ],
	CreatingParkingLevel[ MAX_PLAYERS ],
	CreateParkingID[ MAX_PLAYERS ],
	DeliverLevel[ MAX_PLAYERS ],
	TempoDostavaFabrikaCP[ MAX_PLAYERS ],
	DeliverCar[ MAX_PLAYERS ],
	TrafikaPrva[ MAX_PLAYERS ],
	TrafikaTrenutna[ MAX_PLAYERS ],
	CarriesBox[ MAX_PLAYERS ],
	Putovar[ MAX_PLAYERS ],
	bool:Putovara[ MAX_PLAYERS ],
	Pistovar[ MAX_PLAYERS ],
	bool:Pistovara[ MAX_PLAYERS ],
	ProcesFStation[ MAX_PLAYERS ],
	CreatingFStation[ MAX_PLAYERS ],
	bool:UKLJUCENIFCHAT[ MAX_PLAYERS ],
	BikeBH[ MAX_PLAYERS ],
	EventStranica[ MAX_PLAYERS ],
	StatsList[ MAX_PLAYERS ],
	zauzimanje_firme_ID[ MAX_PLAYERS ],
	zauzimanje_firme_Vreme[ MAX_PLAYERS ],
	zauzimanje_firme_Timer[ MAX_PLAYERS ],
	OruzjeUInventoriju[ MAX_PLAYERS ],
	bool:KupljeneFakture[ MAX_PLAYERS ],
	bool:takingselfie[ MAX_PLAYERS ],
	PlayerInBlowJob[ MAX_PLAYERS ],
	BlowJobCount[ MAX_PLAYERS ],
	PlayerText:BLOWJOBCOVER[ MAX_PLAYERS ][ 5 ],
	PusenjeTimer[ MAX_PLAYERS ],
	IzabraniAskQ[ MAX_PLAYERS ],
	Timer_Fading[ MAX_PLAYERS ],
	Polaganje[ MAX_PLAYERS ],
	PlayerCement[ MAX_PLAYERS ],
	IDBusaKojiVozi[ MAX_PLAYERS ],
	IDVozilaKojimSverca[ MAX_PLAYERS ],
	ProcesSvercanja[ MAX_PLAYERS ],
	PlayerPrevozNovca[ MAX_PLAYERS ],
	F_Count[ MAX_PLAYERS ],
	DropedGun[ MAX_PLAYERS ],
	BrojLisica[ MAX_PLAYERS ],
	TazerMetkovi[ MAX_PLAYERS ],
	FakeKillPlus[ MAX_PLAYERS ],
	FakeKillTime[ MAX_PLAYERS ],
	#if nerp_droga == 1
	PoljeDroge[ MAX_PLAYERS ],
	#endif
	Poravnano[ MAX_PLAYERS ],
	sravnohrpica[ MAX_PLAYERS ],
	VoziBeogradStanicu[MAX_PLAYERS],
	VoziSarajevoStanicu[MAX_PLAYERS],
	WatchModel[ MAX_PLAYERS ],
	ChosenItem[ MAX_PLAYERS ],
	GiveItemID[ MAX_PLAYERS ],
	AdminVozilo[ MAX_PLAYERS ],
	BrziRentVozilo[MAX_PLAYERS],
	Text3D:br_label[MAX_PLAYERS],
	killrent[MAX_PLAYERS],
	TrkaVozilo[ MAX_PLAYERS ],
	IzazivanjeTimer[ MAX_PLAYERS ],
	Krugovi[ MAX_PLAYERS ],
	TrkaCheckpoint[ MAX_PLAYERS ],
	TrkaIzazov[ MAX_PLAYERS ],
	bool:NaDmEventu[ MAX_PLAYERS ],
	bool:NaZombieEventu[ MAX_PLAYERS ],
	bool:NaUtrci[ MAX_PLAYERS ],
	bool:ShowedRegister[ MAX_PLAYERS ],
	ResprayColor1[ MAX_PLAYERS ],
	ResprayColor2[ MAX_PLAYERS ],
	DragedPlayerID[ MAX_PLAYERS ],
	Draged[ MAX_PLAYERS ],
	DragTimer[ MAX_PLAYERS ],
	ShowedAtmTD[ MAX_PLAYERS ],
	gpsid[ MAX_PLAYERS ],
	EnteredGarage[ MAX_PLAYERS ],
	ServerStatsChose[ MAX_PLAYERS ],
	bool:PraznaGajbica[ MAX_PLAYERS ],
	bool:ImaKanticu[ MAX_PLAYERS ],
	GajbicaBiljka[ MAX_PLAYERS ],
	bool:ElectricOprema[ MAX_PLAYERS ],
	BrojilaKuca[ MAX_PLAYERS ],
	EIDK[ MAX_PLAYERS ],
	ElectricPosao[ MAX_PLAYERS ],
	Bandera[ MAX_PLAYERS ],
	bool:MedicDuty[ MAX_PLAYERS ],
	backuptimer[ MAX_PLAYERS ],
	SeedsK[ MAX_PLAYERS ];
new skinlist = mS_INVALID_LISTID; // Buy skins
new regskinlist = mS_INVALID_LISTID;

new bool:VecJeAfk[ MAX_PLAYERS ];
/*
new MaleSkinNames[][] = { "Turista", "Belac_sa_kapuljacom", "Crnac_sa_majcom", "Beskucnik" };
new MaleSkinIDs[][] = { 26, 29, 28, 137 };

new FemaleSkinNames[][] = { "Bogata_zena", "Ulicna_devojka", "Poslovna_zena", "Belkinja_u_suknji" };
new FemaleSkinIDs[][] = { 12, 13, 141, 169 };
*/
//  NEWS //
new EndWood[ MAX_PLAYERS ];
new OdabraoSkinZaReg[MAX_PLAYERS];
new bool:InputPassword[ MAX_PLAYERS ],
	bool:ChoseCountry[ MAX_PLAYERS ],
	bool:InputAge[ MAX_PLAYERS ],
	bool:InputMail[ MAX_PLAYERS ],
	RegSex[ MAX_PLAYERS ],
	BiraSkin[ MAX_PLAYERS ],
	BiraPol[ MAX_PLAYERS ];
new GlobalProdaja[ MAX_PLAYERS ],
	Ponudjeno[ MAX_PLAYERS ],
	Trazio[ MAX_PLAYERS ],
	GlobalCena[ MAX_PLAYERS ],
	GlobalID_2[ MAX_PLAYERS ],
	GlobalID[ MAX_PLAYERS ];
new Spectate[ MAX_PLAYERS ];
new MarriageCeremoney[ MAX_PLAYERS char ];
new ProposeOffer[ MAX_PLAYERS ],
	DivorceOffer[ MAX_PLAYERS ];
new ProposedTo[ MAX_PLAYERS ];
new GotProposedBy[ MAX_PLAYERS ];

new BunnyHopPokusaji[MAX_PLAYERS];

new MarryWitness[ MAX_PLAYERS ];
new MarryWitnessOffer[ MAX_PLAYERS ];
new WatchingTV[MAX_PLAYERS char];
new bool:AdminDuty[ MAX_PLAYERS ],
	MinutiIgraca[ MAX_PLAYERS ],
	IgracPosadio[ MAX_PLAYERS ],
	VremeZaCuvanje[ MAX_PLAYERS ],
	IzabraniPort[ MAX_PLAYERS ],
	ChosenVehicle[ MAX_PLAYERS ],
	KreiranAutoSalon[ MAX_PLAYERS ],
	KreiraGarazu[ MAX_PLAYERS ],
	bool:PlayerCPShow[ MAX_PLAYERS ],
	PhoneOnline[ MAX_PLAYERS ],
	Float:SpecPos[ MAX_PLAYERS ][ 3 ],
	SpecVW[ MAX_PLAYERS ],
	SpecInt[ MAX_PLAYERS ],
	Float:PozicijaWAR[ MAX_PLAYERS ][ 3 ],
	VirtualWWAR[ MAX_PLAYERS ],
	InteriorWAR[ MAX_PLAYERS ],
	KreiranjeWara[ MAX_PLAYERS ],
	anticheatinfo[ MAX_PLAYERS ],
	RPTeacherDuty[ MAX_PLAYERS ];
new InAmbu[ MAX_PLAYERS ];
new bool:TelohraniteljUniforma[ MAX_PLAYERS ],
	bool:VozacUniforma[ MAX_PLAYERS ];
new TrashLimit[ MAX_PLAYERS ],
	TrashTimer[ MAX_PLAYERS ],
	TrashSearch[ MAX_PLAYERS ];
new bool:NosiObjekt[ MAX_PLAYERS ][ 3 ];
new PropertySafeGun[ MAX_PLAYERS ];
new PaketType[ MAX_PLAYERS ],
	bool:NosiPaketOruzja[ MAX_PLAYERS ];
new TimerLearn[ MAX_PLAYERS ];
new PinDur[MAX_PLAYERS];
new ProveriInvOruzje[ MAX_PLAYERS ];
new TimerTutorial[ MAX_PLAYERS ];
new TimerPitanje[ MAX_PLAYERS ];
new BolnicaTimer[ MAX_PLAYERS ];
new rampagranice1_1,
	rampagranice1_2,
	rampagranice2_1,
	rampagranice2_3,
	gradjkapija,
	rudzllift,
	rudnikgate1,
	rudnikgate2;


new bool:VrataBankeSrusena,
	LozinkaBanke[ 32 ],
	VrataSefaBanke,
	Text3D:Dinamit3D,
	DinamitObjekt,
	SekundDinamita,
	bool:SruseniLaseri,
	bool:BankaOpljackana,
	bool:PljackaUToku,
	bool:ZlataraUToku,
	bool:ZlataraOpljackana,
	LaseriBanka[ 14 ];
	
new bool:vrataPD, vrataPDobject;
new bool:RudnikLift, bool:RudnikLiftuPokretu;
new VremeZatvaranjaCelija, celija[ 12 ], bool:OtvoreneCelije;
new ChosenProperty[ MAX_PLAYERS ];
new cseconds, cstring[40];
new PitanjeBroj[ MAX_PLAYERS ],
	TacanOdgovor[ MAX_PLAYERS ],
	PokusajiHakedovanja[ MAX_PLAYERS ],
	HakovanjeTimer[ MAX_PLAYERS ],
	KupljenGPS[MAX_PLAYERS ],
	bool:PozvaoTaxi[ MAX_PLAYERS ],
	Rentano[ MAX_PLAYERS ],
	CenaVoznje[ MAX_PLAYERS ],
	bool:taxiDuty[ MAX_PLAYERS ],
	bool:TaximetarUkljucen[ MAX_PLAYERS ],
	VoziIgracaID[ MAX_PLAYERS ],
	offeredByCabbie[ MAX_PLAYERS ],
	TrunkVehicle[ MAX_PLAYERS ],
	TazerTimer[ MAX_PLAYERS ],
	TaxiTimer[ MAX_PLAYERS ],
	PlayerCuffed[ MAX_PLAYERS ],
	PosaoRudar[ MAX_PLAYERS ],
	#if nerp_droga == 1
	bool:PlayerDrugged[ MAX_PLAYERS ],
	#endif
	bool:PlayerStoned[ MAX_PLAYERS ],
	bool:PosaoTDShowed[ MAX_PLAYERS ],
	bool:PlayerTuningCar[ MAX_PLAYERS ],
	bool:StatsTDShowed[ MAX_PLAYERS ],
	bool:OdjecaTDShowed[ MAX_PLAYERS ],
	bool:MessageBoxShowed[ MAX_PLAYERS ],
	bool:BRACETMLogoShowed[ MAX_PLAYERS ],
	bool:SpecTDShowed[ MAX_PLAYERS ],
	bool:ScreenMsgTDShowed[ MAX_PLAYERS ],
	bool:WifiConnectionTDShowed[ MAX_PLAYERS ],
	bool:PUBGTDShowed[ MAX_PLAYERS ],
	bool:LicnaKartaShowed[ MAX_PLAYERS ],
	bool:BuyCarTDShowed[ MAX_PLAYERS ],
	bool:BojaVozilaTDShowed[ MAX_PLAYERS ],
	bool:IgracSeRegistruje[ MAX_PLAYERS ],
	bool:PocetniTutorialStartovan[ MAX_PLAYERS ],
	bool:LaptopRuke[ MAX_PLAYERS ],
	bool:VecjeUsao[ MAX_PLAYERS ],
	bool:Dinamit[ MAX_PLAYERS ],
	bool:PuniGorivo[ MAX_PLAYERS ],
	ProcesPice[ MAX_PLAYERS ],
	PlayerCode[ MAX_PLAYERS ],
	bool:TogHud[ MAX_PLAYERS ],
	bool:IgracZavezan[ MAX_PLAYERS ],
	bool:AccountVerified[ MAX_PLAYERS ],
	bool:KnockedDown[ MAX_PLAYERS ],
	bool:IgracOpljackan[ MAX_PLAYERS ],
	bool:Pojas[ MAX_PLAYERS ],
	bool:Uze[ MAX_PLAYERS ],
	bool:Maskuse[ MAX_PLAYERS ],
	bool:FlyMode[ MAX_PLAYERS ],
	SearchNadji[ MAX_PLAYERS ],
	bool:ImaTazer[ MAX_PLAYERS ],
	AccPostoji[ MAX_PLAYERS ],
	LogRegShowed[MAX_PLAYERS];
new ListaoObjekte[ MAX_PLAYERS ],
	nekokupujenamestaj = 0,
	KupujeNamestaj[ MAX_PLAYERS ];
new gNews[ MAX_PLAYERS char ];
new VrstaIlegala[ MAX_PLAYERS ],
	KolicinaIlegala[ MAX_PLAYERS ];
new Odbrojavanje[ MAX_PLAYERS ];
new bool:Uciskolu[ MAX_PLAYERS ],
	RentTimer[ MAX_PLAYERS ],
	SkolaTimer[ MAX_PLAYERS ];
new bool:UzeoOpremu[ MAX_PLAYERS ];

new Grass[ MAX_PLAYERS ][76],
	GrassID[76][ MAX_PLAYERS ],
	TravaTimer[ MAX_PLAYERS ],
	bool:KrenuoKosenje[ MAX_PLAYERS ],
	PokosenaTrava[ MAX_PLAYERS ];
	
new bool:KrenuoZetvu[ MAX_PLAYERS ],
	PokosenoZito[ MAX_PLAYERS ],
	ZitoTimer[ MAX_PLAYERS ],
	ZitoID[72][ MAX_PLAYERS ],
	ZitoObjects[ MAX_PLAYERS ][72];
	
new smecedoletimer[MAX_PLAYERS];
new PolaganjeBodovi[ MAX_PLAYERS ],
	StaroVreme[ MAX_PLAYERS ],
	NovoVreme[ MAX_PLAYERS ];
new GreskaVoznja[ MAX_PLAYERS ];
new ListaBurg[ MAX_PLAYERS ];
new UzeoIzMarketa[ MAX_PLAYERS ][ 11 ],
	UkupnaCena[ MAX_PLAYERS ];
new bool:FaceOn[ MAX_PLAYERS ],
	bool:HeadOn[ MAX_PLAYERS ],
	bool:HelmetOn[ MAX_PLAYERS ],
	bool:SungOn[ MAX_PLAYERS ],
	bool:PapagajOn[ MAX_PLAYERS ];
new PonudioIgrac[ MAX_PLAYERS ];
new ModelTrke[ MAX_PLAYERS ];
new UlogTrke[ MAX_PLAYERS ];
new inProperty[ MAX_PLAYERS ],
	inOrgInt[ MAX_PLAYERS ],
	inDrugFactory[MAX_PLAYERS],
	inOrgGarage[MAX_PLAYERS],
	inHotel[ MAX_PLAYERS ],
	uInterijeru[ MAX_PLAYERS ],
	uFirmi[ MAX_PLAYERS ];
new CenaProdaje[ MAX_PLAYERS ];
new EditingBody[ MAX_PLAYERS ];
new RadioAktiviran[ MAX_PLAYERS ];
new UsaoAutoProdaja[ MAX_PLAYERS ];
new PrviSpawn[ MAX_PLAYERS ];
new OrgKreiranje[ MAX_PLAYERS ];
new PokusajLogina[ MAX_PLAYERS ];
new bool:OrgVehAnncSeen[MAX_PLAYERS],
	LastOrgVehDetected[MAX_PLAYERS];
new TackeLoadingTD = 1,
	bool:LoadingTextdrawShowed[MAX_PLAYERS],
	LoadingTimer[MAX_PLAYERS];
new KupujeOdDilera[MAX_PLAYERS],
	bool:ItemNearbyShowed[MAX_PLAYERS];

//varijable


new g_aPreloadLibs[134][13] = {
	"AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
	"BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
	"BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
	"BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
	"BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
	"CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
	"COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
	"DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
	"DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
	"FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
	"FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
	"GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
	"GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
	"INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
	"KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
	"MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
	"MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
	"PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
	"POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
	"QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
	"ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
	"SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
	"SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
	"STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
	"SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
	"TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
	"WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
};

new ZabranjeneReci[][] =
{
	"http://","https://",".com",".info",".org",".hr",".info",".ba",".tk","www",":7777",":7778",":7878",":7877",":7789",
	"mater", "majka", "jebem", "kurac", "picka", "jebi", "govno", "govna"
};

new ImeVozila[212][20] = {
		"Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel",
		"Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
		"Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
		"Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection",
		"Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus",
		"Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
		"Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral",
		"Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
		"Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van",
		"Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale",
		"Oceanic","Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy",
		"Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX",
		"Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper",
		"Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking",
		"Blista Compact", "Police Maverick", "Boxvillde", "Benson", "Mesa", "RC Goblin",
		"Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher", "Super GT",
		"Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt",
		"Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra",
		"FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
		"Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer",
		"Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent",
		"Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo",
		"Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
		"Windsor", "Monster", "Monster", "Uranus", "Jester", "Sultan", "Stratum",
		"Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
		"Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper",
		"Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
		"News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
		"Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car",
		"Police Car", "Police Car", "Police Ranger", "Picador", "S.W.A.T", "Alpha",
		"Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs", "Boxville",
		"Tiller", "Utility Trailer"
};

new Float:CheatPositions[ 46 ][ 3 ]= {
	{-1935.77, 228.79, 34.16},//Transfender near Wang Cars in Doherty
	{-2707.48, 218.65, 4.93},//Wheel Archangels in Ocean Flats
	{2645.61,-2029.15,14.28},//LowRider Tuning Garage in Willowfield
	{1041.26,-1036.77,32.48},//Transfender in Temple
	{2387.55,1035.70,11.56},//Transfender in come-a-lot
	{1836.93,-1856.28,14.13},//Eight Ball Autos near El Corona
	{2006.11,2292.87,11.57},//Welding Wedding Bomb-workshop in Emerald Isle
	{-1787.25,1202.00,25.84},//Michelles Pay 'n' Spray in Downtown
	{720.10,-470.93,17.07},//Pay 'n' Spray in Dillimore
	{-1420.21,2599.45,56.43},//Pay 'n' Spray in El Quebrados
	{-100.16,1100.79,20.34},//Pay 'n' Spray in Fort Carson
	{2078.44,-1831.44,14.13},//Pay 'n' Spray in Idlewood
	{-2426.89,1036.61,51.14},//Pay 'n' Spray in Juniper Hollow
	{1957.96,2161.96,11.56},//Pay 'n' Spray in Redsands East
	{488.29,-1724.85,12.01},//Pay 'n' Spray in Santa Maria Beach
	{1025.08,-1037.28,32.28},//Pay 'n' Spray in Temple
	{2393.70,1472.80,11.42},//Pay 'n' Spray near Royal Casino
	{-1904.97,268.51,41.04},//Pay 'n' Spray near Wang Cars in Doherty
	{403.58,2486.33,17.23},//Player Garage: Verdant Meadows
	{1578.24,1245.20,11.57},//Player Garage: Las Venturas Airport
	{-2105.79,905.11,77.07},//Player Garage: Calton Heights
	{423.69,2545.99,17.07},//Player Garage: Derdant Meadows
	{785.79,-513.12,17.44},//Player Garage: Dillimore
	{-2027.34,141.02,29.57},//Player Garage: Doherty
	{1698.10,-2095.88,14.29},//Player Garage: El Corona
	{-361.10,1185.23,20.49},//Player Garage: Fort Carson
	{-2463.27,-124.86,26.41},//Player Garage: Hashbury
	{2505.64,-1683.72,14.25},//Player Garage: Johnson House
	{1350.76,-615.56,109.88},//Player Garage: Mulholland
	{2231.64,156.93,27.63},//Player Garage: Palomino Creek
	{-2695.51,810.70,50.57},//Player Garage: Paradiso
	{1293.61,2529.54,11.42},//Player Garage: Prickle Pine
	{1401.34,1903.08,11.99},//Player Garage: Redland West
	{2436.50,698.43,11.60},//Player Garage: Rockshore West
	{322.65,-1780.30,5.55},//Player Garage: Santa Maria Beach
	{917.46,2012.14,11.65},//Player Garage: Whitewood Estates
	{1641.14,-1526.87,14.30},//Commerce Region Loading Bay
	{-1617.58,688.69,-4.50},//San Fierro Police Garage
	{837.05,-1101.93,23.98},//Los Santos Cemetery
	{-2057.8000,229.9000,35.6204}, // San Fierro
	{-2366.0000,-1667.4000,484.1011}, // Mount Chiliad
	{2503.7000,-1705.8000,13.5480}, // Grove Street
	{1997.9000,1056.3000,10.8203}, // Las Venturas
	{-2872.7000,2712.6001,275.2690}, // BaySide
	{904.1000,608.0000,-32.3281}, // Unterwasser
	{-236.9000,2663.8000,73.6513} // The big Cock
};

enum SAZONE_MAIN
{
	SAZONE_NAME[48],//38
	Float:SAZONE_AREA[6]//6
};
#define MAX_ZONE_NAME  38
//371
new const gSAZones[ 365 ][ SAZONE_MAIN ] =
{

	{"The Big Ear",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
	{"Aldea Malvada",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
	{"Angel Pine",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
	{"Arco del Oeste",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
	{"Avispa Country Club",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
	{"Avispa Country Club",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
	{"Avispa Country Club",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
	{"Avispa Country Club",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
	{"Avispa Country Club",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
	{"Avispa Country Club",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
	{"Back o Beyond",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
	{"Battery Point",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
	{"Bayside",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
	{"Bayside Marina",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
	{"Beacon Hill",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
	{"Blackfield",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
	{"Blackfield",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
	{"Blackfield Chapel",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
	{"Blackfield Chapel",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
	{"Blackfield Int.",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
	{"Blackfield Int.",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
	{"Blackfield Int.",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
	{"Blackfield Int.",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
	{"Blueberry",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
	{"Blueberry",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
	{"Blueberry Acres",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
	{"Caligula's Palace",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
	{"Caligula's Palace",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
	{"Calton Heights",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
	{"Chinatown",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
	{"City Hall",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
	{"Come-A-Lot",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
	{"Commerce",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
	{"Commerce",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
	{"Commerce",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
	{"Commerce",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
	{"Commerce",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
	{"Commerce",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
	{"Conference Center",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
	{"Conference Center",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
	{"Cranberry Station",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
	{"Creek",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
	{"Dillimore",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
	{"Doherty",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
	{"Doherty",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
	{"Downtown",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
	{"Downtown",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
	{"Downtown",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
	{"Downtown",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
	{"Downtown",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
	{"Downtown",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
	{"Downtown LS",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
	{"Downtown LS",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
	{"Downtown LS",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
	{"Downtown LS",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
	{"Downtown LS",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
	{"Downtown LS",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
	{"Downtown LS",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
	{"Downtown LS",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
	{"Downtown LS",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
	{"East Beach",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
	{"East Beach",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
	{"East Beach",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
	{"East Beach",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
	{"East LS",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
	{"East LS",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
	{"East LS",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
	{"East LS",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
	{"East LS",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
	{"East LS",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
	{"East LS",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
	{"Easter Basin",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
	{"Easter Basin",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
	{"Easter Bay Airport",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
	{"Easter Bay Airport",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
	{"Easter Bay Airport",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
	{"Easter Bay Airport",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
	{"Easter Bay Chemicals",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
	{"Easter Bay Chemicals",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
	{"El Castillo del Diablo",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
	{"El Castillo del Diablo",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
	{"El Castillo del Diablo",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
	{"El Corona",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
	{"El Corona",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
	{"El Quebrados",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
	{"Esplanade East",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
	{"Esplanade East",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
	{"Esplanade East",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
	{"Esplanade North",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
	{"Esplanade North",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
	{"Esplanade North",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
	{"Fallen Tree",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
	{"Fallow Bridge",               {434.30,366.50,0.00,603.00,555.60,200.00}},
	{"Fern Ridge",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
	{"Financial",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
	{"Fisher's Lagoon",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
	{"Flint Intersection",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},
	{"Flint Range",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
	{"Fort Carson",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
	{"Foster Valley",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
	{"Foster Valley",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
	{"Frederick Bridge",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},
	{"Gant Bridge",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},
	{"Gant Bridge",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},
	{"Ganton",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
	{"Ganton",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
	{"Garcia",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
	{"Garcia",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
	{"Garver Bridge",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},
	{"Garver Bridge",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},
	{"Garver Bridge",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},
	{"Glen Park",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},
	{"Glen Park",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},
	{"Glen Park",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},
	{"Green Palms",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
	{"Greenglass College",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
	{"Greenglass College",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
	{"Hampton Barns",               {603.00,264.30,0.00,761.90,366.50,200.00}},
	{"Hankypanky Point",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
	{"Harry Gold Parkway",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
	{"Hashbury",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
	{"Hilltop Farm",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
	{"Hunter Quarry",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
	{"Idlewood",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
	{"Idlewood",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
	{"Idlewood",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
	{"Idlewood",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
	{"Idlewood",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
	{"Idlewood",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
	{"Jefferson",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
	{"Jefferson",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
	{"Jefferson",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
	{"Jefferson",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
	{"Jefferson",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
	{"Jefferson",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
	{"Julius Thruway East",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
	{"Julius Thruway East",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
	{"Julius Thruway East",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
	{"Julius Thruway East",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
	{"Julius Thruway North",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
	{"Julius Thruway North",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
	{"Julius Thruway North",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
	{"Julius Thruway North",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
	{"Julius Thruway North",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
	{"Julius Thruway North",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
	{"Julius Thruway North",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
	{"Julius Thruway North",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
	{"Julius Thruway South",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
	{"Julius Thruway South",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
	{"Julius Thruway West",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
	{"Julius Thruway West",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
	{"Juniper Hill",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
	{"Juniper Hollow",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
	{"K.A.C.C. Military Fuels",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
	{"Kincaid Bridge",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},
	{"Kincaid Bridge",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},
	{"Kincaid Bridge",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},
	{"King's",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
	{"King's",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
	{"King's",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
	{"LVA Freight Depot",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
	{"LVA Freight Depot",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
	{"LVA Freight Depot",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
	{"LVA Freight Depot",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
	{"LVA Freight Depot",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
	{"Las Barrancas",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
	{"Las Brujas",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
	{"Las Colinas",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
	{"Las Colinas",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
	{"Las Colinas",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
	{"Las Colinas",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
	{"Las Colinas",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
	{"Las Colinas",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
	{"Las Colinas",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
	{"Las Payasadas",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
	{"LV Airport",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
	{"LV Airport",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
	{"LV Airport",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
	{"LV Airport",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
	{"Last Dime Motel",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
	{"Leafy Hollow",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
	{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
	{"Lil' Probe Inn",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
	{"Linden Side",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
	{"Linden Station",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
	{"Linden Station",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
	{"Little Mexico",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
	{"Little Mexico",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
	{"Los Flores",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
	{"Los Flores",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
	{"Los Santos International",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
	{"Los Santos International",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
	{"Los Santos International",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
	{"Los Santos International",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
	{"Los Santos International",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
	{"Los Santos International",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
	{"Marina",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
	{"Marina",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
	{"Marina",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
	{"Market",                      {787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
	{"Market",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
	{"Market",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
	{"Market",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
	{"Market Station",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
	{"Martin Bridge",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},
	{"Missionary Hill",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
	{"Montgomery",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
	{"Montgomery",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
	{"Montgomery Int.",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
	{"Montgomery Int.",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
	{"Mulholland",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
	{"Mulholland",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
	{"Mulholland",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
	{"Mulholland",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
	{"Mulholland",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
	{"Mulholland",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
	{"Mulholland",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
	{"Mulholland",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
	{"Mulholland",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
	{"Mulholland",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
	{"Mulholland",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
	{"Mulholland",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
	{"Mulholland",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
	{"Mulholland Int.",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
	{"North Rock",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
	{"Ocean Docks",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
	{"Ocean Docks",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
	{"Ocean Docks",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
	{"Ocean Docks",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
	{"Ocean Docks",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
	{"Ocean Docks",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
	{"Ocean Docks",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
	{"Ocean Flats",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
	{"Octane Springs",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
	{"Old Venturas Strip",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
	{"Palisades",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
	{"Palomino Creek",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
	{"Paradiso",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
	{"Pershing Square",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
	{"Pilgrim",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
	{"Pilgrim",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
	{"Pilson Int.",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
	{"Pirates in Men's Pants",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
	{"Playa del Seville",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
	{"Prickle Pine",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
	{"Prickle Pine",                {1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
	{"Prickle Pine",                {1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
	{"Prickle Pine",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
	{"Queens",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
	{"Queens",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
	{"Queens",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
	{"Randolph Industrial Estate",  {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
	{"Redsands East",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
	{"Redsands East",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
	{"Redsands East",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
	{"Redsands West",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
	{"Redsands West",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
	{"Redsands West",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
	{"Redsands West",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
	{"Regular Tom",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
	{"Richman",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
	{"Richman",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
	{"Richman",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
	{"Richman",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
	{"Richman",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
	{"Richman",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
	{"Richman",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
	{"Richman",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
	{"Richman",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
	{"Richman",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
	{"Robada Int.",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
	{"Roca Escalante",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
	{"Roca Escalante",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
	{"Rockshore East",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
	{"Rockshore West",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
	{"Rockshore West",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
	{"Rodeo",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
	{"Rodeo",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
	{"Rodeo",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
	{"Rodeo",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
	{"Rodeo",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
	{"Rodeo",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
	{"Rodeo",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
	{"Rodeo",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
	{"Rodeo",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
	{"Rodeo",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
	{"Rodeo",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
	{"Rodeo",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
	{"Royal Casino",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
	{"San Andreas Sound",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},
	{"Santa Flora",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
	{"Santa Maria Beach",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
	{"Santa Maria Beach",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
	{"Shady Cabin",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
	{"Shady Creeks",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
	{"Shady Creeks",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
	{"Sobell Rail Yards",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
	{"Spinybed",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
	{"Starfish Casino",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
	{"Starfish Casino",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
	{"Starfish Casino",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
	{"Temple",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
	{"Temple",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
	{"Temple",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
	{"Temple",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
	{"Temple",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
	{"Temple",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
	{"The Camel's Toe",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
	{"The Clown's Pocket",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
	{"The Emerald Isle",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
	{"The Farm",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
	{"The Four Dragons Casino",     {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
	{"The High Roller",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
	{"The Mako Span",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},
	{"The Panopticon",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
	{"The Pink Swan",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
	{"The Sherman Dam",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
	{"The Strip",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
	{"The Strip",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
	{"The Strip",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
	{"The Strip",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
	{"The Visage",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
	{"The Visage",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
	{"DEntisT Station",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
	{"Valle Ocultado",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
	{"Verdant Bluffs",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
	{"Verdant Bluffs",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
	{"Verdant Bluffs",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
	{"Verdant Meadows",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
	{"Verona Beach",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
	{"Verona Beach",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
	{"Verona Beach",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
	{"Verona Beach",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
	{"Verona Beach",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
	{"Vinewood",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
	{"Vinewood",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
	{"Vinewood",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
	{"Vinewood",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
	{"Whitewood Estates",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
	{"Whitewood Estates",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
	{"Willowfield",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
	{"Willowfield",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
	{"Willowfield",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
	{"Willowfield",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
	{"Willowfield",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
	{"Willowfield",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
	{"Willowfield",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
	{"Yellow Bell Station",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
	// Main Zones
	{"Los Santos",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
	{"Las Venturas",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
	{"Bone County",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
	{"Tierra Robada",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},
	{"Tierra Robada",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},
	{"San Fierro",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
	{"Red County",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
	{"Flint County",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},
	{"Whetstone",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
	
};

//------------------------------Za gradove zone
enum SAZONE_MAIN11
{
	SAZONE_NAME11[38],
	Float:SAZONE_AREA11[6]
};
#define MAX_ZONE_NAME11 														  38
new gSAZones11[ 365 ][ SAZONE_MAIN11 ] = {

	{"Sarajevo",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
	{"Sarajevo",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
	{"Zagreb",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
	{"Sarajevo",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
	{"Zagreb",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
	{"Zagreb",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
	{"Zagreb",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
	{"Zagreb",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
	{"Zagreb",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
	{"Zagreb",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
	{"Zagreb",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
	{"Zagreb",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
	{"Sarajevo",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
	{"Sarajevo",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
	{"Zagreb",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
	{"Sarajevo",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
	{"Sarajevo",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
	{"Sarajevo",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
	{"Sarajevo",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
	{"Sarajevo",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
	{"Sarajevo",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
	{"Sarajevo",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
	{"Sarajevo",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
	{"Beograd",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
	{"Beograd",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
	{"Beograd",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
	{"Sarajevo",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
	{"Sarajevo",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
	{"Zagreb",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
	{"Zagreb",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
	{"Zagreb",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
	{"Sarajevo",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
	{"Beograd",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
	{"Beograd",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
	{"Beograd",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
	{"Beograd",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
	{"Beograd",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
	{"Beograd",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
	{"Beograd",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
	{"Beograd",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
	{"Zagreb",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
	{"Sarajevo",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
	{"Beograd",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
	{"Zagreb",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
	{"Zagreb",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
	{"Zagreb",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
	{"Zagreb",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
	{"Zagreb",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
	{"Zagreb",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
	{"Zagreb",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
	{"Zagreb",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
	{"Beograd",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
	{"Beograd",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
	{"Beograd",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
	{"Beograd",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
	{"Beograd",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
	{"Beograd",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
	{"Beograd",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
	{"Beograd",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
	{"Beograd",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
	{"Beograd",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
	{"Beograd",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
	{"Beograd",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
	{"Beograd",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
	{"Beograd",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
	{"Beograd",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
	{"Beograd",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
	{"Beograd",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
	{"Beograd",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
	{"Beograd",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
	{"Beograd",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
	{"Zagreb",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
	{"Zagreb",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
	{"Zagreb",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
	{"Zagreb",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
	{"Zagreb",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
	{"Zagreb",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
	{"Zagreb",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
	{"Zagreb",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
	{"Zagreb",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
	{"Zagreb",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
	{"Zagreb",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
	{"Zagreb",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
	{"Sarajevo",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
	{"Sarajevo",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
	{"Sarajevo",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
	{"Beograd",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
	{"Beograd",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
	{"Sarajevo",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
	{"Zagreb",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
	{"Zagreb",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
	{"Zagreb",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
	{"Zagreb",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
	{"Zagreb",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
	{"Zagreb",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
	{"Zagreb",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
	{"BG-SA",               {434.30,366.50,0.00,603.00,555.60,200.00}},//fallow bridge
	{"Beograd",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
	{"Zagreb",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
	{"Beograd",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
	{"Zagreb",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},//flint intersection
	{"Zagreb",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
	{"Sarajevo",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
	{"Zagreb",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
	{"Zagreb",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
	{"Zagreb",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
	{"Zagreb",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
	{"BG-SA",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},//frederick bridge
	{"SA-ZG",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},//gant bridge
	{"SA-ZG",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},//gant bridge
	{"Beograd",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
	{"Beograd",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
	{"Zagreb",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
	{"Zagreb",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
	{"SA-ZG",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},//graver bridge
	{"SA-ZG",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},//graver bridge
	{"SA-ZG",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},//graver bridge
	{"Beograd",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},//nacionalni park BG
	{"Beograd",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},//nacionalni park BG
	{"Beograd",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},//nacionalni park BG
	{"Sarajevo",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
	{"Sarajevo",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
	{"Sarajevo",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
	{"Beograd",               {603.00,264.30,0.00,761.90,366.50,200.00}},
	{"Beograd",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
	{"Sarajevo",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
	{"Zagreb",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
	{"Beograd",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
	{"Sarajevo",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
	{"Beograd",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
	{"Beograd",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
	{"Beograd",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
	{"Beograd",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
	{"Beograd",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
	{"Beograd",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
	{"Beograd",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
	{"Beograd",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
	{"Beograd",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
	{"Beograd",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
	{"Beograd",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
	{"Beograd",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
	{"Sarajevo",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
	{"Sarajevo",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
	{"Sarajevo",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
	{"Sarajevo",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
	{"Sarajevo",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
	{"Sarajevo",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
	{"Sarajevo",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
	{"Sarajevo",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
	{"Sarajevo",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
	{"Sarajevo",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
	{"Sarajevo",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
	{"Sarajevo",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
	{"Sarajevo",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
	{"Sarajevo",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
	{"Sarajevo",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
	{"Sarajevo",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
	{"Zagreb",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
	{"Zagreb",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
	{"Sarajevo",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
	{"SA-ZG",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},//Kincaid Bridge
	{"SA-ZG",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},//Kincaid Bridge
	{"SA-ZG",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},//Kincaid Bridge
	{"Zagreb",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
	{"Zagreb",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
	{"Zagreb",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
	{"Sarajevo",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
	{"Sarajevo",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
	{"Sarajevo",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
	{"Sarajevo",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
	{"Sarajevo",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
	{"Sarajevo",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
	{"Sarajevo",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
	{"Beograd",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
	{"Beograd",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
	{"Beograd",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
	{"Beograd",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
	{"Beograd",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
	{"Beograd",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
	{"Beograd",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
	{"Sarajevo",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
	{"Sarajevo",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
	{"Sarajevo",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
	{"Sarajevo",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
	{"Sarajevo",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
	{"Sarajevo",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
	{"Zagreb",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
	{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
	{"Sarajevo",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
	{"Sarajevo",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
	{"Sarajevo",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
	{"Sarajevo",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
	{"Beograd",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
	{"Beograd",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
	{"Beograd",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
	{"Beograd",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
	{"Beograd",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
	{"Beograd",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
	{"Beograd",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
	{"Beograd",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
	{"Beograd",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
	{"Beograd",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
	{"Beograd",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
	{"Beograd",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
	{"Beograd",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
	{"Beograd",                      {787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
	{"Beograd",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
	{"Beograd",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
	{"Beograd",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
	{"Beograd",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
	{"BG-SA",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},//martin bridge
	{"Zagreb",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
	{"Beograd",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
	{"Beograd",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
	{"Beograd",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
	{"Beograd",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
	{"Beograd",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
	{"Beograd",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
	{"Beograd",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
	{"Beograd",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
	{"Beograd",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
	{"Beograd",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
	{"Beograd",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
	{"Beograd",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
	{"Beograd",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
	{"Beograd",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
	{"Beograd",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
	{"Beograd",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
	{"Beograd",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
	{"Beograd",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
	{"Beograd",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
	{"Beograd",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
	{"Beograd",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
	{"Beograd",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
	{"Beograd",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
	{"Beograd",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
	{"Beograd",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
	{"Beograd",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
	{"Zagreb",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
	{"Zagreb",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
	{"Zagreb",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
	{"Sarajevo",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
	{"Sarajevo",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
	{"Zagreb",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
	{"Beograd",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
	{"Zagreb",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
	{"Beograd",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
	{"Sarajevo",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
	{"Sarajevo",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
	{"Sarajevo",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
	{"Sarajevo",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
	{"Beograd",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
	{"Sarajevo",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
	{"Sarajevo",                {1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
	{"Sarajevo",                {1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
	{"Sarajevo",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
	{"Zagreb",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
	{"Zagreb",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
	{"Zagreb",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
	{"Sarajevo",  {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
	{"Sarajevo",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
	{"Sarajevo",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
	{"Sarajevo",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
	{"Sarajevo",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
	{"Sarajevo",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
	{"Sarajevo",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
	{"Sarajevo",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
	{"Sarajevo",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
	{"Beograd",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
	{"Beograd",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
	{"Beograd",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
	{"Beograd",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
	{"Beograd",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
	{"Beograd",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
	{"Beograd",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
	{"Beograd",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
	{"Beograd",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
	{"Beograd",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
	{"Sarajevo",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
	{"Sarajevo",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
	{"Sarajevo",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
	{"Sarajevo",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
	{"Sarajevo",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
	{"Sarajevo",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
	{"Beograd",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
	{"Beograd",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
	{"Beograd",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
	{"Beograd",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
	{"Beograd",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
	{"Beograd",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
	{"Beograd",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
	{"Beograd",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
	{"Beograd",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
	{"Beograd",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
	{"Beograd",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
	{"Beograd",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
	{"Sarajevo",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
	{"BG-SA",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},//san andreas sound
	{"Zagreb",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
	{"Beograd",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
	{"Beograd",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
	{"Zagreb",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
	{"Zagreb",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
	{"Zagreb",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
	{"Sarajevo",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
	{"Sarajevo",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
	{"Sarajevo",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
	{"Sarajevo",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
	{"Sarajevo",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
	{"Beograd",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
	{"Beograd",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
	{"Beograd",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
	{"Beograd",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
	{"Beograd",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
	{"Beograd",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
	{"Sarajevo",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
	{"Sarajevo",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
	{"Sarajevo",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
	{"Zagreb",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
	{"Sarajevo",     {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
	{"Sarajevo",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
	{"BG-SA",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},//the mako span
	{"Beograd",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
	{"Sarajevo",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
	{"Sarajevo",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
	{"Sarajevo",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
	{"Sarajevo",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
	{"Sarajevo",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
	{"Sarajevo",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
	{"Sarajevo",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
	{"Sarajevo",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
	{"Beograd",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
	{"Sarajevo",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
	{"Beograd",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
	{"Beograd",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
	{"Beograd",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
	{"Sarajevo",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
	{"Beograd",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
	{"Beograd",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
	{"Beograd",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
	{"Beograd",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
	{"Beograd",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
	{"Beograd",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
	{"Beograd",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
	{"Beograd",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
	{"Beograd",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
	{"Sarajevo",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
	{"Sarajevo",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
	{"Beograd",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
	{"Beograd",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
	{"Beograd",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
	{"Beograd",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
	{"Beograd",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
	{"Beograd",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
	{"Beograd",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
	{"Sarajevo",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
	// Main Zones
	{"Beograd",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
	{"Sarajevo",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
	{"Sarajevo",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
	{"Sarajevo",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},//tierra robada
	{"Sarajevo",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},//tierra robada
	{"Zagreb",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
	{"Sarajevo",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
	{"Zagreb",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},//flint county
	{"Zagreb",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
};





new Float:SpawnBolnica[ 3 ][ 3 ] =
{
	{ 1155.8646,-1334.4711,804.9955 },
	{ 1155.7944,-1338.9091,804.9955 },
	{ 1149.1810,-1338.8960,804.9955 }
};


new Float:SpawnBolnicaNakonLijecenja[ 3 ][ 3 ] =
{
	{ 1153.4758,-1335.2194,804.5207 },
	{ 1153.1509,-1339.0521,804.5207 },
	{ 1150.7323,-1338.9109,804.5207 }
};

/*new Float:TrafikaPos[ 9 ][ 3 ] = {

	{ 1174.0956, -936.1318, 42.8307 },
	{ 1514.9395, -1031.0515, 23.7966 },
	{ 1202.5309, -1275.9502, 13.3616 },
	{ 1418.1516, -1721.0294, 13.5469 },
	{ 339.2676, -1771.2668, 5.1687 },
	{ 1023.6545, -1332.1298, 13.3842 },
	{ 1189.3583, -1706.9924, 13.5755 },
	{ 2083.0374, -1760.8845, 13.5625 },
	{ 2264.8145, -1309.9031, 23.9844 }

};*/

new Float:RandomRudnik[ 6 ][ 3 ] = {

	{ 568.4388,747.0173,970.3410 },
	{ 580.7068,753.5078,971.0794 },
	{ 560.1007,803.0745,969.5175 },
	{ 590.9931,784.0509,969.4036 },
	{ 595.0934,823.3504,971.0921 },
	{ 583.2307, 818.6588, 970.8891 }
};

new Float:RandomCelije[ 3 ][ 3 ] =
{
	{ 1801.0837, -1581.8691, 13.5572 },
	{ 1802.3077, -1578.9171, 13.5572 },
	{ 1801.4437, -1574.2371, 13.5572 }
};

new Float:RandomDMPos[ 10 ][ 3 ] = {
	{ -382.7271, 2274.1548, 41.5471 },
	{ -394.9037, 2257.2969, 42.2798 },
	{ -396.4926, 2230.7151, 43.1595 },
	{ -414.2215, 2221.9216, 42.4297 },
	{ -436.2568, 2243.3733, 42.4297 },
	{ -457.3188, 2231.3545, 44.5985 },
	{ -396.8878, 2192.7390, 42.4176 },
	{ -361.7321, 2202.5627, 42.4844 },
	{ -325.0925, 2215.3992, 44.0645 },
	{ -355.6452, 2220.9185, 49.2862 }
};

new Float:RandomAFKZone[ 53 ][ 3 ] = {
	{ 1730.1456,-1659.6969,20.2397 },
	{ 1727.7513,-1651.9196,20.2299 },
	{ 1726.7904,-1649.3760,20.2322 },
	{ 1721.7285,-1648.6044,20.2282 },
	{ 1718.5098,-1646.6769,20.2273 },
	{ 1713.7710,-1649.8018,20.2279 },
	{ 1715.0129,-1653.6700,20.2227 },
	{ 1715.1097,-1657.7659,20.2228 },
	{ 1715.2035,-1661.7488,20.2288 },
	{ 1715.2915,-1665.4894,20.2269 },
	{ 1714.6241,-1668.3933,20.2255 },
	{ 1722.3838,-1673.0726, 23.6953 },
	{ 1716.7896,-1673.0103, 23.6953 },
	{ 1711.6324,-1672.6580, 23.7049 },
	{ 1709.9771,-1669.4884, 23.7027 },
	{ 1709.4767,-1663.6036, 23.7023 },
	{ 1709.0681,-1659.0173, 23.7021 },
	{ 1709.6382,-1652.6377, 23.6953 },
	{ 1710.0719,-1647.7860, 23.6953 },
	{ 1711.8132,-1644.6721, 23.6882 },
	{ 1716.3827,-1640.8685, 23.6911 },
	{ 1721.7980,-1640.7451, 23.6959 },
	{ 1728.8870,-1640.0542, 23.7373 },
	{ 1733.5642,-1643.3423, 23.7481 },
	{ 1733.5536,-1648.1727, 23.7387 },
	{ 1733.5106,-1654.5677, 23.7296 },
	{ 1733.0682,-1662.7927, 23.7112 },
	{ 1721.1396,-1660.3567, 20.2306 },
	{ 1718.0803,-1655.7264, 20.1501 },
	{ 1721.7438,-1651.4983, 20.0934 },
	{ 1725.2799,-1655.4889, 20.0625 },
	{ 1712.9745,-1673.1198, 27.2055 },
	{ 1716.2690,-1673.0341, 27.2052 },
	{ 1719.9147,-1672.9789, 27.2063 },
	{ 1722.9498,-1672.6964, 27.2047 },
	{ 1726.1809,-1671.0621, 27.1953 },
	{ 1729.7810,-1667.7145, 27.2010 },
	{ 1733.1187,-1664.5486, 27.2140 },
	{ 1733.4927,-1660.4409, 27.2252 },
	{ 1733.7899,-1654.8900, 27.2309 },
	{ 1733.8026,-1650.1589, 27.2378 },
	{ 1733.8157,-1645.2821, 27.2399 },
	{ 1733.5480,-1640.8468, 27.2502 },
	{ 1729.6189,-1640.1465, 27.2498 },
	{ 1725.2853,-1640.3112, 27.2165 },
	{ 1720.8525,-1640.4642, 27.1966 },
	{ 1715.5104,-1641.0824, 27.2133 },
	{ 1712.0817,-1644.7480, 27.2019 },
	{ 1709.9279,-1649.0500, 27.1953 },
	{ 1709.5186,-1654.9104, 27.1953 },
	{ 1709.6089,-1661.3516, 27.1953 },
	{ 1709.6362,-1665.8845, 27.1953 },
	{ 1709.6707,-1671.6222, 27.1953 }
};

new Float:RandomZatvor[ 18 ][ 3 ] =
{
	{-1621.8823,-1153.7292,1441.8977},
	{-1621.8241,-1160.1481,1441.9044},
	{-1621.2933,-1164.4321,1441.9095},
	{-1621.8856,-1169.4512,1441.8884},
	{-1614.9843,-1176.2041,1441.9028},
	{-1604.2158,-1169.5011,1441.9070},
	{-1604.2146,-1163.3435,1441.9263},
	{-1603.9850,-1160.2555,1441.9232},
	{-1604.0726,-1155.2769,1441.9180},
	{-1619.4568,-1154.7194,1441.9012},
	{-1619.1504,-1161.2350,1441.9084},
	{-1618.8331,-1163.3763,1441.9110},
	{-1618.8447,-1170.6316,1441.8929},
	{-1613.7721,-1174.0829,1441.9019},
	{-1606.6498,-1170.6804,1441.9058},
	{-1606.4337,-1164.4810,1441.9252},
	{-1606.4889,-1161.4972,1441.9220},
	{-1606.7170,-1154.0354,1441.9139}
	
};

new Float:RandomLSSpawn1[ 6 ][ 3 ] =//plaza
{

	{ 386.4861,-2075.2322,7.8661 }, // LS
	{ 385.1859,-2074.7090,7.8661 }, // LS
	{ 383.3157,-2074.2034,7.8661 }, // LS
	{ 381.3557,-2075.0903,7.8661 }, // LS
	{ 383.9581,-2073.8086,7.8661 }, // LS
	{ 385.4878,-2077.7417,7.8661 } // LS
};

new Float:RandomLSSpawn2[ 6 ][ 3 ] = {//kolodvor

	{ 1732.9080, -1910.9319, 13.6568 }, // LS
	{ 1732.8937, -1911.9510, 13.6568 }, // LS
	{ 1732.8510, -1913.0195, 13.6568 }, // LS
	{ 1731.5055, -1912.9473, 13.6568 }, // LS
	{ 1731.5413, -1912.0054, 13.6568 }, // LS
	{ 1731.4545, -1910.9930, 13.6568 } // LS
};

new Float:RandomSFSpawn[ 4 ][ 3 ] = {
	{-2722.4272, 368.2627, 4.3964}, // SF
	{-2694.1816, 366.7715, 4.4007}, // SF
	{-2695.6519, 386.0594, 4.3672}, // SF
	{-2716.8711, 385.5885, 4.3672} // SF
};
new Float:RandomWARMapa11[ 9 ][ 3 ] =
{
	{1147.9226,2813.0664,10.8125},
	{1148.4319,2809.7048,10.8203},
	{1148.7649,2805.6304,10.8203},
	{1151.0385,2800.8855,10.8203},
	{1155.1233,2800.9697,10.8203},
	{1155.0419,2805.0557,10.8203},
	{1144.4396,2799.8264,10.8125},
	{1139.9843,2806.2156,10.9688},
	{1140.9631,2812.3542,10.9190}
};
new Float:RandomWARMapa12[ 9 ][ 3 ] =
{
	{1403.0447,2733.0447,10.8126},
	{1410.5400,2737.9583,10.8203},
	{1414.4192,2747.7236,10.8203},
	{1411.3033,2757.2588,11.2597},
	{1399.9032,2750.0581,10.8203},
	{1391.1559,2744.3250,10.8203},
	{1384.0992,2743.9656,10.8203},
	{1388.7274,2728.1936,10.8203},
	{1379.5826,2729.1980,10.8203}
};
new Float:RandomWARMapa21[ 7 ][ 3 ] =
{
	{-972.6812,1096.0303,1344.9882},
	{-972.5949,1084.3115,1344.9950},
	{-973.4254,1076.6229,1344.9950},
	{-973.5809,1070.1228,1345.0007},
	{-973.7216,1064.7092,1345.0061},
	{-973.6556,1056.8405,1345.0156},
	{-973.0229,1024.2570,1345.0525}
};
new Float:RandomWARMapa22[ 7 ][ 3 ] =
{
	{-1132.7081,1022.7668,1345.7273},
	{-1132.6602,1035.5205,1345.7427},
	{-1132.2740,1041.1238,1345.7412},
	{-1131.0614,1048.8101,1345.7435},
	{-1132.0385,1055.2090,1345.7603},
	{-1132.0372,1063.7393,1345.7628},
	{-1131.6272,1094.3673,1345.7885}
};
new Float:RandomWARMapa31[ 4 ][ 3 ] =
{
	{1295.8276,1070.7544,10.7652},
	{1293.9846,1078.9841,10.6999},
	{1300.7595,1085.3835,10.8203},
	{1312.7617,1084.8655,10.8203}
};
new Float:RandomWARMapa32[ 4 ][ 3 ] =
{
	{1492.2148,916.9006,10.9297},
	{1478.9260,916.6356,10.8203},
	{1467.7583,915.6778,10.8203},
	{1471.7261,930.1809,10.8203}
};
new Float:RandomWARMapa41[ 5 ][ 3 ] =
{
	{2922.0735,4057.7339,41.9413},
	{2924.9233,4058.4211,41.9413},
	{2925.6855,4053.5361,41.9413},
	{2926.5029,4045.3936,41.9413},
	{2921.1628,4044.2600,41.9413}
};
new Float:RandomWARMapa42[ 5 ][ 3 ] =
{
	{2925.1416,4300.6401,41.9413},
	{2923.4927,4307.6055,41.9413},
	{2927.1511,4311.6382,41.9413},
	{2930.3958,4310.5850,41.9413},
	{2931.5002,4302.3281,41.9413}
};
new Float:RandomWARMapa51[ 4 ][ 3 ] =
{
	{-136.6962,-114.7337,3.1172},
	{-126.6221,-115.4705,3.1172},
	{-104.1388,-119.4517,3.1172},
	{-84.2369,-121.1719,3.1172}
};
new Float:RandomWARMapa52[ 4 ][ 3 ] =
{
	{0.4129,91.1095,3.1172},
	{-22.3045,108.2041,3.1172},
	{-45.0152,113.6356,3.1172},
	{-77.4174,134.2272,3.1172}
};

new Float:BanderaPos[ 20 ][ 4 ] =
{
	{ 2432.5647,681.7413,10.8203,315.8406 },
	{ 2532.5339,1217.1047,10.8203,245.9482 },
	{ 2499.5620,1776.2246,10.8203,277.9712 },
	{ 2534.9197,2168.8958,10.8203,155.8769 },
	{ 2280.8657,2304.8418,10.8203,359.8563 },
	{ 2083.9951,2296.8896,10.7841,194.7723 },
	{ 2051.2249,2447.0010,10.8203,181.7585 },
	{ 2294.1565,2719.1472,10.8203,283.9687 },
	{ 1413.8735,2692.5422,10.8125,173.4260 },
	{ 1013.3679,2134.4868,10.8203,203.4019 },
	{ 1283.4261,1203.9707,10.8130,108.7977 },
	{ 1700.7755,1138.9292,10.8203,47.8974  },
	{ 1686.6173,1880.3638,10.8203,94.6164  },
	{ 1591.1235,788.2990,10.8620,287.9215  },
	{ 1669.2457,2180.2170,10.8203,149.5226 },
	{ 1433.8298,1880.2521,10.8203,88.0362  },
	{ 1408.8463,2318.8994,10.8203,358.2549 },
	{ 1500.7568,1070.6007,10.8203,206.9159 },
	{ 1861.3567,711.0256,10.8203,355.3306  },
	{ 1934.5298,2184.4272,10.8125,150.9104 }
};

new Float:BanderaPosGore[ 20 ][ 4 ] =
{
	{ 2437.0715,691.1681,18.6546,351.0805 },
	{ 2533.1082,1207.9181,18.8829,182.4873 },
	{ 2491.7607,1773.7358,16.8973,88.3193 },
	{ 2536.6785,2180.2520,18.6930,1.6110 },
	{ 2279.2913,2294.2029,19.1398,178.6877 },
	{ 2079.7476,2294.2219,19.6134,180.5887 },
	{ 2038.7064,2444.4255,19.0830,90.2225 },
	{ 2284.5796,2722.5095,19.0112,88.4702 },
	{ 1417.2456,2702.4819,19.5150,4.8326 },
	{ 1016.6584,2143.7092,19.2723,357.2291 },
	{ 1294.7180,1203.1068,18.8795,269.4974 },
	{ 1710.8828,1142.8740,17.5276,274.0304 },
	{ 1694.6365,1884.1866,18.7538,271.6907 },
	{ 1578.5826,786.2355,18.9675,88.1801 },
	{ 1677.2218,2182.9092,18.9100,271.6906 },
	{ 1439.3055,1885.7688,17.7997,271.6906 },
	{ 1399.2322,2322.6819,18.7533,90.3757 },
	{ 1497.6464,1082.5927,19.0339,359.5710 },
	{ 1857.5492,711.8239,18.8533,2.6418 },
	{ 1937.5627,2196.2046,17.5565,352.4039 }
};


//===============================[ Enum ]=======================================

new BunnyHop[MAX_PLAYERS];
new UkljucenBH = 1;
new sniperevent = 0;
new presenthuntevent = 0;

enum xPlayerInfo
{
	xLozinka[ LOZINKA_STRING ],
	xPol,
	xGodine,
	xNovac,
	xLevel,
	xRespekt,
	xPoboljsanja,
	xPayDay,
	xAdmin,
	xSkin,
	xSpawn,
	xLider,
	xClan,
	xRank,
	xVoziloID[ 4 ],
	xMaterijali,
	xFirmaID,
	xPosao,
	xUgovor,
	xMehSkill,
	xMDelovi,
	xHead,
	Float:xHeadPos[9],
	xFace,
	Float:xFacePos[9],
	xSungMask,
	Float:xSungMaskPos[9],
	xCigare,
	xUpaljac,
	xBStil,
	xRegistrovan,
	Float:xSHealth,
	xBrojTelefona,
	xVozacka,
	xLicna,
	xTaxLic,
	xPasos,
	xJMBG,
	xBrojLk,
	xBrojPasosa,
	xMotorska,
	xKamionskaC1,
	xKamionskaC2,
	xKamionskaC3,
	xBrodska,
	xLetelica,
	xOsnovna,
	xSrednja,
	xFakultet,
	xSkolaLimit,
	xUbijen,
	#if nerp_droga == 1
	xDrug[5],
	xDrugCode[5],
	#endif
	xSolna,
	xPseudo,
	xSodaB,
	xCrveniF,
	xLysAcid,
	xDesVoda,
	xMarihuana,
	xOpium,
	xKalcij,
	xAmonijH,
	xKokain,
	xKokain2,
	xMetilAmin,
	xHunger,
	xToilet,
	bool:xHeroinAddict,
	xHeroinUsed,
	xHeroinIndicator,
	bool:xCokeCrackAddict,
	xCokeCrackUsed,
	xCokeCrackIndicator,
	bool:xMethAddict,
	xMethIndicator,
	xMethUsed,
	bool:xInekcija,
	bool:xToolkit,
	xProperty[ 3 ],
	xObject[ 10 ],
	bool:xGunLicense,
	xTelefonBon,
	xModelTelefona,
	xSnaga,
	xZatvor,
	xZatvorVreme,
	xWanted,
	xUhapsen,
	xPDUhapsio,
	xPDStatsTicket,
	xPDStatsTicketMoney,
	xTakenWeps,
	#if nerp_droga == 1
	xTakenDrugs,
	#endif
	xPocetniTut,
	xAKod,
	xSat,
	xMaskID,
	xBRacun,
	xPreostaloZaOtplatu,
	xIznosRate,
	xIznosKredita,
	xOnlineSati,
	xHelper,
	xRPLearn,
	xWarn,
	xMute,
	Float:xMarker[ 3 ],
	xBrojNews,
	xOrgUgovor,
	xGpsLevel,
	xHelmet,
	xBDays,
	xBMonths,
	xBYears,
	xGradRank,
	xSkriptaRank,
	xUlazBL,
	bool:xBoombox,
	Float:xHelmetPos[ 9 ],
	xDrzava,
	xEmail[ 34 ],
	xVIPLevel,
	xHitmenCena,
	xLesLimit,
	xKazneniUgovor,
	xOffPJail[ 64 ],
	xOffPPrison[ 64 ],
	xOffPMute[ 64 ],
	xStaffMin,
	xLastLogin[ 64 ],
	bool:xMarried,
	xMarriedTo[ 24 ],
	bool:xTogMob,
	xHotelID,
	xHotelRoom,
	xPromoter,
	xFieldID,
	xSljive,
	xKruske,
	xJabuke,
	xKupus,
	xRuze,
	xSemeSljive,
	xSemeKruske,
	xSemeJabuke,
	xSemeKupusa,
	xSemeRuze,
	xLottoNumber,
	xLottoMoney,
	xGarageID,
	bool:xImaBRacun,
	xPlatniRacun,
	bool:xDonatorSlot,
	xPljackaVreme,
	bool:xLeaveJail,
	xBailPrice,
	xHangarTime,
	xEvent1Mesto,
	xEvent2Mesto,
	xEvent3Mesto,
	xDMEventUbistva,
	xRentID,
	xZlato,
	xRezervniKljucevi,
	xRadarBodovi,
	bool:xDBO,
	xDBoja,
	xRPPoen,
	xPodApoeni,
	xApoeni,
	Float:xVipTime,
	xZauzimanjeVreme,
	xPoklon,
	bool:xPaketic,
	xKljucKapije[ MAX_PLAYER_NAME ],
	xSvercer,
	xSpawned,
	xBHD,
	xRCON,
	xTogn,
	//GROBAR
	xPosaoMisija,
	xUzeoMrtvoTelo,
	//SMS IGRA
	xPokupioAuto,
	//ostalo
	xRanac,
	xMreza,
	xTelAuto,
	xKnjizica,
	xVakcina,
	xUputnica,
	xZMaska,
	xPin,
	xDutyTime,
	xPP,
	xDeathScreen,
	xDJ,
	xOTD,
	xTdstil,
	//pubg
	xPUBG,
	xPUBGKills,
	//ostalo
	xSkocio,
	xVokiToki,
	xPapagaj,
	xGamemode,
	xgms,
	xBanovan,
	xBDatum[3],
	xBReason[41],
	xSniperHeadshots,
	xPUBGKillsTotal,
	xPFV,
	xZombieEventKills
}

new PlayerInfo[ MAX_PLAYERS ][ xPlayerInfo ];
new Branje[MAX_PLAYERS];
new LiderSkins[MAX_PLAYERS];
new Ranjen[MAX_PLAYERS];
new Modern[MAX_PLAYERS];



//
new PlayerText:KILOMETARSATPLAYER[ MAX_PLAYERS ][ 3 ];
new PlayerText:KILOMETARSATTD[ MAX_PLAYERS ][ 24 ];
new PlayerText:JailTD[ MAX_PLAYERS ];
//
//new PlayerText:LicnaKartaTD[21][MAX_PLAYERS];
//new PlayerText:StatsTDs[40][MAX_PLAYERS];


new PlayerText:TaxistaTD[ MAX_PLAYERS ][ 8 ];
new PlayerText:GladIgraca[ MAX_PLAYERS ];
new PlayerText:WcIgraca[ MAX_PLAYERS ];
new PlayerText:LokacijaIgracaTD[ MAX_PLAYERS ];
new PlayerText:GradIgracaTD[ MAX_PLAYERS ];
//new PlayerText:BankaIgraca[ MAX_PLAYERS ];
//new PlayerText:ZlatoIgraca[ MAX_PLAYERS ];
//new PlayerText:TDEditor_PTD[MAX_PLAYERS][ 11 ];
//new PlayerText:PlataIgraca[ MAX_PLAYERS ];
new PlayerText:WantedIgraca[ MAX_PLAYERS ];

new PlayerText:SkinIgraca[MAX_PLAYERS];


//BANKA ZLATO TD
new PlayerText:Textdraw0[MAX_PLAYERS];
new PlayerText:Textdraw1[MAX_PLAYERS];
new PlayerText:Textdraw2[MAX_PLAYERS];
new PlayerText:Textdraw3[MAX_PLAYERS];
new PlayerText:Textdraw4[MAX_PLAYERS];
new PlayerText:Textdraw5[MAX_PLAYERS];
new PlayerText:Textdraw6[MAX_PLAYERS];
//new PlayerText:Textdraw7[MAX_PLAYERS];
//new PlayerText:BankaIgraca[MAX_PLAYERS];
//new PlayerText:Textdraw9[MAX_PLAYERS];
//new PlayerText:ZlatoIgraca[MAX_PLAYERS];
//new PlayerText:Textdraw11[MAX_PLAYERS];
//new PlayerBar:BrzinomerHealth[ MAX_PLAYERS ] = { INVALID_PLAYER_BAR_ID, ...};
new PlayerText:NickIgraca[MAX_PLAYERS];

new Text:TDEditor_TD[100];
//new Text:GPSIGTD[15];

new Text:GladTDPizza;
new Text:WcTDSolja;

#define BETA_BUILD 1
#define betaver "VERZIJA: ~w~Beta - dev.build.3640-2f43g71hsys438g7 ("NERP_VERZIJA")~n~Sva prava pridrzana: BRACE tm"

//////////////////////////////////




enum xPekar
{
	xMisija,
	xPreuzeoTjesto
}
new PekarInfo[MAX_PLAYERS][xPekar];

enum xDzeparos
{
	xMisija
}
new DzeparosInfo[MAX_PLAYERS][xDzeparos];

#define GRAD_MAYOR      6
#define GRAD_VMAYOR     5
#define GRAD_LBODYGUARD 4
#define GRAD_LDRIVER    3
#define GRAD_DRIVER     2
#define GRAD_BODYGUARD  1

stock g_aWeaponSlots[] = {
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10, 10, 8, 8, 8, 0, 0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 6, 6, 7, 7, 7, 7, 8, 12, 9, 9, 9, 11, 11, 11
};

enum _weaponInfos{
	wName[24],
	wID,
	wSlot,
	wModel,
	wTXDName[100],
	wAmmoName[50]
}

new WeaponInfos[ 47 ][ _weaponInfos ] = {
	{"Fist", 0, 0, 0, "hud:fist", WEAPONDATA_NO_AMMO },
	{"Brass Knuckles", 1, 0, 331, "brassknuckle:brassknuckleicon", WEAPONDATA_NO_AMMO },
	{"Golf Club", 2, 1, 333, "golfclub:golfclubicon", WEAPONDATA_NO_AMMO },
	{"Nightstick", 3, 1, 334, "nitestick:nitestickicon", WEAPONDATA_NO_AMMO },
	{"Knife", 4, 1, 335, "knifecur:knifecuricon", WEAPONDATA_NO_AMMO },
	{"Baseball Bat", 5, 1, 336, "bat:baticon", WEAPONDATA_NO_AMMO },
	{"Shovel", 6, 1, 337, "shovel:shovelicon", WEAPONDATA_NO_AMMO },
	{"Pool Cue", 7, 1, 338, "poolcue:poolcueicon", WEAPONDATA_NO_AMMO },
	{"Katana", 8, 1, 339, "katana:katanaicon", WEAPONDATA_NO_AMMO },
	{"Chainsaw", 9, 1, 341, "chnsaw:chnsawicon", WEAPONDATA_NO_AMMO },
	{"Double-ended Dildo", 10, 10, 321, "gun_dildo2:gun_dildo2icon", WEAPONDATA_NO_AMMO },
	{"Dildo", 11, 10, 321, "gun_dildo2:gun_dildo2icon", WEAPONDATA_NO_AMMO },
	{"Vibrator", 12, 10, 323, "gun_dildo2:gun_dildo2icon", WEAPONDATA_NO_AMMO },
	{"Silver Vibrator", 13, 10, 324, "gun_dildo2:gun_dildo2icon", WEAPONDATA_NO_AMMO },
	{"Flowers", 14, 10, 325, "flowera:floweraicon", WEAPONDATA_NO_AMMO },
	{"Cane", 15, 10, 326, "gun_cane:gun_caneicon", WEAPONDATA_NO_AMMO },
	{"Grenade", 16, 8, 342, "grenade:grenadeicon", WEAPONDATA_NO_AMMO },
	{"Tear Gas", 17, 8, 343, "teargas:teargasicon", WEAPONDATA_NO_AMMO },
	{"Molotov Cocktail", 18, 8, 344, "molotov:molotovicon", WEAPONDATA_NO_AMMO },
	{"No gun", 19, -1, 0,"hud:fist", WEAPONDATA_NO_AMMO },
	{"No gun", 20, -1, 0,"hud:fist", WEAPONDATA_NO_AMMO },
	{"No gun", 21, -1, 0,"hud:fist", WEAPONDATA_NO_AMMO },
	{"Colt .45", 22, 2, 346, "colt45:colt45icon", WEAPONDATA_45ACP },
	{"Silenced Colt .45", 23, 2, 347,"colt45:colt45icon", WEAPONDATA_45ACP },
	{"Desert Eagle", 24, 2, 348,"colt45:colt45icon", WEAPONDATA_45ACP },
	{"Shotgun", 25, 3, 349, "shotgspa:shotgspaicon", WEAPONDATA_12GUAGE },
	{"Sawnoff Shotgun", 26, 3, 350, "sawnoff:sawnofficon", WEAPONDATA_12GUAGE },
	{"Combat Shotgun", 27, 3, 351, "shotgspa:shotgspaicon", WEAPONDATA_12GUAGE },
	{"Micro SMG", 28, 4, 352, "micro_uzi:micro_uziicon", WEAPONDATA_9MM },
	{"MP5", 29, 4, 353, "mp5lng:mp5lngicon", WEAPONDATA_9MM },
	{"AK47", 30, 5, 355, "ak47:ak47icon", WEAPONDATA_762MM },
	{"M4", 31, 5, 356, "m4:m4icon", WEAPONDATA_556MM },
	{"Tec-9", 32, 4, 372, "tec9:tec9icon", WEAPONDATA_9MM },
	{"Country Rifle", 33, 6, 357, "cuntgun:cuntgunicon", WEAPONDATA_762MM },
	{"Sniper Rifle", 34, 6, 358, "sniper:snipericon", WEAPONDATA_300MAGNUM },
	{"RPG", 35, 7, 359, "rocketla:rocketlaicon", WEAPONDATA_ROCKET },
	{"HS Rocket", 36, 7, 360, "rocketla:rocketlaicon", WEAPONDATA_ROCKET },
	{"Flamethrower", 37, 7, 361, "flame:flameicon", WEAPONDATA_NO_AMMO },
	{"Minigun", 38, 7, 362, "minigun:minigunicon", WEAPONDATA_762MM },
	{"Satchel Charge", 39, 8, 363, "satchel:satchelicon", WEAPONDATA_NO_AMMO },
	{"Detonator", 40, 12, 364, "bomb:bombicon", WEAPONDATA_NO_AMMO },
	{"Spraycan", 41, 9, 365, "spraycan:spraycanicon", WEAPONDATA_NO_AMMO },
	{"Fire Extinguisher", 42, 9, 366, "fire_ex:fire_exicon", WEAPONDATA_NO_AMMO },
	{"Camera", 43, 9, 367, "camera:cameraicon", WEAPONDATA_NO_AMMO },
	{"Night Vis Goggles", 44, 11, 368, "nvgoggles:nvgogglesicon", WEAPONDATA_NO_AMMO },
	{"Thermal Goggles", 45, 11, 369, "irgoggles:irgogglesicon", WEAPONDATA_NO_AMMO },
	{"Parachute", 46, 11, 371, "hud:fist", WEAPONDATA_NO_AMMO }
};

enum aPlayerInfo {
	aTBan,
	aTWarn,
	aTKick,
	aTCharge,
	aTJail,
	aTUnjail,
	aTUnwarn,
	aTUnban,
	aTPM
}
new AI[ MAX_PLAYERS ][ aPlayerInfo ];

#define MAX_INVENTORY 	30
#define INV_FILE                                  			  "Inventory/%s.ini"

enum inventoryData {
	bool:invExists,
	invItem[32],
	invModel,
	invQuantity
}
new inventoryInfo[ MAX_PLAYERS ][ MAX_INVENTORY ][ inventoryData ];

enum lala123 {
	Pol, 
	Level,  
	OnlineSati,
	Respekt,  
	Novac, 
	Banka,
	Upozorenja,
	Posao,
	Posaougovor,
	Godine, 
	Organizacija,
	Rank,
	Imovina1,
	Imovina2,
	Imovina3,
	Vozilo1,
	Vozilo2,
	Vozilo3,
	Vozilo4,
	Firma,
	StaffMin,
	LastLogin[ 64 ],
	Admin,
	GameSage,
	Hotel,
	eMail[ 34 ]
}
new OfflineCheck[ lala123 ];

#define IsValidWeapon(%0) (%0>=1 && %0<=18 || %0>=21 && %0<=46)

#define MAX_W_SLOTS 13

enum antiC {
	EnterVehTime,
	EnteredVehicle,
	TakeVehicle,
	SpamChat,
	SpamCommand,
	Weapon[ 13 ],
	Ammo[ 13 ],
	WeaponCheck,
	WeaponDetect,
	WeaponHack,
	TakenWeapon,
	TeleportCheck,
	Float:TeleportPos[ 3 ],
	TeleportHack,
	Float:TrueHealth,
	Float:TrueArmour,
	SpeedHack,
	AFKMinute,
	HighPing,
	bool:InTuningGarage,
	Float:AFKFirstPos[ 3 ],
	Float:AFKSecondPos[ 3 ],
	Float:SpeedPos[ 3 ],
	bool:SpeedFall,
	LastWShot,
	CPPort,
	SpamVehicle,
	LastAmmo,
	LastAmmoChecks,
	bool:RemoveVehicle,
	CPSCount,
	CPSTick,
	CWTime,
	CWVehID,
	ArmedWeapon,
	VehRepairTime
}
new antiCheatCS[ MAX_PLAYERS ][ antiC ];
new BusyVehicle[ MAX_VEHICLES ];

enum antiVS {
	Float:VehTrueHealth,
	VehCheck
}
new antiCheatVS[ MAX_VEHICLES ][ antiVS ];

new Float:RealVehiclePositions[ MAX_VEHICLES ][ 3 ];
new LastPullingVehicle[ MAX_VEHICLES ];

#define AC_ADMINPORUKA 0
#define AC_KICK 1
#define AC_BAN 2

#define DETECT_WEAPON_HACK 	    1
#define DETECT_AMMO_HACK   	    2
#define DETECT_TELEPORT_HACK    3
#define DETECT_FLY_HACK 	    4
#define DETECT_SPEED_HACK   	5
#define DETECT_JETPACK_HACK 	6
#define DETECT_VEHREPAIR_HACK   7

enum antiSS {
	WeaponHRezimRada,
	TeleportHRezimRada,
	HealthHRezimRada,
	SpeedHRezimRada,
	JetPackHRezimRada,
	MoneyHRezimRada,
	FlyHRezimRada,
	TuningHRezimRada,
	VehRepRezimRada,
	bool:antiWeaponH,
	bool:antiTeleportH,
	bool:antiHealthH,
	bool:antiArmourH,
	bool:antiSpeedH,
	bool:antiJetPackH,
	bool:antiMoneyH,
	bool:antiFlyH,
	bool:antiTuningH,
	bool:antiVehRepair
}
new antiCheatSS[ antiSS ];

#define MaxBrojKreiranih 1980
//------------------------------------------------------------------------------

#define SERVER_NAME_STRING_LENGTH 300
//TDEditor_TD[47],
enum Serva
{
	// save
	RegistrovanihKorisnika,
	BanovanihKorisnika,
	KikovanihKorisnika,
	BrojWarnova,
	BrojPosetaServeru,
	bool:HappyHours,
	PocetniLevel,
	PocetniNovaca,
	bool:KupovinaVozila,
	bool:Report,
	bool:Pitanja,
	bool:Oglasi,
	RekordServera,
	bool:Registracija,
	Drva,
	Zlato,
	Namestaj,
	NovacBanka,
	ReactTime,
	ReactName[ MAX_PLAYER_NAME ],
	// dont save
	Text3D:ZlatoLabel,
	Text3D:NovacLabel,
	Text3D:NovacLabel2,
	bool:HangarPaket,
	BrojImovina,
	BrojKontejnera,
	BrojKreiranihVozila,
	Prognozasys,
	VremeInGame,
	bool:RRVehicle,
	bool:HappyJobs,
	//grobar
	bool:PreuzetoGrobarVoziilo,
	//smsigra
	bool:VoziloDostavljeno,
	//sranje
	ServerName[SERVER_NAME_STRING_LENGTH],
	Online,
	Reklamiranje,
	ServerPassword
}
new ServerInfo[ Serva ];

//new UzeoVozilo[MAX_PLAYERS];
//------------------------------------------------------------------------------

enum InfoPoslova
{
	//1
	PlataKosaca,
	BonusKosaca,
	//
	GradjevinarZemljaPlata,
	BonusGradjevinarZemlja,
	//2
	GradjevinarBetonPlata,
	BonusGradjevinarBeton,
	//
	DjubretarPlata,
	BonusDjubretara,
	//3
	CistacUlicePlata,
	BonusCistacaUlica,
	//
	PilotBGPlata,
	BonusPilotBG,
	//
	PilotSAPlata,
	BonusPilotSA,
	//4
	PilotZGPlata,
	BonusPilotZG,
	//5
	MehanicarMotorPlata,
	MehanicarGumePlata,
	//
	FarmerZitoPlata,
	BonusFarmerZito,
	//
	FarmerBeracPlata,
	BonusBerac,
	//6
	FarmerMlijekoPlata,
	BonusMlijeko,
	//7
	DostavljacPizzePlata,
	BonusPizza,
	//8
	PlataTempo,
	BonusTempo,
	//
	PlataBusBG,
	BonusBusBG,
	//
	PlataBusSA,
	BonusBusSA,
	//9
	PlataBusZG,
	BonusBusZG,
	//
	RudarGramiZlata,
	//10
	RudarDostavaPlata,
	BonusRudarDostava
	
	
}
new PosloviInfo[ InfoPoslova ];

//------------------------------------------------------------------------------




enum rInfo {
	sCreated,
	Float:sX,
	Float:sY,
	Float:sZ,
	sObject,
	sSpike
};
new Roadblocks[ 100 ][ rInfo ];

enum BoomboxInfao {
	boomboxPlaced,
	Float:boomboxPos[ 3 ],
	boomboxInterior,
	boomboxWorld,
	boomboxObject,
	boomboxURL[128 char],
	Text3D:boomboxText3D
};
new BoomboxInfo[ MAX_PLAYERS ][ BoomboxInfao ];
new Boombox[ MAX_PLAYERS ];

enum rudarBre {
	rudarTimer,
	rudarIskopano,
	rudarObjects[ 3 ]
};
new rudarPosao[ MAX_PLAYERS ][ rudarBre ];

#define MAX_EVENTS      101
#define MAX_CP          202
#define MAX_TIME        33
#define EVENT_FILE      "Events/%d.ini"
new
	EventName[ MAX_PLAYERS ][ 64 ],
	EventCP[ MAX_PLAYERS ],
	EventCarsCreate[ MAX_PLAYERS ],
	EventID[ MAX_PLAYERS ],
	PlayerCP[ MAX_PLAYERS ],
	PlayerEventVehID[ MAX_PLAYERS ],
	EventVehID[ MAX_PLAYERS ],
	bool:PlayerCreateEvent[ MAX_PLAYERS ],
	Float:PlayerPos[ MAX_PLAYERS ][ 3 ],
	PlayerPosInt[ MAX_PLAYERS ],
	PlayerPosVW[ MAX_PLAYERS ];

enum jao {
	Drivers,
	Position,
	EventTime,
	eID,
	Vehicle[ 30 ]
}
new EventInfo[ jao ];

enum jo {
	Float:TCPX,
	Float:TCPY,
	Float:TCPZ,
	Float:TCPA,
	Float:TCPX2,
	Float:TCPY2,
	Float:TCPZ2,
	Float:TCPA2,
	Name[ 64 ],
	VehID,
	MaxCP,
	Float:PrivremeniX1,
	Float:PrivremeniY1,
	Float:PrivremeniX2,
	Float:PrivremeniY2
}
new Event[ MAX_EVENTS ][ jo ];

enum ev
{
	Float:CPX,
	Float:CPY,
	Float:CPZ,
}
new CheckPoint[ MAX_EVENTS ][ MAX_CP ][ ev ];

enum pCrime
{
	pAccusing[32],
	pDone,
	pLocation[32]
};
new PlayerCrime[ MAX_PLAYERS ][pCrime];

enum pAmbulance {
	pVictimLocation[ 32 ],
}
new PlayerInjured[ MAX_PLAYERS ][ pAmbulance ];

enum zlInfo {
	zPocinio[ MAX_PLAYER_NAME ],
	zPrijavio[ MAX_PLAYER_NAME ],
	zZlocin[ 64 ],
};
new ZlocinInfo[ MAX_PLAYERS ][ zlInfo ];

enum pMechanicService {
	pMechanicLocation[32],
}
new PlayerNeedMechanic[ MAX_PLAYERS ][pMechanicService];


enum e_garbagemanInfo {
	bool:gmiDuty,
	bool:gmiReadyToDump,
	bool:gmiHasGarbage,
	bool:gmiJob,
	gmiContainerID,
	gmiVehicleID
};
new garbagemanInfo[ MAX_PLAYERS ][ e_garbagemanInfo ];

enum g_Veh {
	gGarbages,
	gPlayerID
};
new garbagemanVehicles[ MAX_VEHICLES ][ g_Veh ];

#define MAX_FARMERS_PLANTS_PLANTED				10
#define MAX_FARMS 						      1000

enum ea_farmerInfo {
	farmPlayerID,
	bool:farmPlantCreated,
	bool:farmWheatCreated,
	farmObject,
	Text3D:farm3D
};
new plantInfo[ MAX_FARMS ][ ea_farmerInfo ];

enum e_farmerInfo {
	fiFarmerSeeds,
	fiFarmerPlantsPlanted,
	fiFarmerWheatCreated,
	fiFarmerPickupedBales,
	bool:fiFarmerPickupedBale,
	fiCowNumber,
	fiFruitNumber,
	fiFruitDeliveryNumber,
	fiVehicleBucket,
	fiVehicleFruit,
	fiBucketObject,
	bool:fiHaveBucket,
	bool:fiHaveGajbica,
	bool:fiHaveFruits
};
new farmerInfo[ MAX_PLAYERS ][ e_farmerInfo ];

enum aa
{
	fvSeeds,
	bool:fvMilk,//da li ima utovareno mlijeko
	fvMilkpID//za kojeg igraca je vozilo
};
new farmerVehicles[ MAX_VEHICLES ][ aa ];

new farmerField, AdminBaza, AutoPijacaBG,SSB, KosacMost, ZgradaNeka, GSFMost,SAJBaza, ZlataraSef, bankSafe, SpawnZona, GradjPosao, FarmerPosao, VineWoodArea;


enum aeass32 {
	Float:cpPos[ 3 ],
	Float:obPos[ 3 ]
};

new milkInfo[ 9 ][ aeass32 ] ={
	{ {-1013.2965,-1279.4894,130.8821}, {-1012.8652, -1279.7913, 129.9894} },
	{ {-999.9442,-1277.0166,131.7101}, {-999.3514, -1277.0195, 130.7761} },
	{ {-1001.9974,-1285.3643,131.8190}, {-1001.9038, -1285.9528, 130.9792} },
	{ {-992.6811,-1284.0557,132.0662}, {-992.1581, -1283.6869, 131.1604} },
	{ {-991.5820,-1273.1993,132.3684}, {-991.2403, -1273.6890, 131.4589} },
	{ {-1005.0901,-1265.4371,131.5786}, {-1005.4325, -1266.0370, 130.6398} },
	{ {-992.5124,-1262.6783,132.6911}, {-992.0071, -1262.3378, 131.8144} },
	{ {-1004.4811,-1252.0953,131.8424}, {-1004.4329, -1251.4368, 130.8970} },
	{ {-1018.6659,-1255.1324,130.8547}, {-1018.0547, -1255.0837, 130.0016} }
};

new hitfound = 0;
new ahitid = 999;

enum HitmanInfoa {
	GotHit,
	GetChased,
	GoChase,
	PlacedNews
};
new HitmanInfo[ MAX_PLAYERS ][ HitmanInfoa ];

new bool:pizzaVehicle[ MAX_VEHICLES ];

new LastCar[ MAX_PLAYERS ];

#define MAX_INTERIJERA 														 100
enum iinfo {
	iIme[32],
	Float:iXUlaz,
	Float:iYUlaz,
	Float:iZUlaz,
	Float:iAUlaz,
	Float:iXIzlaz,
	Float:iYIzlaz,
	Float:iZIzlaz,
	Float:iAIzlaz,
	iIntID,
	iIntIDSpolja,
	iVwID,
	iVwIDSpolja,
	iPickup,
	iPickupID,
	i3dLabel,
	i3dLabelID
};
new IntInfo[ MAX_INTERIJERA ][ iinfo ];
new intide;
/*
new ForbiddenNames [][] = {
	"GOVNO", "govno", "Govance", ".", "kurac", "mater", "jebem", ":", ";", "èuna", "æuna", "è", "æ", "š", "ð", "pizda",
	"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
	  "", "", "", "", "" };*/

new VehPrice[ 212 ][ 3 ] =
{
	{ 400, 600000, 10000 }, // Landstalker
	{ 401, 700000, 400 }, // Bravura
	{ 402, 850000, 466 }, // Buffalo
	{ 403, 0, 0 }, // Linerunner
	{ 404, 200000, 333 }, // Perenniel
	{ 405, 400000, 600 }, // Sentinel
	{ 406, 0, 0 }, // Dumper edit
	{ 407, 0, 0 }, // Firetruck edit
	{ 408, 0, 0 }, // Trashmaster edit
	{ 409, 700000, 1266 }, // Stretch
	{ 410, 400000, 433 }, // Manana
	{ 411, 5000000, 6533 }, // Infernus
	{ 412, 250000, 800 }, // Voodoo
	{ 413, 210000, 1050 }, // Pony
	{ 414, 0, 0 }, // Mule
	{ 415, 1000000, 4333 }, // Cheetah
	{ 416, 100, 100 }, // Ambulance
	{ 417, 500000, 2500 }, // Leviathan
	{ 418, 230000, 1150 }, // Moonbeam
	{ 419, 110000, 733 }, // Esperanto
	{ 420, 0, 0 }, // Taxi
	{ 421, 95000, 633 }, // Washington
	{ 422, 400000, 850 }, // Bobcat
	{ 423, 0, 0 }, // Mr Whoopee edit
	{ 424, 520000, 2600 }, // BF Injection edit
	{ 425, 0, 0 }, // Hunter edit
	{ 426, 400000, 1600 }, // Premier
	{ 427, 0, 0 }, // Enforcer edit
	{ 428, 0, 0 }, // Securicar edit
	{ 429, 800000, 800 }, // Banshee
	{ 430, 0, 0 }, // Predator edit
	{ 431, 0, 0 }, // Bus edit
	{ 432, 0, 0 }, // Rhino edit
	{ 433, 0, 0 }, // Barracks
	{ 434, 1500000, 1450 }, // Hotknife
	{ 435, 0, 0 }, // Article Trailer edit
	{ 436, 65000, 550 }, // Previon edit
	{ 437, 0, 0 }, // Coach edit
	{ 438, 0, 0 }, // Cabbie
	{ 439, 75000, 500 }, // Stallion
	{ 440, 0, 0 }, // Rumpo
	{ 441, 0, 0 }, // RC Bandit edit
	{ 442, 0, 0 }, // Romero
	{ 443, 0, 0 }, // Packer
	{ 444, 99999999, 99999 }, // Monster edit
	{ 445, 400000, 933 }, // Admiral
	{ 446, 600000, 3000 }, // Squallo edit
	{ 447, 300000, 1500 }, // Seasparrow edit
	{ 448, 0, 0 }, // Pizzaboy
	{ 449, 0, 0 }, // Tram edit
	{ 450, 0, 0 }, // Article Trailer 2 edit
	{ 451, 3000000, 4133 }, // Turismo
	{ 452, 450000, 2250 }, // Speeder edit
	{ 453, 220000, 1100 }, // Reefer edit
	{ 454, 800000, 4000 }, // Tropic edit
	{ 455, 0, 0 }, // Flatbed
	{ 456, 0, 0 }, // Yankee
	{ 457, 180000, 900 }, // Caddy edit
	{ 458, 350000, 1025 }, // Solair edit
	{ 459, 0, 0 }, // Topfun Van (Berkley's RC)
	{ 460, 640000, 3200 }, // Skimmer edit
	{ 461, 650000, 3250 }, // PCJ-600
	{ 462, 150000, 950 }, // Faggio
	{ 463, 350000, 1750 }, // Freeway
	{ 464, 0, 0 }, // RC Baron edit
	{ 465, 0, 0 }, // RC Raider edit
	{ 466, 100000, 500 }, // Glendale
	{ 467, 100000, 500 }, // Oceanic
	{ 468, 500000, 2500 }, // Sanchez
	{ 469, 590000, 2950 }, // Sparrow edit
	{ 470, 99999999, 99999 }, // Patriot
	{ 471, 300000, 1450 }, // Quad
	{ 472, 0, 0 }, // Coastguard edit
	{ 473, 170000, 850 }, // Dinghy edit
	{ 474, 110000, 550 }, // Hermes
	{ 475, 110000, 733 }, // Sabre
	{ 476, 415000, 2075 }, // Rustler edit
	{ 477, 330000, 2200 }, // ZR-350
	{ 478, 0, 0 }, // Walton
	{ 479, 150000, 366 }, // Regina
	{ 480, 500000, 500 }, // Comet
	{ 481, 30000, 150 }, // BMX edit
	{ 482, 250000, 1250 }, // Burrito
	{ 483, 999999, 1075 }, // Camper
	{ 484, 505000, 2525 }, // Marquis edit
	{ 485, 0, 0 }, // Baggage edit
	{ 486, 0, 0 }, // Dozer
	{ 487, 950000, 4750 }, // Maverick edit
	{ 488, 0, 0 }, // SAN News Maverick edit
	{ 489, 200000, 1333 }, // Rancher
	{ 490, 0, 0 }, // FBI Rancher edit
	{ 491, 195000, 975 }, // Virgo
	{ 492, 120000, 800 }, // Greenwood
	{ 493, 99999999, 99999 }, // Jetmax edit
	{ 494, 99999999, 99999 }, // Hotring Racer edit
	{ 495, 99999999, 99999 }, // Sandking edit
	{ 496, 160000, 1066 }, // Blista Compact
	{ 497, 0, 0 }, // Police Maverick edit
	{ 498, 0, 0 }, // Boxville
	{ 499, 0, 0 }, // Benson
	{ 500, 95000, 633 }, // Mesa
	{ 501, 0, 0 }, // RC Goblin edit
	{ 502, 930000, 4650 }, // Hotring Racer edit
	{ 503, 930000, 4650 }, // Hotring Racer edit
	{ 504, 0, 0 }, // Bloodring Banger edit
	{ 505, 200000, 1333 }, // Rancher
	{ 506, 550000, 3666 }, // Super GT
	{ 507, 100000, 666 }, // Elegant
	{ 508, 0, 0 }, // Journey
	{ 509, 30000, 150 }, // Bike edit
	{ 510, 25000, 125 }, // Mountain Bike edit
	{ 511, 0, 0 }, // Beagle edit
	{ 512, 545000, 2725 }, // Cropduster edit
	{ 513, 515000, 2575 }, // Stuntplane edit
	{ 514, 0, 0 }, // Tanker
	{ 515, 0, 0 }, // Roadtrain
	{ 516, 120000, 800 }, // Nebula
	{ 517, 250000, 1250 }, // Majestic
	{ 518, 185000, 925 }, // Buccaneer
	{ 519, 2000000, 10000 }, // Shamal edit
	{ 520, 0, 0 }, // Hydra edit
	{ 521, 850000, 4250 }, // FCR-900
	{ 522, 1000000, 5000 }, // NRG-500
	{ 523, 0, 0 }, // HPV1000 edit
	{ 524, 0, 0 }, // Cement Truck
	{ 525, 0, 0 }, // Towtruck
	{ 526, 335000, 1675 }, // Fortune
	{ 527, 215000, 1075 }, // Cadrona edit
	{ 528, 0, 0 }, // FBI Truck edit
	{ 529, 200000, 1000 }, // Willard
	{ 530, 0, 0 }, // Forklift edit
	{ 531, 315000, 1575 }, // Tractor
	{ 532, 0, 0 }, // Combine Harvester
	{ 533, 150000, 1000 }, // Feltzer
	{ 534, 185000, 1233 }, // Remington
	{ 535, 225000, 1125 }, // Slamvan
	{ 536, 170000, 1133 }, // Blade
	{ 537, 0, 0 }, // Freight edit
	{ 538, 0, 0 }, // Brownstreak edit
	{ 539, 0, 0 }, // Vortex edit
	{ 540, 420000, 2100 }, // Vincent edit
	{ 541, 700000, 4666 }, // Bullet
	{ 542, 205000, 1025 }, // Clover
	{ 543, 195000, 975 }, // Sadler
	{ 544, 0, 0 }, // Firetruck LA edit
	{ 545, 530000, 2650 }, // Hustler
	{ 546, 210000, 1050 }, // Intruder
	{ 547, 85000, 566 }, // Primo
	{ 548, 0, 0 }, // Cargobob edit
	{ 549, 280000, 1400 }, // Tampa
	{ 550, 390000, 1950 }, // Sunrise
	{ 551, 100000, 666 }, // Merit
	{ 552, 0, 0 }, // Utility Van edit
	{ 553, 0, 0 }, // Nevada edit
	{ 554, 570000, 2850 }, // Yosemite
	{ 555, 370000, 1850 }, // Windsor
	{ 556, 99999999, 99999 }, // Monster "A" edit
	{ 557, 99999999, 99999 }, // Monster "B" edit
	{ 558, 520000, 2600 }, // Uranus
	{ 559, 550000, 3666 }, // Jester
	{ 560, 1200000, 4666 }, // Sultan
	{ 561, 585000, 2925 }, // Stratum
	{ 562, 700000, 4333 }, // Elegy
	{ 563, 0, 0 }, // Raindance edit
	{ 564, 0, 0 }, // RC Tiger edit
	{ 565, 500000, 966 }, // Flash
	{ 566, 130000, 866 }, // Tahoma
	{ 567, 220000, 1466 }, // Savanna
	{ 568, 400000, 2000 }, // Bandito
	{ 569, 0, 0 }, // Freight Flat Trailer edit
	{ 570, 0, 0 }, // Streak Trailer edit
	{ 571, 99999999, 99999 }, // Kart
	{ 572, 0, 0 }, // Mower
	{ 573, 770000, 3850 }, // Dune
	{ 574, 0, 0 }, // Sweeper
	{ 575, 385000, 1925 }, // Broadway
	{ 576, 195000, 975 }, // Tornado
	{ 577, 0, 0 }, // AT400 edit
	{ 578, 600000, 3000 }, // DFT-30
	{ 579, 750000, 5066 }, // Huntley
	{ 580, 250000, 1200 }, // Stafford
	{ 581, 580000, 2900 }, // BF-400
	{ 582, 0, 0 }, // Newsvan edit
	{ 583, 0, 0 }, // Tug edit
	{ 584, 0, 0 }, // Petrol Trailer edit
	{ 585, 400000, 1050 }, // Emperor
	{ 586, 400000, 2000 }, // Wayfarer
	{ 587, 450000, 600 }, // Euros
	{ 588, 0, 0 }, // Hotdog edit
	{ 589, 400000, 2425 }, // Club
	{ 590, 0, 0 }, // Freight Box Trailer edit
	{ 591, 0, 0 }, // Article Trailer 3 edit
	{ 592, 0, 0 }, // Andromada edit
	{ 593, 395000, 1975 }, // Dodo edit
	{ 594, 0, 0 }, // RC Cam edit
	{ 595, 0, 0 }, // Launch edit
	{ 596, 0, 0 }, // Police Car (LShowPlayerDialog) edit
	{ 597, 0, 0 }, // Police Car (SFPD) edit
	{ 598, 0, 0 }, // Police Car (LVPD) edit
	{ 599, 0, 0 }, // Police Ranger edit
	{ 600, 350000, 1525 }, // Picador
	{ 601, 0, 0 }, // S.W.A.T. edit
	{ 602, 450000, 2025 }, // Alpha
	{ 603, 450000, 1666 }, // Phoenix
	{ 604, 0, 0 }, // Glendale Shit edit
	{ 605, 0, 0 }, // Sadler Shit edit
	{ 606, 0, 0 }, // Baggage Trailer "A" edit
	{ 607, 0, 0 }, // Baggage Trailer "B" edit
	{ 608, 0, 0 }, // Tug Stairs Trailer edit
	{ 609, 0, 0 }, // Boxville
	{ 610, 0, 0 }, // Farm Trailer edit
	{ 611, 0, 0 } // Utility Trailer edit
};

#if defined retardirani_textdrawi
new Text:moderntds[50];
#endif

new VehicleSpeedAC[ 212 ][ 2 ] =
{
	{ 400, 162 },
	{ 401, 151 },
	{ 402, 191 },
	{ 403, 114 },
	{ 404, 137 },
	{ 405, 168 },
	{ 406, 115 },
	{ 407, 153 },
	{ 408, 105 },
	{ 409, 150 },
	{ 410, 134 },
	{ 411, 225 },
	{ 412, 173 },
	{ 413, 115 },
	{ 414, 110 },
	{ 415, 196 },
	{ 416, 158 },
	{ 417, 135 }, //avion
	{ 418, 120 },
	{ 419, 163 },
	{ 420, 149 },
	{ 421, 158 },
	{ 422, 144 },
	{ 423, 103 },
	{ 424, 139 },
	{ 425, 215 }, //avion
	{ 426, 178 },
	{ 427, 160 },
	{ 428, 162 },
	{ 429, 206 },
	{ 430, 0 }, // brod
	{ 431, 135 },
	{ 432, 99 },
	{ 433, 115 },
	{ 434, 171 },
	{ 435, 0 }, //prikolica
	{ 436, 153 },
	{ 437, 162 },
	{ 438, 147 },
	{ 439, 173 },
	{ 440, 140 },
	{ 441, 0 }, //mali autic
	{ 442, 144 },
	{ 443, 131 },
	{ 444, 115 },
	{ 445, 168 },
	{ 446, 0 }, // brod
	{ 447, 155 },
	{ 448, 189 },
	{ 449, 0 }, // tramvaj
	{ 450, 0 }, // prikolica
	{ 451, 197 },
	{ 452, 0 }, //BROD
	{ 453, 0 }, //BROD
	{ 454, 0 }, //BROD
	{ 455, 162 },
	{ 456, 110 },
	{ 457, 100 },
	{ 458, 161 },
	{ 459, 140 },
	{ 460, 155 },
	{ 461, 195 },
	{ 462, 184 },
	{ 463, 206 },
	{ 464, 0 }, //mali avion igracka
	{ 465, 0 }, //mali tenk igracka
	{ 466, 152 },
	{ 467, 145 },
	{ 468, 185 },
	{ 469, 120 }, //
	{ 470, 161 },
	{ 471, 115 },
	{ 472, 0 }, //BROD
	{ 473, 0 }, //BROD
	{ 474, 153 },
	{ 475, 177 },
	{ 476, 275 }, //(ZNAM DA JE NEREALNO AL I NEREALAN JE AVION)
	{ 477, 191 },
	{ 478, 122 },
	{ 479, 144 },
	{ 480, 188 },
	{ 481, 0 }, //BMX
	{ 482, 161 }, //
	{ 483, 128 },
	{ 484, 0 }, //BROD
	{ 485, 105 },
	{ 486, 70 },
	{ 487, 190 },
	{ 488, 160 },
	{ 489, 144 },
	{ 490, 163 },
	{ 491, 153 },
	{ 492, 145 },
	{ 493, 0 }, //
	{ 494, 219 },
	{ 495, 181 },
	{ 496, 167 },
	{ 497, 190 },
	{ 498, 113 },
	{ 499, 128 },
	{ 500, 145 },
	{ 501, 35 },
	{ 502, 219 },
	{ 503, 219 },
	{ 504, 177 },
	{ 505, 144 },
	{ 506, 183 },
	{ 507, 170 },
	{ 508, 112 },
	{ 509, 0 }, //Biciklo
	{ 510, 0 }, //Biciklo
	{ 511, 187 },
	{ 512, 197 },
	{ 513, 0 }, //
	{ 514, 125 },
	{ 515, 147 },
	{ 516, 161 },
	{ 517, 162 },
	{ 518, 169 },
	{ 519, 268 },
	{ 520, 268 },
	{ 521, 210 },
	{ 522, 215 },
	{ 523, 200 },
	{ 524, 135 },
	{ 525, 165 },
	{ 526, 162 },
	{ 527, 153 },
	{ 528, 180 },
	{ 529, 153 },
	{ 530, 66 },
	{ 531, 75 },
	{ 532, 115 },
	{ 533, 171 },
	{ 534, 173 },
	{ 535, 163 },
	{ 536, 177 },
	{ 537, 0 }, // voz
	{ 538, 0 }, // Voz -
	{ 539, 105 },
	{ 540, 153 },
	{ 541, 207 },
	{ 542, 169 },
	{ 543, 155 },
	{ 544, 153 },
	{ 545, 151 },
	{ 546, 153 },
	{ 547, 147 },
	{ 548, 0 }, //Helikopter - Nece da poleti.
	{ 549, 158 },
	{ 550, 149 },
	{ 551, 162 },
	{ 552, 125 },
	{ 553, 0 }, // avion golem
	{ 554, 148 },
	{ 555, 165 },
	{ 556, 115 },
	{ 557, 115 },
	{ 558, 160 },
	{ 559, 182 },
	{ 560, 174 },
	{ 561, 159 },
	{ 562, 182 },
	{ 563, 145 },
	{ 564, 0 }, //-mali tenk igracka
	{ 565, 169 },
	{ 566, 164 },
	{ 567, 178 },
	{ 568, 151 },
	{ 569, 0 }, //VOZ
	{ 570, 0 }, //VOZ
	{ 571, 98 },
	{ 572, 65 },
	{ 573, 115 },
	{ 574, 110 },
	{ 575, 162 },
	{ 576, 162 },
	{ 577, 0 }, //NEPOTREBAN AVION
	{ 578, 135 },
	{ 579, 163 },
	{ 580, 158 },
	{ 581, 201 },
	{ 582, 140 },
	{ 583, 90 },
	{ 584, 0 }, //Prikolica
	{ 585, 157 },
	{ 586, 209 },
	{ 587, 169 },
	{ 588, 112 },
	{ 589, 168 },
	{ 590, 0 }, //Vagon
	{ 591, 0 }, //Prikolica
	{ 592, 268 },
	{ 593, 268 },
	{ 594, 0 }, //Saksija
	{ 595, 0 }, //Brod -
	{ 596, 180 },
	{ 597, 180 },
	{ 598, 180 },
	{ 599, 162 },
	{ 600, 155 },
	{ 601, 115 },
	{ 602, 173 },
	{ 603, 175 },
	{ 604, 151 },
	{ 605, 155 },
	{ 606, 0 }, //Prikolica
	{ 607, 0 }, //Prikolica
	{ 608, 0 }, //Prikolica
	{ 609, 112 },
	{ 610, 0 }, //Prikolica
	{ 611, 0 } //Prikolica
};

// Definicija ostecena po oruzju i delu tela

/*new Float:WeaponDamage[ 43 ][ 7 ] = {
	{5.0, 15.0, 2.0, 2.0, 7.0, 7.0, 20.0}, // Unarmed
	{10.0, 15.0, 15.0, 22.0, 22.0, 22.0, 30.0},// Brass Knuckles
	{15.0, 25.0, 5.0, 5.0, 7.0, 7.0, 35.0},// Golf Club
	{25.0, 25.0, 7.0, 7.0, 10.0, 10.0, 30.0},// Night Stick
	{40.0, 50.0, 15.0, 15.0, 17.0, 17.0, 60.0},// Knife
	{15.0, 25.0, 5.0, 5.0, 7.0, 7.0, 35.0},// Baseball Bat
	{15.0, 25.0, 5.0, 5.0, 7.0, 7.0, 35.0},// Shovel
	{10.0, 50.0, 5.0, 5.0, 17.0, 17.0, 10.0},// Pool Cue
	{50.0, 55.0, 25.0, 25.0, 27.0, 27.0, 100.0},// Katana
	{70.0, 75.0, 50.0, 50.0, 60.0, 60.0, 100.0},// Chainsaw
	{10.0, 50.0, 5.0, 5.0, 7.0, 7.0, 50.0}, // dildo
	{10.0, 50.0, 5.0, 5.0, 7.0, 7.0, 50.0}, // dildo
	{10.0, 50.0, 5.0, 5.0, 7.0, 7.0, 50.0}, // dildo
	{10.0, 50.0, 5.0, 5.0, 7.0, 7.0, 50.0}, // dildo
	{5.0, 5.0, 1.0, 1.0, 5.0, 5.0, 10.0}, // Flowers
	{10.0, 50.0, 5.0, 5.0, 7.0, 7.0, 50.0}, // Cane
	{100.0, 100.0, 50.0, 50.0, 60.0, 60.0, 100.0},// Grenade
	{5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0}, // Tear Gas
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0}, // Molotov
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0},//"Invalid Weapon",
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0},//"Invalid Weapon",
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0},//"Invalid Weapon",
	{35.0, 50.0, 15.0, 15.0, 17.0, 17.0, 100.0}, // Colt 45
	{35.0, 50.0, 15.0, 15.0, 17.0, 17.0, 100.0}, // Silenced Colt 45
	{55.0, 60.0, 25.0, 25.0, 27.0, 27.0, 100.0}, // Desert Eagle
	{90.0, 80.0, 35.0, 35.0, 47.0, 47.0, 100.0}, // Shotgun
	{90.0, 80.0, 35.0, 35.0, 47.0, 47.0, 100.0}, // Sawno-ff Shotgun
	{90.0, 80.0, 35.0, 35.0, 47.0, 47.0, 100.0}, // Combat Shotgun
	{70.0, 80.0, 25.0, 25.0, 27.0, 27.0, 100.0}, // Micro SMG
	{80.0, 80.0, 30.0, 30.0, 35.0, 35.0, 100.0}, // SMG
	{80.0, 80.0, 40.0, 40.0, 45.0, 45.0, 100.0}, // AK47
	{80.0, 80.0, 40.0, 40.0, 45.0, 45.0, 100.0}, // M4
	{70.0, 80.0, 25.0, 25.0, 27.0, 27.0, 100.0}, // Tec9
	{80.0, 80.0, 30.0, 30.0, 35.0, 35.0, 100.0}, // Country Rifle
	{100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0}, // Sniper Rifle
	{100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0}, // Rocket Launcher
	{100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0}, // HS Rocket Launcher
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0}, // Flamethrower
	{70.0, 80.0, 20.0, 20.0, 30.0, 30.0, 100.0}, // Minigun
	{100.0, 100.0, 50.0, 50.0, 60.0, 60.0, 100.0},// Satchel Charge
	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},// Detonator
	{10.0, 5.0, 5.0, 5.0, 5.0, 5.0, 15.0}, // Spray Can
	{10.0, 5.0, 5.0, 5.0, 5.0, 5.0, 15.0} // Fire Extinguisher
};*/

//------------------------------------------------------------------------------
new WeapNames[ 48 ][ 32 ] = {
	"Unarmed",
	"Brass Knuckles",
	"Golf Club",
	"Night Stick",
	"Knife",
	"Baseball Bat",
	"Shovel",
	"Pool Cue",
	"Katana",
	"Chainsaw",
	"Purple Dildo",
	"Big White Vibrator",
	"Medium White Vibrator",
	"Small White Vibrator",
	"Flowers",
	"Cane",
	"Grenade",
	"Tear Gas",
	"Molotov",
	"Invalid Weapon",
	"Invalid Weapon",
	"Invalid Weapon",
	"Colt 45",
	"Silenced Colt 45",
	"Desert Eagle",
	"Shotgun",
	"Sawno-ff Shotgun",
	"Combat Shotgun",
	"Micro SMG",
	"SMG",
	"AK47",
	"M4",
	"Tec9",
	"Country Rifle",
	"Sniper Rifle",
	"Rocket Launcher",
	"HS Rocket Launcher",
	"Flamethrower",
	"Minigun",
	"Satchel Charge",
	"Detonator",
	"Spray Can",
	"Fire Extinguisher",
	"Camera",
	"Night Vision Goggles",
	"Infrared Vision Goggles",
	"Parachute",
	"Fake Pistol"
};
new acolorid = 0;



//===========================[ FORWARDOVI ]=====================================

forward split(const strsrc[], strdest[][], delimiter);

forward PetSec();
forward ImmobCountForPlayer( playerid );
forward BreakLockCountForPlayer( playerid );
forward Register( playerid );
forward LoadATM( id, name[], value[] );
forward ZaustaviWAR( w );
forward TimerWAROstaloVremeB( w );
forward VehicleBreakLock( playerid, vehicleid, autoid );
forward TrashLimitOff( playerid );
forward UpdatePlayerGps( playerid, fresh );
forward GetPlayerBusinessId( playerid, type );
forward LoadEvent( id, name[], value[] );
forward EventTimeR( );
forward UlazIzlaz( playerid);
forward SacuvajATM( id );
forward StopCameraEffect( playerid );
forward Speeding( playerid );
forward NewsOn( );
forward AddsOn( );
forward SaveBussines( id );
forward SaveProperty( id );
forward SacuvajObjekte( id );
forward OcitajImovinu( id, name[], value[] );
forward OcitajObjekte( id, name[], value[] );
forward SacuvajKont( id );
forward OcitajKont( id, name[], value[] );
forward OcitajFirmu( idx, name[], value[] );
forward SaveVehicle( id );
forward SaveAntiCheat( );
forward LoadAntiCheat( name[ ], value[ ] );
forward OcitajVozilo( id, name[], value[] );
forward PorukaRadius( Float:radi, playerid, string[ ], col1 );
forward SlobodnoSada( playerid );
forward PostaviSpawn( playerid );
forward OcitajKorisnika( playerid, name[ ], value[ ] );
forward OcitajAdmina( playerid, name[ ], value[ ] );
forward SaveOrganization( id );
forward UcitajOrganizaciju( id, name[], value[] );
forward VehicleEngineStart( playerid );
forward KneeTrain( playerid );
forward BoxTrain( playerid );
forward KungTrain( playerid );
forward GrabTrain( playerid );
forward GPSConnect( playerid, gpslvl, vehicleid );
forward KickIgraca( playerid );
forward AntiSpawnCrash();
forward ResprayTimer( playerid, autoid );
forward CarDamageTimer( playerid );
forward CheckGas( playerid );
forward Fillup( playerid, fuel );
forward Postaviotable( playerid, izbor );
forward Istovar( playerid, vehicleid, broj );
forward Utovar( playerid, vehicleid, broj );
forward PayDay( playerid );
forward PayCheck( playerid );
forward StopMusic( );
forward TravaT( i );
forward ZetvaT( i );
forward SrednjaCasovi( playerid, broj );
forward FakultetCasovi( playerid, broj );
forward OsnovnaCasovi( playerid, broj );
forward CistacKilometri( playerid );
#if nerp_droga == 1
forward CarCheck( playerid );
#endif
forward DinamicWeather( );
forward LoadFurniture( hid );
forward SaveFurniture( hid );
forward Provala( playerid );
forward TazovanTajmer( playerid );
forward BackupClear( playerid, calledbytimer );
forward KSpam( playerid );
forward PocetniTut( playerid, izbor );
forward Taxitimer( playerid );
forward SacuvajAdmina( playerid );
forward Ame( playerid );
forward ClearKnock( playerid );
forward ClearPlayerRob( playerid );
forward RolePlayTut( playerid, learnid );
forward Provera1( playerid, type );
forward Provera2( playerid, type );

new OneSeatVehicles[ 38 ] = {

	425, 430, 432, 441, 446, 448, 452, 453,
	454, 464, 465, 472, 473, 476, 481, 484,
	485, 486, 493, 501, 509, 510, 519, 520,
	530, 531, 532, 539, 553, 564, 568, 571,
	572, 574, 583, 592, 594, 595
};

#define beta_testing 0
#define GetVehicleNameEx(%0)      						   ImeVozila[(%0) - 400]

#define notification_line_break 30
new NotifTimer[MAX_PLAYERS];

new hidemoneytdtimer[MAX_PLAYERS];

new AnnounceTextDrawsOn[MAX_PLAYERS];

new bool:OnFly[MAX_PLAYERS];

new bool:Leti[MAX_PLAYERS];

forward InitFly(playerid);
forward bool:StartFly(playerid);					// pocinje da leti
forward Fly(playerid);								// tajmer
forward bool:StopFly(playerid);						// prestaje da leti
forward SetPlayerLookAt(playerid,Float:x,Float:y);	// set player face position

#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


forward PumpaIstovar( playerid );
public PumpaIstovar( playerid ) {

	Dimi_KillTimer( Pistovar[ playerid ] );
	TogglePlayerControllable( playerid, true );
	announcement( playerid, "~w~ISTOVARENO", 5000, 1 );
	SendInfoMessage( playerid, "Gorivo je uspjesno istovareno!");
	Pistovara[ playerid ] = false;

	new fstationID = VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vFuelProperty ];
	new cisternID = FuelStation[ fstationID ][ fsCisternID ];

	new stringce[ 256 ];
	format( stringce, sizeof stringce, ""col_balkanstory"[ "col_white"CISTERNA "col_balkanstory"]\n"col_balkanstory"Dizel: {FFFFFF}%d/300 litara\n"col_balkanstory"Benzin: {FFFFFF}%d/300 litara\n"col_balkanstory"Gas: {FFFFFF}%d/300 litara\n"col_balkanstory"Kerozin: {FFFFFF}%d/300 litara\n\n"col_balkanstory"[ {FFFFFF}%s "col_balkanstory"]",
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 0 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 1 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 3 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 2 ],
		FuelStation[ fstationID ][ fsName ] );

	Delete3DTextLabel( VehicleInfo[ cisternID ][ v3DText ] );

	VehicleInfo[ cisternID ][ Validv3DText ] = true;
	VehicleInfo[ cisternID ][ v3DText ] = Create3DTextLabel( stringce, 0x33CCFFAA, 0.0, 0.0, 0.0, 30.0, 0, 1 );
	Attach3DTextLabelToVehicle( VehicleInfo[ cisternID ][ v3DText ], VehicleInfo[ cisternID ][ vID ], 0.0, 0.0, 0.0);
	return 1;
}

forward PumpaUtovar( playerid );
public PumpaUtovar( playerid ) {

	Dimi_KillTimer( Putovar[ playerid ] );
	TogglePlayerControllable( playerid, true );
	announcement(playerid, "~w~UTOVARENO", 5000, 1);
	SendInfoMessage( playerid, "Gorivo je uspjesno utovareno!");
	Putovara[ playerid ] = false;

	new fstationID = VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vFuelProperty ];
	new cisternID = FuelStation[ fstationID ][ fsCisternID ];

	Delete3DTextLabel( VehicleInfo[ cisternID ][ v3DText ] );

	new stringce[ 256 ];
	format( stringce, sizeof stringce, ""col_balkanstory"[ "col_white"CISTERNA "col_balkanstory"]\n"col_balkanstory"Dizel: {FFFFFF}%d/300 litara\n"col_balkanstory"Benzin: {FFFFFF}%d/300 litara\n"col_balkanstory"Gas: {FFFFFF}%d/300 litara\n"col_balkanstory"Kerozin: {FFFFFF}%d/300 litara\n\n"col_balkanstory"[ {FFFFFF}%s "col_balkanstory"]",
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 0 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 1 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 3 ],
		CisternFuel[ VehicleInfo[ cisternID ][ vID ] ][ 2 ],
		FuelStation[ fstationID ][ fsName ] );

	VehicleInfo[ cisternID ][ Validv3DText ] = true;
	VehicleInfo[ cisternID ][ v3DText ] = Create3DTextLabel( stringce, 0x33CCFFAA, 0.0, 0.0, 0.0, 30.0, 0, 1 );
	Attach3DTextLabelToVehicle( VehicleInfo[ cisternID ][ v3DText ], VehicleInfo[ cisternID ][ vID ], 0.0, 0.0, 0.0);
	return 1;
}


//////////////////////////////////////////////////////////


//------------------------------------------------------------------------------

forward SkiniRobZlatare( );
public SkiniRobZlatare( ) {

	Dimi_KillTimer( TimerZlatareVracanje );
	
	ZlataraUToku = false;
	ZlataraOpljackana = false;

	return true;
}

forward SkiniRobBanke( );
public SkiniRobBanke( ) {

	Dimi_KillTimer( TimerBankeVracanje );

	if( SruseniLaseri == true )
	{

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
	}
	
	BankaOpljackana = false;
	PljackaUToku = false;
	
	if( VrataBankeSrusena == true ) {
		if( IsValidDynamicObject( VrataSefaBanke ) )
			DestroyDynamicObject( VrataSefaBanke );

		VrataSefaBanke = CreateDynamicObject(2634, 1470.7053, -1015.7482, 2046.0902,   0.0000, 0.0000, 0.0000);//normala
		VrataBankeSrusena = false;
	}
	return true;
}

forward PljackanjeZlatarice( playerid );
public PljackanjeZlatarice( playerid ) {
	new string[ 128 ];
	if( IsPlayerInDynamicArea( playerid, ZlataraSef ) ) {
		if( ZlatoVreme[ playerid ] > 0 ) {
		
			new zlato = random(2)+1;
		
			if( ServerInfo[ Zlato ] >= (PljackaZlato[ playerid ] + zlato) )  {

				PljackaZlato[ playerid ] += zlato;
				format( string, sizeof( string ), "~w~Ostanite u sefu jos ~r~%d ~w~sekundi", ZlatoVreme[ playerid ] );
				announcement( playerid, string, 1000, 4 ) ;
				ZlatoVreme[ playerid ]--;
			
			}
			else if( ServerInfo[ Zlato ] < (PljackaZlato[ playerid ] + zlato) ) {
			
				announcement( playerid, "~w~Nema vise zlata u sefu!", 1000, 4) ;
				ZlatoVreme[ playerid ] = 0;
				SendInfoMessage( playerid, "Opljackali ste zlataru i uzeli ste %d grama zlata!", PljackaZlato[ playerid ] );
				Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] );
				SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackano zlato!" );
				VremeZaZlato[ playerid ] = 120;
				PostaviWanted( playerid, "Pljacka Zlatare", "Nepoznati", 6 );
				ZlataraUToku = false;
				
				ServerInfo[ Zlato ] -= PljackaZlato[ playerid ];
				SaveServerStats( );
				new zlatostring[ 256 ];
				format( zlatostring, sizeof( zlatostring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%dg "col_white"zlata\n"col_white"Da opljackate zlataru kucajte\n"col_balkanstory"[ /pljackajzlataru ]", ServerInfo[ Zlato ] );
				UpdateDynamic3DTextLabelText( ServerInfo[ ZlatoLabel ], BELA, zlatostring );
				

				format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Zlatara je opljackana i opljackano je %dg zlata.", PljackaZlato[ playerid ] );
				OOCNews( 0xFFA500AA, globalstring );
			}
		}
		else if( ZlatoVreme[ playerid ] == 0 ) {
		
			format(string, sizeof( string ),"~w~Opljackali ste zlataru i uzeli ~g~%dg zlata !", PljackaZlato[ playerid ] );
			announcement( playerid, string, 6000, 4 );
			SendInfoMessage( playerid, "Opljackali ste zlataru i uzeli ste %d grama zlata!", PljackaZlato[ playerid ] );
			SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackano zlato!" );
			Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] );
			ZlatoVreme[ playerid ] = 0;
			VremeZaZlato[ playerid ] = 120;
			PostaviWanted( playerid, "Pljacka Zlatare", "Nepoznati", 6 );
			ZlataraUToku = false;
			
			ServerInfo[ Zlato ] -= PljackaZlato[ playerid ];
			SaveServerStats( );
			new zlatostring[ 256 ];
			format( zlatostring, sizeof( zlatostring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%dg "col_white"zlata\n"col_white"Da opljackate zlataru kucajte\n"col_balkanstory"[ /pljackajzlataru ]", ServerInfo[ Zlato ] );
			UpdateDynamic3DTextLabelText( ServerInfo[ ZlatoLabel ], BELA, zlatostring );

			format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Zlatara je opljackana i opljackano je %dg zlata.", PljackaZlato[ playerid ] );
			OOCNews( 0xFFA500AA, globalstring );
		}
	}
	else {
		announcement( playerid, "~w~Otisli ste iz sefa!", 1000, 4) ;
		ZlatoVreme[ playerid ] = 0;
		SendInfoMessage( playerid, "Opljackali ste zlataru i uzeli ste %d grama zlata!", PljackaZlato[ playerid ] );
		Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] );
		SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackano zlato!" );
		VremeZaZlato[ playerid ] = 120;
		PostaviWanted( playerid, "Pljacka Zlatare", "Nepoznati", 6 );
		ZlataraUToku = false;
		
		ServerInfo[ Zlato ] -= PljackaZlato[ playerid ];
		SaveServerStats( );
		new zlatostring[ 256 ];
		format( zlatostring, sizeof( zlatostring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%dg "col_white"zlata\n"col_white"Da opljackate zlataru kucajte\n"col_balkanstory"[ /pljackajzlataru ]", ServerInfo[ Zlato ] );
		UpdateDynamic3DTextLabelText( ServerInfo[ ZlatoLabel ], BELA, zlatostring );

		format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Zlatara je opljackana i opljackano je %dg zlata.", PljackaZlato[ playerid ] );
		OOCNews( 0xFFA500AA, globalstring );
	}
	return true;
}

forward PljackanjeBankice( playerid );
public PljackanjeBankice( playerid ) {
	new string[ 128 ];
	if( IsPlayerInDynamicArea( playerid, bankSafe ) ) {
		if( PljackaVreme[ playerid ] > 0 ) {
		
			new novac = random(51)+300;
			
			if( ServerInfo[ NovacBanka ] >= (PljackaNovac[ playerid ] + novac) )  {
			
				PljackaNovac[ playerid ] += novac;
				format( string, sizeof( string ), "~w~Ostanite u sefu jos ~r~%d ~w~sekundi", PljackaVreme[ playerid ] );
				announcement( playerid, string, 1000, 4 ) ;
				PljackaVreme[ playerid ]--;
				
			}
			else if( ServerInfo[ NovacBanka ] < (PljackaNovac[ playerid ] + novac) ) {

				announcement( playerid, "~w~Nema vise novca u sefu!", 1000, 4) ;
				PljackaVreme[ playerid ] = 0;
				SendInfoMessage( playerid, "Opljackali ste banku i uzeli ste %d$!", PljackaNovac[ playerid ] );
				Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] );
				SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackani novac!" );
				VremeZaNovac[ playerid ] = 120;
				PostaviWanted( playerid, "Pljacka Banke", "Nepoznati", 6 );
				PljackaUToku = false;

				ServerInfo[ NovacBanka ] -= PljackaNovac[ playerid ];
				SaveServerStats( );
				
				new novacstring[ 256 ];
				format( novacstring, sizeof( novacstring ), ""col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Da opljackate banku kucajte\n"col_balkanstory"[ /postavidinamit /provalilozinku /pljackajbanku ]", ServerInfo[ NovacBanka ] );
				UpdateDynamic3DTextLabelText( ServerInfo[ NovacLabel ], BELA, novacstring );

				format( novacstring, sizeof( novacstring ), ""col_white"[ STANJE NOVCA ]\n"col_white"Trenutno u sefu ima "col_balkanstory"%d$\n"col_white"Maksimalno moze imati "col_balkanstory"1 000 000$\n"col_balkanstory"", ServerInfo[ NovacBanka ] );
				UpdateDynamic3DTextLabelText( ServerInfo[ NovacLabel2 ], BELA, novacstring );

				format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Komercijalna banka je opljackana i opljackano je %d$ novca.", PljackaNovac[ playerid ] );
				OOCNews( 0xFFA500AA, globalstring );
			}
		}
		else if( PljackaVreme[ playerid ] == 0 ) {
			format(string, sizeof( string ),"~w~Opljackali ste banku i uzeli ~g~%d$ !", PljackaNovac[ playerid ] );
			announcement( playerid, string, 6000, 4 );
			SendInfoMessage( playerid, "Opljackali ste banku i uzeli ste %d$!", PljackaNovac[ playerid ] );
			SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackani novac!" );
			Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] );
			PljackaVreme[ playerid ] = 0;
			VremeZaNovac[ playerid ] = 120;
			PostaviWanted( playerid, "Pljacka Banke", "Nepoznati", 6 );
			PljackaUToku = false;
			
			format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Komercijalna banka je opljackana i opljackano je %d$.", PljackaNovac[ playerid ] );
			OOCNews( 0xFFA500AA, globalstring );
		}
	}
	else {
		announcement( playerid, "~w~Otisli ste iz sefa!", 1000, 4) ;
		PljackaVreme[ playerid ] = 0;
		SendInfoMessage( playerid, "Opljackali ste banku i uzeli ste %d$!", PljackaNovac[ playerid ] );
		Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] );
		SendInfoMessage( playerid, "Morate ostati zivi jos 2 minuta da bi dobili opljackani novac!" );
		VremeZaNovac[ playerid ] = 120;
		PostaviWanted( playerid, "Pljacka Banke", "Nepoznati", 6 );
		PljackaUToku = false;
		
		format( globalstring, sizeof( globalstring ), "|| CNN News || "col_white"Upravo je izvrsena pljacka banke i ukradeno je %d$.", PljackaNovac[ playerid ] );
		OOCNews( 0xFFA500AA, globalstring );
	}
	return true;
}

forward hakedovanje( playerid );
public hakedovanje( playerid ) {
	if( IsPlayerInRangeOfPoint( playerid, 5, 1464.5373, -1005.3227, 2045.4697 ) ) {
	
		new rand = random( 50 );
		if( rand == 14 ) {
			SendInfoMessage( playerid, "Otkriveni ste u pokusaju upada u sistem!" );
			PostaviWanted( playerid, "Pokusaj pljacke banke", "Nepoznati", 3 );
			Dimi_KillTimer( HakovanjeTimer[ playerid ] );
			return true;
		}
	
		PokusajiHakedovanja[ playerid ]++;
		if( PokusajiHakedovanja[ playerid ] == 1 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21puojhb6pn321[j0d8asud-021nh31-sa-d-128hjn=a" );
		else if( PokusajiHakedovanja[ playerid ] == 2 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "p[i1j=2ijkdlasmj093_013km-=0uasj2=3imuidsja2es2" );
		else if( PokusajiHakedovanja[ playerid ] == 3 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[kmivjmb-k23bki23basdb74qa4d6541aba6569b4asd13b" );
		else if( PokusajiHakedovanja[ playerid ] == 4 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "adw2as5dw98e7471sd521sa6d52w87e9wq3dsae21xndrjs" );
		else if( PokusajiHakedovanja[ playerid ] == 5 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "xxxx____--------x!24414!@@SSSSSSSSSSSSSSAbvcasx" );
		else if( PokusajiHakedovanja[ playerid ] == 6 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21puosGGGGGGGSAZBSSAWQWWW_______@@@@!$$$$$$$S" );
		else if( PokusajiHakedovanja[ playerid ] == 7 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21mzxkcbnczxnbjzmxncbzxjczzzzzzzzzxc237df6665" );
		else if( PokusajiHakedovanja[ playerid ] == 8 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "dsss313sd23&**!@*&Y^!MKSJUAhnk1o3jki89jnnawjuhi" );
		else if( PokusajiHakedovanja[ playerid ] == 9 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21puojhb6pn321[j0d8asud-021nh31-sa-d-128hjn=a" );
		else if( PokusajiHakedovanja[ playerid ] == 10 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "p[i1j=2ijkdlasmj093_013km-=0uasj2=3imuidsja2es2" );
		else if( PokusajiHakedovanja[ playerid ] == 11 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[kmivjmb-k23bki23basdb74qa4d6541aba6569b4asd13b" );
		else if( PokusajiHakedovanja[ playerid ] == 12 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "xxxx____--------x!24414!@@SSSSSSSSSSSSSSAbvcasx" );
		else if( PokusajiHakedovanja[ playerid ] == 13 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21puosGGGGGGGSAZBSSAWQWWW_______@@@@!$$$$$$$S" );
		else if( PokusajiHakedovanja[ playerid ] == 14 ) HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 500, false, "d", playerid ), SendClientMessagee( playerid, -1, "[p21mzxkcbnczxnbjzmxncbzxjczzzzzzzzzxc237df6665" );
		else if( PokusajiHakedovanja[ playerid ] == 15 )
		{
			new string[ 32 ];
			new randnumber = 100000 + random(461) + random(789999);
			format( string, sizeof( string ), "sfd%db@f$", randnumber );
			strmid( LozinkaBanke, string, 0, strlen( string ), 32 );
			scmex( playerid, -1, "{0057AE}|| HACK || {FFFFFF}Uspjesno ste hakovali sifru: "SERVERBOJA_AQUA"%s", string );
			SendInfoMessage( playerid, "Za 30 sekuni ce se resetovati sifra, pozurite i unesite sifru!" );
			SendInfoMessage( playerid, "Da unesete lozinku koristite /unesilozinku [sifra]" );
			HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 30000, false, "d", playerid );
		}
		else if( PokusajiHakedovanja[ playerid ] == 16 )
		{
			new string[ 32 ];
			new randnumber = 100000 + random(461) + random(789999);
			format( string, sizeof( string ), "sfd%db@f$", randnumber );
			strmid( LozinkaBanke, string, 0, strlen( string ), 32 );
			PokusajiHakedovanja[ playerid ] = 0;
			SendInfoMessage( playerid, "Lozinka je resetovana i vas upad u sistem je blokiran!" );
			SendInfoMessage( playerid, "Laptop zapocinje novi upad." );
			HakovanjeTimer[ playerid ] = SetTimerEx( "hakedovanje", 1000, false, "d", playerid );
		}
	}
	else
	{
		SendInfoMessage( playerid, "Udaljili ste se od mjesta za upad u sistem i obustavljen je proces!" );

		PostaviWanted( playerid, "Pokusaj pljacke banke", "Nepoznati", 3 );

		Dimi_KillTimer( HakovanjeTimer[ playerid ] );
	}
	return true;
}

forward PukoDinamit( );
public PukoDinamit( ) {
	if( SekundDinamita == 0 ) {
		DestroyDynamicObject( DinamitObjekt );
		CreateExplosion( 1470.7386, -1015.8056, 2045.5791, 7, 4 );
		Delete3DTextLabel( Dinamit3D );
		SekundDinamita = 10;
		VrataBankeSrusena = true;
		DestroyDynamicObject( VrataSefaBanke );
		VrataSefaBanke = CreateDynamicObject(2634, 1470.7053, -1017.2322, 2044.7122, 97.0550, 0.0000, 0.0000);//srusena
		return true;
	}
	SekundDinamita--;
	SetTimer( "PukoDinamit", 1000, false );
	Delete3DTextLabel( Dinamit3D );
	new string[ 128 ];
	format( string, sizeof( string ), ""col_red"[ EKSPLOZIJA ]\n{ffffff}Pomjerite se od dinamita, eksplozija za:\n"col_red"%d sekundi...", SekundDinamita );
	Dinamit3D = Create3DTextLabel( string, BELA, 1470.7329, -1015.5365, 2046.0665, 30.0, -1, 0);
	return true;
}


/////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
forward GradjevinarRavna(playerid);
public GradjevinarRavna(playerid)
{

	if(GetVehicleModel( GetPlayerVehicleID(playerid) ) != 486 ) return 1;//bager
	if(sravnohrpica[playerid] == GRADJEVINARHRPICE)
	{
		Dimi_KillTimer(ravnjanjetimer[playerid]);
		sravnohrpica[playerid] = 0;
		Dimi_DisablePlayerCheckpoint( playerid );
		CheckpointStatus[ playerid ] = 0;
		new bonus = random(PosloviInfo[ BonusGradjevinarZemlja ]);
		new isplacen = PosloviInfo[ GradjevinarZemljaPlata ] + bonus;
		PlayerInfo[ playerid ][ xPlatniRacun ] += isplacen;
		SavePlayer( playerid ); UpdatePlataTD( playerid );
		//BussinesJobMoney( POSAO_GRADJEVINAR, (200/10) );//cora orao
		//SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
		ShowPlayerDialog(playerid, dialog_GRADJEVINARPOSAO2, DSMSG, ""col_white"Gradjevinar",""col_white"Da li zelite ponovo ravnati zemlju?\n","Da","Ne");
		SendJobMessage( playerid, "Zavrsio si sa ravnanjem terena, zaradio si "col_job"%d$ "col_white"koji su ti legli na platni racun.", isplacen);
		StaroVreme[ playerid ] = 0;
		NovoVreme[ playerid ] = 0;
		for(new t = 0; t < GRADJEVINARHRPICE; t++)//ovdje povecat broj kad doradimo objekte
		{
			DestroyDynamicObject(pijesakhrpa[playerid][t]);
		}

		return 1;
	}

	for(new t = 0; t < GRADJEVINARHRPICE; t++)//ovdje povecat broj kad doradimo objekte
	{
		new Float:x, Float:y, Float:z;
		GetDynamicObjectPos(pijesakhrpa[playerid][t], x, y, z);


		if(IsPlayerInRangeOfPoint(playerid,2.0,x,y,z) && z <= GRADJEVINARDOWNPOS)
		{
			DestroyDynamicObject(pijesakhrpa[playerid][t]);
			sravnohrpica[playerid] ++;
		}

		if(IsPlayerInRangeOfPoint(playerid,3.0,x,y,z) && z > GRADJEVINARDOWNPOS)
		{
			if(GetSpeed( playerid ) > 10)
			{
				MoveDynamicObject(pijesakhrpa[playerid][t],x,y,GRADJEVINARDOWNPOS,0.2);
			}
			else if(GetSpeed( playerid ) < 10)
			{
				StopDynamicObject(pijesakhrpa[playerid][t]);
			}
		}
		else
		{
			StopDynamicObject(pijesakhrpa[playerid][t]);
		}
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
forward istovarsnijega(playerid);
public istovarsnijega(playerid)
{
	Dimi_DisablePlayerCheckpoint( playerid );
	CheckpointStatus[ playerid ] = 0;
	PlayerInfo[ playerid ][ xPlatniRacun ] += cistacnovac[ playerid ];
	SavePlayer( playerid ); UpdatePlataTD( playerid );
	SendJobMessage( playerid, "Za ociscenih "col_white"%dkm "col_job"zaradili ste:"col_white" %d$",cistackilometri[ playerid ],cistacnovac[ playerid ] );
	//SetVehicleToRespawn( cistacvozilo[ playerid ] );
	BussinesJobMoney( POSAO_KOMUNALAC, cistacnovac[ playerid ]/10 );
	cistacvozilo[ playerid ] = -1;
	CistacPosao[ playerid ] = false;
	cistackilometri[ playerid ] = 0;
	cistacmetri[ playerid ] = 0;
	CistacWarning[ playerid ] = 0;
	cistacnovac[ playerid ] = 0;
	Dimi_KillTimer( CistacTimer[ playerid ] );
	Dimi_KillTimer( smecedoletimer[ playerid ] );
	CKilometriTDControl( playerid, false );
	TogglePlayerControllable( playerid, true );
	ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO3, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite ponovo cistiti snijeg sa ulica?\n","Da","Ne");
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
forward istovarcistilice(playerid);
public istovarcistilice(playerid)
{
	Dimi_DisablePlayerCheckpoint( playerid );
	CheckpointStatus[ playerid ] = 0;
	new bonus = random(PosloviInfo[ BonusCistacaUlica ]);
	new isplata = PosloviInfo[ CistacUlicePlata ] + bonus;
	new isplata2 = isplata*cistackilometri[ playerid ];
	PlayerInfo[ playerid ][ xPlatniRacun ] += isplata2;
	SavePlayer( playerid ); UpdatePlataTD( playerid );
	SendJobMessage( playerid, "Za ociscenih "col_white"%dkm "col_job"zaradili ste:"col_white" %d$",cistackilometri[ playerid ],isplata2 );
	//SetVehicleToRespawn( cistacvozilo[ playerid ] );
	BussinesJobMoney( POSAO_KOMUNALAC, 200/10 );
	cistacvozilo[ playerid ] = -1;
	CistacPosao[ playerid ] = false;
	cistackilometri[ playerid ] = 0;
	cistacmetri[ playerid ] = 0;
	CistacWarning[ playerid ] = 0;
	cistacnovac[ playerid ] = 0;
	Dimi_KillTimer( CistacTimer[ playerid ] );
	Dimi_KillTimer( smecedoletimer[ playerid ] );
	CKilometriTDControl( playerid, false );
	TogglePlayerControllable( playerid, true );
	ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO2, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite ponovo cistiti ulice?\n","Da","Ne");
	return 1;
}
forward preradamleka(playerid);
public preradamleka(playerid)
{

	farmerInfo[ playerid ][ fiHaveBucket ] = true;
	farmerInfo[ playerid ][ fiCowNumber ] = 9;
	SetPlayerAttachedObject(playerid, OBJECT_SLOT_RHAND, 19569, 1, 0.003000, 0.422999, 0.000999, 3.700000, 97.499969, 86.699958, 2.293999, 3.209000, 1.359000);
	TogglePlayerControllable( playerid, true );
	SendJobMessage(playerid,"Mlijeko je upakovano sada ga morate dostaviti mlijekari da se preradi!");
	SendJobMessage(playerid,"Ubacite vase mlijeko u jedno od praznih vozila i dostavite ga!");
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
forward smecedolee(playerid);
public smecedolee(playerid)
{
//dodat uslov ako je variabla manja od broja vreca smeca da ovo ponavlja u suprotnom ako je jednako da mu da platu

	if(isprazniovreca[playerid] > 0)
	{
		if(zasmeceobject1[playerid] == 1)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid],GetPlayerVehicleID(playerid), 0.075000,-3.900001,0.225000,-0.000001,0.000000,-86.399986);
			zasmeceobject1[playerid] =2;
			return 1;
		}
		if(zasmeceobject1[playerid] == 2)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid],GetPlayerVehicleID(playerid), 0.075000,-4.500000,0.225000,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =3;
			return 1;
		}
		if(zasmeceobject1[playerid] == 3)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid], GetPlayerVehicleID(playerid), 0.075000,-4.500000,0.000000,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =4;
			return 1;
		}
		if(zasmeceobject1[playerid] == 4)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid], GetPlayerVehicleID(playerid), 0.075000,-4.500000,-0.375000,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =5;
			return 1;
		}
		if(zasmeceobject1[playerid] == 5)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid], GetPlayerVehicleID(playerid), 0.075000,-4.500000,-0.749999,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =6;
			return 1;
		}
		if(zasmeceobject1[playerid] == 6)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid], GetPlayerVehicleID(playerid), 0.075000,-4.500000,-1.350000,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =7;
			return 1;
		}
		if(zasmeceobject1[playerid] == 7)
		{
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			AttachPlayerObjectToVehicle(playerid,smeceobject1[playerid], GetPlayerVehicleID(playerid), 0.075000,-4.500000,-2.000000,0.000000,2.699998,-86.399986);
			zasmeceobject1[playerid] =1;
			isprazniovreca[playerid] -=1;
			return 1;
		}

	}
	if(isprazniovreca[playerid] == 0)
	{
		if( garbagemanInfo[ playerid ][ gmiDuty ] == true )
		{
			Dimi_KillTimer( smecedoletimer[ playerid ] );
			RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
			DestroyPlayerObject(playerid,smeceobject1[playerid]);
			Dimi_DisablePlayerCheckpoint( playerid );
			CheckpointStatus[ playerid ] = 0;
			new bonus = random(PosloviInfo[ BonusDjubretara ]);
			new isplata = PosloviInfo[ DjubretarPlata ] + bonus;
			
			PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
			SavePlayer( playerid ); UpdatePlataTD( playerid );
			//BussinesJobMoney( POSAO_KOMUNALAC, 200/10  );
			SendJobMessage( playerid, "Ispraznili ste %d vreca smeca i zaradili "col_white"%d$",garbagemanVehicles[ GetPlayerVehicleID( playerid ) ][ gGarbages ], isplata );
			garbagemanVehicles[ GetPlayerVehicleID( playerid ) ][ gPlayerID ] = -1;
			garbagemanVehicles[ GetPlayerVehicleID( playerid ) ][ gGarbages ] = 0;
			garbagemanInfo[ playerid ][ gmiDuty ] = false;
			garbagemanInfo[ playerid ][ gmiReadyToDump ] = false;
			garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
			garbagemanInfo[ playerid ][ gmiJob ] = false;
			garbagemanInfo[ playerid ][ gmiContainerID ] = 0;
			garbagemanInfo[ playerid ][ gmiVehicleID ] = -1;
			AktivanKontejner[ playerid ] = -1;
			isprazniovreca[playerid] = 0;
			//SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
			ShowPlayerDialog(playerid, dialog_KOMUNALACPOSAO, DSMSG, ""col_white"Komunalac",""col_white"Da li zelite ponovo skupljati smece?\n","Da","Ne");
			TogglePlayerControllable( playerid, true );
		}
	}



	return 1;
}


forward RudnikLiftFalse( );
public RudnikLiftFalse( )
{
	RudnikLift = false;
	RudnikLiftuPokretu = false;
}



/////////////////////


public OnPlayerEnterCheckpoint( playerid ) {

	if( GetFactionType( playerid ) != ORG_TIP_PD ) {

		if( GetSpeed( playerid ) <= 0 && PlayerInfo[ playerid ][ xAdmin ] < 6 && PosaoRudar[ playerid ] == 0 ) {
			antiCheatCS[ playerid ][ CPPort ]++;
			if( antiCheatCS[ playerid ][ CPPort ] >= 2 ) {

				format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"col_white" Moguce portanje na checkpointima || "SERVERBOJA_AQUA"%s[ID: %d] "col_white"| Koristi /spec!!!", ImeIgraca( playerid ), playerid );
				AdminPoruka( ANTICHEAT, globalstring );
				return 1;
			}
		}
	
	}

	new velo = GetPlayerVehicleID( playerid );//mamara

	if(VoziSarajevoStanicu[playerid] == 1 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{

		new time = gettime( );
		new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
		if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
		{
			GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
			GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
			AdminPoruka( ANTICHEAT, globalstring );
			return 1;
		}
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 2;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,20);
	}
	else if(VoziSarajevoStanicu[playerid] == 2 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 3;
		Dimi_SetPlayerCheckpoint( playerid, 1398.6301,-2283.4348,13.3792, 3.0 );
		
	}
	else if(VoziSarajevoStanicu[playerid] == 3 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 4;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,21);
	}
	else if(VoziSarajevoStanicu[playerid] == 4 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 5;
		Dimi_SetPlayerCheckpoint( playerid, 1612.5609,-1368.7367,28.6391, 3.0 );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 40;
	}
	else if(VoziSarajevoStanicu[playerid] == 5 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{

		new time = gettime( );
		new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
		if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
		{
			GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
			GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
			AdminPoruka( ANTICHEAT, globalstring );
			return 1;
		}
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 6;
		Dimi_SetPlayerCheckpoint( playerid, 1641.2385,175.8407,33.5726, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 6 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 7;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,22);
	}
	else if(VoziSarajevoStanicu[playerid] == 7 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 8;
		Dimi_SetPlayerCheckpoint( playerid, 2075.1538,1159.4023,10.6719, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 8 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 9;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,23);
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 20;
		
	}

	else if(VoziSarajevoStanicu[playerid] == 9 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{

		new time = gettime( );
		new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
		if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
		{
			GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
			GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
			AdminPoruka( ANTICHEAT, globalstring );
			return 1;
		}
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 10;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,24);
	}
	else if(VoziSarajevoStanicu[playerid] == 10 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 11;
		Dimi_SetPlayerCheckpoint( playerid, 2149.2217,2353.1401,10.6719, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 11 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 12;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,25);
	}
	else if(VoziSarajevoStanicu[playerid] == 12 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 13;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,26);
	}
	else if(VoziSarajevoStanicu[playerid] == 13 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 14;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,27);
	}
	else if(VoziSarajevoStanicu[playerid] == 14 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 15;
		Dimi_SetPlayerCheckpoint( playerid, 1616.3000,182.8255,33.7600, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 15 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 16;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,28);
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 35;
		
	}
	else if(VoziSarajevoStanicu[playerid] == 16 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{

		new time = gettime( );
		new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
		if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
		{
			GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
			GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
			AdminPoruka( ANTICHEAT, globalstring );
			return 1;
		}
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 17;
		Dimi_SetPlayerCheckpoint( playerid, 1629.7318,-2057.2405,21.0050, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 17 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 18;
		Dimi_SetPlayerCheckpoint( playerid, 1284.4724,-2263.5178,13.7249, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 18 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 19;
		Dimi_SetPlayerCheckpoint( playerid, 1925.5221,-2168.5381,13.3828, 3.0 );
	}
	else if(VoziSarajevoStanicu[playerid] == 19 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 20;
		Dimi_SetPlayerCheckpoint( playerid, 1824.7725,-1905.7489,13.3625, 3.0 );
		StaroVreme[ playerid ] = gettime();
		NovoVreme[ playerid ] = 15;
	}
	else if(VoziSarajevoStanicu[playerid] == 20 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		new time = gettime( );
		new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
		if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
		{
			GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
			GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
			format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
			AdminPoruka( ANTICHEAT, globalstring );
			return 1;
		}
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		VoziSarajevoStanicu[playerid] = 21;
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",2000,false,"di",playerid,29);
	}









	////////////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 1 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid),2022.2390, -1940.3439, 13.3392);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), -90);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor3[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,1);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 2 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431)
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid),2115.7620, -1495.3179, 23.7852);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 0);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,2);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 3 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 2074.7952, -1246.3740, 23.7958);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 0);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,3);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 4 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1686.2146, -1157.7994, 23.6432);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 90);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor3[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,4);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 5 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER  && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1419.5568, -1030.7904, 23.5964);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 90);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,5);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 6 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1131.9955, -942.2639, 42.6853);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 92.6558);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,6);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 7 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1050.9318, -1342.3832, 13.3641);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 180);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor3[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,7);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 8 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1294.4772, -1599.8816, 13.3569);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 180);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,8);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 9 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1389.7153, -1875.1062, 13.3632);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), -90);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		ApplyActorAnimation(BusActor2[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,9);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 10 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1640.1517, -1875.2441, 13.3647);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), -90);
		ApplyActorAnimation(BusActor1[playerid], "PED","WALK_gang2",4.1,0,0,0,0,0);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",1000,false,"di",playerid,10);
	}
	//////////////////////////////////////////////////////////////////////////////////
	if(VoziBeogradStanicu[playerid] == 11 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PosaoVozila[ velo ] == POSAO_BUSVOZAC && GetVehicleModel( velo ) == 431 )
	{
		if(IDIgracaKojiVoziBus[ velo ] != playerid) return GRESKA( playerid, "Ovo nije autobus sa kojim ste zapoceli posao!" );
		DisablePlayerCheckpoint(playerid);
		SetVehiclePos(GetPlayerVehicleID(playerid), 1818.7383, -1873.6160, 13.3619);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 180);
		DestroyActor(BusActor1[playerid]);
		BusActor1[playerid] = CreateActor(79,1816.2534, -1874.1019, 13.5834, -90);
		BusActor2[playerid] = CreateActor(59,1816.3088, -1875.1788, 13.5834, -90);
		BusActor3[playerid] = CreateActor(55,1816.8732, -1873.4846, 13.4424,-108.0000);
		BusActor4[playerid] = CreateActor(46,1816.8350, -1874.4065, 13.4424,-90);
		BusActor5[playerid] = CreateActor(28,1817.0443, -1875.1472, 13.4424,-82);
		SetActorFacingAngle(BusActor1[playerid], 90.00000);
		SetActorFacingAngle(BusActor2[playerid], 90.00000);
		SetActorFacingAngle(BusActor3[playerid], 108.00000);
		SetActorFacingAngle(BusActor4[playerid], 90.00000);
		SetActorFacingAngle(BusActor5[playerid], 82.00000);
		TogglePlayerControllable(playerid,0);
		SetTimerEx("ulazeputnici",500,false,"di",playerid,11);
	}
	//////////////////////////////////////////////////////////////////////////////////





	if( CheckpointStatus[ playerid ] != 0 ) {//ocitavanje Checkpointa
		switch( CheckpointStatus[ playerid ] ) {
			case 1:
			{
				PlayerPlaySound( playerid, 1058, 0.0, 0.0, 0.0);
				Dimi_DisablePlayerCheckpoint( playerid );
				SetPVarInt( playerid, "LocatingCar", 0);
				CheckpointStatus[ playerid ] = 0;
				announcement( playerid, "~r~gps ugasen", 5000, 1);
			}
			case 2:
			{
				PlayerPlaySound( playerid, 1058, 0.0, 0.0, 0.0);
				Dimi_DisablePlayerCheckpoint( playerid );
				SetPVarInt( playerid, "LocatingPark", 0);
				CheckpointStatus[ playerid ] = 0;
				announcement( playerid, "~r~gps ugasen", 5000, 1);
			}
			case 3:
			{
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 578 && WOOD[ GetPlayerVehicleID( playerid ) ] == true )
				{
					new Float:rot;
					GetVehicleZAngle( GetPlayerVehicleID( playerid ), rot );
					if( rot > 200 && rot < 250 )
					{
						new time = gettime( );
						new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
						if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
						{
							GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
							GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
							AdminPoruka( ANTICHEAT, globalstring );
							return 1;
						}
					
						Dimi_DisablePlayerCheckpoint( playerid );
						announcement( playerid, "~w~Pricekajte drvece se istovaruje..", 5000, 1);
						TogglePlayerControllable( playerid, false );
						CheckpointStatus[ playerid ] = 0;
						//DestroyDynamicObject( WOODObject[ GetPlayerVehicleID( playerid ) ] );
						//WOODObject[ GetPlayerVehicleID( playerid ) ] = CreateDynamicObject( 18609, -1966.6454, -2436.1814, 32.0000, 0, 0, 50.0000 );
						//MoveDynamicObject( WOODObject[ GetPlayerVehicleID( playerid ) ], -1972.1990, -2430.8147, 32.0000, 2.00 );
						SetTimerEx( "Istovar", 5000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 1 );
					}
				}
			}
			case 4: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 455 && sljunak[ GetPlayerVehicleID( playerid ) ] == true ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}
						
					Dimi_DisablePlayerCheckpoint( playerid );
					announcement( playerid, "~w~Pricekajte sljunak se istovaruje..", 5000, 1);
					TogglePlayerControllable( playerid, false );
					CheckpointStatus[ playerid ] = 0;
					SetTimerEx( "Istovar", 5000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 2 );
				}
			}
			case 5:
			{
				
				if( DeliverLevel[ playerid ] == 2 )
				{

					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
					{

						GRESKA( playerid, "Dosli ste na odrediste prije nego sto je odredjeno!" );
						GRESKA( playerid, "Sacekajte jos %d sekundi i prodjite ponovo kroz checkpoint.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je dosao do Tempo Skladista"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}


					if( CarriesBox[ playerid ] == 1 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CarriesBox[ playerid ] = 0;
						RemovePlayerAttachedObject(playerid, OBJECT_SLOT_BADGE);
						SetPlayerSpecialAction( playerid, 0 );
						SendJobMessage( playerid, "Ubacili ste paket robe u skladiste Tempo Marketa!");
						
						TrafikaTrenutna[ playerid ]++;
						if( (TrafikaTrenutna[ playerid ] - TrafikaPrva[ playerid ]) == AKTIV_TEMPOKUTIJE )
						{
						
							DeliverLevel[ playerid ] = 3;
							SendJobMessage( playerid, "Ubacili ste %d paketa robe u skladiste Tempo Marketa!",AKTIV_TEMPOKUTIJE);
							SendJobMessage( playerid, "Sjedite u vas kombi i odvezite ga do markera!",AKTIV_TEMPOKUTIJE);
							Dimi_SetPlayerCheckpoint( playerid, 1092.6167,-1339.5862,12.8617, 4.0 );
							CheckpointStatus[ playerid ] = 6;
							return 1;
						}
						SendJobMessage( playerid, "Nastavite sa ubacivanjem paketa u skladiste!");
						Dimi_SetPlayerCheckpoint( playerid, 1128.5640,-1322.0059,12.8617, 2.0 );
						CheckpointStatus[ playerid ] = 5;
					}
				}
				if(TempoDostavaFabrikaCP[ playerid ] == 1)
				{
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
					{

						GRESKA( playerid, "Dosli ste na checkpoint prije odredjenog vremena!. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i prodjite ponovo kroz checkpoint.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je dosao na CP prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}
					Dimi_DisablePlayerCheckpoint( playerid );
					TempoDostavaFabrikaCP[ playerid ] = 0;
					SendJobMessage( playerid, "Rubu uzimate komandom /uzmikutiju te je ubacujete u kamion tipkom Y !");
				}
			}
			case 6:
			{
			
				if( DeliverLevel[playerid] == 3 )
				{
				
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
					{
					
						GRESKA( playerid, "Zavrsili ste posao ranije nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i prodjite ponovo kroz objekt.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je zavrsio posao prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					DeliverLevel[ playerid ] = 0;
					TrafikaTrenutna[ playerid ] = 0;
					TrafikaPrva[ playerid ] = 0;
					CarriesBox[ playerid ] = 0;
					SetVehicleToRespawn( DeliverCar[ playerid ] );
					StateBox[ DeliverCar[ playerid ] ] = 0;
					KamionUsed[ DeliverCar[ playerid ] ] = -1;
					DeliverCar[ playerid ] = -1;
					KamionUsed[ playerid ] = -1; 
					
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;
					SendJobMessage( playerid, "Uspjesno ste zavrsili posao!");
					
					new bonus = random( PosloviInfo[ BonusTempo ] );
					new isplata = PosloviInfo[ PlataTempo ] + bonus;

					format( globalstring, sizeof( globalstring ), ""col_job"Uspjesno ste zavrsili dostavljanje!\n\n"col_white"Plata: "col_job"%d$", isplata );
					ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, globalstring, "Ok", "" );

					PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
					SavePlayer( playerid );
					UpdatePlataTD( playerid );



					BussinesJobMoney( POSAO_TEMPODOSTAVA, (200/10) );
				}
			}
			case 7: {
				// edit
			}
			case 8: {
				// edit
			}
			case 9:
			{
				if( IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 408 && garbagemanInfo[ playerid ][ gmiJob ] == true )
				{
					if( garbagemanInfo[ playerid ][ gmiReadyToDump ] == true )
					{
					
						Dimi_DisablePlayerCheckpoint( playerid );
						garbagemanInfo[ playerid ][ gmiDuty ] = true;
						CheckpointStatus[ playerid ] = 0;
						SendJobMessage( playerid, "Da ispraznite kamion kucajte /ispraznikamion!");

					}

				}
			}
			case 10: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 524 && PlayerInfo[ playerid ][ xPosao ] == POSAO_GRADJEVINAR ) {

					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					announcement( playerid, "~w~Pricekajte beton se utovara", 5000, 1);
					TogglePlayerControllable( playerid, false );
					SetTimerEx( "Utovar", 5000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 4 );
					CheckpointStatus[ playerid ] = 0;
					Dimi_DisablePlayerCheckpoint( playerid );
				}
			}
			case 11:
			{
			
				if( IsPlayerInAnyVehicle( playerid ) )
				{
				
					if( VrstaIlegala[ playerid ] == 1 )
					{
						if( PlayerInfo[ playerid ][ xNovac ] < KolicinaIlegala[ playerid ]*2) return GRESKA( playerid, "Nemate dovoljno novca!Jedan gram kosta 2$");
						DajIgracuNovac( playerid, -KolicinaIlegala[ playerid ]*2) ;
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						PlayerInfo[ playerid ][ xOpium ] += KolicinaIlegala[ playerid ];
						SendClientMessageEx( playerid, UGBOJA, "Pokupio si %d grama opiuma.", KolicinaIlegala[ playerid ] );
						KolicinaIlegala[ playerid ] = 0; VrstaIlegala[ playerid ] = 0;
					}
					else if( VrstaIlegala[ playerid ] == 2 )
					{
					
						if( PlayerInfo[ playerid ][ xNovac ] < KolicinaIlegala[ playerid ]*3) return GRESKA( playerid, "Nemate dovoljno novca!Jedan gram kosta 3$");
						DajIgracuNovac( playerid, -KolicinaIlegala[ playerid ]*3) ;
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						PlayerInfo[ playerid ][ xMetilAmin ] += KolicinaIlegala[ playerid ];
						SendClientMessageEx( playerid, UGBOJA, "Pokupio si %d grama Methylamina.", KolicinaIlegala[ playerid ] );
						KolicinaIlegala[ playerid ] = 0; VrstaIlegala[ playerid ] = 0;
					}
					else
					{
						GRESKA( playerid, "Nisi narucio robu. ");
						return 1;
					}
				}
				else
				{
					SendClientMessagee( playerid, CRVENA, "Moras biti u autu. ");
					return 1;
				}
			}
			case 12:
			{
			
				Dimi_DisablePlayerCheckpoint( playerid );
				SendClientMessagee( playerid, ZUTA, "Kada klijent sedne u vozilo ukucajte '/taxi ponudivoznju' da mu ponudite voznju.");
				CheckpointStatus[ playerid ] = 0;
			}
			case 13:
			{
				if( Polaganje[ playerid ] >= 1 && TipVozila[ GetPlayerVehicleID( playerid ) ] == POLAGANJE_VOZILO && GetPlayerState( playerid ) == 2 )
				{
					Dimi_DisablePlayerCheckpoint( playerid );
					switch( Polaganje[ playerid ] )
					{
						case 1:
						{
							Polaganje[ playerid ] = 2;
							Dimi_SetPlayerCheckpoint( playerid, 2101.0637,-1731.4563,13.3945, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 2:
						{
							Polaganje[ playerid ] = 3;
							Dimi_SetPlayerCheckpoint( playerid, 2010.7570,-1809.5197,13.0883, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 3:
						{
							Polaganje[ playerid ] = 4;
							Dimi_SetPlayerCheckpoint( playerid, 2115.3909,-1474.8832,23.8139, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 4:
						{
							Polaganje[ playerid ] = 5;
							Dimi_SetPlayerCheckpoint( playerid, 1865.2924,-1459.8168,13.3828, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 5:
						{
							Polaganje[ playerid ] = 6;
							Dimi_SetPlayerCheckpoint( playerid, 1818.9824,-1607.3741,13.3784, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 6:
						{
							Polaganje[ playerid ] = 17;
							Dimi_SetPlayerCheckpoint( playerid, 1939.3354,-1620.3693,13.3906, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 17:
						{
							Polaganje[ playerid ] = 18;
							Dimi_SetPlayerCheckpoint( playerid, 1939.9143,-1739.2455,13.3828, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 18:
						{
							Polaganje[ playerid ] = 19;
							Dimi_SetPlayerCheckpoint( playerid, 1958.7872,-1919.6593,13.3828, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 19:
						{
							Polaganje[ playerid ] = 20;
							Dimi_SetPlayerCheckpoint( playerid, 2054.6221,-1934.9481,13.3268, 5.0 );
							SendInfoMessage( playerid, "Nastavite dalje sa voznjom!" );
						}
						case 20:
						{
							Polaganje[ playerid ] = 21;
							Dimi_SetPlayerCheckpoint( playerid, 2084.1482,-1876.6210,13.3264, 5.0 );
							SendInfoMessage( playerid, "Zavrsili ste sa voznjom vratite sad vozilo u auto skolu!" );
						}
						case 21:
						{
							Polaganje[ playerid ] = 0;
							SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
							new Float:HP; GetVehicleHealth( GetPlayerVehicleID( playerid ), HP );
							if( HP < 950.0 )
							{
								SendInfoMessage( playerid, "Mnogo ste ostetili vozilo i pali ste na polaganju!" );
								return 1;
							}
							PlayerInfo[ playerid ][ xVozacka ] = 1;
							SavePlayer( playerid );
							SendInfoMessage( playerid, "Uspjesno ste zavrsili polaganje B kategorije!" );
						}
					}
				}
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////
			case 14:
			{

				if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 431 && GetPlayerState( playerid ) == 2 )
				{


				}
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////
			case 15:
			{
				Dimi_DisablePlayerCheckpoint( playerid );
				SendInfoMessage( playerid, "Stigli ste na lokaciju!");
				CheckpointStatus[ playerid ] = 0;
			}
			case 16:
			{

				if(farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 4)
				{
					if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 422 )
					{
						if( farmerVehicles[ GetPlayerVehicleID( playerid ) ][ fvMilk ] == true )
						{

							new time = gettime( );
							new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
							if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
							{
								GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
								GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
								format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
								AdminPoruka( ANTICHEAT, globalstring );
								return 1;
							}

							SendJobMessage( playerid, "Stigao si na lokaciju, izadji i izvadi iz kamioneta voce." );
							SendJobMessage( playerid, "Voce iz kamioneta vadite na 'LMB'." );
						}
					}
				}

				if( farmerInfo[ playerid ][ fiHaveBucket ] )
				{
					if( farmerInfo[ playerid ][ fiCowNumber ] < 9 )
					{
						new id = farmerInfo[ playerid ][ fiCowNumber ];
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						farmerInfo[ playerid ][ fiBucketObject ] = CreatePlayerObject( playerid, 19468, milkInfo[ id ][ obPos ][ 0 ], milkInfo[ id ][ obPos ][ 1 ], milkInfo[ id ][ obPos ][ 2 ], 0.0, 0.0, 0.0 );
						SetTimerEx( "FarmerCows", 5000, false, "di", playerid, (id+1) );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiCowNumber ] == 25 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						farmerInfo[ playerid ][ fiCowNumber ] = 26;
						SendJobMessage( playerid, "Sada ubacite vasu kantu mlijeka kojeg ste pomuzli da se upakuje!" );
						
					}
					else if( farmerInfo[ playerid ][ fiCowNumber ] == 9 )
					{
						SendJobMessage( playerid, "Zavrsili ste sa kravama, odnesite mlijeko u kamionet." );
						SendJobMessage( playerid, "Mlijeko u kamionet ubacujete 'LIJEVIM KLIKOM MISA'." );
					}
				}
				/////////////////////////////////////////////////////////////////
				if( !farmerInfo[ playerid ][ fiHaveFruits ] )
				{
					if( farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 1 )
					{

						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						SendJobMessage(playerid, "Sada uzmite voce koje cete dostaviti /uzmivoce");
						farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 2;

					}

				}
				/////////////////////////////////////////////////////////////////
				if( farmerInfo[ playerid ][ fiHaveGajbica ] )//edo majkara
				{
					if( farmerInfo[ playerid ][ fiFruitNumber ] == 1 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 1 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 2 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 2 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 3 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 3 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 4 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 4 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 5 )//ostavlja jabuke
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19639, 1, 0.017999, 0.470999, 0.029999, -0.900001, 95.499961, -86.599990);
						ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
						SendJobMessage( playerid, "Ostavili ste jabuke, sada idi oberi kruske!" );
						///
						Dimi_SetPlayerCheckpoint( playerid, -1068.7754,-1270.9158,132.7849, 1.0 );//prva kruska
						farmerInfo[ playerid ][ fiFruitNumber ] = 6;
						CheckpointStatus[ playerid ] = 16;
					}
					//----------------------------------------------------------
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 6 )//bere prvu krusku
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 5 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 7 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 6 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 8 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 7 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 9 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 8 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					//------------------------------------------------------------
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 10 )//ostavlja kruske
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 19639, 1, 0.017999, 0.470999, 0.029999, -0.900001, 95.499961, -86.599990);
						ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
						SendJobMessage( playerid, "Ostavili ste kruske, sada idi oberi sljive!" );
						///
						Dimi_SetPlayerCheckpoint( playerid, -1069.4270,-1282.4227,131.8473, 1.0 );//prva sljiva
						farmerInfo[ playerid ][ fiFruitNumber ] = 11;
						CheckpointStatus[ playerid ] = 16;
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 11 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 9 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 12 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 10 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 13 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 11 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 14 )
					{
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						TogglePlayerControllable( playerid, false );
						SetTimerEx( "FarmerFruits", 5000, false, "di", playerid, 12 );
						ApplyAnimation( playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 0, 0 );
					}
					else if( farmerInfo[ playerid ][ fiFruitNumber ] == 15 )//ostavlja sljive
					{
						new plata = random(200)+1000;
						PlayerInfo[ playerid ][ xPlatniRacun ] += plata;
						UpdatePlataTD( playerid );
						Dimi_DisablePlayerCheckpoint( playerid );
						CheckpointStatus[ playerid ] = 0;
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						SendJobMessage( playerid, "Ostavili ste sljive i obrali ste svo voce!" );
						SendJobMessage( playerid, "Uspjesno ste zavrsili posao i zaradili %d$!",plata );
						farmerInfo[ playerid ][ fiFruitNumber ] = 0;
						farmerInfo[ playerid ][ fiHaveGajbica ] = false;
					}

				}
				/////////////////////////////////////////////////////////////////
				
				
				
			}
			case 17:
			{
			
				if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 422 )
				{
					if( farmerVehicles[ GetPlayerVehicleID( playerid ) ][ fvMilk ] == true )
					{
	
						new time = gettime( );
						new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
						if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
						{
							GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
							GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
							AdminPoruka( ANTICHEAT, globalstring );
							return 1;
						}

						SendJobMessage( playerid, "Stigao si na lokaciju, izadji i izvadi iz kamioneta mlijeko." );
						SendJobMessage( playerid, "Mlijeko iz kamioneta vadite 'LIJEVIM KLIKOM MISA'." );
					}
				}
			}
			case 18: {
				if( GetFactionType( playerid ) == ORG_TIP_ELEK && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 552 && ElectricOprema[ playerid ] && IsPlayerInAnyVehicle( playerid ) ) {
					Dimi_DisablePlayerCheckpoint( playerid );
					electricNACP[ playerid ] = true;
					SendJobMessage( playerid, "Stigao si na lokaciju, izadji, popni se na banderu i popravi kvar." );
					SendJobMessage( playerid, "Koristi komandu - "col_white"/electric popravi." );
				}
			}
			case 19: {
				if( !IsPlayerInAnyVehicle( playerid ) && ElectricPosao[ playerid ] == 2 && GetFactionType( playerid ) == ORG_TIP_ELEK && ElectricOprema[ playerid ] ) {
					Dimi_DisablePlayerCheckpoint( playerid );
					BrojilaKuca[ playerid ]++;
					SendJobMessage( playerid, "Poceli se sa ocitavanjem brojila, pricekajte "col_white"5s." );
					ApplyAnimation( playerid, "SPRAYCAN", "spraycan_full", 4.0, 0, 0, 0, 5000, 0 );
					SetTimerEx( "BrojiloGotovo", 5000, false, "d", playerid );
				}
			}
			case 20: {
				if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PILOT && ( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 519 || GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 511 )  ) {
					if( LetSF[ playerid ] == 1 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, 1850.6820,-2494.7190,13.5547 ) ) {
							TogglePlayerControllable( playerid, false );
							announcement( playerid, "~w~sacekajte, putnici se ukrcavaju...", 5000, 5);
							PilotTimer[ playerid ] = SetTimerEx( "PilotUtovar", 5000, false, "d", playerid );
							Dimi_SetPlayerCheckpoint( playerid, -1506.8629, -14.1312, 14.1409, 5.0 );
							LetSF[ playerid ] = 2;
							StaroVreme[ playerid ] = gettime();
							NovoVreme[ playerid ] = 90;
						}
					}
					else if( LetSF[ playerid ] == 2 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, -1506.8629, -14.1312, 14.1409 ) ) {
						
							new time = gettime( );
							new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
							if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
								GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
								GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
								format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
								AdminPoruka( ANTICHEAT, globalstring );
								return 1;
							}
						
							TogglePlayerControllable( playerid, false );
							announcement( playerid, "~w~sacekajte, putnici se iskrcavaju...", 5000, 5);
							PilotTimer[ playerid ] = SetTimerEx( "PilotUtovar", 5000, false, "d", playerid );
							Dimi_SetPlayerCheckpoint( playerid, 1879.6438, -2493.6636, 13.5547, 5.0 );
							LetSF[ playerid ] = 3;
							StaroVreme[ playerid ] = gettime();
							NovoVreme[ playerid ] = 75;
						}
					}
					else if( LetSF[ playerid ] == 3 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, 1879.6438, -2493.6636, 13.5547 ) ) {
						
							new time = gettime( );
							new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
							if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
								GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
								GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
								format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
								AdminPoruka( ANTICHEAT, globalstring );
								return 1;
							}
						
							CheckpointStatus[ playerid ] = 0;
							TogglePlayerControllable( playerid, false );
							SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
							new bonus = random(PosloviInfo[ BonusPilotZG ]);
							new isplata = PosloviInfo[ PilotZGPlata ] + bonus;
							PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
							SavePlayer( playerid ); UpdatePlataTD( playerid );
							BussinesJobMoney( POSAO_PILOT, (200/10) );
							SendJobMessage( playerid, "Let je zavrsen i zaradili ste "col_white"%d$",isplata );
							ShowPlayerDialog( playerid, dialog_PILOT, DSL, D_NASLOV, ""col_balkanstory"(1). "col_white"Let BG - ZG\n"col_balkanstory"(2). "col_white"Let BG - SA", D_ODABERI, D_ODUSTANI );
							LetSF[ playerid ] = 0;
							DisablePlayerCheckpoint( playerid );
						}
					}
				}
			}
			case 21: {
				if( PlayerInfo[ playerid ][ xPosao ] == POSAO_PILOT && ( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 519 || GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 511 )  ) {
					if( LetLV[ playerid ] == 1 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, 1850.6820,-2494.7190,13.5547 ) ) {
							TogglePlayerControllable( playerid, false );
							announcement( playerid, "~w~sacekajte, putnici se ukrcavaju...", 5000, 5);
							PilotTimer[ playerid ] = SetTimerEx( "PilotUtovar", 5000, false, "d", playerid );
							Dimi_SetPlayerCheckpoint( playerid, 1477.5233, 1395.1841, 10.8203, 5.0 );
							LetLV[ playerid ] = 2;
							StaroVreme[ playerid ] = gettime();
							NovoVreme[ playerid ] = 90;
						}
					}
					else if( LetLV[ playerid ] == 2 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, 1477.5233, 1395.1841, 10.8203 ) ) {
						
							new time = gettime( );
							new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
							if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
								GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
								GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
								format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
								AdminPoruka( ANTICHEAT, globalstring );
								return 1;
							}
						
							TogglePlayerControllable( playerid, false );
							announcement( playerid, "~w~sacekajte, putnici se iskrcavaju...", 5000, 5);
							PilotTimer[ playerid ] = SetTimerEx( "PilotUtovar", 5000, false, "d", playerid );
							Dimi_SetPlayerCheckpoint( playerid, 1879.6438, -2493.6636, 13.5547, 5.0 );
							LetLV[ playerid ] = 3;
							StaroVreme[ playerid ] = gettime();
							NovoVreme[ playerid ] = 75;
						}
					}
					else if( LetLV[ playerid ] == 3 && GetPlayerState( playerid ) == PLAYER_STATE_DRIVER ) {
						if( IsPlayerInRangeOfPoint( playerid, 5.0, 1879.6438, -2493.6636, 13.5547 ) ) {
						
							new time = gettime( );
							new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
							if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
								GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
								GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
								format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
								AdminPoruka( ANTICHEAT, globalstring );
								return 1;
							}
						
							CheckpointStatus[ playerid ] = 0;
							TogglePlayerControllable( playerid, false );
							SetTimerEx( "SlobodnoSada", 2000, false, "i", playerid );
							new bonus = random(PosloviInfo[ BonusPilotSA ]);
							new isplata = PosloviInfo[ PilotSAPlata ] + bonus;
							PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
							SavePlayer( playerid ); UpdatePlataTD( playerid );
							BussinesJobMoney( POSAO_PILOT, (200/10) );
							SendJobMessage( playerid, "Let je zavrsen i zaradili ste "col_white"%d$",isplata );
							ShowPlayerDialog( playerid, dialog_PILOT, DSL, D_NASLOV, ""col_balkanstory"(1). "col_white"Let BG - ZG\n"col_balkanstory"(2). "col_white"Let BG - SA", D_ODABERI, D_ODUSTANI );
							LetLV[ playerid ] = 0;
							DisablePlayerCheckpoint( playerid );
						}
					}
				}
			}
			case 22:
			{
				Dimi_DisablePlayerCheckpoint( playerid );
				SendJobMessage( playerid, "Stanite blizu kontejnera i uzmite smece "col_white"'LMB'." );//CheckpointStatus[ playerid ] == 22
				CheckpointStatus[ playerid ] = 0;
			}
			case 23: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 524 && VehCement[ GetPlayerVehicleID( playerid ) ] == true ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}
					new Float:z_rot;
					GetVehicleZAngle(GetPlayerVehicleID(playerid), z_rot);
					if(z_rot < 249.6655 || z_rot > 291.7383) return GRESKA(playerid,"Kamion morate okrenuti zadnjim dijelom da bi istovarili beton!");

					Dimi_DisablePlayerCheckpoint( playerid );
					announcement( playerid, "~w~Istovar betona", 5000, 1);
					TogglePlayerControllable( playerid, false );
					
					betonobject1[playerid] = CreatePlayerObject(playerid,18672,0,0,-1000,0,0,0,100);
					AttachPlayerObjectToVehicle(playerid,betonobject1[playerid], GetPlayerVehicleID(playerid), 0.074999,-4.350000,-0.899999,0.000000,0.000000,-179.099899);
					betonobject2[playerid] = CreatePlayerObject(playerid,3048, 2429.9795, 1932.6199, 4.0410,   0.00000, 0.00000, 0.00000);
					MovePlayerObject(playerid,betonobject2[playerid],2429.8755, 1932.7239, 5.0810,0.2);
					CheckpointStatus[ playerid ] = 0;
					SetTimerEx( "Istovar", 7000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 7 );
				}
			}
			case 24: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 524 && VehCement[ GetPlayerVehicleID( playerid ) ] == true ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					DestroyPlayerObject(playerid,betonobject2[playerid]);
					CheckpointStatus[ playerid ] = 0;
					VehCement[ GetPlayerVehicleID( playerid ) ] = false;
					PlayerCement[ playerid ] = -1;
					
					new bonus = random(PosloviInfo[ BonusGradjevinarBeton ]);
					new isplacen = PosloviInfo[ GradjevinarBetonPlata ] + bonus;
					PlayerInfo[ playerid ][ xPlatniRacun ] += isplacen;//cora orao
					SavePlayer( playerid );
					UpdatePlataTD( playerid );
					BussinesJobMoney( POSAO_GRADJEVINAR, (200/10) );
					//SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					ShowPlayerDialog(playerid, dialog_GRADJEVINARPOSAO, DSMSG, ""col_white"Gradjevinar",""col_white"Da li zelite ponovo prevoziti beton?\n","Da","Ne");
					SendJobMessage( playerid, "Prevoz betona je zavrsen, zaradio si "col_white"%d$ "col_job"koji su ti legli na platni racun.", isplacen );
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;
				}
			}
			case 25:
			{//izbaceno od gradjevinara

			}
			case 26:
			{
				if( PlayerInfo[ playerid ][ xPosao ] == POSAO_FARMER && farmerInfo[ playerid ][ fiCowNumber ] == 17 && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 422 )
				{

					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
					{
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					CheckpointStatus[ playerid ] = 0;
					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					new bonus = random(PosloviInfo[ BonusMlijeko ]);
					new isplata = PosloviInfo[ FarmerMlijekoPlata ] + bonus;
					PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
					SendJobMessage( playerid, "Zavrsili ste sa poslom i zaradili "col_white"%d$.", isplata );
					BussinesJobMoney( POSAO_FARMER, 200/10 );
					SavePlayer( playerid ); UpdatePlataTD( playerid );
					farmerInfo[ playerid ][ fiCowNumber ] = 0;
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;
				}
				
				else if( PlayerInfo[ playerid ][ xPosao ] == POSAO_FARMER && farmerInfo[ playerid ][ fiFruitDeliveryNumber ] == 6 && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 422 )
				{

					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] )
					{
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					CheckpointStatus[ playerid ] = 0;
					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					new bonus = random(PosloviInfo[ BonusBerac ]);
					new isplata = PosloviInfo[ FarmerBeracPlata ] + bonus;
					PlayerInfo[ playerid ][ xPlatniRacun ] += isplata;
					SendJobMessage( playerid, "Zavrsili ste sa dostavom i zaradili "col_white"%d$.", isplata );
					BussinesJobMoney( POSAO_FARMER, 200/10 );
					SavePlayer( playerid ); UpdatePlataTD( playerid );
					farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 0;
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;
				}
				
				
			}
			case 27://edoo
			{
				if( PlayerInfo[ playerid ][ xPosao ] == POSAO_KOMUNALAC && CistacPosao[ playerid ] == true ) {

					#if NERP_ZIMSKI_MOD  == 1
					if( TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO &&
						GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 455 &&
						PosaoVozila[ GetPlayerVehicleID( playerid ) ] == POSAO_KOMUNALAC ) { }
					else return 1;
					#else
					if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 574 ) { }
					else return 1;
					#endif

					smecedoletimer[playerid] = SetTimerEx("istovarcistilice", 6000, false, "i", playerid);
					announcement(playerid,"~w~Istovar smeca....",5000,1);
					TogglePlayerControllable(playerid,false);
					Dimi_DisablePlayerCheckpoint( playerid );
					CheckpointStatus[ playerid ] = 0;
					Dimi_KillTimer( CistacTimer[ playerid ] );
					CKilometriTDControl( playerid, false );
					DestroyDynamicObject(cistacvodica[0][playerid]);
					DestroyDynamicObject(cistacvodica[1][playerid]);

				}
			}
			case 28: {
			}
			case 29: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 578 ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					CheckpointStatus[ playerid ] = 0;
					new bonus = random(200);
					PlayerInfo[ playerid ][ xPlatniRacun ] += (2800+bonus);
					SavePlayer( playerid ); UpdatePlataTD( playerid );
					BussinesJobMoney( POSAO_PREVOZNIK, ((2800+bonus)/10) );
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;
					ServerInfo[ Drva ] += 10;
					SaveServerStats( );

					SendJobMessage( playerid, "Zavrsio si prevoz drveca, zaradio si "col_white"%d$ "col_job"koji su ti legli na platni racun.", (2800+bonus) );
				}
			}
			case 30: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 455 && sljunak[ GetPlayerVehicleID( playerid ) ] == true ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}
					
					sljunak[ GetPlayerVehicleID( playerid ) ] = false;
					Dimi_DisablePlayerCheckpoint( playerid );
					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					CheckpointStatus[ playerid ] = 0;
					new bonus = random( 200 );
					PlayerInfo[ playerid ][ xPlatniRacun ] += (2800+bonus);
					SavePlayer( playerid ); UpdatePlataTD( playerid );
					BussinesJobMoney( POSAO_PREVOZNIK, ((2800+bonus)/10) );
					StaroVreme[ playerid ] = 0;
					NovoVreme[ playerid ] = 0;

					SendJobMessage( playerid, "Zavrsio si prevoz sljunka, zaradio si "col_white"%d$ "col_job"koji su ti legli na platni racun.", (2800+bonus) );
				}
			}
			case 31: {
				// edit
			}
			case 32: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_ONFOOT && PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR && PosaoRudar[ playerid ] != 0 && UzeoOpremu[ playerid ] == true ) {

					Dimi_DisablePlayerCheckpoint( playerid );
					ApplyAnimation( playerid, "CHAINSAW", "CSAW_1", 4.1, 1, 1, 1, 0, 0 );
					PlayerPlaySound( playerid, 1056, 0.0, 0.0, 0.0 );
					SendJobMessage( playerid, "Poceli ste sa kopanjem sacekajte 20 sekundi.");
					announcement( playerid, "~w~Kopate~n~sacekajte par sekundi", 20000, 4 );
					rudarPosao[ playerid ][ rudarTimer ] = SetTimerEx( "Iskopavanje", 20000, false, "i", playerid );
				}
			}
			case 33: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_ONFOOT && PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR && PosaoRudar[ playerid ] != 0 && UzeoOpremu[ playerid ] == true ) {
					if( rudarPosao[ playerid ][ rudarIskopano ] >= 6 ) {
					
						ClearAnimations( playerid );
						RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
						Dimi_DisablePlayerCheckpoint( playerid );
						SendJobMessage( playerid, "Sacekajte malo dok se ruda preradi!");
						
						rudarPosao[ playerid ][ rudarObjects ][ 0 ] = CreatePlayerObject( playerid, 19941, 493.3516, 762.6542, 1000.5337,   0.0000, -8.4424, 0.0000 );
						rudarPosao[ playerid ][ rudarObjects ][ 1 ] = CreatePlayerObject( playerid, 19941, 493.3516, 762.5182, 1000.5337,   0.0000, -8.4424, 0.0000 );
						rudarPosao[ playerid ][ rudarObjects ][ 2 ] = CreatePlayerObject( playerid, 19941, 493.3516, 762.3822, 1000.5337,   0.0000, -8.4424, 0.0000 );

						MovePlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 0 ], 498.0776, 762.6542, 1001.0777, 0.5 );
						MovePlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 1 ], 497.9756, 762.5182, 1001.0777, 0.5 );
						MovePlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 2 ], 498.1796, 762.3822, 1001.0777, 0.5 );

						rudarPosao[ playerid ][ rudarTimer ] = SetTimerEx( "sekundiRudar", 12000, false, "i", playerid );
					}
				}
			}
			case 34:
			{
				if( GetPlayerState( playerid ) == PLAYER_STATE_ONFOOT && PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR && PosaoRudar[ playerid ] != 0 && UzeoOpremu[ playerid ] == true )
				{
					
					DestroyPlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 0 ] );
					DestroyPlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 1 ] );
					DestroyPlayerObject( playerid, rudarPosao[ playerid ][ rudarObjects ][ 2 ] );
					Dimi_DisablePlayerCheckpoint( playerid );
					
					CheckpointStatus[ playerid ] = 0;
					new zlato = PosloviInfo[ RudarGramiZlata ] + random( 4 );

					SendJobMessage( playerid, "Uspjesno ste zavrsili sa kopanjem!Iskopali ste %dg zlata.", zlato );

					BussinesJobMoney( POSAO_RUDAR, 200/10 );

					PlayerInfo[ playerid ][ xZlato ] += zlato;
					SavePlayer( playerid );
					UpdateZlatoTD( playerid );
					
					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_LHAND );
					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
					
					SetPlayerAttachedObject( playerid, OBJECT_SLOT_LHAND, 18634, 6, 0.048513, 0.018571, 0.028653, 314.764404, 226.953979, 222.510803, 1.000000, 1.000000, 1.000000 );
					SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 2060, 1, -0.191781, -0.162666, -0.003734, 88.812377, 0.000000, 0.408470, 1.000000, 1.000000, 1.000000 );
					
					rudarPosao[ playerid ][ rudarIskopano ] = 0;
					
					PosaoRudar[ playerid ] = 0;
				}
			}
			case 35: {
			
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 428 && PlayerInfo[ playerid ][ xPosao ] == POSAO_PREVOZNOVCA ) {

					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					announcement( playerid, "~w~Pricekajte, novac se utovaruje..", 5000, 1);
					TogglePlayerControllable( playerid, false );
					SetTimerEx( "Utovar", 5000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 5 );
					CheckpointStatus[ playerid ] = 0;
					Dimi_DisablePlayerCheckpoint( playerid );
				}
			}
			case 36: {
				if( GetPlayerState( playerid ) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle( playerid ) && GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 428 && VehNovac[ GetPlayerVehicleID( playerid ) ] == true ) {
					new time = gettime( );
					new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
					if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
						GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
						GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
						format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
						AdminPoruka( ANTICHEAT, globalstring );
						return 1;
					}

					Dimi_DisablePlayerCheckpoint( playerid );
					announcement( playerid, "~w~Pricekajte novac se istovaruje..", 5000, 1);
					TogglePlayerControllable( playerid, false );
					CheckpointStatus[ playerid ] = 0;
					SetTimerEx( "Istovar", 5000, false, "dii", playerid, GetPlayerVehicleID( playerid ), 8 );
				}
			}
			case 37: {
			
				if( GetVehicleModel( GetPlayerVehicleID( playerid ) ) == 538 && GetPlayerState( playerid ) == 2 ) {

					if( VozPosao[ playerid ] < 6 ) {
						Dimi_DisablePlayerCheckpoint( playerid );
						VozPosao[ playerid ]++;
						CheckpointStatus[ playerid ] = 37;
					}

					if( VozPosao[ playerid ] == 2 ) Dimi_SetPlayerCheckpoint( playerid, -1943.9296, 141.2939, 27.0006, 5.0 );
					else if( VozPosao[ playerid ] == 3 ) Dimi_SetPlayerCheckpoint( playerid, 1440.2815,2632.3748,10.8203, 5.0 );
					else if( VozPosao[ playerid ] == 4 ) Dimi_SetPlayerCheckpoint( playerid, 2864.9333,1287.2427,10.8203, 5.0 );
					else if( VozPosao[ playerid ] == 5 ) Dimi_SetPlayerCheckpoint( playerid, 1740.3632,-1954.2498,13.5469, 5.0 );
					else if( VozPosao[ playerid ] == 6 ) {

						new time = gettime( );
						new ostatak = ( NovoVreme[ playerid ] - ( time - StaroVreme[ playerid ] ) );
						if( ( time - StaroVreme[ playerid ] ) < NovoVreme[ playerid ] ) {
							GRESKA( playerid, "Dosli ste ranije na marker nego sto je predvidjeno. " );
							GRESKA( playerid, "Sacekajte jos %d sekundi i udjite ponovo u marker.", ostatak );
							format( globalstring, sizeof( globalstring ), "{FF0000}| AC |:"SERVERBOJA_AQUA" %s[ID: %d] "col_white"je stigao na marker prije vremena"SERVERBOJA_AQUA"( za %d od %d sekundi ).", ImeIgraca( playerid ), playerid, (NovoVreme[ playerid ]-ostatak), NovoVreme[ playerid ] );
							AdminPoruka( ANTICHEAT, globalstring );
							return 1;
						}

						SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
						Dimi_DisablePlayerCheckpoint( playerid );
						TogglePlayerControllable( playerid, true );
						VozPosao[ playerid ] = 0;
						CheckpointStatus[ playerid ] = 0;
						Dimi_KillTimer( PosaoMasinovodja[ playerid ] );

						new bonus = random( 400 );

						format( globalstring, sizeof( globalstring ), ""col_job"Uspjesno ste zavrsili voz liniju!\n\n"col_white"Plata: "col_job"2800$\n"col_white"Bonus: "col_job"%d$", bonus );
						ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, globalstring, "Ok", "" );

						PlayerInfo[ playerid ][ xPlatniRacun ] += (2800+bonus);
						SavePlayer( playerid );
						UpdatePlataTD( playerid );

						StaroVreme[ playerid ] = 0;
						NovoVreme[ playerid ] = 0;

						BussinesJobMoney( POSAO_MASINOVODJA, ((2800+bonus)/10) );
						return 1;
					}
					TogglePlayerControllable( playerid, false );
					PosaoMasinovodja[ playerid ] = SetTimerEx( "UtovarVoz", 5000, false, "d", playerid );
					announcement( playerid, "~y~Stigli ste na stanicu, pricekajte malo...", 5000, 3 );
				}
			}
			case 38: {
				if( PlayerInfo[ playerid ][ xPosao ] == POSAO_RIBAR && TipVozila[ GetPlayerVehicleID( playerid ) ] == POSLOVNO_VOZILO && VehicleInfo[ ScriptIDVozila[ GetPlayerVehicleID( playerid ) ] ][ vJob ] == PlayerInfo[ playerid ][ xPosao ] ) {

					DestroyPlayerObject( playerid, fishermanInfo[ playerid ][ fObject ] );

					ClearChat( playerid, 25 );
					DajIgracuNovac( playerid, fishermanInfo[ playerid ][ FishKG ]*25 );
					SendJobMessage( playerid, "Istovarili ste "col_job"%d "col_white"kilograma ribe i zaradili "col_job"$%d"col_white".", fishermanInfo[ playerid ][ FishKG ], fishermanInfo[ playerid ][ FishKG ]*25 );
					Dimi_DisablePlayerCheckpoint( playerid);
					fishermanInfo[ playerid ][ FishKG ] = 0;
					fishermanInfo[ playerid ][ Fishing ] = false;
					fishermanInfo[ playerid ][ StartedFishing ] = false;
					fishermanInfo[ playerid ][ Fisherman ] = 0;
					fishermanInfo[ playerid ][ fLastVeh ] = 0;

					/*P_Enum[playerid][pe_SkillRIBAR]++;
					if(P_Enum[playerid][pe_SkillRIBAR] == 50) { INFO(playerid, "Vas skill ribara je sada level 1, dobijacete vise novca pri zaradi!"); }
					else if(P_Enum[playerid][pe_SkillRIBAR] == 100) { INFO(playerid, "Vas skill ribara je sada level 2, dobijacete vise novca pri zaradi!"); }
					else if(P_Enum[playerid][pe_SkillRIBAR] == 200) { INFO(playerid, "Vas skill ribara je sada level 3, dobijacete vise novca pri zaradi!"); }
					else if(P_Enum[playerid][pe_SkillRIBAR] == 300) { INFO(playerid, "Vas skill ribara je sada level 4, dobijacete vise novca pri zaradi!"); }
					else if(P_Enum[playerid][pe_SkillRIBAR] == 400) { INFO(playerid, "Vas skill ribara je sada level 5, dobijacete vise novca pri zaradi!"); }

					if(P_Enum[playerid][pe_SkillRIBAR] >= 50) { new bonus = randomEx(5, 10); Dimi_Plus(playerid, bonus, "Bonus ribara"); va_SendClientMessage(playerid, COLOR_XEPTIC, JOBPREFIX"Bonus zarade: "COL_MONEY"$%d", bonus); }
					else if(P_Enum[playerid][pe_SkillRIBAR] >= 100) { new bonus = randomEx(6, 12); Dimi_Plus(playerid, bonus, "Bonus ribara"); va_SendClientMessage(playerid, COLOR_XEPTIC, JOBPREFIX"Bonus zarade: "COL_MONEY"$%d", bonus); }
					else if(P_Enum[playerid][pe_SkillRIBAR] >= 200) { new bonus = randomEx(7, 14); Dimi_Plus(playerid, bonus, "Bonus ribara"); va_SendClientMessage(playerid, COLOR_XEPTIC, JOBPREFIX"Bonus zarade: "COL_MONEY"$%d", bonus); }
					else if(P_Enum[playerid][pe_SkillRIBAR] >= 300) { new bonus = randomEx(8, 16); Dimi_Plus(playerid, bonus, "Bonus ribara"); va_SendClientMessage(playerid, COLOR_XEPTIC, JOBPREFIX"Bonus zarade: "COL_MONEY"$%d", bonus); }
					else if(P_Enum[playerid][pe_SkillRIBAR] >= 400) { new bonus = randomEx(9, 18); Dimi_Plus(playerid, bonus, "Bonus ribara"); va_SendClientMessage(playerid, COLOR_XEPTIC, JOBPREFIX"Bonus zarade: "COL_MONEY"$%d", bonus); }*/

					SetVehicleToRespawn( GetPlayerVehicleID( playerid ) );
					SetPlayerPos( playerid, 2114.9539, 135.0508, 2.3156 );
					//ShowFishingTD( playerid, false );
				}
			}
			case 39:
			{
			
				if( ProcesSvercanja[ playerid ] == 1 )
				{
					Dimi_DisablePlayerCheckpoint( playerid );
					Dimi_SetPlayerCheckpoint( playerid, -2138.0974,-247.9632,36.5156, 2.0 );
					CheckpointStatus[ playerid ] = 39;
					ProcesSvercanja[ playerid ] = 2;

					SendInfoMessage(playerid, "Sada izadjite iz kombija i uzmite paket materijala!" );
				}
				else if( ProcesSvercanja[ playerid ] == 2 )
				{
					Dimi_DisablePlayerCheckpoint( playerid );
					ProcesSvercanja[ playerid ] = 3;
					CheckpointStatus[ playerid ] = 0;
					SetPlayerAttachedObject( playerid, OBJECT_SLOT_BADGE, 3052, 1, 0.15, 0.4, 0.0, 0.0, 90.0, 0.0, 1.0, 1.0, 1.0 );
					SendInfoMessage(playerid, "Preuzeli ste paket matsa sada ga ubacite u kombi /ubacimats");
					ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );
				
				}
				else if( ProcesSvercanja[ playerid ] == 4 )
				{
					Dimi_DisablePlayerCheckpoint( playerid );
					CheckpointStatus[ playerid ] = 0;
					SendInfoMessage(playerid, "Sada izadjite iz vozila i izvadite materijale /izvadimats !");

				}
				else if( ProcesSvercanja[ playerid ] == 5 )
				{
				
					if( !IsPlayerAttachedObjectSlotUsed( playerid, OBJECT_SLOT_BADGE ) ) return GRESKA( playerid, "Nemate kutiju u rukama!");

					Dimi_DisablePlayerCheckpoint( playerid );
					
					ProcesSvercanja[ playerid ] = 0;

					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );

					CheckpointStatus[ playerid ] = 0;

					new mats = random(20)+200;

					SendInfoMessage(playerid, "Dostavili ste kutiju matsa i dobili %d materijala!", mats );
					ApplyAnimation( playerid, "CARRY", "putdwn", 3.0, 0, 0, 0, 0, 0 );
					
					PlayerInfo[ playerid ][ xSvercer ] = 5;
					PlayerInfo[ playerid ][ xMaterijali ] += mats;
					SavePlayer( playerid );
				
				}
			}
			case 40: {
			
				if( NamestajLevel[ playerid ] == 1 || NamestajLevel[ playerid ] == 2 || NamestajLevel[ playerid ] == 4 || IsPlayerInRangeOfPoint(playerid, 4.0, 2149.6013, -2273.1235, 13.3047)) {
				
					Dimi_DisablePlayerCheckpoint( playerid );
					CheckpointStatus[ playerid ] = 0;
				}
				else if( NamestajLevel[ playerid ] == 6 ) {
				
					Dimi_DisablePlayerCheckpoint( playerid );
					NamestajLevel[ playerid ] = 0;
					Rezanje[ playerid ] = 0;
					RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );
					SetPlayerSpecialAction( playerid, false );
					CheckpointStatus[ playerid ] = 0;
					
					new bonus = random( 40 );

					format( globalstring, sizeof( globalstring ), ""col_job"Uspjesno ste zavrsili proizvodnju!\n\n"col_white"Plata: "col_job"200$\n"col_white"Bonus: "col_job"%d$", bonus );
					ShowPlayerDialog( playerid, 0, DSMSG, D_NASLOV, globalstring, "Ok", "" );

					PlayerInfo[ playerid ][ xPlatniRacun ] += (200+bonus);
					SavePlayer( playerid );
					UpdatePlataTD( playerid );
					
					ServerInfo[ Namestaj ] += 1;
					SaveServerStats( );

					BussinesJobMoney( POSAO_PNAMESTAJA, ((200+bonus)/10) );

				}
			}
		}
	}
	return true;
}

forward sekundiRudar( playerid );
public sekundiRudar( playerid ) {

	Dimi_KillTimer( rudarPosao[ playerid ][ rudarTimer ] );
	Dimi_SetPlayerCheckpoint( playerid, 497.9888, 764.4081, 1001.5510, 2.0 );
	CheckpointStatus[ playerid ] = 34;
	SendJobMessage( playerid, "Vase iskopine su preradjenje, odite da ih pokupite." );
	return true;
}

forward Iskopavanje( playerid );
public Iskopavanje( playerid ) {

	if( GetPlayerState( playerid ) == PLAYER_STATE_ONFOOT && PlayerInfo[ playerid ][ xPosao ] == POSAO_RUDAR && PosaoRudar[ playerid ] != 0 && UzeoOpremu[ playerid ] == true ) {

		Dimi_KillTimer( rudarPosao[ playerid ][ rudarTimer ] );
		ClearAnimations( playerid );
		rudarPosao[ playerid ][ rudarIskopano ]++;
		if( rudarPosao[ playerid ][ rudarIskopano ] < 6 ) {
			new broj = rudarPosao[ playerid ][ rudarIskopano ];
			Dimi_SetPlayerCheckpoint( playerid, RandomRudnik[ broj ][ 0 ], RandomRudnik[ broj ][ 1 ], RandomRudnik[ broj ][ 2 ], 2.5 );
			CheckpointStatus[ playerid ] = 32;
			ClearAnimations( playerid );
			
			SendJobMessage( playerid, "Oznaceno vam je novo mesto, pratite marker!" );
		}
		else if( rudarPosao[ playerid ][ rudarIskopano ] >= 6 ) {

			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_RHAND );
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_RHAND, 2060, 1, 0.15, 0.4, 0.0, 0.0, 90.0, 0.0, 1.0, 1.0, 1.0 );

			RemovePlayerAttachedObject( playerid, OBJECT_SLOT_LHAND );
			SetPlayerAttachedObject( playerid, OBJECT_SLOT_LHAND, 18634, 1, -0.600000, 0.100000, 0.189999, 270.000000, 180.000000, 90.000000, 1.000000, 1.000000, 1.000000 );
			
			ApplyAnimation( playerid, "CARRY", "crry_prtial", 4.1, 0, 1, 1, 1, 1, 1 );

			Dimi_SetPlayerCheckpoint( playerid, 491.6207,764.1483,1001.4609, 2.0 );
			CheckpointStatus[ playerid ] = 33;
			SendJobMessage( playerid, "Zavrsili ste sa kopanjem, sada odnesite da preradite iskopine!" );
		}
	}
	return true;
}

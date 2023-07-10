/*            *
* DOBRODOSLI NAM NA...       *
* ------------- Nova Era RolePlay!
*       *       =====================
*____________________________________*
*
* OMOGUCIO SVE OVO: Skopsi
*                           *
* Verzija: pogledati #DEFINE NERP_VERZIJA    *
*                             *
* Developer: DEntisT_and_Brace
*               *
* Zadnji update: 22.01.2021      *
*
* Mapper: Mata | Vlasnik: Skopsi          *
*                   *
*/

#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


/////////////////////////////parking///////////////////

forward Parking_Save( id );
public Parking_Save( id ) {

	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), PARKING_FILE, id );
	new INI:File = INI_Open( iFile );
	
	INI_WriteBool( File, "Placed", ParkingInfo[ id ][ parkPlaced ] );
	INI_WriteFloat( File, "ObjectPos_X", ParkingInfo[ id ][ parkObjectPos ][ 0 ] );
	INI_WriteFloat( File, "ObjectPos_Y", ParkingInfo[ id ][ parkObjectPos ][ 1 ] );
	INI_WriteFloat( File, "ObjectPos_Z", ParkingInfo[ id ][ parkObjectPos ][ 2 ] );
	INI_WriteFloat( File, "ObjectPos_RX", ParkingInfo[ id ][ parkObjectPos ][ 3 ] );
	INI_WriteFloat( File, "ObjectPos_RY", ParkingInfo[ id ][ parkObjectPos ][ 4 ] );
	INI_WriteFloat( File, "ObjectPos_RZ", ParkingInfo[ id ][ parkObjectPos ][ 5 ] );
	
	INI_WriteInt( File, "Int", ParkingInfo[ id ][ parkInt ] );
	INI_WriteInt( File, "VW", ParkingInfo[ id ][ parkVW ] );
	
	INI_WriteFloat( File, "MaxX", ParkingInfo[ id ][ parkMaxX ] );
	INI_WriteFloat( File, "MinX", ParkingInfo[ id ][ parkMinX ] );
	INI_WriteFloat( File, "MaxY", ParkingInfo[ id ][ parkMaxY ] );
	INI_WriteFloat( File, "MinY", ParkingInfo[ id ][ parkMinY ] );
	
	INI_WriteFloat( File, "Pickup_1_Pos_X", ParkingInfo[ id ][ parkPickup_1_Pos ][ 0 ] );
	INI_WriteFloat( File, "Pickup_1_Pos_Y", ParkingInfo[ id ][ parkPickup_1_Pos ][ 1 ] );
	INI_WriteFloat( File, "Pickup_1_Pos_Z", ParkingInfo[ id ][ parkPickup_1_Pos ][ 2 ] );
	
	INI_WriteFloat( File, "Pickup_2_Pos_X", ParkingInfo[ id ][ parkPickup_2_Pos ][ 0 ] );
	INI_WriteFloat( File, "Pickup_2_Pos_Y", ParkingInfo[ id ][ parkPickup_2_Pos ][ 1 ] );
	INI_WriteFloat( File, "Pickup_2_Pos_Z", ParkingInfo[ id ][ parkPickup_2_Pos ][ 2 ] );
	
	INI_WriteInt( File, "MaxParkPlaces", ParkingInfo[ id ][ parkMaxParkPlaces ] );
	
	INI_Close( File );

	return (true);
}

forward Parking_Load(id, name[], value[]);
public Parking_Load(id, name[], value[]) {

	new string[ 24 ];
	
	INI_Bool( "Placed", ParkingInfo[ id ][ parkPlaced ] );

	INI_Float( "ObjectPos_X", ParkingInfo[ id ][ parkObjectPos ][ 0 ] );
	INI_Float( "ObjectPos_Y", ParkingInfo[ id ][ parkObjectPos ][ 1 ] );
	INI_Float( "ObjectPos_Z", ParkingInfo[ id ][ parkObjectPos ][ 2 ] );
	INI_Float( "ObjectPos_RX", ParkingInfo[ id ][ parkObjectPos ][ 3 ] );
	INI_Float( "ObjectPos_RY", ParkingInfo[ id ][ parkObjectPos ][ 4 ] );
	INI_Float( "ObjectPos_RZ", ParkingInfo[ id ][ parkObjectPos ][ 5 ] );

	INI_Int( "Int", ParkingInfo[ id ][ parkInt ] );
	INI_Int( "VW", ParkingInfo[ id ][ parkVW ] );

	INI_Float( "Pickup_1_Pos_X", ParkingInfo[ id ][ parkPickup_1_Pos ][ 0 ] );
	INI_Float( "Pickup_1_Pos_Y", ParkingInfo[ id ][ parkPickup_1_Pos ][ 1 ] );
	INI_Float( "Pickup_1_Pos_Z", ParkingInfo[ id ][ parkPickup_1_Pos ][ 2 ] );

	INI_Float( "Pickup_2_Pos_X", ParkingInfo[ id ][ parkPickup_2_Pos ][ 0 ] );
	INI_Float( "Pickup_2_Pos_Y", ParkingInfo[ id ][ parkPickup_2_Pos ][ 1 ] );
	INI_Float( "Pickup_2_Pos_Z", ParkingInfo[ id ][ parkPickup_2_Pos ][ 2 ] );

	INI_Float( "MaxX", ParkingInfo[ id ][ parkMaxX ] );
	INI_Float( "MinX", ParkingInfo[ id ][ parkMinX ] );
	INI_Float( "MaxY", ParkingInfo[ id ][ parkMaxY ] );
	INI_Float( "MinY", ParkingInfo[ id ][ parkMinY ] );

	INI_Int( "MaxParkPlaces", ParkingInfo[ id ][ parkMaxParkPlaces ] );
	
	
	for( new i = 0; i < ParkingInfo[ id ][ parkMaxParkPlaces ]; i++) {
		
		ParkingPlaces[ id ][ i ][ parkTaken ] = false;
		format( string, sizeof( string ), "parkPlace_X%d", i );
		INI_Float( string, ParkingPlaces[ id ][ i ][ parkPlace_X ] );
		format( string, sizeof( string ), "parkPlace_Y%d", i );
		INI_Float( string, ParkingPlaces[ id ][ i ][ parkPlace_Y ] );
		format( string, sizeof( string ), "parkPlace_Z%d", i );
		INI_Float( string, ParkingPlaces[ id ][ i ][ parkPlace_Z ] );
		format( string, sizeof( string ), "parkPlace_A%d", i );
		INI_Float( string, ParkingPlaces[ id ][ i ][ parkPlace_A ] );
	}
	return 1;
}

////////////////fuel station////////////////


forward FStation_Save( id );
public FStation_Save( id ) {

	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), FSTATION_FILE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Placed", FuelStation[ id ][ fsPlaced ] );
	INI_WriteInt( File, "BussinesID", FuelStation[ id ][ fsBussinesID ] );
	INI_WriteInt( File, "GasolinePrice", FuelStation[ id ][ fsGasolinePrice ] );
	INI_WriteInt( File, "GasolineL", FuelStation[ id ][ fsGasolineL ] );
	INI_WriteInt( File, "DieselPrice", FuelStation[ id ][ fsDieselPrice ] );
	INI_WriteInt( File, "DieselL", FuelStation[ id ][ fsDieselL ] );
	INI_WriteInt( File, "GasPrice", FuelStation[ id ][ fsGasPrice ] );
	INI_WriteInt( File, "GasL", FuelStation[ id ][ fsGasL ] );
	INI_WriteInt( File, "GasOilPrice", FuelStation[ id ][ fsGasOilPrice ] );
	INI_WriteInt( File, "GasOilL", FuelStation[ id ][ fsGasOilL ] );
	INI_WriteString( File, "Name", FuelStation[ id ][ fsName ] );
	INI_WriteFloat( File, "PosX", FuelStation[ id ][ fsPos ][ 0 ] );
	INI_WriteFloat( File, "PosY", FuelStation[ id ][ fsPos ][ 1 ] );
	INI_WriteFloat( File, "PosZ", FuelStation[ id ][ fsPos ][ 2 ] );
	INI_WriteInt( File, "TruckID", FuelStation[ id ][ fsTruckID ] );
	INI_WriteInt( File, "CisternID", FuelStation[ id ][ fsCisternID ] );
	INI_Close( File );
	
	return (true);
}

forward FStation_Load( id, name[], value[] );
public FStation_Load( id, name[], value[] ) {

	INI_Bool( "Placed", FuelStation[ id ][ fsPlaced ] );
	INI_Int( "BussinesID", FuelStation[ id ][ fsBussinesID ] );
	INI_Int( "GasolinePrice", FuelStation[ id ][ fsGasolinePrice ] );
	INI_Int( "GasolineL", FuelStation[ id ][ fsGasolineL ] );
	INI_Int( "DieselPrice", FuelStation[ id ][ fsDieselPrice ] );
	INI_Int( "DieselL", FuelStation[ id ][ fsDieselL ] );
	INI_Int( "GasPrice", FuelStation[ id ][ fsGasPrice ] );
	INI_Int( "GasL", FuelStation[ id ][ fsGasL ] );
	INI_Int( "GasOilPrice", FuelStation[ id ][ fsGasOilPrice ] );
	INI_Int( "GasOilL", FuelStation[ id ][ fsGasOilL ] );
	INI_String( "Name", FuelStation[ id ][ fsName ], 64 );
	INI_Float( "PosX", FuelStation[ id ][ fsPos ][ 0 ] );
	INI_Float( "PosY", FuelStation[ id ][ fsPos ][ 1 ] );
	INI_Float( "PosZ", FuelStation[ id ][ fsPos ][ 2 ] );
	INI_Int( "TruckID", FuelStation[ id ][ fsTruckID ] );
	INI_Int( "CisternID", FuelStation[ id ][ fsCisternID ] );

	return (true);
}


//-------------------[ BEOGRADSKI GPS ]-----------------------------------------
forward BGGPS_Save( id );
public BGGPS_Save( id )
{
	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), F_BGGPS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteString( File, "Name", BGgpsInfo[ id ][ BGgpsName ] );
	INI_WriteFloat( File, "PosX", BGgpsInfo[ id ][ BGgpsPos ][ 0 ] );
	INI_WriteFloat( File, "PosY", BGgpsInfo[ id ][ BGgpsPos ][ 1 ] );
	INI_WriteFloat( File, "PosZ", BGgpsInfo[ id ][ BGgpsPos ][ 2 ] );
	INI_Close( File );
	return (true);
}
//
forward BGLoadGPS( id, name[], value[] );
public BGLoadGPS( id, name[], value[] ) {

	INI_String( "Name", BGgpsInfo[ id ][ BGgpsName ], 50  );
	INI_Float( "PosX", BGgpsInfo[ id ][ BGgpsPos ][ 0 ] );
	INI_Float( "PosY", BGgpsInfo[ id ][ BGgpsPos ][ 1 ] );
	INI_Float( "PosZ", BGgpsInfo[ id ][ BGgpsPos ][ 2 ] );
	return (true);
}


//-------------------[ SARAJEVSKI GPS ]-----------------------------------------
forward SAGPS_Save( id );
public SAGPS_Save( id )
{
	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), F_SAGPS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteString( File, "Name", SAgpsInfo[ id ][ SAgpsName ] );
	INI_WriteFloat( File, "PosX", SAgpsInfo[ id ][ SAgpsPos ][ 0 ] );
	INI_WriteFloat( File, "PosY", SAgpsInfo[ id ][ SAgpsPos ][ 1 ] );
	INI_WriteFloat( File, "PosZ", SAgpsInfo[ id ][ SAgpsPos ][ 2 ] );
	INI_Close( File );
	return (true);
}
//
forward SALoadGPS( id, name[], value[] );
public SALoadGPS( id, name[], value[] ) {

	INI_String( "Name", SAgpsInfo[ id ][ SAgpsName ], 50  );
	INI_Float( "PosX", SAgpsInfo[ id ][ SAgpsPos ][ 0 ] );
	INI_Float( "PosY", SAgpsInfo[ id ][ SAgpsPos ][ 1 ] );
	INI_Float( "PosZ", SAgpsInfo[ id ][ SAgpsPos ][ 2 ] );
	return (true);
}

//-------------------[ ZAGREBACKI GPS ]-----------------------------------------
forward ZGGPS_Save( id );
public ZGGPS_Save( id )
{
	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), F_ZGGPS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteString( File, "Name", ZGgpsInfo[ id ][ ZGgpsName ] );
	INI_WriteFloat( File, "PosX", ZGgpsInfo[ id ][ ZGgpsPos ][ 0 ] );
	INI_WriteFloat( File, "PosY", ZGgpsInfo[ id ][ ZGgpsPos ][ 1 ] );
	INI_WriteFloat( File, "PosZ", ZGgpsInfo[ id ][ ZGgpsPos ][ 2 ] );
	INI_Close( File );
	return (true);
}
//
forward ZGLoadGPS( id, name[], value[] );
public ZGLoadGPS( id, name[], value[] ) {

	INI_String( "Name", ZGgpsInfo[ id ][ ZGgpsName ], 50  );
	INI_Float( "PosX", ZGgpsInfo[ id ][ ZGgpsPos ][ 0 ] );
	INI_Float( "PosY", ZGgpsInfo[ id ][ ZGgpsPos ][ 1 ] );
	INI_Float( "PosZ", ZGgpsInfo[ id ][ ZGgpsPos ][ 2 ] );
	return (true);
}


//-------------------[ OSTALE LOKACIJE GPS ]-----------------------------------------
forward OSGPS_Save( id );
public OSGPS_Save( id )
{
	new iFile[ 60 ];
	format( iFile, sizeof( iFile ), F_OSGPS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteString( File, "Name", OSgpsInfo[ id ][ OSgpsName ] );
	INI_WriteFloat( File, "PosX", OSgpsInfo[ id ][ OSgpsPos ][ 0 ] );
	INI_WriteFloat( File, "PosY", OSgpsInfo[ id ][ OSgpsPos ][ 1 ] );
	INI_WriteFloat( File, "PosZ", OSgpsInfo[ id ][ OSgpsPos ][ 2 ] );
	INI_Close( File );
	return (true);
}
//
forward OSLoadGPS( id, name[], value[] );
public OSLoadGPS( id, name[], value[] ) {

	INI_String( "Name", OSgpsInfo[ id ][ OSgpsName ], 50  );
	INI_Float( "PosX", OSgpsInfo[ id ][ OSgpsPos ][ 0 ] );
	INI_Float( "PosY", OSgpsInfo[ id ][ OSgpsPos ][ 1 ] );
	INI_Float( "PosZ", OSgpsInfo[ id ][ OSgpsPos ][ 2 ] );
	return (true);
}


//////////////////////////////////////pokloni//////////////////////

forward LoadPresents( id, name[], value[] );
public LoadPresents( id, name[], value[] ) {

	INI_Bool( "Taken", presentsInfo[ id ][ presTaken ] );
	INI_Bool( "Placed", presentsInfo[ id ][ presPlaced ] );
	INI_Float( "Pos1", presentsInfo[ id ][ presPos ][ 0 ] );
	INI_Float( "Pos2", presentsInfo[ id ][ presPos ][ 1 ] );
	INI_Float( "Pos3", presentsInfo[ id ][ presPos ][ 2 ] );
	INI_Float( "Pos4", presentsInfo[ id ][ presPos ][ 3 ] );
	INI_Float( "Pos5", presentsInfo[ id ][ presPos ][ 4 ] );
	INI_Float( "Pos6", presentsInfo[ id ][ presPos ][ 5 ] );

	return (true);
}


forward SavePresent( id );
public SavePresent( id ) {

	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_PRESENTS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Taken", presentsInfo[ id ][ presTaken ] );
	INI_WriteBool( File, "Placed", presentsInfo[ id ][ presPlaced ] );
	INI_WriteFloat( File, "Pos1", presentsInfo[ id ][ presPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", presentsInfo[ id ][ presPos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", presentsInfo[ id ][ presPos ][ 2 ] );
	INI_WriteFloat( File, "Pos4", presentsInfo[ id ][ presPos ][ 3 ] );
	INI_WriteFloat( File, "Pos5", presentsInfo[ id ][ presPos ][ 4 ] );
	INI_WriteFloat( File, "Pos6", presentsInfo[ id ][ presPos ][ 5 ] );
	INI_Close( File );
	return (true);
}


//////////////////////xorb////////////////////////



forward SaveXOrb( id );
public SaveXOrb( id ) {

	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_XORBS, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Placed", XmasOrbs[ id ][ xoPlaced ] );
	INI_WriteFloat( File, "Pos1", XmasOrbs[ id ][ xoPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", XmasOrbs[ id ][ xoPos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", XmasOrbs[ id ][ xoPos ][ 2 ] );
	INI_WriteFloat( File, "Pos4", XmasOrbs[ id ][ xoPos ][ 3 ] );
	INI_WriteFloat( File, "Pos5", XmasOrbs[ id ][ xoPos ][ 4 ] );
	INI_WriteFloat( File, "Pos6", XmasOrbs[ id ][ xoPos ][ 5 ] );
	INI_Close( File );
	return (true);
}



forward LoadXOrbs( id, name[], value[] );
public LoadXOrbs( id, name[], value[] ) {

	INI_Bool( "Placed", XmasOrbs[ id ][ xoPlaced ] );
	INI_Float( "Pos1", XmasOrbs[ id ][ xoPos ][ 0 ] );
	INI_Float( "Pos2", XmasOrbs[ id ][ xoPos ][ 1 ] );
	INI_Float( "Pos3", XmasOrbs[ id ][ xoPos ][ 2 ] );
	INI_Float( "Pos4", XmasOrbs[ id ][ xoPos ][ 3 ] );
	INI_Float( "Pos5", XmasOrbs[ id ][ xoPos ][ 4 ] );
	INI_Float( "Pos6", XmasOrbs[ id ][ xoPos ][ 5 ] );

	return (true);
}


///////////////////////ctree//////////////////////////


forward SaveCTree( id );
public SaveCTree( id ) {

	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_CTREES, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Placed", CTree[ id ][ ctPlaced ] );
	INI_WriteFloat( File, "Pos1", CTree[ id ][ ctPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", CTree[ id ][ ctPos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", CTree[ id ][ ctPos ][ 2 ] );
	INI_WriteFloat( File, "Pos4", CTree[ id ][ ctPos ][ 3 ] );
	INI_WriteFloat( File, "Pos5", CTree[ id ][ ctPos ][ 4 ] );
	INI_WriteFloat( File, "Pos6", CTree[ id ][ ctPos ][ 5 ] );
	INI_Close( File );
	return (true);
}

forward LoadCTrees( id, name[], value[] );
public LoadCTrees( id, name[], value[] ) {

	INI_Bool( "Placed", CTree[ id ][ ctPlaced ] );
	INI_Float( "Pos1", CTree[ id ][ ctPos ][ 0 ] );
	INI_Float( "Pos2", CTree[ id ][ ctPos ][ 1 ] );
	INI_Float( "Pos3", CTree[ id ][ ctPos ][ 2 ] );
	INI_Float( "Pos4", CTree[ id ][ ctPos ][ 3 ] );
	INI_Float( "Pos5", CTree[ id ][ ctPos ][ 4 ] );
	INI_Float( "Pos6", CTree[ id ][ ctPos ][ 5 ] );

	return (true);
}

///////////////////////////////////garaze/////////////////////////////


forward Garage_Save( id );
public Garage_Save( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_GARAGE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Owned", garageInfo[ id ][ garageOwned ] );
	INI_WriteString( File, "Owner", garageInfo[ id ][ garageOwner ] );
	INI_WriteInt( File, "Price", garageInfo[ id ][ garagePrice ] );
	INI_WriteInt( File, "Level", garageInfo[ id ][ garageLevel ] );
	INI_WriteBool( File, "Locked", garageInfo[ id ][ garageLocked ] );
	INI_WriteFloat( File, "Pos1", garageInfo[ id ][ garagePos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", garageInfo[ id ][ garagePos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", garageInfo[ id ][ garagePos ][ 2 ] );
	INI_WriteFloat( File, "VehiclePos1", garageInfo[ id ][ garageVehiclePos ][ 0 ] );
	INI_WriteFloat( File, "VehiclePos2", garageInfo[ id ][ garageVehiclePos ][ 1 ] );
	INI_WriteFloat( File, "VehiclePos3", garageInfo[ id ][ garageVehiclePos ][ 2 ] );
	INI_WriteFloat( File, "VehiclePos4", garageInfo[ id ][ garageVehiclePos ][ 3 ] );
	INI_WriteInt( File, "VW", garageInfo[ id ][ garageVW ] );
	INI_WriteInt( File, "Type", garageInfo[ id ][ garageType ] );
	INI_Close( File );
	return (true);
}

forward LoadGarages( id, name[], value[] );
public LoadGarages( id, name[], value[] ) {

	INI_Bool( "Owned", garageInfo[ id ][ garageOwned ] );
	INI_String( "Owner", garageInfo[ id ][ garageOwner ], MAX_PLAYER_NAME );
	INI_Int( "Price", garageInfo[ id ][ garagePrice ] );
	INI_Int( "Level", garageInfo[ id ][ garageLevel ] );
	INI_Bool( "Locked", garageInfo[ id ][ garageLocked ] );
	INI_Float( "Pos1", garageInfo[ id ][ garagePos ][ 0 ] );
	INI_Float( "Pos2", garageInfo[ id ][ garagePos ][ 1 ] );
	INI_Float( "Pos3", garageInfo[ id ][ garagePos ][ 2 ] );
	INI_Float( "VehiclePos1", garageInfo[ id ][ garageVehiclePos ][ 0 ] );
	INI_Float( "VehiclePos2", garageInfo[ id ][ garageVehiclePos ][ 1 ] );
	INI_Float( "VehiclePos3", garageInfo[ id ][ garageVehiclePos ][ 2 ] );
	INI_Float( "VehiclePos4", garageInfo[ id ][ garageVehiclePos ][ 3 ] );
	INI_Int( "VW", garageInfo[ id ][ garageVW ] );
	INI_Int( "Type", garageInfo[ id ][ garageType ] );
	return (true);
}

/////////////////////////////////gangzone////////////////////////


forward GZone_Load( id, name[], value[] );
public GZone_Load( id, name[], value[] ) {
	
	INI_Bool( "Taken", gZoneInfo[ id ][ gZoneTaken ] );
	INI_Bool( "Takeable", gZoneInfo[ id ][ gZoneTakeable ] );
	INI_Int( "GangID", gZoneInfo[ id ][ gZoneGangID ] );
	INI_Int( "Time", gZoneInfo[ id ][ gZoneTime ]);
	INI_Float( "MaxX", gZoneInfo[ id ][ gZoneMaxX ] );
	INI_Float( "MinX", gZoneInfo[ id ][ gZoneMinX ] );
	INI_Float( "MaxY", gZoneInfo[ id ][ gZoneMaxY ] );
	INI_Float( "MinY", gZoneInfo[ id ][ gZoneMinY ] );
	INI_String( "Color", gZoneInfo[ id ][ gZoneColor ], 24 );
	INI_Float( "PickupPos", gZoneInfo[ id ][ gZonePickupPos ][ 0 ] );
	INI_Float( "PickupPos2", gZoneInfo[ id ][ gZonePickupPos ][ 1 ] );
	INI_Float( "PickupPos3", gZoneInfo[ id ][ gZonePickupPos ][ 2 ] );
	//breh:jao(hads);
	return (true);
}

//////////////////////////imanja///////////////////////


forward Field_Save( id );
public Field_Save( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_FIELD, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Owned", fieldInfo[ id ][ fieldOwned ] );
	INI_WriteString( File, "Owner", fieldInfo[ id ][ fieldOwner ] );
	INI_WriteInt( File, "Price", fieldInfo[ id ][ fieldPrice ] );
	INI_WriteInt( File, "Level", fieldInfo[ id ][ fieldLevel ] );
	INI_WriteFloat( File, "MaxX", fieldInfo[ id ][ fieldMaxX ] );
	INI_WriteFloat( File, "MinX", fieldInfo[ id ][ fieldMinX ] );
	INI_WriteFloat( File, "MaxY", fieldInfo[ id ][ fieldMaxY ] );
	INI_WriteFloat( File, "MinY", fieldInfo[ id ][ fieldMinY ] );
	INI_WriteInt( File, "StalkNumber", fieldInfo[ id ][ fieldStalkNumber ] );
	INI_WriteFloat( File, "fieldObjectPosX", fieldInfo[ id ][ fieldObjectPos ][ 0 ] );
	INI_WriteFloat( File, "fieldObjectPosY", fieldInfo[ id ][ fieldObjectPos ][ 1 ] );
	INI_WriteFloat( File, "fieldObjectPosZ", fieldInfo[ id ][ fieldObjectPos ][ 2 ] );
	INI_WriteFloat( File, "fieldObjectPosRX", fieldInfo[ id ][ fieldObjectPos ][ 3 ] );
	INI_WriteFloat( File, "fieldObjectPosRY", fieldInfo[ id ][ fieldObjectPos ][ 4 ] );
	INI_WriteFloat( File, "fieldObjectPosRZ", fieldInfo[ id ][ fieldObjectPos ][ 5 ] );
	INI_WriteInt( File, "TractorID", fieldInfo[ id ][ fieldTractorID ] ); 
	INI_WriteInt( File, "AdditionID", fieldInfo[ id ][ fieldAdditionID ] );
	INI_WriteInt( File, "TruckID", fieldInfo[ id ][ fieldTruckID ] );
	INI_Close( File );
	return (true);
}

forward LoadFields( id, name[], value[] );
public LoadFields( id, name[], value[] ) {

	INI_Bool( "Owned", fieldInfo[ id ][ fieldOwned ] );
	INI_String( "Owner", fieldInfo[ id ][ fieldOwner ], MAX_PLAYER_NAME );
	INI_Int( "Price", fieldInfo[ id ][ fieldPrice ] );
	INI_Int( "Level", fieldInfo[ id ][ fieldLevel ] );
	INI_Float( "MaxX", fieldInfo[ id ][ fieldMaxX ] );
	INI_Float( "MinX", fieldInfo[ id ][ fieldMinX ] );
	INI_Float( "MaxY", fieldInfo[ id ][ fieldMaxY ] );
	INI_Float( "MinY", fieldInfo[ id ][ fieldMinY ] );
	INI_Int( "StalkNumber", fieldInfo[ id ][ fieldStalkNumber ] );
	INI_Float( "fieldObjectPosX", fieldInfo[ id ][ fieldObjectPos ][ 0 ] );
	INI_Float( "fieldObjectPosY", fieldInfo[ id ][ fieldObjectPos ][ 1 ] );
	INI_Float( "fieldObjectPosZ", fieldInfo[ id ][ fieldObjectPos ][ 2 ] );
	INI_Float( "fieldObjectPosRX", fieldInfo[ id ][ fieldObjectPos ][ 3 ] );
	INI_Float( "fieldObjectPosRY", fieldInfo[ id ][ fieldObjectPos ][ 4 ] );
	INI_Float( "fieldObjectPosRZ", fieldInfo[ id ][ fieldObjectPos ][ 5 ] );
	INI_Int( "TractorID", fieldInfo[ id ][ fieldTractorID ] ); 
	INI_Int( "AdditionID", fieldInfo[ id ][ fieldAdditionID ] );
	INI_Int( "TruckID", fieldInfo[ id ][ fieldTruckID ] );
	return (true);
}

forward LoadStalks( id, name[], value[] );
public LoadStalks( id, name[], value[] ) {

	INI_Int( "fieldID", stalkInfo[ id ][ sfieldID ] );
	INI_Int( "ObjectID", stalkInfo[ id ][ sObjectID ] );
	INI_Float( "Pos1", stalkInfo[ id ][ sPos ][ 0 ] );
	INI_Float( "Pos2", stalkInfo[ id ][ sPos ][ 1 ] );
	INI_Float( "Pos3", stalkInfo[ id ][ sPos ][ 2 ] );
	INI_Bool( "Planted", stalkInfo[ id ][ sPlanted ] );
	INI_Bool( "Grow", stalkInfo[ id ][ sGrow ] );
	INI_Int( "Type", stalkInfo[ id ][ sType ] );
	INI_Int( "Minut", stalkInfo[ id ][ sMinut ] );
	INI_Int( "Hour", stalkInfo[ id ][ sHour ] );
	return (true);
}

forward Stalk_Save( id );
public Stalk_Save( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_STALK, id );
	new INI:File = INI_Open( iFile );
	INI_WriteInt( File, "fieldID", stalkInfo[ id ][ sfieldID ] );
	INI_WriteInt( File, "ObjectID", stalkInfo[ id ][ sObjectID ] );
	INI_WriteFloat( File, "Pos1", stalkInfo[ id ][ sPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", stalkInfo[ id ][ sPos ][ 1 ] );
	INI_WriteFloat( File,"Pos3", stalkInfo[ id ][ sPos ][ 2 ] );
	INI_WriteBool( File, "Planted", stalkInfo[ id ][ sPlanted ] );
	INI_WriteBool( File, "Grow", stalkInfo[ id ][ sGrow ] );
	INI_WriteInt( File, "Type", stalkInfo[ id ][ sType ] );
	INI_WriteInt( File, "Minut", stalkInfo[ id ][ sMinut ] );
	INI_WriteInt( File, "Hour", stalkInfo[ id ][ sHour ] );
	INI_Close( File );
	return (true);
}

////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
public LoadEvent(id, name[], value[])
{
	new string[6];
	INI_String( "Name", Event[ id ][ Name ], 64 );
	INI_Float( "TCPX", Event[ id ][ TCPX ] );
	INI_Float( "TCPY", Event[ id ][ TCPY ] );
	INI_Float( "TCPZ", Event[ id ][ TCPZ ] );
	INI_Float( "TCPA", Event[ id ][ TCPA ] );
	INI_Float( "TCPX2", Event[ id ][ TCPX2 ] );
	INI_Float( "TCPY2", Event[ id ][ TCPY2 ] );
	INI_Float( "TCPZ2", Event[ id ][ TCPZ2 ] );
	INI_Float( "TCPA2", Event[ id ][ TCPA2 ] );
	INI_Int( "Veh", Event[ id ][ VehID ] );
	for( new i = 2; i <= MAX_CP; i++)
	{
		format( string, 6, "CPX%d",i);
		INI_Float( string, CheckPoint[ id ][ i ][ CPX ] );
		format( string, 6,"CPY%d",i);
		INI_Float( string, CheckPoint[ id ][ i ][ CPY ] );
		format( string, 6, "CPZ%d",i);
		INI_Float( string, CheckPoint[ id ][ i ][ CPZ ] );
	}
	INI_Int( "MaxCP", Event[ id ][ MaxCP ] );
	return 1;
}
//------------------------------------------------------------------------------
public OcitajKont( id, name[], value[] )
{
	INI_Float( "ObjPos1", KontInfo[ id ][ koObjPos ][ 0 ] );
	INI_Float( "ObjPos2", KontInfo[ id ][ koObjPos ][ 1 ] );
	INI_Float( "ObjPos3", KontInfo[ id ][ koObjPos ][ 2 ] );
	INI_Float( "ObjRot1", KontInfo[ id ][ koObjRot ][ 0 ] );
	INI_Float( "ObjRot2", KontInfo[ id ][ koObjRot ][ 1 ] );
	INI_Float( "ObjRot3", KontInfo[ id ][ koObjRot ][ 2 ] );
	return true;
}
//------------------------------------------------------------------------------
public LoadATM( id, name[], value[] )
{
	INI_Float( "atmPos1", atmInfo[ id ][ atmPos ][ 0 ] );
	INI_Float( "atmPos2", atmInfo[ id ][ atmPos ][ 1 ] );
	INI_Float( "atmPos3", atmInfo[ id ][ atmPos ][ 2 ] );
	INI_Float( "atmPos4", atmInfo[ id ][ atmPos ][ 3 ] );
	INI_Float( "atmPos5", atmInfo[ id ][ atmPos ][ 4 ] );
	INI_Float( "atmPos6", atmInfo[ id ][ atmPos ][ 5 ] );
	INI_Bool( "atmPreseceneZice", atmInfo[ id ][ atmPreseceneZice ] );
	INI_Bool( "atmProbijenBios", atmInfo[ id ][ atmProbijenBios ] );
	INI_Int( "atmVremeDoRoba", atmInfo[ id ][ atmVremeDoRoba ] );
	INI_Bool( "atmExists", atmInfo[ id ][ atmExists ] );
	return true;
}
//------------------------------------------------------------------------------
public SacuvajKont( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), KO_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "ObjPos1", KontInfo[ id ][ koObjPos ][ 0 ] );
	INI_WriteFloat( File, "ObjPos2", KontInfo[ id ][ koObjPos ][ 1 ] );
	INI_WriteFloat( File, "ObjPos3", KontInfo[ id ][ koObjPos ][ 2 ] );
	INI_WriteFloat( File, "ObjRot1", KontInfo[ id ][ koObjRot ][ 0 ] );
	INI_WriteFloat( File, "ObjRot2", KontInfo[ id ][ koObjRot ][ 1 ] );
	INI_WriteFloat( File, "ObjRot3", KontInfo[ id ][ koObjRot ][ 2 ] );
	INI_Close( File );
	return true;
}//------------------------------------------------------------------------------
forward OcitajMrtvoTelo( id, name[], value[] );
public OcitajMrtvoTelo( id, name[], value[] )
{
	INI_Float( "ObjPos1", bodyInfo[ id ][ bodyObjPos ][ 0 ] );
	INI_Float( "ObjPos2", bodyInfo[ id ][ bodyObjPos ][ 1 ] );
	INI_Float( "ObjPos3", bodyInfo[ id ][ bodyObjPos ][ 2 ] );
	INI_String( "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ], IME_IGRACA_DUZINA_STRINGA);
	return true;
}
forward SacuvajMrtvoTelo( id );
public SacuvajMrtvoTelo( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), BODY_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "ObjPos1", bodyInfo[ id ][ bodyObjPos ][ 0 ] );
	INI_WriteFloat( File, "ObjPos2", bodyInfo[ id ][ bodyObjPos ][ 1 ] );
	INI_WriteFloat( File, "ObjPos3", bodyInfo[ id ][ bodyObjPos ][ 2 ] );
	INI_WriteString( File, "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ]);
	INI_Close( File );
	return true;
}
//------------------------------------------------------------------------------
public SacuvajATM( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), ATM_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "atmPos1", atmInfo[ id ][ atmPos ][ 0 ] );
	INI_WriteFloat( File, "atmPos2", atmInfo[ id ][ atmPos ][ 1 ] );
	INI_WriteFloat( File, "atmPos3", atmInfo[ id ][ atmPos ][ 2 ] );
	INI_WriteFloat( File, "atmPos4", atmInfo[ id ][ atmPos ][ 3 ] );
	INI_WriteFloat( File, "atmPos5", atmInfo[ id ][ atmPos ][ 4 ] );
	INI_WriteFloat( File, "atmPos6", atmInfo[ id ][ atmPos ][ 5 ] );
	INI_WriteBool( File, "atmPreseceneZice", atmInfo[ id ][ atmPreseceneZice ] );
	INI_WriteBool( File, "atmProbijenBios", atmInfo[ id ][ atmProbijenBios ] );
	INI_WriteInt( File, "atmVremeDoRoba", atmInfo[ id ][ atmVremeDoRoba ] );
	INI_WriteBool( File, "atmExists", atmInfo[ id ][ atmExists ] );
	INI_Close( File );
	return true;
}
//------------------------------------------------------------------------------
forward LoadRadar( radarID, name[], value[] );
public LoadRadar( radarID, name[], value[] ) {

	INI_Int( "MaxSpeed", radarInfo[ radarID ][ radarMaxSpeed ] );
	INI_Int( "Price", radarInfo[ radarID ][ radarPrice ] );
	INI_Float( "Pos1", radarInfo[ radarID ][ radarPos ][ 0 ] );
	INI_Float( "Pos2", radarInfo[ radarID ][ radarPos ][ 1 ] );
	INI_Float( "Pos3", radarInfo[ radarID ][ radarPos ][ 2 ] );
	INI_Float( "Pos4", radarInfo[ radarID ][ radarPos ][ 3 ] );
	INI_Float( "Pos5", radarInfo[ radarID ][ radarPos ][ 4 ] );
	INI_Float( "Pos6", radarInfo[ radarID ][ radarPos ][ 5 ] );
	
	return true;
}

////////////////////////////////firme//////////////////////////////

//------------------------------------------------------------------------------
public OcitajFirmu(idx, name[], value[])
{
	INI_Int( "Kupljen", BussinesInfo[ idx ][bOwned] );
	INI_Int( "Cena", BussinesInfo[ idx ][ bPrice] );
	INI_String( "Vlasnik", BussinesInfo[ idx ][ bOwner], MAX_PLAYER_NAME);
	INI_Int( "Tip", BussinesInfo[ idx ][ bType] );
	INI_Int( "Zakljucana", BussinesInfo[ idx ][ bLocked] );
	INI_Int( "Novac", BussinesInfo[ idx ][ bMoney] );
	INI_Float( "UlazX", BussinesInfo[ idx ][ bEnterX] );
	INI_Float( "UlazY", BussinesInfo[ idx ][ bEnterY] );
	INI_Float( "UlazZ", BussinesInfo[ idx ][ bEnterZ] );
	INI_Float( "IzasaoX", BussinesInfo[ idx ][ bExitX] );
	INI_Float( "IzasaoY", BussinesInfo[ idx ][ bExitY] );
	INI_Float( "IzasaoZ", BussinesInfo[ idx ][ bExitZ] );
	INI_Int( "Int", BussinesInfo[ idx ][ bInt] );
	INI_Int( "VW", BussinesInfo[ idx ][ bVW] );
	INI_Int( "Uinterioru", BussinesInfo[ idx ][ bInInt] );
	INI_Int( "Uvw", BussinesInfo[ idx ][ bInVW] );
	INI_String( "Ime", BussinesInfo[ idx ][ bName ], 64 );
	INI_Int( "Level", BussinesInfo[ idx ][ bLevel ] );
	INI_Int( "JobID", BussinesInfo[ idx ][ bJobID ] );
	INI_Int( "Neaktivnost", BussinesInfo[ idx ][ bNeaktivnost ] );
	INI_Int( "Facture", BussinesInfo[ idx ][ bFacture ] );
	INI_Int( "Reket", BussinesInfo[ idx ][ bReket ] );
	INI_Float( "ReketTime", BussinesInfo[ idx ][ bReketTime ] );
	return true;
}
//------------------------------------------------------------------------------
public SaveBussines( id ) {
	new file4[ 40 ];
	format( file4, sizeof( file4 ), F_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_SetTag( File, "Informacije");
	INI_WriteInt( File, "Kupljen", BussinesInfo[ id ][ bOwned] );
	INI_WriteInt( File, "Cena", BussinesInfo[ id ][ bPrice] );
	INI_WriteString( File, "Vlasnik", BussinesInfo[ id ][ bOwner] );
	INI_WriteInt( File, "Tip", BussinesInfo[ id ][ bType] );
	INI_WriteInt( File, "Zakljucana", BussinesInfo[ id ][ bLocked] );
	INI_WriteInt( File, "Novac", BussinesInfo[ id ][ bMoney] );
	INI_WriteFloat( File, "UlazX", BussinesInfo[ id ][ bEnterX] );
	INI_WriteFloat( File, "UlazY", BussinesInfo[ id ][ bEnterY] );
	INI_WriteFloat( File, "UlazZ", BussinesInfo[ id ][ bEnterZ] );
	INI_WriteFloat( File, "IzasaoX", BussinesInfo[ id ][ bExitX] );
	INI_WriteFloat( File, "IzasaoY", BussinesInfo[ id ][ bExitY] );
	INI_WriteFloat( File, "IzasaoZ", BussinesInfo[ id ][ bExitZ] );
	INI_WriteInt( File, "Int", BussinesInfo[ id ][ bInt] );
	INI_WriteInt( File, "VW", BussinesInfo[ id ][ bVW] );
	INI_WriteInt( File, "Uinterioru", BussinesInfo[ id ][ bInInt] );
	INI_WriteInt( File, "Uvw", BussinesInfo[ id ][ bInVW] );
	INI_WriteString( File, "Ime", BussinesInfo[ id ][ bName] );
	INI_WriteInt( File, "Level", BussinesInfo[ id ][ bLevel ] );
	INI_WriteInt( File, "JobID", BussinesInfo[ id ][ bJobID ] );
	INI_WriteInt( File, "Neaktivnost", BussinesInfo[ id ][ bNeaktivnost ] );
	INI_WriteInt( File, "Facture", BussinesInfo[ id ][ bFacture ] );
	INI_WriteInt( File, "Reket", BussinesInfo[ id ][ bReket ] );
	INI_WriteFloat( File, "ReketTime", BussinesInfo[ id ][ bReketTime ] );
	INI_Close( File );
	return true;
}

//////////////////////////////Salon////////////////////////////


//------------------------------------------------------------------------------
forward SaveSalon( id );
public SaveSalon( id )
{
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), AS_FILE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteInt( File, "MaxVehModel", AutoSalon[ id ][ aMaxVehModel ] );
	INI_WriteInt( File, "VehModel1", AutoSalon[ id ][ aVehModel ][ 0 ] );
	INI_WriteInt( File, "VehModel2", AutoSalon[ id ][ aVehModel ][ 1 ] );
	INI_WriteInt( File, "VehModel3", AutoSalon[ id ][ aVehModel ][ 2 ] );
	INI_WriteInt( File, "VehModel4", AutoSalon[ id ][ aVehModel ][ 3 ] );
	INI_WriteInt( File, "VehModel5", AutoSalon[ id ][ aVehModel ][ 4 ] );
	INI_WriteInt( File, "VehModel6", AutoSalon[ id ][ aVehModel ][ 5 ] );
	INI_WriteInt( File, "VehModel7", AutoSalon[ id ][ aVehModel ][ 6 ] );
	INI_WriteInt( File, "VehModel8", AutoSalon[ id ][ aVehModel ][ 7 ] );
	INI_WriteInt( File, "VehModel9", AutoSalon[ id ][ aVehModel ][ 8 ] );
	INI_WriteInt( File, "VehModel10", AutoSalon[ id ][ aVehModel ][ 9 ] );
	INI_WriteInt( File, "VehModel11", AutoSalon[ id ][ aVehModel ][ 10 ] );
	INI_WriteInt( File, "VehModel12", AutoSalon[ id ][ aVehModel ][ 11 ] );
	INI_WriteInt( File, "VehModel13", AutoSalon[ id ][ aVehModel ][ 12 ] );
	INI_WriteInt( File, "VehModel14", AutoSalon[ id ][ aVehModel ][ 13 ] );
	INI_WriteInt( File, "VehModel15", AutoSalon[ id ][ aVehModel ][ 14 ] );
	INI_WriteInt( File, "VehModel16", AutoSalon[ id ][ aVehModel ][ 15 ] );
	INI_WriteInt( File, "VehModel17", AutoSalon[ id ][ aVehModel ][ 16 ] );
	INI_WriteInt( File, "VehModel18", AutoSalon[ id ][ aVehModel ][ 17 ] );
	INI_WriteInt( File, "VehModel19", AutoSalon[ id ][ aVehModel ][ 18 ] );
	INI_WriteInt( File, "VehModel20", AutoSalon[ id ][ aVehModel ][ 19 ] );
	INI_WriteInt( File, "VehModel21", AutoSalon[ id ][ aVehModel ][ 20 ] );
	INI_WriteInt( File, "VehModel22", AutoSalon[ id ][ aVehModel ][ 21 ] );
	INI_WriteInt( File, "VehModel23", AutoSalon[ id ][ aVehModel ][ 22 ] );
	INI_WriteInt( File, "VehModel24", AutoSalon[ id ][ aVehModel ][ 23 ] );
	INI_WriteInt( File, "VehModel25", AutoSalon[ id ][ aVehModel ][ 24 ] );
	INI_WriteInt( File, "VehModel26", AutoSalon[ id ][ aVehModel ][ 25 ] );
	INI_WriteInt( File, "VehModel27", AutoSalon[ id ][ aVehModel ][ 26 ] );
	INI_WriteInt( File, "VehModel28", AutoSalon[ id ][ aVehModel ][ 27 ] );
	INI_WriteInt( File, "VehModel29", AutoSalon[ id ][ aVehModel ][ 28 ] );
	INI_WriteInt( File, "VehModel30", AutoSalon[ id ][ aVehModel ][ 29 ] );
	INI_WriteInt( File, "VehModel31", AutoSalon[ id ][ aVehModel ][ 30 ] );
	INI_WriteInt( File, "VehModel32", AutoSalon[ id ][ aVehModel ][ 31 ] );
	INI_WriteInt( File, "VehModel33", AutoSalon[ id ][ aVehModel ][ 32 ] );
	INI_WriteInt( File, "VehModel34", AutoSalon[ id ][ aVehModel ][ 33 ] );
	INI_WriteInt( File, "VehModel35", AutoSalon[ id ][ aVehModel ][ 34 ] );
	INI_WriteInt( File, "VehModel36", AutoSalon[ id ][ aVehModel ][ 35 ] );
	INI_WriteInt( File, "VehModel37", AutoSalon[ id ][ aVehModel ][ 36 ] );
	INI_WriteInt( File, "VehModel38", AutoSalon[ id ][ aVehModel ][ 37 ] );
	INI_WriteInt( File, "VehModel39", AutoSalon[ id ][ aVehModel ][ 38 ] );
	INI_WriteInt( File, "VehModel40", AutoSalon[ id ][ aVehModel ][ 39 ] );
	INI_WriteInt( File, "VehModel41", AutoSalon[ id ][ aVehModel ][ 40 ] );
	INI_WriteInt( File, "VehModel42", AutoSalon[ id ][ aVehModel ][ 41 ] );
	INI_WriteInt( File, "VehModel43", AutoSalon[ id ][ aVehModel ][ 42 ] );
	INI_WriteInt( File, "VehModel44", AutoSalon[ id ][ aVehModel ][ 43 ] );
	INI_WriteInt( File, "VehModel45", AutoSalon[ id ][ aVehModel ][ 44 ] );
	INI_WriteInt( File, "VehModel46", AutoSalon[ id ][ aVehModel ][ 45 ] );
	INI_WriteInt( File, "VehModel47", AutoSalon[ id ][ aVehModel ][ 46 ] );
	INI_WriteInt( File, "VehModel48", AutoSalon[ id ][ aVehModel ][ 47 ] );
	INI_WriteInt( File, "VehModel49", AutoSalon[ id ][ aVehModel ][ 48 ] );
	INI_WriteInt( File, "VehModel50", AutoSalon[ id ][ aVehModel ][ 49 ] );
	
	INI_WriteInt( File, "VehAmmount1", AutoSalon[ id ][ aVehAmmount ][ 0 ] );
	INI_WriteInt( File, "VehAmmount2", AutoSalon[ id ][ aVehAmmount ][ 1 ] );
	INI_WriteInt( File, "VehAmmount3", AutoSalon[ id ][ aVehAmmount ][ 2 ] );
	INI_WriteInt( File, "VehAmmount4", AutoSalon[ id ][ aVehAmmount ][ 3 ] );
	INI_WriteInt( File, "VehAmmount5", AutoSalon[ id ][ aVehAmmount ][ 4 ] );
	INI_WriteInt( File, "VehAmmount6", AutoSalon[ id ][ aVehAmmount ][ 5 ] );
	INI_WriteInt( File, "VehAmmount7", AutoSalon[ id ][ aVehAmmount ][ 6 ] );
	INI_WriteInt( File, "VehAmmount8", AutoSalon[ id ][ aVehAmmount ][ 7 ] );
	INI_WriteInt( File, "VehAmmount9", AutoSalon[ id ][ aVehAmmount ][ 8 ] );
	INI_WriteInt( File, "VehAmmount10", AutoSalon[ id ][ aVehAmmount ][ 9 ] );
	INI_WriteInt( File, "VehAmmount11", AutoSalon[ id ][ aVehAmmount ][ 10 ] );
	INI_WriteInt( File, "VehAmmount12", AutoSalon[ id ][ aVehAmmount ][ 11 ] );
	INI_WriteInt( File, "VehAmmount13", AutoSalon[ id ][ aVehAmmount ][ 12 ] );
	INI_WriteInt( File, "VehAmmount14", AutoSalon[ id ][ aVehAmmount ][ 13 ] );
	INI_WriteInt( File, "VehAmmount15", AutoSalon[ id ][ aVehAmmount ][ 14 ] );
	INI_WriteInt( File, "VehAmmount16", AutoSalon[ id ][ aVehAmmount ][ 15 ] );
	INI_WriteInt( File, "VehAmmount17", AutoSalon[ id ][ aVehAmmount ][ 16 ] );
	INI_WriteInt( File, "VehAmmount18", AutoSalon[ id ][ aVehAmmount ][ 17 ] );
	INI_WriteInt( File, "VehAmmount19", AutoSalon[ id ][ aVehAmmount ][ 18 ] );
	INI_WriteInt( File, "VehAmmount20", AutoSalon[ id ][ aVehAmmount ][ 19 ] );
	INI_WriteInt( File, "VehAmmount21", AutoSalon[ id ][ aVehAmmount ][ 20 ] );
	INI_WriteInt( File, "VehAmmount22", AutoSalon[ id ][ aVehAmmount ][ 21 ] );
	INI_WriteInt( File, "VehAmmount23", AutoSalon[ id ][ aVehAmmount ][ 22 ] );
	INI_WriteInt( File, "VehAmmount24", AutoSalon[ id ][ aVehAmmount ][ 23 ] );
	INI_WriteInt( File, "VehAmmount25", AutoSalon[ id ][ aVehAmmount ][ 24 ] );
	INI_WriteInt( File, "VehAmmount26", AutoSalon[ id ][ aVehAmmount ][ 25 ] );
	INI_WriteInt( File, "VehAmmount27", AutoSalon[ id ][ aVehAmmount ][ 26 ] );
	INI_WriteInt( File, "VehAmmount28", AutoSalon[ id ][ aVehAmmount ][ 27 ] );
	INI_WriteInt( File, "VehAmmount29", AutoSalon[ id ][ aVehAmmount ][ 28 ] );
	INI_WriteInt( File, "VehAmmount30", AutoSalon[ id ][ aVehAmmount ][ 29 ] );
	INI_WriteInt( File, "VehAmmount31", AutoSalon[ id ][ aVehAmmount ][ 30 ] );
	INI_WriteInt( File, "VehAmmount32", AutoSalon[ id ][ aVehAmmount ][ 31 ] );
	INI_WriteInt( File, "VehAmmount33", AutoSalon[ id ][ aVehAmmount ][ 32 ] );
	INI_WriteInt( File, "VehAmmount34", AutoSalon[ id ][ aVehAmmount ][ 33 ] );
	INI_WriteInt( File, "VehAmmount35", AutoSalon[ id ][ aVehAmmount ][ 34 ] );
	INI_WriteInt( File, "VehAmmount36", AutoSalon[ id ][ aVehAmmount ][ 35 ] );
	INI_WriteInt( File, "VehAmmount37", AutoSalon[ id ][ aVehAmmount ][ 36 ] );
	INI_WriteInt( File, "VehAmmount38", AutoSalon[ id ][ aVehAmmount ][ 37 ] );
	INI_WriteInt( File, "VehAmmount39", AutoSalon[ id ][ aVehAmmount ][ 38 ] );
	INI_WriteInt( File, "VehAmmount40", AutoSalon[ id ][ aVehAmmount ][ 39 ] );
	INI_WriteInt( File, "VehAmmount41", AutoSalon[ id ][ aVehAmmount ][ 40 ] );
	INI_WriteInt( File, "VehAmmount42", AutoSalon[ id ][ aVehAmmount ][ 41 ] );
	INI_WriteInt( File, "VehAmmount43", AutoSalon[ id ][ aVehAmmount ][ 42 ] );
	INI_WriteInt( File, "VehAmmount44", AutoSalon[ id ][ aVehAmmount ][ 43 ] );
	INI_WriteInt( File, "VehAmmount45", AutoSalon[ id ][ aVehAmmount ][ 44 ] );
	INI_WriteInt( File, "VehAmmount46", AutoSalon[ id ][ aVehAmmount ][ 45 ] );
	INI_WriteInt( File, "VehAmmount47", AutoSalon[ id ][ aVehAmmount ][ 46 ] );
	INI_WriteInt( File, "VehAmmount48", AutoSalon[ id ][ aVehAmmount ][ 47 ] );
	INI_WriteInt( File, "VehAmmount49", AutoSalon[ id ][ aVehAmmount ][ 48 ] );
	INI_WriteInt( File, "VehAmmount50", AutoSalon[ id ][ aVehAmmount ][ 49 ] );
	
	INI_WriteFloat( File, "VehBuyedPosX", AutoSalon[ id ][ aVehBuyedPos ][ 0 ] );
	INI_WriteFloat( File, "VehBuyedPosY", AutoSalon[ id ][ aVehBuyedPos ][ 1 ] );
	INI_WriteFloat( File, "VehBuyedPosZ", AutoSalon[ id ][ aVehBuyedPos ][ 2 ] );
	INI_WriteFloat( File, "VehBuyedPosA", AutoSalon[ id ][ aVehBuyedPos ][ 3 ] );
	INI_WriteFloat( File, "PickupPosX", AutoSalon[ id ][ aPickupPos ][ 0 ] );
	INI_WriteFloat( File, "PickupPosY", AutoSalon[ id ][ aPickupPos ][ 1 ] );
	INI_WriteFloat( File, "PickupPosZ", AutoSalon[ id ][ aPickupPos ][ 2 ] );
	INI_WriteFloat( File, "CameraPosX", AutoSalon[ id ][ aCameraPos ][ 0 ] );
	INI_WriteFloat( File, "CameraPosY", AutoSalon[ id ][ aCameraPos ][ 1 ] );
	INI_WriteFloat( File, "CameraPosZ", AutoSalon[ id ][ aCameraPos ][ 2 ] );
	INI_WriteFloat( File, "CameraLookAtX", AutoSalon[ id ][ aCameraLookAt ][ 0 ] );
	INI_WriteFloat( File, "CameraLookAtY", AutoSalon[ id ][ aCameraLookAt ][ 1 ] );
	INI_WriteFloat( File, "CameraLookAtZ", AutoSalon[ id ][ aCameraLookAt ][ 2 ] );
	INI_WriteInt( File, "VirtualW", AutoSalon[ id ][ aVW ] );
	INI_WriteInt( File, "Interior", AutoSalon[ id ][ aInt ] );
	INI_WriteInt( File, "IzlogVeh", AutoSalon[ id ][ aIzlogVeh ] );
	INI_Close( File );
	return 1;
}
//------------------------------------------------------------------------------
forward LoadSalon( id, name[], value[] );
public LoadSalon( id, name[], value[] )
{
	INI_Int( "MaxVehModel", AutoSalon[ id ][ aMaxVehModel ] );
	INI_Int( "VehModel1", AutoSalon[ id ][ aVehModel ][ 0 ] );
	INI_Int( "VehModel2", AutoSalon[ id ][ aVehModel ][ 1 ] );
	INI_Int( "VehModel3", AutoSalon[ id ][ aVehModel ][ 2 ] );
	INI_Int( "VehModel4", AutoSalon[ id ][ aVehModel ][ 3 ] );
	INI_Int( "VehModel5", AutoSalon[ id ][ aVehModel ][ 4 ] );
	INI_Int( "VehModel6", AutoSalon[ id ][ aVehModel ][ 5 ] );
	INI_Int( "VehModel7", AutoSalon[ id ][ aVehModel ][ 6 ] );
	INI_Int( "VehModel8", AutoSalon[ id ][ aVehModel ][ 7 ] );
	INI_Int( "VehModel9", AutoSalon[ id ][ aVehModel ][ 8 ] );
	INI_Int( "VehModel10", AutoSalon[ id ][ aVehModel ][ 9 ] );
	INI_Int( "VehModel11", AutoSalon[ id ][ aVehModel ][ 10 ] );
	INI_Int( "VehModel12", AutoSalon[ id ][ aVehModel ][ 11 ] );
	INI_Int( "VehModel13", AutoSalon[ id ][ aVehModel ][ 12 ] );
	INI_Int( "VehModel14", AutoSalon[ id ][ aVehModel ][ 13 ] );
	INI_Int( "VehModel15", AutoSalon[ id ][ aVehModel ][ 14 ] );
	INI_Int( "VehModel16", AutoSalon[ id ][ aVehModel ][ 15 ] );
	//
	INI_Int( "VehModel17", AutoSalon[ id ][ aVehModel ][ 16 ] );
	INI_Int( "VehModel18", AutoSalon[ id ][ aVehModel ][ 17 ] );
	INI_Int( "VehModel19", AutoSalon[ id ][ aVehModel ][ 18 ] );
	INI_Int( "VehModel20", AutoSalon[ id ][ aVehModel ][ 19 ] );
	INI_Int( "VehModel21", AutoSalon[ id ][ aVehModel ][ 20 ] );
	INI_Int( "VehModel22", AutoSalon[ id ][ aVehModel ][ 21 ] );
	INI_Int( "VehModel23", AutoSalon[ id ][ aVehModel ][ 22 ] );
	INI_Int( "VehModel24", AutoSalon[ id ][ aVehModel ][ 23 ] );
	INI_Int( "VehModel25", AutoSalon[ id ][ aVehModel ][ 24 ] );
	INI_Int( "VehModel26", AutoSalon[ id ][ aVehModel ][ 25 ] );
	INI_Int( "VehModel27", AutoSalon[ id ][ aVehModel ][ 26 ] );
	INI_Int( "VehModel28", AutoSalon[ id ][ aVehModel ][ 27 ] );
	INI_Int( "VehModel29", AutoSalon[ id ][ aVehModel ][ 28 ] );
	INI_Int( "VehModel30", AutoSalon[ id ][ aVehModel ][ 29 ] );
	INI_Int( "VehModel31", AutoSalon[ id ][ aVehModel ][ 30 ] );
	INI_Int( "VehModel32", AutoSalon[ id ][ aVehModel ][ 31 ] );
	INI_Int( "VehModel33", AutoSalon[ id ][ aVehModel ][ 32 ] );
	INI_Int( "VehModel34", AutoSalon[ id ][ aVehModel ][ 33 ] );
	INI_Int( "VehModel35", AutoSalon[ id ][ aVehModel ][ 34 ] );
	INI_Int( "VehModel36", AutoSalon[ id ][ aVehModel ][ 35 ] );
	INI_Int( "VehModel37", AutoSalon[ id ][ aVehModel ][ 36 ] );
	INI_Int( "VehModel38", AutoSalon[ id ][ aVehModel ][ 37 ] );
	INI_Int( "VehModel39", AutoSalon[ id ][ aVehModel ][ 38 ] );
	INI_Int( "VehModel40", AutoSalon[ id ][ aVehModel ][ 39 ] );
	INI_Int( "VehModel41", AutoSalon[ id ][ aVehModel ][ 40 ] );
	INI_Int( "VehModel42", AutoSalon[ id ][ aVehModel ][ 41 ] );
	INI_Int( "VehModel43", AutoSalon[ id ][ aVehModel ][ 42 ] );
	INI_Int( "VehModel44", AutoSalon[ id ][ aVehModel ][ 43 ] );
	INI_Int( "VehModel45", AutoSalon[ id ][ aVehModel ][ 44 ] );
	INI_Int( "VehModel46", AutoSalon[ id ][ aVehModel ][ 45 ] );
	INI_Int( "VehModel47", AutoSalon[ id ][ aVehModel ][ 46 ] );
	INI_Int( "VehModel48", AutoSalon[ id ][ aVehModel ][ 47 ] );
	INI_Int( "VehModel49", AutoSalon[ id ][ aVehModel ][ 48 ] );
	INI_Int( "VehModel50", AutoSalon[ id ][ aVehModel ][ 49 ] );
	
	INI_Int( "VehAmmount1", AutoSalon[ id ][ aVehAmmount ][ 0 ] );
	INI_Int( "VehAmmount2", AutoSalon[ id ][ aVehAmmount ][ 1 ] );
	INI_Int( "VehAmmount3", AutoSalon[ id ][ aVehAmmount ][ 2 ] );
	INI_Int( "VehAmmount4", AutoSalon[ id ][ aVehAmmount ][ 3 ] );
	INI_Int( "VehAmmount5", AutoSalon[ id ][ aVehAmmount ][ 4 ] );
	INI_Int( "VehAmmount6", AutoSalon[ id ][ aVehAmmount ][ 5 ] );
	INI_Int( "VehAmmount7", AutoSalon[ id ][ aVehAmmount ][ 6 ] );
	INI_Int( "VehAmmount8", AutoSalon[ id ][ aVehAmmount ][ 7 ] );
	INI_Int( "VehAmmount9", AutoSalon[ id ][ aVehAmmount ][ 8 ] );
	INI_Int( "VehAmmount10", AutoSalon[ id ][ aVehAmmount ][ 9 ] );
	INI_Int( "VehAmmount11", AutoSalon[ id ][ aVehAmmount ][ 10 ] );
	INI_Int( "VehAmmount12", AutoSalon[ id ][ aVehAmmount ][ 11 ] );
	INI_Int( "VehAmmount13", AutoSalon[ id ][ aVehAmmount ][ 12 ] );
	INI_Int( "VehAmmount14", AutoSalon[ id ][ aVehAmmount ][ 13 ] );
	INI_Int( "VehAmmount15", AutoSalon[ id ][ aVehAmmount ][ 14 ] );
	INI_Int( "VehAmmount16", AutoSalon[ id ][ aVehAmmount ][ 15 ] );
	INI_Int( "VehAmmount17", AutoSalon[ id ][ aVehAmmount ][ 16 ] );
	INI_Int( "VehAmmount18", AutoSalon[ id ][ aVehAmmount ][ 17 ] );
	INI_Int( "VehAmmount19", AutoSalon[ id ][ aVehAmmount ][ 18 ] );
	INI_Int( "VehAmmount20", AutoSalon[ id ][ aVehAmmount ][ 19 ] );
	INI_Int( "VehAmmount21", AutoSalon[ id ][ aVehAmmount ][ 20 ] );
	INI_Int( "VehAmmount22", AutoSalon[ id ][ aVehAmmount ][ 21 ] );
	INI_Int( "VehAmmount23", AutoSalon[ id ][ aVehAmmount ][ 22 ] );
	INI_Int( "VehAmmount24", AutoSalon[ id ][ aVehAmmount ][ 23 ] );
	INI_Int( "VehAmmount25", AutoSalon[ id ][ aVehAmmount ][ 24 ] );
	INI_Int( "VehAmmount26", AutoSalon[ id ][ aVehAmmount ][ 25 ] );
	INI_Int( "VehAmmount27", AutoSalon[ id ][ aVehAmmount ][ 26 ] );
	INI_Int( "VehAmmount28", AutoSalon[ id ][ aVehAmmount ][ 27 ] );
	INI_Int( "VehAmmount29", AutoSalon[ id ][ aVehAmmount ][ 28 ] );
	INI_Int( "VehAmmount30", AutoSalon[ id ][ aVehAmmount ][ 29 ] );
	INI_Int( "VehAmmount31", AutoSalon[ id ][ aVehAmmount ][ 30 ] );
	INI_Int( "VehAmmount32", AutoSalon[ id ][ aVehAmmount ][ 31 ] );
	INI_Int( "VehAmmount33", AutoSalon[ id ][ aVehAmmount ][ 32 ] );
	INI_Int( "VehAmmount34", AutoSalon[ id ][ aVehAmmount ][ 33 ] );
	INI_Int( "VehAmmount35", AutoSalon[ id ][ aVehAmmount ][ 34 ] );
	INI_Int( "VehAmmount36", AutoSalon[ id ][ aVehAmmount ][ 35 ] );
	INI_Int( "VehAmmount37", AutoSalon[ id ][ aVehAmmount ][ 36 ] );
	INI_Int( "VehAmmount38", AutoSalon[ id ][ aVehAmmount ][ 37 ] );
	INI_Int( "VehAmmount39", AutoSalon[ id ][ aVehAmmount ][ 38 ] );
	INI_Int( "VehAmmount40", AutoSalon[ id ][ aVehAmmount ][ 39 ] );
	INI_Int( "VehAmmount41", AutoSalon[ id ][ aVehAmmount ][ 40 ] );
	INI_Int( "VehAmmount42", AutoSalon[ id ][ aVehAmmount ][ 41 ] );
	INI_Int( "VehAmmount43", AutoSalon[ id ][ aVehAmmount ][ 42 ] );
	INI_Int( "VehAmmount44", AutoSalon[ id ][ aVehAmmount ][ 43 ] );
	INI_Int( "VehAmmount45", AutoSalon[ id ][ aVehAmmount ][ 44 ] );
	INI_Int( "VehAmmount46", AutoSalon[ id ][ aVehAmmount ][ 45 ] );
	INI_Int( "VehAmmount47", AutoSalon[ id ][ aVehAmmount ][ 46 ] );
	INI_Int( "VehAmmount48", AutoSalon[ id ][ aVehAmmount ][ 47 ] );
	INI_Int( "VehAmmount49", AutoSalon[ id ][ aVehAmmount ][ 48 ] );
	INI_Int( "VehAmmount50", AutoSalon[ id ][ aVehAmmount ][ 49 ] );
	
	INI_Float( "VehBuyedPosX", AutoSalon[ id ][ aVehBuyedPos ][ 0 ] );
	INI_Float( "VehBuyedPosY", AutoSalon[ id ][ aVehBuyedPos ][ 1 ] );
	INI_Float( "VehBuyedPosZ", AutoSalon[ id ][ aVehBuyedPos ][ 2 ] );
	INI_Float( "VehBuyedPosA", AutoSalon[ id ][ aVehBuyedPos ][ 3 ] );
	INI_Float( "PickupPosX", AutoSalon[ id ][ aPickupPos ][ 0 ] );
	INI_Float( "PickupPosY", AutoSalon[ id ][ aPickupPos ][ 1 ] );
	INI_Float( "PickupPosZ", AutoSalon[ id ][ aPickupPos ][ 2 ] );
	INI_Float( "CameraPosX", AutoSalon[ id ][ aCameraPos ][ 0 ] );
	INI_Float( "CameraPosY", AutoSalon[ id ][ aCameraPos ][ 1 ] );
	INI_Float( "CameraPosZ", AutoSalon[ id ][ aCameraPos ][ 2 ] );
	INI_Float( "CameraLookAtX", AutoSalon[ id ][ aCameraLookAt ][ 0 ] );
	INI_Float( "CameraLookAtY", AutoSalon[ id ][ aCameraLookAt ][ 1 ] );
	INI_Float( "CameraLookAtZ", AutoSalon[ id ][ aCameraLookAt ][ 2 ] );
	INI_Int( "VirtualW", AutoSalon[ id ][ aVW ] );
	INI_Int( "Interior", AutoSalon[ id ][ aInt ] );
	INI_Int( "IzlogVeh", AutoSalon[ id ][ aIzlogVeh ] );
	return true;
}

//////////////////////kapije//////////////////////////


//------------------------------------------------------------------------------
forward LoadGate( id, name[], value[] );
public LoadGate( id, name[], value[] ) {

	INI_String( "Owner", GateData[ id ][ gateOwner ], MAX_PLAYER_NAME );
	INI_Int( "Model", GateData[ id ][ gateModel ] );
	INI_Int( "For", GateData[ id ][ gateFor ] );
	INI_Int( "OrgID", GateData[ id ][ gateOrgID ] );
	INI_Float( "Speed", GateData[ id ][ gateSpeed ] );
	INI_Float( "Radius", GateData[ id ][ gateRadius ] );
	INI_Int( "Time", GateData[ id ][ gateTime ] );
	INI_Float( "Pos1", GateData[ id ][ gatePos ][ 0 ] );
	INI_Float( "Pos2", GateData[ id ][ gatePos ][ 1 ] );
	INI_Float( "Pos3", GateData[ id ][ gatePos ][ 2 ] );
	INI_Float( "Pos4", GateData[ id ][ gatePos ][ 3 ] );
	INI_Float( "Pos5", GateData[ id ][ gatePos ][ 4 ] );
	INI_Float( "Pos6", GateData[ id ][ gatePos ][ 5 ] );
	INI_Int( "Interior", GateData[ id ][ gateInterior ] );
	INI_Int( "World", GateData[ id ][ gateWorld ] );
	INI_Float( "Move1", GateData[ id ][ gateMove ][ 0 ] );
	INI_Float( "Move2", GateData[ id ][ gateMove ][ 1 ] );
	INI_Float( "Move3", GateData[ id ][ gateMove ][ 2 ] );
	INI_Float( "Move4", GateData[ id ][ gateMove ][ 3 ] );
	INI_Float( "Move5", GateData[ id ][ gateMove ][ 4 ] );
	INI_Float( "Move6", GateData[ id ][ gateMove ][ 5 ] );

	return 1;
}


//////////////////////////hoteli//////////////////////

forward LoadHotel( id, name[], value[] );
public LoadHotel( id, name[], value[] ) {

	INI_Int( "Owned", hotelInfo[ id ][ hOwned ] );
	INI_String( "Owner", hotelInfo[ id ][ hOwner ], MAX_PLAYER_NAME );
	INI_Float( "Enter1", hotelInfo[ id ][ hEnter ][ 0 ] );
	INI_Float( "Enter2", hotelInfo[ id ][ hEnter ][ 1 ] );
	INI_Float( "Enter3", hotelInfo[ id ][ hEnter ][ 2 ] );
	INI_Float( "Exit1", hotelInfo[ id ][ hExit ][ 0 ] );
	INI_Float( "Exit2", hotelInfo[ id ][ hExit ][ 1 ] );
	INI_Float( "Exit3", hotelInfo[ id ][ hExit ][ 2 ] );
	INI_Int( "Price", hotelInfo[ id ][ hPrice ] );
	INI_Int( "RoomPrice", hotelInfo[ id ][ hRoomPrice ] );
	INI_Int( "Money", hotelInfo[ id ][ hMoney ] );
	INI_Int( "Interior", hotelInfo[ id ][ hInterior ] );
	INI_Int( "VW", hotelInfo[ id ][ hVW ] );
	INI_Int( "Level", hotelInfo[ id ][ hLevel ] );
	INI_Int( "Locked", hotelInfo[ id ][ hLocked ] );
	INI_String( "Adress", hotelInfo[ id ][ hAdress ], 38 );
	INI_String( "Guest_1", hotelInfo[ id ][ hGuest_1 ], MAX_PLAYER_NAME );
	INI_String( "Guest_2", hotelInfo[ id ][ hGuest_2 ], MAX_PLAYER_NAME );
	INI_String( "Guest_3", hotelInfo[ id ][ hGuest_3 ], MAX_PLAYER_NAME );
	INI_String( "Guest_4", hotelInfo[ id ][ hGuest_4 ], MAX_PLAYER_NAME );
	INI_String( "Guest_5", hotelInfo[ id ][ hGuest_5 ], MAX_PLAYER_NAME );
	INI_String( "Guest_6", hotelInfo[ id ][ hGuest_6 ], MAX_PLAYER_NAME );
	INI_String( "Guest_7", hotelInfo[ id ][ hGuest_7 ], MAX_PLAYER_NAME );
	INI_String( "Guest_8", hotelInfo[ id ][ hGuest_8 ], MAX_PLAYER_NAME );
	INI_String( "Guest_9", hotelInfo[ id ][ hGuest_9 ], MAX_PLAYER_NAME );
	INI_String( "Guest_10", hotelInfo[ id ][ hGuest_10 ], MAX_PLAYER_NAME );
	INI_Int( "Porez", hotelInfo[ id ][ hPorez ] );
	INI_Int( "VrednostPoreza", hotelInfo[ id ][ hVrednostPoreza  ] );
	return 1;
}

////////////////////imovine//////////////////////////



//------------------------------------------------------------------------------
public SaveProperty( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), IM_FILE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteInt( File, "Owned", II[ id ][ iOwned ] );
	INI_WriteString( File, "Owner", II[ id ][ iOwner ] );
	INI_WriteInt( File, "Usage", II[ id ][iUsage] );
	INI_WriteFloat( File, "Enter1", II[ id ][ iEnter ][ 0 ] );
	INI_WriteFloat( File, "Enter2", II[ id ][ iEnter ][ 1 ] );
	INI_WriteFloat( File, "Enter3", II[ id ][ iEnter ][ 2 ] );
	INI_WriteFloat( File, "Exit1", II[ id ][ iExit ][ 0 ] );
	INI_WriteFloat( File, "Exit2", II[ id ][ iExit ][ 1 ] );
	INI_WriteFloat( File, "Exit3", II[ id ][ iExit ][ 2 ] );
	INI_WriteInt( File, "Price", II[ id ][ iPrice ] );
	INI_WriteInt( File, "Locked", II[ id ][ iLocked ] );
	INI_WriteInt( File, "Interior", II[ id ][ iInterior ] );
	INI_WriteInt( File, "VW", II[ id ][ iVW ] );
	INI_WriteInt( File, "Vrsta", II[ id ][ iVrsta ] );
	INI_WriteInt( File, "Ormar", II[ id ][ iOrmar ] );
	INI_WriteInt( File, "Skin1", II[ id ][ iSkin ][ 0 ] );
	INI_WriteInt( File, "Skin2", II[ id ][ iSkin ][ 1 ] );
	INI_WriteInt( File, "Skin3", II[ id ][ iSkin ][ 2 ] );
	INI_WriteInt( File, "SafeStatus", II[ id ][ iSafeStatus ] );
	INI_WriteInt( File, "SafePass", II[ id ][ iSafePass ] );
	INI_WriteInt( File, "Oruzje1", II[ id ][ iOruzje ][ 0 ] );
	INI_WriteInt( File, "Oruzje2", II[ id ][ iOruzje ][ 1 ] );
	INI_WriteInt( File, "Oruzje3", II[ id ][ iOruzje ][ 2 ] );
	INI_WriteInt( File, "Oruzje4", II[ id ][ iOruzje ][ 3 ] );
	INI_WriteInt( File, "Municija1", II[ id ][ iMunicija ][ 0 ] );
	INI_WriteInt( File, "Municija2", II[ id ][ iMunicija ][ 1 ] );
	INI_WriteInt( File, "Municija3", II[ id ][ iMunicija ][ 2 ] );
	INI_WriteInt( File, "Municija4", II[ id ][ iMunicija ][ 3 ] );
	#if nerp_droga == 1
	INI_WriteInt( File, "Drug1", II[ id ][ iDrug ][ 0 ] );
	INI_WriteInt( File, "Drug2", II[ id ][ iDrug ][ 1 ] );
	INI_WriteInt( File, "Drug3", II[ id ][ iDrug ][ 2 ] );
	INI_WriteInt( File, "Drug4", II[ id ][ iDrug ][ 3 ] );
	INI_WriteInt( File, "Drug5", II[ id ][ iDrug ][ 4 ] );
	INI_WriteInt( File, "Drug6", II[ id ][ iDrug ][ 5 ] );
	INI_WriteInt( File, "Drug7", II[ id ][ iDrug ][ 6 ] );
	INI_WriteInt( File, "Drug8", II[ id ][ iDrug ][ 7 ] );
	INI_WriteInt( File, "Drug9", II[ id ][ iDrug ][ 8 ] );
	INI_WriteInt( File, "Drug10", II[ id ][ iDrug ][ 9 ] );
	INI_WriteInt( File, "DrugCode1", II[ id ][ iDrugCode ][ 0 ] );
	INI_WriteInt( File, "DrugCode2", II[ id ][ iDrugCode ][ 1 ] );
	INI_WriteInt( File, "DrugCode3", II[ id ][ iDrugCode ][ 2 ] );
	INI_WriteInt( File, "DrugCode4", II[ id ][ iDrugCode ][ 3 ] );
	INI_WriteInt( File, "DrugCode5", II[ id ][ iDrugCode ][ 4 ] );
	INI_WriteInt( File, "DrugCode6", II[ id ][ iDrugCode ][ 5 ] );
	INI_WriteInt( File, "DrugCode7", II[ id ][ iDrugCode ][ 6 ] );
	INI_WriteInt( File, "DrugCode8", II[ id ][ iDrugCode ][ 7 ] );
	INI_WriteInt( File, "DrugCode9", II[ id ][ iDrugCode ][ 8 ] );
	INI_WriteInt( File, "DrugCode10", II[ id ][ iDrugCode ][ 9 ] );
	#endif
	INI_WriteInt( File, "DoorLevel", II[ id ][ iDoorLevel ] );
	INI_WriteInt( File, "Alarm", II[ id ][ iAlarm ] );
	INI_WriteInt( File, "LockLevel", II[ id ][ iLockLevel ] );
	INI_WriteInt( File, "Time", II[ id ][ iTime ] );
	INI_WriteFloat( File, "PizzaTime", II[ id ][ iPizzaTime ] );
	INI_WriteInt( File, "Level", II[ id ][ iLevel ] );
	INI_WriteString( File, "Adress", II[ id ][ iAdress ] );
	INI_WriteInt( File, "Neaktivnost", II[ id ][ iNeaktivnost ] );
	INI_WriteInt( File, "Rentable", II[ id ][ iRentable ] );
	INI_WriteInt( File, "RentPrice", II[ id ][ iRentPrice ] );
	INI_WriteInt( File, "Rentovano", II[ id ][ iRentovano ] );
	INI_WriteInt( File, "Money", II[ id ][ iMoney ] );
	INI_WriteInt( File, "Mats", II[ id ][ iMats ] );
	INI_Close(File);
	return 1;
}
//------------------------------------------------------------------------------
public OcitajImovinu( id, name[], value[] ) {
	INI_Int( "Owned", II[ id ][ iOwned ] );
	INI_String( "Owner", II[ id ][ iOwner ], MAX_PLAYER_NAME );
	INI_Int( "Usage", II[ id ][iUsage] );
	INI_Float( "Enter1", II[ id ][ iEnter ][ 0 ] );
	INI_Float( "Enter2", II[ id ][ iEnter ][ 1 ] );
	INI_Float( "Enter3", II[ id ][ iEnter ][ 2 ] );
	INI_Float( "Exit1", II[ id ][ iExit ][ 0 ] );
	INI_Float( "Exit2", II[ id ][ iExit ][ 1 ] );
	INI_Float( "Exit3", II[ id ][ iExit ][ 2 ] );
	INI_Int( "Price", II[ id ][ iPrice ] );
	INI_Int( "Locked", II[ id ][ iLocked ] );
	INI_Int( "Interior", II[ id ][ iInterior ] );
	INI_Int( "VW", II[ id ][ iVW ] );
	INI_Int( "Vrsta", II[ id ][ iVrsta ] );
	INI_Int( "Ormar", II[ id ][ iOrmar ] );
	INI_Int( "Skin1", II[ id ][ iSkin ][ 0 ] );
	INI_Int( "Skin2", II[ id ][ iSkin ][ 1 ] );
	INI_Int( "Skin3", II[ id ][ iSkin ][ 2 ] );
	INI_Int( "SafeStatus", II[ id ][ iSafeStatus ] );
	INI_Int( "SafePass", II[ id ][ iSafePass ] );
	INI_Int( "Oruzje1", II[ id ][ iOruzje ][ 0 ] );
	INI_Int( "Oruzje2", II[ id ][ iOruzje ][ 1 ] );
	INI_Int( "Oruzje3", II[ id ][ iOruzje ][ 2 ] );
	INI_Int( "Oruzje4", II[ id ][ iOruzje ][ 3 ] );
	INI_Int( "Municija1", II[ id ][ iMunicija ][ 0 ] );
	INI_Int( "Municija2", II[ id ][ iMunicija ][ 1 ] );
	INI_Int( "Municija3", II[ id ][ iMunicija ][ 2 ] );
	INI_Int( "Municija4", II[ id ][ iMunicija ][ 3 ] );
	#if nerp_droga == 1
	INI_Int( "Drug1", II[ id ][ iDrug ][ 0 ] );
	INI_Int( "Drug2", II[ id ][ iDrug ][ 1 ] );
	INI_Int( "Drug3", II[ id ][ iDrug ][ 2 ] );
	INI_Int( "Drug4", II[ id ][ iDrug ][ 3 ] );
	INI_Int( "Drug5", II[ id ][ iDrug ][ 4 ] );
	INI_Int( "Drug6", II[ id ][ iDrug ][ 5 ] );
	INI_Int( "Drug7", II[ id ][ iDrug ][ 6 ] );
	INI_Int( "Drug8", II[ id ][ iDrug ][ 7 ] );
	INI_Int( "Drug9", II[ id ][ iDrug ][ 8 ] );
	INI_Int( "Drug10", II[ id ][ iDrug ][ 9 ] );
	INI_Int( "DrugCode1", II[ id ][ iDrugCode ][ 0 ] );
	INI_Int( "DrugCode2", II[ id ][ iDrugCode ][ 1 ] );
	INI_Int( "DrugCode3", II[ id ][ iDrugCode ][ 2 ] );
	INI_Int( "DrugCode4", II[ id ][ iDrugCode ][ 3 ] );
	INI_Int( "DrugCode5", II[ id ][ iDrugCode ][ 4 ] );
	INI_Int( "DrugCode6", II[ id ][ iDrugCode ][ 5 ] );
	INI_Int( "DrugCode7", II[ id ][ iDrugCode ][ 6 ] );
	INI_Int( "DrugCode8", II[ id ][ iDrugCode ][ 7 ] );
	INI_Int( "DrugCode9", II[ id ][ iDrugCode ][ 8 ] );
	INI_Int( "DrugCode10", II[ id ][ iDrugCode ][ 9 ] );
	#endif
	INI_Int( "DoorLevel", II[ id ][ iDoorLevel ] );
	INI_Int( "Alarm", II[ id ][ iAlarm ] );
	INI_Int( "LockLevel", II[ id ][ iLockLevel ] );
	INI_Int( "Time", II[ id ][ iTime ] );
	INI_Float( "PizzaTime", II[ id ][ iPizzaTime ] );
	INI_Int( "Level", II[ id ][ iLevel ] );
	INI_String( "Adress", II[ id ][ iAdress ], 38 );
	INI_Int( "Neaktivnost", II[ id ][ iNeaktivnost ] );
	INI_Int( "Rentable", II[ id ][ iRentable ] );
	INI_Int( "RentPrice", II[ id ][ iRentPrice ] );
	INI_Int( "Rentovano", II[ id ][ iRentovano ] );
	INI_Int( "Money", II[ id ][ iMoney ] );
	INI_Int( "Mats", II[ id ][ iMats ] );
	return true;
}


///////////////////////////vozila/////////////////////////////////////

//------------------------------------------------------------------------------
public SaveVehicle( id ) {
	new file4[40];
	format(file4, sizeof(file4), V_FILE, id);
	new INI:File = INI_Open(file4);
	INI_SetTag( File, "Informacije");
	INI_WriteInt( File, "Kupljen", VehicleInfo[ id ][ vOwned ] );
	INI_WriteInt( File, "Cena", VehicleInfo[ id ][ vPrice ] );
	INI_WriteString( File, "Vlasnik", VehicleInfo[ id ][ vOwner ] );
	INI_WriteInt( File, "Zakljucana", VehicleInfo[ id ][ vLocked ] );
	INI_WriteFloat( File, "LokacijaX", VehicleInfo[ id ][ vLokacijaX ] );
	INI_WriteFloat( File, "LokacijaY", VehicleInfo[ id ][ vLokacijaY ] );
	INI_WriteFloat( File, "LokacijaZ", VehicleInfo[ id ][ vLokacijaZ ] );
	INI_WriteFloat( File, "LokacijaA", VehicleInfo[ id ][ vLokacijaA ] );
	INI_WriteInt( File, "VirtualWorld", VehicleInfo[ id ][ vVirtualWorld ] );
	INI_WriteInt( File, "Interior", VehicleInfo[ id ][ vInterior ] );
	INI_WriteInt( File, "Koriscenje", VehicleInfo[ id ][ vUsage ] );
	INI_WriteInt( File, "Posao", VehicleInfo[ id ][ vJob ] );
	INI_WriteInt( File, "Orga", VehicleInfo[ id ][ vOrganization ] );
	INI_WriteInt( File, "FuelStation", VehicleInfo[ id ][ vFuelProperty ] );
	INI_WriteInt( File, "Boja1", VehicleInfo[ id ][ vColor1 ] );
	INI_WriteInt( File, "Boja2", VehicleInfo[ id ][ vColor2 ] );
	INI_WriteInt( File, "Model", VehicleInfo[ id ][ vModel ] );
	INI_WriteInt( File, "Reg", VehicleInfo[ id ][ vReg ] );
	INI_WriteInt( File, "RegVreme", VehicleInfo[ id ][ vRegVreme ] );
	INI_WriteString( File, "Tablice", VehicleInfo[ id ][ vTablice ] );
	INI_WriteInt( File, "Teh", VehicleInfo[ id ][ vTeh ] );
	INI_WriteInt( File, "GPS", VehicleInfo[ id ][ vGPS ] );
	INI_WriteInt( File, "Osiguranje", VehicleInfo[ id ][ vOsiguranje ] );
	INI_WriteInt( File, "Lock", VehicleInfo[ id ][ vLock ] );
	INI_WriteInt( File, "Alarm", VehicleInfo[ id ][ vAlarm ] );
	INI_WriteInt( File, "Fuel", VehicleInfo[ id ][ vFuel ] );
	INI_WriteInt( File, "FuelType", VehicleInfo[ id ][ vFuelType ]  );
	INI_WriteInt( File, "Neon", VehicleInfo[ id ][ vNeon ] );
	INI_WriteInt( File, "Tuned", VehicleInfo[ id ][ vTuned ] );
	INI_WriteInt( File, "Imobilizator", VehicleInfo[ id ][ vImobilizator ] );
	INI_WriteInt( File, "Spoiler", VehicleInfo[ id ][ vSpoiler ] );
	INI_WriteInt( File, "Hood", VehicleInfo[ id ][ vHood ] );
	INI_WriteInt( File, "Roof", VehicleInfo[ id ][ vRoof ] );
	INI_WriteInt( File, "Skirt", VehicleInfo[ id ][ vSkirt ] );
	INI_WriteInt( File, "Lamps", VehicleInfo[ id ][ vLamps ] );
	INI_WriteInt( File, "Nitro", VehicleInfo[ id ][ vNitro ] );
	INI_WriteInt( File, "Exhaust", VehicleInfo[ id ][ vExhaust ] );
	INI_WriteInt( File, "Wheels", VehicleInfo[ id ][ vWheels ] );
	INI_WriteInt( File, "Stereo", VehicleInfo[ id ][ vStereo ] );
	INI_WriteInt( File, "Hydraulics", VehicleInfo[ id ][ vHydraulics ] );
	INI_WriteInt( File, "FrontBumper", VehicleInfo[ id ][ vFrontBumper ] );
	INI_WriteInt( File, "RearBumper", VehicleInfo[ id ][ vRearBumper ] );
	INI_WriteInt( File, "Vents", VehicleInfo[ id ][ vVents ] );
	INI_WriteInt( File, "PaintJob", VehicleInfo[ id ][ vPaintJob ] );
	INI_WriteInt( File, "Provera", VehicleInfo[ id ][ vProvera ] );
	INI_WriteInt( File, "ID", VehicleInfo[ id ][ vID ] );
	#if nerp_droga == 1
	INI_WriteInt( File, "Drug1", VehicleInfo[ id ][ vDrug ][ 0 ] );
	INI_WriteInt( File, "Drug2", VehicleInfo[ id ][ vDrug ][ 1 ] );
	INI_WriteInt( File, "Drug3", VehicleInfo[ id ][ vDrug ][ 2 ] );
	INI_WriteInt( File, "Drug4", VehicleInfo[ id ][ vDrug ][ 3 ] );
	INI_WriteInt( File, "Drug5", VehicleInfo[ id ][ vDrug ][ 4 ] );
	INI_WriteInt( File, "Drug6", VehicleInfo[ id ][ vDrug ][ 5 ] );
	INI_WriteInt( File, "DrugCode1", VehicleInfo[ id ][ vDrugCode ][ 0 ] );
	INI_WriteInt( File, "DrugCode2", VehicleInfo[ id ][ vDrugCode ][ 1 ] );
	INI_WriteInt( File, "DrugCode3", VehicleInfo[ id ][ vDrugCode ][ 2 ] );
	INI_WriteInt( File, "DrugCode4", VehicleInfo[ id ][ vDrugCode ][ 3 ] );
	INI_WriteInt( File, "DrugCode5", VehicleInfo[ id ][ vDrugCode ][ 4 ] );
	INI_WriteInt( File, "DrugCode6", VehicleInfo[ id ][ vDrugCode ][ 5 ] );
	#endif
	INI_WriteInt( File, "Materijali", VehicleInfo[ id ][ vMaterijali ] );
	INI_WriteInt( File, "Melee", VehicleInfo[ id ][ vMelee ] );
	INI_WriteInt( File, "Weap1", VehicleInfo[ id ][ vWeap1 ] );
	INI_WriteInt( File, "Ammo1", VehicleInfo[ id ][ vAmmo1 ] );
	INI_WriteInt( File, "Weap2", VehicleInfo[ id ][ vWeap2 ] );
	INI_WriteInt( File, "Ammo2", VehicleInfo[ id ][ vAmmo2 ] );
	INI_WriteInt( File, "Gajbica1", VehicleInfo[ id ][ vGajbica ][ 0 ] );
	INI_WriteInt( File, "Gajbica2", VehicleInfo[ id ][ vGajbica ][ 1 ] );
	INI_WriteInt( File, "Gajbica3", VehicleInfo[ id ][ vGajbica ][ 2 ] );
	INI_WriteInt( File, "Gajbica4", VehicleInfo[ id ][ vGajbica ][ 3 ] );
	INI_WriteInt( File, "Gajbica5", VehicleInfo[ id ][ vGajbica ][ 4 ] );
	INI_WriteInt( File, "GajbicaKolicina1", VehicleInfo[ id ][ vGajbicaAmmount ][ 0 ] );
	INI_WriteInt( File, "GajbicaKolicina2", VehicleInfo[ id ][ vGajbicaAmmount ][ 1 ] );
	INI_WriteInt( File, "GajbicaKolicina3", VehicleInfo[ id ][ vGajbicaAmmount ][ 2 ] );
	INI_WriteInt( File, "GajbicaKolicina4", VehicleInfo[ id ][ vGajbicaAmmount ][ 3 ] );
	INI_WriteInt( File, "GajbicaKolicina5", VehicleInfo[ id ][ vGajbicaAmmount ][ 4 ] );
	INI_WriteInt( File, "Neaktivnost", VehicleInfo[ id ][ vNeaktivnost ] );
	INI_WriteInt( File, "Kilometri", VehicleInfo[ id ][ vKilometri ] );
	INI_WriteInt( File, "Metri", VehicleInfo[ id ][ vMetri ] );
	INI_Close(File);
	return true;
}
//------------------------------------------------------------------------------
public OcitajVozilo( id, name[], value[] ) {
	INI_Int( "Kupljen", VehicleInfo[ id ][ vOwned ] );
	INI_Int( "Cena", VehicleInfo[ id ][ vPrice ] );
	INI_String( "Vlasnik", VehicleInfo[ id ][ vOwner ], MAX_PLAYER_NAME );
	INI_Int( "Zakljucana", VehicleInfo[ id ][ vLocked ] );
	INI_Float( "LokacijaX", VehicleInfo[ id ][ vLokacijaX ] );
	INI_Float( "LokacijaY", VehicleInfo[ id ][ vLokacijaY ] );
	INI_Float( "LokacijaZ", VehicleInfo[ id ][ vLokacijaZ ] );
	INI_Float( "LokacijaA", VehicleInfo[ id ][ vLokacijaA ] );
	INI_Int( "VirtualWorld", VehicleInfo[ id ][ vVirtualWorld ] );
	INI_Int( "Interior", VehicleInfo[ id ][ vInterior ] );
	INI_Int( "Koriscenje", VehicleInfo[ id ][ vUsage ] );
	INI_Int( "Posao", VehicleInfo[ id ][ vJob ] );
	INI_Int( "Orga", VehicleInfo[ id ][ vOrganization ] );
	INI_Int( "FuelStation", VehicleInfo[ id ][ vFuelProperty ] );
	INI_Int( "Boja1", VehicleInfo[ id ][ vColor1] );
	INI_Int( "Boja2", VehicleInfo[ id ][ vColor2] );
	INI_Int( "Model", VehicleInfo[ id ][ vModel] );
	INI_Int( "Reg", VehicleInfo[ id ][ vReg ] );
	INI_Int( "RegVreme", VehicleInfo[ id ][ vRegVreme ] );
	INI_String( "Tablice", VehicleInfo[ id ][ vTablice ], 16 );
	INI_Int( "Teh", VehicleInfo[ id ][ vTeh ] );
	INI_Int( "GPS", VehicleInfo[ id ][ vGPS ] );
	INI_Int( "Osiguranje", VehicleInfo[ id ][ vOsiguranje ] );
	INI_Int( "Lock", VehicleInfo[ id ][ vLock ] );
	INI_Int( "Alarm", VehicleInfo[ id ][ vAlarm ] );
	INI_Int( "Fuel", VehicleInfo[ id ][ vFuel ] );
	INI_Int( "FuelType", VehicleInfo[ id ][ vFuelType ] );
	INI_Int( "Neon", VehicleInfo[ id ][ vNeon ] );
	INI_Int( "Tuned", VehicleInfo[ id ][ vTuned ] );
	INI_Int( "Imobilizator", VehicleInfo[ id ][ vImobilizator ] );
	INI_Int( "Spoiler", VehicleInfo[ id ][ vSpoiler] );
	INI_Int( "Hood", VehicleInfo[ id ][ vHood] );
	INI_Int( "Roof", VehicleInfo[ id ][ vRoof] );
	INI_Int( "Skirt", VehicleInfo[ id ][ vSkirt] );
	INI_Int( "Lamps", VehicleInfo[ id ][ vLamps] );
	INI_Int( "Nitro", VehicleInfo[ id ][ vNitro] );
	INI_Int( "Exhaust", VehicleInfo[ id ][ vExhaust] );
	INI_Int( "Wheels", VehicleInfo[ id ][ vWheels] );
	INI_Int( "Stereo", VehicleInfo[ id ][ vStereo] );
	INI_Int( "Hydraulics", VehicleInfo[ id ][ vHydraulics] );
	INI_Int( "FrontBumper", VehicleInfo[ id ][ vFrontBumper] );
	INI_Int( "RearBumper", VehicleInfo[ id ][ vRearBumper] );
	INI_Int( "Vents", VehicleInfo[ id ][ vVents] );
	INI_Int( "PaintJob", VehicleInfo[ id ][ vPaintJob ] );
	INI_Int( "Provera", VehicleInfo[ id ][ vProvera ] );
	#if nerp_droga == 1
	INI_Int( "Drug1", VehicleInfo[ id ][ vDrug ][ 0 ] );
	INI_Int( "Drug2", VehicleInfo[ id ][ vDrug ][ 1 ] );
	INI_Int( "Drug3", VehicleInfo[ id ][ vDrug ][ 2 ] );
	INI_Int( "Drug4", VehicleInfo[ id ][ vDrug ][ 3 ] );
	INI_Int( "Drug5", VehicleInfo[ id ][ vDrug ][ 4 ] );
	INI_Int( "Drug6", VehicleInfo[ id ][ vDrug ][ 5 ] );
	INI_Int( "DrugCode1", VehicleInfo[ id ][ vDrugCode ][ 0 ] );
	INI_Int( "DrugCode2", VehicleInfo[ id ][ vDrugCode ][ 1 ] );
	INI_Int( "DrugCode3", VehicleInfo[ id ][ vDrugCode ][ 2 ] );
	INI_Int( "DrugCode4", VehicleInfo[ id ][ vDrugCode ][ 3 ] );
	INI_Int( "DrugCode5", VehicleInfo[ id ][ vDrugCode ][ 4 ] );
	INI_Int( "DrugCode6", VehicleInfo[ id ][ vDrugCode ][ 5 ] );
	#endif
	INI_Int( "Materijali", VehicleInfo[ id ][ vMaterijali ] );
	INI_Int( "Melee", VehicleInfo[ id ][ vMelee ] );
	INI_Int( "Weap1", VehicleInfo[ id ][ vWeap1 ] );
	INI_Int( "Ammo1", VehicleInfo[ id ][ vAmmo1 ] );
	INI_Int( "Weap2", VehicleInfo[ id ][ vWeap2 ] );
	INI_Int( "Ammo2", VehicleInfo[ id ][ vAmmo2 ] );
	INI_Int( "Gajbica1", VehicleInfo[ id ][ vGajbica ][ 0 ] );
	INI_Int( "Gajbica2", VehicleInfo[ id ][ vGajbica ][ 1 ] );
	INI_Int( "Gajbica3", VehicleInfo[ id ][ vGajbica ][ 2 ] );
	INI_Int( "Gajbica4", VehicleInfo[ id ][ vGajbica ][ 3 ] );
	INI_Int( "Gajbica5", VehicleInfo[ id ][ vGajbica ][ 4 ] );
	INI_Int( "GajbicaKolicina1", VehicleInfo[ id ][ vGajbicaAmmount ][ 0 ] );
	INI_Int( "GajbicaKolicina2", VehicleInfo[ id ][ vGajbicaAmmount ][ 1 ] );
	INI_Int( "GajbicaKolicina3", VehicleInfo[ id ][ vGajbicaAmmount ][ 2 ] );
	INI_Int( "GajbicaKolicina4", VehicleInfo[ id ][ vGajbicaAmmount ][ 3 ] );
	INI_Int( "GajbicaKolicina5", VehicleInfo[ id ][ vGajbicaAmmount ][ 4 ] );
	INI_Int( "Neaktivnost", VehicleInfo[ id ][ vNeaktivnost ] );
	INI_Int( "Kilometri", VehicleInfo[ id ][ vKilometri ] );
	INI_Int( "Metri", VehicleInfo[ id ][ vMetri ] );
	INI_Int( "ID", VehicleInfo[ id ][ vID ] );
	return true;
}

///////////////////////////organizacije////orge/////////////////////////////////


//------------------------------------------------------------------------------
public SaveOrganization(id)
{
		new org_file[ 40 ];
		format (org_file, sizeof( org_file ), O_FILE, id );

		if(OI[ id ][ oCreated ] == 1)
		{
		new INI:File = INI_Open( org_file );
		
		INI_SetTag( File, "Organizacija");

		INI_WriteInt( File, "ID", OI[ id ][ oID ] );
		INI_WriteInt( File, "Created", OI[ id ][ oCreated ] );
		INI_WriteString( File, "Ime", OI[ id ][ oName ] );
		INI_WriteString( File, "PreFix", OI[ id ][ oPreFix ] );
		INI_WriteString( File, "Color", OI[ id ][ oColor ] );

		INI_WriteInt( File, "Tip", OI[ id ][ oTip ] );
		INI_WriteInt( File, "Suspended", OI[ id ][ oSuspended ] );
		INI_WriteInt( File, "MaxClanova", OI[ id ][ oMaxClanova ] );
		INI_WriteInt( File, "UbacenihClanova", OI[ id ][ oUbacenihClanova ] );

		INI_WriteInt( File, "Skin1", OI[ id ][ oSkin1 ] );
		INI_WriteInt( File, "Skin2", OI[ id ][ oSkin2 ] );
		INI_WriteInt( File, "Skin3", OI[ id ][ oSkin3 ] );
		INI_WriteInt( File, "Skin4", OI[ id ][ oSkin4 ] );
		INI_WriteInt( File, "Skin5", OI[ id ][ oSkin5 ] );
		INI_WriteInt( File, "Skin6", OI[ id ][ oSkin6 ] );

		INI_WriteInt( File, "ZSkin1", OI[ id ][ oZSkin1 ] );
		INI_WriteInt( File, "ZSkin2", OI[ id ][ oZSkin2 ] );
		INI_WriteInt( File, "ZSkin3", OI[ id ][ oZSkin3 ] );
		INI_WriteInt( File, "ZSkin4", OI[ id ][ oZSkin4 ] );
		INI_WriteInt( File, "ZSkin5", OI[ id ][ oZSkin5 ] );
		INI_WriteInt( File, "ZSkin6", OI[ id ][ oZSkin6 ] );

		INI_WriteString( File, "Lider1", OI[ id ][ oLider1 ] );
		INI_WriteString( File, "Lider2", OI[ id ][ oLider2 ] );

		INI_WriteString( File, "Clan1", OI[ id ][ oClan1 ] );
		INI_WriteString( File, "Clan2", OI[ id ][ oClan2 ] );
		INI_WriteString( File, "Clan3", OI[ id ][ oClan3 ] );
		INI_WriteString( File, "Clan4", OI[ id ][ oClan4 ] );
		INI_WriteString( File, "Clan5", OI[ id ][ oClan5 ] );
		INI_WriteString( File, "Clan6", OI[ id ][ oClan6 ] );
		INI_WriteString( File, "Clan7", OI[ id ][ oClan7 ] );
		INI_WriteString( File, "Clan8", OI[ id ][ oClan8 ] );
		INI_WriteString( File, "Clan9", OI[ id ][ oClan9 ] );
		INI_WriteString( File, "Clan10", OI[ id ][ oClan10 ] );
		INI_WriteString( File, "Clan11", OI[ id ][ oClan11 ] );
		INI_WriteString( File, "Clan12", OI[ id ][ oClan12 ] );
		INI_WriteString( File, "Clan13", OI[ id ][ oClan13 ] );
		INI_WriteString( File, "Clan14", OI[ id ][ oClan14 ] );
		INI_WriteString( File, "Clan15", OI[ id ][ oClan15 ] );
		INI_WriteString( File, "Clan16", OI[ id ][ oClan16 ] );
		INI_WriteString( File, "Clan17", OI[ id ][ oClan17 ] );
		INI_WriteString( File, "Clan18", OI[ id ][ oClan18 ] );
		INI_WriteString( File, "Clan19", OI[ id ][ oClan19 ] );
		INI_WriteString( File, "Clan20", OI[ id ][ oClan20 ] );
		INI_WriteString( File, "Clan21", OI[ id ][ oClan21 ] );
		INI_WriteString( File, "Clan22", OI[ id ][ oClan22 ] );
		INI_WriteString( File, "Clan23", OI[ id ][ oClan23 ] );
		INI_WriteString( File, "Clan24", OI[ id ][ oClan24 ] );
		INI_WriteString( File, "Clan25", OI[ id ][ oClan25 ] );
		INI_WriteString( File, "Clan26", OI[ id ][ oClan26 ] );
		INI_WriteString( File, "Clan27", OI[ id ][ oClan27 ] );
		INI_WriteString( File, "Clan28", OI[ id ][ oClan28 ] );
		INI_WriteString( File, "Clan29", OI[ id ][ oClan29 ] );
		INI_WriteString( File, "Clan30", OI[ id ][ oClan30 ] );

		INI_WriteString( File, "Rank1", OI[ id ][ oRank1 ] );
		INI_WriteString( File, "Rank2", OI[ id ][ oRank2 ] );
		INI_WriteString( File, "Rank3", OI[ id ][ oRank3 ] );
		INI_WriteString( File, "Rank4", OI[ id ][ oRank4 ] );
		INI_WriteString( File, "Rank5", OI[ id ][ oRank5 ] );
		INI_WriteString( File, "Rank6", OI[ id ][ oRank6 ] );

		INI_WriteFloat( File, "PozExtX", OI[ id ][ oPozExtX ] );
		INI_WriteFloat( File, "PozExtY", OI[ id ][ oPozExtY ] );
		INI_WriteFloat( File, "PozExtZ", OI[ id ][ oPozExtZ ] );

		INI_WriteFloat( File, "PozIntX", OI[ id ][ oPozIntX ] );
		INI_WriteFloat( File, "PozIntY", OI[ id ][ oPozIntY ] );
		INI_WriteFloat( File, "PozIntZ", OI[ id ][ oPozIntZ ] );

		INI_WriteFloat( File, "DutyPoint1", OI[ id ][ oDutyPoint ][ 0 ] );
		INI_WriteFloat( File, "DutyPoint2", OI[ id ][ oDutyPoint ][ 1 ] );
		INI_WriteFloat( File, "DutyPoint3", OI[ id ][ oDutyPoint ][ 2 ] );

		INI_WriteInt( File, "DutyInt", OI[ id ][ oDutyInt ] );
		INI_WriteInt( File, "DutyVW", OI[ id ][ oDutyVW ] );

		INI_WriteFloat( File, "EquipPoint1", OI[ id ][ oEquipPoint ][ 0 ] );
		INI_WriteFloat( File, "EquipPoint2", OI[ id ][ oEquipPoint ][ 1 ] );
		INI_WriteFloat( File, "EquipPoint3", OI[ id ][ oEquipPoint ][ 2 ] );

		INI_WriteInt( File, "EquipInt", OI[ id ][ oEquipInt ] );
		INI_WriteInt( File, "EquipVW", OI[ id ][ oEquipVW ] );

		INI_WriteInt( File, "Savez", OI[ id ][ oSavez ] );

		INI_WriteInt( File, "MaxPort", OI[ id ][ oMaxPort ] );
		INI_WriteInt( File, "ControlType", OI[ id ][ oControlType ] );
		INI_WriteFloat( File, "DrugField1", OI[ id ][ oDrugField ][ 0 ] );
		INI_WriteFloat( File, "DrugField2", OI[ id ][ oDrugField ][ 1 ] );
		INI_WriteFloat( File, "DrugField3", OI[ id ][ oDrugField ][ 2 ] );
		INI_WriteFloat( File, "SafePos1", OI[ id ][ oSafePos ][ 0 ] );
		INI_WriteFloat( File, "SafePos2", OI[ id ][ oSafePos ][ 1 ] );
		INI_WriteFloat( File, "SafePos3", OI[ id ][ oSafePos ][ 2 ] );

		INI_WriteInt( File, "SafeMoney", OI[ id ][ oSafeMoney ] );
		
		#if nerp_droga == 1
		INI_WriteInt( File, "SafeDrug1", OI[ id ][ oSafeDrug ][ 0 ] );
		INI_WriteInt( File, "SafeDrug2", OI[ id ][ oSafeDrug ][ 1 ] );
		INI_WriteInt( File, "SafeDrug3", OI[ id ][ oSafeDrug ][ 2 ] );
		INI_WriteInt( File, "SafeDrug4", OI[ id ][ oSafeDrug ][ 3 ] );
		INI_WriteInt( File, "SafeDrugCode1", OI[ id ][ oSafeDrugCode ][ 0 ] );
		INI_WriteInt( File, "SafeDrugCode2", OI[ id ][ oSafeDrugCode ][ 1 ] );
		INI_WriteInt( File, "SafeDrugCode3", OI[ id ][ oSafeDrugCode ][ 2 ] );
		INI_WriteInt( File, "SafeDrugCode4", OI[ id ][ oSafeDrugCode ][ 3 ] );
		#endif
		INI_WriteInt( File, "Int", OI[ id ][ oInt ] );
		INI_WriteInt( File, "Vw", OI[ id ][ oVw ] );

		INI_WriteInt(File, "ImaDrugFactory", OI[id][ImaDrugFactory]);
		INI_WriteFloat( File, "DrugFactoryPos1", OI[ id ][ oDrugFactoryPos ][ 0 ] );
		INI_WriteFloat( File, "DrugFactoryPos2", OI[ id ][ oDrugFactoryPos ][ 1 ] );
		INI_WriteFloat( File, "DrugFactoryPos3", OI[ id ][ oDrugFactoryPos ][ 2 ] );

		INI_WriteInt(File, "ImaGarage", OI[id][ImaGarage]);
		INI_WriteFloat( File, "GaragePos1", OI[ id ][ oGaragePos ][ 0 ] );
		INI_WriteFloat( File, "GaragePos2", OI[ id ][ oGaragePos ][ 1 ] );
		INI_WriteFloat( File, "GaragePos3", OI[ id ][ oGaragePos ][ 2 ] );

		INI_Close( File );
		
		}
		return 1;
}
forward LoadPorts(id, name[], value[] );
public LoadPorts(id, name[], value[])
{
	new string[ 15 ];

	for( new i = 0; i < OI[ id ][ oMaxPort ]; i++)
	{

		format( string, sizeof( string ), "Pos1X%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos1 ][ 0 ] );

		format( string, sizeof( string ), "Pos1Y%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos1 ][ 1 ] );

		format( string, sizeof( string ), "Pos1Z%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos1 ][ 2 ] );

		format( string, sizeof( string ), "Int1%d", i );
		INI_Int( string, PortOP[ id ][ i ][ Int ][ 0 ] );

		format( string, sizeof( string ), "VW1%d", i );
		INI_Int( string, PortOP[ id ][ i ][ VW ][ 0 ] );

		format( string, sizeof( string ), "Pos2X%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos2 ][ 0 ] );

		format( string, sizeof( string ), "Pos2Y%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos2 ][ 1 ] );

		format( string, sizeof( string ), "Pos2Z%d", i );
		INI_Float( string, PortOP[ id ][ i ][ Pos2 ][ 2 ] );

		format( string, sizeof( string ), "Int2%d", i );
		INI_Int( string, PortOP[ id ][ i ][ Int ][ 1 ] );

		format( string, sizeof( string ), "VW2%d", i );
		INI_Int( string, PortOP[ id ][ i ][ VW ][ 1 ] );

	}
	return 1;
}
//------------------------------------------------------------------------------
public UcitajOrganizaciju(id, name[], value[])
{


		INI_Int( "ID", OI[ id ][ oID ] );
		INI_Int( "Created", OI[ id ][ oCreated ] );
		INI_String( "Ime", OI[ id ][ oName ], ORG_IME );
		INI_String( "PreFix", OI[ id ][ oPreFix ], 10 );
		INI_String( "Color", OI[ id ][ oColor ], 24 );

		INI_Int( "Tip", OI[ id ][ oTip ] );
		INI_Int( "Suspended", OI[ id ][ oSuspended ] );
		INI_Int( "MaxClanova", OI[ id ][ oMaxClanova ] );
		INI_Int( "UbacenihClanova", OI[ id ][ oUbacenihClanova ] );

		INI_Int( "Skin1", OI[ id ][ oSkin1] );
		INI_Int( "Skin2", OI[ id ][ oSkin2] );
		INI_Int( "Skin3", OI[ id ][ oSkin3] );
		INI_Int( "Skin4", OI[ id ][ oSkin4] );
		INI_Int( "Skin5", OI[ id ][ oSkin5] );
		INI_Int( "Skin6", OI[ id ][ oSkin6] );

		INI_Int( "ZSkin1", OI[ id ][ oZSkin1] );
		INI_Int( "ZSkin2", OI[ id ][ oZSkin2] );
		INI_Int( "ZSkin3", OI[ id ][ oZSkin3] );
		INI_Int( "ZSkin4", OI[ id ][ oZSkin4] );
		INI_Int( "ZSkin5", OI[ id ][ oZSkin5] );
		INI_Int( "ZSkin6", OI[ id ][ oZSkin6] );

		INI_String( "Lider1", OI[ id ][ oLider1 ], ORG_LIDER );
		INI_String( "Lider2", OI[ id ][ oLider2 ], ORG_LIDER );

		INI_String( "Clan1", OI[ id ][ oClan1 ], ORG_CLAN );
		INI_String( "Clan2", OI[ id ][ oClan2 ], ORG_CLAN );
		INI_String( "Clan3", OI[ id ][ oClan3 ], ORG_CLAN );
		INI_String( "Clan4", OI[ id ][ oClan4 ], ORG_CLAN );
		INI_String( "Clan5", OI[ id ][ oClan5 ], ORG_CLAN );
		INI_String( "Clan6", OI[ id ][ oClan6 ], ORG_CLAN );
		INI_String( "Clan7", OI[ id ][ oClan7 ], ORG_CLAN );
		INI_String( "Clan8", OI[ id ][ oClan8 ], ORG_CLAN );
		INI_String( "Clan9", OI[ id ][ oClan9 ], ORG_CLAN );
		INI_String( "Clan10", OI[ id ][ oClan10 ], ORG_CLAN );
		INI_String( "Clan11", OI[ id ][ oClan11 ], ORG_CLAN );
		INI_String( "Clan12", OI[ id ][ oClan12 ], ORG_CLAN );
		INI_String( "Clan13", OI[ id ][ oClan13 ], ORG_CLAN );
		INI_String( "Clan14", OI[ id ][ oClan14 ], ORG_CLAN );
		INI_String( "Clan15", OI[ id ][ oClan15 ], ORG_CLAN );
		INI_String( "Clan16", OI[ id ][ oClan16 ], ORG_CLAN );
		INI_String( "Clan17", OI[ id ][ oClan17 ], ORG_CLAN );
		INI_String( "Clan18", OI[ id ][ oClan18 ], ORG_CLAN );
		INI_String( "Clan19", OI[ id ][ oClan19 ], ORG_CLAN );
		INI_String( "Clan20", OI[ id ][ oClan20 ], ORG_CLAN );
		INI_String( "Clan21", OI[ id ][ oClan21 ], ORG_CLAN );
		INI_String( "Clan22", OI[ id ][ oClan22 ], ORG_CLAN );
		INI_String( "Clan23", OI[ id ][ oClan23 ], ORG_CLAN );
		INI_String( "Clan24", OI[ id ][ oClan24 ], ORG_CLAN );
		INI_String( "Clan25", OI[ id ][ oClan25 ], ORG_CLAN );
		INI_String( "Clan26", OI[ id ][ oClan26 ], ORG_CLAN );
		INI_String( "Clan27", OI[ id ][ oClan27 ], ORG_CLAN );
		INI_String( "Clan28", OI[ id ][ oClan28 ], ORG_CLAN );
		INI_String( "Clan29", OI[ id ][ oClan29 ], ORG_CLAN );
		INI_String( "Clan30", OI[ id ][ oClan30 ], ORG_CLAN );

		INI_String( "Rank1", OI[ id ][ oRank1], ORG_RANK);
		INI_String( "Rank2", OI[ id ][ oRank2], ORG_RANK);
		INI_String( "Rank3", OI[ id ][ oRank3], ORG_RANK);
		INI_String( "Rank4", OI[ id ][ oRank4], ORG_RANK);
		INI_String( "Rank5", OI[ id ][ oRank5], ORG_RANK);
		INI_String( "Rank6", OI[ id ][ oRank6], ORG_RANK);

		INI_Float( "PozExtX", OI[ id ][ oPozExtX] );
		INI_Float( "PozExtY", OI[ id ][ oPozExtY] );
		INI_Float( "PozExtZ", OI[ id ][ oPozExtZ] );

		INI_Float( "PozIntX", OI[ id ][ oPozIntX] );
		INI_Float( "PozIntY", OI[ id ][ oPozIntY] );
		INI_Float( "PozIntZ", OI[ id ][ oPozIntZ] );

		INI_Float( "DutyPoint1", OI[ id ][ oDutyPoint ][ 0 ] );
		INI_Float( "DutyPoint2", OI[ id ][ oDutyPoint ][ 1 ] );
		INI_Float( "DutyPoint3", OI[ id ][ oDutyPoint ][ 2 ] );

		INI_Int( "DutyInt", OI[ id ][ oDutyInt ] );
		INI_Int( "DutyVW", OI[ id ][ oDutyVW ] );

		INI_Float( "EquipPoint1", OI[ id ][ oEquipPoint ][ 0 ] );
		INI_Float( "EquipPoint2", OI[ id ][ oEquipPoint ][ 1 ] );
		INI_Float( "EquipPoint3", OI[ id ][ oEquipPoint ][ 2 ] );

		INI_Int( "EquipInt", OI[ id ][ oEquipInt ] );
		INI_Int( "EquipVW", OI[ id ][ oEquipVW ] );

		INI_Int( "Savez", OI[ id ][ oSavez ] );

		INI_Int( "MaxPort", OI[ id ][ oMaxPort ] );
		INI_Int( "ControlType", OI[ id ][ oControlType ] );
		INI_Float( "DrugField1", OI[ id ][ oDrugField ][ 0 ] );
		INI_Float( "DrugField2", OI[ id ][ oDrugField ][ 1 ] );
		INI_Float( "DrugField3", OI[ id ][ oDrugField ][ 2 ] );
		INI_Float( "SafePos1", OI[ id ][ oSafePos ][ 0 ] );
		INI_Float( "SafePos2", OI[ id ][ oSafePos ][ 1 ] );
		INI_Float( "SafePos3", OI[ id ][ oSafePos ][ 2 ] );

		INI_Int( "SafeMoney", OI[ id ][ oSafeMoney ] );
		#if nerp_droga == 1
		INI_Int( "SafeDrug1", OI[ id ][ oSafeDrug ][ 0 ] );
		INI_Int( "SafeDrug2", OI[ id ][ oSafeDrug ][ 1 ] );
		INI_Int( "SafeDrug3", OI[ id ][ oSafeDrug ][ 2 ] );
		INI_Int( "SafeDrug4", OI[ id ][ oSafeDrug ][ 3 ] );
		INI_Int( "SafeDrugCode1", OI[ id ][ oSafeDrugCode ][ 0 ] );
		INI_Int( "SafeDrugCode2", OI[ id ][ oSafeDrugCode ][ 1 ] );
		INI_Int( "SafeDrugCode3", OI[ id ][ oSafeDrugCode ][ 2 ] );
		INI_Int( "SafeDrugCode4", OI[ id ][ oSafeDrugCode ][ 3 ] );
		#endif
		INI_Int( "Int", OI[ id ][ oInt] );
		INI_Int( "Vw", OI[ id ][ oVw ] );
		
		INI_Int("ImaDrugFactory", OI[id][ImaDrugFactory]);
		INI_Float( "DrugFactoryPos1", OI[ id ][ oDrugFactoryPos ][ 0 ] );
		INI_Float( "DrugFactoryPos2", OI[ id ][ oDrugFactoryPos ][ 1 ] );
		INI_Float( "DrugFactoryPos3", OI[ id ][ oDrugFactoryPos ][ 2 ] );

		INI_Int("ImaGarage", OI[id][ImaGarage]);
		INI_Float( "GaragePos1", OI[ id ][ oGaragePos ][ 0 ] );
		INI_Float( "GaragePos2", OI[ id ][ oGaragePos ][ 1 ] );
		INI_Float( "GaragePos3", OI[ id ][ oGaragePos ][ 2 ] );
		return 1;
}

////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
forward OcitajUlicu( id, name[], value[] );
public OcitajUlicu( id, name[], value[] )
{
	INI_Float( "ObjPos1", streetInfo[ id ][ streetObjPos ][ 0 ] );
	INI_Float( "ObjPos2", streetInfo[ id ][ streetObjPos ][ 1 ] );
	INI_Float( "ObjPos3", streetInfo[ id ][ streetObjPos ][ 2 ] );
	//INI_String( "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ], IME_IGRACA_DUZINA_STRINGA);
	return true;
}
forward SacuvajUlicu( id );
public SacuvajUlicu( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), STREET_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "ObjPos1", streetInfo[ id ][ streetObjPos ][ 0 ] );
	INI_WriteFloat( File, "ObjPos2", streetInfo[ id ][ streetObjPos ][ 1 ] );
	INI_WriteFloat( File, "ObjPos3", streetInfo[ id ][ streetObjPos ][ 2 ] );
	//INI_WriteString( File, "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ]);
	INI_Close( File );
	return true;
}
//------------------------------------------------------------------------------
forward OcitajDilera( id, name[], value[] );
public OcitajDilera( id, name[], value[] )
{
	INI_Float( "Pos1", DealerInfo[ id ][ dealerPos ][ 0 ] );
	INI_Float( "Pos2", DealerInfo[ id ][ dealerPos ][ 1 ] );
	INI_Float( "Pos3", DealerInfo[ id ][ dealerPos ][ 2 ] );
	INI_Int( "Organizacija", DealerInfo[ id ][ Organizacija ] );
	return true;
}
forward SacuvajDilera( id );
public SacuvajDilera( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), DEALER_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "Pos1", DealerInfo[ id ][ dealerPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", DealerInfo[ id ][ dealerPos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", DealerInfo[ id ][ dealerPos ][ 2 ] );
	INI_WriteInt( File, "Organizacija", DealerInfo[ id ][ Organizacija ] );
	INI_Close( File );
	return true;
}
//------------------------------------------------------------------------------
forward OcitajRent( id, name[], value[] );
public OcitajRent( id, name[], value[] )
{
	INI_Float( "ObjPos1", rentInfo[ id ][ rentObjPos ][ 0 ] );
	INI_Float( "ObjPos2", rentInfo[ id ][ rentObjPos ][ 1 ] );
	INI_Float( "ObjPos3", rentInfo[ id ][ rentObjPos ][ 2 ] );
	//INI_String( "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ], IME_IGRACA_DUZINA_STRINGA);
	return true;
}
forward SacuvajRent( id );
public SacuvajRent( id )
{
	new file4[ 40 ];
	format( file4, sizeof( file4 ), RENT_FILE, id );
	new INI:File = INI_Open( file4 );
	INI_WriteFloat( File, "ObjPos1", rentInfo[ id ][ rentObjPos ][ 0 ] );
	INI_WriteFloat( File, "ObjPos2", rentInfo[ id ][ rentObjPos ][ 1 ] );
	INI_WriteFloat( File, "ObjPos3", rentInfo[ id ][ rentObjPos ][ 2 ] );
	//INI_WriteString( File, "bodyImeIgraca", bodyInfo[ id ][ bodyImeIgraca ]);
	INI_Close( File );
	return true;
}

//////////////////////////igrac//////////////////////////////////////
forward ShowOffStats( name[ ], value[ ] );
public ShowOffStats( name[ ], value[ ] ) {
	INI_Int( "Godine", OfflineCheck[ Godine ] );
	INI_Int( "Pol", OfflineCheck[ Pol ] );
	INI_Int( "Novac", OfflineCheck[ Novac ] );
	INI_Int( "Level", OfflineCheck[ Level ] );
	INI_Int( "Respekt", OfflineCheck[ Respekt ] );
	INI_Int( "Clan", OfflineCheck[ Organizacija ] );
	INI_Int( "Rank", OfflineCheck[ Rank ] );
	INI_Int( "VoziloID1", OfflineCheck[ Vozilo1 ] );
	INI_Int( "VoziloID2", OfflineCheck[ Vozilo2 ] );
	INI_Int( "VoziloID3", OfflineCheck[ Vozilo3 ] );
	INI_Int( "VoziloID4", OfflineCheck[ Vozilo4 ] );
	INI_Int( "Posao", OfflineCheck[ Posao ] );
	INI_Int( "Ugovor", OfflineCheck[ Posaougovor ] );
	INI_Int( "OnlineSati", OfflineCheck[ OnlineSati ] );
	INI_Int( "BRacun", OfflineCheck[ Banka ] );
	INI_Int( "Property1", OfflineCheck[ Imovina1 ] );
	INI_Int( "Property2", OfflineCheck[ Imovina2 ] );
	INI_Int( "Property3", OfflineCheck[ Imovina3 ] );
	INI_Int( "Warn", OfflineCheck[ Upozorenja ] );
	INI_Int( "FirmaID", OfflineCheck[ Firma ] );
	INI_Int( "StaffMin", OfflineCheck[ StaffMin ] );
	INI_String( "LastLogin", OfflineCheck[ LastLogin ], 64 );
	INI_Int( "RPTeacher", OfflineCheck[ GameSage ] );
	INI_Int( "Admin", OfflineCheck[ Admin ] );
	INI_Int( "HotelID", OfflineCheck[ Hotel ] );
	INI_String( "Email", OfflineCheck[ eMail ], 34 );
	return 1;
}
public OcitajKorisnika( playerid, name[ ], value[ ] ) {

	INI_String( "Lozinka", PlayerInfo[ playerid ][ xLozinka ], LOZINKA_STRING );
	INI_Int( "Pol", PlayerInfo[ playerid ][ xPol ] );
	INI_Int( "Godine", PlayerInfo[ playerid ][ xGodine ] );
	INI_Int( "Novac", PlayerInfo[ playerid ][ xNovac ] );
	INI_Int( "Level", PlayerInfo[ playerid ][ xLevel ] );
	INI_Int( "Respekt", PlayerInfo[ playerid ][ xRespekt ] );
	INI_Int( "Poboljsanja", PlayerInfo[ playerid ][ xPoboljsanja ] );
	INI_Int( "PayDay", PlayerInfo[ playerid ][ xPayDay ] );
	INI_Int( "Admin", PlayerInfo[ playerid ][ xAdmin ] );
	INI_Int( "Skin", PlayerInfo[ playerid ][ xSkin ] );
	INI_Int( "Spawn", PlayerInfo[ playerid ][ xSpawn ] );
	INI_Int( "Lider", PlayerInfo[ playerid ][ xLider ] );
	INI_Int( "Clan", PlayerInfo[ playerid ][ xClan ] );
	INI_Int( "Rank", PlayerInfo[ playerid ][ xRank ] );
	INI_Int( "VoziloID1", PlayerInfo[ playerid ][ xVoziloID ][ 0 ] );
	INI_Int( "VoziloID2", PlayerInfo[ playerid ][ xVoziloID ][ 1 ] );
	INI_Int( "VoziloID3", PlayerInfo[ playerid ][ xVoziloID ][ 2 ] );
	INI_Int( "VoziloID4", PlayerInfo[ playerid ][ xVoziloID ][ 3 ] );
	INI_Int( "Materijali", PlayerInfo[ playerid ][ xMaterijali ] );
	INI_Int( "FirmaID", PlayerInfo[ playerid ][ xFirmaID ] );
	INI_Int( "Posao", PlayerInfo[ playerid ][ xPosao ] );
	INI_Int( "Ugovor", PlayerInfo[ playerid ][ xUgovor ] );
	INI_Int( "MehSkill", PlayerInfo[ playerid ][ xMehSkill ] );
	INI_Int( "MDelovi", PlayerInfo[ playerid ][ xMDelovi ] );
	INI_Int( "Head", PlayerInfo[ playerid ][ xHead ] );
	INI_Float( "HeadPos1", PlayerInfo[ playerid ][ xHeadPos ][ 0 ] );
	INI_Float( "HeadPos2", PlayerInfo[ playerid ][ xHeadPos ][ 1 ] );
	INI_Float( "HeadPos3", PlayerInfo[ playerid ][ xHeadPos ][ 2 ] );
	INI_Float( "HeadPos4", PlayerInfo[ playerid ][ xHeadPos ][ 3 ] );
	INI_Float( "HeadPos5", PlayerInfo[ playerid ][ xHeadPos ][ 4 ] );
	INI_Float( "HeadPos6", PlayerInfo[ playerid ][ xHeadPos ][ 5 ] );
	INI_Float( "HeadPos7", PlayerInfo[ playerid ][ xHeadPos ][ 6 ] );
	INI_Float( "HeadPos8", PlayerInfo[ playerid ][ xHeadPos ][ 7 ] );
	INI_Float( "HeadPos9", PlayerInfo[ playerid ][ xHeadPos ][ 8 ] );
	INI_Int( "Face", PlayerInfo[ playerid ][ xFace ] );
	INI_Float( "FacePos1", PlayerInfo[ playerid ][ xFacePos ][ 0 ] );
	INI_Float( "FacePos2", PlayerInfo[ playerid ][ xFacePos ][ 1 ] );
	INI_Float( "FacePos3", PlayerInfo[ playerid ][ xFacePos ][ 2 ] );
	INI_Float( "FacePos4", PlayerInfo[ playerid ][ xFacePos ][ 3 ] );
	INI_Float( "FacePos5", PlayerInfo[ playerid ][ xFacePos ][ 4 ] );
	INI_Float( "FacePos6", PlayerInfo[ playerid ][ xFacePos ][ 5 ] );
	INI_Float( "FacePos7", PlayerInfo[ playerid ][ xFacePos ][ 6 ] );
	INI_Float( "FacePos8", PlayerInfo[ playerid ][ xFacePos ][ 7 ] );
	INI_Float( "FacePos9", PlayerInfo[ playerid ][ xFacePos ][ 8 ] );
	INI_Int( "SungMask", PlayerInfo[ playerid ][ xSungMask ] );
	INI_Float( "SungMaskPos1", PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ] );
	INI_Float( "SungMaskPos2", PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ] );
	INI_Float( "SungMaskPos3", PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ] );
	INI_Float( "SungMaskPos4", PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ] );
	INI_Float( "SungMaskPos5", PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ] );
	INI_Float( "SungMaskPos6", PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ] );
	INI_Float( "SungMaskPos7", PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] );
	INI_Float( "SungMaskPos8", PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] );
	INI_Float( "SungMaskPos9", PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] );
	INI_Int( "Cigare", PlayerInfo[ playerid ][ xCigare ] );
	INI_Int( "Upaljac", PlayerInfo[ playerid ][ xUpaljac ] );
	INI_Int( "BStil", PlayerInfo[ playerid ][ xBStil ] );
	INI_Int( "Registrovan", PlayerInfo[ playerid ][ xRegistrovan ] );
	INI_Float( "SHealth", PlayerInfo[ playerid ][ xSHealth ] );
	INI_Int( "BrojTelefona", PlayerInfo[ playerid ][ xBrojTelefona ] );
	INI_Int( "Vozacka", PlayerInfo[ playerid ][ xVozacka ] );
	INI_Int( "Licna", PlayerInfo[ playerid ][ xLicna ] );
	INI_Int( "TaxiLicenca", PlayerInfo[ playerid ][ xTaxLic ] );
	INI_Int( "Pasos", PlayerInfo[ playerid ][ xPasos ] );
	INI_Int( "JMBG", PlayerInfo[ playerid ][ xJMBG ] );
	INI_Int( "BrojLicne", PlayerInfo[ playerid ][ xBrojLk ] );
	INI_Int( "BrojPasosa", PlayerInfo[ playerid ][ xBrojPasosa ] );
	INI_Int( "Motorska", PlayerInfo[ playerid ][ xMotorska ] );
	INI_Int( "KamionskaC1", PlayerInfo[ playerid ][ xKamionskaC1 ] );
	INI_Int( "KamionskaC2", PlayerInfo[ playerid ][ xKamionskaC2 ] );
	INI_Int( "KamionskaC3", PlayerInfo[ playerid ][ xKamionskaC3 ] );
	INI_Int( "Brodska", PlayerInfo[ playerid ][ xBrodska ] );
	INI_Int( "Letelica", PlayerInfo[ playerid ][ xLetelica ] );
	INI_Int( "Osnovna", PlayerInfo[ playerid ][ xOsnovna ] );
	INI_Int( "Srednja", PlayerInfo[ playerid ][ xSrednja ] );
	INI_Int( "Fakultet", PlayerInfo[ playerid ][ xFakultet ] );
	INI_Int( "SkolaLimit", PlayerInfo[ playerid ][ xSkolaLimit ] );
	INI_Int( "Ubijen", PlayerInfo[ playerid ][ xUbijen ] );
	#if nerp_droga == 1
	INI_Int( "Drug1", PlayerInfo[ playerid ][ xDrug ][ 0 ] );
	INI_Int( "Drug2", PlayerInfo[ playerid ][ xDrug ][ 1 ] );
	INI_Int( "Drug3", PlayerInfo[ playerid ][ xDrug ][ 2 ] );
	INI_Int( "Drug4", PlayerInfo[ playerid ][ xDrug ][ 3 ] );
	INI_Int( "Drug5", PlayerInfo[ playerid ][ xDrug ][ 4 ] );
	INI_Int( "DrugCode1", PlayerInfo[ playerid ][ xDrugCode ][ 0 ] );
	INI_Int( "DrugCode2", PlayerInfo[ playerid ][ xDrugCode ][ 1 ] );
	INI_Int( "DrugCode3", PlayerInfo[ playerid ][ xDrugCode ][ 2 ] );
	INI_Int( "DrugCode4", PlayerInfo[ playerid ][ xDrugCode ][ 3 ] );
	INI_Int( "DrugCode5", PlayerInfo[ playerid ][ xDrugCode ][ 4 ] );
	#endif
	INI_Int( "Solna", PlayerInfo[ playerid ][ xSolna ] );
	INI_Int( "Pseudo", PlayerInfo[ playerid ][ xPseudo ] );
	INI_Int( "SodaB", PlayerInfo[ playerid ][ xSodaB ] );
	INI_Int( "CrveniF", PlayerInfo[ playerid ][ xCrveniF ] );
	INI_Int( "LysAcid", PlayerInfo[ playerid ][ xLysAcid ] );
	INI_Int( "DesVoda", PlayerInfo[ playerid ][ xDesVoda ] );
	INI_Int( "Marihuana", PlayerInfo[ playerid ][ xMarihuana ] );
	INI_Int( "Opium", PlayerInfo[ playerid ][ xOpium ] );
	INI_Int( "Kalcijum", PlayerInfo[ playerid ][ xKalcij ] );
	INI_Int( "AmonijumHlorid", PlayerInfo[ playerid ][ xAmonijH ] );
	INI_Int( "Kokain", PlayerInfo[ playerid ][ xKokain ] );
	INI_Int( "Kokain2", PlayerInfo[ playerid ][ xKokain2 ] );
	INI_Int( "MetilAmin", PlayerInfo[ playerid ][ xMetilAmin ] );
	INI_Int( "Hunger", PlayerInfo[ playerid ][ xHunger ] );
	INI_Int( "Toilet", PlayerInfo[ playerid ][ xToilet ] );
	INI_Bool( "HeroinAddict", PlayerInfo[ playerid ][ xHeroinAddict ] );
	INI_Int( "HeroinUsed", PlayerInfo[ playerid ][ xHeroinUsed ] );
	INI_Int( "HeroinIndicator", PlayerInfo[ playerid ][ xHeroinIndicator ] );
	INI_Bool( "CokeCrackAddict", PlayerInfo[ playerid ][ xCokeCrackAddict ] );
	INI_Int( "CokeCrackUsed", PlayerInfo[ playerid ][ xCokeCrackUsed ] );
	INI_Int( "CokeCrackIndicator", PlayerInfo[ playerid ][ xCokeCrackIndicator ] );
	INI_Bool( "MethAddict", PlayerInfo[ playerid ][ xMethAddict ] );
	INI_Int( "MethIndicator", PlayerInfo[ playerid ][ xMethIndicator ] );
	INI_Int( "MethUsed", PlayerInfo[ playerid ][ xMethUsed ] );
	INI_Bool( "Inekcija", PlayerInfo[ playerid ][ xInekcija ] );
	INI_Bool( "Toolkit", PlayerInfo[ playerid ][ xToolkit ] );
	INI_Int( "Property1", PlayerInfo[ playerid ][ xProperty ][ 0 ] );
	INI_Int( "Property2", PlayerInfo[ playerid ][ xProperty ][ 1 ] );
	INI_Int( "Property3", PlayerInfo[ playerid ][ xProperty ][ 2 ] );
	INI_Bool( "GunLicense", PlayerInfo[ playerid ][ xGunLicense ] );
	INI_Int( "TelefonBon", PlayerInfo[ playerid ][ xTelefonBon ] );
	INI_Int( "ModelTelefona", PlayerInfo[ playerid ][ xModelTelefona ] );
	INI_Int( "Snaga", PlayerInfo[ playerid ][ xSnaga ] );
	INI_Int( "Zatvor", PlayerInfo[ playerid ][ xZatvor ] );
	INI_Int( "ZatvorVreme", PlayerInfo[ playerid ][ xZatvorVreme ] );
	INI_Int( "Wanted", PlayerInfo[ playerid ][ xWanted ] );
	INI_Int( "Uhapsen", PlayerInfo[ playerid ][ xUhapsen ] );
	INI_Int( "PDUhapsio", PlayerInfo[ playerid ][ xPDUhapsio ] );
	INI_Int( "PDStatsTicket", PlayerInfo[ playerid ][ xPDStatsTicket ] );
	INI_Int( "PDStatsTicketMoney", PlayerInfo[ playerid ][ xPDStatsTicketMoney ] );
	INI_Int( "TakenWeps", PlayerInfo[ playerid ][ xTakenWeps ] );
	#if nerp_droga == 1
	INI_Int( "TakenDrugs", PlayerInfo[ playerid ][ xTakenDrugs ] );
	#endif
	INI_Int( "PocetniTut", PlayerInfo[ playerid ][ xPocetniTut ] );
	INI_Int( "AKod", PlayerInfo[ playerid ][ xAKod ] );
	INI_Int( "Sat", PlayerInfo[ playerid ][ xSat ] );
	INI_Int( "MaskID", PlayerInfo[ playerid ][ xMaskID ] );
	INI_Int( "BRacun", PlayerInfo[ playerid ][ xBRacun ] );
	INI_Int( "PreostaloZaOtplatu", PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] );
	INI_Int( "IznosRate", PlayerInfo[ playerid ][ xIznosRate ] );
	INI_Int( "IznosKredita", PlayerInfo[ playerid ][ xIznosKredita ] );
	INI_Int( "OnlineSati", PlayerInfo[ playerid ][ xOnlineSati ] );
	INI_Int( "Helper", PlayerInfo[ playerid ][ xHelper ] );
	INI_Int( "RPLearn", PlayerInfo[ playerid ][ xRPLearn ] );
	INI_Int( "Warn", PlayerInfo[ playerid ][ xWarn ] );
	INI_Int( "Mute", PlayerInfo[ playerid ][ xMute ] );
	INI_Float( "Marker1", PlayerInfo[ playerid ][ xMarker ][ 0 ] );
	INI_Float( "Marker2", PlayerInfo[ playerid ][ xMarker ][ 1 ] );
	INI_Float( "Marker3", PlayerInfo[ playerid ][ xMarker ][ 2 ] );
	INI_Int( "BrojNews", PlayerInfo[ playerid ][ xBrojNews ] );
	INI_Int( "OrgUgovor", PlayerInfo[ playerid ][ xOrgUgovor ] );
	INI_Int( "GpsLevel", PlayerInfo[ playerid ][ xGpsLevel ] );
	INI_Int( "Helmet", PlayerInfo[ playerid ][ xHelmet ] );
	INI_Int( "BanDays", PlayerInfo[ playerid ][ xBDays ] );
	INI_Int( "BanMonths", PlayerInfo[ playerid ][ xBMonths ] );
	INI_Int( "BanYear", PlayerInfo[ playerid ][ xBYears ] );
	INI_Int( "GradRank", PlayerInfo[ playerid ][ xGradRank ] );
	INI_Int( "SkriptaRank", PlayerInfo[ playerid ][ xSkriptaRank ] );
	INI_Int( "UlazBL", PlayerInfo[ playerid ][ xUlazBL ] );
	INI_Bool( "Boombox", PlayerInfo[ playerid ][ xBoombox ] );
	INI_Float( "HelmetPos1", PlayerInfo[ playerid ][ xHelmetPos ][ 0 ] );
	INI_Float( "HelmetPos2", PlayerInfo[ playerid ][ xHelmetPos ][ 1 ] );
	INI_Float( "HelmetPos3", PlayerInfo[ playerid ][ xHelmetPos ][ 2 ] );
	INI_Float( "HelmetPos4", PlayerInfo[ playerid ][ xHelmetPos ][ 3 ] );
	INI_Float( "HelmetPos5", PlayerInfo[ playerid ][ xHelmetPos ][ 4 ] );
	INI_Float( "HelmetPos6", PlayerInfo[ playerid ][ xHelmetPos ][ 5 ] );
	INI_Float( "HelmetPos7", PlayerInfo[ playerid ][ xHelmetPos ][ 6 ] );
	INI_Float( "HelmetPos8", PlayerInfo[ playerid ][ xHelmetPos ][ 7 ] );
	INI_Float( "HelmetPos9", PlayerInfo[ playerid ][ xHelmetPos ][ 8 ] );
	INI_Int( "Drzava", PlayerInfo[ playerid ][ xDrzava ] );
	INI_String( "Email", PlayerInfo[ playerid ][ xEmail ], 34 );
	INI_Int( "VIPLevel", PlayerInfo[ playerid ][ xVIPLevel ] );
	INI_Int( "HitmenCena", PlayerInfo[ playerid ][ xHitmenCena ] );
	INI_Int( "Objekt1", PlayerInfo[ playerid ][ xObject ][ 0 ] );
	INI_Int( "Objekt2", PlayerInfo[ playerid ][ xObject ][ 1 ] );
	INI_Int( "Objekt3", PlayerInfo[ playerid ][ xObject ][ 2 ] );
	INI_Int( "Objekt4", PlayerInfo[ playerid ][ xObject ][ 3 ] );
	INI_Int( "Objekt5", PlayerInfo[ playerid ][ xObject ][ 4 ] );
	INI_Int( "Objekt6", PlayerInfo[ playerid ][ xObject ][ 5 ] );
	INI_Int( "Objekt7", PlayerInfo[ playerid ][ xObject ][ 6 ] );
	INI_Int( "Objekt8", PlayerInfo[ playerid ][ xObject ][ 7 ] );
	INI_Int( "Objekt9", PlayerInfo[ playerid ][ xObject ][ 8 ] );
	INI_Int( "Objekt10", PlayerInfo[ playerid ][ xObject ][ 9 ] );
	INI_Int( "LesLimit", PlayerInfo[ playerid ][ xLesLimit ] );
	INI_Int( "KazneniUgovor", PlayerInfo[ playerid ][ xKazneniUgovor ] );
	INI_String( "OffPJail", PlayerInfo[ playerid ][ xOffPJail ], 64 );
	INI_String( "OffPPrison", PlayerInfo[ playerid ][ xOffPPrison ], 64 );
	INI_String( "OffPMute", PlayerInfo[ playerid ][ xOffPMute ], 64 );
	INI_Int( "StaffMin", PlayerInfo[ playerid ][ xStaffMin ] );
	INI_String( "LastLogin", PlayerInfo[ playerid ][ xLastLogin ], 64 );
	INI_Bool( "Married", PlayerInfo[ playerid ][ xMarried ] );
	INI_String( "MarriedTo", PlayerInfo[ playerid ][ xMarriedTo ], 24 );
	INI_Bool( "TogMob", PlayerInfo[ playerid ][ xTogMob ] );
	INI_Int( "HotelID", PlayerInfo[ playerid ][ xHotelID ] );
	INI_Int( "HotelRoom", PlayerInfo[ playerid ][ xHotelRoom ] );
	INI_Int( "Promoter", PlayerInfo[ playerid ][ xPromoter ] );
	INI_Int( "FieldID", PlayerInfo[ playerid ][ xFieldID ] );
	INI_Int( "Sljive", PlayerInfo[ playerid ][ xSljive ] );
	INI_Int( "Kruske", PlayerInfo[ playerid ][ xKruske ] );
	INI_Int( "Jabuke", PlayerInfo[ playerid ][ xJabuke ] );
	INI_Int( "Kupus", PlayerInfo[ playerid ][ xKupus ] );
	INI_Int( "Ruze", PlayerInfo[ playerid ][ xRuze ] );
	INI_Int( "SemeSljive", PlayerInfo[ playerid ][ xSemeSljive ] );
	INI_Int( "SemeKruske", PlayerInfo[ playerid ][ xSemeKruske ] );
	INI_Int( "SemeJabuke", PlayerInfo[ playerid ][ xSemeJabuke ] );
	INI_Int( "SemeKupusa", PlayerInfo[ playerid ][ xSemeKupusa ] );
	INI_Int( "SemeRuze", PlayerInfo[ playerid ][ xSemeRuze ] );
	INI_Int( "LottoNumber", PlayerInfo[ playerid ][ xLottoNumber ] );
	INI_Int( "LottoMoney", PlayerInfo[ playerid ][ xLottoMoney ] );
	INI_Int( "GarageID", PlayerInfo[ playerid ][ xGarageID ] );
	INI_Bool( "ImaBRacun", PlayerInfo[ playerid ][ xImaBRacun ] );
	INI_Int( "PlatniRacun", PlayerInfo[ playerid ][ xPlatniRacun ] );
	INI_Bool( "DonatorSlot", PlayerInfo[ playerid ][ xDonatorSlot ] );
	INI_Int( "PljackaVreme", PlayerInfo[ playerid ][ xPljackaVreme ] );
	INI_Bool( "LeaveJail", PlayerInfo[ playerid ][ xLeaveJail ] );
	INI_Int( "BailPrice", PlayerInfo[ playerid ][ xBailPrice ] );
	INI_Int( "HangarTime", PlayerInfo[ playerid ][ xHangarTime ] );
	INI_Int( "Event1Mesto", PlayerInfo[ playerid ][ xEvent1Mesto ] );
	INI_Int( "Event2Mesto", PlayerInfo[ playerid ][ xEvent2Mesto ] );
	INI_Int( "Event3Mesto", PlayerInfo[ playerid ][ xEvent3Mesto ] );
	INI_Int( "DMEventUbistva", PlayerInfo[ playerid ][ xDMEventUbistva ] );
	INI_Int( "RentID", PlayerInfo[ playerid ][ xRentID ] );
	INI_Int( "Zlato", PlayerInfo[ playerid ][ xZlato ] );
	INI_Int( "RezervniKljucevi", PlayerInfo[ playerid ][ xRezervniKljucevi ] );
	INI_Int( "RadarBodovi", PlayerInfo[ playerid ][ xRadarBodovi ] );
	INI_Bool( "DBO", PlayerInfo[ playerid ][ xDBO ] );
	INI_Int( "DBoja", PlayerInfo[ playerid ][ xDBoja ] );
	INI_Int( "RPPoen", PlayerInfo[ playerid ][ xRPPoen ] );
	INI_Int( "PodApoeni", PlayerInfo[ playerid ][ xPodApoeni ] );
	INI_Int( "Apoeni", PlayerInfo[ playerid ][ xApoeni ] );
	INI_Float( "VipTime", PlayerInfo[ playerid ][ xVipTime ] );
	INI_Int( "ZauzimanjeVreme", PlayerInfo[ playerid ][ xZauzimanjeVreme ] );
	INI_Int( "Poklon", PlayerInfo[ playerid ][ xPoklon ] );
	INI_Bool( "Paketic", PlayerInfo[ playerid ][ xPaketic ] );
	INI_String( "KljucKapije", PlayerInfo[ playerid ][ xKljucKapije ], MAX_PLAYER_NAME );
	INI_Int( "Svercer", PlayerInfo[ playerid ][ xSvercer ] );
	INI_Int( "BHD", PlayerInfo[ playerid ][ xBHD ] );
	INI_Int( "RCON", PlayerInfo[ playerid ][ xRCON ] );
	INI_Int( "Togn", PlayerInfo[ playerid ][ xTogn ] );
	INI_Int( "Ranac", PlayerInfo[ playerid ][ xRanac ] );

	INI_Int( "ZM", PlayerInfo[ playerid ][ xZMaska ] );
	INI_Int( "Knjizica", PlayerInfo[ playerid ][ xKnjizica ] );
	INI_Int( "Vakcina", PlayerInfo[ playerid ][ xVakcina ] );
	INI_Int( "Uputnica", PlayerInfo[ playerid ][ xUputnica ] );

	INI_Int( "Pin", PlayerInfo[ playerid ][ xPin ] );
	INI_Int( "DutyTime", PlayerInfo[ playerid ][ xDutyTime ] );
	INI_Int( "DJ", PlayerInfo[ playerid ][ xDJ ]);
	INI_Int( "OTD", PlayerInfo[ playerid ][ xOTD ]);
	INI_Int( "VokiToki", PlayerInfo[ playerid ][ xVokiToki ]);
	INI_Int( "Papagaj", PlayerInfo[ playerid ][ xPapagaj ]);
	INI_Int( "Banovan", PlayerInfo[ playerid ][ xBanovan ]);
	INI_Int( "BD0", PlayerInfo[ playerid ][ xBDatum ][0]);
	INI_Int( "BD1", PlayerInfo[ playerid ][ xBDatum ][1]);
	INI_Int( "BD2", PlayerInfo[ playerid ][ xBDatum ][2]);

	INI_String( "BReason", PlayerInfo[ playerid ][ xBReason ], 41 );

	INI_Int("SniperHeadshots", PlayerInfo[playerid][xSniperHeadshots]);
	INI_Int("PUBGKills", PlayerInfo[playerid][xPUBGKillsTotal]);
	INI_Int( "ZombieKills", PlayerInfo[ playerid ][ xZombieEventKills ] );
	return true;
}
/////////////////////////Nova Security Sys///////////////////////////////////////


//------------------------------------------------------------------------------
public LoadAntiCheat( name[ ], value[ ] ) {
	INI_Int( "WeaponHRezimRada", antiCheatSS[ WeaponHRezimRada ] );
	INI_Int( "TeleportHRezimRada", antiCheatSS[ TeleportHRezimRada ] );
	INI_Int( "HealthHRezimRada", antiCheatSS[ HealthHRezimRada ] );
	INI_Int( "SpeedHRezimRada", antiCheatSS[ SpeedHRezimRada ] );
	INI_Int( "JetPackHRezimRada", antiCheatSS[ JetPackHRezimRada ] );
	INI_Int( "MoneyHRezimRada", antiCheatSS[ MoneyHRezimRada ] );
	INI_Int( "FlyHRezimRada", antiCheatSS[ FlyHRezimRada ] );
	INI_Int( "TuningHRezimRada", antiCheatSS[ TuningHRezimRada ] );
	INI_Int( "VehRepRezimRada", antiCheatSS[ VehRepRezimRada ] );
	INI_Bool( "antiWeaponH", antiCheatSS[ antiWeaponH ] );
	INI_Bool( "antiTeleportH", antiCheatSS[ antiTeleportH ] );
	INI_Bool( "antiHealthH", antiCheatSS[ antiHealthH ] );
	INI_Bool( "antiArmourH", antiCheatSS[ antiArmourH ] );
	INI_Bool( "antiSpeedH", antiCheatSS[ antiSpeedH ] );
	INI_Bool( "antiJetPackH", antiCheatSS[ antiJetPackH ] );
	INI_Bool( "antiMoneyH", antiCheatSS[ antiMoneyH ] );
	INI_Bool( "antiFlyH", antiCheatSS[ antiFlyH ] );
	INI_Bool( "antiTuningH", antiCheatSS[ antiTuningH ] );
	INI_Bool( "antiVehRepair", antiCheatSS[ antiVehRepair ] );
	return 1;
}
public SaveAntiCheat( ) {
	new INI:File = INI_Open( "Ostalo/anticheat.ini" );
	INI_SetTag( File, "Informacije" );
	INI_WriteInt( File, "WeaponHRezimRada", antiCheatSS[ WeaponHRezimRada ] );
	INI_WriteInt( File, "TeleportHRezimRada", antiCheatSS[ TeleportHRezimRada ] );
	INI_WriteInt( File, "HealthHRezimRada", antiCheatSS[ HealthHRezimRada ] );
	INI_WriteInt( File, "SpeedHRezimRada", antiCheatSS[ SpeedHRezimRada ] );
	INI_WriteInt( File, "JetPackHRezimRada", antiCheatSS[ JetPackHRezimRada ] );
	INI_WriteInt( File, "MoneyHRezimRada", antiCheatSS[ MoneyHRezimRada ] );
	INI_WriteInt( File, "FlyHRezimRada", antiCheatSS[ FlyHRezimRada ] );
	INI_WriteInt( File, "TuningHRezimRada", antiCheatSS[ TuningHRezimRada ] );
	INI_WriteInt( File, "VehRepRezimRada", antiCheatSS[ VehRepRezimRada ] );
	INI_WriteBool( File, "antiWeaponH", antiCheatSS[ antiWeaponH ] );
	INI_WriteBool( File, "antiTeleportH", antiCheatSS[ antiTeleportH ] );
	INI_WriteBool( File, "antiHealthH", antiCheatSS[ antiHealthH ] );
	INI_WriteBool( File, "antiArmourH", antiCheatSS[ antiArmourH ] );
	INI_WriteBool( File, "antiSpeedH", antiCheatSS[ antiSpeedH ] );
	INI_WriteBool( File, "antiJetPackH", antiCheatSS[ antiJetPackH ] );
	INI_WriteBool( File, "antiMoneyH", antiCheatSS[ antiMoneyH ] );
	INI_WriteBool( File, "antiFlyH", antiCheatSS[ antiFlyH ] );
	INI_WriteBool( File, "antiTuningH", antiCheatSS[ antiTuningH ] );
	INI_WriteBool( File, "antiVehRepair", antiCheatSS[ antiVehRepair ] );
	INI_Close( File );
	return true;
}

///////////////////////////server stats/////////////////////////////////////


//-----------------------------------------------------------------------------

forward LoadServerStats( name[ ], value[ ] );
public LoadServerStats( name[ ], value[ ] )
{
	INI_Int( "RegistrovanihKorisnika", ServerInfo[ RegistrovanihKorisnika ] );
	INI_Int( "BanovanihKorisnika", ServerInfo[ BanovanihKorisnika ] );
	INI_Int( "KikovanihKorisnika", ServerInfo[ KikovanihKorisnika ] );
	INI_Int( "BrojWarnova", ServerInfo[ BrojWarnova ] );
	INI_Int( "BrojPosetaServeru", ServerInfo[ BrojPosetaServeru ] );
	INI_Bool( "HappyHours", ServerInfo[ HappyHours ] );
	INI_Int( "PocetniLevel", ServerInfo[ PocetniLevel ] );
	INI_Int( "PocetniNovaca", ServerInfo[ PocetniNovaca ] );
	INI_Bool( "KupovinaVozila", ServerInfo[ KupovinaVozila ] );
	INI_Bool( "Report", ServerInfo[ Report ] );
	INI_Bool( "Pitanja", ServerInfo[ Pitanja ] ); 
	INI_Int( "RekordServera", ServerInfo[ RekordServera ] );
	INI_Bool( "Oglasi", ServerInfo[ Oglasi ] );
	INI_Bool( "Registracija", ServerInfo[ Registracija ] );
	INI_Int( "Drva", ServerInfo[ Drva ] );
	INI_Int( "NovacBanka", ServerInfo[ NovacBanka ] );
	INI_Int( "ReactTime", ServerInfo[ ReactTime ] );
	INI_String( "ReactName", ServerInfo[ ReactName ], MAX_PLAYER_NAME );
	INI_Int( "Zlato", ServerInfo[ Zlato ] );
	INI_Int( "Namestaj", ServerInfo[ Namestaj ] );
	INI_Bool( "HappyJobs", ServerInfo[HappyJobs] );
	INI_String("SrwName", ServerInfo[ServerName], SERVER_NAME_STRING_LENGTH);
	return 1;
}

forward SaveServerStats( );
public SaveServerStats( )
{
	new INI:File = INI_Open( "Ostalo/serverstats.ini" );
	INI_SetTag( File, "Informacije" );
	INI_WriteInt( File, "RegistrovanihKorisnika", ServerInfo[ RegistrovanihKorisnika ] );
	INI_WriteInt( File, "BanovanihKorisnika", ServerInfo[ BanovanihKorisnika ] );
	INI_WriteInt( File, "KikovanihKorisnika", ServerInfo[ KikovanihKorisnika ] );
	INI_WriteInt( File, "BrojWarnova", ServerInfo[ BrojWarnova ] );
	INI_WriteInt( File, "BrojPosetaServeru", ServerInfo[ BrojPosetaServeru ] );
	INI_WriteBool( File, "HappyHours", ServerInfo[ HappyHours ] );
	INI_WriteInt( File, "PocetniLevel", ServerInfo[ PocetniLevel ] );
	INI_WriteInt( File, "PocetniNovaca", ServerInfo[ PocetniNovaca ] );
	INI_WriteBool( File, "KupovinaVozila", ServerInfo[ KupovinaVozila ] );
	INI_WriteBool( File, "Report", ServerInfo[ Report ] );
	INI_WriteBool( File, "Pitanja", ServerInfo[ Pitanja ] );
	INI_WriteInt( File, "RekordServera", ServerInfo[ RekordServera ] );
	INI_WriteBool( File, "Oglasi", ServerInfo[ Oglasi ] );
	INI_WriteBool( File, "Registracija", ServerInfo[ Registracija ] );
	INI_WriteInt( File, "Drva", ServerInfo[ Drva ] );
	INI_WriteInt( File, "NovacBanka", ServerInfo[ NovacBanka ] );
	INI_WriteInt( File, "ReactTime", ServerInfo[ ReactTime ] );
	INI_WriteString( File, "ReactName", ServerInfo[ ReactName ] );
	INI_WriteInt( File, "Zlato", ServerInfo[ Zlato ] );
	INI_WriteInt( File, "Namestaj", ServerInfo[ Namestaj ] );
	INI_WriteBool( File, "HappyJobs", ServerInfo[ HappyJobs ] );
	INI_WriteString(File,"SrwName",ServerInfo[ServerName]);
	INI_Close( File );
	return true;
}


///////////////////////////poslovi/////////////////////////////////////


forward SavePosloviInfo( );
public SavePosloviInfo( )
{
	new INI:File = INI_Open( "PlatePoslova/PosloviInfo.ini" );
	INI_SetTag( File, "Informacije" );
	//---------------------------------------------------------------------
	INI_WriteInt( File, "PlataKosaca", PosloviInfo[ PlataKosaca ] );
	INI_WriteInt( File, "BonusKosaca", PosloviInfo[ BonusKosaca ] );
	//---------------------------------------------------------------------
	INI_WriteInt( File, "GradjevinarZemljaPlata", PosloviInfo[ GradjevinarZemljaPlata ] );
	INI_WriteInt( File, "BonusGradjevinarZemlja", PosloviInfo[ BonusGradjevinarZemlja ] );
	//
	INI_WriteInt( File, "GradjevinarBetonPlata", PosloviInfo[ GradjevinarBetonPlata ] );
	INI_WriteInt( File, "BonusGradjevinarBeton", PosloviInfo[ BonusGradjevinarBeton ] );
	//------------------------------------------------------------------------
	INI_WriteInt( File, "DjubretarPlata", PosloviInfo[ DjubretarPlata ] );
	INI_WriteInt( File, "BonusDjubretara", PosloviInfo[ BonusDjubretara ] );
	//
	INI_WriteInt( File, "CistacUlicePlata", PosloviInfo[ CistacUlicePlata ] );
	INI_WriteInt( File, "BonusCistacaUlica", PosloviInfo[ BonusCistacaUlica ] );
	//---------------------------------------------------------------------------
	INI_WriteInt( File, "PilotBGPlata", PosloviInfo[ PilotBGPlata ] );
	INI_WriteInt( File, "BonusPilotBG", PosloviInfo[ BonusPilotBG ] );
	//
	INI_WriteInt( File, "PilotSAPlata", PosloviInfo[ PilotSAPlata ] );
	INI_WriteInt( File, "BonusPilotSA", PosloviInfo[ BonusPilotSA ] );
	//
	INI_WriteInt( File, "PilotZGPlata", PosloviInfo[ PilotZGPlata ] );
	INI_WriteInt( File, "BonusPilotZG", PosloviInfo[ BonusPilotZG ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "MehanicarMotorPlata", PosloviInfo[ MehanicarMotorPlata ] );
	INI_WriteInt( File, "MehanicarGumePlata", PosloviInfo[ MehanicarGumePlata ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "FarmerZitoPlata", PosloviInfo[ FarmerZitoPlata ] );
	INI_WriteInt( File, "BonusFarmerZito", PosloviInfo[ BonusFarmerZito ] );
	//
	INI_WriteInt( File, "FarmerBeracPlata", PosloviInfo[ FarmerBeracPlata ] );
	INI_WriteInt( File, "BonusBerac", PosloviInfo[ BonusBerac ] );
	//
	INI_WriteInt( File, "FarmerMlijekoPlata", PosloviInfo[ FarmerMlijekoPlata ] );
	INI_WriteInt( File, "BonusMlijeko", PosloviInfo[ BonusMlijeko ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "DostavljacPizzePlata", PosloviInfo[ DostavljacPizzePlata ] );
	INI_WriteInt( File, "BonusPizza", PosloviInfo[ BonusPizza ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "PlataTempo", PosloviInfo[ PlataTempo ] );
	INI_WriteInt( File, "BonusTempo", PosloviInfo[ BonusTempo ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "PlataBusBG", PosloviInfo[ PlataBusBG ] );
	INI_WriteInt( File, "BonusBusBG", PosloviInfo[ BonusBusBG ] );
	//
	INI_WriteInt( File, "PlataBusSA", PosloviInfo[ PlataBusSA ] );
	INI_WriteInt( File, "BonusBusSA", PosloviInfo[ BonusBusSA ] );
	//
	INI_WriteInt( File, "PlataBusZG", PosloviInfo[ PlataBusZG ] );
	INI_WriteInt( File, "BonusBusZG", PosloviInfo[ BonusBusZG ] );
	//--------------------------------------------------------------------------
	INI_WriteInt( File, "RudarGramiZlata", PosloviInfo[ RudarGramiZlata ] );
	//
	INI_WriteInt( File, "RudarDostavaPlata", PosloviInfo[ RudarDostavaPlata ] );
	INI_WriteInt( File, "BonusRudarDostava", PosloviInfo[ BonusRudarDostava ] );

	INI_Close( File );
	return true;
}

//-----------------------------------------------------------------------------

forward LoadPosloviInfo( name[ ], value[ ] );
public LoadPosloviInfo( name[ ], value[ ] )
{
	//---------------------------------------------------------------------
	INI_Int( "PlataKosaca", PosloviInfo[ PlataKosaca ] );
	INI_Int( "BonusKosaca", PosloviInfo[ BonusKosaca ] );
	//---------------------------------------------------------------------
	INI_Int( "GradjevinarZemljaPlata", PosloviInfo[ GradjevinarZemljaPlata ] );
	INI_Int( "BonusGradjevinarZemlja", PosloviInfo[ BonusGradjevinarZemlja ] );
	//
	INI_Int( "GradjevinarBetonPlata", PosloviInfo[ GradjevinarBetonPlata ] );
	INI_Int( "BonusGradjevinarBeton", PosloviInfo[ BonusGradjevinarBeton ] );
	//------------------------------------------------------------------------
	INI_Int( "DjubretarPlata", PosloviInfo[ DjubretarPlata ] );
	INI_Int( "BonusDjubretara", PosloviInfo[ BonusDjubretara ] );
	//
	INI_Int( "CistacUlicePlata", PosloviInfo[ CistacUlicePlata ] );
	INI_Int( "BonusCistacaUlica", PosloviInfo[ BonusCistacaUlica ] );
	//---------------------------------------------------------------------------
	INI_Int( "PilotBGPlata", PosloviInfo[ PilotBGPlata ] );
	INI_Int( "BonusPilotBG", PosloviInfo[ BonusPilotBG ] );
	//
	INI_Int( "PilotSAPlata", PosloviInfo[ PilotSAPlata ] );
	INI_Int( "BonusPilotSA", PosloviInfo[ BonusPilotSA ] );
	//
	INI_Int( "PilotZGPlata", PosloviInfo[ PilotZGPlata ] );
	INI_Int( "BonusPilotZG", PosloviInfo[ BonusPilotZG ] );
	//--------------------------------------------------------------------------
	INI_Int( "MehanicarMotorPlata", PosloviInfo[ MehanicarMotorPlata ] );
	INI_Int( "MehanicarGumePlata", PosloviInfo[ MehanicarGumePlata ] );
	//--------------------------------------------------------------------------
	INI_Int( "FarmerZitoPlata", PosloviInfo[ FarmerZitoPlata ] );
	INI_Int( "BonusFarmerZito", PosloviInfo[ BonusFarmerZito ] );
	//
	INI_Int( "FarmerBeracPlata", PosloviInfo[ FarmerBeracPlata ] );
	INI_Int( "BonusBerac", PosloviInfo[ BonusBerac ] );
	//
	INI_Int( "FarmerMlijekoPlata", PosloviInfo[ FarmerMlijekoPlata ] );
	INI_Int( "BonusMlijeko", PosloviInfo[ BonusMlijeko ] );
	//--------------------------------------------------------------------------
	INI_Int( "DostavljacPizzePlata", PosloviInfo[ DostavljacPizzePlata ] );
	INI_Int( "BonusPizza", PosloviInfo[ BonusPizza ] );
	//--------------------------------------------------------------------------
	INI_Int( "PlataTempo", PosloviInfo[ PlataTempo ] );
	INI_Int( "BonusTempo", PosloviInfo[ BonusTempo ] );
	//--------------------------------------------------------------------------
	INI_Int( "PlataBusBG", PosloviInfo[ PlataBusBG ] );
	INI_Int( "BonusBusBG", PosloviInfo[ BonusBusBG ] );
	//
	INI_Int( "PlataBusSA", PosloviInfo[ PlataBusSA ] );
	INI_Int( "BonusBusSA", PosloviInfo[ BonusBusSA ] );
	//
	INI_Int( "PlataBusZG", PosloviInfo[ PlataBusZG ] );
	INI_Int( "BonusBusZG", PosloviInfo[ BonusBusZG ] );
	//--------------------------------------------------------------------------
	INI_Int( "RudarGramiZlata", PosloviInfo[ RudarGramiZlata ] );
	//
	INI_Int( "RudarDostavaPlata", PosloviInfo[ RudarDostavaPlata ] );
	INI_Int( "BonusRudarDostava", PosloviInfo[ BonusRudarDostava ] );

	return true;
}


///////////////////////////admin/////////////////////////////////////

public OcitajAdmina( playerid, name[ ], value[ ] ) {

	INI_Int( "aTBan", AI[ playerid ][ aTBan ] );
	INI_Int( "aTWarn", AI[ playerid ][ aTWarn ] );
	INI_Int( "aTKick", AI[ playerid ][ aTKick ] );
	INI_Int( "aTCharge", AI[ playerid ][ aTCharge ] );
	INI_Int( "aTJail", AI[ playerid ][ aTJail ] );
	INI_Int( "aTUnjail", AI[ playerid ][ aTUnjail ] );
	INI_Int( "aTUnwarn", AI[ playerid ][ aTUnwarn ] );
	INI_Int( "aTUnban", AI[ playerid ][ aTUnban ] );
	INI_Int( "aTPM", AI[ playerid ][ aTPM ] );
	return 1;
}
//------------------------------------------------------------------------------
public SacuvajAdmina( playerid ) {
	new INI:File = INI_Open( Admini( playerid ) );
	INI_SetTag( File, "Informacije" );
	INI_WriteInt( File, "aTBan", AI[ playerid ][ aTBan ] );
	INI_WriteInt( File, "aTWarn", AI[ playerid ][ aTWarn ] );
	INI_WriteInt( File, "aTKick", AI[ playerid ][ aTKick ] );
	INI_WriteInt( File, "aTCharge", AI[ playerid ][ aTCharge ] );
	INI_WriteInt( File, "aTJail", AI[ playerid ][ aTJail ] );
	INI_WriteInt( File, "aTUnjail", AI[ playerid ][ aTUnjail ] );
	INI_WriteInt( File, "aTUnwarn", AI[ playerid ][ aTUnwarn ] );
	INI_WriteInt( File, "aTUnban", AI[ playerid ][ aTUnban ] );
	INI_WriteInt( File, "aTPM", AI[ playerid ][ aTPM ] );
	INI_Close( File );
	return true;
}

///////////////////////////inventory/////////////////////////////////////


forward SaveInventory( playerid );
public SaveInventory( playerid ) {
	new string[ 15 ];
	new INI:File = INI_Open( Inventory( playerid ) );
	
	INI_SetTag( File, "Informacije" );
	
	for( new i = 0; i < MAX_INVENTORY; i++) {
	
		format( string, sizeof( string ), "Exist%d", i );
		INI_WriteBool( File, string, inventoryInfo[ playerid ][ i ][ invExists ] );

		format( string, sizeof( string ), "Name%d", i );
		INI_WriteString( File, string, inventoryInfo[ playerid ][ i ][ invItem ] );

		format( string, sizeof( string ), "Model%d", i );
		INI_WriteInt( File, string, inventoryInfo[ playerid ][ i ][ invModel ] );

		format( string, sizeof( string ), "Quantity%d", i );
		INI_WriteInt( File, string, inventoryInfo[ playerid ][ i ][ invQuantity ] );
	}
	
	INI_Close( File );
	return true;
}

forward LoadInventory( playerid, name[ ], value[ ] );
public LoadInventory( playerid, name[ ], value[ ] ) {
	new string[ 15 ];

	for( new i = 0; i < MAX_INVENTORY; i++) {

		format( string, sizeof( string ), "Exist%d", i );
		INI_Bool( string, inventoryInfo[ playerid ][ i ][ invExists ] );

		format( string, sizeof( string ), "Name%d", i );
		INI_String( string, inventoryInfo[ playerid ][ i ][ invItem ], 32 );

		format( string, sizeof( string ), "Model%d", i );
		INI_Int( string, inventoryInfo[ playerid ][ i ][ invModel ] );

		format( string, sizeof( string ), "Quantity%d", i );
		INI_Int( string, inventoryInfo[ playerid ][ i ][ invQuantity ] );

	}
	return 1;
}

forward ProveraInvOruzja( playerid, ID );
public ProveraInvOruzja( playerid, ID ) {

	if( playerid != IPI ) {
	
		Dimi_KillTimer( ProveriInvOruzje[ playerid ] );

		if( ID >= 0 && ID < MAX_INVENTORY ) {

			for( new i = 0; i < 47; i++ ) {
				if( ( WeaponInfos[ i ][ wModel ] >= 321 && WeaponInfos[ i ][ wModel ] <= 372 ) && WeaponInfos[ i ][ wModel ] == inventoryInfo[ playerid ][ ID ][ invModel ] ) {
					OruzjeUInventoriju[ playerid ]++;
					break;
				}
			}
		}

		if( ID+1 < MAX_INVENTORY ) ProveriInvOruzje[ playerid ] = SetTimerEx( "ProveraInvOruzja", 10, false, "dd", playerid, ID+1 );
	}
	return 1;
}


////////////////////////////stats////////////////////////////////////


LoadStats(playerid); public LoadStats(playerid)
{
	new player_ingame_nickname[100];
	format(player_ingame_nickname,sizeof(player_ingame_nickname),"%s",ImeIgraca(playerid));
	PlayerTextDrawSetString( playerid, NickIgraca[ playerid ], player_ingame_nickname );
	new nxtlevel = PlayerInfo[ playerid ][ xLevel ]+1,
		expamount = nxtlevel*levelexp,
		exp = PlayerInfo[ playerid ][ xRespekt ],
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
		PlayerInfo[ playerid ][ xPromoter ],
		PlayerInfo[ playerid ][ xRPPoen ] );

	PlayerTextDrawSetString(playerid,PlayerStats[3][playerid],str);

	format( str, sizeof( str ), 
			"~n~~n~apoeni: %i\
			~n~posao:~n~%s\
			~n~ugovor: %ih\
			~n~novac: %i $\
			~n~banka: %i $",
		PlayerInfo[ playerid ][ xApoeni ],
		getJobName(PlayerInfo[ playerid ][ xPosao ]),
		PlayerInfo[ playerid ][ xUgovor ],
		PlayerInfo[ playerid ][ xNovac ],
		PlayerInfo[ playerid ][ xBRacun ]);

	PlayerTextDrawSetString(playerid,PlayerStats[4][playerid],str);
	//6"zlato: 999999g~n~materijali: 9999~n~tel br: 999999~n~brak: ~n~~y~mustafa_kulovac~n~hapsenja: 999"
	format( str, sizeof( str ), 
			"zlato: %i g\
			~n~materijali: %i\
			~n~tel br: %i\
			~n~brak: \
			~n~~y~%s\
			~n~hapsenja: %i",
		PlayerInfo[ playerid ][ xZlato ],
		PlayerInfo[ playerid ][ xMaterijali ],
		PlayerInfo[ playerid ][ xBrojTelefona ],
		PlayerInfo[ playerid ][ xMarriedTo ],
		PlayerInfo[ playerid ][ xUhapsen ]);

	PlayerTextDrawSetString(playerid,PlayerStats[6][playerid],str);
	//7"organizacija:~n~~y~saobracajna policija~n~~w~org rank: 6~n~org kazna: 7h"
	format( str, sizeof( str ), 
			"organizacija:~n~\
			~y~%s\
			~n~~w~org rank: %i\
			~n~org kazna: %ih",
		OI[PlayerInfo[playerid][xClan]][oName],
		PlayerInfo[ playerid ][ xRank ],
		PlayerInfo[ playerid ][ xKazneniUgovor ]);

	PlayerTextDrawSetString(playerid,PlayerStats[7][playerid],str);


	//8"vozilo 1: nema~n~vozilo 2: nema~n~vozilo 3: nema~n~vozilo 4: nema~n~"
	format( str, sizeof( str ), 
			"~w~vozilo 1: ~y~%i\
			~n~~w~vozilo 2: ~y~%i\
			~n~~w~vozilo 3: ~y~%i\
			~n~~w~vozilo 4: ~y~%i~n~",
		PlayerInfo[ playerid ][ xVoziloID ][ 0 ],
		PlayerInfo[ playerid ][ xVoziloID ][ 1 ],
		PlayerInfo[ playerid ][ xVoziloID ][ 2 ],
		PlayerInfo[ playerid ][ xVoziloID ][ 3 ]);

	PlayerTextDrawSetString(playerid,PlayerStats[8][playerid],str);

	//10"imovina 1: nema~n~imovina 2: nema~n~imovina 3: nema"
	format( str, sizeof( str ), 
			"~w~imovina 1: ~y~%i\
			~n~~w~imovina 2: ~y~%i\
			~n~~w~imovina 3: ~y~%i",
		PlayerInfo[ playerid ][ xProperty ][ 0 ],
		PlayerInfo[ playerid ][ xProperty ][ 1 ],
		PlayerInfo[ playerid ][ xProperty ][ 2 ]);

	PlayerTextDrawSetString(playerid,PlayerStats[10][playerid],str);
	//11"firma: nema~n~garaza: nema~n~imanje: nema"
	format( str, sizeof( str ), 
			"~w~firma: ~y~%i\
			~n~~w~garaza: ~y~%i\
			~n~~w~imanje: ~y~%i",
		PlayerInfo[ playerid ][ xFirmaID ],
		PlayerInfo[ playerid ][ xGarageID ],
		PlayerInfo[ playerid ][ xFieldID ]);

	PlayerTextDrawSetString(playerid,PlayerStats[11][playerid],str);
	PlayerTextDrawHide(playerid, SkinIgraca[playerid]);
	PlayerTextDrawSetPreviewModel(playerid,SkinIgraca[playerid], PlayerInfo[playerid][xSkin]);
	PlayerTextDrawShow(playerid, SkinIgraca[playerid]);
	return 1;
}

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

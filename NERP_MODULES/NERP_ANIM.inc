//******************************************************************************
/*
			|| Animacije System by Balkan Story | DentisT ||
			
								Izradio:DentisT
						 Procesor komandi: ZCMD(Zeex)
						 Credits:   STREAMER, SSCANF2
								Verzija: 1.0
*/
//******************************************************************************


#define SPECIAL_ACTION_PISSING      68


new ANIM_gPlayerUsingLoop[ MAX_PLAYERS ];
new ANIM_gPlayerPreloaded[ MAX_PLAYERS ];
new ANIM_animation[ MAX_PLAYERS ];
//new PlayerText:AnimacijeTD[MAX_PLAYERS];

//------------------------------------------------

ANIM_IsKeyJustDown(key, newkeys, oldkeys)
{
	if((newkeys & key) && !(oldkeys & key)) return 1;
	return 0;
}

//-------------------------------------------------

ANIM_OnePlayAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
    //if (ANIM_gPlayerUsingLoop[playerid] == 1) PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
	ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, 1);
	ANIM_animation[playerid]++;
}

//-------------------------------------------------

ANIM_LoopingAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	//if (ANIM_gPlayerUsingLoop[playerid] == 1) PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
    ANIM_gPlayerUsingLoop[playerid] = 1;
    ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, 1);
    //PlayerTextDrawShow(playerid,AnimacijeTD[playerid]);
    ANIM_animation[playerid]++;
}

//-------------------------------------------------

StopANIM_LoopingAnim(playerid)
{
	ANIM_gPlayerUsingLoop[playerid] = 0;
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
}

//-------------------------------------------------

ANIM_PreloadLibSys(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0, 1);
}

//====================== || PUBLICI || =======================================
ANIM_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
public ANIM_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(!ANIM_gPlayerUsingLoop[playerid]) return;
	if(ANIM_IsKeyJustDown(KEY_HANDBRAKE,newkeys,oldkeys))
	{
	    StopANIM_LoopingAnim(playerid);
        //PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
        ANIM_animation[playerid] = 0;
    }
}
//------------------------------------------------
ANIM_OnPlayerDeath(playerid, killerid, reason);
public ANIM_OnPlayerDeath(playerid, killerid, reason)
{
	if(ANIM_gPlayerUsingLoop[playerid])
	{
        ANIM_gPlayerUsingLoop[playerid] = 0;
        //PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
	}
 	return 1;
}
//-------------------------------------------------
ANIM_OnPlayerSpawn(playerid);
public ANIM_OnPlayerSpawn(playerid)
{
	if(!ANIM_gPlayerPreloaded[playerid])
	{
   		ANIM_PreloadLibSys(playerid,"BOMBER");
   		ANIM_PreloadLibSys(playerid,"RAPPING");
    	ANIM_PreloadLibSys(playerid,"SHOP");
   		ANIM_PreloadLibSys(playerid,"BEACH");
   		ANIM_PreloadLibSys(playerid,"SMOKING");
    	ANIM_PreloadLibSys(playerid,"FOOD");
    	ANIM_PreloadLibSys(playerid,"ON_LOOKERS");
    	ANIM_PreloadLibSys(playerid,"DEALER");
		ANIM_PreloadLibSys(playerid,"CRACK");
		ANIM_PreloadLibSys(playerid,"CARRY");
		ANIM_PreloadLibSys(playerid,"COP_AMBIENT");
		ANIM_PreloadLibSys(playerid,"PARK");
		ANIM_PreloadLibSys(playerid,"INT_HOUSE");
		ANIM_PreloadLibSys(playerid,"FOOD");
		ANIM_PreloadLibSys(playerid,"PED");
		ANIM_gPlayerPreloaded[playerid] = 1;
	}
	return 1;
}
//-------------------------------------------------
ANIM_OnPlayerConnect(playerid);
public ANIM_OnPlayerConnect(playerid)
{
	// Init our text display
	/*AnimacijeTD[playerid] = CreatePlayerTextDraw(playerid, 507.111236, 409.670928, "~b~DESNI KLIK ~w~za prekid animacije");
	PlayerTextDrawLetterSize(playerid, AnimacijeTD[playerid], 0.171777, 1.276444);
	PlayerTextDrawAlignment(playerid, AnimacijeTD[playerid], 1);
	PlayerTextDrawColor(playerid, AnimacijeTD[playerid], -1);
	PlayerTextDrawSetShadow(playerid, AnimacijeTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, AnimacijeTD[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, AnimacijeTD[playerid], 51);
	PlayerTextDrawFont(playerid, AnimacijeTD[playerid], 2);
	PlayerTextDrawSetProportional(playerid, AnimacijeTD[playerid], 1);*/

	ANIM_gPlayerUsingLoop[playerid] = 0;
	ANIM_gPlayerPreloaded[playerid] = 0;
 	StopANIM_LoopingAnim(playerid);
  	//PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
   	ANIM_animation[playerid] = 0;
	return 1;
}

//-------------------------------------------------

ANIM_OnFilterScriptInit();
public ANIM_OnFilterScriptInit()
{
	print(" ");
	print(" ");
	print("----------------------------------------------------------");
	print("DentisT animacije: system, status - uspjesno ucitano!");
	print("----------------------------------------------------------");
	print(" ");
	print(" ");
	return 1;
}

//============================ | ANIMACIJE | ===================================================

//------------------------------------------------------------------------------
CMD:handsup(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "ROB_BANK","SHP_HandsUp_Scr", 4.0, 0, 1, 1, 1, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cellin(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cellout(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
	return 1;
}
//------------------------------------------------------------------------------
CMD:drunk(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:bomb(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ClearAnimations(playerid);
	ANIM_LoopingAnim(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0); // Place Bomb
	return 1;
}
//------------------------------------------------------------------------------
CMD:getarrested(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid,"ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1); // Gun Arrest
	return 1;
}
//------------------------------------------------------------------------------
CMD:laugh(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0); // Laugh
	return 1;
}
//------------------------------------------------------------------------------
CMD:lookout(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0); // Rob Lookout
	return 1;
}
//------------------------------------------------------------------------------
CMD:robman(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0); // Rob
	return 1;
}
//------------------------------------------------------------------------------
CMD:crossarms(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1); // Arms crossed
	return 1;
}
//------------------------------------------------------------------------------
CMD:lay(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 0, 0); // Lay down
	return 1;
}
//------------------------------------------------------------------------------
CMD:hide(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0); // Taking Cover
	return 1;
}
//------------------------------------------------------------------------------
CMD:vomit(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0); // Vomit BAH!
	return 1;
}
//------------------------------------------------------------------------------
CMD:eat(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0); // Eat Burger
	return 1;
}
//------------------------------------------------------------------------------
CMD:wave(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0); // Wave
	return 1;
}
//------------------------------------------------------------------------------
CMD:slapass(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0); // Ass Slapping
	return 1;
}
//------------------------------------------------------------------------------
CMD:deal(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_OnePlayAnim(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0); // Deal Drugs
	return 1;
}
//------------------------------------------------------------------------------
CMD:crack(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0); // Dieing of Crack
	return 1;
}
//------------------------------------------------------------------------------
CMD:wall(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
	ANIM_LoopingAnim(playerid, "ped","HIT_wall",4.1,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:smoke(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /smoke [1-4]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0); // male
    if(brojic == 2) ANIM_LoopingAnim(playerid,"SMOKING", "F_smklean_loop", 4.0, 1, 0, 0, 0, 0); //female
    if(brojic == 3) ANIM_LoopingAnim(playerid,"SMOKING","M_smkstnd_loop", 4.0, 1, 0, 0, 0, 0); // standing-fucked
    if(brojic == 4) ANIM_LoopingAnim(playerid,"SMOKING","M_smk_out", 4.0, 1, 0, 0, 0, 0); // standing

	return 1;
}
//------------------------------------------------------------------------------
CMD:ghand(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /ghand [1-7]");

   	if(brojic == 1) ANIM_LoopingAnim(playerid,"GHANDS","gsign1",4.1,1,1,1,1,1);
   	if(brojic == 2) ANIM_LoopingAnim(playerid,"GHANDS","gsign1LH",4.1,0,1,1,1,1);
   	if(brojic == 3) ANIM_LoopingAnim(playerid,"GHANDS","gsign2",4.1,0,1,1,1,1);
   	if(brojic == 4) ANIM_LoopingAnim(playerid,"GHANDS","gsign2LH",4.1,0,1,1,1,1);
   	if(brojic == 5) ANIM_LoopingAnim(playerid,"GHANDS","gsign3",4.1,0,1,1,1,1);
   	if(brojic == 6) ANIM_LoopingAnim(playerid,"GHANDS","gsign3LH",4.1,0,1,1,1,1);
   	if(brojic == 7) ANIM_LoopingAnim(playerid,"GHANDS","gsign4",4.1,0,1,1,1,1);


	return 1;
}
//------------------------------------------------------------------------------
CMD:caranim(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"CAR","Tap_hand",4.1,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:no(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"PED","endchat_01",4.1,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:crawl(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"PED","CAR_crawloutRHS",4.1,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:comeon(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"RYDER","RYD_Beckon_01",4.1,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fuckit(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"RYDER","RYD_Beckon_03",4.1,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:groundsit(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:scared(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"FOOD","EAT_Vomit_SK", 4.1, 0, 1, 1, 1, 1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:chat(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","IDLE_CHAT",4.0,1,0,0,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:celebrate(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"Freeweights","gym_free_celebrate",4.1,1,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fucku(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"PED","fucku",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:taichi(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fall(playerid, params[])
{
    ANIM_LoopingAnim(playerid,"PED","KO_skid_front",4.1,0,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fallback(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid, "PED","FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:kiss(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid, "KISSING", "Playa_Kiss_02", 3.0, 1, 1, 1, 1, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:injured(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:sup(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /sup[1-3]");
	if(brojic == 1) ANIM_OnePlayAnim(playerid,"GANGS","hndshkba",4.0,0,0,0,0,0);
	if(brojic == 2) ANIM_OnePlayAnim(playerid,"GANGS","hndshkda",4.0,0,0,0,0,0);
	if(brojic == 3) ANIM_OnePlayAnim(playerid,"GANGS","hndshkfa_swt",4.0,0,0,0,0,0);

	return 1;
}
//------------------------------------------------------------------------------
CMD:rap(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /rap[1-4]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"RAPPING","RAP_A_Loop",4.0,1,0,0,0,0);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"RAPPING","RAP_C_Loop",4.0,1,0,0,0,0);
	if(brojic == 3) ANIM_LoopingAnim(playerid,"GANGS","prtial_gngtlkD",4.0,1,0,0,0,0);
	if(brojic == 4) ANIM_LoopingAnim(playerid,"GANGS","prtial_gngtlkH",4.0,1,0,0,1,1);

	return 1;
}
//------------------------------------------------------------------------------
CMD:push(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:akick(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"POLICE","Door_Kick",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:spray(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"SPRAYCAN","spraycan_full",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:medic(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"MEDIC","CPR",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:koface(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","KO_shot_face",4.0,0,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:kostomach(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","KO_shot_stom",4.0,0,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:exhaust(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","IDLE_tired",3.0,1,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:leftslap(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"PED","BIKE_elbowL",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:hoodfrisked(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"POLICE","crm_drgbst_01",4.0,0,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:lightcig(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"SMOKING","M_smk_in",3.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:tapcig(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"SMOKING","M_smk_tap",3.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:box(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"GYMNASIUM","GYMshadowbox",4.0,1,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:wankin(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PAULNMAC", "wank_loop", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:lay2(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"SUNBATHE","Lay_Bac_in",3.0,0,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:sit(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_LoopingAnim(playerid,"PED","SEAT_IDLE",4.1,0,0,0,1,1);
    //ApplyAnimation(playerid,"PED","SEAT_IDLE",4,0,0,0, 1,0,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cop(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"SWORD","sword_block",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cop1(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"COP_AMBIENT","Coplook_think",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cop2(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"COP_AMBIENT","Copbrowse_in",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cop3(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"FINALE","FIN_Cop1_ClimbOut2",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:copstop(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    ANIM_OnePlayAnim(playerid,"COP_DVBYZ","COP_Dvby_FT",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fall1(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_OnePlayAnim(playerid,"SWORD","Sword_Hit_3",50.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:police(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /police [0-9]");

    if(brojic == 0) ANIM_OnePlayAnim(playerid,"POLICE","plc_drgbst_02",50.0,0,1,1,1,1);
	if(brojic == 1) ANIM_OnePlayAnim(playerid,"POLICE","CopTraf_Away",50.0,0,1,1,1,1);
   	if(brojic == 2) ANIM_OnePlayAnim(playerid,"POLICE","CopTraf_Come",50.0,0,1,1,1,1);
   	if(brojic == 3) ANIM_OnePlayAnim(playerid,"POLICE","CopTraf_Left",50.0,0,1,1,1,1);
   	if(brojic == 4) ANIM_OnePlayAnim(playerid,"POLICE","CopTraf_Stop",50.0,0,1,1,1,1);
   	if(brojic == 5) ANIM_OnePlayAnim(playerid,"POLICE","COP_getoutcar_LHS",50.0,0,1,1,1,1);
   	if(brojic == 6) ANIM_OnePlayAnim(playerid,"POLICE","Cop_move_FWD",50.0,0,1,1,1,1);
   	if(brojic == 7) ANIM_OnePlayAnim(playerid,"POLICE","crm_drgbst_01",50.0,0,1,1,1,1);
   	if(brojic == 8) ANIM_OnePlayAnim(playerid,"POLICE","Door_Kick",50.0,0,1,1,1,1);
   	if(brojic == 9) ANIM_OnePlayAnim(playerid,"POLICE","plc_drgbst_01",50.0,0,1,1,1,1);


	return 1;
}
//------------------------------------------------------------------------------
CMD:elbow(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_OnePlayAnim(playerid,"FIGHT_D","FightD_3",4.0,0,1,1,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fstance(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_LoopingAnim(playerid,"FIGHT_D","FightD_IDLE",4.0,1,1,1,1,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:lowthrow(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_OnePlayAnim(playerid,"GRENADE","WEAPON_throwu",3.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:highthrow(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_OnePlayAnim(playerid,"GRENADE","WEAPON_throw",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:dealstance(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_LoopingAnim(playerid,"DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:piss(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_LoopingAnim(playerid,"PAULNMAC", "Piss_in", 3.0, 0, 0, 0, 0, 0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:basket(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /basket [1-6]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"BSKTBALL","BBALL_idleloop",4.0,1,0,0,0,0);
	if(brojic == 2) ANIM_OnePlayAnim(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
	if(brojic == 3) ANIM_OnePlayAnim(playerid,"BSKTBALL","BBALL_pickup",4.0,0,0,0,0,0);
	if(brojic == 4) ANIM_LoopingAnim(playerid,"BSKTBALL","BBALL_run",4.1,1,1,1,1,1);
	if(brojic == 5) ANIM_LoopingAnim(playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
	if(brojic == 6) ANIM_LoopingAnim(playerid,"BSKTBALL","BBALL_Dnk",4.0,1,0,0,0,0);

	return 1;
}
//------------------------------------------------------------------------------
CMD:reload(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /reload [1-2]");
	if(brojic == 1) ANIM_OnePlayAnim(playerid,"COLT45","colt45_reload",4.0,0,0,0,0,1);
	if(brojic == 2) ANIM_OnePlayAnim(playerid,"UZI","UZI_reload",4.0,0,0,0,0,0);
	return 1;
}
//------------------------------------------------------------------------------
CMD:gwalk(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /gwalk [1-2]");
	if(brojic == 1) ANIM_LoopingAnim(playerid,"PED","WALK_gang1",4.1,1,1,1,1,1);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"PED","WALK_gang2",4.1,1,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:fwalk(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_LoopingAnim(playerid,"PED","WOMAN_walksexy",4.1,1,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:walk(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ANIM_LoopingAnim(playerid,"PED","WALK_civi",4.1,1,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:aim(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /aim [1-3]");
	if(brojic == 1) ANIM_LoopingAnim(playerid,"PED","gang_gunstand",4.0,1,1,1,1,1);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"PED","Driveby_L",4.0,0,1,1,1,1);
	if(brojic == 3) ANIM_LoopingAnim(playerid,"PED","Driveby_R",4.0,0,1,1,1,1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:riot(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /riot [1-3]");
	if(brojic == 1) ANIM_LoopingAnim(playerid,"RIOT","RIOT_shout",4.0,1,0,0,0,0);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"RIOT","RIOT_CHANT",4.0,1,1,1,1,0);
	if(brojic == 3) ANIM_OnePlayAnim(playerid,"RIOT","RIOT_FUKU",2.0,0,0,0,0,0);

	return 1;
}
//------------------------------------------------------------------------------
CMD:lean(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /lean [1-2]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"GANGS","leanIDLE",4.0,0,1,1,1,0);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"MISC","Plyrlean_loop",4.0,0,1,1,1,0);
	   	
	return 1;
}
//------------------------------------------------------------------------------
CMD:bat(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /bat [1-2]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"CRACK","Bbalbat_Idle_01",4.1,0,1,1,1,1);
	if(brojic == 2) ANIM_LoopingAnim(playerid,"CRACK","Bbalbat_Idle_02",4.1,0,1,1,1,1);

	return 1;
}
//------------------------------------------------------------------------------
CMD:clear(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
   	ApplyAnimation(playerid, "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0, 1);
	return 1;
}
//------------------------------------------------------------------------------
CMD:strip(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /strip [1-7]");

	if(brojic == 1) ANIM_LoopingAnim(playerid,"STRIP", "strip_A", 4.1, 1, 1, 1, 1, 1 );
	if(brojic == 2) ANIM_LoopingAnim(playerid,"STRIP", "strip_B", 4.1, 1, 1, 1, 1, 1 );
	if(brojic == 3) ANIM_LoopingAnim(playerid,"STRIP", "strip_C", 4.1, 1, 1, 1, 1, 1 );
	if(brojic == 4) ANIM_LoopingAnim(playerid,"STRIP", "strip_D", 4.1, 1, 1, 1, 1, 1 );
	if(brojic == 5) ANIM_LoopingAnim(playerid,"STRIP", "strip_E", 4.1, 1, 1, 1, 1, 1 );
 	if(brojic == 6) ANIM_LoopingAnim(playerid,"STRIP", "strip_F", 4.1, 1, 1, 1, 1, 1 );
	if(brojic == 7) ANIM_LoopingAnim(playerid,"STRIP", "strip_G", 4.1, 1, 1, 1, 1, 1 );

	return 1;
}
//------------------------------------------------------------------------------
CMD:dance(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,-1,"{FF0000}GRESKA: {FFFFFF}Ne mozete animacije koristiti u vozilu!");
    new brojic;
    if( sscanf( params, "i", brojic ) ) return SendClientMessage(playerid,-1,"KORISTENJE: /dance [1-4]");

	if(brojic == 1) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
	if(brojic == 2) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
	if(brojic == 3) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
	if(brojic == 4) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);

	return 1;
}
//------------------------------------------------------------------------------

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


///////KONST////////////
#define NERP_EDITING_POS (0)
#define NERP_EDITING_ROT (1)

#define NERP_OBJECT_GLOBAL (0)
#define NERP_OBJECT_PLAYER (1)
#define NERP_OBJECT_ATTACHED (2)

#define NERP_EDITING_GLOBALOBJ_CALLBACK "OnPlayerEditDynamicObject"
#define NERP_EDITING_PLAYEROBJ_CALLBACK "OnPlayerEditPlayerObject"

#define NERP_DEFAULT_UPDATE_RATE (0.01)

////////VARIJABLE////////////////
enum NERP_PlayerEditInfo
{
	EditedObject,
	EditedAttachedObject,
	ObjectType,
	Float:EditedObjectPos[3],
	Float:EditedObjectRot[3],
	Float:StartPos[3],
	Float:StartRot[3],
	bool:Editing,
	EditingMode,
	Float:UpdateRate
}

new PlayerEditInfo[MAX_PLAYERS][NERP_PlayerEditInfo];

////////////FUNKCIJE//////////////////
stock ShowPlayerEditingMenu(playerid, bool:show)
{
	if(show)
	{
		PlayerEditInfo[playerid][Editing] = true;
		for(new i; i < 30; i++)
		{
			TextDrawShowForPlayer(playerid, EditObjectTextdraw[i]);
		}
	}
	else if (!show)
	{
		PlayerEditInfo[playerid][Editing] = false;
		for(new i; i < 30; i++)
		{
			TextDrawHideForPlayer(playerid, EditObjectTextdraw[i]);
		}
	}
	return 1;
}

NERP_SHOW_MENU_AGAIN(playerid, objectid, objecttype); public NERP_SHOW_MENU_AGAIN(playerid, objectid, objecttype)
{
	ShowPlayerEditingMenu(playerid, true);
	PlayerEditInfo[playerid][ObjectType] = objecttype;
	new Float:Float[3];
	new EditingMenuString[256];
	PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_POS;
	PlayerEditInfo[playerid][UpdateRate] = NERP_DEFAULT_UPDATE_RATE;

	//object data
	if(objecttype == NERP_OBJECT_GLOBAL)
	{
		PlayerEditInfo[playerid][EditedObject] = objectid;
		format(EditingMenuString,sizeof EditingMenuString,
			"~y~EDIOR: ~g~ON~w~~n~Editing object: ~r~%i",
			objectid);
		GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		
		GetDynamicObjectPos(objectid, Float[0], Float[1], Float[2]);
		PlayerEditInfo[playerid][EditedObjectPos][0] = Float[0];
		PlayerEditInfo[playerid][EditedObjectPos][1] = Float[1];
		PlayerEditInfo[playerid][EditedObjectPos][2] = Float[2];

		PlayerEditInfo[playerid][StartPos][0] = Float[0];
		PlayerEditInfo[playerid][StartPos][1] = Float[1];
		PlayerEditInfo[playerid][StartPos][2] = Float[2];
		
		GetDynamicObjectRot(objectid, Float[0], Float[1], Float[2]);
		PlayerEditInfo[playerid][EditedObjectRot][0] = Float[0];
		PlayerEditInfo[playerid][EditedObjectRot][1] = Float[1];
		PlayerEditInfo[playerid][EditedObjectRot][2] = Float[2];

		PlayerEditInfo[playerid][StartRot][0] = Float[0];
		PlayerEditInfo[playerid][StartRot][1] = Float[1];
		PlayerEditInfo[playerid][StartRot][2] = Float[2];
	}
	if(objecttype == NERP_OBJECT_PLAYER)
	{
		PlayerEditInfo[playerid][EditedObject] = objectid;
		format(EditingMenuString,sizeof EditingMenuString,
			"~y~EDIOR: ~g~ON~w~~n~Editing player~n~object: ~r~%i",
			objectid);
		GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		
		GetPlayerObjectPos(playerid, objectid, Float[0], Float[1], Float[2]);
		PlayerEditInfo[playerid][EditedObjectPos][0] = Float[0];
		PlayerEditInfo[playerid][EditedObjectPos][1] = Float[1];
		PlayerEditInfo[playerid][EditedObjectPos][2] = Float[2];

		PlayerEditInfo[playerid][StartPos][0] = Float[0];
		PlayerEditInfo[playerid][StartPos][1] = Float[1];
		PlayerEditInfo[playerid][StartPos][2] = Float[2];
		
		GetPlayerObjectRot(playerid, objectid, Float[0], Float[1], Float[2]);
		PlayerEditInfo[playerid][EditedObjectRot][0] = Float[0];
		PlayerEditInfo[playerid][EditedObjectRot][1] = Float[1];
		PlayerEditInfo[playerid][EditedObjectRot][2] = Float[2];

		PlayerEditInfo[playerid][StartRot][0] = Float[0];
		PlayerEditInfo[playerid][StartRot][1] = Float[1];
		PlayerEditInfo[playerid][StartRot][2] = Float[2];
	}

	return 1;
}

stock PlayerEditObject(playerid, objectid)
{
	SetTimerEx("NERP_SHOW_MENU_AGAIN", 1000, false, "ii", playerid, objectid, NERP_OBJECT_GLOBAL);
	return 1;
}

stock PlayerEditPlayerObject(playerid, objectid)
{
	SetTimerEx("NERP_SHOW_MENU_AGAIN", 1000, false, "ii", playerid, objectid, NERP_OBJECT_PLAYER);
	return 1;
}

stock PlayerEditAttachedObject(playerid, objectid)
{
	SetTimerEx("NERP_SHOW_MENU_AGAIN", 1000, false, "ii", playerid, objectid, NERP_OBJECT_ATTACHED);
	return 1;
}

stock NERP_PlayerFinishEditObject(playerid)
{
	ShowPlayerEditingMenu(playerid, false);
	PlayerEditInfo[playerid][EditedObject] = -1;
	PlayerEditInfo[playerid][EditedAttachedObject] = -1;
	PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_POS;
	PlayerEditInfo[playerid][UpdateRate] = NERP_DEFAULT_UPDATE_RATE;
	PlayerEditInfo[playerid][ObjectType] = NERP_OBJECT_GLOBAL;

	new Float:Float[3];

	Float[0] = 0.0;
	Float[1] = 0.0;
	Float[2] = 0.0;
	
	PlayerEditInfo[playerid][EditedObjectPos][0] = Float[0];
	PlayerEditInfo[playerid][EditedObjectPos][1] = Float[1];
	PlayerEditInfo[playerid][EditedObjectPos][2] = Float[2];

	PlayerEditInfo[playerid][StartPos][0] = Float[0];
	PlayerEditInfo[playerid][StartPos][1] = Float[1];
	PlayerEditInfo[playerid][StartPos][2] = Float[2];
	
	PlayerEditInfo[playerid][EditedObjectRot][0] = Float[0];
	PlayerEditInfo[playerid][EditedObjectRot][1] = Float[1];
	PlayerEditInfo[playerid][EditedObjectRot][2] = Float[2];

	PlayerEditInfo[playerid][StartRot][0] = Float[0];
	PlayerEditInfo[playerid][StartRot][1] = Float[1];
	PlayerEditInfo[playerid][StartRot][2] = Float[2];
	return 1;
}

///////////PUBLIC/////////
OnPlayerClickEditingMenu(playerid, Text:textid);
public OnPlayerClickEditingMenu(playerid, Text:textid)
{
	new EditingMenuString[256];
	//global objects
	if(PlayerEditInfo[playerid][ObjectType] == NERP_OBJECT_GLOBAL)
	{
		//////////////////////EditingMode SELECTION////////////////////////
		if(textid == EditObjectTextdraw[7])
		{
			GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~POSITION", 2000, 5);
			PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_POS;
		}
		if(textid == EditObjectTextdraw[8])
		{
			GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~ROTATION", 2000, 5);
			PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_ROT;
		}
		//////////////////////X POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[11])// oduzima x
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][0]=
					PlayerEditInfo[playerid][EditedObjectPos][0]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				
				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][0]=
					PlayerEditInfo[playerid][EditedObjectRot][0]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[12])// dodaje x
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][0]=
					PlayerEditInfo[playerid][EditedObjectPos][0]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][0]=
					PlayerEditInfo[playerid][EditedObjectRot][0]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		//////////////////////Y POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[13])// oduzima y
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][1]=
					PlayerEditInfo[playerid][EditedObjectPos][1]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][1]=
					PlayerEditInfo[playerid][EditedObjectRot][1]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[14])// dodaje y
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][1]=
					PlayerEditInfo[playerid][EditedObjectPos][1]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][1]=
					PlayerEditInfo[playerid][EditedObjectRot][1]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		//////////////////////Z POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[15])// oduzima z
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][2]=
					PlayerEditInfo[playerid][EditedObjectPos][2]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][2]=
					PlayerEditInfo[playerid][EditedObjectRot][2]-PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[16])// dodaje z
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][2]=
					PlayerEditInfo[playerid][EditedObjectPos][2]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][2]=
					PlayerEditInfo[playerid][EditedObjectRot][2]+PlayerEditInfo[playerid][UpdateRate];
				SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if((textid != EditObjectTextdraw[18]) && (textid != EditObjectTextdraw[19]))
		{
			CallLocalFunction(NERP_EDITING_GLOBALOBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_UPDATE,
				PlayerEditInfo[playerid][EditedObjectPos][0], 
				PlayerEditInfo[playerid][EditedObjectPos][1],
				PlayerEditInfo[playerid][EditedObjectPos][2],
				PlayerEditInfo[playerid][EditedObjectRot][0], 
				PlayerEditInfo[playerid][EditedObjectRot][1],
				PlayerEditInfo[playerid][EditedObjectRot][2]);
		}
		///////////////FINISH EDITING//////////////////
		if(textid == EditObjectTextdraw[18])
		{
			CallLocalFunction(NERP_EDITING_GLOBALOBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_FINAL,
				PlayerEditInfo[playerid][EditedObjectPos][0], 
				PlayerEditInfo[playerid][EditedObjectPos][1],
				PlayerEditInfo[playerid][EditedObjectPos][2],
				PlayerEditInfo[playerid][EditedObjectRot][0], 
				PlayerEditInfo[playerid][EditedObjectRot][1],
				PlayerEditInfo[playerid][EditedObjectRot][2]);

			GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~FINAL", 2000, 5);

			NERP_PlayerFinishEditObject(playerid);
		}
		if(textid == EditObjectTextdraw[19])
		{
			SetDynamicObjectPos(PlayerEditInfo[playerid][EditedObject], 
				PlayerEditInfo[playerid][StartPos][0], 
				PlayerEditInfo[playerid][StartPos][1],
				PlayerEditInfo[playerid][StartPos][2]);

			SetDynamicObjectRot(PlayerEditInfo[playerid][EditedObject], 
				PlayerEditInfo[playerid][StartRot][0], 
				PlayerEditInfo[playerid][StartRot][1],
				PlayerEditInfo[playerid][StartRot][2]);

			CallLocalFunction(NERP_EDITING_GLOBALOBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_CANCEL,
				PlayerEditInfo[playerid][StartPos][0], 
				PlayerEditInfo[playerid][StartPos][1],
				PlayerEditInfo[playerid][StartPos][2],
				PlayerEditInfo[playerid][StartRot][0], 
				PlayerEditInfo[playerid][StartRot][1],
				PlayerEditInfo[playerid][StartRot][2]);

			GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~CANCELED", 2000, 5);

			NERP_PlayerFinishEditObject(playerid);
		}
		////////////////////////////UPDATE RATE/////////////////////////
		if(textid == EditObjectTextdraw[23]) //oduzima update rate
		{
			PlayerEditInfo[playerid][UpdateRate] = PlayerEditInfo[playerid][UpdateRate]-NERP_DEFAULT_UPDATE_RATE;

			format(EditingMenuString,sizeof EditingMenuString,
				"~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(-)",
				PlayerEditInfo[playerid][UpdateRate]);
			GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		}
		if(textid == EditObjectTextdraw[24]) //dodaje update rate
		{
			PlayerEditInfo[playerid][UpdateRate] = PlayerEditInfo[playerid][UpdateRate]+NERP_DEFAULT_UPDATE_RATE;

			format(EditingMenuString,sizeof EditingMenuString,
				"~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(+)",
				PlayerEditInfo[playerid][UpdateRate]);
			GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		}
	}
	//player objects
	if(PlayerEditInfo[playerid][ObjectType] == NERP_OBJECT_PLAYER)
	{
		//////////////////////EditingMode SELECTION////////////////////////
		if(textid == EditObjectTextdraw[7])
		{
			GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~POSITION", 2000, 5);
			PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_POS;
		}
		if(textid == EditObjectTextdraw[8])
		{
			GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~ROTATION", 2000, 5);
			PlayerEditInfo[playerid][EditingMode] = NERP_EDITING_ROT;
		}
		//////////////////////X POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[11])// oduzima x
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][0]=
					PlayerEditInfo[playerid][EditedObjectPos][0]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				
				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][0]=
					PlayerEditInfo[playerid][EditedObjectRot][0]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[12])// dodaje x
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][0]=
					PlayerEditInfo[playerid][EditedObjectPos][0]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][0]=
					PlayerEditInfo[playerid][EditedObjectRot][0]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		//////////////////////Y POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[13])// oduzima y
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][1]=
					PlayerEditInfo[playerid][EditedObjectPos][1]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][1]=
					PlayerEditInfo[playerid][EditedObjectRot][1]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[14])// dodaje y
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][1]=
					PlayerEditInfo[playerid][EditedObjectPos][1]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][1]=
					PlayerEditInfo[playerid][EditedObjectRot][1]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		//////////////////////Z POSITION/ROTATION////////////////////////
		if(textid == EditObjectTextdraw[15])// oduzima z
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][2]=
					PlayerEditInfo[playerid][EditedObjectPos][2]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][2]=
					PlayerEditInfo[playerid][EditedObjectRot][2]-PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if(textid == EditObjectTextdraw[16])// dodaje z
		{
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_POS)
			{
				PlayerEditInfo[playerid][EditedObjectPos][2]=
					PlayerEditInfo[playerid][EditedObjectPos][2]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectPos][0], 
					PlayerEditInfo[playerid][EditedObjectPos][1],
					PlayerEditInfo[playerid][EditedObjectPos][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
			if(PlayerEditInfo[playerid][EditingMode] == NERP_EDITING_ROT)
			{
				PlayerEditInfo[playerid][EditedObjectRot][2]=
					PlayerEditInfo[playerid][EditedObjectRot][2]+PlayerEditInfo[playerid][UpdateRate];
				SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);

				format(EditingMenuString,sizeof EditingMenuString,
					"~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
					PlayerEditInfo[playerid][EditedObject],
					PlayerEditInfo[playerid][EditedObjectRot][0], 
					PlayerEditInfo[playerid][EditedObjectRot][1],
					PlayerEditInfo[playerid][EditedObjectRot][2]);
				GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
			}
		}
		if((textid != EditObjectTextdraw[18]) && (textid != EditObjectTextdraw[19]))
		{
			CallLocalFunction(NERP_EDITING_PLAYEROBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_UPDATE,
				PlayerEditInfo[playerid][EditedObjectPos][0], 
				PlayerEditInfo[playerid][EditedObjectPos][1],
				PlayerEditInfo[playerid][EditedObjectPos][2],
				PlayerEditInfo[playerid][EditedObjectRot][0], 
				PlayerEditInfo[playerid][EditedObjectRot][1],
				PlayerEditInfo[playerid][EditedObjectRot][2]);
		}
		///////////////FINISH EDITING//////////////////
		if(textid == EditObjectTextdraw[18])
		{
			CallLocalFunction(NERP_EDITING_PLAYEROBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_FINAL,
				PlayerEditInfo[playerid][EditedObjectPos][0], 
				PlayerEditInfo[playerid][EditedObjectPos][1],
				PlayerEditInfo[playerid][EditedObjectPos][2],
				PlayerEditInfo[playerid][EditedObjectRot][0], 
				PlayerEditInfo[playerid][EditedObjectRot][1],
				PlayerEditInfo[playerid][EditedObjectRot][2]);

			GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~FINAL", 2000, 5);

			NERP_PlayerFinishEditObject(playerid);
		}
		if(textid == EditObjectTextdraw[19])
		{
			SetPlayerObjectPos(playerid, PlayerEditInfo[playerid][EditedObject], 
				PlayerEditInfo[playerid][StartPos][0], 
				PlayerEditInfo[playerid][StartPos][1],
				PlayerEditInfo[playerid][StartPos][2]);

			SetPlayerObjectRot(playerid, PlayerEditInfo[playerid][EditedObject], 
				PlayerEditInfo[playerid][StartRot][0], 
				PlayerEditInfo[playerid][StartRot][1],
				PlayerEditInfo[playerid][StartRot][2]);

			CallLocalFunction(NERP_EDITING_PLAYEROBJ_CALLBACK, "iiiffffff", 
				playerid,PlayerEditInfo[playerid][EditedObject],EDIT_RESPONSE_CANCEL,
				PlayerEditInfo[playerid][StartPos][0], 
				PlayerEditInfo[playerid][StartPos][1],
				PlayerEditInfo[playerid][StartPos][2],
				PlayerEditInfo[playerid][StartRot][0], 
				PlayerEditInfo[playerid][StartRot][1],
				PlayerEditInfo[playerid][StartRot][2]);

			GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~CANCELED", 2000, 5);

			NERP_PlayerFinishEditObject(playerid);
		}
		////////////////////////////UPDATE RATE/////////////////////////
		if(textid == EditObjectTextdraw[23]) //oduzima update rate
		{
			PlayerEditInfo[playerid][UpdateRate] = PlayerEditInfo[playerid][UpdateRate]-NERP_DEFAULT_UPDATE_RATE;

			format(EditingMenuString,sizeof EditingMenuString,
				"~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(-)",
				PlayerEditInfo[playerid][UpdateRate]);
			GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		}
		if(textid == EditObjectTextdraw[24]) //dodaje update rate
		{
			PlayerEditInfo[playerid][UpdateRate] = PlayerEditInfo[playerid][UpdateRate]+NERP_DEFAULT_UPDATE_RATE;

			format(EditingMenuString,sizeof EditingMenuString,
				"~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(+)",
				PlayerEditInfo[playerid][UpdateRate]);
			GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
		}
	}
	return 1;
}
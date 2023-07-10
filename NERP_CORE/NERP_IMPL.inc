#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif


IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while (text[pos] < 0x21) // Strip out leading spaces
	{
		if (text[pos] == 0) return INVALID_PLAYER_ID; // No passed text
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if (IsNumeric(text[pos])) // Check whole passed string
	{
		// If they have a numeric name you have a problem (although names are checked on id failure)
		userid = strval(text[pos]);
		if (userid >=0 && userid < MAX_PLAYERS)
		{
			if(!IsPlayerConnected(userid))
			{
				/*if (playerid != INVALID_PLAYER_ID)
				{
					SendClientMessage(playerid, 0xFF0000AA, "User not connected");
				}*/
				userid = INVALID_PLAYER_ID;
			}
			else
			{
				return userid; // A player was found
			}
		}
		/*else
		{
			if (playerid != INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Invalid user ID");
			}
			userid = INVALID_PLAYER_ID;
		}
		return userid;*/
		// Removed for fallthrough code
	}
	// They entered [part of] a name or the id search failed (check names just incase)
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME];
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			GetPlayerName(i, name, sizeof (name));
			if (strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{
				if (len == strlen(name)) // Exact match
				{
					return i; // Return the exact player on an exact match
					// Otherwise if there are two players:
					// Me and MeYou any time you entered Me it would find both
					// And never be able to return just Me's id
				}
				else // Partial match
				{
					count++;
					userid = i;
				}
			}
		}
	}
	if (count != 1)
	{
		if (playerid != INVALID_PLAYER_ID)
		{
			if (count)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch");
			}
			else
			{
				SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
			}
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}


stock showgmtd(playerid)
{
	for(new i = 0; i < 20; i++)
	{
		TextDrawShowForPlayer(playerid, gamemodetd[i]);
	}
	PlayerTextDrawShow(playerid, p_gamemodetd[0][playerid]);
	PlayerTextDrawShow(playerid, p_gamemodetd[1][playerid]);
}
stock hidegmtd(playerid)
{
	for(new i = 0; i < 20; i++)
	{
		TextDrawHideForPlayer(playerid, gamemodetd[i]);
	}
	PlayerTextDrawHide(playerid, p_gamemodetd[0][playerid]);
	PlayerTextDrawHide(playerid, p_gamemodetd[1][playerid]);
}

//global

phidetdtd(playerid); public phidetdtd(playerid)
{
	KillTimer(hideptakedamage[playerid]);
	//xhidetdtd(playerid);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	PlayerTextDrawHide(playerid,ptakedamage0[playerid]);
	PlayerTextDrawHide(playerid,ptakedamage1[playerid]);
	TextDrawHideForPlayer(playerid,takedamage0);
	TextDrawHideForPlayer(playerid,takedamage1);
	//hideptdtd(playerid);
	return 1;
}

stock showbatd(playerid)
{
	TextDrawShowForPlayer(playerid,betatextdraw0);
	TextDrawShowForPlayer(playerid,betatextdraw1);
	TextDrawShowForPlayer(playerid,betatextdraw2);
	TextDrawShowForPlayer(playerid,betatextdraw3);
	TextDrawShowForPlayer(playerid,betatextdraw4);
	TextDrawShowForPlayer(playerid,betatextdraw5);
	TextDrawShowForPlayer(playerid,betatextdraw6);
}

stock hidebatd(playerid)
{
	TextDrawHideForPlayer(playerid,betatextdraw0);
	TextDrawHideForPlayer(playerid,betatextdraw1);
	TextDrawHideForPlayer(playerid,betatextdraw2);
	TextDrawHideForPlayer(playerid,betatextdraw3);
	TextDrawHideForPlayer(playerid,betatextdraw4);
	TextDrawHideForPlayer(playerid,betatextdraw5);
	TextDrawHideForPlayer(playerid,betatextdraw6);
}

stock bool:Weapon_GetAmmoName(weaponid, dest[], size = sizeof (dest))
{
	dest[0] = '\0';
	if (Weapon_IsValid(weaponid))
	{
		strcat(dest, YSI_g_WeaponAmmoNames[weaponid], size);
		return true;
	}
	return false;
}


//------------------------------------------------

IsKeyJustDown(key, newkeys, oldkeys)
{
	if((newkeys & key) && !(oldkeys & key)) return 1;
	return 0;
}

//-------------------------------------------------

OnePlayAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	//if (gPlayerUsingLoopingAnim[playerid] == 1) PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
	ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, 1);
	g_NERP_Animation[playerid]++;
}

//-------------------------------------------------

LoopingAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	//if (gPlayerUsingLoopingAnim[playerid] == 1) PlayerTextDrawHide(playerid,AnimacijeTD[playerid]);
	gPlayerUsingLoopingAnim[playerid] = 1;
	ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, 1);
	//PlayerTextDrawShow(playerid,AnimacijeTD[playerid]);
	g_NERP_Animation[playerid]++;
}

//-------------------------------------------------

StopLoopingAnim(playerid)
{
	gPlayerUsingLoopingAnim[playerid] = 0;
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
}

//-------------------------------------------------

PreloadAnimLib(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0, 1);
}

stock hidectd(playerid)
{
	TextDrawHideForPlayer(playerid,connect0);
	TextDrawHideForPlayer(playerid,connect1);
	TextDrawHideForPlayer(playerid,connect2);
	TextDrawHideForPlayer(playerid,connect3);
	TextDrawHideForPlayer(playerid,connect4);
	TextDrawHideForPlayer(playerid,connect5);
}
stock showctd(playerid)
{
	TextDrawShowForPlayer(playerid,connect0);
	TextDrawShowForPlayer(playerid,connect1);
	TextDrawShowForPlayer(playerid,connect2);
	TextDrawShowForPlayer(playerid,connect3);
	TextDrawShowForPlayer(playerid,connect4);
	TextDrawShowForPlayer(playerid,connect5);
}

stock showktd(playerid)
{
	TextDrawShowForPlayer(playerid,kladionica0);
	TextDrawShowForPlayer(playerid,kladionica1);
	TextDrawShowForPlayer(playerid,kladionica2);
	TextDrawShowForPlayer(playerid,kladionica3);
	TextDrawShowForPlayer(playerid,kladionica4);
	TextDrawShowForPlayer(playerid,kladionica5);
	TextDrawShowForPlayer(playerid,kladionica6);
}

stock hidektd(playerid)
{
	TextDrawHideForPlayer(playerid,kladionica0);
	TextDrawHideForPlayer(playerid,kladionica1);
	TextDrawHideForPlayer(playerid,kladionica2);
	TextDrawHideForPlayer(playerid,kladionica3);
	TextDrawHideForPlayer(playerid,kladionica4);
	TextDrawHideForPlayer(playerid,kladionica5);
	TextDrawHideForPlayer(playerid,kladionica6);
}


stock showhb(playerid)
{
	if(ClientType[playerid] == CLIENT_MOBILE) return hidehb(playerid);
	TextDrawShowForPlayer(playerid,healthbar0);
	TextDrawShowForPlayer(playerid,healthbar1);
	TextDrawShowForPlayer(playerid,healthbar2);
	return 1;
}
stock hidehb(playerid)
{
	TextDrawHideForPlayer(playerid,healthbar0);
	TextDrawHideForPlayer(playerid,healthbar1);
	TextDrawHideForPlayer(playerid,healthbar2);
	return 1;
}
stock pshowhb(playerid)
{
	if(ClientType[playerid] == CLIENT_MOBILE) return phidehb(playerid);
	TextDrawShowForPlayer(playerid,healthbar0);
	TextDrawShowForPlayer(playerid,healthbar1);
	PlayerTextDrawShow( playerid, phealthbar0[playerid] );//TextDrawShowForPlayer(playerid,healthbar2);
	return 1;
}
stock phidehb(playerid)
{
	TextDrawHideForPlayer(playerid,healthbar0);
	TextDrawHideForPlayer(playerid,healthbar1);
	PlayerTextDrawHide(playerid,phealthbar0[playerid]);//TextDrawHideForPlayer(playerid,healthbar2);
	return 1;
}


#define showinjurytd showinjuredtd
stock showinjuredtd(playerid)
{
	TextDrawShowForPlayer(playerid,injured0);
	TextDrawShowForPlayer(playerid,injured1);
	TextDrawShowForPlayer(playerid,injured2);
	TextDrawShowForPlayer(playerid,injured3);
	TextDrawShowForPlayer(playerid,injured4);
	TextDrawShowForPlayer(playerid,injured5);
	TextDrawShowForPlayer(playerid,injured6);
}
#define hideinjurytd hideinjuredtd
stock hideinjuredtd(playerid)
{
	TextDrawHideForPlayer(playerid,injured0);
	TextDrawHideForPlayer(playerid,injured1);
	TextDrawHideForPlayer(playerid,injured2);
	TextDrawHideForPlayer(playerid,injured3);
	TextDrawHideForPlayer(playerid,injured4);
	TextDrawHideForPlayer(playerid,injured5);
	TextDrawHideForPlayer(playerid,injured6);
}



stock showdmtd(playerid)
{
	TextDrawShowForPlayer(playerid,dmtext0);
	TextDrawShowForPlayer(playerid,dmtext1);
	TextDrawShowForPlayer(playerid,dmtext2);
	TextDrawShowForPlayer(playerid,dmtext3);
	TextDrawShowForPlayer(playerid,dmtext4);
	TextDrawShowForPlayer(playerid,dmtext5);
	TextDrawShowForPlayer(playerid,dmtext6);
	TextDrawShowForPlayer(playerid,dmtext7);
}

stock hidedmtd(playerid)
{
	TextDrawHideForPlayer(playerid,dmtext0);
	TextDrawHideForPlayer(playerid,dmtext1);
	TextDrawHideForPlayer(playerid,dmtext2);
	TextDrawHideForPlayer(playerid,dmtext3);
	TextDrawHideForPlayer(playerid,dmtext4);
	TextDrawHideForPlayer(playerid,dmtext5);
	TextDrawHideForPlayer(playerid,dmtext6);
	TextDrawHideForPlayer(playerid,dmtext7);
}

stock showdt(playerid)
{
	TextDrawShowForPlayer( playerid, Deathtext0 );
	TextDrawShowForPlayer( playerid, Deathtext1 );
	TextDrawShowForPlayer( playerid, Deathtext2 );
	TextDrawShowForPlayer( playerid, Deathtext3 );
	TextDrawShowForPlayer( playerid, Deathtext4 );
	TextDrawShowForPlayer( playerid, Deathtext5 );
	TextDrawShowForPlayer( playerid, Deathtext6 );
	TextDrawShowForPlayer( playerid, Deathtext7 );
	TextDrawShowForPlayer( playerid, Deathtext8 );
	TextDrawShowForPlayer( playerid, Deathtext9 );
}

stock hidedt(playerid)
{
	TextDrawHideForPlayer( playerid, Deathtext0 );
	TextDrawHideForPlayer( playerid, Deathtext1 );
	TextDrawHideForPlayer( playerid, Deathtext2 );
	TextDrawHideForPlayer( playerid, Deathtext3 );
	TextDrawHideForPlayer( playerid, Deathtext4 );
	TextDrawHideForPlayer( playerid, Deathtext5 );
	TextDrawHideForPlayer( playerid, Deathtext6 );
	TextDrawHideForPlayer( playerid, Deathtext7 );
	TextDrawHideForPlayer( playerid, Deathtext8 );
	TextDrawHideForPlayer( playerid, Deathtext9 );
}


stock showuo(playerid)
{
	TextDrawShowForPlayer( playerid, UO0 );
	TextDrawShowForPlayer( playerid, UO1 );
	TextDrawShowForPlayer( playerid, UO2 );
	TextDrawShowForPlayer( playerid, UO3 );
	TextDrawShowForPlayer( playerid, UO4 );
	TextDrawShowForPlayer( playerid, UO5 );
	TextDrawShowForPlayer( playerid, UO6 );
	TextDrawShowForPlayer( playerid, UO7 );
	TextDrawShowForPlayer( playerid, UO8 );
	TextDrawShowForPlayer( playerid, UO9 );
	TextDrawShowForPlayer( playerid, UO10 );
	hideucmd(playerid);
	//return 1;
}

stock hideuo(playerid)
{
	TextDrawHideForPlayer( playerid, UO0 );
	TextDrawHideForPlayer( playerid, UO1 );
	TextDrawHideForPlayer( playerid, UO2 );
	TextDrawHideForPlayer( playerid, UO3 );
	TextDrawHideForPlayer( playerid, UO4 );
	TextDrawHideForPlayer( playerid, UO5 );
	TextDrawHideForPlayer( playerid, UO6 );
	TextDrawHideForPlayer( playerid, UO7 );
	TextDrawHideForPlayer( playerid, UO8 );
	TextDrawHideForPlayer( playerid, UO9 );
	TextDrawHideForPlayer( playerid, UO10 );
	//return 1;
}

forward hideuoo(playerid); public hideuoo(playerid)
{
	hideuo(playerid);
	return 1;
}
stock ucitavanje(id)
{
	showuo(id),SetTimerEx( "hideuoo", 5000, false, "i", id );
}



// COMMAND SISTEM
// ========================================

stock hidesrtd(playerid)
{
	PlayerTextDrawHide( playerid, Regtd21[playerid] );
	PlayerTextDrawHide( playerid, Regtd22[playerid] );
	PlayerTextDrawHide( playerid, Regtd23[playerid] );
	PlayerTextDrawHide( playerid, Regtd24[playerid] );
	PlayerTextDrawHide( playerid, Regtd25[playerid] );
	PlayerTextDrawHide( playerid, Regtd26[playerid] );

	PlayerTextDrawShow(playerid,td0[playerid]);
	PlayerTextDrawShow(playerid,td1[playerid]);
	PlayerTextDrawShow(playerid,td2[playerid]);
	PlayerTextDrawShow(playerid,td3[playerid]);
	PlayerTextDrawShow(playerid,td4[playerid]);
	PlayerTextDrawShow(playerid,td5[playerid]);
}

stock hidetdtd(playerid)
{
	PlayerTextDrawHide(playerid,td0[playerid]);
	PlayerTextDrawHide(playerid,td1[playerid]);
	PlayerTextDrawHide(playerid,td2[playerid]);
	PlayerTextDrawHide(playerid,td3[playerid]);
	PlayerTextDrawHide(playerid,td4[playerid]);
	PlayerTextDrawHide(playerid,td5[playerid]);
}

stock showrtd(playerid)
{
	hidetdtd(playerid);
	PlayerTextDrawShow(playerid,Regtd0[playerid]);
	PlayerTextDrawShow(playerid,Regtd1[playerid]);
	PlayerTextDrawShow(playerid,Regtd2[playerid]);
	PlayerTextDrawShow(playerid,Regtd3[playerid]);
	PlayerTextDrawShow(playerid,Regtd4[playerid]);
	PlayerTextDrawShow(playerid,Regtd5[playerid]);
	PlayerTextDrawShow(playerid,Regtd6[playerid]);
	PlayerTextDrawShow(playerid,Regtd7[playerid]);
	PlayerTextDrawShow(playerid,Regtd8[playerid]);
	PlayerTextDrawShow(playerid,Regtd9[playerid]);
	PlayerTextDrawShow(playerid,Regtd10[playerid]);
	PlayerTextDrawShow(playerid,Regtd11[playerid]);
	PlayerTextDrawShow(playerid,Regtd12[playerid]);
	PlayerTextDrawShow(playerid,Regtd13[playerid]);
	PlayerTextDrawShow(playerid,Regtd14[playerid]);
	PlayerTextDrawShow(playerid,Regtd15[playerid]);
	PlayerTextDrawShow(playerid,Regtd16[playerid]);
	PlayerTextDrawShow(playerid,Regtd17[playerid]);
	PlayerTextDrawShow(playerid,Regtd18[playerid]);
	PlayerTextDrawShow(playerid,Regtd19[playerid]);
	PlayerTextDrawShow(playerid,Regtd20[playerid]);
	PlayerTextDrawShow(playerid,Regtd21[playerid]);
	PlayerTextDrawShow(playerid,Regtd22[playerid]);
	PlayerTextDrawShow(playerid,Regtd23[playerid]);
	PlayerTextDrawShow(playerid,Regtd24[playerid]);
	PlayerTextDrawShow(playerid,Regtd25[playerid]);
	PlayerTextDrawShow(playerid,Regtd26[playerid]);
	PlayerTextDrawShow(playerid,Regtd27[playerid]);
	PlayerTextDrawShow(playerid,Regtd28[playerid]);
}
stock hidertd(playerid)
{
	PlayerTextDrawHide(playerid,Regtd0[playerid]);
	PlayerTextDrawHide(playerid,Regtd1[playerid]);
	PlayerTextDrawHide(playerid,Regtd2[playerid]);
	PlayerTextDrawHide(playerid,Regtd3[playerid]);
	PlayerTextDrawHide(playerid,Regtd4[playerid]);
	PlayerTextDrawHide(playerid,Regtd5[playerid]);
	PlayerTextDrawHide(playerid,Regtd6[playerid]);
	PlayerTextDrawHide(playerid,Regtd7[playerid]);
	PlayerTextDrawHide(playerid,Regtd8[playerid]);
	PlayerTextDrawHide(playerid,Regtd9[playerid]);
	PlayerTextDrawHide(playerid,Regtd10[playerid]);
	PlayerTextDrawHide(playerid,Regtd11[playerid]);
	PlayerTextDrawHide(playerid,Regtd12[playerid]);
	PlayerTextDrawHide(playerid,Regtd13[playerid]);
	PlayerTextDrawHide(playerid,Regtd14[playerid]);
	PlayerTextDrawHide(playerid,Regtd15[playerid]);
	PlayerTextDrawHide(playerid,Regtd16[playerid]);
	PlayerTextDrawHide(playerid,Regtd17[playerid]);
	PlayerTextDrawHide(playerid,Regtd18[playerid]);
	PlayerTextDrawHide(playerid,Regtd19[playerid]);
	PlayerTextDrawHide(playerid,Regtd20[playerid]);
	PlayerTextDrawHide(playerid,Regtd21[playerid]);
	PlayerTextDrawHide(playerid,Regtd22[playerid]);
	PlayerTextDrawHide(playerid,Regtd23[playerid]);
	PlayerTextDrawHide(playerid,Regtd24[playerid]);
	PlayerTextDrawHide(playerid,Regtd25[playerid]);
	PlayerTextDrawHide(playerid,Regtd26[playerid]);
	PlayerTextDrawHide(playerid,Regtd27[playerid]);
	PlayerTextDrawHide(playerid,Regtd28[playerid]);
	PlayerTextDrawHide(playerid,Regtd0[playerid]);
	PlayerTextDrawHide(playerid,Regtd1[playerid]);
	PlayerTextDrawHide(playerid,Regtd2[playerid]);
	PlayerTextDrawHide(playerid,Regtd3[playerid]);
	PlayerTextDrawHide(playerid,Regtd4[playerid]);
	PlayerTextDrawHide(playerid,Regtd5[playerid]);
	PlayerTextDrawHide(playerid,Regtd6[playerid]);
	PlayerTextDrawHide(playerid,Regtd7[playerid]);
	PlayerTextDrawHide(playerid,Regtd8[playerid]);
	PlayerTextDrawHide(playerid,Regtd9[playerid]);
	PlayerTextDrawHide(playerid,Regtd10[playerid]);
	PlayerTextDrawHide(playerid,Regtd11[playerid]);
	PlayerTextDrawHide(playerid,Regtd12[playerid]);
	PlayerTextDrawHide(playerid,Regtd13[playerid]);
	PlayerTextDrawHide(playerid,Regtd14[playerid]);
	PlayerTextDrawHide(playerid,Regtd15[playerid]);
	PlayerTextDrawHide(playerid,Regtd16[playerid]);
	PlayerTextDrawHide(playerid,Regtd17[playerid]);
	PlayerTextDrawHide(playerid,Regtd18[playerid]);
	PlayerTextDrawHide(playerid,Regtd19[playerid]);
	PlayerTextDrawHide(playerid,Regtd20[playerid]);
	PlayerTextDrawHide(playerid,Regtd21[playerid]);
	PlayerTextDrawHide(playerid,Regtd22[playerid]);
	PlayerTextDrawHide(playerid,Regtd23[playerid]);
	PlayerTextDrawHide(playerid,Regtd24[playerid]);
	PlayerTextDrawHide(playerid,Regtd25[playerid]);
	PlayerTextDrawHide(playerid,Regtd26[playerid]);
	PlayerTextDrawHide(playerid,Regtd27[playerid]);
	PlayerTextDrawHide(playerid,Regtd28[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd0[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd1[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd2[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd3[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd4[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd5[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd6[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd7[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd8[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd9[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd10[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd11[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd12[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd13[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd14[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd15[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd16[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd17[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd18[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd19[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd20[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd21[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd22[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd23[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd24[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd25[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd26[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd27[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd28[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd0[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd1[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd2[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd3[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd4[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd5[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd6[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd7[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd8[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd9[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd10[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd11[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd12[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd13[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd14[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd15[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd16[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd17[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd18[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd19[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd20[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd21[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd22[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd23[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd24[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd25[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd26[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd27[playerid]);
	PlayerTextDrawDestroy(playerid,Regtd28[playerid]);
}




#define NewPawn_SendClientMessageEx SendClientMessageEx

#define p_id playerid

stock scmex_temp(p_id,color,const NewPawn_message_string[],{Float,_}:...)
{
	new string[1000] = ""col_balkanstory"#SERVER{ffffff}: ";
	static
		args,
		start,
		end,
		NewPawn_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args
 
	if (
		args > 12
	)
	{
		#emit ADDR.pri NewPawn_message_string
		#emit STOR.pri start
 
		for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
			#emit LREF.pri end
			#emit PUSH.pri
		}
		#emit PUSH.S NewPawn_message_string
		#emit PUSH.C 144
		#emit PUSH.C NewPawn_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format
		//NewPawn_unspecified_string
		strcat(string,NewPawn_unspecified_string);
		SendClientMessage
		(
			p_id,
			color,
			string
		)
		;
 
		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	//NewPawn_message_string
	strcat(string,NewPawn_message_string);
	return
		SendClientMessage
		(
			p_id,
			color,
			string
		)
	;
}
stock ascmex
(
	p_id,
	color,
	const NewPawn_message_string[],
	{Float,_}:...
)
{
	//new string[100] = ""col_balkanstory"#SERVER{ffffff}:";
	static
		args,
		start,
		end,
		NewPawn_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args
 
	if (
		args > 12
	)
	{
		#emit ADDR.pri NewPawn_message_string
		#emit STOR.pri start
 
		for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
			#emit LREF.pri end
			#emit PUSH.pri
		}
		#emit PUSH.S NewPawn_message_string
		#emit PUSH.C 144
		#emit PUSH.C NewPawn_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format
		//NewPawn_unspecified_string
		//strcat(string,NewPawn_message_string);
		SendClientMessage
		(
			p_id,
			color,
			NewPawn_unspecified_string
		)
		;
 
		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	//NewPawn_message_string
	//strcat(string,NewPawn_message_string);
	return
		SendClientMessage
		(
			p_id,
			color,
			NewPawn_message_string
		)
	;
}


//============================[ FUNKCIJE ]======================================
ResetujWarIgraca( playerid ) 
{
	WARPInfo[ playerid ][ WARTim ][ 0 ] = false;
	WARPInfo[ playerid ][ WARTim ][ 1 ] = false;
	WARPInfo[ playerid ][ WARUbistva ] = 0;
	WARPInfo[ playerid ][ WARSmrti ] = 0;
	WARPInfo[ playerid ][ WARIgrac ] = -1;
}
//------------------------------------------------------------------------------
/*forward BikeBunnyHop( playerid );
public BikeBunnyHop( playerid ) {

	if( BikeBH[ playerid ] == 1 ) {
	
		BikeBH[ playerid ] = 0;
	}
	return true;
}*/
//


stock ZaposljavanjeDialog(playerid,vozacka,licna,pasos,iskustvo,ugovor)
{
	new voza[5],lica[5],paso[5];
	if( vozacka == 0 ) { voza = "NE"; }
	else if( vozacka == 1 ) { voza = "DA"; }
	//
	if( licna == 0 ) { lica = "NE"; }
	else if( licna == 1 ) { lica = "DA"; }
	//
	if( pasos == 0 ) { paso = "NE"; }
	else if( pasos == 1 ) { paso = "DA"; }
	//
	new bbok[350];
	format(bbok,350,"{0080FF}____________________________________________________\n\n",bbok);
	format(bbok,350,"%s{0080FF}Da bi radili ovaj posao potrebno je:\n",bbok);
	format(bbok,350,"%s{0080FF}Vozacka dozvola: {FFFFFF}%s\n{0080FF}Licna karta: {FFFFFF}%s\n{0080FF}Pasos: {FFFFFF}%s\n",bbok,voza,lica,paso);
	format(bbok,350,"%s{0080FF}Radno iskustvo:{FFFFFF} %d god.\n{0080FF}Trajanje ugovora: {FFFFFF}%dh",bbok,iskustvo,ugovor);
	format(bbok,350,"%s\n{0080FF}____________________________________________________\n\n",bbok);
	ShowPlayerDialog(playerid,dialog_ZAPOSLJAVANJE, DIALOG_STYLE_MSGBOX,"Zaposljavanje",bbok,"Prihvati","Odbij");
	return 1;
}

stock NextParkingID(const len) 
{
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), PARKING_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}

GetNearestParkingZone( playerid ) 
{
	new Float:Pos[ 4 ];
	GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
	for( new id = 1; id < MAX_PARKINGS; id++) {
		if( Pos[ 0 ] <= ParkingInfo[ id ][ parkMaxX ] && Pos[ 0 ] >= ParkingInfo[ id ][ parkMinX ] && Pos[ 1 ] <= ParkingInfo[ id ][ parkMaxY ] && Pos[ 1 ] >= ParkingInfo[ id ][ parkMinY ] ) {
			return id;
		}
	}
	return -1;
}

stock IsCordsInOtherParkingZone( Float:x, Float:y ) 
{
	for( new id = 1; id < MAX_PARKINGS; id++) {
		if( x <= ParkingInfo[ id ][ parkMaxX ] && x >= ParkingInfo[ id ][ parkMinX ] && y <= ParkingInfo[ id ][ parkMaxY ] && y >= ParkingInfo[ id ][ parkMinY ] ) {
			return id;
		}
	}
	return -1;
}

stock IsCordsInParkingZone( id, Float:x, Float:y ) 
{

	if( x <= ParkingInfo[ id ][ parkMaxX ] && x >= ParkingInfo[ id ][ parkMinX ] && y <= ParkingInfo[ id ][ parkMaxY ] && y >= ParkingInfo[ id ][ parkMinY ] ) {
		return id;
	}
	return -1;
}

forward Prerada( playerid );
public Prerada( playerid ) {

	Dimi_KillTimer( NamestajTajmer[ playerid ] );
	DestroyPlayerObject( playerid, Objekat[ playerid ] );
	Objekat[ playerid ] = CreatePlayerObject( playerid, 2410, 2148.72168, -2270.14478, 13.23200,   0.00000, 0.00000, -45.00000);
	MovePlayerObject( playerid, Objekat[ playerid ], 2145.72437, -2266.87305, 13.23200, 1.0);
	return true;
}

forward Prerada2( playerid );
public Prerada2( playerid ) {

	Dimi_KillTimer( NamestajTajmer2[ playerid ] );
	EndWood[ playerid ] = 0;
	return true;
}

forward TimerRezanja( playerid );
public TimerRezanja( playerid ) {

	Dimi_KillTimer( NamestajTajmer[ playerid ] );
	if( Rezanje[ playerid ] != 100 ) {
		ClearAnimations( playerid );
	}
	KoristioRezanje[ playerid ] = 0;
	if( Rezanje[ playerid ] != 100 ) {
		TogglePlayerControllable( playerid, false );
	}
	return true;
}


//------------------------------------------------------------------------------
forward PecaRibu( playerid );
public PecaRibu( playerid ) {

	fishermanInfo[ playerid ][ TriesFish ] = 1;
	ClearChat( playerid, 25 );
	announcement( playerid, "~w~Uhvatili ste ribu.~n~Izvucite je tipkom ~r~N", 1500, 3 );
	Dimi_KillTimer( fishermanInfo[ playerid ][ fsTimer ] );
	return 1;
}


/*stock ShowFishingTD( playerid, bool:show ) {

	if( show == false )
	{
		PlayerTextDrawHide(playerid, FishermangTD[0][playerid]);
		PlayerTextDrawHide(playerid, FishermangTD[1][playerid]);
	}
	else if( show == true ) {
	
		PlayerTextDrawShow(playerid, FishermangTD[0][playerid]);
		PlayerTextDrawShow(playerid, FishermangTD[1][playerid]);
	}
	return (true);
}*/
//------------------------------------------------------------------------------
ResetPlayer( playerid )
{
	if( IsValidDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] ) )
	{
		DestroyDynamicMapIcon( PlayerGpsRadar[ playerid ][ _pgrIconId ] );
	}

	if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] ) )
	{
		DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
	}

	if( IsValidDynamicCP(PlayerGpsRadar[ playerid ][_pgrCheckPointId ] ) )
	{
		DestroyDynamicCP(PlayerGpsRadar[ playerid ][_pgrCheckPointId] );
	}

	for(new t = 0; t < GRADJEVINARHRPICE; t++)//ovdje povecat broj kad doradimo objekte
	{
		if( IsValidDynamicObject( pijesakhrpa[playerid][t] ) )
		{
			DestroyDynamicObject(pijesakhrpa[playerid][t]);
		}
	}




	PlayerGpsRadar[ playerid ][_pgrIconId] = -1;
	PlayerGpsRadar[ playerid ][_pgrObject] = -1;
	PlayerGpsRadar[ playerid ][_pgrCheckPointId] = -1;
	ResetujAdmina( playerid );
	//
	ResetujWarIgraca( playerid );
	ResetTuningInfo( playerid );
	//
	flymodecamera[ playerid ][cameramode] 	= false;
	flymodecamera[ playerid ][lrold]	   	 	= 0;
	flymodecamera[ playerid ][udold]   		= 0;
	flymodecamera[ playerid ][mode]   		= 0;
	flymodecamera[ playerid ][lastmove]   	= 0;
	flymodecamera[ playerid ][accelmul]   	= 0.0;
	//
	fishermanInfo[ playerid ][ Fisherman ] = 0;
	fishermanInfo[ playerid ][ StartedFishing ] = false;
	fishermanInfo[ playerid ][ Fishing ] = false;
	fishermanInfo[ playerid ][ fLastVeh ] = 0;
	//
	for( new i = 0; i < MAX_INVENTORY; i++ )
	{
		inventoryInfo[ playerid ][ i ][ invExists ] = false;
		inventoryInfo[ playerid ][ i ][ invModel ] = 0;
		inventoryInfo[ playerid ][ i ][ invQuantity ] = 0;
		strmid( inventoryInfo[ playerid ][ i ][ invItem ], "None", 0, strlen( "None" ), 32 );
	}
	#if kladionica == 1
	for(  new i = 0; i < 10; i++ )
	{
		KladionicaListic[ playerid ][ parID ][ i ] = -1;
		KladionicaListic[ playerid ][ keciksdva ][ i ] = -1;
		KladionicaListic[ playerid ][ Kvota ][ i ] = 0.0;
		KladionicaListic[ playerid ][ teamID1 ][ i ] = -1;
		KladionicaListic[ playerid ][ teamID2 ][ i ] = -1;
	}
	KladionicaListic[ playerid ][ Uplaceno ] = false;
	KladionicaListic[ playerid ][ Zavrseno ] = false;
	KladionicaListic[ playerid ][ Uplata ] = 0;
	KladionicaListic[ playerid ][ Dobitak ] = 0;
	KladionicaListic[ playerid ][ Status ] = false;
	IzabraniPar[ playerid ] = -1;
	#endif
	//
	EndWood[ playerid ] = 0;
	//
	Start[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	Gambling[ playerid ] = 0;
	RuletAccount[ playerid ] = 0;
	BikeBH[ playerid ] = 0;
	SlotTimer[ playerid ] = -1;
	//
	Dimi_KillTimer( Putovar[ playerid ] );
	Dimi_KillTimer( Pistovar[ playerid ] );
	Dimi_KillTimer( NamestajTajmer[ playerid ] );
	Dimi_KillTimer( NamestajTajmer2[ playerid ] );
	Dimi_KillTimer( ProveriInvOruzje[ playerid ] );
	Dimi_KillTimer( TimerLearn[ playerid ] );
	#if NERP_ZIMSKI_MOD  == 1
	Dimi_KillTimer( EffectTimer[ playerid ] );
	#endif
	Dimi_KillTimer( gZone_Timer[ playerid ] );
	Dimi_KillTimer( zauzimanje_firme_Timer[ playerid ] );
	Dimi_KillTimer( PusenjeTimer[ playerid ] );
	Dimi_KillTimer( PosaoMasinovodja[ playerid ] );
	Dimi_KillTimer( atmrobTimer[ playerid ] );
	Dimi_KillTimer( SkolaTimer[ playerid ] );
	Dimi_KillTimer( TimerPitanje[ playerid ] );
	Dimi_KillTimer( RentTimer[ playerid ] );
	Dimi_KillTimer( DragTimer[ playerid ] );
	Dimi_KillTimer( TimerTutorial[ playerid ] );
	Dimi_KillTimer( FarbanjeTimer[ playerid ] );
	Dimi_KillTimer( BolnicaTimer[ playerid ] );
	Dimi_KillTimer( TaxiTimer[ playerid ] );
	Dimi_KillTimer( TazerTimer[ playerid ] );
	Dimi_KillTimer( CistacTimer[ playerid ] );
	Dimi_KillTimer( TrashTimer[ playerid ] );
	Dimi_KillTimer( PilotTimer[ playerid ] );
	Dimi_KillTimer( FarbanjeTimer[ playerid ] );
	Dimi_KillTimer( TravaTimer[ playerid ] );
	Dimi_KillTimer( ZitoTimer[ playerid ] );
	Dimi_KillTimer( smecedoletimer[ playerid ] );
	Dimi_KillTimer( ravnjanjetimer[ playerid ] );
	Dimi_KillTimer( IzazivanjeTimer[ playerid ] );
	Dimi_KillTimer( PljackanjeBankeTimer[ playerid ] );
	Dimi_KillTimer( PljackanjeZlatareTimer[ playerid ] );
	Dimi_KillTimer( rudarPosao[ playerid ][ rudarTimer ] );
	
	#if NERP_ZIMSKI_MOD  == 1
	Snow[ playerid ] = false;
	#endif
	//----------------[ Enum ]----------------
	PlayerInfo[ playerid ][ xPol ] = 1;
	PlayerInfo[ playerid ][ xGodine ] = 0;
	PlayerInfo[ playerid ][ xNovac ] = 0;
	PlayerInfo[ playerid ][ xLevel ] = 0;
	PlayerInfo[ playerid ][ xRespekt ] = 0;
	PlayerInfo[ playerid ][ xPoboljsanja ] = 0;
	PlayerInfo[ playerid ][ xPayDay ] = 0;
	PlayerInfo[ playerid ][ xAdmin ] = 0;
	PlayerInfo[ playerid ][ xSkin ] = 26;
	PlayerInfo[ playerid ][ xSpawn ] = 0;
	PlayerInfo[ playerid ][ xLider ] = 0;
	PlayerInfo[ playerid ][ xClan ] = 0;
	PlayerInfo[ playerid ][ xKazneniUgovor ] = 0;
	PlayerInfo[ playerid ][ xRank ] = 0;
	PlayerInfo[ playerid ][ xVoziloID ][ 0 ] = -1;
	PlayerInfo[ playerid ][ xVoziloID ][ 1 ] = -1;
	PlayerInfo[ playerid ][ xVoziloID ][ 2 ] = -1;
	PlayerInfo[ playerid ][ xVoziloID ][ 3 ] = -1;
	PlayerInfo[ playerid ][ xMaterijali ] = 0;
	PlayerInfo[ playerid ][ xFirmaID ] = -1;
	PlayerInfo[ playerid ][ xPosao ] = 0;
	PlayerInfo[ playerid ][ xUgovor ] = 0;
	PlayerInfo[ playerid ][ xMehSkill ] = 0;
	PlayerInfo[ playerid ][ xMDelovi ] = 0;
	PlayerInfo[ playerid ][ xHead ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xStaffMin ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 4 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 5 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 6 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 7 ] = 0;
	PlayerInfo[ playerid ][ xHeadPos ][ 8 ] = 0;
	PlayerInfo[ playerid ][ xFace ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 4 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 5 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 6 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 7 ] = 0;
	PlayerInfo[ playerid ][ xFacePos ][ 8 ] = 0;
	PlayerInfo[ playerid ][ xSungMask ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 4 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 5 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 6 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 7 ] = 0;
	PlayerInfo[ playerid ][ xSungMaskPos ][ 8 ] = 0;
	PlayerInfo[ playerid ][ xCigare ] = 0;
	PlayerInfo[ playerid ][ xUpaljac ] = 0;
	PlayerInfo[ playerid ][ xBStil ] = 0;
	PlayerInfo[ playerid ][ xRegistrovan ] = 0;
	PlayerInfo[ playerid ][ xSHealth ] = 0;
	PlayerInfo[ playerid ][ xBrojTelefona ] = 0;
	PlayerInfo[ playerid ][ xVozacka ] = 0;
	PlayerInfo[ playerid ][ xLicna ] = 0;
	PlayerInfo[ playerid ][ xTaxLic ] = 0;
	PlayerInfo[ playerid ][ xPasos ] = 0;
	PlayerInfo[ playerid ][ xJMBG ] = 0;
	PlayerInfo[ playerid ][ xBrojLk ] = 0;
	PlayerInfo[ playerid ][ xBrojPasosa ] = 0;
	PlayerInfo[ playerid ][ xMotorska ] = 0;
	PlayerInfo[ playerid ][ xKamionskaC1 ] = 0;
	PlayerInfo[ playerid ][ xKamionskaC2 ] = 0;
	PlayerInfo[ playerid ][ xKamionskaC3 ] = 0;
	PlayerInfo[ playerid ][ xBrodska ] = 0;
	PlayerInfo[ playerid ][ xLetelica ] = 0;
	PlayerInfo[ playerid ][ xOsnovna ] = 0;
	PlayerInfo[ playerid ][ xSrednja ] = 0;
	PlayerInfo[ playerid ][ xFakultet ] = 0;
	PlayerInfo[ playerid ][ xSkolaLimit ] = 0;
	PlayerInfo[ playerid ][ xUbijen ] = 0;
	#if nerp_droga == 1
	PlayerInfo[ playerid ][ xDrug ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xDrug ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xDrug ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xDrug ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xDrug ][ 4 ] = 0;
	PlayerInfo[ playerid ][ xDrugCode ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xDrugCode ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xDrugCode ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xDrugCode ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xDrugCode ][ 4 ] = 0;
	#endif
	PlayerInfo[ playerid ][ xSolna ] = 0;
	PlayerInfo[ playerid ][ xPseudo ] = 0;
	PlayerInfo[ playerid ][ xSodaB ] = 0;
	PlayerInfo[ playerid ][ xCrveniF ] = 0;
	PlayerInfo[ playerid ][ xLysAcid ] = 0;
	PlayerInfo[ playerid ][ xDesVoda ] = 0;
	PlayerInfo[ playerid ][ xMarihuana ] = 0;
	PlayerInfo[ playerid ][ xOpium ] = 0;
	PlayerInfo[ playerid ][ xKalcij ] = 0;
	PlayerInfo[ playerid ][ xAmonijH ] = 0;
	PlayerInfo[ playerid ][ xKokain ] = 0;
	PlayerInfo[ playerid ][ xKokain2 ] = 0;
	PlayerInfo[ playerid ][ xMetilAmin ] = 0;
	PlayerInfo[ playerid ][ xHunger ] = 15;
	PlayerInfo[ playerid ][ xToilet ] = 20;
	PlayerInfo[ playerid ][ xHeroinAddict ] = false;
	PlayerInfo[ playerid ][ xHeroinUsed ] = 0;
	PlayerInfo[ playerid ][ xHeroinIndicator ] = 0;
	PlayerInfo[ playerid ][ xCokeCrackAddict ] = false;
	PlayerInfo[ playerid ][ xCokeCrackUsed ] = 0;
	PlayerInfo[ playerid ][ xCokeCrackIndicator ] = 0;
	PlayerInfo[ playerid ][ xMethAddict ] = false;
	PlayerInfo[ playerid ][ xMethIndicator ] = 0;
	PlayerInfo[ playerid ][ xMethUsed ] = 0;
	PlayerInfo[ playerid ][ xInekcija ] = false;
	PlayerInfo[ playerid ][ xToolkit ] = false;
	PlayerInfo[ playerid ][ xProperty ][ 0 ] = -1;
	PlayerInfo[ playerid ][ xProperty ][ 1 ] = -1;
	PlayerInfo[ playerid ][ xProperty ][ 2 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 0 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 1 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 2 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 3 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 4 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 5 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 6 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 7 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 8 ] = -1;
	PlayerInfo[ playerid ][ xObject ][ 9 ] = -1;
	PlayerInfo[ playerid ][ xGunLicense ] = false;
	PlayerInfo[ playerid ][ xTelefonBon ] = 0;
	PlayerInfo[ playerid ][ xModelTelefona ] = 0;
	PlayerInfo[ playerid ][ xSnaga ] = 0;
	PlayerInfo[ playerid ][ xZatvor ] = 0;
	PlayerInfo[ playerid ][ xZatvorVreme ] = 0;
	PlayerInfo[ playerid ][ xWanted ] = 0;
	PlayerInfo[ playerid ][ xUhapsen ] = 0;
	PlayerInfo[ playerid ][ xPDUhapsio ] = 0;
	PlayerInfo[ playerid ][ xPDStatsTicket ] = 0;
	PlayerInfo[ playerid ][ xPDStatsTicketMoney ] = 0;
	PlayerInfo[ playerid ][ xTakenWeps ] = 0;
	#if nerp_droga == 1
	PlayerInfo[ playerid ][ xTakenDrugs ] = 0;
	#endif
	PlayerInfo[ playerid ][ xPocetniTut ] = 0;
	PlayerInfo[ playerid ][ xAKod ] = 0;
	PlayerInfo[ playerid ][ xSat ] = 0;
	PlayerInfo[ playerid ][ xMaskID ] = 0;
	PlayerInfo[ playerid ][ xBRacun ] = 0;
	PlayerInfo[ playerid ][ xPreostaloZaOtplatu ] = 0;
	PlayerInfo[ playerid ][ xIznosRate ] = 0;
	PlayerInfo[ playerid ][ xIznosKredita ] = 0;
	PlayerInfo[ playerid ][ xOnlineSati ] = 0;
	PlayerInfo[ playerid ][ xHelper ] = 0;
	PlayerInfo[ playerid ][ xRPLearn ] = 0;
	PlayerInfo[ playerid ][ xWarn ] = 0;
	PlayerInfo[ playerid ][ xMute ] = 0;
	PlayerInfo[ playerid ][ xMarker ][ 0 ] = 0.00000;
	PlayerInfo[ playerid ][ xMarker ][ 1 ] = 0.00000;
	PlayerInfo[ playerid ][ xMarker ][ 2 ] = 0.00000;
	PlayerInfo[ playerid ][ xBrojNews ] = 0;
	PlayerInfo[ playerid ][ xOrgUgovor ] = 0;
	PlayerInfo[ playerid ][ xGpsLevel ] = 0;
	PlayerInfo[ playerid ][ xHelmet ] = 0;
	PlayerInfo[ playerid ][ xBDays ] = 0;
	PlayerInfo[ playerid ][ xBMonths ] = 0;
	PlayerInfo[ playerid ][ xBYears ] = 0;
	PlayerInfo[ playerid ][ xGradRank ] = 0;
	PlayerInfo[ playerid ][ xSpawned ] = 0;
	PlayerInfo[ playerid ][ xBHD ] = 0;
	PlayerInfo[ playerid ][ xRCON ] = 0;
	PlayerInfo[ playerid ][ xRanac ] = 0;
	PlayerInfo[ playerid ][ xTogn ] = 0;
	PlayerInfo[ playerid ][ xKnjizica ] = 0;
	PlayerInfo[ playerid ][ xVakcina ] = 0;
	PlayerInfo[ playerid ][ xUputnica ] = 0;
	PlayerInfo[ playerid ][ xZMaska ] = 0;
	PlayerInfo[ playerid ][ xPin ] = 0;
	PlayerInfo[ playerid ][ xDutyTime ] = 0;
	PlayerInfo[ playerid ][ xDJ ] = 0;
	PlayerInfo[ playerid ][ xOTD ] = 0;
	PlayerInfo[ playerid ][ xTdstil ] = 0;
	PlayerInfo[ playerid ][ xTogn ] = 0;
	PlayerInfo[ playerid ][ xVokiToki ] = 0;
	PlayerInfo[ playerid ][ xPapagaj ] = 0;
	PlayerInfo[ playerid ][ xSniperHeadshots ] = 0;
	PlayerInfo[ playerid ][ xPUBGKillsTotal ] = 0;
	PlayerInfo[ playerid ][ xBanovan ] = 0;
	PlayerInfo[ playerid ][ xBDatum ][0] = 0;
	PlayerInfo[ playerid ][ xBDatum ][1] = 0;
	PlayerInfo[ playerid ][ xBDatum ][2] = 0;
	PlayerInfo[ playerid ][ xSkriptaRank ] = 0;
	PlayerInfo[ playerid ][ xUlazBL ] = 0;
	PlayerInfo[ playerid ][ xBoombox ] = false;
	PlayerInfo[ playerid ][ xHelmetPos ][ 0 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 1 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 2 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 3 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 4 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 5 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 6 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 7 ] = 0;
	PlayerInfo[ playerid ][ xHelmetPos ][ 8 ] = 0;
	PlayerInfo[ playerid ][ xDrzava ] = 0;
	PlayerInfo[ playerid ][ xVIPLevel ] = 0;
	PlayerInfo[ playerid ][ xHitmenCena ] = 0;
	PlayerInfo[ playerid ][ xLesLimit ] = 0;
	PlayerInfo[ playerid ][ xMarried ] = false;
	PlayerInfo[ playerid ][ xTogMob ] = false;
	PlayerInfo[ playerid ][ xHotelID ] = -1;
	PlayerInfo[ playerid ][ xHotelRoom ] = -1;
	PlayerInfo[ playerid ][ xPromoter ] = 0;
	PlayerInfo[ playerid ][ xFieldID ] = -1;
	PlayerInfo[ playerid ][ xSljive ] = 0;
	PlayerInfo[ playerid ][ xKruske ] = 0;
	PlayerInfo[ playerid ][ xJabuke ] = 0;
	PlayerInfo[ playerid ][ xKupus ] = 0;
	PlayerInfo[ playerid ][ xRuze ] = 0;
	PlayerInfo[ playerid ][ xSemeSljive ] = 0;
	PlayerInfo[ playerid ][ xSemeKruske ] = 0;
	PlayerInfo[ playerid ][ xSemeJabuke ] = 0;
	PlayerInfo[ playerid ][ xSemeKupusa ] = 0;
	PlayerInfo[ playerid ][ xSemeRuze ] = 0;
	PlayerInfo[ playerid ][ xLottoNumber ] = 0;
	PlayerInfo[ playerid ][ xLottoMoney ] = 0;
	PlayerInfo[ playerid ][ xGarageID ] = -1;
	PlayerInfo[ playerid ][ xImaBRacun ] = false;
	PlayerInfo[ playerid ][ xPlatniRacun ] = 0;
	PlayerInfo[ playerid ][ xDonatorSlot ] = false;
	PlayerInfo[ playerid ][ xLeaveJail ] = false;
	PlayerInfo[ playerid ][ xBailPrice ] = 0;
	PlayerInfo[ playerid ][ xHangarTime ] = 0;
	PlayerInfo[ playerid ][ xZauzimanjeVreme ] = 0;
	PlayerInfo[ playerid ][ xSvercer ] = 0;
	PlayerInfo[ playerid ][ xEvent1Mesto ] = 0;
	PlayerInfo[ playerid ][ xEvent2Mesto ] = 0;
	PlayerInfo[ playerid ][ xEvent3Mesto ] = 0;
	PlayerInfo[ playerid ][ xDMEventUbistva ] = 0;
	PlayerInfo[ playerid ][ xZombieEventKills ] = 0;
	PlayerInfo[ playerid ][ xRentID ] = -1;
	PlayerInfo[ playerid ][ xZlato ] = 0;
	PlayerInfo[ playerid ][ xPljackaVreme ] = 0;
	PlayerInfo[ playerid ][ xRezervniKljucevi ] = -1;
	PlayerInfo[ playerid ][ xRadarBodovi ] = 0;
	PlayerInfo[ playerid ][ xDBoja ] = 0;
	PlayerInfo[ playerid ][ xRPPoen ] = 0;
	PlayerInfo[ playerid ][ xPodApoeni ] = 0;
	PlayerInfo[ playerid ][ xApoeni ] = 0;
	PlayerInfo[ playerid ][ xVipTime ] = 0;
	PlayerInfo[ playerid ][ xPoklon ] = 0;
	PlayerInfo[ playerid ][ xPaketic ] = false;
	PlayerInfo[ playerid ][ xDBO ] = false;
	strmid( PlayerInfo[ playerid ][ xKljucKapije ], "Niko", 0, strlen( "Niko" ), 24 );
	strmid( PlayerInfo[ playerid ][ xOffPJail ], "N", 0, strlen("N"), 2 );
	strmid( PlayerInfo[ playerid ][ xMarriedTo ], "Niko", 0, strlen( "Niko" ), 24 );
	strmid( PlayerInfo[ playerid ][ xBReason ], "Nema", 0, strlen( "Nema" ), 41);
	strmid( RealName[ playerid ], ImeIgraca( playerid ), 0, strlen( ImeIgraca( playerid ) ), 64 );
	//----------------[ New ]-----------------
	farmerInfo[ playerid ][ fiFarmerSeeds ] = 0;
	farmerInfo[ playerid ][ fiFarmerPlantsPlanted ] = -1;
	farmerInfo[ playerid ][ fiFarmerWheatCreated ] = -1;
	farmerInfo[ playerid ][ fiFarmerPickupedBales ] = 0;
	farmerInfo[ playerid ][ fiFarmerPickupedBale ] = false;
	farmerInfo[ playerid ][ fiHaveBucket ] = false;
	farmerInfo[ playerid ][ fiHaveGajbica ] = false;
	farmerInfo[ playerid ][ fiHaveFruits ] = false;
	farmerInfo[ playerid ][ fiCowNumber ] = 0;
	farmerInfo[ playerid ][ fiFruitNumber ] = 0;
	farmerInfo[ playerid ][ fiFruitDeliveryNumber ] = 0;
	farmerInfo[ playerid ][ fiVehicleBucket ] = -1;
	farmerInfo[ playerid ][ fiVehicleFruit ] = -1;
	farmerInfo[ playerid ][ fiBucketObject  ] = INVALID_OBJECT_ID;
	
	askqInfo[ playerid ][ askqSended ] = false;
	askqInfo[ playerid ][ askqAnswered ] = false;
	strmid( askqInfo[ playerid ][ askqAdmin ], "None", 0, strlen( "None" ), 32 );
	strmid( askqInfo[ playerid ][ askqAnswer ], "None", 0, strlen( "None" ), 128 );
	
	NamestajLevel[ playerid ] = 0;
	Rezanje[ playerid ] = 0;
	KoristioRezanje[ playerid ] = 0;
	FakeKillPlus[ playerid ] = 0;
	FakeKillTime[ playerid ] = 0;
	CreatingGZone[ playerid ] = -1;
	CreatingGZoneID[ playerid ] = -1;
	CreatingThing[ playerid ] = -1;
	CreatingField[ playerid ] = -1;
	VremeZaNovac[ playerid ] = 0;
	VremeZaZlato[ playerid ] = 0;
	CheckpointStatus[ playerid ] = 0;
	StatsList[ playerid ] = 0;
	PljackaVreme[ playerid ] = 0;
	PljackaNovac[ playerid ] = 0;
	ZlatoVreme[ playerid ] = 0;
	PljackaZlato[ playerid ] = 0;
	NaDmEventu[ playerid ] = false;
	VecJeAfk[ playerid ] = false;
	PuniGorivo[ playerid ] = false;
	BiraPol[ playerid ] = 0;
	DropedGun[ playerid ] = 0;
	BiraSkin[ playerid ] = 1;
	PlayerInBlowJob[ playerid ] = 0;
	BrojLisica[ playerid ] = 0;
	DeliverLevel[ playerid ] = 0;
	TempoDostavaFabrikaCP[ playerid ] = 0;
	TrafikaPrva[ playerid ] = 0;
	ParkingPlace[ playerid ] = -1;
	TrafikaTrenutna[ playerid ] = 0;
	DeliverCar[ playerid ] = -1;
	CarriesBox [ playerid ] = 0;
	gZone_ID[ playerid ] = -1;
	EventStranica[ playerid ] = 0;
	gZone_Time[ playerid ] = 0;
	zauzimanje_firme_ID[ playerid ] = -1;
	zauzimanje_firme_Vreme[ playerid ] = 0;
	BlowJobCount[ playerid ] = 0;
	OruzjeUInventoriju[ playerid ] = 0;
	TazerMetkovi[ playerid ] = 0;
	Putovara[ playerid ] = false;
	Pistovara[ playerid ] = false;
	#if NERP_ZIMSKI_MOD  == 1
	PlayerRun[ playerid ] = 0;
	#endif
	CreatingParkingLevel[ playerid ] = 0;
	CreateParkingID[ playerid ] = -1;
	#if kladionica == 1
	ListaPrikazana[ playerid ] = false;
	MojListicPrikazan[ playerid ] = false;
	RezultatiPrikazana[ playerid ] = false;
	#endif
	UKLJUCENIFCHAT[ playerid ] = false;
	takingselfie[ playerid ] = false;
	WatchModel[ playerid ] = 19039;
	SpecPos[ playerid ][ 0 ] = 0.0;
	SpecPos[ playerid ][ 1 ] = 0.0;
	SpecPos[ playerid ][ 2 ] = 0.0;
	CreatingPos[ playerid ][ 0 ] = 0.0;
	CreatingPos[ playerid ][ 1 ] = 0.0;
	CreatingPos[ playerid ][ 2 ] = 0.0;
	CreatingPos[ playerid ][ 3 ] = 0.0;
	PraznaGajbica[ playerid ] = false;
	ImaKanticu[ playerid ] = false;
	Snow_F[ playerid ] = false;
	AlreadyShooted[ playerid ] = false;
	Charged[ playerid ] = 0;
	Shoot[ playerid ] = 0;
	GajbicaBiljka[ playerid ] = 0;
	Polaganje[ playerid ] = 0;
	ProcesFStation[ playerid ] = 0;
	CreatingFStation[ playerid ] = -1;
	rudarPosao[ playerid ][ rudarIskopano ] = 0;
	PokusajLogina[ playerid ] = 0;
	WatchingTV{ playerid } = 0;
	Bandera[ playerid ] = 0;
	KupljeneFakture[ playerid ] = false;
	ResprayColor1[ playerid ] = -1;
	ChosenItem[ playerid ] = -1;
	GiveItemID[ playerid ] = -1;
	IzabraniAskQ[ playerid ] = -1;
	ResprayColor2[ playerid ] = -1;
	VozPosao[ playerid ] = 0;
	ShowedRegister[ playerid ] = false;
	OrgKreiranje[ playerid ] = 0;
	UsaoAutoProdaja[ playerid ] = -1;
	DragedPlayerID[ playerid ] = -1;
	Draged[ playerid ] = -1;
	PlayerCement[ playerid ] = -1;
	IDBusaKojiVozi[ playerid ] = -1;
	IDVozilaKojimSverca[ playerid ] = -1;
	ProcesSvercanja[ playerid ] = 0;
	PlayerPrevozNovca[ playerid ] = -1;
	AdminDuty[ playerid ] = false;
	EditingBody[ playerid ] = 0;
	RadioAktiviran[ playerid ] = 0;
	UlogTrke[ playerid ] = 0;
	PlayerCuffed[ playerid ] = 0;
	PosaoRudar[ playerid ] = 0;
	PonudioIgrac[ playerid ] = -1;
	ModelTrke[ playerid ] = 0;
	electricNACP[ playerid ] = false;
	IgracSeRegistruje[ playerid ] = false;
	PocetniTutorialStartovan[ playerid ] = false;
	#if nerp_droga == 1
	PlayerDrugged[ playerid ] = false;
	#endif
	PlayerStoned[ playerid ] = false;
	PlayerTuningCar[ playerid ] = false;
	PosaoTDShowed[ playerid ] = false;
	StatsTDShowed[ playerid ] = false;
	LicnaKartaShowed[ playerid ] = false;
	BuyCarTDShowed[ playerid ] = false;
	BojaVozilaTDShowed[ playerid ] = false;
	LaptopRuke[ playerid ] = false;
	Dinamit[ playerid ] = false;
	ProcesPice[ playerid ] = 0;
	alreadyPictured[ playerid ] = false;
	TogHud[ playerid ] = false;
	IgracZavezan[ playerid ] = false;
	AccountVerified[ playerid ] = false;
	KnockedDown[ playerid ] = false;
	IgracOpljackan[ playerid ] = false;
	VecjeUsao[ playerid ] = true;
	Pojas[ playerid ] = false;
	Uze[ playerid ] = false;
	Maskuse[ playerid ] = false;
	SearchNadji[ playerid ] = -1;
	FlyMode[ playerid ] = false;
	robbingATM[ playerid ] = -1;
	CenaProdaje[ playerid ] = 0;
	Poravnano[ playerid ] = 0;
	sravnohrpica[ playerid ] = 0;
	VoziBeogradStanicu[ playerid ] = 0;
	VoziSarajevoStanicu[ playerid ] = 0;
	robbingATMSeconds[ playerid ] = 95;
	PlayerCP[ playerid ] = 0;
	UkupnaCena[ playerid ] = 0;
	ElectricOprema[ playerid ] = false;
	ElectricPosao[ playerid ] = 0;
	ShowedAtmTD[ playerid ] = false;
	BrojilaKuca[ playerid ] = 0;
	#if nerp_droga == 1
	PoljeDroge[ playerid ] = -1;
	#endif
	LetSF[ playerid ] = 0;
	LetLV[ playerid ] = 0;
	EIDK[ playerid ] = -1;
	EnteredGarage[ playerid ] = -1;
	EditDGate[ playerid ] = -1;
	EditDGateMove[ playerid ] = -1;
	AdminVozilo[ playerid ] = -1;
	TrkaVozilo[ playerid ] = -1;
	Krugovi[ playerid ] = 0;
	TrkaCheckpoint[ playerid ] = 0;
	TrkaIzazov[ playerid ] = 0;
	NaUtrci[ playerid ] = false;
	PlacaPorez[ playerid ] = 0;
	GlobalProdaja[ playerid ] = -1;
	Ponudjeno[ playerid ] = -1;
	Trazio[ playerid ] = -1;
	ServerStatsChose[ playerid ] = 0;
	inHotel[ playerid ] = -1;
	GlobalCena[ playerid ] = -1;
	GlobalID[ playerid ] = -1;
	GlobalID_2[ playerid ] = -1;
	gNews{ playerid } = 0;
	anticheatinfo[ playerid ] = 0;
	UzeoIzMarketa[ playerid ][ 0 ] = 0;
	UzeoIzMarketa[ playerid ][ 1 ] = 0;
	UzeoIzMarketa[ playerid ][ 2 ] = 0;
	UzeoIzMarketa[ playerid ][ 3 ] = 0;
	UzeoIzMarketa[ playerid ][ 4 ] = 0;
	UzeoIzMarketa[ playerid ][ 5 ] = 0;
	UzeoIzMarketa[ playerid ][ 6 ] = 0;
	UzeoIzMarketa[ playerid ][ 7 ] = 0;
	UzeoIzMarketa[ playerid ][ 8 ] = 0;
	UzeoIzMarketa[ playerid ][ 9 ] = 0;
	UzeoIzMarketa[ playerid ][ 10 ] = 0;
	FaceOn[ playerid ] = false;
	HeadOn[ playerid ] = false;
	Spectate[ playerid ] = -1;
	SungOn[ playerid ] = false;
	PlayerEventVehID[ playerid ] = -1;
	ListaBurg[ playerid ] = 0;
	Training[ playerid ] = 0;
	//PlayerLogged[ playerid ] = false;
	PolaganjeBodovi[ playerid ] = 0;
	GreskaVoznja[ playerid ] = 0;
	StaroVreme[ playerid ] = 0;
	NovoVreme[ playerid ] = 0;
	PokosenaTrava[ playerid ] = 0;
	PokosenoZito[ playerid ] = 0;
	KrenuoKosenje[ playerid ] = false;
	KrenuoZetvu[ playerid ] = false;
	UzeoOpremu[ playerid ] = false;
	HitmanInfo[ playerid ][ GotHit ] = 0;
	HitmanInfo[ playerid ][ PlacedNews ] = 0;
	HitmanInfo[ playerid ][ GetChased ] = 999;
	HitmanInfo[ playerid ][ GoChase ] = 999;
	Odbrojavanje[ playerid ] = 0;
	Uciskolu[ playerid ] = false;
	garbagemanInfo[ playerid ][ gmiDuty ] = false;
	garbagemanInfo[ playerid ][ gmiReadyToDump ] = false;
	garbagemanInfo[ playerid ][ gmiHasGarbage ] = false;
	garbagemanInfo[ playerid ][ gmiJob ] = false;
	garbagemanInfo[ playerid ][ gmiContainerID ] = 0;
	garbagemanInfo[ playerid ][ gmiVehicleID ] = -1;
	AktivanKontejner[ playerid ] = -1;
	RemovePlayerAttachedObject(playerid, smeceobject1[playerid]);
	DestroyPlayerObject(playerid,smeceobject1[playerid]);
	
	RemovePlayerAttachedObject(playerid, betonobject1[playerid]);
	DestroyPlayerObject(playerid,betonobject1[playerid]);
		
	DestroyPlayerObject(playerid,betonobject2[playerid]);
	
	DestroyDynamicObject(cistacvodica[0][playerid]);
	DestroyDynamicObject(cistacvodica[1][playerid]);

	
	isprazniovreca[playerid] = 0;
	zasmeceobject1[playerid] = 0;
	EditKontejnera[ playerid ] = -1;
	EditATM[ playerid ] = -1;
	EditPresents[ playerid ] = -1;
	EditCTrees[ playerid ] = -1;
	EditXOrbs[ playerid ] = -1;
	EditRadar[ playerid ] = -1;
	cistackilometri[ playerid ] = 0;
	cistacmetri[ playerid ] = 0;
	cistacnovac[ playerid ] = 0;
	CistacWarning[ playerid ] = 0;
	cistacpoz[ playerid ][ 0 ] = 0.0;
	cistacpoz[ playerid ][ 1 ] = 0.0;
	cistacpoz[ playerid ][ 2 ] = 0.0;
	CistacPosao[ playerid ] = false;
	cistacvozilo[ playerid ] = -1;
	Seeds[ playerid ] = 0;
	SeedsK[ playerid ] = 0;
	VrstaIlegala[ playerid ] = 0;
	uFirmi[ playerid ] = -1;
	uInterijeru[ playerid ] = -1;
	KolicinaIlegala[ playerid ] = 0;
	inProperty[ playerid ] = -1;
	inOrgInt[ playerid ] = -1;
	PoliceDuty[ playerid ] = false;
	KupujeNamestaj[ playerid ] = 0;
	strmid( ZlocinInfo[ playerid ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
	strmid( ZlocinInfo[ playerid ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
	strmid( ZlocinInfo[ playerid ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
	ImaTazer[ playerid ] = false;
	RiotShield[ playerid ] = false;
	TrunkVehicle[ playerid ] = -1;
	MedicDuty[ playerid ] = false;
	UzeoPicu[ playerid ] = false;
	VoziIgracaID[ playerid ] = INVALID_PLAYER_ID;
	offeredByCabbie[ playerid ] = INVALID_PLAYER_ID;
	CenaVoznje[ playerid ] = 0;
	TaximetarUkljucen[ playerid ] = false;
	taxiDuty[ playerid ] = false;
	PozvaoTaxi[ playerid ] = false;
	KupljenGPS[ playerid ] = 0;
	PitanjeBroj[ playerid ] = 0;
	TacanOdgovor[ playerid ] = -1;
	Rentano[ playerid ] = -1;
	PaketType[ playerid ] = 0;
	NosiPaketOruzja[ playerid ] = false;
	PropertySafeGun[ playerid ] = -1;
	NosiObjekt[ playerid ][ 0 ] = false;
	NosiObjekt[ playerid ][ 1 ] = false;
	NosiObjekt[ playerid ][ 2 ] = false;
	TrashLimit[ playerid ] = 0;
	TrashSearch[ playerid ] = 0;
	HelmetOn[ playerid ] = false;
	TelohraniteljUniforma[ playerid ] = false;
	VozacUniforma[ playerid ] = false;
	InAmbu[ playerid ] = -1;
	PhoneOnline[ playerid ] = 0;
	RPTeacherDuty[ playerid ] = 0;
	BoomboxInfo[ playerid ][ boomboxPlaced ] = 0;
	BoomboxInfo[ playerid ][ boomboxPos ][ 0 ] = 0.0;
	BoomboxInfo[ playerid ][ boomboxPos ][ 1 ] = 0.0;
	BoomboxInfo[ playerid ][ boomboxPos ][ 2 ] = 0.0;
	Boombox[ playerid ] = IPI;
	InputPassword[ playerid ] = false;
	ChoseCountry[ playerid ] = false;
	InputAge[ playerid ] = false;
	InputMail[ playerid ] = false;
	RegSex[ playerid ] = 1;
	KreiranjeWara[ playerid ] = -1;
	EventCP[ playerid ] = 0;
	EventCarsCreate[ playerid ] = 0;
	PlayerCreateEvent[ playerid ] = false;
	ReportGlobal[ playerid ] = 0;
	VIPPort[ playerid ] = 0;
	PromoterPort[ playerid ] = 0;
	PomocGlobal[ playerid ] = 0;
	NewGlobal[ playerid ] = 0;
	PlayerCPShow[ playerid ] = false;
	KreiranAutoSalon[ playerid ] = -1;
	KreiraGarazu[ playerid ] = -1;
	PlayerBuyingAS[ playerid ] = -1;
	AutoSalonBojaVozila[ playerid ] = -1;
	IgracPosadio[ playerid ] = 0;
	VremeZaCuvanje[ playerid ] = 0;
	MinutiIgraca[ playerid ] = 0;
	IzabraniPort[ playerid ] = 0;
	ProposeOffer[ playerid ] = 999;
	DivorceOffer[ playerid ] = 999;
	MarryWitness[ playerid ] = 999;
	MarryWitnessOffer[ playerid ] = 999;
	MarriageCeremoney{ playerid } = 0;
	ProposedTo[ playerid ] = 999;
	GotProposedBy[ playerid ] = 999;
	ChosenVehicle[ playerid ] = -1;
	gpsid[ playerid ] = -1;
	ObjectEdition_TYPE[ playerid ] = 255;
	// Anti cheat
	antiCheatCS[ playerid ][ EnterVehTime ] = 0;
	antiCheatCS[ playerid ][ LastWShot ] = -1;
	antiCheatCS[ playerid ][ EnteredVehicle ] = INVALID_VEHICLE_ID;
	antiCheatCS[ playerid ][ TakeVehicle ] = INVALID_VEHICLE_ID;
	antiCheatCS[ playerid ][ SpamChat ] = 0;
	antiCheatCS[ playerid ][ SpamCommand ] = 0;
	antiCheatCS[ playerid ][ WeaponCheck ] = 1;
	antiCheatCS[ playerid ][ WeaponDetect ] = 3;
	antiCheatCS[ playerid ][ SpeedFall ] = false;
	antiCheatCS[ playerid ][ TeleportCheck ] = 0;
	antiCheatCS[ playerid ][ TeleportHack ] = 0;
	antiCheatCS[ playerid ][ WeaponHack ] = 0;
	antiCheatCS[ playerid ][ SpeedHack ] = 0;
	antiCheatCS[ playerid ][ HighPing ] = 0;
	antiCheatCS[ playerid ][ AFKMinute ] = 0;
	antiCheatCS[ playerid ][ CPSCount ] = 0;
	antiCheatCS[ playerid ][ CPSTick ] = 0;
	antiCheatCS[ playerid ][ VehRepairTime ] = 0;
	antiCheatCS[ playerid ][ CPPort ] = 0;
	antiCheatCS[ playerid ][ CWTime ] = 0;
	antiCheatCS[ playerid ][ CWVehID ] = -1;
	antiCheatCS[ playerid ][ SpamVehicle ] = 0;
	antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;
	antiCheatCS[ playerid ][ LastAmmo ] = 0;
	antiCheatCS[ playerid ][ ArmedWeapon ] = 0;
	antiCheatCS[ playerid ][ InTuningGarage ] = false;
	antiCheatCS[ playerid ][ RemoveVehicle ] = false;
	for( new i = 0; i < 13; i++ ) { 
		antiCheatCS[ playerid ][ Weapon ][ i ] = 0;
		antiCheatCS[ playerid ][ Ammo ][ i ] = 0;
	}
	//----------------[ PVar ]-----------------
	SetPVarInt( playerid, "GOTOOffer", 999 );
	SetPVarInt( playerid, "RepairEOffer", 999 );
	SetPVarInt( playerid, "RepairAOffer", 999 );
	SetPVarInt( playerid, "RepairLOffer", 999 );
	SetPVarInt( playerid, "RefillOffer", 999 );
	SetPVarInt( playerid, "RepairIOffer", 999 );
	SetPVarInt( playerid, "TicketOffer", 999 );
	SetPVarInt( playerid, "RepairBKOffer", 999 );
	SetPVarInt( playerid, "RepairTOffer", 999 );
	SetPVarInt( playerid, "ShakeOffer", 999 );
	SetPVarInt( playerid, "PlayerHasTest", 999 );
	SetPVarInt( playerid, "ResprayOffer", 999 );
	SetPVarInt( playerid, "ResprayDozvola", 999 );
	SetPVarInt( playerid, "RecoverOffer", 999 );
	SetPVarInt( playerid, "MedicineOffer", 999 );
	SetPVarInt( playerid, "CanisterFuel", 0 );
	SetPVarInt( playerid, "gGas", 1 );
	SetPVarInt( playerid, "Mobile", -1 );
	SetPVarInt( playerid, "LiveOffer", 999 );
	SetPVarInt( playerid, "TalkingLive", 255 );
}

new ForbiddenNames[][] = {
	"http://","https://",".com",".net",".org",".hr",".info",".ba",".tk","www","7777","7778","7878","7877","7789",
	"gf","server","Extazy","life","city","balkan","united","ultimate","battle","craft","ucfr","Xeptic","geforce",
	"srw","serv","srv","angels","angeles","battle-craft","ultimate","roleplay","ludi-grad","Ludi Grad","lu di grad",
	"gaming","gamming","uif","samp", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "CroHerze", "Cro Herze", "Old School",
	"Zara", "mater", "majka", "jebem", "kurac", "picka", "jebi", "govno", "govna", "balkanschool", "bs", "serverii", "cuna",
	"net", "mamicu", "majkicu", "jebac", "kurva", "kurvica", "guzica", "kurcic", "kurcina", "loool", "idegas", "gas", "old",
	"roleplay", "jao", "ahh", "krvavu"
};
//------------------------------------------------------------------------------
IsANoTrunkVehicle( vehicleID ) {
	switch( GetVehicleModel( vehicleID ) ) {
		case 403,406,407,408,411,416,417,423,424,425,430,432,434,435,441,443,444,446,447,449,450,452,453,454,457,460,464,465,469,472,473,476,481,485,486,493,494,495,501,502,503,504,505,509,510,512,513,514,515,520,524,525,528,530,531,532,537,538,539,544,552,556,557,564,568,569,570,571,572,573,574,578,583,584, 590,591,592,593,594,595,601,606,607,608,610,611:
			return true;
	}
	return false;
}


//-----------------------------------------------------------------------------



bool:SportVozilo( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 411,415,419,420,421,424,429,434,444,451,477,494,495,502,503,504,506,
		541,556,557,559,562,587,602,603: return true;
	}
	return false;
}

bool:PutnickoVozilo( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 400,401,402,404,405,409,410,412,426,436,438,439,445,458,466,467,470,
		474,475,479,480,489,490,491,492,496,500,505,507,508,516,517,518,526,527,
		529,533,534,535,536,540,542,545,546,547,549,550,551,554,555,558,560,
		561,565,566,567,575,576,579,580,585,589,600,604: return true;
	}
	return false;
}



bool:TeretnoVozilo( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 403,406,407,408,413,414,416,418,422,423,427,428,433,440,442,443,455,456,
		459,478,482,483,498,499,514,515,524,525,543,552,573,578,588,609: return true;
	}
	return false;
}


////////////////////////////////////////////////////////////////////////////////
bool:VoziloJe2Vrata( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 401,402,403,406,407,408,410,411,412,414,415,417,419,422,423,424,429,
		431,433,434,436,437,439,442,443,444,447,451,455,456,457,469,474,475,477,
		478,480,483,488,489,491,494,495,496,499,500,502,503,504,505,506,508,511,
		514,515,517,518,524,525,526,527,528,529,533,534,535,536,541,542,543,544,
		545,549,552,554,555,556,557,558,559,562,563,565,573,574,575,576,577,578,
		583,587,588,589,593,599,600,601,602,603,605,609: return true;
	}
	return false;
}

bool:VoziloJe4Vrata( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 400,404,405,409,413,416,418,420,421,426,427,428,438,440,445,458,
		459,460,466,467,470,479,482,487,490,492,497,498,507,516,540,546,547,
		550,551,560,561,566,567,579,580,582,585,596,597,598,604: return true;
	}
	return false;
}

bool:VoziloNemaVrata( vehid )
{
	switch( GetVehicleModel( vehid ) )
	{
		case 425,430,432,435,441,446,448,449,450,452,453,454,461,462,
		463,464,465,468,471,472,473,476,481,484,485,486,493,501,509,510,
		512,513,519,520,521,522,523,530,531,532,537,538,539,548,553,564,
		568,569,570,571,572,581,584,586,590,591,592,594,595,606,607,608,
		610,611: return true;
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
bool:VoziloJeDizel( vehid )
{//vOZILO JE DIZEL
	switch( GetVehicleModel( vehid ) )
	{
		case 400,401,403,405,406,407,408,409,413,414,416,418,420,421,423,426,427,
		428,431,432,433,437,440,443,444,445,455,456,459,470,478,482,483,
		486,489,490,492,498,499,505,508,514,515,516,524,525,528,530,
		531,532,540,544,551,552,554,556,557,560,561,573,578,579,580,582,
		583,588,589,596,597,598,599,601,609: return true;
	}
	return false;
}
bool:VoziloJeBenzin( vehid )
{//VOZILO JE BENZIN
	switch(GetVehicleModel( vehid ) )
	{
		case 402,404,410,411,412,415,419,422,424,429,430,434,436,438,439,442,446,
		448,451,452,453,454,458,461,462,463,466,467,468,471,472,473,474,
		475,477,479,480,484,485,487,488,491,493,494,495,496,500,501,502,
		503,504,506,507,517,518,521,522,523,526,527,529,533,534,535,536,
		539,541,542,543,545,546,547,549,550,555,558,559,562,565,566,567,
		568,571,572,574,575,576,581,585,586,587,595,600,602,603,604,605: return true;
	}
	return false;
}
bool:VoziloJeKerozin( vehid )
{//
	switch(GetVehicleModel( vehid ) )
	{
		case 417, 425, 447, 460, 469, 476, 497, 511, 512, 513, 519,520, 548, 553, 563, 577, 592, 593: return true;
		//474, 478, 483, 485, 486, 498, 499, 500, 508, 510, 517, 525, 531, 532, 546,
		//547, 550, 551, 552, 573, 574, 578, 588, 589, 600, 601, 609: return true;
	}
	return false;
}

bool:VoziloNemaGorivo( vehid )
{//
	switch(GetVehicleModel( vehid ) )
	{
		case 435, 441, 449, 450, 457, 464, 465, 481, 501, 509, 510,537, 538, 564, 570, 584, 590, 591,594, 606, 607, 608, 610, 611: return true;
		//474, 478, 483, 485, 486, 498, 499, 500, 508, 510, 517, 525, 531, 532, 546,
		//547, 550, 551, 552, 573, 574, 578, 588, 589, 600, 601, 609: return true;
	}
	return false;
}


// kerozin 417, 425 447 460 469 476 487 488 497 511, 512 513 519, 520, 548 553 563 577 592 593
// brod 430 446 452 453 454 472 473 484 493 539 595
// tenk 432
// voz 537, 538 569 570
//------------------------------------------------------------------------------
GetVehicleFuelType( vehicle ) {

	new fueltypeName[14] = "Fuel Type";
	
	if( ScriptIDVozila[ vehicle ] != -1 ) {
		if( VehicleInfo[ ScriptIDVozila[ vehicle ] ][ vFuelType ] == 1 ) fueltypeName = "Dizel";
		else if( VehicleInfo[ ScriptIDVozila[ vehicle ] ][ vFuelType ] == 2 ) fueltypeName = "Benzin";
		else if( VehicleInfo[ ScriptIDVozila[ vehicle ] ][ vFuelType ] == 3 ) fueltypeName = "Kerozin";
		else if( VehicleInfo[ ScriptIDVozila[ vehicle ] ][ vFuelType ] == 4 ) fueltypeName = "N/A";
		else fueltypeName = "Benzin";
	}
	else fueltypeName = "Benzin";
	
	return fueltypeName;
}
//------------------------------------------------------------------------------
/*bool:isATrucker( vehicleid)
{
	switch(GetVehicleModel( vehicleid))
	{
		case 422, 600, 543, 478, 554, 413, 440, 459, 482: return true;
	}
	return false;
}*/
bool:IsVehicleBajs(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 481, 509, 510: return true;
	}
	return false;
}
bool:isATractor( vehid )
{
	if( GetVehicleModel( vehid ) == 531 ) return true;
	return false;
}
bool:isAHarvester( vehid )
{
	if( GetVehicleModel( vehid ) == 532 ) return true;
	return false;
}
bool:IsVehiclePrikolica(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 435, 450, 584, 591, 611, 610: return true;
	}
	return false;
}
bool:IsVehicleMotor(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 448, 461, 462, 463, 468, 471, 521, 522, 523, 586, 581: return true;
	}
	return false;
}
bool:IsVehicleAuto(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 400, 401, 402, 404, 405, 409, 410, 411, 412, 415, 419, 420, 421, 422,
		426, 429, 434, 436, 438, 439, 442, 445, 451, 458, 466, 467, 470, 474, 475,
		477, 478, 479, 480, 489, 490, 491, 492, 494, 495, 496, 500, 502, 503, 504,
		505, 506, 507, 516, 517, 518, 525, 526, 527, 528, 529, 533, 534, 535, 536,
		540, 541, 542, 543, 545, 546, 547, 549, 550, 551, 552, 554, 555, 558, 559,
		560, 561, 562, 565, 566, 567, 568, 575, 576, 579, 580, 585, 587, 589, 596,
		597, 598, 599, 600, 602, 603, 604, 605, 444, 457, 483, 485, 530, 531, 539,
		556, 557, 574, 424, 583, 572: return true;
	}
	return false;
}
bool:IsVehicleC1(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 499, 482, 498, 588, 609, 414, 582, 413, 440, 459, 456, 416, 423, 427,
		428, 508, 573, 601: return true;
	}
	return false;
}
bool:IsVehicleC2(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 406, 407, 408, 431, 432, 433, 437, 443, 455, 486, 524, 532, 544, 578: return true;
	}
	return false;
}
bool:IsVehicleC3(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 403, 514, 515: return true;
	}
	return false;
}
bool:IsVehicleBrod(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 472, 473, 493, 595, 484, 430, 453, 452, 446, 454: return true;
	}
	return false;
}
bool:IsVehicleLetelica(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 417, 425, 447, 460, 469, 476, 487, 488, 497, 511, 512, 513, 519,
		520, 548, 553, 563, 577, 592, 593: return true;
	}
	return false;
}
//------------------------------[ ENCODES ]------------------------------------
encode_tires(tire1, tire2, tire3, tire4) return tire1 | (tire2 << 1) | (tire3 << 2) | (tire4 << 3);
encode_panels(flp, frp, rlp, rrp, windshield, front_bumper, rear_bumper)
{
	return flp | (frp << 4) | (rlp << 8) | (rrp << 12) | (windshield << 16) | (front_bumper << 20) | (rear_bumper << 24);
}
encode_doors(bonnet, boot, driver_door, passenger_door, behind_driver_door, behind_passenger_door)
{
	#pragma unused behind_driver_door
	#pragma unused behind_passenger_door
	return bonnet | (boot << 8) | (driver_door << 16) | (passenger_door << 24);
}
encode_lights(light1, light2, light3, light4)
{
	return light1 | (light2 << 1) | (light3 << 2) | (light4 << 3);
}
//==============================[ STOCK ]=======================================
stock HexToInt(string[]) // By DracoBlue
{
	if(string[ 0 ] == 0) 
		return 0;

	new i, 
		cur=1,
		res=0;

	for ( i = strlen(string);
		i>0;
		i-- ) 
	{
		if (
				string[ i - 1 ] < 58 
		) res = res + cur * (
								string[ i - 1 ] - 48 
							); 
		else 
			res = res + cur 
		* 
							(
								string[ i - 1 ] - 65 + 10
							);
		cur=cur*16;
	}
	return res;
}
//
Text:CreateSprite(Float:X,Float:Y,Name12a[],Float:Width,Float:Height)
{
	new Text:RetSprite;
	RetSprite = TextDrawCreate(X, Y, Name12a); // Text is txdfile:texture
	TextDrawFont(RetSprite, 4); // Font ID 4 is the sprite draw font
	TextDrawColor(RetSprite,0xFFFFFFFF);
	TextDrawTextSize(RetSprite,Width,Height); // Text size is the Width:Height
	return RetSprite;
}

Text:CreateBox(Float:X,Float:Y,Float:Width,Float:Height,color)
{
	new Text[500];
	for(new i=floatround(Y); i < floatround(Y+Height);i++)
	{
		strcat(Text,"~n~_");
	}
	new Text:RetSprite;
	RetSprite = TextDrawCreate(X, Y, Text); // Text is txdfile:texture
	TextDrawFont(RetSprite, 0); // Font ID 4 is the sprite draw font
	TextDrawColor(RetSprite,0xFFFFFFFF);
	TextDrawTextSize(RetSprite,Width+X,Height+Y); // Text size is the Width:Height
	TextDrawUseBox(RetSprite,1);
	TextDrawBoxColor(RetSprite,color);
	TextDrawLetterSize(RetSprite,0.0001,0.1158);
	return RetSprite;
}
//------------------------------------------------------------------------------
//pony 413
//moonbean 418
//romero 442
stock ShowLogo(playerid)
{
	if(ClientType[playerid] == CLIENT_PC)
	{
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, PCNERPLogo[i]);
		}
	}
	if(ClientType[playerid] == CLIENT_MOBILE)
	{
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, MobileNERPLogo[i]);
		}
	}
	return 1;
}
stock GrobarVozilo(model)
{
	if(	model == 442 )
	{
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
stock reactionRandom( Min, Max ){
	new randomreaction;
	randomreaction = Min + random( Max );
	return randomreaction;
}

stock StartReaction( ) {

	if( !reactionWon )
	{
		format( reactionMessage[ 1 ], 128, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Nazalost, prijethodnu rijec "SERVERBOJA_AQUA"nije "SERVERBOJA_SIVA"niko ukucao na vrijeme!");
		if( strlen( reactionMessage[ 1 ] ) ) SendClientMessageToAll( -1, reactionMessage[ 1 ] );
	}
	reactionMessage[ 0 ][ 0 ] = EOS;
	reactionMessage[ 1 ][ 0 ] = EOS;
	reactionWinner[ 0 ] = EOS;

	reactionMoney = reactionRandom(.Min = 200, .Max = 300),

	reactionMessage[ 0 ][ 0 ] = '\0';

	for( new c; c < 8; ++c )
	{
		reactionMessage[ 0 ][ c ] = random(2) ? ( '0' + random(9) ) : ( random(2) ? ( 'a' + random(26) ) : ( 'A' + random(26) ) );
	}

	reactionTest = 3;

	format( reactionMessage[ 1 ], 128,"| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Ukucajte prvi "SERVERBOJA_AQUA"%s "SERVERBOJA_SIVA"i osvojite "SERVERBOJA_AQUA"%i$!", reactionMessage[ 0 ], reactionMoney );
	

	SendClientMessageToAll( -1, reactionMessage[ 1 ] );

	reactionTime = GetTickCount( );
}

stock EndReaction( playerid ) {

	DajIgracuNovac( playerid, reactionMoney );

	reactionTime = ( GetTickCount( ) - reactionTime );

	format( reactionMessage[ 1 ], 128, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Igrac "SERVERBOJA_AQUA"%s "SERVERBOJA_SIVA"je prvi upisao "SERVERBOJA_AQUA"%s "SERVERBOJA_SIVA"!", ImeIgraca( playerid ), reactionMessage[ 0 ] );
	for(new i; i < MAX_PLAYERS; i++) {
	
		if( i != playerid ) {
		
			if( IsPlayerConnected( i ) ) {
			
				SendClientMessage( i, -1, reactionMessage[ 1 ] );
			}
		}
	}

	reactionTest = 0;

	format( reactionMessage[ 1 ], 128, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Prvi ste napisali "SERVERBOJA_AQUA"%s "SERVERBOJA_SIVA"te dobili "SERVERBOJA_AQUA"%i$ "SERVERBOJA_SIVA"- cestitke.", reactionMessage[ 0 ], reactionMoney );
	SendClientMessage( playerid, -1, reactionMessage[ 1 ] );
	format( reactionMessage[ 1 ], 128, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Reagovali ste za "SERVERBOJA_AQUA"%d ms (%d sec).", reactionTime, floatround( reactionTime * 0.001 ) );
	SendClientMessage( playerid, -1, reactionMessage[ 1 ] );


	PlayerInfo[ playerid ][ xPodApoeni ]++;
	if( PlayerInfo[ playerid ][ xPodApoeni ] == 500 ) {
	
		PlayerInfo[ playerid ][ xApoeni ]++;
		PlayerInfo[ playerid ][ xPodApoeni ] = 0;
		SendClientMessagee( playerid, ZUTA, "Dobili ste jedan APoen zbog 500 pogodjenih reakcija." );
	}

	if( reactionTime < ServerInfo[ ReactTime ] )
	{
	
		format( reactionMessage[ 1 ], 256, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Vi ste oborili rekord igraca "SERVERBOJA_AQUA"%s (%d ms)"SERVERBOJA_SIVA"! Novi rekord je "SERVERBOJA_AQUA"%d ms.", ServerInfo[ ReactName ], ServerInfo[ ReactTime ], reactionTime );
		SendClientMessage( playerid, -1, reactionMessage[ 1 ] );
		format( reactionMessage[ 1 ], 256, "| "SERVERBOJA_AQUA"REAKCIJA {FFFFFF}| "SERVERBOJA_SIVA"Oboren rekord igraca "SERVERBOJA_AQUA"%s (%d ms)"SERVERBOJA_SIVA"! Novi rekord je "SERVERBOJA_AQUA"%d ms.", ServerInfo[ ReactName ], ServerInfo[ ReactTime ], reactionTime );
		for(new i; i < MAX_PLAYERS; i++)
		{
		
			if( i != playerid )
			{
			
				if( IsPlayerConnected( i ) )
				{
				
					SendClientMessage( i, -1, reactionMessage[ 1 ] );
				}
			}
		}
		ServerInfo[ ReactTime ] = reactionTime;
		strmid( ServerInfo[ ReactName ], ImeIgraca( playerid ), 0, strlen( ImeIgraca( playerid ) ), 32 );
		SaveServerStats( );
	}

	reactionWon = true;
	strmid( reactionWinner, ImeIgraca( playerid ), 0, strlen( ImeIgraca( playerid ) ), 32 );
}
//------------------------------------------------------------------------------
forward Black_Fading( playerid );
public Black_Fading( playerid ) 
{
	F_Count[ playerid ]++;

	PlayerTextDrawHide( playerid, Fading[ playerid ] );
	PlayerTextDrawShow( playerid, Fading[ playerid ] );

	if( F_Count[ playerid ] == 1 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000000A );
	if( F_Count[ playerid ] == 2 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000010 );
	if( F_Count[ playerid ] == 3 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000001A );
	if( F_Count[ playerid ] == 4 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000020 );
	if( F_Count[ playerid ] == 5 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000002A );
	if( F_Count[ playerid ] == 6 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000030 );
	if( F_Count[ playerid ] == 7 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000003A );
	if( F_Count[ playerid ] == 8 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000040 );
	if( F_Count[ playerid ] == 9 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000004A );
	if( F_Count[ playerid ] == 10 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000050 );
	if( F_Count[ playerid ] == 11 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000005A );
	if( F_Count[ playerid ] == 12 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000060 );
	if( F_Count[ playerid ] == 13 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000006A );
	if( F_Count[ playerid ] == 14 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000070 );
	if( F_Count[ playerid ] == 15 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000007A );
	if( F_Count[ playerid ] == 16 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000080 );
	if( F_Count[ playerid ] == 17 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000008A );
	if( F_Count[ playerid ] == 18 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000090 );
	if( F_Count[ playerid ] == 19 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000009A );
	if( F_Count[ playerid ] == 20 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000A1 );
	if( F_Count[ playerid ] == 21 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000AA );
	if( F_Count[ playerid ] == 22 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000B1 );
	if( F_Count[ playerid ] == 23 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000BB );
	if( F_Count[ playerid ] == 24 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000C1 );
	if( F_Count[ playerid ] == 25 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000CC );
	if( F_Count[ playerid ] == 26 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000D1 );
	if( F_Count[ playerid ] == 27 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000DD );
	if( F_Count[ playerid ] == 28 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000E1 );
	if( F_Count[ playerid ] == 29 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000EE );
	if( F_Count[ playerid ] == 30 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000F1 );
	if( F_Count[ playerid ] == 31 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000FF );
	// Completely Black
	if( F_Count[ playerid ] == 32 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000F1 );
	if( F_Count[ playerid ] == 33 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000EE );
	if( F_Count[ playerid ] == 34 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000E1 );
	if( F_Count[ playerid ] == 35 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000DD );
	if( F_Count[ playerid ] == 36 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000D1 );
	if( F_Count[ playerid ] == 37 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000CC );
	if( F_Count[ playerid ] == 38 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000C1 );
	if( F_Count[ playerid ] == 39 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000BB );
	if( F_Count[ playerid ] == 40 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000B1 );
	if( F_Count[ playerid ] == 41 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000AA );
	if( F_Count[ playerid ] == 42 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000A1 );
	if( F_Count[ playerid ] == 43 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000009A );
	if( F_Count[ playerid ] == 44 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000090 );
	if( F_Count[ playerid ] == 45 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000008A );
	if( F_Count[ playerid ] == 46 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000080 );
	if( F_Count[ playerid ] == 47 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000007A );
	if( F_Count[ playerid ] == 48 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000070 );
	if( F_Count[ playerid ] == 49 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000006A );
	if( F_Count[ playerid ] == 50 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000060 );
	if( F_Count[ playerid ] == 51 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000005A );
	if( F_Count[ playerid ] == 52 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000050 );
	if( F_Count[ playerid ] == 53 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000004A );
	if( F_Count[ playerid ] == 54 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000040 );
	if( F_Count[ playerid ] == 55 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000003A );
	if( F_Count[ playerid ] == 56 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000030 );
	if( F_Count[ playerid ] == 57 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000002A );
	if( F_Count[ playerid ] == 58 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000020 );
	if( F_Count[ playerid ] == 59 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000001A );
	if( F_Count[ playerid ] == 60 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x00000010 );
	if( F_Count[ playerid ] == 61 ) return PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x0000000A );
	if( F_Count[ playerid ] == 62 ) return PlayerTextDrawHide( playerid, Fading[ playerid ] ), F_Count[ playerid ] = 0, KillTimer( Timer_Fading[ playerid ] );

	return true;
}

stock FadeFromBlack( playerid ) 
{
	if( F_Count[ playerid ] >= 32 ) return false;

	Timer_Fading[ playerid ] = SetTimerEx( "Black_Fading", 50, true, "i", playerid );
	PlayerTextDrawShow( playerid, Fading[ playerid ] );
	PlayerTextDrawBoxColor( playerid, Fading[ playerid ], 0x000000FF );
	F_Count[ playerid ] = 32;
	return true;
}
//

stock CheckDeleteProperty( id )
{

	if( id != IPI )
	{

		if( PlayerInfo[ id ][ xProperty ][ 0 ] != -1 && strcmp( ImeIgraca( id ), II[ PlayerInfo[ id ][ xProperty ][ 0 ] ][ iOwner ], true) == 0)
		{

			II[ PlayerInfo[ id ][ xProperty ][ 0 ] ][ iOwned ] = 0;
			II[ PlayerInfo[ id ][ xProperty ][ 0 ] ][ iNeaktivnost ] = 0;
			strmid( II[ PlayerInfo[ id ][ xProperty ][ 0 ] ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
			PropertyRefresh( PlayerInfo[ id ][ xProperty ][ 0 ] );
			SaveProperty( PlayerInfo[ id ][ xProperty ][ 0 ] );
		}
		if( PlayerInfo[ id ][ xProperty ][ 1 ] != -1 && strcmp( ImeIgraca( id ), II[ PlayerInfo[ id ][ xProperty ][ 1 ] ][ iOwner ], true) == 0)
		{

			II[ PlayerInfo[ id ][ xProperty ][ 1 ] ][ iOwned ] = 0;
			II[ PlayerInfo[ id ][ xProperty ][ 1 ] ][ iNeaktivnost ] = 0;
			strmid( II[ PlayerInfo[ id ][ xProperty ][ 1 ] ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
			PropertyRefresh( PlayerInfo[ id ][ xProperty ][ 1 ] );
			SaveProperty( PlayerInfo[ id ][ xProperty ][ 1 ] );
		}
		if( PlayerInfo[ id ][ xProperty ][ 2 ] != -1 && strcmp( ImeIgraca( id ), II[ PlayerInfo[ id ][ xProperty ][ 2 ] ][ iOwner ], true) == 0)
		{

			II[ PlayerInfo[ id ][ xProperty ][ 2 ] ][ iOwned ] = 0;
			II[ PlayerInfo[ id ][ xProperty ][ 2 ] ][ iNeaktivnost ] = 0;
			strmid( II[ PlayerInfo[ id ][ xProperty ][ 2 ] ][ iOwner], "Drzava", 0, strlen( "Drzava" ), 32);
			PropertyRefresh( PlayerInfo[ id ][ xProperty ][ 2 ] );
			SaveProperty( PlayerInfo[ id ][ xProperty ][ 2 ] );
		}
		if( PlayerInfo[ id ][ xFirmaID ] != -1 && strcmp( ImeIgraca( id ), BussinesInfo[ PlayerInfo[ id ][ xFirmaID ] ][ bOwner ], true) == 0)
		{

			BussinesInfo[ PlayerInfo[ id ][ xFirmaID ] ][ bOwned ] = 0;
			BussinesInfo[ PlayerInfo[ id ][ xFirmaID ] ][ bNeaktivnost ] = 0;
			BussinesInfo[ PlayerInfo[ id ][ xFirmaID ] ][ bFacture ] = 100;
			strmid( BussinesInfo[ PlayerInfo[ id ][ xFirmaID ] ][ bOwner ], "Drzava", 0, strlen( "Drzava" ), 32);
			Bussines_Refresh( PlayerInfo[ id ][ xFirmaID ] );
			SaveBussines( PlayerInfo[ id ][ xFirmaID ] );
		}
		if( PlayerInfo[ id ][ xHotelID ] != -1 && strcmp( ImeIgraca( id ), hotelInfo[ PlayerInfo[ id ][ xHotelID ] ][ hOwner ], true) == 0)
		{

			hotelInfo[ PlayerInfo[ id ][ xHotelID ] ][ hOwned ] = 0;
			strmid( hotelInfo[ PlayerInfo[ id ][ xHotelID ] ][ hOwner ], "Drzava", 0, strlen( "Drzava" ), 32);
			HotelRefresh( PlayerInfo[ id ][ xHotelID ] );
			SaveHotel( PlayerInfo[ id ][ xHotelID ] );
		}
		if( PlayerInfo[ id ][ xGarageID ] != -1 && strcmp( ImeIgraca( id ), garageInfo[ PlayerInfo[ id ][ xGarageID ] ][ garageOwner ], true ) == 0)
		{

			garageInfo[ PlayerInfo[ id ][ xGarageID ] ][ garageOwned ] = false;
			strmid( garageInfo[ PlayerInfo[ id ][ xGarageID ] ][ garageOwner ], "Drzava", 0, strlen( "Drzava" ), 32);
			Garage_Refresh( PlayerInfo[ id ][ xGarageID ] );
			Garage_Save( PlayerInfo[ id ][ xGarageID ] );
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( PlayerInfo[ id ][ xVoziloID ][ 0 ] != -1 && strcmp( ImeIgraca( id ), VehicleInfo[ PlayerInfo[ id ][ xVoziloID ][ 0 ] ][ vOwner ], true) == 0)
		{

			new c = PlayerInfo[ id ][ xVoziloID ][ 0 ];
			new Float:vehx, Float:vehy, Float:vehz, Float:veha;
			new novacena = VehPrice[ VehicleInfo[ c ][ vModel ] - 400 ][ 1 ];//prava cijena kolko kosta u salonu
			new polovnacena = novacena/2; //pola od prave
			new polovnacena2 = novacena/4;
			new zadnjacena = polovnacena+polovnacena2;
			GetVehiclePos(c, vehx, vehy, vehz);
			GetVehicleZAngle(c, veha);
			
			Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
			VehicleInfo[ c ][ Validv3DText ] = false;
			
			
			Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

			VehicleInfo[ c ][ vVirtualWorld ] = 0;
			VehicleInfo[ c ][ vInterior ] = 0;
			
			VehicleInfo[ c ][ vReg ] = 0;
			VehicleInfo[ c ][ vTeh ] = 0;
			VehicleInfo[ c ][ vRegVreme ] = 0;

			VehicleInfo[ c ][ vOwned ] = 0;
			VehicleInfo[ c ][ vNeaktivnost ] = 0;
			VehicleInfo[ c ][ vPrice ] = zadnjacena;
			VehicleInfo[ c ][ vLocked ] = 0;

			VehicleInfo[ c ][ vLokacijaX ] = vehx;
			VehicleInfo[ c ][ vLokacijaY ] = vehy;
			VehicleInfo[ c ][ vLokacijaZ ] = vehz;
			VehicleInfo[ c ][ vLokacijaA ] = veha;

			VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
			LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
			SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );

			strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

			TuneVehicle( c );
			SetVehicleLabels( c );

			SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
			{
				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( PlayerInfo[ id ][ xVoziloID ][ 1 ] != -1 && strcmp( ImeIgraca( id ), VehicleInfo[ PlayerInfo[ id ][ xVoziloID ][ 1 ] ][ vOwner ], true) == 0)
		{

			new c = PlayerInfo[ id ][ xVoziloID ][ 1 ];
			new Float:vehx, Float:vehy, Float:vehz, Float:veha;
			new novacena = VehPrice[ VehicleInfo[ c ][ vModel ] - 400 ][ 1 ];//prava cijena kolko kosta u salonu
			new polovnacena = novacena/2; //pola od prave
			new polovnacena2 = novacena/4;
			new zadnjacena = polovnacena+polovnacena2;
			GetVehiclePos(c, vehx, vehy, vehz);
			GetVehicleZAngle(c, veha);
			
			Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
			VehicleInfo[ c ][ Validv3DText ] = false;
			
			Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

			VehicleInfo[ c ][ vVirtualWorld ] = 0;
			VehicleInfo[ c ][ vInterior ] = 0;
			
			VehicleInfo[ c ][ vReg ] = 0;
			VehicleInfo[ c ][ vTeh ] = 0;
			VehicleInfo[ c ][ vRegVreme ] = 0;

			VehicleInfo[ c ][ vOwned ] = 0;
			VehicleInfo[ c ][ vNeaktivnost ] = 0;
			VehicleInfo[ c ][ vPrice ] = zadnjacena;
			VehicleInfo[ c ][ vLocked ] = 0;

			VehicleInfo[ c ][ vLokacijaX ] = vehx;
			VehicleInfo[ c ][ vLokacijaY ] = vehy;
			VehicleInfo[ c ][ vLokacijaZ ] = vehz;
			VehicleInfo[ c ][ vLokacijaA ] = veha;

			VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
			LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
			SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );

			strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

			TuneVehicle( c );
			SetVehicleLabels( c );

			SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
			{
				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( PlayerInfo[ id ][ xVoziloID ][ 2 ] != -1 && strcmp( ImeIgraca( id ), VehicleInfo[ PlayerInfo[ id ][ xVoziloID ][ 2 ] ][ vOwner ], true) == 0)
		{

			new c = PlayerInfo[ id ][ xVoziloID ][ 2 ];
			new Float:vehx, Float:vehy, Float:vehz, Float:veha;
			new novacena = VehPrice[ VehicleInfo[ c ][ vModel ] - 400 ][ 1 ];//prava cijena kolko kosta u salonu
			new polovnacena = novacena/2; //pola od prave
			new polovnacena2 = novacena/4;
			new zadnjacena = polovnacena+polovnacena2;
			GetVehiclePos(c, vehx, vehy, vehz);
			GetVehicleZAngle(c, veha);
			
			Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
			VehicleInfo[ c ][ Validv3DText ] = false;
			
			Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

			VehicleInfo[ c ][ vVirtualWorld ] = 0;
			VehicleInfo[ c ][ vInterior ] = 0;
			
			VehicleInfo[ c ][ vReg ] = 0;
			VehicleInfo[ c ][ vTeh ] = 0;
			VehicleInfo[ c ][ vRegVreme ] = 0;

			VehicleInfo[ c ][ vOwned ] = 0;
			VehicleInfo[ c ][ vNeaktivnost ] = 0;
			VehicleInfo[ c ][ vPrice ] = zadnjacena;
			VehicleInfo[ c ][ vLocked ] = 0;

			VehicleInfo[ c ][ vLokacijaX ] = vehx;
			VehicleInfo[ c ][ vLokacijaY ] = vehy;
			VehicleInfo[ c ][ vLokacijaZ ] = vehz;
			VehicleInfo[ c ][ vLokacijaA ] = veha;

			VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
			LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
			SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );

			strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

			TuneVehicle( c );
			SetVehicleLabels( c );

			SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
			{
				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( PlayerInfo[ id ][ xVoziloID ][ 3 ] != -1 && strcmp( ImeIgraca( id ), VehicleInfo[ PlayerInfo[ id ][ xVoziloID ][ 3 ] ][ vOwner ], true) == 0) {

			new c = PlayerInfo[ id ][ xVoziloID ][ 3 ];
			new Float:vehx, Float:vehy, Float:vehz, Float:veha;
			new novacena = VehPrice[ VehicleInfo[ c ][ vModel ] - 400 ][ 1 ];//prava cijena kolko kosta u salonu
			new polovnacena = novacena/2; //pola od prave
			new polovnacena2 = novacena/4;
			new zadnjacena = polovnacena+polovnacena2;
			GetVehiclePos(c, vehx, vehy, vehz);
			GetVehicleZAngle(c, veha);
			
			Delete3DTextLabel( VehicleInfo[ c ][ v3DText ] );
			VehicleInfo[ c ][ Validv3DText ] = false;
			
			Dimi_DestroyVehicle( VehicleInfo[ c ][ vID ] );

			VehicleInfo[ c ][ vVirtualWorld ] = 0;
			VehicleInfo[ c ][ vInterior ] = 0;
			
			VehicleInfo[ c ][ vReg ] = 0;
			VehicleInfo[ c ][ vTeh ] = 0;
			VehicleInfo[ c ][ vRegVreme ] = 0;

			VehicleInfo[ c ][ vOwned ] = 0;
			VehicleInfo[ c ][ vNeaktivnost ] = 0;
			VehicleInfo[ c ][ vPrice ] = zadnjacena;
			VehicleInfo[ c ][ vLocked ] = 0;

			VehicleInfo[ c ][ vLokacijaX ] = vehx;
			VehicleInfo[ c ][ vLokacijaY ] = vehy;
			VehicleInfo[ c ][ vLokacijaZ ] = vehz;
			VehicleInfo[ c ][ vLokacijaA ] = veha;

			VehicleInfo[ c ][ vID ] = Dimi_CreateVehicle( c, NAPRODAJU_VOZILO, -1, -1, -1, VehicleInfo[ c ][ vModel ], VehicleInfo[ c ][ vLokacijaX ], VehicleInfo[ c ][ vLokacijaY ], VehicleInfo[ c ][ vLokacijaZ ]+1.0, VehicleInfo[ c ][ vLokacijaA ], VehicleInfo[ c ][ vColor1 ], VehicleInfo[ c ][ vColor2 ], 300000 );
			LinkVehicleToInterior( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vInterior ] );
			SetVehicleVirtualWorld( VehicleInfo[ c ][ vID ], VehicleInfo[ c ][ vVirtualWorld ] );

			strmid( VehicleInfo[ c ][ vOwner ], "Drzava", 0, strlen( "Drzava" ), 32);

			TuneVehicle( c );
			SetVehicleLabels( c );

			SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 0, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			if( IsVehicleBajs( VehicleInfo[ c ][ vID ] ) )
			{
				SetVehicleParamsEx( VehicleInfo[ c ][ vID ], 1, 0, 0, VehicleInfo[ c ][ vLocked ], 0, 0, 0 );
			}
		}
	}
	return true;
}

//------------------------------------------------------------------------------

forward RemoveRadarPictured( playerid );
public RemoveRadarPictured( playerid ) {

	alreadyPictured[ playerid ] = false;
	return 1;
}

stock RadarColor( playerid ) {

	if( Radar_Count[ playerid ] >= 32 ) return false;

	Timer_Radar[ playerid ] = SetTimerEx( "Radar_Color", 10, true, "i", playerid );
	PlayerTextDrawShow( playerid, RadarCol[ playerid ] );
	PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000FF );
	Radar_Count[ playerid ] = 32;
	return true;
}

forward Radar_Color( playerid );
public Radar_Color( playerid ) {

	Radar_Count[ playerid ]++;

	PlayerTextDrawHide( playerid, RadarCol[ playerid ] );
	PlayerTextDrawShow( playerid, RadarCol[ playerid ] );

	if( Radar_Count[ playerid ] == 1 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00000A );
	if( Radar_Count[ playerid ] == 2 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000010 );
	if( Radar_Count[ playerid ] == 3 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00001A );
	if( Radar_Count[ playerid ] == 4 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000020 );
	if( Radar_Count[ playerid ] == 5 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00002A );
	if( Radar_Count[ playerid ] == 6 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000030 );
	if( Radar_Count[ playerid ] == 7 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00003A );
	if( Radar_Count[ playerid ] == 8 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000040 );
	if( Radar_Count[ playerid ] == 9 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00004A );
	if( Radar_Count[ playerid ] == 10 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000050 );
	if( Radar_Count[ playerid ] == 11 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00005A );
	if( Radar_Count[ playerid ] == 12 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000060 );
	if( Radar_Count[ playerid ] == 13 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00006A );
	if( Radar_Count[ playerid ] == 14 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000070 );
	if( Radar_Count[ playerid ] == 15 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00007A );
	if( Radar_Count[ playerid ] == 16 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000080 );
	if( Radar_Count[ playerid ] == 17 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00008A );
	if( Radar_Count[ playerid ] == 18 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000090 );
	if( Radar_Count[ playerid ] == 19 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00009A );
	if( Radar_Count[ playerid ] == 20 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000A1 );
	if( Radar_Count[ playerid ] == 21 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000AA );
	if( Radar_Count[ playerid ] == 22 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000B1 );
	if( Radar_Count[ playerid ] == 23 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000BB );
	if( Radar_Count[ playerid ] == 24 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000C1 );
	if( Radar_Count[ playerid ] == 25 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000CC );
	if( Radar_Count[ playerid ] == 26 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000D1 );
	if( Radar_Count[ playerid ] == 27 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000DD );
	if( Radar_Count[ playerid ] == 28 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000E1 );
	if( Radar_Count[ playerid ] == 29 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000EE );
	if( Radar_Count[ playerid ] == 30 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000F1 );
	if( Radar_Count[ playerid ] == 31 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000FF );

	if( Radar_Count[ playerid ] == 32 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000F1 );
	if( Radar_Count[ playerid ] == 33 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000EE );
	if( Radar_Count[ playerid ] == 34 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000E1 );
	if( Radar_Count[ playerid ] == 35 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000DD );
	if( Radar_Count[ playerid ] == 36 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000D1 );
	if( Radar_Count[ playerid ] == 37 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000CC );
	if( Radar_Count[ playerid ] == 38 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000C1 );
	if( Radar_Count[ playerid ] == 39 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000BB );
	if( Radar_Count[ playerid ] == 40 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000B1 );
	if( Radar_Count[ playerid ] == 41 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000AA );
	if( Radar_Count[ playerid ] == 42 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF0000A1 );
	if( Radar_Count[ playerid ] == 43 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00009A );
	if( Radar_Count[ playerid ] == 44 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000090 );
	if( Radar_Count[ playerid ] == 45 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00008A );
	if( Radar_Count[ playerid ] == 46 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000080 );
	if( Radar_Count[ playerid ] == 47 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00007A );
	if( Radar_Count[ playerid ] == 48 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000070 );
	if( Radar_Count[ playerid ] == 49 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00006A );
	if( Radar_Count[ playerid ] == 50 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000060 );
	if( Radar_Count[ playerid ] == 51 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00005A );
	if( Radar_Count[ playerid ] == 52 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000050 );
	if( Radar_Count[ playerid ] == 53 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00004A );
	if( Radar_Count[ playerid ] == 54 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000040 );
	if( Radar_Count[ playerid ] == 55 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00003A );
	if( Radar_Count[ playerid ] == 56 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000030 );
	if( Radar_Count[ playerid ] == 57 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00002A );
	if( Radar_Count[ playerid ] == 58 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000020 );
	if( Radar_Count[ playerid ] == 59 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00001A );
	if( Radar_Count[ playerid ] == 60 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF000010 );
	if( Radar_Count[ playerid ] == 61 ) return PlayerTextDrawBoxColor( playerid, RadarCol[ playerid ], 0xFF00000A );
	if( Radar_Count[ playerid ] == 62 ) return PlayerTextDrawHide( playerid, RadarCol[ playerid ] ), Radar_Count[ playerid ] = 0, Dimi_KillTimer( Timer_Radar[ playerid ] );

	return true;
}
//------------------------------------------------------------------------------
stock JailPlayer( id, time )
{

	ResetAllWeapons( id );
	PlayerInfo[ id ][ xZatvor ] = OBICAN_ZATVOR;
	PlayerInfo[ id ][ xZatvorVreme ] = time;
	ClearAnimations( id );
	PlayerCP[ id ] = 0;
	if( IsPlayerAttachedObjectSlotUsed( id, OBJECT_SLOT_RHAND ) ) RemovePlayerAttachedObject( id, OBJECT_SLOT_RHAND );
	SetPlayerSpecialAction( id, SPECIAL_ACTION_NONE );
	PlayerCuffed[ id ] = 0;
	
	format( globalstring, sizeof( globalstring ), "~r~Do slobode: ~w~%d ~r~min",( PlayerInfo[ id ][ xZatvorVreme ]+1 ) );
	PlayerTextDrawSetString(id,JailTD[id],globalstring);
	PlayerTextDrawShow(id,JailTD[id]);
	
	new rand = random( sizeof( RandomZatvor ) );
	Dimi_SetPlayerPos( id, RandomZatvor[ rand ][ 0 ], RandomZatvor[ rand ][ 1 ],RandomZatvor[ rand ][ 2 ] );
	PlayerInfo[ id ][ xWanted ] = 0;
	Dimi_SetPlayerWantedLevel( id, PlayerInfo[ id ][ xWanted ] );
	strmid( ZlocinInfo[ id ][ zPrijavio ], "Nema", 0, strlen("Nema"), 255 );
	strmid( ZlocinInfo[ id ][ zPocinio ], "Nema", 0, strlen("Nema"), 255 );
	strmid( ZlocinInfo[ id ][ zZlocin ], "Nema", 0, strlen("Nema"), 255 );
	announcement( id, "~y~Ucitavanje sistema i objekata...", 1000, 4 );
	SetTimerEx( "SlobodnoSada", 2000, false, "i", id );
	SetCameraBehindPlayer( id ); SetPlayerInterior( id, 1 );
	SetPlayerVirtualWorld( id, 1 );
	TogglePlayerControllable( id, 0 );
	SavePlayer( id );
}
//------------------------------------------------------------------------------
stock randomString(strDest[], strLen = 10)
{
	while(strLen--)
		strDest[strLen] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
}
//------------------------------------------------------------------------------
stock CreateDroppedGun( GunID, GunAmmo, Float:gPosX, Float:gPosY, Float:gPosZ ) {
	for( new a = 0; a < MAX_GOBJ; a++ ) {
		if( dGunData[ a ][ ObjPos ][ 0 ] == 0.0 ) {
			dGunData[ a ][ ObjData ][ 0 ] = GunID;
			dGunData[ a ][ ObjData ][ 1 ] = GunAmmo;
			dGunData[ a ][ ObjPos ][ 0 ] = gPosX;
			dGunData[ a ][ ObjPos ][ 1 ] = gPosY;
			dGunData[ a ][ ObjPos ][ 2 ] = gPosZ;
			dGunData[ a ][ PUBG ] = 0;
			dGunData[ a ][ gObjID ] = CreateDynamicObject( WeaponInfos[ GunID ][ wModel ], dGunData[ a ][ ObjPos ][ 0 ], dGunData[ a ][ ObjPos ][ 1 ], dGunData[ a ][ ObjPos ][ 2 ]-1, 93.7, 120.0, random(360) );
			return 1;
		}
	}
	return 1;
}

stock CreatePUBGDroppedGun( GunID, GunAmmo, Float:gPosX, Float:gPosY, Float:gPosZ ) {
	for( new a = 0; a < MAX_GOBJ; a++ ) {
		if( dGunData[ a ][ ObjPos ][ 0 ] == 0.0 ) {
			dGunData[ a ][ ObjData ][ 0 ] = GunID;
			dGunData[ a ][ ObjData ][ 1 ] = GunAmmo;
			dGunData[ a ][ ObjPos ][ 0 ] = gPosX;
			dGunData[ a ][ ObjPos ][ 1 ] = gPosY;
			dGunData[ a ][ ObjPos ][ 2 ] = gPosZ;
			dGunData[ a ][ gObjID ] = CreateDynamicObject( WeaponInfos[ GunID ][ wModel ], dGunData[ a ][ ObjPos ][ 0 ], dGunData[ a ][ ObjPos ][ 1 ], dGunData[ a ][ ObjPos ][ 2 ]-1, 93.7, 120.0, random(360), pubg_server );
			dGunData[ a ][ PUBG ] = 1;
			return 1;
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock Dimi_KillTimer( timerid ) {
	if( timerid == -1 ) return 1;
	return KillTimer( timerid );
}
//------------------------------------------------------------------------------
stock IsPlayerInArea(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy) {
	new Float:Poz[ 3 ];
	GetPlayerPos(playerid, Poz[ 0 ], Poz[ 1 ], Poz[ 2 ]);
	if(Poz[ 0 ] > minx && Poz[ 0 ] < maxx && Poz[ 1 ] > miny && Poz[ 1 ] < maxy) return true;
	return false;
}
//------------------------------------------------------------------------------

stock IsSeatAvailable( vehicleid, seat)
{
	new carmodel = GetVehicleModel( vehicleid);
	for (new i = 0; i < sizeof( OneSeatVehicles ); i++ )
	{
		if( carmodel == OneSeatVehicles[i] ) return 0;
	}
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(GetPlayerVehicleID(i) == vehicleid && GetPlayerVehicleSeat(i) == seat) return 0;
	}
	return 1;
}
//
stock Javno3( playerid ) {

	if(IsPlayerConnected( playerid ) )
	{
		if(IsPlayerInRangeOfPoint(playerid, 10,1505.9548,-1741.5792,13.5469) || IsPlayerInRangeOfPoint(playerid, 10,1504.6154,-1741.4963,13.5469) || IsPlayerInRangeOfPoint(playerid, 10,1497.7278,-1733.2307,13.3828) || IsPlayerInRangeOfPoint(playerid, 10,1491.7355,-1738.8771,14.1983) || IsPlayerInRangeOfPoint(playerid, 10,1480.0619,-1741.7356,13.6287) || IsPlayerInRangeOfPoint(playerid, 10,1471.7213,-1740.6451,14.3646))
		{
			return 1;
		}
	}
	return 0;
}

stock Javno4(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 10,1458.7819,-1739.5323,13.9193) || IsPlayerInRangeOfPoint(playerid, 10,1451.9343,-1732.9948,14.2465) || IsPlayerInRangeOfPoint(playerid, 10,1455.6887,-1728.3517,14.0456) || IsPlayerInRangeOfPoint(playerid, 10,1470.7139,-1752.2955,15.4453) || IsPlayerInRangeOfPoint(playerid, 10,1478.5802,-1754.8750,17.4498) || IsPlayerInRangeOfPoint(playerid, 10,1490.0334,-1755.7047,17.4401))
		{
			return 1;
		}
	}
	return 0;
}

stock Javno5(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 10,1483.5298,-1762.2010,18.7289) || IsPlayerInRangeOfPoint(playerid, 10,1475.8184,-1767.5063,18.7958) || IsPlayerInRangeOfPoint(playerid, 10,1224.2733,-930.6243,42.5903) || IsPlayerInRangeOfPoint(playerid, 10,1232.1556,-929.4727,42.5212) || IsPlayerInRangeOfPoint(playerid, 10,1218.4210,-931.0319,42.9727) || IsPlayerInRangeOfPoint(playerid, 10,1209.4436,-926.8596,42.9230))
		{
			return 1;
		}
	}
	return 0;
}

stock Javno6(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 10,1205.9155,-920.4095,43.0673) || IsPlayerInRangeOfPoint(playerid, 10,1195.8317,-921.3834,43.8945) || IsPlayerInRangeOfPoint(playerid, 10,1181.4392,-915.1285,43.2192) || IsPlayerInRangeOfPoint(playerid, 10,1177.5984,-899.8451,44.1480) || IsPlayerInRangeOfPoint(playerid, 10,1180.8157,-887.0159,43.4167) || IsPlayerInRangeOfPoint(playerid, 10,1190.9819,-883.4169,43.2069))
		{
			return 1;
		}
	}
	return 0;
}

stock Javno7(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 10,1205.1240,-881.5010,42.9346) || IsPlayerInRangeOfPoint(playerid, 10,1217.4341,-882.3506,42.9045) || IsPlayerInRangeOfPoint(playerid, 10,1223.5906,-892.5105,43.4221) || IsPlayerInRangeOfPoint(playerid, 10,1226.6726,-911.0240,42.9017))
		{
			return 1;
		}
	}
	return 0;
}

stock Javno8(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 40,1218.4386,-1334.5829,13.4835) || IsPlayerInRangeOfPoint(playerid, 10,1219.6810,-932.0195,42.6316) || IsPlayerInRangeOfPoint(playerid, 10,1481.5367,-1732.5997,13.3828) || IsPlayerInRangeOfPoint(playerid, 10,1544.8290,-2324.2332,13.5547) || IsPlayerInRangeOfPoint(playerid, 10,1198.5538,-1325.6200,13.3984))
		{
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock randomEx(min,max) {
	return (min+random(max));
}

stock randomExx(const iMin, const iMax) {
	return random(iMax - iMin) + iMin;
}
#if kladionica == 1
stock IzvuciRezultateKladionica( ) {

	new par1[ 10 ], par2[ 10 ];

	for( new i = 0; i < 10; i++ ) {

		par1[ i ] = Parovi[ i ][ parID ][ 0 ];
		par2[ i ] = Parovi[ i ][ parID ][ 1 ];

		if( bettingInfo[ par1[ i ] ][ teamStrength ] >  bettingInfo[ par2[ i ] ][ teamStrength ] ) {

			new rand = random( 10 );
			switch( rand ) {

				case 0..5: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 1;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 0 ];
				}
				case 6: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 2;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 2 ];
				}
				case 7..9: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 2 ] = 3;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 1 ];
				}

			}
		}
		else if( bettingInfo[ par1[ i ] ][ teamStrength ] ==  bettingInfo[ par2[ i ] ][ teamStrength ] ) {

			new rand = random( 10 );
			switch( rand ) {

				case 0..5: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 2;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 2 ];
				}
				case 6..7: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 2 ] = 3;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 1 ];
				}
				case 8..9: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 1;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 0 ];
				}

			}
		}
		else if( bettingInfo[ par2[ i ] ][ teamStrength ] >  bettingInfo[ par1[ i ] ][ teamStrength ] ) {

			new rand = random( 10 );
			switch( rand ) {

				case 0..5: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 2 ] = 3;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 1 ];
				}
				case 6: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez;
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 2;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 2 ];
				}
				case 7..9: {

					new rez = random( 4 );
					Parovi[ i ][ Rezultat ][ 0 ] = rez+(1+random( 2 ));
					Parovi[ i ][ Rezultat ][ 1 ] = rez;
					Parovi[ i ][ Rezultat ][ 2 ] = 1;
					StariParovi[ i ][ Kvota ] = Parovi[ i ][ Kvota ][ 0 ];
				}
			}
		}


		new hour, minute, second, day, year, month;
		getdate( year, month, day );
		gettimeEx( hour, minute, second ); 
		FixHour( hour );
		hour = shifthour;

		StariParovi[ i ][ Rezultat ][ 0 ] = Parovi[ i ][ Rezultat ][ 0 ];
		StariParovi[ i ][ Rezultat ][ 1 ] = Parovi[ i ][ Rezultat ][ 1 ];
		StariParovi[ i ][ parID ][ 0 ] = par1[ i ];
		StariParovi[ i ][ parID ][ 1 ] = par2[ i ];
		
		new staar[ 32 ];
		format( staar, sizeof( staar ), "%d.%d.%d %02d:30", day, month, year, hour );
		strmid( StariParovi[ i ][ HourPobeda ], staar, 0, strlen( staar ), 32 );
		
		SaveStareParove( );
		
		//SendClientMessageEx( playerid, -1, "%s %d : %d %s ", bettingInfo[ par1[ i ] ][ teamName ], Parovi[ i ][ Rezultat ][ 0 ], Parovi[ i ][ Rezultat ][ 1 ], bettingInfo[ par2[ i ] ][ teamName ] );
	}
	return (true);
}

stock PostaviParoveKladionica( ) {

		new par1[ 10 ], par2[ 10 ], razlika[ 10 ], Float:ki1[ 10 ], Float:ki2[ 10 ], Float:iks[ 10 ];

		NapraviParove( ); NapraviParove2( );

		for( new i = 0; i < 10; i++ ) {

			par1[ i ] = IzabraniParovi1[ i ];
			par2[ i ] = IzabraniParovi2[ i ];

			razlika[ i ] = bettingInfo[ par1[ i ] ][ teamStrength ] - bettingInfo[ par2[ i ] ][ teamStrength ];

			if( razlika[ i ] == -9 ) ki1[ i ] = 4.8, ki2[ i ] = 1.2, iks[ i ] = 4.0;
			else if( razlika[ i ] == -8 ) ki1[ i ] = 4.6, ki2[ i ] = 1.4, iks[ i ] = 3.8;
			else if( razlika[ i ] == -7 ) ki1[ i ] = 4.4, ki2[ i ] = 1.6, iks[ i ] = 3.6;
			else if( razlika[ i ] == -6 ) ki1[ i ] = 4.2, ki2[ i ] = 1.8, iks[ i ] = 3.4;
			else if( razlika[ i ] == -5 ) ki1[ i ] = 4.0, ki2[ i ] = 2.0, iks[ i ] = 3.2;
			else if( razlika[ i ] == -4 ) ki1[ i ] = 3.8, ki2[ i ] = 2.2, iks[ i ] = 3.0;
			else if( razlika[ i ] == -3 ) ki1[ i ] = 3.6, ki2[ i ] = 2.4, iks[ i ] = 2.8;
			else if( razlika[ i ] == -2 ) ki1[ i ] = 3.4, ki2[ i ] = 2.6, iks[ i ] = 2.6;
			else if( razlika[ i ] == -1 ) ki1[ i ] = 3.2, ki2[ i ] = 2.8, iks[ i ] = 2.4;
			else if( razlika[ i ] == 0 ) ki1[ i ] = 3.0, ki2[ i ] = 3.0, iks[ i ] = 3.0;
			else if( razlika[ i ] == 1 ) ki1[ i ] = 2.8, ki2[ i ] = 3.2, iks[ i ] = 2.4;
			else if( razlika[ i ] == 2 ) ki1[ i ] = 2.6, ki2[ i ] = 3.4, iks[ i ] = 2.6;
			else if( razlika[ i ] == 3 ) ki1[ i ] = 2.4, ki2[ i ] = 3.6, iks[ i ] = 2.8;
			else if( razlika[ i ] == 4 ) ki1[ i ] = 2.2, ki2[ i ] = 3.8, iks[ i ] = 3.0;
			else if( razlika[ i ] == 5 ) ki1[ i ] = 2.0, ki2[ i ] = 4.0, iks[ i ] = 3.2;
			else if( razlika[ i ] == 6 ) ki1[ i ] = 1.8, ki2[ i ] = 4.2, iks[ i ] = 3.4;
			else if( razlika[ i ] == 7 ) ki1[ i ] = 1.6, ki2[ i ] = 4.4, iks[ i ] = 3.6;
			else if( razlika[ i ] == 8 ) ki1[ i ] = 1.4, ki2[ i ] = 4.6, iks[ i ] = 3.8;
			else if( razlika[ i ] == 9 ) ki1[ i ] = 1.2, ki2[ i ] = 4.8, iks[ i ] = 4.0;

			Parovi[ i ][ parID ][ 0 ] = par1[ i ];
			Parovi[ i ][ parID ][ 1 ] = par2[ i ];
			Parovi[ i ][ Kvota ][ 0 ] = ki1[ i ];
			Parovi[ i ][ Kvota ][ 1 ] = ki2[ i ];
			Parovi[ i ][ Kvota ][ 2 ] = iks[ i ];
			Parovi[ i ][ Rezultat ][ 0 ] = 0;
			Parovi[ i ][ Rezultat ][ 1 ] = 0;
			Parovi[ i ][ Rezultat ][ 2 ] = 0;

		}
		return (true);
}

stock NapraviParove( ) {

	for( new i = 0; i < 10; i++ ) {
	
		IzabraniParovi1[ i ] = Random_Number_Generator( i, 46 );
	}
	return (true);
}

stock NapraviParove2( ) {

	for( new i = 0; i < 10; i++ ) {
	
		IzabraniParovi2[ i ] = Random_Number_Generator_2( i, 46 );
	}
	return (true);
}

stock Random_Number_Generator_2(curid,max)
{
	new Num_Var_Index;

	Num_Var_Index = random(max);

	for( new i = 0; i < curid; i++ ) {
	
		if( IzabraniParovi2[ i ] == Num_Var_Index || IzabraniParovi1[ i ] == Num_Var_Index ) return Random_Number_Generator_2(curid,max);
	}

	return Num_Var_Index;
}

stock Random_Number_Generator(curid,max)
{
	new Num_Var_Index;

	Num_Var_Index = random(max);

	for( new i = 0; i < curid; i++ ) {
	
		if( IzabraniParovi1[ i ] == Num_Var_Index || IzabraniParovi2[ i ] == Num_Var_Index ) return Random_Number_Generator(curid,max);
	}

	return Num_Var_Index;
}
#endif

forward IzvlacenjeKuglica( broj );
public IzvlacenjeKuglica( broj )
{

	if( broj == 1 )
	{
		SetTimerEx( "IzvlacenjeKuglica", 3000, false, "d", 2 );
	}
	else if( broj == 2 )
	{
		new LottoBroj = randomExx( 1, 100 );
		new LottoNagrada = ( 40000+random( 50000 ) );
		new ImaNagrade = 0, Dobitnik;
		new stringara[300];
		
		format( stringara, sizeof( stringara ), ""SERVERBOJA_SIVA"| {FFFFFF}LOTTO "SERVERBOJA_SIVA"| Izvrseno je izvlacenje lotto kombinacija i dobitni broj je "SERVERBOJA_AQUA"%d!", LottoBroj );
		SCMA( -1, stringara );
		
		for(new i; i < MAX_PLAYERS; i++)
		{
			if( PlayerInfo[ i ][ xLottoNumber ] == LottoBroj )
			{
				PlayerInfo[ i ][ xLottoMoney ] += LottoNagrada;
				ImaNagrade = 1;
				Dobitnik = i;
			}
			if( ImaNagrade == 1 )
			{
				format( stringara, sizeof( stringara ), ""SERVERBOJA_SIVA"| {FFFFFF}LOTTO WIN "SERVERBOJA_SIVA"| Srecni dobitnik "SERVERBOJA_AQUA"%s "SERVERBOJA_SIVA"osvojio je nagradu od: "SERVERBOJA_AQUA"%d$"SERVERBOJA_SIVA" CESTITAMO!", ImeIgraca( Dobitnik ),LottoNagrada );
				SCMA( -1, stringara );
			}
			PlayerInfo[ i ][ xLottoNumber ] = 0;
		}
		if( ImaNagrade == 0 )
		{
			SCMA( -1, ""SERVERBOJA_SIVA"| {FFFFFF}LOTTO "SERVERBOJA_SIVA"| Nazalost nemamo srecnih dobitnika ovaj put!" );
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock GetFactionType( playerid ) {
	if( PlayerInfo[ playerid ][ xClan ] == 0 )
		return 0;

	return ( OI[ PlayerInfo[ playerid ][ xClan ] ][ oTip ] );
}
//------------------------------------------------------------------------------

stock notfi(players_ingame_id,const posiljalac_poruke[],const tekst_poruke[]) {
	new message_color = -1;
	ascmex(players_ingame_id,message_color,""col_yelow"SMS | Broj: {ffffff}%s "col_yelow"| Tekst: {ffffff}%s",posiljalac_poruke,tekst_poruke);
	return 1;
}
stock SendClientMessagee( playerid, color, const strdfg[] ) 
{
	if( PlayerLogged[ playerid ] == true ) 
	{
		new stringicc[300];
		format(stringicc,sizeof(stringicc),"[NE] {ffffff}%s",strdfg);
		return SendClientMessage(playerid, color, stringicc );//SendClientMessageEx( playerid, color, ""col_balkanstory"BS | "SERVERBOJA_SIVA"%s", strdfg );
	}
	return color;
}
forward UtovarVoz( playerid );
public UtovarVoz( playerid ) {

	Dimi_KillTimer( PosaoMasinovodja[ playerid ] );
	TogglePlayerControllable( playerid, true );
	SendInfoMessage(playerid, "Novac zaradjen od karti: 100$");
	DajIgracuNovac(playerid, 100);
	announcement( playerid, "~y~Nova lokacija stanice je oznacena na mapi...", 3000, 3 );
	return 1;
}
//------------------------------------------------------------------------------
GetFreeFarmID( ) {
	for( new i = 0; i < MAX_FARMS; i++ ) {

		if( !plantInfo[ i ][ farmPlantCreated ] && !plantInfo[ i ][ farmWheatCreated ] && plantInfo[ i ][ farmObject ] == INVALID_OBJECT_ID ) {
			return i;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
ResetAllFarmPlants( ) {
	printf("[NE:RP] - Nova Era | Resetovanje sistema za biljke je u toku!");
	for( new i = 0; i < MAX_FARMS; i++ ) {
		ResetFarmPlant( i );
	}
}
//------------------------------------------------------------------------------
ResetFarmPlant( plantid ) {
	if( plantid != -1 ) {
		plantInfo[ plantid ][ farmPlayerID ] = IPI;
		plantInfo[ plantid ][ farmPlantCreated ] = false;
		plantInfo[ plantid ][ farmWheatCreated ] = false;
		plantInfo[ plantid ][ farmObject ] = INVALID_OBJECT_ID;
		plantInfo[ plantid ][ farm3D ] = Text3D:INVALID_3DTEXT_ID;
	}
	return -1;
}
//------------------------------------------------------------------------------
bool:isPlayerNearFarmerPlant( playerID )
{
	new Float:objectPos[ 3 ];

	for( new i = 0; i < MAX_FARMS; i++ ) {
	
		if( plantInfo[ i ][ farmPlantCreated ] && plantInfo[ i ][ farmObject ] != INVALID_OBJECT_ID && IsValidDynamicObject( plantInfo[ i ][ farmObject ] ) ) {

			GetDynamicObjectPos( plantInfo[ i ][ farmObject ], objectPos[ 0 ], objectPos[ 1 ], objectPos[ 2 ] );
			if( IsPlayerInRangeOfPoint( playerID, 5.0, objectPos[ 0 ], objectPos[ 1 ], objectPos[ 2 ] ) ) return true;

		}
	}
	return false;
}
//------------------------------------------------------------------------------
getPlayerNearFarmerPlant( playerID ) {

	new Float:objectPos[ 3 ];

	for( new i = 0; i < MAX_FARMS; i++ ) {
	
		if( plantInfo[ i ][ farmPlantCreated ] && plantInfo[ i ][ farmPlayerID ] == playerID ) {
		
			if( plantInfo[ i ][ farmObject ] != INVALID_OBJECT_ID && IsValidDynamicObject( plantInfo[ i ][ farmObject ] ) ) {
			
				GetDynamicObjectPos( plantInfo[ i ][ farmObject ], objectPos[ 0 ], objectPos[ 1 ], objectPos[ 2 ] );
				if( IsPlayerInRangeOfPoint( playerID, 5.0, objectPos[ 0 ], objectPos[ 1 ], objectPos[ 2 ] ) ) return i;
			}
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
stock IsCheatPosition( playerid ) {
	for( new i = 0; i < sizeof( CheatPositions );i++ )
		if( IsPlayerInRangeOfPoint( playerid, 5.0, CheatPositions[ i ][ 0 ], CheatPositions[ i ][ 1 ], CheatPositions[ i ][ 2 ] ) )
			return true;
	return false;
}
//------------------------------------------------------------------------------
stock PlayerHasTazer( playerid ) {
	return ( GetPlayerWeapon( playerid ) == 23 && ImaTazer[ playerid ] );
}
//------------------------------------------------------------------------------
stock NextGZoneID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_GZONE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock NextRadarID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_RADARS, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock NextFieldID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_FIELD, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock NextFStationID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), FSTATION_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}



GetNearestFuelStation( playerid ) {

	for( new i = 1; i < MAX_FSTATION; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 20.0, FuelStation[ i ][ fsPos ][ 0 ], FuelStation[ i ][  fsPos ][ 1 ], FuelStation[ i ][ fsPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

IsThatFuelStationMy( playerid ) {

	for( new i = 1; i < MAX_FSTATION; i++) {

		if( PlayerInfo[ playerid ][ xFirmaID ] == FuelStation[ i ][ fsBussinesID ] ) { return i; }
	}
	return -1;
}


FStation_Refresh( fstationID ) {

	new filename[ 32 ];

	if( fstationID != -1 ) {

		format( filename, sizeof( filename ), FSTATION_FILE, fstationID );

		if( fexist( filename ) ) {

			if( IsValidDynamic3DTextLabel( FuelStation[ fstationID ][ fs3d ] ) )
				DestroyDynamic3DTextLabel( FuelStation[ fstationID ][ fs3d ] );

			if( IsValidDynamicPickup( FuelStation[ fstationID ][ fsPickup ] ) )
				DestroyDynamicPickup( FuelStation[ fstationID ][ fsPickup ] );

			if( FuelStation[ fstationID ][ fsPlaced ] ) {

				new string[ 512 ];
				//format( string, sizeof( string ), ""col_balkanstory"[ {FFFFFF}%s"col_balkanstory" ]\nCijena benzina: {FFFFFF}%d$\n"col_balkanstory"Cijena dizela: {FFFFFF}%d$\n"col_balkanstory"Cena 1L PLINA: {FFFFFF}%d$\n"col_balkanstory"Cena 1L GASNOG ULJA: {FFFFFF}%d$\n{FFFFFF}/natoci\n"col_balkanstory"[ {FFFFFF}Adresa: {FFFFFF}%d "col_balkanstory"]",
				format( string, sizeof( string ), ""col_balkanstory"[ {FFFFFF}%s"col_balkanstory" ]\nCijena benzina: {FFFFFF}%d$\n"col_balkanstory"Cijena dizela: {FFFFFF}%d$\n{FFFFFF}/natoci\n"col_balkanstory"| {FFFFFF}Adresa: {FFFFFF}%d "col_balkanstory"|",
					FuelStation[ fstationID ][ fsName ],
					FuelStation[ fstationID ][ fsGasolinePrice ],
					FuelStation[ fstationID ][ fsDieselPrice ],
					fstationID );

				FuelStation[ fstationID ][ fs3d ] = CreateDynamic3DTextLabel( string, 0x33CCFFFF, FuelStation[ fstationID ][ fsPos ] [ 0 ], FuelStation[ fstationID ][ fsPos ] [ 1 ], FuelStation[ fstationID ][ fsPos ] [ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
				FuelStation[ fstationID ][ fsPickup ] = CreateDynamicPickup (1650, 1, FuelStation[ fstationID ][ fsPos ] [ 0 ], FuelStation[ fstationID ][ fsPos ] [ 1 ], FuelStation[ fstationID ][ fsPos ] [ 2 ], 0, 0 );
			}
		}
	}
}

//------------------------------------------------------------------------------
stock NextBGGPSID(const len)
{
		new id = (-1);
		for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop )
		{
			provjera = ( loop+1 );
			format( Data_, ( sizeof Data_ ), F_BGGPS, provjera );
			if(!fexist(Data_))
			{
			id = ( provjera );
			break;
		}
		}
		return ( id );
}
//------------------------------------------------------------------------------
stock NextSAGPSID(const len)
{
		new id = (-1);
		for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop )
		{
			provjera = ( loop+1 );
			format( Data_, ( sizeof Data_ ), F_SAGPS, provjera );
			if(!fexist(Data_))
			{
			id = ( provjera );
			break;
		}
		}
		return ( id );
}
//------------------------------------------------------------------------------
stock NextZGGPSID(const len)
{
		new id = (-1);
		for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop )
		{
			provjera = ( loop+1 );
			format( Data_, ( sizeof Data_ ), F_ZGGPS, provjera );
			if(!fexist(Data_))
			{
			id = ( provjera );
			break;
		}
		}
		return ( id );
}
//------------------------------------------------------------------------------
stock NextOSGPSID(const len)
{
		new id = (-1);
		for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop )
		{
			provjera = ( loop+1 );
			format( Data_, ( sizeof Data_ ), F_OSGPS, provjera );
			if(!fexist(Data_))
			{
			id = ( provjera );
			break;
		}
		}
		return ( id );
}



//------------------------------------------------------------------------------
stock NextGarageID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_GARAGE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//
GetNearestPresent( playerid ) {

	for( new i = 1; i < MAX_PRESENTS; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 3.0, presentsInfo[ i ][ presPos ][ 0 ], presentsInfo[ i ][  presPos ][ 1 ], presentsInfo[ i ][ presPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

stock NextPresentID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_PRESENTS, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}


//

GetNearestXOrb( playerid ) {

	for( new i = 1; i < MAX_XORBS; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 3.0, XmasOrbs[ i ][ xoPos ][ 0 ], XmasOrbs[ i ][  xoPos ][ 1 ], XmasOrbs[ i ][ xoPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

stock NextXOrbID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_XORBS, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}


//

GetNearestCTree( playerid ) {

	for( new i = 1; i < MAX_CTREES; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 3.0, CTree[ i ][ ctPos ][ 0 ], CTree[ i ][  ctPos ][ 1 ], CTree[ i ][ ctPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

stock NextCTreeID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_CTREES, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}


//------------------------------------------------------------------------------
ResetGarage( id ) {
	garageInfo[ id ][ garageOwned ] = false;
	strmid( garageInfo[ id ][ garageOwned ], "Drzava", 0, strlen( "Drzava" ), MAX_PLAYER_NAME );
	garageInfo[ id ][ garagePrice ] = 0;
	garageInfo[ id ][ garageLevel ] = 0;
	garageInfo[ id ][ garageLocked ] = false;
	garageInfo[ id ][ garagePos ][ 0 ] = 0.0;
	garageInfo[ id ][ garagePos ][ 1 ] = 0.0;
	garageInfo[ id ][ garagePos ][ 2 ] = 0.0;
	garageInfo[ id ][ garageVehiclePos ][ 0 ] = 0.0;
	garageInfo[ id ][ garageVehiclePos ][ 1 ] = 0.0;
	garageInfo[ id ][ garageVehiclePos ][ 2 ] = 0.0;
	garageInfo[ id ][ garageVehiclePos ][ 3 ] = 0.0;
	garageInfo[ id ][ garageVW ] = 0;
	garageInfo[ id ][ garageType ] = -1;
}

GetNearestGarage( playerid ) {

	for( new i = 1; i < MAX_GARAGES; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 3.0, garageInfo[ i ][ garagePos ][ 0 ], garageInfo[ i ][  garagePos ][ 1 ], garageInfo[ i ][ garagePos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

GetNearestRadar( playerid ) {

	for( new i = 1; i < MAX_RADARS; i++) {

		if( IsPlayerInRangeOfPoint( playerid, 10.0, radarInfo[ i ][ radarPos ][ 0 ], radarInfo[ i ][  radarPos ][ 1 ], radarInfo[ i ][ radarPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}

Garage_Refresh( id ) {
	new filename[ 32 ],
			vrsta[ 20 ],
				string[ 256 ];

	if( id  != -1 ) {

		format( filename, sizeof( filename ), F_GARAGE, id );

		if( fexist( filename ) ) {

			if( IsValidDynamic3DTextLabel( garageInfo[ id ][ garage3D ] ) )
				DestroyDynamic3DTextLabel( garageInfo[ id ][ garage3D ] );

			if( IsValidDynamicPickup( garageInfo[ id ][ garagePickup ] ) )
				DestroyDynamicPickup( garageInfo[ id ][ garagePickup ] );

			switch( garageInfo[ id ][ garageType ] ) {


				case 0:
				{
					vrsta = "N/A";
				}
				case 1:
				{
					vrsta = "Mala garaza";
				}
				case 2:
				{
					vrsta = "Srednja garaza";
				}
				case 3:
				{
					vrsta = "Velika garaza";
				}
			}

			if( !garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_orange"|| Garaza na prodaju - "col_white"ID: %d ||\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Cena garaze: "col_white"%d\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za kupovinu kucajte "col_white"/kupigarazu", id, vrsta, garageInfo[ id ][ garagePrice ], garageInfo[ id ][ garageLevel ] );
			}
			else if( garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_white"[ID %d]"col_orange"Vlasnik: "col_white"%s\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za ulaz koristite "col_white"/genter", id, garageInfo[ id ][ garageOwner ], vrsta, garageInfo[ id ][ garageLevel ] );
			}
			if( !garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_orange"[ GARAZA >> NA PRODAJU - "col_white"ID: %d ]\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Cena garaze: "col_white"%d\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za kupovinu kucajte "col_white"/kupigarazu", id, vrsta, garageInfo[ id ][ garagePrice ], garageInfo[ id ][ garageLevel ] );
			}
			else if( garageInfo[ id ][ garageOwned ] ) {
				format( string, sizeof( string ), ""col_orange"[ GARAZA >> U VLASNISTVU - "col_white"ID: %d ]\n"col_orange"Vlasnik: "col_white"%s\n"col_orange"Tip garaze: "col_white"%s\n"col_orange"Potreban level: "col_white"%d\n"col_orange"Za ulaz koristite "col_white"/genter", id, garageInfo[ id ][ garageOwner ], vrsta, garageInfo[ id ][ garageLevel ] );
			}
			garageInfo[ id ][ garage3D ] = CreateDynamic3DTextLabel( string, BELA, garageInfo[ id ][ garagePos ][ 0 ], garageInfo[ id ][ garagePos ][ 1 ], garageInfo[ id ][ garagePos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			garageInfo[ id ][ garagePickup ] = CreateDynamicPickup( 19130, 1, garageInfo[ id ][ garagePos ][ 0 ], garageInfo[ id ][ garagePos ][ 1 ], garageInfo[ id ][ garagePos ][ 2 ], 0, 0 );

		}
	}
}

//------------------------------------------------------------------------------

GZone_Reset( id ) {

	gZoneInfo[ id ][ gZoneTaken ] = false;
	gZoneInfo[ id ][ gZoneTakeable ] = false;
	gZoneInfo[ id ][ gZoneGangID ] = -1;
	gZoneInfo[ id ][ gZoneTime ] = 0;
	gZoneInfo[ id ][ gZoneMaxX ] = 0.0;
	gZoneInfo[ id ][ gZoneMinX ] = 0.0;
	gZoneInfo[ id ][ gZoneMaxY ] = 0.0;
	gZoneInfo[ id ][ gZoneMinY ] = 0.0;
	gZoneInfo[ id ][ gZonePickupPos ][ 0 ] = 0.0;
	gZoneInfo[ id ][ gZonePickupPos ][ 1 ] = 0.0;
	gZoneInfo[ id ][ gZonePickupPos ][ 2 ] = 0.0;
}


GetNearestGZone( playerid ) {

	new Float:Pos[ 4 ];
	GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
	for( new id = 1; id < MAX_GZONE; id++ ) {
		if( Pos[ 0 ] <= gZoneInfo[ id ][ gZoneMaxX ] && Pos[ 0 ] >= gZoneInfo[ id ][ gZoneMinX ] && Pos[ 1 ] <= gZoneInfo[ id ][ gZoneMaxY ] && Pos[ 1 ] >= gZoneInfo[ id ][ gZoneMinY ] ) {
			return id;
		}
	}
	return -1;
}


GZone_Refresh( id )
{

	new filename[ 32 ], string[ 256 ];

	if( id  != -1 )
	{

		format( filename, sizeof( filename ), F_GZONE, id );

		if( fexist( filename ) )
		{

			if( IsValidDynamic3DTextLabel( gZoneInfo[ id ][ gZone3D ] ) )
				DestroyDynamic3DTextLabel( gZoneInfo[ id ][ gZone3D ] );

			if( IsValidDynamicPickup( gZoneInfo[ id ][ gZonePickup ] ) )
				DestroyDynamicPickup( gZoneInfo[ id ][ gZonePickup ] );

			if( !gZoneInfo[ id ][ gZoneTaken ] )
			{
				gZoneInfo[ id ][ gZonePickup ] = CreateDynamicPickup( 1313, 1, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 0, 0 );
				gZoneInfo[ id ][ gZone3D ] = CreateDynamic3DTextLabel( ""col_white"[ TERITORIJA ]\nTeritorija je "col_balkanstory"slobodna"col_white"\nAko zelis da je zauzmes kucaj "col_balkanstory"/zauzmi", BELA, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			}
			else if( gZoneInfo[ id ][ gZoneTaken ] )
			{
				gZoneInfo[ id ][ gZonePickup ] = CreateDynamicPickup( 1313, 1, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 0, 0 );
				format( string, sizeof( string ), ""col_white"[ TERITORIJA ]\nTeritorija je u vlasnistvu bande "col_balkanstory"%s"col_white"\nAko zelis da je zauzmes kucaj "col_balkanstory"/zauzmi",  OI[ gZoneInfo[ id ][ gZoneGangID ] ][ oName ] );
				gZoneInfo[ id ][ gZone3D ] = CreateDynamic3DTextLabel( string, BELA, gZoneInfo[ id ][ gZonePickupPos ][ 0 ], gZoneInfo[ id ][ gZonePickupPos ][ 1 ], gZoneInfo[ id ][ gZonePickupPos ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
			}
		}
	}
}

stock GZone_Save( id ) {

	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), F_GZONE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteBool( File, "Taken", gZoneInfo[ id ][ gZoneTaken ] );
	INI_WriteBool( File, "Takeable", gZoneInfo[ id ][ gZoneTakeable ] );
	INI_WriteInt( File, "GangID", gZoneInfo[ id ][ gZoneGangID ] );
	INI_WriteInt( File, "Time", gZoneInfo[ id ][ gZoneTime ] );
	INI_WriteFloat( File, "MaxX", gZoneInfo[ id ][ gZoneMaxX ] );
	INI_WriteFloat( File, "MinX", gZoneInfo[ id ][ gZoneMinX ] );
	INI_WriteFloat( File, "MaxY", gZoneInfo[ id ][ gZoneMaxY ] );
	INI_WriteFloat( File, "MinY", gZoneInfo[ id ][ gZoneMinY ] );
	INI_WriteString( File, "Color", gZoneInfo[ id ][ gZoneColor ] );
	INI_WriteFloat( File, "PickupPos", gZoneInfo[ id ][ gZonePickupPos ][ 0 ] );
	INI_WriteFloat( File, "PickupPos2", gZoneInfo[ id ][ gZonePickupPos ][ 1 ] );
	INI_WriteFloat( File, "PickupPos3", gZoneInfo[ id ][ gZonePickupPos ][ 2 ] );
	INI_Close( File );
	
	return (true);
}

//------------------------------------------------------------------------------
ResetField( id ) {
	fieldInfo[ id ][ fieldOwned ] = false;
	strmid( fieldInfo[ id ][ fieldOwner ], "Drzava", 0, strlen( "Drzava" ), MAX_PLAYER_NAME );
	fieldInfo[ id ][ fieldPrice ] = 0;
	fieldInfo[ id ][ fieldStalkNumber ] = 0;
	fieldInfo[ id ][ fieldLevel ] = 0;
	fieldInfo[ id ][ fieldMaxX ] = 0.0;
	fieldInfo[ id ][ fieldMinX ] = 0.0;
	fieldInfo[ id ][ fieldMaxY ] = 0.0;
	fieldInfo[ id ][ fieldMinY ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 0 ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 1 ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 2 ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 3 ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 4 ] = 0.0;
	fieldInfo[ id ][ fieldObjectPos ][ 5 ] = 0.0;
	fieldInfo[ id ][ fieldTractorID ] = -1; 
	fieldInfo[ id ][ fieldAdditionID ] = -1; 
	fieldInfo[ id ][ fieldTruckID ] = -1;
}

stock NextStalkID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_STALK, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}

GetNearestStalk( playerid ) {

	for( new i = 1; i < MAX_STALKS; i++) {
		if( stalkInfo[ i ][ sPlanted ] == true ) {
			if( IsPlayerInRangeOfPoint( playerid, 3.0, stalkInfo[ i ][ sPos ][ 0 ], stalkInfo[ i ][ sPos ][ 1 ], stalkInfo[ i ][ sPos ][ 2 ] ) ) { return i; }
		}
	}
	return -1;
}

GetNearestField( playerid ) {
	new Float:Pos[ 4 ];
	GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
	for( new id = 1; id < MAX_FIELDS; id++) {
		if( Pos[ 0 ] <= fieldInfo[ id ][ fieldMaxX ] && Pos[ 0 ] >= fieldInfo[ id ][ fieldMinX ] && Pos[ 1 ] <= fieldInfo[ id ][ fieldMaxY ] && Pos[ 1 ] >= fieldInfo[ id ][ fieldMinY ] ) {
			return id;
		}
	}
	return -1;
}

stock IsCordsInOtherField( Float:x, Float:y ) {
	for( new id = 1; id < MAX_FIELDS; id++) {
		if( x <= fieldInfo[ id ][ fieldMaxX ] && x >= fieldInfo[ id ][ fieldMinX ] && y <= fieldInfo[ id ][ fieldMaxY ] && y >= fieldInfo[ id ][ fieldMinY ] ) {
			return id;
		}
	}
	return -1;
}

stock IsCordsInOtherGZone( Float:x, Float:y ) {
	for( new id = 1; id < MAX_GZONE; id++) {
		if( x <= gZoneInfo[ id ][ gZoneMaxX ] && x >= gZoneInfo[ id ][ gZoneMinX ] && y <= gZoneInfo[ id ][ gZoneMaxY ] && y >= gZoneInfo[ id ][ gZoneMinY ] ) {
			return id;
		}
	}
	return -1;
}

stock Stalk_Refresh( id ) {
	stalkInfo[ id ][ sfieldID ] = -1;
	stalkInfo[ id ][ sObjectID ] = 0;
	stalkInfo[ id ][ sPlanted ] = false;
	stalkInfo[ id ][ sGrow ] = false;
	stalkInfo[ id ][ sType ] = 0;
	stalkInfo[ id ][ sMinut ] = 0;
	stalkInfo[ id ][ sHour ] = 0;
	stalkInfo[ id ][ sPos ][ 0 ] = 0.0;
	stalkInfo[ id ][ sPos ][ 1 ] = 0.0;
	stalkInfo[ id ][ sPos ][ 2 ] = 0.0;
}

stock Stalk_Delete( id ) {
	new filename[ 32 ];
	
	if( id  != -1 ) {
	
		format( filename, sizeof( filename ), F_STALK, id );

		if( fexist( filename ) ) {
		
			if( IsValidDynamic3DTextLabel( stalkInfo[ id ][ s3D ] ) )
				DestroyDynamic3DTextLabel( stalkInfo[ id ][ s3D ] );

			if( IsValidDynamicObject( stalkInfo[ id ][ sObject ] ) )
				DestroyDynamicObject( stalkInfo[ id ][ sObject ] );

			Stalk_Refresh( id );
				
			fremove( filename );
		}
	}
}

Field_Refresh( id ) {
	new filename[ 32 ],
			string[ 300 ];

	if( id  != -1 ) {

		format( filename, sizeof( filename ), F_FIELD, id );

		if( fexist( filename ) ) {

			if( IsValidDynamic3DTextLabel( fieldInfo[ id ][ field3D ] ) )
				DestroyDynamic3DTextLabel( fieldInfo[ id ][ field3D ] );

			if( IsValidDynamicPickup( fieldInfo[ id ][ fieldPickup ] ) )
				DestroyDynamicPickup( fieldInfo[ id ][ fieldPickup ] );

			if( IsValidDynamicObject( fieldInfo[ id ][ fieldObject ] ) )
				DestroyDynamicObject( fieldInfo[ id ][ fieldObject ] );


			if( !fieldInfo[ id ][ fieldOwned ] ) {
				format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nImanje na prodaju!\nLevel:{FFFFFF} %d\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena:{FFFFFF}%d$\n/kupiimanje", fieldInfo[ id ][ fieldLevel ],id,fieldInfo[ id ][ fieldPrice ] );
				fieldInfo[ id ][ fieldObject ] = CreateDynamicObject( 19470, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ], fieldInfo[ id ][ fieldObjectPos ][ 3 ], fieldInfo[ id ][ fieldObjectPos ][ 4 ], fieldInfo[ id ][ fieldObjectPos ][ 5 ], -1, -1, -1, 200.0 );
			}
			else if( fieldInfo[ id ][ fieldOwned ] ) {
				format( string, sizeof( string ), "{009EEA}[ IMANJE ]\nVlasnik:{FFFFFF} %s\n{009EEA}Broj: {FFFFFF}%d\n{009EEA}Cijena: {FFFFFF}%d$\n{009EEA}Adresa: {FFFFFF}%s",fieldInfo[ id ][ fieldOwner ],id,fieldInfo[ id ][ fieldPrice ],UlicaImanja( id ) );
				fieldInfo[ id ][ fieldPickup ] = CreateDynamicPickup( 1239, 1, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 0, 0 );
			}
			fieldInfo[ id ][ field3D ] = CreateDynamic3DTextLabel( string, BELA, fieldInfo[ id ][ fieldObjectPos ][ 0 ], fieldInfo[ id ][ fieldObjectPos ][ 1 ], fieldInfo[ id ][ fieldObjectPos ][ 2 ]+1, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );

		}
	}
}

stock IsCordsInField( id, Float:x, Float:y ) {

	if( x <= fieldInfo[ id ][ fieldMaxX ] && x >= fieldInfo[ id ][ fieldMinX ] && y <= fieldInfo[ id ][ fieldMaxY ] && y >= fieldInfo[ id ][ fieldMinY ] ) {
		return id;
	}
	return -1;
}

stock IsCordsInGZone( id, Float:x, Float:y ) {

	if( x <= gZoneInfo[ id ][ gZoneMaxX ] && x >= gZoneInfo[ id ][ gZoneMinX ] && y <= gZoneInfo[ id ][ gZoneMaxY ] && y >= gZoneInfo[ id ][ gZoneMinY ] ) {
		return id;
	}
	return -1;
}



//------------------------------------------------------------------------------
forward Dimi_CreateVehicle( scriptid, tip, orga, posao, firma, modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay );
public Dimi_CreateVehicle( scriptid, tip, orga, posao, firma, modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay ) {

	if( orga == 0 ) orga = -1;
	if( posao == 0 ) posao = -1;
	if( firma == 0 ) firma = -1;

	if( ServerInfo[ BrojKreiranihVozila ] <= MaxBrojKreiranih ) {
		ServerInfo[ BrojKreiranihVozila ]++;
		new idKreiranog;
		if( modelid == 538 ) {
			idKreiranog = AddStaticVehicleEx( modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay );
		}
		else {
			idKreiranog = CreateVehicle( modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay );
		}

		ScriptIDVozila[ idKreiranog ] = scriptid;
		TipVozila[ idKreiranog ] = tip;
		OrgaVozila[ idKreiranog ] = orga;
		PosaoVozila[ idKreiranog ] = posao;
		PumpaImanjeVozilo[ idKreiranog ] = firma;
		RealVehiclePositions[ idKreiranog ][ 0 ] = x;
		RealVehiclePositions[ idKreiranog ][ 1 ] = y;
		RealVehiclePositions[ idKreiranog ][ 2 ] = z;
		
		BusyVehicle[ idKreiranog ] = -1;
		garbagemanVehicles[ idKreiranog ][ gPlayerID ] = -1;
		return idKreiranog;
	} else return -1;
}
forward Dimi_DestroyVehicle( vehicleid );
public Dimi_DestroyVehicle( vehicleid ) {

	if( vehicleid != -1 ) {
	
		if( ScriptIDVozila[ vehicleid ] != -1 ) {
	
			if( VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ Validv3DText ] ) {

				VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ Validv3DText ] = false;
				Delete3DTextLabel( VehicleInfo[ ScriptIDVozila[ vehicleid ] ][ v3DText ] );

			}
		}

	
		if( Neon[ vehicleid ] == 1 ) {
			Neon[ vehicleid ] = 0;
			DestroyDynamicObject( NeonObject1[ vehicleid ] );
			DestroyDynamicObject( NeonObject2[ vehicleid ] );
			DestroyDynamicObject( Kakica[ vehicleid ] );
		}
		RealVehiclePositions[ vehicleid ][ 0 ] = 0.0;
		RealVehiclePositions[ vehicleid ][ 1 ] = 0.0;
		RealVehiclePositions[ vehicleid ][ 2 ] = 0.0;
		ScriptIDVozila[ vehicleid ] = -1;
		TipVozila[ vehicleid ] = -1;
		PumpaImanjeVozilo[ vehicleid ] = -1;
		OrgaVozila[ vehicleid ] = -1;
		PosaoVozila[ vehicleid ] = -1;
	}
	
	if( DestroyVehicle( vehicleid ) ) {
		ServerInfo[ BrojKreiranihVozila ]--;
		return 1;
	}
	else return -1;
}


//------------------------------------------------------------------------------
forward DEntisT_and_Brace(); public DEntisT_and_Brace() { return 1; }
//------------------------------------------------------------------------------
forward DEntisT_and_Brace2(qi); public DEntisT_and_Brace2(qi) {
	new q = 1;
	return qi + q;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Dimi_SetVehicleHealth( vehicleid, Float:vHealth ) {

	if( antiCheatVS[ vehicleid ][ VehCheck ] == 1 ) antiCheatVS[ vehicleid ][ VehCheck ] = 2;
	antiCheatVS[ vehicleid ][ VehTrueHealth ] = vHealth;
	SetVehicleHealth( vehicleid, vHealth );
	if( antiCheatVS[ vehicleid ][ VehCheck ] == 2 ) antiCheatVS[ vehicleid ][ VehCheck ] = 1;

	return 1;
}

Dimi_RepairVehicle( playerid, vehicleid ) {
	if( antiCheatVS[ vehicleid ][ VehCheck ] == 1 ) antiCheatVS[ vehicleid ][ VehCheck ] = 2;
	if( playerid != -1 ) {

		antiCheatCS[ playerid ][ CPSCount ] = 0;
		antiCheatCS[ playerid ][ CPSTick ] = 0;
		antiCheatCS[ playerid ][ VehRepairTime ] = 3;
	}
	RepairVehicle( vehicleid );
	GetVehicleHealth( vehicleid, antiCheatVS[ vehicleid ][ VehTrueHealth ] );
	if( antiCheatVS[ vehicleid ][ VehCheck ] == 2 ) antiCheatVS[ vehicleid ][ VehCheck ] = 1;
	return true;
}
//------------------------------------------------------------------------------
stock CreateBanFile( playerid, reason[ ], admin[ ] ) {

	new banfile[ 80 ];
	format( banfile, sizeof( banfile ), FILE_BAN, ImeIgraca( playerid ) );
	new File:ban = fopen( banfile, io_write );
	new var[ 64 ];
	format( var, 64, "Admin=%s\n", admin );
	fwrite( ban, var );
	new var1[ 128 ];
	format( var1, 128,"Razlog=%s\n", reason );
	fwrite( ban, var1 );
	fclose( ban );

}
//------------------------------------------------------------------------------
IsPlayerInCell( playerid )
{
	for( new i = 0; i < sizeof( RandomZatvor ); i++ )
	{
		if( IsPlayerInRangeOfPoint( playerid, 5.0, RandomZatvor[ i ][ 0 ], RandomZatvor[ i ][ 1 ], RandomZatvor[ i ][ 2 ] ) ) return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
IsPlayerAtVehicleRepairPoint( playerid ) {
	if( GetPlayerCameraMode( playerid ) == 15 ) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 2067.00, -1831.65, 13.55)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 1024.97, -1023.88, 32.10)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 1041.19, -1022.50, 32.11)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 720.25, -457.17, 16.34)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 2386.66, 1045.68, 10.82)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, 1972.50, 2163.03, 11.07)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, -1420.58, 2586.17, 55.84)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, -1904.90, 283.96, 41.05)) return 1;
	if( IsPlayerInRangeOfPoint( playerid, 25.0, -2719.46, 217.77, 4.48)) return 1;
	return 0;
}
//------------------------------------------------------------------------------
stock KillPlayer( player_id ) {
	new empty_health_bar = 0;
	
	new killer_player_id = player_id;
	
	SetPlayerHealth( killer_player_id, empty_health_bar);
	new return_true_value = 1;
	
	return return_true_value;
}
//------------------------------------------------------------------------------
getCheatPower( bool:antic ) {
	new acn[4] = "ON";

	if( antic == true ) acn = "ON";
	else if( antic == false ) acn = "OFF";

	return acn;
}
getCheatWork( antic ) {
	new acn[10] = "Warning";

	if( antic == AC_ADMINPORUKA ) acn = "Warning";
	else if( antic == AC_KICK ) acn = "Kick";
	else if( antic == AC_BAN ) acn = "Ban";

	return acn;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
getVehicleName( vehicle ) {
	new vehName[ 20 ] = "A Hotring Racer";

	if( vehicle == -1 || vehicle == 0 ){
		format( vehName, sizeof( vehName ), "%s", "Nema Vozila" );
	}
	else if( vehicle != -1 ) {
		new vFile[ 50 ];
		format( vFile, sizeof( vFile ), V_FILE, vehicle );
		if( fexist( vFile ) ) {
		
			if( VehicleInfo[ vehicle ][ vModel ] >= 400 && VehicleInfo[ vehicle ][ vModel ] <= 611 ) {
		
				format( vehName, sizeof( vehName ), "%s", GetVehicleNameEx( VehicleInfo[ vehicle ][ vModel ] ) );
			}
			else format( vehName, sizeof( vehName ), "%s", "Nema Vozila" );
		}
		else if( !fexist( vFile ) ) {
			format( vehName, sizeof( vehName ), "%s", "Nema Vozila" );
		}
	}

	return vehName;
}
//------------------------------------------------------------------------------
stock GetMoveDirectionFromKeys( ud, lr ) {
	new direction = 0;

	if(lr < 0)
	{
		if(ud < 0) 		direction = MOVE_FORWARD_LEFT;
		else if(ud > 0) direction = MOVE_BACK_LEFT;
		else            direction = MOVE_LEFT;
	}
	else if(lr > 0)
	{
		if(ud < 0)      direction = MOVE_FORWARD_RIGHT;
		else if(ud > 0) direction = MOVE_BACK_RIGHT;
		else			direction = MOVE_RIGHT;
	}
	else if(ud < 0) 	direction = MOVE_FORWARD;
	else if(ud > 0) 	direction = MOVE_BACK;

	return direction;
}

stock MoveCamera( playerid ) {
	new Float:FV[ 3 ], Float:CP[ 3 ];
	GetPlayerCameraPos( playerid, CP[ 0 ], CP[ 1 ], CP[ 2 ] );
	GetPlayerCameraFrontVector( playerid, FV[ 0 ], FV[ 1 ], FV[ 2 ] );
	if( flymodecamera[ playerid ][ accelmul ] <= 1 ) flymodecamera[ playerid ][ accelmul ] += ACCEL_RATE;
	new Float:speed = MOVE_SPEED * flymodecamera[ playerid ][ accelmul ];
	new Float:Xa, Float:Ya, Float:Za;
	GetNextCameraPosition( flymodecamera[ playerid ][ mode ], CP, FV, Xa, Ya, Za );
	MovePlayerObject( playerid, flymodecamera[ playerid ][ flyobject ], Xa, Ya, Za, speed );
	flymodecamera[ playerid ][ lastmove ] = GetTickCount( );
	return 1;
}

stock GetNextCameraPosition(move_mode, Float:CP[ 3 ], Float:FV[ 3 ], &Float:Xa, &Float:Ya, &Float:Za) {
	#define OFFSET_X (FV[ 0 ]*6000.0)
	#define OFFSET_Y (FV[ 1 ]*6000.0)
	#define OFFSET_Z (FV[ 2 ]*6000.0)
	switch(move_mode)
	{
		case MOVE_FORWARD:
		{
			Xa = CP[ 0 ]+OFFSET_X;
			Ya = CP[ 1 ]+OFFSET_Y;
			Za = CP[ 2 ]+OFFSET_Z;
		}
		case MOVE_BACK:
		{
			Xa = CP[ 0 ]-OFFSET_X;
			Ya = CP[ 1 ]-OFFSET_Y;
			Za = CP[ 2 ]-OFFSET_Z;
		}
		case MOVE_LEFT:
		{
			Xa = CP[ 0 ]-OFFSET_Y;
			Ya = CP[ 1 ]+OFFSET_X;
			Za = CP[ 2 ];
		}
		case MOVE_RIGHT:
		{
			Xa = CP[ 0 ]+OFFSET_Y;
			Ya = CP[ 1 ]-OFFSET_X;
			Za = CP[ 2 ];
		}
		case MOVE_BACK_LEFT:
		{
			Xa = CP[ 0 ]+(-OFFSET_X - OFFSET_Y);
			Ya = CP[ 1 ]+(-OFFSET_Y + OFFSET_X);
			Za = CP[ 2 ]-OFFSET_Z;
		}
		case MOVE_BACK_RIGHT:
		{
			Xa = CP[ 0 ]+(-OFFSET_X + OFFSET_Y);
			Ya = CP[ 1 ]+(-OFFSET_Y - OFFSET_X);
			Za = CP[ 2 ]-OFFSET_Z;
		}
		case MOVE_FORWARD_LEFT:
		{
			Xa = CP[ 0 ]+(OFFSET_X  - OFFSET_Y);
			Ya = CP[ 1 ]+(OFFSET_Y  + OFFSET_X);
			Za = CP[ 2 ]+OFFSET_Z;
		}
		case MOVE_FORWARD_RIGHT:
		{
			Xa = CP[ 0 ]+(OFFSET_X  + OFFSET_Y);
			Ya = CP[ 1 ]+(OFFSET_Y  - OFFSET_X);
			Za = CP[ 2 ]+OFFSET_Z;
		}
	}
}
stock CancelFlyMode( playerid ) {
	FlyMode[ playerid ] = false;
	CancelEdit( playerid );
	TogglePlayerSpectating( playerid, 0);
	DestroyPlayerObject( playerid, flymodecamera[ playerid ][ flyobject ] );
	flymodecamera[ playerid ][ cameramode ] = false;
	return 1;
}

forward FlyMode1( playerid );
public FlyMode1( playerid ) {
	FlyModeAh( playerid );
}

stock FlyModeAh( playerid ) {
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos( playerid, X, Y, Z );
	TogglePlayerSpectating( playerid, 0 );

	flymodecamera[ playerid ][ flyobject ] = CreatePlayerObject( playerid, 19300, X, Y, Z, 0.0, 0.0, 0.0 );
	AttachCameraToPlayerObject( playerid, flymodecamera[ playerid ][ flyobject ] );
	FlyMode[ playerid ] = true;
	flymodecamera[ playerid ][ cameramode ] = true;
	return 1;
}
//------------------------------------------------------------------------------
forward RemoveBadge( playerid );
public RemoveBadge( playerid ) {
	RemovePlayerAttachedObject( playerid, OBJECT_SLOT_BADGE );
}
//------------------------------------------------------------------------------
forward PilotUtovar( playerid );
public PilotUtovar( playerid ) {
	Dimi_KillTimer( PilotTimer[ playerid ] );
	TogglePlayerControllable( playerid, true );
	announcement( playerid, "~w~Nova lokacija postavljena", 3000, 5 );
	return 1;
}
//------------------------------------------------------------------------------
stock PreloadAnimations(playerid)
{
	for (new i = 0; i < sizeof(g_aPreloadLibs); i ++) {
		ApplyAnimation(playerid, g_aPreloadLibs[ i ], "null", 4.0, 0, 0, 0, 0, 0, 1);
	}
	return 1;
}
//------------------------------------------------------------------------------
stock PreloadWeaponIcons(playerid)
{
	for(new i; i < 47; i++)
	{
		GivePlayerWeapon(playerid, i, 1);
	}
	ResetPlayerWeapons(playerid);
	return 1;
}
//------------------------------------------------------------------------------
stock Dimi_SetPlayerCheckpoint( playerid, Float:x, Float:y, Float:z, Float:size ) {
	if( PlayerCPShow[ playerid ] == true ) {
		DisablePlayerCheckpoint( playerid );
		PlayerCPShow[ playerid ] = false;
	}
	PlayerCPShow[ playerid ] = true;
	return SetPlayerCheckpoint( playerid, Float:x, Float:y, Float:z, Float:size );
}

stock Dimi_DisablePlayerCheckpoint( playerid ) {
	if( PlayerCPShow[ playerid ] == true ) {

		DisablePlayerCheckpoint( playerid );
		PlayerCPShow[ playerid ] = false;
	}
}
//------------------------------------------------------------------------------

SetSexSkin( playerid ) {

	new sexskin;

	if( PlayerInfo[ playerid ][ xPol ] == 1 ) { sexskin = 84; }
	else if( PlayerInfo[ playerid ][ xPol ] == 2 ) { sexskin = 11; }
	else { sexskin = 84; }

	return sexskin;
}

//------------------------------------------------------------------------------
SetRandomSpawn( playerid ) {

	new randomspawn;

	if( playerid % 2 == 0 ) { randomspawn = SPAWN_NERP; }
	else { randomspawn = SPAWN_OBICAN_LS_2; }
	
	return randomspawn;
}
//------------------------------------------------------------------------------
stock right(source[], len) {
	new retval[255], srclen;
	srclen = strlen(source);
	strmid(retval, source, srclen - len, srclen, 255);
	return retval;
}
//------------------------------------------------------------------------------
stock WARPoruka( w, color, string[] ) {
	for(new i; i < MAX_PLAYERS; i++) {
		if( WARPInfo[ i ][ WARIgrac ] == w ) {
			SendClientMessagee( i, color, string ); } }
}
//------------------------------------------------------------------------------
stock DMZPoruka( color, string[] ) {
	for(new i; i < MAX_PLAYERS; i++) {
		if( NaDmEventu[ i ] == true ) {
			SendClientMessagee( i, color, string ); } }
}
//------------------------------------------------------------------------------
stock UpravljanjeCelijama( bool:show ) {

	if( show == true )
	{
		MoveDynamicObject(celija[ 0 ],223.5161, 1649.4709, -99.0021, 2.00);
		MoveDynamicObject(celija[ 1 ],230.0161, 1656.7454, -99.0021, 2.00);
		MoveDynamicObject(celija[ 2 ],236.4061, 1656.7454, -99.0021, 2.00);
		MoveDynamicObject(celija[ 3 ],236.4123, 1649.4709, -99.0021, 2.00);
		MoveDynamicObject(celija[4],230.0185, 1649.4709, -99.0021, 2.00);
		MoveDynamicObject(celija[5],236.5891, 1656.7463, -95.4868, 2.00);
		MoveDynamicObject(celija[6],239.5864, 1649.4294, -95.4868, 2.00);
		MoveDynamicObject(celija[7],233.1947, 1649.4294, -95.4868, 2.00);
		MoveDynamicObject(celija[8],226.7899, 1649.4294, -95.4868, 2.00);
		MoveDynamicObject(celija[9],223.7910, 1656.7463, -95.4868, 2.00);
		MoveDynamicObject(celija[10],230.1590, 1656.7463, -95.4868, 2.00);
		MoveDynamicObject(celija[11],223.5971, 1656.7454, -99.0021, 2.00);
		OtvoreneCelije = true;
	}
	else if( show == false )
	{
		MoveDynamicObject(celija[ 0 ], 222.21609, 1649.47095, -99.00210, 2.00);
		MoveDynamicObject(celija[ 1 ], 228.61610, 1656.74536, -99.00210, 2.00);
		MoveDynamicObject(celija[ 2 ], 234.99609, 1656.74536, -99.00210, 2.00);
		MoveDynamicObject(celija[ 3 ], 235.01230, 1649.47095, -99.00210, 2.00);
		MoveDynamicObject(celija[4], 228.61850, 1649.47095, -99.00210, 2.00);
		MoveDynamicObject(celija[5], 235.18910, 1656.74634, -95.48680, 2.00);
		MoveDynamicObject(celija[6], 238.18640, 1649.42944, -95.48680, 2.00);
		MoveDynamicObject(celija[7], 231.79469, 1649.42944, -95.48680, 2.00);
		MoveDynamicObject(celija[8], 225.38989, 1649.42944, -95.48680, 2.00);
		MoveDynamicObject(celija[9], 222.35910, 1656.74634, -95.48680, 2.00);
		MoveDynamicObject(celija[10], 228.75900, 1656.74634, -95.48680, 2.00);
		MoveDynamicObject(celija[11], 222.19710, 1656.74536, -99.00210, 2.00);
		OtvoreneCelije = false;
	}
}
//==============================================================================
ResetTuningInfo( playerid )
{
	TPInfo[ playerid ][ tID ] = -1;
	TPInfo[ playerid ][ tType ] = -1;
	TPInfo[ playerid ][ tPaintjob ] = false;
	TPInfo[ playerid ][ PJColor ] = -1;
	TPInfo[ playerid ][ PJColor ] = -1;
}


stock SendPlayerNotification(playerid, bool:show, const text[])
{
	if(show)
	{
		RemoveNotif(playerid);
		PlayerTextDrawHide( playerid, WantedIgraca[ playerid ] );
		new nerp_playermsgtext[500];

		new 
			len = strlen(text);
		if(len > notification_line_break)
		{
			new fstring[50],sstring[50];
			// 29 30 31 32 33 34 35 36 37
			// t  i  t  o  x  x  x  x  x
			strmid(fstring,text,0,notification_line_break);
			strmid(sstring,text,notification_line_break,len);
			format(nerp_playermsgtext,sizeof nerp_playermsgtext,"%s-~n~%s",fstring,sstring);
		}
		if(len < notification_line_break)
		{
			format(nerp_playermsgtext,sizeof nerp_playermsgtext,text);
		}

		PlayerTextDrawSetString(playerid,Notification[4][playerid],nerp_playermsgtext);

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, Notification[i][playerid]);
		}

		KillTimer(NotifTimer[playerid]);

		NotifTimer[playerid] = SetTimerEx("RemoveNotif", 5000, false, "i", playerid);
	}
	if(!show)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, Notification[i][playerid]);
		}
	}
	return 1;
}

forward RemoveNotif(playerid);
public RemoveNotif(playerid)
{
	PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
	SendPlayerNotification(playerid, false,"");
	return 1;
}
//------------------------------------------------------------------------------
new ScreenMsgTimer[MAX_PLAYERS];
stock SendScreenMessage(playerid, const text[])
{
	new message[512];
	format(message,sizeof message,text);
	ScreenMsgTDControl(playerid, false);
	KillTimer(ScreenMsgTimer[playerid]);

	PlayerTextDrawSetString(playerid,ScreenMsgTextdraw[5][playerid],message);
	ScreenMsgTDControl(playerid, true);
	ScreenMsgTimer[playerid] = SetTimerEx("OnPlayerReadScreenMessage", 5000, false, "i", playerid);
	return 1;
}

forward OnPlayerReadScreenMessage(playerid);
public OnPlayerReadScreenMessage(playerid)
{
	ScreenMsgTDControl(playerid, false);
	return 1;
}
//------------------------------------------------------------------------------
stock SendMessageBox(playerid, const title[], const text[])
{
	new message[512];

	MessageBoxControl(playerid, false);

	format(message,sizeof message,text);
	PlayerTextDrawSetString(playerid,MessageBox[5][playerid],message);

	format(message,sizeof message,title);
	PlayerTextDrawSetString(playerid,MessageBox[2][playerid],message);

	MessageBoxControl(playerid, true);
	return 1;
}
//------------------------------------------------------------------------------
stock StatsTDControl(playerid, bool:show)
{
	if(show)
	{
		for(new i; i < 32; i++)
		{
			PlayerTextDrawShow(playerid, PlayerStats[i][playerid]);
		}
		PlayerTextDrawShow(playerid, SkinIgraca[playerid]);
		PlayerTextDrawShow(playerid, NickIgraca[playerid]);
	}
	else if (!show)
	{
		for(new i; i < 32; i++)
		{
			PlayerTextDrawHide(playerid, PlayerStats[i][playerid]);
		}
		PlayerTextDrawHide(playerid, SkinIgraca[playerid]);
		PlayerTextDrawHide(playerid, NickIgraca[playerid]);
	}
	return 1;
}

//------------------------------------------------------------------------------
stock BRACETMLogoView(playerid, bool:show)
{
	if(show == true)
	{
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, BraceTeam[i]);
		}
	}
	else if(show == false)
	{
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, BraceTeam[i]);
		}
	}
	return 1;	
}
//UcitavanjeTextdraw
//------------------------------------------------------------------------------
stock ShowLoadingTextdraws(playerid, bool:show, interval = 5000)
{
	if(show == true)
	{
		KillTimer(LoadingTimer[playerid]);
		LoadingTextdrawShowed[playerid] = true;
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, UcitavanjeTextdraw[i]);
		}
		LoadingTimer[playerid] = SetTimerEx("HideLoadingTDS", interval, false, "i", playerid);
	}
	else if(show == false)
	{
		KillTimer(LoadingTimer[playerid]);
		LoadingTextdrawShowed[playerid] = false;
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, UcitavanjeTextdraw[i]);
		}
	}
	return 1;	
}

HideLoadingTDS(playerid); public HideLoadingTDS(playerid)
{
	LoadingTextdrawShowed[playerid] = false;
	for(new i; i < 10; i++)
	{
		TextDrawHideForPlayer(playerid, UcitavanjeTextdraw[i]);
	}
	return 1;
}
//------------------------------------------------------------------------------
stock OdjecaTDControl(playerid, bool:show)
{
	if(show)
	{
		for(new i; i < 20; i++)
		{
			PlayerTextDrawHide(playerid, OdjecaTextdraw[i][playerid]);
		}
		OdjecaTDShowed[playerid] = true;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawShow(playerid, OdjecaTextdraw[i][playerid]);
		}
	}
	else if (!show)
	{
		OdjecaTDShowed[playerid] = false;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawHide(playerid, OdjecaTextdraw[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock ShowPlayerNearbyItem(playerid, bool:show, 
	const weapon_txd[] = "hud:fist", 
	const weapon_name[] = "Fist",
	const weapon_ammo[] = "Unknown",
	item_count = 0,
	preview_modelid = -1) 
{
	#pragma unused preview_modelid
	if(show)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, ItemNearby[i][playerid]);
		}

		new item_amount[10], weapon_data_str[256];
		format(item_amount, sizeof item_amount, "%i", item_count);
		format(weapon_data_str, sizeof weapon_data_str, "%s", weapon_txd);
		PlayerTextDrawSetString(playerid, ItemNearby[1][playerid], weapon_data_str);
		format(weapon_data_str, sizeof weapon_data_str, "%s", weapon_name);
		PlayerTextDrawSetString(playerid, ItemNearby[2][playerid], weapon_data_str);
		format(weapon_data_str, sizeof weapon_data_str, "%s", weapon_ammo);
		PlayerTextDrawSetString(playerid, ItemNearby[3][playerid], weapon_data_str);
		PlayerTextDrawSetString(playerid, ItemNearby[4][playerid], item_amount);

		ItemNearbyShowed[playerid] = true;

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, ItemNearby[i][playerid]);
		}
	}
	else if (!show)
	{
		ItemNearbyShowed[playerid] = false;

		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, ItemNearby[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock LogRegSelectControl(playerid, bool:show)
{
	if(show)
	{
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, LogRegSelection[i]);
		}
		LogRegShowed[playerid] = 1;
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, LogRegSelection[i]);
		}
	}
	else if (!show)
	{
		LogRegShowed[playerid] = 0;
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, LogRegSelection[i]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock UnknownCmdControl(playerid, bool:show)
{
	if(show)
	{
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, UnknownCommand[i]);
		}
	}
	else if (!show)
	{
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, UnknownCommand[i]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock ClientSelectControl(playerid, bool:show)
{
	if(show)
	{
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, ClientSelection[i]);
		}
		LogRegShowed[playerid] = 1;
		for(new i; i < 10; i++)
		{
			TextDrawShowForPlayer(playerid, ClientSelection[i]);
		}
	}
	else if (!show)
	{
		LogRegShowed[playerid] = 0;
		for(new i; i < 10; i++)
		{
			TextDrawHideForPlayer(playerid, ClientSelection[i]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock MessageBoxControl(playerid, bool:show)
{
	if(show)
	{
		MessageBoxShowed[playerid] = true;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, MessageBox[i][playerid]);
		}
	}
	else if (!show)
	{
		MessageBoxShowed[playerid] = false;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, MessageBox[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock SpecTDControl(playerid, bool:show)
{
	if(show)
	{
		SpecTDShowed[playerid] = true;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawShow(playerid, SpecTextdraw[i][playerid]);
		}
	}
	else if (!show)
	{
		SpecTDShowed[playerid] = false;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawHide(playerid, SpecTextdraw[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock ScreenMsgTDControl(playerid, bool:show)
{
	if(show)
	{
		ScreenMsgTDShowed[playerid] = true;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, ScreenMsgTextdraw[i][playerid]);
		}
	}
	else if (!show)
	{
		ScreenMsgTDShowed[playerid] = false;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, ScreenMsgTextdraw[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock WifiConnectionTDControl(playerid, bool:show)
{
	if(show)
	{
		WifiConnectionTDShowed[playerid] = true;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, WifiConnection[i][playerid]);
		}
	}
	else if (!show)
	{
		WifiConnectionTDShowed[playerid] = false;
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, WifiConnection[i][playerid]);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock PUBGTDControl(playerid, bool:show)
{
	if(show)
	{
		PUBGTDShowed[playerid] = true;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawShow(playerid, PUBGTextdraw[i][playerid]);
		}
	}
	else if (!show)
	{
		PUBGTDShowed[playerid] = false;
		for(new i; i < 20; i++)
		{
			PlayerTextDrawHide(playerid, PUBGTextdraw[i][playerid]);
		}
	}
	return 1;
}

//------------------------------------------------------------------------------
stock Police_TVTDControl( playerid, bool:show )
{
	if( show == true )
	{
	   
		Police_TV[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid, 186.887680, 139.882217, "usebox");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 0 ], 0.000000, 20.273944);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 0 ], 24.222606, 0.000000);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 0 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 0 ], 0);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 0 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 0 ], 102);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 0 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 0 ], 0);

		Police_TV[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid, 25.777751, 137.884506, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 1 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 1 ], 158.666702, 7.466670);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 1 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 1 ], 260571135);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 1 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 1 ], 4);

		Police_TV[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid, 25.888877, 320.573364, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 2 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 2 ], 159.111297, 3.982226);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 2 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 2 ], 260571135);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 2 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 2 ], 4);

		Police_TV[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid, 57.333328, 165.760055, "Trazi po imenu");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 3 ], 0.278444, 1.236621);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 3 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 3 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 3 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 3 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 3 ], 3);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 3 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 3 ], true);

		Police_TV[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid, 24.444444, 147.840011, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 4 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 4 ], 33.333339, 40.319976);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 4 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 4 ], -1);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 4 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 4 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 4 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 4 ], 5);
		
		PlayerTextDrawSetPreviewModel(playerid, Police_TV[ playerid ][ 4 ], 28);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 4 ], 0);
		PlayerTextDrawSetPreviewRot(playerid, Police_TV[ playerid ][ 4 ],0.000000, 0.000000, 0.000000, 1.000000);

		Police_TV[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid, 24.888885, 187.164505, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 5 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 5 ], 32.000007, 44.302215);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 5 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 5 ], -1);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 5 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 5 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 5 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 5 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 5 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, Police_TV[ playerid ][ 5 ], 560);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 5 ], 0);
		PlayerTextDrawSetPreviewRot(playerid, Police_TV[ playerid ][ 5 ],0.000000, 0.000000, 0.000000, 1.000000);

		Police_TV[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid, 59.222202, 200.608901, "Trazi po tablicama");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 6 ], 0.278444, 1.236621);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 6 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 6 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 6 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 6 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 6 ], 3);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 6 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 6 ], true);

		Police_TV[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid, 24.888885, 218.026687, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 7 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 7 ], 30.666669, 40.320022);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 7 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 7 ], -1);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 7 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 7 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 7 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 7 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, Police_TV[ playerid ][ 7 ], 19942);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 7 ], 0);
		PlayerTextDrawSetPreviewRot(playerid, Police_TV[ playerid ][ 7 ],0.000000, 0.000000, 0.000000, 1.000000);

		Police_TV[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid, 62.333301, 236.448913, "Pojacanje");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 8 ], 0.278444, 1.236621);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 8 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 8 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 8 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 8 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 8 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 8 ], 3);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 8 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 8 ], true);

		Police_TV[ playerid ][ 9 ] = CreatePlayerTextDraw(playerid, 29.333335, 251.377792, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 9 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 9 ], 29.777778, 39.324462);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 9 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 9 ], -1);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 9 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 9 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 9 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 9 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 9 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, Police_TV[ playerid ][ 9 ], 19797);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 9 ], 0);
		PlayerTextDrawSetPreviewRot(playerid, Police_TV[ playerid ][ 9 ],0.000000, 0.000000, 0.000000, 1.000000);

		Police_TV[ playerid ][ 10 ] = CreatePlayerTextDraw(playerid, 63.333305, 264.328918, "Potjera");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 10 ], 0.278444, 1.236621);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 10 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 10 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 10 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 10 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 10 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 10 ], 3);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 10 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 10 ], true);

		Police_TV[ playerid ][ 11 ] = CreatePlayerTextDraw(playerid, 27.111108, 281.244476, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 11 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Police_TV[ playerid ][ 11 ], 27.555553, 36.337799);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 11 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 11 ], -1);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 11 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 11 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 11 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 11 ], 0);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 11 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, Police_TV[ playerid ][ 11 ], 18963);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 11 ], 0);
		PlayerTextDrawSetPreviewRot(playerid, Police_TV[ playerid ][ 11 ],0.000000, 0.000000, 0.000000, 1.000000);

		Police_TV[ playerid ][ 12 ] = CreatePlayerTextDraw(playerid, 56.111179, 295.186798, "OSUMNJICENI");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 12 ], 0.278444, 1.236621);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 12 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 12 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 12 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 12 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 12 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 12 ], 3);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 12 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 12 ], true);

		Police_TV[ playerid ][ 13 ] = CreatePlayerTextDraw(playerid, 171.555572, 308.124328, "X");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 13 ], 0.423777, 1.296356);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 13 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 13 ], -16776961);
		PlayerTextDrawUseBox(playerid, Police_TV[ playerid ][ 13 ], true);
		PlayerTextDrawBoxColor(playerid, Police_TV[ playerid ][ 13 ], 0);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 13 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 13 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 13 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 13 ], 2);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 13 ], 1);
		PlayerTextDrawSetSelectable(playerid, Police_TV[ playerid ][ 13 ], true);

		Police_TV[ playerid ][ 14 ] = CreatePlayerTextDraw(playerid, 56.444438, 136.888900, "Police Database");
		PlayerTextDrawLetterSize(playerid, Police_TV[ playerid ][ 14 ], 0.250000, 0.903111);
		PlayerTextDrawAlignment(playerid, Police_TV[ playerid ][ 14 ], 1);
		PlayerTextDrawColor(playerid, Police_TV[ playerid ][ 14 ], -1);
		PlayerTextDrawSetShadow(playerid, Police_TV[ playerid ][ 14 ], 0);
		PlayerTextDrawSetOutline(playerid, Police_TV[ playerid ][ 14 ], 1);
		PlayerTextDrawBackgroundColor(playerid, Police_TV[ playerid ][ 14 ], 51);
		PlayerTextDrawFont(playerid, Police_TV[ playerid ][ 14 ], 2);
		PlayerTextDrawSetProportional(playerid, Police_TV[ playerid ][ 14 ], 1);


		for( new i = 0; i < 15; i++)
		{
			PlayerTextDrawShow( playerid, Police_TV[ playerid ][ i ] );
		}
	}
	else if( show == false )
	{
		for( new i = 0; i < 15; i ++)
		{
			PlayerTextDrawHide( playerid, Police_TV[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, Police_TV[ playerid ][ i ] );
			Police_TV[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
	}
}
//------------------------------------------------------------------------------
stock ObjektTDControl( playerid, bool:show ) {
	if( show == true ) {
		ObjektTD[ playerid ][ 0 ] = CreatePlayerTextDraw( playerid,412.000000, 376.000000, "    ");
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 0 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 0 ], 1);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 0 ], 0.509999, 1.400000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 0 ], -1);
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 0 ], 0);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 0 ], 1);
		PlayerTextDrawSetShadow( playerid,ObjektTD[ playerid ][ 0 ], 1);
		PlayerTextDrawUseBox( playerid,ObjektTD[ playerid ][ 0 ], 1);
		PlayerTextDrawBoxColor( playerid,ObjektTD[ playerid ][ 0 ], 150);
		PlayerTextDrawTextSize( playerid,ObjektTD[ playerid ][ 0 ], 202.000000, 40.000000);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 0 ], 0);

		ObjektTD[ playerid ][ 1 ] = CreatePlayerTextDraw( playerid,207.000000, 378.000000, "cena: ~w~1000");
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 1 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 1 ], 3);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 1 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 1 ], UGBOJA );
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 1 ], 0);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 1 ], 1);
		PlayerTextDrawSetShadow( playerid,ObjektTD[ playerid ][ 1 ], 1);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 1 ], 0);

		ObjektTD[ playerid ][ 2 ] = CreatePlayerTextDraw( playerid,380.000000, 400.000000, "ld_beat:right"); // 229.000000, 410.000000
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 2 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 2 ], 4);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 2 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 2 ], -1);
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 2 ], 1);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 2 ], 0);
		PlayerTextDrawUseBox( playerid,ObjektTD[ playerid ][ 2 ], 1);
		PlayerTextDrawBoxColor( playerid,ObjektTD[ playerid ][ 2 ], 255);
		PlayerTextDrawTextSize( playerid,ObjektTD[ playerid ][ 2 ], 23.000000, 13.000000);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 2 ], 1);

		ObjektTD[ playerid ][ 3 ] = CreatePlayerTextDraw( playerid,387.000000, 375.000000, "ld_beat:cross");
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 3 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 3 ], 4);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 3 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 3 ], -1);
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 3 ], 1);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 3 ], 0);
		PlayerTextDrawUseBox( playerid,ObjektTD[ playerid ][ 3 ], 1);
		PlayerTextDrawBoxColor( playerid,ObjektTD[ playerid ][ 3 ], 255);
		PlayerTextDrawTextSize( playerid,ObjektTD[ playerid ][ 3 ], 23.000000, 13.000000);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 3 ], 1);

		ObjektTD[ playerid ][ 4 ] = CreatePlayerTextDraw( playerid,214.000000, 400.000000, "ld_beat:left"); // 407.000000, 410.000000
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 4 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 4 ], 4);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 4 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 4 ], -1);
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 4 ], 0);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 4 ], 1);
		PlayerTextDrawSetShadow( playerid,ObjektTD[ playerid ][ 4 ], 1);
		PlayerTextDrawUseBox( playerid,ObjektTD[ playerid ][ 4 ], 1);
		PlayerTextDrawBoxColor( playerid,ObjektTD[ playerid ][ 4 ], 255);
		PlayerTextDrawTextSize( playerid,ObjektTD[ playerid ][ 4 ], 23.000000, 13.000000);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 4 ], 1);

		ObjektTD[ playerid ][ 5 ] = CreatePlayerTextDraw( playerid,306.000000, 397.000000, "Kupi namestaj");
		PlayerTextDrawAlignment( playerid, ObjektTD[ playerid ][ 5 ], 2);
		PlayerTextDrawBackgroundColor( playerid,ObjektTD[ playerid ][ 5 ], 255);
		PlayerTextDrawFont( playerid,ObjektTD[ playerid ][ 5 ], 2);
		PlayerTextDrawLetterSize( playerid,ObjektTD[ playerid ][ 5 ], 0.390000, 1.000000);
		PlayerTextDrawColor( playerid,ObjektTD[ playerid ][ 5 ], -1);
		PlayerTextDrawSetOutline( playerid,ObjektTD[ playerid ][ 5 ], 0);
		PlayerTextDrawSetProportional( playerid,ObjektTD[ playerid ][ 5 ], 1);
		PlayerTextDrawSetShadow( playerid,ObjektTD[ playerid ][ 5 ], 1);
		PlayerTextDrawTextSize( playerid,ObjektTD[ playerid ][ 5 ], 200.000000, 100.000000);
		PlayerTextDrawSetSelectable( playerid,ObjektTD[ playerid ][ 5 ], 1);

		for( new i = 0; i < 6; i++) {
			PlayerTextDrawShow( playerid, ObjektTD[ playerid ][ i ] );
		}
	}
	else if( show == false ) {
		for( new i = 0; i < 6; i ++) {
			PlayerTextDrawHide( playerid, ObjektTD[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, ObjektTD[ playerid ][ i ] );
			ObjektTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
	}
}
//------------------------------------------------------------------------------
stock OrmarTDControl( playerid, bool:show ) {
	if( show == true ) {
		Ormar[ playerid ][ 0 ] = CreatePlayerTextDraw( playerid,475.000000, 332.000000, "           ");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 0 ], UGBOJA );
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 0 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 0 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 0 ], -1);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 0 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 0 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 0 ], 5);
		PlayerTextDrawUseBox( playerid,Ormar[ playerid ][ 0 ], 1);
		PlayerTextDrawBoxColor( playerid,Ormar[ playerid ][ 0 ], 100);
		PlayerTextDrawTextSize( playerid,Ormar[ playerid ][ 0 ], 139.000000, 10.000000);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 0 ], 0);

		Ormar[ playerid ][ 1 ] = CreatePlayerTextDraw( playerid,334.000000, 419.000000, "-");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 1 ], 255);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 1 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 1 ], 10.220003, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 1 ], UGBOJA );
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 1 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 1 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 1 ], 1);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 1 ], 0);

		Ormar[ playerid ][ 2 ] = CreatePlayerTextDraw( playerid,234.000000, 338.000000, "-");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 2 ], 255);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 2 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 2 ], 10.220003, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 2 ], UGBOJA );
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 2 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 2 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 2 ], 1);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 2 ], 0);

		Ormar[ playerid ][ 3 ] = CreatePlayerTextDraw( playerid,140.000000, 344.000000, "New Textdraw");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 3 ], 0);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 3 ], 5);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 3 ], 0.0000, 0.0000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 3 ], -1);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 3 ], 1);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 3 ], 1);
		PlayerTextDrawUseBox( playerid,Ormar[ playerid ][ 3 ], 1);
		PlayerTextDrawBoxColor( playerid,Ormar[ playerid ][ 3 ], 255);
		PlayerTextDrawTextSize( playerid,Ormar[ playerid ][ 3 ], 103.000000, 80.000000);
		PlayerTextDrawSetPreviewModel( playerid, Ormar[ playerid ][ 3 ], 29);
		PlayerTextDrawSetPreviewRot( playerid, Ormar[ playerid ][ 3 ], 0.000000, 0.000000, 0.000000, 1.000000);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 3 ], 1);

		Ormar[ playerid ][ 4 ] = CreatePlayerTextDraw( playerid,261.000000, 344.000000, "New Textdraw");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 4 ], 0);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 4 ], 5);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 4 ], 0.000, 0.000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 4 ], -1);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 4 ], 1);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 4 ], 1);
		PlayerTextDrawUseBox( playerid,Ormar[ playerid ][ 4 ], 1);
		PlayerTextDrawBoxColor( playerid,Ormar[ playerid ][ 4 ], 255);
		PlayerTextDrawTextSize( playerid,Ormar[ playerid ][ 4 ], 103.000000, 80.000000);
		PlayerTextDrawSetPreviewModel( playerid, Ormar[ playerid ][ 4 ], 19);
		PlayerTextDrawSetPreviewRot( playerid, Ormar[ playerid ][ 4 ], 0.000000, 0.000000, 0.000000, 1.000000);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 4 ], 1);

		Ormar[ playerid ][ 5 ] = CreatePlayerTextDraw( playerid,377.000000, 344.000000, "New Textdraw");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 5 ], 0);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 5 ], 5);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 5 ], 0.000, 0.000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 5 ], -1);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 5 ], 1);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 5 ], 1);
		PlayerTextDrawUseBox( playerid,Ormar[ playerid ][ 5 ], 1);
		PlayerTextDrawBoxColor( playerid,Ormar[ playerid ][ 5 ], 255);
		PlayerTextDrawTextSize( playerid,Ormar[ playerid ][ 5 ], 103.000000, 80.000000);
		PlayerTextDrawSetPreviewModel( playerid, Ormar[ playerid ][ 5 ], 110);
		PlayerTextDrawSetPreviewRot( playerid, Ormar[ playerid ][ 5 ], 0.000000, 0.000000, 0.000000, 1.000000);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 5 ], 1);

		Ormar[ playerid ][ 6 ] = CreatePlayerTextDraw( playerid,234.000000, 419.000000, "-");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 6 ], 255);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 6 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 6 ], 10.220003, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 6 ], UGBOJA );
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 6 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 6 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 6 ], 1);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 6 ], 0);

		Ormar[ playerid ][ 7 ] = CreatePlayerTextDraw( playerid,134.000000, 419.000000, "-");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 7 ], 255);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 7 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 7 ], 10.220003, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 7 ], UGBOJA );
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 7 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 7 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 7 ], 1);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 7 ], 0);

		Ormar[ playerid ][ 8 ] = CreatePlayerTextDraw( playerid, 305.000000, 330.000000, "Izaberi_odecu");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 8 ], 255 );
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 8 ], 0 );
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 8 ], 0.500000, 1.000000);
		PlayerTextDrawTextSize( playerid,Ormar[ playerid ][ 8 ], 40.000000, 10.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 8 ], -1);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 8 ], 1 );
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 8 ], 1 );
		PlayerTextDrawAlignment( playerid, Ormar[ playerid ][ 8 ], 2 );
		PlayerTextDrawSetShadow( playerid, Ormar[ playerid ][ 8 ], 1 );
		PlayerTextDrawSetSelectable( playerid, Ormar[ playerid ][ 8 ], 1 );

		Ormar[ playerid ][ 9 ] = CreatePlayerTextDraw( playerid,458.000000, 331.000000, "X");
		PlayerTextDrawBackgroundColor( playerid,Ormar[ playerid ][ 9 ], 255);
		PlayerTextDrawFont( playerid,Ormar[ playerid ][ 9 ], 1);
		PlayerTextDrawLetterSize( playerid,Ormar[ playerid ][ 9 ], 0.500000, 1.000000);
		PlayerTextDrawColor( playerid,Ormar[ playerid ][ 9 ], -16776961);
		PlayerTextDrawSetOutline( playerid,Ormar[ playerid ][ 9 ], 0);
		PlayerTextDrawSetProportional( playerid,Ormar[ playerid ][ 9 ], 1);
		PlayerTextDrawSetShadow( playerid,Ormar[ playerid ][ 9 ], 1);
		PlayerTextDrawSetSelectable( playerid,Ormar[ playerid ][ 9 ], 1);

	}
	else if( show == false ) {
		for( new i = 0; i < 10; i ++) {
			PlayerTextDrawHide( playerid, Ormar[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, Ormar[ playerid ][ i ] );
			Ormar[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
	}
}
//------------------------------------------------------------------------------
stock CKilometriTDControl( playerid, bool:show )
{
	if( show == true )
	{
			CKilometri[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid, 636.222229, 280.753173, "usebox");//new
			PlayerTextDrawLetterSize(playerid, CKilometri[ playerid ][ 0 ], 0.000000, 5.435428);
			PlayerTextDrawTextSize(playerid, CKilometri[ playerid ][ 0 ], 506.000000, 0.000000);
			PlayerTextDrawAlignment(playerid, CKilometri[ playerid ][ 0 ], 1);
			PlayerTextDrawColor(playerid, CKilometri[ playerid ][ 0 ], 0);
			PlayerTextDrawUseBox(playerid, CKilometri[ playerid ][ 0 ], true);
			PlayerTextDrawBoxColor(playerid, CKilometri[ playerid ][ 0 ], 102);
			PlayerTextDrawSetShadow(playerid, CKilometri[ playerid ][ 0 ], 0);
			PlayerTextDrawSetOutline(playerid, CKilometri[ playerid ][ 0 ], 0);
			PlayerTextDrawFont(playerid, CKilometri[ playerid ][ 0 ], 0);
			
			CKilometri[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid, 562.333557, 306.137756, " ");//zarada
			PlayerTextDrawLetterSize(playerid, CKilometri[ playerid ][ 2 ], 0.209999, 1.132088);
			PlayerTextDrawAlignment(playerid, CKilometri[ playerid ][ 2 ], 1);
			PlayerTextDrawColor(playerid, CKilometri[ playerid ][ 2 ], -1);
			PlayerTextDrawSetShadow(playerid, CKilometri[ playerid ][ 2 ], 0);
			PlayerTextDrawSetOutline(playerid, CKilometri[ playerid ][ 2 ], 1);
			PlayerTextDrawBackgroundColor(playerid, CKilometri[ playerid ][ 2 ], 51);
			PlayerTextDrawFont(playerid, CKilometri[ playerid ][ 2 ], 3);
			PlayerTextDrawSetProportional(playerid, CKilometri[ playerid ][ 2 ], 1);
			
			CKilometri[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid, 561.555725, 290.711181, "Predjeno: 100km");//new
			PlayerTextDrawLetterSize(playerid, CKilometri[ playerid ][ 1 ], 0.209999, 1.132088);
			PlayerTextDrawAlignment(playerid, CKilometri[ playerid ][ 1 ], 1);
			PlayerTextDrawColor(playerid, CKilometri[ playerid ][ 1 ], -1);
			PlayerTextDrawSetShadow(playerid, CKilometri[ playerid ][ 1 ], 0);
			PlayerTextDrawSetOutline(playerid, CKilometri[ playerid ][ 1 ], 1);
			PlayerTextDrawBackgroundColor(playerid, CKilometri[ playerid ][ 1 ], 51);
			PlayerTextDrawFont(playerid, CKilometri[ playerid ][ 1 ], 3);
			PlayerTextDrawSetProportional(playerid, CKilometri[ playerid ][ 1 ], 1);
			
			
			CKilometri[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid, 502.666595, 267.804412, "LD_SPAC:white");//new
			PlayerTextDrawLetterSize(playerid, CKilometri[ playerid ][ 3 ], 0.000000, 0.000000);
			PlayerTextDrawTextSize(playerid, CKilometri[ playerid ][ 3 ], 78.666717, 85.119995);
			PlayerTextDrawAlignment(playerid, CKilometri[ playerid ][ 3 ], 1);
			PlayerTextDrawColor(playerid, CKilometri[ playerid ][ 3 ], -1);
			PlayerTextDrawUseBox(playerid, CKilometri[ playerid ][ 3 ], true);
			PlayerTextDrawBoxColor(playerid, CKilometri[ playerid ][ 3 ], 0);
			PlayerTextDrawSetShadow(playerid, CKilometri[ playerid ][ 3 ], 0);
			PlayerTextDrawSetOutline(playerid, CKilometri[ playerid ][ 3 ], 0);
			PlayerTextDrawFont(playerid, CKilometri[ playerid ][ 3 ], 5);
			PlayerTextDrawSetPreviewModel(playerid,CKilometri[ playerid ][ 3 ], 574);
			PlayerTextDrawSetPreviewRot(playerid,CKilometri[ playerid ][ 3 ],0.000000, 0.000000, -40.000000, 1.000000);
			PlayerTextDrawBackgroundColor(playerid,CKilometri[ playerid ][ 3 ], 0);

			
			
			
			
			

			for( new i = 0; i < 4; i ++)
			{
				PlayerTextDrawShow( playerid, CKilometri[ playerid ][ i ] );
			}
	}
	else if( show == false )
	{
		for( new i = 0; i < 4; i ++)
		{
			PlayerTextDrawHide( playerid, CKilometri[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, CKilometri[ playerid ][ i ] );
			CKilometri[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
	}
}
//------------------------------------------------------------------------------

stock ZaposljavanjeTDControl( playerid, bool:show, string1[], string2[], string3[] ) {
	if( show == true ) {
	
		ZaposljavanjeTD[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid, 391.375000, 352.083496, "usebox");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 0.000000, 7.285187);
		PlayerTextDrawTextSize(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 243.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 0);
		PlayerTextDrawUseBox(playerid, ZaposljavanjeTD[ playerid ][ 0 ], true);
		PlayerTextDrawBoxColor(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 102);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 0);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 0 ], 0);

		ZaposljavanjeTD[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid, 317.500000, 351.166961, "Kosac trave");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 0.398749, 1.384164);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 2);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 1 ], UGBOJA );
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 3);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 1 ], 1);

		ZaposljavanjeTD[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid, 321.625000, 364.416931, "-");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 10.333113, 0.223331);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 2);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 2 ], -1);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 3);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 2 ], 1);

		ZaposljavanjeTD[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid, 249.125000, 368.500274, "zarada:             ~w~100$");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 0.296249, 0.870831);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 3 ], UGBOJA );
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 2);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 3 ], 1);

		ZaposljavanjeTD[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid, 249.500000, 377.083587, "ugovor:              ~w~5h");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 0.296249, 0.870831);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 4 ], UGBOJA );
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 2);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 4 ], 1);

		ZaposljavanjeTD[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid, 245.625000, 387.333251, "-");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 9.959370, 0.310833);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 5 ], -1);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 1);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 5 ], 1);

		ZaposljavanjeTD[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid, 373.875000, 400.499969, "usebox");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 0.000000, 1.303708);
		PlayerTextDrawTextSize(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 260.500000, 0.000000);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 0);
		PlayerTextDrawUseBox(playerid, ZaposljavanjeTD[ playerid ][ 6 ], true);
		PlayerTextDrawBoxColor(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 102);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 0);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 6 ], 0);

		ZaposljavanjeTD[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid, 317.875000, 400.000366, "prihvati posao");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 0.398749, 1.384164);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 2);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 7 ], -1);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 1);
		PlayerTextDrawBackgroundColor(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 51);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 3);
		PlayerTextDrawSetProportional(playerid, ZaposljavanjeTD[ playerid ][ 7 ], 1);
		PlayerTextDrawSetSelectable(playerid, ZaposljavanjeTD[ playerid ][ 7 ], true);

		ZaposljavanjeTD[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid, 379.375000, 345.333465, "ld_beat:cross");
		PlayerTextDrawLetterSize(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 15.000000, 12.250007);
		PlayerTextDrawAlignment(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 1);
		PlayerTextDrawColor(playerid, ZaposljavanjeTD[ playerid ][ 8 ], -1);
		PlayerTextDrawSetShadow(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 0);
		PlayerTextDrawSetOutline(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 0);
		PlayerTextDrawFont(playerid, ZaposljavanjeTD[ playerid ][ 8 ], 4);
		PlayerTextDrawSetSelectable(playerid, ZaposljavanjeTD[ playerid ][ 8 ], true);
	
		PlayerTextDrawSetString( playerid, ZaposljavanjeTD[ playerid ][ 1 ], string1 );
		PlayerTextDrawSetString( playerid, ZaposljavanjeTD[ playerid ][ 3 ], string2 );
		PlayerTextDrawSetString( playerid, ZaposljavanjeTD[ playerid ][ 4 ], string3 );
		
		SetTimerEx( "ShowZaposljavanjeTD", 150, false, "d", playerid );

	}
	else if( show == false ) {
		for( new i = 0; i < 9; i ++) {
			PlayerTextDrawHide( playerid, ZaposljavanjeTD[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, ZaposljavanjeTD[ playerid ][ i ] );
			ZaposljavanjeTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
		PosaoTDShowed[ playerid ] = false;
	}
}

forward ShowZaposljavanjeTD( playerid );
public ShowZaposljavanjeTD( playerid ) {

	for( new i = 0; i < 9; i ++ ) {
		PlayerTextDrawShow( playerid, ZaposljavanjeTD[ playerid ][ i ] );
	}
	SelectTextDraw( playerid, UGBOJA );
	PosaoTDShowed[ playerid ] = true;
	return 1;
}

stock BuyCarTDControl( playerid, bool:show )
{

	if( show == true )
	{
	
		BuyCar[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid, 496.666748, 322.566589, "usebox");// OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 0 ], 0.000000, 11.408763);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 0 ], 162.888885, 0.000000);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 0 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 0 ], 0);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 0 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 0 ], 102);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 0 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 0 ], 0);

		BuyCar[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid, 162.666732, 353.920104, "-");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 2 ], 9.806889, 1.196799);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 2 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 2 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 2 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 2 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 2 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 2 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 2 ], 2);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 2 ], 1);

		BuyCar[ playerid ][ 13 ] = CreatePlayerTextDraw(playerid, 164.444503, 320.071258, "LD_SPAC:white");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 13 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 13 ], 330.666687, 10.951107);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 13 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 13 ], tdboja);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 13 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 13 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 13 ], 4);

		BuyCar[ playerid ][ 14 ] = CreatePlayerTextDraw(playerid, 164.111175, 424.111175, "LD_SPAC:white");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 14 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 14 ], 330.666656, 2.986661);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 14 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 14 ], tdboja);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 14 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 14 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 14 ], 4);

		BuyCar[ playerid ][ 15 ] = CreatePlayerTextDraw(playerid, 376.111968, 353.426818, "-");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 15 ], 9.806889, 1.196799);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 15 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 15 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 15 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 15 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 15 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 15 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 15 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 15 ], 2);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 15 ], 1);

		BuyCar[ playerid ][ 16 ] = CreatePlayerTextDraw(playerid, 272.667449, 391.262359, "-");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 16 ], 9.806889, 1.196799);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 16 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 16 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 16 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 16 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 16 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 16 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 16 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 16 ], 2);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 16 ], 1);

		BuyCar[ playerid ][ 17 ] = CreatePlayerTextDraw(playerid, 223.555526, 347.946563, "Gorivo: ~w~dizel");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 17 ], 0.304222, 0.898133);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 17 ], 2);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 17 ], tdboja);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 17 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 17 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 17 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 17 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 17 ], 1);

		BuyCar[ playerid ][ 18 ] = CreatePlayerTextDraw(playerid, 436.110900, 347.950988, "broj vrata: ~w~5");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 18 ], 0.304222, 0.898133);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 18 ], 2);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 18 ], tdboja);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 18 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 18 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 18 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 18 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 18 ], 1);

		BuyCar[ playerid ][ 19 ] = CreatePlayerTextDraw(playerid, 330.444244, 402.213134, "Vrsta: ~w~putnicko");//
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 19 ], 0.304222, 0.898133);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 19 ], 2);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 19 ], tdboja);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 19 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 19 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 19 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 19 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 19 ], 1);

		//--------------------------------------------------------------------------

		BuyCar[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid, 272.444427, 337.991119, "LD_SPAC:white");// auto poprijeko u sredini OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 5], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 5], 115.111083, 86.115570);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 5], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 5], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 5], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 5], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 5], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 5], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 5], 5);
		PlayerTextDrawSetPreviewModel(playerid, BuyCar[ playerid ][ 5], 560);
		PlayerTextDrawSetPreviewRot(playerid, BuyCar[ playerid ][ 5],0.000000, 0.000000, 90.000000, 1.000000);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 5], 0);
		PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 5], 1, 1);
		

		BuyCar[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid, 165.777770, 388.266723, "LD_SPAC:white");//zlato OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 6 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 6 ], 29.333328, 28.871093);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 6 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 6 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 6 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 6 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 6 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 6 ], 5);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 6 ], true);
		PlayerTextDrawSetPreviewModel(playerid, BuyCar[ playerid ][ 6 ], 1212);
		PlayerTextDrawSetPreviewRot(playerid, BuyCar[ playerid ][ 6 ],140.000000, 0.000000, -40.000000, 1.000000);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 6 ], 0);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 6 ], true);

		BuyCar[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid, 193.333374, 403.697875, "$20000000");//cijena OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 7 ], 0.293555, 1.117155);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 7 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 7 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 7 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 7 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 7 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 7 ], 1);

		BuyCar[ playerid ][ 9 ] = CreatePlayerTextDraw(playerid, 168.444427, 338.986694, "LD_SPAC:white");//lijevo auto bocno OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 9 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 9 ], 115.555549, 87.111114);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 9 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 9 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 9 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 9 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 9 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 9 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 9 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, BuyCar[ playerid ][ 9 ], 560);
		PlayerTextDrawSetPreviewRot(playerid, BuyCar[ playerid ][ 9 ],0.000000, 0.000000, -40.000000, 1.000000);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 9 ], 0);
		PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 9 ], 1, 1);

		BuyCar[ playerid ][ 10 ] = CreatePlayerTextDraw(playerid, 392.444519, 392.746643, "LD_SPAC:white");//Zlato OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 10 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 10 ], 26.666648, 29.368896);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 10 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 10 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 10 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 10 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 10 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 10 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 10 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, BuyCar[ playerid ][ 10 ], 19941);
		PlayerTextDrawSetPreviewRot(playerid, BuyCar[ playerid ][ 10 ],-30.000000, 0.000000, 40.000000, 1.000000);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 10 ], 0);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 10 ], true);

		BuyCar[ playerid ][ 11 ] = CreatePlayerTextDraw(playerid, 419.555450, 405.191101, "20000g");//OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 11 ], 0.337111, 0.977778);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 11 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 11 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 11 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 11 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 11 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 11 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 11 ], 1);

		BuyCar[ playerid ][ 12 ] = CreatePlayerTextDraw(playerid, 383.111053, 339.484436, "LD_SPAC:white");//YEAA desno auto bocno
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 12 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 12 ], 105.333343, 88.106658);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 12 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 12 ], -1);
		PlayerTextDrawUseBox(playerid, BuyCar[ playerid ][ 12 ], true);
		PlayerTextDrawBoxColor(playerid, BuyCar[ playerid ][ 12 ], 0);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 12 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 12 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 12 ], 5);
		PlayerTextDrawSetPreviewModel(playerid, BuyCar[ playerid ][ 12 ], 560);
		PlayerTextDrawSetPreviewRot(playerid, BuyCar[ playerid ][ 12 ],0.000000, 0.000000, 40.000000, 1.000000);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 12 ], 0);
		PlayerTextDrawSetPreviewVehCol(playerid, BuyCar[ playerid ][ 12 ], 1, 1);

		BuyCar[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid, 481.777862, 321.066528, "ld_beat:cross");//x OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 8 ], -0.096444, -0.686933);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 8 ], 8.888879, 9.457776);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 8 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 8 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 8 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 8 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 8 ], 4);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 8 ], true);

		BuyCar[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid, 332.000457, 321.066619, "Infernus");// OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 3 ], 0.384666, 0.942933);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 3 ], 2);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 3 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 3 ], 1);
		PlayerTextDrawBackgroundColor(playerid, BuyCar[ playerid ][ 3 ], 51);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 3 ], 3);
		PlayerTextDrawSetProportional(playerid, BuyCar[ playerid ][ 3 ], 1);

		BuyCar[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid, 240.111709, 321.568878, "ld_beat:left");// OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 4 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 4 ], 23.111101, 8.462226);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 4 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 4 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 4 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 4 ], 4);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 4 ], true);

		BuyCar[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid, 401.333892, 322.062164, "ld_beat:right");// OK
		PlayerTextDrawLetterSize(playerid, BuyCar[ playerid ][ 1 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BuyCar[ playerid ][ 1 ], 23.111101, 8.462226);
		PlayerTextDrawAlignment(playerid, BuyCar[ playerid ][ 1 ], 1);
		PlayerTextDrawColor(playerid, BuyCar[ playerid ][ 1 ], -1);
		PlayerTextDrawSetShadow(playerid, BuyCar[ playerid ][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, BuyCar[ playerid ][ 1 ], 0);
		PlayerTextDrawFont(playerid, BuyCar[ playerid ][ 1 ], 4);
		PlayerTextDrawSetSelectable(playerid, BuyCar[ playerid ][ 1 ], true);

		//--------------------------------------------------------------------------

		for( new i = 0; i < 20; i ++)
		{
			PlayerTextDrawShow( playerid, BuyCar[ playerid ][ i ] );
		}
		
		BuyCarTDShowed[ playerid ] = true;

	}
	else if( show == false )
	{
		for( new i = 0; i < 20; i ++)
		{
			PlayerTextDrawHide( playerid, BuyCar[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, BuyCar[ playerid ][ i ] );
			BuyCar[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
		
		BuyCarTDShowed[ playerid ] = false;
	}
	return 1;
}

//------------------------------------------------------------------------------

stock BojaVozilaTDControl( playerid, bool:show )
{

	if( show == true )
	{
		ASBojaVozila[ 0 ] [ playerid ] = CreatePlayerTextDraw(playerid, 626.444458, 23.402236, "usebox");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 0 ] [ playerid ], 0.000000, 16.386543);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 0 ] [ playerid ], 485.111145, 0.000000);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 0 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 0 ] [ playerid ], 0);
		PlayerTextDrawUseBox(playerid, ASBojaVozila[ 0 ] [ playerid ], true);
		PlayerTextDrawBoxColor(playerid, ASBojaVozila[ 0 ] [ playerid ], 102);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 0 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 0 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 0 ] [ playerid ], 0);

		ASBojaVozila[ 1 ] [ playerid ] = CreatePlayerTextDraw(playerid, 486.666564, 19.911109, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 1 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 1 ] [ playerid ], 137.777770, 13.937778);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 1 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 1 ] [ playerid ], tdboja);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 1 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 1 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 1 ] [ playerid ], 4);

		ASBojaVozila[ 2 ] [ playerid ] = CreatePlayerTextDraw(playerid, 486.777679, 167.755554, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 2 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 2 ] [ playerid ], 137.777770, 4.977779);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 2 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 2 ] [ playerid ], tdboja);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 2 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 2 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 2 ] [ playerid ], 4);

		ASBojaVozila[ 3 ] [ playerid ] = CreatePlayerTextDraw(playerid, 557.777954, 22.399995, "boja");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 3 ] [ playerid ], 0.398444, 1.017599);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 3 ] [ playerid ], 2);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 3 ] [ playerid ], -1);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 3 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 3 ] [ playerid ], 1);
		PlayerTextDrawBackgroundColor(playerid, ASBojaVozila[ 3 ] [ playerid ], 51);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 3 ] [ playerid ], 3);
		PlayerTextDrawSetProportional(playerid, ASBojaVozila[ 3 ] [ playerid ], 1);

		ASBojaVozila[ 4 ] [ playerid ] = CreatePlayerTextDraw(playerid, 499.111206, 64.213333, "LD_SPAC:white");//crna
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 4 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 4 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 4 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 4 ] [ playerid ], 255);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 4 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 4 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 4 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 4 ] [ playerid ], true);

		ASBojaVozila[ 5 ] [ playerid ] = CreatePlayerTextDraw(playerid, 522.778015, 64.217773, "LD_SPAC:white");//bijela
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 5 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 5 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 5 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 5 ] [ playerid ], -1);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 5 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 5 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 5 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 5 ] [ playerid ], true);

		ASBojaVozila[ 6 ] [ playerid ] = CreatePlayerTextDraw(playerid, 546.000183, 64.222206, "LD_SPAC:white");//svjetlo plava
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 6 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 6 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 6 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 6 ] [ playerid ], 8964863);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 6 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 6 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 6 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 6 ] [ playerid ], true);

		ASBojaVozila[ 7 ] [ playerid ] = CreatePlayerTextDraw(playerid, 568.778015, 64.226646, "LD_SPAC:white");//crvena
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 7 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 7 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 7 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 7 ] [ playerid ], -1476394753);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 7 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 7 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 7 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 7 ] [ playerid ], true);

		ASBojaVozila[ 8 ] [ playerid ] = CreatePlayerTextDraw(playerid, 591.111511, 64.231086, "LD_SPAC:white");//zelenoplava
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 8 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 8 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 8 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 8 ] [ playerid ], 5855743);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 8 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 8 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 8 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 8 ] [ playerid ], true);

		ASBojaVozila[ 9 ] [ playerid ] = CreatePlayerTextDraw(playerid, 499.222290, 88.608909, "LD_SPAC:white");//pink
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 9 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 9 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 9 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 9 ] [ playerid ], -1066870785);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 9 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 9 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 9 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 9 ] [ playerid ], true);

		ASBojaVozila[ 10 ] [ playerid ] = CreatePlayerTextDraw(playerid, 522.444641, 88.613349, "LD_SPAC:white");//zuta
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 10 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 10 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 10 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 10 ] [ playerid ], -122146049);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 10 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 10 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 10 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 10 ] [ playerid ], true);

		ASBojaVozila[ 11 ] [ playerid ] = CreatePlayerTextDraw(playerid, 545.666931, 88.617782, "LD_SPAC:white");//zelena
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 11 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 11 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 11 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 11 ] [ playerid ], 8405247);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 11 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 11 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 11 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 11 ] [ playerid ], true);

		ASBojaVozila[ 12 ] [ playerid ] = CreatePlayerTextDraw(playerid, 568.889221, 88.622230, "LD_SPAC:white");//tamno ljubicasta
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 12 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 12 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 12 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 12 ] [ playerid ], 806844927);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 12 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 12 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 12 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 12 ] [ playerid ], true);

		ASBojaVozila[ 13 ] [ playerid ] = CreatePlayerTextDraw(playerid, 590.778076, 88.128890, "LD_SPAC:white");//svjetlo zelena
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 13 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 13 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 13 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 13 ] [ playerid ], -1661753345);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 13 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 13 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 13 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 13 ] [ playerid ], true);

		ASBojaVozila[ 14 ] [ playerid ] = CreatePlayerTextDraw(playerid, 499.333557, 113.022224, "LD_SPAC:white");//narandjasta
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 14 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 14 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 14 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 14 ] [ playerid ], -817555713);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 14 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 14 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 14 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 14 ] [ playerid ], true);

		ASBojaVozila[ 15 ] [ playerid ] = CreatePlayerTextDraw(playerid, 522.111572, 113.026664, "LD_SPAC:white");//Tamno plava
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 15 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 15 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 15 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 15 ] [ playerid ], 39159551);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 15 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 15 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 15 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 15 ] [ playerid ], true);

		ASBojaVozila[ 16 ] [ playerid ] = CreatePlayerTextDraw(playerid, 545.333862, 113.031105, "LD_SPAC:white");//plavozelena
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 16 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 16 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 16 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 16 ] [ playerid ], 9803263);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 16 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 16 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 16 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 16 ] [ playerid ], true);

		ASBojaVozila[ 17 ] [ playerid ] = CreatePlayerTextDraw(playerid, 569.000427, 113.035552, "LD_SPAC:white");//siva
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 17 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 17 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 17 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 17 ] [ playerid ], 2139062271);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 17 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 17 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 17 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 17 ] [ playerid ], true);

		ASBojaVozila[ 18 ] [ playerid ] = CreatePlayerTextDraw(playerid, 590.889404, 113.039993, "LD_SPAC:white");//tamno crvena
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 18 ] [ playerid ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ASBojaVozila[ 18 ] [ playerid ], 16.888885, 16.924446);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 18 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 18 ] [ playerid ], 1962934527);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 18 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 18 ] [ playerid ], 0);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 18 ] [ playerid ], 4);
		PlayerTextDrawSetSelectable(playerid, ASBojaVozila[ 18 ] [ playerid ], true);

		ASBojaVozila[ 19 ] [ playerid ] = CreatePlayerTextDraw(playerid, 486.222106, 132.906707, "-");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 19 ] [ playerid ], 11.397992, 0.828444);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 19 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 19 ] [ playerid ], -1);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 19 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 19 ] [ playerid ], 1);
		PlayerTextDrawBackgroundColor(playerid, ASBojaVozila[ 19 ] [ playerid ], 51);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 19 ] [ playerid ], 2);
		PlayerTextDrawSetProportional(playerid, ASBojaVozila[ 19 ] [ playerid ], 1);

		ASBojaVozila[ 20 ] [ playerid ] = CreatePlayerTextDraw(playerid, 486.777679, 52.271144, "-");
		PlayerTextDrawLetterSize(playerid, ASBojaVozila[ 20 ] [ playerid ], 11.397992, 0.828444);
		PlayerTextDrawAlignment(playerid, ASBojaVozila[ 20 ] [ playerid ], 1);
		PlayerTextDrawColor(playerid, ASBojaVozila[ 20 ] [ playerid ], -1);
		PlayerTextDrawSetShadow(playerid, ASBojaVozila[ 20 ] [ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, ASBojaVozila[ 20 ] [ playerid ], 1);
		PlayerTextDrawBackgroundColor(playerid, ASBojaVozila[ 20 ] [ playerid ], 51);
		PlayerTextDrawFont(playerid, ASBojaVozila[ 20 ] [ playerid ], 2);
		PlayerTextDrawSetProportional(playerid, ASBojaVozila[ 20 ] [ playerid ], 1);
		//--------------------------------------------------------------------------

		for( new i = 0; i < 21; i ++)
		{
			PlayerTextDrawShow( playerid, ASBojaVozila[ i ] [ playerid ] );
		}

		BojaVozilaTDShowed[ playerid ] = true;

	}
	else if( show == false )
	{
		for( new i = 0; i < 21; i ++)
		{
			PlayerTextDrawHide( playerid, ASBojaVozila[ i ] [ playerid ] );
			PlayerTextDrawDestroy( playerid, ASBojaVozila[ i ] [ playerid ] );
			ASBojaVozila[ i ] [ playerid ] = PlayerText:INVALID_TEXT_DRAW;
		}

		BojaVozilaTDShowed[ playerid ] = false;
	}
	return 1;
}
//------------------------------------------------------------------------------
stock VremeTDControl( playerid, bool:show )
{
	if( show == true )
	{
		PVreme[ playerid ] = CreatePlayerTextDraw(playerid, 472.250000, 269.916778, "~w~Pricekajte, Vrijeme: ~r~180");
		PlayerTextDrawLetterSize(playerid, PVreme[ playerid ], 0.373749, 1.104166);
		PlayerTextDrawAlignment(playerid, PVreme[ playerid ], 1);
		PlayerTextDrawColor(playerid, PVreme[ playerid ], -1);
		PlayerTextDrawSetShadow(playerid, PVreme[ playerid ], 0);
		PlayerTextDrawSetOutline(playerid, PVreme[ playerid ], 1);
		PlayerTextDrawBackgroundColor(playerid, PVreme[ playerid ], 51);
		PlayerTextDrawFont(playerid, PVreme[ playerid ], 3);
		PlayerTextDrawSetProportional(playerid, PVreme[ playerid ], 1);
		PlayerTextDrawShow( playerid, PVreme[ playerid ] );

	}
	else if( show == false )
	{
		PlayerTextDrawHide( playerid, PVreme[ playerid ] );
		PlayerTextDrawDestroy( playerid, PVreme[ playerid ] );
		PVreme[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	}
}
//------------------------------------------------------------------------------
stock TutorijalTDControl(playerid, id)
{
	if(id == -1)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 0)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}

		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Dobrodosli!");

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]]]]]]]]]");

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Prije svega - dobro nam dosli na Nova Era Online Gaming Community!");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],
			"Sada slijedi kratak tutorial/uvod u server.");

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],
			"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],
			"Da ne duzimo mnogo ostanite sa nama do kraja tutorijala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],
			"Nova Era Community Staff team.");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 1)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Biro rada");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]");


		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Prvo sto cemo vam prikazati je biro rada koji se nalazi u Beogradu.");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],
			"Takodje biro rada se nalazi u ostalim gradovima.");//"Sada slijedi kratak tutorial/uvod u server.");


		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],
			"U birou mozete naci posao po vasim zeljama i kvalifikacijama.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],
			"Svi ne zaposleni gradjani mogu se obratiti na salterima biroa");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],
			"gdje cete dobiti sve upute i pomoc u pronalasku posla.");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid], 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 2)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Opstina");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]");


		//TutorijalTD[3][playerid] = CreatePlayerTextDraw(playerid, 14.000000, 207.375000, 
		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Glavna ustanova svakog grada je opstina koja se bavi dokumentacijom.");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//TutorijalTD[4][playerid] = CreatePlayerTextDraw(playerid, 14.500000, 223.562500, 
			"Na salterima opstine mozete izvaditi sve vazne dokumente kao sto su:");//"Sada slijedi kratak tutorial/uvod u server.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//TutorijalTD[5][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 240.187500, 
			"licna karta, pasos, vijencani list kao i taxi licence.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//TutorijalTD[6][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 257.687500, 
			"Ukoliko niste zadovoljni vasim poslom takodje mozete dati i otkaz.");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//TutorijalTD[7][playerid] = CreatePlayerTextDraw(playerid, 13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//TutorijalTD[8][playerid] = CreatePlayerTextDraw(playerid, 12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 3)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],//TutorijalTD[1][playerid] = CreatePlayerTextDraw(playerid, 16.000000, 161.875000, 
			"Banka");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],//TutorijalTD[2][playerid] = CreatePlayerTextDraw(playerid, 21.000000, 193.375000, 
			"]]]]]]]]]]]]]");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],//TutorijalTD[3][playerid] = CreatePlayerTextDraw(playerid, 14.000000, 207.375000, 
			"Banka je radna organizacija koja posreduje u novcanim transakcijama.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//TutorijalTD[4][playerid] = CreatePlayerTextDraw(playerid, 14.500000, 223.562500, 
			"Banka je vazna ustanova svakog grada jer je skladiste novca.");//"Sada slijedi kratak tutorial/uvod u server.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//TutorijalTD[5][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 240.187500, 
			"Bas zbog toga je ona i cesto podvrgnuta napadima mafija i bandi.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//TutorijalTD[6][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 257.687500, 
			"Ukoliko zelite otvoriti racun, podici kredit ili nekome poslati novac.");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//TutorijalTD[7][playerid] = CreatePlayerTextDraw(playerid, 13.000000, 274.312500, 
			"To mozete uciniti na salterima banke gdje ce vas docekati");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//TutorijalTD[8][playerid] = CreatePlayerTextDraw(playerid, 12.000000, 290.500000, 
			"profesionalno osoblje.");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 4)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
		

		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],//TutorijalTD[1][playerid] = CreatePlayerTextDraw(playerid, 16.000000, 161.875000, 
			"Pijaca");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],//TutorijalTD[2][playerid] = CreatePlayerTextDraw(playerid, 21.000000, 193.375000, 
			"]]]]]]]]]]]]]");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],//TutorijalTD[3][playerid] = CreatePlayerTextDraw(playerid, 14.000000, 207.375000, 
			"Ukoliko posjedujete imanje i zelite trgovati domacim proizvodima");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//TutorijalTD[4][playerid] = CreatePlayerTextDraw(playerid, 14.500000, 223.562500, 
			"to mozete uciniti na gradskoj trznici.");//"Sada slijedi kratak tutorial/uvod u server.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//TutorijalTD[5][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 240.187500, 
			"Takodje mozete kupiti domace i svijeze voce i povrce koje mozete");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//TutorijalTD[6][playerid] = CreatePlayerTextDraw(playerid, 13.500000, 257.687500, 
			"naci po mnogo jeftinijim cijenama nego u marketima.");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//TutorijalTD[7][playerid] = CreatePlayerTextDraw(playerid, 13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//TutorijalTD[8][playerid] = CreatePlayerTextDraw(playerid, 12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 5)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}

		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],//TutorijalTD[1][playerid] = CreatePlayerTextDraw(playerid, 16.000000, 161.875000, 
			"Kladionica");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Kladionica je takodjer jedno od bitnijih mjesta na serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Ako imate zelju za kladjenjem i ulaganjem novca u gluposti");//"Sada slijedi kratak tutorial/uvod u server.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"to mozete uciniti bas u kladionici.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 10)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
	

		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Nova Era Spawn");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Spawn je prvo mesto sa kojim imate kontakt pri registraciji na server...");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Tu mozete da se upoznate sa velikim brojem igraca.");//"Sada slijedi kratak tutorial/uvod u server.");


		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Mozete se upoznati sa njima i zajedno istrazivati server.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Za pomoc nam se obratite na - /pitaj!");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	
	if(id == 11)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}

		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Gigatron");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]");

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Gigatron je mjesto gdje mozete kupiti vas prvi telefon.");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Pored telefona, za isti trebati ce vam sim kartica!");//"Sada slijedi kratak tutorial/uvod u server.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Bez sim kartice ne mozete objavljivati oglase...");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Laptop i radio takodjer mozete nabaviti u gigatronu!");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"Laptop ce vam biti potreban za prije svega RP-anje a i za pljacke!");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 12)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
		


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Zlatara");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]");


		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Zlatara je takodjer jedno od vaznijih mesta na serveru!");

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"U zlatari mozete kupiti ili prodati zlato.");//"Sada slijedi kratak tutorial/uvod u server.");

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Zlatara, kao i banka moze biti opljackana, pazite se toga!");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Osim kupoprodaje zlata, u zlatari mozete kupiti sat");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
	
		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"i verenicki prsten!");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	
		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 13)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
		


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Organi reda i drzave orge");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]");


		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"U organe reda spadaju: SAJ, POLICIJA i Sheriff department");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Ukoliko ste vi bas za lov na kriminalce, pridruzite se organima reda");//"Sada slijedi kratak tutorial/uvod u server.");


		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Pored organa reda tu su i drzavne organizacije.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"U te organizacije spadaju hitna pomoc i CNN studio!");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 14)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}
	


		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Zatvor");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Na serveru postoji i mesto za gradjane koji ne postuju pravila!");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Postujte pravila i ona ce postovati vas, zapamtite to.");//"Sada slijedi kratak tutorial/uvod u server.");


		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Ukoliko ne, nemojte biti iznenadjeni - jail ce biti vase mesto boravka!");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Pravila servera mozete procitati na nasem forumu.");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	
	if(id == 15)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}




		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Trafike i prodavnice");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]");


		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Trafike i prodavnice 24/7 su jedna od najvaznijih mesta.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"U njima si mozete nabaviti razne potrebstine za vas.");//"Sada slijedi kratak tutorial/uvod u server.");


		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"U salonima odece mozete promjeniti vas default skin i kupiti ranac!");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Na trafikama mozete dopuniti kredit i kupiti manje kolicine hrane");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"U prodavnici mozete nabaviti vise stvari kao sto su maska i slicno...");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");

		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}

	if(id == 16)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}



		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"GPS System");

		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]]]]");


		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"Jos malo do kraja tutorijala...");


		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Samo da vas obavestimo da sto prije nabavite gps!");//"Sada slijedi kratak tutorial/uvod u server.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"Zasto? Naravno, na serveru pored prikazanog postoji jos mnogo toga");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"GPS ce vam pomoci da se snadjete i bolje upoznate sa serverom!");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"Ovaj virtualni svet je veoma velik i dobro vam dodje GPS da");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");


		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"vas uputi na siguran put.");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
	if(id == 6)
	{
		for(new i; i < 10; i++)
		{
			PlayerTextDrawHide(playerid, TutorijalTD[i][playerid]);
		}



		PlayerTextDrawSetString(playerid,TutorijalTD[1][playerid],
			"Kraj tutorijala");


		PlayerTextDrawSetString(playerid,TutorijalTD[2][playerid],
			"]]]]]]]]]]]]]]]]]]]]]]]");
	

		PlayerTextDrawSetString(playerid,TutorijalTD[3][playerid],
			"To bi bilo to od tutorijala.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[4][playerid],//14.500000, 223.562500, 
			"Nadamo se da ste nesto naucili iz njega, te da cete se");//"Sada slijedi kratak tutorial/uvod u server.");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[5][playerid],//13.500000, 240.187500, 
			"lakse snaci na serveru zahvaljujuci istom.");//"Takodje cemo vas uputiti kako da zapocnete igru na nasem serveru.");


		PlayerTextDrawSetString(playerid,TutorijalTD[6][playerid],//13.500000, 257.687500, 
			"Zelimo Vam ugodnu i zabavnu igru!");//"Da ne duzimo mnogo ostanite sa nama do kraja tutoriala.");


		PlayerTextDrawSetString(playerid,TutorijalTD[7][playerid],//13.000000, 274.312500, 
			"");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
		

		PlayerTextDrawSetString(playerid,TutorijalTD[8][playerid],//12.000000, 290.500000, 
			"Nova Era Community Staff Team");//"Televizorska oprema ajmo navali narode hahahahah lol seksi ghahahaha");
	
		for(new i; i < 10; i++)
		{
			PlayerTextDrawShow(playerid, TutorijalTD[i][playerid]);
		}
	}
}
//------------------------------------------------------------------------------
stock LoginTDControl( playerid, bool:show )
{
	if( show == true )
	{
		TextDrawHideForPlayer(playerid,betaversiontd);
		for( new i = 0; i < 14; i ++) 
		{
			TextDrawShowForPlayer( playerid, LoginTextdraws[ i ] );
		}
	}
	else if( show == false ) 
	{
		TextDrawShowForPlayer(playerid,betaversiontd);
		for( new i = 0; i < 14; i ++) 
		{
			TextDrawHideForPlayer( playerid, LoginTextdraws[ i ] );
		}
	}
}
/*UGRegisterTD[playerid][ 0 ] = CreatePlayerTextDraw(playerid, 906.444580, 356.415496, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 0 ], 0.000000, 34.622596);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 0 ], -134.888916, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 0 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 0 ], 0);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 0 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 0 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 0 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 0 ], 0);

		UGRegisterTD[playerid][ 1 ] = CreatePlayerTextDraw(playerid, -235.333389, 106.531135, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 1 ], 0.000000, -27.386299);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 1 ], 811.333374, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 1 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 1 ], 0);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 1 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 1 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 1 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 1 ], 0);

		UGRegisterTD[playerid][ 2 ] = CreatePlayerTextDraw(playerid, -54.666652, 353.422241, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 2 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 2 ], 813.333496, 3.982228);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 2 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 2 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 2 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 2 ], 4);

		UGRegisterTD[playerid][ 3 ] = CreatePlayerTextDraw(playerid, -7.555552, 103.040031, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 3 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 3 ], 698.667602, 4.479996);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 3 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 3 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 3 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 3 ], 4);

		UGRegisterTD[playerid][ 4 ] = CreatePlayerTextDraw(playerid, 209.777999, 354.915740, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 4 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 4 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 4 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 4 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 4 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 4 ], 4);

		UGRegisterTD[playerid][ 5 ] = CreatePlayerTextDraw(playerid, 217.444641, 355.417968, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 5 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 5 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 5 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 5 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 5 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 5 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 5 ], 4);

		UGRegisterTD[playerid][ 6 ] = CreatePlayerTextDraw(playerid, 422.444915, 355.920196, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 6 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 6 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 6 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 6 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 6 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 6 ], 4);

		UGRegisterTD[playerid][ 7 ] = CreatePlayerTextDraw(playerid, 430.111694, 356.422424, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 7 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 7 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 7 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 7 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 7 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 7 ], 4);

		UGRegisterTD[playerid][ 8 ] = CreatePlayerTextDraw(playerid, 430.667266, -135.875305, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 8 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 8 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 8 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 8 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 8 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 8 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 8 ], 4);

		UGRegisterTD[playerid][ 9 ] = CreatePlayerTextDraw(playerid, 423.222808, -136.368637, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 9 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 9 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 9 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 9 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 9 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 9 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 9 ], 4);

		UGRegisterTD[playerid][ 10 ] = CreatePlayerTextDraw(playerid, 211.778442, -137.359619, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 10 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 10 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 10 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 10 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 10 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 10 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 10 ], 4);

		UGRegisterTD[playerid][ 11 ] = CreatePlayerTextDraw(playerid, 204.778472, -136.857437, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 11 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 11 ], -3.111119, 240.426712);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 11 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 11 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 11 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 11 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 11 ], 4);

		UGRegisterTD[playerid][ 12 ] = CreatePlayerTextDraw(playerid, 61.777847, 5.973330, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 12 ], 3.641551, 9.225955);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 12 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 12 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 12 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 12 ], 3);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 12 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 12 ], 0);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 12 ], 1);

		UGRegisterTD[playerid][ 13 ] = CreatePlayerTextDraw(playerid, 507.222564, 0.999993, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 13 ], 3.035331, 10.012451);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 13 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 13 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 13 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 13 ], 3);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 13 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 13 ], 0);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 13 ], 1);

		UGRegisterTD[playerid][ 14 ] = CreatePlayerTextDraw(playerid, 280.000183, 86.613281, "LD_POOL:ball");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 14 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 14 ], 67.999969, -75.164451);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 14 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 14 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 14 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 14 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 14 ], 4);

		UGRegisterTD[playerid][ 15 ] = CreatePlayerTextDraw(playerid, 285.444702, 79.151084, "LD_POOL:ball");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 15 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 15 ], 57.333312, -60.231124);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 15 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 15 ], 255);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 15 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 15 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 15 ], 4);

		UGRegisterTD[playerid][ 16 ] = CreatePlayerTextDraw(playerid, 290.000122, 76.168876, "LD_POOL:ball");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 16 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 16 ], 47.999969, -53.262218);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 16 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 16 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 16 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 16 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 16 ], 4);

		UGRegisterTD[playerid][ 17 ] = CreatePlayerTextDraw(playerid, 299.555450, 31.360034, "Nova Era");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 17 ], 0.560222, 3.680711);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 17 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 17 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 17 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 17 ], 2);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 17 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 17 ], 0);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 17 ], 1);

		UGRegisterTD[playerid][ 18 ] = CreatePlayerTextDraw(playerid, 339.555816, 44.799983, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 18 ], 0.309109, 1.271466);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 18 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 18 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 18 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 18 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 18 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 18 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 18 ], 1);

		UGRegisterTD[playerid][ 19 ] = CreatePlayerTextDraw(playerid, 278.777954, 44.804443, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 19 ], 0.309109, 1.271466);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 19 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 19 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 19 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 19 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 19 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 19 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 19 ], 1);

		UGRegisterTD[playerid][ 20 ] = CreatePlayerTextDraw(playerid, 310.000244, 74.675559, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 20 ], 0.309109, 1.271466);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 20 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 20 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 20 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 20 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 20 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 20 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 20 ], 1);

		UGRegisterTD[playerid][ 21 ] = CreatePlayerTextDraw(playerid, 309.222412, 9.471109, "]");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 21 ], 0.309109, 1.271466);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 21 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 21 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 21 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 21 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 21 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 21 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 21 ], 1);

		UGRegisterTD[playerid][ 22 ] = CreatePlayerTextDraw(playerid, 64.444473, 86.115554, "Nova Era");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 22 ], 0.411776, 1.311287);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 22 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 22 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 22 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 22 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 22 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 22 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 22 ], 1);

		UGRegisterTD[playerid][ 23 ] = CreatePlayerTextDraw(playerid, 519.222167, 84.128883, "RolePlay");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 23 ], 0.374444, 1.430755);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 23 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 23 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 23 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 23 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 23 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 23 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 23 ], 1);

		UGRegisterTD[playerid][ 24 ] = CreatePlayerTextDraw(playerid, 242.222045, 88.604484, "Nova Era: ONLINE GAMING Community");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 24 ], 0.166444, 1.196799);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 24 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 24 ], tdboja);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 24 ], 1);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 24 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 24 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 24 ], 2);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 24 ], 1);

		UGRegisterTD[playerid][ 25 ] = CreatePlayerTextDraw(playerid, 139.777770, 369.855468, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 25 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 25 ], 46.444412, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 25 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 25 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 25 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 25 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 25 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 25 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 25 ], 0);

		UGRegisterTD[playerid][ 26 ] = CreatePlayerTextDraw(playerid, 140.333328, 394.748779, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 26 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 26 ], 45.999961, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 26 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 26 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 26 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 26 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 26 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 26 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 26 ], 0);

		UGRegisterTD[playerid][ 27 ] = CreatePlayerTextDraw(playerid, 140.888885, 420.637634, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 27 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 27 ], 45.555519, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 27 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 27 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 27 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 27 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 27 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 27 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 27 ], 0);

		UGRegisterTD[playerid][ 28 ] = CreatePlayerTextDraw(playerid, 586.777648, 370.366577, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 28 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 28 ], 490.444458, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 28 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 28 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 28 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 28 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 28 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 28 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 28 ], 0);

		UGRegisterTD[playerid][ 29 ] = CreatePlayerTextDraw(playerid, 587.777648, 395.757659, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 29 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 29 ], 490.444519, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 29 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 29 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 29 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 29 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 29 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 29 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 29 ], 0);

		UGRegisterTD[playerid][ 30 ] = CreatePlayerTextDraw(playerid, 588.333190, 420.651031, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 30 ], 0.000000, 1.619135);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 30 ], 490.000091, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 30 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 30 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 30 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 30 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 30 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 30 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 30 ], 0);

		UGRegisterTD[playerid][ 31 ] = CreatePlayerTextDraw(playerid, 369.333435, 394.273254, "usebox");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 31 ], 0.000000, 2.552469);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 31 ], 262.000122, 0.000000);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 31 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 31 ], tdboja);
		PlayerTextDrawUseBox(playerid, UGRegisterTD[playerid][ 31 ], true);
		PlayerTextDrawBoxColor(playerid, UGRegisterTD[playerid][ 31 ], 102);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 31 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 31 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 31 ], 0);

		UGRegisterTD[playerid][ 32 ] = CreatePlayerTextDraw(playerid, 247.222442, 413.657775, "LD_POOL:ball");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 32 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 32 ], 13.333312, -14.435556);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 32 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 32 ], 4416767);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 32 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 32 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 32 ], 4);

		UGRegisterTD[playerid][ 33 ] = CreatePlayerTextDraw(playerid, 369.111206, 413.164459, "LD_POOL:ball");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 33 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, UGRegisterTD[playerid][ 33 ], 13.333312, -14.435556);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 33 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 33 ], 4416767);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 33 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 33 ], 0);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 33 ], 4);

		UGRegisterTD[playerid][ 34 ] = CreatePlayerTextDraw(playerid, 243.555511, 431.573364, "Dobrodosli na Nova Era - uzivajte u igranju!");
		PlayerTextDrawLetterSize(playerid, UGRegisterTD[playerid][ 34 ], 0.282444, 1.097244);
		PlayerTextDrawAlignment(playerid, UGRegisterTD[playerid][ 34 ], 1);
		PlayerTextDrawColor(playerid, UGRegisterTD[playerid][ 34 ], -1);
		PlayerTextDrawSetShadow(playerid, UGRegisterTD[playerid][ 34 ], 0);
		PlayerTextDrawSetOutline(playerid, UGRegisterTD[playerid][ 34 ], 1);
		PlayerTextDrawBackgroundColor(playerid, UGRegisterTD[playerid][ 34 ], 51);
		PlayerTextDrawFont(playerid, UGRegisterTD[playerid][ 34 ], 0);
		PlayerTextDrawSetProportional(playerid, UGRegisterTD[playerid][ 34 ], 1);



		//_____________________________[ CLICKABLE DIO I OSTALO ]____________________

		Regtd21[playerid] = CreatePlayerTextDraw(playerid, 92.88, 371.83, "LOZINKA");
		PlayerTextDrawLetterSize(playerid, Regtd21[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd21[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd21[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd21[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd21[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd21[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd21[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd21[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd21[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd21[playerid], true);

		Regtd24[playerid] = CreatePlayerTextDraw(playerid, 539.666687, 372.342102, "DRZAVA");
		PlayerTextDrawLetterSize(playerid, Regtd24[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd24[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd24[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd24[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd24[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd24[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd24[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd24[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd24[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd24[playerid], true);

		Regtd23[playerid] = CreatePlayerTextDraw(playerid, 91.99, 422.63, "POL");
		PlayerTextDrawLetterSize(playerid, Regtd23[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd23[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd23[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd23[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd23[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd23[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd23[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd23[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd23[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd23[playerid], true);

		Regtd22[playerid] = CreatePlayerTextDraw(playerid, 92.99, 397.24, "GODINE");
		PlayerTextDrawLetterSize(playerid, Regtd22[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd22[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd22[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd22[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd22[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd22[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd22[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd22[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd22[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd22[playerid], true);

		Regtd26[playerid] = CreatePlayerTextDraw(playerid, 540.333251, 422.128723, "SKIN");
		PlayerTextDrawLetterSize(playerid, Regtd26[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd26[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd26[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd26[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd26[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd26[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd26[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd26[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd26[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd26[playerid], true);

		Regtd25[playerid] = CreatePlayerTextDraw(playerid, 540.222229, 398.230926, "E-MAIL");
		PlayerTextDrawLetterSize(playerid, Regtd25[playerid], 0.222444, 1.052444);
		PlayerTextDrawTextSize(playerid, Regtd25[playerid], 15, 40);
		PlayerTextDrawAlignment(playerid, Regtd25[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd25[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd25[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd25[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd25[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd25[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd25[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd25[playerid], true);

		Regtd28[playerid] = CreatePlayerTextDraw(playerid, 315.555511, 398.222137, "REGISTER");
		PlayerTextDrawLetterSize(playerid, Regtd28[playerid], 0.339333, 1.510400);
		PlayerTextDrawTextSize(playerid, Regtd28[playerid], 15, 80);
		PlayerTextDrawAlignment(playerid, Regtd28[playerid], 2);
		PlayerTextDrawColor(playerid, Regtd28[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd28[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd28[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd28[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd28[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd28[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], true);
		
		RegisterTD[ playerid ][ 7 ]  = CreatePlayerTextDraw(playerid, 279.110992, 222.008941, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, RegisterTD[ playerid ][ 7 ] , 0.000000, -0.577777);
		PlayerTextDrawTextSize(playerid, RegisterTD[ playerid ][ 7 ] , 65.777809, 101.048873);
		PlayerTextDrawAlignment(playerid, RegisterTD[ playerid ][ 7 ] , 2);
		PlayerTextDrawColor(playerid, RegisterTD[ playerid ][ 7 ] , -1);
		PlayerTextDrawUseBox(playerid, RegisterTD[ playerid ][ 7 ] , true);
		PlayerTextDrawBoxColor(playerid, RegisterTD[ playerid ][ 7 ] , 0);
		PlayerTextDrawSetShadow(playerid, RegisterTD[ playerid ][ 7 ] , 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[ playerid ][ 7 ] , 0);
		PlayerTextDrawBackgroundColor(playerid,RegisterTD[ playerid ][ 7 ], 0);
		PlayerTextDrawFont(playerid, RegisterTD[ playerid ][ 7 ] , 5);
		PlayerTextDrawSetPreviewModel(playerid, RegisterTD[ playerid ][ 7 ], 26);
		PlayerTextDrawSetPreviewRot(playerid, RegisterTD[ playerid ][ 7 ], 0.000000, 0.000000, 20.000000, 1.000000);
		

		RegisterTD[ playerid ][ 9 ] = CreatePlayerTextDraw(playerid, 366.222290, 340.480010, "ld_beat:right");
		PlayerTextDrawLetterSize(playerid, RegisterTD[ playerid ][ 9 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, RegisterTD[ playerid ][ 9 ], 19.555553, 9.955553);
		PlayerTextDrawAlignment(playerid, RegisterTD[ playerid ][ 9 ], 1);
		PlayerTextDrawColor(playerid, RegisterTD[ playerid ][ 9 ], -1);
		PlayerTextDrawSetShadow(playerid, RegisterTD[ playerid ][ 9 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[ playerid ][ 9 ], 0);
		PlayerTextDrawFont(playerid, RegisterTD[ playerid ][ 9 ], 4);
		PlayerTextDrawSetSelectable(playerid, RegisterTD[ playerid ][ 9 ], true);

		RegisterTD[ playerid ][ 10 ] = CreatePlayerTextDraw(playerid, 244.555694, 340.982269, "ld_beat:left");
		PlayerTextDrawLetterSize(playerid, RegisterTD[ playerid ][ 10 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, RegisterTD[ playerid ][ 10 ], 19.555553, 9.955553);
		PlayerTextDrawAlignment(playerid, RegisterTD[ playerid ][ 10 ], 1);
		PlayerTextDrawColor(playerid, RegisterTD[ playerid ][ 10 ], -1);
		PlayerTextDrawSetShadow(playerid, RegisterTD[ playerid ][ 10 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[ playerid ][ 10 ], 0);
		PlayerTextDrawFont(playerid, RegisterTD[ playerid ][ 10 ], 4);
		PlayerTextDrawSetSelectable(playerid, RegisterTD[ playerid ][ 10 ], true);

		RegisterTD[ playerid ][ 11 ] = CreatePlayerTextDraw(playerid, 315.555480, 339.982208, "ODABERI");
		PlayerTextDrawLetterSize(playerid, RegisterTD[ playerid ][ 11 ], 0.279778, 1.027554);
		PlayerTextDrawTextSize(playerid, RegisterTD[ playerid ][ 11 ], 15, 40);
		PlayerTextDrawAlignment(playerid, RegisterTD[ playerid ][ 11 ], 2);
		PlayerTextDrawColor(playerid, RegisterTD[ playerid ][ 11 ], -1);
		PlayerTextDrawSetShadow(playerid, RegisterTD[ playerid ][ 11 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[ playerid ][ 11 ], 1);
		PlayerTextDrawBackgroundColor(playerid, RegisterTD[ playerid ][ 11 ], 51);
		PlayerTextDrawFont(playerid, RegisterTD[ playerid ][ 11 ], 2);
		PlayerTextDrawSetProportional(playerid, RegisterTD[ playerid ][ 11 ], 1);
		PlayerTextDrawSetSelectable(playerid, RegisterTD[ playerid ][ 11 ], true);
		
		RegisterTD[playerid][ 12 ] = CreatePlayerTextDraw(playerid, 390.445190, 338.495391, "usebox");//boxovi za bug na registeru
		PlayerTextDrawLetterSize(playerid, RegisterTD[playerid][ 12 ], 0.000000, 1.431483);
		PlayerTextDrawTextSize(playerid, RegisterTD[playerid][ 12 ], 238.444396, 0.000000);
		PlayerTextDrawAlignment(playerid, RegisterTD[playerid][ 12 ], 1);
		PlayerTextDrawColor(playerid, RegisterTD[playerid][ 12 ], 0);
		PlayerTextDrawUseBox(playerid, RegisterTD[playerid][ 12 ], true);
		PlayerTextDrawBoxColor(playerid, RegisterTD[playerid][ 12 ], 102);
		PlayerTextDrawSetShadow(playerid, RegisterTD[playerid][ 12 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[playerid][ 12 ], 0);
		PlayerTextDrawFont(playerid, RegisterTD[playerid][ 12 ], 0);

		RegisterTD[playerid][ 13 ] = CreatePlayerTextDraw(playerid, 367.333129, 323.064361, "usebox");
		PlayerTextDrawLetterSize(playerid, RegisterTD[playerid][ 13 ], 0.000000, 1.010738);
		PlayerTextDrawTextSize(playerid, RegisterTD[playerid][ 13 ], 258.888702, 0.000000);
		PlayerTextDrawAlignment(playerid, RegisterTD[playerid][ 13 ], 1);
		PlayerTextDrawColor(playerid, RegisterTD[playerid][ 13 ], 0);
		PlayerTextDrawUseBox(playerid, RegisterTD[playerid][ 13 ], true);
		PlayerTextDrawBoxColor(playerid, RegisterTD[playerid][ 13 ], 102);
		PlayerTextDrawSetShadow(playerid, RegisterTD[playerid][ 13 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[playerid][ 13 ], 0);
		PlayerTextDrawFont(playerid, RegisterTD[playerid][ 13 ], 0);
		
		RegisterTD[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid, 314.666687, 322.062286, "JEBEN COVJEK");//da nebi bio ispod boxa
		PlayerTextDrawLetterSize(playerid, RegisterTD[ playerid ][ 8 ], 0.174444, 1.092267);
		PlayerTextDrawAlignment(playerid, RegisterTD[ playerid ][ 8 ], 2);
		PlayerTextDrawColor(playerid, RegisterTD[ playerid ][ 8 ], -1);
		PlayerTextDrawSetShadow(playerid, RegisterTD[ playerid ][ 8 ], 0);
		PlayerTextDrawSetOutline(playerid, RegisterTD[ playerid ][ 8 ], 1);
		PlayerTextDrawBackgroundColor(playerid, RegisterTD[ playerid ][ 8 ], 51);
		PlayerTextDrawFont(playerid, RegisterTD[ playerid ][ 8 ], 2);
		PlayerTextDrawSetProportional(playerid, RegisterTD[ playerid ][ 8 ], 1);


		for( new i = 0; i < 7; i ++) {//counting ok
			PlayerTextDrawShow( playerid, RegisterTD[ playerid ][ i ] );
		}
		

		for( new i = 0; i < 35; i ++)
		{//counting ok
			PlayerTextDrawShow( playerid, UGRegisterTD[ playerid ][ i ] );
		}*/
//------------------------------------------------------------------------------
stock RegisterTDControl( playerid, bool:show ) 
{
	if(show == true) 
	{
		Regtd0[playerid] = CreatePlayerTextDraw(playerid, 641.555541, 51.277778, "usebox");
		PlayerTextDrawLetterSize(playerid, Regtd0[playerid], 0.000000, 6.873456);
		PlayerTextDrawTextSize(playerid, Regtd0[playerid], -2.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, Regtd0[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd0[playerid], 0);
		PlayerTextDrawUseBox(playerid, Regtd0[playerid], true);
		PlayerTextDrawBoxColor(playerid, Regtd0[playerid], 102);
		PlayerTextDrawSetShadow(playerid, Regtd0[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd0[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd0[playerid], 0);

		Regtd1[playerid] = CreatePlayerTextDraw(playerid, 424.888824, 11.946656, "LD_BEAT:CHIT");
		PlayerTextDrawLetterSize(playerid, Regtd1[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd1[playerid], 137.333312, 132.408905);
		PlayerTextDrawAlignment(playerid, Regtd1[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd1[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd1[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd1[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd1[playerid], 4);

		Regtd2[playerid] = CreatePlayerTextDraw(playerid, 436.888793, 24.888889, "LD_BEAT:CHIT");
		PlayerTextDrawLetterSize(playerid, Regtd2[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd2[playerid], 113.777664, 106.026641);
		PlayerTextDrawAlignment(playerid, Regtd2[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd2[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd2[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd2[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd2[playerid], 4);
/*
		Regtd3[playerid] = CreatePlayerTextDraw(playerid, 466.222167, 43.306686, "NE");
		PlayerTextDrawLetterSize(playerid, Regtd3[playerid], 1.480666, 6.732088);
		PlayerTextDrawAlignment(playerid, Regtd3[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd3[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd3[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd3[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd3[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd3[playerid], 3);
		PlayerTextDrawSetProportional(playerid, Regtd3[playerid], 1);

		*/
		Regtd3[playerid] = CreatePlayerTextDraw(playerid, 462.222229, 30.862340, "N");
		PlayerTextDrawLetterSize(playerid, Regtd3[playerid], 2.316664, 9.176181);
		PlayerTextDrawAlignment(playerid, Regtd3[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd3[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd3[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd3[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd3[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd3[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd3[playerid], 1);

		Regtd4[playerid] = CreatePlayerTextDraw(playerid, -2.666171, 51.768917, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd4[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd4[playerid], 470.222534, -2.488882);
		PlayerTextDrawAlignment(playerid, Regtd4[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd4[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd4[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd4[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd4[playerid], 4);

		Regtd5[playerid] = CreatePlayerTextDraw(playerid, 508.444061, 112.497741, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd5[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd5[playerid], 146.666564, 2.488912);
		PlayerTextDrawAlignment(playerid, Regtd5[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd5[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd5[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd5[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd5[playerid], 4);

		Regtd6[playerid] = CreatePlayerTextDraw(playerid, 332.444519, 24.391122, "Nova Era");
		PlayerTextDrawLetterSize(playerid, Regtd6[playerid], 0.909111, 4.681244);
		PlayerTextDrawAlignment(playerid, Regtd6[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd6[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd6[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd6[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd6[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd6[playerid], 0);
		PlayerTextDrawSetProportional(playerid, Regtd6[playerid], 1);

		Regtd7[playerid] = CreatePlayerTextDraw(playerid, 336.444488, 68.693275, "Online Gaming Community");
		PlayerTextDrawLetterSize(playerid, Regtd7[playerid], 0.189999, 1.390933);
		PlayerTextDrawAlignment(playerid, Regtd7[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd7[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd7[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd7[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd7[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd7[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd7[playerid], 1);

		Regtd8[playerid] = CreatePlayerTextDraw(playerid, 306.666625, 69.191146, "LD_BEAT:CHIT");
		PlayerTextDrawLetterSize(playerid, Regtd8[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd8[playerid], 169.333419, -1.991102);
		PlayerTextDrawAlignment(playerid, Regtd8[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd8[playerid], -1061109505);
		PlayerTextDrawSetShadow(playerid, Regtd8[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd8[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd8[playerid], 4);

		Regtd9[playerid] = CreatePlayerTextDraw(playerid, 369.777801, 87.111076, "presents...");
		PlayerTextDrawLetterSize(playerid, Regtd9[playerid], 0.449999, 1.600000);
		PlayerTextDrawAlignment(playerid, Regtd9[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd9[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd9[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd9[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd9[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd9[playerid], 0);
		PlayerTextDrawSetProportional(playerid, Regtd9[playerid], 1);

		Regtd10[playerid] = CreatePlayerTextDraw(playerid, 284.222229, 116.486663, "usebox");
		PlayerTextDrawLetterSize(playerid, Regtd10[playerid], 0.000000, 27.835433);
		PlayerTextDrawTextSize(playerid, Regtd10[playerid], 149.555557, 0.000000);
		PlayerTextDrawAlignment(playerid, Regtd10[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd10[playerid], 0);
		PlayerTextDrawUseBox(playerid, Regtd10[playerid], true);
		PlayerTextDrawBoxColor(playerid, Regtd10[playerid], 102);
		PlayerTextDrawSetShadow(playerid, Regtd10[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd10[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd10[playerid], 0);

		Regtd11[playerid] = CreatePlayerTextDraw(playerid, 149.333389, 96.071105, "Nova Era");
		PlayerTextDrawLetterSize(playerid, Regtd11[playerid], 0.682888, 2.545777);
		PlayerTextDrawAlignment(playerid, Regtd11[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd11[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd11[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd11[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd11[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd11[playerid], 3);
		PlayerTextDrawSetProportional(playerid, Regtd11[playerid], 1);

		Regtd12[playerid] = CreatePlayerTextDraw(playerid, 122.222267, 115.484436, "LD_BEAT:CHIT");
		PlayerTextDrawLetterSize(playerid, Regtd12[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd12[playerid], 191.110961, 1.991115);
		PlayerTextDrawAlignment(playerid, Regtd12[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd12[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd12[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd12[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd12[playerid], 4);

		Regtd13[playerid] = CreatePlayerTextDraw(playerid, 236.444519, 110.008842, "RolePlay");
		PlayerTextDrawLetterSize(playerid, Regtd13[playerid], 0.449999, 1.600000);
		PlayerTextDrawAlignment(playerid, Regtd13[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd13[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd13[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd13[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd13[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd13[playerid], 0);
		PlayerTextDrawSetProportional(playerid, Regtd13[playerid], 1);

		Regtd14[playerid] = CreatePlayerTextDraw(playerid, 164.000000, 133.404556, "Zapocnite sa registracijom tako~n~ sto cete stisnuti na 'Lozinka'...");
		PlayerTextDrawLetterSize(playerid, Regtd14[playerid], 0.132222, 1.231644);
		PlayerTextDrawAlignment(playerid, Regtd14[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd14[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd14[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd14[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd14[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd14[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd14[playerid], 1);

		Regtd15[playerid] = CreatePlayerTextDraw(playerid, 175.999984, 172.728897, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd15[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd15[playerid], 80.888916, 20.408905);
		PlayerTextDrawAlignment(playerid, Regtd15[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd15[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd15[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd15[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd15[playerid], 4);

		Regtd16[playerid] = CreatePlayerTextDraw(playerid, 175.555557, 194.631118, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd16[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd16[playerid], 80.888870, 19.911102);
		PlayerTextDrawAlignment(playerid, Regtd16[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd16[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd16[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd16[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd16[playerid], 4);

		Regtd17[playerid] = CreatePlayerTextDraw(playerid, 176.444427, 215.537780, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd17[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd17[playerid], 80.000000, 21.404434);
		PlayerTextDrawAlignment(playerid, Regtd17[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd17[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd17[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd17[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd17[playerid], 4);

		Regtd18[playerid] = CreatePlayerTextDraw(playerid, 176.888885, 237.937805, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd18[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd18[playerid], 79.999992, 22.897766);
		PlayerTextDrawAlignment(playerid, Regtd18[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd18[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd18[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd18[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd18[playerid], 4);

		Regtd19[playerid] = CreatePlayerTextDraw(playerid, 176.444488, 261.830993, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd19[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd19[playerid], 80.888839, 20.906698);
		PlayerTextDrawAlignment(playerid, Regtd19[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd19[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd19[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd19[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd19[playerid], 4);

		Regtd20[playerid] = CreatePlayerTextDraw(playerid, 176.444458, 283.733276, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, Regtd20[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd20[playerid], 80.444427, 22.399997);
		PlayerTextDrawAlignment(playerid, Regtd20[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd20[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd20[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd20[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd20[playerid], 4);

		Regtd21[playerid] = CreatePlayerTextDraw(playerid, 183.555526, 175.217819, "Lozinka");
		PlayerTextDrawLetterSize(playerid, Regtd21[playerid], 0.352666, 1.336177);
		PlayerTextDrawAlignment(playerid, Regtd21[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd21[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd21[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd21[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd21[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd21[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd21[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd21[playerid], true);

		Regtd22[playerid] = CreatePlayerTextDraw(playerid, 185.333343, 198.613327, "Godine");
		PlayerTextDrawLetterSize(playerid, Regtd22[playerid], 0.384222, 1.236621);
		PlayerTextDrawAlignment(playerid, Regtd22[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd22[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd22[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd22[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd22[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd22[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd22[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd22[playerid], true);

		Regtd23[playerid] = CreatePlayerTextDraw(playerid, 195.111099, 219.022232, "Spol");
		PlayerTextDrawLetterSize(playerid, Regtd23[playerid], 0.381555, 1.440711);
		PlayerTextDrawAlignment(playerid, Regtd23[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd23[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd23[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd23[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd23[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd23[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd23[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd23[playerid], true);

		Regtd24[playerid] = CreatePlayerTextDraw(playerid, 184.444473, 243.413330, "Drzava");
		PlayerTextDrawLetterSize(playerid, Regtd24[playerid], 0.368222, 1.261511);
		PlayerTextDrawAlignment(playerid, Regtd24[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd24[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd24[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd24[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd24[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd24[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd24[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd24[playerid], true);

		Regtd25[playerid] = CreatePlayerTextDraw(playerid, 185.777816, 264.817779, "E-posta");
		PlayerTextDrawLetterSize(playerid, Regtd25[playerid], 0.368666, 1.405866);
		PlayerTextDrawAlignment(playerid, Regtd25[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd25[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd25[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd25[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd25[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd25[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd25[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd25[playerid], true);

		Regtd26[playerid] = CreatePlayerTextDraw(playerid, 187.555511, 284.728912, "Odjeca");
		PlayerTextDrawLetterSize(playerid, Regtd26[playerid], 0.341555, 1.530310);
		PlayerTextDrawAlignment(playerid, Regtd26[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd26[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Regtd26[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd26[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd26[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd26[playerid], 2);
		PlayerTextDrawSetProportional(playerid, Regtd26[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd26[playerid], true);

		Regtd27[playerid] = CreatePlayerTextDraw(playerid, 163.111083, 321.564361, "LD_BEAT:CHIT");
		PlayerTextDrawLetterSize(playerid, Regtd27[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Regtd27[playerid], 100.888763, 31.359981);
		PlayerTextDrawAlignment(playerid, Regtd27[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd27[playerid], -2139062017);
		PlayerTextDrawSetShadow(playerid, Regtd27[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd27[playerid], 0);
		PlayerTextDrawFont(playerid, Regtd27[playerid], 4);

		Regtd28[playerid] = CreatePlayerTextDraw(playerid, 184.888900, 326.542205, "registracija");
		PlayerTextDrawLetterSize(playerid, Regtd28[playerid], 0.449999, 1.600000);
		PlayerTextDrawAlignment(playerid, Regtd28[playerid], 1);
		PlayerTextDrawColor(playerid, Regtd28[playerid], tdboja);
		PlayerTextDrawSetShadow(playerid, Regtd28[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Regtd28[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Regtd28[playerid], 51);
		PlayerTextDrawFont(playerid, Regtd28[playerid], 0);
		PlayerTextDrawSetProportional(playerid, Regtd28[playerid], 1);
		PlayerTextDrawSetSelectable(playerid, Regtd28[playerid], true);

		showrtd(playerid);

		ShowedRegister[ playerid ] = true;

	}
	else if( show == false ) 
	{
	

		hidertd(playerid);
		ShowedRegister[ playerid ] = false;

	}
}
//------------------------------------------------------------------------------
stock Boombox_Place( playerid ) {
	static
		Float:angle;

	GetPlayerFacingAngle(playerid, angle);

	strpack(BoomboxInfo[ playerid ][boomboxURL], "", 128 char);
	GetPlayerPos(playerid, BoomboxInfo[ playerid ][ boomboxPos ][ 0], BoomboxInfo[ playerid ][ boomboxPos ][ 1], BoomboxInfo[ playerid ][ boomboxPos ][ 2] );

	BoomboxInfo[ playerid ][boomboxPlaced] = true;
	BoomboxInfo[ playerid ][boomboxInterior] = GetPlayerInterior(playerid);
	BoomboxInfo[ playerid ][boomboxWorld] = GetPlayerVirtualWorld(playerid);
	new string[ 128 ];
	format( string, sizeof( string ), "Vlasnik: %s\nKoristi '/radio url' da postavis pesmu\n'/radio podigni' da podignes svoj radio", ImeIgraca( playerid ) );

	BoomboxInfo[ playerid ][boomboxObject] = CreateDynamicObject(2103, BoomboxInfo[ playerid ][ boomboxPos ][ 0], BoomboxInfo[ playerid ][ boomboxPos ][ 1], BoomboxInfo[ playerid ][ boomboxPos ][ 2] - 0.9, 0.0, 0.0, angle, BoomboxInfo[ playerid ][boomboxWorld], BoomboxInfo[ playerid ][boomboxInterior] );
	BoomboxInfo[ playerid ][boomboxText3D] = CreateDynamic3DTextLabel( string, -1, BoomboxInfo[ playerid ][ boomboxPos ][ 0], BoomboxInfo[ playerid ][ boomboxPos ][ 1], BoomboxInfo[ playerid ][ boomboxPos ][ 2] - 0.7, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BoomboxInfo[ playerid ][boomboxWorld], BoomboxInfo[ playerid ][boomboxInterior] );

	return 1;
}

stock Boombox_Nearest(playerid)
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && BoomboxInfo[ i ][boomboxPlaced] && 
		GetPlayerInterior(playerid) == BoomboxInfo[ i ][boomboxInterior] && 
		GetPlayerVirtualWorld(playerid) == BoomboxInfo[ i ][boomboxWorld] && 
		IsPlayerInRangeOfPoint(playerid, 30.0, 
			BoomboxInfo[ i ][boomboxPos][ 0 ], BoomboxInfo[ i ][boomboxPos][ 1 ], BoomboxInfo[ i ][boomboxPos][2 ] ) ) 
		{
			return i;
		}
	}
	return INVALID_PLAYER_ID;
}

stock Boombox_SetURL(playerid, url[])
{
	if( BoomboxInfo[ playerid ][ boomboxPlaced ] ) {
		strpack( BoomboxInfo[ playerid ][ boomboxURL ], url, 256 char);

		for(new i; i < MAX_PLAYERS; i++) if(Boombox[ i ] == playerid) {
			
			StopAudioStreamForPlayer(i);
			PlayAudioStreamForPlayer(i, url, BoomboxInfo[ playerid ][ boomboxPos ][ 0], BoomboxInfo[ playerid ][ boomboxPos ][ 1], BoomboxInfo[ playerid ][ boomboxPos ][ 2], 30.0, 1);
		}
	}
	return 1;
}

stock Boombox_Destroy(playerid)
{
	if(BoomboxInfo[ playerid ][boomboxPlaced])
	{
		if( IsValidDynamicObject(BoomboxInfo[ playerid ][boomboxObject ] ) )
			DestroyDynamicObject(BoomboxInfo[ playerid ][boomboxObject] );

		if( IsValidDynamic3DTextLabel(BoomboxInfo[ playerid ][boomboxText3D ] ) )
			DestroyDynamic3DTextLabel(BoomboxInfo[ playerid ][boomboxText3D] );

		for(new i; i < MAX_PLAYERS; i++)
		if(IsPlayerConnected(i) && Boombox[ i ] == playerid) 
		{
			StopAudioStreamForPlayer(i);
		}
		BoomboxInfo[ playerid ][boomboxPlaced] = false;
		BoomboxInfo[ playerid ][boomboxInterior] = 0;
		BoomboxInfo[ playerid ][boomboxWorld] = 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
stock LogSave( gde[], string[]) {

	new entry[ 128 ], s, m, se, day, year, month;
	getdate( year, month, day );
	gettimeEx( s, m, se );
	FixHour( s );
	s = shifthour;
	
	format( entry, sizeof( entry ), "%d/%d/%d | %d/%d/%d | %s\r\n", day, month, year, s, m, se, string );
	new File:hFile;
	hFile = fopen( gde, io_append );
	fwrite( hFile, entry ); // LINE 48202
	fclose( hFile );
}
//------------------------------------------------------------------------------
stock GetZoneName(Float:x, Float:y, zone[], len) {

	for( new i = 0; i != sizeof(gSAZones); i++ )
	{
		if(x >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock escape(text[])
{
	new
		ret[MAX_INI_ENTRY_TEXT * 2],
		ch,
		i,
		j;
	while ((ch = text[i++]) && j < sizeof (ret))
	{
		if(ch == '\'')
		{
			if(j < sizeof (ret) - 2)
			{
				ret[j++] = '\'';
				ret[j++] = '\'';
			}
		}
		else if(j < sizeof (ret))
		{
			ret[j++] = ch;
		}
		else
		{
			j++;
		}
	}
	ret[sizeof (ret) - 1] = '\0';
	return ret;
}

stock Float:PointAngle(playerid, Float:xa, Float:ya, Float:xb, Float:yb)
{
	new Float:carangle;
	new Float:xc, Float:yc;
	new Float:angle;
	xc = floatabs(floatsub(xa,xb));
	yc = floatabs(floatsub(ya,yb));
	if(yc == 0.0 || xc == 0.0)
	{
		if(yc == 0 && xc > 0) angle = 0.0;
		else if(yc == 0 && xc < 0) angle = 180.0;
		else if(yc > 0 && xc == 0) angle = 90.0;
		else if(yc < 0 && xc == 0) angle = 270.0;
		else if(yc == 0 && xc == 0) angle = 0.0;
	}
	else
	{
		angle = atan(xc/yc);
		if(xb > xa && yb <= ya) angle += 90.0;
		else if(xb <= xa && yb < ya) angle = floatsub(90.0, angle);
		else if(xb < xa && yb >= ya) angle -= 90.0;
		else if(xb >= xa && yb > ya) angle = floatsub(270.0, angle);
	}
	GetVehicleZAngle(GetPlayerVehicleID(playerid), carangle);
	return floatadd(angle, -carangle);
}

stock setPlayerGps(playerid, Float:x, Float:y, Float:z) {
	if(PlayerInfo[ playerid ][xGpsLevel] >= 1) {
		if( IsValidDynamicMapIcon(PlayerGpsRadar[ playerid ][_pgrIconId ] ) ) {
			DestroyDynamicMapIcon(PlayerGpsRadar[ playerid ][_pgrIconId] );
		}

		PlayerGpsRadar[ playerid ][ _pgrPos ][ 0 ] = x;
		PlayerGpsRadar[ playerid ][ _pgrPos ][ 1 ] = y;
		PlayerGpsRadar[ playerid ][ _pgrPos ][ 2 ] = z;
		PlayerGpsRadar[ playerid ][ _pgrIconId ] = CreateDynamicMapIcon(x, y, z, 0, CRVENA, -1, -1, playerid, 6000.0, MAPICON_GLOBAL);

		SetTimerEx("UpdatePlayerGps", 100, false, "dd", playerid, 1);
		if( PlayerInfo[ playerid ][ xGpsLevel ] >= 3) {
			if( IsPlayerInAnyVehicle( playerid ) ) {

				if( IsValidDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] ) ) {
					DestroyDynamicObject( PlayerGpsRadar[ playerid ][ _pgrObject ] );
				}

				new Float:VPos[ 3 ], Float:Rotation;

				PlayerGpsRadar[ playerid ][ _pgrObject ] = CreateDynamicObject(19133, 0, 0, 1100, 0.0, 0.0, 0.0);

				GetVehiclePos( GetPlayerVehicleID( playerid ), VPos[ 0 ], VPos[ 1 ], VPos[ 2 ] );
				Rotation = PointAngle( playerid, VPos[ 0 ], VPos[ 1 ], x, y );
				AttachDynamicObjectToVehicle( PlayerGpsRadar[ playerid ][ _pgrObject ], GetPlayerVehicleID( playerid ), 0.0, 0.0, 1.5, 0.0, 90.0, Rotation );
			}
		}
	}
}
//------------------------------------------------------------------------------

CreateMapIcons( ) 
{
	printf("[NE:RP] - Nova Era | Ucitavanje sistema za map icone...");
	for( new i = 1;i < MAX_BUSSINES; i++ ) {
		if( BussinesInfo[ i ][ bType ] == VRSTA_BINCO || BussinesInfo[ i ][ bType ] == VRSTA_SUBURBAN || BussinesInfo[ i ][ bType ] == VRSTA_ZIP || BussinesInfo[ i ][ bType ] == VRSTA_VICTIM ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 45, BELA, -1, -1, -1, 300.0 );
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_BURG ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 10, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_CLUCK ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 14, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_PIZZA ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 29, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_GYM ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 54, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_GUNSHOP ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 6, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_BAR ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 49, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_RESTORAN ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 50, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_NKLUB || BussinesInfo[ i ][ bType ] == VRSTA_DISCO ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 48, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_MARKET ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 36, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_ELEKTRONIK ) {
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 23, BELA, -1, -1, -1, 300.0);
		}
		if( BussinesInfo[ i ][ bType ] == VRSTA_TRAFIKA )
		{
			CreateDynamicMapIcon( BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ], 42, BELA, -1, -1, -1, 300.0);
		}
	}

	// Police
	CreateDynamicMapIcon( 1555.500488, -1675.764160, 16.195312, 30, BELA, -1, -1, -1, 300.0);




	for( new i = 0; i < 7; i++ )
	{
		CreateDynamicMapIcon( RibarPosition[ i ][ 0 ], RibarPosition[ i ][ 1 ], RibarPosition[ i ][ 2 ], 9, BELA, -1, -1, -1, 300.0);
	}


	return 1;
}

//------------------------------------------------------------------------------
public NewsOn( ) {
	newsbre = 1;
}

public AddsOn( ) {
	adds = true;
}
//------------------------------------------------------------------------------
stock frename( oldname[], newname[] ) {
	if( !fexist( oldname ) ) return false;
	fremove( newname );
	if( !fcopy( oldname, newname ) ) return false;
	fremove( oldname );
	return true;
}
stock fcopy( oldname[], newname[] ) {
	new File:ohnd, File:nhnd;
	if( !fexist( oldname ) ) return false;
	ohnd=fopen( oldname, io_read );
	nhnd=fopen( newname, io_write );
	new buf2[ 1 ];
	new i;
	for( i=flength(ohnd);i>0;i-- ) {
		fputchar( nhnd, fgetchar( ohnd, buf2[ 0 ], false ), false );
	}
	fclose( ohnd );
	fclose( nhnd );
	return true;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
stock CreateRoadblock( Object,Float:x,Float:y,Float:z,Float:Angle ) {

	for( new i = 0; i < sizeof(Roadblocks); i++) {
	
		if( Roadblocks[ i ][ sCreated ] == 0 ) {
		
			Roadblocks[ i ][ sCreated ] = 1;
			Roadblocks[ i ][ sX ] = x;
			Roadblocks[ i ][ sY ] = y;
			Roadblocks[ i ][ sZ ] = z-0.7;
			Roadblocks[ i ][ sSpike ] = false;
			Roadblocks[ i ][ sObject ] = CreateDynamicObject( Object, x, y, z-0.9, 0, 0, Angle);
			return 1;
		}
	}
	return 1;
}

stock CreateSpike( Object,Float:x,Float:y,Float:z,Float:Angle ) {

	for( new i = 0; i < sizeof(Roadblocks); i++ ) {
	
		if( Roadblocks[ i ][ sCreated ] == 0 ) {
		
			Roadblocks[ i ][ sCreated ]=1;
			Roadblocks[ i ][ sX ]=x;
			Roadblocks[ i ][ sY ]=y;
			Roadblocks[ i ][ sZ ]=z-0.7;
			Roadblocks[ i ][ sSpike ] = true;
			Roadblocks[ i ][ sObject ] = CreateDynamicObject( Object, x, y, z-1, 0, 0, Angle-90);
			return 1;
		}
	}
	return 0;
}

stock DeleteAllRoadblocks( playerid )
{
	for( new i = 0; i < sizeof(Roadblocks); i++)
	{
		if( IsPlayerInRangeOfPoint( playerid, 100, Roadblocks[ i ][sX], Roadblocks[ i ][sY], Roadblocks[ i ][sZ ] ) )
		{
			if(Roadblocks[ i ][sCreated] == 1)
			{
				Roadblocks[ i ][sCreated] = 0;
				Roadblocks[ i ][sX] = 0.0;
				Roadblocks[ i ][sY] = 0.0;
				Roadblocks[ i ][sZ] = 0.0;
				Roadblocks[ i ][ sSpike ] = false;
				DestroyDynamicObject(Roadblocks[ i ][sObject] );
			}
		}
	}
	return 1;
}
stock DeleteClosestRoadblock( playerid )
{
	for( new i = 0; i < sizeof(Roadblocks); i++)
	{
		if( IsPlayerInRangeOfPoint( playerid, 5.0, Roadblocks[ i ][sX], Roadblocks[ i ][sY], Roadblocks[ i ][sZ ] ) )
		{
			if(Roadblocks[ i ][sCreated] == 1)
			{
				Roadblocks[ i ][sCreated] = 0;
				Roadblocks[ i ][sX] = 0.0;
				Roadblocks[ i ][sY] = 0.0;
				Roadblocks[ i ][sZ] = 0.0;
				Roadblocks[ i ][ sSpike ] = false;
				DestroyDynamicObject(Roadblocks[ i ][sObject] );
				return 1;
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock Dimi_SetPlayerWantedLevel( playerid, broj )
{
	switch( broj )
	{
		case 0:
		{
			PlayerTextDrawHide( playerid, WantedIgraca[ playerid ] );
			//HideWantedLevel(playerid);
			SetPlayerColor( playerid, 0xFFFFFF00 );
			DonatorBoja( playerid );
		}
		case 1:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 2:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 3:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 4:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 5:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 6:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 7:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 8:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 9:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
		case 10:
		{
			PlayerTextDrawSetString( playerid, WantedIgraca[ playerid ], "]]]]]]]]]]" );
			PlayerTextDrawShow( playerid, WantedIgraca[ playerid ] );
			SetPlayerColor( playerid, 0xAA333300 );
			//ShowWantedLevel(playerid);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock PostaviWanted( playerid, zlocin[], prijavio[], kolicina = 1 ) {
	if( IsPlayerConnected( playerid ) ) {
	
		new string[ 256 ];
		Dimi_SetPlayerWantedLevel( playerid, PlayerInfo[ playerid ][ xWanted ]+kolicina );
		PlayerInfo[ playerid ][ xWanted ] += kolicina;

		if( PlayerInfo[ playerid ][ xWanted ] > 10 ) {
			Dimi_SetPlayerWantedLevel( playerid, 10 );
			PlayerInfo[ playerid ][ xWanted ] = 10;
		}

		strmid( ZlocinInfo[ playerid ][ zPrijavio ], prijavio, 0, strlen(prijavio), 255);
		strmid( ZlocinInfo[ playerid ][ zPocinio ], ImeIgraca( playerid ), 0, strlen( ImeIgraca( playerid ) ), 255);
		strmid( ZlocinInfo[ playerid ][ zZlocin ], zlocin, 0, strlen(zlocin), 255);

		format( string, sizeof( string ), ""col_balkanstory"- Pocinili ste zlocin: "col_white"%s "col_balkanstory"| Prijava od: "col_white"%s!", zlocin, prijavio );
		SendClientMessagee( playerid, -1, string);
		format( string, sizeof( string ), ""col_balkanstory"- Trenutni Wanted Level: "col_white"%d!", PlayerInfo[ playerid ][ xWanted ] );
		SendClientMessagee( playerid, -1, string);

		for( new id = 1; id < MAX_ORG; id++) {
			if( OI[ id ][ oTip ] == ORG_TIP_PD ) {
				format( string, sizeof( string ), ""col_balkanstory"- Imamo novi prijavljen zlocin od: "col_white"%s!", prijavio);
				OrgPoruka( id, -1, string);
				format( string, sizeof( string ), ""col_balkanstory"- Pocinio: "col_white"%s "col_balkanstory"| Zlocin: "col_white"%s "col_balkanstory"| Wanted Level Pocinioca: %d!", ImeIgraca( playerid ), zlocin, PlayerInfo[ playerid ][ xWanted ] );
				OrgPoruka( id, -1, string);
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
stock Igrac2D( playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos( playerid, x, y, z);
	for( new i = 0; i != sizeof(gSAZones); i++ )
	{
		if(x >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock GetPlayerLocation( playerid )
{
	new imeulice[MAX_ZONE_NAME];
	Igrac2D( playerid,imeulice,sizeof(imeulice));
	return imeulice;
}
//ZA ULICE
stock streetloc( streetdbid,zone[], len)
{
	//new Float:x, Float:y, Float:z;
	//GetPlayerPos( playerid, x, y, z);
	for( new i = 0; i != sizeof(gSAZones); i++ )
	{
		if(streetInfo[streetdbid][streetObjPos][0] >= gSAZones[ i ][SAZONE_AREA][ 0 ] && streetInfo[streetdbid][streetObjPos][0] <= gSAZones[ i ][SAZONE_AREA][ 3 ] && streetInfo[streetdbid][streetObjPos][1] >= gSAZones[ i ][SAZONE_AREA][ 1 ] && streetInfo[streetdbid][streetObjPos][1] <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock GetStreetLocation( streetid )
{
	new imeulice[MAX_ZONE_NAME];
	streetloc( streetid, imeulice,sizeof(imeulice));
	return imeulice;
}
////////////////////////////////////////////////////////////////////////////////

stock Igrac2D11( playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos( playerid, x, y, z);
	for( new i = 0; i != sizeof(gSAZones11); i++ )
	{
		if(x >= gSAZones11[ i ][SAZONE_AREA11][ 0 ] && x <= gSAZones11[ i ][SAZONE_AREA11][ 3 ] && y >= gSAZones11[ i ][SAZONE_AREA11][ 1 ] && y <= gSAZones11[ i ][SAZONE_AREA11][4])
		{
			return format(zone, len, gSAZones11[ i ][SAZONE_NAME11], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock GetPlayerLocation11( playerid )
{
	new imeulice[MAX_ZONE_NAME];
	Igrac2D11( playerid,imeulice,sizeof(imeulice));
	return imeulice;
}

//------------------------------------------------------------------------------
stock SetTablice( h )
{
	new tablice[ 20 ];
	if( 10 > h )
	{
		format( tablice, sizeof( tablice ), "LS 000%d.", h );
		SetVehicleNumberPlate( h, tablice );
	}
	else if( 10 <= h && h < 100 )
	{
		format( tablice , sizeof( tablice ), "LS 00%d.", h );
		SetVehicleNumberPlate( h, tablice );
	}
	else if( 100 <= h && h < 1000 )
	{
		format( tablice, sizeof( tablice ), "LS 0%d.", h );
		SetVehicleNumberPlate( h, tablice );
	}
	else if( 1000 <= h && h < 2001 )
	{
		format( tablice, sizeof( tablice ), "LS %d.", h );
		SetVehicleNumberPlate( h, tablice );
	}
	return 1;
}
//------------------------------------------------------------------------------
stock ini_GetKey( line[] ) {

	new keyRes[256];
	keyRes[ 0 ] = 0;

	if( strfind( line , "=" , true ) == -1 ) return keyRes;

	strmid( keyRes , line , 0 , strfind( line , "=" , true ) , sizeof( keyRes) );
	return keyRes;
}
//------------------------------------------------------------------------------
stock ini_GetValue( line[] ) {
	new valRes[256];
	valRes[ 0 ]=0;

	if( strfind( line , "=" , true ) == -1 ) return valRes;

	strmid( valRes , line , strfind( line , "=" , true )+1 , strlen( line ) , sizeof( valRes ) );
	return valRes;
}
//------------------------------------------------------------------------------
stock Create3DandP( text[], Float:vXU, Float:vYU, Float:vZU, vInt, vVW, pickupid, Float:radius ) {
	CreateDynamic3DTextLabel(text, 0x0059FFAA, vXU, vYU, vZU, radius, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vVW, vInt, -1, 20.0);
	CreateDynamicPickup(pickupid, 1, vXU, vYU, vZU, vVW, vInt);
}
//------------------------------------------------------------------------------
stock UlicaHotela( i ) {
	new imeulice[ MAX_ZONE_NAME ];
	UlicaHotela2D( i, imeulice, sizeof( imeulice ) );
	return imeulice;
}
//------------------------------------------------------------------------------
stock UlicaHotela2D( h, zone[], len ) {
	new Float:x22, Float:y22;
	x22 = hotelInfo[ h ][ hEnter ][ 0 ]; y22 = hotelInfo[ h ][ hEnter ][ 1 ];
	for( new i = 0; i != sizeof( gSAZones ); i++ ) {
		if(x22 >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x22 <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y22 >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y22 <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock UlicaImovine( i )
{
	new imeulice[ MAX_ZONE_NAME ];
	UlicaImovine2D( i, imeulice, sizeof( imeulice ) );
	return imeulice;
}
//------------------------------------------------------------------------------
stock UlicaImovine2D( h, zone[], len )
{
	new Float:x22, Float:y22;
	x22 = II[ h ][ iEnter ][ 0 ]; y22 = II[ h ][ iEnter ][ 1 ];
	for( new i = 0; i != sizeof(gSAZones); i++ )
	{
		if(x22 >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x22 <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y22 >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y22 <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock GetSpeed( playerid ) {
	new Float:ST[ 4 ];
	if( IsPlayerInAnyVehicle( playerid ) )
		GetVehicleVelocity( GetPlayerVehicleID( playerid ), ST[ 0 ], ST[ 1 ], ST[ 2 ] );
	else
		GetPlayerVelocity( playerid, ST[ 0 ], ST[ 1 ], ST[ 2 ] );

	ST[ 3 ] = floatsqroot(floatpower(floatabs(ST[ 0 ]), 2.0) + floatpower(floatabs(ST[ 1 ]), 2.0) + floatpower(floatabs(ST[ 2 ]), 2.0)) * 178.8617875;
	return floatround( ST[ 3 ] );
}
//------------------------------------------------------------------------------
stock IsPlayerFacingVehicle( playerid,vehicleid)
{
		new Float:pX,Float:pY,Float:pZ,Float:X,Float:Y,Float:Z,Float:ang;

		if(!IsPlayerConnected( playerid )) return 0;

		GetVehiclePos( vehicleid, X, Y, Z);
		GetPlayerPos( playerid, pX, pY, pZ);

		if( Y > pY ) ang = (-acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
		else if( Y < pY && X < pX ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 450.0);
		else if( Y < pY ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);

		if(X > pX) ang = (floatabs(floatabs(ang) + 180.0));
		else ang = (floatabs(ang) - 180.0);
		new Float:russia;
		GetPlayerFacingAngle( playerid,russia);
		if(ang-russia<-130 || ang-russia>130) return 0;
		else return 1;
}
//------------------------------------------------------------------------------
GetNameByWatchID( playerid ) {
	new watchName[ 20 ] = "Rolex Datejust";

	switch( PlayerInfo[ playerid ][ xSat ] ) {
		case 0: watchName = "Nema sata";
		case 19039: watchName = "Rolex Datejust";
		case 19040: watchName = "Emporio Armani";
		case 19041: watchName = "Casio G-Shock";
		case 19042: watchName = "Michael Kors";
		case 19043: watchName = "Hugo Boss";
	}
	return watchName;
}
//------------------------------------------------------------------------------
stock UzmiTipUtakmice( broj ) {
	new watchName[ 10 ] = "ki 1";

	switch( broj ) {
		case 1: watchName = "ki 1";
		case 2: watchName = "ki x";
		case 3: watchName = "ki 2";
	}
	return watchName;
}
//------------------------------------------------------------------------------
GetReketName( reketID ) {

	new reketName[ 64 ] = "Nema";

	if( reketID == -1 || reketID == 0 ) {
	
		format( reketName, sizeof( reketName ), "%s", "Nema" );
	}
	else if( reketID != -1 ) {
	
		new orgFile[ 50 ];
		format( orgFile, sizeof( orgFile ), O_FILE, reketID );
		if( fexist( orgFile ) ) {
		
			format( reketName, sizeof( reketName ), "%s", OI[ reketID ][ oName ] );
		}
		else if( !fexist( orgFile ) ) {
		
			format( reketName, sizeof( reketName ), "%s", "Nema" );
		}
	
	}
	
	return reketName;
}
//------------------------------------------------------------------------------
getJobName( jobID )
{
	new jobName[26] = "Nepostojeci posao";

	switch( jobID ) {
		case POSAO_NEMA: jobName = "Nezaposlen";
		case POSAO_MEHANICAR: jobName = "Mehanicar";//8
		case POSAO_MASINOVODJA: jobName = "Masinovodja";
		case POSAO_TAXI: jobName = "Taxista";
		case POSAO_PREVOZNIK: jobName = "Prevoznik";
		case POSAO_KOSAC: jobName = "Kosac Trave";//1
		case POSAO_KOMUNALAC: jobName = "Komunalac";//4
		case POSAO_GRADJEVINAR: jobName = "Gradjevinar";//2
		case POSAO_PIZZA: jobName = "Dostavljac pizze";
		case POSAO_PILOT: jobName = "Pilot";//6
		case POSAO_FARMER: jobName = "Farmer";
		case POSAO_BUSVOZAC: jobName = "Bus vozac";//7
		case POSAO_RUDAR: jobName = "Rudar";//3
		case POSAO_PREVOZNOVCA: jobName = "Prevoznik Novca";
		case POSAO_RIBAR: jobName = "Ribar";
		case POSAO_PNAMESTAJA: jobName = "Proizvodjac Namestaja";
		case POSAO_TEMPODOSTAVA: jobName = "Tempo Dostavljac";//5
	}
	return jobName;
}
//------------------------------------------------------------------------------
getGajbicaName( SLOTID )
{
	new NAME[11] = "Jabukeaaaa";

	switch( SLOTID )
	{
		case -1: NAME = "Nema nista";
		case 0: NAME = "Prazna";
		case BILJKA_SLJIVA: NAME = "Sljive";
		case BILJKA_KRUSKA: NAME = "Kruske";
		case BILJKA_JABUKA: NAME = "Jabuke";
		case BILJKA_KUPUS: NAME = "Kupus";
		case BILJKA_RUZE: NAME = "Ruze";
	}
	return NAME;
}
//------------------------------------------------------------------------------
getOrgRank( playerid, orgID ) {
	new orgRank[64] = "Los Santos Police Department";

	if( orgID == 0 ) orgRank = "Civil";
	else {
		if( PlayerInfo[ playerid ][ xRank ] == 1) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank1 ] );
		else if( PlayerInfo[ playerid ][ xRank ] == 2) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank2 ] );
		else if( PlayerInfo[ playerid ][ xRank ] == 3) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank3 ] );
		else if( PlayerInfo[ playerid ][ xRank ] == 4) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank4 ] );
		else if( PlayerInfo[ playerid ][ xRank ] == 5) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank5 ] );
		else if( PlayerInfo[ playerid ][ xRank ] == 6) format( orgRank, sizeof( orgRank ), "%s", OI[ PlayerInfo[ playerid ][ xClan ] ][ oRank6 ] );
	}
	return orgRank;
}
//------------------------------------------------------------------------------
getOrgName( orgID ) {
	new orgName[64] = "Los Santos Police Department";

	if( orgID == 0 ) orgName = "Civil";
	else format( orgName, sizeof( orgName ), "%s", OI[ orgID ][ oName ] );
	return orgName;
}
//------------------------------------------------------------------------------
NearestGate( playerid )
{

	for( new i = 1; i != MAX_GATES; i ++ ) if( GateData[ i ][ gateModel ] && IsPlayerInRangeOfPoint( playerid, GateData[ i ][ gateRadius ], GateData[ i ][ gatePos ][ 0 ], GateData[ i ][ gatePos ][ 1 ], GateData[ i ][ gatePos ][ 2 ] ) ) {
	
		if( GetPlayerInterior( playerid ) == GateData[ i ][ gateInterior ] && GetPlayerVirtualWorld( playerid ) == GateData[ i ][ gateWorld ] )
			return i;
	}
	return -1;
}
//------------------------------------------------------------------------------
stock Gate_Operate( playerid, gateid )
{

	if( gateid != -1 && GateData[ gateid ][ gateModel ] )
	{

		if( !GateData[ gateid ][ gateOpened ] )
		{
		
			GateData[ gateid ][ gateOpened ] = true;
			MoveDynamicObject( GateData[ gateid ][ gateObject ], GateData[ gateid ][ gateMove ][ 0 ], GateData[ gateid ][ gateMove ][ 1 ], GateData[ gateid ][ gateMove ][ 2 ], GateData[ gateid ][ gateSpeed ], GateData[ gateid ][ gateMove ][ 3 ], GateData[ gateid ][ gateMove ][ 4 ], GateData[ gateid ][ gateMove ][ 5 ] );

			SendInfoMessage( playerid, "Otvorili ste kapiju/vrata/rampu i zatvara se za %d sekundi!", GateData[ gateid ][ gateTime ]/1000 );

			if( GateData[ gateid ][ gateTime ] > 0 )
			{
				GateData[ gateid ][ gateTimer ] = SetTimerEx( "CloseGate", GateData[ gateid ][ gateTime ], false, "dfffffff", gateid, GateData[ gateid ][ gatePos ][ 0 ], GateData[ gateid ][ gatePos ][ 1 ], GateData[ gateid ][ gatePos ][ 2 ], GateData[ gateid ][ gateSpeed ], GateData[ gateid ][ gatePos ][ 3 ], GateData[ gateid ][ gatePos ][ 4 ], GateData[ gateid ][ gatePos ][ 5 ] );
			}
		}
		else if( GateData[ gateid ][ gateOpened ] )
		{
		
			GateData[ gateid ][ gateOpened ] = false;
			MoveDynamicObject( GateData[ gateid ][ gateObject ], GateData[ gateid ][ gatePos ][ 0 ], GateData[ gateid ][ gatePos ][ 1 ], GateData[ gateid ][ gatePos ][ 2 ], GateData[ gateid ][ gateSpeed ], GateData[ gateid ][ gatePos ][ 3 ], GateData[ gateid ][ gatePos ][ 4 ], GateData[ gateid ][ gatePos ][ 5 ] );

			SendInfoMessage( playerid,"Zatvorili ste kapiju/vrata/rampu!" );

			if( GateData[ gateid ][ gateTime ] > 0 )
			{
				Dimi_KillTimer( GateData[ gateid ][ gateTimer ] );
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
forward CloseGate( gateid, Float:fX, Float:fY, Float:fZ, Float:speed, Float:fRotX, Float:fRotY, Float:fRotZ);
public CloseGate( gateid, Float:fX, Float:fY, Float:fZ, Float:speed, Float:fRotX, Float:fRotY, Float:fRotZ)
{

	if( GateData[ gateid ][ gateModel ] && GateData[ gateid ][ gateOpened ] )
	{
	
		MoveDynamicObject( GateData[ gateid ][ gateObject ], fX, fY, fZ, speed, fRotX, fRotY, fRotZ );

		GateData[ gateid ][ gateOpened ] = false ;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
GetNearestOrgPortID( playerid ) {
	for( new i = 1; i < MAX_ORG; i++ ) {
		for( new id = 0; id < OI[ i ][ oMaxPort ]; id++ ) {
			if( IsPlayerInRangeOfPoint( playerid, 3.0, PortOP[ i ][ id ][ Pos1 ][ 0 ], PortOP[ i ][ id ][ Pos1 ][ 1 ], PortOP[ i ][ id ][ Pos1 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 0 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 0 ] ) {
				return id;
			}
			else if( IsPlayerInRangeOfPoint( playerid, 3.0, PortOP[ i ][ id ][ Pos2 ][ 0 ], PortOP[ i ][ id ][ Pos2 ][ 1 ], PortOP[ i ][ id ][ Pos2 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 1 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 1 ] ) {
				return id;
			}
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestOrgIDPort( playerid )
{
	for( new i = 1; i < MAX_ORG; i++ )
	{
		for( new id = 0; id < OI[ i ][ oMaxPort ]; id++ )
		{
			if( IsPlayerInRangeOfPoint( playerid, 3.0, PortOP[ i ][ id ][ Pos1 ][ 0 ], PortOP[ i ][ id ][ Pos1 ][ 1 ], PortOP[ i ][ id ][ Pos1 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 0 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 0 ] )
			{
				return i;
			}
			else if( IsPlayerInRangeOfPoint( playerid, 3.0, PortOP[ i ][ id ][ Pos2 ][ 0 ], PortOP[ i ][ id ][ Pos2 ][ 1 ], PortOP[ i ][ id ][ Pos2 ][ 2 ] ) && GetPlayerVirtualWorld( playerid ) == PortOP[ i ][ id ][ VW ][ 1 ] && GetPlayerInterior( playerid ) == PortOP[ i ][ id ][ Int ][ 1 ] )
			{
				return i;
			}
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestHotel( playerid )
{

	for( new i = 1; i < MAX_HOTELS; i++)
	{

		if( IsPlayerInRangeOfPoint( playerid, 3.0, hotelInfo[ i ][ hEnter ][ 0 ], hotelInfo[ i ][  hEnter ][ 1 ], hotelInfo[ i ][ hEnter ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
stock GetNearestVikendica( playerid )
{
	for( new i = 1; i < MAX_IMOVINA; i++)
	{
		if(II[ i ][ iUsage ] == IMOVINA_VIKENDICA && IsPlayerInRangeOfPoint( playerid, 3.0, II[ i ][ iEnter ][ 0 ], II[ i ][  iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestStan( playerid )
{
	for( new i = 1; i < MAX_IMOVINA; i++)
	{
		if(II[ i ][ iUsage ] == IMOVINA_STAN && IsPlayerInRangeOfPoint( playerid, 3.0, II[ i ][ iEnter ][ 0 ], II[ i ][  iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestHouse( playerid )
{
	for( new i = 1; i < MAX_IMOVINA; i++)
	{
		if(II[ i ][ iUsage ] == IMOVINA_KUCA && IsPlayerInRangeOfPoint( playerid, 3.0, II[ i ][ iEnter ][ 0 ], II[ i ][  iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestProperty( playerid )
{

	for( new i = 1; i < MAX_IMOVINA; i++)
	{

		if( IsPlayerInRangeOfPoint( playerid, 3.0, II[ i ][ iEnter ][ 0 ], II[ i ][  iEnter ][ 1 ], II[ i ][ iEnter ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestSalon( playerid ) {
	for( new i = 1; i < MAX_AUTOS; i++) {
		if( IsPlayerInRangeOfPoint( playerid, 3.0, AutoSalon[ i ][ aPickupPos ][ 0 ], AutoSalon[ i ][  aPickupPos ][ 1 ], AutoSalon[ i ][ aPickupPos ][ 2 ] ) ) { return i; }
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestFurniture( playerid, hid ) {

	for( new a = 0; a < MAX_X_OBJECTS; a++) {

		if( IsPlayerInRangeOfPoint( playerid, 2.0, Furniture[ hid ][ a ][ f_X ], Furniture[ hid ][ a ][ f_Y ], Furniture[ hid ][ a ][ f_Z ] ) && Furniture[ hid ][ a ][ f_Model ] ) { return a; }
	}
	return -1;
}
//------------------------------------------------------------------------------
ImeIgraceveImovine( i )
{
	new pName[26];

	if( i == -1 || i == 0 )
	{
		pName = "Nema imovine";
	}
	else if( i != -1 )
	{
		switch( II[ i ][ iUsage ] )
		{
			case IMOVINA_KUCA: pName = "Kuca";
			case IMOVINA_STAN: pName = "Stan";
			case IMOVINA_VIKENDICA: pName = "Vikendica";
		}
	}

	return pName;
}
//------------------------------------------------------------------------------
GetPropertyName( i )
{
	new pName[26] = "Nepostojeci posao";
	
	if( i == -1 || i == 0 )
	{
		format( pName, sizeof( pName ), "%s", "Nema nekretnine" );
	}
	else if( i != -1 )
	{
		switch( II[ i ][ iUsage ] )
		{
			case IMOVINA_KUCA: pName = "Kucu";
			case IMOVINA_STAN: pName = "Stan";
			case IMOVINA_VIKENDICA: pName = "Vikendicu";
		}
	}
	
	return pName;
}
//------------------------------------------------------------------------------
GetPropertyAName( i )
{
	new pName[26] = "Nepostojeci posao";

	if( i == -1 || i == 0 ){
		format( pName, sizeof( pName ), "%s", "Nema nekretnine" );
	}
	else if( i != -1 ) {
		switch( II[ i ][ iUsage ] )
		{
			case IMOVINA_KUCA: pName = "Kuca";
			case IMOVINA_STAN: pName = "Stan";
			case IMOVINA_VIKENDICA: pName = "Vikendica";
		}
	}

	return pName;
}
//------------------------------------------------------------------------------
getBussinesType( f )
{
	new jobName[26] = "Nepostojeci posao";

	switch( BussinesInfo[ f ][ bType ] )
	{
		case VRSTA_RESTORAN: jobName = "Restoran";
		case VRSTA_CLUCK: jobName = "Cluckin' Bell";
		case VRSTA_ZIP: jobName = "Zip";
		case VRSTA_BINCO: jobName = "Binco";
		case VRSTA_SUBURBAN: jobName = "Suburban";
		case VRSTA_VICTIM: jobName = "Victim";
		case VRSTA_BAR: jobName = "Bar";
		case VRSTA_NKLUB: jobName = "Nocni Klub";
		case VRSTA_DISCO: jobName = "Diskoteka";
		case VRSTA_GUNSHOP: jobName = "Ammunation";
		case VRSTA_PIZZA: jobName = "Picerija";
		case VRSTA_BURG: jobName = "Burg";
		case VRSTA_MARKET: jobName = "Prodavnica";
		case VRSTA_GYM: jobName = "Teretana";
		case VRSTA_ELEKTRONIK: jobName = "Elektronik";
		case VRSTA_TRAFIKA: jobName = "Trafika";
		case VRSTA_JFIRMA: jobName = "Firma bez ulaza";
		case VRSTA_POSAO: jobName = "Poslovna firma";
		case VRSTA_RENT: jobName = "Rent a vehicle";
		case VRSTA_PUMPA: jobName = "Pumpa";
		case VRSTA_JAVNAK: jobName = "Javna Kuca";
		case VRSTA_KLAD: jobName = "Kladionica";
		case VRSTA_OGLAS: jobName = "Oglas";
		case VRSTA_TELEKOM: jobName = "Telekom";
		case VRSTA_PAYSPRAY: jobName = "Pay 'n' Spray";
		case VRSTA_KOMUNALIJE: jobName = "Komunalije";
		case VRSTA_VODOVOD: jobName = "Vodovod";
		case VRSTA_ELEKTRANA: jobName = "Elektrana";
		case VRSTA_LUTRIJA: jobName = "Lutrija";
		case VRSTA_CASINO: jobName = "Casino";
		case VRSTA_NEON: jobName = "Neon Shop";
		case VRSTA_RODA: jobName = "Market Roda";
	}
	return jobName;
}
getAmountFuel( carid )
{
	new fuel;
	if( IsVehicleBajs( carid ) ) fuel = 1000;
	else if( IsVehicleMotor( carid ) ) fuel = 15;
	else if( IsVehicleAuto( carid ) ) fuel = 40;
	else if( IsVehicleC1( carid ) ) fuel = 55;
	else if( IsVehicleC2( carid ) ) fuel = 70;
	else if( IsVehicleC3( carid ) ) fuel = 70;
	else if( IsVehicleBrod( carid ) ) fuel = 100;
	else if( IsVehicleLetelica( carid ) ) fuel = 100;

	return fuel;
}
//------------------------------------------------------------------------------
OOCNews( color, const string[] ) {
	for(new i; i < MAX_PLAYERS; i++) {
		if( PlayerLogged[ i ] == true ) {
			if( !gNews{ i } ) {
				SendClientMessage( i, color, string );
			}
		}
	}
}
//------------------------------------------------------------------------------

PoredTrafike( playerid )
{

	if( IsPlayerConnected( playerid ) )
	{
	
		if( IsPlayerInRangeOfPoint( playerid, 3.0, 354.3248,-2030.7961,7.9078 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1912.2021,-1734.6825,13.3773 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1886.4380,-1646.7341,13.3773 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1696.2340,-1887.5942,13.5517 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1420.1433,-1718.0017,13.5469 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1439.3855,-1043.3324,23.8281 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1194.2517,-954.1796,42.8990 )   ||
			IsPlayerInRangeOfPoint( playerid, 3.0, 1325.0109,-1389.5940,13.5681 )) {
	
			return 1;
		}

	}
	return 0;
}

/*/------------------------------------------------------------------------------
IsAtGasStation( playerid ) {
	if( IsPlayerConnected( playerid ) ) {
		if( IsPlayerInRangeOfPoint( playerid,10.0, 1004.0070,-939.3102,42.1797)  ||
			IsPlayerInRangeOfPoint( playerid,6.0, -90.5515,-1169.4578,2.4079)    ||
			IsPlayerInRangeOfPoint( playerid,6.0, -1609.7958,-2718.2048,48.5391) ||
			IsPlayerInRangeOfPoint( playerid,6.0, -2029.4968,156.4366,28.9498)   ||
			IsPlayerInRangeOfPoint( playerid,8.0, -2408.7590,976.0934,45.4175)   ||
			IsPlayerInRangeOfPoint( playerid,5.0, -2243.9629,-2560.6477,31.8841) ||
			IsPlayerInRangeOfPoint( playerid,8.0, -1676.6323,414.0262,6.9484)    ||
			IsPlayerInRangeOfPoint( playerid,6.0, 2202.2349,2474.3494,10.5258)   ||
			IsPlayerInRangeOfPoint( playerid,10.0, 614.9333,1689.7418,6.6968)    ||
			IsPlayerInRangeOfPoint( playerid,8.0, -1328.8250,2677.2173,49.7665)  ||
			IsPlayerInRangeOfPoint( playerid,6.0, 70.3882,1218.6783,18.5165)     ||
			IsPlayerInRangeOfPoint( playerid,8.0, 2113.7390,920.1079,10.5255)    ||
			IsPlayerInRangeOfPoint( playerid,6.0, -1327.7218,2678.8723,50.0625)  ||
			IsPlayerInRangeOfPoint( playerid,6.0, 1488.67, -2400.87, 14.12)      ||
			IsPlayerInRangeOfPoint( playerid,6.0, 1765.69, -2287.06, 27.29)      ||
			IsPlayerInRangeOfPoint( playerid,6.0, 1926.9827,-1769.5992,13.5469)  ||
			IsPlayerInRangeOfPoint( playerid,6.0, 1926.2886,-1776.2615,13.5469)  ||
			IsPlayerInRangeOfPoint( playerid,6.0, 1545.19, -1352.68, 329.97 ) ) {
			return 1;
		}
	}
	return 0;
}*/
//------------------------------------------------------------------------------
stock Kickovanje( id, reason[] )
{
	//SendAcMessage(id,reason);
	new kick_message_string[300];

	format(kick_message_string,sizeof(kick_message_string),""col_red"| KICK |: {ffffff}%s",reason);

	SendClientMessage( id, -1, kick_message_string );
	SetTimerEx( "KickIgraca", 150, false, "d", id );
	return 1;
}
/*/==============================================================================
LockCar(carid)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;

	GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(carid, engine, lights, alarm, 1, bonnet, boot, objective);
}*/
//==============================================================================
UnLockCar(carid)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;

	GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(carid, engine, lights, alarm, 0, bonnet, boot, objective);
}
//==============================================================================
forward antisk(playerid); // forwarduje public antisk
public antisk(playerid) // kada timer zavrsi odbrojavanje pokrece sve ispod
{
	Dimi_SetPlayerHealth(playerid, 100.0); // stavlja igracu helte na 100
	SendClientMessage(playerid, 0xAAAA33AA, ""col_balkanstory"[Anti-SpawnKill]{ffffff}: Vasa zastita na prvom ulogovanju u igru je istekla!"); // salje igracu poruku da vise nemaju anti spawn-kill protekciju
	return 1;
}
forward antiskmsg(playerid); public antiskmsg(playerid)
{
	SendClientMessage(playerid, 0xAAAA33AA, ""col_balkanstory"[Anti-SpawnKill]{ffffff}: Vasa standardna zastita je istekla!"); // salje igracu poruku da vise nemaju anti spawn-kill protekciju
	return 1;
}
///////////////////////////////////////////////////////////////////////////////
stock IsComponentidCompatible( modelid, componentid ) {
	if( componentid == 1025 || componentid == 1073 || componentid == 1074 || componentid == 1075 || componentid == 1076 ||
		componentid == 1077 || componentid == 1078 || componentid == 1079 || componentid == 1080 || componentid == 1081 ||
		componentid == 1082 || componentid == 1083 || componentid == 1084 || componentid == 1085 || componentid == 1096 ||
		componentid == 1097 || componentid == 1098 || componentid == 1087 || componentid == 1086 ) {
		return componentid;
	}

	switch( modelid ) {
		case 400: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 ) return componentid;
		case 401: if( componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 114 || componentid == 1020 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 402: if( componentid == 1009 || componentid == 1009 || componentid == 1010 ) return componentid;
		case 404: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
		case 405: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1023 || componentid == 1000) return componentid;
		case 409: if( componentid == 1009 ) return componentid;
		case 410: if( componentid == 1019 || componentid == 1021 || componentid == 1020 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 411: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 412: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 415: if( componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 418: if( componentid == 1020 || componentid == 1021 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016) return componentid;
		case 419: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 420: if( componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1003) return componentid;
		case 421: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1016 || componentid == 1000) return componentid;
		case 422: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007) return componentid;
		case 426: if( componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003) return componentid;
		case 429: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 436: if( componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 438: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 439: if( componentid == 1003 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1013) return componentid;
		case 442: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 445: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 451: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 458: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 466: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 467: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 474: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 475: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 477: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007) return componentid;
		case 478: if( componentid == 1005 || componentid == 1004 || componentid == 1012 || componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 479: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 480: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 489: if( componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016 || componentid == 1000) return componentid;
		case 491: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 492: if( componentid == 1005 || componentid == 1004 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1016 || componentid == 1000) return componentid;
		case 496: if( componentid == 1006 || componentid == 1017 || componentid == 1007 || componentid == 1011 || componentid == 1019 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1003 || componentid == 1002 || componentid == 1142 || componentid == 1143 || componentid == 1020) return componentid;
		case 500: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 506: if( componentid == 1009) return componentid;
		case 507: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 516: if( componentid == 1004 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1015 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
		case 517: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 518: if( componentid == 1005 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 526: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 527: if( componentid == 1021 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1015 || componentid == 1017 || componentid == 1007) return componentid;
		case 529: if( componentid == 1012 || componentid == 1011 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 533: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 534: if( componentid == 1126 || componentid == 1127 || componentid == 1179 || componentid == 1185 || componentid == 1100 || componentid == 1123 || componentid == 1125 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1180 || componentid == 1178 || componentid == 1101 || componentid == 1122 || componentid == 1124 || componentid == 1106) return componentid;
		case 535: if( componentid == 1109 || componentid == 1110 || componentid == 1113 || componentid == 1114 || componentid == 1115 || componentid == 1116 || componentid == 1117 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1120 || componentid == 1118 || componentid == 1121 || componentid == 1119) return componentid;
		case 536: if( componentid == 1104 || componentid == 1105 || componentid == 1182 || componentid == 1181 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1184 || componentid == 1183 || componentid == 1128 || componentid == 1103 || componentid == 1107 || componentid == 1108) return componentid;
		case 540: if( componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
		case 541: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 542: if( componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1015) return componentid;
		case 545: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 546: if( componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
		case 547: if( componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1016 || componentid == 1003 || componentid == 1000) return componentid;
		case 549: if( componentid == 1012 || componentid == 1011 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 550: if( componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003) return componentid;
		case 551: if( componentid == 1005 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003) return componentid;
		case 555: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 558: if( componentid == 1092 || componentid == 1089 || componentid == 1166 || componentid == 1165 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1168 || componentid == 1167 || componentid == 1088 || componentid == 1091 || componentid == 1164 || componentid == 1163 || componentid == 1094 || componentid == 1090 || componentid == 1095 || componentid == 1093) return componentid;
		case 559: if( componentid == 1065 || componentid == 1066 || componentid == 1160 || componentid == 1173 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1159 || componentid == 1161 || componentid == 1162 || componentid == 1158 || componentid == 1067 || componentid == 1068 || componentid == 1071 || componentid == 1069 || componentid == 1072 || componentid == 1070 || componentid == 1009) return componentid;
		case 560: if( componentid == 1028 || componentid == 1029 || componentid == 1169 || componentid == 1170 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1141 || componentid == 1140 || componentid == 1032 || componentid == 1033 || componentid == 1138 || componentid == 1139 || componentid == 1027 || componentid == 1026 || componentid == 1030 || componentid == 1031) return componentid;
		case 561: if( componentid == 1064 || componentid == 1059 || componentid == 1155 || componentid == 1157 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1154 || componentid == 1156 || componentid == 1055 || componentid == 1061 || componentid == 1058 || componentid == 1060 || componentid == 1062 || componentid == 1056 || componentid == 1063 || componentid == 1057) return componentid;
		case 562: if( componentid == 1034 || componentid == 1037 || componentid == 1171 || componentid == 1172 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1149 || componentid == 1148 || componentid == 1038 || componentid == 1035 || componentid == 1147 || componentid == 1146 || componentid == 1040 || componentid == 1036 || componentid == 1041 || componentid == 1039) return componentid;
		case 565: if( componentid == 1046 || componentid == 1045 || componentid == 1153 || componentid == 1152 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1150 || componentid == 1151 || componentid == 1054 || componentid == 1053 || componentid == 1049 || componentid == 1050 || componentid == 1051 || componentid == 1047 || componentid == 1052 || componentid == 1048) return componentid;
		case 566: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 567: if( componentid == 1129 || componentid == 1132 || componentid == 1189 || componentid == 1188 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1187 || componentid == 1186 || componentid == 1130 || componentid == 1131 || componentid == 1102 || componentid == 1133) return componentid;
		case 575: if( componentid == 1044 || componentid == 1043 || componentid == 1174 || componentid == 1175 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1176 || componentid == 1177 || componentid == 1099 || componentid == 1042) return componentid;
		case 576: if( componentid == 1136 || componentid == 1135 || componentid == 1191 || componentid == 1190 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1192 || componentid == 1193 || componentid == 1137 || componentid == 1134) return componentid;
		case 579: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 580: if( componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
		case 585: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
		case 587: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 589: if( componentid == 1005 || componentid == 1004 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1024 || componentid == 1013 || componentid == 1006 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
		case 600: if( componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1022 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007) return componentid;
		case 602: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
		case 603: if( componentid == 1144 || componentid == 1145 || componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
	}
	return false;
}
//==============================================================================
stock GetVehicleCameraPos( vehicleid, &Float:x, &Float:y, &Float:z, Float:xoff=0.0, Float:yoff=0.0, Float:zoff=0.0 ) { // credits Pasha
	new Float:rot;
	GetVehicleZAngle( vehicleid, rot );
	rot = 360 - rot;
	GetVehiclePos( vehicleid, x, y, z );
	x = floatsin( rot, degrees ) * yoff + floatcos( rot, degrees ) * xoff + x;
	y = floatcos( rot, degrees ) * yoff - floatsin( rot, degrees ) * xoff + y;
	z = zoff + z;
}
//==============================================================================
SavePlayerVehicleTuning(autoid, componentid) {
	if( IsASpoiler( componentid ) )
		VehicleInfo[ autoid ][ vSpoiler] = componentid;

	else if( IsANitro( componentid ) )
		VehicleInfo[ autoid ][ vNitro] = componentid;

	else if( IsAFrontBumper( componentid ) )
		VehicleInfo[ autoid ][ vFrontBumper] = componentid;

	else if( IsARearBumper( componentid ) )
		VehicleInfo[ autoid ][ vRearBumper] = componentid;

	else if( IsAStereo( componentid ) )
		VehicleInfo[ autoid ][ vStereo] = componentid;

	else if( IsAExhaust( componentid ) )
		VehicleInfo[ autoid ][ vExhaust] = componentid;

	else if( IsALamp( componentid ) )
		VehicleInfo[ autoid ][ vLamps] = componentid;

	else if( IsAHydraulic( componentid ) )
		VehicleInfo[ autoid ][ vHydraulics ] = componentid;

	else if( IsAVents( componentid ) )
		VehicleInfo[ autoid ][ vVents ] = componentid;

	else if( IsAHood( componentid ) )
		VehicleInfo[ autoid ][ vHood ] = componentid;

	else if( IsAWheel( componentid ) )
		VehicleInfo[ autoid ][ vWheels ] = componentid;

	else if( IsARoof( componentid ) )
		VehicleInfo[ autoid ][ vRoof ] = componentid;

	else if( IsASkirt( componentid ) )
		VehicleInfo[ autoid ][ vSkirt ] = componentid;

	SaveVehicle( autoid );
}
//==============================================================================
IsASkirt( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_SIDESKIRT )
		return true;

	return false;
}
//==============================================================================
IsASpoiler( componentid ) {

	if( GetVehicleComponentType( componentid ) == CARMODTYPE_SPOILER )
		return true;

	return false;
}
//==============================================================================
IsANitro( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_NITRO )
		return true;

	return false;
}
//==============================================================================
IsAFrontBumper( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_FRONT_BUMPER )
		return true;

	return false;
}
//==============================================================================
IsARearBumper( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_REAR_BUMPER )
		return true;

	return false;
}
//==============================================================================
IsAStereo( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_STEREO )
		return true;

	return false;
}
//==============================================================================
IsAExhaust( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_EXHAUST )
		return true;

	return false;
}
//==============================================================================
IsALamp( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_LAMPS )
		return true;

	return false;
}
//==============================================================================
IsAHydraulic( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_HYDRAULICS )
		return true;

	return false;
}
//==============================================================================
IsAVents( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_VENT_RIGHT || GetVehicleComponentType( componentid ) == CARMODTYPE_VENT_LEFT )
		return true;

	return false;
}
//==============================================================================
IsAHood( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_HOOD )
		return true;

	return false;
}
//==============================================================================
IsAWheel( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_WHEELS )
		return true;

	return false;
}
//==============================================================================
IsARoof( componentid ) {
	if( GetVehicleComponentType( componentid ) == CARMODTYPE_ROOF )
		return true;

	return false;
}
//==============================================================================
TuneVehicle( vehicleid )
{
	if( vehicleid != -1 )
	{
		if( VehicleInfo[ vehicleid ][ vTuned ] != 0)
		{
			if( VehicleInfo[ vehicleid ][ vPaintJob ] >= 0 && VehicleInfo[ vehicleid ][ vPaintJob ] < 6)
				ChangeVehiclePaintjob( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vPaintJob ] );
			if( IsASpoiler( VehicleInfo[ vehicleid ][ vSpoiler ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vSpoiler ] );
			if( IsANitro( VehicleInfo[ vehicleid ][ vNitro ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vNitro ] );
			if( IsAFrontBumper( VehicleInfo[ vehicleid ][ vFrontBumper ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vFrontBumper ] );
			if( IsARearBumper( VehicleInfo[ vehicleid ][ vRearBumper ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vRearBumper ] );
			if( IsAStereo( VehicleInfo[ vehicleid ][ vStereo ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vStereo ] );
			if( IsAExhaust( VehicleInfo[ vehicleid ][ vExhaust ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vExhaust ] );
			if( IsALamp( VehicleInfo[ vehicleid ][ vLamps ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vLamps ] );
			if( IsAHydraulic( VehicleInfo[ vehicleid ][ vHydraulics ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vHydraulics ] );
			if( IsAVents( VehicleInfo[ vehicleid ][ vVents ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vVents ] );
			if( IsAHood( VehicleInfo[ vehicleid ][ vHood ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vHood ] );
			if( IsAWheel( VehicleInfo[ vehicleid ][ vWheels ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vWheels ] );
			if( IsARoof( VehicleInfo[ vehicleid ][ vRoof ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vRoof ] );
			if( IsASkirt( VehicleInfo[ vehicleid ][ vSkirt ] ) )
				AddVehicleComponent( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vSkirt ] );

			ChangeVehicleColor( VehicleInfo[ vehicleid ][ vID ], VehicleInfo[ vehicleid ][ vColor1 ], VehicleInfo[ vehicleid ][ vColor2 ] );
		}
	}
}
//------------------------------------------------------------------------------
IsPlayerNearPlayer(Float:radi, playerid, targetid)
{
	if( IsPlayerConnected( playerid ) && IsPlayerConnected( targetid ) ) {
		if( GetPlayerVirtualWorld( playerid ) == GetPlayerVirtualWorld( targetid ) ) {

			new Float:posx,
				Float:posy,
				Float:posz,
				Float:oldposx,
				Float:oldposy,
				Float:oldposz,
				Float:tempposx,
				Float:tempposy,
				Float:tempposz;

			GetPlayerPos( playerid, oldposx, oldposy, oldposz);

			GetPlayerPos(targetid, posx, posy, posz);
			tempposx = (oldposx -posx);
			tempposy = (oldposy -posy);
			tempposz = (oldposz -posz);

			if(((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
			{
				return 1;
			}
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock ResetVehicleStatistics( i ) {

	if( i != INVALID_VEHICLE_ID ) {
	
		if( Parked[ i ] != -1 ) {

			new Float:Pos[ 3 ];
			GetVehiclePos( i, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );

			new parkID = IsCordsInOtherParkingZone( Pos[ 0 ], Pos[ 1 ] );

			if( parkID != -1 ) {
				ParkingPlaces[ parkID ][ Parked[ i ] ][ parkTaken ] = false;
			}
		}
	
		pizzaVehicle[ i ] = false;
		garbagemanVehicles[ i ][ gGarbages ] = 0;
		garbagemanVehicles[ i ][ gPlayerID ] = -1;
		farmerVehicles[ i ][ fvSeeds ] = 0;
		farmerVehicles[ i ][ fvMilk ] = false;
		farmerVehicles[ i ][ fvMilkpID ] = -1;
		CisternFuel[ i ][ 0 ] = 0;
		CisternFuel[ i ][ 1 ] = 0;
		CisternFuel[ i ][ 2 ] = 0;
		CisternFuel[ i ][ 3 ] = 0;
		Parked[ i ] = -1;
		sljunak[ i ] = false;
		VehCement[ i ] = false;
		KutijaMatsa[ i ] = false;
		IDIgracaKojiVoziBus[ i ] = -1;
		VehNovac[ i ] = false;
		KamionUsed[ i ] = -1;
		StateBox[ i ] = 0;
		BusyVehicle[ i ] = -1;
		Dimi_KillTimer( ParkingTime[ i ] );
	}
}

stock SetVehicleLabels( i )
{

	if( !VehicleInfo[ i ][ Validv3DText ] )
	{

		/*if( VehicleInfo[ i ][ vUsage ] == ADMIN_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "Tip ovog vozila:\n| Admin / GameSage Vozilo |", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}*/
		/*if( VehicleInfo[ i ][ vUsage ] == POSLOVNO_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "Tip ovog vozila:\n| VOZILO ZA POSAO |", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}*/
		/*if( VehicleInfo[ i ][ vUsage ] == IZLOZBENO_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "Tip ovog vozila:\n| Ovo je izlozbeno vozilo, tj. ne\n mozete uci u njega dok ga ne kupite! |", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}*/
		/*if( VehicleInfo[ i ][ vUsage ] == PRIVATNO_VOZILO )
		{
			new stringic2[ 300 ];
			format( stringic2, sizeof( stringic2 ), "[ PRIVATNO VOZILO ]\n\n{ffffff}Ovo vozilo je privatno vozilo, i\nne mozete uci u njega bez kljuca istog!\n"col_balkanstory"[ /papirivozila ]" );

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringic2, PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}*/
		if( VehicleInfo[ i ][ vUsage ] == RENTANO_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "[ RENT ]", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}
		else if( VehicleInfo[ i ][ vUsage ] == PROMOTER_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "[ PROMOTER ]", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}
		else if( VehicleInfo[ i ][ vUsage ] == VIP_VOZILO )
		{

			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( "[ V.I.P. VOZILO ]", PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
		}

		/*else if( VehicleInfo[ i ][ vUsage ] == ORGANIZACIJSKO_VOZILO )
		{

			if( OI[ VehicleInfo[ i ][ vOrganization ] ][ oTip ] == ORG_TIP_PD )
			{

				new stringic[ 300 ];
				format( stringic, sizeof( stringic ), "[ ORG. VOZILO - %s ]", OI[ VehicleInfo[ i ][ vOrganization ] ][ oPreFix ] );

				VehicleInfo[ i ][ Validv3DText ] = true;
				VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringic, PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
				Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
			}
			else
			{
				new stringic[ 300 ];
				format( stringic, sizeof( stringic ), "[ ORG. VOZILO - %s ]", OI[ VehicleInfo[ i ][ vOrganization ] ][ oPreFix ] );

				VehicleInfo[ i ][ Validv3DText ] = true;
				VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringic, PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
				Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
			}
		}*/
		else if( VehicleInfo[ i ][ vUsage ] == NAPRODAJU_VOZILO )
		{

			new stringce[ 250 ];
			format(stringce,sizeof(stringce),"{07C1F5}Vozilo na prodaju!\nModel: {FFFFFF}%s\n{07C1F5}Cijena: {FFFFFF}$%d\n{07C1F5}Gorivo: {FFFFFF}%s\n{07C1F5}Za kupovnu {FFFFFF}udji u vozilo",ImeVozila[ VehicleInfo[ i ][ vModel ]-400 ],VehicleInfo[ i ][ vPrice ],GetVehicleFuelType( i ));
			VehicleInfo[ i ][ Validv3DText ] = true;
			VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringce, PLAVA, 0.0, 0.0, 0.0, 5.0, 0, 1 );
			Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);

		}
				else if( VehicleInfo[ i ][ vUsage ] == PUMPA_VOZILO )
		{

			if( VehicleInfo[ i ][ vModel ] == 584 )
			{

				new fstationID = VehicleInfo[ i ][ vFuelProperty ];

				new stringce[ 256 ];
				format( stringce, sizeof stringce, ""col_balkanstory"[ "col_white"CISTERNA "col_balkanstory"]\n"col_balkanstory"Dizel: {FFFFFF}%d/300 litara\n"col_balkanstory"Benzin: {FFFFFF}%d/300 litara\n"col_balkanstory"Gas: {FFFFFF}%d/300 litara\n"col_balkanstory"Kerozin: {FFFFFF}%d/300 litara\n\n"col_balkanstory"[ {FFFFFF}%s "col_balkanstory"]", CisternFuel[ VehicleInfo[ i ][ vID ] ][ 0 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 1 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 3 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 2 ], FuelStation[ fstationID ][ fsName ] );

				VehicleInfo[ i ][ Validv3DText ] = true;
				VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringce, PLAVA, 0.0, 0.0, 0.0, 30.0, 0, 1 );
				Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
			}
		}
	}
	else if( VehicleInfo[ i ][ Validv3DText ] )
	{

		if( VehicleInfo[ i ][ vUsage ] == PUMPA_VOZILO )
		{

			if( VehicleInfo[ i ][ vModel ] == 584 )
			{

				new fstationID = VehicleInfo[ i ][ vFuelProperty ];

				Delete3DTextLabel( VehicleInfo[ i ][ v3DText ] );

				new stringce[ 256 ];
				format( stringce, sizeof stringce, ""col_balkanstory"[ "col_white"CISTERNA "col_balkanstory"]\n"col_balkanstory"Dizel: {FFFFFF}%d/300 litara\n"col_balkanstory"Benzin: {FFFFFF}%d/300 litara\n"col_balkanstory"Gas: {FFFFFF}%d/300 litara\n"col_balkanstory"Kerozin: {FFFFFF}%d/300 litara\n\n"col_balkanstory"[ {FFFFFF}%s "col_balkanstory"]", CisternFuel[ VehicleInfo[ i ][ vID ] ][ 0 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 1 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 3 ], CisternFuel[ VehicleInfo[ i ][ vID ] ][ 2 ], FuelStation[ fstationID ][ fsName ] );

				VehicleInfo[ i ][ Validv3DText ] = true;
				VehicleInfo[ i ][ v3DText ] = Create3DTextLabel( stringce, PLAVA, 0.0, 0.0, 0.0, 30.0, 0, 1 );
				Attach3DTextLabelToVehicle( VehicleInfo[ i ][ v3DText ], VehicleInfo[ i ][ vID ], 0.0, 0.0, 0.0);
			}
		}
	}
}


stock ResetVehicle( i ) {
	VehicleInfo[ i ][ vOwned ] = 0;
	VehicleInfo[ i ][ vPrice ] = 0;
	strmid( VehicleInfo[ i ][ vOwner ], "Drzava", 0, strlen("Drzava"), 32);
	VehicleInfo[ i ][ vLocked ] = 0;
	VehicleInfo[ i ][ vLokacijaX ] = 0;
	VehicleInfo[ i ][ vLokacijaY ] = 0;
	VehicleInfo[ i ][ vLokacijaZ ] = 0;
	VehicleInfo[ i ][ vLokacijaA ] = 0;
	VehicleInfo[ i ][ vVirtualWorld ] = 0;
	VehicleInfo[ i ][ vInterior ] = 0;
	VehicleInfo[ i ][ vUsage ] = 0;
	VehicleInfo[ i ][ vJob ] = -1;
	VehicleInfo[ i ][ vOrganization ] = -1;
	VehicleInfo[ i ][ vFuelProperty ] = -1;
	VehicleInfo[ i ][ vColor1 ] = 0;
	VehicleInfo[ i ][ vColor2 ] = 0;
	VehicleInfo[ i ][ vModel ] = 0;
	VehicleInfo[ i ][ vReg ] = 0;
	VehicleInfo[ i ][ vRegVreme ] = 0;
	VehicleInfo[ i ][ vTeh ] = 0;
	VehicleInfo[ i ][ vGPS ] = 0;
	VehicleInfo[ i ][ vOsiguranje ] = 0;
	VehicleInfo[ i ][ vLock ] = 0;
	VehicleInfo[ i ][ vAlarm ] = 0;
	VehicleInfo[ i ][ vFuel ] = 100;
	VehicleInfo[ i ][ vFuelType ] = 0;
	VehicleInfo[ i ][ vNeon ] = 0;
	VehicleInfo[ i ][ vTuned ] = 0;
	VehicleInfo[ i ][ vImobilizator ] = 0;
	VehicleInfo[ i ][ vSpoiler ] = 0;
	VehicleInfo[ i ][ vHood ] = 0;
	VehicleInfo[ i ][ vRoof ] = 0;
	VehicleInfo[ i ][ vSkirt ] = 0;
	VehicleInfo[ i ][ vLamps ] = 0;
	VehicleInfo[ i ][ vNitro ] = 0;
	VehicleInfo[ i ][ vExhaust ] = 0;
	VehicleInfo[ i ][ vWheels ] = 0;
	VehicleInfo[ i ][ vStereo ] = 0;
	VehicleInfo[ i ][ vHydraulics ] = 0;
	VehicleInfo[ i ][ vFrontBumper ] = 0;
	VehicleInfo[ i ][ vRearBumper ] = 0;
	VehicleInfo[ i ][ vVents ] = 0;
	VehicleInfo[ i ][ vPaintJob ] = 255;
	VehicleInfo[ i ][ vProvera ] = -1;
	#if nerp_droga == 1
	VehicleInfo[ i ][ vDrug ][ 0 ] = 0;
	VehicleInfo[ i ][ vDrug ][ 1 ] = 0;
	VehicleInfo[ i ][ vDrug ][ 2 ] = 0;
	VehicleInfo[ i ][ vDrug ][ 3 ] = 0;
	VehicleInfo[ i ][ vDrug ][ 4 ] = 0;
	VehicleInfo[ i ][ vDrug ][ 5 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 0 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 1 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 2 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 3 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 4 ] = 0;
	VehicleInfo[ i ][ vDrugCode ][ 5 ] = 0;
	#endif
	VehicleInfo[ i ][ vMaterijali ] = 0;
	VehicleInfo[ i ][ vMelee ] = 0;
	VehicleInfo[ i ][ vWeap1 ] = 0;
	VehicleInfo[ i ][ vAmmo1 ] = 0;
	VehicleInfo[ i ][ vWeap2 ] = 0;
	VehicleInfo[ i ][ vAmmo2 ] = 0;
	VehicleInfo[ i ][ vGajbica ][ 0 ] = -1;
	VehicleInfo[ i ][ vGajbica ][ 1 ] = -1;
	VehicleInfo[ i ][ vGajbica ][ 2 ] = -1;
	VehicleInfo[ i ][ vGajbica ][ 3 ] = -1;
	VehicleInfo[ i ][ vGajbica ][ 4 ] = -1;
	VehicleInfo[ i ][ vGajbicaAmmount ][ 0 ] = 0;
	VehicleInfo[ i ][ vGajbicaAmmount ][ 1 ] = 0;
	VehicleInfo[ i ][ vGajbicaAmmount ][ 2 ] = 0;
	VehicleInfo[ i ][ vGajbicaAmmount ][ 3 ] = 0;
	VehicleInfo[ i ][ vGajbicaAmmount ][ 4 ] = 0;
	VehicleInfo[ i ][ vNeaktivnost ] = 0;
	VehicleInfo[ i ][ vKilometri ] = 0;
	VehicleInfo[ i ][ vMetri ] = 0;
	VehicleInfo[ i ][ vID ] = -1;
	SetVehicleLabels(i);
}
//------------------------------------------------------------------------------
stock ObrisiVozilo( autoid )
{
	new string[64];
	format(string, sizeof(string), V_FILE, autoid);
	if( fexist( string ) ) { fremove(string); }
	return 1;
}
//------------------------------------------------------------------------------
stock KreirajInterijer(ime[], Float:XUlaz, Float:YUlaz, Float:ZUlaz, Float:XIzlaz, Float:YIzlaz, Float:ZIzlaz, eIntID, IntIDx, vwID, vwIDx)
{
	printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",ime,XUlaz,YUlaz,ZUlaz);
	intide++;
	strmid(IntInfo[intide][iIme], ime, 0, strlen(ime), 255);
	printf("Interior '%s' has an id %d.",ime,intide);
	IntInfo[intide][iXUlaz] = XUlaz;
	IntInfo[intide][iYUlaz] = YUlaz;
	IntInfo[intide][iZUlaz] = ZUlaz;
	IntInfo[intide][iXIzlaz] = XIzlaz;
	IntInfo[intide][iYIzlaz] = YIzlaz;
	IntInfo[intide][iZIzlaz] = ZIzlaz;
	IntInfo[intide][iIntID] = eIntID;
	IntInfo[intide][iIntIDSpolja] = IntIDx;
	IntInfo[intide][iVwID] = vwID;
	IntInfo[intide][iVwIDSpolja] = vwIDx;
	return 1;
}

stock KreirajInterijerEx(ime[], Float:XUlaz, Float:YUlaz, Float:ZUlaz, Float:XIzlaz, Float:YIzlaz, Float:ZIzlaz, eIntID, IntIDx, vwID, vwIDx)
{
	printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",ime,XUlaz,YUlaz,ZUlaz);
	intide++;
	strmid(IntInfo[intide][iIme], ime, 0, strlen(ime), 255);
	printf("Interior '%s' has an id %d.",ime,intide);
	IntInfo[intide][iXUlaz] = XUlaz;
	IntInfo[intide][iYUlaz] = YUlaz;
	IntInfo[intide][iZUlaz] = ZUlaz;
	IntInfo[intide][iXIzlaz] = XIzlaz;
	IntInfo[intide][iYIzlaz] = YIzlaz;
	IntInfo[intide][iZIzlaz] = ZIzlaz;
	IntInfo[intide][iIntID] = eIntID;
	IntInfo[intide][iIntIDSpolja] = IntIDx;
	IntInfo[intide][iVwID] = vwID;
	IntInfo[intide][iVwIDSpolja] = vwIDx;
	new ulaz_label_string[300];
	format(ulaz_label_string,sizeof(ulaz_label_string),""col_balkanstory"[ %s ]\n"col_white"Da udjete u interijer, stisnite:\n\n[ F ]",ime);
	Create3DandP(ulaz_label_string, XUlaz,YUlaz,ZUlaz, -1, -1, 19133, 2.0);
	Create3DandP(""col_balkanstory"[ IZLAZ ]\n"col_white"Da izadjete iz interijera, stisnite:\n\n[ F ]", XIzlaz,YIzlaz,ZIzlaz, -1, -1, 19133, 2.0);
	return 1;
}
//KreirajInterijerEx("KLADIONICA",1691.2272,-1343.2809,17.4297,1670.3978,-1340.6511,20163.0254,0,0,0,0);
//------------------------------------------------------------------------------
CMD:trenutnivw(playerid,params[])
{
	new virtualworldid = GetPlayerVirtualWorld(playerid);
	SendInfoMessage(playerid,"Vas trenutni virtual world id je: %i",virtualworldid);
	return 1;
}
stock LoadVehicles( )
{

	for( new i = 1; i < MAX_CARS; i++ )
	{
		printf("[NE:RP] - Nova Era | Ucitavanje sistema za vozila pod sektorom : %i",i);
		VehicleInfo[ i ][ vID ] = -1;
		new vFile[50];
		format( vFile, sizeof( vFile ), V_FILE, i );
		if( fexist( vFile ) )
		{
		
			INI_ParseFile( vFile, "OcitajVozilo", .bExtra = true, .extra = i );
			VehicleInfo[ i ][ vID ] = -1;
			VehicleInfo[ i ][ vProvera ] = i;
			VehicleInfo[ i ][ Validv3DText ] = false;
			if( VehicleInfo[ i ][ vModel ] != 0 )
			{
			
				VehicleInfo[ i ][ vID ] = Dimi_CreateVehicle( i, VehicleInfo[ i ][ vUsage ], VehicleInfo[ i ][ vOrganization ], VehicleInfo[ i ][ vJob ], VehicleInfo[ i ][ vFuelProperty ], VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ]+1.0, VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], 300000 );
				LinkVehicleToInterior( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vInterior ] );
				SetVehicleVirtualWorld( VehicleInfo[ i ][ vID ], VehicleInfo[ i ][ vVirtualWorld ] );
				vCanDrive[ VehicleInfo[ i ][ vID ] ] = 1; 
				
				if( VehicleInfo[ i ][ vFuelType ] == 0 )
				{
				
					if( VoziloJeDizel( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 1;
					else if( VoziloJeBenzin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 2;
					else if( VoziloJeKerozin( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 3;
					else if( VoziloNemaGorivo( VehicleInfo[ i ][ vID ] ) ) VehicleInfo[ i ][ vFuelType ] = 4;
				}
				
				SetVehicleParamsEx( VehicleInfo[ i ][ vID ], 0, 0, 0, VehicleInfo[ i ][ vLocked ], 0, 0, 0 );
				if( IsVehicleBajs( VehicleInfo[ i ][ vID ] ) )
				{
					SetVehicleParamsEx( VehicleInfo[ i ][ vID ], 1, 0, 0, VehicleInfo[ i ][ vLocked ], 0, 0, 0 );
				}
				ResetVehicleStatistics( VehicleInfo[ i ][ vID ] );
				VehicleInfo[ i ][ vFuel ] = getAmountFuel( VehicleInfo[ i ][ vID ] );

				if( VehicleInfo[ i ][ vUsage ] == PRIVATNO_VOZILO )
				{
					Fuel[ VehicleInfo[ i ][ vID ] ] = VehicleInfo[ i ][ vFuel ];
				}
				else if( VehicleInfo[ i ][ vUsage ] == NAPRODAJU_VOZILO )
				{
					Fuel[ VehicleInfo[ i ][ vID ] ] = VehicleInfo[ i ][ vFuel ];
				}
				else if( VehicleInfo[ i ][ vUsage ] == POSLOVNO_VOZILO )
				{
					VehicleInfo[ i ][ vFuel ] = 100;
					Fuel[ VehicleInfo[ i ][ vID ] ] = 100;
				}
				else
				{
					Fuel[ VehicleInfo[ i ][ vID ] ] = getAmountFuel( VehicleInfo[ i ][ vID ] );
				}
			
				SetVehicleLabels( i );
			
				new h = VehicleInfo[ i ][ vID ];
				if( VehicleInfo[ i ][ vReg ] == 1 )
				{
					SetTablice( h );
				}
				else if( VehicleInfo[ i ][ vReg ] == 2 )
				{
					SetVehicleNumberPlate( h, VehicleInfo[ i ][ vTablice ] );
				}
				else
				{
					SetVehicleNumberPlate( h, "NEMA" );
				}
				
				TuneVehicle( i );
				SaveVehicle( i );
				
				#if NERP_ZIMSKI_MOD  == 1 //izbaceno jer nije zima :D
				if( VehicleInfo[ i ][ vUsage ] == POSLOVNO_VOZILO && VehicleInfo[ i ][ vJob ] == POSAO_KOMUNALAC && VehicleInfo[ i ][ vModel ] == 455 ) {

					SnowObjects[ VehicleInfo[ i ][ vID ] ] = true;

					SnowObject1[ VehicleInfo[ i ][ vID ] ] = CreateDynamicObject( 19601, 0, 0, 1500, 0, 0, 0 );
					AttachDynamicObjectToVehicle( SnowObject1[ VehicleInfo[ i ][ vID ] ], VehicleInfo[ i ][ vID ], 0.000000, 4.200001, -1.049999, 13.500000, 0.000000, 180.000 );
						
					SnowObject2[ VehicleInfo[ i ][ vID ] ] = CreateDynamicObject( 18646, 0, 0, 1500, 0, 0, 0 );
					AttachDynamicObjectToVehicle( SnowObject2[ VehicleInfo[ i ][ vID ] ], VehicleInfo[ i ][ vID ], 0.749999, 1.575000, 1.725000, 0.000000, 0.000000, 0.000000 );

				}
				#endif
			}
			else if( VehicleInfo[ i ][ vModel ] == 0 ) {
			
				ResetVehicle( i );
				ObrisiVozilo( i );
				fremove( V_FILE );
			}
			//printf( "AddStaticVehicle_V( %d, %f, %f, %f, %f, %d, %d, %d, %d, %d )", VehicleInfo[ i ][ vModel ], VehicleInfo[ i ][ vLokacijaX ], VehicleInfo[ i ][ vLokacijaY ], VehicleInfo[ i ][ vLokacijaZ ], VehicleInfo[ i ][ vLokacijaA ], VehicleInfo[ i ][ vColor1 ], VehicleInfo[ i ][ vColor2 ], VehicleInfo[ i ][ vUsage ], VehicleInfo[ i ][ vOrganization ], VehicleInfo[ i ][ vJob ] );
			SetVehicleLabels(i);
		}
	}
}
//------------------------------------------------------------------------------
stock GetVehicleZone(h, zone[], len)
{
	new Float:x22, Float:y22;

	new Float:x,
		Float:y,
		Float:z;

	GetVehiclePos(h, x, y, z);

	x22 = x; y22 = y;
	for( new i = 0; i != sizeof(gSAZones); i++ )
	{
		if(x22 >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x22 <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y22 >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y22 <= gSAZones[ i ][SAZONE_AREA][4])
		{
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0);
		}
	}
	return 0;
}
//------------------------------------------------------------------------------

stock WarTDControl( playerid, bool:show ) {
	if( show == true ) {
		/*WARTextDraw[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid,640.000000, 220.000000, "          ");
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 0 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 0 ], 1);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 0 ], 0.500000, 1.000000);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 0 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 0 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 0 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 0 ], 1);
		PlayerTextDrawUseBox(playerid,WARTextDraw[ playerid ][ 0 ], 1);
		PlayerTextDrawBoxColor(playerid,WARTextDraw[ playerid ][ 0 ], 150);
		PlayerTextDrawTextSize(playerid,WARTextDraw[ playerid ][ 0 ], 500.000000, 40.000000);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 0 ], 0);*/

		WARTextDraw[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid,567.000000, 220.000000, "WAR");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 1 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 1 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 1 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 1 ], 0.419999, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 1 ], UGBOJA );
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 1 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 1 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 1 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 1 ], 0);

		WARTextDraw[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid,568.000000, 227.000000, "-");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 2 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 2 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 2 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 2 ], 12.080010, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 2 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 2 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 2 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 2 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 2 ], 0);

		WARTextDraw[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid,527.000000, 234.000000, "Tim 1");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 3 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 3 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 3 ], 3);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 3 ], 0.360000, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 3 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 3 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 3 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 3 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 3 ], 0);

		WARTextDraw[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid,608.000000, 234.000000, "Tim 2");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 4 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 4 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 4 ], 3);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 4 ], 0.360000, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 4 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 4 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 4 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 4 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 4 ], 0);

		WARTextDraw[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid,506.000000, 248.000000, "Ubistva: 100~n~Smrti: 100~n~Igraci: 10");
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 5 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 5 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 5 ], 0.230000, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 5 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 5 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 5 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 5 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 5 ], 0);

		WARTextDraw[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid,573.000000, 248.000000, "Ubistva: 100~n~Smrti: 100~n~Igraci: 10");
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 6 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 6 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 6 ], 0.230000, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 6 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 6 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 6 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 6 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 6 ], 0);

		WARTextDraw[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid,568.000000, 275.000000, "-");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 7 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 7 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 7 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 7 ], 12.080010, 0.899999);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 7 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 7 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 7 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 7 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 7 ], 0);

		WARTextDraw[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid,567.000000, 284.000000, "10:00");
		PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 8 ], 2);
		PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 8 ], 255);
		PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 8 ], 2);
		PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 8 ], 0.459999, 1.300000);
		PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 8 ], -1);
		PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 8 ], 0);
		PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 8 ], 1);
		PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 8 ], 1);
		PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 8 ], 0);


		for( new i = 0; i < 9; i ++) {
			PlayerTextDrawShow( playerid, WARTextDraw[ playerid ][ i ] );
		}

	}
	else if( show == false ) {
		for( new i = 0; i < 9; i ++ ) {
			PlayerTextDrawHide( playerid, WARTextDraw[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, WARTextDraw[ playerid ][ i ] );
			WARTextDraw[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
	}
}

stock SetWarStatsTD( w ) {
	new string[ 128 ], stringcic[ 10 ];
	for(new id; id < MAX_PLAYERS; id++) {
		if( WARPInfo[ id ][ WARIgrac ] == w ) {
			format( string ,sizeof( string ),"~w~Ubistva: ~y~%d~n~~w~Smrti: ~r~%d~n~~w~Igraci: ~y~%d", WARInfo[ w ][ WARTimSkor ][ 0 ], WARInfo[ w ][ WARTimSkor ][ 1 ], WARInfo[ w ][ WARTimClanovi ][ 0 ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 5 ],  string );
			format( string ,sizeof( string ),"~w~Ubistva: ~y~%d~n~~w~Smrti: ~r~%d~n~~w~Igraci: ~y~%d", WARInfo[ w ][ WARTimSkor ][ 1 ], WARInfo[ w ][ WARTimSkor ][ 0 ], WARInfo[ w ][ WARTimClanovi ][ 1 ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 6 ],  string );
			format( stringcic, sizeof( stringcic ), "%s", OI[ PlayerInfo[ WARInfo[ w ][ WARTimLider ][ 0 ] ][ xLider ] ][ oPreFix ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 3 ],  stringcic );
			format( stringcic, sizeof( stringcic ), "%s", OI[ PlayerInfo[ WARInfo[ w ][ WARTimLider ][ 1 ] ][ xLider ] ][ oPreFix ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 4 ],  stringcic );
		}
	}
}

stock DestroyPlayerTextDraws( playerid ) {

	if( ShowedRegister[ playerid ] == true ) {
		for( new i = 0; i < 14; i ++) {//counting ok
			PlayerTextDrawHide( playerid, RegisterTD[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, RegisterTD[ playerid ][ i ] );
			RegisterTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}

		ShowedRegister[ playerid ] = false;
		//counting3
	/*	for( new i = 0; i < 29; i ++) {
			PlayerTextDrawHide( playerid, LoginTD[ playerid ][ i ] );
			PlayerTextDrawDestroy( playerid, LoginTD[ playerid ][ i ] );
			LoginTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}*/
		
		
		//
	}
	for( new i = 0; i < 8; i ++)
	{
		PlayerTextDrawDestroy( playerid, TaxistaTD[ playerid ][ i ] );
		TaxistaTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
	}

	for( new i = 0; i < 3; i ++)
	{
		PlayerTextDrawDestroy( playerid, KILOMETARSATPLAYER[ playerid ][ i ] );
		KILOMETARSATPLAYER[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
	}
	for( new i = 0; i < 24; i ++)
	{
		PlayerTextDrawDestroy( playerid, KILOMETARSATTD[ playerid ][ i ] );
		KILOMETARSATTD[ playerid ][ i ] = PlayerText:INVALID_TEXT_DRAW;
	}




	PlayerTextDrawDestroy( playerid, JailTD[ playerid ] );
	JailTD[ playerid ] = PlayerText:INVALID_TEXT_DRAW;


	PlayerTextDrawDestroy( playerid, GladIgraca[ playerid ] );
	GladIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	
	PlayerTextDrawDestroy( playerid, WcIgraca[ playerid ] );
	WcIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	
	PlayerTextDrawDestroy( playerid, LokacijaIgracaTD[ playerid ] );
	LokacijaIgracaTD[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	
	PlayerTextDrawDestroy( playerid, GradIgracaTD[ playerid ] );
	GradIgracaTD[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	
	/*PlayerTextDrawDestroy( playerid, BankaIgraca[ playerid ] );
	BankaIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	PlayerTextDrawDestroy( playerid, ZlatoIgraca[ playerid ] );
	ZlatoIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;*/
	//PlayerTextDrawDestroy( playerid, PlataIgraca[ playerid ] );
	//PlataIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
	PlayerTextDrawDestroy( playerid, WantedIgraca[ playerid ] );
	WantedIgraca[ playerid ] = PlayerText:INVALID_TEXT_DRAW;
}


stock WeaponTextDrawControl(playerid, bool:control)
{
	if(control == true)
	{

		for(new i = 0; i < 10; i++ )
		{
			PlayerTextDrawShow(playerid, OruzjeIgraca[playerid][i]);
		}
	}
	else if(control == false)
	{
		for(new i = 0; i < 10; i++ )
		{
			PlayerTextDrawHide(playerid, OruzjeIgraca[playerid][i]);
			//PlayerTextDrawDestroy(playerid, OruzjeIgraca[playerid][i]);
		}
		//CancelSelectTextDraw(playerid);
	}
	return 1;
}

stock BanTextDrawControl(playerid, bool:control)
{
	if(control == true)
	{
		BanTD[playerid][0] = CreatePlayerTextDraw(playerid, 627.333312, 1.500000, "usebox");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][0], 0.000000, 49.405799);
		PlayerTextDrawTextSize(playerid, BanTD[playerid][0], 342.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][0], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][0], 0);
		PlayerTextDrawUseBox(playerid, BanTD[playerid][0], true);
		PlayerTextDrawBoxColor(playerid, BanTD[playerid][0], 102);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][0], 0);
		PlayerTextDrawFont(playerid, BanTD[playerid][0], 0);

		BanTD[playerid][1] = CreatePlayerTextDraw(playerid, 370.222198, 40.817771, "Banovani ste...");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][1], 0.600666, 4.502044);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][1], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][1], tdboja);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][1], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][1], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][1], 3);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][1], 1);

		BanTD[playerid][2] = CreatePlayerTextDraw(playerid, 359.111083, 40.817775, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][2], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BanTD[playerid][2], 8.000061, 47.288890);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][2], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][2], tdboja);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][2], 0);
		PlayerTextDrawFont(playerid, BanTD[playerid][2], 4);

		BanTD[playerid][3] = CreatePlayerTextDraw(playerid, 360.444458, 86.115554, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][3], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BanTD[playerid][3], 256.888732, 1.493334);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][3], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][3], tdboja);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][3], 0);
		PlayerTextDrawFont(playerid, BanTD[playerid][3], 4);

		BanTD[playerid][4] = CreatePlayerTextDraw(playerid, 358.222229, 115.484443, "- Postovani, vas racun je suspendovan sa servera!");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][4], 0.176222, 1.326221);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][4], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][4], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][4], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][4], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][4], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][4], 1);

		BanTD[playerid][5] = CreatePlayerTextDraw(playerid, 359.555541, 166.755554, "Vise informacija");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][5], 0.449999, 1.600000);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][5], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][5], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][5], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][5], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][5], 0);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][5], 1);

		BanTD[playerid][6] = CreatePlayerTextDraw(playerid, 449.777801, 175.217773, "LD_SPAC:white");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][6], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, BanTD[playerid][6], 166.222198, 1.991119);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][6], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][6], tdboja);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][6], 0);
		PlayerTextDrawFont(playerid, BanTD[playerid][6], 4);

		BanTD[playerid][7] = CreatePlayerTextDraw(playerid, 364.000000, 202.595550, "- Ime: /, na datum: /");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][7], 0.201111, 1.371022);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][7], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][7], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][7], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][7], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][7], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][7], 1);

		BanTD[playerid][8] = CreatePlayerTextDraw(playerid, 363.111114, 223.004455, "- Razlog:");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][8], 0.170889, 1.485509);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][8], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][8], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][8], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][8], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][8], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][8], 1);

		BanTD[playerid][9] = CreatePlayerTextDraw(playerid, 610.000000, 136.895553, "usebox");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][9], 0.000000, 2.172223);
		PlayerTextDrawTextSize(playerid, BanTD[playerid][9], 525.111145, 0.000000);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][9], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][9], 0);
		PlayerTextDrawUseBox(playerid, BanTD[playerid][9], true);
		PlayerTextDrawBoxColor(playerid, BanTD[playerid][9], 102);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][9], 0);
		PlayerTextDrawFont(playerid, BanTD[playerid][9], 0);

		BanTD[playerid][10] = CreatePlayerTextDraw(playerid, 568.888793, 138.382232, "POSALJI ZAHTJEV ZA ~n~UNBAN ACCOUNTA");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][10], 0.170888, 0.878222);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][10], 2);
		PlayerTextDrawColor(playerid, BanTD[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][10], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][10], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][10], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][10], 1);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][10], 1);
		PlayerTextDrawSetSelectable(playerid, BanTD[playerid][10], true);

		BanTD[playerid][11] = CreatePlayerTextDraw(playerid, 352.888824, 261.333312, "- Vas racun je, ukoliko administracija ne intervenise, permanentno suspendovan sa servera.");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][11], 0.118888, 1.296356);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][11], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][11], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][11], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][11], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][11], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][11], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][11], 1);

		BanTD[playerid][12] = CreatePlayerTextDraw(playerid, 356.000000, 285.724365, "Ukoliko mislite da je doslo do greske, obratite nam se na Discordu, ili forumu.");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][12], 0.140222, 1.246578);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][12], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][12], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][12], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][12], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][12], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][12], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][12], 1);

		BanTD[playerid][13] = CreatePlayerTextDraw(playerid, 356.000000, 301.653350, "Da apelujete svoju suspenziju, slikajte vas ekran (F8) i posaljite nam,~n~nakon toga kliknite na 'Posalji zahtjev za unban'.");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][13], 0.147333, 0.898133);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][13], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][13], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][13], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][13], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][13], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][13], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][13], 1);

		BanTD[playerid][14] = CreatePlayerTextDraw(playerid, 356.444427, 332.515563, "Hvala na razumjevanju,~n~Staff Team.");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][14], 0.449999, 1.600000);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][14], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][14], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][14], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][14], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][14], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][14], 1);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][14], 1);

		BanTD[playerid][15] = CreatePlayerTextDraw(playerid, 356.888885, 270.293304, "zbog violacije pravila Nova Era:OGC zajednice!");
		PlayerTextDrawLetterSize(playerid, BanTD[playerid][15], 0.111333, 1.385954);
		PlayerTextDrawAlignment(playerid, BanTD[playerid][15], 1);
		PlayerTextDrawColor(playerid, BanTD[playerid][15], -1);
		PlayerTextDrawSetShadow(playerid, BanTD[playerid][15], 0);
		PlayerTextDrawSetOutline(playerid, BanTD[playerid][15], 1);
		PlayerTextDrawBackgroundColor(playerid, BanTD[playerid][15], 51);
		PlayerTextDrawFont(playerid, BanTD[playerid][15], 2);
		PlayerTextDrawSetProportional(playerid, BanTD[playerid][15], 1);

		SelectTextDraw(playerid, tdboja);

		new p_string[256];

		format(p_string, sizeof p_string, "- Ime: %s, na datum: %i/%i/%i", 
			ImeIgraca(playerid), 
			PlayerInfo[playerid][xBDatum][0],
			PlayerInfo[playerid][xBDatum][1],
			PlayerInfo[playerid][xBDatum][2]);

		PlayerTextDrawSetString(playerid, BanTD[playerid][7], p_string);

		format(p_string, sizeof p_string, "- Razlog: %s", 
			PlayerInfo[playerid][xBReason]); 

		PlayerTextDrawSetString(playerid, BanTD[playerid][8], p_string);

		for(new i = 0; i < 20; i++ )
		{
			PlayerTextDrawShow(playerid, BanTD[playerid][i]);
		}
	}
	else if(control == false)
	{
		for(new i = 0; i < 20; i++ )
		{
			PlayerTextDrawHide(playerid, BanTD[playerid][i]);
			PlayerTextDrawDestroy(playerid, BanTD[playerid][i]);
		}

		CancelSelectTextDraw(playerid);
	}
	return 1;
}

//------------------------------------------------------------------------------
/*stock OnePlayAnim( playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	ApplyAnimation( playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp);
}*/
//------------------------------------------------------------------------------
stock UlicaImanja( id ) {
	new imeulice[ MAX_ZONE_NAME ];
	UlicaImanja2( id, imeulice, sizeof( imeulice ) );
	return imeulice;
}
//------------------------------------------------------------------------------
stock UlicaImanja2(id, zone[], len) {
	new Float:x22, Float:y22;
	x22 = fieldInfo[ id ][ fieldObjectPos ][ 0 ]; y22 = fieldInfo[ id ][ fieldObjectPos ][ 1 ];
	for( new i = 0; i != sizeof(gSAZones); i++ ) {
		if(x22 >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x22 <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y22 >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y22 <= gSAZones[ i ][SAZONE_AREA][4]) {
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0); } }
	return 0;
}
//------------------------------------------------------------------------------
stock UliceFirme( h ) {
	new imeulice[ MAX_ZONE_NAME ];
	UliceFirme2( h, imeulice, sizeof( imeulice ) );
	return imeulice;
}
//------------------------------------------------------------------------------
stock UliceFirme2(h, zone[], len) {
	new Float:x22, Float:y22;
	x22 = BussinesInfo[ h ][ bEnterX ]; y22 = BussinesInfo[ h ][ bEnterY ];
	for( new i = 0; i != sizeof(gSAZones); i++ ) {
		if(x22 >= gSAZones[ i ][SAZONE_AREA][ 0 ] && x22 <= gSAZones[ i ][SAZONE_AREA][ 3 ] && y22 >= gSAZones[ i ][SAZONE_AREA][ 1 ] && y22 <= gSAZones[ i ][SAZONE_AREA][4]) {
			return format(zone, len, gSAZones[ i ][SAZONE_NAME], 0); } }
	return 0;
}
//------------------------------------------------------------------------------
stock RPImeIgraca( id ) {
	new ime[ MAX_PLAYER_NAME ];
	GetPlayerName( id, ime, sizeof ime);
	return ime;
}
//------------------------------------------------------------------------------
stock ImeIgraca( id ) {
	new ime[ MAX_PLAYER_NAME ];
	if( Maskuse[ id ] == true ) format( ime, sizeof( ime ), "%s", RealName[ id ] );
	else GetPlayerName( id, ime, sizeof ime);
	return ime;
}

CMD:crash(playerid, params[])
{
	if(PlayerInfo[playerid][xAdmin] < 1338) return greska(playerid, "Vi ne mozete koristiti ovu komandu!");
	new giveplayerid;
	if(sscanf(params, "u", giveplayerid)) return SendUsageMessage(playerid, "/crash [ID / deo imena]");
	if(!IsPlayerConnected(giveplayerid)) return greska(playerid, "Taj igrac nije online!");

	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 1000, 0);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 2000, 1);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 3000, 2);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 4000, 3);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 5000, 4);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 6000, 5);
	announcement(giveplayerid, "??!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/�����", 7000, 6);
	return 1;
}
//------------------------------------------------------------------------------
GetNearestContainer( playerid )
{
	for( new b = 1; b < MAX_KONT; b++ )
	{
		if( IsPlayerInRangeOfPoint( playerid, 4.0, KontInfo[b][koObjPos][ 0 ], KontInfo[b][koObjPos][ 1 ], KontInfo[b][koObjPos][2 ] ) ) return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestStreet( playerid )
{
	for( new b = 1; b < MAX_STREETS; b++ )
	{
		new st = b;
		if( IsPlayerInRangeOfPoint( playerid, 4.0, streetInfo[st][streetObjPos][0],streetInfo[st][streetObjPos][1],streetInfo[st][streetObjPos][2] ) ) return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestDealer( playerid )
{
	for( new b = 0; b < MAX_DEALERS; b++ )
	{
		if( IsPlayerInRangeOfPoint( playerid, 4.0, 
			DealerInfo[b][dealerPos][0],
			DealerInfo[b][dealerPos][1],
			DealerInfo[b][dealerPos][2] ) ) return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestRent( playerid )
{
	for( new b = 1; b < MAX_RENTS; b++ )
	{
		new st = b;
		if( IsPlayerInRangeOfPoint( playerid, 4.0, rentInfo[st][rentObjPos][0],rentInfo[st][rentObjPos][1],rentInfo[st][rentObjPos][2] ) ) return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestDeadBody( playerid )
{
	for( new b = 1; b < MAX_BODIES; b++ )
	{
		if( IsPlayerInRangeOfPoint( playerid, 4.0, bodyInfo[b][bodyObjPos][ 0 ], bodyInfo[b][bodyObjPos][ 1 ], bodyInfo[b][bodyObjPos][2] ) ) return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
GetNearestAtm( playerid )
{
	for( new b = 1; b < sizeof(atmInfo); b++){
		if( IsPlayerInRangeOfPoint( playerid, 4.0, atmInfo[b][atmPos][ 0 ], atmInfo[b][atmPos][ 1 ], atmInfo[b][atmPos][2 ] ) ) return b; }
	return -1;
}
//------------------------------------------------------------------------------
GetNearestBussines( playerid ) {
	for( new b = 1; b < sizeof(BussinesInfo); b++) {
		if( IsPlayerInRangeOfPoint( playerid, 3.0, BussinesInfo[b][bEnterX], BussinesInfo[b][bEnterY], BussinesInfo[b][bEnterZ ] ) ) return b; }
	return -1;
}
GetNearestBussines2( playerid ) {
	for( new b = 1; b < sizeof(BussinesInfo); b++) {
		if( IsPlayerInRangeOfPoint( playerid, 6.0, BussinesInfo[b][bEnterX], BussinesInfo[b][bEnterY], BussinesInfo[b][bEnterZ ] ) ) return b; }
	return -1;
}
//------------------------------------------------------------------------------
GetNearestTrafika( playerid )
{
	for( new b = 1; b < sizeof(BussinesInfo); b++)
	{
		if( BussinesInfo[ b ][ bType ] == VRSTA_TRAFIKA && IsPlayerInRangeOfPoint( playerid, 6.0, BussinesInfo[b][bEnterX], BussinesInfo[b][bEnterY], BussinesInfo[b][bEnterZ ] ) )
		return b;
	}
	return -1;
}
//------------------------------------------------------------------------------
stock NextHotelID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), HOTEL_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock NextGateID(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), GATE_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock SledeciIDFirme(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), F_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock SledeciIDImovine(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), IM_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
stock SledeciIDSalona(const len) {
	new id = (-1);
	for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
	   provjera = ( loop+1 );
	   format( Data_, ( sizeof Data_ ), AS_FILE, provjera );
	   if(!fexist(Data_)) {
		  id = ( provjera );
		  break; } }
	return ( id );
}
//------------------------------------------------------------------------------
SoundForAll( sound )
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if( IsPlayerConnected( i ) ) PlayerPlaySound( i, sound, 0.0, 0.0, 0.0 );
	}
}
//------------------------------------------------------------------------------
stock AdminPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}
/*
stock AdminAltPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}*/

stock DJPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xDJ ] >= 1 ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}

stock GrudvanjePoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( Snow_F[ i ] ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}

/*stock EventPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || PlayerCP[ i ] > 0 ) {
				SendClientMessagee( i, color, string ); } } }
	return true;
}*/
stock AdminSMS( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] ) {
				if(GetPVarInt( i, "ToggedPM") == 0) {
					SendClientMessage( i, color, string ); } } } }
	return true;
}
stock AdminWisper( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] ) {
				if(GetPVarInt( i, "ToggedWISP") == 0) {
					SendClientMessage( i, color, string ); } } } }
	return true;
}
stock AdminRPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] ) {
				if(GetPVarInt( i, "ToggedReport") == 0) {
					SendClientMessage( i, color, string ); } } } }
	return true;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
stock RPTPoruka( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1337 || RconAdmin[ i ] || PlayerInfo[ i ][ xHelper ] >= 1 ) {
				if(GetPVarInt( i, "ToggedPomoc") == 0) {
					SendClientMessage( i, color, string ); } } } }
	return true;
}
stock RPTChat( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] || PlayerInfo[ i ][ xHelper ] >= 1 ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}
stock RPTChatPlus( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] || PlayerInfo[ i ][ xHelper ] >= 2 ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}
stock PROMChat( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] || PlayerInfo[ i ][ xHelper ] >= 1 || PlayerInfo[ i ][ xVIPLevel ] >= 1 ) {
				if(GetPVarInt( i, "ToggedG") == 0) {
					SendClientMessage( i, color, string ); } } } }
	return true;
}
/*        if( PlayerInfo[ playerid ][ xLevel ] < 10 )
		{
			format( string1, sizeof( string1 ), "[ C-NEWBIE ] - "SERVERBOJA_SC"(( Novi igrac - %s: %s ))", ImeIgraca( playerid ), text );
		}
		if( PlayerInfo[ playerid ][ xLevel ] == 10 )
		{
			format( string1, sizeof( string1 ), "[ C-NEWBIE ] - "SERVERBOJA_SC"(( Igrac - %s: %s ))", ImeIgraca( playerid ), text );
		}
		else if( PlayerInfo[ playerid ][ xHelper ] >= 1 || PlayerInfo[ playerid ][ xAdmin ] >= 1 || PlayerInfo[ playerid ][ xPromoter ] == 2 )
		{
			format( string1, sizeof( string1 ), "[ C-NEWBIE ] - "SERVERBOJA_SCZ"(( STAFF - %s:"SERVERBOJA_BJELA" %s "SERVERBOJA_SCZ"))", ImeIgraca( playerid ), text );
		}*/
stock NChat( color, string[] ) {
	for( new i = 0; i < MAX_PLAYERS; i++) {
		if( IsPlayerConnected( i ) ) {
			if( PlayerInfo[ i ][ xTogn ] == 1 ) {
				SendClientMessage( i, color, string ); } } }
	return true;
}

stock PromoteriAdminChat( color, string[] ) {

	for( new i = 0; i < MAX_PLAYERS; i++) {
	
		if( IsPlayerConnected( i ) ) {
		
			if( PlayerInfo[ i ][ xAdmin ] >= 1 || RconAdmin[ i ] || PlayerInfo[ i ][ xPromoter ] >= 1 ) {
			
					SendClientMessage( i, color, string );
			}
		}
	}
	return true;
}

//------------------------------------------------------------------------------
stock antiSpeedVehicle( carid ) {
	new v = GetVehicleModel( carid );
	if( v == 593 || v == 592 || v == 577 || v == 553 || v == 520 || v == 519 || v == 511 || v == 460 || v == 563 || v == 548 || v == 497 || v == 488 || v == 487 || v == 469 || v == 447 || v == 417 ) {
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
forward OnPlayerFalla( playerid );
public OnPlayerFalla( playerid )
{
	if( antiCheatCS[ playerid ][ SpeedFall ] ) return 1;

	SetTimerEx( "Reactivate", 8000, false, "i", playerid );
	antiCheatCS[ playerid ][ SpeedFall ] = true;

	return 1;
}

forward FallingChecker( playerid );
public FallingChecker( playerid )
{
	new Float:Pos[ 4 ];

	if( IsPlayerConnected( playerid ) )
	{
		GetPlayerPos( playerid, Pos[ 0 ], Pos[ 1 ], Pos[ 2 ] );
		Pos[ 3 ] = floatsqroot( ( Pos[ 0 ]-antiCheatCS[ playerid ][ SpeedPos ][ 0 ] * Pos[ 0 ]-antiCheatCS[ playerid ][ SpeedPos ][ 0 ] ) + ( Pos[ 1 ]-antiCheatCS[ playerid ][ SpeedPos ][ 1 ] * Pos[ 1 ]-antiCheatCS[ playerid ][ SpeedPos ][ 1 ] ) );

		if( Pos[ 3 ] < 10 && ( antiCheatCS[ playerid ][ SpeedPos ][ 2 ] - Pos[ 2 ] ) > 5 )
		{

			OnPlayerFalla( playerid );
		}
		antiCheatCS[ playerid ][ SpeedPos ][ 0 ] = Pos[ 0 ];
		antiCheatCS[ playerid ][ SpeedPos ][ 1 ] = Pos[ 1 ];
		antiCheatCS[ playerid ][ SpeedPos ][ 2 ] = Pos[ 2 ];
	}
	return 1;
}

forward Reactivate( playerid );
public Reactivate( playerid ) {

	antiCheatCS[ playerid ][ SpeedFall ] = false;

	return 1;
}


//------------------------------------------------------------------------------
public OnPlayerClickMap( playerid, Float:fX, Float:fY, Float:fZ ) {
	if( playerid == INVALID_PLAYER_ID ) return 1;
	if( PlayerInfo[ playerid ][ xAdmin ] >= 1337 && AdminDuty[ playerid ] ) {
		antiCheatCS[ playerid ][ TeleportCheck ] = 4;
		SetPlayerPosFindZ( playerid, fX, fY, fZ );
	}
	return 1;
}
//------------------------------------------------------------------------------
stock Dimi_IsNotWeaponNoAmmo( weaponid ) {
	new slot = g_aWeaponSlots[ weaponid ];
	if( slot != 0 && slot != 1 && slot != 10) return 1;
	return 0;
}

stock Dimi_IsGiveVehicleWeapon( weaponid ) {
	if( weaponid == 46 || weaponid == 2 ) return 1;
	return 0;
}
/*stock Dimi_GetWeaponSlot( weaponid ) {
	new slot = -1;
	switch( weaponid ) {
		case 0,1: slot = 0;
		case 2 .. 9: slot = 1;
		case 10 .. 15: slot = 10;
		case 16 .. 18, 39: slot = 8;
		case 22 .. 24: slot =2;
		case 25 .. 27: slot = 3;
		case 28, 29, 32: slot = 4;
		case 30, 31: slot = 5;
		case 33, 34: slot = 6;
		case 35 .. 38: slot = 7;
		case 40: slot = 12;
		case 41 .. 43: slot = 9;
		case 44 .. 46: slot = 11;
	}
	return slot;
}*/
//------------------------------------------------------------------------------
GiveWeaponToPlayer( playerid, weaponid, ammo ) {

	if( antiCheatCS[ playerid ][ WeaponCheck ] == 1 ) antiCheatCS[ playerid ][ WeaponCheck ] = 2;
	if( IsValidWeapon( weaponid ) ) {

		antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;
		antiCheatCS[ playerid ][ WeaponDetect ] = 3;
		antiCheatCS[ playerid ][ Weapon ][ g_aWeaponSlots[ weaponid ] ] = weaponid;
		antiCheatCS[ playerid ][ Ammo ][ g_aWeaponSlots[ weaponid ] ] += ammo;
		GivePlayerWeapon( playerid, weaponid, ammo );
	}
	if( antiCheatCS[ playerid ][ WeaponCheck ] == 2 ) antiCheatCS[ playerid ][ WeaponCheck ] = 1;

	return 1;
}

/*SetWeaponAmmo( playerid, weapon, ammo ) {

	if(antiCheatCS[ playerid ][ WeaponCheck ] == 1 ) antiCheatCS[ playerid ][ WeaponCheck ] = 2;
	new slot = g_aWeaponSlots[ weapon ];
	if( weapon > 0 && 47 > weapon && slot != -1 ) {
		antiCheatCS[ playerid ][ WeaponDetect ] = 3;
		antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;
		antiCheatCS[ playerid ][ Ammo ][ slot ] = ammo;
		SetPlayerAmmo( playerid, weapon, ammo );
	}
	if( antiCheatCS[ playerid ][ WeaponCheck ] == 2 ) antiCheatCS[ playerid ][ WeaponCheck ] = 1;

	return 1;
}*/


ResetAllWeapons( playerid ) {

	if( antiCheatCS[ playerid ][ WeaponCheck ] == 1 ) antiCheatCS[ playerid ][ WeaponCheck ] = 2;
	for( new i = 0; i < MAX_W_SLOTS; i++ ) {
		antiCheatCS[ playerid ][ WeaponDetect ] = 3;
		antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;
		antiCheatCS[ playerid ][ Weapon ][ i ] = 0;
		antiCheatCS[ playerid ][ Ammo ][ i ] = 0;
	}
	ResetPlayerWeapons(playerid);
	if( antiCheatCS[ playerid ][ WeaponCheck ]==2) antiCheatCS[ playerid ][ WeaponCheck ] = 1;

	return 1;
}
//------------------------------------------------------------------------------
RemovePlayerWeapon( playerid, weaponid ) {

	if( antiCheatCS[ playerid ][ WeaponCheck ] == 1 ) antiCheatCS[ playerid ][ WeaponCheck ] = 2;
	antiCheatCS[ playerid ][ WeaponDetect ] = 3;
	antiCheatCS[ playerid ][ LastAmmoChecks ] = 0;

	ResetPlayerWeapons( playerid );

	for( new i = 0; i < 13; i ++ ) {
		if( antiCheatCS[ playerid ][ Weapon ][ i ] != weaponid ) {
			GivePlayerWeapon( playerid, antiCheatCS[ playerid ][ Weapon ][ i ], antiCheatCS[ playerid ][ Ammo ][ i ] );
		}
		else {
			antiCheatCS[ playerid ][ Weapon ][ i ] = 0;
			antiCheatCS[ playerid ][ Ammo ][ i ] = 0;
		}
	}
	if( antiCheatCS[ playerid ][ WeaponCheck ] == 2 ) antiCheatCS[ playerid ][ WeaponCheck ] = 1;
	return true;
}
//------------------------------------------------------------------------------
stock GetWeapon( playerid ) {

	new weaponid = GetPlayerWeapon( playerid );

	new slot = g_aWeaponSlots[ weaponid ];
	if( IsValidWeapon( weaponid ) && slot != -1 && antiCheatCS[ playerid ][ Weapon ][ slot ] == weaponid )
		return weaponid;

	return 0;
}
//------------------------------------------------------------------------------
stock HavePlayerWeapon( playerid ) {
	switch( GetPlayerWeapon( playerid ) ) {
		case 16..18, 22..39, 41, 42: return true;
	}
	return false;
}
//------------------------------------------------------------------------------
stock GetPlayerWeaponAmmo( playerid, weaponid ) {
	new wd[ 2 ][ 13 ];
	for( new i; i < 13; i++ ) GetPlayerWeaponData( playerid, i, wd[ 0 ][ i ], wd[ 1 ][ i ] );
	for( new i; i < 13; i++ ) {
		if( weaponid == wd[ 0 ][ i ] ) return wd[ 1 ][ i ];
	}
	return 0;
}
//------------------------------------------------------------------------------
////////////////////////////


//------------------------------------------------------------------------------
stock KodSprunk( playerid ) {
		if( IsPlayerInRangeOfPoint( playerid, 4, -2420.219, 984.578, 44.297 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2420.180, 985.945, 44.297 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2225.203, -1153.422, 1025.906 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2576.703, -1284.430, 1061.094 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2155.906, 1606.773, 1000.055 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2209.906, 1607.195, 1000.055 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2222.203, 1606.773, 1000.055 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 495.969, -24.320, 1000.734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 501.828, -1.430, 1000.734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 373.828, -178.141, 1000.734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 330.680, 178.500, 1020.070 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 331.922, 178.500, 1020.070 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 350.906, 206.086, 1008.477 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 361.563, 158.617, 1008.477 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 371.594, 178.453, 1020.070 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 374.891, 188.977, 1008.477 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2155.844, 1607.875, 1000.063 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2202.453, 1617.008, 1000.063 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2209.242, 1621.211, 1000.063 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2222.367, 1602.641, 1000.063 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 500.563, -1.367, 1000.734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 379.039, -178.883, 1000.734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2480.86,-1959.27,12.9609 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1634.11,-2237.53,12.8906 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2139.52,-1161.48,23.3594 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2153.23,-1016.15,62.2344 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -1350.12,493.859,10.5859 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2229.19,286.414,34.7031 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1659.46,1722.86,10.2188 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2647.7,1129.66,10.2188 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2845.73,1295.05,10.7891 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1398.84,2222.61,10.4219 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -1455.12,2591.66,55.2344 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -76.0312,1227.99,19.125 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 662.43,-552.164,15.7109 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -253.742,2599.76,62.2422 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2271.73,-76.4609,25.9609 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1789.21,-1369.27,15.1641 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1729.79,-1943.05,12.9453 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2060.12,-1897.64,12.9297 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1928.73,-1772.45,12.9453 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2325.98,-1645.13,14.2109 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2352.18,-1357.16,23.7734 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1154.73,-1460.89,15.1562 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -1350.12,492.289,10.5859 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2118.97,-423.648,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2118.62,-422.414,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2097.27,-398.336,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2092.09,-490.055,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2063.27,-490.055,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2005.65,-490.055,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2034.46,-490.055,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2068.56,-398.336,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2039.85,-398.336,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -2011.14,-398.336,34.7266 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -1980.79,142.664,27.0703 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2319.99,2532.85,10.2188 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1520.15,1055.27,10.00 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2503.14,1243.7,10.2188 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 2085.77,2071.36,10.4531 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -862.828,1536.61,21.9844 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -14.7031,1175.36,18.9531 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, -253.742,2597.95,62.2422 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 201.016,-107.617,0.898438 ) ) return 1;
		else if( IsPlayerInRangeOfPoint( playerid, 4, 1277.84,372.516,18.9531 ) ) return 1;
		else return 0;
}
//------------------------------------------------------------------------------
stock strreplace(string[], find, replace) {
	for( new i=0; string[ i ]; i++) {
		if(string[ i ] == find) {
			string[ i ] = replace; } }
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

stock SaveZPoruka( orgid, boja, string[] ) 	{

	if( OI[ orgid ][ oSavez ] != -1 ) {
	
		for(new i; i < MAX_PLAYERS; i++) {

			if( ( PlayerInfo[ i ][ xClan ] == orgid || PlayerInfo[ i ][ xClan ] == OI[ orgid ][ oSavez ] ) && PlayerInfo[ i ][ xRank ] >= 5 ) 	{

				SendClientMessagee( i, boja, string );
			}
		}
	}
	return true;
}

stock OrgPoruka(orgid, boja, string[])
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if( PlayerInfo[ i ][ xClan ] == orgid || PlayerInfo[ i ][ xLider ] == orgid || UKLJUCENIFCHAT[ i ] )
		{
			if(GetPVarInt( i, "ToggedFR") == 0)
			{
				SendClientMessage( i, boja, string );
			}
		}
	}
	return true;
}
stock OrgPorukaLeader( orgid, boja, string[] ) 	{
	for(new i; i < MAX_PLAYERS; i++) {
		if( PlayerInfo[ i ][ xLider ] == orgid ) 	{
			SendClientMessage(  i, boja, string );
		}
	}
	return true;
}
stock OrgPorukaMD(orgid, boja, string[]) 	{
	for(new i; i < MAX_PLAYERS; i++) {
		if( PlayerInfo[ i ][ xClan ] == orgid || PlayerInfo[ i ][ xLider ] == orgid ) 	{
			if(GetPVarInt( i, "ToggedFR") == 0) {
				if( MedicDuty[ i ] == true ) {
					SendClientMessage( i, boja, string ); } } } }
	return true;
}
//------------------------------------------------------------------------------
stock OrgPoruka1(orgid, boja, string[]) 	{
	for(new i; i < MAX_PLAYERS; i++) {
		if( PlayerInfo[ i ][ xClan ] == orgid || PlayerInfo[ i ][ xLider ] == orgid ) 	{
			if(GetPVarInt( i, "ToggedDC") == 0) {
				SendClientMessage( i, boja, string ); } } }
	return true;
}
//------------------------------------------------------------------------------
GetNearestOrganization( playerid ) {
	for( new b = 1; b < MAX_ORG; b++) {
		if( IsPlayerInRangeOfPoint( playerid, 2.0, OI[ b ][ oPozExtX], OI[ b ][ oPozExtY], OI[ b ][ oPozExtZ ] ) ) return b; }
	return -1;
}
//------------------------------------------------------------------------------
stock Bussines_Refresh( b )
{
	new string[ 512 ];

	if( IsValidDynamicPickup( FirmaPickup[ b ] ) )
		DestroyDynamicPickup( FirmaPickup[ b ] );

	if( IsValidDynamic3DTextLabel( FirmaLabel[ b ] ) )
		DestroyDynamic3DTextLabel( FirmaLabel[ b ] );

	if( BussinesInfo[ b ][ bOwned ] == 0)
	{

		format(string,sizeof(string), ""col_yelow"[ FIRMA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n"col_yelow"Vrsta: {FFFFFF}%s\n"col_yelow"Level: {FFFFFF}%d\n"col_yelow"Broj: {FFFFFF}%d\n"col_yelow"Adresa: {FFFFFF}%s\n"col_yelow"Da kupite firmu: {FFFFFF}/kupifirmu",BussinesInfo[ b ][ bPrice ],getBussinesType( b ),BussinesInfo[ b ][ bLevel ],b,UliceFirme( b ) );
		FirmaPickup[ b ] = CreateDynamicPickup(1274, 1, BussinesInfo[ b ][ bEnterX ], BussinesInfo[ b ][ bEnterY ], BussinesInfo[ b ][ bEnterZ ] );
	}
	else if( BussinesInfo[ b ][ bOwned ] == 1)
	{
	
		format(string,sizeof(string), ""col_yelow"[ FIRMA >> U VLASNISTVU ]\n"col_yelow"Ime: %s\nVlasnik: {FFFFFF}%s\n"col_yelow"Vrsta: {FFFFFF}%s\n"col_yelow"Broj: {FFFFFF}%d\n"col_yelow"Adresa: {FFFFFF}%s\n"col_yelow"Iznuda: {FFFFFF}%s\n"col_yelow"Neaktivnost: {FFFFFF}%dh",BussinesInfo[ b ][ bName ],BussinesInfo[ b ][ bOwner ],getBussinesType( b ),b,UliceFirme( b ),GetReketName( BussinesInfo[ b ][ bReket ] ),BussinesInfo[ b ][ bNeaktivnost ]);
		FirmaPickup[ b ] = CreateDynamicPickup(1274, 1, BussinesInfo[ b ][ bEnterX ], BussinesInfo[ b ][ bEnterY ], BussinesInfo[ b ][ bEnterZ ] );
	}

	FirmaLabel[ b ] = CreateDynamic3DTextLabel(string, 0x33CCFFAA, BussinesInfo[ b ][ bEnterX ], BussinesInfo[ b ][ bEnterY ], BussinesInfo[ b ][ bEnterZ ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
	return true;
}
//------------------------------------------------------------------------------
GetVrstaKuce( type )//EDITEDD LEON
{
	new typeName[26] = "Nepostojeca vrsta";

	switch( type )
	{
		case 0: typeName = "Nema";
		case MALA_KUCA: typeName = "Mala kuca";
		case SREDNJA_KUCA: typeName = "Srednja kuca";
		case VELIKA_KUCA: typeName = "Velika kuca";
		case VILA_KUCA: typeName = "Vila";
	}
	return typeName;
}

GetVrstaStana( type )//EDITEDD LEON
{
	new typeName[26] = "Nepostojeca vrsta";

	switch( type )
	{
		case 0: typeName = "Nema";
		case MALI_STAN: typeName = "Mali stan";
		case SREDNJI_STAN: typeName = "Srednji stan";
		case VELIKI_STAN: typeName = "Veliki stan";
	}
	return typeName;
}

GetVrstaVikendice( type )//EDITEDD LEON
{
	new typeName[26] = "Nepostojeca vrsta";

	switch( type )
	{
		case 0: typeName = "Nema";
		case MALA_VIKENDICA: typeName = "Mala vikendica";
		case SREDNJA_VIKENDICA: typeName = "Srednja vikendica";
		case VELIKA_VIKENDICA: typeName = "Velika vikendica";
	}
	return typeName;
}


//------------------------------------------------------------------------------
stock HotelRefresh( h )
{
	new string[ 256 ];
	if( h != -1 )
	{
		if( IsValidDynamicPickup( hotelInfo[ h ][ hPickup ] ) )
			DestroyDynamicPickup( hotelInfo[ h ][ hPickup ] );

		if( IsValidDynamic3DTextLabel( hotelInfo[ h ][ h3DText ] ) )
			DestroyDynamic3DTextLabel( hotelInfo[ h ][ h3DText ] );


		if( hotelInfo[ h ][ hOwned ] == 0 )
		{
			format( string, sizeof( string ), "{36AB00}[ HOTEL >> NA PRODAJU ]\n"col_white"[ID hotela >> %d]{36AB00}\n{36AB00}Cena: "col_white"%d$\n{36AB00}Potreban level: "col_white"%d\n{36AB00}Adresa: "col_white"%s\n{36AB00}Za kupovinu "col_white"/kupihotel", h, hotelInfo[ h ][ hPrice ], hotelInfo[ h ][ hLevel ], hotelInfo[ h ][ hAdress ] );
		}
		else if( hotelInfo[ h ][ hOwned ] == 1 )
		{
			format( string, sizeof( string ), "{36AB00}[ HOTEL >> U VLASNISTVU ]\n"col_white"[ID hotela >> %d]{36AB00}\nVlasnik: "col_white"%s\n{36AB00}Adresa: "col_white"%s\n{36AB00}Cena najma: "col_white"%d\n{36AB00}'ENTER' za ulaz u hotel", h, hotelInfo[ h ][ hOwner ], hotelInfo[ h ][ hAdress ], hotelInfo[ h ][ hRoomPrice ] );
		}
		hotelInfo[ h ][ hPickup ] = CreateDynamicPickup( 19134, 1, hotelInfo[ h ][ hEnter ][ 0 ], hotelInfo[ h ][ hEnter ][ 1 ], hotelInfo[ h ][ hEnter ][ 2 ] );
		hotelInfo[ h ][ h3DText ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, hotelInfo[ h ][ hEnter ][ 0 ], hotelInfo[ h ][ hEnter ][ 1 ], hotelInfo[ h ][ hEnter ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
	}
	return true;
}
//------------------------------------------------------------------------------
stock PropertyRefresh( im )
{
	new string[ 300 ];
	if( im != -1 )
	{
	
		if( IsValidDynamicPickup( ImovinaPickup[ im ] ) )
			DestroyDynamicPickup( ImovinaPickup[ im ] );

		if( IsValidDynamic3DTextLabel( ImovinaLabel[ im ] ) )
			DestroyDynamic3DTextLabel( ImovinaLabel[ im ] );
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( II[ im ][ iUsage ] == IMOVINA_KUCA )//EDITEDD LEON
		{
		
			if( II[ im ][ iOwned ] == 0 )
			{
				format( string, sizeof( string ),"{D50000}[ KUCA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Level: {FFFFFF}%d\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Da kupite kucu: {FFFFFF}/kupikucu",II[ im ][ iPrice ],GetVrstaKuce( II[ im ][ iVrsta ] ),II[ im ][ iLevel ],im,II[ im ][ iAdress ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
			{
				format( string, sizeof( string ),"{D50000}[ KUCA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Neaktivnost: {FFFFFF}%dh",II[ im ][ iOwner ],GetVrstaKuce( II[ im ][ iVrsta ] ),im,II[ im ][ iAdress ],II[ im ][ iNeaktivnost ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
			{
				format( string, sizeof( string ),"{D50000}[ KUCA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{D50000}Vrsta: {FFFFFF}%s\n{D50000}Broj: {FFFFFF}%d\n{D50000}Adresa: {FFFFFF}%s\n{D50000}Neaktivnost: {FFFFFF}%dh\n{D50000}Cijena renta: {FFFFFF}%d$",II[ im ][ iOwner ],GetVrstaKuce( II[ im ][ iVrsta ] ),im,II[ im ][ iAdress ],II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19522, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if( II[ im ][ iUsage ] == IMOVINA_STAN )
		{
			if( II[ im ][ iOwned ] == 0 )
			{
				format( string, sizeof( string ),"{FF8040}[ STAN >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Level: {FFFFFF}%d\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Da kupite stan: {FFFFFF}/kupistan",II[ im ][ iPrice ],GetVrstaStana( II[ im ][ iVrsta ] ), II[ im ][ iLevel ],im, II[ im ][ iAdress ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
			{
				format( string, sizeof( string ),"{FF8040}[ STAN >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Neaktivnost: {FFFFFF}%dh", II[ im ][ iOwner ],GetVrstaStana( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
			{
				format( string, sizeof( string ),"{FF8040}[ STAN >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FF8040}Vrsta: {FFFFFF}%s\n{FF8040}Broj: {FFFFFF}%d\n{FF8040}Adresa: {FFFFFF}%s\n{FF8040}Neaktivnost: {FFFFFF}%dh\n{FF8040}Cijena renta: {FFFFFF}%d$", II[ im ][ iOwner ],GetVrstaStana( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19523, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if( II[ im ][ iUsage ] == IMOVINA_VIKENDICA )
		{
			if( II[ im ][ iOwned ] == 0 )
			{
				format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> NA PRODAJU ]\nCijena: {FFFFFF}%d$\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Level: {FFFFFF}%d\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Da kupite vikendicu: {FFFFFF}/kupivikendicu",II[ im ][ iPrice ],GetVrstaVikendice( II[ im ][ iVrsta ] ), II[ im ][ iLevel ],im, II[ im ][ iAdress ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 0 )
			{
				format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
			else if( II[ im ][ iOwned ] == 1 && II[ im ][ iRentable ] == 1 )
			{
				format( string, sizeof( string ),"{FFFF00}[ VIKENDICA >> U VLASNISTVU ]\nVlasnik: {FFFFFF}%s\n{FFFF00}Vrsta: {FFFFFF}%s\n{FFFF00}Broj: {FFFFFF}%d\n{FFFF00}Adresa: {FFFFFF}%s\n{FFFF00}Neaktivnost: {FFFFFF}%dh\n{FFFF00}Cijena renta: {FFFFFF}%d$",II[ im ][ iOwner ],GetVrstaVikendice( II[ im ][ iVrsta ] ),im, II[ im ][ iAdress ], II[ im ][ iNeaktivnost ],II[ im ][ iRentPrice ] );
				ImovinaPickup[ im ] = CreateDynamicPickup(19524, 1, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ] , 0, 0 );
			}
		}
		/////////////////////////////////////////////////////////////////////////////
		ImovinaLabel[ im ] = CreateDynamic3DTextLabel( string, 0x33CCFFAA, II[ im ][ iEnter ][ 0 ], II[ im ][ iEnter ][ 1 ], II[ im ][ iEnter ][ 2 ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0 );
	}
	return true;
}
//------------------------------------------------------------------------------
stock Dileri3D(diler, bool:destroyactor = false, lookatplayer = -1)
{
	if(destroyactor == true)
	{
		if(IsValidActor(DealerActor[diler]))
		{
			DestroyActor(DealerActor[diler]);
		}
	}

	new diler_text[300];

	if(DealerInfo[diler][Organizacija] == -1) 
	{
		format(diler_text,sizeof(diler_text),
			""col_balkanstory"[ DILER | "{ffffff}"%i"col_balkanstory" ]\nU vlasnistvu: "col_green"Slobodan"col_white"\n\nDa kupite dilera: /kupidilera\nDa kupite robu od dilera: /diler",
			diler);

		if(!IsValidActor(DealerActor[diler]))
		{
			DealerActor[diler] = CreateActor(29,
				DealerInfo[diler][dealerPos][0],
				DealerInfo[diler][dealerPos][1],
				DealerInfo[diler][dealerPos][2],random(180));
		}
	}
	if(DealerInfo[diler][Organizacija] != -1) 
	{
		format(diler_text,sizeof(diler_text),
			""col_balkanstory"[ DILER | "{ffffff}"%i"col_balkanstory" ]\nU vlasnistvu: "col_red"%s"col_white"\n\nDa kupite dilera: /kupidilera\nDa kupite robu od dilera: /diler",
			diler,OI[DealerInfo[diler][Organizacija]][oName]);

		if(!IsValidActor(DealerActor[diler]))
		{
			DealerActor[diler] = CreateActor(
				OI[DealerInfo[diler][Organizacija]][oSkin1],
				DealerInfo[diler][dealerPos][0],
				DealerInfo[diler][dealerPos][1],
				DealerInfo[diler][dealerPos][2],random(180));
		}
	}

	if(!IsValidDynamic3DTextLabel(DealerInfo[diler][dealerText3D]))
	{
		DealerInfo[diler][dealerText3D] = CreateDynamic3DTextLabel(
			diler_text, -1, 
			DealerInfo[diler][dealerPos][0],
			DealerInfo[diler][dealerPos][1],
			DealerInfo[diler][dealerPos][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1 );
	}

	if(IsValidActor(DealerActor[diler]))
	{
		/*SetActorPos(DealerActor[diler],
			DealerInfo[diler][dealerPos][0],
			DealerInfo[diler][dealerPos][1],
			DealerInfo[diler][dealerPos][2]);*/

		ApplyActorAnimation(DealerActor[diler], "ped", "factalk", 4.1, true, 1, 1, 0, 0);

		if(lookatplayer != -1)
		{
			SetActorFacingPlayer(DealerActor[diler],lookatplayer);
		}
	}

	return 1;
}

stock Orge3D( id )
{
	new string[ 300 ];
	DestroyDynamicPickup( OrgPickup[ id ] );
	Delete3DTextLabel( Org3D[ id ] );
	format( string, sizeof( string ),""col_balkanstory"[ ORGANIZACIJA ]\nIme: %s\n"col_white"Da udjete u interijer\norganizacije, koristite tipku:\n"col_balkanstory"F", OI[ id ][ oName ] );
	Org3D[ id ] = Create3DTextLabel( string, -1, OI[ id ][ oPozExtX ], OI[ id ][ oPozExtY ], OI[ id ][ oPozExtZ ], 25, 0, 1);
	OrgPickup[ id ] = CreateDynamicPickup( 19133, 1, OI[ id ][ oPozExtX ], OI[ id ][ oPozExtY ], OI[ id ][ oPozExtZ ] );

	DestroyDynamicPickup( OrgPickup2[ id ] );
	DestroyDynamic3DTextLabel( Org3D2[ id ] );
	
	Org3D2[ id ] = CreateDynamic3DTextLabel(
		""col_balkanstory"[ IZLAZ ]\n\n"col_white"Da izadjete iz org, stisnite:\n"col_balkanstory"F", -1, 
			OI[ id ][ oPozIntX ], OI[ id ][ oPozIntY ], OI[ id ][ oPozIntZ ], 
			5, 
			INVALID_PLAYER_ID, 
			INVALID_VEHICLE_ID, 0, 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0);
	
	OrgPickup2[ id ] = CreateDynamicPickup( 19133, 1, 
			OI[ id ][ oPozIntX ], OI[ id ][ oPozIntY ], OI[ id ][ oPozIntZ ], 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0 );

	if( OI[ id ][ oDutyPoint ][ 0 ] != 0 && OI[ id ][ oDutyPoint ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( DutyPointPickup[ id ] );
		DestroyDynamic3DTextLabel( OrgDuty3D[ id ] );
		OrgDuty3D[ id ] = CreateDynamic3DTextLabel( 
			""col_balkanstory"[ DUZNOST ]\n"col_white"Da odete na duznost\n"col_balkanstory"/duty\n/undercover", -1, OI[ id ][ oDutyPoint ][ 0 ], OI[ id ][ oDutyPoint ][ 1 ], OI[ id ][ oDutyPoint ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oDutyVW ], OI[ id ][ oDutyInt ], -1, 20.0);
		DutyPointPickup[ id ] = CreateDynamicPickup( 1239, 1, 
			OI[ id ][ oDutyPoint ][ 0 ], 
			OI[ id ][ oDutyPoint ][ 1 ], 
			OI[ id ][ oDutyPoint ][ 2 ], OI[ id ][ oDutyVW ], OI[ id ][ oDutyInt ], -1, 20.0 );
	}
	if( OI[ id ][ oEquipPoint ][ 0 ] != 0 && OI[ id ][ oEquipPoint ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( EquipPointPickup[ id ] );
		DestroyDynamic3DTextLabel( OrgEquip3D[ id ] );
		OrgEquip3D[ id ] = CreateDynamic3DTextLabel( ""col_balkanstory"[ OPREMA ]\n"col_white"Da uzmete opremu, kucajte:\n"col_balkanstory"/oprema", -1, OI[ id ][ oEquipPoint ][ 0 ], OI[ id ][ oEquipPoint ][ 1 ], OI[ id ][ oEquipPoint ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oEquipVW ], OI[ id ][ oEquipInt ], -1, 20.0);
		EquipPointPickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oEquipPoint ][ 0 ], OI[ id ][ oEquipPoint ][ 1 ], OI[ id ][ oEquipPoint ][ 2 ], OI[ id ][ oEquipVW ], OI[ id ][ oEquipInt ], -1, 20.0 );
	}
	#if nerp_droga == 1
	if( OI[ id ][ oDrugField ][ 0 ] != 0 && OI[ id ][ oDrugField ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( OrgFieldPickup[ id ] );
		DestroyDynamic3DTextLabel( OrgField3d[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), ""col_balkanstory"[ POLJANA ]\n"col_white"Ova poljana je u vlasnistvu:\n"col_balkanstory"%s", OI[ id ][ oName ] );
		OrgField3d[ id ] = CreateDynamic3DTextLabel( stringfield, -1, OI[ id ][ oDrugField ][ 0 ], OI[ id ][ oDrugField ][ 1 ], OI[ id ][ oDrugField ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 50.0);
		OrgFieldPickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oDrugField ][ 0 ], OI[ id ][ oDrugField ][ 1 ], OI[ id ][ oDrugField ][ 2 ], 0, 0, -1, 50.0 );
	}
	#endif
	if( OI[ id ][ oSafePos ][ 0 ] != 0 && OI[ id ][ oSafePos ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( OrgSafePickup[ id ] );
		DestroyDynamic3DTextLabel( OrgSafe3d[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), ""col_balkanstory"[ ORGANIZACIJSKI SEF ]\nU vlasnistvu: %s\n"col_white"Da otvorite sef organizacije, kucajte:\n"col_balkanstory"/orgsef", OI[ id ][ oName ] );
		OrgSafe3d[ id ] = CreateDynamic3DTextLabel( stringfield, -1, OI[ id ][ oSafePos ][ 0 ], OI[ id ][ oSafePos ][ 1 ], OI[ id ][ oSafePos ][ 2 ], 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, OI[ id ][ oVw ], OI[ id ][ oInt ], -1, 20.0);
		OrgSafePickup[ id ] = CreateDynamicPickup( 1239, 1, OI[ id ][ oSafePos ][ 0 ], OI[ id ][ oSafePos ][ 1 ], OI[ id ][ oSafePos ][ 2 ], OI[ id ][ oVw ], OI[ id ][ oInt ], -1, 20.0 );
	}
	DestroyDynamicPickup( GaragePickup2[ id ] );
	DestroyDynamic3DTextLabel( Garage3d2[ id ] );
	DestroyDynamicPickup( DrugFactoryPickup2[ id ] );
	DestroyDynamic3DTextLabel( DrugFactory3d2[ id ] );
	/*if(OI[id][oTip] == ORG_TIP_MAFIJA || OI[id][oTip] == ORG_TIP_BANDA) 
	//DrugFactoryCoords  | 2 |1314
	{
		DestroyDynamicPickup( DrugFactoryPickup2[ id ] );
		DestroyDynamic3DTextLabel( DrugFactory3d2[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), 
			""col_balkanstory"[ BAZA ORGANIZACIJE ]\nU vlasnistvu: %s\n"col_white"Da izadjete iz fabrike, stisnite:\n"col_balkanstory"F", 
			OI[ id ][ oName ] );
		DrugFactory3d2[ id ] = CreateDynamic3DTextLabel( stringfield, -1, 
			DrugFactoryCoords , 
			5, 
			INVALID_PLAYER_ID, 
			INVALID_VEHICLE_ID, 0, 
			OI[ id ][ oVw ], 
			DrugFactoryInt, -1, 20.0);
		DrugFactoryPickup2[ id ] = CreateDynamicPickup( 1314, 1, 
			DrugFactoryCoords ,
			OI[ id ][ oVw ], 
			DrugFactoryInt, -1, 20.0 );
	}*/
	if( OI[ id ][ oDrugFactoryPos ][ 0 ] != 0 && OI[ id ][ oDrugFactoryPos ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( DrugFactoryPickup[ id ] );
		DestroyDynamic3DTextLabel( DrugFactory3d[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), 
			""col_balkanstory"[ FABRIKA DROGE ]\nU vlasnistvu: %s\n"col_white"Da udjete u prostoriju, stisnite:\n"col_balkanstory"F", 
			OI[ id ][ oName ] );
		DrugFactory3d[ id ] = CreateDynamic3DTextLabel( stringfield, -1, 
			OI[ id ][ oDrugFactoryPos ][ 0 ], 
			OI[ id ][ oDrugFactoryPos ][ 1 ], 
			OI[ id ][ oDrugFactoryPos ][ 2 ], 
			5, 
			INVALID_PLAYER_ID, 
			INVALID_VEHICLE_ID, 0, 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0);
		DrugFactoryPickup[ id ] = CreateDynamicPickup( 1279, 1, 
			OI[ id ][ oDrugFactoryPos ][ 0 ], 
			OI[ id ][ oDrugFactoryPos ][ 1 ], 
			OI[ id ][ oDrugFactoryPos ][ 2 ], 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0 );
	}

	//garaza
	/*if( OI[ id ][ oGaragePos ][ 0 ] != 0 && OI[ id ][ oGaragePos ][ 1 ] != 0 )
	//DrugFactoryCoords  | 2 |1314
	{
		DestroyDynamicPickup( GaragePickup2[ id ] );
		DestroyDynamic3DTextLabel( Garage3d2[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), 
			""col_balkanstory"[ BAZA ORGANIZACIJE ]\nU vlasnistvu: %s\n"col_white"Da izadjete iz garaze, stisnite:\n"col_balkanstory"F", 
			OI[ id ][ oName ] );
		Garage3d2[ id ] = CreateDynamic3DTextLabel( stringfield, -1, 
			GarageCoords, 
			5, 
			INVALID_PLAYER_ID, 
			INVALID_VEHICLE_ID, 0, 
			OI[ id ][ oVw ], 
			GarageInt, -1, 20.0);
		GaragePickup2[ id ] = CreateDynamicPickup( 1314, 1, 
			GarageCoords ,
			OI[ id ][ oVw ], 
			GarageInt, -1, 20.0 );
	}*/
	if( OI[ id ][ oGaragePos ][ 0 ] != 0 && OI[ id ][ oGaragePos ][ 1 ] != 0 )
	{
		DestroyDynamicPickup( GaragePickup[ id ] );
		DestroyDynamic3DTextLabel( Garage3d[ id ] );
		new stringfield[ 300 ];
		format( stringfield, sizeof( stringfield ), 
			""col_balkanstory"[ GARAZA ]\nU vlasnistvu: %s\n"col_white"Da udjete u prostoriju, stisnite:\n"col_balkanstory"F", 
			OI[ id ][ oName ] );
		Garage3d[ id ] = CreateDynamic3DTextLabel( stringfield, -1, 
			OI[ id ][ oGaragePos ][ 0 ], 
			OI[ id ][ oGaragePos ][ 1 ], 
			OI[ id ][ oGaragePos ][ 2 ], 
			5, 
			INVALID_PLAYER_ID, 
			INVALID_VEHICLE_ID, 0, 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0);
		GaragePickup[ id ] = CreateDynamicPickup( 19132, 1, 
			OI[ id ][ oGaragePos ][ 0 ], 
			OI[ id ][ oGaragePos ][ 1 ], 
			OI[ id ][ oGaragePos ][ 2 ], 
			OI[ id ][ oVw ], 
			OI[ id ][ oInt ], -1, 20.0 );
	}
	return true;
}
//------------------------------------------------------------------------------
stock Dimi_SetPlayerHealth( playerid, Float:Zivot ) {

	if( Zivot < 0.0 ) {
		Zivot = 0.0;
	}
	/*if( Zivot > 100.0 ) {
		Zivot = 100.0;
	}*/

	SetPlayerHealth( playerid, Zivot );
	antiCheatCS[ playerid ][ TrueHealth ] = Zivot;
	return true;
}
stock DodajIgracuHP( playerid, value)
{
  new Float:Health; GetPlayerHealth( playerid, Health); Dimi_SetPlayerHealth( playerid, Health+value);
}
//------------------------------------------------------------------------------
stock Dimi_SetPlayerArmour( playerid, Float: armor ) {
	if( armor > 100.0 ) {
		armor = 100.0;
	}
	SetPlayerArmour( playerid, armor );
	antiCheatCS[ playerid ][ TrueArmour ] = armor;
	return true;
}
stock DodajIgracuArmour( playerid, value)
{
  new Float:Armour; GetPlayerArmour( playerid, Armour); Dimi_SetPlayerArmour( playerid, Armour+value);
}
//------------------------------------------------------------------------------
stock PocetniNovac( playerid, novac ) {
	new Strg[ 15 ];
	if( novac > 0 ) {
		format( Strg, sizeof( Strg ), "~g~$%d", novac );
		announcement( playerid, Strg, 3000, 1 ); }
	else if( novac < 0 ) {
		format( Strg, sizeof( Strg ), "~r~$%d", novac );
		announcement( playerid, Strg, 3000, 1 ); }
	PlayerInfo[ playerid  ][ xNovac ] = novac;
	ResetujBarNovac( playerid );
	UpdejtujBarNovac( playerid, PlayerInfo[ playerid  ][ xNovac ] );
	return PlayerInfo[ playerid ][ xNovac ];

}
//------------------------------------------------------------------------------
stock BussinesMoney( bussinesID, ammount ) {

	if( bussinesID == -1 ) return 1;
	if( ammount < 0 || ammount > 99999999 ) return 1;
	
	if( BussinesInfo[ bussinesID ][ bReket ] == -1 ) {
	
		BussinesInfo[ bussinesID ][ bMoney ] += ammount;
		SaveBussines( bussinesID );
	}
	else if( BussinesInfo[ bussinesID ][ bReket ] != -1 ) {
	
		new dvajesposto = (ammount/100)*20;
		new osamdesetposto = (ammount/100)*80;
	
		BussinesInfo[ bussinesID ][ bMoney ] += osamdesetposto;
		SaveBussines( bussinesID );
		
		OI[ BussinesInfo[ bussinesID ][ bReket ] ][ oSafeMoney ] += dvajesposto;
		SaveOrganization( BussinesInfo[ bussinesID ][ bReket ] );
	}
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesRodaMoney( ammount ) {

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ ) {

		if( BussinesInfo[ i ][ bType ] == VRSTA_RODA ) {

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
stock BussinesTrafikaMoney( ammount )
{

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ )
	{
		if( BussinesInfo[ i ][ bType ] == VRSTA_TRAFIKA )
		{

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesTelekomMoney( ammount ) {

	new bussinesID = -1;
	
	for( new i = 1; i < MAX_BUSSINES; i++ ) {
	
		if( BussinesInfo[ i ][ bType ] == VRSTA_TELEKOM ) {
		
			bussinesID = i;
			break;
		}
	}
	
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesOglasMoney( ammount )
{

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ )
	{

		if( BussinesInfo[ i ][ bType ] == VRSTA_OGLAS )
		{

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesElektranaMoney( ammount ) {

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ ) {

		if( BussinesInfo[ i ][ bType ] == VRSTA_ELEKTRANA ) {

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesLutrijaMoney( ammount ) {

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ ) {

		if( BussinesInfo[ i ][ bType ] == VRSTA_LUTRIJA ) {

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesKomunalijeMoney( ammount ) {

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ ) {

		if( BussinesInfo[ i ][ bType ] == VRSTA_KOMUNALIJE ) {

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesVodovodMoney( ammount ) {

	new bussinesID = -1;

	for( new i = 1; i < MAX_BUSSINES; i++ ) {

		if( BussinesInfo[ i ][ bType ] == VRSTA_VODOVOD ) {

			bussinesID = i;
			break;
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
stock BussinesJobMoney( jobID, ammount ) {
	new bussinesID = -1;
	for (new i = 1; i < MAX_BUSSINES; i++ ) {
		if( BussinesInfo[ i ][ bType ] == VRSTA_POSAO ) {
			if( BussinesInfo[ i ][ bJobID ] == jobID ) {
				bussinesID = i;
				break;
			}
		}
	}
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}

stock BussinesRentMoney( playerid, ammount ) {
	new bussinesID = -1;
	for( new i = 1; i < MAX_BUSSINES; i++ ) {
		if( IsPlayerInRangeOfPoint( playerid, 100.0, BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ] ) ) {
			if( BussinesInfo[ i ][ bType ] == VRSTA_RENT ) {
				bussinesID = i;
				break;
			}
		}
	}
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}

stock BussinesPaySprayMoney( playerid, ammount ) {

	new bussinesID = -1;
	for( new i = 1; i < MAX_BUSSINES; i++ ) {
		if( IsPlayerInRangeOfPoint( playerid, 100.0, BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ] ) ) {
			if( BussinesInfo[ i ][ bType ] == VRSTA_PAYSPRAY ) {
				bussinesID = i;
				break;
			}
		}
	}
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
stock BussinesPumpaMoney( playerid, ammount ) {
	new bussinesID = -1;
	for( new i = 1; i < MAX_BUSSINES; i++ ) {
		if( IsPlayerInRangeOfPoint( playerid, 100.0, BussinesInfo[ i ][ bEnterX ], BussinesInfo[ i ][ bEnterY ], BussinesInfo[ i ][ bEnterZ ] ) ) {
			if( BussinesInfo[ i ][ bType ] == VRSTA_PUMPA ) {
				bussinesID = i;
				break;
			}
		}
	}
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
stock BussinesJavnaKucaMoney( playerid, ammount ) {

	new bussinesID = -1;
	
	if( uFirmi[ playerid ] != -1 ) {
	
		if( BussinesInfo[ uFirmi[ playerid ] ][ bType ] == VRSTA_JAVNAK ) {
		
			bussinesID = uFirmi[ playerid ];
		}
	}
	
	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
stock BussinesNeonMoney( playerid, ammount ) {

	new bussinesID = -1;

	if( uFirmi[ playerid ] != -1 ) {

		if( BussinesInfo[ uFirmi[ playerid ] ][ bType ] == VRSTA_NEON ) {

			bussinesID = uFirmi[ playerid ];
		}
	}

	if( bussinesID == -1 ) return 1;
	BussinesMoney( bussinesID, ammount );
	return 1;
}
//------------------------------------------------------------------------------
/*DajIgracuToilet( playerid, wc )
{
	PlayerInfo[ playerid ][ xToilet ] -= wc;

	if( PlayerInfo[ playerid ][ xToilet ] < 0 )
		PlayerInfo[ playerid ][ xToilet ] = 0;

	new stringic[ 20 ];
	format( stringic, sizeof( stringic ), "%d", PlayerInfo[ playerid ][ xToilet ] );
	PlayerTextDrawSetString( playerid, WcIgraca[ playerid ], stringic );

	return 1;
}*/
//------------------------------------------------------------------------------
SetToilet( playerid, wc ) {
	PlayerInfo[ playerid ][ xToilet ] = wc;

	new stringic[ 20 ];
	format( stringic, sizeof( stringic ), "%d", PlayerInfo[ playerid ][ xToilet ] );
	PlayerTextDrawSetString( playerid, WcIgraca[ playerid ], stringic );

	return 1;
}

//------------------------------------------------------------------------------
DajIgracuGlad( playerid, glad ) {
	PlayerInfo[ playerid ][ xHunger ] -= glad;

	if( PlayerInfo[ playerid ][ xHunger ] < 0 )
		PlayerInfo[ playerid ][ xHunger ] = 0;

	new stringic[ 20 ];
	format( stringic, sizeof( stringic ), "%d", PlayerInfo[ playerid ][ xHunger ] );
	PlayerTextDrawSetString( playerid, GladIgraca[ playerid ], stringic );
	
	return 1;
}
//------------------------------------------------------------------------------
stock SetGlad( playerid, glad ) {
	PlayerInfo[ playerid ][ xHunger ] = glad;

	new stringic[ 20 ];
	format( stringic, sizeof( stringic ), "%d", PlayerInfo[ playerid ][ xHunger ] );
	PlayerTextDrawSetString( playerid, GladIgraca[ playerid ], stringic );

	return 1;
}

//jbtnovac
stock DajIgracuNovac( playerid, novac ) 
{
	AnnounceTextDrawsOn[playerid] = 1;

	PlayerInfo[ playerid ][ xNovac ] += novac;
	ResetujBarNovac( playerid );
	UpdejtujBarNovac( playerid, PlayerInfo[ playerid  ][ xNovac ] );
	SavePlayer( playerid );
	
	new stringic[50];

	format(stringic,50,"%d",novac);

	TextDrawShowForPlayer(playerid,moneytd0);
	TextDrawShowForPlayer(playerid,moneytd1);
	
	PlayerTextDrawSetString( playerid, playermoneytd0[ playerid ], stringic );

	PlayerTextDrawColor(playerid, playermoneytd0[playerid], -1);
	PlayerTextDrawShow(playerid,playermoneytd0[ playerid ]);

	hidemoneytdtimer[playerid] = SetTimerEx("hidemoneytds", 4000, false, "i", playerid);
	
	return PlayerInfo[ playerid ][ xNovac ];

}
stock announcement(playerid,const msg[],interval=4000, a=1, b=2)
{
	AnnounceTextDrawsOn[playerid] = 1;
	#pragma unused a
	#pragma unused b

	/*playermoneytd0[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "999999999");
	PlayerTextDrawLetterSize(playerid, playermoneytd0[playerid], 0.201111, 1.346133);
	PlayerTextDrawAlignment(playerid, playermoneytd0[playerid], 2);
	PlayerTextDrawColor(playerid, playermoneytd0[playerid], -1);
	PlayerTextDrawSetShadow(playerid, playermoneytd0[playerid], 0);
	PlayerTextDrawSetOutline(playerid, playermoneytd0[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, playermoneytd0[playerid], 51);
	PlayerTextDrawFont(playerid, playermoneytd0[playerid], 2);
	PlayerTextDrawSetProportional(playerid, playermoneytd0[playerid], 1);*/

	new message[300];

	KillTimer(hidemoneytdtimer[playerid]);

	TextDrawHideForPlayer(playerid,moneytd1);

	format(message,300,"%s",msg);

	TextDrawShowForPlayer(playerid,moneytd0);

	PlayerTextDrawSetString( playerid, playermoneytd0[ playerid ], message );
	PlayerTextDrawColor(playerid, playermoneytd0[playerid], tdboja);
	PlayerTextDrawShow(playerid,playermoneytd0[ playerid ]);
	//PlayerTextDrawDestroy(playerid,playermoneytd0[playerid]);


	hidemoneytdtimer[playerid] = SetTimerEx("hidemoneytds", interval, false, "i", playerid);
	return 1;
}
hidemoneytds(playerid); public hidemoneytds(playerid)
{
	PlayerTextDrawSetString( playerid, playermoneytd0[ playerid ], "" );
	AnnounceTextDrawsOn[playerid] = 0;
	TextDrawHideForPlayer(playerid,moneytd0);
	TextDrawHideForPlayer(playerid,moneytd1);
	PlayerTextDrawColor(playerid, playermoneytd0[playerid], -1);
	PlayerTextDrawHide(playerid,playermoneytd0[playerid]);
	//PlayerTextDrawDestroy(playerid,playermoneytd0[playerid]);
	KillTimer(hidemoneytdtimer[playerid]);
	OrgVehAnncSeen[playerid] = false;
	return 1;
}
/*
ptask HideAnnounceTextDraws[150](playerid)
{
	if(AnnounceTextDrawsOn[playerid] == 0)
	{
		TextDrawHideForPlayer(playerid,moneytd0);
		TextDrawHideForPlayer(playerid,moneytd1);
		PlayerTextDrawHide(playerid,playermoneytd0[playerid]);
	}
	return 1;
}*/
//------------------------------------------------------------------------------
stock ForbiddenWeap( playerid ) {
	new weap = GetPlayerWeapon(playerid);
	if( weap == 35 || weap == 36 || weap == 37 || weap == 38 || weap == 39 || weap == 40 || weap == 42 || weap == 44 || weap == 45) {
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
stock Korisnici( playerid ) {
	new string[ 128 ];
	format( string, sizeof( string ), I_FILE, ImeIgraca( playerid ) );
	return string;
}
//------------------------------------------------------------------------------
stock Admini( playerid ) {
	new string[ 128 ];
	format( string, sizeof( string ), A_FILE, ImeIgraca( playerid ) );
	return string;
}
stock Inventory( playerid ) {
	new string[ 64 ];
	format( string, sizeof( string ), INV_FILE, ImeIgraca( playerid ) );
	return string;
}
stock KladIme( playerid ) {
	new string[ 64 ];
	format( string, sizeof( string ), KLAD_FILE, ImeIgraca( playerid ) );
	return string;
}
//------------------------------------------------------------------------------
stock IsValidRoleplayName(const name[]) {

	if(!name[ 0 ] || strfind(name, "_") == -1)
		return 0;

	else for (new i = 0, len = strlen(name); i != len; i ++) {
		if((i == 0) && (name[ i ] < 'A' || name[ i ] > 'Z'))
			return 0;

		else if((i != 0 && i < len  && name[ i ] == '_') && (name[i + 1] < 'A' || name[i + 1] > 'Z'))
			return 0;

		else if((name[ i ] < 'A' || name[ i ] > 'Z') && (name[ i ] < 'a' || name[ i ] > 'z') && name[ i ] != '_' && name[ i ] != '.')
			return 0;
	}
	return 1;
}



//------------------------------------------------------------------------------
getPosBehindVehicle( vehicleid, &Float:x, &Float:y, &Float:z, Float:offset = 0.5)
{
	if( vehicleid == INVALID_VEHICLE_ID) return;

	new
		Float:vehicleSize[ 3 ],
		Float:vehiclePos[ 3 ];

	GetVehiclePos( vehicleid, 
		vehiclePos[ 0 ], vehiclePos[ 1 ], vehiclePos[ 2 ] );
	GetVehicleModelInfo(GetVehicleModel( 
		vehicleid), VEHICLE_MODEL_INFO_SIZE, 
	vehicleSize[ 0 ], vehicleSize[ 1 ], vehicleSize[ 2 ] );
	getXYBehindVehicle( vehicleid, 
		vehiclePos[ 0 ], vehiclePos[ 1 ], (vehicleSize[ 1 ]/2)+offset);

	x = vehiclePos[ 0 ];
	y = vehiclePos[ 1 ];
	z = vehiclePos[ 2 ];
	return;
}
getXYBehindVehicle( vehicleid, &Float:q, &Float:w, Float:distance )
{
	new Float:a;
	GetVehiclePos( vehicleid, q, w, a);
	GetVehicleZAngle( vehicleid, a);
	q += (distance * -floatsin(-a, degrees));
	w += (distance * -floatcos(-a, degrees));
	return;
}

stock getPlayerNearestVehicle( playerid ) {
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	for (new i = 1; i != MAX_VEHICLES; i ++) if(IsValidVehicle(i) && GetVehiclePos(i, fX, fY, fZ))
	{
		if( IsPlayerInRangeOfPoint( playerid, 10.0, fX, fY, fZ)) return i;
	}
	return INVALID_VEHICLE_ID;
}
stock getPlayerNearestTractor( playerid ) {
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	for (new i = 1; i != MAX_VEHICLES; i ++) if( IsValidVehicle( i ) && GetVehiclePos( i, fX, fY, fZ ) )
	{
		if( IsPlayerInRangeOfPoint( playerid, 5.0, fX, fY, fZ ) ) return i;
	}
	return INVALID_VEHICLE_ID;
}
stock getPlayerNearestPizzaVehicle( playerid ) {
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	for (new i = 1; i != MAX_VEHICLES; i ++) if(IsValidVehicle(i) && GetVehiclePos(i, fX, fY, fZ))
	{
		if( IsPlayerInRangeOfPoint( playerid, 2.0, fX, fY, fZ)) return i;
	}
	return INVALID_VEHICLE_ID;
}


stock SaveRadar( radarID ) {

	new file4[ 64 ];
	format( file4, sizeof( file4 ), F_RADARS, radarID );
	new INI:File = INI_Open( file4 );
	INI_WriteInt( File, "MaxSpeed", radarInfo[ radarID ][ radarMaxSpeed ] );
	INI_WriteInt( File, "Price", radarInfo[ radarID ][ radarPrice ] );
	INI_WriteFloat( File, "Pos1", radarInfo[ radarID ][ radarPos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", radarInfo[ radarID ][ radarPos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", radarInfo[ radarID ][ radarPos ][ 2 ] );
	INI_WriteFloat( File, "Pos4", radarInfo[ radarID ][ radarPos ][ 3 ] );
	INI_WriteFloat( File, "Pos5", radarInfo[ radarID ][ radarPos ][ 4 ] );
	INI_WriteFloat( File, "Pos6", radarInfo[ radarID ][ radarPos ][ 5 ] );
	INI_Close( File );

	return true;
}

//------------------------------------------------------------------------------
stock SaveGate( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), GATE_FILE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteString( File, "Owner", GateData[ id ][ gateOwner ] );
	INI_WriteInt( File, "Model", GateData[ id ][ gateModel ] );
	INI_WriteInt( File, "For", GateData[ id ][ gateFor ] );
	INI_WriteInt( File, "OrgID", GateData[ id ][ gateOrgID ] );
	INI_WriteFloat( File, "Speed", GateData[ id ][ gateSpeed ] );
	INI_WriteFloat( File, "Radius", GateData[ id ][ gateRadius ] );
	INI_WriteInt( File, "Time", GateData[ id ][ gateTime ] );
	INI_WriteFloat( File, "Pos1", GateData[ id ][ gatePos ][ 0 ] );
	INI_WriteFloat( File, "Pos2", GateData[ id ][ gatePos ][ 1 ] );
	INI_WriteFloat( File, "Pos3", GateData[ id ][ gatePos ][ 2 ] );
	INI_WriteFloat( File, "Pos4", GateData[ id ][ gatePos ][ 3 ] );
	INI_WriteFloat( File, "Pos5", GateData[ id ][ gatePos ][ 4 ] );
	INI_WriteFloat( File, "Pos6", GateData[ id ][ gatePos ][ 5 ] );
	INI_WriteInt( File, "Interior", GateData[ id ][ gateInterior ] );
	INI_WriteInt( File, "World", GateData[ id ][ gateWorld ] );
	INI_WriteFloat( File, "Move1", GateData[ id ][ gateMove ][ 0 ] );
	INI_WriteFloat( File, "Move2", GateData[ id ][ gateMove ][ 1 ] );
	INI_WriteFloat( File, "Move3", GateData[ id ][ gateMove ][ 2 ] );
	INI_WriteFloat( File, "Move4", GateData[ id ][ gateMove ][ 3 ] );
	INI_WriteFloat( File, "Move5", GateData[ id ][ gateMove ][ 4 ] );
	INI_WriteFloat( File, "Move6", GateData[ id ][ gateMove ][ 5 ] );
	INI_Close( File );
	return 1;
}
//------------------------------------------------------------------------------
stock SaveHotel( id ) {
	new iFile[ 40 ];
	format( iFile, sizeof( iFile ), HOTEL_FILE, id );
	new INI:File = INI_Open( iFile );
	INI_WriteInt( File, "Owned", hotelInfo[ id ][ hOwned ] );
	INI_WriteString( File, "Owner", hotelInfo[ id ][ hOwner ] );
	INI_WriteFloat( File, "Enter1", hotelInfo[ id ][ hEnter ][ 0 ] );
	INI_WriteFloat( File, "Enter2", hotelInfo[ id ][ hEnter ][ 1 ] );
	INI_WriteFloat( File, "Enter3", hotelInfo[ id ][ hEnter ][ 2 ] );
	INI_WriteFloat( File, "Exit1", hotelInfo[ id ][ hExit ][ 0 ] );
	INI_WriteFloat( File, "Exit2", hotelInfo[ id ][ hExit ][ 1 ] );
	INI_WriteFloat( File, "Exit3", hotelInfo[ id ][ hExit ][ 2 ] );
	INI_WriteInt( File, "Price", hotelInfo[ id ][ hPrice ] );
	INI_WriteInt( File, "RoomPrice", hotelInfo[ id ][ hRoomPrice ] );
	INI_WriteInt( File, "Money", hotelInfo[ id ][ hMoney ] );
	INI_WriteInt( File, "Interior", hotelInfo[ id ][ hInterior ] );
	INI_WriteInt( File, "VW", hotelInfo[ id ][ hVW ] );
	INI_WriteInt( File, "Level", hotelInfo[ id ][ hLevel ] );
	INI_WriteInt( File, "Locked", hotelInfo[ id ][ hLocked ] );
	INI_WriteString( File, "Adress", hotelInfo[ id ][ hAdress ] );
	INI_WriteString( File, "Guest_1", hotelInfo[ id ][ hGuest_1 ] );
	INI_WriteString( File, "Guest_2", hotelInfo[ id ][ hGuest_2 ] );
	INI_WriteString( File, "Guest_3", hotelInfo[ id ][ hGuest_3 ] );
	INI_WriteString( File, "Guest_4", hotelInfo[ id ][ hGuest_4 ] );
	INI_WriteString( File, "Guest_5", hotelInfo[ id ][ hGuest_5 ] );
	INI_WriteString( File, "Guest_6", hotelInfo[ id ][ hGuest_6 ] );
	INI_WriteString( File, "Guest_7", hotelInfo[ id ][ hGuest_7 ] );
	INI_WriteString( File, "Guest_8", hotelInfo[ id ][ hGuest_8 ] );
	INI_WriteString( File, "Guest_9", hotelInfo[ id ][ hGuest_9 ] );
	INI_WriteString( File, "Guest_10", hotelInfo[ id ][ hGuest_10 ] );
	INI_WriteInt( File, "Porez", hotelInfo[ id ][ hPorez ] );
	INI_WriteInt( File, "VrednostPoreza", hotelInfo[ id ][ hVrednostPoreza  ] );
	INI_Close( File );
	return 1;
}


//------------------------------------------------------------------------------

#if kladionica == 1
forward SaveKladionica( playerid );
public SaveKladionica( playerid ) {

	new string[ 30 ];
	new INI:File = INI_Open( KladIme( playerid ) );

	INI_SetTag( File, "Informacije" );

	INI_WriteBool( File, "Uplaceno", KladionicaListic[ playerid ][ Uplaceno ] );
	INI_WriteBool( File, "Zavrseno", KladionicaListic[ playerid ][ Zavrseno ] );
	INI_WriteInt( File, "Uplata", KladionicaListic[ playerid ][ Uplata ] );
	INI_WriteFloat( File, "Dobitak", KladionicaListic[ playerid ][ Dobitak ] );
	INI_WriteBool( File, "Status", KladionicaListic[ playerid ][ Status ] );
	INI_WriteString( File, "HourPobeda", KladionicaListic[ playerid ][ HourPobeda ]  );
	
	for( new i = 0; i < 10; i++) {

		format( string, sizeof( string ), "parID%d", i );
		INI_WriteInt( File, string, KladionicaListic[ playerid ][ parID ][ i ] );

		format( string, sizeof( string ), "keciksdva%d", i );
		INI_WriteInt( File, string, KladionicaListic[ playerid ][ keciksdva ][ i ] );

		format( string, sizeof( string ), "Kvota%d", i );
		INI_WriteFloat( File, string, KladionicaListic[ playerid ][ Kvota ][ i ] );

		format( string, sizeof( string ), "teamID1%d", i );
		INI_WriteInt( File, string, KladionicaListic[ playerid ][ teamID1 ][ i ] );

		format( string, sizeof( string ), "teamID2%d", i );
		INI_WriteInt( File, string, KladionicaListic[ playerid ][ teamID2 ][ i ] );

	}
	

	INI_Close( File );
	return true;
}


forward LoadKladionica( playerid, name[ ], value[ ] );
public LoadKladionica( playerid, name[ ], value[ ] ) {

	new string[ 30 ];

	INI_Bool( "Uplaceno", KladionicaListic[ playerid ][ Uplaceno ] );
	INI_Bool( "Zavrseno", KladionicaListic[ playerid ][ Zavrseno ] );
	INI_Int( "Uplata", KladionicaListic[ playerid ][ Uplata ] );
	INI_Float( "Dobitak", KladionicaListic[ playerid ][ Dobitak ] );
	INI_Bool( "Status", KladionicaListic[ playerid ][ Status ] );
	INI_String( "HourPobeda", KladionicaListic[ playerid ][ HourPobeda ], 24  );

	for( new i = 0; i < 10; i++) {
	
		format( string, sizeof( string ), "parID%d", i );
		INI_Int( string, KladionicaListic[ playerid ][ parID ][ i ] );
		
		format( string, sizeof( string ), "keciksdva%d", i );
		INI_Int( string, KladionicaListic[ playerid ][ keciksdva ][ i ] );
		
		format( string, sizeof( string ), "Kvota%d", i );
		INI_Float( string, KladionicaListic[ playerid ][ Kvota ][ i ] );
		
		format( string, sizeof( string ), "teamID1%d", i );
		INI_Int( string, KladionicaListic[ playerid ][ teamID1 ][ i ] );

		format( string, sizeof( string ), "teamID2%d", i );
		INI_Int( string, KladionicaListic[ playerid ][ teamID2 ][ i ] );
	
	}
	return 1;
}
#endif


////////////////////


VehicleObjectCheck( vehicleid ) {
	if( vehicleid != -1 ) {
		if( Neon[ vehicleid ] == 1 ) {
			Neon[ vehicleid ] = 0;
			DestroyDynamicObject( NeonObject1[ vehicleid ] );
			DestroyDynamicObject( NeonObject2[ vehicleid ] );
		}
		if( WOOD[ vehicleid ] == true ) {
			WOOD[ vehicleid ] = false;
			DestroyDynamicObject( WOODObject[ vehicleid ] );
		}
		if( Siren[ vehicleid ] == 1 ) {
			Siren[ vehicleid ] = 0;
			DestroyDynamicObject( SirenObject[ vehicleid ] );
		}
		if( CarSign[ vehicleid ] == 1 ) {
			CarSign[ vehicleid ] = 0;
			Delete3DTextLabel( vehicle3Dtext[ vehicleid ] );
		}
		#if NERP_ZIMSKI_MOD  == 1
		if( SnowObjects[ vehicleid ] == true ) {
			SnowObjects[ vehicleid ] = false;
			DestroyDynamicObject( SnowObject1[ vehicleid ] );
			DestroyDynamicObject( SnowObject2[ vehicleid ] );
		}
		#endif
	}
}

strtok(const string[], &index)
{
	new length = strlen(string);

	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index,
		result[20];

	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}

	result[index - offset] = EOS;
	return result;
}

SendMechanicMessage( color, string[] )
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if( PlayerInfo[ i ][ xPosao ] == POSAO_MEHANICAR && GetPVarInt( i, "JobDuty" ) == 1 )
		{
			SendClientMessagee( i, color, string );
		}
	}
}

CellphoneCheck( playerid ) {

	if( GetPVarInt( playerid, "CellTime" ) > 0 ) {
	
		if( GetPVarInt( playerid, "CellTime") == cchargetime ) {
		
			SetPVarInt( playerid, "CellTime", 1 );

			if( GetPVarInt( GetPVarInt( playerid, "Mobile" ), "Mobile" ) == playerid ) {
				PovecajPVarInt( playerid, "CallCost", callcost );
			}
		}

		PovecajPVarInt( playerid, "CellTime", 1);

		if( GetPVarInt(GetPVarInt( playerid, "Mobile"), "Mobile") == -1 && GetPVarInt( playerid, "CellTime") == 5 ) {
			format( globalstring, sizeof( globalstring ), "* %s zvoni mobilni telefon.", ImeIgraca( GetPVarInt( playerid, "Mobile") ) );
			PorukaRadius(30.0, GetPVarInt( playerid, "Mobile"), globalstring, LJUBICASTA );
		}
	}
	if( GetPVarInt( playerid, "CellTime") == 0 && GetPVarInt( playerid, "CallCost") > 0 ) {
	
		format(  globalstring, sizeof( globalstring ), "~w~Cena poziva~n~~r~$%d", GetPVarInt( playerid, "CallCost")+4 );
		PlayerInfo[ playerid ][ xTelefonBon ] -= GetPVarInt( playerid, "CallCost")+4;
		BussinesTelekomMoney( GetPVarInt( playerid, "CallCost")+4 );
		announcement( playerid, globalstring, 5000, 1 );
		SetPVarInt( playerid, "CallCost", 0 );
		SendClientMessage(playerid,-1,"");
	}
}

SearchingHit( playerid ) {
	new string[ 128 ];
	new searchhit = 0;
	for(new i; i < MAX_PLAYERS; i++) {
		if( searchhit == 0 ) {
			if( PlayerInfo[ i ][ xHitmenCena ] > 0 && HitmanInfo[ i ][ GotHit ] == 0 && OI[ PlayerInfo[ i ][ xClan ] ][ oTip ] != ORG_TIP_HITM ) {
				searchhit = 1;
				hitfound = 1;
				ahitid = i;
				for(new k; k < MAX_PLAYERS; k++) {
					if( OI[ PlayerInfo[ k ][ xClan ] ][ oTip ] == ORG_TIP_HITM ) {
						SendClientMessagee( k, BELA, "|______________________ Novosti Agencije __________________________|");
						SendClientMessagee( k, SVETLOPLAVA, "*** Nova Poruka: Nova meta je dostupna. ***");
						format( string, sizeof( string ), "Osoba: %s   ID: %d   Vrednost: $%d", ImeIgraca( i ), i, PlayerInfo[ i ][ xHitmenCena ] );
						SendClientMessagee( k, SVETLOPLAVA, string );
						SendClientMessagee( k, ZUTA, "Koristite Givehit id, da biste dodjelili metu jednome od vasih agenata.");
						SendClientMessagee( k, BELA, "|______________________________________________________________________|");
					}
				}
				return 0;
			}
		}
	}
	if( searchhit == 0 )
	{
		GRESKA( playerid, "Nema dostupnih meta !");
	}
	return 0;
}

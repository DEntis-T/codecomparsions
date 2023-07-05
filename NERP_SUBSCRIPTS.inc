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


stock bool:Weapon_IsValid(weaponid)
{
	return (weaponid >= 1 && weaponid <= 18 || weaponid >= 21 && weaponid <= 46);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
        SA-MP "GetVehicleColor v2.1" Include
        Copyright © 2011 RyDeR`
*/
 
#if defined _Included_GetVehicleColor
        #endinput
#endif
 
#define _Included_GetVehicleColor
 
#define PROPERTY_OFFSET(%0) \
        ((((%0) * ((%0) << 1)) << 2) + 65536)
 
stock n_AddStaticVehicle(modelID, Float: spawn_X, Float: spawn_Y, Float: spawn_Z, Float: z_Angle, color1, color2)
{
        if(color1 < 0 || color2 < 0)
        {
                color1 = random(127);
                color2 = random(127);
        }
        modelID = AddStaticVehicle(modelID, spawn_X, spawn_Y, spawn_Z, z_Angle, color1, color2);
       
        new
                colorStr[24]
        ;      
        format(colorStr, sizeof(colorStr), "%d-%d", color1, color2);
        setproperty(_, "", PROPERTY_OFFSET(modelID), colorStr);
       
        return modelID;
}
 
stock n_AddStaticVehicleEx(modelID, Float: spawn_X, Float: spawn_Y, Float: spawn_Z, Float: z_Angle, color1, color2, respawn_Delay)
{
        if(color1 < 0 || color2 < 0)
        {
                color1 = random(127);
                color2 = random(127);
        }
        modelID = AddStaticVehicleEx(modelID, spawn_X, spawn_Y, spawn_Z, z_Angle, color1, color2, respawn_Delay);
       
        new
                colorStr[24]
        ;      
        format(colorStr, sizeof(colorStr), "%d-%d", color1, color2);
        setproperty(_, "", PROPERTY_OFFSET(modelID), colorStr);
       
        return modelID;
}
 
stock n_CreateVehicle(modelID, Float: spawn_X, Float: spawn_Y, Float: spawn_Z, Float: z_Angle, color1, color2, respawn_Delay)
{
        if(color1 < 0 || color2 < 0)
        {
                color1 = random(127);
                color2 = random(127);
        }
        modelID = CreateVehicle(modelID, spawn_X, spawn_Y, spawn_Z, z_Angle, color1, color2, respawn_Delay);
       
        new
                colorStr[24]
        ;      
        format(colorStr, sizeof(colorStr), "%d-%d", color1, color2);
        setproperty(_, "", PROPERTY_OFFSET(modelID), colorStr);
       
        return modelID;
}
 
stock n_DestroyVehicle(vehicleID)
{
        deleteproperty(_, "", PROPERTY_OFFSET(vehicleID));
       
        return DestroyVehicle(vehicleID);
}
 
stock n_ChangeVehicleColor(vehicleID, color1, color2)
{
        new
                colorStr[24]
        ;      
        format(colorStr, sizeof(colorStr), "%d-%d", color1, color2);
        setproperty(_, "", PROPERTY_OFFSET(vehicleID), colorStr);
       
        return ChangeVehicleColor(vehicleID, color1, color2);
}
 
public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
        new
                colorStr[24]
        ;      
        format(colorStr, sizeof(colorStr), "%d-%d", color1, color2);
        setproperty(_, "", PROPERTY_OFFSET(vehicleid), colorStr);
       
        if(funcidx("n_OnVehicleRespray") != -1)
        {
                return CallLocalFunction("n_OnVehicleRespray", "iiii", playerid, vehicleid, color1, color2);
        }
        return 1;
}
 
stock GetVehicleColor(vehicleID, &color1, &color2)
{
        vehicleID = PROPERTY_OFFSET(vehicleID);
       
        if(existproperty(_, "", vehicleID))
        {
                new
                        colorStr[24],
                        strPos
                ;
                getproperty(_, "", vehicleID, colorStr);
                strunpack(colorStr, colorStr);
               
                if((strPos = strfind(colorStr, "-")) != -1)
                {
                        color1 = strval(colorStr);
                        color2 = strval(colorStr[strPos + 1]);
                        return 1;
                }
        }
        return 0;
}
 
#define AddStaticVehicle n_AddStaticVehicle
#define AddStaticVehicleEx n_AddStaticVehicleEx
#define CreateVehicle n_CreateVehicle
#define DestroyVehicle n_DestroyVehicle
#define ChangeVehicleColor n_ChangeVehicleColor
 
#if defined _ALS_OnVehicleRespray
        #undef OnVehicleRespray
#else
        #define _ALS_OnVehicleRespray
#endif
 
#define OnVehicleRespray n_OnVehicleRespray
 
forward n_OnVehicleRespray(playerid, vehicleid, color1, color2);

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *            Dini 1.6
 *       (c) Copyright 2006-2008 by DracoBlue
 *
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 13th May 2006
 * @update    : 16th Sep 2008
 *
 * This file is provided as is (no warranties).
 *
 * It's released under the terms of MIT.
 *
 * Feel free to use it, a little message in
 * about box is honouring thing, isn't it?
 *
 */

#if defined _dini_included
  #endinput
#endif

#define _dini_included
#pragma library dini

#if defined MAX_STRING
#define DINI_MAX_STRING MAX_STRING
#else
#define DINI_MAX_STRING 255
#endif

stock dini_Exists(filename[]) {
	return fexist(filename);
}

stock dini_Remove(filename[]) {
	return fremove(filename);
}

stock dini_Create(filename[]) {
	if (fexist(filename)) return false;
	new File:fhnd;
	fhnd=fopen(filename,io_write);
	if (fhnd) {
		fclose(fhnd);
		return true;
	}
	return false;
}

stock dini_Set(filename[],key[],value[]) {
	// If we have no key, it can't be set
	// we also have no chance to set the value, if all together is bigger then the max string
	new key_length = strlen(key);
	new value_length = strlen(value);
	if (key_length==0 || key_length+value_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[DINI_MAX_STRING];
	new bool:wasset=false;
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			!wasset
			&& tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be replaced!
				format(tmpres,sizeof(tmpres),"%s=%s",key,value);
				wasset=true;
		} else {
			DINI_StripNewLine(tmpres);
		}
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	if (!wasset) {
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (DINI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock dini_IntSet(filename[],key[],value) {
   new valuestring[DINI_MAX_STRING];
   format(valuestring,DINI_MAX_STRING,"%d",value);
   return dini_Set(filename,key,valuestring);
}

stock dini_Int(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock dini_FloatSet(filename[],key[],Float:value) {
   new valuestring[DINI_MAX_STRING];
   format(valuestring,DINI_MAX_STRING,"%f",value);
   return dini_Set(filename,key,valuestring);
}

stock Float:dini_Float(filename[],key[]) {
   return floatstr(dini_Get(filename,key));
}

stock dini_Bool(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock dini_BoolSet(filename[],key[],value) {
	if (value) {
		return dini_Set(filename,key,"1");
	}
	return dini_Set(filename,key,"0");
}

stock dini_Unset(filename[],key[]) {
	// If we have no key, it can't be set
	// we also have no chance to unset the key, if all together is bigger then the max string
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[DINI_MAX_STRING];
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,DINI_MAX_STRING,"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be removed!
		} else {
			DINI_StripNewLine(tmpres);
			fwrite(fwhnd,tmpres);
			fwrite(fwhnd,"\r\n");
		}
	}
	
	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,DINI_MAX_STRING,"%s.part",filename);
	if (DINI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}

stock dini_Get(filename[],key[]) {
	new tmpres[DINI_MAX_STRING];
	
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return tmpres;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return tmpres;
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
			/* We've got what we need */
			DINI_StripNewLine(tmpres);
			strmid(tmpres, tmpres, key_length + 1, strlen(tmpres), DINI_MAX_STRING);
			fclose(fohnd);
			return tmpres;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock dini_Isset(filename[],key[]) {
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	new tmpres[DINI_MAX_STRING];
	while (fread(fohnd,tmpres)) {
		if (
				tmpres[key_length]=='='
			&&  !strcmp(tmpres, key, true, key_length)	
		) {
			// We've got what we need
			fclose(fohnd);
			return true;
		}
	}
	fclose(fohnd);
	return false;
}



stock DINI_StripNewLine(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock DINI_fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	if (!ohnd) return false;
	nhnd=fopen(newname,io_write);
	if (!nhnd) {
		fclose(ohnd);
		return false;
	}
	new tmpres[DINI_MAX_STRING];
	while (fread(ohnd,tmpres)) {
		DINI_StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
enum g_ePlayerMenuEnum {
	PlayerText:g_eMenuTextdraws[6],
	PlayerText:g_eMenuItems[18],
	PlayerText:g_eMenuAmounts[18],
	Float:g_eMenuRot[4],
	g_eMenuModels[MAX_MENU_ITEMS],
	g_eMenuAmount[MAX_MENU_ITEMS],
	g_eMenuTotalItems,
	g_eMenuPage,
	g_eMenuPages,
	g_eMenuShown,
	g_eMenuExtra,
	g_eMenuIgnore,
	g_eMenuTime,
	g_eMenuType
};
enum g_eItemRotationEnum {
	g_eItemModel,
	Float:g_eItemRotX,
	Float:g_eItemRotY,
	Float:g_eItemRotZ,
	Float:g_eItemZoom
};

static stock
	g_ePlayerMenuData[MAX_PLAYERS][g_ePlayerMenuEnum],
	g_eMenuCustomRotation[MAX_CUSTOM_ROTATIONS][g_eItemRotationEnum]
;

static const g_arrVehicleColors[256] = {
	0x000000FF, 0xF5F5F5FF, 0x2A77A1FF, 0x840410FF, 0x263739FF, 0x86446EFF, 0xD78E10FF, 0x4C75B7FF, 0xBDBEC6FF, 0x5E7072FF,
	0x46597AFF, 0x656A79FF, 0x5D7E8DFF, 0x58595AFF, 0xD6DAD6FF, 0x9CA1A3FF, 0x335F3FFF, 0x730E1AFF, 0x7B0A2AFF, 0x9F9D94FF,
	0x3B4E78FF, 0x732E3EFF, 0x691E3BFF, 0x96918CFF, 0x515459FF, 0x3F3E45FF, 0xA5A9A7FF, 0x635C5AFF, 0x3D4A68FF, 0x979592FF,
	0x421F21FF, 0x5F272BFF, 0x8494ABFF, 0x767B7CFF, 0x646464FF, 0x5A5752FF, 0x252527FF, 0x2D3A35FF, 0x93A396FF, 0x6D7A88FF,
	0x221918FF, 0x6F675FFF, 0x7C1C2AFF, 0x5F0A15FF, 0x193826FF, 0x5D1B20FF, 0x9D9872FF, 0x7A7560FF, 0x989586FF, 0xADB0B0FF,
	0x848988FF, 0x304F45FF, 0x4D6268FF, 0x162248FF, 0x272F4BFF, 0x7D6256FF, 0x9EA4ABFF, 0x9C8D71FF, 0x6D1822FF, 0x4E6881FF,
	0x9C9C98FF, 0x917347FF, 0x661C26FF, 0x949D9FFF, 0xA4A7A5FF, 0x8E8C46FF, 0x341A1EFF, 0x6A7A8CFF, 0xAAAD8EFF, 0xAB988FFF,
	0x851F2EFF, 0x6F8297FF, 0x585853FF, 0x9AA790FF, 0x601A23FF, 0x20202CFF, 0xA4A096FF, 0xAA9D84FF, 0x78222BFF, 0x0E316DFF,
	0x722A3FFF, 0x7B715EFF, 0x741D28FF, 0x1E2E32FF, 0x4D322FFF, 0x7C1B44FF, 0x2E5B20FF, 0x395A83FF, 0x6D2837FF, 0xA7A28FFF,
	0xAFB1B1FF, 0x364155FF, 0x6D6C6EFF, 0x0F6A89FF, 0x204B6BFF, 0x2B3E57FF, 0x9B9F9DFF, 0x6C8495FF, 0x4D8495FF, 0xAE9B7FFF,
	0x406C8FFF, 0x1F253BFF, 0xAB9276FF, 0x134573FF, 0x96816CFF, 0x64686AFF, 0x105082FF, 0xA19983FF, 0x385694FF, 0x525661FF,
	0x7F6956FF, 0x8C929AFF, 0x596E87FF, 0x473532FF, 0x44624FFF, 0x730A27FF, 0x223457FF, 0x640D1BFF, 0xA3ADC6FF, 0x695853FF,
	0x9B8B80FF, 0x620B1CFF, 0x5B5D5EFF, 0x624428FF, 0x731827FF, 0x1B376DFF, 0xEC6AAEFF, 0x000000FF, 0x177517FF, 0x210606FF,
	0x125478FF, 0x452A0DFF, 0x571E1EFF, 0x010701FF, 0x25225AFF, 0x2C89AAFF, 0x8A4DBDFF, 0x35963AFF, 0xB7B7B7FF, 0x464C8DFF,
	0x84888CFF, 0x817867FF, 0x817A26FF, 0x6A506FFF, 0x583E6FFF, 0x8CB972FF, 0x824F78FF, 0x6D276AFF, 0x1E1D13FF, 0x1E1306FF,
	0x1F2518FF, 0x2C4531FF, 0x1E4C99FF, 0x2E5F43FF, 0x1E9948FF, 0x1E9999FF, 0x999976FF, 0x7C8499FF, 0x992E1EFF, 0x2C1E08FF,
	0x142407FF, 0x993E4DFF, 0x1E4C99FF, 0x198181FF, 0x1A292AFF, 0x16616FFF, 0x1B6687FF, 0x6C3F99FF, 0x481A0EFF, 0x7A7399FF,
	0x746D99FF, 0x53387EFF, 0x222407FF, 0x3E190CFF, 0x46210EFF, 0x991E1EFF, 0x8D4C8DFF, 0x805B80FF, 0x7B3E7EFF, 0x3C1737FF,
	0x733517FF, 0x781818FF, 0x83341AFF, 0x8E2F1CFF, 0x7E3E53FF, 0x7C6D7CFF, 0x020C02FF, 0x072407FF, 0x163012FF, 0x16301BFF,
	0x642B4FFF, 0x368452FF, 0x999590FF, 0x818D96FF, 0x99991EFF, 0x7F994CFF, 0x839292FF, 0x788222FF, 0x2B3C99FF, 0x3A3A0BFF,
	0x8A794EFF, 0x0E1F49FF, 0x15371CFF, 0x15273AFF, 0x375775FF, 0x060820FF, 0x071326FF, 0x20394BFF, 0x2C5089FF, 0x15426CFF,
	0x103250FF, 0x241663FF, 0x692015FF, 0x8C8D94FF, 0x516013FF, 0x090F02FF, 0x8C573AFF, 0x52888EFF, 0x995C52FF, 0x99581EFF,
	0x993A63FF, 0x998F4EFF, 0x99311EFF, 0x0D1842FF, 0x521E1EFF, 0x42420DFF, 0x4C991EFF, 0x082A1DFF, 0x96821DFF, 0x197F19FF,
	0x3B141FFF, 0x745217FF, 0x893F8DFF, 0x7E1A6CFF, 0x0B370BFF, 0x27450DFF, 0x071F24FF, 0x784573FF, 0x8A653AFF, 0x732617FF,
	0x319490FF, 0x56941DFF, 0x59163DFF, 0x1B8A2FFF, 0x38160BFF, 0x041804FF, 0x355D8EFF, 0x2E3F5BFF, 0x561A28FF, 0x4E0E27FF,
	0x706C67FF, 0x3B3E42FF, 0x2E2D33FF, 0x7B7E7DFF, 0x4A4442FF, 0x28344EFF
};

stock SetModelPreviewRotation(modelid, Float:x, Float:y, Float:z, Float:zoom = 1.0)
{
	for (new i = 0; i != MAX_CUSTOM_ROTATIONS; i ++) if (!g_eMenuCustomRotation[i][g_eItemModel]) {
		g_eMenuCustomRotation[i][g_eItemModel] = modelid;
		g_eMenuCustomRotation[i][g_eItemRotX] = x;
		g_eMenuCustomRotation[i][g_eItemRotY] = y;
		g_eMenuCustomRotation[i][g_eItemRotZ] = z;
		g_eMenuCustomRotation[i][g_eItemZoom] = zoom;

		break;
	}
	return 0;
}

stock HideModelESelectionMenu(playerid)
{
	if (!IsPlayerConnected(playerid) || !g_ePlayerMenuData[playerid][g_eMenuShown]) return 0;

	for (new i = 0; i < 6; i ++) {
	    PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][i]);
	}
	for (new i = 0; i != MAX_MENU_ITEMS; i ++)
	{
	    if (i < 18)
	    {
	        if (g_ePlayerMenuData[playerid][g_eMenuItems][i] != PlayerText:INVALID_TEXT_DRAW)
	        {
	            PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i]);
                g_ePlayerMenuData[playerid][g_eMenuItems][i] = PlayerText:INVALID_TEXT_DRAW;
			}
	    	if (g_ePlayerMenuData[playerid][g_eMenuAmounts][i] != PlayerText:INVALID_TEXT_DRAW)
	    	{
                PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i]);
                g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = PlayerText:INVALID_TEXT_DRAW;
			}
		}
		g_ePlayerMenuData[playerid][g_eMenuModels][i] = -1;
		g_ePlayerMenuData[playerid][g_eMenuAmount][i] = 0;
	}
	g_ePlayerMenuData[playerid][g_eMenuShown] = false;
	g_ePlayerMenuData[playerid][g_eMenuTotalItems] = 0;
	g_ePlayerMenuData[playerid][g_eMenuExtra] = 0;
	g_ePlayerMenuData[playerid][g_eMenuPage] = 1;
	g_ePlayerMenuData[playerid][g_eMenuPages] = 0;
    g_ePlayerMenuData[playerid][g_eMenuIgnore] = true;

	g_ePlayerMenuData[playerid][g_eMenuRot][0] = 0.0;
    g_ePlayerMenuData[playerid][g_eMenuRot][1] = 0.0;
    g_ePlayerMenuData[playerid][g_eMenuRot][2] = 0.0;
    g_ePlayerMenuData[playerid][g_eMenuRot][3] = 0.0;

	CancelSelectTextDraw(playerid);
	return 1;
}

stock ShowModelESelectionMenu(playerid, header[], extraid, items[], size = sizeof(items), Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fZoom = 1.0, carcol = -1, bool:amount = false, amounts[] = {-1})
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	if (size > MAX_MENU_ITEMS)
	    return printf("** Warning: Please increase \"MAX_MENU_ITEMS\" if you want to create more items.");

	if (g_ePlayerMenuData[playerid][g_eMenuShown])
	{
	    HideModelESelectionMenu(playerid);
	}
	for (new i = 0; i < 18; i ++) {
	    g_ePlayerMenuData[playerid][g_eMenuItems][i] = PlayerText:INVALID_TEXT_DRAW;
		g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = PlayerText:INVALID_TEXT_DRAW;
	}
	new
	    Float:x = 78.0,
	    Float:y = 162.0,
		page[8],
		str[16];

	format(page, 8, "1/%d", (size / 18) + 1);

 	for (new i = 0, idx = 0; i != MAX_MENU_ITEMS; i ++)
	{
 		if (i >= size)
 		{
 	        g_ePlayerMenuData[playerid][g_eMenuModels][i] = -1;
 	    }
 	    else
		{
		    if (items[i] == -1)
			{
                g_ePlayerMenuData[playerid][g_eMenuModels][i] = -1;
                g_ePlayerMenuData[playerid][g_eMenuAmount][i] = 0;
      		}
	  		else
	  		{
	   			g_ePlayerMenuData[playerid][g_eMenuTotalItems]++;
				g_ePlayerMenuData[playerid][g_eMenuModels][i] = items[i];

				if (amount) {
	                g_ePlayerMenuData[playerid][g_eMenuAmount][i] = amounts[i];
				}
			}
			if (i < 18 && items[i] != -1)
			{
				if (idx > 0 && (idx % 6) == 0)
				{
	   				x = 140.0;
	  	    		y += 55.0;
	  			}
	    		else
				{
	 	    		x += 62.0;
	        	}
	        	idx++;

	        	if (i < 18 && items[i] != -1)
				{
				    g_ePlayerMenuData[playerid][g_eMenuItems][i] = CreatePlayerTextDraw(playerid, x, y, "_");

					PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], -188);
					PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 5);
					PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1.430000, 5.700000);
					PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], -1);
					PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 0);
					PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 61.000000, 54.000000);
					PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], items[i]);
                    PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], fRotX, fRotY, fRotZ, fZoom);

					if (amount && amounts[i] != -1)
					{
					    format(str, 16, "%d", amounts[i]);

					    g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = CreatePlayerTextDraw(playerid, x + 57.0, y + 43.0, str);
						PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 3);
						PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 255);
						PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 1);
						PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 0.310000, 1.000000);
						PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], -1429936641);
						PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 1);
						PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i], 1);
					}
					else
					{
					    g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = PlayerText:INVALID_TEXT_DRAW;
					}
                    if (carcol != -1)
                    {
						PlayerTextDrawSetPreviewVehCol(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], carcol, carcol);
					}
					for (new j = 0; j != MAX_CUSTOM_ROTATIONS; j ++)
					{
						if (g_eMenuCustomRotation[j][g_eItemModel] == items[i])
						{
							PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], g_eMenuCustomRotation[j][g_eItemRotX], g_eMenuCustomRotation[j][g_eItemRotY], g_eMenuCustomRotation[j][g_eItemRotZ], g_eMenuCustomRotation[j][g_eItemZoom]);
							break;
						}
					}
				}
			}
		}
	}
	g_ePlayerMenuData[playerid][g_eMenuExtra] = extraid;
	g_ePlayerMenuData[playerid][g_eMenuShown] = true;
	g_ePlayerMenuData[playerid][g_eMenuPage] = 1;
	g_ePlayerMenuData[playerid][g_eMenuPages] = (size / 18) + 1;
	g_ePlayerMenuData[playerid][g_eMenuTime] = GetTickCount();
	g_ePlayerMenuData[playerid][g_eMenuType] = 1;

    g_ePlayerMenuData[playerid][g_eMenuRot][0] = fRotX;
    g_ePlayerMenuData[playerid][g_eMenuRot][1] = fRotY;
    g_ePlayerMenuData[playerid][g_eMenuRot][2] = fRotZ;
    g_ePlayerMenuData[playerid][g_eMenuRot][3] = fZoom;

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][0] = CreatePlayerTextDraw(playerid, 125.000000, 141.000000, "_");//background
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], tdboja);//255
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1.040000, 23.000007);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 119);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 529.000000, 11.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 0);

    g_ePlayerMenuData[playerid][g_eMenuTextdraws][1] = CreatePlayerTextDraw(playerid, 126.000000, 125.000000, header);//naslov
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 0);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 0.809999, 2.599999);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 0);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][2] = CreatePlayerTextDraw(playerid, 498.000000, 141.000000, page);//br stranice 1/2
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0.390000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 1);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][3] = CreatePlayerTextDraw(playerid, 499.000000, 335.000000, NERP_TEXT_NEXT);//dalje
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][4] = CreatePlayerTextDraw(playerid, 449.000000, 335.000000, NERP_TEXT_BACK);//nazad
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][5] = CreatePlayerTextDraw(playerid, 399.000000, 335.000000, NERP_TEXT_EXIT);//izlaz
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], CRVENA);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);

    for (new i = 0; i < 6; i ++) {
	    PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][i]);
	}
	for (new i = 0; i < 18; i ++) if (g_ePlayerMenuData[playerid][g_eMenuModels][i] != -1) {
	    PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i]);

	    if (g_ePlayerMenuData[playerid][g_eMenuAmounts][i] != PlayerText:INVALID_TEXT_DRAW) {
	        PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i]);
		}
	}
	SelectTextDraw(playerid, -1);
	return 1;
}

stock ShowColorSelectionMenu(playerid, extraid, colors[], size = sizeof(colors))
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	if (size > MAX_MENU_ITEMS)
	    return printf("** Warning: Please increase \"MAX_MENU_ITEMS\" if you want to create more items.");

	if (g_ePlayerMenuData[playerid][g_eMenuShown])
	{
	    HideModelESelectionMenu(playerid);
	}
	for (new i = 0; i < 18; i ++) {
	    g_ePlayerMenuData[playerid][g_eMenuItems][i] = PlayerText:INVALID_TEXT_DRAW;
		g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = PlayerText:INVALID_TEXT_DRAW;
	}
	new
	    Float:x = 78.0,
	    Float:y = 162.0,
		page[8];

	format(page, 8, "1/%d", (size / 18) + 1);

 	for (new i = 0, idx = 0; i != MAX_MENU_ITEMS; i ++)
	{
 	    if (i >= size)
		{
 	        g_ePlayerMenuData[playerid][g_eMenuModels][i] = -1;
 	    }
 	    else
		{
		    if (colors[i] == -1)
			{
                g_ePlayerMenuData[playerid][g_eMenuModels][i] = -1;
      		}
	  		else
		 	{
	   			g_ePlayerMenuData[playerid][g_eMenuTotalItems]++;
				g_ePlayerMenuData[playerid][g_eMenuModels][i] = colors[i];
			}
			if (idx < 18 && colors[i] != -1)
			{
				if (idx > 0 && (idx % 6) == 0)
				{
	   				x = 140.0;
	  	    		y += 55.0;
	  			}
	    		else
				{
	 	    		x += 62.0;
	        	}
	        	idx++;

	        	if (colors[i] != -1)
				{
				    g_ePlayerMenuData[playerid][g_eMenuItems][i] = CreatePlayerTextDraw(playerid, x, y, "_");

					PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], g_arrVehicleColors[colors[i]]);
					PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 5);
					PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1.430000, 5.700000);
					PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], -1);
					PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 0);
					PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 61.000000, 54.000000);
					PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 1);
					PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i], 19300);

					g_ePlayerMenuData[playerid][g_eMenuAmounts][i] = PlayerText:INVALID_TEXT_DRAW;
				}
			}
		}
	}
	g_ePlayerMenuData[playerid][g_eMenuExtra] = extraid;
	g_ePlayerMenuData[playerid][g_eMenuShown] = true;
	g_ePlayerMenuData[playerid][g_eMenuPage] = 1;
	g_ePlayerMenuData[playerid][g_eMenuPages] = (size / 18) + 1;
	g_ePlayerMenuData[playerid][g_eMenuTime] = GetTickCount();
	g_ePlayerMenuData[playerid][g_eMenuType] = 2;

    g_ePlayerMenuData[playerid][g_eMenuTextdraws][0] = CreatePlayerTextDraw(playerid, 126.000000, 125.000000, "Boje vozila");
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 0);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 0.809999, 2.599999);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 1);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][0], 0);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][1] = CreatePlayerTextDraw(playerid, 125.000000, 141.000000, "_");
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1.040000, 23.000007);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 119);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 529.000000, 11.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][1], 0);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][2] = CreatePlayerTextDraw(playerid, 498.000000, 141.000000, page);
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 1);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0.390000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 1);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], 0);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][3] = CreatePlayerTextDraw(playerid, 499.000000, 335.000000, "Dalje");
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][3], 1);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][4] = CreatePlayerTextDraw(playerid, 449.000000, 335.000000, "Nazad");
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], -1);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][4], 1);

	g_ePlayerMenuData[playerid][g_eMenuTextdraws][5] = CreatePlayerTextDraw(playerid, 399.000000, 335.000000, "Zatvori");
	PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 2);
	PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 255);
	PlayerTextDrawFont(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 3);
	PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 0.400000, 1.100000);
	PlayerTextDrawColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], CRVENA);
	PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 0);
	PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);
	PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], -188);
	PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 559.000000, 45.000000);
	PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][5], 1);

    for (new i = 0; i < 6; i ++) {
	    PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][i]);
	}
	for (new i = 0; i < 18; i ++) if (g_ePlayerMenuData[playerid][g_eMenuModels][i] != -1) {
	    PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i]);

	    if (g_ePlayerMenuData[playerid][g_eMenuAmounts][i] != PlayerText:INVALID_TEXT_DRAW) {
	        PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i]);
		}
	}
	SelectTextDraw(playerid, -1);
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (g_ePlayerMenuData[playerid][g_eMenuIgnore] || (GetTickCount() - g_ePlayerMenuData[playerid][g_eMenuTime]) < 200)
	{
	    g_ePlayerMenuData[playerid][g_eMenuIgnore] = false;
	    return CallLocalFunction("MS_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
	}
	else if ((clickedid == Text:INVALID_TEXT_DRAW && g_ePlayerMenuData[playerid][g_eMenuShown]))
	{
	    CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, g_ePlayerMenuData[playerid][g_eMenuExtra], 0, 0, MODEL_RESPONSE_CANCEL);
	    HideModelESelectionMenu(playerid);
	}
	return CallLocalFunction("MS_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
}

stock Menu_SetPage(playerid, page)
{
	if (g_ePlayerMenuData[playerid][g_eMenuShown])
	{
	    if (page < 1 || page > g_ePlayerMenuData[playerid][g_eMenuPages])
		    return 0;

	    new
			start = (18 * (page - 1)),
			str[16];

		for (new i = 0; i < 18; i ++) {
			PlayerTextDrawHide(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i]);
		}
		for (new i = start; i != start + 18 && i < MAX_MENU_ITEMS; i ++)
		{
  			if (g_ePlayerMenuData[playerid][g_eMenuModels][i] == -1)
  			{
     			PlayerTextDrawHide(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start]);

		        if (g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start] != PlayerText:INVALID_TEXT_DRAW)
				{
    			    PlayerTextDrawHide(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start]);
				}
			}
			else
			{
			    if (g_ePlayerMenuData[playerid][g_eMenuType] == 2)
				{
			        PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start], 19300);
			        PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start], g_arrVehicleColors[g_ePlayerMenuData[playerid][g_eMenuModels][i]]);
			    }
			    else
				{
					PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start], g_ePlayerMenuData[playerid][g_eMenuRot][0], g_ePlayerMenuData[playerid][g_eMenuRot][1], g_ePlayerMenuData[playerid][g_eMenuRot][2], g_ePlayerMenuData[playerid][g_eMenuRot][3]);

				    for (new j = 0; j != MAX_CUSTOM_ROTATIONS; j ++)
					{
						if (g_eMenuCustomRotation[j][g_eItemModel] == g_ePlayerMenuData[playerid][g_eMenuModels][i])
						{
							PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start], g_eMenuCustomRotation[j][g_eItemRotX], g_eMenuCustomRotation[j][g_eItemRotY], g_eMenuCustomRotation[j][g_eItemRotZ], g_eMenuCustomRotation[j][g_eItemZoom]);
							break;
						}
					}
				    PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start], g_ePlayerMenuData[playerid][g_eMenuModels][i]);
				}
		        PlayerTextDrawHide(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start]);
		        PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuItems][i - start]);

		        if (g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start] != PlayerText:INVALID_TEXT_DRAW)
				{
				    format(str, sizeof(str), "%d", g_ePlayerMenuData[playerid][g_eMenuAmount][i]);
					PlayerTextDrawSetString(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start], str);

					PlayerTextDrawHide(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start]);
			        PlayerTextDrawShow(playerid, g_ePlayerMenuData[playerid][g_eMenuAmounts][i - start]);
				}
			}
		}
	    g_ePlayerMenuData[playerid][g_eMenuPage] = page;

	    format(str, 8, "%d/%d", page, g_ePlayerMenuData[playerid][g_eMenuPages]);
	    PlayerTextDrawSetString(playerid, g_ePlayerMenuData[playerid][g_eMenuTextdraws][2], str);
	}
	return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (!g_ePlayerMenuData[playerid][g_eMenuShown] || (GetTickCount() - g_ePlayerMenuData[playerid][g_eMenuTime]) < 600)
	{
		return CallLocalFunction("MS_OnPlayerClickPlayerTextDraw", "ii", playerid, _:playertextid);
	}
    if (playertextid == g_ePlayerMenuData[playerid][g_eMenuTextdraws][5])
	{
        CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, g_ePlayerMenuData[playerid][g_eMenuExtra], 0, 0, MODEL_RESPONSE_CANCEL);
        HideModelESelectionMenu(playerid);
	}
	else
	{
		if (playertextid == g_ePlayerMenuData[playerid][g_eMenuTextdraws][3])
		{
			if (g_ePlayerMenuData[playerid][g_eMenuPage] == g_ePlayerMenuData[playerid][g_eMenuPages])
			    return 0;

			else
				Menu_SetPage(playerid, g_ePlayerMenuData[playerid][g_eMenuPage] + 1);
		}
		else if (playertextid == g_ePlayerMenuData[playerid][g_eMenuTextdraws][4])
		{
			if (g_ePlayerMenuData[playerid][g_eMenuPage] < 2)
			    return 0;

	        else
				Menu_SetPage(playerid, g_ePlayerMenuData[playerid][g_eMenuPage] - 1);
		}
		else for (new i = 0; i < 18; i ++)
		{
		    if (g_ePlayerMenuData[playerid][g_eMenuItems][i] == playertextid)
			{
		        new
					index = (i + (g_ePlayerMenuData[playerid][g_eMenuPage] - 1) * 18),
					extraid = g_ePlayerMenuData[playerid][g_eMenuExtra],
					modelid = g_ePlayerMenuData[playerid][g_eMenuModels][index];

	            HideModelESelectionMenu(playerid);
		        CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, extraid, index, modelid, MODEL_RESPONSE_SELECT);
		        break;
		    }
		}
	}
	return CallLocalFunction("MS_OnPlayerClickPlayerTextDraw", "dd", playerid, _:playertextid);
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickTextDraw MS_OnPlayerClickTextDraw
#define OnPlayerClickPlayerTextDraw MS_OnPlayerClickPlayerTextDraw

forward MS_OnPlayerClickTextDraw(playerid, Text:clickedid);
forward MS_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);

forward OnModelSelectionResponse(playerid, extraid, index, modelid, response);

////////////////////////////////////////////////////////////////////////////////////////////////////////
stock SetFacingPoint(actorid, Float:x, Float:y)
{
    new Float:pX, Float:pY, Float:pZ;
    GetActorPos(actorid, pX, pY, pZ);

    new Float:angle;

    if( y > pY ) angle = (-acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);
    else if( y < pY && x < pX ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 450.0);
    else if( y < pY ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);

    if(x > pX) angle = (floatabs(floatabs(angle) + 180.0));
    else angle = (floatabs(angle) - 180.0);

    return SetActorFacingAngle(actorid, angle);
}

stock SetActorFacingPlayer(actorid, playerid)
{
    new Float:pX, Float:pY, Float:pZ;
    GetPlayerPos(playerid, pX, pY, pZ);

    return SetFacingPoint(actorid, pX, pY);
}

#if defined INC_CHATBREAK

#if !defined _INC_y_va
    #error You need to "#include <YSI_Coding\y_va>" before using ChatBreaker library.
#endif

const LINE_BREAKING_LENGTH = 90;

stock SendSplitMessage(playerid, color, const msgstring[])
{
    new 
		len = strlen(msgstring);
    if(len >= LINE_BREAKING_LENGTH)
    {
		new 
			colorstring[9] = EOS, 
			colorstart = 0, 
			colorend = 0,	
			spacepos = 0, 
			bool:broken = false;

		for(new j = (LINE_BREAKING_LENGTH - 20); j < len; j++)
		{
			if(msgstring[j] == '{')
				colorstart = j;
				
			if(msgstring[j] == '}')
				colorend = j + 1;

			if(msgstring[j] == ' ')
				spacepos = j;

			if(j >= LINE_BREAKING_LENGTH && spacepos >= (LINE_BREAKING_LENGTH - 20) && (colorstart == 0 || (colorstart != 0 && colorend > colorstart)))
			{
				broken = true;

				if(colorstart != 0 && colorend != 0)
					strmid(colorstring, msgstring, colorstart, colorend, sizeof(colorstring));

				va_SendClientMessage(playerid, color, "%.*s...", spacepos, msgstring);
				va_SendClientMessage(playerid, color, "%s...%s", colorstring, msgstring[spacepos+1]);
				return 1;
			}
		}
		if(!broken)
			SendClientMessage(playerid, color, msgstring);
	}
    else return SendClientMessage(playerid, color, msgstring);
	return 1;
}

stock AC_SendClientMessage(playerid, color, const message[])
{
	SendSplitMessage(playerid, color, message);
	return 1;
}
#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif
#define SendClientMessage AC_SendClientMessage

stock SendSplitMessageToAll(color, const msgstring[])
{
    new 
		len = strlen(msgstring);
    if(len >= LINE_BREAKING_LENGTH)
    {
		new 
			colorstring[9] = EOS, 
			colorstart = 0, 
			colorend = 0,	
			spacepos = 0, 
			bool:broken=false;

		for(new j = 60; j < len; j++)
		{
			if(msgstring[j] == ' ')
				spacepos = j;
			
			if(msgstring[j] == '{')
				colorstart = j;
				
			if(msgstring[j] == '}')
				colorend = j + 1;

			if(j >= LINE_BREAKING_LENGTH && spacepos >= (LINE_BREAKING_LENGTH - 20) && (colorstart == 0 || (colorstart != 0 && colorend > colorstart)))
			{
				broken = true;
                
				if(colorstart != 0 && colorend != 0)
					strmid(colorstring, msgstring, colorstart, colorend, sizeof(colorstring));

				va_SendClientMessageToAll(color, "%.*s...", spacepos, msgstring);
				va_SendClientMessageToAll(color, "%s...%s", colorstring, msgstring[spacepos+1]);
				return 1;
			}
		}
		if(!broken)
			SendClientMessageToAll(color, msgstring);
	}
    else return SendClientMessageToAll(color, msgstring);
	return 1;
}

stock AC_SendClientMessageToAll(color, const message[])
{
	SendSplitMessageToAll(color, message);
	return 1;
}
#if defined _ALS_SendClientMessageToAll
    #undef SendClientMessageToAll
#else
    #define _ALS_SendClientMessageToAll
#endif
#define SendClientMessageToAll AC_SendClientMessageToAll

#endif

#if !defined _INC_ALT_CHAT
	#define _INC_ALT_CHAT
#else
	#endinput
#endif

#if !defined _samp_included
	#error Include \"a_samp\" first.
#endif

#if !defined MAX_LINES
	#define MAX_LINES (5)
#endif

#if !defined isnull
	#define isnull(%0) \
		((!(%0[0])) || (((%0[0]) == '\1') && (!(%0[1]))))
#endif

enum e_ALTCHAT_STATES (<<=1) {
	ALTCHAT_STATE_NONE = 0,
	ALTCHAT_STATE_CREATED = 1,
	ALTCHAT_STATE_SHOWN
};

static PlayerText: AltChat_UI[MAX_PLAYERS][MAX_LINES],
	AltChat_Text[MAX_PLAYERS][MAX_LINES][128],
	e_ALTCHAT_STATES: gPlayerAltChatState[MAX_PLAYERS] = { ALTCHAT_STATE_NONE, ... };

stock CreatePlayerAltChat(playerid) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}

	if (IsPlayerAltChatCreated(playerid)) {
		return 0;
	}

 	new PlayerText: textdrawid,
 		Float: position_y = 229.573348;

	for(new i = 0; i < MAX_LINES; ++ i) {
		textdrawid = AltChat_UI[playerid][i] = CreatePlayerTextDraw(playerid, 35.599971, position_y, " "); // Empty textdraw string causing SA-MP to crash :/
		PlayerTextDrawLetterSize(playerid, textdrawid, 0.209600, 1.137066);
		PlayerTextDrawAlignment(playerid, textdrawid, 1);
		PlayerTextDrawColor(playerid, textdrawid, -1);
		PlayerTextDrawSetShadow(playerid, textdrawid, 0);
		PlayerTextDrawSetOutline(playerid, textdrawid, 1);
		PlayerTextDrawBackgroundColor(playerid, textdrawid, 255);
		PlayerTextDrawFont(playerid, textdrawid, 1);
		PlayerTextDrawSetProportional(playerid, textdrawid, 1);
		PlayerTextDrawSetShadow(playerid, textdrawid, 0);

		AltChat_Text[playerid][i][0] = EOS;
 		
		position_y += (240.026733 - 229.573348); // This is spacing between two lines
	}

	gPlayerAltChatState[playerid] = ALTCHAT_STATE_CREATED;
	return 1;
}

stock DestroyPlayerAltChat(playerid) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}

	if (!IsPlayerAltChatCreated(playerid)) {
		return 0;
	}

	for(new i = 0; i < MAX_LINES; ++ i) {
		PlayerTextDrawDestroy(playerid, AltChat_UI[playerid][i]);

		AltChat_Text[playerid][i][0] = EOS;
		strmid(AltChat_Text[playerid][i], " ", 0, 2, 2);
	}

	gPlayerAltChatState[playerid] = ALTCHAT_STATE_NONE;
	return 1;
}

stock TogglePlayerAltChat(playerid, bool: toggle) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}

	if (!IsPlayerAltChatCreated(playerid)) {
		return 0;
	}
	
	new shown = IsPlayerAltChatShown(playerid);

	if (toggle && !shown) {
		for(new i = 0; i < MAX_LINES; ++ i) {	
			PlayerTextDrawShow(playerid, AltChat_UI[playerid][i]);
		}

		gPlayerAltChatState[playerid] ^= ALTCHAT_STATE_SHOWN;
	} else if (!toggle && shown) {
		for(new i = 0; i < MAX_LINES; ++ i) {	
			PlayerTextDrawHide(playerid, AltChat_UI[playerid][i]);
		}

		gPlayerAltChatState[playerid] ^= ALTCHAT_STATE_SHOWN;
	}
	return 1;
}
new altstring[512];

#define scmalt[%1](%2) \
	format(altstring, sizeof altstring, %2); SendPlayerAltMessage(%1,altstring)

stock SendPlayerAltMessage(playerid, message[]) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}
	
	if (!IsPlayerAltChatCreated(playerid) || !IsPlayerAltChatShown(playerid)) {
		return 0;
	}

	if (isnull(message)) {
		message[0] = ' ';
	}

	for(new i = 0; i < MAX_LINES; i ++) {
		if (i == MAX_LINES - 1) {
			strmid(AltChat_Text[playerid][i], message, 0, 128, 128);
			break;
		}
		strmid(AltChat_Text[playerid][i], AltChat_Text[playerid][i + 1], 0, 128, 128);
	}

	for (new i = 0; i < MAX_LINES; i ++) {
		if (AltChat_Text[playerid][i][0] == EOS) {
			AltChat_Text[playerid][i][0] = ' ';
		}

		PlayerTextDrawSetString(playerid, AltChat_UI[playerid][i], AltChat_Text[playerid][i]);
	}
	return 1;
}

stock IsPlayerAltChatCreated(playerid) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}
	
	return (gPlayerAltChatState[playerid] & ALTCHAT_STATE_CREATED);
}

stock IsPlayerAltChatShown(playerid) {
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}
	
	return (gPlayerAltChatState[playerid] & ALTCHAT_STATE_SHOWN);
}

#if defined _INC_y_hooks
	hook OnPlayerConnect(playerid) {
#else 
	public OnPlayerConnect(playerid) {
#endif
	for(new i = 0; i < MAX_LINES; ++ i) {
		AltChat_Text[playerid][i][0] = EOS;
	}

	gPlayerAltChatState[playerid] = ALTCHAT_STATE_NONE;

	//CreatePlayerAltChat(playerid);

	#if !defined _INC_y_hooks
		#if defined ALTCHAT_OnPlayerConnect
			return ALTCHAT_OnPlayerConnect(playerid);
		#else
			return 1;
		#endif
	#endif
}

#if !defined _INC_y_hooks
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect ALTCHAT_OnPlayerConnect
	#if defined ALTCHAT_OnPlayerConnect
		forward ALTCHAT_OnPlayerConnect(playerid);
	#endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////
		//#include <fixes>

// A_SAMP+

/*
ToggleHUDComponentForPlayer(playerid, HUD_COMPONENT_WEAPON, 0);
ToggleHUDComponentForPlayer(playerid, HUD_COMPONENT_HEALTH, 0);
ToggleHUDComponentForPlayer(playerid, HUD_COMPONENT_MONEY, 0);
*/
#define HUD_COMPONENT_ALL 0
#define HUD_COMPONENT_AMMO 1
#define HUD_COMPONENT_WEAPON 2
#define HUD_COMPONENT_HEALTH 3
#define HUD_COMPONENT_BREATH 4
#define HUD_COMPONENT_ARMOUR 5
#define HUD_COMPONENT_MINIMAP 6
#define HUD_COMPONENT_CROSSHAIR 7
#define HUD_COMPONENT_MONEY 8

#define HUD_COLOUR_MONEY_POSITIVE 0
#define HUD_COLOUR_MONEY_NEGATIVE 1
#define HUD_COLOUR_ARMOUR 2
#define HUD_COLOUR_HEALTH 3
#define HUD_COLOUR_BREATH 4
#define HUD_COLOUR_AMMO 5
#define HUD_COLOUR_WANTED_LEVEL 6
#define HUD_COLOUR_RADIO_TUNED 7
#define HUD_COLOUR_RADIO_UNTUNED 8

#define RADIO_PLAYBACKFM 1
#define RADIO_KROSE 2
#define RADIO_KDST 3
#define RADIO_BOUNCEFM 4
#define RADIO_SFUR 5
#define RADIO_LOSSANTOS 6
#define RADIO_RADIOX 7
#define RADIO_CSR 8
#define RADIO_KJAHWEST 9
#define RADIO_MASTERSOUNDS 10
#define RADIO_WCTR 11
#define RADIO_UTP 12
#define RADIO_OFF 13

#define PAUSE_ID_STATS 0
#define PAUSE_ID_STARTGAME 1
#define PAUSE_ID_BRIEF 2
#define PAUSE_ID_AUDIOSETTINGS 3
#define PAUSE_ID_DISPLAYSETTINGS 4
#define PAUSE_ID_MAP 5
#define PAUSE_ID_DEFAULTSETTINGS 23
#define PAUSE_ID_AUDIODEFAULTSETTINGS 24
#define PAUSE_ID_CONTROLLERDEFAULTSETTINGS 25
#define PAUSE_ID_USERTRACKOPTIONS 26
#define PAUSE_ID_LANGUAGE 28
#define PAUSE_ID_OPTIONS 33
#define PAUSE_ID_QUITGAME 35
#define PAUSE_ID_CONTROLLERSETUP 36
#define PAUSE_ID_REDEFINECONTROLS 37
#define PAUSE_ID_FOOTVEHICLECONTROLS 38
#define PAUSE_ID_MOUSESETTINGS 39
#define PAUSE_ID_JOYPADSETTINGS 40
#define PAUSE_ID_MAIN 41

#define PLAYER_ACTION_ALL 0
#define PLAYER_ACTION_SPRINT 1
#define PLAYER_ACTION_ENTER_CAR 2
#define PLAYER_ACTION_CROUCH 3
#define PLAYER_ACTION_FIRE_WEAPON 4
#define PLAYER_ACTION_UNKNOWN 5
#define PLAYER_ACTION_SWITCH_WEAPON 6
#define PLAYER_ACTION_JUMP 7

#define STUNT_TYPE_TWO_WHEELS 247
#define STUNT_TYPE_INSANE 173
#define STUNT_TYPE_WHEELIE 117
#define STUNT_TYPE_STOPPIE 233

#define DEFAULT_BLUR_INTENSITY 36
#define NO_BLUR_INTENSITY 0

#define DEFAULT_AIRCRAFT_HEIGHT 800
#define DEFAULT_JETPACK_HEIGHT 100

#define MOUSE_LEFT_CLICK 0
#define MOUSE_RIGHT_CLICK 1
#define MOUSE_MIDDLE_CLICK 2

native SetPlayerCheckpointEx(playerid, Float:x, Float:y, Float:z, Float:size, colour = 0xFF000020, period = 1024, Float:pulse = 0.1, rotation_rate = 0, bool:check_z = true);
native SetPlayerCheckpointColour(playerid, colour);

native SetPlayerRaceCheckpointEx(playerid, type, Float:x, Float:y, Float:z, Float:point_x, Float:point_y, Float:point_z, Float:size, colour = 0xFF000020, period = 1024, Float:pulse = 0.1, rotation_rate = 0);
native SetPlayerRaceCheckpointColour(playerid, colour);

native ToggleHUDComponentForPlayer(playerid, componentid, bool:toggle);
native SetRadioStationForPlayer(playerid, stationid);
native SetWaveHeightForPlayer(playerid, Float:height);
native SetWaveHeightForAll(Float:height);
native TogglePauseMenuAbility(playerid, bool:toggle);
native IsPlayerInPauseMenu(playerid);
native SetPlayerHUDComponentColour(playerid, componentid, colour);
native TogglePlayerAction(playerid, actionid, bool:toggle);
native SetPlayerBlurIntensity(playerid, intensity);
native SetPlayerGameSpeed(playerid, Float:speed);
native TogglePlayerDriveOnWater(playerid, bool:toggle);
native TogglePlayerFrozen(playerid, bool:toggle);
native SetPlayerPedAnims(playerid, bool:toggle);
native TogglePlayerSwitchReload(playerid, bool:toggle);
native bool:IsUsingSAMPP(playerid);
native GetPlayerResolution(playerid, &X, &Y);
native SetPlayerNoReload(playerid, bool:toggle);
native TogglePlayerInfiniteRun(playerid, bool:toggle);
native SetPlayerAircraftHeight(playerid, Float:height);
native Float:GetPlayerAircraftHeight(playerid);
native SetPlayerJetpackHeight(playerid, Float:height);
native Float:GetPlayerJetpackHeight(playerid);
native TogglePlayerVehicleBlips(playerid, bool:toggle);
native GetPlayerVehicleBlips(playerid);
native GetPlayerRadioStation(playerid);
native TogglePlayerInfiniteOxygen(playerid, bool:toggle);
native ToggleWaterBuoyancy(playerid, bool:toggle);
native ToggleUnderwaterEffect(playerid, bool:toggle);
native ToggleNightVision(playerid, bool:toggle);
native ToggleThermalVision(playerid, bool:toggle);
native SAMPP_ExecuteCallback(type, {Float,_}:...);

forward OnPlayerOpenPauseMenu(playerid);
forward OnPlayerClosePauseMenu(playerid);
forward OnPlayerEnterPauseSubmenu(playerid, from, to);
forward OnDriverDriveByShot(playerid);
forward OnPlayerStunt(playerid, stuntid, money, details[]);
forward OnPlayerResolutionChange(playerid, X, Y);
forward OnPlayerSAMPPConnect(address[], port);
forward OnPlayerSAMPPJoin(playerid, bool:has_plugin);
forward OnPlayerClick(playerid, type, X, Y);
forward OnPlayerChangeRadioStation(playerid, stationid, vehicleid);
forward OnPlayerDrinkSprunk(playerid);

public OnPlayerConnect(playerid)
{
	SAMPP_ExecuteCallback(0, playerid);

#if defined SAMPP_OnPlayerConnect
	return SAMPP_OnPlayerConnect(playerid);
#else
	return 1;
#endif
}

#if defined SAMPP_OnPlayerConnect
	forward SAMPP_OnPlayerConnect(playerid);
#endif
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect SAMPP_OnPlayerConnect

public OnPlayerDisconnect(playerid, reason)
{
	SAMPP_ExecuteCallback(1, playerid, reason);

#if defined SAMPP_OnPlayerDisconnect
	return SAMPP_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}

#if defined SAMPP_OnPlayerDisconnect
	forward SAMPP_OnPlayerDisconnect(playerid, reason);
#endif
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect SAMPP_OnPlayerDisconnect
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Copyright (C) 2017 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined _streamer_included
	#endinput
#endif
#define _streamer_included

#include <a_samp>

// Definitions

#define STREAMER_TYPE_OBJECT (0)
#define STREAMER_TYPE_PICKUP (1)
#define STREAMER_TYPE_CP (2)
#define STREAMER_TYPE_RACE_CP (3)
#define STREAMER_TYPE_MAP_ICON (4)
#define STREAMER_TYPE_3D_TEXT_LABEL (5)
#define STREAMER_TYPE_AREA (6)
#define STREAMER_TYPE_ACTOR (7)

#define STREAMER_AREA_TYPE_CIRCLE (0)
#define STREAMER_AREA_TYPE_CYLINDER (1)
#define STREAMER_AREA_TYPE_SPHERE (2)
#define STREAMER_AREA_TYPE_RECTANGLE (3)
#define STREAMER_AREA_TYPE_CUBOID (4)
#define STREAMER_AREA_TYPE_POLYGON (5)

#define STREAMER_OBJECT_TYPE_GLOBAL (0)
#define STREAMER_OBJECT_TYPE_PLAYER (1)
#define STREAMER_OBJECT_TYPE_DYNAMIC (2)

#define STREAMER_MAX_TYPES (8)
#define STREAMER_MAX_AREA_TYPES (6)
#define STREAMER_MAX_OBJECT_TYPES (3)

#define INVALID_STREAMER_ID (0)

#if !defined FLOAT_INFINITY
    #define FLOAT_INFINITY (Float:0x7F800000)
#endif

#if defined STREAMER_ENABLE_TAGS
	#define STREAMER_TAG_OBJECT DynamicObject
	#define STREAMER_TAG_OBJECT_ALT {DynamicObject,_}
	#define STREAMER_TAG_PICKUP DynamicPickup
	#define STREAMER_TAG_CP DynamicCP
	#define STREAMER_TAG_RACE_CP DynamicRaceCP
	#define STREAMER_TAG_MAP_ICON DynamicMapIcon
	#define STREAMER_TAG_3D_TEXT_LABEL DynamicText3D
	#define STREAMER_TAG_AREA DynamicArea
	#define STREAMER_TAG_ACTOR DynamicActor

	#define STREAMER_ALL_TAGS {DynamicObject,DynamicPickup,DynamicCP,DynamicRaceCP,DynamicMapIcon,DynamicText3D,DynamicArea,DynamicActor,_}
#else
	#define STREAMER_TAG_OBJECT _
	#define STREAMER_TAG_OBJECT_ALT _
	#define STREAMER_TAG_PICKUP _
	#define STREAMER_TAG_CP _
	#define STREAMER_TAG_RACE_CP _
	#define STREAMER_TAG_MAP_ICON _
	#define STREAMER_TAG_AREA _
	#define STREAMER_TAG_ACTOR _

	#if defined STREAMER_REMOVE_TEXT3D_TAG
		#define STREAMER_TAG_3D_TEXT_LABEL _
		#define STREAMER_ALL_TAGS _
	#else
		#if defined STREAMER_USE_DYNAMIC_TEXT3D_TAG
			#define STREAMER_TAG_3D_TEXT_LABEL DynamicText3D
			#define STREAMER_ALL_TAGS {DynamicText3D,_}
		#else
			#define STREAMER_TAG_3D_TEXT_LABEL Text3D
			#define STREAMER_ALL_TAGS {Text3D,_}
		#endif
	#endif
#endif

#if !defined STREAMER_OBJECT_SD
	#define STREAMER_OBJECT_SD 300.0
#endif
#if !defined STREAMER_OBJECT_DD
	#define STREAMER_OBJECT_DD 0.0
#endif
#if !defined STREAMER_PICKUP_SD
	#define STREAMER_PICKUP_SD 200.0
#endif
#if !defined STREAMER_CP_SD
	#define STREAMER_CP_SD 200.0
#endif
#if !defined STREAMER_RACE_CP_SD
	#define STREAMER_RACE_CP_SD 200.0
#endif
#if !defined STREAMER_MAP_ICON_SD
	#define STREAMER_MAP_ICON_SD 200.0
#endif
#if !defined STREAMER_3D_TEXT_LABEL_SD
	#define STREAMER_3D_TEXT_LABEL_SD 200.0
#endif
#if !defined STREAMER_ACTOR_SD
	#define STREAMER_ACTOR_SD 200.0
#endif

// Include File Version

public Streamer_IncludeFileVersion = 0x295;

#pragma unused Streamer_IncludeFileVersion

// Enum

enum
{
	E_STREAMER_AREA_ID,
	E_STREAMER_ATTACHED_OBJECT,
	E_STREAMER_ATTACHED_PLAYER,
	E_STREAMER_ATTACHED_VEHICLE,
	E_STREAMER_ATTACH_OFFSET_X,
	E_STREAMER_ATTACH_OFFSET_Y,
	E_STREAMER_ATTACH_OFFSET_Z,
	E_STREAMER_ATTACH_R_X,
	E_STREAMER_ATTACH_R_Y,
	E_STREAMER_ATTACH_R_Z,
	E_STREAMER_ATTACH_X,
	E_STREAMER_ATTACH_Y,
	E_STREAMER_ATTACH_Z,
	E_STREAMER_COLOR,
	E_STREAMER_DRAW_DISTANCE,
	E_STREAMER_EXTRA_ID,
	E_STREAMER_HEALTH,
	E_STREAMER_INTERIOR_ID,
	E_STREAMER_INVULNERABLE,
	E_STREAMER_MAX_X,
	E_STREAMER_MAX_Y,
	E_STREAMER_MAX_Z,
	E_STREAMER_MIN_X,
	E_STREAMER_MIN_Y,
	E_STREAMER_MIN_Z,
	E_STREAMER_MODEL_ID,
	E_STREAMER_MOVE_R_X,
	E_STREAMER_MOVE_R_Y,
	E_STREAMER_MOVE_R_Z,
	E_STREAMER_MOVE_SPEED,
	E_STREAMER_MOVE_X,
	E_STREAMER_MOVE_Y,
	E_STREAMER_MOVE_Z,
	E_STREAMER_NEXT_X,
	E_STREAMER_NEXT_Y,
	E_STREAMER_NEXT_Z,
	E_STREAMER_PLAYER_ID,
	E_STREAMER_PRIORITY,
	E_STREAMER_ROTATION,
	E_STREAMER_R_X,
	E_STREAMER_R_Y,
	E_STREAMER_R_Z,
	E_STREAMER_SIZE,
	E_STREAMER_STREAM_DISTANCE,
	E_STREAMER_STYLE,
	E_STREAMER_SYNC_ROTATION,
	E_STREAMER_TEST_LOS,
	E_STREAMER_TYPE,
	E_STREAMER_WORLD_ID,
	E_STREAMER_X,
	E_STREAMER_Y,
	E_STREAMER_Z
}

#define E_STREAMER_CUSTOM(%0) ((%0) | 0x40000000 & ~0x80000000)

// Natives (Settings)

native Streamer_GetTickRate();
native Streamer_SetTickRate(rate);
native Streamer_GetPlayerTickRate(playerid);
native Streamer_SetPlayerTickRate(playerid, rate);
native Streamer_ToggleChunkStream(toggle);
native Streamer_IsToggleChunkStream();
native Streamer_GetChunkTickRate(type, playerid = -1);
native Streamer_SetChunkTickRate(type, rate, playerid = -1);
native Streamer_GetChunkSize(type);
native Streamer_SetChunkSize(type, size);
native Streamer_GetMaxItems(type);
native Streamer_SetMaxItems(type, items);
native Streamer_GetVisibleItems(type, playerid = -1);
native Streamer_SetVisibleItems(type, items, playerid = -1);
native Streamer_GetRadiusMultiplier(type, &Float:multiplier, playerid = -1);
native Streamer_SetRadiusMultiplier(type, Float:multiplier, playerid = -1);
native Streamer_GetTypePriority(types[], maxtypes = sizeof types);
native Streamer_SetTypePriority(const types[], maxtypes = sizeof types);
native Streamer_GetCellDistance(&Float:distance);
native Streamer_SetCellDistance(Float:distance);
native Streamer_GetCellSize(&Float:size);
native Streamer_SetCellSize(Float:size);
native Streamer_ToggleItemStatic(type, STREAMER_ALL_TAGS:id, toggle);
native Streamer_IsToggleItemStatic(type, STREAMER_ALL_TAGS:id);
native Streamer_ToggleItemInvAreas(type, STREAMER_ALL_TAGS:id, toggle);
native Streamer_IsToggleItemInvAreas(type, STREAMER_ALL_TAGS:id);
native Streamer_ToggleItemCallbacks(type, STREAMER_ALL_TAGS:id, toggle);
native Streamer_IsToggleItemCallbacks(type, STREAMER_ALL_TAGS:id);
native Streamer_ToggleErrorCallback(toggle);
native Streamer_IsToggleErrorCallback();
native Streamer_AmxUnloadDestroyItems(toggle);

// Natives (Updates)

native Streamer_ProcessActiveItems();
native Streamer_ToggleIdleUpdate(playerid, toggle);
native Streamer_IsToggleIdleUpdate(playerid);
native Streamer_ToggleCameraUpdate(playerid, toggle);
native Streamer_IsToggleCameraUpdate(playerid);
native Streamer_ToggleItemUpdate(playerid, type, toggle);
native Streamer_IsToggleItemUpdate(playerid, type);
native Streamer_GetLastUpdateTime(&Float:time);
native Streamer_Update(playerid, type = -1);
native Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, type = -1, compensatedtime = -1, freezeplayer = 1);

// Natives (Data Manipulation)

native Streamer_GetFloatData(type, STREAMER_ALL_TAGS:id, data, &Float:result);
native Streamer_SetFloatData(type, STREAMER_ALL_TAGS:id, data, Float:value);
native Streamer_GetIntData(type, STREAMER_ALL_TAGS:id, data);
native Streamer_SetIntData(type, STREAMER_ALL_TAGS:id, data, value);
native Streamer_RemoveIntData(type, STREAMER_ALL_TAGS:id, data);
native Streamer_HasIntData(type, STREAMER_ALL_TAGS:id, data);
native Streamer_GetArrayData(type, STREAMER_ALL_TAGS:id, data, dest[], maxdest = sizeof dest);
native Streamer_SetArrayData(type, STREAMER_ALL_TAGS:id, data, const src[], maxsrc = sizeof src);
native Streamer_IsInArrayData(type, STREAMER_ALL_TAGS:id, data, value);
native Streamer_AppendArrayData(type, STREAMER_ALL_TAGS:id, data, value);
native Streamer_RemoveArrayData(type, STREAMER_ALL_TAGS:id, data, value);
native Streamer_HasArrayData(type, STREAMER_ALL_TAGS:id, data);
native Streamer_GetArrayDataLength(type, STREAMER_ALL_TAGS:id, data);
native Streamer_GetUpperBound(type);

// Natives (Miscellaneous)

native Streamer_GetDistanceToItem(Float:x, Float:y, Float:z, type, STREAMER_ALL_TAGS:id, &Float:distance, dimensions = 3);
native Streamer_ToggleItem(playerid, type, STREAMER_ALL_TAGS:id, toggle);
native Streamer_IsToggleItem(playerid, type, STREAMER_ALL_TAGS:id);
native Streamer_ToggleAllItems(playerid, type, toggle, const exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native Streamer_GetItemInternalID(playerid, type, STREAMER_ALL_TAGS:streamerid);
native Streamer_GetItemStreamerID(playerid, type, internalid);
native Streamer_IsItemVisible(playerid, type, STREAMER_ALL_TAGS:id);
native Streamer_DestroyAllVisibleItems(playerid, type, serverwide = 1);
native Streamer_CountVisibleItems(playerid, type, serverwide = 1);
native Streamer_DestroyAllItems(type, serverwide = 1);
native Streamer_CountItems(type, serverwide = 1);
native Streamer_GetNearbyItems(Float:x, Float:y, Float:z, type, STREAMER_ALL_TAGS:items[], maxitems = sizeof items, Float:range = 300.0, worldid = -1);
native Streamer_GetAllVisibleItems(playerid, type, STREAMER_ALL_TAGS:items[], maxitems = sizeof items);
native Streamer_GetItemPos(type, STREAMER_ALL_TAGS:id, &Float:x, &Float:y, &Float:z);
native Streamer_SetItemPos(type, STREAMER_ALL_TAGS:id, Float:x, Float:y, Float:z);
native Streamer_GetItemOffset(type, STREAMER_ALL_TAGS:id, &Float:x, &Float:y, &Float:z);
native Streamer_SetItemOffset(type, STREAMER_ALL_TAGS:id, Float:x, Float:y, Float:z);

// Natives (Objects)

native STREAMER_TAG_OBJECT:CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicObject(STREAMER_TAG_OBJECT:objectid);
native IsValidDynamicObject(STREAMER_TAG_OBJECT:objectid);
native GetDynamicObjectPos(STREAMER_TAG_OBJECT:objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectPos(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectRot(STREAMER_TAG_OBJECT:objectid, &Float:rx, &Float:ry, &Float:rz);
native SetDynamicObjectRot(STREAMER_TAG_OBJECT:objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectNoCameraCol(STREAMER_TAG_OBJECT:objectid);
native SetDynamicObjectNoCameraCol(STREAMER_TAG_OBJECT:objectid);
native MoveDynamicObject(STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z, Float:speed, Float:rx = -1000.0, Float:ry = -1000.0, Float:rz = -1000.0);
native StopDynamicObject(STREAMER_TAG_OBJECT:objectid);
native IsDynamicObjectMoving(STREAMER_TAG_OBJECT:objectid);
native AttachCameraToDynamicObject(playerid, STREAMER_TAG_OBJECT:objectid);
native AttachDynamicObjectToObject(STREAMER_TAG_OBJECT:objectid, attachtoid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz, syncrotation = 1);
native AttachDynamicObjectToPlayer(STREAMER_TAG_OBJECT:objectid, playerid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz);
native AttachDynamicObjectToVehicle(STREAMER_TAG_OBJECT:objectid, vehicleid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz);
native EditDynamicObject(playerid, STREAMER_TAG_OBJECT:objectid);
native IsDynamicObjectMaterialUsed(STREAMER_TAG_OBJECT:objectid, materialindex);
native RemoveDynamicObjectMaterial(STREAMER_TAG_OBJECT:objectid, materialindex);
native GetDynamicObjectMaterial(STREAMER_TAG_OBJECT:objectid, materialindex, &modelid, txdname[], texturename[], &materialcolor, maxtxdname = sizeof txdname, maxtexturename = sizeof texturename);
native SetDynamicObjectMaterial(STREAMER_TAG_OBJECT:objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor = 0);
native IsDynamicObjectMaterialTextUsed(STREAMER_TAG_OBJECT:objectid, materialindex);
native RemoveDynamicObjectMaterialText(STREAMER_TAG_OBJECT:objectid, materialindex);
native GetDynamicObjectMaterialText(STREAMER_TAG_OBJECT:objectid, materialindex, text[], &materialsize, fontface[], &fontsize, &bold, &fontcolor, &backcolor, &textalignment, maxtext = sizeof text, maxfontface = sizeof fontface);
native SetDynamicObjectMaterialText(STREAMER_TAG_OBJECT:objectid, materialindex, const text[], materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0);
native STREAMER_TAG_OBJECT:GetPlayerCameraTargetDynObject(playerid);

// Natives (Pickups)

native STREAMER_TAG_PICKUP:CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_PICKUP_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicPickup(STREAMER_TAG_PICKUP:pickupid);
native IsValidDynamicPickup(STREAMER_TAG_PICKUP:pickupid);

// Natives (Checkpoints)

native STREAMER_TAG_CP:CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_CP_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicCP(STREAMER_TAG_CP:checkpointid);
native IsValidDynamicCP(STREAMER_TAG_CP:checkpointid);
native IsPlayerInDynamicCP(playerid, STREAMER_TAG_CP:checkpointid);
native STREAMER_TAG_CP:GetPlayerVisibleDynamicCP(playerid);

// Natives (Race Checkpoints)

native STREAMER_TAG_RACE_CP:CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_RACE_CP_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicRaceCP(STREAMER_TAG_RACE_CP:checkpointid);
native IsValidDynamicRaceCP(STREAMER_TAG_RACE_CP:checkpointid);
native IsPlayerInDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid);
native STREAMER_TAG_RACE_CP:GetPlayerVisibleDynamicRaceCP(playerid);

// Natives (Map Icons)

native STREAMER_TAG_MAP_ICON:CreateDynamicMapIcon(Float:x, Float:y, Float:z, type, color, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_MAP_ICON_SD, style = MAPICON_LOCAL, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicMapIcon(STREAMER_TAG_MAP_ICON:iconid);
native IsValidDynamicMapIcon(STREAMER_TAG_MAP_ICON:iconid);

// Natives (3D Text Labels)

native STREAMER_TAG_3D_TEXT_LABEL:CreateDynamic3DTextLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL:id);
native IsValidDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL:id);
native GetDynamic3DTextLabelText(STREAMER_TAG_3D_TEXT_LABEL:id, text[], maxtext = sizeof text);
native UpdateDynamic3DTextLabelText(STREAMER_TAG_3D_TEXT_LABEL:id, color, const text[]);

// Natives (Areas)

native STREAMER_TAG_AREA:CreateDynamicCircle(Float:x, Float:y, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicCylinder(Float:x, Float:y, Float:minz, Float:maxz, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicSphere(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicRectangle(Float:minx, Float:miny, Float:maxx, Float:maxy, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicCuboid(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicCube(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA:CreateDynamicPolygon(const Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native DestroyDynamicArea(STREAMER_TAG_AREA:areaid);
native IsValidDynamicArea(STREAMER_TAG_AREA:areaid);
native GetDynamicAreaType(STREAMER_TAG_AREA:areaid);
native GetDynamicPolygonPoints(STREAMER_TAG_AREA:areaid, Float:points[], maxpoints = sizeof points);
native GetDynamicPolygonNumberPoints(STREAMER_TAG_AREA:areaid);
native IsPlayerInDynamicArea(playerid, STREAMER_TAG_AREA:areaid, recheck = 0);
native IsPlayerInAnyDynamicArea(playerid, recheck = 0);
native IsAnyPlayerInDynamicArea(STREAMER_TAG_AREA:areaid, recheck = 0);
native IsAnyPlayerInAnyDynamicArea(recheck = 0);
native GetPlayerDynamicAreas(playerid, STREAMER_TAG_AREA:areas[], maxareas = sizeof areas);
native GetPlayerNumberDynamicAreas(playerid);
native IsPointInDynamicArea(STREAMER_TAG_AREA:areaid, Float:x, Float:y, Float:z);
native IsPointInAnyDynamicArea(Float:x, Float:y, Float:z);
native IsLineInDynamicArea(STREAMER_TAG_AREA:areaid, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native IsLineInAnyDynamicArea(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native GetDynamicAreasForPoint(Float:x, Float:y, Float:z, STREAMER_TAG_AREA:areas[], maxareas = sizeof areas);
native GetNumberDynamicAreasForPoint(Float:x, Float:y, Float:z);
native GetDynamicAreasForLine(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, STREAMER_TAG_AREA:areas[], maxareas = sizeof areas);
native GetNumberDynamicAreasForLine(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native AttachDynamicAreaToObject(STREAMER_TAG_AREA:areaid, STREAMER_TAG_OBJECT_ALT:objectid, type = STREAMER_OBJECT_TYPE_DYNAMIC, playerid = INVALID_PLAYER_ID, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native AttachDynamicAreaToPlayer(STREAMER_TAG_AREA:areaid, playerid, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native AttachDynamicAreaToVehicle(STREAMER_TAG_AREA:areaid, vehicleid, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native ToggleDynAreaSpectateMode(STREAMER_TAG_AREA:areaid, toggle);
native IsToggleDynAreaSpectateMode(STREAMER_TAG_AREA:areaid);

// Natives (Actors)

native STREAMER_TAG_ACTOR:CreateDynamicActor(modelid, Float:x, Float:y, Float:z, Float:r, invulnerable = true, Float:health = 100.0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_ACTOR_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0);
native DestroyDynamicActor(STREAMER_TAG_ACTOR:actorid);
native IsValidDynamicActor(STREAMER_TAG_ACTOR:actorid);
native IsDynamicActorStreamedIn(STREAMER_TAG_ACTOR:actorid, forplayerid);
native GetDynamicActorVirtualWorld(STREAMER_TAG_ACTOR:actorid);
native SetDynamicActorVirtualWorld(STREAMER_TAG_ACTOR:actorid, vworld);
native GetDynamicActorAnimation(STREAMER_TAG_ACTOR:actorid, animlib[], animname[], &Float:fdelta, &loop, &lockx, &locky, &freeze, &time, maxanimlib = sizeof animlib, maxanimname = sizeof animname);
native ApplyDynamicActorAnimation(STREAMER_TAG_ACTOR:actorid, const animlib[], const animname[], Float:fdelta, loop, lockx, locky, freeze, time);
native ClearDynamicActorAnimations(STREAMER_TAG_ACTOR:actorid);
native GetDynamicActorFacingAngle(STREAMER_TAG_ACTOR:actorid, &Float:ang);
native SetDynamicActorFacingAngle(STREAMER_TAG_ACTOR:actorid, Float:ang);
native GetDynamicActorPos(STREAMER_TAG_ACTOR:actorid, &Float:x, &Float:y, &Float:z);
native SetDynamicActorPos(STREAMER_TAG_ACTOR:actorid, Float:x, Float:y, Float:z);
native GetDynamicActorHealth(STREAMER_TAG_ACTOR:actorid, &Float:health);
native SetDynamicActorHealth(STREAMER_TAG_ACTOR:actorid, Float:health);
native SetDynamicActorInvulnerable(STREAMER_TAG_ACTOR:actorid, invulnerable = true);
native IsDynamicActorInvulnerable(STREAMER_TAG_ACTOR:actorid);
native STREAMER_TAG_ACTOR:GetPlayerTargetDynamicActor(playerid);
native STREAMER_TAG_ACTOR:GetPlayerCameraTargetDynActor(playerid);

// Natives (Extended)

native STREAMER_TAG_OBJECT:CreateDynamicObjectEx(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_PICKUP:CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = STREAMER_PICKUP_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_CP:CreateDynamicCPEx(Float:x, Float:y, Float:z, Float:size, Float:streamdistance = STREAMER_CP_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_RACE_CP:CreateDynamicRaceCPEx(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, Float:streamdistance = STREAMER_RACE_CP_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_MAP_ICON:CreateDynamicMapIconEx(Float:x, Float:y, Float:z, type, color, style = MAPICON_LOCAL, Float:streamdistance = STREAMER_MAP_ICON_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_3D_TEXT_LABEL:CreateDynamic3DTextLabelEx(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0,
	maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_AREA:CreateDynamicCircleEx(Float:x, Float:y, Float:size, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicCylinderEx(Float:x, Float:y, Float:minz, Float:maxz, Float:size, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicSphereEx(Float:x, Float:y, Float:z, Float:size, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicRectangleEx(Float:minx, Float:miny, Float:maxx, Float:maxy, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicCuboidEx(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicCubeEx(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA:CreateDynamicPolygonEx(const Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_ACTOR:CreateDynamicActorEx(modelid, Float:x, Float:y, Float:z, Float:r, invulnerable = 1, Float:health = 100.0, Float:streamdistance = STREAMER_ACTOR_SD, const worlds[] = { -1 }, const interiors[] = { -1 }, const players[] = { -1 }, const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);

// Natives (Deprecated)

native Streamer_CallbackHook(callback, {Float,_}:...);

native Streamer_TickRate(rate);
native Streamer_MaxItems(type, items);
native Streamer_VisibleItems(type, items, playerid = -1);
native Streamer_CellDistance(Float:distance);
native Streamer_CellSize(Float:size);

native DestroyAllDynamicObjects();
native CountDynamicObjects();
native DestroyAllDynamicPickups();
native CountDynamicPickups();
native DestroyAllDynamicCPs();
native CountDynamicCPs();
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();
native DestroyAllDynamicAreas();
native CountDynamicAreas();

native TogglePlayerDynamicCP(playerid, STREAMER_TAG_CP:checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle, const exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native TogglePlayerDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle, const exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native TogglePlayerDynamicArea(playerid, STREAMER_TAG_AREA:areaid, toggle);
native TogglePlayerAllDynamicAreas(playerid, toggle, const exceptions[] = { -1 }, maxexceptions = sizeof exceptions);

// Callbacks

forward OnDynamicObjectMoved(STREAMER_TAG_OBJECT:objectid);
forward OnPlayerEditDynamicObject(playerid, STREAMER_TAG_OBJECT:objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
forward OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT:objectid, modelid, Float:x, Float:y, Float:z);
forward OnPlayerShootDynamicObject(playerid, weaponid, STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z);
forward OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP:pickupid);
forward OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP:checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid);
forward OnPlayerEnterDynamicArea(playerid, STREAMER_TAG_AREA:areaid);
forward OnPlayerLeaveDynamicArea(playerid, STREAMER_TAG_AREA:areaid);
forward OnPlayerGiveDamageDynamicActor(playerid, STREAMER_TAG_ACTOR:actorid, Float:amount, weaponid, bodypart);
forward OnDynamicActorStreamIn(STREAMER_TAG_ACTOR:actorid, forplayerid);
forward OnDynamicActorStreamOut(STREAMER_TAG_ACTOR:actorid, forplayerid);
forward Streamer_OnItemStreamIn(type, STREAMER_ALL_TAGS:id, forplayerid);
forward Streamer_OnItemStreamOut(type, STREAMER_ALL_TAGS:id, forplayerid);
forward Streamer_OnPluginError(const error[]);

	
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
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
* Zadnji update: JULI 2023      *
*
* Mapper: Mata | Vlasnik: Skopsi          *
*                   *
*/
// ZADNJA VERZIJA braski 					*
// LogNeaktivnost 					*
// PUBGGGGGGGGGGGG UPDATE PUBG PABDĐZ PUBG PUBG
// DODANA ORUZJA NA PUBG ;D
// DODANA VOZILA NA PUBG :D 	*
// PUBG OPTIMIZOVAN
// DODAT SISTEM SA SKRACENICE*
//
// HIUDHZIKHSIKJSHKSHKJHS

//#pragma option -l

// a*
//b
//brate najzadnje je nema sta



////////////////////////////////////////////////////

#define INCLUDE_NERP_MODULES 1


stock tmpobjid;
stock object_world = 0;
stock object_int = 0;
#define NERP_ZOMBIE_SISTEM 1
#define NERP_LOAD_TIMERS 1
#pragma option -;+
#define nerp_droga 1
#define NERP_DISCORD_BOT 0
#define injury_system_failure_not 1
#include "NERP_TEXT.inc"
#include <a_samp>
#include <a_actor>
#include <a_objects>
#include <sscanf2>
#include <YSI\y_ini>
#include "NERP_SAMPEX.inc"
#if !defined SAMPEX_INCLUDED_FILE
	#error Could not find Sa-mpEx library: by DEntisT
#endif
#define IZCMD_ENABLE_CASE_SENSITIVITY
#include <izcmd>
#include <newsamp>
#include <mapandreas>
#include <mSelection>
#if !defined MAX_MENU_ITEMS
	#define MAX_MENU_ITEMS (300)
#endif

#if !defined MAX_CUSTOM_ROTATIONS
	#define MAX_CUSTOM_ROTATIONS (50)
#endif
#define MODEL_RESPONSE_CANCEL (0)
#define MODEL_RESPONSE_SELECT (1)
#define tdboja 0x5371ffff//5468671
//0x80FF00FF//ZELENA//SVETLOPLAVA//1604639231
#if !defined isnull
	#define isnull(%1) \
				((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
stock
	udb_hash(buf[]) 
{
	new length=strlen(buf);
	new s1 = 1;
	new s2 = 0;
	new n;
	for (n=0; n<length; n++)
	{
	  s1 = (s1 + buf[n]) % 65521;
	  s2 = (s2 + s1)     % 65521;
	}
	return (s2 << 16) + s1;
}
//==============================================================================

#include "NERP_CORE/NERP_VARS.inc"

//------------------------------------------------------------------------------

#include "NERP_CORE/NERP_IMPL.inc"
#include "NERP_CORE/NERP_POSLOVI.inc"

//------------------------------------------------------------------------------

#include "NERP_CORE/NERP_BASE.inc"
#include "NERP_CORE/NERP_PLAYERCONNECTION.inc"

//------------------------------------------------------------------------------

#include "NERP_TIMERS.inc"

//------------------------------------------------------------------------------

#include "NERP_MODULES/NERP_MAPA.inc"

#include "NERP_LABELSANDPICKUPS.inc"

#include "NERP_EVENTS/NERP_WINTEROBJ.inc"

//------------------------------------------------------------------------------

#include "NERP_MODULES/NERP_TDS.inc"


//------------------------------------------------------------------------------

#include "NERP_CORE/NERP_KLAD.inc"


//------------------------------------------------------------------------------

#include "NERP_SECURITY.inc"

/////////////////////////////////////

#include "NERP_INDEX.inc"

//------------------------------------------------------------------------------

#include "NERP_MODULES/NERP_DATA.inc"

/////////////////////////////////////

#include "NERP_CORE/NERP_PLAYERUPDATE.inc"

//------------------------------------------------------------------------------

#include "NERP_CORE/NERP_DIALOGS.inc"

/////////////////////////////////////

#include "NERP_CORE/NERP_PLAYERKEYS.inc"

/////////////////////////////////////

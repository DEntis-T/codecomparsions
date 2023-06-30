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


#define ZOMBIE_EVENT_SERVER 3640
#define MAX_ZOMBIES 100

#define ACTION_ZOMBIE_ATTACK 0
#define ACTION_ZOMBIE_CHASING 1
#define ACTION_ZOMBIE_CHANGEPOS 2
#define ACTION_ZOMBIE_INJURED 3

new Float:RandomZombieEvent[ 10 ][ 3 ] = {
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

new RandomZombieSkin[] = {
	78,79,132,134,135,136,137,159,160,
	162,168,196,200,209,212,213,218,230,
	239,264
};

new ZombiePosIndex,
	ZombieSkinIndex;

/////////////////////////

enum zombie_data 
{
	bool:Valid,
	Float:zombiePos[3],
	Float:zombieAngle,
	Health,
	FollowingPlayer,
	LastShotid,
	NewAction
}
new zombieInfo[ MAX_ZOMBIES ][ zombie_data ];
new zombieActor[MAX_ZOMBIES];

new ZombieAttackTimer[MAX_PLAYERS];

////////////////////

enum zombieevent_data
{
	Players,
	Zombies
}
new ZombieEvent[zombieevent_data];

stock Float:EstimateFacingAngle(Float:x, Float:y, Float:pX, Float:pY)
{
    new Float:angle;

    if( y > pY ) angle = (-acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);
    else if( y < pY && x < pX ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 450.0);
    else if( y < pY ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);

    if(x > pX) angle = (floatabs(floatabs(angle) + 180.0));
    else angle = (floatabs(angle) - 180.0);

    return angle;
}

zombieGame(); public zombieGame()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(NaZombieEventu[i])
		{
			new players[10];

			format(players, sizeof players, "%i", ZombieEvent[Zombies]);
			PlayerTextDrawSetString(i, ZombieEventTextdraw[7][i], players);

			format(players, sizeof players, "%i", ZombieEvent[Players]);
			PlayerTextDrawSetString(i, ZombieEventTextdraw[8][i], players);

			for(new x; x < 10; x++)
			{
				PlayerTextDrawShow(i, ZombieEventTextdraw[x][i]);
			}
		}
		if(!NaZombieEventu[i])
		{
			for(new x; x < 10; x++)
			{
				PlayerTextDrawHide(i, ZombieEventTextdraw[x][i]);
			}
		}
	}
	return 1;
}

zombieSpawn(); public zombieSpawn()
{
	if(ZombieEvent[Zombies] > ZombieEvent[Players])
	{
		return 1;
	}
	if(ZombieEvent[Players] == 0)
	{
		for(new i; i < MAX_ZOMBIES; i++)
		{
			if(IsValidActor(zombieActor[i]))
			{
				DestroyActor(zombieActor[i]);
			}
			ZombieEvent[Zombies] = 0;
			zombieInfo[i][Valid] = false;
		}
	}
	if(ZombieEvent[Players] != 0)
	{
		for(new i; i < MAX_ZOMBIES; i++)
		{
			ZombiePosIndex = random( sizeof( RandomZombieEvent ) );
			ZombieSkinIndex = random(sizeof RandomZombieSkin);

			if(!zombieInfo[i][Valid])
			{
				ZombieEvent[Zombies]++;

				zombieActor[i] = CreateActor(RandomZombieSkin[ZombieSkinIndex], 
					RandomZombieEvent[ ZombiePosIndex ][ 0 ]+1.0,
					RandomZombieEvent[ ZombiePosIndex ][ 1 ]+0.5,
					RandomZombieEvent[ ZombiePosIndex ][ 2 ],
					0.0 );

				SetActorVirtualWorld(zombieActor[i], ZOMBIE_EVENT_SERVER);
				SetActorInvulnerable(zombieActor[i], false);

				zombieInfo[i][zombiePos][0] = RandomZombieEvent[ ZombiePosIndex ][ 0 ]+1.0;
				zombieInfo[i][zombiePos][1] = RandomZombieEvent[ ZombiePosIndex ][ 1 ]+0.5;
				zombieInfo[i][zombiePos][2] = RandomZombieEvent[ ZombiePosIndex ][ 2 ];

				zombieInfo[i][Valid] = true;
				zombieInfo[i][Health] = 100;

				for(new player; player < MAX_PLAYERS; player++)
				{
					if(NaZombieEventu[player])
					{
						if(IsPlayerInRangeOfPoint(player, 25.0,
						RandomZombieEvent[ ZombiePosIndex ][ 0 ]+1.0,
						RandomZombieEvent[ ZombiePosIndex ][ 1 ]+0.5,
						RandomZombieEvent[ ZombiePosIndex ][ 2 ]))
						{
							ClearActorAnimations(zombieActor[i]);
							SetActorFacingPlayer(zombieActor[i], player);
							zombieInfo[i][FollowingPlayer] = player;
							ApplyActorAnimation(zombieActor[i],"ped","WALK_drunk",4.1, true, 1, 1, 0, 0);
							zombieInfo[i][NewAction] = ACTION_ZOMBIE_CHASING;
						}
					}	
				}
			}
		}
		return 1;
	}
	return 1;
}

zombieUpdate(); public zombieUpdate()
{
	if(ZombieEvent[Players] != 0)
	{
		for(new i; i < MAX_ZOMBIES; i++)
		{
			if(zombieInfo[i][Valid])
			{
				if(zombieInfo[i][NewAction] == ACTION_ZOMBIE_INJURED) return 1;
				if(zombieInfo[i][Health] == 0)
				{
					ClearActorAnimations(zombieActor[i]);
					ApplyActorAnimation(zombieActor[i], "SWEET", "Sweet_injuredloop", 4.1, true, 1, 1, 0, 0);
					SetTimerEx("KillZombie", 3000, false, "i", i);
					zombieInfo[i][NewAction] = ACTION_ZOMBIE_INJURED;
					PlayerInfo[zombieInfo[i][LastShotid]][xZombieEventKills]++;
					return 1;
				}

				for(new player; player < MAX_PLAYERS; player++)
				{
					if(NaZombieEventu[player])
					{
						new Float:angle;
						GetActorFacingAngle(zombieActor[i], angle);
						if(zombieInfo[i][zombieAngle] != angle)
						{
							if(IsPlayerInRangeOfPoint(player, 50.0, //ganja ga zombi
							zombieInfo[ i ][zombiePos][ 0 ],
							zombieInfo[ i ][zombiePos][ 1 ],
							zombieInfo[ i ][zombiePos][ 2 ]))
							{
								zombieInfo[i][FollowingPlayer] = player;
								if(zombieInfo[i][NewAction] != ACTION_ZOMBIE_CHASING && 
									zombieInfo[i][NewAction] != ACTION_ZOMBIE_CHANGEPOS)
								{
									ClearActorAnimations(zombieActor[i]);
									SetActorFacingPlayer(zombieActor[i], player);
									ApplyActorAnimation(zombieActor[i],"ped","WALK_drunk",4.1, true, 1, 1, 0, 0);
									zombieInfo[i][NewAction] = ACTION_ZOMBIE_CHASING;
									zombieInfo[i][zombieAngle] = angle;
								}
							}

							if(IsPlayerInRangeOfPoint(player, 2.0, //ubija ga zombi
							zombieInfo[ i ][zombiePos][ 0 ],
							zombieInfo[ i ][zombiePos][ 1 ],
							zombieInfo[ i ][zombiePos][ 2 ]))
							{
								zombieInfo[i][FollowingPlayer] = player;
								if(zombieInfo[i][NewAction] != ACTION_ZOMBIE_ATTACK && 
									zombieInfo[i][NewAction] != ACTION_ZOMBIE_CHANGEPOS)
								{
									ClearActorAnimations(zombieActor[i]);
									SetActorFacingPlayer(zombieActor[i], player);
									ApplyActorAnimation(zombieActor[i],"Flowers","Flower_attack",4.1, true, 1, 1, 0, 0);
									zombieInfo[i][NewAction] = ACTION_ZOMBIE_ATTACK;
									zombieInfo[i][zombieAngle] = angle;

								}
							}
						}
					}	
				}
			}
		}
		return 1;
	}
	return 1;
}

UpdateZombiePos(); public UpdateZombiePos()
{
	if(ZombieEvent[Players] != 0)
	{
		new Float:NewZombiePos[3];
		for(new i; i < MAX_ZOMBIES; i++)
		{
			if(zombieInfo[i][Valid])
			{
				if(zombieInfo[i][NewAction] != ACTION_ZOMBIE_INJURED) return 1;
				for(new player; player < MAX_PLAYERS; player++)
				{
					if(NaZombieEventu[player])
					{
						GetPlayerPos(player,
							NewZombiePos[0],
							NewZombiePos[1],
							NewZombiePos[2]);

						zombieInfo[ i ][zombiePos][ 0 ] = NewZombiePos[0]-random(4);
						zombieInfo[ i ][zombiePos][ 1 ] = NewZombiePos[1]+random(4);
						zombieInfo[ i ][zombiePos][ 2 ] = NewZombiePos[2];
						
						SetActorPos(zombieActor[i],
							zombieInfo[ i ][zombiePos][ 0 ],
							zombieInfo[ i ][zombiePos][ 1 ],
							zombieInfo[ i ][zombiePos][ 2 ]);

						zombieInfo[i][NewAction] = ACTION_ZOMBIE_CHANGEPOS;

						ApplyActorAnimation(zombieActor[i], "ped", "getup", 4.1, true, 1, 1, 0, 0);
						SetTimerEx("resetZombieAction", 1200, false, "i", i);
					}	
				}
			}
		}
		return 1;
	}
	return 1;
}

GetNearestZombie( playerid )
{
    for( new i = 1; i < MAX_STREETS; i++ )
	{
        if( IsPlayerInRangeOfPoint( playerid, 2.0, 
        	zombieInfo[ i ][zombiePos][ 0 ],
			zombieInfo[ i ][zombiePos][ 1 ],
			zombieInfo[ i ][zombiePos][ 2 ] ) ) return i;
	}
    return -1;
}

/////////////reset action///////////
resetZombieAction(i); public resetZombieAction(i)
{
	zombieInfo[i][NewAction] = ACTION_ZOMBIE_CHASING;
	return 1;
}

///////KILL ZOMBIE/////////
KillZombie(i); public KillZombie(i)
{
	zombieInfo[i][NewAction] = ACTION_ZOMBIE_CHASING;
	zombieInfo[i][Valid] = false;
	ZombieEvent[Zombies]--;
	if(IsValidActor(zombieActor[i]))
	{
		ClearActorAnimations(zombieActor[i]);
		DestroyActor(zombieActor[i]);
	}
	return 1;
}


ZombieAttackPlayer(playerid); public ZombieAttackPlayer(playerid)
{
	if(GetNearestZombie(playerid) != -1) DodajIgracuHP(playerid, -10);
	return 1;
}

//publics
public OnPlayerGiveDamageActor(playerid, damaged_actorid, Float: amount, weaponid, bodypart)
{
    if(NaZombieEventu[playerid])
    {
    	for(new i; i < MAX_ZOMBIES; i++)
    	{
    		if(damaged_actorid == zombieActor[i])
    		{
    			if(zombieInfo[i][Health] > 0)
    			{
	    			SetActorHealth(zombieActor[i], 100.0);
	    			zombieInfo[i][Health] -= 20;
	    			zombieInfo[i][LastShotid] = playerid;
	    			SendInfoMessage(playerid, "Oduzeo si zombiju 20 HP-a, preostalo %i HP.", zombieInfo[i][Health]);
	    		}
    		}
    	}
    }
    return 1;
}

////////////KOMANDE//////////////////

CMD:udjinazombie( playerid, params[] )
{
	if( PlayerInfo[ playerid ][ xLevel ] < 3 ) return GRESKA( playerid, "Ne mozes ako nisi level 3+." );
	//if( !IsPlayerInRangeOfPoint( playerid, 3.0, 1382.1486, -1088.6586, 28.2120 ) ) return GRESKA( playerid, "Morate biti kod ulaza zgrade za DM(Pitajte Admin/GM gdje je)." );
	if( PlayerInfo[ playerid ][ xWanted ] > 0 ) return GRESKA( playerid, "Ne mozes na zombie event sa WLom." );
	if( PoliceDuty[ playerid ] ) return GRESKA( playerid, "Ne mozes sa PD duty na zombie event." );
	if(NaDmEventu[ playerid ]) return greska(pid,"Na deathmatch eventu si!");
	if(PlayerInfo[pid][xPUBG] == 1) return greska(pid,"Ti si na PUBG eventu - moras odigrati match!");
	if(NaZombieEventu[ playerid ]) return greska(pid, "Vec si na Zombie Eventu.");
	NaZombieEventu[ playerid ] = true;
    new rand = random( sizeof( RandomZombieEvent ) );
	Dimi_SetPlayerPos( playerid, 
		RandomZombieEvent[ rand ][ 0 ],
		RandomZombieEvent[ rand ][ 1 ],
		RandomZombieEvent[ rand ][ 2 ] );
	SetPlayerFacingAngle( playerid, 360.000 );
	SetCameraBehindPlayer( playerid );
	SetPlayerInterior( playerid, 0 );
	Dimi_SetPlayerHealth( playerid, 100 );
	Dimi_SetPlayerArmour( playerid, 100 );

	GivePlayerZombieEventWeap(playerid);
	SetPlayerVirtualWorld(playerid, ZOMBIE_EVENT_SERVER);
	
	SendInfoMessage( playerid, "Da izadjes iz Zombie Event zone kucaj /izadjisazombie." );
	ZombieEvent[Players]++;

	ZombieAttackTimer[playerid] = SetTimerEx("ZombieAttackPlayer", 2000, true, "i", playerid);
    return 1;
}

stock ZombieEvent_OnPlayerDeath(playerid)
{
	NaZombieEventu[ playerid ] = false;
   	DodajIgracuHP(playerid, -1000);
	ZombieEvent[Players]--;
	KillTimer(ZombieAttackTimer[playerid]);
	NaZombieEventu[ playerid ] = true;
    new rand = random( sizeof( RandomZombieEvent ) );
	Dimi_SetPlayerPos( playerid, 
		RandomZombieEvent[ rand ][ 0 ],
		RandomZombieEvent[ rand ][ 1 ],
		RandomZombieEvent[ rand ][ 2 ] );
	SetPlayerFacingAngle( playerid, 360.000 );
	SetCameraBehindPlayer( playerid );
	SetPlayerInterior( playerid, 0 );
	Dimi_SetPlayerHealth( playerid, 100 );
	Dimi_SetPlayerArmour( playerid, 100 );

	GivePlayerZombieEventWeap(playerid);
	SetPlayerVirtualWorld(playerid, ZOMBIE_EVENT_SERVER);
	
	SendInfoMessage( playerid, "Da izadjes iz Zombie Event zone kucaj /izadjisazombie." );
	ZombieEvent[Players]++;

	hideinjuredtd(pid);
	hidehb(pid);
	Ranjen[pid] = 0;

	ZombieAttackTimer[playerid] = SetTimerEx("ZombieAttackPlayer", 2000, true, "i", playerid);
	return 1;
}

stock ZombieEvent_CloseConnection(playerid)
{
	if(!NaZombieEventu[ playerid ]) return 1;
	NaZombieEventu[ playerid ] = false;
	ZombieEvent[Players]--;
	KillTimer(ZombieAttackTimer[playerid]);
	return 1;
}

CMD:izadjisazombie( playerid, params[] )
{
	if(!NaZombieEventu[ playerid ]) return greska(pid, "Vi niste na Zombie Eventu.");
	NaZombieEventu[ playerid ] = false;
	ZombieEvent[Players]--;
	KillTimer(ZombieAttackTimer[playerid]);
    return 1;
}

stock GivePlayerZombieEventWeap(playerid)
{
	if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 4500 )
	{
	    SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 10." );
	    GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 26, 150 );
		GiveWeaponToPlayer( playerid, 28, 400 );
		GiveWeaponToPlayer( playerid, 31, 400 );
		SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
		SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 4000 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 9." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 27, 150 );
		GiveWeaponToPlayer( playerid, 32, 800 );
		GiveWeaponToPlayer( playerid, 31, 400 );
		SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 3500 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 8." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 27, 150 );
		GiveWeaponToPlayer( playerid, 28, 800 );
		GiveWeaponToPlayer( playerid, 31, 400 );
		SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 3000 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 7." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 27, 150 );
		GiveWeaponToPlayer( playerid, 29, 400 );
		GiveWeaponToPlayer( playerid, 31, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 2500 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 6." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 26, 150 );
		GiveWeaponToPlayer( playerid, 29, 400 );
		GiveWeaponToPlayer( playerid, 31, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 2000 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 5." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 26, 150 );
		GiveWeaponToPlayer( playerid, 29, 400 );
		GiveWeaponToPlayer( playerid, 30, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 1500 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 4." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 25, 100 );
		GiveWeaponToPlayer( playerid, 29, 400 );
		GiveWeaponToPlayer( playerid, 31, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 1000 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 3." );
		GiveWeaponToPlayer( playerid, 24, 150 );
		GiveWeaponToPlayer( playerid, 25, 100 );
		GiveWeaponToPlayer( playerid, 29, 400 );
		GiveWeaponToPlayer( playerid, 30, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 500 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 2." );
		GiveWeaponToPlayer( playerid, 24, 200 );
		GiveWeaponToPlayer( playerid, 25, 100 );
		GiveWeaponToPlayer( playerid, 29, 400 );
	}
	else if( PlayerInfo[ playerid ][ xZombieEventKills ] >= 0 )
	{
		SendInfoMessage( playerid, "Usao si na Zombie Event sa rankom 1." );
		GiveWeaponToPlayer( playerid, 24, 200 );
		GiveWeaponToPlayer( playerid, 25, 100 );
	}
	return 1;
}
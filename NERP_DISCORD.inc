/*

	NERP DISCORD

	Bot

	DEntisT

	v1.0


*/

#if INCLUDE_NERP_MODULES == 0
	#endinput
#endif

#if defined _discordcmd_included
	#endinput
#endif
#define _discordcmd_included


#if defined dcconnector_included
	#endinput
#endif
#define dcconnector_included



enum DCC_ChannelType
{
	GUILD_TEXT = 0,
	DM = 1,
	GUILD_VOICE = 2,
	GROUP_DM = 3,
	GUILD_CATEGORY = 4
};

enum DCC_UserPresenceStatus
{
	INVALID = 0,
	ONLINE = 1,
	IDLE = 2,
	DO_NOT_DISTURB = 3,
	OFFLINE = 4
};

enum DCC_BotPresenceStatus
{
	INVALID = 0,
	ONLINE,
	IDLE,
	DO_NOT_DISTURB,
	INVISIBLE,
	OFFLINE
};

enum DCC_MessageReactionType
{
	REACTION_ADD = 0, // Sent when a user adds a reaction to a message.
	REACTION_REMOVE, // Sent when a user removes a reaction from a message.
	REACTION_REMOVE_ALL, // Sent when a user explicitly removes all reactions from a message.
	REACTION_REMOVE_EMOJI // Sent when a bot removes all instances of a given emoji from the reactions of a message.
};

#define DCC_INVALID_CHANNEL DCC_Channel:0
#define DCC_INVALID_USER DCC_User:0
#define DCC_INVALID_ROLE DCC_Role:0
#define DCC_INVALID_GUILD DCC_Guild:0

#define DCC_ID_SIZE (20 + 1)
#define DCC_USERNAME_SIZE (32 + 1)
#define DCC_NICKNAME_SIZE (32 + 1)
#define DCC_EMOJI_NAME_SIZE (32 + 1)
// natives
//  channels
native DCC_Channel:DCC_FindChannelByName(const channel_name[]);
native DCC_Channel:DCC_FindChannelById(const channel_id[]);

native DCC_GetChannelId(DCC_Channel:channel, dest[DCC_ID_SIZE], max_size = sizeof dest);
native DCC_GetChannelType(DCC_Channel:channel, &DCC_ChannelType:type);
native DCC_GetChannelGuild(DCC_Channel:channel, &DCC_Guild:guild);
native DCC_GetChannelName(DCC_Channel:channel, dest[], max_size = sizeof dest);
native DCC_GetChannelTopic(DCC_Channel:channel, dest[], max_size = sizeof dest);
native DCC_GetChannelPosition(DCC_Channel:channel, &position);
native DCC_IsChannelNsfw(DCC_Channel:channel, &bool:is_nsfw);
native DCC_GetChannelParentCategory(DCC_Channel:channel, &DCC_Channel:category);

native DCC_SendChannelMessage(DCC_Channel:channel, const message[], const callback[] = "", const format[] = "", {Float, _}:...);
native DCC_SetChannelName(DCC_Channel:channel, const name[]);
native DCC_SetChannelTopic(DCC_Channel:channel, const topic[]);
native DCC_SetChannelPosition(DCC_Channel:channel, position);
native DCC_SetChannelNsfw(DCC_Channel:channel, bool:is_nsfw);
native DCC_SetChannelParentCategory(DCC_Channel:channel, DCC_Channel:parent_category);
native DCC_DeleteChannel(DCC_Channel:channel);


// messages
native DCC_GetMessageId(DCC_Message:message, dest[DCC_ID_SIZE], max_size = DCC_ID_SIZE);
native DCC_GetMessageChannel(DCC_Message:message, &DCC_Channel:channel);
native DCC_GetMessageAuthor(DCC_Message:message, &DCC_User:author);
native DCC_GetMessageContent(DCC_Message:message, dest[], max_size = sizeof dest);
native DCC_IsMessageTts(DCC_Message:message, &bool:is_tts);
native DCC_IsMessageMentioningEveryone(DCC_Message:message, &bool:mentions_everyone);
native DCC_GetMessageUserMentionCount(DCC_Message:message, &mentioned_user_count);
native DCC_GetMessageUserMention(DCC_Message:message, offset, &DCC_User:mentioned_user);
native DCC_GetMessageRoleMentionCount(DCC_Message:message, &mentioned_role_count);
native DCC_GetMessageRoleMention(DCC_Message:message, offset, &DCC_Role:mentioned_role);

native DCC_DeleteMessage(DCC_Message:message);

native DCC_Message:DCC_GetCreatedMessage(); // for use in DCC_SendChannelMessage result callback

native DCC_DeleteInternalMessage(DCC_Message:message); // This deletes a stored message, this DOES NOT delete it on discord, this is for persistent messages.

native DCC_EditMessage(DCC_Message:message, const content[], DCC_Embed:embed = DCC_Embed:0);

native DCC_SetMessagePersistent(DCC_Message:message, bool:persistent);
native DCC_CacheChannelMessage(const channel_id[DCC_ID_SIZE], const message_id[DCC_ID_SIZE], const callback[] = "", const format[] = "", {Float, _}:...);
//  users
native DCC_User:DCC_FindUserByName(const user_name[], const user_discriminator[]);
native DCC_User:DCC_FindUserById(const user_id[]);

native DCC_GetUserName(DCC_User:user, dest[DCC_USERNAME_SIZE], max_size = sizeof dest);
native DCC_GetUserId(DCC_User:user, dest[DCC_ID_SIZE], max_size = DCC_ID_SIZE);
native DCC_GetUserDiscriminator(DCC_User:user, dest[], max_size = sizeof dest);
native DCC_IsUserBot(DCC_User:user, &bool:is_bot);
native DCC_IsUserVerified(DCC_User:user, &bool:is_verified);


//  roles
native DCC_Role:DCC_FindRoleByName(DCC_Guild:guild, const role_name[]);
native DCC_Role:DCC_FindRoleById(const role_id[]);

native DCC_GetRoleId(DCC_Role:role, dest[DCC_ID_SIZE], max_size = sizeof dest);
native DCC_GetRoleName(DCC_Role:role, dest[], max_size = sizeof dest);
native DCC_GetRoleColor(DCC_Role:role, &color);
native DCC_GetRoleColour(DCC_Role:role, &colour) = DCC_GetRoleColor; // for our British mates
native DCC_GetRolePermissions(DCC_Role:role, &perm_high, &perm_low); // 64 bit integer
native DCC_IsRoleHoist(DCC_Role:role, &bool:is_hoist);
native DCC_GetRolePosition(DCC_Role:role, &position);
native DCC_IsRoleMentionable(DCC_Role:role, &bool:is_mentionable);


//  guilds
native DCC_Guild:DCC_FindGuildByName(const guild_name[]);
native DCC_Guild:DCC_FindGuildById(const guild_id[]);

native DCC_GetGuildId(DCC_Guild:guild, dest[DCC_ID_SIZE], max_size = sizeof dest);
native DCC_GetGuildName(DCC_Guild:guild, dest[], max_size = sizeof dest);
native DCC_GetGuildOwnerId(DCC_Guild:guild, dest[DCC_ID_SIZE], max_size = sizeof dest);
native DCC_GetGuildRole(DCC_Guild:guild, offset, &DCC_Role:role);
native DCC_GetGuildRoleCount(DCC_Guild:guild, &count);
native DCC_GetGuildMember(DCC_Guild:guild, offset, &DCC_User:user);
native DCC_GetGuildMemberCount(DCC_Guild:guild, &count);
native DCC_GetGuildMemberVoiceChannel(DCC_Guild:guild, DCC_User:user, &DCC_Channel:channel);
native DCC_GetGuildMemberNickname(DCC_Guild:guild, DCC_User:user, dest[DCC_NICKNAME_SIZE], max_size = sizeof dest);
native DCC_GetGuildMemberRole(DCC_Guild:guild, DCC_User:user, offset, &DCC_Role:role);
native DCC_GetGuildMemberRoleCount(DCC_Guild:guild, DCC_User:user, &count);
native DCC_HasGuildMemberRole(DCC_Guild:guild, DCC_User:user, DCC_Role:role, &bool:has_role);
native DCC_GetGuildMemberStatus(DCC_Guild:guild, DCC_User:user, &DCC_UserPresenceStatus:status);
native DCC_GetGuildChannel(DCC_Guild:guild, offset, &DCC_Channel:channel);
native DCC_GetGuildChannelCount(DCC_Guild:guild, &count);
native DCC_GetAllGuilds(DCC_Guild:dest[], max_size = sizeof dest);

native DCC_SetGuildName(DCC_Guild:guild, const name[]);
native DCC_CreateGuildChannel(DCC_Guild:guild, const name[], DCC_ChannelType:type, const callback[] = "", const format[] = "", {Float, _}:...);
native DCC_Channel:DCC_GetCreatedGuildChannel();
native DCC_SetGuildMemberNickname(DCC_Guild:guild, DCC_User:user, const nickname[]);
native DCC_SetGuildMemberVoiceChannel(DCC_Guild:guild, DCC_User:user, DCC_Channel:channel);
native DCC_AddGuildMemberRole(DCC_Guild:guild, DCC_User:user, DCC_Role:role);
native DCC_RemoveGuildMemberRole(DCC_Guild:guild, DCC_User:user, DCC_Role:role);
native DCC_RemoveGuildMember(DCC_Guild:guild, DCC_User:user); // kicks the user from the server
native DCC_CreateGuildMemberBan(DCC_Guild:guild, DCC_User:user, const reason[] = "");
native DCC_RemoveGuildMemberBan(DCC_Guild:guild, DCC_User:user);
native DCC_SetGuildRolePosition(DCC_Guild:guild, DCC_Role:role, position);
native DCC_SetGuildRoleName(DCC_Guild:guild, DCC_Role:role, const name[]);
native DCC_SetGuildRolePermissions(DCC_Guild:guild, DCC_Role:role, perm_high, perm_low);
native DCC_SetGuildRoleColor(DCC_Guild:guild, DCC_Role:role, color);
native DCC_SetGuildRoleHoist(DCC_Guild:guild, DCC_Role:role, bool:hoist);
native DCC_SetGuildRoleMentionable(DCC_Guild:guild, DCC_Role:role, bool:mentionable);
native DCC_CreateGuildRole(DCC_Guild:guild, const name[], const callback[] = "", const format[] = "", {Float, _}:...);
native DCC_Role:DCC_GetCreatedGuildRole();
native DCC_DeleteGuildRole(DCC_Guild:guild, DCC_Role:role);

// bot
native DCC_BotPresenceStatus:DCC_GetBotPresenceStatus();

native DCC_TriggerBotTypingIndicator(DCC_Channel:channel);
native DCC_SetBotNickname(DCC_Guild:guild, const nickname[]);
stock DCC_ClearBotNickname(DCC_Guild:guild)
{
	return DCC_SetBotNickname(guild, "");
}
native DCC_CreatePrivateChannel(DCC_User:user, const callback[], const format[] = "", {Float, _}:...);
native DCC_Channel:DCC_GetCreatedPrivateChannel();
native DCC_SetBotPresenceStatus(DCC_BotPresenceStatus:status);
native DCC_SetBotActivity(const name[]);
stock DCC_ClearBotActivity()
{
	return DCC_SetBotActivity("");
}


// misc
native DCC_EscapeMarkdown(const src[], dest[], max_size = sizeof dest);

// embedded messages
native DCC_Embed:DCC_CreateEmbed(const title[] = "", const description[] = "", const url[] = "", const timestamp[] = "", color = 0, const footer_text[] = "", const footer_icon_url[] = "", const thumbnail_url[] = "", const image_url[] = "");
native DCC_DeleteEmbed(DCC_Embed:embed);
native DCC_SendChannelEmbedMessage(DCC_Channel:channel, DCC_Embed:embed, const message[] = "", const callback[] = "", const format[] = "", {Float, _}:...);
native DCC_AddEmbedField(DCC_Embed:embed, const name[], const value[], bool:inline = false);
native DCC_SetEmbedTitle(DCC_Embed:embed, const title[]);
native DCC_SetEmbedDescription(DCC_Embed:embed, const description[]);
native DCC_SetEmbedUrl(DCC_Embed:embed, const url[]);
native DCC_SetEmbedTimestamp(DCC_Embed:embed, const timestamp[]);
native DCC_SetEmbedColor(DCC_Embed:embed, color);
native DCC_SetEmbedColour(DCC_Embed:embed, colour) = DCC_SetEmbedColor; // oi m8
native DCC_SetEmbedFooter(DCC_Embed:embed, const footer_text[], const footer_icon_url[] = "");
native DCC_SetEmbedThumbnail(DCC_Embed:embed, const thumbnail_url[]);
native DCC_SetEmbedImage(DCC_Embed:embed, const image_url[]);

// emoji
native DCC_Emoji:DCC_CreateEmoji(const name[DCC_EMOJI_NAME_SIZE], const snowflake[DCC_ID_SIZE] = "");
native DCC_DeleteEmoji(DCC_Emoji:emoji);
native DCC_GetEmojiName(DCC_Emoji:emoji, dest[DCC_EMOJI_NAME_SIZE], maxlen = DCC_EMOJI_NAME_SIZE);

// reaction
native DCC_CreateReaction(DCC_Message:message, DCC_Emoji:reaction_emoji);
native DCC_DeleteMessageReaction(DCC_Message:message, DCC_Emoji:reaction_emoji = DCC_Emoji:0); // if reaction_emoji is 0 (default value) this will delete ALL of the reactions on the message.

// callbacks
//  channels
forward DCC_OnChannelCreate(DCC_Channel:channel);
forward DCC_OnChannelUpdate(DCC_Channel:channel);
forward DCC_OnChannelDelete(DCC_Channel:channel);

// messages
forward DCC_OnMessageCreate(DCC_Message:message);
forward DCC_OnMessageDelete(DCC_Message:message);
forward DCC_OnMessageReaction(DCC_Message:message, DCC_User:reaction_user, DCC_Emoji:emoji, DCC_MessageReactionType:reaction_type);

//  users
forward DCC_OnUserUpdate(DCC_User:user);

//  guilds
forward DCC_OnGuildCreate(DCC_Guild:guild);
forward DCC_OnGuildUpdate(DCC_Guild:guild);
forward DCC_OnGuildDelete(DCC_Guild:guild);

forward DCC_OnGuildMemberAdd(DCC_Guild:guild, DCC_User:user);
forward DCC_OnGuildMemberUpdate(DCC_Guild:guild, DCC_User:user);
forward DCC_OnGuildMemberVoiceUpdate(DCC_Guild:guild, DCC_User:user, DCC_Channel:channel);
forward DCC_OnGuildMemberRemove(DCC_Guild:guild, DCC_User:user);

forward DCC_OnGuildRoleCreate(DCC_Guild:guild, DCC_Role:role);
forward DCC_OnGuildRoleUpdate(DCC_Guild:guild, DCC_Role:role);
forward DCC_OnGuildRoleDelete(DCC_Guild:guild, DCC_Role:role);

#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

// Config

#define MAX_CMD_LEN			32
#define MAX_CMD_NAME		20

// Prefix

#if	!defined CMD_PREFIX
	#define	CMD_PREFIX		'-'
#endif

// Macros

#define DISCORD:%1(%2)		\
	forward discord_%1(%2);	\
	public discord_%1(%2)

#define DC:%1(%2) 			\
	DISCORD:%1(%2)

#define discord%0command:%1(%2) 			\
	DISCORD:%1(%2)
// Command result

#define DISCORD_SUCCESS		(1)
#define DISCORD_FAILURE		(0)

// Code
public DCC_OnMessageCreate(DCC_Message: message) {

	new
		DCC_User: author,
		bool: is_bot = false,
		content[256 + MAX_CMD_NAME + 2],
		command[MAX_CMD_NAME],
		params[256],
		discord[MAX_CMD_LEN] = "discord_"
	;

	if (!DCC_GetMessageAuthor(message, author) || author == DCC_INVALID_USER) { // The message author is invalid
		#if defined discdcmd_DCC_OnMessageCreate
			return discdcmd_DCC_OnMessageCreate(DCC_Message: message);
		#else
			return 0;
		#endif
	}

	DCC_IsUserBot(author, is_bot);
	DCC_GetMessageContent(message, content);

	if (is_bot || content[0] != CMD_PREFIX) { // Skip if the message author is a bot or is not a command
		#if defined discdcmd_DCC_OnMessageCreate
			return discdcmd_DCC_OnMessageCreate(DCC_Message: message);
		#else
			return 0;
		#endif
	}

	if (sscanf(content, "s["#MAX_CMD_NAME"]S()[256]", command, params)) {
		#if defined discdcmd_DCC_OnMessageCreate
			return discdcmd_DCC_OnMessageCreate(DCC_Message: message);
		#else
			return 0;
		#endif
	}

	for (new i = strlen(command) - 1; i != 0; i --) {
		command[i] |= 0x20; // lower case using bitwise OR operator
	}

	strcat(discord, command[1]);

	if (isnull(params)) {
		params = "\1";
	}

	#if defined OnDiscordCommandPerformed
		OnDiscordCommandPerformed(message, author, bool: CallLocalFunction(discord, "iis", _: message, _: author, params));
	#else
		CallLocalFunction(discord, "iis", _: message, _: author, params);
	#endif
	
	#if defined discdcmd_DCC_OnMessageCreate
		return discdcmd_DCC_OnMessageCreate(DCC_Message: message);
	#else
		return 1;
	#endif
}

// Hooking and functions

#if defined _ALS_DCC_OnMessageCreate
	#undef DCC_OnMessageCreate
#else
	#define _ALS_DCC_OnMessageCreate
#endif

#define DCC_OnMessageCreate discdcmd_DCC_OnMessageCreate
#if defined discdcmd_DCC_OnMessageCreate
	forward discdcmd_DCC_OnMessageCreate(DCC_Message: message);
#endif

#if defined OnDiscordCommandPerformed
	forward OnDiscordCommandPerformed(DCC_Message: message, DCC_User: author, bool: success);
#endif	

new
	DCC_Channel: disc_kanal
;

new
	 DCC_Channel: disc_chat_kanal;


NERP_ONGMINIT();
public NERP_ONGMINIT() {
	print("Is this causing problems?");
	DCC_SetBotPresenceStatus(IDLE);
	DCC_SetBotActivity("DEntisT | Nova Era - SA:MP");
	disc_kanal = DCC_FindChannelById("942856320472727593");
	disc_chat_kanal = DCC_FindChannelById("930817271948001324");
	print("This is not a problem");
	return 1;
}
NERP_OPT( playerid, text[] );
public NERP_OPT( playerid, text[] )
{
	new textreport[300];
	format(textreport,sizeof(textreport),":warning: | Igrac **%s** *(ID: %i)* je poslao poruku u chat. Poruka glasi: *%s*",ImeIgraca(playerid),playerid,text);
	DCC_SendChannelMessage(disc_chat_kanal,textreport);
	return 1;
}

forward discordbot_cmds(playerid, cmdtext[], success);
public discordbot_cmds(playerid, cmdtext[], success)
{
	new textreport[300];
	if(success == 1)
	{
		format(textreport,sizeof(textreport),
			":white_check_mark: | CMD-OK | Igrac **%s** *(ID: %i)* je iskoristio komandu. Komanda: *%s*",
			ImeIgraca(playerid),playerid,cmdtext);
		DCC_SendChannelMessage(disc_kanal,textreport);
	}
	else if (success == 0)
	{
		format(textreport,sizeof(textreport),
			":x: | CMD-NO | Igrac **%s** *(ID: %i)* je pokusao iskoristiti nepostojecu komandu. Komanda: *%s*",
			ImeIgraca(playerid),playerid,cmdtext);
		DCC_SendChannelMessage(disc_kanal,textreport);
	}
	return 1;
}

ObavjestiIgrace(); public ObavjestiIgrace()
{
	DCC_SendChannelMessage(disc_chat_kanal,":robot: |__Nova Era - RolePlay__| :robot:");
	DCC_SendChannelMessage(disc_chat_kanal,"============================================");
	DCC_SendChannelMessage(disc_chat_kanal,":white_check_mark: | *Server uspjesno osvjezen.*");
	DCC_SendChannelMessage(disc_chat_kanal,":white_check_mark: | IP: /");
	return 1;
}

public OnDiscordCommandPerformed(DCC_Message: message,DCC_User: author, bool: success) {

	if (!success) {
		new
			DCC_Channel: channel
		;
		
		DCC_GetMessageChannel(message, channel);
		return DCC_SendChannelMessage(channel, ":x: | Komanda koju ste unijeli **ne postoji**.");
	}

	return 1;
}

#define channelcheck \
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel); \
	if (channel != disc_kanal) \
	{DCC_SendChannelMessage(channel, ":x: | **Ovo nije** kanal za ovu komandu - pokusajte u kanalu <#893436437943435275>."); \
	return 1;}

#define cmdparams \
	DCC_Message:message,DCC_User:author,params[]

DC:online(DCC_Message: message, DCC_User: author, params[])
{
	channelcheck
	return DCC_SendChannelMessage(channel, ":ok: | **Bot** je uspjesno *povezan* na serveru!");
}

DC:help(cmdparams)
{
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel);
	DCC_SendChannelMessage(channel, ":robot: | **POMOC OKO BOTA** | :robot:");
	DCC_SendChannelMessage(channel, "");
	DCC_SendChannelMessage(channel, ":white_check_mark: Prefiks bota je: **-**");
	DCC_SendChannelMessage(channel, "");
	DCC_SendChannelMessage(channel, ":white_check_mark: -online: *Provjerava da li je bot uključen.*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -links: *Prikazuje sve linkove vezane za nas server.*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -say: *Salje globalnu poruku na server.*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -kick: *Kicka igraca sa servera.*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -ugasi: *Ova komanda restartuje server - koristiti samo ako si owner!*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -pm: *Ovom komandom mogu i igraci i admini poslati privatnu poruku odavde sa discorda.*");
	DCC_SendChannelMessage(channel, ":white_check_mark: -kladionica: *Komande za kladionicu na discordu - mini igra*");
	return 1;
}

DC:links(cmdparams)
{
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel);
	DCC_SendChannelMessage(channel, ":ok: | Posjetite nas **portal & forum** na *https://novaerarp.wixsite.com/portal*.");
	return 1; 
}

DC:pm(cmdparams)
{
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel);
	new id, nick[64], reason[200];
	if(sscanf(params,"is[64]s[200]",id,nick,reason)) 
		return DCC_SendChannelMessage(channel, 
			":x: | **GRESKA** | Koristite komandu ovako: *-pm [ID igraca na serveru] [vas nick (jedna rijec sa donjom crtom ili bez)] [poruka]*");
	if(!IsPlayerConnected(id)) return DCC_SendChannelMessage(channel,":x: | Igrac sa **tim ID-om** nije online na serveru!");
	new poruka[300];
	format(poruka,sizeof(poruka),""col_balkanstory"[DISCORD - PM]{ffffff} Korisnik: "col_red"%s {ffffff}| Poruka: %s",nick,reason);
	SendClientMessage(id,-1,poruka);
	format(poruka,sizeof(poruka),":ok: | **Privatna poruka** uspjesno poslana korisniku: **%s** | Poruka: *%s*",ImeIgraca(id),reason);
	DCC_SendChannelMessage(channel,poruka);
	return 1; 
}

// discord gamble sistem

DC:kladionica(cmdparams)
{
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel);
	DCC_SendChannelMessage(channel, ":game_die: | **KLADIONICA HELP** | :game_die:");
	DCC_SendChannelMessage(channel, "");
	DCC_SendChannelMessage(channel, ":white_check_mark: Prefiks bota je: **-**");
	DCC_SendChannelMessage(channel, "");
	DCC_SendChannelMessage(channel, ":white_check_mark: -ulozi: *Ulazete kolicinu novca na igru na srecu!*");
	return 1; 
}

DC:ulozi(DCC_Message: message, DCC_User: author, params[])
{
	new DCC_Channel: channel; DCC_GetMessageChannel(message, channel);
	new string[100];
	format(string,100,":x: TEST_ID_EQU:%i | data_error(id:7643): unable to download message content.");
	DCC_SendChannelMessage(channel,string);
	return 1;
}

NERP_OPC(playerid);
public NERP_OPC(playerid)
{
	new string[300];
	format(string, sizeof(string),":airplane_arriving: | Igrac **%s (ID: %i)** se uspjesno povezao na serveru!",ImeIgraca(playerid),playerid);
	DCC_SendChannelMessage(disc_kanal,string);
	return 1;
}

NERP_OPD(playerid, reason);
public NERP_OPD(playerid, reason)
{
	new string[300];
	format(string, sizeof(string),":airplane_departure: | Igrac **%s (ID: %i)** je izasao sa servera!",ImeIgraca(playerid),playerid);
	DCC_SendChannelMessage(disc_kanal,string);
	return 1;
}

DC:say(cmdparams)
{
	channelcheck
	new adminname[100], poruka[200];
	if(sscanf(params,"s[100]s[200]",adminname,poruka)) 
		return DCC_SendChannelMessage(disc_kanal, 
			":x: | **GRESKA** | Koristite komandu ovako: *-say [tvoj nickname (jedna rijec sa donjom crtom ili bez)] [poruka]*");
	DCC_SendChannelMessage(disc_kanal,":ok: | **Poruka** uspjesno poslana na serveru!");
	new clientmessage[300];
	format(clientmessage,sizeof(clientmessage),
		""col_balkanstory"[DISCORD GLOBAL PORUKA]{ffffff} Korisnik: "col_red"%s {ffffff}| Poruka: %s",adminname,poruka);
	SendClientMessageToAll(-1,clientmessage);
	return 1;
}

DC:kick(cmdparams)
{
	channelcheck
	new id, reason[100];
	if(sscanf(params,"is[200]",id,reason)) 
		return DCC_SendChannelMessage(disc_kanal, 
			":x: | **GRESKA** | Koristite komandu ovako: *-kick [ID igraca na serveru] [razlog]*");
	if(!IsPlayerConnected(id)) return DCC_SendChannelMessage(disc_kanal,":x: | Igrac sa **tim ID-om** nije online na serveru!");
	new disc_kick_msg[300];
	format(disc_kick_msg,sizeof(disc_kick_msg),":white_check_mark: | Uspjesno ste kickali **%s** sa servera! ||*Razlog: %s*||",ImeIgraca(id),reason);
	DCC_SendChannelMessage(disc_kanal,disc_kick_msg);
	SendClientMessage(id,-1,""col_red"[KICK]{ffffff} Vi ste kickani sa servera! Admin: "col_balkanstory"Discord Bot - novaerarp.(/).com");
	SendClientMessageEx(id,-1, ""col_red"[KICK-RAZLOG] {ffffff}Razlog: %s",reason);
	Dimi_Kick(id);
	return 1;
}

DiscAnnc();
public DiscAnnc()
{
	DCC_SendChannelMessage(disc_kanal, ":white_check_mark: | **Server je** uspjesno ukljucen!");

	return 1;
}

DC:ugasi(cmdparams)
{
	channelcheck
	DCC_SendChannelMessage(disc_kanal, ":no_entry: | **Server je** uspjesno iskljucen!");
	GameModeExit();
	return 1;
}
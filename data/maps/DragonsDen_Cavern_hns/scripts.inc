DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… So you're here.\p"
	.string "If you think you can keep up,\n"
	.string "with me, come to the FIGHTING\l"
	.string "DOJO in SAFFRON.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
    .string "CLAIR: WAIT!\p"
	.string "I'm sorry about this.\n"
    .string "Here, take this as my apology.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
    .string "DRAGON PULSE is a kind of er...\n"
	.string "never mind!\p"
	.string "It's a huge energy of some kind.\p"
	.string "If you don't want it, you don't have\n"
	.string "to take it.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "What's the matter? Aren't\n"
    .string "you going on to the POKéMON\l"
    .string "LEAGUE?\p"
    .string "After you become CHAMPION, you\n"
    .string "can rematch any GYM LEADER you\l"
    .string "want.\p"
    .string "Go to the POKéMON LEAGUE.\p"
    .string "Do you know how to get there?\p"
    .string "From here, go to NEW BARK TOWN.\p"
    .string "Then SURF east to POKéMON LEAGUE.\p"
    .string "The route there is very tough.\p"
    .string "Don't you dare lose at the POKéMON\n"
    .string "LEAGUE!\p"
    .string "If you do, I'll feel even worse\n"
    .string "about having lost to you!\p"
    .string "Give it everything you've got.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "DRAGON SHRINE\p"
    .string "A shrine honoring the dragon\n"
    .string "POKéMON\p"
    .string "said to have lived in DRAGON'S\n"
    .string "DEN.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "…\n"
    .string "What? {PLAYER}?\p"
    .string "…No, I won't battle you now…\p"
    .string "My POKéMON aren't ready to beat\n"
    .string "you.\p"
    .string "I can't push them too hard now.\p"
    .string "I have to be disciplined to become\n"
    .string "the greatest POKéMON trainer…$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "…\p"
    .string "Whew…\p"
    .string "Learn to stay out of my way…$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "You! How dare you enter\n"
    .string "uninvited!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "S-strong!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "The SHRINE ahead is home to the\n"
    .string "MASTER of our dragon-user clan.\p"
    .string "You're not allowed to just go in!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "You shouldn't be in here!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Oh yikes, I lost!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Soon I'm going to get permission\n"
    .string "from our MASTER to use dragons.\p"
    .string "When I do, I'm going to become an\n"
    .string "admirable dragon trainer and gain\l"
    .string "our MASTER's approval.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "It's a stranger we don't know.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Ouchies.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "It was like having to battle\n"
    .string "LANCE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Who are you?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Meanie.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "We'll tell on you.\p"
    .string "MASTER will be angry with you.$"

DragonsDen_Cavern_Text_Tyranitar::
    .string "Tyrant... itar!$"

DragonsDen_Cavern_EventScript_SliverTyranitar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TYRANITAR, CRY_MODE_NORMAL
	msgbox DragonsDen_Cavern_Text_Tyranitar, MSGBOX_NPC
	waitmoncry
	release
	end

DragonsDen_Cavern_EventScript_SliverBattle::
	lockall
	faceplayer
	removeobject LOCALID_DRAGONSDEN_LANCE
	removeobject LOCALID_DRAGONSDEN4_CLAIR
	msgbox DragonsDen_Cavern_Text_Silver, MSGBOX_NPC
	closemessage
	playse SE_PIN
	waitse
	applymovement2 LOCALID_DRAGONSDEN_SILVER, DragonsDen_Cavern_Movement_MarkUp
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_MarkUp
	applymovement2 LOCALID_DRAGONSDEN_TYRANITAR, DragonsDen_Cavern_Movement_MarkUp
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Cavern_Movement_MarkUp
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_SeeSomeone
	closemessage
	applymovement2 LOCALID_DRAGONSDEN_TYRANITAR, DragonsDen_Cavern_Movement_TtarMove
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_PlayerMove
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Cavern_Movement_FollowerMove
	waitmovement 0
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	msgbox DragonsDen_Cavern_Text_WhatLance
	closemessage
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	addobject LOCALID_DRAGONSDEN_LANCE
	addobject LOCALID_DRAGONSDEN4_CLAIR
	applymovement2 LOCALID_DRAGONSDEN_LANCE, DragonsDen_Cavern_Movement_LanceWalkDown
	applymovement2 LOCALID_DRAGONSDEN4_CLAIR, DragonsDen_Cavern_Movement_ClairWalkDown
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_LanceHere
	closemessage
	applymovement2 LOCALID_DRAGONSDEN4_CLAIR, DragonsDen_Cavern_Movement_ClairDown
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_ClairHere
	closemessage
	applymovement2 LOCALID_DRAGONSDEN_SILVER, DragonsDen_Cavern_Movement_SilverUp
	applymovement2 LOCALID_DRAGONSDEN4_CLAIR, DragonsDen_Cavern_Movement_ClairSlide
	waitmovement 0
	playse SE_M_STRENGTH
	waitse
	msgbox DragonsDen_Cavern_Text_SilverNo
	closemessage
	applymovement2 LOCALID_DRAGONSDEN_SILVER, DragonsDen_Cavern_Movement_SilverToPlayer
	applymovement2 LOCALID_DRAGONSDEN4_CLAIR, DragonsDen_Cavern_Movement_ClairDown
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_SilverLetFight
	closemessage
	goto DragonsDen_Cavern_EventScript_Silver_Multi
	end

DragonsDen_Cavern_Text_Silver:
	.string "{RIVAL}: ...What?\n"
    .string "Are you here to make fun of my\l"
    .string "training?\p"
    .string "Humph!\n"
    .string "I too took all my time coming here!\l"
    .string "but the master won't tell me\l"
    .string "anything\l"
    .string "and he's making a big deal of it...\p"
    .string "So I decided to train my POKEMON\n"
    .string "here.$"

DragonsDen_Cavern_Text_SeeSomeone::
    .string "{RIVAL}: Who's that?$"

DragonsDen_Cavern_Text_WhatLance::
    .string "{RIVAL}: LANCE?$"

DragonsDen_Cavern_Text_LanceHere::
    .string "LANCE: Hi {PLAYER}!\n"
    .string "And...you.\l"
    .string "We met at the Team Rocket Hideout.\l"
    .string "{RIVAL}: You?\p"
    .string "Where have you been all this time?\n"
    .string "Prepare to lose to me this time?\l"
    .string "I challenge you!\p"
    .string "LANCE: Calm down.\n"
    .string "I was in a bit of a hurry then.\l"
    .string "Sorry for that.\l"
    .string "But...I always welcome\l"
    .string "challengers!\p"
    .string "Hey!\n"
    .string "How about a double battle?\p"
    .string "{RIVAL}: Humph!\n"
    .string "You can't beat me one-on-one,\l"
    .string "can you?\p"
    .string "LANCE: Come on.\n"
    .string "A double battle is really not bad.\l"
    .string "{PLAYER}, you'll be on my side!$"

DragonsDen_Cavern_Text_SilverHumph::
    .string "{RIVAL}: Humph!$"

DragonsDen_Cavern_Text_ClairHere::
    .string "CLAIR: Well then, you over there!\n"
    .string "Will you team up with me?\p"
    .string "{RIVAL}: You must be kidding!\n"
    .string "That embarrassing one in the weird\l"
    .string "costume for me?\p"
    .string "No way I can battle with her!$"

DragonsDen_Cavern_Text_SilverNo::
    .string "{RIVAL}: Serves you right!$"


DragonsDen_Cavern_Text_SilverLetFight::
    .string "{PLAYER}: Come to my side!\n"
    .string "We'll beat LANCE together!$"

DragonsDen_Cavern_Text_LanceLeave::
    .string "LANCE: Just as I expected.\n"
    .string "You two make quite a team...\p"
    .string "Going solo is certainly one way\n"
	.string "to aim for the top...\p"
    .string "But that's not all there is to\n"
    .string "POKEMON battle.\l"
    .string "Although I don't feel it's\l"
    .string "necessary to remind you guys.\p"
    .string "See you, PLAYER,\n"
    .string "another time!$"

DragonsDen_Cavern_Text_ClairLeave::
    .string "CLAIR: I must excuse myself.\n"
    .string "PLAYER, it was a fun battle.\l"
    .string "That goes for you, too, wise guy.$"

DragonsDen_Cavern_Text_SilverLeave::
    .string "{RIVAL}: {PLAYER},\n"
    .string "It wasn't supposed to go\l"
    .string "this way...\p"
    .string "Anyway, I am not giving up\n"
    .string "beating you!\p"
    .string "I'll train my POKEMON and...\n"
    .string "my own heart, too.\p"
    .string "I'll come back as the toughest\n"
    .string "challenge for you!$"

DragonsDen_Cavern_EventScript_Silver_Multi::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, DragonsDen_Cavern_EventScript_PickSilverPartner
	special LoadPlayerParty
	goto DragonsDen_Cavern_EventScript_SilverYouCant
	release
	end

DragonsDen_Cavern_EventScript_SilverYouCant::
	msgbox DragonsDen_Cavern_Text_YouCantDoThat
	closemessage
	goto DragonsDen_Cavern_EventScript_Silver_Multi
	end

DragonsDen_Cavern_Text_YouCantDoThat::
    .string "{RIVAL}: You can't quit now!\n"
    .string "We need to fight!$"

DragonsDen_Cavern_EventScript_PickSilverPartner::
	lock
	faceplayer
	applymovement2 LOCALID_DRAGONSDEN_SILVER, Common_Movement_FaceUp
	waitmovement 0 
	msgbox DragonsDen_Cavern_Text_LetFightNow
	closemessage
	switch VAR_STARTER_MON
	case 0, DragonsDen_Cavern_EventScript_DoSilverMulti_Typhlosion
	case 1, DragonsDen_Cavern_EventScript_DoSilverMulti_Feraligatr
	case 2, DragonsDen_Cavern_EventScript_DoSilverMulti_Meganium
	goto DragonsDen_Cavern_EventScript_DoSilverMulti_Typhlosion

DragonsDen_Cavern_Text_LetFightNow::
    .string "{RIVAL}: Alright, let's\n"
    .string "fight!$"

DragonsDen_Cavern_EventScript_DoSilverMulti_Typhlosion::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, DragonsDen_Cavern_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, DragonsDen_Cavern_Text_Clair3Defeat, PARTNER_SILVER_TYPHLOSION_HNS
	goto DragonsDen_Cavern_EventScript_SilverMultiResult

DragonsDen_Cavern_EventScript_DoSilverMulti_Feraligatr::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, DragonsDen_Cavern_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, DragonsDen_Cavern_Text_Clair3Defeat, PARTNER_SILVER_FERALIGATR_HNS
	goto DragonsDen_Cavern_EventScript_SilverMultiResult

DragonsDen_Cavern_EventScript_DoSilverMulti_Meganium::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, DragonsDen_Cavern_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, DragonsDen_Cavern_Text_Clair3Defeat, PARTNER_SILVER_MEGANIUM_HNS
	goto DragonsDen_Cavern_EventScript_SilverMultiResult

DragonsDen_Cavern_EventScript_SilverMultiResult::
	switch VAR_RESULT
	case 1, DragonsDen_Cavern_EventScript_SilverMultiWin
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end

DragonsDen_Cavern_EventScript_SilverMultiWin::
	lock
	faceplayer
	applymovement2 LOCALID_DRAGONSDEN_SILVER, Common_Movement_FaceUp
	waitmovement 0 
	msgbox DragonsDen_Cavern_Text_SilverHumph
	closemessage
	waitmessage
	msgbox DragonsDen_Cavern_Text_LanceLeave
	closemessage
	waitmessage
	applymovement2 LOCALID_DRAGONSDEN_LANCE, DragonsDen_Cavern_Movement_LanceExit
	waitmovement 0
	msgbox DragonsDen_Cavern_Text_ClairLeave
	closemessage
	waitmessage
	applymovement2 LOCALID_DRAGONSDEN4_CLAIR, DragonsDen_Cavern_Movement_ClairExit
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN_SILVER, Common_Movement_FaceRight
	msgbox DragonsDen_Cavern_Text_SilverLeave
	closemessage
	waitmessage
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_SILVER
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_DRAGONSDEN_SILVER
	removeobject LOCALID_DRAGONSDEN_TYRANITAR
	fadescreen FADE_FROM_BLACK
	releaseall
	end

DragonsDen_Cavern_Text_Lance3Defeat:
	.string "Did you see that, CLAIR?$"

DragonsDen_Cavern_Text_Clair3Defeat:
	.string "Oh, I see...$"

DragonsDen_Cavern_Movement_TtarMove::
	walk_down
	walk_down
	walk_left
	face_up
	step_end

DragonsDen_Cavern_Movement_PlayerMove::
	walk_right
	walk_down
	face_up
	step_end

DragonsDen_Cavern_Movement_FollowerMove::
	walk_down
	walk_right
	walk_down
	walk_down
	face_up
	step_end

DragonsDen_Cavern_Movement_MarkUp::
	face_up
	emote_exclamation_mark
	step_end


DragonsDen_Cavern_Movement_LanceWalkDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

DragonsDen_Cavern_Movement_ClairWalkDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

DragonsDen_Cavern_Movement_LanceExit::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairExit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairSlide:
	slide_up
	face_down
	slide_up
	face_down
	step_end

DragonsDen_Cavern_Movement_SilverUp::
	walk_up
	step_end

DragonsDen_Cavern_Movement_SilverToPlayer::
	walk_down
	face_right
	step_end

DragonsDen_Cavern_Movement_ClairDown::
	walk_down
	step_end



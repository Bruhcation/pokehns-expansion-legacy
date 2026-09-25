GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "Y-you! You came to rescue me?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "Is that what you were expecting?\p"
	.string "Wrong! I'm an imposter!\p"
	.string "I pretended to be the real thing to\n"
	.string "prepare for our takeover.\p"
	.string "Do you want to know where we hid\n"
	.string "the real DIRECTOR?\p"
	.string "Sure, I'll tell you. But only if you\n"
	.string "can beat me!$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "OK, OK. I'll tell you where he is.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "The boss stashed the DIRECTOR in\n"
	.string "the UNDERGROUND WAREHOUSE.\p"
	.string "It's at the far end of the UNDER-\n"
	.string "GROUND.\p"
	.string "I am a nice guy, I will give you\n"
	.string "the BASEMENT KEY to get to the\l"
	.string "UNDERGROUND WAREHOUSE.\p"
	.string "But I doubt you'll get that far.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "The boss stashed the DIRECTOR in\n"
	.string "the UNDERGROUND WAREHOUSE.\p"
	.string "It's at the far end of the UNDER-\n"
	.string "GROUND.\p"
	.string "You can use the BASEMENT KEY to\n"
	.string "get to the UNDERGROUND WAREHOUSE.\p"
	.string "But I doubt you'll get that far.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Houndoom::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Houndoom, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Text_Houndoom::
	.string "Hound... Doom!!!$"

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	removeobject LOCALID_RADIOTOWER5F_HOUNDOOM
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_RADIOTOWER5F_GIOVANNI
	applymovement LOCALID_RADIOTOWER5F_GIOVANNI, GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkDown
	waitmovement 0
	applymovement LOCALID_GOLDENROD_ARCHER, GoldenrodCity_RadioTower_5F_Movement_MarkFaceRight
	applymovement LOCALID_GOLDENROD_ARIANA, GoldenrodCity_RadioTower_5F_Movement_MarkFaceRight
	applymovement OBJ_EVENT_ID_PLAYER, GoldenrodCity_RadioTower_5F_Movement_MarkFaceRight
	playse SE_PIN
	waitse
	msgbox GoldenrodCity_RadioTower_5F_Text_QuestionMark, MSGBOX_DEFAULT
	closemessage
	waitmessage
	fadescreen FADE_TO_BLACK
	delay 60
	fadescreen FADE_FROM_BLACK
	msgbox GoldenrodCity_RadioTower_5F_Text_Giovanni, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement LOCALID_RADIOTOWER5F_GIOVANNI, GoldenrodCity_RadioTower_5F_Movement_GiovanniToArcher
	waitmovement 0
	applymovement LOCALID_GOLDENROD_ARCHER, Common_Movement_FaceDown
	waitmovement 0	
	msgbox GoldenrodCity_RadioTower_5F_Text_Giovanni2, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement LOCALID_RADIOTOWER5F_GIOVANNI, GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkAway
	waitmovement 0	
	msgbox GoldenrodCity_RadioTower_5F_Text_Giovanni3, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement LOCALID_RADIOTOWER5F_GIOVANNI, GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkUp
	waitmovement 0
	playse SE_EXIT
	msgbox GoldenrodCity_RadioTower_5F_Text_Archer1, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement LOCALID_GOLDENROD_ARCHER, GoldenrodCity_RadioTower_5F_Movement_ArcherWalkDown
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_Archer2, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement LOCALID_GOLDENROD_ARCHER, GoldenrodCity_RadioTower_5F_Movement_ArcherWalkUp
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_Archer3, MSGBOX_DEFAULT
	closemessage
	waitmessage
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_Movement_MarkFaceRight::
	emote_exclamation_mark
	face_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_ArcherWalkDown::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_ArcherWalkUp::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_Archer1::
    .string "ARCHER:I... I did this for you.\n"
    .string "For the glory of TEAM ROCKET.\l"
    .string "All my efforts, all these\l"
    .string "sacrifices.\p"
    .string "And you just...\n"
    .string "Was it all in vain?\l"
    .string "Did I misunderstand our purpose?$"

GoldenrodCity_RadioTower_5F_Text_Archer2::
    .string "You left. You vanished\n"
    .string "without a word.\l"
    .string "We were lost. I tried to carry\l"
    .string "your legacy.\p"
    .string "You were the leader,\n"
    .string "the visionary.\l"
    .string "And I... I'm just...\l"
    .string "Was I a mere puppet?\l"
    .string "Chasing a dream you never shared?$"

GoldenrodCity_RadioTower_5F_Text_Archer3::
    .string "But... but I can't just let go.\n"
    .string "Not after everything.\l"
    .string "Do you expect me to just walk away,\l"
    .string "to abandon our cause?\p"
    .string "I... I need time.\n"
    .string "I need to get out of here.\p"
    .string "But know this, GIOVANNI.\n"
    .string "Even if the path was wrong...\l"
    .string "My intentions were true!$"

GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkUp::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkAway::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
GoldenrodCity_RadioTower_5F_Movement_GiovanniToArcher::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_RadioTower_5F_Text_QuestionMark:
    .string "???: Such conviction.\n"
    .string "Reminds me of a time when I,\l"
    .string "too, was so sure.\p"
    .string "You speak of legacy, of\n"
    .string "taking over...\l"
    .string "But recall, ARCHER.\l"
    .string "Why did I choose to disband it?$"

GoldenrodCity_RadioTower_5F_Text_Giovanni:
    .string "GIOVANNI: It wasn't merem defeat\n"
    .string "or whim,\l"
    .string "It was an awakening.\l"
    .string "See the state of this group now.\l"
    .string "Desperate acts, hiding.\l"
    .string "A far cry from where we once\l"
    .string "stood.$"

GoldenrodCity_RadioTower_5F_Text_Giovanni2:
    .string "Power isn't just about domination.\n"
    .string "It's understanding and respect.\l"
    .string "Is this the legacy you imagined?\l"
    .string "Reduced to skulking in the\l"
    .string "shadows?$"

GoldenrodCity_RadioTower_5F_Text_Giovanni3:
    .string "Rethink this path.\n"
	.string "Do you truly see a future for this\l"
    .string "TEAM ROCKET?$"

GoldenrodCity_RadioTower_5F_Movement_GiovanniWalkDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Remember me from the HIDEOUT in\n"
	.string "MAHOGANY TOWN?\p"
	.string "My boss scolded me but I'm stronger.\p"
	.string "I lost then, but I won't this time.$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "This can't be happening!\p"
	.string "I fought hard, but I still lost…\p"
	.string "I'm so sorry GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, isn't it?\p"
	.string "A brat like you won't appreciate\n"
	.string "the magnificence of TEAM ROCKET.\p"
	.string "That's too bad. I really admire\n"
	.string "your power.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh? You managed to get this far?\p"
	.string "You must be quite the trainer.\p"
	.string "We intend to take over this RADIO\n"
	.string "STATION and announce our comeback.\p"
	.string "That should bring our boss GIOVANNI\n"
	.string "back from his solitary training.\p"
	.string "We are going to regain our former\n"
	.string "glory...\p"
	.string "I won't allow you to interfere with\n"
	.string "our meticulous plans!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "No! Forgive me, GIOVANNI!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "How could this be?\p"
	.string "TEAM ROCKET was destined to rise\n"
    .string "again...\p"
    .string "For GIOVANNI, for our legacy.\n"
    .string "We cannot fall now!\l"
    .string "You may have won this battle,\l"
    .string "but the war?\l"
    .string "It's far from over.\l"
    .string "You'll see.\p"
    .string "Our ambition, our dream will not\n"
    .string "fade!\l"
    .string "The world will fear TEAM ROCKET\l"
    .string "once again!\l"
    .string "This is only a setback!$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTOR: {PLAYER}, thank you!\p"
	.string "TEAM ROCKET was destined to rise\n"
    .string "again...\p"
    .string "For GIOVANNI, for our legacy.\n"
    .string "We cannot fall now!\p"
    .string "You may have won this battle,\n"
    .string "but the war?\l"
    .string "It's far from over.\l"
    .string "You'll see.\l"
    .string "Our ambition, our dream will not\l"
    .string "fade!\p"
    .string "The world will fear TEAM ROCKET\n"
    .string "once again!\p"
    .string "This is only a setback!$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "There used to be a tower right here\n"
	.string "in GOLDENROD CITY.\p"
	.string "But it was old and creaky.\p"
	.string "So we replaced it with our RADIO\n"
	.string "TOWER.\p"
	.string "We dug up that wing during\n"
	.string "construction.\p"
	.string "I heard that all sorts of POKéMON\n"
	.string "lived in GOLDENROD in the past.\p"
	.string "Perhaps…\p"
	.string "That wing has some connection to the\n"
	.string "TIN TOWER in ECRUTEAK CITY…\p"
	.string "OK, I better go to my OFFICE.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "There used to be a tower right here\n"
	.string "in GOLDENROD CITY.\p"
	.string "But it was old and creaky.\p"
	.string "So we replaced it with our RADIO\n"
	.string "TOWER.\p"
	.string "We dug up that wing during\n"
	.string "construction.\p"
	.string "I heard that all sorts of POKéMON\n"
	.string "lived in GOLDENROD in the past.\p"
	.string "Perhaps…\p"
	.string "That wing has some connection to the\n"
	.string "WHIRL ISLANDS near CIANWOOD CITY…\p"
	.string "OK, I better go to my OFFICE.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah!\p"
	.string "That reminds me…\p"
	.string "That wing I gave you... I think\n"
	.string "it's related to the LEGENDARY\l"
	.string "POKéMON.\p"
	.string "But! The LEGENDARY POKéMON won't\n"
	.string "appear with just that wing...\p"
	.string "Apparently there is something else\n"
	.string "you need... Or something like that.\p"
	.string "I wonder what it was...\p"
	.string "I can't remember.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Are you expecting something?\n"
	.string "This is what they call FAKE OUT.\p"
	.string "I really must go back to my OFFICE\n"
	.string "this time. See ya!$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTOR: Hello, {PLAYER}!\p"
	.string "You know, I love POKéMON.\p"
	.string "I built this RADIO TOWER so I could\n"
	.string "express my love of POKéMON.\p"
	.string "It would be nice if people enjoyed\n"
	.string "our programs.$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN: Do you listen to our music?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5F DIRECTOR'S   OFFICE$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"

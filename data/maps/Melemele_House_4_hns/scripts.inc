Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "We're vacationing on the ALOLA ISLES!\p"
	.string "It's just like the ALOLA region,\n"
	.string "but closer to KANTO!\p"
	.string "I saved so much on travel expenses!$"

Melemele_House4_Woman_Text_0:
	.string "My boyfriend told me we were going to\n"
	.string "ALOLA…\p"
	.string "I had assumed it would be the ALOLA\n"
	.string "region, not the small isles off the\l"
	.string "coast of KANTO.$"

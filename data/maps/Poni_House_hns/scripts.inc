Poni_House_hns_MapScripts::
	.byte 0

Poni_House_hns_TradeWater::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETED_TAUROS_WATER_TRADE, Poni_House_hns_TradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_TAUROS_WATER
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox Poni_House_hns_Text_WantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Poni_House_hns_DeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Poni_House_hns_DeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Poni_House_hns_Text_TakeCare, MSGBOX_DEFAULT
	setflag FLAG_COMPLETED_TAUROS_WATER_TRADE
	release
	end

Poni_House_hns_TradeFire::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETED_TAUROS_FIRE_TRADE, Poni_House_hns_FireTradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_TAUROS_FIRE
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox Poni_House_hns_Text_WantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Poni_House_hns_FireDeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Poni_House_hns_FireDeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Poni_House_hns_Text_FireTakeCare, MSGBOX_DEFAULT
	setflag FLAG_COMPLETED_TAUROS_FIRE_TRADE
	release
	end

Poni_House_hns_DeclineTrade::
	msgbox Poni_House_hns_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Poni_House_hns_TradeCompleted::
	msgbox Poni_House_hns_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Poni_House_hns_FireDeclineTrade::
	msgbox Poni_House_hns_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Poni_House_hns_FireTradeCompleted::
	msgbox Poni_House_hns_Text_FireTradeCompleted, MSGBOX_DEFAULT
	release
	end

Poni_House_hns_Text_WantToTrade:
	.string "The {STR_VAR_2} out here aren't like\n"
	.string "the ones on the mainland.\p"
	.string "Want to trade for my {STR_VAR_2}?$"

Poni_House_hns_Text_TakeCare:
	.string "Thanks!\n"
	.string "TORA, you take care!$"

Poni_House_hns_Text_DeclineTrade:
	.string "You don't want to trade? Aww...$"

Poni_House_hns_Text_TradeCompleted:
	.string "Hi, how's my old TORA doing?$"

Poni_House_hns_Text_FireTakeCare:
	.string "Thanks!\n"
	.string "TORO, you take care!$"

Poni_House_hns_Text_FireDeclineTrade:
	.string "You don't want to trade? Damn...$"

Poni_House_hns_Text_FireTradeCompleted:
	.string "Hi, how's my old TORO doing?$"


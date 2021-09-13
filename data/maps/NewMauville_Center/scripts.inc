NewMauville_Center_MapScripts::
	.byte 0

NewMauville_Center_EventScript_SpookyMonitor::
	lockall
	goto_if_set FLAG_ROTOM_CAUGHT, NewMauville_Center_EventScript_SilentMonitor
	goto_if_set FLAG_ROTOM_DEFEATED, NewMauville_Center_EventScript_SilentMonitor
	msgbox New_Mauville_Center_Text_OminousPresence, MSGBOX_DEFAULT
	goto NewMauville_Center_EventScript_ThumpMonitor

NewMauville_Center_EventScript_ThumpMonitor:
	msgbox New_Mauville_Center_Text_ThumpChoice, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq New_Mauville_Center_EventScript_LeaveMonitor
	goto NewMauville_Center_EventScript_RotomBattle


NewMauville_Center_EventScript_RotomBattle::
	msgbox NewMauville_Center_Text_RotomAttacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_ROTOM, 0
	delay 40
	waitmoncry
	setwildbattle SPECIES_ROTOM, 45, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq NewMauville_Center_EventScript_RotomFades
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Center_EventScript_RotomDefeated
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Center_EventScript_RotomRetreats
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Center_EventScript_ResetRotom
	release
	end

New_Mauville_Center_EventScript_LeaveMonitor:
	msgbox 	NewMauville_Center_Text_LeaveMonitor, MSGBOX_DEFAULT
	release
	end

NewMauville_Center_EventScript_RotomFades:
	setflag FLAG_ROTOM_CAUGHT
	msgbox NewMauville_Center_Text_RotomFades
	release
	end

NewMauville_Center_EventScript_RotomDefeated:
	setflag FLAG_ROTOM_DEFEATED
	msgbox NewMauville_Center_Text_RotomDisappears
	release
	end	

NewMauville_Center_EventScript_RotomRetreats:
	msgbox NewMauville_Center_Text_RotomRetreats
	release
	end

NewMauville_Center_EventScript_ResetRotom:
	release
	end	

NewMauville_Center_EventScript_SilentMonitor:
	msgbox NewMauville_Center_Text_SilentMonitor
	release
	end

New_Mauville_Center_Text_OminousPresence:
	.string "You sense an ominous presence\n"
	.string "inside the monitor…$"

New_Mauville_Center_Text_ThumpChoice:
	.string "Thump the monitor?$"

NewMauville_Center_Text_RotomAttacked:
	.string "The Pokémon inside attacked!$"

NewMauville_Center_Text_LeaveMonitor:
	.string "You leave the monitor alone…$"

NewMauville_Center_Text_RotomFades:
	.string "With the ROTOM's power gone,\n"
	.string "the monitor powers down.$"

NewMauville_Center_Text_RotomDisappears:
	.string "Defeated, the ROTOM retreats\n"
	.string "deep within New Mauville…$"	

NewMauville_Center_Text_RotomRetreats:
	.string "The ROTOM retreats back\n"
	.string "into the monitor…$"

NewMauville_Center_Text_SilentMonitor:
	.string "The monitor is silent.$"	

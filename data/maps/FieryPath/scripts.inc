FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPath_EventScript_Tyler::
	trainerbattle_single TRAINER_TYLER, FieryPath_Text_TylerIntro, FieryPath_Text_TylerDefeat
	msgbox FieryPath_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end	

FieryPath_Text_TylerIntro:
	.string "I saw my favorite Pokémon {COLOR RED}Chimchar\n"
	.string "{COLOR DARK_GRAY}go in there!\p"
	.string "If you want to go in first,\n"
	.string "you'll have to beat me!$"

FieryPath_Text_TylerDefeat:
	.string "But…my Fire types…$"

FieryPath_Text_TylerPostBattle:
	.string "I guess I'm not strong enough\n"
	.string "to stop you from going in…$"


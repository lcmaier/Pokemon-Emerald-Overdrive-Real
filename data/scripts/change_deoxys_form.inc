ChangeDeoxysForm::
	lockall
	msgbox ChangeDeoxysForm_Text_Beginning, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChangeDeoxysForm_Start
ChangeDeoxysForm_End:
	msgbox ChangeDeoxysForm_Text_Cancel, MSGBOX_DEFAULT
	releaseall
	end

ChangeDeoxysForm_Start:
	msgbox ChangeDeoxysForm_Text_Select, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq ChangeDeoxysForm_End
	special TryChangeDeoxysForm
	compare VAR_RESULT, TRUE
	goto_if_eq ChangeDeoxysForm_Success
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Success:
	playmoncry SPECIES_DEOXYS, 0
	msgbox ChangeDeoxysForm_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitbuttonpress
	releaseall
	end

ChangeDeoxysForm_Text_Beginning:
	.string "Would you like to touch\n"
	.string "the meteorite?$"

ChangeDeoxysForm_Text_Cancel:
	.string "You do not touch\n"
	.string "the meteorite.$"

ChangeDeoxysForm_Text_Select:
	.string "Please select a DEOXYS.$"

ChangeDeoxysForm_Text_Success:
	.string "Your DEOXYS has transformed!$"

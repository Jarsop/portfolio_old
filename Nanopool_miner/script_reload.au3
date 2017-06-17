While (1)
	If WinExists("EthDcrMiner64") Then
		Sleep(3600000)
		WinActivate("EthDcrMiner64")
		Send("r")
	;	WinSetState("EthDcrMiner64", "", @SW_MINIMIZE)
	Else
		Break
	EndIf
WEnd
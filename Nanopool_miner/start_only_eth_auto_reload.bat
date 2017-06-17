@echo off

set exe=C:\Users\jpges\Documents\Nanopool_miner-20170502T145433Z-001\Nanopool_miner\EthDcrMiner64.exe
set arguments= " -epool eth-eu1.nanopool.org:9999 -ewal 0xce478277c69fb38d76760ae3a555c23afa1311a1 -epsw Shadow -etht 1000 -mode 1 -ftime 10
pause"
set duree_redem=1
set /a nb_redemarrages=0

cls
color 70
setx GPU_FORCE_64BIT_PTR 0
setx GPU_MAX_HEAP_SIZE 100
setx GPU_USE_SYNC_OBJECTS 1
setx GPU_MAX_ALLOC_PERCENT 100
setx GPU_SINGLE_ALLOC_PERCENT 100

:start
start /min /affinity 0x1 "EthDcrMiner64" %exe% %arguments%

:recom
set duree=9000

:prez
cls
echo                      .+` 
echo                     -omd.
echo                    :ssmNm-
echo                  `/sssmNNN/ 
echo                 +ssssmNNNNs'
echo                .osssssmNNNNNh. 
echo               :sssssssmNNNNNNd-
echo             `/ssssssssmNNNNNNNm/
echo            `+ssssssssyNNNNNNNNNNo' 
echo           .ossssyhdmNNMMMMMMNNNNNy' 
echo          -syyhdmNNNNNNMMMMMMMMMMNNd- 
echo         :hmNNNNNNNNNNNMMMMMMMMMMMMMd.
echo         `-ohmNNNNNNNNNMMMMMMMMMMmy/- 
echo          ::.-/sdNNNNNNMMMMMMNds::/s: 
echo           -oo/-.-ohmNNMMMmy+-:ohmh- 
echo            .+sso+:-./yhs:-/sdNNNo` 
echo              :osssoo/-:+hmNNNNd:
echo               .+ssssssdNNNNNNs` 
echo                `:sssssmNNNNm:
echo                  .osssmNNNy.
echo                   `/ssmNm/
echo                     -omh.
echo                       `:                                       Script by Jgeslin
echo ------------------------------------------------------------------------------
echo Le minage sous %exe% va durer encore %duree% secondes (redemarrage num. %nb_redemarrages%)
echo ------------------------------------------------------------------------------
set /a duree-=1
if %duree%==-1 goto redem
choice /C onr /N /T 1 /D n /M "O pour redemarrer le logiciel maintenant, R pour redemarrer le compteur"
if errorlevel ==3 goto recom
if errorlevel ==2 goto prez
if errorlevel ==1 goto redem
goto prez

:redem
taskkill /f /im %exe%
cls
echo:
echo Le logiciel redemarre dans %duree_redem% secondes
timeout %duree_redem%
set /a nb_redemarrages+=1
goto start
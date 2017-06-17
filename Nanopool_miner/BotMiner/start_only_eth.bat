setx GPU_FORCE_64BIT_PTR 0
setx GPU_MAX_HEAP_SIZE 100
setx GPU_USE_SYNC_OBJECTS 1
setx GPU_MAX_ALLOC_PERCENT 100
setx GPU_SINGLE_ALLOC_PERCENT 100

set exe = "C:\Users\jpges\Documents\Nanopool_miner-20170502T145433Z-001\Nanopool_miner\EthDcrMiner64.exe"
set arguments = " -epool eth-eu1.nanopool.org:9999 -ewal  0xce478277c69fb38d76760ae3a555c23afa1311a1 -epsw Shadow -etht 1000 -mode 1 -ftime 10
pause"

start /affinity 0x1 "EthDcrMiner64" "C:\Users\jpges\Documents\Nanopool_miner-20170502T145433Z-001\Nanopool_miner\EthDcrMiner64.exe" " -epool eth-eu1.nanopool.org:9999 -ewal  0xce478277c69fb38d76760ae3a555c23afa1311a1 -epsw Shadow -etht 1000 -mode 1 -ftime 10"

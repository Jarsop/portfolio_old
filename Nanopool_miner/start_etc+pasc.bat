setx GPU_FORCE_64BIT_PTR 0
setx GPU_MAX_HEAP_SIZE 100
setx GPU_USE_SYNC_OBJECTS 1
setx GPU_MAX_ALLOC_PERCENT 100
setx GPU_SINGLE_ALLOC_PERCENT 100

EthDcrMiner64.exe -epool etc-eu1.nanopool.org:19999 -ewal YOUR_WALLET/YOUR_WORKER/YOUR_EMAIL -epsw x -dpool stratum+tcp://pasc-eu1.nanopool.org:15555 -dwal YOUR_PASC_WALLET.YOUR_PAYMENTID.YOUR_WORKER/YOUR_EMAIL -dpsw x -dcoin pasc -etht 1000 -dcrt 1000 -ftime 10
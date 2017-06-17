__author__ = "jgeslin"

#
#### PERSONNAL INFO ###
#

WALLET = "0xce478277c69fb38d76760ae3a555c23afa1311a1"
E_API_KEY = "MY_KEY"

#
#### GLOBAL PROGRAMME NAME ###
#

DRIVER = r"C:\Users\jpges\Drivers\geckodriver.exe"
MINER = "EthDcrMiner64"
SCRIPT_OLD = "C:\WINDOWS\system32\cmd.exe"
SCRIPT = "EhtMiner Auto-Reload"
FIREFOX = "Nanopool | Ethereum | Account - Mozilla Firefox"
MAIN = "AutEMining"

#
#### ADDRESS ###
#

ETHERSCAN = "https://api.etherscan.io/api?module=account&action=balance&address="+WALLET+"&tag=latest&apikey="+E_API_KEY
ETH_CHANGE = "https://api.etherscan.io/api?module=stats&action=ethprice&apikey="+E_API_KEY
NANO = "https://api.nanopool.org/v1/eth/user/"+WALLET
CALCULATOR = "https://api.nanopool.org/v1/eth/approximated_earnings/"

#
#### PATH ###
#

PATH_SCRIPT = r"C:\Users\jpges\Documents\Nanopool_miner-20170502T145433Z-001\Nanopool_miner\BotMiner\start_only_eth.bat"

#
#### Tools ###
#

DOLLARS_EURO = 0.889761

def my_dump(obj):
    for attr in dir(obj):
        print("obj.%s = %s" % (attr, getattr(obj, attr)))

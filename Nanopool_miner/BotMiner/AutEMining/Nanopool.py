__author__ = "jgeslin"

import json
from urllib.request import Request,urlopen
from .settings import *
#
#### Nanopool class ###
#

class Nanopool(object):
    def __init__(self):
        self.req_eth = Request(ETHERSCAN, headers={'User-Agent': 'Mozilla/5.0'})
        self.req_nano = Request(NANO, headers={'User-Agent': 'Mozilla/5.0'})
        self.req_eth_change = Request(ETH_CHANGE, headers={'User-Agent': 'Mozilla/5.0'})
        print("Nanopool Tracker Created !")

    def make_result(self, s):
        l = len(s)
        if l <= 18:
            return '0.' + s
        else:
            return s[0:(l - 18)] + '.' + s[l - 18:-1]

    def __enter__(self):
        try:
            ret_eth = urlopen(self.req_eth).read()
            ret_eth_change = urlopen(self.req_eth_change).read()
            ret_nano = urlopen(self.req_nano).read()
            ret_eth = json.loads(ret_eth)
            ret_eth_change = json.loads(ret_eth_change)
            ret_nano = json.loads(ret_nano)
        except:
            try:
                ret_eth = urlopen(self.req_eth).read()
                ret_eth_change = urlopen(self.req_eth_change).read()
                ret_nano = urlopen(self.req_nano).read()
                ret_eth = json.loads(ret_eth)
                ret_eth_change = json.loads(ret_eth_change)
                ret_nano = json.loads(ret_nano)
            except:
                return ['Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null']
        req_calc = Request(CALCULATOR+ret_nano['data']['avgHashrate']['h6'], headers={'User-Agent': 'Mozilla/5.0'})
        bal = self.make_result(ret_eth['result'])
        try:
            ret_calc = urlopen(req_calc).read()
            ret_calc = json.loads(ret_calc)
            hr = [
                    ret_nano['data']['hashrate']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h1']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h3']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h6']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h12']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h24']+' Mh\s',
                    ret_nano['data']['balance']+' ETC',
                    ret_calc['data']['month']['coins'],
                    ret_calc['data']['month']['dollars'] * DOLLARS_EURO,
                    bal,
                    (float(bal) * float(ret_eth_change['result']['ethusd'])) * DOLLARS_EURO
                ]
            return hr
        except:
            try:
                ret_calc = urlopen(req_calc).read()
                ret_calc = json.loads(ret_calc)
                hr = [
                    ret_nano['data']['hashrate']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h1']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h3']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h6']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h12']+' Mh\s',
                    ret_nano['data']['avgHashrate']['h24']+' Mh\s',
                    ret_nano['data']['balance']+' ETC',
                    ret_calc['data']['month']['coins'],
                    ret_calc['data']['month']['dollars'] * DOLLARS_EURO,
                    bal,
                    (float(bal) * float(ret_eth_change['result']['ethusd'])) * DOLLARS_EURO
                ]
                return hr
            except:
                return ['Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null', 'Null']

    def __exit__(self, type, value, traceack):
        pass

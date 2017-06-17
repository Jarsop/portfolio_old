__author__ = "jgeslin"

from .Miner import Miner
from .Nanopool import Nanopool
from time import time
import re

#
#### MinerBot class ###
#

class MinerBot(object):
    def __init__(self, bot):
        self.Nanopool = Nanopool()
        self.Miner = Miner()
        self._stop = True
        self._stopm = True
        self.bot = bot

    def start_miner(self):
        with self.Miner:
            while self._stopm is False:
                pass

    def refresh(self):
        with self.Nanopool as hr:
            print(hr)
            self.bot.llf_hr.config(text=hr[0])
            self.bot.llf_h1.config(text=hr[1])
            self.bot.llf_h3.config(text=hr[2])
            self.bot.llf_h6.config(text=hr[3])
            self.bot.llf_h12.config(text=hr[4])
            self.bot.llf_h24.config(text=hr[5])
            self.bot.llf_etc.config(text=hr[6])
            self.bot.llf_rate.config(text=hr[7])
            self.bot.llf_rate_e.config(text=hr[8])
            self.bot.llf_bal.config(text=hr[9])
            self.bot.llf_bale.config(text=hr[10])
            self.bot.refresh_check(1)

    def start(self):
        res = 0
        while self._stop is False:
            if self.bot.next_check <= time():
                self.bot.check += 1
                self.bot.llfi_check.config(text=self.bot.check)
                if res == self.bot.restart or (self.bot.reload and self.bot.check % self.bot.reload == 0):
                    res = 0
                    self.bot.restart_m()
                    self.sleep(30)
                for current_check in range(self.bot.nbcheck):
                    with self.Nanopool as hr:
                        print(hr)
                        self.bot.llf_hr.config(text=hr[0])
                        self.bot.llf_h1.config(text=hr[1])
                        self.bot.llf_h3.config(text=hr[2])
                        self.bot.llf_h6.config(text=hr[3])
                        self.bot.llf_h12.config(text=hr[4])
                        self.bot.llf_h24.config(text=hr[5])
                        self.bot.llf_etc.config(text=hr[6])
                        self.bot.llf_rate.config(text=hr[7])
                        self.bot.llf_rate_e.config(text=hr[8])
                        self.bot.llf_bal.config(text=hr[9])
                        self.bot.llf_bale.config(text=hr[10])
                        self.bot.refresh_check(0)
                        regex = re.search(r"[-+]?\d*\.\d+|\d+", hr[0])
                        if regex:
                            current_hash = float(str(regex[0]))
                            if current_hash < self.bot.hlimit:
                                if current_check + 1 >= self.bot.nbcheck:
                                    self.Miner.reload_miner()
                                    self.bot.refresh_reload()
                                    self.bot.dtc_ld("Hashrate many to bad (%s / %s Mh\s) Reload miner..."
                                                    %(hr[0], self.bot.hlimit))
                                    print("reload")
                                else:
                                    self.bot.dtc_ld("Hashrate too bad ! (%s / %s Mh\s) check: %s/%s"
                                                    %(hr[0], self.bot.hlimit, current_check + 1, self.bot.nbcheck))
                                    print("check: %s/%s"%(current_check + 1, self.bot.nbcheck))
                            else:
                                res = 0
                                if current_hash < 45.0:
                                    self.bot.dtc_ld("Hashrate so good ! (%s / %s Mh\s)"
                                                    %(hr[0], self.bot.hlimit))
                                else:
                                    self.bot.dtc_ld("! TERMINATOR'S HASHRATE ! (%s / %s Mh\s)"
                                                    %(hr[0], self.bot.hlimit))
                                break
                    self.sleep_cycle()
                    if self._stop is True:
                        break
                else:
                    self.sleep_after_cycle()
                    res += 1
                self.bot.next_check = time() + self.bot.time_loop

    def sleep(self, offset):
        t = time()
        while time() <= t + offset:
            if self._stop is True:
                break

    def sleep_cycle(self):
        t = time()
        while time() <= t + self.bot.wait:
            if self._stop is True:
                break

    def sleep_after_cycle(self):
        t = time()
        while time() <= t + self.bot.bwait:
            if self._stop is True:
                break

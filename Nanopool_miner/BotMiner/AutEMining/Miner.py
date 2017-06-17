__author__ = "jgeslin"

import autoit
from .settings import *

#
#### Miner Class ####
#

class Miner(object):
    def __init__(self):
        print("Miner Spy Created !")

    def __enter__(self):
        if autoit.win_exists(SCRIPT) or autoit.win_exists(MINER):
            exit(-1)
        autoit.run(PATH_SCRIPT)
        self.change_win_script_name()

    def __exit__(self, type, value, traceback):
        self.close_window(SCRIPT)
        self.close_window(MINER)

    def close_window(self, win):
        if autoit.win_exists(win):
            autoit.win_close(win)

    def change_win_script_name(self):
        if autoit.win_exists(SCRIPT_OLD):
            autoit.win_set_title(SCRIPT_OLD, SCRIPT)

    def start_script(self):
        if autoit.win_exists(SCRIPT):
            autoit.win_close(SCRIPT)
            autoit.run(PATH_SCRIPT)

    def restart_miner(self):
        if autoit.win_exists(MINER):
            autoit.win_close(MINER)
            autoit.run(PATH_SCRIPT)

    def reload_miner(self):
        if autoit.win_exists(MINER):
            autoit.win_activate(MINER)
            autoit.send("r")

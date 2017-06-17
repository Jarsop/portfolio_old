__author__ = "jgeslin"

import autoit
import re
from time import time
from datetime import datetime
from threading import Thread
from tkinter import *
from tkinter.messagebox import *
from PIL import Image, ImageTk
from .settings import *
from .MinerBot import MinerBot

#
#### GUI ###
#

class BotGUI(object):
    def __init__(self):
        self.check, self.reload, self.restart = 0, 5000, 3
        self.idld, self.idlu, self.idrd, self.idru = 0, 0, 0, 0
        self.MinerBot = MinerBot(self)
        self._thread, self._threadm, self.MinerBot._stop = None, None, True
        self.time_loop, self.next_check, self.hlimit, self.nbcheck, self.wait, self.bwait = 10.0, time(), 8.5, 5, 60.0, 240
        self.start_GUI()
        self.set_navbar()
        self.set_canvas()
        self.set_labelframe()
        self.set_button()
        self.set_entry()
        self.set_label()
        self.f.mainloop()

    def exit(self):
        self.stop()
        self.stop_miner()
        self.f.quit()
        exit(0)

    def refresh_check(self, i):
        s = datetime.now().time()
        t = 'Last check: '+str(s).split('.')[0]
        self.dtc_lu(t)
        if i:
            self.dtc_ld("Current Hashrate : (%s / %s Mh/s)"
                                        %(self.llf_hr['text'], self.hlimit))
    def refresh_reload(self):
        s = datetime.now().time()
        t = 'Last reload: '+str(s).split('.')[0]
        self.dtc_ru(t)

    def refresh_restart(self):
        s = datetime.now().time()
        t = 'Last restart: '+str(s).split('.')[0]
        self.dtc_rd(t)

    def hide_script(self):
        if autoit.win_exists(MAIN):
            autoit.win_set_state(MAIN, autoit.properties.SW_HIDE)
        self.hide_script_button.configure(text="Show Script", command=self.show_script, relief=SUNKEN, bg='gray', fg='black')

    def show_script(self):
        if autoit.win_exists(MAIN):
            autoit.win_set_state(MAIN, autoit.properties.SW_SHOW)
            autoit.win_activate(MAIN)
        self.hide_script_button.configure(text="Hide Script", command=self.hide_script, relief=RAISED, bg='black', fg='gray')

    def hide_miner(self):
        if autoit.win_exists(MINER):
            autoit.win_set_state(MINER, autoit.properties.SW_HIDE)
        self.hide_miner_button.configure(text="Show Miner", command=self.show_miner, relief=SUNKEN, bg='gray', fg='black')

    def show_miner(self):
        if autoit.win_exists(MINER):
            autoit.win_set_state(MINER, autoit.properties.SW_SHOW)
            autoit.win_activate(MINER)
        self.hide_miner_button.configure(text="Hide Miner", command=self.hide_miner, relief=RAISED, bg='black', fg='gray')

    def start_miner(self):
        self.dtc_rd("Auto-Mining started")
        if self._threadm is None:
            self.MinerBot._stopm = False
            self._threadm = Thread(target=self.MinerBot.start_miner)
            self._threadm.start()
        self.start_am_button.configure(text="Stop Auto-Mining", command=self.stop_miner, relief=SUNKEN, bg='gray')

    def stop_miner(self):
        self.dtc_rd("Auto-Mining stopped")
        if self._threadm is not None:
            self._threadm, self.MinerBot._stopm = None,  True
        self.start_am_button.configure(text="Start Auto-Mining", command=self.start_miner, relief=RAISED, bg='black')

    def reset(self):
        self.check, self.reload, self.restart = 0, 0, 3
        self.time_loop, self.next_check, self.hlimit, self.nbcheck, self.wait, self.bwait = 10.0, time(), 17.0, 5, 60.0, 180
        self.llfi_check.config(text=self.check)
        self.llfi_sec.config(text=self.time_loop)
        self.llfi_hlimit.config(text=self.hlimit)
        self.llfi_nbcheck.config(text=self.nbcheck)
        self.llfi_wait.config(text=self.wait)
        self.llfi_bwait.config(text=self.bwait)
        self.llfi_reload.config(text=self.reload)
        self.dtc_ru("Values Reset")

    def restart_m(self):
        self.MinerBot.Miner.restart_miner()
        self.dtc_rd("Miner Restarted")
        self.refresh_restart()

    def start(self):
        self.dtc_ru("Auto-Reaload started")
        if self._thread is None:
            self.MinerBot._stop = False
            self._thread = Thread(target=self.MinerBot.start)
            self._thread.start()
        self.start_ar_button.configure(text="Stop Auto-Reload", command=self.stop, relief=SUNKEN, bg='gray')

    def stop(self):
        self.dtc_ru("Auto-Reaload stopped")
        if self._thread is not None:
            self._thread, self.MinerBot._stop = None,  True
        self.start_ar_button.configure(text="Start Auto-Reload", command=self.start, relief=RAISED, bg='black')

    def dtc_ld(self, str):
        if self.idld:
            self.canvas.delete(self.idld)
        self.idld = self.canvas.create_text(10, 50,
                                           text=str, font=("Monospace","12"), width=1000, anchor='w', fill='white')

    def dtc_lu(self, str):
        if self.idlu:
            self.canvas.delete(self.idlu)
        self.idlu = self.canvas.create_text(10, 25,
                                           text=str, font=("Monospace","12"), width=1000, anchor='w', fill='white')
    def dtc_ru(self, str):
        if self.idru:
            self.foot_canvas.delete(self.idru)
        self.idru = self.foot_canvas.create_text(10, 25,
                                           text=str, font=("Monospace","12"), width=1000, anchor='w', fill='white')
    def dtc_rd(self, str):
        if self.idrd:
            self.foot_canvas.delete(self.idrd)
        self.idrd = self.foot_canvas.create_text(10, 50,
                                           text=str, font=("Monospace","12"), width=1000, anchor='w', fill='white')

    def bind_loop_sec(self):
        ret = self.entry_sleep.get()
        regex = re.search(r"^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$", ret)
        if regex:
            self.time_loop = float(str(regex[0]))
            print(regex[0])
        self.next_check = self.next_check - time() + self.time_loop
        self.llfi_sec.config(text=self.time_loop)
        self.entry_sleep.delete(0, END)

    def bind_hlimit(self):
        ret = self.entry_hlimit.get()
        regex = re.search(r"^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$", ret)
        if regex:
            self.hlimit = float(str(regex[0]))
            print(regex[0])
        self.llfi_hlimit.config(text=self.hlimit)
        self.entry_hlimit.delete(0, END)

    def bind_nbcheck(self):
        ret = self.entry_nbcheck.get()
        regex = re.search(r"^[-+]?[0-9]+", ret)
        if regex:
            self.nbcheck = int(str(regex[0]))
            print(regex[0])
        self.llfi_nbcheck.config(text=self.nbcheck)
        self.entry_nbcheck.delete(0, END)

    def bind_wait(self):
        ret = self.entry_wait.get()
        regex = re.search(r"^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$", ret)
        if regex:
            self.wait = float(str(regex[0]))
            print(regex[0])
        self.llfi_wait.config(text=self.wait)
        self.entry_wait.delete(0, END)

    def bind_bwait(self):
        ret = self.entry_bwait.get()
        regex = re.search(r"^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$", ret)
        if regex:
            self.bwait = float(str(regex[0]))
            print(regex[0])
        self.llfi_bwait.config(text=self.bwait)
        self.entry_bwait.delete(0, END)

    def bind_reload(self):
        ret = self.entry_reload.get()
        regex = re.search(r"^[-+]?[0-9]+", ret)
        if regex:
            self.reload = int(str(regex[0]))
            print(regex[0])
        self.llfi_reload.config(text=self.reload)
        self.entry_reload.delete(0, END)

    def bind_restart(self):
        ret = self.entry_restart.get()
        regex = re.search(r"^[-+]?[0-9]+", ret)
        if regex:
            self.restart = int(str(regex[0]))
            print(regex[0])
        if self.restart < 0:
            self.restart = 0
        self.llfi_restart.config(text=self.restart)
        if self.restart == 0:
            self.restart = -1
        self.entry_restart.delete(0, END)

    def alert(self):
        showinfo("alerte", "Bravo!")

    def start_GUI(self):
        self.f = Tk()
        self.f.protocol("WM DELETE WINDOW", self.exit)
        self.f.title("AutoBot Ether Mining - AutEMining")
        self.f.state("zoomed")
        self.f.rowconfigure(0, weight=1)
        self.f.columnconfigure(0, weight=1)
        w, h = self.f.winfo_screenwidth(), self.f.winfo_screenheight()
        self.image = Image.open("./img/ethereum1.jpg")
        self.photo = ImageTk.PhotoImage(self.image)
        self.li = Label(self.f, image=self.photo, bg='black')
        self.li.place(x=0, y=0, width=w, height=h)


    def set_navbar(self):
        menubar = Menu(self.f)
        menu1 = Menu(menubar, tearoff=0)
        menu1.add_command(label="Restart Miner", command=self.restart_m)
        menu1.add_command(label="Reset", command=self.reset)
        menu1.add_separator()
        menu1.add_command(label="Quit", command=self.f.quit)
        menubar.add_cascade(label="More", menu=menu1)
        self.f.config(menu=menubar, bg='gray')

    def set_canvas(self):
        self.canvas = Canvas(self.li, width=self.f.winfo_screenwidth()/3,
                             height=70, bg='black', highlightthickness=1, relief=SUNKEN)
        self.foot_canvas = Canvas(self.li, width=self.f.winfo_screenwidth()/3,
                                  height=70, bg='black', highlightthickness=1, relief=SUNKEN)
        self.canvas.place(relx=0.00, rely=0.82, anchor='w')
        self.foot_canvas.place(relx=0.66, rely=0.82, anchor='w')

    def set_button(self):
        self.start_ar_button = Button(self.bframe, command=self.start, text ='Start Auto-Reload',
                                      height=1, width=15, bg='black', fg="#0099FF")
        self.start_am_button = Button(self.bframe, command=self.start_miner, text ='Start Auto-Mining',
                                      height=1, width=15, bg='black', fg="#00CC00")
        self.hide_script_button = Button(self.bframe, command=self.hide_script, text ='Hide Script',
                                        height=1, width=12, bg='black', fg="gray")
        self.hide_miner_button = Button(self.bframe, command=self.hide_miner, text ='Hide Miner',
                                      height=1, width=12, bg='black', fg="gray")
        self.refresh_button = Button(self.bframe, command=self.MinerBot.refresh, text ='Refresh Hm/s',
                                      height=1, width=15, bg='black', fg="red")
        self.magnify_button = Button(self.bframe, command=self.set_panelwindow, text ="Magnify'",
                                                                        height=1, width=15, bg='black', fg="yellow")
        self.start_ar_button.grid(row=0, column=2)
        self.start_am_button.grid(row=1, column=2)
        self.hide_script_button.grid(row=1, column=0)
        self.hide_miner_button.grid(row=0, column=0)
        self.refresh_button.grid(row=1, column=1)
        self.magnify_button.grid(row=0, column=1)

        self.apply_loop_sec_button = Button(self.lfs_sec, command=self.bind_loop_sec, text ='Apply',
                                      height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_hlimit_button = Button(self.lfs_hlimit, command=self.bind_hlimit, text ='Apply',
                                            height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_nbcheck_button = Button(self.lfs_nbcheck, command=self.bind_nbcheck, text ='Apply',
                                          height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_wait_button = Button(self.lfs_wait, command=self.bind_wait, text ='Apply',
                                           height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_bwait_button = Button(self.lfs_bwait, command=self.bind_bwait, text ='Apply',
                                        height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_reload_button = Button(self.lfs_reload, command=self.bind_reload, text ='Apply',
                                         height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_restart_button = Button(self.lfs_restart, command=self.bind_restart, text ='Apply',
                                          height=1, width=13, bg='black', fg="#00CC00", borderwidth=1)
        self.apply_loop_sec_button.pack(side=BOTTOM)
        self.apply_hlimit_button.pack(side=BOTTOM)
        self.apply_nbcheck_button.pack(side=BOTTOM)
        self.apply_wait_button.pack(side=BOTTOM)
        self.apply_bwait_button.pack(side=BOTTOM)
        self.apply_reload_button.pack(side=BOTTOM)
        self.apply_restart_button.pack(side=BOTTOM)

    def set_labelframe(self):
        self.lfs = LabelFrame(self.f, text="Settings:", borderwidth=0, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.lfs.place(relx=0.0, rely=0.40, anchor='w')

        self.lfs_sec = LabelFrame(self.lfs, text="Secs b/w loops:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_hlimit = LabelFrame(self.lfs, text="Limit Mh/s:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_nbcheck = LabelFrame(self.lfs, text="Nb checks:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_wait = LabelFrame(self.lfs, text="Secs b/w checks:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_bwait = LabelFrame(self.lfs, text="Secs after reload:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_reload = LabelFrame(self.lfs, text="Check \\b reload:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_restart = LabelFrame(self.lfs, text="Reload \\b restart:", borderwidth=1, bg='black', fg="#00CC00")
        self.lfs_sec.pack(side=TOP)
        self.lfs_hlimit.pack(side=TOP)
        self.lfs_nbcheck.pack(side=TOP)
        self.lfs_wait.pack(side=TOP)
        self.lfs_bwait.pack(side=TOP)
        self.lfs_reload.pack(side=TOP)
        self.lfs_restart.pack(side=TOP)

        self.lfi = LabelFrame(self.f, text="Mining's Values:", borderwidth=0, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.lfi.place(relx=0.0, rely=0.06, anchor='w')

        self.lfip = LabelFrame(self.lfi, text="Pool's Values", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.lfip.pack(side=LEFT)

        self.lfip_hr = LabelFrame(self.lfip, text="Mh/s", bg='black', fg="#0099FF")
        self.lfip_h1 = LabelFrame(self.lfip, text="Mh/s last hour", bg='black', fg="#FF3333")
        self.lfip_h3 = LabelFrame(self.lfip, text="Mh/s last 3h", bg='black', fg="#FF3333")
        self.lfip_h6 = LabelFrame(self.lfip, text="Mh/s last 6h", bg='black', fg="#FF3333")
        self.lfip_h12 = LabelFrame(self.lfip, text="Mh/s last 12h", bg='black', fg="#FF3333")
        self.lfip_h24 = LabelFrame(self.lfip, text="Mh/s last 24h", bg='black', fg="#FF3333")
        self.lfip_etc = LabelFrame(self.lfip, text="Balance ETC", bg='black', fg="#00CC00")
        self.lfip_rate = LabelFrame(self.lfip, text="Rate Per Month", bg='black', fg="yellow")
        self.lfip_rate_e = LabelFrame(self.lfip, text="Rate Per Month (EUR)", bg='black', fg="yellow")
        self.lfip_hr.pack(side=LEFT)
        self.lfip_h1.pack(side=LEFT)
        self.lfip_h3.pack(side=LEFT)
        self.lfip_h6.pack(side=LEFT)
        self.lfip_h12.pack(side=LEFT)
        self.lfip_h24.pack(side=LEFT)
        self.lfip_etc.pack(side=LEFT)
        self.lfip_rate.pack(side=LEFT)
        self.lfip_rate_e.pack(side=LEFT)

        self.lfia = LabelFrame(self.lfi, text="Account's Values", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.lfia.pack(side=LEFT, padx=5)

        self.lfia_bal = LabelFrame(self.lfia, text="Balance (ETC)", bg='black', fg="green")
        self.lfia_bale = LabelFrame(self.lfia, text="Balance (EUR)", bg='black', fg="green")
        self.lfia_bal.pack(side=LEFT)
        self.lfia_bale.pack(side=LEFT)

        self.bframe = LabelFrame(self.f, text="Controls:", borderwidth=0, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.bframe.place(relx=0.37, rely=0.92, anchor='w')

        self.finfo = LabelFrame(self.f, text="Settings Values:", borderwidth=0, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.finfo.place(relx=0.92, rely=0.35, anchor='w')
        self.fi_check = LabelFrame(self.finfo, text="Checks:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_sec = LabelFrame(self.finfo, text="Secs b/w loops:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_hlimit = LabelFrame(self.finfo, text="Limit Mh\s:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_nbcheck = LabelFrame(self.finfo, text="Nb checks:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_wait = LabelFrame(self.finfo, text="Secs b/w checks:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_bwait = LabelFrame(self.finfo, text="Secs after reload:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_reload = LabelFrame(self.finfo, text="Check \\b reload:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_restart = LabelFrame(self.finfo, text="Reload \\b restart:", borderwidth=1, relief=GROOVE, bg='black', fg="#C0C0C0")
        self.fi_check.pack(side=TOP)
        self.fi_sec.pack(side=TOP)
        self.fi_hlimit.pack(side=TOP)
        self.fi_nbcheck.pack(side=TOP)
        self.fi_wait.pack(side=TOP)
        self.fi_bwait.pack(side=TOP)
        self.fi_reload.pack(side=TOP)
        self.fi_restart.pack(side=TOP)

    def set_label(self):
        self.llf_hr = Label(self.lfip_hr, text="Null", bg='black', fg="#0099FF", width=10)
        self.llf_h1 = Label(self.lfip_h1, text="Null", bg='black', fg="#FF3333", width=10)
        self.llf_h3 = Label(self.lfip_h3, text="Null", bg='black', fg="#FF3333", width=10)
        self.llf_h6 = Label(self.lfip_h6, text="Null", bg='black', fg="#FF3333", width=10)
        self.llf_h12 = Label(self.lfip_h12, text="Null", bg='black', fg="#FF3333", width=10)
        self.llf_h24 = Label(self.lfip_h24, text="Null", bg='black', fg="#FF3333", width=10)
        self.llf_etc = Label(self.lfip_etc, text="Null", bg='black', fg="#00CC00", width=15)
        self.llf_rate = Label(self.lfip_rate, text="Null", bg='black', fg="yellow", width=17)
        self.llf_rate_e = Label(self.lfip_rate_e, text="Null", bg='black', fg="#0099FF", width=18)
        self.llf_bal = Label(self.lfia_bal, text="Null", bg='black', fg="#0099FF", width=20)
        self.llf_bale = Label(self.lfia_bale, text="Null", bg='black', fg="#0099FF", width=20)
        self.llf_hr.pack()
        self.llf_h1.pack()
        self.llf_h3.pack()
        self.llf_h6.pack()
        self.llf_h12.pack()
        self.llf_h24.pack()
        self.llf_etc.pack()
        self.llf_rate.pack()
        self.llf_rate_e.pack()
        self.llf_bal.pack()
        self.image1 = Image.open("./img/ethereum_ico.png")
        self.photo1 = ImageTk.PhotoImage(self.image1)
        self.li1 = Label(self.lfi, image=self.photo1, bg='black')
        self.li1.pack(ipadx=10, ipady=5)
        self.llf_bale.pack()

        self.llfi_check = Label(self.fi_check, text=self.check, bg='black', fg="#FF3333", width=13)
        self.llfi_sec = Label(self.fi_sec, text=self.time_loop, bg='black', fg="#0099FF", width=13)
        self.llfi_hlimit = Label(self.fi_hlimit, text=self.hlimit, bg='black', fg="#FF3333", width=13)
        self.llfi_nbcheck = Label(self.fi_nbcheck, text=self.nbcheck, bg='black', fg="#FF3333", width=13)
        self.llfi_wait = Label(self.fi_wait, text=self.wait, bg='black', fg="#FF3333", width=13)
        self.llfi_bwait = Label(self.fi_bwait, text=self.bwait, bg='black', fg="#FF3333", width=13)
        self.llfi_reload = Label(self.fi_reload, text=self.reload, bg='black', fg="#FF3333", width=13)
        self.llfi_restart = Label(self.fi_restart, text=self.restart, bg='black', fg="#FF3333", width=13)
        self.llfi_check.pack()
        self.llfi_sec.pack()
        self.llfi_hlimit.pack()
        self.llfi_nbcheck.pack()
        self.llfi_wait.pack()
        self.llfi_bwait.pack()
        self.llfi_reload.pack()
        self.llfi_restart.pack()

    def set_entry(self):
        self.entry_sleep = Entry(self.lfs_sec, bg='#303030', fg="#00CC00", width=15)
        self.entry_hlimit = Entry(self.lfs_hlimit, bg='#303030', fg="#00CC00", width=15)
        self.entry_nbcheck = Entry(self.lfs_nbcheck, bg='#303030', fg="#00CC00", width=15)
        self.entry_wait = Entry(self.lfs_wait, bg='#303030', fg="#00CC00", width=15)
        self.entry_bwait = Entry(self.lfs_bwait, bg='#303030', fg="#00CC00", width=15)
        self.entry_reload = Entry(self.lfs_reload, bg='#303030', fg="#00CC00", width=15)
        self.entry_restart = Entry(self.lfs_restart, bg='#303030', fg="#00CC00", width=15)
        self.entry_sleep.pack()
        self.entry_hlimit.pack()
        self.entry_nbcheck.pack()
        self.entry_wait.pack()
        self.entry_bwait.pack()
        self.entry_reload.pack()
        self.entry_restart.pack()

    def set_panelwindow(self):
        autoit.win_set_state(MINER, autoit.properties.SW_SHOW)
        autoit.win_set_state(MINER, autoit.properties.SW_RESTORE)
        autoit.win_move(MINER, x=109, y=137, width=1061, height=516)
        autoit.win_activate(MINER)

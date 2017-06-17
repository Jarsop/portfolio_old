from cx_Freeze import setup, Executable
import os

# On appelle la fonction setup
os.environ['TCL_LIBRARY'] = r'C:\Users\jpges\AppData\Local\Programs\Python\Python36-32\tcl\tcl8.6'
os.environ['TK_LIBRARY'] = r'C:\Users\jpges\AppData\Local\Programs\Python\Python36-32\tcl\tk8.6'

setup(
    name = "AutEthMining",
    version = "1",
    description = "AutoBot Miner for Ether",
    executables = [Executable("run.py")],
)
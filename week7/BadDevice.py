from m5.params import *
from Device import BasicPioDevice

class BadDevice(BasicPioDevice):
    type = 'HelloDevice'
    cxx_header = "dev/hellodev.hh"
    devicename = Param.String("DeviceName")

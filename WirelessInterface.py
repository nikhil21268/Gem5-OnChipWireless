# WirelessInterface.py

from m5.params import *
from m5.proxy import *
from MemObject import MemObject

class WirelessInterface(MemObject):
    type = 'WirelessInterface'
    cxx_header = "mem/WirelessInterface.hh"

    bandwidth = Param.Int(100, "Bandwidth in bits per cycle")
    serialization_latency = Param.Latency('1ns', "Serialization latency")
    deserialization_latency = Param.Latency('1ns', "Deserialization latency")
    modulation_latency = Param.Latency('1ns', "Modulation latency")
    demodulation_latency = Param.Latency('1ns', "Demodulation latency")
    mac_protocol = Param.String("TokenPassing", "MAC protocol (TokenPassing or ExponentialBackoff)")
    transceiver_id = Param.Int(0, "Unique ID for the transceiver")
    initial_backoff_window = Param.Int(16, "Initial backoff window size")
    max_backoff_window = Param.Int(1024, "Maximum backoff window size")

    upper_port = MasterPort("Port to connect to the upper level")
    lower_port = SlavePort("Port to connect to the lower level")

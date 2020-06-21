import cocotb
import csv
from cocotb.triggers import Timer
import scipy.signal
from matplotlib import pyplot as plt
import numpy as np


def q1_152float(num):
    if num > 0x7fff:
        num = num - (1<<16)
    return num / 2**15

def float2q1_15(num):
    return int(round(num * 2**15)) & 0xffff

T = 1/48000
tau = 0.3/2.2
alpha = T/tau
outarr = []

@cocotb.test()
def my_first_test(dut):
    """Try accessing the design."""
    dut._log.info("Making test signals")
    in_array = np.arange(48000)
    rect = 0.9*(np.heaviside(in_array-10000,1)-2*np.heaviside(in_array-34000,1))
    time = in_array*T
    dut._log.info("Running test signal through DUT")
    dut.sample_clk = 1
    dut.alpha = float2q1_15(alpha)+5
    for sample in rect:
        dut.clk = 0
        yield Timer(1,units='ns')
        dut.clk = 1
        dut.signal_in = float2q1_15(sample)
        outarr.append(q1_152float(int(dut.filtered)))
        yield Timer(1,units='ns')

    dut._log.info("Running test signal through golden model")
    golden = scipy.signal.lfilter([alpha],[1,-(1-alpha)],rect)
    dut._log.info("Plotting signals")
    plt.plot(time,rect)
    plt.plot(time,golden)
    plt.plot(time,outarr)
    plt.legend(("Input signal","Golden model output","DUT output"))
    plt.xlabel("Samples")
    plt.ylabel("Amplitude")
    plt.savefig("result.svg")
    dut._log.info("Test done")

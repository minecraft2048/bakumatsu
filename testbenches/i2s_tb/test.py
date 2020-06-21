import cocotb
import csv
from cocotb.triggers import Timer

@cocotb.test()
def my_first_test(dut):
    """Try accessing the design."""

    dut._log.info("Running test!")
    for i in range(1000):
        dut.clk = 0
        yield Timer(1,units='ns')
        dut.clk = 1
        dut.sck_indut.sd_indut.ws_in
        yield Timer(1,units='ns')
    dut._log.info("Running test!")


@cocotb.coroutine
def reset_dut(reset_n, duration):
    with open('qwer') as fd:
        stimulus = csv.reader(fd)
        for sck,sd,ws,*_ in stimulus:
            yield int(sck),int(sd),int(ws)

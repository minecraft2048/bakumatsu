VERILOG_SOURCES = ../../dsp.sv ../../basic_bits.sv
# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file:
TOPLEVEL=ema_filter
# MODULE is the name of the Python test file:
MODULE=test
SIM=verilator
WAVES=1
VERILATOR_TRACE=1
COCOTB_HDL_TIMEPRECISION = 1ns

include $(shell cocotb-config --makefiles)/Makefile.inc
include $(shell cocotb-config --makefiles)/Makefile.sim


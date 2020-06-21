PROJ=gen
TRELLIS?=/usr/share/trellis
SSHADDR=pi@raspberrypi.local

all: ${PROJ}.bit

%.json: %.sv 
	yosys -p "synth_ecp5 -json $@" $<

%_out.config: %.json
	nextpnr-ecp5 --json $< --textcfg $@ --um5g-85k --package CABGA381 --lpf ecp5evn.lpf

%.bit: %_out.config
	ecppack --svf ${PROJ}.svf $< $@

${PROJ}.svf : ${PROJ}.bit

prog: ${PROJ}.svf
	openocd -f ${TRELLIS}/misc/openocd/ecp5-evn.cfg -c "transport select jtag; init; svf $<; exit"

prog-remote: ${PROJ}.svf
	scp ${PROJ}.svf ${SSHADDR}:/home/pi; ssh -t ${SSHADDR} ./upload.sh $<

clean::
	rm -f *.svf *.bit *.config *.json

test_filter: dsp.sv testbenches/dsp_tb/test.py
	cd testbenches/dsp_tb && $(MAKE)
	
.PHONY: prog clean

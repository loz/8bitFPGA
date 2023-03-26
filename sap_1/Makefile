BOARD=tangnano9k
FAMILY=GW1N-9C
DEVICE=GW1NR-LV9QN88PC6/I5

all: out/sap.fs

# Synthesis
out/sap.json: sap.v src/*.v
	yosys -p "read_verilog sap.v; synth_gowin -top sap -json out/sap.json"

# Place and Route
out/sap_pnr.json: out/sap.json
	nextpnr-gowin --json out/sap.json --freq 27 --write out/sap_pnr.json --device ${DEVICE} --family ${FAMILY} --cst ${BOARD}.cst

# Generate Bitstream
out/sap.fs: out/sap_pnr.json tangnano9k.cst
	gowin_pack -d ${FAMILY} -o out/sap.fs out/sap_pnr.json

# Program Board
load: out/sap.fs
	openFPGALoader -b ${BOARD} out/sap.fs

flash:  out/sap.fs
	openFPGALoader -b ${BOARD} out/sap.fs -f

#uart_test.o: uart.v uart_tb.v
#	iverilog -o uart_test.o -s test uart.v uart_tb.v

#test: uart_test.o
#	vvp uart_test.o

# Cleanup build artifacts
clean:
	rm out/*

.PHONY: load clean test
.INTERMEDIATE: out/sap_pnr.json out/sap.json
BOARD=tangnano9k
FAMILY=GW1N-9C
DEVICE=GW1NR-LV9QN88PC6/I5

all: top.fs

# Synthesis
top.json: top.v *.v
	yosys -p "read_verilog top.v; synth_gowin -top top -json top.json"

# Place and Route
top_pnr.json: top.json *.cst
	nextpnr-gowin --json top.json --freq 27 --write top_pnr.json --device ${DEVICE} --family ${FAMILY} --cst ${BOARD}.cst

# Generate Bitstream
top.fs: top_pnr.json
	gowin_pack -d ${FAMILY} -o top.fs top_pnr.json

#Tests
test: display.v display_tb.v
	iverilog -o display.o -s test display_tb.v
	vvp display.o

# Program Board
load: top.fs
	openFPGALoader -b ${BOARD} top.fs

flash: top.fs
	openFPGALoader -b ${BOARD} top.fs -f
	
.PHONY: load
.INTERMEDIATE: top_pnr.json top.json

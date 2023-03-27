BOARD=tangnano9k
FAMILY=GW1N-9C
DEVICE=GW1NR-LV9QN88PC6/I5

all: music.fs

# Synthesis
music.json: music.v
	yosys -p "read_verilog music.v; synth_gowin -top music -json music.json"

# Place and Route
music_pnr.json: music.json
	nextpnr-gowin --json music.json --freq 27 --write music_pnr.json --device ${DEVICE} --family ${FAMILY} --cst ${BOARD}.cst

# Generate Bitstream
music.fs: music_pnr.json
	gowin_pack -d ${FAMILY} -o music.fs music_pnr.json

# Program Board
load: music.fs
	openFPGALoader -b ${BOARD} music.fs

flash: music.fs
	openFPGALoader -b ${BOARD} music.fs -f
	
.PHONY: load
.INTERMEDIATE: music_pnr.json music.json
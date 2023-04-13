VFLAGS = -O3 --x-assign fast --x-initial fast --noassert
SDL_CFLAGS = `sdl2-config --cflags`
SDL_LDFLAGS = `sdl2-config --libs`

top: obj_dir/Vtop.mk
	make -C ./obj_dir -f Vtop.mk

obj_dir/Vtop.mk: top.sv
	verilator ${VFLAGS} -I../lib \
		-cc top.sv --exe main_top.cpp -o top \
		-CFLAGS "${SDL_CFLAGS}" -LDFLAGS "${SDL_LDFLAGS}"

all: top

clean:
	rm -rf ./obj_dir

.PHONY: all clean

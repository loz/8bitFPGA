#include <stdio.h>
#include <SDL.h>
#include <verilated.h>
#include "Vtop.h"

// screen dimensions
const int H_RES = 1024;
const int V_RES = 600;

typedef struct Pixel {  // for SDL texture
    uint8_t a;  // transparency
    uint8_t b;  // blue
    uint8_t g;  // green
    uint8_t r;  // red
} Pixel;

int main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL init failed.\n");
        return 1;
    }

    Pixel screenbuffer[H_RES*V_RES];

    SDL_Window*   sdl_window   = NULL;
    SDL_Renderer* sdl_renderer = NULL;
    SDL_Texture*  sdl_texture  = NULL;

    sdl_window = SDL_CreateWindow("FPGA", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, H_RES, V_RES, SDL_WINDOW_SHOWN);
    if (!sdl_window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sdl_renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
    if (!sdl_texture) {
        printf("Texture creation failed: %s\n", SDL_GetError());
        return 1;
    }

    // reference SDL keyboard state array: https://wiki.libsdl.org/SDL_GetKeyboardState
    const Uint8 *keyb_state = SDL_GetKeyboardState(NULL);

    printf("Simulation running. Press 'Q' in simulation window to quit.\n\n");

    // initialize Verilog module
    Vtop* top = new Vtop;

    // reset
    for(int r=0; r<8; r++) {
        top->rst_pix = 1;
        top->clk_pix = 0;
        top->eval();
        top->clk_pix = 1;
        top->eval();
    }
    top->rst_pix = 0;
    top->clk_pix = 0;
    top->eval();

    // initialize frame rate
    uint64_t start_ticks = SDL_GetPerformanceCounter();
    uint64_t frame_count = 0;

    // main loop
    //#define __DEBUG_CLOCKS_
    #ifdef __DEBUG_CLOCKS_
        for(int t=0; t<100; t++) {
    #else
        while (1) {
    #endif
        // cycle the clock
        top->clk_pix = 1;
        top->eval();
        top->clk_pix = 0;
        top->eval();

        if(top->tapaddress == 0x8000) {
            printf("Reset Vector Hit 0x8000, Data(%02x)\n", top->data);
        }

        #ifdef __DEBUG_CLOCKS_
        printf("Tick: (%04x) [%02x] %s\n", top->tapaddress, top->data, (top->rw == 0 ? "r" : "w"));
        #endif
        // update pixel if not in blanking interval
        if (top->sdl_de) {
            //printf("DisplayVisible\n");
            Pixel* p = &screenbuffer[top->sdl_sy*H_RES + top->sdl_sx];
            p->a = 0xFF;  // transparency
            p->b = top->sdl_b;
            p->g = top->sdl_g;
            p->r = top->sdl_r;
        }
        //if(top->irqtap == 1) {
        //    printf("Tick: (%04x) [%02x] IRQ?: %s\n", top->tapaddress, top->data, (top->irqtap == 0 ? "N" : "Y"));
        //}

        // update texture once per frame (in blanking)
        if (top->sdl_sy == 0 && top->sdl_sx == 0) {
            SDL_UpdateTexture(sdl_texture, NULL, screenbuffer, H_RES*sizeof(Pixel));
            SDL_RenderClear(sdl_renderer);
            SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
            SDL_RenderPresent(sdl_renderer);
            frame_count++;

            // UART Keypress simulation
            SDL_Event e;
            if (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    break;
                } else if (e.type == SDL_KEYDOWN) {
                    //printf("Key Pressed, %02x (%s)\n", e.key.keysym.scancode, SDL_GetKeyName(e.key.keysym.sym));
                    switch(e.key.keysym.scancode) {
                        case SDL_SCANCODE_BACKSPACE:
                            top->sdl_uart_byte = 0x7f;
                            break;
                        case SDL_SCANCODE_SPACE:
                            top->sdl_uart_byte = 0x20;
                            break;
                        case SDL_SCANCODE_RETURN:
                            top->sdl_uart_byte = 0x0d;
                            break;
                        default:
                            top->sdl_uart_byte = SDL_GetKeyName(e.key.keysym.sym)[0];
                    }
                    top->sdl_uart_byte_ready = 1;
                    top->clk_pix = 1;
                    top->eval();
                    //printf("Tick: (%04x) [%02x] IRQ?: %s\n", top->tapaddress, top->data, (top->irqtap == 0 ? "N" : "Y"));
                    top->clk_pix = 0;
                    top->eval();
                    //printf("Tick: (%04x) [%02x] IRQ?: %s\n", top->tapaddress, top->data, (top->irqtap == 0 ? "N" : "Y"));
                    top->sdl_uart_byte_ready = 0;
                }
            }
        }
    }

    // calculate frame rate
    uint64_t end_ticks = SDL_GetPerformanceCounter();
    double duration = ((double)(end_ticks-start_ticks))/SDL_GetPerformanceFrequency();
    double fps = (double)frame_count/duration;
    printf("Frames per second: %.1f\n", fps);

    top->final();  // simulation done

    SDL_DestroyTexture(sdl_texture);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    return 0;
}

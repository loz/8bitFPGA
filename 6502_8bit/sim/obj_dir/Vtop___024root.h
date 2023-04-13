// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_pix,0,0);
    VL_IN8(rst_pix,0,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_frame,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    CData/*0:0*/ top__DOT__de;
    CData/*0:0*/ top__DOT__frame;
    CData/*3:0*/ top__DOT__paint_r;
    CData/*3:0*/ top__DOT__paint_g;
    CData/*3:0*/ top__DOT__paint_b;
    CData/*7:0*/ top__DOT__ppu__DOT____Vlvbound_h8536dfbd__0;
    CData/*7:0*/ top__DOT__ppu__DOT____Vlvbound_h6786e09c__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk_pix;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(sdl_sx,11,0);
    VL_OUT16(sdl_sy,11,0);
    SData/*11:0*/ top__DOT__sx;
    SData/*11:0*/ top__DOT__sy;
    SData/*11:0*/ top__DOT__display_inst__DOT__x;
    SData/*11:0*/ top__DOT__display_inst__DOT__y;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 2368> top__DOT__ppu__DOT__text_buffer;
    VlUnpacked<SData/*8:0*/, 800> top__DOT__ppu__DOT__font_map__DOT__charmap;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

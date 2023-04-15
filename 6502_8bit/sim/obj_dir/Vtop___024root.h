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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_pix,0,0);
        VL_IN8(rst_pix,0,0);
        VL_OUT8(sdl_de,0,0);
        VL_OUT8(sdl_frame,0,0);
        VL_OUT8(sdl_r,7,0);
        VL_OUT8(sdl_g,7,0);
        VL_OUT8(sdl_b,7,0);
        VL_IN8(sdl_uart_byte,7,0);
        VL_IN8(sdl_uart_byte_ready,0,0);
        VL_OUT8(data,7,0);
        VL_OUT8(rw,0,0);
        VL_OUT8(irqtap,0,0);
        CData/*7:0*/ top__DOT__data_in;
        CData/*7:0*/ top__DOT__data_out;
        CData/*0:0*/ top__DOT__write_enable;
        CData/*0:0*/ top__DOT__de;
        CData/*0:0*/ top__DOT__frame;
        CData/*3:0*/ top__DOT__paint_r;
        CData/*3:0*/ top__DOT__paint_g;
        CData/*3:0*/ top__DOT__paint_b;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__ABL;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__ABH;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__ADD;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__IRHOLD;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__IRHOLD_valid;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__C;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__Z;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__I;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__D;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__V;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__N;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__AN;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__HC;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__AI;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__IR;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__CO;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__NMI_edge;
        CData/*1:0*/ top__DOT__cpu_6502__DOT__regsel;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__P;
        CData/*5:0*/ top__DOT__cpu_6502__DOT__state;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__PC_inc;
        CData/*1:0*/ top__DOT__cpu_6502__DOT__src_reg;
        CData/*1:0*/ top__DOT__cpu_6502__DOT__dst_reg;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__index_y;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__load_reg;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__inc;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__write_back;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__load_only;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__store;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__adc_sbc;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__compare;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__shift;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__rotate;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__backwards;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__cond_true;
        CData/*2:0*/ top__DOT__cpu_6502__DOT__cond_code;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__shift_right;
        CData/*3:0*/ top__DOT__cpu_6502__DOT__op;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__adc_bcd;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__adj_bcd;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__bit_ins;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__plp;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__php;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__clc;
    };
    struct {
        CData/*0:0*/ top__DOT__cpu_6502__DOT__sec;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__cld;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__sed;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__cli;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__sei;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__clv;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__res;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__write_register;
        CData/*0:0*/ top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__AI7;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__BI7;
        CData/*7:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI;
        CData/*4:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp_h;
        CData/*0:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp_HC;
        CData/*0:0*/ top__DOT__umapper__DOT__byte_ready;
        CData/*5:0*/ __Vdly__top__DOT__cpu_6502__DOT__state;
        CData/*0:0*/ __Vtrigrprev__TOP__clk_pix;
        CData/*0:0*/ __Vtrigrprev__TOP__rst_pix;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(sdl_sx,11,0);
        VL_OUT16(sdl_sy,11,0);
        VL_OUT16(tapaddress,15,0);
        SData/*15:0*/ top__DOT__address_bus;
        SData/*11:0*/ top__DOT__sx;
        SData/*11:0*/ top__DOT__sy;
        SData/*15:0*/ top__DOT__cpu_6502__DOT__PC;
        SData/*15:0*/ top__DOT__cpu_6502__DOT__PC_temp;
        SData/*8:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp;
        SData/*11:0*/ top__DOT__display_inst__DOT__x;
        SData/*11:0*/ top__DOT__display_inst__DOT__y;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 4> top__DOT__cpu_6502__DOT__AXYS;
        VlUnpacked<CData/*7:0*/, 8192> top__DOT__rom0__DOT__memory;
        VlUnpacked<CData/*7:0*/, 8192> top__DOT__ram__DOT__memory;
        VlUnpacked<SData/*8:0*/, 800> top__DOT__ppu__DOT__font_map__DOT__charmap;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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

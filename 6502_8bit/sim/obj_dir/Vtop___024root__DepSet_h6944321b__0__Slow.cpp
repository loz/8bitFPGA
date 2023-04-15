// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->top__DOT__cpu_6502__DOT__C = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__Z = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__I = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__D = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__V = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__N = 0U;
    vlSelf->top__DOT__cpu_6502__DOT__NMI_edge = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk_pix = vlSelf->clk_pix;
    vlSelf->__Vtrigrprev__TOP__rst_pix = vlSelf->rst_pix;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_hd9fed8bb__0;
    VlWide<4>/*127:0*/ __Vtemp_h3f974f67__0;
    // Body
    __Vtemp_hd9fed8bb__0[0U] = 0x2e6d656dU;
    __Vtemp_hd9fed8bb__0[1U] = 0x72656e74U;
    __Vtemp_hd9fed8bb__0[2U] = 0x2f637572U;
    __Vtemp_hd9fed8bb__0[3U] = 0x726f6d73U;
    __Vtemp_hd9fed8bb__0[4U] = 0x2e2e2fU;
    VL_READMEM_N(true, 8, 8192, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hd9fed8bb__0)
                 ,  &(vlSelf->top__DOT__rom0__DOT__memory)
                 , 0, ~0ULL);
    __Vtemp_h3f974f67__0[0U] = 0x2e6d656dU;
    __Vtemp_h3f974f67__0[1U] = 0x666f6e74U;
    __Vtemp_h3f974f67__0[2U] = 0x7265732fU;
    __Vtemp_h3f974f67__0[3U] = 0x2e2e2fU;
    VL_READMEM_N(false, 9, 800, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h3f974f67__0)
                 ,  &(vlSelf->top__DOT__ppu__DOT__font_map__DOT__charmap)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_hf63381f3_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hdb9aaec7_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hd12ab508_0;
extern const VlUnpacked<CData/*0:0*/, 8192> Vtop__ConstPool__TABLE_h85b28cba_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vtop__ConstPool__TABLE_h660d6bfa_0;
extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_hc0459796_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h990428e9_0;
extern const VlUnpacked<CData/*3:0*/, 2> Vtop__ConstPool__TABLE_h1a6a251c_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ top__DOT__cpu_6502__DOT__BI;
    top__DOT__cpu_6502__DOT__BI = 0;
    CData/*0:0*/ top__DOT__cpu_6502__DOT__CI;
    top__DOT__cpu_6502__DOT__CI = 0;
    CData/*7:0*/ top__DOT__cpu_6502__DOT__regfile;
    top__DOT__cpu_6502__DOT__regfile = 0;
    CData/*0:0*/ top__DOT__cpu_6502__DOT__alu_shift_right;
    top__DOT__cpu_6502__DOT__alu_shift_right = 0;
    CData/*3:0*/ top__DOT__cpu_6502__DOT__alu_op;
    top__DOT__cpu_6502__DOT__alu_op = 0;
    SData/*8:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic;
    top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic = 0;
    CData/*4:0*/ top__DOT__cpu_6502__DOT__ALU__DOT__temp_l;
    top__DOT__cpu_6502__DOT__ALU__DOT__temp_l = 0;
    SData/*8:0*/ top__DOT__ppu__DOT__char;
    top__DOT__ppu__DOT__char = 0;
    SData/*9:0*/ top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0;
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0 = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*6:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    SData/*10:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    SData/*10:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    SData/*12:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*6:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    CData/*0:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    // Body
    __Vtableidx3 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__plp) 
                     << 7U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_reg) 
                                << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)));
    vlSelf->top__DOT__cpu_6502__DOT__write_register 
        = Vtop__ConstPool__TABLE_hf63381f3_0[__Vtableidx3];
    vlSelf->top__DOT__cpu_6502__DOT__IR = ((((~ (IData)(vlSelf->top__DOT__cpu_6502__DOT__I)) 
                                             & (IData)(vlSelf->top__DOT__umapper__DOT__byte_ready)) 
                                            | (IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge))
                                            ? 0U : 
                                           ((IData)(vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid)
                                             ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__IRHOLD)
                                             : (IData)(vlSelf->top__DOT__data_in)));
    __Vtableidx8 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__N) 
                     << 6U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__V) 
                                << 5U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__C) 
                                           << 4U) | 
                                          (((IData)(vlSelf->top__DOT__cpu_6502__DOT__Z) 
                                            << 3U) 
                                           | (IData)(vlSelf->top__DOT__cpu_6502__DOT__cond_code)))));
    vlSelf->top__DOT__cpu_6502__DOT__cond_true = Vtop__ConstPool__TABLE_hdb9aaec7_0
        [__Vtableidx8];
    vlSelf->top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD 
        = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_bcd) 
           & (0xdU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)));
    __Vtableidx2 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__store) 
                     << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state));
    vlSelf->top__DOT__write_enable = Vtop__ConstPool__TABLE_hd12ab508_0
        [__Vtableidx2];
    top__DOT__ppu__DOT__char = ((0x25U <= (0x3fU & 
                                           VL_DIVS_III(32, 
                                                       (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                        >> 1U), (IData)(8U))))
                                 ? 0x20U : vlSelf->top__DOT__ram__DOT__memory
                                [(0x1fffU & ((IData)(0x1000U) 
                                             + ((0xfc0U 
                                                 & (VL_DIVS_III(32, 
                                                                (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                                 >> 1U), (IData)(8U)) 
                                                    << 6U)) 
                                                + (0x7fU 
                                                   & VL_DIVS_III(32, 
                                                                 (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                                  >> 1U), (IData)(8U))))))]);
    vlSelf->top__DOT__cpu_6502__DOT__P = (0x30U | (
                                                   ((IData)(vlSelf->top__DOT__cpu_6502__DOT__N) 
                                                    << 7U) 
                                                   | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__V) 
                                                       << 6U) 
                                                      | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__D) 
                                                          << 3U) 
                                                         | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__I) 
                                                             << 2U) 
                                                            | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__Z) 
                                                                << 1U) 
                                                               | (IData)(vlSelf->top__DOT__cpu_6502__DOT__C)))))));
    vlSelf->irqtap = vlSelf->top__DOT__umapper__DOT__byte_ready;
    top__DOT__cpu_6502__DOT__alu_shift_right = (((0xdU 
                                                  == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                                                 | ((0x24U 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                                                    | (0x23U 
                                                       == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) 
                                                & (IData)(vlSelf->top__DOT__cpu_6502__DOT__shift_right));
    __Vtableidx6 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_only) 
                     << 0xcU) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__compare) 
                                  << 0xbU) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO) 
                                               << 0xaU) 
                                              | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__inc) 
                                                  << 9U) 
                                                 | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__shift) 
                                                     << 8U) 
                                                    | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__C) 
                                                        << 7U) 
                                                       | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__rotate) 
                                                           << 6U) 
                                                          | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))))))));
    top__DOT__cpu_6502__DOT__CI = Vtop__ConstPool__TABLE_h85b28cba_0
        [__Vtableidx6];
    __Vtableidx4 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__dst_reg) 
                     << 9U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__index_y) 
                                << 8U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__src_reg) 
                                           << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))));
    vlSelf->top__DOT__cpu_6502__DOT__regsel = Vtop__ConstPool__TABLE_h660d6bfa_0
        [__Vtableidx4];
    __Vtableidx5 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__backwards) 
                     << 0xaU) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__op) 
                                  << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)));
    top__DOT__cpu_6502__DOT__alu_op = Vtop__ConstPool__TABLE_hc0459796_0
        [__Vtableidx5];
    vlSelf->rw = vlSelf->top__DOT__write_enable;
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0 
        = (0x3ffU & ((0xff8U & (((0x20U > (IData)(top__DOT__ppu__DOT__char))
                                  ? ((0U == (IData)(top__DOT__ppu__DOT__char))
                                      ? 1U : 0U) : 
                                 ((IData)(top__DOT__ppu__DOT__char) 
                                  - (IData)(0x1fU))) 
                                << 3U)) + (0x1ffU & 
                                           VL_MODDIVS_III(32, 
                                                          (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                           >> 1U), (IData)(8U)))));
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__backwards) 
                     << 0xaU) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO) 
                                  << 9U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge) 
                                             << 8U) 
                                            | (((IData)(vlSelf->irqtap) 
                                                << 7U) 
                                               | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__I) 
                                                   << 6U) 
                                                  | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))))));
    vlSelf->top__DOT__cpu_6502__DOT__PC_inc = Vtop__ConstPool__TABLE_h990428e9_0
        [__Vtableidx1];
    top__DOT__cpu_6502__DOT__regfile = vlSelf->top__DOT__cpu_6502__DOT__AXYS
        [vlSelf->top__DOT__cpu_6502__DOT__regsel];
    if ((0x20U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((0x10U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            top__DOT__cpu_6502__DOT__BI = (0xffU & (IData)(vlSelf->top__DOT__data_in));
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
            vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
            if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__ADD;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else {
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
            }
        } else if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & (IData)(vlSelf->top__DOT__data_in));
                if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                        vlSelf->top__DOT__data_out 
                            = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                        vlSelf->top__DOT__address_bus 
                            = vlSelf->top__DOT__data_in;
                    } else {
                        vlSelf->top__DOT__data_out 
                            = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                        vlSelf->top__DOT__address_bus 
                            = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                                << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL));
                    }
                } else {
                    vlSelf->top__DOT__data_out = (0xffU 
                                                  & (IData)(top__DOT__cpu_6502__DOT__regfile));
                    vlSelf->top__DOT__address_bus = 
                        ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                          ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)
                          : (0x100U | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)));
                }
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else {
                if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                        vlSelf->top__DOT__address_bus 
                            = (0x100U | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                        vlSelf->top__DOT__cpu_6502__DOT__AI 
                            = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    } else {
                        vlSelf->top__DOT__address_bus 
                            = (0x100U | (IData)(top__DOT__cpu_6502__DOT__regfile));
                        vlSelf->top__DOT__cpu_6502__DOT__AI 
                            = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                    }
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__address_bus = 
                        ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                          ? (((IData)(vlSelf->top__DOT__data_in) 
                              << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                          : (0x100U | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
            }
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                    ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)
                    : ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                        ? (((IData)(vlSelf->top__DOT__data_in) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                        : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
        } else {
            if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & 0U);
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    vlSelf->top__DOT__address_bus = 
                        (0x100U | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                } else {
                    vlSelf->top__DOT__address_bus = 
                        ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                          ? (0x100U | (IData)(top__DOT__cpu_6502__DOT__regfile))
                          : (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                              << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL)));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                }
            } else if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & 0U);
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    vlSelf->top__DOT__data_out = (0xffU 
                                                  & (IData)(top__DOT__cpu_6502__DOT__regfile));
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__data_in));
                } else {
                    vlSelf->top__DOT__data_out = (0xffU 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__php)
                                                      ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__P)
                                                      : (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)));
                    vlSelf->top__DOT__address_bus = 
                        (0x100U | (IData)(top__DOT__cpu_6502__DOT__regfile));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                }
            } else {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
            }
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
        }
    } else if ((0x10U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                }
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__address_bus = ((2U 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 
                                                  (0x100U 
                                                   | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                                                   : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC))
                                                  : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
            } else if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & 0U);
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    vlSelf->top__DOT__data_out = (0xffU 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                    vlSelf->top__DOT__address_bus = 
                        (0x100U | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                } else {
                    vlSelf->top__DOT__data_out = (0xffU 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__PC) 
                                                     >> 8U));
                    vlSelf->top__DOT__address_bus = 
                        (0x100U | (IData)(top__DOT__cpu_6502__DOT__regfile));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                }
            } else {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & (IData)(vlSelf->top__DOT__data_in));
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__address_bus = ((1U 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                  ? 
                                                 (((IData)(vlSelf->top__DOT__data_in) 
                                                   << 8U) 
                                                  | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                                                  : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            }
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                    ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)
                    : ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                        ? (((IData)(vlSelf->top__DOT__data_in) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                        : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
        } else {
            top__DOT__cpu_6502__DOT__BI = (0xffU & (IData)(vlSelf->top__DOT__data_in));
            if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                        vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                            = (((IData)(vlSelf->top__DOT__data_in) 
                                << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                        vlSelf->top__DOT__address_bus 
                            = (((IData)(vlSelf->top__DOT__data_in) 
                                << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    } else {
                        vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                            = vlSelf->top__DOT__cpu_6502__DOT__PC;
                        vlSelf->top__DOT__address_bus 
                            = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    }
                } else {
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    vlSelf->top__DOT__address_bus = 
                        ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                          ? (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                              << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL))
                          : (((IData)(vlSelf->top__DOT__data_in) 
                              << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)));
                }
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else {
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
                if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                        vlSelf->top__DOT__address_bus 
                            = vlSelf->top__DOT__cpu_6502__DOT__ADD;
                        vlSelf->top__DOT__cpu_6502__DOT__AI 
                            = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                    } else {
                        vlSelf->top__DOT__address_bus 
                            = vlSelf->top__DOT__data_in;
                        vlSelf->top__DOT__cpu_6502__DOT__AI 
                            = (0xffU & 0U);
                    }
                } else {
                    vlSelf->top__DOT__address_bus = 
                        ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                          ? (((IData)(vlSelf->top__DOT__data_in) 
                              << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                          : (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
            }
            vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
        }
    } else if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__ADD;
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
                }
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
            } else {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_only)
                                     ? 0U : (IData)(top__DOT__cpu_6502__DOT__regfile)));
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = ((((~ (IData)(vlSelf->top__DOT__cpu_6502__DOT__I)) 
                             & (IData)(vlSelf->irqtap)) 
                            | (IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge))
                            ? (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                                << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL))
                            : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
            }
            vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
        } else if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & (IData)(vlSelf->top__DOT__data_in));
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & 0U);
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__res)
                        ? 0x9ffcU : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge)
                                      ? 0x9ffaU : 0x9ffeU));
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (((IData)(vlSelf->irqtap) 
                                                  | (IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge))
                                                  ? 
                                                 (0xefU 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__P))
                                                  : (IData)(vlSelf->top__DOT__cpu_6502__DOT__P)));
                vlSelf->top__DOT__address_bus = (0x100U 
                                                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
            }
        } else {
            top__DOT__cpu_6502__DOT__BI = (0xffU & 0U);
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
            if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                vlSelf->top__DOT__address_bus = (0x100U 
                                                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
            } else {
                vlSelf->top__DOT__data_out = (0xffU 
                                              & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__PC) 
                                                 >> 8U));
                vlSelf->top__DOT__address_bus = (0x100U 
                                                 | (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
            }
        }
    } else {
        if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                            << 8U) | (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH));
                }
            } else {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                    vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__data_in));
                } else {
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
            }
        } else {
            if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & (IData)(vlSelf->top__DOT__data_in));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                 ? 0U : (IData)(top__DOT__cpu_6502__DOT__regfile)));
            } else {
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & ((1U 
                                                   & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 0U
                                                   : (IData)(vlSelf->top__DOT__data_in)));
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            }
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
            vlSelf->top__DOT__address_bus = ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                              ? (((IData)(vlSelf->top__DOT__data_in) 
                                                  << 8U) 
                                                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                                              : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
        }
        vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
    }
    __Vtableidx9 = ((8U >= (0xfU & ((IData)(7U) - VL_MODDIVS_III(32, 
                                                                 (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                                  >> 1U), (IData)(8U))))) 
                    & (((0x31fU >= (IData)(top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0))
                         ? vlSelf->top__DOT__ppu__DOT__font_map__DOT__charmap
                        [top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0]
                         : 0U) >> (0xfU & ((IData)(7U) 
                                           - VL_MODDIVS_III(32, 
                                                            (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                             >> 1U), (IData)(8U))))));
    vlSelf->top__DOT__paint_r = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx9];
    vlSelf->top__DOT__paint_g = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx9];
    vlSelf->top__DOT__paint_b = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx9];
    vlSelf->tapaddress = vlSelf->top__DOT__address_bus;
    vlSelf->data = ((IData)(vlSelf->top__DOT__write_enable)
                     ? (IData)(vlSelf->top__DOT__data_out)
                     : ((0x8000U & (IData)(vlSelf->top__DOT__address_bus))
                         ? (((0x8000U & (IData)(vlSelf->top__DOT__address_bus))
                              ? 0xffU : 0U) & (((0x8000U 
                                                 & (IData)(vlSelf->top__DOT__address_bus))
                                                 ? 
                                                vlSelf->top__DOT__rom0__DOT__memory
                                                [(0x1fffU 
                                                  & (IData)(vlSelf->top__DOT__address_bus))]
                                                 : 0U) 
                                               & ((0x8000U 
                                                   & (IData)(vlSelf->top__DOT__address_bus))
                                                   ? 0xffU
                                                   : 0U)))
                         : ((0x4000U & (IData)(vlSelf->top__DOT__address_bus))
                             ? (IData)(vlSelf->sdl_uart_byte)
                             : vlSelf->top__DOT__ram__DOT__memory
                            [(0x1fffU & (IData)(vlSelf->top__DOT__address_bus))])));
    top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic = 
        ((2U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
          ? ((1U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
              ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__AI)
              : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                 ^ (IData)(top__DOT__cpu_6502__DOT__BI)))
          : ((1U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
              ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                 & (IData)(top__DOT__cpu_6502__DOT__BI))
              : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                 | (IData)(top__DOT__cpu_6502__DOT__BI))));
    if (top__DOT__cpu_6502__DOT__alu_shift_right) {
        top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic 
            = ((0x100U & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                          << 8U)) | (((IData)(top__DOT__cpu_6502__DOT__CI) 
                                      << 7U) | (0x7fU 
                                                & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                                                   >> 1U))));
    }
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI 
        = (0xffU & ((8U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
                     ? ((4U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
                         ? 0U : (IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic))
                     : ((4U & (IData)(top__DOT__cpu_6502__DOT__alu_op))
                         ? (~ (IData)(top__DOT__cpu_6502__DOT__BI))
                         : (IData)(top__DOT__cpu_6502__DOT__BI))));
    top__DOT__cpu_6502__DOT__ALU__DOT__temp_l = (0x1fU 
                                                 & (((0xfU 
                                                      & (IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic)) 
                                                     + 
                                                     (0xfU 
                                                      & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI))) 
                                                    + 
                                                    ((~ 
                                                      ((IData)(top__DOT__cpu_6502__DOT__alu_shift_right) 
                                                       | (3U 
                                                          == 
                                                          (3U 
                                                           & ((IData)(top__DOT__cpu_6502__DOT__alu_op) 
                                                              >> 2U))))) 
                                                     & (IData)(top__DOT__cpu_6502__DOT__CI))));
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_HC 
        = (1U & (((IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_l) 
                  >> 4U) | ((IData)(vlSelf->top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD) 
                            & (5U <= (7U & ((IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_l) 
                                            >> 1U))))));
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_h 
        = (0x1fU & ((((IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_logic) 
                      >> 4U) + (0xfU & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI) 
                                        >> 4U))) + (IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_HC)));
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp 
        = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_h) 
            << 4U) | (0xfU & (IData)(top__DOT__cpu_6502__DOT__ALU__DOT__temp_l)));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_pix)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk_pix or posedge rst_pix)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge clk_pix)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_pix)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk_pix or posedge rst_pix)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge clk_pix)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_pix = 0;
    vlSelf->rst_pix = 0;
    vlSelf->sdl_sx = 0;
    vlSelf->sdl_sy = 0;
    vlSelf->sdl_de = 0;
    vlSelf->sdl_frame = 0;
    vlSelf->sdl_r = 0;
    vlSelf->sdl_g = 0;
    vlSelf->sdl_b = 0;
    vlSelf->sdl_uart_byte = 0;
    vlSelf->sdl_uart_byte_ready = 0;
    vlSelf->tapaddress = 0;
    vlSelf->data = 0;
    vlSelf->rw = 0;
    vlSelf->irqtap = 0;
    vlSelf->top__DOT__address_bus = 0;
    vlSelf->top__DOT__data_in = 0;
    vlSelf->top__DOT__data_out = 0;
    vlSelf->top__DOT__write_enable = 0;
    vlSelf->top__DOT__sx = 0;
    vlSelf->top__DOT__sy = 0;
    vlSelf->top__DOT__de = 0;
    vlSelf->top__DOT__frame = 0;
    vlSelf->top__DOT__paint_r = 0;
    vlSelf->top__DOT__paint_g = 0;
    vlSelf->top__DOT__paint_b = 0;
    vlSelf->top__DOT__cpu_6502__DOT__PC = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ABL = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ABH = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ADD = 0;
    vlSelf->top__DOT__cpu_6502__DOT__IRHOLD = 0;
    vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__cpu_6502__DOT__AXYS[__Vi0] = 0;
    }
    vlSelf->top__DOT__cpu_6502__DOT__C = 0;
    vlSelf->top__DOT__cpu_6502__DOT__Z = 0;
    vlSelf->top__DOT__cpu_6502__DOT__I = 0;
    vlSelf->top__DOT__cpu_6502__DOT__D = 0;
    vlSelf->top__DOT__cpu_6502__DOT__V = 0;
    vlSelf->top__DOT__cpu_6502__DOT__N = 0;
    vlSelf->top__DOT__cpu_6502__DOT__AN = 0;
    vlSelf->top__DOT__cpu_6502__DOT__HC = 0;
    vlSelf->top__DOT__cpu_6502__DOT__AI = 0;
    vlSelf->top__DOT__cpu_6502__DOT__IR = 0;
    vlSelf->top__DOT__cpu_6502__DOT__CO = 0;
    vlSelf->top__DOT__cpu_6502__DOT__NMI_edge = 0;
    vlSelf->top__DOT__cpu_6502__DOT__regsel = 0;
    vlSelf->top__DOT__cpu_6502__DOT__P = 0;
    vlSelf->top__DOT__cpu_6502__DOT__state = 0;
    vlSelf->top__DOT__cpu_6502__DOT__PC_inc = 0;
    vlSelf->top__DOT__cpu_6502__DOT__PC_temp = 0;
    vlSelf->top__DOT__cpu_6502__DOT__src_reg = 0;
    vlSelf->top__DOT__cpu_6502__DOT__dst_reg = 0;
    vlSelf->top__DOT__cpu_6502__DOT__index_y = 0;
    vlSelf->top__DOT__cpu_6502__DOT__load_reg = 0;
    vlSelf->top__DOT__cpu_6502__DOT__inc = 0;
    vlSelf->top__DOT__cpu_6502__DOT__write_back = 0;
    vlSelf->top__DOT__cpu_6502__DOT__load_only = 0;
    vlSelf->top__DOT__cpu_6502__DOT__store = 0;
    vlSelf->top__DOT__cpu_6502__DOT__adc_sbc = 0;
    vlSelf->top__DOT__cpu_6502__DOT__compare = 0;
    vlSelf->top__DOT__cpu_6502__DOT__shift = 0;
    vlSelf->top__DOT__cpu_6502__DOT__rotate = 0;
    vlSelf->top__DOT__cpu_6502__DOT__backwards = 0;
    vlSelf->top__DOT__cpu_6502__DOT__cond_true = 0;
    vlSelf->top__DOT__cpu_6502__DOT__cond_code = 0;
    vlSelf->top__DOT__cpu_6502__DOT__shift_right = 0;
    vlSelf->top__DOT__cpu_6502__DOT__op = 0;
    vlSelf->top__DOT__cpu_6502__DOT__adc_bcd = 0;
    vlSelf->top__DOT__cpu_6502__DOT__adj_bcd = 0;
    vlSelf->top__DOT__cpu_6502__DOT__bit_ins = 0;
    vlSelf->top__DOT__cpu_6502__DOT__plp = 0;
    vlSelf->top__DOT__cpu_6502__DOT__php = 0;
    vlSelf->top__DOT__cpu_6502__DOT__clc = 0;
    vlSelf->top__DOT__cpu_6502__DOT__sec = 0;
    vlSelf->top__DOT__cpu_6502__DOT__cld = 0;
    vlSelf->top__DOT__cpu_6502__DOT__sed = 0;
    vlSelf->top__DOT__cpu_6502__DOT__cli = 0;
    vlSelf->top__DOT__cpu_6502__DOT__sei = 0;
    vlSelf->top__DOT__cpu_6502__DOT__clv = 0;
    vlSelf->top__DOT__cpu_6502__DOT__res = 0;
    vlSelf->top__DOT__cpu_6502__DOT__write_register = 0;
    vlSelf->top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__AI7 = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__BI7 = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_h = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp = 0;
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_HC = 0;
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->top__DOT__rom0__DOT__memory[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->top__DOT__ram__DOT__memory[__Vi0] = 0;
    }
    vlSelf->top__DOT__display_inst__DOT__x = 0;
    vlSelf->top__DOT__display_inst__DOT__y = 0;
    for (int __Vi0 = 0; __Vi0 < 800; ++__Vi0) {
        vlSelf->top__DOT__ppu__DOT__font_map__DOT__charmap[__Vi0] = 0;
    }
    vlSelf->top__DOT__umapper__DOT__byte_ready = 0;
    vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state = 0;
    vlSelf->__Vtrigrprev__TOP__clk_pix = 0;
    vlSelf->__Vtrigrprev__TOP__rst_pix = 0;
}

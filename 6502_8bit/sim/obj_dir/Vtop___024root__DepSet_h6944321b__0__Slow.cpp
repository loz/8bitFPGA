// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk_pix = vlSelf->clk_pix;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ top__DOT__ppu__DOT__unnamedblk1__DOT__i;
    top__DOT__ppu__DOT__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ top__DOT__ppu__DOT__unnamedblk2__DOT__i;
    top__DOT__ppu__DOT__unnamedblk2__DOT__i = 0;
    VlWide<4>/*127:0*/ __Vtemp_h3f974f67__0;
    // Body
    top__DOT__ppu__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x940U, top__DOT__ppu__DOT__unnamedblk1__DOT__i)) {
        vlSelf->top__DOT__ppu__DOT____Vlvbound_h8536dfbd__0 = 0x20U;
        if (VL_LIKELY((0x93fU >= (0xfffU & top__DOT__ppu__DOT__unnamedblk1__DOT__i)))) {
            vlSelf->top__DOT__ppu__DOT__text_buffer[(0xfffU 
                                                     & top__DOT__ppu__DOT__unnamedblk1__DOT__i)] 
                = vlSelf->top__DOT__ppu__DOT____Vlvbound_h8536dfbd__0;
        }
        top__DOT__ppu__DOT__unnamedblk1__DOT__i = ((IData)(1U) 
                                                   + top__DOT__ppu__DOT__unnamedblk1__DOT__i);
    }
    vlSelf->top__DOT__ppu__DOT__text_buffer[0U] = 0x54U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[1U] = 0x68U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[2U] = 0x69U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[3U] = 0x73U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[4U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[5U] = 0x69U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[6U] = 0x73U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[7U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[8U] = 0x61U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[9U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xaU] = 0x6dU;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xbU] = 0x65U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xcU] = 0x73U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xdU] = 0x73U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xeU] = 0x61U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0xfU] = 0x67U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x10U] = 0x65U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x11U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x12U] = 0x69U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x13U] = 0x6eU;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x14U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x15U] = 0x74U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x16U] = 0x68U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x17U] = 0x65U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x18U] = 0x20U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x19U] = 0x62U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1aU] = 0x75U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1bU] = 0x66U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1cU] = 0x66U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1dU] = 0x65U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1eU] = 0x72U;
    vlSelf->top__DOT__ppu__DOT__text_buffer[0x1fU] = 0x21U;
    top__DOT__ppu__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x64U, top__DOT__ppu__DOT__unnamedblk2__DOT__i)) {
        vlSelf->top__DOT__ppu__DOT____Vlvbound_h6786e09c__0 
            = (0xffU & ((IData)(0x1eU) + top__DOT__ppu__DOT__unnamedblk2__DOT__i));
        if (VL_LIKELY((0x93fU >= (0xfffU & ((IData)(0x50U) 
                                            + top__DOT__ppu__DOT__unnamedblk2__DOT__i))))) {
            vlSelf->top__DOT__ppu__DOT__text_buffer[(0xfffU 
                                                     & ((IData)(0x50U) 
                                                        + top__DOT__ppu__DOT__unnamedblk2__DOT__i))] 
                = vlSelf->top__DOT__ppu__DOT____Vlvbound_h6786e09c__0;
        }
        top__DOT__ppu__DOT__unnamedblk2__DOT__i = ((IData)(1U) 
                                                   + top__DOT__ppu__DOT__unnamedblk2__DOT__i);
    }
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
                VL_FATAL_MT("top.sv", 5, "", "Settle region did not converge.");
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

extern const VlUnpacked<CData/*3:0*/, 2> Vtop__ConstPool__TABLE_h1a6a251c_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ top__DOT__ppu__DOT__char;
    top__DOT__ppu__DOT__char = 0;
    SData/*11:0*/ top__DOT__ppu__DOT____VdfgTmp_hb3489696__0;
    top__DOT__ppu__DOT____VdfgTmp_hb3489696__0 = 0;
    SData/*9:0*/ top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0;
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0 = 0;
    CData/*0:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    top__DOT__ppu__DOT____VdfgTmp_hb3489696__0 = (0xfffU 
                                                  & ((0xfc0U 
                                                      & (VL_DIVS_III(32, 
                                                                     (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                                      >> 1U), (IData)(8U)) 
                                                         << 6U)) 
                                                     + 
                                                     (0x7fU 
                                                      & VL_DIVS_III(32, 
                                                                    (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                                     >> 1U), (IData)(8U)))));
    top__DOT__ppu__DOT__char = ((0x25U <= (0x3fU & 
                                           VL_DIVS_III(32, 
                                                       (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                        >> 1U), (IData)(8U))))
                                 ? 0x20U : ((0x93fU 
                                             >= (IData)(top__DOT__ppu__DOT____VdfgTmp_hb3489696__0))
                                             ? vlSelf->top__DOT__ppu__DOT__text_buffer
                                            [top__DOT__ppu__DOT____VdfgTmp_hb3489696__0]
                                             : 0U));
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0 
        = (0x3ffU & ((((0x20U > (IData)(top__DOT__ppu__DOT__char))
                        ? 0U : (0x1ffU & ((IData)(top__DOT__ppu__DOT__char) 
                                          - (IData)(0x1fU)))) 
                      << 3U) + (0x1ffU & VL_MODDIVS_III(32, 
                                                        (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sy)) 
                                                         >> 1U), (IData)(8U)))));
    __Vtableidx1 = ((8U >= (0xfU & ((IData)(7U) - VL_MODDIVS_III(32, 
                                                                 (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                                  >> 1U), (IData)(8U))))) 
                    & (((0x31fU >= (IData)(top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0))
                         ? vlSelf->top__DOT__ppu__DOT__font_map__DOT__charmap
                        [top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0]
                         : 0U) >> (0xfU & ((IData)(7U) 
                                           - VL_MODDIVS_III(32, 
                                                            (VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__sx)) 
                                                             >> 1U), (IData)(8U))))));
    vlSelf->top__DOT__paint_r = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx1];
    vlSelf->top__DOT__paint_g = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx1];
    vlSelf->top__DOT__paint_b = Vtop__ConstPool__TABLE_h1a6a251c_0
        [__Vtableidx1];
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
    vlSelf->top__DOT__sx = 0;
    vlSelf->top__DOT__sy = 0;
    vlSelf->top__DOT__de = 0;
    vlSelf->top__DOT__frame = 0;
    vlSelf->top__DOT__paint_r = 0;
    vlSelf->top__DOT__paint_g = 0;
    vlSelf->top__DOT__paint_b = 0;
    vlSelf->top__DOT__display_inst__DOT__x = 0;
    vlSelf->top__DOT__display_inst__DOT__y = 0;
    for (int __Vi0 = 0; __Vi0 < 2368; ++__Vi0) {
        vlSelf->top__DOT__ppu__DOT__text_buffer[__Vi0] = 0;
    }
    vlSelf->top__DOT__ppu__DOT____Vlvbound_h8536dfbd__0 = 0;
    vlSelf->top__DOT__ppu__DOT____Vlvbound_h6786e09c__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 800; ++__Vi0) {
        vlSelf->top__DOT__ppu__DOT__font_map__DOT__charmap[__Vi0] = 0;
    }
    vlSelf->__Vtrigrprev__TOP__clk_pix = 0;
}

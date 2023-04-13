// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*3:0*/, 2> Vtop__ConstPool__TABLE_h1a6a251c_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ top__DOT__ppu__DOT__char;
    top__DOT__ppu__DOT__char = 0;
    SData/*11:0*/ top__DOT__ppu__DOT____VdfgTmp_hb3489696__0;
    top__DOT__ppu__DOT____VdfgTmp_hb3489696__0 = 0;
    SData/*9:0*/ top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0;
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_hd891c823__0 = 0;
    CData/*0:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*11:0*/ __Vdly__top__DOT__display_inst__DOT__y;
    __Vdly__top__DOT__display_inst__DOT__y = 0;
    SData/*11:0*/ __Vdly__top__DOT__display_inst__DOT__x;
    __Vdly__top__DOT__display_inst__DOT__x = 0;
    // Body
    __Vdly__top__DOT__display_inst__DOT__x = vlSelf->top__DOT__display_inst__DOT__x;
    __Vdly__top__DOT__display_inst__DOT__y = vlSelf->top__DOT__display_inst__DOT__y;
    if ((0x3ffU == VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x)))) {
        __Vdly__top__DOT__display_inst__DOT__y = ((0x257U 
                                                   == 
                                                   VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y)))
                                                   ? 0U
                                                   : 
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      VL_EXTENDS_II(12,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y)))));
        __Vdly__top__DOT__display_inst__DOT__x = 0U;
    } else {
        __Vdly__top__DOT__display_inst__DOT__x = (0xfffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     VL_EXTENDS_II(12,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x))));
    }
    vlSelf->sdl_b = (0xffU & (((IData)(vlSelf->top__DOT__paint_b) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_b)));
    vlSelf->sdl_g = (0xffU & (((IData)(vlSelf->top__DOT__paint_g) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_g)));
    vlSelf->sdl_r = (0xffU & (((IData)(vlSelf->top__DOT__paint_r) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_r)));
    vlSelf->sdl_frame = vlSelf->top__DOT__frame;
    vlSelf->sdl_de = vlSelf->top__DOT__de;
    vlSelf->sdl_sx = vlSelf->top__DOT__sx;
    vlSelf->sdl_sy = vlSelf->top__DOT__sy;
    vlSelf->top__DOT__frame = ((0U == VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y))) 
                               & (0U == VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x))));
    vlSelf->top__DOT__de = (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y))) 
                            & VL_LTES_III(32, 0U, VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x))));
    vlSelf->top__DOT__sx = vlSelf->top__DOT__display_inst__DOT__x;
    vlSelf->top__DOT__sy = vlSelf->top__DOT__display_inst__DOT__y;
    if (vlSelf->rst_pix) {
        __Vdly__top__DOT__display_inst__DOT__y = 0U;
        __Vdly__top__DOT__display_inst__DOT__x = 0U;
        vlSelf->top__DOT__frame = 0U;
        vlSelf->top__DOT__de = 0U;
        vlSelf->top__DOT__sx = 0U;
        vlSelf->top__DOT__sy = 0U;
    }
    vlSelf->top__DOT__display_inst__DOT__x = __Vdly__top__DOT__display_inst__DOT__x;
    vlSelf->top__DOT__display_inst__DOT__y = __Vdly__top__DOT__display_inst__DOT__y;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top.sv", 5, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 5, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_pix & 0xfeU))) {
        Verilated::overWidthError("clk_pix");}
    if (VL_UNLIKELY((vlSelf->rst_pix & 0xfeU))) {
        Verilated::overWidthError("rst_pix");}
}
#endif  // VL_DEBUG

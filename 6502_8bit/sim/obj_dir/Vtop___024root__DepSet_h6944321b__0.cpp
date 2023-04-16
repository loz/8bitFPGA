// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
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
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*0:0*/, 16384> Vtop__ConstPool__TABLE_h866597a0_0;
extern const VlUnpacked<CData/*3:0*/, 16384> Vtop__ConstPool__TABLE_haa5f2d86_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*13:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__cpu_6502__DOT__AXYS__v0;
    __Vdlyvdim0__top__DOT__cpu_6502__DOT__AXYS__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__cpu_6502__DOT__AXYS__v0;
    __Vdlyvval__top__DOT__cpu_6502__DOT__AXYS__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu_6502__DOT__AXYS__v0;
    __Vdlyvset__top__DOT__cpu_6502__DOT__AXYS__v0 = 0;
    SData/*11:0*/ __Vdly__top__DOT__display_inst__DOT__y;
    __Vdly__top__DOT__display_inst__DOT__y = 0;
    SData/*11:0*/ __Vdly__top__DOT__display_inst__DOT__x;
    __Vdly__top__DOT__display_inst__DOT__x = 0;
    CData/*0:0*/ __Vdly__top__DOT__umapper__DOT__byte_ready;
    __Vdly__top__DOT__umapper__DOT__byte_ready = 0;
    // Body
    __Vdly__top__DOT__display_inst__DOT__x = vlSelf->top__DOT__display_inst__DOT__x;
    __Vdly__top__DOT__display_inst__DOT__y = vlSelf->top__DOT__display_inst__DOT__y;
    __Vdly__top__DOT__umapper__DOT__byte_ready = vlSelf->top__DOT__umapper__DOT__byte_ready;
    __Vdlyvset__top__DOT__cpu_6502__DOT__AXYS__v0 = 0U;
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
    if (((IData)(vlSelf->sdl_uart_byte_ready) & (~ (IData)(vlSelf->top__DOT__umapper__DOT__byte_ready)))) {
        __Vdly__top__DOT__umapper__DOT__byte_ready = 1U;
    } else if ((((IData)(vlSelf->top__DOT__write_enable) 
                 & ((IData)(vlSelf->top__DOT__address_bus) 
                    >> 0xeU)) & (IData)(vlSelf->top__DOT__umapper__DOT__byte_ready))) {
        __Vdly__top__DOT__umapper__DOT__byte_ready = 0U;
    }
    if (((IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge) 
         & (0xbU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->top__DOT__cpu_6502__DOT__NMI_edge = 0U;
    }
    if (vlSelf->top__DOT__cpu_6502__DOT__write_register) {
        __Vdlyvval__top__DOT__cpu_6502__DOT__AXYS__v0 
            = ((0x1aU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? (IData)(vlSelf->top__DOT__data_in)
                : ((0xf0U & ((((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                               >> 4U) + ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adj_bcd)
                                          ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_bcd)
                                              ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO)
                                                  ? 6U
                                                  : 0U)
                                              : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO)
                                                  ? 0U
                                                  : 0xaU))
                                          : 0U)) << 4U)) 
                   | (0xfU & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                              + ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adj_bcd)
                                  ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_bcd)
                                      ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__HC)
                                          ? 6U : 0U)
                                      : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__HC)
                                          ? 0U : 0xaU))
                                  : 0U)))));
        __Vdlyvset__top__DOT__cpu_6502__DOT__AXYS__v0 = 1U;
        __Vdlyvdim0__top__DOT__cpu_6502__DOT__AXYS__v0 
            = vlSelf->top__DOT__cpu_6502__DOT__regsel;
    }
    vlSelf->sdl_b = (0xffU & (((IData)(vlSelf->top__DOT__paint_b) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_b)));
    vlSelf->sdl_g = (0xffU & (((IData)(vlSelf->top__DOT__paint_g) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_g)));
    vlSelf->sdl_r = (0xffU & (((IData)(vlSelf->top__DOT__paint_r) 
                               << 4U) | (IData)(vlSelf->top__DOT__paint_r)));
    vlSelf->sdl_frame = vlSelf->top__DOT__frame;
    vlSelf->sdl_de = vlSelf->top__DOT__de;
    vlSelf->top__DOT__cpu_6502__DOT__cond_code = (7U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__IR) 
                                                     >> 5U));
    vlSelf->sdl_sx = vlSelf->top__DOT__sx;
    vlSelf->sdl_sy = vlSelf->top__DOT__sy;
    vlSelf->top__DOT__cpu_6502__DOT__PC = (0xffffU 
                                           & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__PC_temp) 
                                              + (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC_inc)));
    if ((((((0x21U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
            & (0x22U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
           & (0x1eU != (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
          & (0x1fU != (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
         & (0x20U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->top__DOT__cpu_6502__DOT__ABL = (0xffU 
                                                & (IData)(vlSelf->top__DOT__address_bus));
        vlSelf->top__DOT__cpu_6502__DOT__ABH = (0xffU 
                                                & ((IData)(vlSelf->top__DOT__address_bus) 
                                                   >> 8U));
    }
    __Vtableidx7 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__IR) 
                     << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state));
    if (Vtop__ConstPool__TABLE_h866597a0_0[__Vtableidx7]) {
        vlSelf->top__DOT__cpu_6502__DOT__op = Vtop__ConstPool__TABLE_haa5f2d86_0
            [__Vtableidx7];
    }
    if ((1U & (~ (IData)(vlSelf->rst_pix)))) {
        if (((0x1eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
             | (0x21U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
            vlSelf->top__DOT__cpu_6502__DOT__IRHOLD 
                = vlSelf->top__DOT__data_in;
        }
    }
    if ((0xbU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__I = 1U;
    } else if ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__I = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 2U));
    } else if ((0x24U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if (vlSelf->top__DOT__cpu_6502__DOT__sei) {
            vlSelf->top__DOT__cpu_6502__DOT__I = 1U;
        }
        if (vlSelf->top__DOT__cpu_6502__DOT__cli) {
            vlSelf->top__DOT__cpu_6502__DOT__I = 0U;
        }
    } else if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if (vlSelf->top__DOT__cpu_6502__DOT__plp) {
            vlSelf->top__DOT__cpu_6502__DOT__I = (1U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                                                     >> 2U));
        }
    }
    if ((0x2eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__Z = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)))));
        vlSelf->top__DOT__cpu_6502__DOT__N = vlSelf->top__DOT__cpu_6502__DOT__AN;
    } else if ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__Z = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 1U));
        vlSelf->top__DOT__cpu_6502__DOT__N = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 7U));
    } else if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if (vlSelf->top__DOT__cpu_6502__DOT__plp) {
            vlSelf->top__DOT__cpu_6502__DOT__Z = (1U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                                                     >> 1U));
            vlSelf->top__DOT__cpu_6502__DOT__N = (1U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                                                     >> 7U));
        } else {
            if (((((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_reg) 
                   & (1U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__regsel))) 
                  | (IData)(vlSelf->top__DOT__cpu_6502__DOT__compare)) 
                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__bit_ins))) {
                vlSelf->top__DOT__cpu_6502__DOT__Z 
                    = (1U & (~ (IData)((0U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD)))));
            }
            if ((((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_reg) 
                  & (1U != (IData)(vlSelf->top__DOT__cpu_6502__DOT__regsel))) 
                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__compare))) {
                vlSelf->top__DOT__cpu_6502__DOT__N 
                    = vlSelf->top__DOT__cpu_6502__DOT__AN;
            }
        }
    } else if (((0xdU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                & (IData)(vlSelf->top__DOT__cpu_6502__DOT__bit_ins))) {
        vlSelf->top__DOT__cpu_6502__DOT__N = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 7U));
    }
    if (((IData)(vlSelf->top__DOT__cpu_6502__DOT__shift) 
         & (0x2eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->top__DOT__cpu_6502__DOT__C = vlSelf->top__DOT__cpu_6502__DOT__CO;
    } else if ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__C = (1U & (IData)(vlSelf->top__DOT__data_in));
    } else if (((~ (IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back)) 
                & (0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        if ((((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_sbc) 
              | (IData)(vlSelf->top__DOT__cpu_6502__DOT__shift)) 
             | (IData)(vlSelf->top__DOT__cpu_6502__DOT__compare))) {
            vlSelf->top__DOT__cpu_6502__DOT__C = vlSelf->top__DOT__cpu_6502__DOT__CO;
        } else if (vlSelf->top__DOT__cpu_6502__DOT__plp) {
            vlSelf->top__DOT__cpu_6502__DOT__C = (1U 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
        } else {
            if (vlSelf->top__DOT__cpu_6502__DOT__sec) {
                vlSelf->top__DOT__cpu_6502__DOT__C = 1U;
            }
            if (vlSelf->top__DOT__cpu_6502__DOT__clc) {
                vlSelf->top__DOT__cpu_6502__DOT__C = 0U;
            }
        }
    }
    if ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__V = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 6U));
    } else if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if (vlSelf->top__DOT__cpu_6502__DOT__adc_sbc) {
            vlSelf->top__DOT__cpu_6502__DOT__V = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__AI7) 
                                                  ^ 
                                                  ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__BI7) 
                                                   ^ 
                                                   ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AN) 
                                                    ^ (IData)(vlSelf->top__DOT__cpu_6502__DOT__CO))));
        }
        if (vlSelf->top__DOT__cpu_6502__DOT__clv) {
            vlSelf->top__DOT__cpu_6502__DOT__V = 0U;
        }
        if (vlSelf->top__DOT__cpu_6502__DOT__plp) {
            vlSelf->top__DOT__cpu_6502__DOT__V = (1U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                                                     >> 6U));
        }
    } else if (((0xdU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                & (IData)(vlSelf->top__DOT__cpu_6502__DOT__bit_ins))) {
        vlSelf->top__DOT__cpu_6502__DOT__V = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 6U));
    }
    vlSelf->top__DOT__umapper__DOT__byte_ready = __Vdly__top__DOT__umapper__DOT__byte_ready;
    if (__Vdlyvset__top__DOT__cpu_6502__DOT__AXYS__v0) {
        vlSelf->top__DOT__cpu_6502__DOT__AXYS[__Vdlyvdim0__top__DOT__cpu_6502__DOT__AXYS__v0] 
            = __Vdlyvval__top__DOT__cpu_6502__DOT__AXYS__v0;
    }
    vlSelf->irqtap = vlSelf->top__DOT__umapper__DOT__byte_ready;
    vlSelf->top__DOT__cpu_6502__DOT__HC = vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_HC;
    vlSelf->top__DOT__cpu_6502__DOT__adj_bcd = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_sbc) 
                                                & (IData)(vlSelf->top__DOT__cpu_6502__DOT__D));
    if (((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
         | (8U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->top__DOT__cpu_6502__DOT__adc_bcd = 
            ((0x61U == (0xe3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
             & (IData)(vlSelf->top__DOT__cpu_6502__DOT__D));
    }
    if ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__D = (1U & 
                                              ((IData)(vlSelf->top__DOT__data_in) 
                                               >> 3U));
    } else if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if (vlSelf->top__DOT__cpu_6502__DOT__sed) {
            vlSelf->top__DOT__cpu_6502__DOT__D = 1U;
        }
        if (vlSelf->top__DOT__cpu_6502__DOT__cld) {
            vlSelf->top__DOT__cpu_6502__DOT__D = 0U;
        }
        if (vlSelf->top__DOT__cpu_6502__DOT__plp) {
            vlSelf->top__DOT__cpu_6502__DOT__D = (1U 
                                                  & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                                                     >> 3U));
        }
    }
    if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__php = (8U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__shift_right 
            = (0x42U == (0xc3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)));
        vlSelf->top__DOT__cpu_6502__DOT__rotate = (
                                                   (0x2aU 
                                                    == 
                                                    (0xafU 
                                                     & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                                   | (0x26U 
                                                      == 
                                                      (0xa7U 
                                                       & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__inc = ((0xe6U 
                                                 == 
                                                 (0xe7U 
                                                  & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                                | (0xc8U 
                                                   == 
                                                   (0xdfU 
                                                    & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__index_y = 
            (((0x11U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
              | (0x96U == (0xd7U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
             | (9U == (0xfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__src_reg = 
            ((0xbaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
              ? 1U : (((((0x86U == (0xe7U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                         | (0x8aU == (0xebU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                        | (0xe0U == (0xf3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                       | (0xcaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                       ? 2U : (((((0x84U == (0xe7U 
                                             & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                  | (0x98U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                 | (0xc0U == (0xf3U 
                                              & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                                | (0x88U == (0xbfU 
                                             & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))
                                ? 3U : 0U)));
        vlSelf->top__DOT__cpu_6502__DOT__dst_reg = 
            ((((0xe8U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)) 
               | (0xcaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
              | (0xa2U == (0xe3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))
              ? 2U : (((8U == (0xbfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                       | (0x9aU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                       ? 1U : ((((0x88U == (0xbfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                 | (0xa4U == (0xe7U 
                                              & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                                | (0xa0U == (0xf7U 
                                             & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))
                                ? 3U : 0U)));
        vlSelf->top__DOT__cpu_6502__DOT__load_only 
            = (0xa0U == (0xe0U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)));
        vlSelf->top__DOT__cpu_6502__DOT__sei = (0x78U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__cli = (0x58U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__load_reg = 
            (((((((((0xaU == (0x9fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                    | (1U == (0x83U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                   | (0x88U == (0xedU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                  | (0xa0U == (0xf1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                 | (0xbaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                | (0xb4U == (0xf5U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
               | (0xcaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
              | (0xa1U == (0xa3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
             | (8U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__clv = (0xb8U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__bit_ins = 
            (0x24U == (0xf7U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)));
        vlSelf->top__DOT__cpu_6502__DOT__sec = (0x38U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__clc = (0x18U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__shift = ((6U 
                                                   == 
                                                   (0x87U 
                                                    & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                                  | (0xaU 
                                                     == 
                                                     (0x8fU 
                                                      & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__compare = 
            (((0xc0U == (0xdbU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
              | (0xccU == (0xdfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
             | (0xc1U == (0xe3U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__sed = (0xf8U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__cld = (0xd8U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
        vlSelf->top__DOT__cpu_6502__DOT__plp = (0x28U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR));
    }
    if (((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
         | (8U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->top__DOT__cpu_6502__DOT__adc_sbc = 
            (0x61U == (0x63U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)));
    }
    vlSelf->top__DOT__frame = ((0U == VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y))) 
                               & (0U == VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x))));
    vlSelf->top__DOT__de = (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__y))) 
                            & VL_LTES_III(32, 0U, VL_EXTENDS_II(32,12, (IData)(vlSelf->top__DOT__display_inst__DOT__x))));
    vlSelf->top__DOT__sx = vlSelf->top__DOT__display_inst__DOT__x;
    vlSelf->top__DOT__sy = vlSelf->top__DOT__display_inst__DOT__y;
    if (vlSelf->rst_pix) {
        __Vdly__top__DOT__display_inst__DOT__y = 0U;
        __Vdly__top__DOT__display_inst__DOT__x = 0U;
        vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid = 0U;
        vlSelf->top__DOT__cpu_6502__DOT__res = 1U;
        vlSelf->top__DOT__frame = 0U;
        vlSelf->top__DOT__de = 0U;
        vlSelf->top__DOT__sx = 0U;
        vlSelf->top__DOT__sy = 0U;
    } else {
        if (((0x1eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
             | (0x21U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
            vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid = 1U;
        } else if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid = 0U;
        }
        if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            vlSelf->top__DOT__cpu_6502__DOT__res = 0U;
        }
    }
    vlSelf->top__DOT__cpu_6502__DOT__AN = (1U & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp) 
                                                 >> 7U));
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__BI7 
        = (1U & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_BI) 
                 >> 7U));
    vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__AI7 
        = (1U & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__AI) 
                 >> 7U));
    vlSelf->top__DOT__display_inst__DOT__x = __Vdly__top__DOT__display_inst__DOT__x;
    vlSelf->top__DOT__display_inst__DOT__y = __Vdly__top__DOT__display_inst__DOT__y;
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
    vlSelf->top__DOT__cpu_6502__DOT__ADD = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*12:0*/ __Vdlyvdim0__top__DOT__ram__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__ram__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__memory__v0;
    __Vdlyvval__top__DOT__ram__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__memory__v0;
    __Vdlyvset__top__DOT__ram__DOT__memory__v0 = 0;
    // Body
    __Vdlyvset__top__DOT__ram__DOT__memory__v0 = 0U;
    if (vlSelf->top__DOT__ram_enabled) {
        __Vdlyvval__top__DOT__ram__DOT__memory__v0 
            = vlSelf->data;
        __Vdlyvset__top__DOT__ram__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top__DOT__ram__DOT__memory__v0 
            = (0x1fffU & (IData)(vlSelf->top__DOT__address_bus));
    }
    if (__Vdlyvset__top__DOT__ram__DOT__memory__v0) {
        vlSelf->top__DOT__ram__DOT__memory[__Vdlyvdim0__top__DOT__ram__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__ram__DOT__memory__v0;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
        = vlSelf->top__DOT__cpu_6502__DOT__state;
    if (vlSelf->rst_pix) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state = 8U;
    } else if (((((((((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (0x2fU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0x30U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0x31U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (1U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (2U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (3U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if (((((((((0U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)) 
                       | (0x20U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                      | (0x2cU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                     | (0x40U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                    | (0x4cU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                   | (0x60U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                  | (0x6cU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                 | (8U == (0xbfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))) {
                vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
                    = ((0U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                        ? 8U : ((0x20U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                 ? 0x1aU : ((0x2cU 
                                             == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                             ? 0U : 
                                            ((0x40U 
                                              == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                              ? 0x25U
                                              : ((0x4cU 
                                                  == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                                  ? 0x16U
                                                  : 
                                                 ((0x60U 
                                                   == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                                   ? 0x2aU
                                                   : 
                                                  ((0x6cU 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))
                                                    ? 0x18U
                                                    : 0x21U)))))));
            } else if (((((((((0x28U == (0xbfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                              | (0x18U == (0x9fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                             | (0x80U == (0x9dU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                            | (0x8cU == (0x9fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                           | (0x88U == (0x8fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                          | (1U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                         | (4U == (0x1cU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                        | (9U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))) {
                vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
                    = ((0x28U == (0xbfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                        ? 0x1eU : ((0x18U == (0x9fU 
                                              & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                    ? 0x24U : ((0x80U 
                                                == 
                                                (0x9dU 
                                                 & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                ? 0xdU
                                                : (
                                                   (0x8cU 
                                                    == 
                                                    (0x9fU 
                                                     & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                    ? 0U
                                                    : 
                                                   ((0x88U 
                                                     == 
                                                     (0x8fU 
                                                      & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                     ? 0x24U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                      ? 0xeU
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (0x1cU 
                                                        & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                       ? 0x2fU
                                                       : 0xdU)))))));
            } else if (((((((((0xdU == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                              | (0xeU == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                             | (0x10U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                            | (0x11U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                           | (0x14U == (0x1cU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                          | (0x19U == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                         | (0x1cU == (0x1cU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))) 
                        | (0xaU == (0xfU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))))) {
                vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
                    = ((0xdU == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                        ? 0U : ((0xeU == (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                 ? 0U : ((0x10U == 
                                          (0x1fU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                          ? 5U : ((0x11U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                   ? 0x12U
                                                   : 
                                                  ((0x14U 
                                                    == 
                                                    (0x1cU 
                                                     & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                    ? 0x30U
                                                    : 
                                                   ((0x19U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                     ? 2U
                                                     : 
                                                    ((0x1cU 
                                                      == 
                                                      (0x1cU 
                                                       & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR)))
                                                      ? 2U
                                                      : 0x24U)))))));
            }
        } else {
            vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
                = ((0x2fU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                    ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back)
                        ? 0x23U : 0xdU) : ((0x30U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                            ? 0x31U
                                            : ((0x31U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back)
                                                    ? 0x23U
                                                    : 0xdU)
                                                : (
                                                   (0U 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 1U
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 
                                                    ((IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back)
                                                      ? 0x23U
                                                      : 0xdU)
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                      ? 3U
                                                      : 
                                                     ((((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO) 
                                                        | (IData)(vlSelf->top__DOT__cpu_6502__DOT__store)) 
                                                       | (IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back))
                                                       ? 4U
                                                       : 0xdU)))))));
        }
    } else if (((((((((4U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (0xeU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0xfU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0x10U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0x11U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (0x12U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (0x13U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (0x14U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
            = ((4U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? ((IData)(vlSelf->top__DOT__cpu_6502__DOT__write_back)
                    ? 0x23U : 0xdU) : ((0xeU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                        ? 0xfU : ((0xfU 
                                                   == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 0x10U
                                                   : 
                                                  ((0x10U 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 0x11U
                                                    : 
                                                   ((0x11U 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 0xdU
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                      ? 0x13U
                                                      : 
                                                     ((0x13U 
                                                       == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                       ? 0x14U
                                                       : 
                                                      (((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO) 
                                                        | (IData)(vlSelf->top__DOT__cpu_6502__DOT__store))
                                                        ? 0x15U
                                                        : 0xdU))))))));
    } else if (((((((((0x15U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (0x23U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0x2eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0xdU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0x24U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (0x21U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (0x22U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (0x1eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
            = ((0x15U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? 0xdU : ((0x23U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                           ? 0x2eU : ((0x2eU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                       ? 0xdU : ((0xdU 
                                                  == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                  ? 0xcU
                                                  : 
                                                 ((0x24U 
                                                   == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 0xcU
                                                   : 
                                                  ((0x21U 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 0x22U
                                                    : 
                                                   ((0x22U 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 0xcU
                                                     : 0x1fU)))))));
    } else if (((((((((0x1fU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (0x20U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0x1aU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0x1bU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0x1cU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (0x1dU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (0x25U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (0x26U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
            = ((0x1fU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? 0x20U : ((0x20U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                            ? 0xcU : ((0x1aU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                       ? 0x1bU : ((0x1bU 
                                                   == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 0x1cU
                                                   : 
                                                  ((0x1cU 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 0x1dU
                                                    : 
                                                   ((0x1dU 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 0xdU
                                                     : 
                                                    ((0x25U 
                                                      == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                      ? 0x26U
                                                      : 0x27U)))))));
    } else if (((((((((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (0x28U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0x29U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0x2aU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0x2bU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (0x2cU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (0x2dU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (5U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
            = ((0x27U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? 0x28U : ((0x28U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                            ? 0x29U : ((0x29U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                        ? 0xcU : ((0x2aU 
                                                   == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                   ? 0x2bU
                                                   : 
                                                  ((0x2bU 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 0x2cU
                                                    : 
                                                   ((0x2cU 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 0x2dU
                                                     : 
                                                    ((0x2dU 
                                                      == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                      ? 0xdU
                                                      : 
                                                     ((IData)(vlSelf->top__DOT__cpu_6502__DOT__cond_true)
                                                       ? 6U
                                                       : 0xcU))))))));
    } else if (((((((((6U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)) 
                      | (7U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                     | (0x16U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                    | (0x17U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                   | (0x18U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                  | (0x19U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                 | (8U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) 
                | (9U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state 
            = ((6U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                ? (((IData)(vlSelf->top__DOT__cpu_6502__DOT__CO) 
                    ^ (IData)(vlSelf->top__DOT__cpu_6502__DOT__backwards))
                    ? 7U : 0xcU) : ((7U == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                     ? 0xcU : ((0x16U 
                                                == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                ? 0x17U
                                                : (
                                                   (0x17U 
                                                    == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                    ? 0xcU
                                                    : 
                                                   ((0x18U 
                                                     == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                     ? 0x19U
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                      ? 0x16U
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                                       ? 9U
                                                       : 0xaU)))))));
    } else if ((0xaU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state = 0xbU;
    } else if ((0xbU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state = 0x16U;
    }
}

extern const VlUnpacked<CData/*3:0*/, 2> Vtop__ConstPool__TABLE_h1a6a251c_0;

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Init
    SData/*8:0*/ top__DOT__ppu__DOT__char;
    top__DOT__ppu__DOT__char = 0;
    SData/*9:0*/ top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0;
    top__DOT__ppu__DOT__font_map__DOT____VdfgTmp_h88b94275__0 = 0;
    CData/*0:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    // Body
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
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hdb9aaec7_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*6:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    // Body
    __Vtableidx8 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__N) 
                     << 6U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__V) 
                                << 5U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__C) 
                                           << 4U) | 
                                          (((IData)(vlSelf->top__DOT__cpu_6502__DOT__Z) 
                                            << 3U) 
                                           | (IData)(vlSelf->top__DOT__cpu_6502__DOT__cond_code)))));
    vlSelf->top__DOT__cpu_6502__DOT__cond_true = Vtop__ConstPool__TABLE_hdb9aaec7_0
        [__Vtableidx8];
    if ((0xcU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        vlSelf->top__DOT__cpu_6502__DOT__store = ((0x84U 
                                                   == 
                                                   (0xe5U 
                                                    & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
                                                  | (0x81U 
                                                     == 
                                                     (0xe3U 
                                                      & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
        vlSelf->top__DOT__cpu_6502__DOT__write_back 
            = ((6U == (0x87U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))) 
               | (0xc6U == (0xc7U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__IR))));
    }
    vlSelf->top__DOT__cpu_6502__DOT__backwards = (1U 
                                                  & ((IData)(vlSelf->top__DOT__data_in) 
                                                     >> 7U));
    vlSelf->top__DOT__cpu_6502__DOT__CO = (1U & (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp) 
                                                  >> 8U) 
                                                 | ((IData)(vlSelf->top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD) 
                                                    & (5U 
                                                       <= 
                                                       (7U 
                                                        & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__ALU__DOT__temp_h) 
                                                           >> 1U))))));
    if ((1U & (~ (IData)(vlSelf->top__DOT__write_enable)))) {
        vlSelf->top__DOT__data_in = vlSelf->data;
    }
    vlSelf->top__DOT__cpu_6502__DOT__IR = ((((~ (IData)(vlSelf->top__DOT__cpu_6502__DOT__I)) 
                                             & (IData)(vlSelf->top__DOT__umapper__DOT__byte_ready)) 
                                            | (IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge))
                                            ? 0U : 
                                           ((IData)(vlSelf->top__DOT__cpu_6502__DOT__IRHOLD_valid)
                                             ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__IRHOLD)
                                             : (IData)(vlSelf->top__DOT__data_in)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__cpu_6502__DOT__state = vlSelf->__Vdly__top__DOT__cpu_6502__DOT__state;
}

extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_hf63381f3_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h990428e9_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hd12ab508_0;
extern const VlUnpacked<CData/*0:0*/, 8192> Vtop__ConstPool__TABLE_h85b28cba_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vtop__ConstPool__TABLE_h660d6bfa_0;
extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_hc0459796_0;

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
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
    // Body
    __Vtableidx3 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__plp) 
                     << 7U) | (((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_reg) 
                                << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)));
    vlSelf->top__DOT__cpu_6502__DOT__write_register 
        = Vtop__ConstPool__TABLE_hf63381f3_0[__Vtableidx3];
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
    vlSelf->top__DOT__cpu_6502__DOT____Vcellinp__ALU__BCD 
        = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__adc_bcd) 
           & (0xdU == (IData)(vlSelf->top__DOT__cpu_6502__DOT__state)));
    __Vtableidx2 = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__store) 
                     << 6U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__state));
    vlSelf->top__DOT__write_enable = Vtop__ConstPool__TABLE_hd12ab508_0
        [__Vtableidx2];
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
    top__DOT__cpu_6502__DOT__regfile = vlSelf->top__DOT__cpu_6502__DOT__AXYS
        [vlSelf->top__DOT__cpu_6502__DOT__regsel];
    if ((0x20U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((0x10U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
            top__DOT__cpu_6502__DOT__BI = (0xffU & (IData)(vlSelf->top__DOT__data_in));
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
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                    ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)
                    : ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                        ? (((IData)(vlSelf->top__DOT__data_in) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                        : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
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
        } else {
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
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
        }
    } else if ((0x10U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                    ? (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)
                    : ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                        ? (((IData)(vlSelf->top__DOT__data_in) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                        : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
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
        } else {
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
            top__DOT__cpu_6502__DOT__BI = (0xffU & (IData)(vlSelf->top__DOT__data_in));
            vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
        }
    } else if ((8U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
        if ((4U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
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
            } else {
                if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = vlSelf->top__DOT__cpu_6502__DOT__PC;
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & ((IData)(vlSelf->top__DOT__cpu_6502__DOT__load_only)
                                     ? 0U : (IData)(top__DOT__cpu_6502__DOT__regfile)));
                } else {
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = ((((~ (IData)(vlSelf->top__DOT__cpu_6502__DOT__I)) 
                             & (IData)(vlSelf->irqtap)) 
                            | (IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge))
                            ? (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                                << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL))
                            : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                }
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
            }
            vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
        } else if ((2U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
            if ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))) {
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & (IData)(vlSelf->top__DOT__data_in));
                vlSelf->top__DOT__data_out = (0xffU 
                                              & (IData)(top__DOT__cpu_6502__DOT__regfile));
                vlSelf->top__DOT__address_bus = vlSelf->top__DOT__cpu_6502__DOT__PC;
                vlSelf->top__DOT__cpu_6502__DOT__AI 
                    = (0xffU & 0U);
            } else {
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = ((IData)(vlSelf->top__DOT__cpu_6502__DOT__res)
                        ? 0x9ffcU : ((IData)(vlSelf->top__DOT__cpu_6502__DOT__NMI_edge)
                                      ? 0x9ffaU : 0x9ffeU));
                top__DOT__cpu_6502__DOT__BI = (0xffU 
                                               & 0U);
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
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
            top__DOT__cpu_6502__DOT__BI = (0xffU & 0U);
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
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                            << 8U) | (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC)));
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & (IData)(vlSelf->top__DOT__data_in));
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABL));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & 0U);
                } else {
                    vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                        = (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                            << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    top__DOT__cpu_6502__DOT__BI = (0xffU 
                                                   & 0U);
                    vlSelf->top__DOT__address_bus = 
                        (((IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH) 
                          << 8U) | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD));
                    vlSelf->top__DOT__cpu_6502__DOT__AI 
                        = (0xffU & (IData)(vlSelf->top__DOT__cpu_6502__DOT__ABH));
                }
            } else {
                vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                    = vlSelf->top__DOT__cpu_6502__DOT__PC;
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
            }
        } else {
            vlSelf->top__DOT__cpu_6502__DOT__PC_temp 
                = vlSelf->top__DOT__cpu_6502__DOT__PC;
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
            vlSelf->top__DOT__address_bus = ((1U & (IData)(vlSelf->top__DOT__cpu_6502__DOT__state))
                                              ? (((IData)(vlSelf->top__DOT__data_in) 
                                                  << 8U) 
                                                 | (IData)(vlSelf->top__DOT__cpu_6502__DOT__ADD))
                                              : (IData)(vlSelf->top__DOT__cpu_6502__DOT__PC));
        }
        vlSelf->top__DOT__data_out = (0xffU & (IData)(top__DOT__cpu_6502__DOT__regfile));
    }
    vlSelf->tapaddress = vlSelf->top__DOT__address_bus;
    vlSelf->top__DOT__ram_enabled = (IData)((0U == 
                                             (0xc000U 
                                              & (IData)(vlSelf->top__DOT__address_bus))));
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
         | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 4, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
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
                    VL_FATAL_MT("top.sv", 4, "", "Active region did not converge.");
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
                VL_FATAL_MT("top.sv", 4, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->sdl_uart_byte_ready & 0xfeU))) {
        Verilated::overWidthError("sdl_uart_byte_ready");}
}
#endif  // VL_DEBUG

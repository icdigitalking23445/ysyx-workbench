// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" void illegal_halt();

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__illegal_halt_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__illegal_halt_TOP\n"); );
    // Body
    illegal_halt();
}

extern "C" void interrupt_halt();

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__interrupt_halt_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__interrupt_halt_TOP\n"); );
    // Body
    interrupt_halt();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->top__DOT__idu_io_IsIllegal) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal)));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->top__DOT__idu_io_IsInterrupt) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt)));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal 
        = vlSelf->top__DOT__idu_io_IsIllegal;
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt 
        = vlSelf->top__DOT__idu_io_IsInterrupt;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

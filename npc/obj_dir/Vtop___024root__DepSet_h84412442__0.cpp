// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

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

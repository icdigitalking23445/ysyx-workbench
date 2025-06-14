// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal 
        = vlSelf->top__DOT__idu_io_IsIllegal;
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt 
        = vlSelf->top__DOT__idu_io_IsInterrupt;
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
                VL_FATAL_MT("vsrc/top.v", 931, "", "Settle region did not converge.");
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

void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__pcPlus4 = ((IData)(4U) + vlSelf->top__DOT__pc);
    vlSelf->top__DOT__ifu__DOT__pmem_rdata = 0U;
    if (vlSelf->top__DOT__valid) {
        Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, vlSelf->__Vfunc_top__DOT__ifu__DOT__pmem__DOT__pmem_read__0__Vfuncout);
        vlSelf->top__DOT__ifu__DOT__pmem_rdata = vlSelf->__Vfunc_top__DOT__ifu__DOT__pmem__DOT__pmem_read__0__Vfuncout;
    }
    vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0 
        = ((0U != vlSelf->top__DOT__ifu__DOT__pmem_rdata) 
           & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
              >> 0x1eU));
    if ((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0 = 0x13U;
    } else {
        vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3 
            = (7U & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                     >> 0xcU));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 7U));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 0x14U));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 0xfU));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0 
            = (0x7fU & vlSelf->top__DOT__ifu__DOT__pmem_rdata);
    }
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0 
        = ((0U != vlSelf->top__DOT__ifu__DOT__pmem_rdata) 
           & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
              >> 0x1fU));
    vlSelf->top__DOT__pmemD_wmask = ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                      ? 0xfU : ((1U 
                                                 == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                 ? 3U
                                                 : 
                                                ((0U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                  ? 1U
                                                  : 0U)));
    vlSelf->top__DOT__idu__DOT___io_imm_T_5 = ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0)
                                                  ? 0xfffffU
                                                  : 0U) 
                                                << 0xcU) 
                                               | ((0U 
                                                   == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                   ? 0U
                                                   : 
                                                  (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                   >> 0x14U)));
    vlSelf->top__DOT__exu__DOT__alu_io_TYpe = ((0x73U 
                                                == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                ? 9U
                                                : (
                                                   (0x67U 
                                                    == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                    ? 7U
                                                    : 
                                                   ((0x17U 
                                                     == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                     ? 5U
                                                     : 
                                                    ((0x6fU 
                                                      == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                      ? 6U
                                                      : 
                                                     ((0x37U 
                                                       == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                       ? 5U
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                        ? 4U
                                                        : 
                                                       ((0x63U 
                                                         == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                         ? 3U
                                                         : 
                                                        ((0x23U 
                                                          == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                          ? 2U
                                                          : 
                                                         ((3U 
                                                           == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                           ? 1U
                                                           : 
                                                          ((0x33U 
                                                            == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                            ? 0U
                                                            : 8U))))))))));
    if ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = vlSelf->top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
    } else if ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0)
                  ? 0x7ffU : 0U) << 0x15U) | (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0) 
                                               << 0x14U) 
                                              | ((((0U 
                                                    == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                    ? 0U
                                                    : 
                                                   (0xffU 
                                                    & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                       >> 0xcU))) 
                                                  << 0xcU) 
                                                 | ((0x7ff800U 
                                                     & (((0U 
                                                          != vlSelf->top__DOT__ifu__DOT__pmem_rdata) 
                                                         << 0xbU) 
                                                        & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                           >> 9U))) 
                                                    | (((0U 
                                                         == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                         ? 0U
                                                         : 
                                                        (0x3ffU 
                                                         & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                            >> 0x15U))) 
                                                       << 1U)))));
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = 0U;
    } else if ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = (((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                 ? 0U : (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                         >> 0xcU)) << 0xcU);
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = 0U;
    } else if ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = vlSelf->top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
    } else if ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = 0U;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0)
                  ? 0x7ffffU : 0U) << 0xdU) | (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0) 
                                                << 0xcU) 
                                               | ((0xfffff800U 
                                                   & (((0U 
                                                        != vlSelf->top__DOT__ifu__DOT__pmem_rdata) 
                                                       << 0xbU) 
                                                      & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                         << 4U))) 
                                                  | ((((0U 
                                                        == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                        ? 0U
                                                        : 
                                                       (0x3fU 
                                                        & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                           >> 0x19U))) 
                                                      << 5U) 
                                                     | (((0U 
                                                          == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                          ? 0U
                                                          : 
                                                         (0xfU 
                                                          & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                             >> 8U))) 
                                                        << 1U)))));
        vlSelf->top__DOT__idu_io_rs2 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
    } else if ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = 0U;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0)
                  ? 0xfffffU : 0U) << 0xcU) | ((((0U 
                                                  == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                                  >> 0x19U)) 
                                                << 5U) 
                                               | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0)));
        vlSelf->top__DOT__idu_io_rs2 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
    } else if ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = vlSelf->top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
    } else {
        if ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0;
            vlSelf->top__DOT__idu_io_rs2 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0;
            vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
        } else {
            vlSelf->top__DOT__idu_io_rd = 0U;
            vlSelf->top__DOT__idu_io_rs2 = 0U;
            vlSelf->top__DOT__idu_io_rs1 = 0U;
        }
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b = 0U;
    }
    vlSelf->top__DOT__idu_io_IsIllegal = (8U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
    vlSelf->top__DOT__idu_io_IsInterrupt = (9U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
    vlSelf->top__DOT__pmemD_valid = ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                     | (2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)));
    vlSelf->top__DOT__regFile_io_writeEnable = (1U 
                                                & (~ 
                                                   ((3U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                                    | ((2U 
                                                        == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                                       | ((IData)(vlSelf->top__DOT__idu_io_IsIllegal) 
                                                          | (IData)(vlSelf->top__DOT__idu_io_IsInterrupt))))));
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum 
        = (vlSelf->top__DOT__pc + vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b);
    vlSelf->top__DOT__regFile__DOT___GEN_53 = ((0x15U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_21
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                    ? vlSelf->top__DOT__regFile__DOT__regFile_20
                                                    : 
                                                   ((0x13U 
                                                     == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                     ? vlSelf->top__DOT__regFile__DOT__regFile_19
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                      ? vlSelf->top__DOT__regFile__DOT__regFile_18
                                                      : 
                                                     ((0x11U 
                                                       == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                       ? vlSelf->top__DOT__regFile__DOT__regFile_17
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                        ? vlSelf->top__DOT__regFile__DOT__regFile_16
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                         ? vlSelf->top__DOT__regFile__DOT__regFile_15
                                                         : 
                                                        ((0xeU 
                                                          == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                          ? vlSelf->top__DOT__regFile__DOT__regFile_14
                                                          : 
                                                         ((0xdU 
                                                           == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                           ? vlSelf->top__DOT__regFile__DOT__regFile_13
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                            ? vlSelf->top__DOT__regFile__DOT__regFile_12
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                             ? vlSelf->top__DOT__regFile__DOT__regFile_11
                                                             : 
                                                            ((0xaU 
                                                              == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                              ? vlSelf->top__DOT__regFile__DOT__regFile_10
                                                              : 
                                                             ((9U 
                                                               == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                               ? vlSelf->top__DOT__regFile__DOT__regFile_9
                                                               : 
                                                              ((8U 
                                                                == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                ? vlSelf->top__DOT__regFile__DOT__regFile_8
                                                                : 
                                                               ((7U 
                                                                 == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                 ? vlSelf->top__DOT__regFile__DOT__regFile_7
                                                                 : 
                                                                ((6U 
                                                                  == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                  ? vlSelf->top__DOT__regFile__DOT__regFile_6
                                                                  : 
                                                                 ((5U 
                                                                   == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                   ? vlSelf->top__DOT__regFile__DOT__regFile_5
                                                                   : 
                                                                  ((4U 
                                                                    == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                    ? vlSelf->top__DOT__regFile__DOT__regFile_4
                                                                    : 
                                                                   ((3U 
                                                                     == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                     ? vlSelf->top__DOT__regFile__DOT__regFile_3
                                                                     : 
                                                                    ((2U 
                                                                      == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                      ? vlSelf->top__DOT__regFile__DOT__regFile_2
                                                                      : 
                                                                     ((1U 
                                                                       == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                                       ? vlSelf->top__DOT__regFile__DOT__regFile_1
                                                                       : vlSelf->top__DOT__regFile__DOT__regFile_0)))))))))))))))))))));
    vlSelf->top__DOT__regFile__DOT___GEN_21 = ((0x15U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_21
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                    ? vlSelf->top__DOT__regFile__DOT__regFile_20
                                                    : 
                                                   ((0x13U 
                                                     == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                     ? vlSelf->top__DOT__regFile__DOT__regFile_19
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                      ? vlSelf->top__DOT__regFile__DOT__regFile_18
                                                      : 
                                                     ((0x11U 
                                                       == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                       ? vlSelf->top__DOT__regFile__DOT__regFile_17
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                        ? vlSelf->top__DOT__regFile__DOT__regFile_16
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                         ? vlSelf->top__DOT__regFile__DOT__regFile_15
                                                         : 
                                                        ((0xeU 
                                                          == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                          ? vlSelf->top__DOT__regFile__DOT__regFile_14
                                                          : 
                                                         ((0xdU 
                                                           == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                           ? vlSelf->top__DOT__regFile__DOT__regFile_13
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                            ? vlSelf->top__DOT__regFile__DOT__regFile_12
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                             ? vlSelf->top__DOT__regFile__DOT__regFile_11
                                                             : 
                                                            ((0xaU 
                                                              == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                              ? vlSelf->top__DOT__regFile__DOT__regFile_10
                                                              : 
                                                             ((9U 
                                                               == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                               ? vlSelf->top__DOT__regFile__DOT__regFile_9
                                                               : 
                                                              ((8U 
                                                                == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                ? vlSelf->top__DOT__regFile__DOT__regFile_8
                                                                : 
                                                               ((7U 
                                                                 == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                 ? vlSelf->top__DOT__regFile__DOT__regFile_7
                                                                 : 
                                                                ((6U 
                                                                  == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                  ? vlSelf->top__DOT__regFile__DOT__regFile_6
                                                                  : 
                                                                 ((5U 
                                                                   == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                   ? vlSelf->top__DOT__regFile__DOT__regFile_5
                                                                   : 
                                                                  ((4U 
                                                                    == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                    ? vlSelf->top__DOT__regFile__DOT__regFile_4
                                                                    : 
                                                                   ((3U 
                                                                     == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                     ? vlSelf->top__DOT__regFile__DOT__regFile_3
                                                                     : 
                                                                    ((2U 
                                                                      == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                      ? vlSelf->top__DOT__regFile__DOT__regFile_2
                                                                      : 
                                                                     ((1U 
                                                                       == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                                       ? vlSelf->top__DOT__regFile__DOT__regFile_1
                                                                       : vlSelf->top__DOT__regFile__DOT__regFile_0)))))))))))))))))))));
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
        = ((0x1fU == (IData)(vlSelf->top__DOT__idu_io_rs2))
            ? vlSelf->top__DOT__regFile__DOT__regFile_31
            : ((0x1eU == (IData)(vlSelf->top__DOT__idu_io_rs2))
                ? vlSelf->top__DOT__regFile__DOT__regFile_30
                : ((0x1dU == (IData)(vlSelf->top__DOT__idu_io_rs2))
                    ? vlSelf->top__DOT__regFile__DOT__regFile_29
                    : ((0x1cU == (IData)(vlSelf->top__DOT__idu_io_rs2))
                        ? vlSelf->top__DOT__regFile__DOT__regFile_28
                        : ((0x1bU == (IData)(vlSelf->top__DOT__idu_io_rs2))
                            ? vlSelf->top__DOT__regFile__DOT__regFile_27
                            : ((0x1aU == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                ? vlSelf->top__DOT__regFile__DOT__regFile_26
                                : ((0x19U == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                    ? vlSelf->top__DOT__regFile__DOT__regFile_25
                                    : ((0x18U == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                        ? vlSelf->top__DOT__regFile__DOT__regFile_24
                                        : ((0x17U == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                            ? vlSelf->top__DOT__regFile__DOT__regFile_23
                                            : ((0x16U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_22
                                                : vlSelf->top__DOT__regFile__DOT___GEN_53))))))))));
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
        = ((0x1fU == (IData)(vlSelf->top__DOT__idu_io_rs1))
            ? vlSelf->top__DOT__regFile__DOT__regFile_31
            : ((0x1eU == (IData)(vlSelf->top__DOT__idu_io_rs1))
                ? vlSelf->top__DOT__regFile__DOT__regFile_30
                : ((0x1dU == (IData)(vlSelf->top__DOT__idu_io_rs1))
                    ? vlSelf->top__DOT__regFile__DOT__regFile_29
                    : ((0x1cU == (IData)(vlSelf->top__DOT__idu_io_rs1))
                        ? vlSelf->top__DOT__regFile__DOT__regFile_28
                        : ((0x1bU == (IData)(vlSelf->top__DOT__idu_io_rs1))
                            ? vlSelf->top__DOT__regFile__DOT__regFile_27
                            : ((0x1aU == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                ? vlSelf->top__DOT__regFile__DOT__regFile_26
                                : ((0x19U == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                    ? vlSelf->top__DOT__regFile__DOT__regFile_25
                                    : ((0x18U == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                        ? vlSelf->top__DOT__regFile__DOT__regFile_24
                                        : ((0x17U == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                            ? vlSelf->top__DOT__regFile__DOT__regFile_23
                                            : ((0x16U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_22
                                                : vlSelf->top__DOT__regFile__DOT___GEN_21))))))))));
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt 
        = (0x1fU & (((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                     & ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3)) 
                        | (5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))))
                     ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b
                     : vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b));
    vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum 
        = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
           + vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4 
        = VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5 
        = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
           < vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    if ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               >= vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    } else if ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5;
    } else {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                   ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                : 0U);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                ? VL_GTES_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                    ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4)
                    : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                        ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                           != vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                        : ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3)) 
                           & (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              == vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))));
    }
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5 
        = (0x7fffffffffffffffULL & ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                     ? (QData)((IData)(
                                                       ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
                                                         ? 
                                                        VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))
                                                         : 
                                                        (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                         >> (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt)))))
                                     : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                         ? ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                            << (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))
                                         : 0ULL)));
    vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc 
        = ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
            ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
            : (0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum));
    vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_9 
        = ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
            ? ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                   & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                    ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                       | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                    : ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                        ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)
                        : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                            ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                               ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                            : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                   < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                : ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                    ? VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                    : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                        ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)
                                        : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)))))))
            : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                ? 0U : ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                         ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                         : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                             ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                             : ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                 ? ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                     ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                     : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                         ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                         : ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                             ? ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
                                                 ? 
                                                VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                                               (0x1fU 
                                                                & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                                 : 
                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))
                                             : ((4U 
                                                 == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                 ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                  ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                   ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                    ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
                                                     ? 
                                                    (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                     - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                                                     : 
                                                    (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                     + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))))))))
                                 : 0U)))));
    if ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__exu_io_jump_target = 0U;
        vlSelf->top__DOT__exu_io_result_out = vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp;
    } else if ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__exu_io_jump_target = vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc;
        vlSelf->top__DOT__exu_io_result_out = vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc;
    } else if ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__exu_io_jump_target = vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc;
        vlSelf->top__DOT__exu_io_result_out = vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc;
    } else {
        vlSelf->top__DOT__exu_io_jump_target = 0U;
        vlSelf->top__DOT__exu_io_result_out = ((7U 
                                                == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                ? 0U
                                                : (
                                                   (6U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? 0U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                     ? 
                                                    ((0x17U 
                                                      == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                      + vlSelf->top__DOT__pc)
                                                      : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                     : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_9)));
    }
    vlSelf->top__DOT__branchTarget = (((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                       & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                                       ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                           ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                           : 0U) : 
                                      ((IData)(4U) 
                                       + vlSelf->top__DOT__pc));
    vlSelf->top__DOT__pmemD_rdata = 0U;
    if (((IData)(vlSelf->top__DOT__pmemD_valid) & (2U 
                                                   != (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(vlSelf->top__DOT__exu_io_result_out, vlSelf->__Vfunc_top__DOT__pmemD__DOT__pmem_read__3__Vfuncout);
        vlSelf->top__DOT__pmemD_rdata = vlSelf->__Vfunc_top__DOT__pmemD__DOT__pmem_read__3__Vfuncout;
    }
    if (((IData)(vlSelf->top__DOT__pmemD_valid) & (2U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)))) {
        if ((1U & (IData)(vlSelf->top__DOT__pmemD_wmask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(vlSelf->top__DOT__exu_io_result_out, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b, 1U);
        }
        if ((2U & (IData)(vlSelf->top__DOT__pmemD_wmask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(1U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 8U), 2U);
        }
        if ((4U & (IData)(vlSelf->top__DOT__pmemD_wmask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(2U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 0x10U), 4U);
        }
        if ((8U & (IData)(vlSelf->top__DOT__pmemD_wmask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(3U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 0x18U), 8U);
        }
    }
    vlSelf->top__DOT__byteOff = ((0x1fU >= (0x18U & 
                                            (vlSelf->top__DOT__exu_io_result_out 
                                             << 3U)))
                                  ? (vlSelf->top__DOT__pmemD_rdata 
                                     >> (0x18U & (vlSelf->top__DOT__exu_io_result_out 
                                                  << 3U)))
                                  : 0U);
    vlSelf->top__DOT__regFile_io_writeData = ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                               ? ((2U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                   ? vlSelf->top__DOT__pmemD_rdata
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                    ? 
                                                   (0xffffU 
                                                    & vlSelf->top__DOT__byteOff)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                     ? 
                                                    ((((0x8000U 
                                                        & vlSelf->top__DOT__byteOff)
                                                        ? 0xffffU
                                                        : 0U) 
                                                      << 0x10U) 
                                                     | (0xffffU 
                                                        & vlSelf->top__DOT__byteOff))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                      ? 
                                                     (0xffU 
                                                      & vlSelf->top__DOT__byteOff)
                                                      : 
                                                     ((0U 
                                                       == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                       ? 
                                                      ((((0x80U 
                                                          & vlSelf->top__DOT__byteOff)
                                                          ? 0xffffffU
                                                          : 0U) 
                                                        << 8U) 
                                                       | (0xffU 
                                                          & vlSelf->top__DOT__byteOff))
                                                       : 0U)))))
                                               : ((6U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelf->top__DOT__pc)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlSelf->top__DOT__pc)
                                                    : vlSelf->top__DOT__exu_io_result_out)));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge top.idu_io_IsIllegal)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge top.idu_io_IsInterrupt)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge top.idu_io_IsIllegal)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge top.idu_io_IsInterrupt)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu_io_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_IsIllegal = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu_io_IsInterrupt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regFile_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile_io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu_io_result_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu_io_jump_target = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pmemD_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pmemD_wmask = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__pmemD_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pcPlus4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__byteOff = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__branchTarget = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu__DOT__pmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT___io_imm_T_5 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h46550e90__0 = 0;
    vlSelf->top__DOT__regFile__DOT__regFile_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_5 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_6 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_7 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_8 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_9 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_10 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_11 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_12 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_13 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_14 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_15 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_16 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_17 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_18 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_19 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_20 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_21 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_22 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_23 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_24 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_25 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_26 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_27 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_28 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_29 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_30 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT__regFile_31 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT___GEN_21 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile__DOT___GEN_53 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu_io_TYpe = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_9 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0 = 0;
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5 = VL_RAND_RESET_Q(63);
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_top__DOT__ifu__DOT__pmem__DOT__pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__pmemD__DOT__pmem_read__3__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

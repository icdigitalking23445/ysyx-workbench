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
                VL_FATAL_MT("vsrc/top.v", 889, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*11:0*/ top__DOT__idu__DOT___io_imm_T_5;
    top__DOT__idu__DOT___io_imm_T_5 = 0;
    SData/*11:0*/ top__DOT__idu__DOT___io_imm_T_30;
    top__DOT__idu__DOT___io_imm_T_30 = 0;
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_21;
    top__DOT__regFile__DOT___GEN_21 = 0;
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_53;
    top__DOT__regFile__DOT___GEN_53 = 0;
    // Body
    vlSelf->io_pc = vlSelf->top__DOT__pc;
    vlSelf->top__DOT__pc_snpc = ((IData)(4U) + vlSelf->top__DOT__pc);
    top__DOT__idu__DOT___io_imm_T_5 = ((0xfe0U & (vlSelf->io_instruction 
                                                  >> 0x14U)) 
                                       | (0x1fU & (vlSelf->io_instruction 
                                                   >> 7U)));
    vlSelf->top__DOT__exu__DOT__alu_io_TYpe = ((0x73U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->io_instruction))
                                                ? 9U
                                                : (
                                                   (0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->io_instruction))
                                                    ? 7U
                                                    : 
                                                   ((0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->io_instruction))
                                                     ? 5U
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->io_instruction))
                                                      ? 6U
                                                      : 
                                                     ((0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->io_instruction))
                                                       ? 5U
                                                       : 
                                                      ((0x13U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->io_instruction))
                                                        ? 4U
                                                        : 
                                                       ((0x63U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->io_instruction))
                                                         ? 3U
                                                         : 
                                                        ((0x23U 
                                                          == 
                                                          (0x7fU 
                                                           & vlSelf->io_instruction))
                                                          ? 2U
                                                          : 
                                                         ((3U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelf->io_instruction))
                                                           ? 1U
                                                           : 
                                                          ((0x33U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->io_instruction))
                                                            ? 0U
                                                            : 8U))))))))));
    vlSelf->top__DOT__idu_io_IsIllegal = (8U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
    vlSelf->top__DOT__idu_io_IsInterrupt = (9U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
    top__DOT__idu__DOT___io_imm_T_30 = (0xfffU & ((4U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                   ? 
                                                  (vlSelf->io_instruction 
                                                   >> 0x14U)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? (IData)(top__DOT__idu__DOT___io_imm_T_5)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                     ? (IData)(top__DOT__idu__DOT___io_imm_T_5)
                                                     : 
                                                    ((1U 
                                                      == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                      ? 
                                                     (vlSelf->io_instruction 
                                                      >> 0x14U)
                                                      : 0U)))));
    if ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
        vlSelf->top__DOT__idu__DOT___io_imm_T_36 = 
            (((- (IData)((vlSelf->io_instruction >> 0x1fU))) 
              << 0xcU) | (vlSelf->io_instruction >> 0x14U));
    } else if ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 0U);
        vlSelf->top__DOT__idu__DOT___io_imm_T_36 = 
            (0xfffff000U & vlSelf->io_instruction);
    } else if ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 0U);
        vlSelf->top__DOT__idu__DOT___io_imm_T_36 = 
            (0xfffff000U & vlSelf->io_instruction);
    } else {
        if ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 
                                           (vlSelf->io_instruction 
                                            >> 7U));
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0x14U));
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0xfU));
        } else if ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0xfU));
        } else if ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0xfU));
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0x14U));
        } else if ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 
                                           (vlSelf->io_instruction 
                                            >> 7U));
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0xfU));
        } else if ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 
                                           (vlSelf->io_instruction 
                                            >> 7U));
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0x14U));
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 
                                            (vlSelf->io_instruction 
                                             >> 0xfU));
        } else {
            vlSelf->top__DOT__idu_io_rd = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 0U);
            vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 0U);
        }
        vlSelf->top__DOT__idu__DOT___io_imm_T_36 = 
            (((- (IData)((1U & ((IData)(top__DOT__idu__DOT___io_imm_T_30) 
                                >> 0xbU)))) << 0xcU) 
             | (IData)(top__DOT__idu__DOT___io_imm_T_30));
    }
    vlSelf->top__DOT__regFile_io_writeEnable = (1U 
                                                & (~ 
                                                   ((3U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                                    | ((2U 
                                                        == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                                       | ((IData)(vlSelf->top__DOT__idu_io_IsIllegal) 
                                                          | (IData)(vlSelf->top__DOT__idu_io_IsInterrupt))))));
    top__DOT__regFile__DOT___GEN_53 = ((0x15U == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                        ? vlSelf->top__DOT__regFile__DOT__regFile_21
                                        : ((0x14U == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                            ? vlSelf->top__DOT__regFile__DOT__regFile_20
                                            : ((0x13U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs2))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_19
                                                : (
                                                   (0x12U 
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
    top__DOT__regFile__DOT___GEN_21 = ((0x15U == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                        ? vlSelf->top__DOT__regFile__DOT__regFile_21
                                        : ((0x14U == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                            ? vlSelf->top__DOT__regFile__DOT__regFile_20
                                            : ((0x13U 
                                                == (IData)(vlSelf->top__DOT__idu_io_rs1))
                                                ? vlSelf->top__DOT__regFile__DOT__regFile_19
                                                : (
                                                   (0x12U 
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
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum 
        = (vlSelf->top__DOT__pc + (0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36));
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
                                                : top__DOT__regFile__DOT___GEN_53))))))))));
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
                                                : top__DOT__regFile__DOT___GEN_21))))))))));
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1 
        = ((0x40000000U & vlSelf->io_instruction) ? 
           VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                          (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
            : (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               >> (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)));
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4 
        = VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5 
        = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
           < vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    if ((7U == (7U & (vlSelf->io_instruction >> 0xcU)))) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               >= vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
    } else if ((6U == (7U & (vlSelf->io_instruction 
                             >> 0xcU)))) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5;
    } else {
        vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out 
            = ((4U == (7U & (vlSelf->io_instruction 
                             >> 0xcU))) ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                           ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                : 0U);
        vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp 
            = ((5U == (7U & (vlSelf->io_instruction 
                             >> 0xcU))) ? VL_GTES_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                : ((4U == (7U & (vlSelf->io_instruction 
                                 >> 0xcU))) ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4)
                    : ((1U == (7U & (vlSelf->io_instruction 
                                     >> 0xcU))) ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                   != vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                        : (IData)(((0U == (0x7000U 
                                           & vlSelf->io_instruction)) 
                                   & (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                      == vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))))));
    }
    vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum 
        = (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
           + (0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36));
    vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc 
        = ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
            ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
            : (0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum));
    if ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7 = 0U;
        vlSelf->top__DOT__exu_io_jump_target = 0U;
    } else {
        vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7 
            = ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                    ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                    : ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                        ? ((7U == (7U & (vlSelf->io_instruction 
                                         >> 0xcU)))
                            ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                            : ((6U == (7U & (vlSelf->io_instruction 
                                             >> 0xcU)))
                                ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                : ((5U == (7U & (vlSelf->io_instruction 
                                                 >> 0xcU)))
                                    ? vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1
                                    : ((4U == (7U & 
                                               (vlSelf->io_instruction 
                                                >> 0xcU)))
                                        ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                        : ((3U == (7U 
                                                   & (vlSelf->io_instruction 
                                                      >> 0xcU)))
                                            ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5)
                                            : ((2U 
                                                == 
                                                (7U 
                                                 & (vlSelf->io_instruction 
                                                    >> 0xcU)))
                                                ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4)
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->io_instruction 
                                                        >> 0xcU)))
                                                    ? (IData)(
                                                              (0x7fffffffffffffffULL 
                                                               & ((5U 
                                                                   == 
                                                                   (7U 
                                                                    & (vlSelf->io_instruction 
                                                                       >> 0xcU)))
                                                                   ? (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1))
                                                                   : 
                                                                  ((1U 
                                                                    == 
                                                                    (7U 
                                                                     & (vlSelf->io_instruction 
                                                                        >> 0xcU)))
                                                                    ? 
                                                                   ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                                                    << 
                                                                    (0x1fU 
                                                                     & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                                                    : 0ULL))))
                                                    : 
                                                   ((0x40000000U 
                                                     & vlSelf->io_instruction)
                                                     ? 
                                                    (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                     - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)
                                                     : 
                                                    (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                     + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))))))))
                        : 0U)));
        vlSelf->top__DOT__exu_io_jump_target = ((6U 
                                                 == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                 ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                                 : 
                                                ((7U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                  ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                                  : 0U));
    }
    vlSelf->top__DOT__branchPath = (((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                     & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                                     ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                         ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                         : 0U) : ((IData)(4U) 
                                                  + vlSelf->top__DOT__pc));
    vlSelf->top__DOT__regFile_io_writeData = (((6U 
                                                == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                               | (7U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)))
                                               ? vlSelf->top__DOT__exu_io_jump_target
                                               : ((3U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                   ? (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                     ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                      ? 0U
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                       ? 0U
                                                       : 
                                                      ((5U 
                                                        == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                        ? (IData)(
                                                                  (0xfffffffffffULL 
                                                                   & ((5U 
                                                                       == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                                       ? 
                                                                      ((QData)((IData)(vlSelf->top__DOT__pc)) 
                                                                       + 
                                                                       ((QData)((IData)(
                                                                                (0xfffU 
                                                                                & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                                                                        << 0xcU))
                                                                       : 
                                                                      ((QData)((IData)(
                                                                                (0xfffU 
                                                                                & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                                                                       << 0xcU))))
                                                        : 
                                                       ((4U 
                                                         == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                         ? 
                                                        ((7U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->io_instruction 
                                                              >> 0xcU)))
                                                          ? 
                                                         (0xfffU 
                                                          & (vlSelf->top__DOT__idu__DOT___io_imm_T_36 
                                                             & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a))
                                                          : 
                                                         ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->io_instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((0xfffU 
                                                            & vlSelf->top__DOT__idu__DOT___io_imm_T_36) 
                                                           | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                           : 
                                                          ((4U 
                                                            == 
                                                            (7U 
                                                             & (vlSelf->io_instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((0xfffU 
                                                             & vlSelf->top__DOT__idu__DOT___io_imm_T_36) 
                                                            ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                            : 
                                                           ((3U 
                                                             == 
                                                             (7U 
                                                              & (vlSelf->io_instruction 
                                                                 >> 0xcU)))
                                                             ? 
                                                            (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                             < 
                                                             (0xfffU 
                                                              & vlSelf->top__DOT__idu__DOT___io_imm_T_36))
                                                             : 
                                                            ((2U 
                                                              == 
                                                              (7U 
                                                               & (vlSelf->io_instruction 
                                                                  >> 0xcU)))
                                                              ? 
                                                             VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                                                        (0xfffU 
                                                                         & vlSelf->top__DOT__idu__DOT___io_imm_T_36))
                                                              : 
                                                             ((0U 
                                                               == 
                                                               (7U 
                                                                & (vlSelf->io_instruction 
                                                                   >> 0xcU)))
                                                               ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                                               : 0U))))))
                                                         : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7))))))));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
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
    vlSelf->io_instruction = VL_RAND_RESET_I(32);
    vlSelf->io_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu_io_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__idu_io_IsIllegal = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu_io_IsInterrupt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regFile_io_writeData = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regFile_io_writeEnable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu_io_jump_target = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_snpc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__branchPath = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT___io_imm_T_36 = VL_RAND_RESET_I(32);
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
    vlSelf->top__DOT__exu__DOT__alu_io_TYpe = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

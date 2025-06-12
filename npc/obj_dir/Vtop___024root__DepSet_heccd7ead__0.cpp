// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__idu__DOT___io_imm_T_5;
    top__DOT__idu__DOT___io_imm_T_5 = 0;
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_21;
    top__DOT__regFile__DOT___GEN_21 = 0;
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_53;
    top__DOT__regFile__DOT___GEN_53 = 0;
    // Body
    top__DOT__idu__DOT___io_imm_T_5 = ((((vlSelf->io_instruction 
                                          >> 0x1fU)
                                          ? 0xfffffU
                                          : 0U) << 0xcU) 
                                       | (vlSelf->io_instruction 
                                          >> 0x14U));
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
    if ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
    } else if ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((vlSelf->io_instruction >> 0x1fU) ? 0x7ffU
                  : 0U) << 0x15U) | ((0x100000U & (vlSelf->io_instruction 
                                                   >> 0xbU)) 
                                     | ((0xff000U & vlSelf->io_instruction) 
                                        | ((0x800U 
                                            & (vlSelf->io_instruction 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelf->io_instruction 
                                                 >> 0x14U))))));
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 0U);
    } else if ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = (0xfffff000U & vlSelf->io_instruction);
        vlSelf->top__DOT__idu_io_rs2 = 0U;
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & 0U);
    } else if ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0x14U));
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
    } else if ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & 0U);
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((vlSelf->io_instruction >> 0x1fU) ? 0x7ffffU
                  : 0U) << 0xdU) | ((0x1000U & (vlSelf->io_instruction 
                                                >> 0x13U)) 
                                    | ((0x800U & (vlSelf->io_instruction 
                                                  << 4U)) 
                                       | ((0x7e0U & 
                                           (vlSelf->io_instruction 
                                            >> 0x14U)) 
                                          | (0x1eU 
                                             & (vlSelf->io_instruction 
                                                >> 7U))))));
        vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 0U);
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
    } else if ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & 0U);
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = ((((vlSelf->io_instruction >> 0x1fU) ? 0xfffffU
                  : 0U) << 0xcU) | ((0xfe0U & (vlSelf->io_instruction 
                                               >> 0x14U)) 
                                    | (0x1fU & (vlSelf->io_instruction 
                                                >> 7U))));
        vlSelf->top__DOT__idu_io_rs2 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0x14U));
    } else if ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
        vlSelf->top__DOT__idu_io_rd = (0x1fU & (vlSelf->io_instruction 
                                                >> 7U));
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
            = top__DOT__idu__DOT___io_imm_T_5;
        vlSelf->top__DOT__idu_io_rs2 = (0x1fU & 0U);
        vlSelf->top__DOT__idu_io_rs1 = (0x1fU & (vlSelf->io_instruction 
                                                 >> 0xfU));
    } else {
        if ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
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
        vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b = 0U;
    }
    vlSelf->top__DOT__idu_io_IsIllegal = (8U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
    vlSelf->top__DOT__idu_io_IsInterrupt = (9U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe));
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
           + vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b);
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
                                               ? ((IData)(4U) 
                                                  + vlSelf->top__DOT__pc)
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
                                                                       ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                                                        << 0xcU))
                                                                       : 
                                                                      ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
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
                                                         (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                          & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                          : 
                                                         ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->io_instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                           | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                           : 
                                                          ((4U 
                                                            == 
                                                            (7U 
                                                             & (vlSelf->io_instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                            ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                            : 
                                                           ((3U 
                                                             == 
                                                             (7U 
                                                              & (vlSelf->io_instruction 
                                                                 >> 0xcU)))
                                                             ? 
                                                            (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                             < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                             : 
                                                            ((2U 
                                                              == 
                                                              (7U 
                                                               & (vlSelf->io_instruction 
                                                                  >> 0xcU)))
                                                              ? 
                                                             VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__illegal_halt_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->top__DOT__idu_io_IsIllegal) {
        Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__illegal_halt_TOP();
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__interrupt_halt_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->top__DOT__idu_io_IsInterrupt) {
        Vtop___024root____Vdpiimwrap_top__DOT__dpiHandlers__DOT__interrupt_halt_TOP();
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_21;
    top__DOT__regFile__DOT___GEN_21 = 0;
    IData/*31:0*/ top__DOT__regFile__DOT___GEN_53;
    top__DOT__regFile__DOT___GEN_53 = 0;
    // Body
    if (vlSelf->reset) {
        vlSelf->top__DOT__pc = 0x80000000U;
        vlSelf->top__DOT__regFile__DOT__regFile_25 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_24 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_23 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_31 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_22 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_28 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_30 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_29 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_26 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_27 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_17 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_16 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_13 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_4 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_18 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_0 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_12 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_5 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_19 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_1 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_7 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_21 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_14 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_10 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_6 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_20 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_2 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_15 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_11 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_3 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_8 = 0U;
        vlSelf->top__DOT__regFile__DOT__regFile_9 = 0U;
    } else {
        vlSelf->top__DOT__pc = ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                 ? vlSelf->top__DOT__exu_io_jump_target
                                 : ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                     ? vlSelf->top__DOT__exu_io_jump_target
                                     : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                         ? vlSelf->top__DOT__branchPath
                                         : vlSelf->top__DOT__pc_snpc)));
        if (((IData)(vlSelf->top__DOT__regFile_io_writeEnable) 
             & (0U != (IData)(vlSelf->top__DOT__idu_io_rd)))) {
            if ((0x19U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_25 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x18U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_24 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x17U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_23 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1fU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_31 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x16U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_22 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1cU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_28 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1eU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_30 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1dU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_29 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1aU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_26 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x1bU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_27 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x11U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_17 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x10U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_16 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0xdU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_13 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((4U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_4 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x12U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_18 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            vlSelf->top__DOT__regFile__DOT__regFile_0 
                = ((0U == (IData)(vlSelf->top__DOT__idu_io_rd))
                    ? vlSelf->top__DOT__regFile_io_writeData
                    : 0U);
            if ((0xcU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_12 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((5U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_5 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x13U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_19 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((1U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_1 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((7U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_7 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x15U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_21 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0xeU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_14 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0xaU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_10 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((6U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_6 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0x14U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_20 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((2U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_2 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0xfU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_15 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((0xbU == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_11 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((3U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_3 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((8U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_8 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
            if ((9U == (IData)(vlSelf->top__DOT__idu_io_rd))) {
                vlSelf->top__DOT__regFile__DOT__regFile_9 
                    = vlSelf->top__DOT__regFile_io_writeData;
            }
        } else {
            vlSelf->top__DOT__regFile__DOT__regFile_0 = 0U;
        }
    }
    vlSelf->io_pc = vlSelf->top__DOT__pc;
    vlSelf->top__DOT__pc_snpc = ((IData)(4U) + vlSelf->top__DOT__pc);
    vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum 
        = (vlSelf->top__DOT__pc + vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b);
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
           + vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b);
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
                                               ? ((IData)(4U) 
                                                  + vlSelf->top__DOT__pc)
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
                                                                       ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                                                        << 0xcU))
                                                                       : 
                                                                      ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
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
                                                         (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                          & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                          : 
                                                         ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->io_instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                           | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                           : 
                                                          ((4U 
                                                            == 
                                                            (7U 
                                                             & (vlSelf->io_instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                            ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                                            : 
                                                           ((3U 
                                                             == 
                                                             (7U 
                                                              & (vlSelf->io_instruction 
                                                                 >> 0xcU)))
                                                             ? 
                                                            (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                             < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                             : 
                                                            ((2U 
                                                              == 
                                                              (7U 
                                                               & (vlSelf->io_instruction 
                                                                  >> 0xcU)))
                                                              ? 
                                                             VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                VL_FATAL_MT("vsrc/top.v", 893, "", "Input combinational region did not converge.");
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
                    VL_FATAL_MT("vsrc/top.v", 893, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 893, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

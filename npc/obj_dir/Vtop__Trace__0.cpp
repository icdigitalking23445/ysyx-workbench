// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__idu_io_rs1),5);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__idu_io_rs2),5);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__idu_io_rd),5);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b),32);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__exu__DOT__alu_io_TYpe),4);
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__idu_io_IsIllegal));
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__idu_io_IsInterrupt));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__regFile_io_writeEnable));
        bufp->chgBit(oldp+8,((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+9,((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+10,((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+11,((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+12,((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgQData(oldp+13,(((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                 << 0xcU)),44);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__regFile_io_writeData),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b),32);
        bufp->chgBit(oldp+18,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                               & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))));
        bufp->chgIData(oldp+19,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                  ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                  : 0U)),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__exu_io_jump_target),32);
        bufp->chgIData(oldp+21,((((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                  & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                                  ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                      ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                      : 0U) : ((IData)(4U) 
                                               + vlSelf->top__DOT__pc))),32);
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp));
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc),32);
        bufp->chgIData(oldp+25,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
        bufp->chgIData(oldp+26,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
        bufp->chgCData(oldp+27,((0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),5);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum),32);
        bufp->chgIData(oldp+30,((IData)((0xfffffffffffULL 
                                         & ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                             ? ((QData)((IData)(vlSelf->top__DOT__pc)) 
                                                + ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                                   << 0xcU))
                                             : ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                                << 0xcU))))),32);
        bufp->chgQData(oldp+31,((0x7fffffffffffffffULL 
                                 & ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                    << (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))),63);
        bufp->chgIData(oldp+33,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 >> (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))),32);
        bufp->chgIData(oldp+34,(VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                               (0x1fU 
                                                & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))),32);
        bufp->chgQData(oldp+35,((0xfffffffffffULL & 
                                 ((QData)((IData)(vlSelf->top__DOT__pc)) 
                                  + ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)) 
                                     << 0xcU)))),44);
        bufp->chgIData(oldp+37,((0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+39,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__regFile__DOT__regFile_0),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__regFile__DOT__regFile_1),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__regFile__DOT__regFile_2),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__regFile__DOT__regFile_3),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__regFile__DOT__regFile_4),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__regFile__DOT__regFile_5),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__regFile__DOT__regFile_6),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__regFile__DOT__regFile_7),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__regFile__DOT__regFile_8),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__regFile__DOT__regFile_9),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__regFile__DOT__regFile_10),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__regFile__DOT__regFile_11),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__regFile__DOT__regFile_12),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__regFile__DOT__regFile_13),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__regFile__DOT__regFile_14),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__regFile__DOT__regFile_15),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__regFile__DOT__regFile_16),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__regFile__DOT__regFile_17),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__regFile__DOT__regFile_18),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__regFile__DOT__regFile_19),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__regFile__DOT__regFile_20),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__regFile__DOT__regFile_21),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__regFile__DOT__regFile_22),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__regFile__DOT__regFile_23),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__regFile__DOT__regFile_24),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__regFile__DOT__regFile_25),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__regFile__DOT__regFile_26),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__regFile__DOT__regFile_27),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__regFile__DOT__regFile_28),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__regFile__DOT__regFile_29),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__regFile__DOT__regFile_30),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__regFile__DOT__regFile_31),32);
    }
    bufp->chgBit(oldp+72,(vlSelf->clock));
    bufp->chgBit(oldp+73,(vlSelf->reset));
    bufp->chgIData(oldp+74,(vlSelf->io_instruction),32);
    bufp->chgIData(oldp+75,(vlSelf->io_pc),32);
    bufp->chgCData(oldp+76,((7U & (vlSelf->io_instruction 
                                   >> 0xcU))),3);
    bufp->chgCData(oldp+77,((vlSelf->io_instruction 
                             >> 0x19U)),7);
    bufp->chgIData(oldp+78,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                              ? (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp)
                              : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                  ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                  : ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                      ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                      : ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                          ? 0U : ((6U 
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
                                                     : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7)))))))),32);
    bufp->chgIData(oldp+79,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                              ? 0U : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                       ? 0U : ((5U 
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
                                                : (
                                                   (4U 
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
                                                    : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7))))),32);
    bufp->chgIData(oldp+80,((IData)((0x7fffffffffffffffULL 
                                     & ((5U == (7U 
                                                & (vlSelf->io_instruction 
                                                   >> 0xcU)))
                                         ? (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1))
                                         : ((1U == 
                                             (7U & 
                                              (vlSelf->io_instruction 
                                               >> 0xcU)))
                                             ? ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                                << 
                                                (0x1fU 
                                                 & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                             : 0ULL))))),32);
    bufp->chgIData(oldp+81,(((7U == (7U & (vlSelf->io_instruction 
                                           >> 0xcU)))
                              ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                              : ((6U == (7U & (vlSelf->io_instruction 
                                               >> 0xcU)))
                                  ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                  : ((5U == (7U & (vlSelf->io_instruction 
                                                   >> 0xcU)))
                                      ? vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1
                                      : ((4U == (7U 
                                                 & (vlSelf->io_instruction 
                                                    >> 0xcU)))
                                          ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                          : ((3U == 
                                              (7U & 
                                               (vlSelf->io_instruction 
                                                >> 0xcU)))
                                              ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5)
                                              : ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->io_instruction 
                                                      >> 0xcU)))
                                                  ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4)
                                                  : 
                                                 ((1U 
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
                                                    + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))))))))),32);
    bufp->chgIData(oldp+82,(((7U == (7U & (vlSelf->io_instruction 
                                           >> 0xcU)))
                              ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                 & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                              : ((6U == (7U & (vlSelf->io_instruction 
                                               >> 0xcU)))
                                  ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                     | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                  : ((4U == (7U & (vlSelf->io_instruction 
                                                   >> 0xcU)))
                                      ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                         ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                      : ((3U == (7U 
                                                 & (vlSelf->io_instruction 
                                                    >> 0xcU)))
                                          ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                             < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                          : ((2U == 
                                              (7U & 
                                               (vlSelf->io_instruction 
                                                >> 0xcU)))
                                              ? VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                              : ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->io_instruction 
                                                      >> 0xcU)))
                                                  ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                                  : 0U))))))),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}

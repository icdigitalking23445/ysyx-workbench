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
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__pc),32);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__valid));
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__ifu__DOT__pmem_rdata),32);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__idu_io_rs1),5);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__idu_io_rs2),5);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__idu_io_rd),5);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3),3);
        bufp->chgCData(oldp+7,(((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                 ? 0U : (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                         >> 0x19U))),7);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b),32);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__exu__DOT__alu_io_TYpe),4);
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__idu_io_IsIllegal));
        bufp->chgBit(oldp+11,(vlSelf->top__DOT__idu_io_IsInterrupt));
        bufp->chgBit(oldp+12,((0x17U == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))));
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__regFile_io_writeData),32);
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__regFile_io_writeEnable));
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__exu_io_result_out),32);
        bufp->chgBit(oldp+18,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                               & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))));
        bufp->chgIData(oldp+19,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                  ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                  : 0U)),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__exu_io_jump_target),32);
        bufp->chgBit(oldp+21,(vlSelf->top__DOT__pmemD_valid));
        bufp->chgBit(oldp+22,((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgCData(oldp+23,(vlSelf->top__DOT__pmemD_wmask),4);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__pmemD_rdata),32);
        bufp->chgIData(oldp+25,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgBit(oldp+26,((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgCData(oldp+27,((3U & vlSelf->top__DOT__exu_io_result_out)),2);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__byteOff),32);
        bufp->chgSData(oldp+29,((0xffffU & vlSelf->top__DOT__byteOff)),16);
        bufp->chgIData(oldp+30,(((((0x80U & vlSelf->top__DOT__byteOff)
                                    ? 0xffffffU : 0U) 
                                  << 8U) | (0xffU & vlSelf->top__DOT__byteOff))),32);
        bufp->chgIData(oldp+31,((0xffU & vlSelf->top__DOT__byteOff)),32);
        bufp->chgIData(oldp+32,(((((0x8000U & vlSelf->top__DOT__byteOff)
                                    ? 0xffffU : 0U) 
                                  << 0x10U) | (0xffffU 
                                               & vlSelf->top__DOT__byteOff))),32);
        bufp->chgIData(oldp+33,((0xffffU & vlSelf->top__DOT__byteOff)),32);
        bufp->chgIData(oldp+34,(((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                  ? vlSelf->top__DOT__pmemD_rdata
                                  : ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                      ? (0xffffU & vlSelf->top__DOT__byteOff)
                                      : ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                          ? ((((0x8000U 
                                                & vlSelf->top__DOT__byteOff)
                                                ? 0xffffU
                                                : 0U) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & vlSelf->top__DOT__byteOff))
                                          : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                              ? (0xffU 
                                                 & vlSelf->top__DOT__byteOff)
                                              : ((0U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                  ? 
                                                 ((((0x80U 
                                                     & vlSelf->top__DOT__byteOff)
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   << 8U) 
                                                  | (0xffU 
                                                     & vlSelf->top__DOT__byteOff))
                                                  : 0U)))))),32);
        bufp->chgBit(oldp+35,((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+36,((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgBit(oldp+37,((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
        bufp->chgIData(oldp+38,((((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                                  & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                                  ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                      ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                      : 0U) : ((IData)(4U) 
                                               + vlSelf->top__DOT__pc))),32);
        bufp->chgIData(oldp+39,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                  ? 0U : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                           ? 0U : (
                                                   (5U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? 
                                                   ((0x17U 
                                                     == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                     ? 
                                                    (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                     + vlSelf->top__DOT__pc)
                                                     : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                    : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_9)))),32);
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp));
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc),32);
        bufp->chgIData(oldp+43,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
        bufp->chgIData(oldp+44,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
        bufp->chgCData(oldp+45,(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt),5);
        bufp->chgIData(oldp+46,((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum),32);
        bufp->chgIData(oldp+49,(((0x17U == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                  ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                     + vlSelf->top__DOT__pc)
                                  : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)),32);
        bufp->chgBit(oldp+50,(((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                               & ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3)) 
                                  | (5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))))));
        bufp->chgIData(oldp+51,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                  ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                  : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                      ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                      : ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                          ? ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
                                              ? VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                                               (0x1fU 
                                                                & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                              : (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))
                                          : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                              ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                              : ((3U 
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
                                                     + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))))))))),32);
        bufp->chgIData(oldp+52,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
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
                                              : ((3U 
                                                  == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                  ? 
                                                 (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                                  < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                   ? 
                                                  VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                    ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)
                                                    : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)))))))),32);
        bufp->chgQData(oldp+53,((0x7fffffffffffffffULL 
                                 & ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                    << (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt)))),63);
        bufp->chgIData(oldp+55,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                 >> (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))),32);
        bufp->chgIData(oldp+56,(VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))),32);
        bufp->chgIData(oldp+57,((vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                 + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+58,((0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)),32);
        bufp->chgIData(oldp+59,(((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                                  ? 0x13U : vlSelf->top__DOT__ifu__DOT__pmem_rdata)),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__regFile__DOT__regFile_0),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__regFile__DOT__regFile_1),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__regFile__DOT__regFile_2),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__regFile__DOT__regFile_3),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__regFile__DOT__regFile_4),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__regFile__DOT__regFile_5),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__regFile__DOT__regFile_6),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__regFile__DOT__regFile_7),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__regFile__DOT__regFile_8),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__regFile__DOT__regFile_9),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__regFile__DOT__regFile_10),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__regFile__DOT__regFile_11),32);
        bufp->chgIData(oldp+72,(vlSelf->top__DOT__regFile__DOT__regFile_12),32);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__regFile__DOT__regFile_13),32);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__regFile__DOT__regFile_14),32);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__regFile__DOT__regFile_15),32);
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__regFile__DOT__regFile_16),32);
        bufp->chgIData(oldp+77,(vlSelf->top__DOT__regFile__DOT__regFile_17),32);
        bufp->chgIData(oldp+78,(vlSelf->top__DOT__regFile__DOT__regFile_18),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__regFile__DOT__regFile_19),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__regFile__DOT__regFile_20),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__regFile__DOT__regFile_21),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__regFile__DOT__regFile_22),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__regFile__DOT__regFile_23),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__regFile__DOT__regFile_24),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__regFile__DOT__regFile_25),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__regFile__DOT__regFile_26),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__regFile__DOT__regFile_27),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__regFile__DOT__regFile_28),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__regFile__DOT__regFile_29),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__regFile__DOT__regFile_30),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__regFile__DOT__regFile_31),32);
    }
    bufp->chgBit(oldp+92,(vlSelf->clock));
    bufp->chgBit(oldp+93,(vlSelf->reset));
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
}

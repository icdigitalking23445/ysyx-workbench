// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

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

void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->reset) {
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
        vlSelf->top__DOT__pc = 0x80000000U;
    } else {
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
        vlSelf->top__DOT__pc = ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                 ? vlSelf->top__DOT__exu_io_jump_target
                                 : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                     ? vlSelf->top__DOT__exu_io_jump_target
                                     : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                         ? vlSelf->top__DOT__branchTarget
                                         : vlSelf->top__DOT__pcPlus4)));
    }
    vlSelf->top__DOT__valid = (1U & (~ (IData)(vlSelf->reset)));
    vlSelf->top__DOT__pcPlus4 = ((IData)(4U) + vlSelf->top__DOT__pc);
    if (vlSelf->top__DOT__valid) {
        Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, vlSelf->__Vfunc_top__DOT__ifu__DOT__pmem__DOT__pmem_read__0__Vfuncout);
        vlSelf->top__DOT__ifu__DOT__pmem_rdata = vlSelf->__Vfunc_top__DOT__ifu__DOT__pmem__DOT__pmem_read__0__Vfuncout;
    } else {
        vlSelf->top__DOT__ifu__DOT__pmem_rdata = 0U;
    }
    vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0 
        = ((0U != vlSelf->top__DOT__ifu__DOT__pmem_rdata) 
           & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
              >> 0x1eU));
    if ((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)) {
        vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0 = 0U;
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0 = 0x13U;
    } else {
        vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3 
            = (7U & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                     >> 0xcU));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d41f789__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 7U));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 0xfU));
        vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0 
            = (0x1fU & (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                        >> 0x14U));
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
                                                (0U 
                                                 == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))));
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
        vlSelf->top__DOT__idu_io_rs2 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0;
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
        vlSelf->top__DOT__idu_io_rs2 = 0U;
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
        vlSelf->top__DOT__idu_io_rs2 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d222a6e__0;
        vlSelf->top__DOT__idu_io_rs1 = vlSelf->top__DOT__idu__DOT____VdfgTmp_h7d78de21__0;
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
    vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1 
        = ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
            ? VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                             (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
            : (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
               >> (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)));
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
                    : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                        ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                           ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                        : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                            ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                               < vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                            : ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                ? VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                : ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                    ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                    : 0U)))))) : ((3U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                    ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                     ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                                     : 
                                                    ((0U 
                                                      == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                      ? 
                                                     ((7U 
                                                       == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                       ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                        ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                                        : 
                                                       ((5U 
                                                         == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                         ? vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1
                                                         : 
                                                        ((4U 
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
                                                             ? (IData)(
                                                                       (0x7fffffffffffffffULL 
                                                                        & ((5U 
                                                                            == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                                            ? (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1))
                                                                            : 
                                                                           ((1U 
                                                                             == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                                             ? 
                                                                            ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                                                             << 
                                                                             (0x1fU 
                                                                              & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                                                             : 0ULL))))
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
                                                    ((5U 
                                                      == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
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
    if (((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
         | (2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_read_TOP(vlSelf->top__DOT__exu_io_result_out, vlSelf->__Vfunc_top__DOT__pmemD__DOT__pmem_read__3__Vfuncout);
        vlSelf->top__DOT__pmemD_rdata = vlSelf->__Vfunc_top__DOT__pmemD__DOT__pmem_read__3__Vfuncout;
        if ((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(vlSelf->top__DOT__exu_io_result_out, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b, 
                                                                                ((1U 
                                                                                & (IData)(vlSelf->top__DOT__pmemD_wmask))
                                                                                 ? 1U
                                                                                 : 0U));
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(1U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 8U), 
                                                                                ((2U 
                                                                                & (IData)(vlSelf->top__DOT__pmemD_wmask))
                                                                                 ? 2U
                                                                                 : 0U));
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(2U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 0x10U), 
                                                                                ((4U 
                                                                                & (IData)(vlSelf->top__DOT__pmemD_wmask))
                                                                                 ? 4U
                                                                                 : 0U));
            Vtop___024root____Vdpiimwrap_top__DOT__ifu__DOT__pmem__DOT__pmem_write_TOP(
                                                                                ((IData)(3U) 
                                                                                + vlSelf->top__DOT__exu_io_result_out), 
                                                                                (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b 
                                                                                >> 0x18U), 
                                                                                ((8U 
                                                                                & (IData)(vlSelf->top__DOT__pmemD_wmask))
                                                                                 ? 8U
                                                                                 : 0U));
        }
    } else {
        vlSelf->top__DOT__pmemD_rdata = 0U;
    }
    vlSelf->top__DOT__regFile_io_writeData = ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                               ? vlSelf->top__DOT__pmemD_rdata
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
        vlSelf->__Vm_traceActivity[1U] = 1U;
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
    VlTriggerVec<3> __VpreTriggered;
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
                    VL_FATAL_MT("vsrc/top.v", 918, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 918, "", "NBA region did not converge.");
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

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+75,"reset", false,-1);
    tracep->declBus(c+76,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+75,"reset", false,-1);
    tracep->declBus(c+76,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBus(c+76,"idu_io_instruction", false,-1, 31,0);
    tracep->declBus(c+1,"idu_io_rs1", false,-1, 4,0);
    tracep->declBus(c+2,"idu_io_rs2", false,-1, 4,0);
    tracep->declBus(c+3,"idu_io_rd", false,-1, 4,0);
    tracep->declBus(c+78,"idu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"idu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+4,"idu_io_imm", false,-1, 11,0);
    tracep->declBus(c+5,"idu_io_TYpe", false,-1, 3,0);
    tracep->declBit(c+6,"idu_io_IsIllegal", false,-1);
    tracep->declBit(c+7,"idu_io_IsInterrupt", false,-1);
    tracep->declBit(c+74,"regFile_clock", false,-1);
    tracep->declBit(c+75,"regFile_reset", false,-1);
    tracep->declBus(c+1,"regFile_io_rs1", false,-1, 4,0);
    tracep->declBus(c+2,"regFile_io_rs2", false,-1, 4,0);
    tracep->declBus(c+3,"regFile_io_rd", false,-1, 4,0);
    tracep->declBus(c+17,"regFile_io_writeData", false,-1, 31,0);
    tracep->declBit(c+8,"regFile_io_writeEnable", false,-1);
    tracep->declBus(c+18,"regFile_io_regData1", false,-1, 31,0);
    tracep->declBus(c+19,"regFile_io_regData2", false,-1, 31,0);
    tracep->declBus(c+78,"exu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"exu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+4,"exu_io_imm", false,-1, 11,0);
    tracep->declBus(c+5,"exu_io_TYpe", false,-1, 3,0);
    tracep->declBus(c+18,"exu_io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+19,"exu_io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+77,"exu_io_pc", false,-1, 31,0);
    tracep->declBus(c+80,"exu_io_result_out", false,-1, 31,0);
    tracep->declBit(c+20,"exu_io_branch_taken", false,-1);
    tracep->declBus(c+21,"exu_io_branch_target", false,-1, 31,0);
    tracep->declBus(c+22,"exu_io_jump_target", false,-1, 31,0);
    tracep->declBit(c+6,"dpiHandlers_IsIllegal", false,-1);
    tracep->declBit(c+7,"dpiHandlers_IsInterrupt", false,-1);
    tracep->declBus(c+40,"pc", false,-1, 31,0);
    tracep->declBus(c+41,"pc_snpc", false,-1, 31,0);
    tracep->declBit(c+9,"isBranch", false,-1);
    tracep->declBit(c+10,"isStore", false,-1);
    tracep->declBit(c+11,"isJal", false,-1);
    tracep->declBit(c+12,"isJalr", false,-1);
    tracep->declBus(c+23,"branchPath", false,-1, 31,0);
    tracep->pushNamePrefix("dpiHandlers ");
    tracep->declBit(c+6,"IsIllegal", false,-1);
    tracep->declBit(c+7,"IsInterrupt", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+4,"io_imm", false,-1, 11,0);
    tracep->declBus(c+5,"io_TYpe", false,-1, 3,0);
    tracep->declBus(c+18,"io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+19,"io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBus(c+80,"io_result_out", false,-1, 31,0);
    tracep->declBit(c+20,"io_branch_taken", false,-1);
    tracep->declBus(c+21,"io_branch_target", false,-1, 31,0);
    tracep->declBus(c+22,"io_jump_target", false,-1, 31,0);
    tracep->declBus(c+78,"alu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"alu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+5,"alu_io_TYpe", false,-1, 3,0);
    tracep->declBus(c+18,"alu_io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+19,"alu_io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+13,"alu_io_imm", false,-1, 31,0);
    tracep->declBus(c+77,"alu_io_pc", false,-1, 31,0);
    tracep->declBus(c+81,"alu_io_result", false,-1, 31,0);
    tracep->declBus(c+18,"branchUnit_io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"branchUnit_io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"branchUnit_io_funct3", false,-1, 2,0);
    tracep->declBus(c+77,"branchUnit_io_pc", false,-1, 31,0);
    tracep->declBus(c+13,"branchUnit_io_imm", false,-1, 31,0);
    tracep->declBit(c+24,"branchUnit_io_taken", false,-1);
    tracep->declBus(c+25,"branchUnit_io_branch_target", false,-1, 31,0);
    tracep->declBus(c+77,"jumpUnit_io_pc", false,-1, 31,0);
    tracep->declBus(c+18,"jumpUnit_io_rs1", false,-1, 31,0);
    tracep->declBus(c+13,"jumpUnit_io_imm", false,-1, 31,0);
    tracep->declBit(c+11,"jumpUnit_io_isJal", false,-1);
    tracep->declBus(c+26,"jumpUnit_io_jump_pc", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+5,"io_TYpe", false,-1, 3,0);
    tracep->declBus(c+18,"io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+19,"io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+13,"io_imm", false,-1, 31,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBus(c+81,"io_result", false,-1, 31,0);
    tracep->declBus(c+18,"addR_io_a", false,-1, 31,0);
    tracep->declBus(c+19,"addR_io_b", false,-1, 31,0);
    tracep->declBus(c+27,"addR_io_sum", false,-1, 31,0);
    tracep->declBus(c+18,"subR_io_a", false,-1, 31,0);
    tracep->declBus(c+19,"subR_io_b", false,-1, 31,0);
    tracep->declBus(c+28,"subR_io_diff", false,-1, 31,0);
    tracep->declBus(c+18,"shftr_io_in", false,-1, 31,0);
    tracep->declBus(c+29,"shftr_io_shamt", false,-1, 4,0);
    tracep->declBus(c+78,"shftr_io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"shftr_io_funct7", false,-1, 6,0);
    tracep->declBus(c+82,"shftr_io_out", false,-1, 31,0);
    tracep->declBus(c+18,"logicU_io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"logicU_io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"logicU_io_funct3", false,-1, 2,0);
    tracep->declBus(c+30,"logicU_io_out", false,-1, 31,0);
    tracep->declBus(c+18,"addI_io_a", false,-1, 31,0);
    tracep->declBus(c+13,"addI_io_b", false,-1, 31,0);
    tracep->declBus(c+31,"addI_io_sum", false,-1, 31,0);
    tracep->declBus(c+18,"addrAdd_io_a", false,-1, 31,0);
    tracep->declBus(c+13,"addrAdd_io_b", false,-1, 31,0);
    tracep->declBus(c+31,"addrAdd_io_sum", false,-1, 31,0);
    tracep->declBus(c+13,"uunit_io_imm", false,-1, 31,0);
    tracep->declBus(c+77,"uunit_io_pc", false,-1, 31,0);
    tracep->declBit(c+14,"uunit_io_isAuipc", false,-1);
    tracep->declBus(c+32,"uunit_io_out", false,-1, 31,0);
    tracep->declBus(c+83,"rtypeRes", false,-1, 31,0);
    tracep->declBus(c+84,"itypeRes", false,-1, 31,0);
    tracep->pushNamePrefix("addI ");
    tracep->declBus(c+18,"io_a", false,-1, 31,0);
    tracep->declBus(c+13,"io_b", false,-1, 31,0);
    tracep->declBus(c+31,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("addR ");
    tracep->declBus(c+18,"io_a", false,-1, 31,0);
    tracep->declBus(c+19,"io_b", false,-1, 31,0);
    tracep->declBus(c+27,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("addrAdd ");
    tracep->declBus(c+18,"io_a", false,-1, 31,0);
    tracep->declBus(c+13,"io_b", false,-1, 31,0);
    tracep->declBus(c+31,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("logicU ");
    tracep->declBus(c+18,"io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+30,"io_out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shftr ");
    tracep->declBus(c+18,"io_in", false,-1, 31,0);
    tracep->declBus(c+29,"io_shamt", false,-1, 4,0);
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+82,"io_out", false,-1, 31,0);
    tracep->declQuad(c+33,"sll", false,-1, 62,0);
    tracep->declBus(c+35,"srl", false,-1, 31,0);
    tracep->declBus(c+36,"sra", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("subR ");
    tracep->declBus(c+18,"io_a", false,-1, 31,0);
    tracep->declBus(c+19,"io_b", false,-1, 31,0);
    tracep->declBus(c+28,"io_diff", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("uunit ");
    tracep->declBus(c+13,"io_imm", false,-1, 31,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBit(c+14,"io_isAuipc", false,-1);
    tracep->declBus(c+32,"io_out", false,-1, 31,0);
    tracep->declQuad(c+15,"luiVal", false,-1, 43,0);
    tracep->declQuad(c+37,"auipcVal", false,-1, 43,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("branchUnit ");
    tracep->declBus(c+18,"io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBus(c+13,"io_imm", false,-1, 31,0);
    tracep->declBit(c+24,"io_taken", false,-1);
    tracep->declBus(c+25,"io_branch_target", false,-1, 31,0);
    tracep->declBus(c+18,"cmp_io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"cmp_io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"cmp_io_funct3", false,-1, 2,0);
    tracep->declBit(c+24,"cmp_io_cmp", false,-1);
    tracep->declBus(c+77,"ad_io_a", false,-1, 31,0);
    tracep->declBus(c+13,"ad_io_b", false,-1, 31,0);
    tracep->declBus(c+25,"ad_io_sum", false,-1, 31,0);
    tracep->pushNamePrefix("ad ");
    tracep->declBus(c+77,"io_a", false,-1, 31,0);
    tracep->declBus(c+13,"io_b", false,-1, 31,0);
    tracep->declBus(c+25,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cmp ");
    tracep->declBus(c+18,"io_in1", false,-1, 31,0);
    tracep->declBus(c+19,"io_in2", false,-1, 31,0);
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBit(c+24,"io_cmp", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("jumpUnit ");
    tracep->declBus(c+77,"io_pc", false,-1, 31,0);
    tracep->declBus(c+18,"io_rs1", false,-1, 31,0);
    tracep->declBus(c+13,"io_imm", false,-1, 31,0);
    tracep->declBit(c+11,"io_isJal", false,-1);
    tracep->declBus(c+26,"io_jump_pc", false,-1, 31,0);
    tracep->declBus(c+77,"adJal_io_a", false,-1, 31,0);
    tracep->declBus(c+13,"adJal_io_b", false,-1, 31,0);
    tracep->declBus(c+25,"adJal_io_sum", false,-1, 31,0);
    tracep->declBus(c+18,"adJalr_io_a", false,-1, 31,0);
    tracep->declBus(c+13,"adJalr_io_b", false,-1, 31,0);
    tracep->declBus(c+31,"adJalr_io_sum", false,-1, 31,0);
    tracep->declBus(c+39,"jalrAligned", false,-1, 31,0);
    tracep->pushNamePrefix("adJal ");
    tracep->declBus(c+77,"io_a", false,-1, 31,0);
    tracep->declBus(c+13,"io_b", false,-1, 31,0);
    tracep->declBus(c+25,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("adJalr ");
    tracep->declBus(c+18,"io_a", false,-1, 31,0);
    tracep->declBus(c+13,"io_b", false,-1, 31,0);
    tracep->declBus(c+31,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+76,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+1,"io_rs1", false,-1, 4,0);
    tracep->declBus(c+2,"io_rs2", false,-1, 4,0);
    tracep->declBus(c+3,"io_rd", false,-1, 4,0);
    tracep->declBus(c+78,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+79,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+4,"io_imm", false,-1, 11,0);
    tracep->declBus(c+5,"io_TYpe", false,-1, 3,0);
    tracep->declBit(c+6,"io_IsIllegal", false,-1);
    tracep->declBit(c+7,"io_IsInterrupt", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regFile ");
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+75,"reset", false,-1);
    tracep->declBus(c+1,"io_rs1", false,-1, 4,0);
    tracep->declBus(c+2,"io_rs2", false,-1, 4,0);
    tracep->declBus(c+3,"io_rd", false,-1, 4,0);
    tracep->declBus(c+17,"io_writeData", false,-1, 31,0);
    tracep->declBit(c+8,"io_writeEnable", false,-1);
    tracep->declBus(c+18,"io_regData1", false,-1, 31,0);
    tracep->declBus(c+19,"io_regData2", false,-1, 31,0);
    tracep->declBus(c+42,"regFile_0", false,-1, 31,0);
    tracep->declBus(c+43,"regFile_1", false,-1, 31,0);
    tracep->declBus(c+44,"regFile_2", false,-1, 31,0);
    tracep->declBus(c+45,"regFile_3", false,-1, 31,0);
    tracep->declBus(c+46,"regFile_4", false,-1, 31,0);
    tracep->declBus(c+47,"regFile_5", false,-1, 31,0);
    tracep->declBus(c+48,"regFile_6", false,-1, 31,0);
    tracep->declBus(c+49,"regFile_7", false,-1, 31,0);
    tracep->declBus(c+50,"regFile_8", false,-1, 31,0);
    tracep->declBus(c+51,"regFile_9", false,-1, 31,0);
    tracep->declBus(c+52,"regFile_10", false,-1, 31,0);
    tracep->declBus(c+53,"regFile_11", false,-1, 31,0);
    tracep->declBus(c+54,"regFile_12", false,-1, 31,0);
    tracep->declBus(c+55,"regFile_13", false,-1, 31,0);
    tracep->declBus(c+56,"regFile_14", false,-1, 31,0);
    tracep->declBus(c+57,"regFile_15", false,-1, 31,0);
    tracep->declBus(c+58,"regFile_16", false,-1, 31,0);
    tracep->declBus(c+59,"regFile_17", false,-1, 31,0);
    tracep->declBus(c+60,"regFile_18", false,-1, 31,0);
    tracep->declBus(c+61,"regFile_19", false,-1, 31,0);
    tracep->declBus(c+62,"regFile_20", false,-1, 31,0);
    tracep->declBus(c+63,"regFile_21", false,-1, 31,0);
    tracep->declBus(c+64,"regFile_22", false,-1, 31,0);
    tracep->declBus(c+65,"regFile_23", false,-1, 31,0);
    tracep->declBus(c+66,"regFile_24", false,-1, 31,0);
    tracep->declBus(c+67,"regFile_25", false,-1, 31,0);
    tracep->declBus(c+68,"regFile_26", false,-1, 31,0);
    tracep->declBus(c+69,"regFile_27", false,-1, 31,0);
    tracep->declBus(c+70,"regFile_28", false,-1, 31,0);
    tracep->declBus(c+71,"regFile_29", false,-1, 31,0);
    tracep->declBus(c+72,"regFile_30", false,-1, 31,0);
    tracep->declBus(c+73,"regFile_31", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__idu_io_rs1),5);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__idu_io_rs2),5);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__idu_io_rd),5);
    bufp->fullSData(oldp+4,((0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36)),12);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__exu__DOT__alu_io_TYpe),4);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__idu_io_IsIllegal));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__idu_io_IsInterrupt));
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__regFile_io_writeEnable));
    bufp->fullBit(oldp+9,((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullBit(oldp+10,((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullBit(oldp+11,((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullBit(oldp+12,((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullIData(oldp+13,((0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36)),32);
    bufp->fullBit(oldp+14,((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullQData(oldp+15,(((QData)((IData)((0xfffU 
                                               & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                              << 0xcU)),44);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__regFile_io_writeData),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b),32);
    bufp->fullBit(oldp+20,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                            & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))));
    bufp->fullIData(oldp+21,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                               ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                               : 0U)),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__exu_io_jump_target),32);
    bufp->fullIData(oldp+23,((((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                               & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                               ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                   ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                   : 0U) : ((IData)(4U) 
                                            + vlSelf->top__DOT__pc))),32);
    bufp->fullBit(oldp+24,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp));
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc),32);
    bufp->fullIData(oldp+27,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
    bufp->fullIData(oldp+28,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
    bufp->fullCData(oldp+29,((0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),5);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum),32);
    bufp->fullIData(oldp+32,((IData)((0xfffffffffffULL 
                                      & ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                          ? ((QData)((IData)(vlSelf->top__DOT__pc)) 
                                             + ((QData)((IData)(
                                                                (0xfffU 
                                                                 & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                                                << 0xcU))
                                          : ((QData)((IData)(
                                                             (0xfffU 
                                                              & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                                             << 0xcU))))),32);
    bufp->fullQData(oldp+33,((0x7fffffffffffffffULL 
                              & ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                 << (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))),63);
    bufp->fullIData(oldp+35,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              >> (0x1fU & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))),32);
    bufp->fullIData(oldp+36,(VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                            (0x1fU 
                                             & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))),32);
    bufp->fullQData(oldp+37,((0xfffffffffffULL & ((QData)((IData)(vlSelf->top__DOT__pc)) 
                                                  + 
                                                  ((QData)((IData)(
                                                                   (0xfffU 
                                                                    & vlSelf->top__DOT__idu__DOT___io_imm_T_36))) 
                                                   << 0xcU)))),44);
    bufp->fullIData(oldp+39,((0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+41,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regFile__DOT__regFile_0),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regFile__DOT__regFile_1),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regFile__DOT__regFile_2),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regFile__DOT__regFile_3),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regFile__DOT__regFile_4),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regFile__DOT__regFile_5),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regFile__DOT__regFile_6),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regFile__DOT__regFile_7),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regFile__DOT__regFile_8),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regFile__DOT__regFile_9),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regFile__DOT__regFile_10),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regFile__DOT__regFile_11),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regFile__DOT__regFile_12),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regFile__DOT__regFile_13),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regFile__DOT__regFile_14),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regFile__DOT__regFile_15),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regFile__DOT__regFile_16),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regFile__DOT__regFile_17),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regFile__DOT__regFile_18),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regFile__DOT__regFile_19),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regFile__DOT__regFile_20),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regFile__DOT__regFile_21),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regFile__DOT__regFile_22),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regFile__DOT__regFile_23),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regFile__DOT__regFile_24),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regFile__DOT__regFile_25),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regFile__DOT__regFile_26),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regFile__DOT__regFile_27),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regFile__DOT__regFile_28),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regFile__DOT__regFile_29),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regFile__DOT__regFile_30),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regFile__DOT__regFile_31),32);
    bufp->fullBit(oldp+74,(vlSelf->clock));
    bufp->fullBit(oldp+75,(vlSelf->reset));
    bufp->fullIData(oldp+76,(vlSelf->io_instruction),32);
    bufp->fullIData(oldp+77,(vlSelf->io_pc),32);
    bufp->fullCData(oldp+78,((7U & (vlSelf->io_instruction 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+79,((vlSelf->io_instruction 
                              >> 0x19U)),7);
    bufp->fullIData(oldp+80,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                               ? (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp)
                               : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                   ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                   : ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                       ? vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc
                                       : ((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                           ? 0U : (
                                                   (6U 
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
                                                      : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7)))))))),32);
    bufp->fullIData(oldp+81,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
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
                                                  : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_7))))),32);
    bufp->fullIData(oldp+82,((IData)((0x7fffffffffffffffULL 
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
    bufp->fullIData(oldp+83,(((7U == (7U & (vlSelf->io_instruction 
                                            >> 0xcU)))
                               ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                               : ((6U == (7U & (vlSelf->io_instruction 
                                                >> 0xcU)))
                                   ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                   : ((5U == (7U & 
                                              (vlSelf->io_instruction 
                                               >> 0xcU)))
                                       ? vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1
                                       : ((4U == (7U 
                                                  & (vlSelf->io_instruction 
                                                     >> 0xcU)))
                                           ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                           : ((3U == 
                                               (7U 
                                                & (vlSelf->io_instruction 
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
    bufp->fullIData(oldp+84,(((7U == (7U & (vlSelf->io_instruction 
                                            >> 0xcU)))
                               ? (0xfffU & (vlSelf->top__DOT__idu__DOT___io_imm_T_36 
                                            & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a))
                               : ((6U == (7U & (vlSelf->io_instruction 
                                                >> 0xcU)))
                                   ? ((0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36) 
                                      | vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                   : ((4U == (7U & 
                                              (vlSelf->io_instruction 
                                               >> 0xcU)))
                                       ? ((0xfffU & vlSelf->top__DOT__idu__DOT___io_imm_T_36) 
                                          ^ vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)
                                       : ((3U == (7U 
                                                  & (vlSelf->io_instruction 
                                                     >> 0xcU)))
                                           ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                              < (0xfffU 
                                                 & vlSelf->top__DOT__idu__DOT___io_imm_T_36))
                                           : ((2U == 
                                               (7U 
                                                & (vlSelf->io_instruction 
                                                   >> 0xcU)))
                                               ? VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                                            (0xfffU 
                                                             & vlSelf->top__DOT__idu__DOT___io_imm_T_36))
                                               : ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->io_instruction 
                                                       >> 0xcU)))
                                                   ? vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum
                                                   : 0U))))))),32);
}

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
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBit(c+94,"reset", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBit(c+94,"reset", false,-1);
    tracep->declBit(c+93,"ifu_clock", false,-1);
    tracep->declBus(c+1,"ifu_io_pc", false,-1, 31,0);
    tracep->declBit(c+2,"ifu_io_valid", false,-1);
    tracep->declBus(c+3,"ifu_io_inst", false,-1, 31,0);
    tracep->declBus(c+3,"idu_io_instruction", false,-1, 31,0);
    tracep->declBus(c+4,"idu_io_rs1", false,-1, 4,0);
    tracep->declBus(c+5,"idu_io_rs2", false,-1, 4,0);
    tracep->declBus(c+6,"idu_io_rd", false,-1, 4,0);
    tracep->declBus(c+7,"idu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"idu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+9,"idu_io_imm", false,-1, 31,0);
    tracep->declBus(c+10,"idu_io_TYpe", false,-1, 3,0);
    tracep->declBit(c+11,"idu_io_IsIllegal", false,-1);
    tracep->declBit(c+12,"idu_io_IsInterrupt", false,-1);
    tracep->declBit(c+13,"idu_io_isAuipc", false,-1);
    tracep->declBit(c+93,"regFile_clock", false,-1);
    tracep->declBit(c+94,"regFile_reset", false,-1);
    tracep->declBus(c+4,"regFile_io_rs1", false,-1, 4,0);
    tracep->declBus(c+5,"regFile_io_rs2", false,-1, 4,0);
    tracep->declBus(c+6,"regFile_io_rd", false,-1, 4,0);
    tracep->declBus(c+14,"regFile_io_writeData", false,-1, 31,0);
    tracep->declBit(c+15,"regFile_io_writeEnable", false,-1);
    tracep->declBus(c+16,"regFile_io_regData1", false,-1, 31,0);
    tracep->declBus(c+17,"regFile_io_regData2", false,-1, 31,0);
    tracep->declBus(c+7,"exu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"exu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+9,"exu_io_imm", false,-1, 31,0);
    tracep->declBus(c+10,"exu_io_TYpe", false,-1, 3,0);
    tracep->declBus(c+16,"exu_io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+17,"exu_io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+1,"exu_io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"exu_io_isAuipc", false,-1);
    tracep->declBus(c+18,"exu_io_result_out", false,-1, 31,0);
    tracep->declBit(c+19,"exu_io_branch_taken", false,-1);
    tracep->declBus(c+20,"exu_io_branch_target", false,-1, 31,0);
    tracep->declBus(c+21,"exu_io_jump_target", false,-1, 31,0);
    tracep->declBit(c+11,"dpiHandlers_IsIllegal", false,-1);
    tracep->declBit(c+12,"dpiHandlers_IsInterrupt", false,-1);
    tracep->declBit(c+93,"pmemD_clock", false,-1);
    tracep->declBit(c+22,"pmemD_valid", false,-1);
    tracep->declBit(c+23,"pmemD_wen", false,-1);
    tracep->declBus(c+24,"pmemD_wmask", false,-1, 3,0);
    tracep->declBus(c+18,"pmemD_raddr", false,-1, 31,0);
    tracep->declBus(c+18,"pmemD_waddr", false,-1, 31,0);
    tracep->declBus(c+17,"pmemD_wdata", false,-1, 31,0);
    tracep->declBus(c+25,"pmemD_rdata", false,-1, 31,0);
    tracep->declBus(c+1,"pc", false,-1, 31,0);
    tracep->declBus(c+26,"pcPlus4", false,-1, 31,0);
    tracep->declBit(c+2,"valid", false,-1);
    tracep->declBit(c+27,"isLoad", false,-1);
    tracep->declBit(c+23,"isStore", false,-1);
    tracep->declBus(c+28,"byteOffset", false,-1, 1,0);
    tracep->declBus(c+29,"byteOff", false,-1, 31,0);
    tracep->declBus(c+30,"halfOff", false,-1, 15,0);
    tracep->declBus(c+31,"lbValue", false,-1, 31,0);
    tracep->declBus(c+32,"lbuValue", false,-1, 31,0);
    tracep->declBus(c+33,"lhValue", false,-1, 31,0);
    tracep->declBus(c+34,"lhuValue", false,-1, 31,0);
    tracep->declBus(c+35,"loadData", false,-1, 31,0);
    tracep->declBit(c+36,"isBranch", false,-1);
    tracep->declBit(c+37,"isJal", false,-1);
    tracep->declBit(c+38,"isJalr", false,-1);
    tracep->declBus(c+39,"branchTarget", false,-1, 31,0);
    tracep->pushNamePrefix("dpiHandlers ");
    tracep->declBit(c+11,"IsIllegal", false,-1);
    tracep->declBit(c+12,"IsInterrupt", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBus(c+10,"io_TYpe", false,-1, 3,0);
    tracep->declBus(c+16,"io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+17,"io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"io_isAuipc", false,-1);
    tracep->declBus(c+18,"io_result_out", false,-1, 31,0);
    tracep->declBit(c+19,"io_branch_taken", false,-1);
    tracep->declBus(c+20,"io_branch_target", false,-1, 31,0);
    tracep->declBus(c+21,"io_jump_target", false,-1, 31,0);
    tracep->declBus(c+7,"alu_io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"alu_io_funct7", false,-1, 6,0);
    tracep->declBus(c+10,"alu_io_TYpe", false,-1, 3,0);
    tracep->declBus(c+16,"alu_io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+17,"alu_io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+9,"alu_io_imm", false,-1, 31,0);
    tracep->declBus(c+1,"alu_io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"alu_io_isAuipc", false,-1);
    tracep->declBus(c+40,"alu_io_result", false,-1, 31,0);
    tracep->declBus(c+16,"branchUnit_io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"branchUnit_io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"branchUnit_io_funct3", false,-1, 2,0);
    tracep->declBus(c+1,"branchUnit_io_pc", false,-1, 31,0);
    tracep->declBus(c+9,"branchUnit_io_imm", false,-1, 31,0);
    tracep->declBit(c+41,"branchUnit_io_taken", false,-1);
    tracep->declBus(c+42,"branchUnit_io_branch_target", false,-1, 31,0);
    tracep->declBus(c+1,"jumpUnit_io_pc", false,-1, 31,0);
    tracep->declBus(c+16,"jumpUnit_io_rs1", false,-1, 31,0);
    tracep->declBus(c+9,"jumpUnit_io_imm", false,-1, 31,0);
    tracep->declBit(c+37,"jumpUnit_io_isJal", false,-1);
    tracep->declBus(c+43,"jumpUnit_io_jump_pc", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+10,"io_TYpe", false,-1, 3,0);
    tracep->declBus(c+16,"io_reg_rs1", false,-1, 31,0);
    tracep->declBus(c+17,"io_reg_rs2", false,-1, 31,0);
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"io_isAuipc", false,-1);
    tracep->declBus(c+40,"io_result", false,-1, 31,0);
    tracep->declBus(c+16,"addR_io_a", false,-1, 31,0);
    tracep->declBus(c+17,"addR_io_b", false,-1, 31,0);
    tracep->declBus(c+44,"addR_io_sum", false,-1, 31,0);
    tracep->declBus(c+16,"subR_io_a", false,-1, 31,0);
    tracep->declBus(c+17,"subR_io_b", false,-1, 31,0);
    tracep->declBus(c+45,"subR_io_diff", false,-1, 31,0);
    tracep->declBus(c+16,"shftr_io_in", false,-1, 31,0);
    tracep->declBus(c+46,"shftr_io_shamt", false,-1, 4,0);
    tracep->declBus(c+7,"shftr_io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"shftr_io_funct7", false,-1, 6,0);
    tracep->declBus(c+47,"shftr_io_out", false,-1, 31,0);
    tracep->declBus(c+16,"logicU_io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"logicU_io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"logicU_io_funct3", false,-1, 2,0);
    tracep->declBus(c+48,"logicU_io_out", false,-1, 31,0);
    tracep->declBus(c+16,"addI_io_a", false,-1, 31,0);
    tracep->declBus(c+9,"addI_io_b", false,-1, 31,0);
    tracep->declBus(c+49,"addI_io_sum", false,-1, 31,0);
    tracep->declBus(c+16,"addrAdd_io_a", false,-1, 31,0);
    tracep->declBus(c+9,"addrAdd_io_b", false,-1, 31,0);
    tracep->declBus(c+49,"addrAdd_io_sum", false,-1, 31,0);
    tracep->declBus(c+9,"uunit_io_imm", false,-1, 31,0);
    tracep->declBus(c+1,"uunit_io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"uunit_io_isAuipc", false,-1);
    tracep->declBus(c+50,"uunit_io_out", false,-1, 31,0);
    tracep->declBit(c+51,"isIShift", false,-1);
    tracep->declBus(c+52,"rtypeRes", false,-1, 31,0);
    tracep->declBus(c+53,"itypeRes", false,-1, 31,0);
    tracep->pushNamePrefix("addI ");
    tracep->declBus(c+16,"io_a", false,-1, 31,0);
    tracep->declBus(c+9,"io_b", false,-1, 31,0);
    tracep->declBus(c+49,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("addR ");
    tracep->declBus(c+16,"io_a", false,-1, 31,0);
    tracep->declBus(c+17,"io_b", false,-1, 31,0);
    tracep->declBus(c+44,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("addrAdd ");
    tracep->declBus(c+16,"io_a", false,-1, 31,0);
    tracep->declBus(c+9,"io_b", false,-1, 31,0);
    tracep->declBus(c+49,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("logicU ");
    tracep->declBus(c+16,"io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+48,"io_out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shftr ");
    tracep->declBus(c+16,"io_in", false,-1, 31,0);
    tracep->declBus(c+46,"io_shamt", false,-1, 4,0);
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+47,"io_out", false,-1, 31,0);
    tracep->declQuad(c+54,"sll", false,-1, 62,0);
    tracep->declBus(c+56,"srl", false,-1, 31,0);
    tracep->declBus(c+57,"sra", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("subR ");
    tracep->declBus(c+16,"io_a", false,-1, 31,0);
    tracep->declBus(c+17,"io_b", false,-1, 31,0);
    tracep->declBus(c+45,"io_diff", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("uunit ");
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBit(c+13,"io_isAuipc", false,-1);
    tracep->declBus(c+50,"io_out", false,-1, 31,0);
    tracep->declBus(c+58,"auipcVal", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("branchUnit ");
    tracep->declBus(c+16,"io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBit(c+41,"io_taken", false,-1);
    tracep->declBus(c+42,"io_branch_target", false,-1, 31,0);
    tracep->declBus(c+16,"cmp_io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"cmp_io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"cmp_io_funct3", false,-1, 2,0);
    tracep->declBit(c+41,"cmp_io_cmp", false,-1);
    tracep->declBus(c+1,"ad_io_a", false,-1, 31,0);
    tracep->declBus(c+9,"ad_io_b", false,-1, 31,0);
    tracep->declBus(c+42,"ad_io_sum", false,-1, 31,0);
    tracep->pushNamePrefix("ad ");
    tracep->declBus(c+1,"io_a", false,-1, 31,0);
    tracep->declBus(c+9,"io_b", false,-1, 31,0);
    tracep->declBus(c+42,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cmp ");
    tracep->declBus(c+16,"io_in1", false,-1, 31,0);
    tracep->declBus(c+17,"io_in2", false,-1, 31,0);
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBit(c+41,"io_cmp", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("jumpUnit ");
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBus(c+16,"io_rs1", false,-1, 31,0);
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBit(c+37,"io_isJal", false,-1);
    tracep->declBus(c+43,"io_jump_pc", false,-1, 31,0);
    tracep->declBus(c+1,"adJal_io_a", false,-1, 31,0);
    tracep->declBus(c+9,"adJal_io_b", false,-1, 31,0);
    tracep->declBus(c+42,"adJal_io_sum", false,-1, 31,0);
    tracep->declBus(c+16,"adJalr_io_a", false,-1, 31,0);
    tracep->declBus(c+9,"adJalr_io_b", false,-1, 31,0);
    tracep->declBus(c+49,"adJalr_io_sum", false,-1, 31,0);
    tracep->declBus(c+59,"jalrAligned", false,-1, 31,0);
    tracep->pushNamePrefix("adJal ");
    tracep->declBus(c+1,"io_a", false,-1, 31,0);
    tracep->declBus(c+9,"io_b", false,-1, 31,0);
    tracep->declBus(c+42,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("adJalr ");
    tracep->declBus(c+16,"io_a", false,-1, 31,0);
    tracep->declBus(c+9,"io_b", false,-1, 31,0);
    tracep->declBus(c+49,"io_sum", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+3,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+4,"io_rs1", false,-1, 4,0);
    tracep->declBus(c+5,"io_rs2", false,-1, 4,0);
    tracep->declBus(c+6,"io_rd", false,-1, 4,0);
    tracep->declBus(c+7,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+8,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+9,"io_imm", false,-1, 31,0);
    tracep->declBus(c+10,"io_TYpe", false,-1, 3,0);
    tracep->declBit(c+11,"io_IsIllegal", false,-1);
    tracep->declBit(c+12,"io_IsInterrupt", false,-1);
    tracep->declBit(c+13,"io_isAuipc", false,-1);
    tracep->declBus(c+60,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBus(c+1,"io_pc", false,-1, 31,0);
    tracep->declBit(c+2,"io_valid", false,-1);
    tracep->declBus(c+3,"io_inst", false,-1, 31,0);
    tracep->declBit(c+93,"pmem_clock", false,-1);
    tracep->declBit(c+2,"pmem_valid", false,-1);
    tracep->declBit(c+95,"pmem_wen", false,-1);
    tracep->declBus(c+96,"pmem_wmask", false,-1, 3,0);
    tracep->declBus(c+1,"pmem_raddr", false,-1, 31,0);
    tracep->declBus(c+97,"pmem_waddr", false,-1, 31,0);
    tracep->declBus(c+97,"pmem_wdata", false,-1, 31,0);
    tracep->declBus(c+3,"pmem_rdata", false,-1, 31,0);
    tracep->pushNamePrefix("pmem ");
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBit(c+2,"valid", false,-1);
    tracep->declBit(c+95,"wen", false,-1);
    tracep->declBus(c+96,"wmask", false,-1, 3,0);
    tracep->declBus(c+1,"raddr", false,-1, 31,0);
    tracep->declBus(c+97,"waddr", false,-1, 31,0);
    tracep->declBus(c+97,"wdata", false,-1, 31,0);
    tracep->declBus(c+3,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pmemD ");
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBit(c+22,"valid", false,-1);
    tracep->declBit(c+23,"wen", false,-1);
    tracep->declBus(c+24,"wmask", false,-1, 3,0);
    tracep->declBus(c+18,"raddr", false,-1, 31,0);
    tracep->declBus(c+18,"waddr", false,-1, 31,0);
    tracep->declBus(c+17,"wdata", false,-1, 31,0);
    tracep->declBus(c+25,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regFile ");
    tracep->declBit(c+93,"clock", false,-1);
    tracep->declBit(c+94,"reset", false,-1);
    tracep->declBus(c+4,"io_rs1", false,-1, 4,0);
    tracep->declBus(c+5,"io_rs2", false,-1, 4,0);
    tracep->declBus(c+6,"io_rd", false,-1, 4,0);
    tracep->declBus(c+14,"io_writeData", false,-1, 31,0);
    tracep->declBit(c+15,"io_writeEnable", false,-1);
    tracep->declBus(c+16,"io_regData1", false,-1, 31,0);
    tracep->declBus(c+17,"io_regData2", false,-1, 31,0);
    tracep->declBus(c+61,"regFile_0", false,-1, 31,0);
    tracep->declBus(c+62,"regFile_1", false,-1, 31,0);
    tracep->declBus(c+63,"regFile_2", false,-1, 31,0);
    tracep->declBus(c+64,"regFile_3", false,-1, 31,0);
    tracep->declBus(c+65,"regFile_4", false,-1, 31,0);
    tracep->declBus(c+66,"regFile_5", false,-1, 31,0);
    tracep->declBus(c+67,"regFile_6", false,-1, 31,0);
    tracep->declBus(c+68,"regFile_7", false,-1, 31,0);
    tracep->declBus(c+69,"regFile_8", false,-1, 31,0);
    tracep->declBus(c+70,"regFile_9", false,-1, 31,0);
    tracep->declBus(c+71,"regFile_10", false,-1, 31,0);
    tracep->declBus(c+72,"regFile_11", false,-1, 31,0);
    tracep->declBus(c+73,"regFile_12", false,-1, 31,0);
    tracep->declBus(c+74,"regFile_13", false,-1, 31,0);
    tracep->declBus(c+75,"regFile_14", false,-1, 31,0);
    tracep->declBus(c+76,"regFile_15", false,-1, 31,0);
    tracep->declBus(c+77,"regFile_16", false,-1, 31,0);
    tracep->declBus(c+78,"regFile_17", false,-1, 31,0);
    tracep->declBus(c+79,"regFile_18", false,-1, 31,0);
    tracep->declBus(c+80,"regFile_19", false,-1, 31,0);
    tracep->declBus(c+81,"regFile_20", false,-1, 31,0);
    tracep->declBus(c+82,"regFile_21", false,-1, 31,0);
    tracep->declBus(c+83,"regFile_22", false,-1, 31,0);
    tracep->declBus(c+84,"regFile_23", false,-1, 31,0);
    tracep->declBus(c+85,"regFile_24", false,-1, 31,0);
    tracep->declBus(c+86,"regFile_25", false,-1, 31,0);
    tracep->declBus(c+87,"regFile_26", false,-1, 31,0);
    tracep->declBus(c+88,"regFile_27", false,-1, 31,0);
    tracep->declBus(c+89,"regFile_28", false,-1, 31,0);
    tracep->declBus(c+90,"regFile_29", false,-1, 31,0);
    tracep->declBus(c+91,"regFile_30", false,-1, 31,0);
    tracep->declBus(c+92,"regFile_31", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__pc),32);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__valid));
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__ifu__DOT__pmem_rdata),32);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__idu_io_rs1),5);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__idu_io_rs2),5);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__idu_io_rd),5);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3),3);
    bufp->fullCData(oldp+8,(((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                              ? 0U : (vlSelf->top__DOT__ifu__DOT__pmem_rdata 
                                      >> 0x19U))),7);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b),32);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__exu__DOT__alu_io_TYpe),4);
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__idu_io_IsIllegal));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__idu_io_IsInterrupt));
    bufp->fullBit(oldp+13,((0x17U == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))));
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__regFile_io_writeData),32);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__regFile_io_writeEnable));
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__exu_io_result_out),32);
    bufp->fullBit(oldp+19,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                            & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))));
    bufp->fullIData(oldp+20,(((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                               ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                               : 0U)),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__exu_io_jump_target),32);
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__pmemD_valid));
    bufp->fullBit(oldp+23,((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullCData(oldp+24,(vlSelf->top__DOT__pmemD_wmask),4);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__pmemD_rdata),32);
    bufp->fullIData(oldp+26,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullBit(oldp+27,((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullCData(oldp+28,((3U & vlSelf->top__DOT__exu_io_result_out)),2);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__byteOff),32);
    bufp->fullSData(oldp+30,((0xffffU & vlSelf->top__DOT__byteOff)),16);
    bufp->fullIData(oldp+31,(((((0x80U & vlSelf->top__DOT__byteOff)
                                 ? 0xffffffU : 0U) 
                               << 8U) | (0xffU & vlSelf->top__DOT__byteOff))),32);
    bufp->fullIData(oldp+32,((0xffU & vlSelf->top__DOT__byteOff)),32);
    bufp->fullIData(oldp+33,(((((0x8000U & vlSelf->top__DOT__byteOff)
                                 ? 0xffffU : 0U) << 0x10U) 
                              | (0xffffU & vlSelf->top__DOT__byteOff))),32);
    bufp->fullIData(oldp+34,((0xffffU & vlSelf->top__DOT__byteOff)),32);
    bufp->fullIData(oldp+35,(((2U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
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
                                           : ((0U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                               ? ((
                                                   ((0x80U 
                                                     & vlSelf->top__DOT__byteOff)
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   << 8U) 
                                                  | (0xffU 
                                                     & vlSelf->top__DOT__byteOff))
                                               : 0U)))))),32);
    bufp->fullBit(oldp+36,((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullBit(oldp+37,((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullBit(oldp+38,((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))));
    bufp->fullIData(oldp+39,((((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                               & (IData)(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp))
                               ? ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                   ? vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum
                                   : 0U) : ((IData)(4U) 
                                            + vlSelf->top__DOT__pc))),32);
    bufp->fullIData(oldp+40,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                               ? 0U : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                        ? 0U : ((5U 
                                                 == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe))
                                                 ? 
                                                ((0x17U 
                                                  == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                                                  ? 
                                                 (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                                  + vlSelf->top__DOT__pc)
                                                  : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                 : vlSelf->top__DOT__exu__DOT__alu__DOT___io_result_T_9)))),32);
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp));
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__exu__DOT__jumpUnit_io_jump_pc),32);
    bufp->fullIData(oldp+44,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              + vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
    bufp->fullIData(oldp+45,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              - vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)),32);
    bufp->fullCData(oldp+46,(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt),5);
    bufp->fullIData(oldp+47,((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum),32);
    bufp->fullIData(oldp+50,(((0x17U == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h1ab2847e__0))
                               ? (vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                                  + vlSelf->top__DOT__pc)
                               : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)),32);
    bufp->fullBit(oldp+51,(((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu_io_TYpe)) 
                            & ((1U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3)) 
                               | (5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))))));
    bufp->fullIData(oldp+52,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                               ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                               : ((6U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                   ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                   : ((5U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                       ? ((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT____VdfgTmp_hbf81ac49__0)
                                           ? VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, 
                                                            (0x1fU 
                                                             & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b))
                                           : (vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                                              >> (0x1fU 
                                                  & vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_b)))
                                       : ((4U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                           ? vlSelf->top__DOT__exu__DOT__alu__DOT__logicU_io_out
                                           : ((3U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                               ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5)
                                               : ((2U 
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
    bufp->fullIData(oldp+53,(((7U == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
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
                                               : ((2U 
                                                   == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                   ? 
                                                  VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b)
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_funct3))
                                                    ? (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_5)
                                                    : vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)))))))),32);
    bufp->fullQData(oldp+54,((0x7fffffffffffffffULL 
                              & ((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a)) 
                                 << (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt)))),63);
    bufp->fullIData(oldp+56,((vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a 
                              >> (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))),32);
    bufp->fullIData(oldp+57,(VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu__DOT__addR_io_a, (IData)(vlSelf->top__DOT__exu__DOT__alu__DOT__shftr_io_shamt))),32);
    bufp->fullIData(oldp+58,((vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_b 
                              + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+59,((0xfffffffeU & vlSelf->top__DOT__exu__DOT__alu__DOT__addI_io_sum)),32);
    bufp->fullIData(oldp+60,(((0U == vlSelf->top__DOT__ifu__DOT__pmem_rdata)
                               ? 0x13U : vlSelf->top__DOT__ifu__DOT__pmem_rdata)),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regFile__DOT__regFile_0),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regFile__DOT__regFile_1),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regFile__DOT__regFile_2),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regFile__DOT__regFile_3),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regFile__DOT__regFile_4),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regFile__DOT__regFile_5),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regFile__DOT__regFile_6),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regFile__DOT__regFile_7),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regFile__DOT__regFile_8),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regFile__DOT__regFile_9),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regFile__DOT__regFile_10),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regFile__DOT__regFile_11),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regFile__DOT__regFile_12),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regFile__DOT__regFile_13),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regFile__DOT__regFile_14),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regFile__DOT__regFile_15),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regFile__DOT__regFile_16),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regFile__DOT__regFile_17),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regFile__DOT__regFile_18),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regFile__DOT__regFile_19),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regFile__DOT__regFile_20),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regFile__DOT__regFile_21),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regFile__DOT__regFile_22),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regFile__DOT__regFile_23),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regFile__DOT__regFile_24),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regFile__DOT__regFile_25),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regFile__DOT__regFile_26),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regFile__DOT__regFile_27),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regFile__DOT__regFile_28),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regFile__DOT__regFile_29),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regFile__DOT__regFile_30),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regFile__DOT__regFile_31),32);
    bufp->fullBit(oldp+93,(vlSelf->clock));
    bufp->fullBit(oldp+94,(vlSelf->reset));
    bufp->fullBit(oldp+95,(0U));
    bufp->fullCData(oldp+96,(0U),4);
    bufp->fullIData(oldp+97,(0U),32);
}

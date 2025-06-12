// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        CData/*0:0*/ top__DOT__idu_io_IsIllegal;
        CData/*0:0*/ top__DOT__idu_io_IsInterrupt;
        VL_IN8(reset,0,0);
        CData/*4:0*/ top__DOT__idu_io_rs1;
        CData/*4:0*/ top__DOT__idu_io_rs2;
        CData/*4:0*/ top__DOT__idu_io_rd;
        CData/*0:0*/ top__DOT__regFile_io_writeEnable;
        CData/*3:0*/ top__DOT__exu__DOT__alu_io_TYpe;
        CData/*0:0*/ top__DOT__exu__DOT__alu__DOT___rtypeRes_T_4;
        CData/*0:0*/ top__DOT__exu__DOT__alu__DOT___rtypeRes_T_5;
        CData/*0:0*/ top__DOT__exu__DOT__branchUnit__DOT__cmp_io_cmp;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__idu_io_IsIllegal;
        CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__idu_io_IsInterrupt;
        CData/*0:0*/ __VactContinue;
        VL_IN(io_instruction,31,0);
        VL_OUT(io_pc,31,0);
        IData/*31:0*/ top__DOT__regFile_io_writeData;
        IData/*31:0*/ top__DOT__exu_io_jump_target;
        IData/*31:0*/ top__DOT__pc;
        IData/*31:0*/ top__DOT__pc_snpc;
        IData/*31:0*/ top__DOT__branchPath;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_0;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_1;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_2;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_3;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_4;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_5;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_6;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_7;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_8;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_9;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_10;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_11;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_12;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_13;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_14;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_15;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_16;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_17;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_18;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_19;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_20;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_21;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_22;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_23;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_24;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_25;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_26;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_27;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_28;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_29;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_30;
        IData/*31:0*/ top__DOT__regFile__DOT__regFile_31;
        IData/*31:0*/ top__DOT__exu__DOT__jumpUnit_io_jump_pc;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__addR_io_a;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__addR_io_b;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__logicU_io_out;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__addI_io_b;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__addI_io_sum;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT___io_result_T_7;
        IData/*31:0*/ top__DOT__exu__DOT__alu__DOT__shftr__DOT___io_out_T_1;
        IData/*31:0*/ top__DOT__exu__DOT__branchUnit__DOT__ad_io_sum;
    };
    struct {
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

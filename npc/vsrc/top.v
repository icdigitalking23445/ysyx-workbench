module IFU(
  input         clock,
  input  [31:0] io_pc,
  input         io_valid,
  output [31:0] io_inst
);
  wire  pmem_clock; // @[ifu.scala 20:20]
  wire  pmem_valid; // @[ifu.scala 20:20]
  wire  pmem_wen; // @[ifu.scala 20:20]
  wire [3:0] pmem_wmask; // @[ifu.scala 20:20]
  wire [31:0] pmem_raddr; // @[ifu.scala 20:20]
  wire [31:0] pmem_waddr; // @[ifu.scala 20:20]
  wire [31:0] pmem_wdata; // @[ifu.scala 20:20]
  wire [31:0] pmem_rdata; // @[ifu.scala 20:20]
  Pmem pmem ( // @[ifu.scala 20:20]
    .clock(pmem_clock),
    .valid(pmem_valid),
    .wen(pmem_wen),
    .wmask(pmem_wmask),
    .raddr(pmem_raddr),
    .waddr(pmem_waddr),
    .wdata(pmem_wdata),
    .rdata(pmem_rdata)
  );
  assign io_inst = pmem_rdata; // @[ifu.scala 33:11]
  assign pmem_clock = clock; // @[ifu.scala 21:17]
  assign pmem_valid = io_valid; // @[ifu.scala 23:17]
  assign pmem_wen = 1'h0; // @[ifu.scala 24:17]
  assign pmem_wmask = 4'h0; // @[ifu.scala 25:17]
  assign pmem_raddr = io_pc; // @[ifu.scala 30:17]
  assign pmem_waddr = 32'h0; // @[ifu.scala 26:17]
  assign pmem_wdata = 32'h0; // @[ifu.scala 27:17]
endmodule
module IDU(
  input  [31:0] io_instruction,
  output [4:0]  io_rs1,
  output [4:0]  io_rs2,
  output [4:0]  io_rd,
  output [2:0]  io_funct3,
  output [6:0]  io_funct7,
  output [31:0] io_imm,
  output [3:0]  io_TYpe,
  output        io_IsIllegal,
  output        io_IsInterrupt,
  output        io_isAuipc
);
  wire [31:0] inst = io_instruction == 32'h0 ? 32'h13 : io_instruction; // @[IDU.scala 34:14]
  wire [3:0] _io_TYpe_T_2 = 7'h33 == inst[6:0] ? 4'h0 : 4'h8; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_4 = 7'h3 == inst[6:0] ? 4'h1 : _io_TYpe_T_2; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_6 = 7'h23 == inst[6:0] ? 4'h2 : _io_TYpe_T_4; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_8 = 7'h63 == inst[6:0] ? 4'h3 : _io_TYpe_T_6; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_10 = 7'h13 == inst[6:0] ? 4'h4 : _io_TYpe_T_8; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_12 = 7'h37 == inst[6:0] ? 4'h5 : _io_TYpe_T_10; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_14 = 7'h6f == inst[6:0] ? 4'h6 : _io_TYpe_T_12; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_16 = 7'h17 == inst[6:0] ? 4'h5 : _io_TYpe_T_14; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_18 = 7'h67 == inst[6:0] ? 4'h7 : _io_TYpe_T_16; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_7 = 4'h0 == io_TYpe ? inst[19:15] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_9 = 4'h1 == io_TYpe ? inst[19:15] : _io_rs1_T_7; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_11 = 4'h2 == io_TYpe ? inst[19:15] : _io_rs1_T_9; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_13 = 4'h3 == io_TYpe ? inst[19:15] : _io_rs1_T_11; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_15 = 4'h4 == io_TYpe ? inst[19:15] : _io_rs1_T_13; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_17 = 4'h5 == io_TYpe ? 5'h0 : _io_rs1_T_15; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_19 = 4'h6 == io_TYpe ? 5'h0 : _io_rs1_T_17; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_4 = 4'h0 == io_TYpe ? inst[24:20] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_6 = 4'h1 == io_TYpe ? 5'h0 : _io_rs2_T_4; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_8 = 4'h2 == io_TYpe ? inst[24:20] : _io_rs2_T_6; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_10 = 4'h3 == io_TYpe ? inst[24:20] : _io_rs2_T_8; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_12 = 4'h4 == io_TYpe ? 5'h0 : _io_rs2_T_10; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_14 = 4'h5 == io_TYpe ? 5'h0 : _io_rs2_T_12; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_16 = 4'h6 == io_TYpe ? 5'h0 : _io_rs2_T_14; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_7 = 4'h0 == io_TYpe ? inst[11:7] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_9 = 4'h1 == io_TYpe ? inst[11:7] : _io_rd_T_7; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_11 = 4'h2 == io_TYpe ? 5'h0 : _io_rd_T_9; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_13 = 4'h3 == io_TYpe ? 5'h0 : _io_rd_T_11; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_15 = 4'h4 == io_TYpe ? inst[11:7] : _io_rd_T_13; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_17 = 4'h5 == io_TYpe ? inst[11:7] : _io_rd_T_15; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_19 = 4'h6 == io_TYpe ? inst[11:7] : _io_rd_T_17; // @[Mux.scala 81:58]
  wire [19:0] _io_imm_T_2 = inst[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_imm_T_5 = {_io_imm_T_2,inst[31:20]}; // @[IDU.scala 84:17]
  wire [31:0] _io_imm_T_12 = {_io_imm_T_2,inst[31:25],inst[11:7]}; // @[IDU.scala 87:30]
  wire [18:0] _io_imm_T_15 = inst[31] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_imm_T_21 = {_io_imm_T_15,inst[31],inst[7],inst[30:25],inst[11:8],1'h0}; // @[IDU.scala 93:28]
  wire [31:0] _io_imm_T_30 = {inst[31:12],12'h0}; // @[IDU.scala 95:51]
  wire [10:0] _io_imm_T_33 = inst[31] ? 11'h7ff : 11'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_imm_T_39 = {_io_imm_T_33,inst[31],inst[19:12],inst[20],inst[30:21],1'h0}; // @[IDU.scala 101:13]
  wire [31:0] _io_imm_T_49 = 4'h1 == io_TYpe ? $signed(_io_imm_T_5) : $signed(32'sh0); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_51 = 4'h2 == io_TYpe ? $signed(_io_imm_T_12) : $signed(_io_imm_T_49); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_53 = 4'h3 == io_TYpe ? $signed(_io_imm_T_21) : $signed(_io_imm_T_51); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_55 = 4'h4 == io_TYpe ? $signed(_io_imm_T_5) : $signed(_io_imm_T_53); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_57 = 4'h5 == io_TYpe ? $signed(_io_imm_T_30) : $signed(_io_imm_T_55); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_59 = 4'h6 == io_TYpe ? $signed(_io_imm_T_39) : $signed(_io_imm_T_57); // @[Mux.scala 81:58]
  assign io_rs1 = 4'h7 == io_TYpe ? inst[19:15] : _io_rs1_T_19; // @[Mux.scala 81:58]
  assign io_rs2 = 4'h7 == io_TYpe ? 5'h0 : _io_rs2_T_16; // @[Mux.scala 81:58]
  assign io_rd = 4'h7 == io_TYpe ? inst[11:7] : _io_rd_T_19; // @[Mux.scala 81:58]
  assign io_funct3 = inst[14:12]; // @[IDU.scala 104:22]
  assign io_funct7 = inst[31:25]; // @[IDU.scala 105:22]
  assign io_imm = 4'h7 == io_TYpe ? $signed(_io_imm_T_5) : $signed(_io_imm_T_59); // @[Mux.scala 81:58]
  assign io_TYpe = 7'h73 == inst[6:0] ? 4'h9 : _io_TYpe_T_18; // @[Mux.scala 81:58]
  assign io_IsIllegal = io_TYpe == 4'h8; // @[IDU.scala 29:31]
  assign io_IsInterrupt = io_TYpe == 4'h9; // @[IDU.scala 31:33]
  assign io_isAuipc = inst[6:0] == 7'h17; // @[IDU.scala 35:27]
endmodule
module RegFile(
  input         clock,
  input         reset,
  input  [4:0]  io_rs1,
  input  [4:0]  io_rs2,
  input  [4:0]  io_rd,
  input  [31:0] io_writeData,
  input         io_writeEnable,
  output [31:0] io_regData1,
  output [31:0] io_regData2
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regFile_0; // @[RegFile.scala 19:24]
  reg [31:0] regFile_1; // @[RegFile.scala 19:24]
  reg [31:0] regFile_2; // @[RegFile.scala 19:24]
  reg [31:0] regFile_3; // @[RegFile.scala 19:24]
  reg [31:0] regFile_4; // @[RegFile.scala 19:24]
  reg [31:0] regFile_5; // @[RegFile.scala 19:24]
  reg [31:0] regFile_6; // @[RegFile.scala 19:24]
  reg [31:0] regFile_7; // @[RegFile.scala 19:24]
  reg [31:0] regFile_8; // @[RegFile.scala 19:24]
  reg [31:0] regFile_9; // @[RegFile.scala 19:24]
  reg [31:0] regFile_10; // @[RegFile.scala 19:24]
  reg [31:0] regFile_11; // @[RegFile.scala 19:24]
  reg [31:0] regFile_12; // @[RegFile.scala 19:24]
  reg [31:0] regFile_13; // @[RegFile.scala 19:24]
  reg [31:0] regFile_14; // @[RegFile.scala 19:24]
  reg [31:0] regFile_15; // @[RegFile.scala 19:24]
  reg [31:0] regFile_16; // @[RegFile.scala 19:24]
  reg [31:0] regFile_17; // @[RegFile.scala 19:24]
  reg [31:0] regFile_18; // @[RegFile.scala 19:24]
  reg [31:0] regFile_19; // @[RegFile.scala 19:24]
  reg [31:0] regFile_20; // @[RegFile.scala 19:24]
  reg [31:0] regFile_21; // @[RegFile.scala 19:24]
  reg [31:0] regFile_22; // @[RegFile.scala 19:24]
  reg [31:0] regFile_23; // @[RegFile.scala 19:24]
  reg [31:0] regFile_24; // @[RegFile.scala 19:24]
  reg [31:0] regFile_25; // @[RegFile.scala 19:24]
  reg [31:0] regFile_26; // @[RegFile.scala 19:24]
  reg [31:0] regFile_27; // @[RegFile.scala 19:24]
  reg [31:0] regFile_28; // @[RegFile.scala 19:24]
  reg [31:0] regFile_29; // @[RegFile.scala 19:24]
  reg [31:0] regFile_30; // @[RegFile.scala 19:24]
  reg [31:0] regFile_31; // @[RegFile.scala 19:24]
  wire [31:0] _GEN_1 = 5'h1 == io_rs1 ? regFile_1 : regFile_0; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_2 = 5'h2 == io_rs1 ? regFile_2 : _GEN_1; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_3 = 5'h3 == io_rs1 ? regFile_3 : _GEN_2; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_4 = 5'h4 == io_rs1 ? regFile_4 : _GEN_3; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_5 = 5'h5 == io_rs1 ? regFile_5 : _GEN_4; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_6 = 5'h6 == io_rs1 ? regFile_6 : _GEN_5; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_7 = 5'h7 == io_rs1 ? regFile_7 : _GEN_6; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_8 = 5'h8 == io_rs1 ? regFile_8 : _GEN_7; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_9 = 5'h9 == io_rs1 ? regFile_9 : _GEN_8; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_10 = 5'ha == io_rs1 ? regFile_10 : _GEN_9; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_11 = 5'hb == io_rs1 ? regFile_11 : _GEN_10; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_12 = 5'hc == io_rs1 ? regFile_12 : _GEN_11; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_13 = 5'hd == io_rs1 ? regFile_13 : _GEN_12; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_14 = 5'he == io_rs1 ? regFile_14 : _GEN_13; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_15 = 5'hf == io_rs1 ? regFile_15 : _GEN_14; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_16 = 5'h10 == io_rs1 ? regFile_16 : _GEN_15; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_17 = 5'h11 == io_rs1 ? regFile_17 : _GEN_16; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_18 = 5'h12 == io_rs1 ? regFile_18 : _GEN_17; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_19 = 5'h13 == io_rs1 ? regFile_19 : _GEN_18; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_20 = 5'h14 == io_rs1 ? regFile_20 : _GEN_19; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_21 = 5'h15 == io_rs1 ? regFile_21 : _GEN_20; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_22 = 5'h16 == io_rs1 ? regFile_22 : _GEN_21; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_23 = 5'h17 == io_rs1 ? regFile_23 : _GEN_22; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_24 = 5'h18 == io_rs1 ? regFile_24 : _GEN_23; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_25 = 5'h19 == io_rs1 ? regFile_25 : _GEN_24; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_26 = 5'h1a == io_rs1 ? regFile_26 : _GEN_25; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_27 = 5'h1b == io_rs1 ? regFile_27 : _GEN_26; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_28 = 5'h1c == io_rs1 ? regFile_28 : _GEN_27; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_29 = 5'h1d == io_rs1 ? regFile_29 : _GEN_28; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_30 = 5'h1e == io_rs1 ? regFile_30 : _GEN_29; // @[RegFile.scala 23:{15,15}]
  wire [31:0] _GEN_33 = 5'h1 == io_rs2 ? regFile_1 : regFile_0; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_34 = 5'h2 == io_rs2 ? regFile_2 : _GEN_33; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_35 = 5'h3 == io_rs2 ? regFile_3 : _GEN_34; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_36 = 5'h4 == io_rs2 ? regFile_4 : _GEN_35; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_37 = 5'h5 == io_rs2 ? regFile_5 : _GEN_36; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_38 = 5'h6 == io_rs2 ? regFile_6 : _GEN_37; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_39 = 5'h7 == io_rs2 ? regFile_7 : _GEN_38; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_40 = 5'h8 == io_rs2 ? regFile_8 : _GEN_39; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_41 = 5'h9 == io_rs2 ? regFile_9 : _GEN_40; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_42 = 5'ha == io_rs2 ? regFile_10 : _GEN_41; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_43 = 5'hb == io_rs2 ? regFile_11 : _GEN_42; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_44 = 5'hc == io_rs2 ? regFile_12 : _GEN_43; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_45 = 5'hd == io_rs2 ? regFile_13 : _GEN_44; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_46 = 5'he == io_rs2 ? regFile_14 : _GEN_45; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_47 = 5'hf == io_rs2 ? regFile_15 : _GEN_46; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_48 = 5'h10 == io_rs2 ? regFile_16 : _GEN_47; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_49 = 5'h11 == io_rs2 ? regFile_17 : _GEN_48; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_50 = 5'h12 == io_rs2 ? regFile_18 : _GEN_49; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_51 = 5'h13 == io_rs2 ? regFile_19 : _GEN_50; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_52 = 5'h14 == io_rs2 ? regFile_20 : _GEN_51; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_53 = 5'h15 == io_rs2 ? regFile_21 : _GEN_52; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_54 = 5'h16 == io_rs2 ? regFile_22 : _GEN_53; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_55 = 5'h17 == io_rs2 ? regFile_23 : _GEN_54; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_56 = 5'h18 == io_rs2 ? regFile_24 : _GEN_55; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_57 = 5'h19 == io_rs2 ? regFile_25 : _GEN_56; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_58 = 5'h1a == io_rs2 ? regFile_26 : _GEN_57; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_59 = 5'h1b == io_rs2 ? regFile_27 : _GEN_58; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_60 = 5'h1c == io_rs2 ? regFile_28 : _GEN_59; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_61 = 5'h1d == io_rs2 ? regFile_29 : _GEN_60; // @[RegFile.scala 24:{15,15}]
  wire [31:0] _GEN_62 = 5'h1e == io_rs2 ? regFile_30 : _GEN_61; // @[RegFile.scala 24:{15,15}]
  assign io_regData1 = 5'h1f == io_rs1 ? regFile_31 : _GEN_30; // @[RegFile.scala 23:{15,15}]
  assign io_regData2 = 5'h1f == io_rs2 ? regFile_31 : _GEN_62; // @[RegFile.scala 24:{15,15}]
  always @(posedge clock) begin
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_0 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h0 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_0 <= io_writeData; // @[RegFile.scala 28:20]
      end else begin
        regFile_0 <= 32'h0; // @[RegFile.scala 21:16]
      end
    end else begin
      regFile_0 <= 32'h0; // @[RegFile.scala 21:16]
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_1 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_1 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_2 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h2 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_2 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_3 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h3 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_3 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_4 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h4 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_4 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_5 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h5 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_5 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_6 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h6 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_6 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_7 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h7 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_7 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_8 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h8 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_8 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_9 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h9 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_9 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_10 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'ha == io_rd) begin // @[RegFile.scala 28:20]
        regFile_10 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_11 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'hb == io_rd) begin // @[RegFile.scala 28:20]
        regFile_11 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_12 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'hc == io_rd) begin // @[RegFile.scala 28:20]
        regFile_12 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_13 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'hd == io_rd) begin // @[RegFile.scala 28:20]
        regFile_13 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_14 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'he == io_rd) begin // @[RegFile.scala 28:20]
        regFile_14 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_15 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'hf == io_rd) begin // @[RegFile.scala 28:20]
        regFile_15 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_16 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h10 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_16 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_17 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h11 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_17 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_18 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h12 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_18 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_19 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h13 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_19 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_20 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h14 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_20 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_21 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h15 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_21 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_22 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h16 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_22 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_23 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h17 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_23 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_24 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h18 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_24 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_25 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h19 == io_rd) begin // @[RegFile.scala 28:20]
        regFile_25 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_26 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1a == io_rd) begin // @[RegFile.scala 28:20]
        regFile_26 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_27 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1b == io_rd) begin // @[RegFile.scala 28:20]
        regFile_27 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_28 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1c == io_rd) begin // @[RegFile.scala 28:20]
        regFile_28 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_29 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1d == io_rd) begin // @[RegFile.scala 28:20]
        regFile_29 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_30 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1e == io_rd) begin // @[RegFile.scala 28:20]
        regFile_30 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
    if (reset) begin // @[RegFile.scala 19:24]
      regFile_31 <= 32'h0; // @[RegFile.scala 19:24]
    end else if (io_writeEnable & io_rd != 5'h0) begin // @[RegFile.scala 27:41]
      if (5'h1f == io_rd) begin // @[RegFile.scala 28:20]
        regFile_31 <= io_writeData; // @[RegFile.scala 28:20]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  regFile_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  regFile_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  regFile_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  regFile_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  regFile_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  regFile_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  regFile_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  regFile_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  regFile_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  regFile_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  regFile_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  regFile_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  regFile_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  regFile_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  regFile_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  regFile_15 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  regFile_16 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  regFile_17 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  regFile_18 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  regFile_19 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  regFile_20 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  regFile_21 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  regFile_22 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  regFile_23 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  regFile_24 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  regFile_25 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  regFile_26 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  regFile_27 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  regFile_28 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  regFile_29 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  regFile_30 = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  regFile_31 = _RAND_31[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Adder32(
  input  [31:0] io_a,
  input  [31:0] io_b,
  output [31:0] io_sum
);
  assign io_sum = io_a + io_b; // @[EXU.scala 13:18]
endmodule
module Sub32(
  input  [31:0] io_a,
  input  [31:0] io_b,
  output [31:0] io_diff
);
  assign io_diff = io_a - io_b; // @[EXU.scala 23:19]
endmodule
module Shifter(
  input  [31:0] io_in,
  input  [4:0]  io_shamt,
  input  [2:0]  io_funct3,
  input  [6:0]  io_funct7,
  output [31:0] io_out
);
  wire [62:0] _GEN_0 = {{31'd0}, io_in}; // @[EXU.scala 36:19]
  wire [62:0] sll = _GEN_0 << io_shamt; // @[EXU.scala 36:19]
  wire [31:0] srl = io_in >> io_shamt; // @[EXU.scala 38:19]
  wire [31:0] sra = $signed(io_in) >>> io_shamt; // @[EXU.scala 40:40]
  wire [31:0] _io_out_T_1 = io_funct7[5] ? sra : srl; // @[EXU.scala 44:20]
  wire [62:0] _io_out_T_3 = 3'h1 == io_funct3 ? sll : 63'h0; // @[Mux.scala 81:58]
  wire [62:0] _io_out_T_5 = 3'h5 == io_funct3 ? {{31'd0}, _io_out_T_1} : _io_out_T_3; // @[Mux.scala 81:58]
  assign io_out = _io_out_T_5[31:0]; // @[EXU.scala 42:10]
endmodule
module LogicUnit(
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  input  [2:0]  io_funct3,
  output [31:0] io_out
);
  wire [31:0] _io_out_T = io_in1 ^ io_in2; // @[EXU.scala 57:25]
  wire [31:0] _io_out_T_1 = io_in1 | io_in2; // @[EXU.scala 58:25]
  wire [31:0] _io_out_T_2 = io_in1 & io_in2; // @[EXU.scala 59:25]
  wire [31:0] _io_out_T_4 = 3'h4 == io_funct3 ? _io_out_T : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _io_out_T_6 = 3'h6 == io_funct3 ? _io_out_T_1 : _io_out_T_4; // @[Mux.scala 81:58]
  assign io_out = 3'h7 == io_funct3 ? _io_out_T_2 : _io_out_T_6; // @[Mux.scala 81:58]
endmodule
module UTypeUnit(
  input  [31:0] io_imm,
  input  [31:0] io_pc,
  input         io_isAuipc,
  output [31:0] io_out
);
  wire [31:0] auipcVal = io_pc + io_imm; // @[EXU.scala 94:24]
  assign io_out = io_isAuipc ? auipcVal : io_imm; // @[EXU.scala 95:16]
endmodule
module ALU(
  input  [2:0]  io_funct3,
  input  [6:0]  io_funct7,
  input  [3:0]  io_TYpe,
  input  [31:0] io_reg_rs1,
  input  [31:0] io_reg_rs2,
  input  [31:0] io_imm,
  input  [31:0] io_pc,
  input         io_isAuipc,
  output [31:0] io_result
);
  wire [31:0] addR_io_a; // @[EXU.scala 164:22]
  wire [31:0] addR_io_b; // @[EXU.scala 164:22]
  wire [31:0] addR_io_sum; // @[EXU.scala 164:22]
  wire [31:0] subR_io_a; // @[EXU.scala 168:22]
  wire [31:0] subR_io_b; // @[EXU.scala 168:22]
  wire [31:0] subR_io_diff; // @[EXU.scala 168:22]
  wire [31:0] shftr_io_in; // @[EXU.scala 172:22]
  wire [4:0] shftr_io_shamt; // @[EXU.scala 172:22]
  wire [2:0] shftr_io_funct3; // @[EXU.scala 172:22]
  wire [6:0] shftr_io_funct7; // @[EXU.scala 172:22]
  wire [31:0] shftr_io_out; // @[EXU.scala 172:22]
  wire [31:0] logicU_io_in1; // @[EXU.scala 179:22]
  wire [31:0] logicU_io_in2; // @[EXU.scala 179:22]
  wire [2:0] logicU_io_funct3; // @[EXU.scala 179:22]
  wire [31:0] logicU_io_out; // @[EXU.scala 179:22]
  wire [31:0] addI_io_a; // @[EXU.scala 200:22]
  wire [31:0] addI_io_b; // @[EXU.scala 200:22]
  wire [31:0] addI_io_sum; // @[EXU.scala 200:22]
  wire [31:0] addrAdd_io_a; // @[EXU.scala 220:23]
  wire [31:0] addrAdd_io_b; // @[EXU.scala 220:23]
  wire [31:0] addrAdd_io_sum; // @[EXU.scala 220:23]
  wire [31:0] uunit_io_imm; // @[EXU.scala 225:21]
  wire [31:0] uunit_io_pc; // @[EXU.scala 225:21]
  wire  uunit_io_isAuipc; // @[EXU.scala 225:21]
  wire [31:0] uunit_io_out; // @[EXU.scala 225:21]
  wire  isIShift = io_TYpe == 4'h4 & (io_funct3 == 3'h1 | io_funct3 == 3'h5); // @[EXU.scala 174:42]
  wire [31:0] _rtypeRes_T_1 = io_funct7[5] ? subR_io_diff : addR_io_sum; // @[EXU.scala 186:20]
  wire  _rtypeRes_T_4 = $signed(io_reg_rs1) < $signed(io_reg_rs2); // @[EXU.scala 188:36]
  wire  _rtypeRes_T_5 = io_reg_rs1 < io_reg_rs2; // @[EXU.scala 189:29]
  wire [31:0] _rtypeRes_T_10 = $signed(io_reg_rs1) >>> io_reg_rs2[4:0]; // @[EXU.scala 192:47]
  wire [31:0] _rtypeRes_T_12 = io_reg_rs1 >> io_reg_rs2[4:0]; // @[EXU.scala 193:19]
  wire [31:0] _rtypeRes_T_13 = io_funct7[5] ? _rtypeRes_T_10 : _rtypeRes_T_12; // @[EXU.scala 191:20]
  wire [31:0] _rtypeRes_T_15 = 3'h1 == io_funct3 ? shftr_io_out : _rtypeRes_T_1; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_17 = 3'h2 == io_funct3 ? {{31'd0}, _rtypeRes_T_4} : _rtypeRes_T_15; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_19 = 3'h3 == io_funct3 ? {{31'd0}, _rtypeRes_T_5} : _rtypeRes_T_17; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_21 = 3'h4 == io_funct3 ? logicU_io_out : _rtypeRes_T_19; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_23 = 3'h5 == io_funct3 ? _rtypeRes_T_13 : _rtypeRes_T_21; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_25 = 3'h6 == io_funct3 ? logicU_io_out : _rtypeRes_T_23; // @[Mux.scala 81:58]
  wire [31:0] rtypeRes = 3'h7 == io_funct3 ? logicU_io_out : _rtypeRes_T_25; // @[Mux.scala 81:58]
  wire  _itypeRes_T_2 = $signed(io_reg_rs1) < $signed(io_imm); // @[EXU.scala 210:36]
  wire  _itypeRes_T_3 = io_reg_rs1 < io_imm; // @[EXU.scala 211:29]
  wire [31:0] _itypeRes_T_4 = io_reg_rs1 ^ io_imm; // @[EXU.scala 212:29]
  wire [31:0] _itypeRes_T_5 = io_reg_rs1 | io_imm; // @[EXU.scala 214:29]
  wire [31:0] _itypeRes_T_6 = io_reg_rs1 & io_imm; // @[EXU.scala 215:29]
  wire [31:0] _itypeRes_T_8 = 3'h1 == io_funct3 ? shftr_io_out : addI_io_sum; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_10 = 3'h2 == io_funct3 ? {{31'd0}, _itypeRes_T_2} : _itypeRes_T_8; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_12 = 3'h3 == io_funct3 ? {{31'd0}, _itypeRes_T_3} : _itypeRes_T_10; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_14 = 3'h4 == io_funct3 ? _itypeRes_T_4 : _itypeRes_T_12; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_16 = 3'h5 == io_funct3 ? shftr_io_out : _itypeRes_T_14; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_18 = 3'h6 == io_funct3 ? _itypeRes_T_5 : _itypeRes_T_16; // @[Mux.scala 81:58]
  wire [31:0] itypeRes = 3'h7 == io_funct3 ? _itypeRes_T_6 : _itypeRes_T_18; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_1 = 4'h0 == io_TYpe ? rtypeRes : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_3 = 4'h1 == io_TYpe ? addrAdd_io_sum : _io_result_T_1; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_5 = 4'h2 == io_TYpe ? addrAdd_io_sum : _io_result_T_3; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_7 = 4'h3 == io_TYpe ? 32'h0 : _io_result_T_5; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_9 = 4'h4 == io_TYpe ? itypeRes : _io_result_T_7; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_11 = 4'h5 == io_TYpe ? uunit_io_out : _io_result_T_9; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_13 = 4'h6 == io_TYpe ? 32'h0 : _io_result_T_11; // @[Mux.scala 81:58]
  Adder32 addR ( // @[EXU.scala 164:22]
    .io_a(addR_io_a),
    .io_b(addR_io_b),
    .io_sum(addR_io_sum)
  );
  Sub32 subR ( // @[EXU.scala 168:22]
    .io_a(subR_io_a),
    .io_b(subR_io_b),
    .io_diff(subR_io_diff)
  );
  Shifter shftr ( // @[EXU.scala 172:22]
    .io_in(shftr_io_in),
    .io_shamt(shftr_io_shamt),
    .io_funct3(shftr_io_funct3),
    .io_funct7(shftr_io_funct7),
    .io_out(shftr_io_out)
  );
  LogicUnit logicU ( // @[EXU.scala 179:22]
    .io_in1(logicU_io_in1),
    .io_in2(logicU_io_in2),
    .io_funct3(logicU_io_funct3),
    .io_out(logicU_io_out)
  );
  Adder32 addI ( // @[EXU.scala 200:22]
    .io_a(addI_io_a),
    .io_b(addI_io_b),
    .io_sum(addI_io_sum)
  );
  Adder32 addrAdd ( // @[EXU.scala 220:23]
    .io_a(addrAdd_io_a),
    .io_b(addrAdd_io_b),
    .io_sum(addrAdd_io_sum)
  );
  UTypeUnit uunit ( // @[EXU.scala 225:21]
    .io_imm(uunit_io_imm),
    .io_pc(uunit_io_pc),
    .io_isAuipc(uunit_io_isAuipc),
    .io_out(uunit_io_out)
  );
  assign io_result = 4'h7 == io_TYpe ? 32'h0 : _io_result_T_13; // @[Mux.scala 81:58]
  assign addR_io_a = io_reg_rs1; // @[EXU.scala 165:14]
  assign addR_io_b = io_reg_rs2; // @[EXU.scala 166:14]
  assign subR_io_a = io_reg_rs1; // @[EXU.scala 169:14]
  assign subR_io_b = io_reg_rs2; // @[EXU.scala 170:14]
  assign shftr_io_in = io_reg_rs1; // @[EXU.scala 173:19]
  assign shftr_io_shamt = isIShift ? io_imm[4:0] : io_reg_rs2[4:0]; // @[EXU.scala 175:25]
  assign shftr_io_funct3 = io_funct3; // @[EXU.scala 176:19]
  assign shftr_io_funct7 = io_funct7; // @[EXU.scala 177:19]
  assign logicU_io_in1 = io_reg_rs1; // @[EXU.scala 180:20]
  assign logicU_io_in2 = io_reg_rs2; // @[EXU.scala 181:20]
  assign logicU_io_funct3 = io_funct3; // @[EXU.scala 182:20]
  assign addI_io_a = io_reg_rs1; // @[EXU.scala 201:14]
  assign addI_io_b = io_imm; // @[EXU.scala 202:14]
  assign addrAdd_io_a = io_reg_rs1; // @[EXU.scala 221:16]
  assign addrAdd_io_b = io_imm; // @[EXU.scala 222:16]
  assign uunit_io_imm = io_imm; // @[EXU.scala 226:20]
  assign uunit_io_pc = io_pc; // @[EXU.scala 227:20]
  assign uunit_io_isAuipc = io_isAuipc; // @[EXU.scala 229:20]
endmodule
module Comparator(
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  input  [2:0]  io_funct3,
  output        io_cmp
);
  wire  _io_cmp_T = io_in1 == io_in2; // @[EXU.scala 74:25]
  wire  _io_cmp_T_1 = io_in1 != io_in2; // @[EXU.scala 75:25]
  wire  _io_cmp_T_2 = $signed(io_in1) < $signed(io_in2); // @[EXU.scala 76:23]
  wire  _io_cmp_T_3 = $signed(io_in1) >= $signed(io_in2); // @[EXU.scala 77:23]
  wire  _io_cmp_T_4 = io_in1 < io_in2; // @[EXU.scala 78:25]
  wire  _io_cmp_T_5 = io_in1 >= io_in2; // @[EXU.scala 79:25]
  wire  _io_cmp_T_9 = 3'h1 == io_funct3 ? _io_cmp_T_1 : 3'h0 == io_funct3 & _io_cmp_T; // @[Mux.scala 81:58]
  wire  _io_cmp_T_11 = 3'h4 == io_funct3 ? _io_cmp_T_2 : _io_cmp_T_9; // @[Mux.scala 81:58]
  wire  _io_cmp_T_13 = 3'h5 == io_funct3 ? _io_cmp_T_3 : _io_cmp_T_11; // @[Mux.scala 81:58]
  wire  _io_cmp_T_15 = 3'h6 == io_funct3 ? _io_cmp_T_4 : _io_cmp_T_13; // @[Mux.scala 81:58]
  assign io_cmp = 3'h7 == io_funct3 ? _io_cmp_T_5 : _io_cmp_T_15; // @[Mux.scala 81:58]
endmodule
module BranchUnit(
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  input  [2:0]  io_funct3,
  input  [31:0] io_pc,
  input  [31:0] io_imm,
  output        io_taken,
  output [31:0] io_branch_target
);
  wire [31:0] cmp_io_in1; // @[EXU.scala 110:19]
  wire [31:0] cmp_io_in2; // @[EXU.scala 110:19]
  wire [2:0] cmp_io_funct3; // @[EXU.scala 110:19]
  wire  cmp_io_cmp; // @[EXU.scala 110:19]
  wire [31:0] ad_io_a; // @[EXU.scala 118:18]
  wire [31:0] ad_io_b; // @[EXU.scala 118:18]
  wire [31:0] ad_io_sum; // @[EXU.scala 118:18]
  Comparator cmp ( // @[EXU.scala 110:19]
    .io_in1(cmp_io_in1),
    .io_in2(cmp_io_in2),
    .io_funct3(cmp_io_funct3),
    .io_cmp(cmp_io_cmp)
  );
  Adder32 ad ( // @[EXU.scala 118:18]
    .io_a(ad_io_a),
    .io_b(ad_io_b),
    .io_sum(ad_io_sum)
  );
  assign io_taken = cmp_io_cmp; // @[EXU.scala 115:12]
  assign io_branch_target = ad_io_sum; // @[EXU.scala 121:20]
  assign cmp_io_in1 = io_in1; // @[EXU.scala 111:17]
  assign cmp_io_in2 = io_in2; // @[EXU.scala 112:17]
  assign cmp_io_funct3 = io_funct3; // @[EXU.scala 113:17]
  assign ad_io_a = io_pc; // @[EXU.scala 119:11]
  assign ad_io_b = io_imm; // @[EXU.scala 120:11]
endmodule
module JumpUnit(
  input  [31:0] io_pc,
  input  [31:0] io_rs1,
  input  [31:0] io_imm,
  input         io_isJal,
  output [31:0] io_jump_pc
);
  wire [31:0] adJal_io_a; // @[EXU.scala 135:21]
  wire [31:0] adJal_io_b; // @[EXU.scala 135:21]
  wire [31:0] adJal_io_sum; // @[EXU.scala 135:21]
  wire [31:0] adJalr_io_a; // @[EXU.scala 140:22]
  wire [31:0] adJalr_io_b; // @[EXU.scala 140:22]
  wire [31:0] adJalr_io_sum; // @[EXU.scala 140:22]
  wire [31:0] jalrAligned = adJalr_io_sum & 32'hfffffffe; // @[EXU.scala 144:29]
  Adder32 adJal ( // @[EXU.scala 135:21]
    .io_a(adJal_io_a),
    .io_b(adJal_io_b),
    .io_sum(adJal_io_sum)
  );
  Adder32 adJalr ( // @[EXU.scala 140:22]
    .io_a(adJalr_io_a),
    .io_b(adJalr_io_b),
    .io_sum(adJalr_io_sum)
  );
  assign io_jump_pc = io_isJal ? adJal_io_sum : jalrAligned; // @[EXU.scala 146:20]
  assign adJal_io_a = io_pc; // @[EXU.scala 136:14]
  assign adJal_io_b = io_imm; // @[EXU.scala 137:14]
  assign adJalr_io_a = io_rs1; // @[EXU.scala 141:15]
  assign adJalr_io_b = io_imm; // @[EXU.scala 142:15]
endmodule
module EXU(
  input  [2:0]  io_funct3,
  input  [6:0]  io_funct7,
  input  [31:0] io_imm,
  input  [3:0]  io_TYpe,
  input  [31:0] io_reg_rs1,
  input  [31:0] io_reg_rs2,
  input  [31:0] io_pc,
  input         io_isAuipc,
  output [31:0] io_result_out,
  output        io_branch_taken,
  output [31:0] io_branch_target,
  output [31:0] io_jump_target
);
  wire [2:0] alu_io_funct3; // @[EXU.scala 269:19]
  wire [6:0] alu_io_funct7; // @[EXU.scala 269:19]
  wire [3:0] alu_io_TYpe; // @[EXU.scala 269:19]
  wire [31:0] alu_io_reg_rs1; // @[EXU.scala 269:19]
  wire [31:0] alu_io_reg_rs2; // @[EXU.scala 269:19]
  wire [31:0] alu_io_imm; // @[EXU.scala 269:19]
  wire [31:0] alu_io_pc; // @[EXU.scala 269:19]
  wire  alu_io_isAuipc; // @[EXU.scala 269:19]
  wire [31:0] alu_io_result; // @[EXU.scala 269:19]
  wire [31:0] branchUnit_io_in1; // @[EXU.scala 279:26]
  wire [31:0] branchUnit_io_in2; // @[EXU.scala 279:26]
  wire [2:0] branchUnit_io_funct3; // @[EXU.scala 279:26]
  wire [31:0] branchUnit_io_pc; // @[EXU.scala 279:26]
  wire [31:0] branchUnit_io_imm; // @[EXU.scala 279:26]
  wire  branchUnit_io_taken; // @[EXU.scala 279:26]
  wire [31:0] branchUnit_io_branch_target; // @[EXU.scala 279:26]
  wire [31:0] jumpUnit_io_pc; // @[EXU.scala 287:24]
  wire [31:0] jumpUnit_io_rs1; // @[EXU.scala 287:24]
  wire [31:0] jumpUnit_io_imm; // @[EXU.scala 287:24]
  wire  jumpUnit_io_isJal; // @[EXU.scala 287:24]
  wire [31:0] jumpUnit_io_jump_pc; // @[EXU.scala 287:24]
  wire [31:0] _GEN_0 = 4'h7 == io_TYpe ? jumpUnit_io_jump_pc : 32'h0; // @[EXU.scala 300:19 298:20 311:22]
  wire [31:0] _GEN_1 = 4'h7 == io_TYpe ? jumpUnit_io_jump_pc : alu_io_result; // @[EXU.scala 300:19 295:20 312:22]
  wire [31:0] _GEN_2 = 4'h6 == io_TYpe ? jumpUnit_io_jump_pc : _GEN_0; // @[EXU.scala 300:19 307:22]
  wire [31:0] _GEN_3 = 4'h6 == io_TYpe ? jumpUnit_io_jump_pc : _GEN_1; // @[EXU.scala 300:19 308:22]
  ALU alu ( // @[EXU.scala 269:19]
    .io_funct3(alu_io_funct3),
    .io_funct7(alu_io_funct7),
    .io_TYpe(alu_io_TYpe),
    .io_reg_rs1(alu_io_reg_rs1),
    .io_reg_rs2(alu_io_reg_rs2),
    .io_imm(alu_io_imm),
    .io_pc(alu_io_pc),
    .io_isAuipc(alu_io_isAuipc),
    .io_result(alu_io_result)
  );
  BranchUnit branchUnit ( // @[EXU.scala 279:26]
    .io_in1(branchUnit_io_in1),
    .io_in2(branchUnit_io_in2),
    .io_funct3(branchUnit_io_funct3),
    .io_pc(branchUnit_io_pc),
    .io_imm(branchUnit_io_imm),
    .io_taken(branchUnit_io_taken),
    .io_branch_target(branchUnit_io_branch_target)
  );
  JumpUnit jumpUnit ( // @[EXU.scala 287:24]
    .io_pc(jumpUnit_io_pc),
    .io_rs1(jumpUnit_io_rs1),
    .io_imm(jumpUnit_io_imm),
    .io_isJal(jumpUnit_io_isJal),
    .io_jump_pc(jumpUnit_io_jump_pc)
  );
  assign io_result_out = 4'h3 == io_TYpe ? {{31'd0}, branchUnit_io_taken} : _GEN_3; // @[EXU.scala 300:19 304:24]
  assign io_branch_taken = 4'h3 == io_TYpe & branchUnit_io_taken; // @[EXU.scala 300:19 296:20 302:24]
  assign io_branch_target = 4'h3 == io_TYpe ? branchUnit_io_branch_target : 32'h0; // @[EXU.scala 300:19 297:20 303:24]
  assign io_jump_target = 4'h3 == io_TYpe ? 32'h0 : _GEN_2; // @[EXU.scala 300:19 298:20]
  assign alu_io_funct3 = io_funct3; // @[EXU.scala 270:18]
  assign alu_io_funct7 = io_funct7; // @[EXU.scala 271:18]
  assign alu_io_TYpe = io_TYpe; // @[EXU.scala 272:18]
  assign alu_io_reg_rs1 = io_reg_rs1; // @[EXU.scala 273:18]
  assign alu_io_reg_rs2 = io_reg_rs2; // @[EXU.scala 274:18]
  assign alu_io_imm = io_imm; // @[EXU.scala 275:28]
  assign alu_io_pc = io_pc; // @[EXU.scala 276:18]
  assign alu_io_isAuipc = io_isAuipc; // @[EXU.scala 277:18]
  assign branchUnit_io_in1 = io_reg_rs1; // @[EXU.scala 280:24]
  assign branchUnit_io_in2 = io_reg_rs2; // @[EXU.scala 281:24]
  assign branchUnit_io_funct3 = io_funct3; // @[EXU.scala 282:24]
  assign branchUnit_io_pc = io_pc; // @[EXU.scala 283:24]
  assign branchUnit_io_imm = io_imm; // @[EXU.scala 284:34]
  assign jumpUnit_io_pc = io_pc; // @[EXU.scala 288:21]
  assign jumpUnit_io_rs1 = io_reg_rs1; // @[EXU.scala 289:21]
  assign jumpUnit_io_imm = io_imm; // @[EXU.scala 290:31]
  assign jumpUnit_io_isJal = io_TYpe == 4'h6; // @[EXU.scala 291:33]
endmodule
module top(
  input   clock,
  input   reset
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  ifu_clock; // @[top.scala 16:19]
  wire [31:0] ifu_io_pc; // @[top.scala 16:19]
  wire  ifu_io_valid; // @[top.scala 16:19]
  wire [31:0] ifu_io_inst; // @[top.scala 16:19]
  wire [31:0] idu_io_instruction; // @[top.scala 21:27]
  wire [4:0] idu_io_rs1; // @[top.scala 21:27]
  wire [4:0] idu_io_rs2; // @[top.scala 21:27]
  wire [4:0] idu_io_rd; // @[top.scala 21:27]
  wire [2:0] idu_io_funct3; // @[top.scala 21:27]
  wire [6:0] idu_io_funct7; // @[top.scala 21:27]
  wire [31:0] idu_io_imm; // @[top.scala 21:27]
  wire [3:0] idu_io_TYpe; // @[top.scala 21:27]
  wire  idu_io_IsIllegal; // @[top.scala 21:27]
  wire  idu_io_IsInterrupt; // @[top.scala 21:27]
  wire  idu_io_isAuipc; // @[top.scala 21:27]
  wire  regFile_clock; // @[top.scala 22:27]
  wire  regFile_reset; // @[top.scala 22:27]
  wire [4:0] regFile_io_rs1; // @[top.scala 22:27]
  wire [4:0] regFile_io_rs2; // @[top.scala 22:27]
  wire [4:0] regFile_io_rd; // @[top.scala 22:27]
  wire [31:0] regFile_io_writeData; // @[top.scala 22:27]
  wire  regFile_io_writeEnable; // @[top.scala 22:27]
  wire [31:0] regFile_io_regData1; // @[top.scala 22:27]
  wire [31:0] regFile_io_regData2; // @[top.scala 22:27]
  wire [2:0] exu_io_funct3; // @[top.scala 23:27]
  wire [6:0] exu_io_funct7; // @[top.scala 23:27]
  wire [31:0] exu_io_imm; // @[top.scala 23:27]
  wire [3:0] exu_io_TYpe; // @[top.scala 23:27]
  wire [31:0] exu_io_reg_rs1; // @[top.scala 23:27]
  wire [31:0] exu_io_reg_rs2; // @[top.scala 23:27]
  wire [31:0] exu_io_pc; // @[top.scala 23:27]
  wire  exu_io_isAuipc; // @[top.scala 23:27]
  wire [31:0] exu_io_result_out; // @[top.scala 23:27]
  wire  exu_io_branch_taken; // @[top.scala 23:27]
  wire [31:0] exu_io_branch_target; // @[top.scala 23:27]
  wire [31:0] exu_io_jump_target; // @[top.scala 23:27]
  wire  dpiHandlers_IsIllegal; // @[top.scala 24:27]
  wire  dpiHandlers_IsInterrupt; // @[top.scala 24:27]
  wire  pmemD_clock; // @[top.scala 42:21]
  wire  pmemD_valid; // @[top.scala 42:21]
  wire  pmemD_wen; // @[top.scala 42:21]
  wire [3:0] pmemD_wmask; // @[top.scala 42:21]
  wire [31:0] pmemD_raddr; // @[top.scala 42:21]
  wire [31:0] pmemD_waddr; // @[top.scala 42:21]
  wire [31:0] pmemD_wdata; // @[top.scala 42:21]
  wire [31:0] pmemD_rdata; // @[top.scala 42:21]
  reg [31:0] pc; // @[top.scala 11:24]
  wire [31:0] pcPlus4 = pc + 32'h4; // @[top.scala 12:20]
  reg  valid; // @[top.scala 13:22]
  wire  isLoad = idu_io_TYpe == 4'h1; // @[top.scala 44:29]
  wire  isStore = idu_io_TYpe == 4'h2; // @[top.scala 45:29]
  wire [3:0] _pmemD_io_wmask_T_1 = 3'h0 == idu_io_funct3 ? 4'h1 : 4'h0; // @[Mux.scala 81:58]
  wire [3:0] _pmemD_io_wmask_T_3 = 3'h1 == idu_io_funct3 ? 4'h3 : _pmemD_io_wmask_T_1; // @[Mux.scala 81:58]
  wire [1:0] byteOffset = pmemD_raddr[1:0]; // @[top.scala 61:32]
  wire [5:0] _byteOff_T = byteOffset * 4'h8; // @[top.scala 62:42]
  wire [31:0] byteOff = pmemD_rdata >> _byteOff_T; // @[top.scala 62:27]
  wire [15:0] halfOff = byteOff[15:0]; // @[top.scala 63:49]
  wire [23:0] _lbValue_T_2 = byteOff[7] ? 24'hffffff : 24'h0; // @[Bitwise.scala 74:12]
  wire [31:0] lbValue = {_lbValue_T_2,byteOff[7:0]}; // @[Cat.scala 31:58]
  wire [31:0] lbuValue = {24'h0,byteOff[7:0]}; // @[Cat.scala 31:58]
  wire [15:0] _lhValue_T_2 = halfOff[15] ? 16'hffff : 16'h0; // @[Bitwise.scala 74:12]
  wire [31:0] lhValue = {_lhValue_T_2,halfOff}; // @[Cat.scala 31:58]
  wire [31:0] lhuValue = {16'h0,halfOff}; // @[Cat.scala 31:58]
  wire [31:0] _loadData_T_1 = 3'h0 == idu_io_funct3 ? lbValue : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _loadData_T_3 = 3'h4 == idu_io_funct3 ? lbuValue : _loadData_T_1; // @[Mux.scala 81:58]
  wire [31:0] _loadData_T_5 = 3'h1 == idu_io_funct3 ? lhValue : _loadData_T_3; // @[Mux.scala 81:58]
  wire [31:0] _loadData_T_7 = 3'h5 == idu_io_funct3 ? lhuValue : _loadData_T_5; // @[Mux.scala 81:58]
  wire [31:0] loadData = 3'h2 == idu_io_funct3 ? pmemD_rdata : _loadData_T_7; // @[Mux.scala 81:58]
  wire  isBranch = idu_io_TYpe == 4'h3; // @[top.scala 78:30]
  wire  isJal = idu_io_TYpe == 4'h6; // @[top.scala 79:30]
  wire  isJalr = idu_io_TYpe == 4'h7; // @[top.scala 80:30]
  wire [31:0] _writeData_T = isJalr ? pcPlus4 : exu_io_result_out; // @[Mux.scala 101:16]
  wire [31:0] _writeData_T_1 = isJal ? pcPlus4 : _writeData_T; // @[Mux.scala 101:16]
  wire [31:0] branchTarget = exu_io_branch_taken ? exu_io_branch_target : pcPlus4; // @[top.scala 96:25]
  IFU ifu ( // @[top.scala 16:19]
    .clock(ifu_clock),
    .io_pc(ifu_io_pc),
    .io_valid(ifu_io_valid),
    .io_inst(ifu_io_inst)
  );
  IDU idu ( // @[top.scala 21:27]
    .io_instruction(idu_io_instruction),
    .io_rs1(idu_io_rs1),
    .io_rs2(idu_io_rs2),
    .io_rd(idu_io_rd),
    .io_funct3(idu_io_funct3),
    .io_funct7(idu_io_funct7),
    .io_imm(idu_io_imm),
    .io_TYpe(idu_io_TYpe),
    .io_IsIllegal(idu_io_IsIllegal),
    .io_IsInterrupt(idu_io_IsInterrupt),
    .io_isAuipc(idu_io_isAuipc)
  );
  RegFile regFile ( // @[top.scala 22:27]
    .clock(regFile_clock),
    .reset(regFile_reset),
    .io_rs1(regFile_io_rs1),
    .io_rs2(regFile_io_rs2),
    .io_rd(regFile_io_rd),
    .io_writeData(regFile_io_writeData),
    .io_writeEnable(regFile_io_writeEnable),
    .io_regData1(regFile_io_regData1),
    .io_regData2(regFile_io_regData2)
  );
  EXU exu ( // @[top.scala 23:27]
    .io_funct3(exu_io_funct3),
    .io_funct7(exu_io_funct7),
    .io_imm(exu_io_imm),
    .io_TYpe(exu_io_TYpe),
    .io_reg_rs1(exu_io_reg_rs1),
    .io_reg_rs2(exu_io_reg_rs2),
    .io_pc(exu_io_pc),
    .io_isAuipc(exu_io_isAuipc),
    .io_result_out(exu_io_result_out),
    .io_branch_taken(exu_io_branch_taken),
    .io_branch_target(exu_io_branch_target),
    .io_jump_target(exu_io_jump_target)
  );
  DPIHandlers dpiHandlers ( // @[top.scala 24:27]
    .IsIllegal(dpiHandlers_IsIllegal),
    .IsInterrupt(dpiHandlers_IsInterrupt)
  );
  Pmem pmemD ( // @[top.scala 42:21]
    .clock(pmemD_clock),
    .valid(pmemD_valid),
    .wen(pmemD_wen),
    .wmask(pmemD_wmask),
    .raddr(pmemD_raddr),
    .waddr(pmemD_waddr),
    .wdata(pmemD_wdata),
    .rdata(pmemD_rdata)
  );
  assign ifu_clock = clock;
  assign ifu_io_pc = pc; // @[top.scala 17:13]
  assign ifu_io_valid = valid; // @[top.scala 19:16]
  assign idu_io_instruction = ifu_io_inst; // @[top.scala 26:22]
  assign regFile_clock = clock;
  assign regFile_reset = reset;
  assign regFile_io_rs1 = idu_io_rs1; // @[top.scala 27:22]
  assign regFile_io_rs2 = idu_io_rs2; // @[top.scala 28:22]
  assign regFile_io_rd = idu_io_rd; // @[top.scala 93:26]
  assign regFile_io_writeData = isLoad ? loadData : _writeData_T_1; // @[Mux.scala 101:16]
  assign regFile_io_writeEnable = ~isBranch & ~isStore & ~idu_io_IsIllegal & ~idu_io_IsInterrupt; // @[top.scala 83:53]
  assign exu_io_funct3 = idu_io_funct3; // @[top.scala 30:19]
  assign exu_io_funct7 = idu_io_funct7; // @[top.scala 31:19]
  assign exu_io_imm = idu_io_imm; // @[top.scala 35:19]
  assign exu_io_TYpe = idu_io_TYpe; // @[top.scala 32:19]
  assign exu_io_reg_rs1 = regFile_io_regData1; // @[top.scala 33:19]
  assign exu_io_reg_rs2 = regFile_io_regData2; // @[top.scala 34:19]
  assign exu_io_pc = pc; // @[top.scala 36:19]
  assign exu_io_isAuipc = idu_io_isAuipc; // @[top.scala 37:19]
  assign dpiHandlers_IsIllegal = idu_io_IsIllegal; // @[top.scala 38:30]
  assign dpiHandlers_IsInterrupt = idu_io_IsInterrupt; // @[top.scala 39:30]
  assign pmemD_clock = clock; // @[top.scala 43:17]
  assign pmemD_valid = isLoad | isStore; // @[top.scala 47:28]
  assign pmemD_wen = idu_io_TYpe == 4'h2; // @[top.scala 45:29]
  assign pmemD_wmask = 3'h2 == idu_io_funct3 ? 4'hf : _pmemD_io_wmask_T_3; // @[Mux.scala 81:58]
  assign pmemD_raddr = exu_io_result_out; // @[top.scala 55:16]
  assign pmemD_waddr = exu_io_result_out; // @[top.scala 56:16]
  assign pmemD_wdata = regFile_io_regData2; // @[top.scala 46:18]
  always @(posedge clock) begin
    if (reset) begin // @[top.scala 11:24]
      pc <= 32'h80000000; // @[top.scala 11:24]
    end else if (4'h7 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= exu_io_jump_target;
    end else if (4'h6 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= exu_io_jump_target;
    end else if (4'h3 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= branchTarget;
    end else begin
      pc <= pcPlus4;
    end
    if (reset) begin // @[top.scala 13:22]
      valid <= 1'h0; // @[top.scala 13:22]
    end else begin
      valid <= 1'h1; // @[top.scala 14:9]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pc = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  valid = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

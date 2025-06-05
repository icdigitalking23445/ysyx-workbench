module IDU(
  input  [31:0] io_instruction,
  output [4:0]  io_rs1,
  output [4:0]  io_rs2,
  output [4:0]  io_rd,
  output [2:0]  io_funct3,
  output [6:0]  io_funct7,
  output [11:0] io_imm,
  output [3:0]  io_TYpe,
  output        io_IsIllegal,
  output        io_IsInterrupt
);
  wire [3:0] _io_TYpe_T_2 = 7'h33 == io_instruction[6:0] ? 4'h0 : 4'h8; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_4 = 7'h3 == io_instruction[6:0] ? 4'h1 : _io_TYpe_T_2; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_6 = 7'h23 == io_instruction[6:0] ? 4'h2 : _io_TYpe_T_4; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_8 = 7'h63 == io_instruction[6:0] ? 4'h3 : _io_TYpe_T_6; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_10 = 7'h13 == io_instruction[6:0] ? 4'h4 : _io_TYpe_T_8; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_12 = 7'h37 == io_instruction[6:0] ? 4'h5 : _io_TYpe_T_10; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_14 = 7'h6f == io_instruction[6:0] ? 4'h6 : _io_TYpe_T_12; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_16 = 7'h17 == io_instruction[6:0] ? 4'h5 : _io_TYpe_T_14; // @[Mux.scala 81:58]
  wire [3:0] _io_TYpe_T_18 = 7'h67 == io_instruction[6:0] ? 4'h7 : _io_TYpe_T_16; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_7 = 4'h0 == io_TYpe ? io_instruction[19:15] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_9 = 4'h1 == io_TYpe ? io_instruction[19:15] : _io_rs1_T_7; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_11 = 4'h2 == io_TYpe ? io_instruction[24:20] : _io_rs1_T_9; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_13 = 4'h3 == io_TYpe ? io_instruction[19:15] : _io_rs1_T_11; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_15 = 4'h4 == io_TYpe ? io_instruction[19:15] : _io_rs1_T_13; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_17 = 4'h5 == io_TYpe ? 5'h0 : _io_rs1_T_15; // @[Mux.scala 81:58]
  wire [4:0] _io_rs1_T_19 = 4'h6 == io_TYpe ? 5'h0 : _io_rs1_T_17; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_4 = 4'h0 == io_TYpe ? io_instruction[24:20] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_6 = 4'h1 == io_TYpe ? 5'h0 : _io_rs2_T_4; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_8 = 4'h2 == io_TYpe ? io_instruction[19:15] : _io_rs2_T_6; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_10 = 4'h3 == io_TYpe ? 5'h0 : _io_rs2_T_8; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_12 = 4'h4 == io_TYpe ? io_instruction[24:20] : _io_rs2_T_10; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_14 = 4'h5 == io_TYpe ? 5'h0 : _io_rs2_T_12; // @[Mux.scala 81:58]
  wire [4:0] _io_rs2_T_16 = 4'h6 == io_TYpe ? 5'h0 : _io_rs2_T_14; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_7 = 4'h0 == io_TYpe ? io_instruction[11:7] : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_9 = 4'h1 == io_TYpe ? io_instruction[11:7] : _io_rd_T_7; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_11 = 4'h2 == io_TYpe ? 5'h0 : _io_rd_T_9; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_13 = 4'h3 == io_TYpe ? 5'h0 : _io_rd_T_11; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_15 = 4'h4 == io_TYpe ? io_instruction[11:7] : _io_rd_T_13; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_17 = 4'h5 == io_TYpe ? io_instruction[11:7] : _io_rd_T_15; // @[Mux.scala 81:58]
  wire [4:0] _io_rd_T_19 = 4'h6 == io_TYpe ? io_instruction[11:7] : _io_rd_T_17; // @[Mux.scala 81:58]
  wire [11:0] _io_imm_T_1 = io_instruction[31:20]; // @[IDU.scala 80:45]
  wire [11:0] _io_imm_T_5 = {io_instruction[31:25],io_instruction[11:7]}; // @[IDU.scala 81:73]
  wire [11:0] _io_imm_T_10 = {io_instruction[31:25],io_instruction[11:8],io_instruction[7]}; // @[IDU.scala 82:92]
  wire [31:0] _io_imm_T_15 = {io_instruction[31:12],12'h0}; // @[IDU.scala 84:61]
  wire [11:0] _io_imm_T_24 = 4'h1 == io_TYpe ? $signed(_io_imm_T_1) : $signed(12'sh0); // @[Mux.scala 81:58]
  wire [11:0] _io_imm_T_26 = 4'h2 == io_TYpe ? $signed(_io_imm_T_5) : $signed(_io_imm_T_24); // @[Mux.scala 81:58]
  wire [11:0] _io_imm_T_28 = 4'h3 == io_TYpe ? $signed(_io_imm_T_10) : $signed(_io_imm_T_26); // @[Mux.scala 81:58]
  wire [11:0] _io_imm_T_30 = 4'h4 == io_TYpe ? $signed(_io_imm_T_1) : $signed(_io_imm_T_28); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_32 = 4'h5 == io_TYpe ? $signed(_io_imm_T_15) : $signed({{20{_io_imm_T_30[11]}},_io_imm_T_30}); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_34 = 4'h6 == io_TYpe ? $signed(_io_imm_T_15) : $signed(_io_imm_T_32); // @[Mux.scala 81:58]
  wire [31:0] _io_imm_T_36 = 4'h7 == io_TYpe ? $signed({{20{_io_imm_T_1[11]}},_io_imm_T_1}) : $signed(_io_imm_T_34); // @[Mux.scala 81:58]
  assign io_rs1 = 4'h7 == io_TYpe ? io_instruction[19:15] : _io_rs1_T_19; // @[Mux.scala 81:58]
  assign io_rs2 = 4'h7 == io_TYpe ? 5'h0 : _io_rs2_T_16; // @[Mux.scala 81:58]
  assign io_rd = 4'h7 == io_TYpe ? io_instruction[11:7] : _io_rd_T_19; // @[Mux.scala 81:58]
  assign io_funct3 = io_instruction[14:12]; // @[IDU.scala 88:32]
  assign io_funct7 = io_instruction[31:25]; // @[IDU.scala 89:32]
  assign io_imm = _io_imm_T_36[11:0]; // @[IDU.scala 78:12]
  assign io_TYpe = 7'h73 == io_instruction[6:0] ? 4'h9 : _io_TYpe_T_18; // @[Mux.scala 81:58]
  assign io_IsIllegal = io_TYpe == 4'h8; // @[IDU.scala 28:31]
  assign io_IsInterrupt = io_TYpe == 4'h9; // @[IDU.scala 30:33]
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
  wire [43:0] luiVal = {io_imm, 12'h0}; // @[EXU.scala 92:25]
  wire [43:0] _GEN_0 = {{12'd0}, io_pc}; // @[EXU.scala 94:24]
  wire [43:0] auipcVal = _GEN_0 + luiVal; // @[EXU.scala 94:24]
  wire [43:0] _io_out_T = io_isAuipc ? auipcVal : luiVal; // @[EXU.scala 95:16]
  assign io_out = _io_out_T[31:0]; // @[EXU.scala 95:10]
endmodule
module ALU(
  input  [2:0]  io_funct3,
  input  [6:0]  io_funct7,
  input  [3:0]  io_TYpe,
  input  [31:0] io_reg_rs1,
  input  [31:0] io_reg_rs2,
  input  [31:0] io_imm,
  input  [31:0] io_pc,
  output [31:0] io_result
);
  wire [31:0] addR_io_a; // @[EXU.scala 163:22]
  wire [31:0] addR_io_b; // @[EXU.scala 163:22]
  wire [31:0] addR_io_sum; // @[EXU.scala 163:22]
  wire [31:0] subR_io_a; // @[EXU.scala 167:22]
  wire [31:0] subR_io_b; // @[EXU.scala 167:22]
  wire [31:0] subR_io_diff; // @[EXU.scala 167:22]
  wire [31:0] shftr_io_in; // @[EXU.scala 171:22]
  wire [4:0] shftr_io_shamt; // @[EXU.scala 171:22]
  wire [2:0] shftr_io_funct3; // @[EXU.scala 171:22]
  wire [6:0] shftr_io_funct7; // @[EXU.scala 171:22]
  wire [31:0] shftr_io_out; // @[EXU.scala 171:22]
  wire [31:0] logicU_io_in1; // @[EXU.scala 177:22]
  wire [31:0] logicU_io_in2; // @[EXU.scala 177:22]
  wire [2:0] logicU_io_funct3; // @[EXU.scala 177:22]
  wire [31:0] logicU_io_out; // @[EXU.scala 177:22]
  wire [31:0] addI_io_a; // @[EXU.scala 198:22]
  wire [31:0] addI_io_b; // @[EXU.scala 198:22]
  wire [31:0] addI_io_sum; // @[EXU.scala 198:22]
  wire [31:0] addrAdd_io_a; // @[EXU.scala 214:23]
  wire [31:0] addrAdd_io_b; // @[EXU.scala 214:23]
  wire [31:0] addrAdd_io_sum; // @[EXU.scala 214:23]
  wire [31:0] uunit_io_imm; // @[EXU.scala 219:21]
  wire [31:0] uunit_io_pc; // @[EXU.scala 219:21]
  wire  uunit_io_isAuipc; // @[EXU.scala 219:21]
  wire [31:0] uunit_io_out; // @[EXU.scala 219:21]
  wire [31:0] _rtypeRes_T_1 = io_funct7[5] ? subR_io_diff : addR_io_sum; // @[EXU.scala 184:20]
  wire  _rtypeRes_T_4 = $signed(io_reg_rs1) < $signed(io_reg_rs2); // @[EXU.scala 186:36]
  wire  _rtypeRes_T_5 = io_reg_rs1 < io_reg_rs2; // @[EXU.scala 187:29]
  wire [31:0] _rtypeRes_T_10 = $signed(io_reg_rs1) >>> io_reg_rs2[4:0]; // @[EXU.scala 190:47]
  wire [31:0] _rtypeRes_T_12 = io_reg_rs1 >> io_reg_rs2[4:0]; // @[EXU.scala 191:19]
  wire [31:0] _rtypeRes_T_13 = io_funct7[5] ? _rtypeRes_T_10 : _rtypeRes_T_12; // @[EXU.scala 189:20]
  wire [31:0] _rtypeRes_T_15 = 3'h1 == io_funct3 ? shftr_io_out : _rtypeRes_T_1; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_17 = 3'h2 == io_funct3 ? {{31'd0}, _rtypeRes_T_4} : _rtypeRes_T_15; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_19 = 3'h3 == io_funct3 ? {{31'd0}, _rtypeRes_T_5} : _rtypeRes_T_17; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_21 = 3'h4 == io_funct3 ? logicU_io_out : _rtypeRes_T_19; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_23 = 3'h5 == io_funct3 ? _rtypeRes_T_13 : _rtypeRes_T_21; // @[Mux.scala 81:58]
  wire [31:0] _rtypeRes_T_25 = 3'h6 == io_funct3 ? logicU_io_out : _rtypeRes_T_23; // @[Mux.scala 81:58]
  wire [31:0] rtypeRes = 3'h7 == io_funct3 ? logicU_io_out : _rtypeRes_T_25; // @[Mux.scala 81:58]
  wire  _itypeRes_T_2 = $signed(io_reg_rs1) < $signed(io_imm); // @[EXU.scala 205:36]
  wire  _itypeRes_T_3 = io_reg_rs1 < io_imm; // @[EXU.scala 206:29]
  wire [31:0] _itypeRes_T_4 = io_reg_rs1 ^ io_imm; // @[EXU.scala 207:29]
  wire [31:0] _itypeRes_T_5 = io_reg_rs1 | io_imm; // @[EXU.scala 208:29]
  wire [31:0] _itypeRes_T_6 = io_reg_rs1 & io_imm; // @[EXU.scala 209:29]
  wire [31:0] _itypeRes_T_8 = 3'h0 == io_funct3 ? addI_io_sum : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_10 = 3'h2 == io_funct3 ? {{31'd0}, _itypeRes_T_2} : _itypeRes_T_8; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_12 = 3'h3 == io_funct3 ? {{31'd0}, _itypeRes_T_3} : _itypeRes_T_10; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_14 = 3'h4 == io_funct3 ? _itypeRes_T_4 : _itypeRes_T_12; // @[Mux.scala 81:58]
  wire [31:0] _itypeRes_T_16 = 3'h6 == io_funct3 ? _itypeRes_T_5 : _itypeRes_T_14; // @[Mux.scala 81:58]
  wire [31:0] itypeRes = 3'h7 == io_funct3 ? _itypeRes_T_6 : _itypeRes_T_16; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_1 = 4'h0 == io_TYpe ? rtypeRes : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_3 = 4'h1 == io_TYpe ? addrAdd_io_sum : _io_result_T_1; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_5 = 4'h2 == io_TYpe ? addrAdd_io_sum : _io_result_T_3; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_7 = 4'h3 == io_TYpe ? 32'h0 : _io_result_T_5; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_9 = 4'h4 == io_TYpe ? itypeRes : _io_result_T_7; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_11 = 4'h5 == io_TYpe ? uunit_io_out : _io_result_T_9; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_13 = 4'h6 == io_TYpe ? 32'h0 : _io_result_T_11; // @[Mux.scala 81:58]
  Adder32 addR ( // @[EXU.scala 163:22]
    .io_a(addR_io_a),
    .io_b(addR_io_b),
    .io_sum(addR_io_sum)
  );
  Sub32 subR ( // @[EXU.scala 167:22]
    .io_a(subR_io_a),
    .io_b(subR_io_b),
    .io_diff(subR_io_diff)
  );
  Shifter shftr ( // @[EXU.scala 171:22]
    .io_in(shftr_io_in),
    .io_shamt(shftr_io_shamt),
    .io_funct3(shftr_io_funct3),
    .io_funct7(shftr_io_funct7),
    .io_out(shftr_io_out)
  );
  LogicUnit logicU ( // @[EXU.scala 177:22]
    .io_in1(logicU_io_in1),
    .io_in2(logicU_io_in2),
    .io_funct3(logicU_io_funct3),
    .io_out(logicU_io_out)
  );
  Adder32 addI ( // @[EXU.scala 198:22]
    .io_a(addI_io_a),
    .io_b(addI_io_b),
    .io_sum(addI_io_sum)
  );
  Adder32 addrAdd ( // @[EXU.scala 214:23]
    .io_a(addrAdd_io_a),
    .io_b(addrAdd_io_b),
    .io_sum(addrAdd_io_sum)
  );
  UTypeUnit uunit ( // @[EXU.scala 219:21]
    .io_imm(uunit_io_imm),
    .io_pc(uunit_io_pc),
    .io_isAuipc(uunit_io_isAuipc),
    .io_out(uunit_io_out)
  );
  assign io_result = 4'h7 == io_TYpe ? 32'h0 : _io_result_T_13; // @[Mux.scala 81:58]
  assign addR_io_a = io_reg_rs1; // @[EXU.scala 164:14]
  assign addR_io_b = io_reg_rs2; // @[EXU.scala 165:14]
  assign subR_io_a = io_reg_rs1; // @[EXU.scala 168:14]
  assign subR_io_b = io_reg_rs2; // @[EXU.scala 169:14]
  assign shftr_io_in = io_reg_rs1; // @[EXU.scala 172:19]
  assign shftr_io_shamt = io_reg_rs2[4:0]; // @[EXU.scala 173:32]
  assign shftr_io_funct3 = io_funct3; // @[EXU.scala 174:19]
  assign shftr_io_funct7 = io_funct7; // @[EXU.scala 175:19]
  assign logicU_io_in1 = io_reg_rs1; // @[EXU.scala 178:20]
  assign logicU_io_in2 = io_reg_rs2; // @[EXU.scala 179:20]
  assign logicU_io_funct3 = io_funct3; // @[EXU.scala 180:20]
  assign addI_io_a = io_reg_rs1; // @[EXU.scala 199:14]
  assign addI_io_b = io_imm; // @[EXU.scala 200:14]
  assign addrAdd_io_a = io_reg_rs1; // @[EXU.scala 215:16]
  assign addrAdd_io_b = io_imm; // @[EXU.scala 216:16]
  assign uunit_io_imm = io_imm; // @[EXU.scala 220:20]
  assign uunit_io_pc = io_pc; // @[EXU.scala 221:20]
  assign uunit_io_isAuipc = io_TYpe == 4'h5; // @[EXU.scala 223:32]
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
  input  [11:0] io_imm,
  input  [3:0]  io_TYpe,
  input  [31:0] io_reg_rs1,
  input  [31:0] io_reg_rs2,
  input  [31:0] io_pc,
  output [31:0] io_result_out,
  output        io_branch_taken,
  output [31:0] io_branch_target,
  output [31:0] io_jump_target
);
  wire [2:0] alu_io_funct3; // @[EXU.scala 262:19]
  wire [6:0] alu_io_funct7; // @[EXU.scala 262:19]
  wire [3:0] alu_io_TYpe; // @[EXU.scala 262:19]
  wire [31:0] alu_io_reg_rs1; // @[EXU.scala 262:19]
  wire [31:0] alu_io_reg_rs2; // @[EXU.scala 262:19]
  wire [31:0] alu_io_imm; // @[EXU.scala 262:19]
  wire [31:0] alu_io_pc; // @[EXU.scala 262:19]
  wire [31:0] alu_io_result; // @[EXU.scala 262:19]
  wire [31:0] branchUnit_io_in1; // @[EXU.scala 272:26]
  wire [31:0] branchUnit_io_in2; // @[EXU.scala 272:26]
  wire [2:0] branchUnit_io_funct3; // @[EXU.scala 272:26]
  wire [31:0] branchUnit_io_pc; // @[EXU.scala 272:26]
  wire [31:0] branchUnit_io_imm; // @[EXU.scala 272:26]
  wire  branchUnit_io_taken; // @[EXU.scala 272:26]
  wire [31:0] branchUnit_io_branch_target; // @[EXU.scala 272:26]
  wire [31:0] jumpUnit_io_pc; // @[EXU.scala 280:24]
  wire [31:0] jumpUnit_io_rs1; // @[EXU.scala 280:24]
  wire [31:0] jumpUnit_io_imm; // @[EXU.scala 280:24]
  wire  jumpUnit_io_isJal; // @[EXU.scala 280:24]
  wire [31:0] jumpUnit_io_jump_pc; // @[EXU.scala 280:24]
  wire [11:0] _alu_io_imm_T = io_imm; // @[EXU.scala 268:28]
  wire [31:0] _GEN_0 = 4'h7 == io_TYpe ? jumpUnit_io_jump_pc : 32'h0; // @[EXU.scala 293:19 291:20 304:22]
  wire [31:0] _GEN_1 = 4'h7 == io_TYpe ? jumpUnit_io_jump_pc : alu_io_result; // @[EXU.scala 293:19 288:20 305:22]
  wire [31:0] _GEN_2 = 4'h6 == io_TYpe ? jumpUnit_io_jump_pc : _GEN_0; // @[EXU.scala 293:19 300:22]
  wire [31:0] _GEN_3 = 4'h6 == io_TYpe ? jumpUnit_io_jump_pc : _GEN_1; // @[EXU.scala 293:19 301:22]
  ALU alu ( // @[EXU.scala 262:19]
    .io_funct3(alu_io_funct3),
    .io_funct7(alu_io_funct7),
    .io_TYpe(alu_io_TYpe),
    .io_reg_rs1(alu_io_reg_rs1),
    .io_reg_rs2(alu_io_reg_rs2),
    .io_imm(alu_io_imm),
    .io_pc(alu_io_pc),
    .io_result(alu_io_result)
  );
  BranchUnit branchUnit ( // @[EXU.scala 272:26]
    .io_in1(branchUnit_io_in1),
    .io_in2(branchUnit_io_in2),
    .io_funct3(branchUnit_io_funct3),
    .io_pc(branchUnit_io_pc),
    .io_imm(branchUnit_io_imm),
    .io_taken(branchUnit_io_taken),
    .io_branch_target(branchUnit_io_branch_target)
  );
  JumpUnit jumpUnit ( // @[EXU.scala 280:24]
    .io_pc(jumpUnit_io_pc),
    .io_rs1(jumpUnit_io_rs1),
    .io_imm(jumpUnit_io_imm),
    .io_isJal(jumpUnit_io_isJal),
    .io_jump_pc(jumpUnit_io_jump_pc)
  );
  assign io_result_out = 4'h3 == io_TYpe ? {{31'd0}, branchUnit_io_taken} : _GEN_3; // @[EXU.scala 293:19 297:24]
  assign io_branch_taken = 4'h3 == io_TYpe & branchUnit_io_taken; // @[EXU.scala 293:19 289:20 295:24]
  assign io_branch_target = 4'h3 == io_TYpe ? branchUnit_io_branch_target : 32'h0; // @[EXU.scala 293:19 290:20 296:24]
  assign io_jump_target = 4'h3 == io_TYpe ? 32'h0 : _GEN_2; // @[EXU.scala 293:19 291:20]
  assign alu_io_funct3 = io_funct3; // @[EXU.scala 263:18]
  assign alu_io_funct7 = io_funct7; // @[EXU.scala 264:18]
  assign alu_io_TYpe = io_TYpe; // @[EXU.scala 265:18]
  assign alu_io_reg_rs1 = io_reg_rs1; // @[EXU.scala 266:18]
  assign alu_io_reg_rs2 = io_reg_rs2; // @[EXU.scala 267:18]
  assign alu_io_imm = {{20'd0}, _alu_io_imm_T}; // @[EXU.scala 268:18]
  assign alu_io_pc = io_pc; // @[EXU.scala 269:18]
  assign branchUnit_io_in1 = io_reg_rs1; // @[EXU.scala 273:24]
  assign branchUnit_io_in2 = io_reg_rs2; // @[EXU.scala 274:24]
  assign branchUnit_io_funct3 = io_funct3; // @[EXU.scala 275:24]
  assign branchUnit_io_pc = io_pc; // @[EXU.scala 276:24]
  assign branchUnit_io_imm = {{20'd0}, _alu_io_imm_T}; // @[EXU.scala 277:24]
  assign jumpUnit_io_pc = io_pc; // @[EXU.scala 281:21]
  assign jumpUnit_io_rs1 = io_reg_rs1; // @[EXU.scala 282:21]
  assign jumpUnit_io_imm = {{20'd0}, _alu_io_imm_T}; // @[EXU.scala 283:21]
  assign jumpUnit_io_isJal = io_TYpe == 4'h6; // @[EXU.scala 284:33]
endmodule
module top(
  input         clock,
  input         reset,
  input  [31:0] io_instruction,
  output [31:0] io_pc
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] idu_io_instruction; // @[top.scala 24:19]
  wire [4:0] idu_io_rs1; // @[top.scala 24:19]
  wire [4:0] idu_io_rs2; // @[top.scala 24:19]
  wire [4:0] idu_io_rd; // @[top.scala 24:19]
  wire [2:0] idu_io_funct3; // @[top.scala 24:19]
  wire [6:0] idu_io_funct7; // @[top.scala 24:19]
  wire [11:0] idu_io_imm; // @[top.scala 24:19]
  wire [3:0] idu_io_TYpe; // @[top.scala 24:19]
  wire  idu_io_IsIllegal; // @[top.scala 24:19]
  wire  idu_io_IsInterrupt; // @[top.scala 24:19]
  wire  regFile_clock; // @[top.scala 25:23]
  wire  regFile_reset; // @[top.scala 25:23]
  wire [4:0] regFile_io_rs1; // @[top.scala 25:23]
  wire [4:0] regFile_io_rs2; // @[top.scala 25:23]
  wire [4:0] regFile_io_rd; // @[top.scala 25:23]
  wire [31:0] regFile_io_writeData; // @[top.scala 25:23]
  wire  regFile_io_writeEnable; // @[top.scala 25:23]
  wire [31:0] regFile_io_regData1; // @[top.scala 25:23]
  wire [31:0] regFile_io_regData2; // @[top.scala 25:23]
  wire [2:0] exu_io_funct3; // @[top.scala 26:19]
  wire [6:0] exu_io_funct7; // @[top.scala 26:19]
  wire [11:0] exu_io_imm; // @[top.scala 26:19]
  wire [3:0] exu_io_TYpe; // @[top.scala 26:19]
  wire [31:0] exu_io_reg_rs1; // @[top.scala 26:19]
  wire [31:0] exu_io_reg_rs2; // @[top.scala 26:19]
  wire [31:0] exu_io_pc; // @[top.scala 26:19]
  wire [31:0] exu_io_result_out; // @[top.scala 26:19]
  wire  exu_io_branch_taken; // @[top.scala 26:19]
  wire [31:0] exu_io_branch_target; // @[top.scala 26:19]
  wire [31:0] exu_io_jump_target; // @[top.scala 26:19]
  wire  dpiHandlers_IsIllegal; // @[top.scala 27:27]
  wire  dpiHandlers_IsInterrupt; // @[top.scala 27:27]
  reg [31:0] pc; // @[top.scala 11:19]
  wire [31:0] pc_snpc = pc + 32'h4; // @[top.scala 12:20]
  wire  isBranch = idu_io_TYpe == 4'h3; // @[top.scala 49:31]
  wire  isStore = idu_io_TYpe == 4'h2; // @[top.scala 50:31]
  wire  isJal = idu_io_TYpe == 4'h6; // @[top.scala 51:31]
  wire  isJalr = idu_io_TYpe == 4'h7; // @[top.scala 52:31]
  wire  _writeData_T = isJal | isJalr; // @[top.scala 60:9]
  wire [31:0] branchPath = exu_io_branch_taken ? exu_io_branch_target : pc_snpc; // @[top.scala 68:6]
  IDU idu ( // @[top.scala 24:19]
    .io_instruction(idu_io_instruction),
    .io_rs1(idu_io_rs1),
    .io_rs2(idu_io_rs2),
    .io_rd(idu_io_rd),
    .io_funct3(idu_io_funct3),
    .io_funct7(idu_io_funct7),
    .io_imm(idu_io_imm),
    .io_TYpe(idu_io_TYpe),
    .io_IsIllegal(idu_io_IsIllegal),
    .io_IsInterrupt(idu_io_IsInterrupt)
  );
  RegFile regFile ( // @[top.scala 25:23]
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
  EXU exu ( // @[top.scala 26:19]
    .io_funct3(exu_io_funct3),
    .io_funct7(exu_io_funct7),
    .io_imm(exu_io_imm),
    .io_TYpe(exu_io_TYpe),
    .io_reg_rs1(exu_io_reg_rs1),
    .io_reg_rs2(exu_io_reg_rs2),
    .io_pc(exu_io_pc),
    .io_result_out(exu_io_result_out),
    .io_branch_taken(exu_io_branch_taken),
    .io_branch_target(exu_io_branch_target),
    .io_jump_target(exu_io_jump_target)
  );
  DPIHandlers dpiHandlers ( // @[top.scala 27:27]
    .IsIllegal(dpiHandlers_IsIllegal),
    .IsInterrupt(dpiHandlers_IsInterrupt)
  );
  assign io_pc = pc; // @[top.scala 17:9]
  assign idu_io_instruction = io_instruction; // @[top.scala 32:22]
  assign regFile_clock = clock;
  assign regFile_reset = reset;
  assign regFile_io_rs1 = idu_io_rs1; // @[top.scala 42:18]
  assign regFile_io_rs2 = idu_io_rs2; // @[top.scala 43:18]
  assign regFile_io_rd = idu_io_rd; // @[top.scala 44:17]
  assign regFile_io_writeData = _writeData_T ? exu_io_jump_target : exu_io_result_out; // @[top.scala 59:16]
  assign regFile_io_writeEnable = ~isBranch & ~isStore & ~idu_io_IsIllegal & ~idu_io_IsInterrupt; // @[top.scala 56:52]
  assign exu_io_funct3 = idu_io_funct3; // @[top.scala 33:17]
  assign exu_io_funct7 = idu_io_funct7; // @[top.scala 34:17]
  assign exu_io_imm = idu_io_imm; // @[top.scala 35:14]
  assign exu_io_TYpe = idu_io_TYpe; // @[top.scala 36:15]
  assign exu_io_reg_rs1 = regFile_io_regData1; // @[top.scala 37:18]
  assign exu_io_reg_rs2 = regFile_io_regData2; // @[top.scala 38:18]
  assign exu_io_pc = pc; // @[top.scala 39:13]
  assign dpiHandlers_IsIllegal = idu_io_IsIllegal; // @[top.scala 29:30]
  assign dpiHandlers_IsInterrupt = idu_io_IsInterrupt; // @[top.scala 30:30]
  always @(posedge clock) begin
    if (reset) begin // @[top.scala 11:19]
      pc <= 32'h80000000; // @[top.scala 11:19]
    end else if (4'h6 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= exu_io_jump_target;
    end else if (4'h7 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= exu_io_jump_target;
    end else if (4'h3 == idu_io_TYpe) begin // @[Mux.scala 81:58]
      pc <= branchPath;
    end else begin
      pc <= pc_snpc;
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
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

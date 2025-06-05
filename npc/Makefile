include ../Makefile


override VERILATOR := /home/weiyaoli/Documents/ysyx-workbench/verilator/bin/verilator
override VERILATOR_ROOT := /home/weiyaoli/Documents/ysyx-workbench/verilator
CXX      := g++
CXXFLAGS := -O2 -std=c++17 \
            -I$(VERILATOR_ROOT)/include \
            -Iobj_dir                    # obj_dir 下会产生 *.h
VERILOG_TOP := vsrc/top.v
VERILOG_OTHER := vsrc/DPIHandlers.v
SIM_CPP     := csrc/main.cpp
SIM_CPP       += csrc/dpi_handlers.cpp
VERILATED_LIB := obj_dir/Vtop__ALL.a
SIM_EXE    := sim
.PHONY: all verilate sim clean

# 默认 target：先综合再生成可执行
all: sim
sim: verilator_ok
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "----> Copying simulator binary to ./$(SIM_EXE)"
	cp obj_dir/Vtop $(SIM_EXE) || cp obj_dir/Vtop.exe $(SIM_EXE)
	


verilate:
	@echo "----> Running Verilator from $(VERILATOR) on $(VERILOG_TOP) ..."
	$(VERILATOR) --cc $(VERILOG_TOP) $(VERILOG_OTHER) \
	             --exe $(SIM_CPP) \
				 --trace \
	             -CFLAGS "-std=c++17" \
	             --build \
	             --top-module top

verilator_ok: verilate
	@if [ -f obj_dir/Vtop__ALL.a ]; then \
	  echo "----> Verilator build OK"; \
	else \
	  echo "====> Error: Verilator did not produce obj_dir/Vtop__ALL.a"; exit 1; \
	fi


clean:
	@echo "----> Cleaning all generated files"
	rm -rf obj_dir $(SIM_EXE)	


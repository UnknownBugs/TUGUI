SRCS:= test_drawXYLine.cpp

INC := $(addprefix -I,$(TOP_DIR))

EFI := $(SRCS:.cpp=)
EFI := $(addprefix $(BIN_DIR)/,$(EFI))

$(EFI): $(SRCS)
	@echo + $@
	$(CXX) $^ $(CXX_FLAGS) -o $@ $(INC)

module := xy_line
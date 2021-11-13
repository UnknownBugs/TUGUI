SRCS:= test_circle.cpp

INC := $(addprefix -I,$(INC_DIR))

EFI := $(SRCS:.cpp=)
EFI := $(addprefix $(BIN_DIR)/,$(EFI))

$(EFI): $(SRCS)
	@echo + $@
	$(CXX) $^ $(CXX_FLAGS) -o $@ $(INC)

module := circle
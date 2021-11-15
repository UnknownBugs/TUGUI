SRCS:= test_rectangle.cpp

INC := $(addprefix -I,$(INC_DIR))

EFI := $(SRCS:.cpp=)
EFI := $(addprefix $(BIN_DIR)/,$(EFI))

$(EFI): $(SRCS)
	@echo + $@
	$(CXX) $^ $(CXX_FLAGS) -o $@ $(INC)

module := rectangle
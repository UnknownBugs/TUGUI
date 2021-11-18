MODULE := coordinate_line
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := test_coordinate_line.cpp

INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(EFI): $(SRCS)
	@echo + $@
	$(CXX) -c $^ $(CXX_FLAGS) -o $(OBJS) $(INC)
	$(CXX) $(LD_FLAGS) $(CXX_FLAGS) $(BOOTMAIN_OBJS) $(OBJS) -o $@
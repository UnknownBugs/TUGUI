MODULE := circle
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := test_circle.cpp

INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(EFI): $(SRCS)
	@echo + $@
	$(CXX) -c $^ $(CXX_FLAGS) -o $(OBJS) $(INC)
	$(LD) $(LD_FLAGS) $(BOOTMAIN_OBJS) $(OBJS) -o $@
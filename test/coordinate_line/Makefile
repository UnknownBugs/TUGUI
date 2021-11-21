MODULE := coordinate_line
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := test_coordinate_line.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(EFI): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $@
	$(CXX) -c $(SRCS) $(CXX_FLAGS) -o $(OBJS) $(LOCAL_INC)
	$(CXX) $(LD_FLAGS) $(CXX_FLAGS) $(BOOTMAIN_OBJS) $(OBJS) -o $@ $(UEFI_APP_CXX_FLAGS)
MODULE := debug
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := t_debug_temp.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

$(EFI): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $@
	$(CXX) -c $(SRCS) $(CXX_FLAGS) -o $(OBJS) $(LOCAL_INC)
	$(LD) $(LD_FLAGS) $(BOOTMAIN_OBJS) $(OBJS) -o $@  $(UEFI_APP_LD_FLAGS)
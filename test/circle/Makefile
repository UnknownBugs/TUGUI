MODULE := circle
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := test_circle.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(EFI): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $@
	$(CXX) -c $(SRCS) $(CXX_FLAGS) -o $(OBJS) $(LOCAL_INC)
	$(LD) $(LD_FLAGS) $(BOOTMAIN_OBJS) $(OBJS) -o $@ -subsystem=10
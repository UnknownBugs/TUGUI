SRCS := uefi_bootmain.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(OBJS): $(SRCS)
	@echo + $@
	$(CXX) -c $^ $(CXX_FLAGS) -o $@ $(LOCAL_INC)

module := uefi_bootmain
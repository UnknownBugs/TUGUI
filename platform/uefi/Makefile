SRCS := uefi_bootmain.cpp

LOCAL_INC_DIR := $(LIBS) \
                 platform \
                 platform/uefi/wrapper \
				 src/colors
LOCAL_INC_DIR := $(addprefix $(TOP_DIR)/,$(LOCAL_INC_DIR))
LOCAL_INC := $(addprefix -I,$(LOCAL_INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(OBJS): $(SRCS)
	@echo + $@
	$(CXX) -c $^ $(CXX_FLAGS) -o $@ $(LOCAL_INC)

module := uefi_bootmain
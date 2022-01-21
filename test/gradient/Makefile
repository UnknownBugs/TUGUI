include ../../tools/makefile/function.mk

MODULE := gradient

LOCAL_OBJ_DIR := $(OBJ_DIR)/$(MODULE)
LOCAL_BIN_DIR := $(BIN_DIR)/$(MODULE)

SRCS := t_gradient_circle.cpp \
        t_gradient_line.cpp \
		t_gradient_rectangle.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(LOCAL_OBJ_DIR)/,$(OBJS))


# batch compiler to obj by CXX
CXX_CMDS = $(call batchCompilerCmds,$(CXX),$(SRCS), -c $(CXX_FLAGS) $(LOCAL_INC),$(LOCAL_OBJ_DIR),srcToObjFile)
# batch compiler/ld to bin by LD
LD_CMDS = $(call batchCompilerCmds,$(LD),$(OBJS),$(LD_FLAGS) $(UEFI_APP_LD_FLAGS) $(BOOTMAIN_OBJS),$(LOCAL_BIN_DIR),objToBinFile)


$(MODULE): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $(MODULE)
	@mkdir -p $(LOCAL_OBJ_DIR) $(LOCAL_BIN_DIR)
	$(CXX_CMDS)
	$(LD_CMDS)
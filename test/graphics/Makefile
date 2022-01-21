include ../../tools/makefile/function.mk

MODULE := graphics

SRCS := t_graphics_line.cpp \
		t_graphics_rectangle.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

# batch compiler to obj by CXX
CXX_CMDS = $(call batchCompilerCmds,$(CXX),$(SRCS), -c $(CXX_FLAGS) $(LOCAL_INC),$(OBJ_DIR),srcToObjFile)
# batch compiler/ld to bin by LD
LD_CMDS = $(call batchCompilerCmds,$(LD),$(OBJS),$(LD_FLAGS) $(UEFI_APP_LD_FLAGS) $(BOOTMAIN_OBJS),$(BIN_DIR),objToBinFile)

$(MODULE): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $(MODULE)
	$(CXX_CMDS)
	$(LD_CMDS)
	
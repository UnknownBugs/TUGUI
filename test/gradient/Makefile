include ../../tools/makefile/function.mk

MODULE := gradient
EFI := $(addprefix $(BIN_DIR)/,$(MODULE))

SRCS := t_gradient_circle.cpp \
        t_gradient_line.cpp \
		t_gradient_rectangle.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

# batch compiler to obj by CXX
CXX_CMDS = $(call batchCompilerCmds,$(CXX),$(SRCS), -c $(CXX_FLAGS) $(LOCAL_INC),$(OBJ_DIR),srcToObjFile)
# batch compiler/ld to bin by LD
LD_CMDS = $(call batchCompilerCmds,$(LD),$(OBJS),$(LD_FLAGS) $(UEFI_APP_LD_FLAGS) $(BOOTMAIN_OBJS),$(BIN_DIR),objToBinFile)


$(MODULE): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@for cmd in $(CXX_CMDS); do \
		echo $$cmd; eval $$cmd; \
	done
	@for cmd in $(LD_CMDS); do \
		echo $$cmd; eval $$cmd; \
	done
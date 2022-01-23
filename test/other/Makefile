include ../tools/makefile/function.mk

MODULE := test

SRCS := base_grahics.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

# batch compiler to obj by CXX
CXX_CMDS = $(call batchCompilerCmds,$(CXX),$(SRCS), -c $(CXX_FLAGS) $(LOCAL_INC) ,$(OBJ_DIR),srcToObjFile)
# batch compiler/ld to bin by LD
LD_CMDS = $(call batchCompilerCmds,$(LD),$(OBJS),$(LD_FLAGS),$(BIN_DIR),objToBinFile)

$(MODULE): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $(MODULE)
	$(CXX_CMDS)
	$(LD_CMDS)
	
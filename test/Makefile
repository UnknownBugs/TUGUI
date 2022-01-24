include ../tools/makefile/function.mk

MODULE := base

SRCS := base_graphics.cpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

# batch compiler to obj by CXX
CXX_CMDS = $(call batchCompilerCmds,$(CXX),$(SRCS),$(CXX_FLAGS) $(LOCAL_INC),$(BIN_DIR),srcToBinFile)

$(MODULE): $(SRCS) $(TUGUI_INCLUDE_FILE)
	@echo + $(MODULE)
	$(CXX_CMDS)

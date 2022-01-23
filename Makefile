include platform/platform.mk

# project dir
TOP_DIR := $(shell pwd)

RM := rm
MKDIR := mkdir
MAKE := make


CXX := g++ 
CXX_FLAGS := -Wall -Wextra \
             $(LINUX_CXX_FLAGS)

# ld
LD := ld
LD_FLAGS  = -e main \
            -lc \
            $(LINUX_LD_FLAGS)

# obj, bin dir
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin

SUBDIRS := test

INC_DIR = core \
          ./

INC_DIR := $(PLATFORM_INC_DIR) \
           $(addprefix $(TOP_DIR)/,$(INC_DIR))


export LD LD_FLAGS
export CXX CXX_FLAGS

export TUGUI_INCLUDE_FILE
export TOP_DIR
export INC_DIR
export OBJ_DIR
export BIN_DIR

all : CreateDir $(SUBDIRS)
	@echo -e $(Info)

CreateDir:
	@echo + dir: obj bin
	@echo $(modules): hahahaha...

	@$(MKDIR) -p $(OBJ_DIR) $(BIN_DIR)

$(SUBDIRS): NULL
	@$(MAKE) -C $@

NULL:


.PHONY : clean

clean :
	rm -rf obj bin

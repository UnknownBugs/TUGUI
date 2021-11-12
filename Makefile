include tools/module_name.mk

# project dir
TOP_DIR := $(shell pwd)

# obj, bin dir
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin
# libs and include
LIBS_DIR := $(TOP_DIR)

ifeq ($(modules),)
SUBDIRS := 	test/xy_line \
			test/straight_line
else
SUBDIRS := $($(modules))
endif

# compilers & app
CXX := x86_64-w64-mingw32-g++
RM = rm
MKDIR = mkdir
MAKE = make

# flag
CXX_FLAGS := -e tugui_main -Wall -Wextra -nostdinc -nostdlib \
        -fno-builtin -Wl,--subsystem,10


export CXX
export CXX_FLAGS

export TOP_DIR
export LIBS_DIR
export OBJ_DIR
export BIN_DIR

all : CreateDir $(SUBDIRS)

CreateDir:
	@echo + dir: obj bin
	@echo $(modules): go

	@$(MKDIR) -p $(OBJ_DIR) $(BIN_DIR)

$(SUBDIRS): NULL
	@$(MAKE) -C $@

NULL:


.PHONY : clean
clean :
	rm -rf obj bin
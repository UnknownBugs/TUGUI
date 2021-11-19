include tools/module_name.mk
include platform/bootmain.mk

# project dir
TOP_DIR := $(shell pwd)

# obj, bin dir
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin

LIBS 	:= libs/MUTILS \
           libs/TDEBUG \
		   libs/TMATH

# include
INC_DIR := $(LIBS) \
           src \
           src/colors \
		   platform \
		   $(PLATFORM_INC_DIR)

INC_DIR := $(addprefix $(TOP_DIR)/,$(INC_DIR))

SUBDIRS := platform/uefi
ifeq ($(modules),)
SUBDIRS += 	test/coordinate_line \
			test/straight_line \
			test/circle \
			test/rectangle
else
SUBDIRS += $($(modules))
endif

LD := x86_64-w64-mingw32-ld
LD_FLAGS := -e tugui_bootmain \
			-nostdinc -nostdinc++ -nostdlib
UEFI_APP_LD_FLAGS := -subsystem=10

# compilers & app
CXX := x86_64-w64-mingw32-g++ 
RM := rm
MKDIR := mkdir
MAKE := make

# flag
# -ffreestanding : __main
CXX_FLAGS := -Wall -Wextra \
        	 -fno-builtin  \
			 -nostdinc -nostdlib \
			 -fno-rtti

UEFI_APP_CXX_FLAGS := -Wl,--subsystem,10

export LD LD_FLAGS UEFI_APP_LD_FLAGS
export CXX CXX_FLAGS UEFI_APP_CXX_FLAGS

export LIBS
export SRCS
export TOP_DIR
export INC_DIR
export OBJ_DIR
export BIN_DIR

BOOTMAIN_OBJS := $(addsuffix .o,$(BOOTMAIN))
BOOTMAIN_OBJS := $(addprefix $(OBJ_DIR)/,$(BOOTMAIN_OBJS))

#SRCS := $(foreach path,$(SUBDIRS), \
            $(notdir \
			    $(wildcard $(path)/*.cpp) \
			) \
        )
#OBJS := $(SRCS:.cpp=.o)
#OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

all : CreateDir $(SUBDIRS)

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
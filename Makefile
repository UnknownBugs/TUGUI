include tools/makefile/function.mk
include modules_info.mk
include platform/bootmain.mk
include libs/UEFIWrapper/UefiWrapperInclude.mk

# project dir
TOP_DIR := $(shell pwd)

LD := x86_64-w64-mingw32-ld
LD_FLAGS := -e tugui_bootmain 

ifneq ($(shell echo $(shell uname -r) | awk -F '-' '{ print $$3 }'),MANJARO)
LD_FLAGS +=  -nostdinc -nostdinc++ -nostdlib
endif

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
             -fno-rtti \
             -fno-exceptions

UEFI_APP_CXX_FLAGS := -Wl,--subsystem,10


# obj, bin dir
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin

UEFIWRAPPER_LIB_INC := libs/UEFIWrapper \
                       $(addprefix libs/UEFIWrapper/,$(UEFIWRAPPER_LIB_INC))


LIBS    := libs/MUTILS \
           libs/TDEBUG \
           libs/TMATH \
<<<<<<< HEAD
           libs/Uefi \
           libs/UEFIWrapper \
=======
           $(UEFIWRAPPER_LIB_INC) \
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
           libs/std

# include
INC_DIR := $(LIBS) \
           platform \
           core \
           ./

INC_DIR := $(addprefix $(TOP_DIR)/,$(INC_DIR))

SUBDIRS := platform/uefi
ifeq ($(modules),)
SUBDIRS += 	$(ALL_MODULES)
else
SUBDIRS += $($(modules))
endif

TUGUI_INCLUDE_FILE := $(TOP_DIR)/core/tugui.hpp
NEW_TUGUI_INCLUDE_FILE := $(TOP_DIR)/core/new_tugui.hpp

export LD LD_FLAGS UEFI_APP_LD_FLAGS
export CXX CXX_FLAGS UEFI_APP_CXX_FLAGS

export TUGUI_INCLUDE_FILE
export LIBS
export SRCS
export TOP_DIR
export INC_DIR
export OBJ_DIR
export BIN_DIR

export modules

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
	@echo -e $(Info)

CreateDir:
	@echo + dir: obj bin
	@echo $(modules): hahahaha...

	@$(MKDIR) -p $(OBJ_DIR) $(BIN_DIR)

$(SUBDIRS): NULL
	@$(MAKE) -C $@

NULL:


.PHONY : modules clean

modules :
	@echo "$(MODULES_INFO)"

clean :
	rm -rf obj bin

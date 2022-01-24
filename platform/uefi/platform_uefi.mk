ifneq ($(shell echo $(shell uname -r) | awk -F '-' '{ print $$3 }'),MANJARO)
LD_FLAGS +=  -nostdinc -nostdinc++ -nostdlib
endif

LD := x86_64-w64-mingw32-ld
LD_FLAGS := -e tugui_bootmain 


UEFI_APP_LD_FLAGS := -subsystem=10

# compilers & app
CXX := x86_64-w64-mingw32-g++ 

# flag
# -ffreestanding : __main
CXX_FLAGS := -Wall -Wextra \
             -fno-builtin  \
             -nostdinc -nostdlib \
             -fno-rtti \
             -fno-exceptions

UEFI_APP_CXX_FLAGS := -Wl,--subsystem,10

UEFIWRAPPER_LIB_INC := libs/UEFIWrapper \
                       $(addprefix platform/uefi/UEFIWrapper/,$(UEFIWRAPPER_LIB_INC))

BOOTMAIN_OBJS := $(addsuffix .o,$(BOOTMAIN))
BOOTMAIN_OBJS := $(addprefix $(OBJ_DIR)/,$(BOOTMAIN_OBJS))

UEFI_PREDEF_MACRO := NO_DEFAULT_STDLIB
UEFI_PREDEF_MACRO = $(addprefix -D,$(UEFI_PREDEF_MACRO))

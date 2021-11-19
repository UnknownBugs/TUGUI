BOOTMAIN := uefi_bootmain
PLATFORM_INC_DIR := platform/uefi \
                    platform/uefi/wrapper

BOOTMAIN_OBJS := $(addsuffix .o,$(BOOTMAIN))
BOOTMAIN_OBJS := $(addprefix $(OBJ_DIR)/,$(BOOTMAIN_OBJS))

export BOOTMAIN_OBJS
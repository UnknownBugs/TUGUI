BOOTMAIN := uefi_bootmain

BOOTMAIN_OBJS := $(addsuffix .o,$(BOOTMAIN))
BOOTMAIN_OBJS := $(addprefix $(OBJ_DIR)/,$(BOOTMAIN_OBJS))

export BOOTMAIN_OBJS
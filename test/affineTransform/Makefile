MODULE := affineTransform

ifeq ($(modules),scale)

include scale.mk

else ifeq ($(modules),translation)

include translation.mk

else ifeq ($(modules),rotation)

include translation.mk

else

all : $(BIN_DIR)/scale $(BIN_DIR)/translation $(BIN_DIR)/rotation

include scale.mk
include translation.mk
include rotation.mk

endif

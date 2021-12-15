all : $(BIN_DIR)/$(modules)Line $(BIN_DIR)/$(modules)Circle $(BIN_DIR)/$(modules)Rectangle

include line.mk
include circle.mk
include rectangle.mk

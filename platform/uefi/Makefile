SRCS := uefi_bootmain.cpp

INCS := uefi_base_interface_impl.hpp

LOCAL_INC := $(addprefix -I,$(INC_DIR))

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

$(OBJS): $(SRCS) $(INCS)
	@echo + $@
	$(CXX) -c $(SRCS) $(CXX_FLAGS) -o $@ $(LOCAL_INC)

module := uefi_bootmain
debug	            := test/debug

ALL_MODULES := $(debug) \

MODULES_LIST := moduels: \
                debug \

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

debug	            := test/debug
gradient            := test/gradient

ALL_MODULES := $(debug) \
               $(gradient)

MODULES_LIST := moduels: \
                debug \
                gradient

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

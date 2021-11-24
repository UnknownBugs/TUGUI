basef           := test/base
coordinate_line	:= test/coordinate_line
straight_line   := test/straight_line
circle          := test/circle
rectangle       := test/rectangle

MODULES_LIST := moduels: \
                base \
                coordinate_line \
                straight_line \
                circle \
                rectangle

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

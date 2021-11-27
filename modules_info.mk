base            := test/base
coordinate_line	:= test/coordinate_line
straight_line   := test/straight_line
circle          := test/circle
rectangle       := test/rectangle
triangle        := test/triangle
keyboard        := test/keyboard

ALL_MODULES := $(base) \
               $(coordinate_line) \
               $(straight_line) \
               $(circle) \
               $(rectangle) \
               $(triangle) \
               $(keyboard)


MODULES_LIST := moduels: \
                base \
                coordinate_line \
                straight_line \
                circle \
                rectangle \
                triangle \
                keyboard

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

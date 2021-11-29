base            := test/base
coordinate_line	:= test/coordinate_line
straight_line   := test/straight_line
circle          := test/circle
rectangle       := test/rectangle
triangle        := test/triangle
keyboard        := test/keyboard
keyevent        := test/keyevent

ALL_MODULES := $(base) \
               $(coordinate_line) \
               $(straight_line) \
               $(circle) \
               $(rectangle) \
               $(triangle) \
               $(keyboard) \
               $(keyevent)


MODULES_LIST := moduels: \
                base \
                coordinate_line \
                straight_line \
                circle \
                rectangle \
                triangle \
                keyboard

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

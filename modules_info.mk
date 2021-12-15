<<<<<<< HEAD
base                := test/base
point	            := test/point
coordinate_line	    := test/coordinate_line
straight_line       := test/straight_line
circle              := test/circle
rectangle           := test/rectangle
triangle            := test/triangle
echo-wait           := test/echo-wait
registerKeyNotify   := test/registerKeyNotify
timer_wait          := test/timer_wait
timer_sync          := test/timer_sync
displayPicture      := test/displayPicture
=======
debug	            := test/debug
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79

ALL_MODULES := $(debug) \

MODULES_LIST := moduels: \
                debug \

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

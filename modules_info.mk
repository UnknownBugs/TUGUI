base                := test/base
coordinate_line	    := test/coordinate_line
straight_line       := test/straight_line
circle              := test/circle
rectangle           := test/rectangle
triangle            := test/triangle
echo-wait           := test/echo-wait
registerKeyNotify   := test/registerKeyNotify
timer_wait          := test/timer_wait
timer_sync          := test/timer_sync
displayPicture		:= test/displayPicture
ALL_MODULES := $(base) \
               $(coordinate_line) \
               $(straight_line) \
               $(circle) \
               $(rectangle) \
               $(triangle) \
               $(echo-wait) \
               $(registerKeyNotify) \
               $(timer_wait) \
               $(timer_sync) \
			   $(displayPicture)

MODULES_LIST := moduels: \
                base \
                coordinate_line \
                straight_line \
                circle \
                rectangle \
                triangle \
                echo-wait \
                registerKeyNotify \
                timer_wait \
                timer_sync

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

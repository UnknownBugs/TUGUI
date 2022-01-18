debug	            := test/debug
base                := test/base
gradient            := test/gradient
graphics            := test/graphics
rasterizer          := test/rasterizer
transformation      := test/transformation
transparency        := test/transparency

ALL_MODULES := $(debug) \
               $(base) \
               $(gradient) \
               $(graphics) \
               $(rasterizer) \
               $(transformation) \
               $(transparency)

MODULES_LIST := moduels: \
                debug \
                base \
                gradient \
                graphics \
                rasterizer \
                transformation \
                transparency

MODULES_INFO := $(addsuffix \n,$(MODULES_LIST))

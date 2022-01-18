# * @Author: SPeak Shen 
# * @Date: 2020-03-19 21:17:34 

# from .c .S .cpp to .o [src_file -> objfile]
# $(1) src file
# $(2) type
# $(3) dir(out path)
define srcToXXFile
	$(addprefix $(3)/,\
		$(addsuffix $(2),\
			$(basename $(1))\
		)\
	)
endef


# from .c .S .cpp to .o [src_file -> objfile]
# $(1) src file
# $(2) dir(out path)
srcToObjFile = $(call srcToXXFile,$(1),.o,$(2))
objToBinFile = $(call srcToXXFile,$(1),,$(2))


## batch compiler by gcc
#	$(1): compiler tools
#	$(2): src file
#	$(3): flag
#   $(4): dir
#   $(5): ConvertFunc
define batchCompiler
	$(foreach f,$(2),\
		$(shell $(1) -c $(f) $(3) -o \ 
			$(call $(5), $(f), $(4))\
		)\
	)
endef

## batch compiler by gcc
#	$(1): compiler tools
#	$(2): src file
#	$(3): flag
#   $(4): dir
#   $(5): ConvertFunc
define batchCompilerCmds
	$(foreach f,$(2),\
		"$(1) $(f) $(3) -o $(call $(5), $(notdir $(f)), $(4))"\
	)
endef
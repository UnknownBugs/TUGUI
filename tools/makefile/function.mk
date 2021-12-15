# * @Author: SPeak Shen 
# * @Date: 2020-03-19 21:17:34 

# from .c .S .cpp to .o [src_file -> objfile]
define srcToObjFile
	$(addprefix obj/,\
		$(addsuffix .o,\
			$(basename $(1))\
		)\
	)
endef

##create dir of file
#	$(1) list of obj file
define createTargetDir
	$(shell mkdir -p $(dir $(1)))
endef

## batch compiler by gcc
#	$(1): list of src file
#	$(2): Include
#	$(3): flag
define batchCompiler
	$(foreach f,$(2),\
		$(shell $(1) -o $(call srcToObjFile,$(f)) $(3) $(4) -c $(f))\
	)
endef

# exe shell script (script,args1,arg2....)
exeShellScript = sh tools/shell/$(1) $(2) $(3) $(4)

toTargetFile = $(addprefix obj/,$(1)$(2).o)

# get filelist of multi-dir
# 
getFileList = $(foreach d,$(2),$(shell find $(d) -name *$(1)))


cgtype = $(patsubst %.$(2),%.$(3),$(1))
objfile = $(call toobj,$(1))
outfile = $(call cgtype,$(call toobj,$(1)),o,out)
filename = $(basename $(notdir $(1)))

read_packet = $(foreach p,$(call packetname,$(1)),$($(p)))

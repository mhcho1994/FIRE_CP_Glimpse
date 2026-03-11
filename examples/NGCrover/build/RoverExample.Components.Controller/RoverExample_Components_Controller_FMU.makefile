# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f 378.fmutmp/sources/RoverExample_Components_Controller_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* 378.fmutmp/sources
	cp -a RoverExample_Components_Controller_FMU.libs 378.fmutmp/sources/


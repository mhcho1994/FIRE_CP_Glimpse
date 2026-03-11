# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f 504.fmutmp/sources/RoverExample_Components_Webserver_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* 504.fmutmp/sources
	cp -a RoverExample_Components_Webserver_FMU.libs 504.fmutmp/sources/


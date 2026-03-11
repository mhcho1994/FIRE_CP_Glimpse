# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f 654.fmutmp/sources/GSQuad_Components_MissionPlanner_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* 654.fmutmp/sources
	cp -a GSQuad_Components_MissionPlanner_FMU.libs 654.fmutmp/sources/


/* External objects file */
#include "GSQuad.Components.Joystick_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GSQuad_Components_Joystick_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define GSQuad_Components_MissionPlanner_INDEX_JAC_H 0
int GSQuad_Components_MissionPlanner_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_MissionPlanner_INDEX_JAC_F 1
int GSQuad_Components_MissionPlanner_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_MissionPlanner_INDEX_JAC_D 2
int GSQuad_Components_MissionPlanner_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_MissionPlanner_INDEX_JAC_C 3
int GSQuad_Components_MissionPlanner_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_MissionPlanner_INDEX_JAC_B 4
int GSQuad_Components_MissionPlanner_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_MissionPlanner_INDEX_JAC_A 5
int GSQuad_Components_MissionPlanner_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_MissionPlanner_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

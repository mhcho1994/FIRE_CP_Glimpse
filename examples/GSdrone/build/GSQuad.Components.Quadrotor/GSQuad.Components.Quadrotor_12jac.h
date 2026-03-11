/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define GSQuad_Components_Quadrotor_INDEX_JAC_H 0
int GSQuad_Components_Quadrotor_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_Quadrotor_INDEX_JAC_F 1
int GSQuad_Components_Quadrotor_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_Quadrotor_INDEX_JAC_D 2
int GSQuad_Components_Quadrotor_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_Quadrotor_INDEX_JAC_C 3
int GSQuad_Components_Quadrotor_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_Quadrotor_INDEX_JAC_B 4
int GSQuad_Components_Quadrotor_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define GSQuad_Components_Quadrotor_INDEX_JAC_A 5
int GSQuad_Components_Quadrotor_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int GSQuad_Components_Quadrotor_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

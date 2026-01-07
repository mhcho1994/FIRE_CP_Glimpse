/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define RoverExample_Components_Rover_INDEX_JAC_LSJac1 0
int RoverExample_Components_Rover_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac3 1
int RoverExample_Components_Rover_functionJacLSJac3_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac3(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_H 2
int RoverExample_Components_Rover_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_F 3
int RoverExample_Components_Rover_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_D 4
int RoverExample_Components_Rover_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_C 7
int RoverExample_Components_Rover_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_B 10
int RoverExample_Components_Rover_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_A 13
int RoverExample_Components_Rover_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac10 5
int RoverExample_Components_Rover_functionJacLSJac10_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac10(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac11 6
int RoverExample_Components_Rover_functionJacLSJac11_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac11(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac8 8
int RoverExample_Components_Rover_functionJacLSJac8_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac8(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac9 9
int RoverExample_Components_Rover_functionJacLSJac9_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac9(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac6 11
int RoverExample_Components_Rover_functionJacLSJac6_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac6(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac7 12
int RoverExample_Components_Rover_functionJacLSJac7_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac7(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac4 14
int RoverExample_Components_Rover_functionJacLSJac4_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac4(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Rover_INDEX_JAC_LSJac5 15
int RoverExample_Components_Rover_functionJacLSJac5_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Rover_initialAnalyticJacobianLSJac5(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif


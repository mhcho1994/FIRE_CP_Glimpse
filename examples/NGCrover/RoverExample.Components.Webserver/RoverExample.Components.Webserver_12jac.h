/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define RoverExample_Components_Webserver_INDEX_JAC_H 0
int RoverExample_Components_Webserver_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Webserver_INDEX_JAC_F 1
int RoverExample_Components_Webserver_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Webserver_INDEX_JAC_D 2
int RoverExample_Components_Webserver_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Webserver_INDEX_JAC_C 3
int RoverExample_Components_Webserver_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Webserver_INDEX_JAC_B 4
int RoverExample_Components_Webserver_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define RoverExample_Components_Webserver_INDEX_JAC_A 5
int RoverExample_Components_Webserver_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int RoverExample_Components_Webserver_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif


#include <stdio.h>
#include "f.c"

int main(void) {
    double x_in = 2.0;
    double result;

    // CasADi expects pointers-to-pointers for inputs and outputs
    const double* arg[1] = { &x_in };
    double* res[1] = { &result };

    int iw[1];      // integer workspace (not used in this simple case)
    double w[1];    // real workspace (not used)
    int mem = 0;

    // Call generated function
    f(arg, res, iw, w, mem);

    printf("f(%f) = %f\n", x_in, result);
    return 0;
}

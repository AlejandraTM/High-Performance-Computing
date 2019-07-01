// gslIntegrate.cpp

#include "gslIntegrate.h"


int main(void) {
 //Integration limits declaration and other variables declaration
 double lim_inf = 0.0;
 double lim_sup = 5.0;
 double result, error;
 //Parameters definition
 struct Params args = {0.3, 2/3.0, 2.0, 1/1.3, 1/30.0};
 //Workspace creation
 gsl_integration_workspace* w= gsl_integration_workspace_alloc (1000);
 //Function definition in the main
 gsl_function f; 
 //Espacio en memoria de la function
 f.function = &examplefunction;
 //Espacio en memoria de los params of the function
 f.params = &args;
 //Integration method implementation
 gsl_integration_qag(&f,lim_inf,lim_sup,1e-7,1000.0,10,6,w,&result,&error); 
 //Print results
 printf ("Result          = % .18f\n", result);
 printf ("Estimated error = % .18f\n", error);
 printf ("Intervals       = %zu\n", w->size);
 gsl_integration_workspace_free(w);
 return 0;
 
}
// Complilation
/*
First: g++ gslfunctions.o  gslIntegrate.cpp -o root -lgsl -lgslcblas -lm

Second: g++ gslfunctions.o  gslIntegrate.cpp -o root -lgsl -lgslcblas -lm

Third: ./root

Results: 
Result          =  8.317880097928300742
Estimated error =  0.000000000000092347
Intervals       = 1

*/



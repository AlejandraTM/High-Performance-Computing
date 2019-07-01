// V2.cpp
/*This code has to be ran with a script1.sh, or you have to give two parameters 0.64 and 0.68, for example. Those are the parameters of the interval in which the program has to look for a root*/
#include <iostream> 
#include <gsl/gsl_roots.h>

	//Parameters of the examplefunction
struct Params {
 double a;
};
	//The function with miltiple roots
double examplefunction(double x, void* param){
 Params* p = (Params*)param;
 return x*cos(-p->a+x*x*x);
}

	//Main function with arguments
int main(int arg, char *args2[]) {
	//limits definition by arguments in args2
 double x_lo = std::stod(args2[1]);
 double x_hi = std::stod(args2[2]);
	//Roots Calculation
 Params args = {5.0}; 
 gsl_root_fsolver* solver;
 gsl_function      fwrapper;
 solver = gsl_root_fsolver_alloc(
              gsl_root_fsolver_brent);
 fwrapper.function = examplefunction;
 fwrapper.params = &args;
 gsl_root_fsolver_set(solver,&fwrapper,x_lo,x_hi);
 
 int status = 1;
 double raiz=0.0;
 for (int iter=0; status and iter < 10; ++iter) 
   {
 
   gsl_root_fsolver_iterate(solver);
   
   double x_rt = gsl_root_fsolver_root(solver);
   double x_lo = gsl_root_fsolver_x_lower(solver);
   double x_hi = gsl_root_fsolver_x_upper(solver);
   raiz=x_rt;
   status=gsl_root_test_interval(x_lo,x_hi,0,1e-6);
   }
	//Results
 std::cout<<"Root for ("<<std::stod(args2[1])<<","<<std::stod(args2[2])<<") is "<<raiz<<"\n";

 gsl_root_fsolver_free(solver);
 
 return status;
 
}

/*How to runt it in Fedora Linux distribution:
	1. chmod +x script1.sh
	2. ./script1.sh
*/


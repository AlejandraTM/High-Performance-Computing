// V1.cpp

/*Whit this code we will get all root os the function from 0 to 5*/
#include <iostream> 
#include <gsl/gsl_roots.h>

//Parameters definition and functions
struct Params {
 double a;
};

double examplefunction(double x, void* param){
 Params* p = (Params*)param;
 return x*cos(-p->a+x*x*x);
}

	/*This function calculates the roots in an interval from x_lo to x_hi using the GSL library*/
double roots(double x_lo, double x_hi){
 double raiz=0.0;
 Params args = {5.0};
 gsl_root_fsolver* solver;
 gsl_function      fwrapper;
 solver = gsl_root_fsolver_alloc(gsl_root_fsolver_brent);
 fwrapper.function = examplefunction;
 fwrapper.params = &args;
 gsl_root_fsolver_set(solver,&fwrapper,x_lo,x_hi);
 int status = 1;
 
 for (int iter=0; status and iter < 10; ++iter) 
   {
 
   gsl_root_fsolver_iterate(solver);
   
   double x_rt = gsl_root_fsolver_root(solver);
   double x_lo = gsl_root_fsolver_x_lower(solver);
   double x_hi = gsl_root_fsolver_x_upper(solver);
   raiz=x_rt;
   status=gsl_root_test_interval(x_lo,x_hi,0,1e-6);
   }
   
 gsl_root_fsolver_free(solver);
 return raiz;
}

int main() {

 double x_lo;
 double x_hi;
 Params args = {5.0};
	/*In this part I defined a loop which starts at 0 and finishes at 5 with a step size of 0.04. In the conditional, it asks about if there is a change of sing in the sub interval, so if the answer is true the function roots will be called*/
 for(double j=0.04;j<5.0;j=j+0.04){
  if((examplefunction(j-0.04,&args)*examplefunction(j,&args))<0.0){
   x_lo=j-0.04;
   x_hi=j;
   std::cout<<"Interval ("<<x_lo<<","<<x_hi<<")"<<" & root= "<<roots(x_lo,x_hi)<<"\n";
  }
 }
 return 0;
 
}


/* How to run the code in Fedora:
g++ V1.cpp -o V1 -lgsl -lgslcblas -lm
./V1
*/




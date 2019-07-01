//Header
//gslIntegrate.h
#include <stdio.h>
#include <iostream> 
#include <gsl/gsl_integration.h>


//Struct parameters declaration
struct Params{
 double a,v,w,b,c;
};
//Definition function declaration
double examplefunction(double x, void* param);


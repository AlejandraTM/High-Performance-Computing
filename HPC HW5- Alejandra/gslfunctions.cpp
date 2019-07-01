#include "gslIntegrate.h"

double examplefunction(double x, void* param)//Definition of the function with parametres
{
 Params* p = (Params*)param;
 return p->a*sin(cos(p->v-p->w*x))+p->b*x-p->c*x*x;
}

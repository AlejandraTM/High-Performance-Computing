#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

double x, y, alpha, beta, a, b, aux;
int iterations;
ofstream archivo;

double random(double& x,double& y,double a,double b,double alpha,double beta,int iteration)
{
	archivo.open("randomPart2.txt",ios::out);
	if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo."<<"\n";
		exit(1);
	}	
	aux=0.0;
	for(int i=1; i<=iterations;i++)
	{
		aux=a-alpha*pow(x,2)+b*y;
		y=beta*x;
		x=aux;
		archivo<<x<<";"<<y<<"\n";
	}
	archivo.close();
}

int main()
{
	x=0.0;y=0.0;alpha=beta=1.0;a=1.4;b=0.3;iterations=100000.0;
	random(x,y,a,b,alpha,beta,iterations);
	return 0;
}



 

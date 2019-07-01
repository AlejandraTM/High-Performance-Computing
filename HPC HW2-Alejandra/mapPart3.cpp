#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

double x, y, alpha, beta, a, b, aux,h,medida,R,auxc;
int iterations;
ofstream archivo;

double random(double& x,double& y,double a,double b,double alpha,double beta,int iteration,double R)
{	
	aux=0.0;
	medida=sqrt(pow(x,2)+pow(y,2));
	for(int i=1; i<=iterations & medida<R;i++)
	{
		aux=a-alpha*pow(x,2)+b*y;
		y=beta*x;
		x=aux;
		medida=sqrt(pow(x,2)+pow(y,2));
		auxc=i;
	}
	cout<<auxc<<"\n";
	if(auxc<iterations)
	{
		return medida;
	}else
	{
		return R;
	}

}

int main()
{
	archivo.open("randomPart32.txt",ios::out);
	alpha=0.2;beta=1.01;a=b=1.0;iterations=1000.0;h=0.1;R=1000;
		if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo."<<"\n";
		exit(1);
	}
	for(double l=0.0+h;l<4.0;l=l+h)
	{	
		for(double k=-4.0+h;k<0.0;k=k+h)
		{	
			x=l;y=k;
			auxc=random(x,y,a,b,alpha,beta,iterations,R);
			archivo<<auxc<<" ";	
		}
		archivo<<"\n";
	}
	archivo.close();
	return 0;
}



 

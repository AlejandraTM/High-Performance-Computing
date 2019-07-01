#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
double n, sum, product,timeSum,timeProc;
unsigned t0,t1,t2,t3;
//Suma primeros n numeros
double suma(int n)
{
	double a;
	a=0.0;
	for(int i=1; i<=n; i++)
	{
		a=a+i;
	}
	return a;
}
//Producto de los n primeros numeros
double producto(int n)
{
	double a;
	a=0.0;
	for(int i=1; i<=n; i++)
	{
		a=a*i;
	}
	return a;
}

int main()
{
	n=500000000;
	t0=clock();//tiempo antes de la suma
	sum=suma(n);//suma
	t1=clock();//tiempo despues de la suma
	t2=clock();//tiempo antes del producto
	product=producto(n);//producto
	t3=clock();//tiempo despues del producto
	timeSum=(double(t1-t0)/CLOCKS_PER_SEC);//Conversion del tiempo de ticks a segundos para la suma
	timeProc=(double(t3-t2)/CLOCKS_PER_SEC);//Conversion del tiempo de ticks a segundos para el producto
	//resultados
	cout<<"Tiempo suma: "<<timeSum<<"\n";
	cout<<"Tiempo producto: "<<timeProc<<"\n";
	return 0;
}

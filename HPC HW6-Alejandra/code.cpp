/*code.cpp --It solve the Travelling salesman problem using Simulated Annealing strategy with aleatory initial parameters. 
	   --You can run it using linux distribution in the following way: g++ code.cpp -o code
									   ./code
 	   --You can rut it from a python program using codepython.py in the following way: python codepython.py*/
#include <iostream>
#include <random>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
	//INITIALIZATION
	int numcities;//Number of cities
	numcities=15.0;
	double city[2][numcities],distance=0.0;
	for(int i=0;i<numcities;i++)//Cities coordinates on a 100x100 grid
	{
		city[0][i]=rand()%100;
		city[1][i]=rand()%100;
	}
	int tour[numcities];
	for(int i=0;i<numcities;i++)//Initial path
	{
		tour[i]=rand()%15;
	}
	//Print inicial path
	cout<<"Inicial Path: "<<"\n";
	for(int i=0;i<numcities;i++)
	{
		cout<<tour[i]<<" ";
	}
	cout<<"\n";
	int Ntour[numcities],x,y;
	for(int i=0;i<numcities;i++)//Initial new path. It will be start as tour then It will be changed
	{
		Ntour[i]=tour[i];
	}

	//SOLUCTION WITH SIMULATED ANNEALING STRATEGY
	for(double i=100000.0;i>1.0;i=i-0.003)
	{
		do{y=rand()%15;x=rand()%15;}while(y < x);//Aleatory initial cities in the tour
		//First aleatory change of cities
		int m=Ntour[x];
		Ntour[x]=Ntour[y];
		Ntour[y]=m;
		//Evaluetion of distances between the new tour and the last tour
		int vec[]={y,y-1,x,x-1};
		double oldDistance=0.0,suma1=0.0,NDistance=0.0,suma2=0.0;
		for(int j=0;j<4;j++)
		{	
			int k=vec[j];
			for(int d=0;d<=1;d++)
			{
				suma1=suma1+pow(city[d][tour[(k+1)%15]]-city[d][tour[k%15]],2);
				suma2=suma2+pow(city[d][Ntour[(k+1)%15]]-city[d][Ntour[k%15]],2);
			}
			NDistance=NDistance+sqrt(suma2);
			oldDistance=oldDistance+sqrt(suma1);
			suma1=0.0;suma2=0.0;
		}
		//Condition of better distance and new tour asignation
		if(((NDistance-oldDistance)/i)>((rand()%1000)/1000.0))
		{
			for(int j=0;j<numcities;j++)
			{
				tour[j]=Ntour[j];
			}
		}
	distance=NDistance;
	}
	
	//Print last path and the shortest distance
	cout<<"Final Path: "<<"\n";
	for(int i=0;i<numcities;i++)
	{
		cout<<Ntour[i]<<" ";
	}
	cout<<"\n";
	cout<<"Short Path: "<<distance<<"\n";
}

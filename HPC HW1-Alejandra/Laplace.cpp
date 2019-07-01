#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

double u,r,limx1,limx2,limy1,limy2,iter,h,initpx1,initpx2;
int a,b,c,d;


int main()
{
	limx1=-1.0;limx2=1.0;limy1=-1.0;limy2=1.0;h=0.1;initpx1=0.5;initpx2=-0.5;
	a=(int)((limx2-limx1)/h);
	b=(int)((limy2-limy1)/h);
	cout<<b<<"\n";
	c=(int)(initpx1/h);
	d=(int)(initpx2/h);
	int M=new int[a][20];
	for(int i; i<=a; i++)
	{
		for(int j; j<=20; j++)
		{
			if(i==0|j==0)
			{
				M[i][j]=-1.0;
			}else{
				M[i][j]=0.1;
			}
		}
	}
	M[(int)(a/2.0)+c][0]=0.0;
	M[(int)(a/2.0)+d][0]=-1.0;
	cout<<M<<"\n";
	
}

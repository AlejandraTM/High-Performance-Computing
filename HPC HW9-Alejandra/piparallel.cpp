#include <math.h>
#include <iostream>
#include <omp.h>

double Pi=2.0*asin(1.0);

double function(double x)//Function
{
	double f;
	f=pow(1-pow(x,2.0),0.5);
	return f;
}

int main(int args, char *args2[])
{
	double a, b,h;
	double firstTerm,secondTerm,solution,error;
	//inicialization of variables
	a=0.0;
	b=1.0;
	int n=std::stod(args2[1]);
	h=(b-a)/n;
	//Leading term of the aproximation
	firstTerm=(h/2.0)*(function(a)+function(b));
	secondTerm=0.0;
	//Second term of the method
	int i;
	#pragma omp parallel for default(none) private(i) shared(a,h,n,secondTerm)
	for(i=1;i<n;i++)
	{
		#pragma omp critical
		secondTerm=secondTerm+function((a+i*h));
	}
	//Solution and error
	solution=firstTerm+(h*secondTerm);
	error=Pi-4*solution;
	std::cout<<"Solution: "<<4*solution<<'\n';
	std::cout<<"Error: "<<error<<'\n';
}

/*How to runt it in Fedora Linux distribution?
	1. g++ -o0 piparallel.cpp -o paralel -fopenmp
	2. export OMP_NUM_THREADS=2
	3. ./paralel 1000000


Solution: threads 2
	Solution: 3.14159
	Error: 1.17595e-09

	real	0m0.174s
	user	0m0.281s
	sys	0m0.003s

	 threads 1
	Solution: 3.14159
	Error: 1.17582e-09

	real	0m0.152s
	user	0m0.149s
	sys	0m0.003s

*/

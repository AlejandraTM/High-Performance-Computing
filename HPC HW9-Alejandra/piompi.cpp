#include <math.h>
#include <iostream>
#include <mpi.h>

double Pi=2.0*asin(1.0);

double function(double x)//Function
{
	double f;
	f=pow(1-pow(x,2.0),0.5);
	return f;
}

int main(int argc, char *argv[])
{
	double a, b,h,tiempoi, tiempof;
	double firstTerm,secondTerm,solution,error,aux;
	//inicialization of variables
	a=0.0;
	b=1.0;
	int n=std::stod(argv[1]);
	h=(b-a)/n;
	//Leading term of the aproximation
	firstTerm=(h/2.0)*(function(a)+function(b));
	secondTerm=0.0;
	//Second term of the method
	int rank, size;
	MPI_Init(&argc,&argv);//MPI implementation
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Barrier(MPI_COMM_WORLD);
	tiempoi=MPI_Wtime();
	int i;
	for(i=1;i<n;i++)
	{
		aux=function((a+i*h));
		secondTerm=secondTerm+aux;
	}
	//Solution and error
	solution=firstTerm+(h*secondTerm);
	error=Pi-4*solution;
	MPI_Allreduce(&aux,&secondTerm,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	tiempof=MPI_Wtime();
	if(rank==0)
	{
		std::cout<<"Solution: "<<4*solution<<'\n';
		std::cout<<"Error: "<<error<<'\n';
		std::cout<<"Time: "<<tiempof-tiempoi<<'\n';
	}
	MPI_Finalize();
}

/*How to runt it in Fedora Linux distribution?
	1. mpicxx piompi.cpp -o ompi
	2. mpiexec -np 2 ./ompi 1000000

_______	MPI solution
	2 CPUs
	Solution: 3.14159
	Error: 1.17582e-09
	Time: 0.116287
	
	1 CPU
	Solution: 3.14159
	Error: 1.17582e-09
	Time: 0.109772

________Serial Solution
	SolutionPI: 3.14159 
        Error:1.17582e-09
	Time: 0m0.124s	     
	     
*/

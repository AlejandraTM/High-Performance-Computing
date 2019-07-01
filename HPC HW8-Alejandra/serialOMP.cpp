#include <cmath>
#include <iostream>
#include <omp.h>

const double pi = 3.14159265358979323846264338327950288;

int main(int args, char *args2[])
{
    // robots walk on a table.
    int table_size = 600;
    int time_steps = 1000;
    double number_of_robots[table_size][table_size];
    double new_number_of_robots[table_size][table_size];
    float crawl_direction[table_size][table_size];
    int total_robots = 10000; // initial number of robots.

    // initialize a direction field.
	int i,j;
   	#pragma omp parallel for default(none) private(i,j) shared(table_size,crawl_direction)
    for (i=0;i<table_size;i++) {
        for (j=0;j<table_size;j++) {
            crawl_direction[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
	/*
    for (i=0;i<table_size;i++) {
        for (j=0;j<table_size;j++) {
            std::cout<<crawl_direction[i][j]<<" ";
        }
		std::cout<<std::endl;
    }*/
    // "randomly" place robots on the table.
	#pragma omp parallel for default(none) private(i,j) shared(table_size,number_of_robots)
    for ( i=0;i<table_size;i++) {
        for ( j=0;j<table_size;j++) {
            number_of_robots[i][j] = 0.0;
        }
    }
    int n = 0;
    srand(std::stod(args2[1]));
    while (n < total_robots) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_robots[i][j] ++;
        n ++;
    }
	// count robots.
    total_robots = 0.0;
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            total_robots += number_of_robots[i][j];
        }
    }
    // report.
    std::cout << 0 << " " << total_robots << std::endl;

	// run time steps. Robots Movement.
    for (int t = 0; t < time_steps; t++) 
	{
        // robots move. Inicialization the auxiliar matrix of movements.
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                new_number_of_robots[i][j] = 0.0;
            }
        }
		//Cicle move. 
		int di,dj,j2,i2;
        for (i=0;i<table_size;i++) {
			#pragma omp parallel for default(none) private(di,dj,j2,i2,i,j) shared(table_size,crawl_direction,number_of_robots,new_number_of_robots)
            for (j=0;j<table_size;j++) {
                di = 1.9*sin(crawl_direction[i][j]);
                dj = 1.9*cos(crawl_direction[i][j]);
                i2 = i + di;
                j2 = j + dj;
                // put only new table if not off table. 
                if (i2>=0 and i2<table_size and j2>=0 and j2<table_size) {
		    	//In this line the robot in the position (i,j) will be moved to the position (i2,j2) given by the sine or cosine in the   	Crawl_direction matrix.
					#pragma omp critical
                    new_number_of_robots[i2][j2] += number_of_robots[i][j];
                } 
            }
        }
        // update
        total_robots = 0.0;
		#pragma omp parallel for default(none) private(i,j) shared(table_size,number_of_robots,new_number_of_robots)
        for (i=0;i<table_size;i++) {
            for (j=0;j<table_size;j++) {
                number_of_robots[i][j] = new_number_of_robots[i][j];
            }
        }        
        // count robots
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                total_robots += number_of_robots[i][j];
            }
        }
        // report
		if(total_robots==0.0)
		{
			std::cout << t+1 << " " << total_robots << std::endl;
			t=time_steps;
		}
    }

	return 0;
} 


/*How to runt it in Fedora Linux distribution?
	$ g++ -o0 serialOMP.cpp -o serialOMP -fopenmp
	$ export OMP_NUM_THREADS=4
	$ ./serialOMP 13

with the time is: $ time ./serialOMP 13
	wihtout parallel OMP 
							real	0m22.003s
							user	0m21.917s
							sys	0m0.011s
	with parallel OMP
							real	0m6.825s
							user	0m25.325s
							sys	0m0.149s
----------------------------------------------
If you what to compare with 4,3,2 or 1 threat you can run the scriptOMP.sh in the next way:
	$ chmod +x scriptOMP.sh	
	$ ./scriptOMP.sh

and get a similar next results:


threats Parallel_time Threat_Time   Serial_Fraction
4         0m7.461s      1.86525    0.7467757263100734
3         0m6.151s      2.05033    0.7815230517866023
2         0m5.362s      2.681      0.8040562762653023
1         0m8.334s      8.334      0.725285954445067

*/


        

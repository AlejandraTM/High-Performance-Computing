#include <cmath>
#include <iostream>

const double pi = 3.14159265358979323846264338327950288;

int main(int args, char *args2[])
{
    // robots walk on a table
    int table_size = 600;
    int time_steps = 1000;
    double number_of_robots[table_size][table_size];
    double new_number_of_robots[table_size][table_size];
    float crawl_direction[table_size][table_size];
    int total_robots = 10000; // initial number of robots
    // initialize a direction field; where do the robots go at each point?
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            crawl_direction[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    // "randomly" place robots on the table
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
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
    // count robots
    total_robots = 0.0;
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            total_robots += number_of_robots[i][j];
        }
    }
    // report
    std::cout << 0 << " " << total_robots << std::endl;
    // run time steps. Robots Movement.
    for (int t = 0; t < time_steps; t++) {
        // robots move. Inicialization the auxiliar matrix of movements.
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                new_number_of_robots[i][j] = 0.0;
            }
        }
	//Cicle move. 
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                int di = 1.9*sin(crawl_direction[i][j]);
                int dj = 1.9*cos(crawl_direction[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                // put only new table if not off table. 
                if (i2>=0 and i2<table_size and j2>=0 and j2<table_size) {
		    //In this line the robot in the position (i,j) will be moved to the position (i2,j2) given by the sine or cosine in the   	Crawl_direction matrix.
                    new_number_of_robots[i2][j2] += number_of_robots[i][j];
                } 
            }
        }
        // update
        total_robots = 0.0;
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
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
	1. chmod +x script.sh
	2. ./script.sh  
*/


        

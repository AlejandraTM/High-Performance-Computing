#!/bin/bash

g++ -o0 serialOMP.cpp -o serialOMP -fopenmp
export OMP_NUM_THREADS=4
echo "threats 4:"; time ./serialOMP 13
wait
export OMP_NUM_THREADS=3
echo "threats 3:"; time ./serialOMP 13
wait
export OMP_NUM_THREADS=2
echo "threats 2:"; time ./serialOMP 13
wait
export OMP_NUM_THREADS=1
echo "threats 1:"; time ./serialOMP 13


##This script is for a Linux OS.

#!/bin/bash

g++ V2.cpp -o V2 -lgsl -lgslcblas -lm 

parallel -j 2 <<EOF
./V2 0.64 0.68; echo "job 1 done"
./V2 3.16 3.2; echo "job 2 done"
./V2 4.04 4.08; echo "job 3 done"
./V2 4.92 4.96; echo "job 4 done"
EOF

##This script is for a Linux OS.

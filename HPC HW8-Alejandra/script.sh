#!/bin/bash

g++ -o2 serial.cpp -o robots
parallel -j 4 <<EOF
./robots  10; echo "job 1 done"
./robots  1; echo "job 2 done"
./robots  3; echo "job 3 done"
./robots  4; echo "job 4 done"
EOF


##This script is for a Linux OS.

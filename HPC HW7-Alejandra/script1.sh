#!/bin/bash

g++ V2.cpp -o V2 -lgsl -lgslcblas -lm 
./V2 0.64 0.68&
./V2 4.92 4.96&

wait

##This script is for a Linux OS.

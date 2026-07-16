#!/bin/bash

# redhat-c++ is a alias for modified gcc included on RHEL
g++ main.cpp -o main.bin && ./main.bin
echo $?
rm ./main.bin

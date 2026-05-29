#!/bin/bash

redhat-c++ main.cpp -o main.bin && ./main.bin
echo $?
rm ./main.bin

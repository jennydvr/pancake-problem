#!/bin/sh

#  executor.sh
#  pancake-problem
#
#  Created by Jenny Valdez on 23/10/12.
#  Copyright (c) 2012 Jenny Valdez. All rights reserved.

#make clean
#make

temp=$1
temp="${temp%p_*}"
temp="${temp##*_}"
temp="$temp.txt"
echo $temp

#echo "AStar"
#echo "    w = 1..."
#./pancake $1 1 0 > $temp
#./promedio.sh $temp

#echo "    w = 5..."
#./pancake $1 5 0 > $temp
#./promedio.sh $temp

#echo "    w = 10..."
#./pancake $1 10 0 > $temp
#./promedio.sh $temp

echo "IDAStar"
echo "    w = 1..."
./pancakes $1 1 1 > $temp
./promedio.sh $temp

echo "    w = 5..."
./pancakes $1 5 1 > $temp
./promedio.sh $temp

echo "    w = 10..."
./pancakes $1 10 1 > $temp
./promedio.sh $temp

remove $temp

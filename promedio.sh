#!/bin/bash

#  promedio.sh
#  pancake-problem
#
#  Created by Jenny Valdez on 23/10/12.
#  Copyright (c) 2012 Jenny Valdez. All rights reserved.

sum1=0
sum2=0
sum3=0
count=0

while read line
do
    count=$(($count + 1))
    n=$(($count - 1))
    n=$(($n % 3))

    case $n in
        0) sum1=$(echo "scale=10; $sum1 + $line" | bc);;
        1) sum2=$(echo "scale=3; $sum2 + $line" | bc);;
        2) sum3=$(echo "scale=3; $sum3 + $line" | bc);;
    esac
done < $1

lines=$(($count / 3))
filename="resultados$1"
echo -e $(echo "scale=3; $sum1/$lines" | bc) >> $filename
echo -e $(echo "scale=3; $sum2/$lines" | bc) >> $filename
echo -e $(echo "scale=3; $sum3/$lines" | bc) >> $filename

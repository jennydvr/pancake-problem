#!/bin/bash

#  promedio.sh
#  pancake-problem
#
#  Created by Jenny Valdez on 23/10/12.
#  Copyright (c) 2012 Jenny Valdez. All rights reserved.

sum=`awk '{sum+=$1} END {print sum}' $1`
count=`wc -l "$1" | awk '{print $1'}`

echo -e $(echo "scale=5; $sum/$count" | bc)

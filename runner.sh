#!/bin/sh

#  runner.sh
#  pancake-problem
#
#  Created by Jenny Valdez on 23/10/12.
#  Copyright (c) 2012 Jenny Valdez. All rights reserved.

while true
do
    file=$(tail -1 "$1")

    if [ "$file" == "" ]
    then
        break
    else
        sed -i '$d' "$1"
        echo "Archivo: $file"
        ./executor.sh "$file"
    fi
done
#!/bin/sh

#  runner.sh
#  pancake-problem
#
#  Created by Jenny Valdez on 23/10/12.
#  Copyright (c) 2012 Jenny Valdez. All rights reserved.

cat "$1" | while read file
do
    echo "Archivo: $file"
    ./executor.sh "$file"
done

//
//  IDA.h
//  pancake-problem
//
//  Created by Grace Gimon on 06/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#ifndef _pancake_problem_IDA_
#define _pancake_problem_IDA_

#include <iostream>
#include "Node.h"

using namespace std;
    
// IDA* algorithm, with default weight = 1
Solution ida(Node n, int weight = 1);

#endif /* defined(__pancake_problem__IDA__) */

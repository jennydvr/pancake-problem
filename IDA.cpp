//
//  IDA.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 06/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//
#include "IDA.h"

Solution boundedDFS(Node n, int t){
	int newF = n.getG() + n.getHeuristic();
	Solution solution;
	if (newF > t){
		solution.cost = t;
		return solution;
	}
	if (n.isGoal()){
		solution.plan = extractSolution(n);
		solution.cost = n.getG();
		return solution;
	}
	
	int newT = bound;
	
	vector<Node> succesors = n.getAllSuccesors();
	for (int i = 0; i< succesors.size(); i++){
		Solution aux;
	/* In case of using non-duplicate nodes
	 * check here
	 */
		Node suc = succesors[i];
		aux = boundedDFS(suc,t);
		closed.push(suc);
		if (!aux.plan.empty())
			return aux;
		newT = min(newT, aux.cost);
	}

	return solution;
}

Solution ida(Node n, int cost){
	cost = n.getHeuristic();
	Solution solution;
	solution.cost = cost;
	while (solution.plan.empty() && cost < bound){
		solution = boundedDFS(n,cost);
		cost = solution.cost;
	}
	return solution;
}

stack<Node> extractSolution (Node n){
	
}


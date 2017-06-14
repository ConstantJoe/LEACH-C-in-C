#include <stdlib.h>
#include <stdio.h>

#define MAX_NODES 300

typedef struct Node{
	int id;
	float energy; 
	int x;
	int y;
	int CHid; //id of this node's cluster head. If id=CHid, then this node is a CH
} Node;

typedef struct NodeArch {
	int numNode;
	Node node[MAX_NODES];
} NodeArch;


int main(){
	// generate a population of nodes (w/ randomish energy - we're assuming this is at the end of an iteration)
		//also assuming all nodes are alive 
	// generate optimal k, the number of CHs

	// generate a set of CHs randomly

	// assign nodes to CHs

	// calculate energy requirements (base off of LEACH-C)

	// 

	// create a temperature variable, cooling rate (base off Java example)

	// LOOP until stop condition met:
		// select neighbour by making small change to current solution 
		// (i.e. swap out one CH for another random one, then reassign all nodes)
		// calculate energy requirements

		// decide whether to move to that solution:
			// if neighbour solution is better than current solution
				//accept it
			//	else if temperature is high enough, and neighbour solution is not too bad, accept it
			//	i.e. exp((solitionEnergy - neighbourEnergy)/temperature)

		// decrease temperature
}
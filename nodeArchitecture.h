#include "netArchitecture.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef NODEARCHITECTURE_H
#define NODEARCHITECTURE_H

#define MAX_NODES 300

typedef struct Node {
	int id;
	int x;
	int y;
	float energy;
	int clusterHead;
} Node;

typedef struct NodeArch {
	int numNode;
	Node node[MAX_NODES];
} NodeArch;

struct NodeArch* newNodes(NetArch* netA, int numNodes);

#endif /* NODEARCHITECTURE_H */


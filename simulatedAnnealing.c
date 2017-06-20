#include <stdlib.h>
#include <stdio.h>

#include "./network/netArchitecture.h"
#include "./network/nodeArchitecture.h"
#include "./network/clusterModel.h"
#include "./network/newCluster.h"
#include "./energy/dissEnergy.h"

double randZeroAndOne()
{
    return (double)rand() / (double)RAND_MAX ;
}


/*
 *	TODOs:  energy of all nodes is always .5
 *			modify "exploration" method to match the paper (current one is awful):
 				-	compute average node energy
 				-	whatever nodes have energy below this can't be CHs
 				-	maybe make it so theres a k% chance a CH will be changed? 
 */
int main(int argc, char *argv[]){
	//create an environment
	struct NetArch* netA  	 = newNetwork(0, 0, 0, 0);
	
	// generate a population of nodes (w/ randomish energy - we're assuming this is at the end of an iteration)
		//also assuming all nodes are alive 
	struct NodeArch* nodeA 	 = newNodes(netA, MAX_NODES);

	// create a struct to hold all network information
	struct ClusterModel* bestClusterM = newClusterModel(netA, nodeA);

	// generate optimal k, the number of CHs
	double dBS = sqrt(pow(bestClusterM->netA.sink.x - bestClusterM->netA.yard.height, 2) + pow(bestClusterM->netA.sink.y - bestClusterM->netA.yard.width, 2));
	bestClusterM->numCluster = clusterOptimum(&bestClusterM->netA, &bestClusterM->nodeA, dBS);

	// generate a set of CHs randomly
	chooseCHs(bestClusterM);

	// assign nodes to CHs
	assignNodes(bestClusterM);

	// calculate energy requirements (fitness function)
	float bestEnergy = totalEnergy(bestClusterM);
	float energy;
	double expVal;
	double randVal;

	// create a temperature variable, cooling rate
	float temp = 10000;
	int round = 0;
	float coolingRate = 0.003;

	struct ClusterModel* newClusterM = malloc(sizeof *newClusterM);


	// LOOP until stop condition met:
	while(temp > 1){
		round++;

		copyClusterModel(newClusterM, bestClusterM);

		// select neighbour by making small change to current solution 
		// (i.e. swap out one CH for another random one, then reassign all nodes)

		modifyaCH(newClusterM);
		// to here
		assignNodes(newClusterM);

		// calculate energy requirements
		energy = totalEnergy(newClusterM);
		float energyB = totalEnergy(bestClusterM);

		// decide whether to move to that solution:
		
		// if neighbour solution is better than current solution
		expVal = exp((bestEnergy - energy) / temp);
		randVal = randZeroAndOne();
		if(energy < bestEnergy){
			//accept it
			bestClusterM = newClusterM;
			bestEnergy = energy;
		}
		else if(expVal > randVal){
			//	else if temperature is high enough, and neighbour solution is not too bad, accept it
			bestClusterM = newClusterM;
			bestEnergy = energy;
		}
		//else keep the old solution

		printf("%d %f\r\n", round, bestEnergy);
		// decrease temperature
		temp *= 1-coolingRate;
	}
}
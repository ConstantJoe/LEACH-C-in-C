/*
 *  Implementation of Mohammad Hossein Homaei's LEACH simulator, in C.
 *  Joseph Finnegan
 *  joseph.finnegan@cs.nuim.ie
 *  2017
 */

#include "clusterModel.h"
#include <math.h>
#include <stdio.h>

#ifndef NEWCLUSTER_H
#define NEWCLUSTER_H

double clusterOptimum(NetArch* netA, NodeArch* nodeA, double dBS);

ClusterModel* newClusterModel(NetArch* netA, NodeArch* nodeA);

ClusterModel* chooseCHs(ClusterModel* clusterM);

ClusterModel* assignNodes(ClusterModel* clusterM);

ClusterModel* clearCHs(ClusterModel* clusterM);

ClusterModel* modifyaCH(ClusterModel* clusterM);

#endif /* NEWCLUSTER_H */

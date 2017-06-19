/*
 *  Implementation of Mohammad Hossein Homaei's LEACH simulator, in C.
 *  Joseph Finnegan
 *  joseph.finnegan@cs.nuim.ie
 *  2017
 */

#include "../network/clusterModel.h"
#include <math.h>
#include <stdio.h>

#ifndef DISSENERGY_H
#define DISSENERGY_H

float dissEnergyCH(ClusterModel* clusterM);
float dissEnergyNonCH(ClusterModel* clusterM);
float totalEnergy(ClusterModel* clusterM);

#endif /* DISSENERGY_H */


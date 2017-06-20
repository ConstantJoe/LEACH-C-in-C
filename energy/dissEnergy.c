/*
 *  Implementation of Mohammad Hossein Homaei's LEACH simulator, in C.
 *  Joseph Finnegan
 *  joseph.finnegan@cs.nuim.ie
 *  2017
 */

#include "dissEnergy.h"

/*
 *  Calculate energy lost by each CH during the round. 
 */
float dissEnergyCH(ClusterModel* clusterM)
{
    float energy = 0;

    double d0 = sqrt(clusterM->netA.energy.freespace / clusterM->netA.energy.multipath);

    int n = clusterM->clusterN.countCHs;

    float ETX = clusterM->netA.energy.transfer;
    float ERX = clusterM->netA.energy.receive;
    float EDA = clusterM->netA.energy.aggr;
    float Emp = clusterM->netA.energy.multipath;
    float Efs = clusterM->netA.energy.freespace;
    int packetLength = 6400;
    int ctrPacketLength = 6400;

    for(int i=0;i<n;i++)
    {
        int chNo = clusterM->clusterN.cNodes[i].no;
        double distance = clusterM->clusterN.cNodes[i].distance;

        if(distance >= d0)
        {
            energy += ((ETX+EDA) * packetLength + Emp * packetLength * pow(distance, 4));
        }
        else
        {
            energy += ((ETX+EDA) * packetLength + Efs * packetLength * pow(distance, 2));
        }
        energy += ctrPacketLength * ERX * round(clusterM->nodeA.numNode / clusterM->numCluster);
    }

    return energy;
}

/*
 *  Calculate energy lost by each non-CH during the round. 
 */
float dissEnergyNonCH(ClusterModel* clusterM)
{   
    float energy = 0; 
    
    double d0 = sqrt(clusterM->netA.energy.freespace / clusterM->netA.energy.multipath);

    float ETX = clusterM->netA.energy.transfer;
    float ERX = clusterM->netA.energy.receive;
    float EDA = clusterM->netA.energy.aggr;
    float Emp = clusterM->netA.energy.multipath;
    float Efs = clusterM->netA.energy.freespace;
    int packetLength = 6400;
    int ctrPacketLength = 6400;

    for(int i=0; i<clusterM->nodeA.numNode; i++)
    {
        if(!(clusterM->nodeA.node[i].clusterHead == clusterM->nodeA.node[i].id)) //if not a CH
        {
            int locNodeX = clusterM->nodeA.node[i].x;
            int locNodeY = clusterM->nodeA.node[i].y;

            int minDisCH = clusterM->nodeA.node[i].clusterHead;
            int chNodeX = clusterM->nodeA.node[minDisCH].x;
            int chNodeY = clusterM->nodeA.node[minDisCH].y;
            double minDis = sqrt(pow(locNodeX - chNodeX, 2) + pow(locNodeY - chNodeY, 2));

            if (minDis > d0)
            {
                energy += ctrPacketLength * ETX + Emp * packetLength * (pow(minDis, 4));
            }
            else
            {
                energy += ctrPacketLength * ETX + Efs * packetLength * (pow(minDis, 2));
            }

            if(minDis > 0)
            {
                energy += ((ERX + EDA) * packetLength);
            }     
        }
    }
    return energy;    
}

float totalEnergy(ClusterModel* clusterM){
    float energy = 0;
    energy += dissEnergyCH(clusterM);
    energy += dissEnergyNonCH(clusterM);

    return energy;
}
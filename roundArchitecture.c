#include "roundArchitecture.h"

struct RoundArch* newRound(int numRound, int packetLength, int ctrPacketLength)
{
	struct RoundArch *roundA = malloc(sizeof *roundA); 
		
	if(packetLength == 0)
	{
		roundA->packetLength= 6400;
	} 
	else
	{
		roundA->packetLength = packetLength;	
	}

	if(ctrPacketLength == 0)
	{
		roundA->ctrPacketLength = 6400;
	} 
	else
	{
		roundA->ctrPacketLength = ctrPacketLength;	
	}
	
	

	return roundA;
}
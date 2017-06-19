CC=gcc
CFLAGS=-I. -lm -g
DEPS = network/nodeArchitecture.h network/netArchitecture.h energy/dissEnergy.h network/clusterModel.h network/newCluster.h
OBJ = simulatedAnnealing.o network/nodeArchitecture.o network/netArchitecture.o energy/dissEnergy.o network/newCluster.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

leach-c: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

clean: 
	rm *.o
	rm leach-c
	rm ./network/*.o
	rm ./energy/*.o

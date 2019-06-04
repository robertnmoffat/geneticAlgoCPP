#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

/*
Class representing a Chromosome to be used in a genetic algorithm class
*/
class Chromosome {
private:
	//The bits
	vector<bool> bits;
	//size of bit array to be set on intialization
	size_t size;
	//how effective the chromosome is at the given task
	float fitness;
	//chance that a chromosome crossover will occur
	float crossoverRate;
	//chance that a chromosomes bit will be mutated
	float mutationRate;

public:
	//Default constructor
	Chromosome(int size, float crossoverRate);
	//Initialize the bits to a random starting state
	void initBits();
	//Combine to chromosomes at a given crossover point
	void combineWith(Chromosome &chromosome, int crossoverPoint);
	void combineWith(Chromosome &chromosome);

	//randomly mutate the bits inside the chromosome at a given mutation rate
	void mutate(float rate);
	void mutate();

	void printChromosome();

	//set a bit at a position
	void setBit(int position, int value);
	//get a bit at a position
	int getBit(int position);

	int getFitness();
	void setFitness(float newFit);
};

#pragma once
#include<iostream>
#include<stdlib.h>
#include"Chromosome.h"

class GenAlg {
private:	
	Chromosome* chromosomes;
	int chromosomeCount;
	int wordLength;
	float totalFitness;

public:
	GenAlg(int chromosomeCount, int chromosomeSize);
	Chromosome selectChromosome();
	float sumTotalFitness();

};
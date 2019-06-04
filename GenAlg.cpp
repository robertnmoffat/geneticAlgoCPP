#include<iostream>

#include"GenAlg.h"

GenAlg::GenAlg(int chromosomeCount, int chromosomeSize) {
	chromosomes = &(new Chromosome(chromosomeSize)[chromosomeCount]);
	this->chromosomeCount = chromosomeCount;
}

float GenAlg::sumTotalFitness() {
	float total = 0.0f;

	for (int i = 0; i < chromosomeCount; i++) {
		total += chromosomes[i].getFitness();
	}

	return total;
}

Chromosome GenAlg::selectChromosome() {
	int choice = rand() % (int)totalFitness;
	float position = 0.0f;
	
	for (int i = 0; i < chromosomeCount; i++) {
		position += chromosomes[i].getFitness();
		if (position >= choice)return chromosomes[i];
	}
}
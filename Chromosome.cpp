#include"Chromosome.h"

Chromosome::Chromosome(int size, float crossoverRate): size(size), crossoverRate(crossoverRate) {
	initBits();
}

void Chromosome::initBits() {
	for (int i = 0; i < size; i++) {
		bits.push_back(rand() % 1 + 1);
	}
}

void Chromosome::combineWith(Chromosome &chromosome, int crossoverPoint) {
	if (chromosome.size != size) {
		cerr << "Chromosome size mismatch." << endl;
		
		return;
	}

	for (int i = crossoverPoint; i < size; i++) {
		setBit(i, chromosome.getBit(i));
		chromosome.setBit(i, getBit(i));
	}
}

void Chromosome::combineWith(Chromosome &chromosome) {
	if (chromosome.size != size) {
		cerr << "Chromosome size mismatch." << endl;

		return;
	}

	int crossoverPoint = rand() % size + 1;

	for (int i = crossoverPoint; i < size; i++) {
		setBit(i, chromosome.getBit(i));
		chromosome.setBit(i, getBit(i));
	}
}

void Chromosome::mutate(float rate) {
	for (int i = 0; i < size; i++) {
		if ((rand() % 100 + 1) <= (rate * 100)) {
			if (bits[i] == 1)
				bits[i] = 0;
			else
				bits[i] = 1;
		}
	}
}

void Chromosome::mutate() {
	for (int i = 0; i < size; i++) {
		if ((rand() % 100 + 1) <= (mutationRate * 100)) {
			if (bits[i] == 1)
				bits[i] = 0;
			else
				bits[i] = 1;
		}
	}
}

void Chromosome::printChromosome() {
	for (int i = 0; i < size; i++) {
		cout << getBit(i);
	}
	cout << endl;
}

void Chromosome::setBit(int position, int value) {
	bits[position] = value;
}

int Chromosome::getBit(int position) {
	return bits[position];
}

int Chromosome::getFitness() {
	return this->fitness;
}

void Chromosome::setFitness(float newFit) {
	this->fitness = newFit;
}


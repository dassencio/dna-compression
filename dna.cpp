#include <iostream>
#include <cstring>
#include <random>

#include "dna.h"


/**
 * @brief returns a random DNA sequence with length in the range [1,20]
 */
char* random_dna ()
{
	static const char base_array[] = { 'A', 'C', 'G', 'T' };

	std::random_device device;
	std::mt19937 gen(device());

	/* random DNA length generator */
	std::uniform_int_distribution<> dis_len(1,20);

	/* random DNA base generator */
	std::uniform_int_distribution<> dis_dna(0,3);

	/* select the DNA sequence length */
	size_t dna_len = dis_len(gen);

	char* dna_str = new char[dna_len+1];

	/* build the DNA sequence */
	for (size_t i = 0; i < dna_len; i++)
	{
		dna_str[i] = base_array[dis_dna(gen)];
	}

	dna_str[dna_len] = '\0';

	return dna_str;
}

int main ()
{
	const char* dna_str = random_dna();

	dna_bitset dna(dna_str, strlen(dna_str));

	const char* dna_str2 = dna.to_string();

	std::cout << "original sequence: " << dna_str  << std::endl;
	std::cout << "stored sequence  : " << dna_str2 << std::endl;

	int result = std::strcmp(dna_str, dna_str2);

	std::cout << "output is correct: " << std::boolalpha << (result == 0) << std::endl;

	delete[] dna_str;
	delete[] dna_str2;

	return result;
}

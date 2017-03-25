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
	std::mt19937 generator(device());

	/* random DNA length generator */
	std::uniform_int_distribution<> length_chooser(1,20);

	/* random DNA base generator */
	std::uniform_int_distribution<> base_chooser(0,3);

	/* select the DNA sequence length */
	size_t dna_len = length_chooser(generator);

	char* dna_str = new char[dna_len+1];

	/* build the DNA sequence */
	for (size_t i = 0; i < dna_len; i++)
	{
		dna_str[i] = base_array[base_chooser(generator)];
	}

	dna_str[dna_len] = '\0';

	return dna_str;
}

int main ()
{
	const char* dna_str = random_dna();

	dna_bitset dna(dna_str, std::strlen(dna_str));

	const char* dna_str2 = dna.to_string();

	std::cout << "original sequence: " << dna_str  << std::endl;
	std::cout << "restored sequence: " << dna_str2 << std::endl;

	int result = std::strcmp(dna_str, dna_str2);

	std::cout << "output is correct: " << std::boolalpha << (result == 0) << std::endl;

	delete[] dna_str;
	delete[] dna_str2;

	return result;
}

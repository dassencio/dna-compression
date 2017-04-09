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
	const char* dna_str_original = random_dna();

	DnaBitset dna(dna_str_original, std::strlen(dna_str_original));

	const char* dna_str_recovered = dna.to_string();

	std::cout << "original sequence : " << dna_str_original  << "\n";
	std::cout << "recovered sequence: " << dna_str_recovered << "\n";

	int result = std::strcmp(dna_str_original, dna_str_recovered);

	std::cout << (result == 0 ? "test passed" : "test failed") << "\n";

	delete[] dna_str_original;
	delete[] dna_str_recovered;

	return (result == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

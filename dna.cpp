#include <iostream>
#include <cstring>
#include <random>

#include "dna.h"


using namespace std;


/**
 * @brief returns a random DNA sequence with length in the range [1,20]
 */
char* random_dna ()
{
	static const char base_array[] = { 'A', 'C', 'G', 'T' };

	random_device rd;
	mt19937 gen(rd());

	/* random DNA length generator */
	uniform_int_distribution<> dis_len(1,20);

	/* random DNA base generator */
	uniform_int_distribution<> dis_dna(0,3);

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

	cout << "original sequence: " << dna_str  << endl;
	cout << "stored sequence  : " << dna_str2 << endl;

	int result = strcmp(dna_str, dna_str2);

	cout << "output is correct: " << boolalpha << (result == 0) << endl;

	delete[] dna_str;
	delete[] dna_str2;

	return result;
}

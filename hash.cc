/*
 * $Id$
 * $Author$
 */

#include <stdio.h>
#include <inttypes.h>

#define BUCKET_COUNT 19
#define BUCKET_SIZE  8

typedef void * functype;

struct hashset
{
	functype entries[BUCKET_COUNT][BUCKET_SIZE];
};

uint32_t compute_hash(functype func)
{
	return ((uint32_t)func >> 2) % BUCKET_COUNT;
}

bool insert(hashset *h, functype func)
{
	uint32_t hash = compute_hash(func)

	for (unsigned l = 0; l < BUCKET_SIZE; l++)
	{
		if (h->entries[hash][l] == 0)
		{
			h->entries[hash][l] = func;
			return true;
		}
		else if (h->entries[hash][l] == func)
		{
			return true;
		}
	}
	return false;
}

bool contains(hashset *h, functype func)
{
	uint32_t hash = compute_hash(func)

	for (unsigned l = 0; l < BUCKET_SIZE; l++)
	{
		if (h->entries[hash][l] == 0)
		{
			// End of list found
			return false;
		}

		if (h->entries[hash][l] == func)
		{
			// Found!
			return true;
		}
	}

	// Full lists but not found.
	return false;
}

int main()
{
}

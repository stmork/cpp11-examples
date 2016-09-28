/*
 * $Id$
 * $Author$
 */

#include <stdio.h>
#include <stdint.h>
#include <strings.h>

#define BUCKET_COUNT 19
#define BUCKET_SIZE  8

typedef void * functype;

struct hashset
{
	functype entries[BUCKET_COUNT][BUCKET_SIZE];
};

unsigned compute_hash(functype func)
{
	const uintptr_t converted = (uintptr_t)func;

	return (converted >> 2) % BUCKET_COUNT;
}

bool insert(hashset *h, functype func)
{
	const unsigned hash = compute_hash(func);

	for (unsigned l = 0; l < BUCKET_SIZE; l++)
	{
		if (h->entries[hash][l] == 0)
		{
			// First empty cell found insert and leave
			h->entries[hash][l] = func;
			return true;
		}
		else if (h->entries[hash][l] == func)
		{
			// Entry already inserted and leave.
			return true;
		}
	}

	// List is full.
	return false;
}

bool contains(hashset *h, functype func)
{
	const unsigned hash = compute_hash(func);

	for (unsigned l = 0; l < BUCKET_SIZE; l++)
	{
		if (h->entries[hash][l] == 0)
		{
			// End of list found
			return false;
		}
		else if (h->entries[hash][l] == func)
		{
			// Found!
			return true;
		}
	}

	// Full lists but not found.
	return false;
}

void iterate(const hashset *set)
{
	for (unsigned i = 0; i < BUCKET_COUNT;i++)
	{
		printf("%2u:\n", i);
		for (unsigned k = 0; k < BUCKET_SIZE; k++)
		{
			if (set->entries[i][k] == 0)
			{
				break;
			}
			else
			{
				printf("  %2u: %p\n", k, set->entries[i][k]);
			}
		}
	}
}

void test1()
{

}

void test2()
{

}

int main()
{
	struct hashset set;

	bzero(&set, sizeof set);

	insert(&set, (functype)insert);
	insert(&set, (functype)contains);
	insert(&set, (functype)main);
	insert(&set, (functype)main);
	insert(&set, (functype)test1);
	printf("%p %s\n", &test1, contains(&set, (functype)&test1) ? "yes" : "no");
	printf("%p %s\n", &test2, contains(&set, (functype)&test2) ? "yes" : "no");
	printf("%p %s\n", &main,  contains(&set, (functype)&main) ? "yes" : "no");
	insert(&set, (functype)test2);

	iterate(&set);
}

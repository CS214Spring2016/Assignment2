#include <stdlib.h>

#ifndef MALLOC_H
#define MALLOC_H

#define block_size 5000
#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)


struct mBlock
{
	struct mBlock *next;
	struct mBlock *prev;
	unsigned int isFree:1; //boolean, 0 if free, 1 if not
	insigned int mSize:24; //size of mem
};

void* mymalloc(unsigned int, char*, unsigned int);
void* myfree(void *, char *, unsigned int);




#endif
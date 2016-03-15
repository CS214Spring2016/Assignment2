#include <stdlib.h>

#ifndef MALLOC_H
#define MALLOC_H

#define block_size 8000 //i figure 8000 is a fun number
#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)


struct mBlock
{
	size_t size;
	struct mBlock *next, *prev;
	unsigned int isFree:1; //boolean, 0 if free, 1 if not

};
typedef struct mBlock mBlock;

void* mymalloc(unsigned int, char*, unsigned int);
void myfree(void *, char *, unsigned int);




#endif
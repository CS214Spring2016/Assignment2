#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>

static char heap[block_size];
static struct mBlock *head;

void *mymalloc(unsigned int size, char* file, unsigned int line)
{

}

void *myfree(void *p, char *file, unsigned int line)
{
	
}
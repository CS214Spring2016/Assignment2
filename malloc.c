#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>


//this is our gigantic block of memory 
static char heap[block_size];
static struct mBlock *head;

void *mymalloc(unsigned int size, char* file, unsigned int line)
{
	static int init = 0; //boolean if initialized or not
	mBlock *current;
	mBlock *next;

	//first time
	if(!init)
	{
		head = (mBlock *) heap;
		head->next = head->prev = 0;
		head->size = block_size - sizeof(mBlock);
		head->isFree = 1;
		init = 1;
	}

	current = head;

	do	
	{
		if(current->size < size)
		{
			//requested size bigger than current block
			//go to next block
			current = current->next;
			if(current == 0)
			{
				fprintf(stderr,"Error: Not enough space in heap: %s, line %d.\n",file,line);
				return NULL;
			}
		}
		else if(!current->isFree)
		{
			//block is currently being used
			//go to next
			current = current->next;
		}
		else if(current->size < (size+sizeof(mBlock)))
		{
			//this means we cant use the header
			//enough room for memory but not header
			printf("Allocated memory of size %d\n",size);
			current->isFree = 0;
			return (char*)current + sizeof(mBlock);
		}
		else
		{
			//give data
			next = (mBlock*)((char*)current + sizeof(mBlock) + size);
			next->prev = current;
			next->next = current->next;



			//when block is in middle
			if(current->next !=0)
			{
				current->next->prev = next;
			}
			current->next = next;

			next->size = current->size - sizeof(mBlock) - size;
			next->isFree = 1;

			current->size = size;
			current->isFree = 0;

			printf("Allocated memory of size %d\n",size);
			return (char*)current + sizeof(mBlock);


		}
	}
	while(current != 0);

	fprintf(stderr,"Error: no room available to fit data in file: %s, line %d.\n",file,line);


	return 0;


}



void myfree(void *p, char *file, unsigned int line)
{

	int location = p - (void *)heap;
	mBlock *current;
	mBlock *ptr = (mBlock *)((char *)p - sizeof(mBlock));

	current = head;

	while(current != NULL)
	{
		if(current == ptr)
		{
			//free twice
			if(current->isFree != 0)
			{
				fprintf(stderr, "Error: Cannot free already freed pointer. In file: %s, line %d\n",file,line);
				return;
			}

			current->isFree = 1;
			//need to merge blocks so we dont have little scattered small blocks around
			//this checks the right
			if(current != NULL && current->next != NULL && current->next->isFree)
			{
				current->size += current->next->size;
				current->next = current->next->next;
			}

			//this looks left
			if(current != NULL && current->prev != NULL && current->prev->isFree) 
			{ 
				current->prev->size += current->size;
				current->prev->next = current->next;
			}
			printf("Freeing block at location %d\n", location);
			return;
		}

		current = current->next;
	}

	fprintf(stderr, "Error: Invalid pointer address. In file: %s, line %d\n",file,line);





	
}



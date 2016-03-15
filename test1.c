#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//first should work, second shouldn't
	//freeing already freed pointer
	char *d = malloc(40);
	free(d);
	printf("expecting error\n");
	free(d);
}
#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//invalid address, cannot free
	printf("expecting error\n");
	free(0);
}
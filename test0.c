#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//test zero
	//simple malloc and free sequence, should throw no errors, small block size
	char *c = malloc(10);
	free(c);
}
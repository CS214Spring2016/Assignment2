#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//example from the assignment
	//this is a working test
	char *e = malloc(100);
	free(e);
	e = (char *)malloc(100);
	free(e);
}
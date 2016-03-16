#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//invalid address, cannot free
	char *p = malloc(1000);
	free(p+10);
}
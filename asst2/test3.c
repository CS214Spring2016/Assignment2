#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//invalid address, cannot free
	int x;
	free(&x);
}
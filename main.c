#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

	char* a = malloc(7950);

	char* b = malloc(2);

	//test one yay both should work
	char *c = malloc(10);
	free(c);

	//first should work, second shouldn't
	char *d = malloc(40);
	free(d);
	printf("expecting error\n");
	free(d);

	//invalid address no work
	printf("expecting error\n");
	free(0);


	//example from the assignment
	char *e = malloc(100);
	free(e);
	e = (char *)malloc(100);
	free(e);

	//another assignment example, shouldn't work
	printf("expecting error\n");
	int x;
	free(&x);

	//another assignment example, shouldn't work
	printf("expecting error\n");
	char* f = malloc(200);
	free(f+10);


	return 0;

}
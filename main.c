#include "malloc.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

	//test one yay both should work
	char *test1 = malloc(10);
	char *test2 = malloc(30);

	free(test1);
	free(test2);

	//first should work, second shouldn't
	char *test3 = malloc(40);
	free(test3);
	printf("expecting error\n");
	free(test3);

	//invalid address no work
	printf("expecting error\n");
	free(0);


	//example from the assignment
	char *p = malloc(100);
	free(p);
	p = (char *)malloc(100);
	free(p);

	//another assignment example, shouldn't work
	printf("expecting error\n");
	int x;
	free(&x);

	//another assignment example, shouldn't work
	printf("expecting error\n");
	p = (char *)malloc(200);
	free(p+10);

	// char *str = malloc(sizeof(char) *strlen(argv[1]));
	// strcpy(str, argv[1]);
	// free(str);





	return 0;

}
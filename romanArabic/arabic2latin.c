#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 100

int makeConvertion( char * arabic, char * latin);

int main()
{
	char arabic[MAX_BUFFER];
	char latin[MAX_BUFFER];

	printf("Welcome to arabic to latin converter.\nIntroduce a number in arabic to convert to his latin expression.\nIntroduce 'q' to exit.\n");
	fflush(stdout);

	while(1) {
		printf("\n>>");
		scanf("%s", arabic);
		arabic[MAX_BUFFER] = 0;

		if ( arabic[0] == 'q') {
				exit(0);
		}

		/* Conversion of the number */
		memset(latin, 0, MAX_BUFFER);
		makeConvertion(arabic, latin);
		printf("\t>>%s", latin);
	}
	
	return 0;

}

int makeConvertion( char * arabic, char * latin)
{

	/* Fuck, we first must convert the number to decimal in order to make the calcullation */
	/* Big numbers */
	if ( ) {
	}	

	return 0;
}

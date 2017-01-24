
#include "string.h"
#include "stdio.h"

#define print(t); printf("(%s)\n",t);
#define log(t); printf("\n**%s\n",t);

int main() {

	int i=0;
	int j=0;
	String string1 = NULL;
	String string2 = NULL;
	
	log("Test for creating a string");
	string1 = newString(lengthString("Hello world"));
	print(string1);
	free(string1);

	log("Test for creating a initializated string");
	string1 = copyString("Hello World");
	print(string1);
	free(string1);

	log("Test for copying from one string to another");
	string1 = copyString("Hello World");
	string2 = copyString(string1);
	print(string1);
	print(string2);
	free(string1);
	free(string2);


	log("Test for obtaning substrings");
	for ( i=0; i<10; i++ ) {
		for (j=10; j>-3; j--) {
			string1 = subString("Hello World", i, j);
			print(string1);
			free(string1);
		}
	}

	log("Test for reversing strings");
	i=0;

	for ( i=0; i<lengthString("Hello world")-1; i++ ) {
		for (j=lengthString("Hello world"); j>=0; j--) {
			string1 = subString("Hello World", i, j);
			print(string1);
			string1 = reverseString(string1);
			print(string1);
			free(string1);
		}
	}


	log("Test for copying the reverse of a string");
	string1 = copyReverseString("Hello World");
	string2 = copyReverseString(string1);
	print(string1);
	print(string2);
	free(string1);
	free(string2);


	log("Test for rejecting characters of a string");
	string1 = copyString("Hello World");
	string1 = reject(string1, 'l');
	print(string1);
	free(string1);

	log("Test for copying rejected string");
	string1 = copyReject("Hello World", 'l');
	string2 = copyReject(string1, 'o');
	print(string1);
	print(string2);
	free(string1);
	free(string2);


	log("Test for rejecting substring");
	string1 = copyString("ABCDEFABCDEFABCDEF");
	string1 = rejectAll(string1,"ACE");
	print(string1);
	string1 = rejectAll(string1,"B");
	print(string1);
	free(string1);

	log("Test for copying the rejected version of a string");
	string1 = copyRejectAll("ABCDEFABCDEFABCDEF", "ACE");
	print(string1);
	free(string1);

	log("Test for finding the first character");
	printf("%d\n",findString("01234567890123456789",'0'));
	printf("%d\n",findString("01234567890123456789",'1'));
	printf("%d\n",findString("01234567890123456789",'2'));
	printf("%d\n",findString("01234567890123456789",'3'));
	printf("%d\n",findString("01234567890123456789",'4'));
	printf("%d\n",findString("01234567890123456789",'5'));
	printf("%d\n",findString("01234567890123456789",'6'));
	printf("%d\n",findString("01234567890123456789",'7'));
	printf("%d\n",findString("01234567890123456789",'8'));
	printf("%d\n",findString("01234567890123456789",'9'));


	log("Test for finding the first character backwards");
	printf("%d\n",findReverseString("01234567890123456789",'0'));
	printf("%d\n",findReverseString("01234567890123456789",'1'));
	printf("%d\n",findReverseString("01234567890123456789",'2'));
	printf("%d\n",findReverseString("01234567890123456789",'3'));
	printf("%d\n",findReverseString("01234567890123456789",'4'));
	printf("%d\n",findReverseString("01234567890123456789",'5'));
	printf("%d\n",findReverseString("01234567890123456789",'6'));
	printf("%d\n",findReverseString("01234567890123456789",'7'));
	printf("%d\n",findReverseString("01234567890123456789",'8'));
	printf("%d\n",findReverseString("01234567890123456789",'9'));


	log("Test for finding a substring in a string");
	printf("%d\n",findAllString("01234567890112233445566778899","012"));
	printf("%d\n",findAllString("01234567890112233445566778899","123"));
	printf("%d\n",findAllString("01234567890112233445566778899","23456789"));
	printf("%d\n",findAllString("01234567890112233445566778899","3456789"));
	printf("%d\n",findAllString("01234567890112233445566778899","456789"));
	printf("%d\n",findAllString("01234567890112233445566778899","56789"));
	printf("%d\n",findAllString("01234567890112233445566778899","6789"));
	printf("%d\n",findAllString("01234567890112233445566778899","789"));
	printf("%d\n",findAllString("01234567890112233445566778899","89"));
	printf("%d\n",findAllString("01234567890112233445566778899","9"));
	printf("%d\n",findAllString("01234567890112233445566778899","abc"));
	printf("%d\n",findAllString("01234567890112233445566778899","011"));

	log("Test for comparing two strings");
	log("Cases that will result -1");
	printf("%d\n",compareString(NULL,"a"));
	printf("%d\n",compareString("a","aa"));
	printf("%d\n",compareString("a","b"));

	log("Cases that will result 0");
	printf("%d\n",compareString(NULL,NULL));
	printf("%d\n",compareString("a","a"));
	printf("%d\n",compareString("bbbb","bbbb"));

	log("Cases that will result 1");
	printf("%d\n",compareString("a",NULL));
	printf("%d\n",compareString("aa","a"));
	printf("%d\n",compareString("b","a"));
	

	log("Test for append one string to another");
	string1= concatenateString("Hello ", "World");
	string2= concatenateString(string1, NULL);
	print(string2);
	free(string2);
	string2= concatenateString(string1, "!");
	print(string2);
	free(string2);
	string2= concatenateString(string1, string1);
	print(string2);
	free(string2);
	print(string1);
	free(string1);
	


	exit(EXIT_SUCCESS);	
}

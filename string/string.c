#include "string.h"

/* Already alocates space for the \0*/
String newString( size_t size )
{
	String new = NULL;

	if ( size > 0) {
		new = (String)malloc((size +1)*sizeof(char));
		new[0] = 0;
		return new;
	}

	return NULL;
}

void freeString( String string )
{
	if ( string == NULL ) {
		return;
	}

	free(string);

	return;
}

String copyString( const String origin )
{
	String new=NULL;
	int size = 0;
	int i=0;	

	if ( origin == NULL ) {
		return NULL;
	}

	size = lengthString(origin);

	new = newString(size);

	while( i<size ) {
		new[i] = origin[i];
		i++;		
	}
	new[size] = 0;
	
	return new;
}

String subString( const String string, int begin, int end )
{
	String new=NULL;
	int sizeOld = 0;
	int sizeNew = 0;
	int i=0;	

	if ( string == NULL ) {
		return NULL;
	}

	/* Obtain the size of the string */
	sizeOld = lengthString(string);

	/* Check that the first index is positive */
	if ( begin < 0 ) {
		return NULL;
	}

	/* Check that the second index is also correct */
	if ( end < begin) {
		return NULL;
	}

	/* Trim the last index */
	if ( end > sizeOld ) {
		end = sizeOld;
	}
	
	/* Obtain the size of the new array */
	sizeNew = end - begin + 1;

	new = newString(sizeNew);

	i = begin;
	while( i < sizeNew + begin ) {
		new[i-begin] = string[i];
		i++;		
	}
	
	new[sizeNew] = 0;

	return new;
}

String reverseString( const String string )
{
	char buffer = 0;
	int size = 0;
	int i=0;

	if ( string == NULL) {
		return NULL;
	}

	size = lengthString(string);

	while ( i< size/2 ) {
		buffer = string[i];
		string[i] = string[size - i -1];
		string[size - i - 1] = buffer;
		i++;
	}
	return string;
}

String copyReverseString( const String string )
{
	String result = NULL;
	int size = 0;
	int i=0;

	if ( string == NULL) {
		return NULL;
	}

	size = lengthString(string);
	result = newString(size);

	while ( i < size ) {
		result[i] = string[size - i -1];
		i++;
	}

	result[size] = 0;

	return result;
}

/* Substitutes each char that is equal to key with 1's (?) */
String reject( const String string, char key )
{
	int i=0;
	int size = 0;
	
	if ( string == NULL ) {
		return NULL;	
	}

	size = lengthString(string);

	while ( i < size) {
		if ( string[i] == key ) {
			string[i] = 49;
		}
		i++;
	}
	
	return string;
}

String copyReject( const String string, char key )
{
	return reject( copyString(string), key);
}

String rejectAll( const String string, const String key )
{
	int n = 0;
	int i = 0;

	n = lengthString(key);
	while ( i<n ) {
		reject(string, key[i]);
		i++;
	}

	return string;
}

String copyRejectAll( const String string, const String key )
{
	return rejectAll( copyString(string), key);
}

int lengthString( const String string )
{
	int i = 0;

	if ( string == NULL ) {
		return 0;
	}	

	while ( string[i] != 0) {
		i++;
	}
	
	return i;
}
int findString( const String string , char key )
{
	int i = 0;
	
	while ( string[i] != key) {
		if (string[i] == 0) {
			return -1;
		}
		i++;
	}
	
	return i;
}

int findReverseString( const String string , char key )
{
	int i = 0;

	i=lengthString(string);
	
	while ( string[i] != key ) {
		if ( i == 0 ) {
			return -1;
		}
		i--;
	}
	
	return i;	
}

int findAllString( const String string , const String key )
{
	int i=0, j=0;
	
	while ( string[i] != 0) {
		if ( string[i] == key[0] ) {
			j=0;
			while ( key[j] == string[j+i] ) {
				j++;
				if ( key[j] == 0 ) {
					/* Return the first index of the substring */
					return i;
				}
			}
		}
		i++;
	}

	return -1;
}
int compareString( const String string1 , const String string2 )
{
	int i = 0;

	if ( string1 == NULL) {
		if ( string2 == NULL ) {
			return 0;
		}
		return -1;
	}

	if ( string2 == NULL ) {
		return 1;
	}

	while(1) {
		if ( string1[i] == 0 ) {
			if (string2[i] == 0) {
				return 0;
			}
			return -1;
		}

		if (string2[i] == 0) {
			return 1;
		}

		if (string1[i] < string2[i] ) {
			return -1;
		} else if (string2[i] < string1[i] ) {
			return 1;
		}
		i++;
	}
}

String concatenateString( const String string1 , const String string2 )
{
	int n1=0, n2=0, i=0;
	String new = NULL;

	n1=lengthString(string1);
	n2=lengthString(string2);
	
	new = newString(n1+n2);

	while (i<n1) {
		new[i] = string1[i];
		i++;
	}
	i=0;
	while(i<n2) {
		new[n1+i] = string2[i];
		i++;
	}
	new[n1+n2] = 0;
	return new;
}

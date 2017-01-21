#include "string.h"

/* Already alocates space for the \0*/
String newString( size_t size )
{
	return (String)malloc((size +1)*sizeof(char));
}

void freeString( String * string )
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
		new[i] = origin[i]
		i++;		
	}

	return new;
}

String subString( const String string, int begin, int end )
{
	String new=NULL;
	int sizeOld = 0;
	int sizeNew = 0;
	int i=0;	

	if ( origin == NULL ) {
		return NULL;
	}

	sizeOld = lengthString(origin);
	if ( begin < 0 ) {
		return NULL;
	}

	if ( end < 0  || end > sizeOld ) {
		end = sizeOld;
	}
	
	sizeNew = end - begin;

	new = newString(sizeNew);

	i = begin;
	while( i<sizeNew+begin ) {
		new[i-begin] = origin[i]
		i++;		
	}

	return new;
}

String reverseString( const String string )
{
	char buffer = NULL;
	int size = 0;
	int i=0;

	if ( string == NULL) {
		return NULL;
	}

	size = lengthString(string);

	while ( i<size ) {
		buffer = string[i];
		string[i] = string[size - i -1];
		string[size - i] = buffer;
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

	while ( i<size ) {
		result[i] = string[size - i -1];
	}

	return string;
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
			string[i] = 1;
		}
	}
	
	return string;
}

String copyReject( const String string, char key )
{
	reject( copyString(string), key);
}

String rejectAll( const String string, const String key )
{
	int n = 0;
	int i=0;

	n = lentghString(key);
	while ( i<n ) {
		reject(string, key[i]);
		i++;
	}

	return string;
}

String copyRejectAll( const String string, char key )
{
	rejectAll( copyString(string), key);
}

int lengthString( const String string )
{
	int i = 0;
	
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

	i=lentghString(string);
	
	while ( string[i] != key ) {
		if ( i<0 ) {
			return -1;
		}
		i--;
	}
	
	return i;	
}

int findAllString( const String string , const String key );
int compare( const String string1 , const String string2 );

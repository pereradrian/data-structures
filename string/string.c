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
	String buffer = NULL;
	int size = 0;
	int i=0;

	if ( string == NULL) {
		return NULL;
	}

	size = lengthString(string);
	buffer = newString(size);

	while ( i<size ) {
		result[i] = string[size-i];
	}
	
	i = 0;
	while ( i< size ) {
		string[i] = buffer[i];
	}

	freeString(buffer);

	return string;
}

String copyReverseString( const String string );
String reject( const String string, char key );
String copyReject( const String string, char key );
String rejectAll( const String string, const String key );
String copyRejectAll( const String string, char key );

int lengthString( const String string );
int findString( const String string , char key );
int findReverseString( const String string , char key );
int findAllString( const String string , const String key );
int compare( const String string1 , const String string2 );
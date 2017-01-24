#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>

typedef char * String;

String newString( size_t size );
void freeString( String string );
String copyString( const String origin );

String subString( const String string, int begin, int end );
String reverseString( const String string );
String copyReverseString( const String string );
String reject( const String string, char key );
String copyReject( const String string, char key );
String rejectAll( const String string, const String key );
String copyRejectAll( const String string, const String key );

int lengthString( const String string );
int findString( const String string , char key );
int findReverseString( const String string , char key );
int findAllString( const String string , const String key );
int compareString( const String string1 , const String string2 );
String concatenateString( const String string1 , const String string2 );

#endif

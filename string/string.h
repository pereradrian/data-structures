#ifndef __GENERIC_ARRAY_H__
#define __GENERIC_ARRAY_H__

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
String copyRejectAll( const String string, char key );

int lengthString( const String string );
int findString( const String string , char key );
int findReverseString( const String string , char key );
int findAllString( const String string , const String key );
int compare( const String string1 , const String string2 );

#endif

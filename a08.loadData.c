/*
 * Date : Aug 19th, 2025, 12:30pm
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h> 
		    
#include <stdlib.h> // atof
		    
#include <string.h> // strcpy
		    
#include "a05.structs.c"

void loadData ( struct FileLines *fileLines  
		, int lim , float stiffs [ lim ] , int nodeIndices [ lim ] [ 2 ] ) {

	//printf("loadData()\n");

	int idx ;
	char stiffs_str [ lim ] [ 10 ]  ;
	char nodeIndices_str [ lim ] [ 2 ] [ 10 ] ;
	char buf[10] , *chptr = buf ;

	for ( idx = 0 ; idx < lim ; idx ++ ) {

		chptr = strtok ( fileLines->allLines[ idx ] , " , " ) ;
		strcpy ( stiffs_str [ idx ] , chptr ) ;
		stiffs[ idx ] = atof ( stiffs_str [ idx ] ) ;

		chptr = nodeIndices_str [ idx ][ 0 ] ;
		chptr = strtok ( NULL , " , " ) ;
		strcpy ( nodeIndices_str [ idx ][ 0 ] , chptr ) ;
		nodeIndices [ idx ] [ 0 ] = atoi ( nodeIndices_str [ idx ] [ 0 ] ) ;

		chptr = nodeIndices_str [ idx ][ 1 ];
		chptr = strtok ( NULL , " , " ) ;
		strcpy ( nodeIndices_str [ idx ][ 1 ] , chptr ) ;
		nodeIndices [ idx ] [ 1 ] = atoi ( nodeIndices_str [ idx ] [ 1 ] ) ;
	}

	//printf("strings\n");
	/*
	for ( idx = 0 ; idx < lim ; idx ++ ) {
		printf( "[%s][%s][%s]\n"
				, stiffs_str[idx]
				, nodeIndices_str[idx][0]
				, nodeIndices_str[idx][1] ) ;
	}*/

	/*
	printf("float, ints\n");
	for ( idx = 0 ; idx < lim ; idx ++ ) {

		printf( "[%.3lf][%d][%d]\n"
				, stiffs [ idx ] 
				, nodeIndices [ idx ] [ 0 ] 
				, nodeIndices [ idx ] [ 1 ] 
		      );
	}*/


}


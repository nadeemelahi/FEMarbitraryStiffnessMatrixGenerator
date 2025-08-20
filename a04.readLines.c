/*
 * Date : Aug 19th, 2025, 5:30am
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h> // FILE *file
#include <string.h> // strcpy()
#include "a05.structs.c" 

int checkIfNewline ( int len , char line [ len ] ) ;

void readLines ( FILE *file , struct FileLines *fileLines ) {

	//printf("readLines()\n");

	int ret , max = fileLines->maxLnSz ;
	char eachLine [ max ] 
		, *ln = eachLine ;

	while ( 1 ) {

		ln = fgets ( eachLine , max , file ) ;
	       if ( ln == NULL ) break ;

	       // 
	       ret = checkIfNewline ( max , eachLine ) ;
	       if ( ret ) continue;

	       strcpy ( fileLines->allLines [ fileLines->lnCnt ] , eachLine ) ;

	       fileLines->lnCnt ++ ;
	}
}


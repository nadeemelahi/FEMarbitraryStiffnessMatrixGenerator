/*
 * Date : Aug 19th, 2025, 5:30am
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h>

#include "a05.structs.c"

void readLines ( FILE *file , struct FileLines *fileLines ) ;

void trimTrailingNewline ( int len , char line [ len ] ) ;

int readData ( char *dataFilename , struct FileLines *fileLines ) {

	//printf("readData()\n");

	FILE *dataFile = fopen( dataFilename , "r" ) ;

	if ( dataFile == NULL ) { 
		printf("Error: readData(): Unable to open file: %s \n", dataFilename );
		return 1 ;
	}

	readLines ( dataFile , fileLines ) ;

	int idx , lim ; 

	lim = fileLines->lnCnt;
		
	for ( idx = 0 ; idx < lim ; idx ++ ) {

		trimTrailingNewline ( fileLines->maxLnSz , fileLines->allLines [ idx ] ) ;
	}

	return 0;

}


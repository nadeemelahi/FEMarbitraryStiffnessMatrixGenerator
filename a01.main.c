/*
 * Date : Aug 19th, 2025, 5:30am
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h>

#include "a05.structs.c"

int readData ( char *dataFilename , struct FileLines *fileLines ) ;

void readLines ( FILE *file , struct FileLines *fileLines ) ;

void loadData ( struct FileLines *fileLines  
		, int lim , float stiffs [ lim ] , int nodeIndices [ lim ] [ 2 ] ) ;

void buildStiffnessMatrix ( int lim , float stiffs [ lim ] , int nodeIndices [ lim ] [ 2 ] ) ;

int main ( int argc , char * argv [ ] ) {

	if ( argc < 2 ) {
		printf("ERROR: main(): missing data file\n");
		printf("CORRECT EXAMPLE USAGE: ./a.out data.txt\n");
		return 1;
	}

	int ret;
	struct FileLines fileLines = { 0 , 50 , 50 } ;

	ret = readData ( argv[1] , &fileLines ) ;
	
	if ( ret ) {
		printf("ERROR: main(): readData()\n");
		return 2;
	}

	int idx , lim ;

	lim = fileLines.lnCnt;

	for ( idx = 0 ; idx < lim ; idx ++ ) {

		printf("%s\n" , fileLines.allLines [ idx ] ) ;
	}


	// ex data 
	// 10 , 1 , 2 
	// 20 , 2 , 3
	// 30 , 2 , 4
	
	// for each line, we need 1 float and 2 ints

	float stiffs [ lim ] ;
	int nodeIndices [ lim ] [ 2 ] ;

	loadData ( &fileLines , lim , stiffs , nodeIndices ) ;

	// WIERD SPACES AUTOMATICALLY TRIMMED - but tabs would need clearing

	buildStiffnessMatrix ( lim , stiffs , nodeIndices ) ;


	return 0;
}

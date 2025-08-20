/*
 * Date : Aug 19th, 2025, 1:00pm
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h>

void buildIndicesList ( int lim , int nodeIndices [ lim ] [ 2 ] , int indicesList [ lim ] [ 4 ] [ 2 ] ) {


	// build indices list
	// 10 , 1 , 2 
	// -> ( 1,1 ) ( 1,2 ) ( 2,1 ) ( 2,2 )
	
	int idx ;
	
	for ( idx = 0 ; idx < lim ; idx ++ ) {

		// nodeIndices [ idx ] [ 0 , 1 ] 
		// -> ( kdex,1,1 ) ( kdx,1,2 ) ( kdx,2,1 ) ( kdx,2,2 )

		// 1 , 1
		indicesList [ idx ] [ 0 ] [ 0 ] = nodeIndices [ idx ] [ 0 ] ;
		indicesList [ idx ] [ 0 ] [ 1 ] = nodeIndices [ idx ] [ 0 ] ;

		// 1 , 2
		indicesList [ idx ] [ 1 ] [ 0 ] = nodeIndices [ idx ] [ 0 ] ;
		indicesList [ idx ] [ 1 ] [ 1 ] = nodeIndices [ idx ] [ 1 ] ;

		// 2 , 1
		indicesList [ idx ] [ 2 ] [ 0 ] = nodeIndices [ idx ] [ 1 ] ;
		indicesList [ idx ] [ 2 ] [ 1 ] = nodeIndices [ idx ] [ 0 ] ;


		// 2 , 2
		indicesList [ idx ] [ 3 ] [ 0 ] = nodeIndices [ idx ] [ 1 ] ;
		indicesList [ idx ] [ 3 ] [ 1 ] = nodeIndices [ idx ] [ 1 ] ;

	}	
	//printf("   buildIndicesList() exits \n");
}

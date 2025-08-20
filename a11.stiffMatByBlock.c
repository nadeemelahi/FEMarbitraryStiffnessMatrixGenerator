/*
 * Date : Aug 19th, 2025, 11:00pm
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */
#include <stdio.h>
#include <string.h>

void stiffMatByBlock (

		int lim
		, float stiffs [ lim ] 
		, int nodeIndices [ lim ] [ 2 ]
		, int indicesList [ lim ] [ 4 ] [ 2 ] 	

		, int mdx , int ndx  
		, int maxNode
		, int k_strSz 
		, char coeffMatrix_str [ maxNode ] [ maxNode ] [ k_strSz ]
		, float coeffMatrix_fl [ maxNode ] [ maxNode ]

		) {

	int row = mdx + 1 ;
	int col = ndx + 1 ;
	//printf("stiffMatByBlock( %d , %d ) " , row , col );


	// tmp string buffers
	char buf1 [ k_strSz ]  // full string
		, buf2 [ 8 ] // _+_k100
		, *ptr1 = buf1
		, *ptr2 = buf2 ; 

	float ktot = 0;


	// clear buf1 from previous executions
	buf1[0] = '0'; buf1[1] = '\0';

	int ice = 0; 
	// first match sprint "kx" 
	// after that sprint "_+_kdx"

	int idx , jdx ;
	// loop over indicesList for matches to row / col
	for ( idx = 0 ; idx < lim ; idx ++ ) {

		// indices [ idx ] [ jdx ] 
		// k index = idx + 1 
		for ( jdx = 0 ; jdx < 4 ; jdx ++ ) {

			if ( 
					indicesList [ idx ] [ jdx ][ 0 ] == row
					&& indicesList [ idx ] [ jdx ][ 1 ] == col
			   ) {


				if ( jdx == 1 || jdx == 2 ) {
					// negative sign
					ktot -= stiffs[ idx ] ;
					//printf("match -k%d\n" , idx + 1 );
					sprintf ( ptr1 , "-k%d", idx + 1 ) ; 

				} else {
					ktot += stiffs[ idx ] ;
					//printf("match k%d\n" , idx + 1 );
					// only need to break ice down the diagonal
					if ( !ice ) {
						ice = 1;

						sprintf ( ptr1 , "k%d", idx + 1 ) ; 

					} else {

						sprintf ( ptr2 , " + k%d", idx + 1 ) ; 
						strcat ( ptr1 , ptr2 ) ;
					}

				}

			}
		}


	}

	// save it
	sprintf ( coeffMatrix_str[ mdx ][ ndx ] , "%s" , ptr1 ) ; 
	//printf ( "[%s] " , coeffMatrix_str[ mdx ][ ndx] ) ;

	coeffMatrix_fl [ mdx ] [ ndx ] = ktot;
	//printf ( "[%f]\n" , coeffMatrix_fl[ mdx ][ ndx] ) ;


}

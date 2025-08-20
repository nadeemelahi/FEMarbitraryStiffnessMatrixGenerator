/*
 * Date : Aug 19th, 2025, 12:45pm
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h>

#include <string.h>

void buildIndicesList ( int lim , int nodeIndices [ lim ] [ 2 ] , int indicesList [ lim ] [ 4 ] [ 2 ]) ;
	
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
	       
	       ) ;

void printStiffnessMatrix ( int maxNode , int k_strSz 
		, char coeffMatrix_str [ maxNode ] [ maxNode ] [ k_strSz ] 
		, float coeffMatrix_fl [ maxNode ] [ maxNode ] 
		) ;

// END prototypes

void buildStiffnessMatrix ( int lim , float stiffs [ lim ] , int nodeIndices [ lim ] [ 2 ] ) {

	//printf("buildStiffnessMatrix()\n");
	

	// build indices list
	// 50 , 1 , 2 -> ( 1,1 ) ( 1,2 ) ( 2,1 ) ( 2,2 )
	// 25 , 2 , 3 -> ( 2,2 ) ( 2,3 ) ( 3,2 ) ( 3,3 )
	// 10 , 2 , 4 -> ( 2,2 ) ( 2,4 ) ( 2,4 ) ( 4,4 )
	
	int indicesList [ lim ] [ 4 ] [ 2 ] ;

	buildIndicesList ( lim , nodeIndices , indicesList ) ; 

	int idx , jdx ;

	//printf("printIndicesList:\n");
	/*
	for ( idx = 0 ; idx < lim ; idx ++ ) {

		printf ( " k%d = %f \n" 
				, ( idx + 1 ) 
				, stiffs [ idx ] 
				) ;

		printf( "\t") ;

		printf( " [%d,%d] "
				, indicesList [ idx ] [ 0 ][ 0 ] 
				, indicesList [ idx ] [ 0 ][ 1 ] 
		      ) ;

		printf( "-[%d,%d] "
				, indicesList [ idx ] [ 1 ][ 0 ] 
				, indicesList [ idx ] [ 1 ][ 1 ] 
		      ) ;

		printf("\n") ;

		printf( "\t") ;

		printf( "-[%d,%d] "
				, indicesList [ idx ] [ 2 ][ 0 ] 
				, indicesList [ idx ] [ 2 ][ 1 ] 
		      ) ;

		printf( " [%d,%d] "
				, indicesList [ idx ] [ 3 ][ 0 ] 
				, indicesList [ idx ] [ 3 ][ 1 ] 
		      );

		printf( "\n" ) ;
	} */
	// ex 3 lines so 3 springs ie) k1 , k2 , k3
	// if num of elements lim is 2 you have k1_+_k2
	// 2each * 2elements + 3 * ( lim - 1 )
	
	int kCnt , each_k_strSz , k_strSz ;
	
	// if number of elements lim is less than 10 
	// k1,k2,k3...k9
	each_k_strSz = 2;
	kCnt = lim ;
	k_strSz = ( each_k_strSz * kCnt ) + 3 * ( kCnt - 1 ) ;

	if ( lim > 9 ) {

		// ..._+_k10_+_k11_+_...
		each_k_strSz = 3;
		// we can minus off 1-9
		kCnt = lim - 9 ;
		k_strSz += ( each_k_strSz * kCnt ) + 3 * ( kCnt - 1 ) ;

	} else if ( lim > 99 ) {

		// ..._+_k100_+_k101_+_...
		each_k_strSz = 4;
		// we can minus off 10-99 = 89
		kCnt = lim - 89 ;
		k_strSz += ( each_k_strSz * kCnt ) + 3 * ( kCnt - 1 ) ;
	} 

	k_strSz ++ ; // null term


	// WIERD NO COMPILER COMPLAINTS ABOUT USING VARIABLES IN CHAR ARRAY ALLOCATION

	int  maxNode = lim + 1 ; // if 3 spring, there will be 3+1 nodes	
					    //
	char coeffMatrix_str [ maxNode ] [ maxNode ] [ k_strSz ] ;
	float coeffMatrix_fl [ maxNode ] [ maxNode ] ;

	int mdx , ndx ; // if 3 spring, there will be 3+1 nodes	
					    //
	// ex 3 x 3 mat
	for ( mdx = 0 ; mdx < maxNode ; mdx ++ ) {
		for ( ndx = 0 ; ndx < maxNode ; ndx ++ ) {

			stiffMatByBlock ( 
					lim 
					, stiffs
					, nodeIndices
					, indicesList

					, mdx , ndx 
					, maxNode
					, k_strSz 
					, coeffMatrix_str
					, coeffMatrix_fl
					);
		}
	}

	
	// set all to zero
	printStiffnessMatrix ( maxNode , k_strSz 
			, coeffMatrix_str  
			, coeffMatrix_fl
			) ;

}


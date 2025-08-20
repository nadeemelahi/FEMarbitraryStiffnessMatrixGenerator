/*
 * Date : Aug 19th, 2025, 3:10am
 * Author : NED ( nadeem elahi )
 * email : nad@3deem.com
 */

#include <stdio.h>
#include <string.h>

void printStiffnessMatrix ( int maxNode , int k_strSz 
		, char coeffMatrix_str [ maxNode ] [ maxNode ] [ k_strSz ] 
		, float coeffMatrix_fl [ maxNode ] [ maxNode ] 
		) {

	//printf("printStiffnessMatrix()\n");

	int idx , jdx ;

	printf("\n");
	for ( idx = 0 ; idx < maxNode ; idx ++ ) {

		for ( jdx = 0 ; jdx < maxNode ; jdx ++ ) {


			printf ( " [ %-15s ]  " , coeffMatrix_str [ idx ] [ jdx ] );

		}

		printf("\n");
	}

	printf("\n");
	for ( idx = 0 ; idx < maxNode ; idx ++ ) {

		for ( jdx = 0 ; jdx < maxNode ; jdx ++ ) {


			printf ( " [ %f ]  " , coeffMatrix_fl [ idx ] [ jdx ] );

		}

		printf("\n");
	}

	printf("\n");
}


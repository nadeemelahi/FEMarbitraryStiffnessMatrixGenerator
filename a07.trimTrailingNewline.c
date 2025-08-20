
/*
 * Date: Aug 17, 2025, 04:25am
 * Author: Ned (Nadeem Elahi)
 * email: nad@3deem.com
 */

#include <string.h>

void trimTrailingNewline ( int len , char line[len] ) {

	int idx = strlen ( line ) ;
	line[ idx - 1 ] = '\0';
}

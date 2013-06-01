

/* Array with CA codes for all satellites */
#include <stdlib.h>
#include "gpssim.h"

unsigned int tap1[] = { 2, 3, 4, 5, 1,  2, 1, 2,  3, 2, 3, 5, 6, 7, 8,  9, 1, 2, 3, 4, 5, 6, 1, 4, 5, 6, 7,  8, 1, 2, 3, 4 };
unsigned int tap2[] = { 6, 7, 8, 9, 9, 10, 8, 9, 10, 3, 4, 6, 7, 8, 9, 10, 4, 5, 6, 7, 8, 9, 3, 6, 7, 8, 9, 10, 6, 7, 8, 9 };

signed char *ca_codes[NUMBER_OF_SATELLITES];


int create_ca_codes( void )
{
    int i = 0;

    for ( i = 0; i < NUMBER_OF_SATELLITES; ++i) {
        ca_codes[ i ] = calloc( CA_CODE_LENGTH, sizeof( signed char ) );
    }

    for ( i = 0; i < NUMBER_OF_SATELLITES; ++i) {
        int j = 0;
        char register1[11] = {0, 1,1,1, 1,1,1, 1,1,1, 1};
        char register2[11] = {0, 1,1,1, 1,1,1, 1,1,1, 1};
        unsigned int t1 = tap1[ i ];
        unsigned int t2 = tap2[ i ];
        for ( int j = 0; j < CA_CODE_LENGTH; ++j ) {
            int k = 0;
            signed char r1b10 = register1[10];
            signed char r2b   = register2[ t1  ] ^ register2[ t2 ];
            ca_codes[ i ][ j ] = r1b10 ^ r2b;
            register1[ 0 ] = register1[ 3 ] ^ register1[ 10 ];
            register2[ 0 ] = register2[ 2 ] ^ register2[ 3 ] ^ 
                             register2[ 6 ] ^ register2[ 8 ] ^ 
                             register2[ 9 ] ^ register2[ 10 ];
            for( int k = 10; k > 0; --k ) {
                register1[ k ] = register1[ k - 1 ];
                register2[ k ] = register2[ k - 1 ];
            }
        }
    }
    return 0;
}


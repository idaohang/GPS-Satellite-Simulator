
#include <stdio.h>
#include <stdlib.h>
#include "ca_codes.h"
#include "gpssim.h"

int main( int argc, char** argv )
{
    create_ca_codes();

    for ( int i = 0; i < NUMBER_OF_SATELLITES; ++i ) {
        for ( int j = 0; j < 10; ++j ) {
            printf( "%d", ca_codes[i][j] );
        }
        printf( "\n" );
    }
    return EXIT_SUCCESS;
}

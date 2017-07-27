#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    float x, y;
    int n;
    unsigned long long int countInCircle = 0;
    unsigned long long int N=2;
    char cont = 'y';
    srand( time(NULL) );

    printf("---------- NUMERICAL PI ESTIMATOR -----------");

    while( cont == 'y' || cont == 'Y' ){
        printf("\nHow many points to determine PI? \n");
        scanf("%d", &N);

        // If statement checks to see if computer could slow down. Gives a message to console if it does slow down
        if( N>1000000 ){
            printf("\n\tAre You Sure You want that many? (y/n) ");
            scanf(" %c", &cont);
            if( cont != 'y' && cont != 'Y' ){
                printf("Would you like to change your value? (y/n) ");
                scanf(" %c", &cont);
                if ( cont == 'y' || cont == 'Y' ) continue;
                else { printf("\n\nHave a nice day!\n\n"); return 0; }
            }
        }
        if( N>100000 ) printf("\tWorking... Please Wait...\n");

        // Block creates random numbers between 0 and 1. (Finds out how many are inside of a circle or the square there.)
        for( n=0; n<N; n++ ){
            x = (float)rand()/RAND_MAX; y = (float)rand()/RAND_MAX;

            if ( pow(x,2) + pow(y,2) <= 1 )
                countInCircle++;
        }

        double piEst = (double)countInCircle/N;

        printf("\n\n ESTIMATED: \t%lf\n", piEst);
        printf(" ACTUAL PI: \t%lf\n", M_PI);
        printf(" ERROR (%): \t%lf\n\n\n", fabs(M_PI-piEst)/M_PI*100 );

        printf("Would you like to try a different value? (y/n) ");
        scanf(" %c", &cont);
    }

    printf("\n\nHave a nice day!\n\n");

    return 0;

}

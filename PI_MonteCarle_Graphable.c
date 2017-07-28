#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    float x, y;                                 /* x and y coordinates for the monte carlo points */
    unsigned long long int n=0;                 /* counts how total points were made */
    unsigned long long int countInCircle = 0;   /* counts how many points landed in or on the circle */
    unsigned long long int N=2;
    int nPlace=10;                    // Used to determine how many places the estimate is accurate
    int decimalPlaces = 0;                      // Target for how many decimal places of accuracy wanted
    int dCounter = 0;                           // Counts how many places of accuracy there is in real time calculations
    int endDecimalCheck = 8;                   /* Tells the final number of digits of accuracy program goes for.
                                                   Meant for testing so that changes are simple and fast for debugging
                                                   rather than going into bowels of code. */
    float piEst; float pi=M_PI;               // Used in finding out how close to pi we actually are
    srand( time(NULL) );
    FILE *fx = fopen("singleDigitsAccuracy.csv","w");
    FILE *fy = fopen("singleIterations.csv","w");


    printf("---------- NUMERICAL PI ESTIMATOR : Graphable -----------");

    for( decimalPlaces=2; decimalPlaces<=endDecimalCheck; decimalPlaces*=2 ){
        /* Counters intentionally don't reset so that old runs don't get wasted */

        // If statement checks to see if computer could slow down. Gives a message to console if it does slow down
        printf("\n\n\tWorking on number of decimal places = %ld... Please Wait...\n", decimalPlaces);

        // Block creates random numbers between 0 and 1. (Finds out how many are inside of a circle or the square there.)
        // Block runs until the appropriate decimal place is correct. Save and display amount of iterations, and time it took
        while(dCounter<decimalPlaces) {

            x = (float)rand()/RAND_MAX; y = (float)rand()/RAND_MAX;

            if ( pow(x,2) + pow(y,2) <= 1 )
                countInCircle++;

            // Counts the number of iterations the code runs for the specific accuracy specified
            n++;

            piEst = (float)4*countInCircle/n;
            // Block of code calculates how many digits of pi was accurate
            if( (int)(pi*nPlace)%nPlace == (int)(piEst*nPlace)%nPlace ){
                dCounter++;
                nPlace*=10;
                if (decimalPlaces==16) printf("Digits %d\t", dCounter);
            } // END OF IF that checks how many decimal places of accuracy
        }


        // Block of code prints to screen and to files.
        printf("Iterations Taken for %d digits of accuracy: %ld\n", decimalPlaces, n);
        printf("ACTUAL: %.17f\n", M_PI);
        printf("ESTIMA: %.17f\n", piEst);
        if (decimalPlaces<endDecimalCheck) fprintf(fx, "%d,", decimalPlaces); else fprintf(fx, "%d", decimalPlaces);
        if (decimalPlaces<endDecimalCheck) fprintf(fy, "%ld,", n);            else fprintf(fy, "%ld", n);
    } // END OF FOR LOOP that goes through all the digits of accuracy wanted.

    printf("\n\nHave a nice day!\n\n");

    return 0;

}

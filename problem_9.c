
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//pythag triplet product = 1000

int p9 (int argc, char** argv) {
    for (int a = 1; a < 400; a++) {
        for (int b = a; b < 400; b++) {
            double cD = sqrt(a * a + b * b);
            if (cD == (int) cD) {
                int c = (int) cD;
                int sum = a + b + c;
                if (sum == 1000) {
                    int product = a * b * c;
                    printf("%i   \n", product);

                }
            }
        }
    }
}


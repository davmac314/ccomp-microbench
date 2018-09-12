#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int addf(int a, int b, int c, int d, int e, int f);
int addf_asm(int a, int b, int c, int d, int e, int f);

#define N 50000000

int main(int argc, char **argv)
{
    for (int i = 0; i < N; i++) {
        addf(0, 0, 0, 0, 0, 0);
        addf(INT_MAX, 1, 1, 1, 1, 1);
        addf(1, 1, 1, 1, INT_MAX, 1);
        addf(INT_MIN, -1, 0, 0, 0, 0);
        addf(0, 0, INT_MIN, 0, 0, -1);
    }

    return 0;
}

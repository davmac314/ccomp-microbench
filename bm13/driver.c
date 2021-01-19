#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>


#define N 50000000

int str2num(const char *c);
void consume(int);

int main(int argc, char **argv)
{
    for (int i = 0; i < N; i++) {
        int n = str2num("one");
        consume(n);
    }

    return 0;
}

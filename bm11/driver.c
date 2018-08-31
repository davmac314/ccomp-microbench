#include <stdlib.h>
#include <stdbool.h>

bool bm11(int *arr, int n);

#define N 500000000

int main(int argc, char **argv)
{
    int *arr = malloc(N * sizeof(int));
    
    unsigned int v = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }
    
    //for (int j = 0; j < 10000; j++) {
        bm11(arr, N);
    //}
    return 0;
}

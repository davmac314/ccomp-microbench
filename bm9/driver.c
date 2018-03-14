#include <stdlib.h>

void bm9(int *arr, int *p);

int main(int argc, char **argv)
{
    int *arr = malloc(10000000 * sizeof(int));
    if (arr == 0) {
        return 1;
    }

    for (int i = 0; i < 100; i++)
    bm9(arr, arr + 1000);
    return 0;
}

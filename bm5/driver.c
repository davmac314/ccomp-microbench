void 
NumSift (long *array, unsigned long i, unsigned long j);

#define ARRSIZE 100000

int main(int argc, char **argv)
{
    long arr[ARRSIZE];
    
    unsigned long r = 0;
    
    /* initialise the array */
    for (int i = 0; i < ARRSIZE; i++) {
        arr[i] = (long) r;
        r = r * 2343 + 569;  /* pseudo-random */
    }
    
    for (int j = 0; j < 1000; j++)
    for (int i = 0; i < (ARRSIZE / 2); i++) {
        NumSift(arr, 0, ARRSIZE - 1);
    }
}

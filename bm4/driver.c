void bm4(char * restrict src, char * restrict dest, int size);

#define SIZE 32768

int main(int argc, char **argv)
{
    char srcarr[SIZE];
    char dstarr[SIZE];
    
    for (int i = 0; i < 100000 * 10; i++) {
        bm4(srcarr, dstarr, SIZE);
    }
}

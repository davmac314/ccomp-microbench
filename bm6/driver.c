void bm6(void);

int main(int argc, char **arv)
{
    /* int array[10]; */
    for (int i = 0; i < 10000000; i++) {
        bm6();
    }
}

int foo(int v)
{
    return 1;
}

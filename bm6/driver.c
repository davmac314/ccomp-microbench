void bar();

int main(int argc, char **arv)
{
    /* int array[10]; */
    for (int i = 0; i < 10000000; i++) {
        bar();
    }
}

int foo(int v)
{
    return 1;
}

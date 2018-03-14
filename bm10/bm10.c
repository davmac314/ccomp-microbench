/**
 Test that a large accumulated shift is correctly recognized and
 reduced.
 */
int bm10(int a)
{
    for (int i = 0; i < 1000000000; i++) {
        a <<= 1;
    }
    return a;
}

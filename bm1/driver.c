int bm1(signed char a);

int main(int argc, char **argv)
{
    for (int j = 0; j < 200; j++)
    for (int i = 0; i < 100000; i++) {
        bm1(200);
        bm1(201);
        bm1(202);
        bm1(203);
        bm1(204);
        bm1(205);
    }
}

//note: not the same structs as in bm3
#include "structs.h"

int main(int argc, char **argv)
{
    struct goober g;
    for (int i = 0; i < 10000000*10; i++) {
        testFunc(&g);
    }
    return 0;
}

#include <string.h>

// bm13: check whether the compiler can see that it doesn't need to initialise a local-variable array on the
// stack (by copying it from an initialiser stored statically), when it is only read and never modified.
// GCC 9.3.0 seems to fail; clang 10.0.1 succeeds.

// Also, GCC with optimisation may be slower than with -O0, especially if the "wrong" processor architecture
// is selected (-march=...).
// Using -fno-builtin, to disable GCC's "inline" strcmp, seems to impose no penalty to performance.

int str2num(const char *s)
{
    struct number_t {
        const char *str;
        int val;
    };

    struct number_t numbers[9] = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    for (int i = 0; i < 9; i++) {
        if (strcmp(s, numbers[i].str) == 0) return numbers[i].val;
    }

    return 0;
}



void consume(int n)
{
    // do nothing, this is just to "use" the input parameter
}

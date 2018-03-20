/* #include <cstring> */
#include <string.h>
#include "../bm3/strucs.h"

/*
 This tests the compilers alias analysis. We allocate space on the stack,
 copy another structure (passed in) into it, modify slightly and then copy it
 back.
 
 If the compiler correctly recognizes that the structures cannot alias,
 it can instead modify the original structure directly, and can even
 optimize away the stack allocation.
 
 Interestingly, gcc 4.3.3 and 4.4.0 do better at this with -march=i686 than
 they do with -march=core2 (when the result is run on a core2). However
 neither of them correct identify the optimization.
 
 gcc 3.4.6 does worse than 4.3.3/4.4.0.
 llvm-2.5-gcc-4.2 does better than gcc-3.4.6 but worse than 4.3.x
*/
 
#if 0
/* If we use this, most compilers seem to suffer. */
/* just a utility */
static void copyTo(char * restrict dest, char * restrict src, int size)
{
    while (size-- != 0) {
        *dest++ = *src++;
    }
}

#else 

#define copyTo(dest,src,size) memcpy(dest,src,size)

#endif

void testFunc(struct goober *g)
{
    // We know, somehow, that goober g is actually a hoover
    struct hoover temp;
    copyTo((char *) &temp, (char *)g, sizeof(struct hoover));
    temp.c = 6;
    copyTo((char *) g, (char *) &temp, sizeof(struct hoover));
}

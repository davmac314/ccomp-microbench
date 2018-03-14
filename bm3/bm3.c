/* #include <cstring> */
#include <string.h>
#include "strucs.h"

/*
 This is a modification of the bm2 test.
 
 The "struct hoover" struct is smaller. This seems to allow some compilers
 to optimize better; possibly loop unrolling is involved.
*/
 
#if 0
/* If we use this, most compilers seem to suffer. */
/* just a utility */
static void copyTo(char *dest, char *src, int size)
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

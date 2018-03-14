/*
 Test whether the compiler recognizes a memcpy operation and produces
 efficient code for it.
 
 From my observations, gcc 4.4.0/4.3.0 do very well, especially with
 -march=core2 on a core2 processor. gcc-3.4.6 and llvm-2.5-gcc-4.2
 are more than 4 times slower.
*/

void memcopy(char * restrict dest, char * restrict src, int size)
{
    while (size-- != 0) {
        *dest++ = *src++;
    }
}

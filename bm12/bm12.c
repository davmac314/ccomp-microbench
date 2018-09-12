#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

// bm12: test compiler's ability to recognize and optimise overflow checks.
// Since signed integer overflow is undefined behaviour in C, overflow
// checks need to be done before the addition that might actually overflow.
// The check is somewhat complex: see would_overflow below.

// No compiler that I've tested produces very good code (an efficient
// assembly version is shown below and performs around 20-25% faster
// than compiler-produced code, as well as being much more smaller). 

// Test if addition would overflow. This is actually quite trikcy in C:
static bool would_overflow(int a, int b)
{
    if (b >= 0) {
        if (INT_MAX - b < a) {
            // addition would overflow
            return true;
        }
    }
    else {
        if (INT_MIN - b > a) {
            // would negative overflow
            return true;
        }
    
    }
    return false;
}

int addf(int a, int b, int c, int d, int e, int f)
{
    if (would_overflow(a, b)) return 0;
    a += b;
    
    if (would_overflow(a, c)) return 0;
    a += c;
    
    if (would_overflow(a, d)) return 0;
    a += d;
    
    if (would_overflow(a, e)) return 0;
    a += e;

    if (would_overflow(a, f)) return 0;
    a += f;
    
    return a;
}

// An efficient assembly version of the above:
/*
int addf_asm(int a, int b, int c, int d, int e, int f)
{
    int zero = 0;
    int m_one = -1; // 111111...1b
    __asm__ (
        "addl %1, %0"   "\n\t"
        "cmovol %6, %7" "\n\t"
        "addl %2, %0"   "\n\t"
        "cmovol %6, %7" "\n\t"
        "addl %3, %0"   "\n\t"
        "cmovol %6, %7" "\n\t"
        "addl %4, %0"   "\n\t"
        "cmovol %6, %7" "\n\t"
        "addl %5, %0"   "\n\t"        
        "cmovol %6, %7" "\n\t"
        "andl %7, %0"
        : "+r"(a)
        : "rm"(b), "rm"(c), "rm"(d), "rm"(e), "rm"(f),
          "r"(zero), "rm"(m_one)
    );
    return a;
}
*/

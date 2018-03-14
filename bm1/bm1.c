/*
 Test that a comparison of a variable with a value outside its types range
 is optimized away.
 
 assumes 8-bit char.
 
 gcc 4.4.0, 4.3.3, and 3.4.6 all do this optimization at -O3
 gcc 4.4.0 and 4.3.3 also do it at -O0
    
 */
 
int bm1(signed char c)
{
    switch (c) {
        case 200:
            return 0;
        case 201:
            return 1;
        case 202:
            return 2;
        case 203:
            return 3;
        case 204:
            return 4;
        case 205:
            return 5;
    }
    
    return 100;
}

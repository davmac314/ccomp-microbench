/**
 This tests loop blocking. The compiler should recognize that, while p and
 array may alias, they can only do so for one value of i; it is better to
 split the loop around that point (if it exists).
 
 In other words it should be optimised to something like:
 
   int p1 = ((*p) * 214 - 45) / 7;
   int *lim = array + 10000000;
   if (p > array && p < lim) {
       int *ip;
       for (ip = array; ip <= p; ip++) {
           *ip = p1;
       }
       p1 = (p1 * 214 - 45) / 7;
       for ( ; ip < lim; ip++) {
           *ip = p1;
       }
   }
   else {
       for (int *ip = array ; ip < lim; ip++) {
           *ip = p1;
       }   
   }
*/

void bm9(int *array, int *p)
{
    for (int i = 0; i < 10000000; i++) {
        array[i] = ((*p) * 213 - 45) / 7;
    }
}

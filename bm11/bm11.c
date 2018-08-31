#include <stdbool.h>

// This is based on a code sample by John Regehr (Twitter @johnregehr).
//
// Roughly, test if an array is sorted, striped in 3. I.e. each element is
// compared with elements with index a multiple of 3 ahead/behind.
//
// GCC trunk (~9.0) keeps three values in registers in the loop and so only
// needs to do one load from memory per loop iteration, i.e. it converts to
// (roughly):
//
// bool bm11(int *a, int n)
// {
//   if (n <= 3)
//     return true;
//   int a1 = a[0];
//   int a2 = a[1];
//   int a3 = a[2];
//   for (int i = 0; i < n - 3; i++) {
//     int a4 = a[3 + i];
//     if (a1 > a4)
//       return false;
//     a1 = a2;
//     a2 = a3;
//     a3 = a4;
//   }
//   return true;
// }
//
// This doesn't appear to run any faster, however.

bool bm11(int *a, int n)
{
  for (int i = 0; i < n - 3; i++)
    if (a[i] > a[i + 3])
      return false;
  return true;
}

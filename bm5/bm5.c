/**
 This comes from gcc PR 21485 (marked as a 4.3/4.4/4.5 regression).
 */

void 
NumSift (long *array, unsigned long i, unsigned long j) 
{ 
  unsigned long k; 
  long temp; 
  while ((i + i) <= j) 
    { 
      k = i + i; 
      if (k < j) 
        if (array[k] < array[k + 1L]) 
          ++k; 
      if (array[i] < array[k]) 
        { 
          temp = array[k]; 
          array[k] = array[i]; 
          array[i] = temp; 
          i = k; 
        } 
      else 
        i = j + 1; 
    } 
  return; 
} 

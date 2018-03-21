/**
 Test from gcc PR: http://gcc.gnu.org/bugzilla/show_bug.cgi?id=32306
 Still open as of 201803
 Essentially testing common subexpression elimination. The array
 elements 0 .. 10 will be set to the same value; can the compiler
 recognize this?
*/

int foo(int);

static short int b1;
static short int b2;
static short int b3;
static short int b4;
static short int b5;
static short int b6;
static short int b7;
static short int b8;
static short int b9;
static short int b10;
static short int b11;
static short int b12;

short array[11];

void bm6(void)
{

  b1  = foo(1);
  b2  = foo(1);
  b3  = foo(1);
  b4  = foo(1);
  b5  = foo(1);
  b6  = foo(1);
  b7  = foo(1);
  b8  = foo(1);
  b9  = foo(1);
  b10 = foo(1);
  b11 = foo(1);
  b12 = foo(1);

  array[0]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[1]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[2]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[3]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[4]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[5]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[6]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[7]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[8]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;     
  array[9]  = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;
  array[10] = b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9 && b10 && b11
&& b12;

  return;
}

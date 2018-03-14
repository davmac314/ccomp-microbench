/**
 Test removal of trivial loops.
 */

int bm8() {
  int loop = 1000000000;
  int timeout;

timeoutloop:
  timeout = 2000;
loopto:
  if (--timeout == 0) goto timeoutloop;
  if (--loop != 0) goto loopto;

  return timeout;
}

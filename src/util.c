#include "./util.h"
void *checked_malloc(int size) {
  int *p = malloc(size);
  assert(p);
  return p;
}

int max(int a, int b) { return (a < b) ? b : a; }


/* util.h */
#include <assert.h>
#include <stdlib.h>

#ifndef UTILS
#define UTILS
typedef char *string;
string String(char *);

typedef char bool;
#define TRUE 1
#define FALSE 0

void *checked_malloc(int);

int max(int a, int b);
#endif

#include "../src/types.h"

#ifndef TABLE
#define TABLE

typedef struct table *Table_;

struct table {
  string id;
  int value;
  Table_ tail;
};

struct IntAndTable {
  int i;
  Table_ t;
};

Table_ Table(string id, int value, struct table *tail);

#endif

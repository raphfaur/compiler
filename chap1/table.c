#include "table.h"
Table_ Table(string id, int value, struct table *tail) {
  Table_ t = checked_malloc(sizeof(*t));
  t->tail = tail;
  t->id = id;
  t->value = value;
  return t;
}

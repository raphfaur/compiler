#include "./table.h"


void interp(A_stm);

int lookup(Table_ t, string key);

struct IntAndTable interpExp(A_exp exp, Table_ t);
Table_ interpStm(A_stm, Table_);



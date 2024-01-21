#include "./interpr.h"
#include <stdio.h>

void interp(A_stm prog) {
  Table_ init_table = NULL;
  interpStm(prog, init_table);
}

Table_ interpStm(A_stm stm, Table_ t) {
  switch (stm->kind) {
  case A_compoundStm: {
    // printf("Interpreting coumpound\n");
    Table_ r_table = interpStm(stm->u.compound.stm1, t);
    return interpStm(stm->u.compound.stm2, r_table);
    break;
  }
  case A_assignStm: {
    // printf("Interpreting Assign\n");
    struct IntAndTable exp_result = interpExp(stm->u.assign.exp, t);
    Table_ assigned_t = Table(stm->u.assign.id, exp_result.i, t);
    assigned_t->tail = t;
    // printf("a = %i, exp_result = %i", lookup(assigned_t, "a"), exp_result.i);
    return assigned_t;
    break;
  }
  case A_printStm: {
    // printf("Interpreting print\n");
    A_expList cursor = stm->u.exps;
    while (cursor->kind == A_pairExpList) {
      struct IntAndTable exp_res = interpExp(cursor->u.pair.head, t);
      printf("%i ", exp_res.i);
      cursor = cursor->u.pair.tail;
    }
    struct IntAndTable exp_res = interpExp(cursor->u.last, t);
    printf("%i", exp_res.i);
    printf("\n");
    return t;
    break;
  } break;
  }
}
struct IntAndTable interpExp(A_exp exp, Table_ t) {
  switch (exp->kind) {
  case A_idExp: {
    // printf("Interpreting id\n");
    int value = lookup(t, exp->u.id);
    struct IntAndTable result = {.i = value, .t = t};
    return result;
    break;
  }
  case A_numExp: {
    // printf("Interpreting num\n");
    struct IntAndTable result;
    result.i = exp->u.num;
    result.t = t;
    return result;
    break;
  }
  case A_opExp: {
    // printf("Interpreting Op\n");
    struct IntAndTable l = interpExp(exp->u.op.left, t);
    struct IntAndTable r = interpExp(exp->u.op.right, l.t);
    int value;
    switch (exp->u.op.oper) {

    case A_plus: {
      // printf("Computing %i + %i", l.i, r.i);
      value = l.i + r.i;
      break;
    }
    case A_minus: {
      value = l.i - r.i;
      break;
    }
    case A_times: {
      value = l.i * r.i;
      break;
    }
    case A_div: {
      value = l.i / r.i;
      break;
    } break;
    }
    struct IntAndTable result;
    result.t = r.t;
    result.i = value;
    // printf("Op IntAndTable has i = %i", result.i);
    return result;
    break;
  }
  case A_eseqExp: {
    // printf("Interpreting asseq\n");
    Table_ new_t = interpStm(exp->u.eseq.stm, t);
    struct IntAndTable table = interpExp(exp->u.eseq.exp, new_t);
    return table;
    break;
  } break;
  }
}

int lookup(Table_ t, string key) {
  Table_ cursor = t;
  while (cursor->id != key) {
    cursor = cursor->tail;
  }
  return cursor->value;
}

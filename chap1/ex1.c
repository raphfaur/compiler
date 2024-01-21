#include "./ex1.h"

int maxarg_exp(A_exp);
int list_size(A_expList);
int maxargs_rec(A_stm);
int maxarg_list(A_expList);

int maxargs(A_stm stm) { return maxargs_rec(stm); }

int maxargs_rec(A_stm stm) {
  if (stm->kind == A_assignStm) {
    return maxarg_exp(stm->u.assign.exp);
  } else if (stm->kind == A_compoundStm) {
    return max(maxargs_rec(stm->u.compound.stm1),
               maxargs_rec(stm->u.compound.stm2));
  }
  {
    int arg_c = list_size(stm->u.exps);
    return max(arg_c, maxarg_list(stm->u.exps));
  }
}

int maxarg_list(A_expList list) {
  if (list->kind == A_pairExpList) {
    return max(maxarg_list(list->u.pair.tail), maxarg_exp(list->u.pair.head));
  } else {
    return maxarg_exp(list->u.last);
  }
}

int maxarg_exp(A_exp exp) {
  switch (exp->kind) {
  case A_idExp:
    return 1;
    break;
  case A_numExp:
    return 1;
    break;
  case A_opExp: {
    int r_arg_c = maxarg_exp(exp->u.op.right);
    int l_arg_c = maxarg_exp(exp->u.op.left);
    return max(r_arg_c, l_arg_c);
    break;
  }
  case A_eseqExp:
    return max(maxarg_exp(exp->u.eseq.exp), maxargs(exp->u.eseq.stm));
    break;
  }
}

int list_size(A_expList list) {
  if (list->kind == A_pairExpList) {
    return 1 + list_size(list->u.pair.tail);
  } else {
    return 1;
  }
}

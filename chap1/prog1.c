#include "./prog1.h"

A_stm prog(void) {
  return A_CompoundStm(
      A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
      A_CompoundStm(
          A_AssignStm("b",
                      A_EseqExp(A_PrintStm(A_PairExpList(
                                    A_IdExp("a"),
                                    A_LastExpList(A_OpExp(A_IdExp("a"), A_minus,
                                                          A_NumExp(1))))),
                                A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
          A_PrintStm(A_LastExpList(A_IdExp("b")))));
}

A_stm prog_test3(void) {
  return A_CompoundStm(
      A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
      A_CompoundStm(
          A_AssignStm(
              "b",
              A_EseqExp(
                  A_PrintStm(A_PairExpList(
                      A_IdExp("a"),
                      A_PairExpList(
                          A_EseqExp(
                              A_PrintStm(A_PairExpList(
                                  A_IdExp("a"),
                                  A_PairExpList(
                                      A_IdExp("a"),
                                      A_PairExpList(
                                          A_NumExp(100),
                                          A_PairExpList(
                                              A_NumExp(200),
                                              A_LastExpList(A_NumExp(300))))))),
                              A_NumExp(100)),
                          A_LastExpList(
                              A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1)))))),
                  A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
          A_PrintStm(A_LastExpList(A_IdExp("b")))));
}

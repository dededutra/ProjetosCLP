ackermann(M, N, 0, Result) :-
    Result is M + N.
ackermann(_, _, 1, 0).
ackermann(_, _, 2, 1).
ackermann(M, _, 3, M).
ackermann(M, 0, P, Result) :-
    P > 2,
    P1 is P - 1,
    ackermann(M, 0, P1, Result).
ackermann(M, N, P, Result) :-
    N > 0,
    P > 0,
    N1 is N - 1,
    P1 is P - 1,
    ackermann(M, N1, P, TempResult),
    ackermann(M, TempResult, P1, Result).

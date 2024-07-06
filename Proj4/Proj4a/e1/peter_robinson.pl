peter_robinson(0, N, Result) :-
    Result is N + 1.
peter_robinson(M, 0, Result) :-
    M > 0,
    M1 is M - 1,
    peter_robinson(M1, 1, Result).
peter_robinson(M, N, Result) :-
    M > 0,
    N > 0,
    M1 is M - 1,
    N1 is N - 1,
    peter_robinson(M, N1, TempResult),
    peter_robinson(M1, TempResult, Result).

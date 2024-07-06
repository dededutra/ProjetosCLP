:- use_module(library(clpfd)).
:- use_module(library(statistics)).
main :-
    find_max_n(4, 20000, MaxN),
    format('Maior tamanho de permutação calculado em menos de 1 minuto: ~d~n', [MaxN]),
    halt.
find_max_n(Lower, Upper, MaxN) :-
    find_max_n_helper(Lower, Upper, -1, MaxN).

find_max_n_helper(Current, Upper, MaxSoFar, MaxN) :-
    Current =< Upper,  
    ( test_permutation(Current) ->
        format('Permutação de tamanho ~d calculada com sucesso~n', [Current]),
        NewMaxSoFar is Current
    ;
        NewMaxSoFar = MaxSoFar
    ),
    Next is Current + 1,
    ( call_with_time_limit(60, find_max_n_helper(Next, Upper, NewMaxSoFar, MaxN))
    ;   MaxN = MaxSoFar
    ).

test_permutation(N) :-
    solve_permutation(N).

solve_permutation(N) :-
    findall(X, between(1, N, X), List),
    perm(List, _).

perm([], []).
perm(L, [H|T]) :-
    select(H, L, R),
    perm(R, T).

:- initialization(main).

:- use_module(library(clpfd)).
:- use_module(library(statistics)).

main :-
    find_max_n(1, 30, MaxN),
    format('Maior tamanho de latin square calculado em menos de 1 minuto: ~d~n', [MaxN]),
    halt.

find_max_n(Lower, Upper, MaxN) :-
    find_max_n_helper(Lower, Upper, -1, MaxN).

find_max_n_helper(Current, Upper, MaxSoFar, MaxN) :-
    ( Current > Upper ->
        MaxN = MaxSoFar
    ; 
        ( test_latin_square(Current) ->
            format('Latin square de tamanho ~d calculado com sucesso~n', [Current]),
            NewMaxSoFar is Current
        ;
            NewMaxSoFar = MaxSoFar
        ),
        Next is Current + 1,
        find_max_n_helper(Next, Upper, NewMaxSoFar, MaxN)
    ).

test_latin_square(N) :-
    catch(call_with_time_limit(60, solve_latin_square(N)), time_limit_exceeded, fail).

solve_latin_square(N) :-
    latin_square(N, Square),
    print_square(Square).

latin_square(N, Square) :-
    length(Square, N),
    maplist(same_length(Square), Square),
    append(Square, Vars),
    Vars ins 1..N,
    maplist(all_distinct, Square),
    transpose(Square, Columns),
    maplist(all_distinct, Columns),
    maplist(label, Square).

print_square([]).
print_square([Row|Rows]) :-
    writeln(Row),
    print_square(Rows).

:- initialization(main).

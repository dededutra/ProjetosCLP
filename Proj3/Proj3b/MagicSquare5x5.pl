:- use_module(library(clpfd)).

magic-square(A11, A12, A13, A14, A15,
   A21, A22, A23, A24, A25,
   A31, A32, A33, A34, A35,
   A41, A42, A43, A44, A45,
   A51, A52, A53, A54, A55) :-
    
    Square = [A11, A12, A13, A14, A15,
              A21, A22, A23, A24, A25,
              A31, A32, A33, A34, A35,
              A41, A42, A43, A44, A45,
              A51, A52, A53, A54, A55],
    
    Square ins 1..25,
    all_distinct(Square),
    Sum #= A11 + A12 + A13 + A14 + A15,
    A21 + A22 + A23 + A24 + A25 #= Sum,
    A31 + A32 + A33 + A34 + A35 #= Sum,
    A41 + A42 + A43 + A44 + A45 #= Sum,
    A51 + A52 + A53 + A54 + A55 #= Sum,
    A11 + A21 + A31 + A41 + A51 #= Sum,
    A12 + A22 + A32 + A42 + A52 #= Sum,
    A13 + A23 + A33 + A43 + A53 #= Sum,
    A14 + A24 + A34 + A44 + A54 #= Sum,
    A15 + A25 + A35 + A45 + A55 #= Sum,
    A11 + A22 + A33 + A44 + A55 #= Sum,
    A15 + A24 + A33 + A42 + A51 #= Sum,

    label(Square).

all_distinct([]).
all_distinct([H|T]) :-
    \+ member(H, T),
    all_distinct(T).

test(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y) :-
    get_time(T1),
    magic-square(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y),
    get_time(T2),
    Time is T2 - T1, 
    format('Tempo para magic square : ~w segundos.~n', [Time]),
    Time < 60.

% Exemplo de uso
:- initialization(main).
main :-
    test(A11, A12, A13, A14, A15,
            A21, A22, A23, A24, A25,
            A31, A32, A33, A34, A35,
            A41, A42, A43, A44, A45,
            A51, A52, A53, A54, A55),
    format('~d ~d ~d ~d ~d\n', [A11, A12, A13, A14, A15]),
    format('~d ~d ~d ~d ~d\n', [A21, A22, A23, A24, A25]),
    format('~d ~d ~d ~d ~d\n', [A31, A32, A33, A34, A35]),
    format('~d ~d ~d ~d ~d\n', [A41, A42, A43, A44, A45]),
    format('~d ~d ~d ~d ~d\n', [A51, A52, A53, A54, A55]),
    halt.

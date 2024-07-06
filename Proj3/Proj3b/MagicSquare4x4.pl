:- use_module(library(clpfd)).

magic_square(Square) :-
    Square = [A11,A12,A13,A14,
            A21,A22,A23,A24,
            A31,A32,A33,A34,
            A41,A42,A43,A44],

    Square ins 1..16,
    all_different(Square),

    A11 + A12 + A13 + A14 #= 34,
    A21 + A22 + A23 + A24 #= 34,
    A31 + A32 + A33 + A34 #= 34,
    A41 + A42 + A43 + A44 #= 34,
    A11 + A21 + A31 + A41 #= 34,
    A12 + A22 + A32 + A42 #= 34,
    A13 + A23 + A33 + A43 #= 34,
    A14 + A24 + A34 + A44 #= 34,
    A11 + A22 + A33 + A44 #= 34,
    A14 + A23 + A32 + A41 #= 34,

    label(Square).

:- initialization(main).
main :-
    magic_square(Square),
    format('~d ~d ~d ~d\n', [A11,A12,A13,A14]),
    format('~d ~d ~d ~d\n', [A21,A22,A23,A24]),
    format('~d ~d ~d ~d\n', [A31,A32,A33,A34]),
    format('~d ~d ~d ~d\n', [A41,A42,A43,A44]),
    halt.
s

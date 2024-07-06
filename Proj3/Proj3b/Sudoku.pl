:- use_module(library(clpfd)).

sudoku(A11, A12, A13, A14, A15, A16, A17, A18, A19,
       A21, A22, A23, A24, A25, A26, A27, A28, A29,
       A31, A32, A33, A34, A35, A36, A37, A38, A39,
       A41, A42, A43, A44, A45, A46, A47, A48, A49,
       A51, A52, A53, A54, A55, A56, A57, A58, A59,
       A61, A62, A63, A64, A65, A66, A67, A68, A69,
       A71, A72, A73, A74, A75, A76, A77, A78, A79,
       A81, A82, A83, A84, A85, A86, A87, A88, A89,
       A91, A92, A93, A94, A95, A96, A97, A98, A99) :-
    
    Sudoku = [A11, A12, A13, A14, A15, A16, A17, A18, A19,
              A21, A22, A23, A24, A25, A26, A27, A28, A29,
              A31, A32, A33, A34, A35, A36, A37, A38, A39,
              A41, A42, A43, A44, A45, A46, A47, A48, A49,
              A51, A52, A53, A54, A55, A56, A57, A58, A59,
              A61, A62, A63, A64, A65, A66, A67, A68, A69,
              A71, A72, A73, A74, A75, A76, A77, A78, A79,
              A81, A82, A83, A84, A85, A86, A87, A88, A89,
              A91, A92, A93, A94, A95, A96, A97, A98, A99],
    Sudoku ins 1..9,

    all_distinct([A11, A12, A13, A14, A15, A16, A17, A18, A19]),
    all_distinct([A21, A22, A23, A24, A25, A26, A27, A28, A29]),
    all_distinct([A31, A32, A33, A34, A35, A36, A37, A38, A39]),
    all_distinct([A41, A42, A43, A44, A45, A46, A47, A48, A49]),
    all_distinct([A51, A52, A53, A54, A55, A56, A57, A58, A59]),
    all_distinct([A61, A62, A63, A64, A65, A66, A67, A68, A69]),
    all_distinct([A71, A72, A73, A74, A75, A76, A77, A78, A79]),
    all_distinct([A81, A82, A83, A84, A85, A86, A87, A88, A89]),
    all_distinct([A91, A92, A93, A94, A95, A96, A97, A98, A99]),
    all_distinct([A11, A21, A31, A41, A51, A61, A71, A81, A91]),
    all_distinct([A12, A22, A32, A42, A52, A62, A72, A82, A92]),
    all_distinct([A13, A23, A33, A43, A53, A63, A73, A83, A93]),
    all_distinct([A14, A24, A34, A44, A54, A64, A74, A84, A94]),
    all_distinct([A15, A25, A35, A45, A55, A65, A75, A85, A95]),
    all_distinct([A16, A26, A36, A46, A56, A66, A76, A86, A96]),
    all_distinct([A17, A27, A37, A47, A57, A67, A77, A87, A97]),
    all_distinct([A18, A28, A38, A48, A58, A68, A78, A88, A98]),
    all_distinct([A19, A29, A39, A49, A59, A69, A79, A89, A99]),
    all_distinct([A11, A12, A13, A21, A22, A23, A31, A32, A33]),
    all_distinct([A14, A15, A16, A24, A25, A26, A34, A35, A36]),
    all_distinct([A17, A18, A19, A27, A28, A29, A37, A38, A39]),
    all_distinct([A41, A42, A43, A51, A52, A53, A61, A62, A63]),
    all_distinct([A44, A45, A46, A54, A55, A56, A64, A65, A66]),
    all_distinct([A47, A48, A49, A57, A58, A59, A67, A68, A69]),
    all_distinct([A71, A72, A73, A81, A82, A83, A91, A92, A93]),
    all_distinct([A74, A75, A76, A84, A85, A86, A94, A95, A96]),
    all_distinct([A77, A78, A79, A87, A88, A89, A97, A98, A99]),

    label(Sudoku).

test(A11, A12, A13, A14, A15, A16, A17, A18, A19,
            A21, A22, A23, A24, A25, A26, A27, A28, A29,
            A31, A32, A33, A34, A35, A36, A37, A38, A39,
            A41, A42, A43, A44, A45, A46, A47, A48, A49,
            A51, A52, A53, A54, A55, A56, A57, A58, A59,
            A61, A62, A63, A64, A65, A66, A67, A68, A69,
            A71, A72, A73, A74, A75, A76, A77, A78, A79,
            A81, A82, A83, A84, A85, A86, A87, A88, A89,
            A91, A92, A93, A94, A95, A96, A97, A98, A99) :-
    get_time(T1),
    sudoku(A11, A12, A13, A14, A15, A16, A17, A18, A19,
           A21, A22, A23, A24, A25, A26, A27, A28, A29,
           A31, A32, A33, A34, A35, A36, A37, A38, A39,
           A41, A42, A43, A44, A45, A46, A47, A48, A49,
           A51, A52, A53, A54, A55, A56, A57, A58, A59,
           A61, A62, A63, A64, A65, A66, A67, A68, A69,
           A71, A72, A73, A74, A75, A76, A77, A78, A79,
           A81, A82, A83, A84, A85, A86, A87, A88, A89,
           A91, A92, A93, A94, A95, A96, A97, A98, A99),
    get_time(T2),
    Time is T2 - T1,
    format('Tempo para resolver o Sudoku: ~3f segundos.~n', [Time]).

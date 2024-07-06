factorial(1, 1).
factorial(Number, Result) :- 
    Number > 1, 
    PreviousNumber is Number - 1, 
    factorial(PreviousNumber, PreviousResult), 
    Result is Number * PreviousResult.

test_factorial(Number) :-
    get_time(StartTime),
    factorial(Number, _),
    get_time(EndTime),
    ExecutionTime is EndTime - StartTime,
    format('~w! : ~ws~n', [Number, ExecutionTime]),
    ExecutionTime < 59.

loop_factorial(CurrentNumber) :-
    test_factorial(CurrentNumber),
    NextNumber is CurrentNumber + 1,
    loop_factorial(NextNumber).

loop_factorial(CurrentNumber) :-
    \+ test_factorial(CurrentNumber).

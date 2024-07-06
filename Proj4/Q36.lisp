(defun fat (n)
  "Calcula o fatorial de n."
  (cond
    ((< n 0) nil)          ; Retorna nil se n for negativo
    ((zerop n) 1)          ; Retorna 1 se n for zero
    (t (* n (fat (- n 1)))) ; Calcula o fatorial de n recursivamente
  )
)

(defun fibo (n)
  "Calcula o n-ésimo número de Fibonacci."
  (cond
    ((< n 1) nil)          ; Retorna nil se n for menor que 1
    ((< n 3) 1)            ; Retorna 1 se n for 1 ou 2
    (t (+ (fibo (- n 1))   ; Calcula o número de Fibonacci de n-1
          (fibo (- n 2)))) ; Calcula o número de Fibonacci de n-2 e soma
  )
)

(defun G (n)
  "Calcula a função G(n) conforme definido."
  (cond
    ((< n 1) nil)                                ; Retorna nil se n for menor que 1
    ((eql n 1) 1)                                ; Retorna 1 se n for igual a 1
    ((eql (mod n 2) 0)                           ; Se n for par
     (- (G (- n 1)) (/ n (fat (fibo n)))))       ; Calcula o termo negativo da função G
    (t                                            ; Se n for ímpar
     (+ (G (- n 1)) (/ n (fat (fibo n))))))      ; Calcula o termo positivo da função G
)

(print (G 5)) ; Imprime o resultado da função G para n = 5


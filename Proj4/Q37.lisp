(defun fibo (n)
  "Calcula o n-ésimo número de Fibonacci."
  (cond
    ((< n 1) nil)          ; Retorna nil se n for menor que 1
    ((< n 3) 1)            ; Retorna 1 se n for 1 ou 2
    (t (+ (fibo (- n 1))   ; Calcula o número de Fibonacci de n-1
          (fibo (- n 2)))) ; Calcula o número de Fibonacci de n-2 e soma
  )
)

(defun ProdFibonacci (n)
  "Calcula o produto dos n primeiros números de Fibonacci."
  (cond
    ((< n 1) nil)                        ; Retorna nil se n for menor que 1
    ((< n 3) 1)                          ; Retorna 1 se n for 1 ou 2
    (t (* (fibo n)                       ; Calcula o número de Fibonacci de n
          (ProdFibonacci (- n 1))))       ; Calcula o produto dos n-1 primeiros números de Fibonacci e multiplica
  )
)

(print (ProdFibonacci 5)) ; Imprime o resultado do produto dos 5 primeiros números de Fibonacci


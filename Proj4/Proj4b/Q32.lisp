;; Função para calcular o fatorial de um número não negativo n
(defun fat (n)
  (cond
    ((< n 0) nil)         ; Retorna nil se n for negativo
    ((zerop n) 1)         ; Retorna 1 se n for zero
    (t (* n (fat (- n 1)))))) ; Calcula n * (n-1) * ... * 1 recursivamente

;; Função para calcular a potência de b elevado a e (b^e)
(defun poten (b e)
  (cond
    ((< e 0) nil)         ; Retorna nil se e for negativo
    ((zerop e) 1)         ; Retorna 1 se e for zero
    (t (* b (poten b (- e 1)))))) ; Calcula b * b^(e-1) recursivamente

;; Função para calcular a série exponencial modificada
(defun exem (x n)
  (cond
    ((< n 0) nil)                         ; Retorna nil se n for negativo
    ((zerop n) 1)                         ; Retorna 1 se n for zero
    (t (+ (/ (poten x n) (fat n))         ; Calcula x^n / n!
           (exem x (- n 1))))))           ; Chama a função recursivamente para n-1

;; Imprime o resultado da série exponencial modificada para x=2 e n=4
(format t "Para n=4 e x=2: ~d~%" (exem 2 4))


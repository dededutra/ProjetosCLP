(defun raiz (a n)
  "Calcula a raiz n-ésima de a.
   Retorna nil se n for negativo, 1 se n for zero.
   Utiliza um método iterativo para aproximação da raiz."
  (cond
    ((< n 0) nil)                         ; Retorna nil se n for negativo
    ((zerop n) 1)                         ; Retorna 1 se n for zero
    (t (/ (+ (raiz a (- n 1))             ; Soma a raiz (n-1) de a
            (/ 3 (raiz a (- n 1))))        ; Adiciona 3 dividido pela raiz (n-1) de a
          2))))                            ; Divide o resultado por 2 para obter a raiz n-ésima de a


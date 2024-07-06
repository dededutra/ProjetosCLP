(defun seriePI (n)
  "Calcula uma série para aproximar o valor de π.
   Retorna nil se n for menor que 1.
   Retorna 4 se n for igual a 1.
   Utiliza uma série alternada para calcular π."
  (cond
    ((< n 1) nil)                              ; Retorna nil se n for menor que 1
    ((eql n 1) 4)                              ; Retorna 4 se n for igual a 1
    ((eql (mod n 2) 0)                         ; Se n for par
     (- (seriePI (- n 1)) (/ 4 (- (* n 2) 1)))) ; Calcula o termo negativo da série
    (t                                          ; Se n for ímpar
     (+ (seriePI (- n 1)) (/ 4 (- (* n 2) 1)))) ; Calcula o termo positivo da série
)


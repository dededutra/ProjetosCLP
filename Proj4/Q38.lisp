(defun fat (n)
  "Calcula o fatorial de n."
  (cond
    ((< n 0) nil)           ; Retorna nil se n for negativo
    ((zerop n) 1)           ; Retorna 1 se n for zero
    (t (* n (fat (- n 1)))) ; Calcula n * (n-1)! recursivamente
  )
)

(defun potencia (b e)
  "Calcula a potência de b elevado a e."
  (cond
    ((< e 0) nil)           ; Retorna nil se e for negativo
    ((zerop e) 1)           ; Retorna 1 se e for zero
    (t (* b (potencia b (- e 1)))) ; Calcula b * b^(e-1) recursivamente
  )
)

(defun H (n)
  "Calcula a sequência H de n."
  (cond
    ((< n 1) nil)                       ; Retorna nil se n for menor que 1
    ((eql n 1) 1)                       ; Retorna 1 se n for 1
    ((eql (mod n 2) 0)                  ; Se n é par
     (- (H (- n 1)) (/ (potencia n n) (fat n)))) ; Calcula H(n-1) - n^n / n!
    (t                                   ; Se n é ímpar
     (+ (H (- n 1)) (/ (potencia n n) (fat n)))) ; Calcula H(n-1) + n^n / n!
  )
)

(print (H 7)) ; Imprime o resultado de H(7)


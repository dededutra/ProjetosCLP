(defun fat (n)
  (cond
    ((< n 0) nil)           
    ((zerop n) 1)           
    (t (* n (fat (- n 1)))) 
  )
)

(defun potencia (b e)
  (cond
    ((< e 0) nil)           
    ((zerop e) 1)         
    (t (* b (potencia b (- e 1)))) 
  )
)

(defun H (n)
  (cond
    ((< n 1) nil)                       
    ((eql n 1) 1)                      
    ((eql (mod n 2) 0)
     (- (H (- n 1)) (/ (potencia n n) (fat n)))) 
    (t                                   
     (+ (H (- n 1)) (/ (potencia n n) (fat n)))) 
  )
)

(print (H 7))


(defun fat (n)
  (cond
    ((< n 0) nil)          
    ((zerop n) 1)          
    (t (* n (fat (- n 1)))) 
  )
)

(defun fibo (n)
  (cond
    ((< n 1) nil)          
    ((< n 3) 1)            
    (t (+ (fibo (- n 1))   
          (fibo (- n 2)))) 
  )
)

(defun G (n)
  (cond
    ((< n 1) nil)                                
    ((eql n 1) 1)                                
    ((eql (mod n 2) 0)                           
     (- (G (- n 1)) (/ n (fat (fibo n)))))       
    (t                                           
     (+ (G (- n 1)) (/ n (fat (fibo n))))))      
)

(print (G 5)) 


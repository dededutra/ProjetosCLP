(defun fibo (n)
  (cond
    ((< n 1) nil)          
    ((< n 3) 1)            
    (t (+ (fibo (- n 1))   
          (fibo (- n 2)))) 
  )
)

(defun ProdFibonacci (n)
  (cond
    ((< n 1) nil)                       
    ((< n 3) 1)                       
    (t (* (fibo n)                       
          (ProdFibonacci (- n 1))))      
  )
)

(print (ProdFibonacci 5)) 


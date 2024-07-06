
(defun fat (n)
  (cond
    ((< n 0) nil)         
    ((zerop n) 1)         
    (t (* n (fat (- n 1)))))) 

(defun poten (b e)
  (cond
    ((< e 0) nil)         
    ((zerop e) 1)         
    (t (* b (poten b (- e 1)))))) 
(defun exem (x n)
  (cond
    ((< n 0) nil)                         
    ((zerop n) 1)                         
    (t (+ (/ (poten x n) (fat n))         
           (exem x (- n 1))))))           

(format t "~d~%" (exem 2 4))


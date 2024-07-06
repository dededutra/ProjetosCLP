(defun ackermann (m n p)
  (cond
    ((= p 0) (+ m n))
    ((= p 1) 0)
    ((= p 2) 1)
    ((= p 3) m)
    ((and (> p 2) (= n 0)) (ackermann m 0 (- p 1)))
    (t (ackermann m (ackermann m (- n 1) p) (- p 1)))))

(print (ackermann 2 3 4))

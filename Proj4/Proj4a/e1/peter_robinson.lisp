(defun peter_robinson (m n)
  (cond
    ((= m 0) (+ n 1))
    ((and (> m 0) (= n 0)) (peter_robinson (- m 1) 1))
    (t (peter_robinson (- m 1) (peter_robinson m (- n 1))))))

(print (peter_robinson 2 3))

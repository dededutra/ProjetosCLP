(defun merge-sort (lst)
"Ordena uma lista usando o algoritmo merge sort."
(if (or (null lst) (null (cdr lst)))
    lst
    (let ((mid (truncate (length lst) 2)))
        (merge (merge-sort (subseq lst 0 mid))
            (merge-sort (subseq lst mid))
            #'<))))

(defun merge (l1 l2 pred)
"Mescla duas listas ordenadas em uma única lista ordenada."
(cond ((null l1) l2)
        ((null l2) l1)
        ((funcall pred (car l1) (car l2))
        (cons (car l1) (merge (cdr l1) l2 pred)))
        (t (cons (car l2) (merge l1 (cdr l2) pred)))))

(defun ler-lista ()
  (let ((lista ()))
    (format t "Digite os elementos da lista:~%")
    (loop
       (let ((entrada (read-line)))
         (if (string= entrada "")
             (return) ; Encerra o loop se a entrada estiver vazia
             (handler-case
                 (let ((numero (parse-integer entrada)))
                   (push numero lista))
               (parse-error ()
                 (format t "Por favor, digite um número inteiro válido ou aperte Enter para terminar.~%"))))))
    (nreverse lista)))

(progn
(format t "Merge sort: ~a~%" (merge-sort 'ler-lista)))
)

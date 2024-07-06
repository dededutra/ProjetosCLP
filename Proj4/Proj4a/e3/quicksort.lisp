(defun particionar (pivo lista)
(if (null lista)
    (list nil nil)
    (let ((x (car lista))
            (resto (cdr lista)))
        (if (<= x pivo)
            (let ((particao (particionar pivo resto)))
            (list (cons x (car particao))
                    (cadr particao)))
            (let ((particao (particionar pivo resto)))
            (list (car particao)
                    (cons x (cadr particao))))))))

(defun quick-sort (lista)
(if (null lista)
    nil
    (let* ((pivo (car lista))
            (resto (cdr lista))
            (particao (particionar pivo resto)))
        (let ((menor (car particao))
            (maior (cadr particao)))
        (append (quick-sort menor) (list pivo) (quick-sort maior))))))

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
    (format t "~a~%" (quick-sort 'ler-lista))
) 

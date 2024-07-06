(defun trocar (lista)
  (if (null (cdr lista))
      lista
      (if (> (car lista) (cadr lista))
          (cons (cadr lista) (trocar (cons (car lista) (cddr lista))))
          (cons (car lista) (trocar (cdr lista))))))

(defun bubble-sort (lista)
  (if (null lista)
      nil
      (let ((troca (trocar lista)))
        (if (equal lista troca)
            lista
            (bubble-sort troca)))))

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
  (format t "~a~%" (bubble-sort 'ler-lista))
)

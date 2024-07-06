(defun inserir (x lista)
  (if (null lista)
      (list x)
      (if (<= x (car lista))
          (cons x lista)
          (cons (car lista) (inserir x (cdr lista))))))

(defun ordenar-insertion (lista)
  (if (null lista)
      nil
      (inserir (car lista) (ordenar-insertion (cdr lista)))))

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
  (format t "~a~%" (ordenar-insertion 'ler-lista))
)

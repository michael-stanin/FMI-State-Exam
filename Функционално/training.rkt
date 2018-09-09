(define (extract str)
  (substring str 4 7))

;(define pie 3)
(define (piece str)
  (substring str 0 pie))


(define (sum-int a b)
  (if (> a b)
      0
      (+ a (sum-int (+ a 1) b))))

(define (cube x) (* x x x))

; sum-cub does not work if a == b
(define (sum-cub a b)
  (if (> a b)
      0
      (+ (cube a) (sum-cub (+ a 1) b))))

(define (nth n l)
  (if (= n 1) (car l)
      (nth (- n 1) (cdr l))))

(define (mlength l)
  (if (null? l) 0
      (+ 1 (length (cdr l)))))

(define (mappend l1 l2)
  (if (null? l1) l2
      (cons (car l1) (append (cdr l1) l2))))

(define (mmember item l)
  (cond ((null? l) '())
        ((equal? (car l) item) l)
        (else (mmember item (cdr l)))))

(define (mreverse l)
  (if (null? l) '()
      (mappend (mreverse (cdr l))
               (list (car l)))))

; Needs to define empty-stream? probably the other stream related functions as well
; such as the cons-stream<->cons, head<->car, tail<->cdr.
;(define (mappend-stream stream1 stream2)
;  (if (empty-stream? stream1) stream2
;      (cons-stream (head stream1)
;                    (mappend-stream (tail stream1) stream2))))

;(define (mints-from n)
;  (cons-stream n (mints-from (+ 1 n))))

;(define mintergers (mints-from 1))

;(mlength (mappend (list 1 2 3 4)(list 5 6 7 8)))

; *******************************
; September 2016
; *******************************
(define (filterByElement x m)
  (filter (lambda (y) (search x y)) m))

(define (filter pred? l)
  (cond ((empty l) '())
        ((pred? (car l)) (cons (car l) (filter pred? (cdr l))))
        (else (filter pred? (cdr l)))))

(define (empty l) (equal? l '()))

(define (search x xs)
  (cond
    ((empty xs) #f)
    ((equal? x (car xs)) #t)
    (else (search x (cdr xs)))))

; The line below crashes DrRacket...
;(apply + (map (lambda (l) (apply max l)) '((5 -2) (1 9) (6 -8))))
;>20
; *******************************

; *******************************
; July 2016
; *******************************

; The line below crashes DrRacket...
;( map ( lambda (x) (append (list x) x) ) '( (1 2) (3 4) ) )
;>(((1 2) 1 2) ((3 4) 3 4))

; The line below crashes DrRacket...
;(map (lambda (f) (map (lambda (x) (f 5 x)) '(1 2 3))) (list + - *))
;>((6 7 8) (4 3 2) (5 10 15))

;( apply list (list (quote +) (quote 5) 8) )
;>(+ 5 8)
; *******************************

; *******************************
; July 2015
; *******************************

;(map
;    (car ( list (lambda (couple) (+ (car couple) (cdr couple)))))
;    (apply append ' (((1 . 2)) ((3 . 4)))))
;>(3 7)

; The line below crashes DrRacket...
;(map (lambda (x) (cons x (list x)))'(1 2 3 4 5))
;> ((1 1) (2 2) (3 3) (4 4) (5 5))

; The line below crashes DrRacket...
;(map (lambda (pred) (filter pred '(1 2 3 4 5))) (list even? odd?))
;>((2 4) (1 3 5))
; *******************************


; *******************************
; September 2015
; *******************************

(define (merge l1 l2)
  (cond ((null? l1) l2)
        ((null? l2) l1)
        ((< (car l1) (car l2)) (cons (car l1) (merge (cdr l1) l2)))
        (else (cons (car l2) (merge l1 (cdr l2))))))
;(merge '(1 3 5 7) '(2 2 6 10))
;>(1 2 2 3 5 6 7 10)

;((lambda (x) (filter even? x)) '(1 2 3 4))
;>(2 4)
; *******************************

; TODOs
; Implement reduce


(define (bubble-up L)  
   (if (null? (cdr L)) 
       L   
       (if (< (car L) (cadr L))  
           (cons (car L) (bubble-up (cdr L)))  
           (cons (cadr L) (bubble-up (cons (car L) (cddr L)))))))

(define (bubble-sort N L)   
  (cond ((= N 1) (bubble-up L))  
        (else (bubble-sort (- N 1) (bubble-up L)))))

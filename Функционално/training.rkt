;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname training) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(define (extract str)
  (substring str 4 7))

(define pie 3)
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
(define (mappend-stream stream1 stream2)
  (if (empty-stream? stream1) stream2
      (cons-stream (head stream1)
                    (mappend-stream (tail stream1) stream2))))

(define (mints-from n)
  (cons-stream n (mints-from (+ 1 n))))

(define mintergers (mints-from 1))

(mlength (mappend (list 1 2 3 4)(list 5 6 7 8)))
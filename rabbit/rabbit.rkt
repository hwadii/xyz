#lang racket

(require racket/random)

(define (make-new a b)
  (floor (/ (+ a b) 2)))
(define (hop n)
  (+ n (car (random-sample '(-1 1) 1))))

(define (bsearch a b to-find [guess (make-new a b)] [tries 0])
  (if (= to-find guess)
      (hash 'guess guess 'tries tries)
      (cond
        [(< guess to-find) (bsearch guess b (hop to-find) (make-new guess b) (add1 tries))]
        [else (bsearch a guess (hop to-find) (make-new a guess) (add1 tries))])))

(let ([to-find (random 0 100)]) (bsearch 0 100 to-find (make-new 0 100)))

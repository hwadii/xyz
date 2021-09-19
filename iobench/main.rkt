#lang racket

(require racket/math)

(define grid (string-split (port->string (open-input-file "./small-letters.txt")) "\n"))
(define mask (string-split (port->string (open-input-file "./small-mask.txt")) "\n"))
#| (define ref (string-normalize-spaces (port->string (open-input-file "ref.txt")))) |#

; Return a list of pairs
(define (ranges max-nr by)
  (let ([step (/ max-nr by)])
    (map (lambda (nr) (cons nr (+ step nr))) (range 0 max-nr step))))

(define (to-string grid-row mask-row)
  (define (to-char c m)
    (if (equal? m " ") c ""))
  (for/fold ([word ""])
    ([c (regexp-match* #rx"." grid-row)]
     [m (regexp-match* #rx"." mask-row)])
    (string-append word (to-char c m))))

(define (to-word grid-slice mask-slice)
  (for/fold ([entire-word ""])
    ([grid-row grid-slice]
     [mask-row mask-slice])
    (string-append entire-word (to-string grid-row mask-row))))

#| (print (equal? (sha1-bytes (string->bytes/utf-8 result)) (sha1-bytes (string->bytes/utf-8 ref)))) |#

(define (to-slice start-end)
  (to-word ()))

(map )

(print (to-word grid mask))

; TODO(wadii): Make this multithreaded.

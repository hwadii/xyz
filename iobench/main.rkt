#lang racket

(define grid (open-input-file "./letters.txt"))
(define mask (open-input-file "./mask.txt"))
(define ref (string-normalize-spaces (port->string (open-input-file "ref.txt"))))

(define (to-string grid-row mask-row)
  (define (to-char c m)
    (if (equal? m " ") c ""))
  (for/fold ([word ""])
    ([c (regexp-match* #rx"." grid-row)]
     [m (regexp-match* #rx"." mask-row)])
    (string-append word (to-char c m))))

(define result (for/fold ([entire-word ""])
                 ([grid-row (in-lines grid)]
                  [mask-row (in-lines mask)])
                 (string-append entire-word (to-string grid-row mask-row))))

(print (equal? (sha1-bytes (string->bytes/utf-8 result)) (sha1-bytes (string->bytes/utf-8 ref))))

; TODO(wadii): Make this multithreaded.

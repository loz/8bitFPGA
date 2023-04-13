  .org $8000
start:
  ldx #$00        ; set X register to zero
printch:
  lda message,x ; load a byte from "message" into the accumulator
  cmp #$00      ; if this zero byte?
  beq stop       ; if so stop
  sta vidmem,x  ; store the byte from accumulator into "vidmem"
  inx           ; increment X register
  jmp printch
stop:
  nop
  jmp stop

 message:
   .ascii "Computer Says Hello!"
   .byte 0

  .org $9000
vidmem:
  .ascii "This is the original text"
;  .ascii "This is some ascii text"

  .org $9ffc
  .word start
  .word $0000

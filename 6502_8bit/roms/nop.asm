  .org $8000
start:
  nop
  jmp start

vidmem:
 .org $9000
  .ascii "This is some ascii text"

  .org $9ffc
  .word start
  .word $0000

  .org $8000
start:
  nop
  jmp start

  .org $9ffc
  .word start
  .word $0000

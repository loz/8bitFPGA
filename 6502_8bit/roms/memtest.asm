  .org $8000
start:
  ldx #$00        ; set X register to zero
loop:
  lda $1000,X
  adc #1
  sta $1000,X
  inx
  cpx #0
  beq wait
  jmp loop
wait:
  ldx #0
  ldy #0
waitloop:
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  inx
  cpx #0
  beq cnty
  jmp waitloop
cnty:
  iny
  cpy #0
  beq start
  ldx #0
  jmp waitloop


  .org $9ffc
  .word start
  .word $0000
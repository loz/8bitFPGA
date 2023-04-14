VIDMEM=$1000
CURSORX=$1750
CURSORY=$1751
COLUMNS=40
BCURSOR=$1752 ; 1752,1753 store location in video memory
  .org $8000
start:
  ldx #$00        ; set X register to zero
  stx CURSORX     ; save cursor at 0
  stx CURSORY  
  ldx #>VIDMEM    ;LSB
  stx BCURSOR+1   
  ldx #<VIDMEM    ;MSB
  stx BCURSOR
printch:
  ldy CURSORX
  lda message,y ; load a byte from "message" into the accumulator
  cmp #$00      ; if this zero byte?
  beq newline   ; if new line
  iny
  lda "."
  sty CURSORX
  sta $BCURSOR
  inx           ; increment X register
  jmp printch
newline:
  lda CURSORY
  cmp #20
  beq stop
  ;tax
  ;adc COLUMNS
  ;sbc CURSOR
  ;txa
  inc CURSORY
  inc BCURSOR
  inx
  lda #$00
  sta CURSORX
  jmp printch
stop:
  nop
  jmp stop

 message:
   .ascii "Computer Says Hello!"
   .byte 0

  .org $9ffc
  .word start
  .word $0000

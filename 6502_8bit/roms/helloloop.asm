VIDMEM=$1000
CURSORX=$02
CURSORY=$03
COLUMNS=63
ROWS=36
BCURSOR=$00 ; VStores VMEM Buffer Location
  .org $8000
start:
  ldx #$00        ; set X register to zero
  stx CURSORX
  stx CURSORY
  ldy #00
  ldx #$00 ;#<VIDMEM    ;LSB
  stx $00 ;BCURSOR  
  ldx #$10 ;#>VIDMEM    ;MSB
  stx $01 ;BCURSOR+1
  ldx #00
  ldy #00
printch:
  ;Messages
  lda message,y
  cmp #00
  beq incpage
  sta (BCURSOR,X) ;Print at buffer cursor
  inc BCURSOR     ;Move buffer cursor
  inc CURSORX     ;X=X+1
  lda CURSORX
  ;cmp #COLUMNS    ;If at column limit, new page
  ;cmp #40    ;If at column limit, new page
  ;beq incpage
  iny
  jmp printch     ;otherwise, next char
incpage:
  ;advance buffer cursor to new line
  lda #COLUMNS
  sbc CURSORX
  adc BCURSOR
  ;subtract Cursor
  bcc skip_zp
  inc BCURSOR+1
skip_zp:
  sta BCURSOR
  lda #00
  sta CURSORX
  inc CURSORY
  lda CURSORY 
  cmp #ROWS    ;Stop at rowcount
  beq stop
  ldy #00
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

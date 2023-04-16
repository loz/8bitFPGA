VIDMEM=$1000
CURSORX=$02
CURSORY=$03
COLUMNS=63
ROWS=36
BCURSOR=$00 ; VStores VMEM Buffer Location
CCURSOR=$04 ; COPY CURSOR
  .org $8000
start:
  cli       ;enable interupts
  ldx #$00        ; set X register to zero
  stx CURSORY
  stx CURSORX
  ldy #00
  ldx #$00 ;#<VIDMEM    ;LSB
  stx $00 ;BCURSOR  
  ldx #$10 ;#>VIDMEM    ;MSB
  stx $01 ;BCURSOR+1
  lda #$3e
  jsr print_ch
main:
   nop
   jmp main

; areg charater printed to screen
print_ch:
  ldx #00
  sta (BCURSOR,X) ;Print at buffer cursor
  inc BCURSOR     ;Move buffer cursor
  inc CURSORX     ;X=X+1
  tay
  lda #$5f
  sta (BCURSOR,X)
  tya ;return A to former state
  rts

; IRQ
byteread:
  ; fetch the byte from UART
  lda %0100000000000000
  cmp #$0d
  beq newline
  cmp #$7f
  beq backspace
  jsr print_ch
cnt:
  ;clear the interupt
  sta %0100000000000000
  rti
newline:
  lda #$20
  sta (BCURSOR,X)
  ;advance buffer cursor to new line
  lda #COLUMNS
  ;subtract Cursor
  sbc CURSORX
  adc BCURSOR
  bcc skip_zp 
  inc BCURSOR+1 ;Zero page of cursor increased, next 512bytes
skip_zp:
  sta BCURSOR
  lda #00
  sta CURSORX ; re-set cursor
  inc CURSORY
  lda CURSORY 
  cmp #ROWS    ;Scroll
  bne skip_scroll
  jsr scroll_screen
skip_scroll:
  lda #$3e
  jsr print_ch
  jmp cnt
  
backspace:
  lda CURSORX
  cmp #01
  beq cnt
  lda #$20
  sta (BCURSOR,X)
  dec BCURSOR     ;Move buffer cursor
  dec CURSORX     ;X=X+1
  lda #$5f
  sta (BCURSOR,X)
  jmp cnt

scroll_screen:
  lda #<VIDMEM    ;LSB
  sta BCURSOR  
  adc #COLUMNS
  sta CCURSOR
  lda #>VIDMEM    ;MSB
  sta BCURSOR+1
  sta CCURSOR+1
  ldx #$00
  stx CURSORY
  ldy #00
cpy_row:
  lda (CCURSOR,X)
  sta (BCURSOR,X)
  inc BCURSOR
  inc CCURSOR
  iny
  cpy #COLUMNS 
  beq rowdone
  jmp cpy_row
rowdone:
  inc BCURSOR
  lda BCURSOR
  cmp #00 ;rolled over
  bne skip_bcpage
  inc BCURSOR+1
skip_bcpage:
  inc CCURSOR
  lda CCURSOR
  cmp #00 ;rolled over
  bne skip_ccpage
  inc CCURSOR+1
skip_ccpage:
  inc CURSORY
  lda CURSORY
  cmp #ROWS
  beq allrowsdone
  ldy #00
  jmp cpy_row
allrowsdone:
  lda #00
  sta CURSORX
  lda BCURSOR
  sbc #COLUMNS
  bcc skip_unpage
  dec BCURSOR+1
skip_unpage:
  sbc #01
  bcc skip_unpage2
  dec BCURSOR+1
skip_unpage2:
  sta BCURSOR
  inc BCURSOR
  dec CURSORY
  rts
  

  .org $9ffc
RESVEC:  .word start
IRQVEC:  .word byteread

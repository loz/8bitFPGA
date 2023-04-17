VIDMEM=$1000
CURSORX=$02
CURSORY=$03
COLUMNS=63
ROWS=37
BCURSOR=$00 ; VStores VMEM Buffer Location
CCURSOR=$04 ; COPY CURSOR
WORDVAR=$06 ; Var for word maths
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
  jsr inc_cursor
  inc CURSORX
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
  lda CURSORX
  cmp #COLUMNS
  beq cnt ; Skip it at column limit
  lda %0100000000000000
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
  clc
  adc BCURSOR
  bcc skip_zp 
  inc BCURSOR+1 ;Zero page of cursor increased, next 512bytes
skip_zp:
  sta BCURSOR
  jsr inc_cursor ;add 1 for column right
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
  jsr dec_cursor
  dec CURSORX
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
  jsr inc_cursor
  iny
  cpy #COLUMNS 
  beq rowdone
  jmp cpy_row
rowdone:
  jsr inc_cursor ;columns is 1 short of screen buffer size
  inc CURSORY
  lda CURSORY
  cmp #ROWS
  beq allrowsdone
  ldy #00
  jmp cpy_row
allrowsdone:
  lda #00
  sta CURSORX
  jsr cursor_up
  jsr dec_cursor ;we overshot for the row
  rts

cursor_up:
  pha ;preserve a
  sec
  lda BCURSOR
  sbc #COLUMNS
  bcs skip_cupage
  dec BCURSOR+1
skip_cupage:
  sta BCURSOR
  dec CURSORY
  pla ;restore a
  rts

inc_cursor:
  pha ;preserve a
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
  pla ;restore a
  rts

dec_cursor:
  pha ;preserve a
  dec BCURSOR
  lda BCURSOR
  cmp #$ff ;rolled over
  bne skip_dbcpage
  dec BCURSOR+1
skip_dbcpage:
  dec CCURSOR
  lda CCURSOR
  cmp #$ff ;rolled over
  bne skip_dccpage
  dec CCURSOR+1
skip_dccpage:
  pla ;restore a
  rts

  .org $9ffc
RESVEC:  .word start
IRQVEC:  .word byteread

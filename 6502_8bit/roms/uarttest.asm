VIDMEM=$1000
CURSORX=$02
CURSORY=$03
COLUMNS=63
ROWS=36
BCURSOR=$00 ; VStores VMEM Buffer Location
  .org $8000
start:
  cli       ;enable interupts
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
  lda #$41
  ldx #00
  sta $1000,x
main:
   nop
   jmp main

; areg charater printed to screen
print_ch:
  sta (BCURSOR,X) ;Print at buffer cursor
  inc BCURSOR     ;Move buffer cursor
  inc CURSORX     ;X=X+1
  lda CURSORX
  rts

; IRQ
byteread:
  ; fetch the byte from UART
  lda %0100000000000000
  jsr print_ch
  ;clear the interupt
  sta %0100000000000000
  rti

  .org $9ffc
RESVEC:  .word start
IRQVEC:  .word byteread

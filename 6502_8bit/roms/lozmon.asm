;Inspired by WOZmon, a memory explorer

VIDMEM=$1000
CURSORX=$02
CURSORY=$03
COLUMNS=63
ROWS=37
BCURSOR=$00 ; VStores VMEM Buffer Location
CCURSOR=$04 ; COPY CURSOR
PCURSOR=$06 ; Parse Cursor
CURLOC=$08  ; Current Memory Location
ENDLOC=$10  ; End range location
MESSAGE=$12 ; MESSAGE Variable
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
  lda #<WELCOME_PROMPT
  sta MESSAGE
  lda #>WELCOME_PROMPT
  sta MESSAGE+1
  jsr print_message
  jsr show_prompt
  jsr show_cursor
main:
   nop
   jmp main

; areg charater printed to screen
print_ch:
  ldx #00
  sta (BCURSOR,X) ;Print at buffer cursor
  jsr inc_cursor
  inc CURSORX
  rts

  ; areg charater printed to screen
print_hex:
  pha ; Save A for re-use
  ror
  ror
  ror
  ror
  clc
  and #%00001111
  jsr print_hex_lower ;really upper 4bits
  pla ;get back original A value for actual lower
  clc
  and #%00001111
  jsr print_hex_lower
  rts

print_hex_lower:
  cmp #10
  bcc print_hex_lower_digit
  ; Hex based
  adc #54
  jmp print_hex_lower_nextbit
print_hex_lower_digit:
  adc #48
print_hex_lower_nextbit:
  jsr print_ch
  rts

;show cursor at its location
show_cursor:
  pha
  lda #$5f
  sta (BCURSOR,X)
  pla
  rts

; IRQ
byteread:
  ; fetch the byte from UART
  lda %0100000000000000
  cmp #$0d
  beq execcmd
  cmp #$7f
  beq backspace
  lda CURSORX
  cmp #COLUMNS
  beq cnt ; Skip it at column limit
  lda %0100000000000000
  ;typing
  jsr print_ch
  jsr show_cursor
cnt:
  ;clear the interupt
  sta %0100000000000000
  rti
execcmd:
  jsr clear_cursor
  jsr parse_input
  cmp #0
  bne execcmd_finish
  jsr show_memory
execcmd_finish:
  jsr newline
  jsr show_prompt
  jsr show_cursor
  jmp cnt
backspace:
  lda CURSORX
  cmp #01
  beq cnt
  jsr clear_cursor
  jsr dec_cursor
  jsr show_cursor
  dec CURSORX
  jmp cnt


; Show memory at CURLOC
show_memory_block
  jsr newline
  ldy #0
show_block_loop
  lda (CURLOC), Y
  jsr print_hex
  lda #" "
  jsr print_ch
  cpy #16
  beq show_block_done
  iny
  jmp show_block_loop
show_block_done:
  rts

show_memory:
  jsr show_memory_block
  rts
  jsr newline
  lda #"0"
  jsr print_ch
  lda #"x"
  jsr print_ch
  lda CURLOC
  jsr print_hex
  lda #":"
  jsr print_ch
  ldx #0
  lda (CURLOC, X)
  jsr print_hex
  rts

; Parse input on this line
parse_input:
  ;Set PCursor to start of current Prompt
  lda BCURSOR
  clc
  sbc CURSORX
  sta PCURSOR
  lda BCURSOR+1
  sbc #0
  sta PCURSOR+1
  clc
  lda PCURSOR
  adc #2
  sta PCURSOR
  lda PCURSOR+1
  adc #0
  sta PCURSOR+1
  lda #$3a ; :
  jsr print_ch
  ldy #0
parse_continue:
  lda (PCURSOR),Y
  clc
  cmp #$30 ; is this digit? ($30-46)
  bcs parse_digit
  jmp invalid_parse
parse_digit:
  clc
  cmp #$3A; is this over dec range?
  bcs parse_potential_hex
  ; ASSERT - Is digit
  clc
  sbc #$2F
  sta CURLOC ;store the digit
  jmp parse_complete
parse_potential_hex:
  clc
  cmp #$41; is this hex? ($41-$46)
  bcs parse_hex
  jmp invalid_parse
parse_hex:
  clc
  cmp #$47
  bcs invalid_parse
  ;normalise to binary value
  clc
  sbc #$36
  sta CURLOC
  ;None valid
  jmp parse_complete
invalid_parse:
  ; nothing extra
  lda #$3F
  jsr print_ch
  lda #1; 'Not Success'
  rts
parse_complete:
  lda #0; 'Success'
  sta CURLOC+1 ; Ensure ZERO page for now
  rts

; Remove cusor char
clear_cursor:
  lda #$20
  sta (BCURSOR,X)
  rts

; Prompt >
show_prompt:
  lda #$3e
  jsr print_ch
  rts

; Move cursor to new line
newline:
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
  rts

; Line scrolling
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

; Print string starting a memory location MESSAGE
print_message:
  ldy #0
print_message_loop:
  lda (MESSAGE),Y
  cmp #0
  beq print_message_complete
  jsr print_ch
  iny
  jmp print_message_loop
print_message_complete
  jsr newline
  jsr newline
  jsr inc_cursor ;this is needed for some reason
  rts

WELCOME_PROMPT: .ascii "Welcome to LOZmon, memory explorer."
                .byte 0

  .org $9ffc
RESVEC:  .word start
IRQVEC:  .word byteread

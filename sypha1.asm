* = $0801 ; BASIC Upstart 
; BASIC line: 10 SYS 2063 
!byte $0C, $08, $0A, $00, $9E, $20, $32, $30, $36, $33, $00, $00, $00
* = $080F ; Start of code 

start: 
  ldy #$d6 
  sty $d400 ;frequency voice 1 low byte 
  ldy #$1c 
  ;sty $d401 ;frequency voice 1 High byte 
  ;dec $d402 ;  pulse wave duty cycle voice 1 low byte 
  ldy #$02 
  sty $d403 ;  pulse wave duty cycle voice 1 High byte 
  ldy #$11 ; triangle and gate bit on 
  sty $d404 ;control register voice 1 
  ldy #$ff ; attack duration is f and decay duration is f voice 1 
  sty $d405 
  ldy #$9f ;  sustain level is 9 and release duration is f 
  sty $d406 
  ldy #$09 ;filter mode is none and main volume control is 9 
  sty $d418 ;this is correct code 
  ldx #$01 
  inc $0400 
  inc $0427 
  inc $05f4 
  inc $07c0 
  inc $07e7 
  ;inc $D400 
  ;inc $D401 
  ;inc $D402 
  ;inc $D403 
  ;inc $D404 
  ;inc $D405 
  ;inc $D406 
  ;inc $D407 
  ;inc $D408 
  ;inc $D409 
  ;inc $D40A 
  ;inc $D40B 
  ;inc $D40C 
  ;inc $D40D 
  ;inc $D40E 
  ;inc $D40F 
  ;inc $D410 
  ;inc $D411 
  ;inc $D412 
  ;inc $D413 
  ;inc $D414 
  ;inc $D415 
  ;inc $D416 
  ;inc $D417 
  ;inc $D418 
  eor #$55 
  jsr delay

delay: 
 ldx #$FF 
delay1: 
 ldy #$FF 
delay2: 
 dey 
 bne delay2 
 dex 
 bne delay1 
 rts
 jmp start
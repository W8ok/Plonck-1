;Testing NOP
  NOP     ;0bX010XXXX
  NOP
  NOP
  NOP
  NOP

;Testing Logic operation
  OR 1    ;Sets data to 1 and does an OR operation, Acc is now 1 0b1110XXXX
  STO A0  ;Stores a 1 in address 0
  AND A0  ;Acc is still 1 0b00000000
  LD A1   ;Acc is now 0   0b01000001
  ORCD A0 ;Acc is still 0 0b00110000
  ORCR A0 ;Acc is now 1
  XNOR A1 ;Acc is now 0
;Acc should now be blinking
  XNOR A1 ;0b00010001
  XNOR A1
  XNOR A1
  XNOR A1
  XNOR A1
  XNOR A1

;Make all memory locations 1 for testing
  STO A0  ;0b01110000
  STO A1
  STO A2
  STO A3
  STO A4
  STO A5
  STO A6
  STO A7  ;0b01110111
  STO A8
  STO A9
  STO A10
  STO A11
  STO A12
  STO A13
  STO A14
  STO A15 ;0b01111111
  HALT    ;0b1111XXXX

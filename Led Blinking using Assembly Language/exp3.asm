// Led Blinking using Assembly Program
ORG 0000
MOV TMOD, #01H
MOV A,#0x01
RL A
MOV P1,A
again1:
again:
MOV TH0,#0x00
MOV TL0,#0x00
SETB TR0
wait:
JNB TF0, wait
CLR TF0
DJNZ R0, again1
RL A
MOV P1,A
SJMP again
END
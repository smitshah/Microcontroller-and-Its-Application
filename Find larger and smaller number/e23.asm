org 0
mov r5,#04
mov r0,#50H
mov a,r0
mov b,a
again: inc r0
mov a,@r0
cjne a,b,check

check: jc n1 ;a<b
	   sjmp b1	;b is already smaller

n1: mov b,a
b1:
djnz r5, again
end
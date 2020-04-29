org 0
mov dptr,#x
mov r0,#50H
mov r7,#0AH
again: mov A,#00H
movc A,@A+DPTR
mov @r0,A
inc dptr
inc r0
djnz r7,again

org 0x200
x: dB 45H,3AH,50H,6BH,75H,52H,8BH,89H,06H,10H
end
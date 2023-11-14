;ORG 0000H
    ;LJMP main

ORG 0000h
main:
    
    inc a
    cjne a,#100,delay
    cpl p1.0
    mov a,#0

;notog:
    ;sjmp delay

delay:
    mov r7,#200
delay1:    
    mov r6,#10
    DJNZ r6,$
    DJNZ r7, delay1
    RET

END



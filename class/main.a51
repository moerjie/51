ORG 0000H
    LJMP MAIN
ORG 0100H
  MAIN:
    MOV A,#10H
    MOV B,#15H
    MOV r1,#10H
    MOV r2,#05H
    ADD A,B
    MOV R3,A
    MOV A,R1
    MOV B,R2
    MUL AB
    mov r0,a
    ;MUL AB

END

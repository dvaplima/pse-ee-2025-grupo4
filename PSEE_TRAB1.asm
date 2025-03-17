;Trabalho 1 - PSEEE
;DAVI LIMA
;INACIO BATISTA
ORG 00h
tempo:
MOV A,P2
MOV B,#00001000b
DIV AB
MOV R0,B
MOV R1,B
INC R0
INC R1
;LEDs
;P1.0 - Chave K1 (Partida)
;P1.1 - Chave K2 (Delta)(Entra 2º)
;P1.2 - Chave K3 (Estrela)(Entra 1º)
;P1.3 - RLY 1 (Inverter)
;BOTOES
;P2.0 - 1º Digito do tempo
;P2.1 - 2º Digito do tempo
;P2.2 - 3º Digito do tempo
;P2.3 - Start
;P2.4 - Inversao
start:
JB P2.3,start ; Aguardar botao 3
inicio: ; Configura cond iniciais
SETB P1.1 ; Desconecta Delta
CLR P1.2 ; Conecta em Y
CLR P1.0 ; Liga
MOV B,R1 ; Salvar Tempo em B
MOV R0,B ; Salvar Tempo em R0
comutador:
MOV ACC,R0 ;Armazena tempo no ACC
JB P2.3,desl;Verificar o botao start
ACALL delay1s;
DEC R0
JNZ comutador
SETB P1.0 ;Desligar o motor
SETB P1.2 ;Desligar o estrela
CLR P1.1 ;Ligar o Delta
CLR P1.0 ;Religar o motor
verificar:
JB P1.3,inv ; Aguardando botao
JNB P1.3,desinv ; Aguardando botao
inv:
JB P2.3,desl;Verificar o botao start
JB P2.4,inv ; Aguardando botao
SETB P1.0 ; Desliga o motor
ACALL delay3s; Espera 3s
CLR P1.3 ; Inverte Rotacao
CLR P1.0 ; Religa o motor
JMP inicio
desinv:
JB P2.3,desl;Verificar o botao start
JNB P2.4,desinv; Aguardando botao
SETB P1.0 ; Desliga o motor
ACALL delay3s ; Espera 3s
SETB P1.3 ; Inverte Rotacao
CLR P1.0 ; Religa o motor
JMP inicio
desl:
SETB P1.0 ;Desliga o motor
JB P2.3,start ;Volta para start
delay3s:
ACALL delay500ms
ACALL delay500ms
ACALL delay500ms
ACALL delay500ms
ACALL delay500ms
ACALL delay500ms
RET
delay1s:
ACALL delay500ms
ACALL delay500ms
RET
delay500ms:
MOV R2,#0FAh
aux1:
MOV R3,#0F9h
NOP
NOP
NOP
NOP
NOP
aux2:
NOP
NOP
NOP
NOP
NOP
NOP
DJNZ R3,aux2
DJNZ R2,aux1
RET
end
section .data
	mensagem1 db "Digite algo: ", 0
	len1 equ $ - mensagem1
	mensagem2 db "Você digitou: ", 0
	len2 equ $ - mensagem2
	
section .bss
	entrada resb 255 ; buffer para input
 
section .text
global _start
_start:
	; imprimir primeira mensagem
	mov EAX, 4
	mov EBX, 1
	mov ECX, mensagem1
	mov EDX, len1
	int 0x80
	
	; ler entrada e gravar no buffer
	mov EAX, 3
	Mov EBX, 0
	mov ECX, entrada
	mov EDX, 255
	int 0x80
	
	;  imprimir saída
	mov EAX, 4
	mov EBX, 1
	mov ECX, mensagem2
	mov EDX, len2
	int 0x80
	
	mov EAX, 4
	mov EBX, 1
	mov ECX, entrada
	mov EDX, 255
	int 0x80
	
	; encerrar programa
	mov EAX, 1
	int 0x80

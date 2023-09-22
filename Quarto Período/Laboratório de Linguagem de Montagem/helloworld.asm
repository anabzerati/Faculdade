section .data
	hello db "Hello World", 0x0A
	hello_len equ $ - hello ;conta caracteres de hello
	
section .text
	global_start
_start:
	mov eax, 4 ; syscall de escrever na tela
	mov ebx, 1 ; saída padrão
	mov ecx, hello ; conteúdo escrito
	mov edx, hello_len
	
	int 0x80 ; interrupção - chamada da syscall 4 (apresentar mensagem)
	
	mov eax, 1 ; syscall de encerramento
	xor ebx, ebx ; exit status
	int 0x80 ; interrupção - chamada da syscall 1 (encerrar programa)

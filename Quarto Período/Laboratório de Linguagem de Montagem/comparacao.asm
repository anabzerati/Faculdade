; Comparar valores dos registradores

; Variáveis definidas na memória
section .data
	numero1 dd '2'
	numero2 dd '3'
	mensagemMaior db "O maior número é: "
	lenMaior equ $ - mensagemMaior
	mensagemIgual db "Os dois números são iguais!"
	lenIgual equ $ - mensagemIgual

; Variávies não definidas na memória
segment .bss
	maiorNumero resb 1 ; reservado um byte

; Código propriamente
section .text
global _start
_start:
	mov eax, [numero1]
	mov ebx, [numero2]
	cmp eax, ebx ; comparar registradores

	je numerosIguais ; jump if equal - seção numerosIguais
	jg numero1Maior ; jump if greater - seção numero1Maior
	jb numero2Maior ; jump ig below - seção numero2Maior


numerosIguais: ; seção para o primeiro caso
	; imprimir mensagem de igualdade
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagemIgual
	mov edx, lenIgual
	int 0x80
	jmp end ; finalizar programa

numero1Maior:
	mov [maiorNumero], eax ; guarda como maior o primeiro
	jmp imprimeMaior ; seção de imprimir maior número

numero2Maior:
	mov [maiorNumero], ebx
	jmp imprimeMaior

imprimeMaior:
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagemMaior
	mov edx, lenMaior
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, maiorNumero
	mov edx, 1
	int 0x80

	jmp end

end:
	mov eax, 1
	xor ebx, ebx ; limpando registrador
	int 0x80

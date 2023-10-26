; Desenvolver um programa em assembly que faça a leitura de um inteiro , compare com um valor da memória e apresente o menor número

; Variáveis inicializadas
section .data
	numero dd '5'

	mensagemEntrada db "Insira um número: ", 0x0a
	lenMensagemEntrada equ $ - mensagemEntrada

	mensagemMenor db "O menor número é: "
	lenMensagemMenor equ $ - mensagemMenor

	mensagemIguais db "Os números são iguais!", 0x0a
	lenMensagemIguais equ $ - mensagemIguais

; Variáveis não inicializadas
segment .bss
	numeroInserido resb 1 
	menorNumero resb 1

; Código
section .text
	global _start
_start:
	; imprime mensagem
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagemEntrada
	mov edx, lenMensagemEntrada
	int 0x80

	; recebe número e armazena na variável numeroInserido
        mov eax, 3
        mov ebx, 0
        mov ecx, numeroInserido
        mov edx, 1
        int 0x80

        ; carregar valores para registradores
        mov eax, [numero]
        mov ebx, [numeroInserido]
        ; sub ebx, '0' ; convertendo ascii para decimal 
        cmp eax, ebx ; comparação dos valores

        je numerosIguais ; se forem iguais, pula para seção adequada 
        jg inseridoMenor ; se o número da memória for maior
        jb memoriaMenor; se o número inserido for maior
	
numerosIguais:
	; imprimir mensagem de igualdade
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagemIguais
	mov edx, lenMensagemIguais

	int 0x80
	jmp end

inseridoMenor:
	mov [menorNumero], ebx
	jmp imprimeMenor

memoriaMenor:
	mov [menorNumero], eax
	jmp imprimeMenor

imprimeMenor:
	; imprimir o menor número
	mov eax, 4
	mov ebx, 1
	mov ecx, mensagemMenor
	mov edx, lenMensagemMenor
	int 0x80
	
	mov eax, 4
	mov ebx, 1
	mov ecx, menorNumero
	mov edx, 1
	int 0x80
	
	jmp end

end:
	mov eax, 1
	xor ebx, ebx ; limpa registrador
	int 0x80

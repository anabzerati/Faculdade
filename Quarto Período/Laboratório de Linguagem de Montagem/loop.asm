section .bss
    num resb 1 ; byte reservado para print

section .text
    global _start
_start:
    mov ecx, 9 ; quantidade de iterações (9 -> 0)
    mov eax, '1' ; número impresso

loop1:
    mov [num], eax ; número que vai ser impresso - 1, 2, ..., 9
    mov eax, 4 ; syscall de impressão
    mov ebx, 1 ; output

    push ecx ; guarda ecx (contador) na pilha

    mov ecx, num ; usa ecx para imprimir o número
    mov edx, 1 ; tamanho da impressão
    int 0x80 ; imprime

    ; incrementar número (1 -> 2 -> 3 -> ...)
    mov eax, [num] 
    sub eax, '0'
    inc eax
    add eax, '0'

    pop ecx ; pegamos contador da pilha

    loop loop1 ; chama loop, continua enquanto ecx diferente de zero

    ;finalização
    mov eax, 1
    int 0x80



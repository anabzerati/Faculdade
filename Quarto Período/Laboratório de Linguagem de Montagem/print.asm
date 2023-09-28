section .data
msg1 db "Enter the first number : ", 0xa ; primeira frase + quebra de linha
len1 equ $ - msg1 ; comprimento da frase
msg2 db "Enter the 2nd number : ", 0xa ; segunda frase + quebra de linha
len2 equ $ - msg2 ; comprimento da frase

msg3 db "The sum is: " ; terceira frase
len3 equ $- msg3 ; comprimento da terceira frase

section .bss
num1 resb 2 ; resb = reserve a byte, aloca espaço para variáveis não inicializadas
num2 resb 2 
res resb 1

section .text
global _start
_start :
  
  ;imprimir primeira frase
  mov edx,len1 ; comprimento
  mov ecx,msg1 ; o que é para ser escrito
  mov ebx,1 ; saída padrão
  mov eax,4 ; sysread
  int 0x80 ; syscall
  
  ;pegar input do primeiro número
  mov edx,2 ; 2 bytes
  mov ecx,num1 ; onde armazenar
  mov ebx,0  ; entrada padrão
  mov eax,3 ; sysread
  int 0x80 ;syscall
  
  ;imprimir segunda frase
  mov edx,len2
  mov ecx,msg2
  mov ebx,1 
  mov eax,4
  int 0x80
  
  ;pegar input do segundo número
  mov edx,2 
  mov ecx,num2
  mov ebx,0 
  mov eax,3
  int 0x80
  
  ;mover valores para os registradores
  mov eax,[num1]
  sub eax,'0' ; converter ascii para decimal
  mov ebx,[num2]
  sub ebx,'0'
  
  ;somar números
  add eax,ebx
  add eax,'0' ; converter decimal para ascii
  
  mov [res],eax ; armazenar soma na memória
  
  ;imprimir terceira frase
  mov edx,len3
  mov ecx,msg3
  mov ebx,1 
  mov eax,4
  int 0x80
  
  ;imprimir resultado
  mov edx,1
  mov ecx,res
  mov ebx,1 
  mov eax,4
  int 0x80
  
  
  
  ;exiting
  mov ebx,0
  mov eax,1 
  int 0x80

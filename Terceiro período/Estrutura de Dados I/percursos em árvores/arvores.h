/*
Arquivo que guarda as definições e funções para as árvores.
Há uma árvore dinâmica e uma em forma de vetor.
*/

#define num 15 //tamanho da árvore estática

typedef int *static_tree; //possibilita chamar ponetiros de inteiro (inclui vetor) de static_tree

typedef struct tree //definição da árvore dinamicamente
{
    int value;
    struct tree *right;
    struct tree *left;
} dynamic_tree;

/*--------------------------------*/
//fuções para árvores dinâmicas
//recebe a raíz e o valor do novo elemento. Cria elemento e busca posição para inserir (de forma ordenada)
dynamic_tree *inserirTree(dynamic_tree *root, int value);
//envolve todos os três percursos. Recebe a raíz (início do percurso) e flag que indica o percurso a se realizar
void percursos(dynamic_tree *root, int flag); 

/*--------------------------------*/
// funções para árvores estáticas
//recebe uma referência à árvore (vetor), o índice do pai e o valor a ser inserido
void static_inserirEsquerda(int parent, int value, static_tree tree);
void static_inserirDireita(int parent, int value, static_tree tree); 
//envolve todos os três percursos. Recebe a raíz e o índice (início do percurso) e flag que indica o percurso a se realizar.
void static_percursos(static_tree tree, int flag, int index); 
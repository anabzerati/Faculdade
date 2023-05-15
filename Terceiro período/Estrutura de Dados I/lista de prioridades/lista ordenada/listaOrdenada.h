/*-----Definição-----*/

typedef struct no{
    int chave;
    struct no *prox;
} No;


/*-----Operações-----*/
//inserção ordenada
No *inserir(No *head, int chave);

//remoção do primeiro elemento
No *remover(No **head);

//busca a partir da chave
No *buscar(No *head, int chave);

//percorre lista
void percorrer(No *head);
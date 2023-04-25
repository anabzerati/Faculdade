/*Definição de estrutura*/
struct tipo_dado{
    int chave;
    //mais info
};

struct node{
    struct tipo_dado info;
    struct node *dir;
    struct node *esq;
};

typedef struct node* tree;

/*Protótipos de funções*/

//Insere elemento a partir da chave. Se não estiver ainda, busca o local adequado
tree inserir(tree root, int chave);

//função recursiva de busca, busca "binária"
tree buscar(tree root, int chave);

//funções para remoção de nó a partir da chave
int buscaRemover(tree *root, int chave);
void remover(tree *root, int chave);
void substituiMenorDireita(tree *p, tree *suc);
void removerNo(tree *p);

//percorre a árvore em ordem
tree percursoEmOrdem(tree root);
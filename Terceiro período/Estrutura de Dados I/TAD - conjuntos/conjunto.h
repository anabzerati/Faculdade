typedef struct conjunto Conjunto;

Conjunto *criaConjuntoVazio();
int membro(Conjunto *A, int x); //retorna 0 se não for membro e 1 se for
void insere(Conjunto *A, int x);
void uniao(Conjunto *A, Conjunto *B, Conjunto *C);
void interseccao(Conjunto *A, Conjunto *B, Conjunto *C);
int igual(Conjunto *A, Conjunto *B); //retorna 0 se não forem iguais e 1 se forem

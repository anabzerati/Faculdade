/*Escreva uma função recursiva para determinar de quantos modos diferentes podemos combinar os números do conjunto, SEM REPETIÇÕES, para gerar
um dado número e indique a combinação com a maior quantidade de elementos.
No caso de n ̃ao ser poss ́ıvel gerar o n ́umero a ser decomposto, então seu programa deve responder com o valor 0.

Entrada: 3 linhas - 1) inteiros N (quant de números a serem decompostos) e M (quant de números para decomposição); 2) M inteiros (conjunto a ser usado para decomposição); 
3) N inteiros Ki a serem decompostos.

Saída: uma linha para cada Ki, com a quantidade de combinações possíveis e os números do maior conjunto de combinação

Observação: No caso de soluções que tenham mesmo número de elementos, deve ser apresentada a solução com o elemento de valor mais alto entre elas.*/

#include <stdio.h>

int *combinacao; //aponta para o vetor que armazena a maior combinação
int count_comb=0; //conta a quantidade de combinações possiveis encontradas 
//variaveis necessárias para função de comparação do vetor "atual" (da combinação feita no momento pela função backtracking) e "geral" (com maior elemento entre todas feitas até o momento)
int tam_vet;
int maior_elemento=0;

void backtracking(int *candidatos, int *comb_atual, int posicao, int valor, int quant, int tam_vet_atual, int maior_num_atual);
void inicializar(int *vetor, int tam);
void concatenar(int *vetor, int num);
void remover_ultimo(int *vetor);
void imprimir_vetor();
void transfere(int *vetor);

int main(){
    int N, M, i, j, indice_maior;

    scanf("%d %d", &N, &M);

    int conj_comb[M]; //vetor para receber os números do conjunto de combinação
    int numeros[N]; //vetor para receber os números a serem decompostos por combinação
    int aux[M]; //vetor vazio auxiliar mandado para combinacoes para armazenar as tentativas de combinacoes 
    combinacao = malloc(M*sizeof(int));
    
    for(i=0; i<M; i++){
        scanf("%d", &conj_comb[i]); //preenche conjunto de números utilizáveis para combinação
    }

    for(i=0; i<N; i++){
        scanf("%d", &numeros[i]); //recebe números para combinar
    }

    for(i=0; i<N; i++){
        inicializar(combinacao, M); //esvazio vetores a cada novo número a ser combinado (preenchidos com zero)
        inicializar(aux, M); 
        backtracking(conj_comb, aux, 0, numeros[i], M, 0, 0); //com essa função, tenho a matriz combinacoes prenchida com todas as combinações, sendo a quantidade de linhas a quantidade de combinações
        printf("%d ", count_comb);
        imprimir_vetor();
        printf("\n");
        count_comb=0;
        tam_vet=0;
        maior_elemento=0;
    }

    return 0;
}

void inicializar(int *vetor, int tam){ //preenche todo o vetor com zero (necessário para não carregar valor de números combinados anteriores)
    int i;
    for(i=0; i<tam; i++){
        vetor[i] = 0;
    }
}

void backtracking(int *candidatos, int *comb_atual, int posicao, int valor, int quant, int tam_vet_atual, int maior_num_atual){ //função que realiza a combinação dos números do conjunto de possíveis a utilizar
  int i = posicao, anterior;
  if (valor==0){ //valor começa como a soma almejada e é decrescido dos números da combinação atual tentada a cada recursão. Se valor chegar a 0 significa que a soma dos números de comb_atual dá a soma desejada
    if(tam_vet_atual>tam_vet || (tam_vet_atual==tam_vet && maior_num_atual>maior_elemento)){ //se tiver mais elementos que o maior "geral" (ou mesma quantidade porem número de maior valor), chama transfere que "troca" (atualiza o novo maior vetor com maior quantidade de elementos)
        transfere(comb_atual);
        tam_vet = tam_vet_atual; //atualiza valores para a análise das p´roximas combinações encontradas
        maior_elemento = maior_num_atual;
    }
    count_comb++; //aumaneta o número de combinações encontradas
    maior_num_atual=0; //esvazia variavel para ser usada no próximo
    tam_vet_atual=0;
  } else if (valor<=0){ //caso o valor seja menor que zero, a soma não é compatível com a desejada e caso seja zero "acabou"
    return;
  }
  //caso o valor seja maior que zero, é chamada a recursão, até que o valor alcance a soma ou passe dela

  anterior = -1;
  while(i!=quant){ 
    if(candidatos[i] == anterior){ //"pula" para não repetir combinações
      continue; //continua o loop desconsiderando o valor
    } 
    if(candidatos[i]>maior_num_atual){
        maior_num_atual = candidatos[i]; //verifica o amior número da combinação 
    }
    concatenar(comb_atual, candidatos[i]); //comb_atual recebe para tentativa de combinação o valor de candidatos[i]
    backtracking(candidatos, comb_atual, i+1, valor - candidatos[i], quant, tam_vet_atual+1, maior_num_atual);
    remover_ultimo(comb_atual); //removo o último valor para não repetir
    anterior = candidatos[i];
    i++;
  }
}

void concatenar(int *vetor, int num){ //adiciona após a última posição preenchida do vetor o valor
    int i=0;
    while(vetor[i]!=0){ //encontra até qual indice o vetor está preenchido
        i++;
    }
    vetor[i] = num;
}

void remover_ultimo(int *vetor){ //remove o último valor
    int i=0;
    while(vetor[i]!=0){  //encontra até qual indice o vetor está preenchido
        i++;
    }
    vetor[i-1]=0;  //o antepenultimo (ultimo preenchido) se torna zero (é retirado)
}

void imprimir_vetor(){  //imprime o vetor combinação (até onde está preenchido com valores diferentes de zero)
    int i=0;
    while(combinacao[i]!=0){
        printf("%d ", combinacao[i]);
        i++;
    }
}

void transfere(int *vetor){ //copia os valores do vetor recebido para o vetor combinação
    int i=0;
    while(vetor[i]!=0){
        combinacao[i]=vetor[i];
        i++;
    }
}
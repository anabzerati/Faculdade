//tentativa 2
/**Escreva uma função recursiva para determinar de quantos modos diferentes podemos combinar os números do conjunto, SEM REPETIÇÕES, para gerar
um dado número e indique a combinação com a maior quantidade de elementos.
No caso de n ̃ao ser poss ́ıvel gerar o n ́umero a ser decomposto, então seu programa deve responder com o valor 0.

Entrada: 3 linhas - 1) inteiros N (quant de números a serem decompostos) e M (quant de números para decomposição); 2) M inteiros (conjunto a ser usado para decomposição); 
3) N inteiros Ki a serem decompostos.

Saída: uma linha para cada Ki, com a quantidade de combinações possíveis e os números do maior conjunto de combinação

Observação: No caso de soluções que tenham mesmo número de elementos, deve ser apresentada a solução com o elemento de valor mais alto entre elas.*/

#include <stdio.h>

int combinacoes[1000][16]; //supus que o max de combinações seria 1000, verificar. 16 é o número max de números do conjunto de candidatos
int count_linhas=0;

void backtracking(int *candidatos, int *comb_atual, int posicao, int valor, int quant);
void inicializar(int *vetor, int tam);
void adicionar_matriz(int *vetor, int linha);
void concatenar(int *vetor, int num);
void remover_ultimo(int *vetor);
void analise_combinacoes(int quant_linhas);
void imprimir_vetor(int linha);

int main(){
    int N, M, i, j, indice_maior;

    scanf("%d %d", &N, &M);

    int conj_comb[M]; //vetor para receber os números do conjunto de combinação
    int numeros[N]; //vetor para receber os números a serem decompostos por combinação
    int aux[M]; //vetor vazio auxiliar mandado para combinacoes para armazenar as tentativas de combinacoes 
    
    for(i=0; i<M; i++){
        scanf("%d", &conj_comb[i]); //preenche conjunto de números utilizáveis para combinação
    }

    for(i=0; i<N; i++){
        scanf("%d", &numeros[i]); //recebe números para combinar
    }

    for(i=0; i<N; i++){
        for(j=0; j<1000; j++){
            inicializar(combinacoes[j], 16); //inicializa a matriz combinações com 0 (e "limpa" dos valores anteriores)
        }
        inicializar(aux, M); 
        backtracking(conj_comb, aux, 0, numeros[i], M); //com essa função, tenho a matriz combinacoes prenchida com todas as combinações, sendo a quantidade de linhas a quantidade de combinações
        printf("%d ", count_linhas);
        //agora é necessário analisar a matriz buscando a combinação com mais valores
        analise_combinacoes(count_linhas);
        printf("\n");
        count_linhas=0;
    }
    return 0;
}

void inicializar(int vetor[], int tam){
    int i;
    for(i=0; i<tam; i++){
        vetor[i] = 0; 
    }
}

void backtracking(int *candidatos, int *comb_atual, int posicao, int valor, int quant){ //função que realiza a combinação dos números do conjunto de possíveis a utilizar
  int i = posicao, anterior;
  if (valor==0){ //valor começa como a soma almejada e é decrescido dos números da combinação atual tentada a cada recursão. Se valor chegar a 0 significa que a soma dos números de comb_atual dá a soma desejada
    adicionar_matriz(comb_atual, count_linhas);
    count_linhas++; //conta quantas linhas da matriz foram preenchidas (quantas combinações foram feitas)
  } else if (valor<=0){ //caso o valor seja menor que zero, a soma não é compatível com a desejada
    return;
  }
  //caso o valor seja maior que zero, é chamada a recursão, até que o valor alcance a soma ou passe dela

  anterior = -1;
  while(i!=quant){ 
    if(candidatos[i] == anterior){ //"pula" para não repetir combinações
      continue; //continua o loop desconsiderando o valor
    } 
    concatenar(comb_atual, candidatos[i]); //comb_atual recebe para tentavida de combinação o valor de candidatos[i]
    backtracking(candidatos, comb_atual, i+1, valor - candidatos[i], quant);
    remover_ultimo(comb_atual); //removo o último valor para não repetir
    anterior = candidatos[i];
    i++;
  }
}

void adicionar_matriz(int *vetor, int linha){ //a linha da matrzi indicada (numero de combinações ja feitas) recebe o conjunto da nova combinação
    int i=0;
    while(vetor[i]!=0){
        combinacoes[linha][i] = vetor[i]; 
        i++;
    }
}

void concatenar(int *vetor, int num){ //apos o último elemento (preenchido, diferente de zero) do vetor, adiciona o valor desejado
    int i=0;
    while(vetor[i]!=0){
        i++;
    }
    vetor[i] = num; 
}

void remover_ultimo(int *vetor){ //verifica a ultima posição do vetor preenchida e muda apara zero (retira o número do vetor)
    int i=0;
    while(vetor[i]!=0){
        i++;
    }
    vetor[i-1]=0;
}

void analise_combinacoes(int quant_linhas){ //verifica a combinação com mais valores/com o número mais alto
    int i, j, quant_elementos_temp, maior_quant=0, indice=0, maior_num_temp, maior_num=0;
    for(i=0; i<quant_linhas; i++){
        j=0;
        quant_elementos_temp=0;
        maior_num_temp=0;
        while(combinacoes[i][j]!=0){
            j++;
            quant_elementos_temp++; //quantos elementos tem a linha da matriz lida 
            if(combinacoes[i][j]>maior_num_temp){ //maior número da linha lida
                maior_num_temp = combinacoes[i][j];
            }
        }
        if(quant_elementos_temp>maior_quant){ //se tiver mais elementos do que a ultima com mais elementos dentre elas, se torna a tual com mais elementos
            maior_quant=quant_elementos_temp;
            indice = i; //número da linha da matriz com a maior combinação
            maior_num = maior_num_temp;
        } else if(quant_elementos_temp==maior_quant && maior_num_temp>maior_num){ //se a quantidade de elementos fpr igual, analisa o maior elemento
            maior_num = maior_num_temp;
            indice = i;
        }
    }
    imprimir_vetor(indice); 
}

void imprimir_vetor(int linha){ //imprime a todos os elementos da linha indicada da matriz (linha que possui o maior número de elementos no subconjunto de combinações)
    int i=0;
    while(combinacoes[linha][i]!=0){
        printf("%d ", combinacoes[linha][i]);
        i++;
    }
}
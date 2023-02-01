#include <stdio.h>
#define n 5

int main() {
  int count_m, count_h, menor_ano, menor_mes, menor_dia, num_cliente_menor, num_lim_esp;
  float menor_saldo_m, menor_saldo_h, maior_saldo_m, maior_saldo_h, soma_saldo_m=0, soma_saldo_h=0, media_saldo_m, media_saldo_h, maior_lim_esp=0, aux, saldos[n], aux_troca;

  //usar vetor para saldos no inicio para ordenacao posterior!
 
  typedef struct {
  char nome[50], sobrenome[50], sexo;
} Tpessoal;

  typedef struct{
  int dia, mes, ano;
} Tdata;

  typedef struct{
  int numero_conta;
  float saldo, limite_esp;
  Tpessoal cliente;
  Tdata data;
} Tconta;

  Tconta conta[n];

  for(int i=0; i<n; i++){
    printf("Insira o nome: ");
    scanf(" %[^\n]s", conta[i].cliente.nome);
    printf("Insira o sobrenome: ");
    scanf(" %[^\n]s", conta[i].cliente.sobrenome);
    printf("Insira <f> para sexo feminino e <m> para sexo masculino: ");
    scanf(" %c", &conta[i].cliente.sexo);
    printf("Escreva a data na forma DD/MM/AAAA: ");
    scanf("%d %d %d", &conta[i].data.dia, &conta[i].data.mes, &conta[i].data.ano);
    printf("Insira o número da conta: ");
    scanf("%d", &conta[i].numero_conta);
    printf("Insira o saldo e o limite especial: ");
    scanf("%f %f", &conta[i].saldo, &conta[i].limite_esp);
  }

  //maior e menos saldo mulheres e homens + media - obs ou o amior ou o menor sempre da erro e a media tambem
  for(int i=0; i<n; i++){
    if(conta[i].cliente.sexo == 'f'){
      if(i==0){
        menor_saldo_m = conta[i].saldo;
        maior_saldo_m = conta[i].saldo;
      } else{
        if(conta[i].saldo<menor_saldo_m){
          menor_saldo_m = conta[i].saldo;
        }
        if(conta[i].saldo>maior_saldo_m){
          maior_saldo_m = conta[i].saldo;
        }
      }
      soma_saldo_m = soma_saldo_m + conta[i].saldo;
      count_m ++;
    }
    if(conta[i].cliente.sexo == 'm'){
      if(i==0){
        menor_saldo_h = conta[i].saldo;
        maior_saldo_h = conta[i].saldo;
      } else{
        if(conta[i].saldo<menor_saldo_h){
          menor_saldo_h = conta[i].saldo;
        }
        if(conta[i].saldo>maior_saldo_h){
          maior_saldo_h = conta[i].saldo;
        }
      }
      soma_saldo_h = soma_saldo_h + conta[i].saldo;
      count_h ++;
    }
  }
  media_saldo_m = soma_saldo_m / count_m; //obs faltou analisar o caso de nao haver nenhuma mulher ou nao haver nenhum homem
  media_saldo_h = soma_saldo_h / count_h;
  printf("\nMaior saldo entre as mulheres: %.2f", maior_saldo_m);
  printf("\nMenor saldo entre as mulheres: %.2f", menor_saldo_m);
  printf("\nMédia de saldo entre as mulheres: %.2f", media_saldo_m);
  printf("\nMaior saldo entre os homens: %.2f", media_saldo_h);
  printf("\nMenor saldo entre os homens: %.2f", menor_saldo_h);
  printf("\nMédia de saldo entre os homens: %.2f", soma_saldo_h/count_h);

//cliente mais antigo
  for(int i=0;i<n;i++){
    if(i==0){
        menor_ano = conta[i].data.ano;
        menor_mes = conta[i].data.mes;
        menor_dia = conta[i].data.dia;
        num_cliente_menor = 0;
    } else{
        if(conta[i].data.ano<menor_ano){
            menor_ano = conta[i].data.ano;
            menor_mes = conta[i].data.mes;
            menor_dia = conta[i].data.dia;
            num_cliente_menor = i;
        } else if(conta[i].data.ano == menor_ano) {
            if(conta[i].data.mes<menor_mes){
                menor_ano = conta[i].data.ano;
                menor_mes = conta[i].data.mes;
                menor_dia = conta[i].data.dia;
                num_cliente_menor = i;
              } else if(conta[i].data.mes==menor_mes){
                if(conta[i].data.dia<menor_dia){
                    menor_ano = conta[i].data.ano;
                    menor_mes = conta[i].data.mes;
                    menor_dia = conta[i].data.dia;
                    num_cliente_menor = i;
                }
              }
        }
    }
  }
  printf("Cliente mais antigo: %s", conta[num_cliente_menor].cliente.nome);
 
 //cliente com maior lim especial
 for(int i=0; i<n; i++){
    if(conta[i].limite_esp>maior_lim_esp){
        maior_lim_esp = conta[i].limite_esp;
        num_lim_esp = i;
    }
 }
 printf("\nCliente com maior limite especial: %s", conta[num_lim_esp].cliente.nome);

 //clientes com saldos negativos obs faltou analisar se ntinha algum com saldo negativo
 printf("\nClientes com saldo negativo: ");
 for(int i=0; i<n; i++){
    if(conta[i].saldo<0){
        printf("\n%s", conta[i].cliente.nome);
    }
    printf("\n");
 }

 //ordem dos clientes por saldo - obs dando erro
 //explicacao de usar um vetor: se ordenasse direto na struct teria que ordena-la por inteiro para nao baguncar
 /*for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(conta[j].saldo<conta[i].saldo){
            saldos_ordem[i]=conta[j].saldo;
        }
    }
 }
 printf("Saldos em ordem crescente: ");
 for(int i=0; i<n;i++){
    printf("%s", saldos_ordem[i]);
 }*/

 //nova ordenacao saldos, criando o vetor de saldos e ordenando ele
 for(int i=0; i<n; i++){
  saldos[i] = conta[i].saldo;
 }
 for(int i=1; i<n; i++){
  for(int j=0; j<n-1; j++){
    if(saldos[j]>saldos[j+1]){
      aux_troca = saldos[j];
      saldos[j] = saldos[j+1];
      saldos[j+1] = aux_troca;
    }
  }
 }
 printf("Clientes em ordem crescente de saldo bancário: ");
 for(int i=0; i<n; i++){
  j=0;
  while(saldos[i] != conta.saldo[j]){
    j++;
  }
  printf("\n %d - %s %s : R$ %.2f", conta[j].numero_conta, conta[j].cliente.nome, conta[j].cliente.sobrenome, conta[j].saldo);
 }
  
 
    return 0;
}
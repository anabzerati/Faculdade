/*Um provedor de acesso a Internet mantem o seguinte cadastro de clientes: codigo do cliente, e-mail,
numero de horas de acesso, pagina (S-sim ou N-nao). Elaborar um programa em C que calcule e mostre
um relatorio contendo o valor a pagar por cada cliente, sabendo-se que as primeiras 20 horas de acesso
custam R$35,00 e cada hora excedente tem o custo de R$2,50. Os clientes que tem paginas devem ter um
acrescimo de R$40,00 a sua conta. O provedor tem um total de 20 clientes. O programa deve exibir um
relatorio em que cada registro deve aparecer em uma linha. Alem disso, o programa deve exibir o total a
receber.*/

#include <stdio.h>
#define n 4

int main(){
    struct internet{
        int codigo, horas;
        char email[20], paginas;
        float pagamento;
    } cliente[n];
    float total;

    for(int i=0; i<n; i++){
        printf("Insira o código do cliente: ");
        scanf("%d", &cliente[i].codigo);
        printf("Insira o e-mail do cliente: ");
        scanf(" %[^\n]s", cliente[i].email);
        printf("Insira a quantidade de horas usadas pelo cliente: ");
        scanf("%d", cliente[i].horas);
        printf("O cliente possui páginas? Responda <s> para se possuirem e <n> se não possuirem: ");
        scanf("%c", cliente[i].paginas);
    }

    for(int i=0; i<n; i++){
        if(cliente[i].paginas = 's'){
            if(cliente[i].horas<=20){
                cliente[i].pagamento = 75;
            } else {
                cliente[i].pagamento = 75 + (cliente[i].horas-20)*2.5;
            }
        } else{
            if(cliente[i].horas<=20){
                cliente[i].pagamento = 35;
            } else {
                cliente[i].pagamento = 35 + (cliente[i].horas-20)*2.5;
            }
        }
        total = total + cliente[i].pagamento;
    }

    for(int i=0; i<n; i++){
        printf("\nCódigo do cliente: %d\tQuantidade de horas usadas: %d\tPossui páginas?: %c\tTotal a pagar: %f", cliente[i].codigo, cliente[i].horas, cliente[i].paginas, cliente[i].pagamento);
    }
    printf("Total a receber: %f", total);


    return 0;
}
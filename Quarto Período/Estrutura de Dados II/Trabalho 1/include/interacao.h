/* Biblioteca com funções de interação com o usuário ao projeto */
#ifndef INTERACAO_H
#define INTERACAO_H

#include "structs.h"
#include "arquivos.h"

/* Lê dados do filme inseridos pelo usuário e retorna uma struct preenchida */
Filme *leDadosFilme();

/* Recebe uma struct com dados do filme e os imprime na tela*/
void imprimeFilme(Filme *);

/* Faz o intermédio entre ler os dados do filme e ser inserido e chamar a função de inserir. Verifica sucesso e imprime uma mensagem na tela*/
void insercao();

/* Lê dados para a busca, chama a função para realizar a busca binária e, por fim, caso seja encontrado um filme, lê seus dados do arquivo de dados e imprime na tela. Caso não encontre, imrpime mensagem de erro*/
void busca();

/* Lê informações do filme a ser removido, realiza a busca e, caso o encontre, o remove do arquivo de dados e dos índices. Verifica sucesso e imprime uma mensagem na tela*/
void remocao();

/* Lê dados necessários e edita nota de um filme, no arquivo de dados, a partir de sua chave primária. Verifica sucesso e imprime uma mensagem na tela*/
void editarNota();

/* Percorre todo o arquivo de dados (seguindo a ordem alfabética de diretores), lendo o registro para RAM e imprimindo na tela suas informações*/
void listarFilmes();

#endif //INTERACAO_H
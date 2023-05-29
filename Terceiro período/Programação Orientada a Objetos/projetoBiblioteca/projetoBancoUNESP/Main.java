package projetoBancoUNESP;

/**
 * Classe principal/inicial. Utiliza a classe LeituraArquivosJava para ler os arquivos, instanciar objetos e armazenar seus dados. Passa o controle para DisplayBanco pelo login.
 * @param args String[] - argumentos da linha de comando
 * */

public class Main {

	public static void main(String[] args) {
		DisplayBanco meuDisplayBanco;
		LeituraArquivos minhaLeituraArquivos = new LeituraArquivos();
		minhaLeituraArquivos.criaScanner("C:\\Users\\anabe\\Documents\\faculdade\\3 periodo\\POO\\arquivosProjetoBanco\\banco.txt");
		minhaLeituraArquivos.criaScanner("C:\\Users\\anabe\\Documents\\faculdade\\3 periodo\\POO\\arquivosProjetoBanco\\agencias.txt");
		minhaLeituraArquivos.criaScanner("C:\\Users\\anabe\\Documents\\faculdade\\3 periodo\\POO\\arquivosProjetoBanco\\contas.txt");
		meuDisplayBanco = minhaLeituraArquivos.getDisplayBanco();
		meuDisplayBanco.login();
		
	}
	
}
package projetoBancoUNESP;

import java.util.Scanner;
import java.util.logging.Logger;
import java.util.logging.Level;
import java.io.*;

/**
 * Classe utilizada para leitura de arquivos. A partir do caminho do arquivo, cria scanner e preenche objetos das classes Banco, Agencia e Cliente.
 * */

public class LeituraArquivos {
	DisplayBanco meuDisplayBanco;
	
	/** 
	 * método de acesso do atrbuto meuDisplayBanco
	 * @return DisplayBanco - dsiplay instânciado, representa o banco
	 * */
	public DisplayBanco getDisplayBanco(){
		return meuDisplayBanco;
	}
	
	/**
	 * método que cria o Scanner a partir do arquivo. Chama leArquivo para dar continuidade a leitura.
	 * @param caminhoArq String - caminho do arquvio a ser lido
	 * */
	public void criaScanner(String caminhoArq) {
		File arquivo = new File(caminhoArq);
		try{
			Scanner scanner = new Scanner(arquivo);
			leArquivo(arquivo, scanner);
		} catch(FileNotFoundException ex) {
			Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex) ;
		}
	}
	
	/**
	 * método privado, usado por criaScanner. A partir Scanner, lê todo o arquivo, e, de acordo com o nome do arquivo, chama o método necessário para armazenar as informações.
	 * @param arquivo File - armazena o arquivo a ser lido
	 * @param scanner Scanner - para leitura do arquivo
	 * */
	private void leArquivo(File arquivo, Scanner scanner) {
		while(scanner.hasNextLine()) { 
			String linha = scanner.nextLine();
			String[] campos = linha.split("#");
			if(arquivo.getName().equals("banco.txt")) {
				atribuiBanco(campos);
			} else if(arquivo.getName().equals("agencias.txt")) {
				atribuiAgencia(campos);
			} else if(arquivo.getName().equals("contas.txt")) {
				atribuiConta(campos);
			}
		}
	}
	
	/**
	 * método privado, usado por leArquivo. Realiza a atrbuição dos campos às variáveis de instância correspondentes.
	 * @param campos String[] - campos separados.
	 * */
	private void atribuiBanco(String[] campos) {
		meuDisplayBanco = new DisplayBanco(campos[0], Integer.valueOf(campos[1]), campos[2], campos[3]);
	}
	
	/**
	 * método privado, usado por leArquivo. Realiza a atrbuição dos campos às variáveis de instância correspondentes.
	 * @param campos String[] - campos separados.
	 * */
	private void atribuiAgencia(String[] campos) {
		Banco bancoAuxiliar = meuDisplayBanco.getBanco();
		bancoAuxiliar.cadastrarAgencia(campos[0], Integer.valueOf(campos[1]), campos[2], bancoAuxiliar);
	}
	
	/**
	 * método privado, usado por leArquivo. Realiza a atrbuição dos campos às variáveis de instância correspondentes.
	 * @param campos String[] - campos separados.
	 * */
	private void atribuiConta(String[] campos) {
		Agencia agenciaAuxiliar = meuDisplayBanco.getBanco().buscarAgencia(Integer.valueOf(campos[5])); //busca agencia pelo código
		agenciaAuxiliar.cadastrarConta(campos[0], campos[1], campos[2], campos[3], Double.valueOf(campos[4]), Integer.valueOf(campos[6]), Integer.valueOf(campos[7]), agenciaAuxiliar);
	}
	
}

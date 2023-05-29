package projetoBancoUNESP;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Classe que representa um banco. Possui uma lista de agencias com as agencias do banco. Realiza as operações principais de busca, logar, deslogar e operações de depósito, saque, transferência e pix. 
 * */

public class Banco {
	private int numero;
	private String nome;
	private String cnpj;
	private String endereco;
	private Conta contaLogada;
	private ArrayList<Agencia> agencias;
	
	/**
	 * Construtor da classe, recebe informações do banco e instancia um objeto da claase. Instancia a ArrayList de agencias.
	 * @param nome String - nome do banco
	 * @param numero int - número identificador do banco
	 * @param cnpj String - cnpj do banco
	 * @param endereco String - endereço do banco
	 * */
	public Banco(String nome, int numero, String cnpj, String endereco) {
		this.numero = numero;
		this.nome = nome;
		this.cnpj = cnpj;
		this.endereco = endereco;
		
		agencias = new ArrayList<Agencia>();
	}

	/**
	 * Método de acesso ao número do banco.
	 * @return numero int - número do banco.
	 * */
	public int getNumero() {
		return numero;
	}

	/**
	 * Método de acesso ao nome do banco.
	 * @return nome String - nome do banco.
	 * */
	public String getNome() {
		return nome;
	}

	/**
	 * Método de acesso ao cnpj do banco.
	 * @return cnpj int - cnpj do banco.
	 * */
	public String getCnpj() {
		return cnpj;
	}
	
	/**
	 * Método de acesso ao endereço do banco.
	 * @return endereco String - endereço do banco.
	 * */
	public String getEndereco() {
		return endereco;
	}

	/**
	 * Método de acesso à conta logada no banco.
	 * @return contaLogada Conta - conta logada do banco.
	 * */
	public Conta getContaLogada() {
		return contaLogada;
	}
	
	/**
	 * Método para cadastro de nova agencia ao banco. Com as informações da agencia, instancia objeto e adiciona a ArrayList de agencias
	 * @param nome String - nome da agencia
	 * @param codigo int - código identificador da agencia
	 * @param endereco String - endereço da agencia
	 * @param banco Banco - banco ao qual pertence
	 * */
	public void cadastrarAgencia(String nome, int codigo, String endereco, Banco banco) {
		Agencia novaAgencia = new Agencia(nome, codigo, endereco, banco);
		agencias.add(novaAgencia);
	}
	
	/**
	 * Método utilizado para busca de agencia a partir de seu código identificador. Percorre a ArrayList de agencias comparando os códigos. Se encontrar a agencia, retorna sua referência. Se não, retorna null.
	 * @param codigoAgencia int - código da agência buscada
	 * @return a Agencia - referência da agencia buscada 
	 * @return null - referência nula em caso de não encontrar a agência
	 * */
	public Agencia buscarAgencia(int codigoAgencia) {
		for(Agencia a : agencias) {
			if(a.getCodigo() == codigoAgencia) {
				return a;
			}
		}
		return null;
	}
	/**
	 * Método utilizado para busca de conta a partir do cpf. Percorre a ArrayList de agencias, chamando o método buscarConta para cada uma delas. Retorna a referência da conta ( e null se não encontrar ).
	 * @param cpf String - cpf da conta buscada
	 * @return buscada Conta - referência a conta encontrada (ou null)
	 * */
	public Conta buscarConta(String cpf) {
		Conta buscada = null;
		for(Agencia a : agencias) {
			buscada = a.buscarConta(cpf);
			if(buscada != null) {
				return buscada;
			}
		}
		return buscada; //verificar (troquei de null para buscada)
	}
	
	/**
	 * Método utilizado para logar cliente. A partir de suas informações, identifica sua conta e valida sua senha. Caso as senhas sejam correspondentes, atribui a conta ao atributo contaLogada e retorna true (operação bem sucedida). Caso contrário, imprime o erro e retorna false (operação falha)
	 * @param numAgencia int - número da agência informado pelo usuário
	 * @param numConta int - número da conta informado pelo usuário
	 * @param senha int - senha da conta informada pelo usuário
	 * @return boolean - true caso a conta seja logada e false caso não
	 * */
	public boolean logarCliente(int numAgencia, int numConta, int senha) {
		Agencia agenciaCliente;
		Conta contaCliente;
		
		agenciaCliente = buscarAgencia(numAgencia);
		if(agenciaCliente != null) {
			contaCliente = agenciaCliente.buscarConta(numConta);
		
			if(contaCliente != null) {
				if(contaCliente.getSenha() == senha) {
					contaLogada = contaCliente;
					return true;
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	
	/**
	 * Método para deslogar conta. Atribui null ao atributo contaLogada, gerando a perda de referência externa à conta previamente logada
	 * */
	public void deslogarConta() {
		contaLogada = null;
	}
	
	/**
	 * Método que intermdia a operação de saque. Recebe o valor desejado e realiza verificações. Caso a pessoa possa sacar, chama o método sacar da classe Conta. Adiciona a operação na lista de operações da conta.
	 * @param saque double - valor desejado de saque
	 * @return saque double - valor desejado (ou -1, caso o saque não seja possível)
	 * */
	public double realizarSaque(double saque) {
		if(saque > contaLogada.getSaldo()) { 
			System.out.println("Operação bloquada por insuficiencia de saldo.");
			return -1;
		}
		contaLogada.sacar(saque);
		
		contaLogada.adicionarExtrato("Saque", saque, null, false);
		
		return saque;
	}
	
	/**
	 * Método que intermdia a operação de depósito. Recebe o valor desejado e realiza verificações. Caso o valor seja invélido, bloqueia a operação. Caso não, chama o método depositar da classe Conta. Adiciona a operação na lista de operações da conta.
	 * @param deposito double - valor desejado de deposito
	 * */
	public void realizarDeposito(double deposito) {
		if(deposito < 0) { 
			System.out.println("Valor de depósito inválido.");
			return;
		}
		contaLogada.depositar(deposito); 
		
		contaLogada.adicionarExtrato("Depósito", deposito, null, true);
	}
	
	/**
	 * Método que intermedia a operação de transferência. Recebe o valor desejado e informeções da conta a receber. Busca conta e realiza verificações. Caso possível a tranferência, realiza o saque e depósito. Adiciona a operação na lista de operações da conta logada e da que recebe.
	 * 
	 * @param valor double - valor da transferencia
	 * @param codigoAgencia int - código da agencia do destintário
	 * @param numConta int - número da conta destinatária
	 * */
	public void realizarTransferencia(double valor, int codigoAgencia, int numConta) { 
		Conta contaDeposito = buscarAgencia(codigoAgencia).buscarConta(numConta);
		
		if(valor < 0) { 
			System.out.println("Valor de transferencia inválido.");
			return;
		} 
		
		if(contaDeposito == null) {
			System.out.println("Conta inválida.");
			return;
		}
		
		double saque = realizarSaque(valor);
		if(saque != -1) {
			contaDeposito.depositar(valor); 
			System.out.println("Depósito realizado com sucesso.");
		} else {
			System.out.println("Operação cancelada.");
		}
		
		Scanner input = new Scanner(System.in);
		System.out.println("Para visualizar o comprovante, insira 1. Pra continuar sem, insira outro valor");
		int escolha = input.nextInt();
		if(escolha == 1) {
			gerarComprovante(contaDeposito.getNome(), valor);
		}
		
		contaLogada.adicionarExtrato("Transferência", valor, contaDeposito, false);
		contaDeposito.adicionarExtrato("Transferência", valor, contaLogada, true);
	}
	
	/**
	 * Método que intermedia a operação de pix. A partir cpf, busca destinatário e realiza verificações. Caso possível o pix, realiza os saque e depósito no valor determinado. Adiciona a operação na lista de operações da conta logada e da que recebe.
	 * @param valor double - valor do pix
	 * @param cpf String - cpf do destinatário
	 * */
	public void realizarPix(double valor, String cpf) { 
		Conta contaPix = buscarConta(cpf);
		
		if(contaPix == null) {
			System.out.println("CPF inválido");
			return;
		}
		
		if(valor > 0 && valor < contaLogada.getSaldo()) {
			contaLogada.sacar(valor);
			contaPix.depositar(valor);
			System.out.println("PIX realizado com sucesso.");
		}
		
		Scanner input = new Scanner(System.in);
		System.out.println("Para visualizar o comprovante, insira 1. Pra continuar sem, insira outro valor");
		int escolha = input.nextInt();
		if(escolha == 1) {
			gerarComprovante(contaPix.getNome(), valor);
		}
		
		contaLogada.adicionarExtrato("PIX", valor, contaPix, false);
		contaPix.adicionarExtrato("PIX", valor, contaLogada, true);
	}
	
	/**
	 * Método que gera comprovante para operações. Imprime a origem, valor e, se houver, destino da operação.
	 * @param nomeDestinatario String - nome de quem recebe o valor
	 * @param valor double - valor da operação
	 * */
	public void gerarComprovante(String nomeDestinatario, double valor) {
		System.out.println("-----Comprovante-----");
		System.out.println("Origem - nome: " + contaLogada.getNome());
		System.out.println("Valor: " + valor);
		if(nomeDestinatario != null) {
			System.out.println("Destino - nome: " + nomeDestinatario);
		}
		System.out.println("-----Comprovante-----");
	}
	
}
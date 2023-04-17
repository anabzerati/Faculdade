package projetoBancoUNESP;

import java.util.Scanner;

/**
 * Classe mais próxima ao usuário, com quem ele interage. Armazena a referencia para o banco, loga usuário e redireciona ações.
 * */

public class DisplayBanco {
	private Banco meuBanco;
	
	/**
	 * Construtor da classe, recebe informações do banco e instancia um objeto da claase.
	 * @param nome String - nome do banco
	 * @param numero int - número identificador do banco
	 * @param cnpj String - cnpj do banco
	 * @param endereco String - endereço do banco
	 * */
	public DisplayBanco(String nome, int numero, String cnpj, String endereco) {
		meuBanco = new Banco(nome, numero, cnpj, endereco);
	}
	
	/**
	 * Método de acesso à variável de instancia meuBanco
	 * @return meuBanco Banco - referência ao objeto da classe Banco
	 * */
	public Banco getBanco() {
		return meuBanco;
	}
	
	/**
	 * Método que "loga" o usuário ao sistema. A partir das informações recebidas, utliza o método logarCliente da classe Banco. Fica em loop enquanto as informações não estiverem corretas/não for possível logar.
	 * Após possuir usuário, redireciona a tela para telaUsuario.
	 * */
	public void login() {
		Scanner input = new Scanner(System.in);
		System.out.println("Bem-vindo usuário!");
		
		System.out.println("Login");
		System.out.println("Número da agencia: ");
		int numeroAgencia = input.nextInt();
		System.out.println("Número da conta: ");
		int numeroConta = input.nextInt();
		System.out.println("Senha: ");
		int senha = input.nextInt();
				
		meuBanco.logarCliente(numeroAgencia, numeroConta, senha);
			
		if(!meuBanco.logarCliente(numeroAgencia, numeroConta, senha)) {
			System.out.println("Ocorreu um erro durante o login. Operação cancelada.");
			login();
		}
		
		telaUsuario();	
		input.close();
	}
	
	/**
	 * Método privado. Apresenta ao usuário suas opções de ação e, de acordo com a escolha, direciona para o método da operação.
	 * */
	private void telaUsuario() {
		Scanner input = new Scanner(System.in);
		int opcao;
		
		do {
			System.out.println("1- Consultar Saldo; 2- Depósito; 3- Saque; 4- Transferência; 5- Pix; 6- Visualizar extrato; 7- Sair.");
			opcao = input.nextInt();
		
			switch(opcao) {
			case 1: operacaoSaldo();
					break;
			case 2: operacaoDeposito();
					break;
			case 3: operacaoSaque();
					break;
			case 4: operacaoTransferencia();
					break;
			case 5: operacaoPix();
					break;
			case 6: operacaoExtrato();
					break;
			case 7: operacaoDeslogar();
					break;
			}
		} while(opcao != 7);
		input.close();
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe verificar seu saldo. Imprime o saldo.
	 * */
	private void operacaoSaldo() {
		System.out.println("O saldo da conta é de R$" + meuBanco.getContaLogada().getSaldo());
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe realizar um depósito. Recebe valor inserido por usuário e chama o método realizarDeposito da classe Banco. Intermedia operação de depósito.
	 * */
	private void operacaoDeposito() {
		Scanner input = new Scanner(System.in);

		System.out.println("Insira o valor do depósito: ");
		double valor = input.nextDouble();
		meuBanco.realizarDeposito(valor);
		
		System.out.println("Para visualizar o comprovante, insira 1. Pra continuar sem, insira outro valor");
		int escolha = input.nextInt();
		if(escolha == 1) {
			meuBanco.gerarComprovante(null, valor);
		}
		
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe realizar um saque. Recebe valor inserido por usuário e chama o método realizarSaque da classe Banco. Intermedia operação de saque.
	 * */
	private void operacaoSaque() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Insira o valor do saque: ");
		double valor = input.nextDouble();
		meuBanco.realizarSaque(valor);
		
		System.out.println("Para visualizar o comprovante, insira 1. Pra continuar sem, insira outro valor");
		int escolha = input.nextInt();
		if(escolha == 1) {
			meuBanco.gerarComprovante(null, valor);
		}
		
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe realizar uma transferencia. Recebe o código da agencia, número da conta e valor inseridos por usuário e chama o método realizarTransferencia da classe Banco. Intermedia operação de transferencia.
	 * */
	private void operacaoTransferencia() {
		Scanner input = new Scanner(System.in);

		System.out.println("Insira o código da agencia e número da conta");
		int agencia = input.nextInt();
		int conta = input.nextInt();
		System.out.println("Insira o valor da transferencia: ");
		double valor = input.nextDouble();
		
		meuBanco.realizarTransferencia(valor, agencia, conta);
		
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe realizar um pix. Recebe o valor e o cpf inseridos por usuário e chama o método realizarPix da classe Banco. Intermedia operação de pix.
	 * */
	private void operacaoPix() {
		Scanner input = new Scanner(System.in);

		System.out.println("Insira a chave pix (cpf): ");
		String cpf = input.nextLine();
		System.out.println("Insira o valor do pix: ");
		double valor = input.nextDouble();
		
		meuBanco.realizarPix(valor, cpf);
		
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe visualizar seu extrato. Intermedia operação de impressão.
	 * */
	private void operacaoExtrato() {
		meuBanco.getContaLogada().imprimirExtrato();
	}
	
	/**
	 * Método privado chamado por telaUsuario quando o usuário escolhe deslogar a conta. Intermedia s saída da conta.
	 * */
	private void operacaoDeslogar() {
		System.out.println("Deslogando");
		meuBanco.deslogarConta();
		login();
	}
	
}
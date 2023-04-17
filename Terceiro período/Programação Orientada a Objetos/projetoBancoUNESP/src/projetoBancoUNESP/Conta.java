package projetoBancoUNESP;

import java.util.ArrayList;

/**
 * Classe que representa uma conta de banco. Possui agência, número, saldo, senha e uma lista de operações realizadas, além de dados do dono, como nome, endereço, cpf e data de nascimento. Possibilita atualização e valição de senha, realização de saque e de depósito.
 * */

public class Conta {
	private int numero;
	private double saldo;
	private String nome;
	private String endereco;
	private String cpf;
	private String dataNasc;
	private int senha;
	private Agencia agencia;
	private ArrayList<Extrato> extrato;
	
	/**
	 * Construtor da classe, recebe informações da conta e instancia um objeto da clase. Instabcia a ArrayList de extratos.
	 * @param nome String - nome do dono
	 * @param dataNasc String - data de nascimento do dono
	 * @param endereco String - endereço do dono
	 * @param cpf String - cpf do dono
	 * @param saldo double - saldo inicial do dono
	 * @param numero - número da conta
	 * @param senha int - senha da conta
	 * @param agencia Agencia - agencia a qual pertence
	 * */
	public Conta(String nome, String dataNasc, String endereco, String cpf, double saldo, int numero, int senha, Agencia agencia) {
		this.numero = numero;
		this.numero = numero;
		this.saldo = saldo;
		this.nome = nome;
		this.endereco = endereco;
		this.cpf = cpf;
		this.dataNasc = dataNasc;
		this.senha = senha;
		this.agencia = agencia;
		
		extrato = new ArrayList<Extrato>();
	}

	/**
	 * Método de acesso ao número da conta.
	 * @return numero int - número da conta
	 * */
	public int getNumero(){
		return numero;
	}
	
	/**
	 * Método de acesso ao saldo da conta.
	 * @return saldo double - saldo da conta
	 * */
	public double getSaldo() {
		return saldo;
	}
	
	/**
	 * Método de acesso ao nome do dono da conta.
	 * @return nome String - nome do dono da conta
	 * */
	public String getNome() {
		return nome;
	}
	
	/**
	 * Método para modificação do endereço do dono da conta.
	 * @param novoEnder String - novo endereço
	 * */
	public void atualizarEndereco(String novoEnder) {
		endereco = novoEnder;
	}
	
	/**
	 * Método de acesso ao endereço do dono da conta.
	 * @return endereco String - endereço do dono da conta
	 * */
	public String getEndereco() {
		return endereco;
	}	
	
	/**
	 * Método de acesso ao cpf do dono da conta.
	 * @return cpf String - cpf do dono da conta
	 * */
	public String getCPF() {
		return cpf;
	}
	
	/**
	 * Método de acesso à data de nascimento do dono da conta.
	 * @return dataNasc String - data de nascimento do dono da conta
	 * */
	public String getDataNasc() {
		return dataNasc;
	}
	
	/**
	 * Método de acesso à agência da conta.
	 * @return agencia Agencia - agência da conta
	 * */
	public Agencia getAgencia() {
		return agencia;
	}
	
	/**
	 * Método de acesso à senha da conta.
	 * @return senha int - senha da conta
	 * */
	public int getSenha() {
		return senha;
	}
	
	/**
	 * Método para atualização de senha. Recebe a antiga senha e a nova, verifica a antuga e, se for validada, atribui a nova senha.
	 * @param antigaSenha int - senha atual
	 * @param novaSenha int - nova senha desejada
	 * @return boolean - se a senha foi ataulizada, true, se não, false
	 * */
	public boolean atualizarSenha(int antigaSenha, int novaSenha) {
		if(validarSenha(antigaSenha)) {
			this.senha = novaSenha;
			return true;
		}
		
		return false;
	}
	
	/**
	 * Método para validar senha. Recebe senha e compara com a da conta. Se forem compatíveis, retorna true, se não, retorna false.
	 * @param senhaValidar int - senha a ser validada
	 * @return boolean - true se a senha for válida e false se não for
	 * */
	public boolean validarSenha(int senhaValidar) {
		if(senhaValidar == this.senha) {
			return true;
		}
		
		return false;
	}
	
	/**
	 * Método para realizar saque. Recebe o valor e decresce do saldo da conta.
	 * @param saque double - valor a ser sacado
	 * @return saque double - valor sacado
	 * */
	public double sacar(double saque) {
		saldo = saldo - saque;
		return saque;
	}
	
	/**
	 * Método para realizar depósito. Recebe o valor e acresce do saldo da conta.
	 * @param deposito double - valor a ser depositado
	 * */
	public void depositar(double deposito) {
		saldo = saldo + deposito;
	}
	
	/**
	 * Método para adicionar elemnto a lista de extratos. Recebe informações da operação, instancia objetdo da classe Extrato e adiciona a ArrayList extrato.
	 * @param operacao String - nome da operação realizada
	 * @param valor double - valor da operação
	 * @param destino Conta - conta com quem a operação interage
	 * @param positivo boolean - true se a operação é de caráter positivo e false se for negativo
	 * */
	public void adicionarExtrato(String operacao, double valor, Conta destino, boolean positivo) {
		Extrato novoExtrato = new Extrato(operacao, valor, destino, positivo);
		extrato.add(novoExtrato);
	}
	
	/**
	 * Método para imprimir extrato. Imprime informações da conta logada e uma lista das operações realizadas com nome da operação, informações de conta com quem interage (se houver) e valor acrescido ou decrescido da conta.
	 * */
	public void imprimirExtrato() {
		System.out.println("-----Extrato-----");
		System.out.println(nome + " - "  + agencia.getCodigo() + " - " + numero);
		System.out.println();
		for(Extrato e : extrato) {
			if(e.getPositivo()) { //recebeu dinheiro
				if(e.getOutro() == null) { //operação "sozinho"
					System.out.println(e.getOperacao() + ": +" + e.getValor()); //depósito
				} else { //recebeu transferencia de outro
					System.out.println(e.getOperacao() + " from " + e.getOutro().nome + "/" + e.getOutro().getAgencia().getCodigo() + "/" + e.getOutro().getNumero() + ": +" + e.getValor());
				}
			} else { //perdeu dinheiro
				if(e.getOutro() == null) { //operacao "sozinho" - saque
					System.out.println(e.getOperacao() + ": -" + e.getValor());
				} else { //fez transferencia ou mandou pix
					System.out.println(e.getOperacao() + " to " + e.getOutro().nome + "/" + e.getOutro().getAgencia().getCodigo() + "/" + e.getOutro().getNumero() + ": -" + e.getValor());
				}
			}
		}
		System.out.println();
		System.out.println("Saldo final: " + saldo);
		System.out.println("-----Extrato-----");
	}
	
}
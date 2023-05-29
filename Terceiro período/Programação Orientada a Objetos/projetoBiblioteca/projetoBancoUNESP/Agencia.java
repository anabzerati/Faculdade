package projetoBancoUNESP;

import java.util.ArrayList;

/**
 * Classe que representa uma agencia de banco. Possui atributos como código identificador, nome, endereço, o banco ao qual pertence e uma lista de contas. Possibilita cadastrar e buscar contas.
 * */

public class Agencia {
	private int codigo;
	private String nome;
	private String endereco;
	private ArrayList<Conta> contas;
	Banco banco;
	
	/**
	 * Construtor da classe, recebe informações da agencia e instancia um objeto da clase. Instancia a lista de contas.
	 * @param nome String - nome da agencia
	 * @param codigo int - código identificador da agencia
	 * @param endereco String - endereço do banco
	 * @param banco Banco - banco ao qual a agencia pertence
	 * */
	public Agencia(String nome, int codigo, String endereco, Banco banco) {
		super();
		this.codigo = codigo;
		this.nome = nome;
		this.endereco = endereco;
		this.banco = banco;
		
		contas = new ArrayList<Conta>();
	}

	/**
	 * Método de acesso ao código da agência.
	 * @return código int - código da agência.
	 * */
	public int getCodigo() {
		return codigo;
	}

	/**
	 * Método de acesso ao nome da agência.
	 * @return nome String - nome da agência.
	 * */
	public String getNome() {
		return nome;
	}

	/**
	 * Método de acesso ao endereço da agência.
	 * @return endereco String - endereço da agência.
	 * */
	public String getEndereco() {
		return endereco;
	}

	/**
	 * Método de acesso ao banco da agência.
	 * @return banco Banco - banco da agência.
	 * */
	public Banco getBanco() {
		return banco;
	}
	
	/**
	 * Método para cadastro de nova conta à agência. Com as informações da conta, instancia objeto e adiciona a ArrayList de contas.
	 * @param nome String - nome do cliente
	 * @param dataNasc String - data de nascimento do cliente
	 * @param endereco String - endereço do cliente
	 * @param cpf String - cpf do cliente
	 * @param saldo double - saldo inicial do cliente
	 * @param numeroConta int - número da conta do cliente
	 * @param senha int - senha da conta do cliente
	 * @param agencia Agencia - agencia a qual pertence
	 * */
	public void cadastrarConta(String nome, String dataNasc, String endereco, String cpf, double saldo, int numeroConta, int senha, Agencia agencia) {
		Conta novaConta = new Conta(nome, dataNasc, endereco, cpf, saldo, numeroConta, senha, agencia); 
		contas.add(novaConta);
	}
	
	/**
	 * Método utilizado para busca de conta a partir de seu código identificador. Percorre a ArrayList de contas comparando os códigos. Se encontrar a conta, retorna sua referência. Se não, retorna null.
	 * @param numeroConta int - código da conta buscada
	 * @return c Conta - referência da conta encontrada 
	 * @return null - referência nula em caso de não encontrar a conta buscada
	 * */
	public Conta buscarConta(int numeroConta) { 
		for(Conta c : contas) {
			if(c.getNumero() == numeroConta) {
				return c;
			}
		}
		return null;
	}
	
	/**
	 * Método utilizado para busca de conta a partir do cpf do cliente. Percorre a ArrayList de contas comparando os cpfs. Se encontrar a conta, retorna sua referência. Se não, retorna null.
	 * @param cpf String - cpf da conta buscada
	 * @return c Conta - referência da conta encontrada 
	 * @return null - referência nula em caso de não encontrar a conta buscada
	 * */
	public Conta buscarConta(String cpf) {
		for(Conta c : contas) {
			if(c.getCPF().equals(cpf)) { 
				return c;
			}
		}
		return null;
	}

}
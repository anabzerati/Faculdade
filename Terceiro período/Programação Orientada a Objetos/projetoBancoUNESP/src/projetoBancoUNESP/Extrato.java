package projetoBancoUNESP;

/**
 * Classe que representa um extrato. Contém as informações da operação que representa, como nome da operação, valor, conta com quem interage e se a operação é de acréscimo ou decréscimo de dinehiro na conta.
 * */

public class Extrato {
	private String operacao;
	private double valor;
	private Conta outro;
	private boolean positivo;
	
	/**
	 * Construtor da classe, recebe informações da agencia e instancia um objeto da clase.
	 * @param operacao String - nome da operação realizada
	 * @param valor double - valor da operação
	 * @param outro Conta - conta com quem a operação interage
	 * @param positivo boolean - true se a operação é de caráter positivo e false se for negativo
	 * */
	public Extrato(String operacao, double valor, Conta outro, boolean positivo) {
		this.operacao = operacao;
		this.valor = valor;
		this.outro = outro;
		this.positivo = positivo;
	}
	
	/**
	 * Método de acesso ao nome da operação.
	 * @return operacao String - nome da operação
	 * */
	public String getOperacao() {
		return operacao;
	}
	
	/**
	 * Método de acesso ao valor da operação.
	 * @return valor double - valor da operação
	 * */
	public double getValor() {
		return valor;
	}
	
	/**
	 * Método de acesso à conta com quem a operação interage (de quem recebe dinheiro ou para quem manda), sendo que pode ser nula se a operação não possuir interação (como saque e depóisito).
	 * @return outro Conta - conta com quem a operação interage
	 * */
	public Conta getOutro() {
		return outro;
	}
	
	/**
	 * Método de acesso à variável booleana positivo. Ela representa se a conta logada recebeu dinheiro na operação (true) ou se transferiu dinheiro para outra (false).
	 * @return positivo boolean - true se o saldo aumenta pós-operação e false se diminui
	 * */
	public boolean getPositivo() {
		return positivo;
	}
}
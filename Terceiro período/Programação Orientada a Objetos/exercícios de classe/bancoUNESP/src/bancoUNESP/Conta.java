package bancoUNESP;

public class Conta {
	private final String nome;
	private final long cpf;
	private double saldo;
	private final long numeroConta;
	Agencia agencia;
	
	
	public Conta(String nome, long cpf, Agencia agencia) {
		this.nome = nome;
		this.cpf = cpf;
		this.agencia = agencia;
		
		numeroConta = agencia.getNumero();
	}
	
	public String getNome() {
		return nome;
	}
	
	public long getCpf() {
		return cpf;
	}
	
	public void setSaldo(double saldo) {
		if(saldo > 0) {
			this.saldo = saldo;
		}
	}
	
	public double getSaldo() {
		return saldo;
	}
	
	public long getNumeroConta() {
		return numeroConta;
	}
	
	public void depositar(double deposito) {
		if(deposito > 0) {
			saldo = saldo + deposito;
		}
	}
	
	public double sacar(double saque) {
		if(saque > 0 && saque <= saldo) {
			saldo = saldo - saque;
			return saque;
		} else {
			System.out.println("Saldo insuficiente");
			return 0;
		}
	}

	
}

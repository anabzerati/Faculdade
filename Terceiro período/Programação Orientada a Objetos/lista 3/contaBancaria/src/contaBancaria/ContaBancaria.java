package contaBancaria;

public class ContaBancaria {
	private int numeroDaConta;
	private double saldo;
	
	public ContaBancaria(int numeroDaConta, double saldo) throws ValorInvalidoException {
		if(numeroDaConta < 0 || saldo < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		this.numeroDaConta = numeroDaConta;
		this.saldo = saldo;
	}
	
	public int getNumeroDaConta() {
		return numeroDaConta;
	}

	public double getSaldo() {
		return saldo;
	}
	
	public void setSaldo(double valor) {
		saldo = valor;
	}

	public void depositar(double valor) throws ValorInvalidoException {
		if(valor < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		
		saldo = saldo + valor;
	}
	
	public void sacar(double valor) throws ValorInvalidoException {
		if(valor < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		if(valor > saldo) {
			throw new ValorInvalidoException("Valor maior do que saldo");
		}
		
		saldo = saldo - valor;
	}
}
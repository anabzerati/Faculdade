package contaBancaria;

public class ContaCorrente extends ContaBancaria{
	private double limite;
	
	public ContaCorrente(int numeroDaConta, double saldo, double limite) throws ValorInvalidoException {
		super(numeroDaConta, saldo);
		if(limite < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		this.limite = limite;
	}
	
	public double getLimite() {
		return limite;
	}
	
	@Override
	public void sacar(double valor) throws ValorInvalidoException {
		if(valor < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		if(valor > getSaldo()) {
			double restante = valor - getSaldo();
			if(limite < restante) {
				throw new ValorInvalidoException("Valor maior do que o limite");
			}
			System.out.println("Valor maior que saldo, usando limite");
			setSaldo(getSaldo() - valor);
			limite = limite - restante;
		}
	}
}
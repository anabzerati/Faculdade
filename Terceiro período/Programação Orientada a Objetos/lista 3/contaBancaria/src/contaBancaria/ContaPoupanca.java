package contaBancaria;

public class ContaPoupanca extends ContaBancaria {
	private double taxaJuros;
	
	public ContaPoupanca(int numeroDaConta, double saldo, double taxaJuros) throws ValorInvalidoException {
		super(numeroDaConta, saldo);
		if(taxaJuros < 0) {
			throw new ValorInvalidoException("Valor negativo");
		}
		this.taxaJuros = taxaJuros;
	}
	
	public double getTaxaJuros() {
		return taxaJuros;
	}
	
	public void aplicarRendimento() {
		try {
			depositar(getSaldo() * taxaJuros);
		} catch (ValorInvalidoException e) {
			System.out.println("Erro: " + e.getMessage());
			e.printStackTrace();
		}
	}
}
package salarioComissao;

public class Vendedor {
	int salarioFixo = 200;
	double vendas;
	
	public void setVendas(double vendas) {
		this.vendas = vendas;
	}
	
	private double calculaComissao() {
		return vendas*0.09;
	}
	
	public double calculaSalarioFinal() {
		double comissao = calculaComissao();
		return salarioFixo + comissao;
	}
}
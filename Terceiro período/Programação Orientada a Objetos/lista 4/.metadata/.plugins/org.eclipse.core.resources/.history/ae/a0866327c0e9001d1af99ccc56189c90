package controleEstoque;

import java.time.LocalDate;

public class ProdutoPerecivel extends ProdutoAbstrato {
	private LocalDate dataAtual;
	private LocalDate dataVencimento;
	
	public ProdutoPerecivel(String nome, double preco, int quantidade, String id, LocalDate dataVencimento) {
		super(nome, preco, quantidade, id);
		this.dataAtual = LocalDate.now();
		this.dataVencimento = dataVencimento;
	}
	
	public boolean estaVencido() {
		if(dataAtual.isAfter(dataVencimento)) {
			return true;
		}
		return false;
	}
	
	private double calcularDesconto() {
		if(dataVencimento.minusMonths(1).isAfter(dataAtual)) {
			return 0;
		} else if(dataVencimento.minusMonths(1).isEqual(dataAtual)) {
			return 20;
		} else {
			return 50;
		}
	}
	
	@Override
	public double getPreco() {
		double porcentagemDesconto = calcularDesconto();
		return super.getPreco() * (1 - porcentagemDesconto);
	}
}

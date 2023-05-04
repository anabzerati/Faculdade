package controleEstoque;

public class ProdutoNaoPerecivel extends ProdutoAbstrato{
	private String categoria;
	
	public ProdutoNaoPerecivel(String nome, double preco, int quantidade, String id, String categoria) {
		super(nome, preco, quantidade, id);
		this.categoria = categoria;
	}
	
	public String getCategoria() {
		return categoria;
	}

	private double calcularDesconto() {
		if(categoria.contentEquals("Especial")) {
			return 5;
		} 
		return 0;
	}
	
	@Override
	public double getPreco() {
		double desconto = calcularDesconto();
		return super.getPreco() - desconto;
	}
}

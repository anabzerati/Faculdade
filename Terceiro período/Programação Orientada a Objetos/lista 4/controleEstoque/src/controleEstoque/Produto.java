package controleEstoque;

public interface Produto {
	String getNome();
	
	double getPreco();
	
	int getQuantidade();
	
	void setQuantidade(int quantidade);
	
	String getId();
}

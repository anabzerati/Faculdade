package controleEstoque;

import java.util.ArrayList;

public class ControleEstoque {
	private ArrayList<ProdutoAbstrato> produtos = new ArrayList<>();
	
	public void adicionarProduto(ProdutoAbstrato produto) {
		produtos.add(produto);
	}
	
	public ProdutoAbstrato buscarProduto(String id) {
		for(ProdutoAbstrato p : produtos) {
			if(p.getId().equals(id)) {
				return p;
			}
		}
		
		return null;
	}
	
	public void removerProduto(String id) {
		ProdutoAbstrato remover = buscarProduto(id);
		
		if(remover == null) {
			return;
		} else {
			produtos.remove(remover);
		}
	}
	
	public void listarProdutos() {
		for(ProdutoAbstrato p : produtos) {
			if(p instanceof ProdutoPerecivel) {
				System.out.printf("Produto perecível - ");
			} else {
				System.out.printf("Produto não perecível - ");
			}
			System.out.printf("%s - %s - preço: %f", p.getNome(), p.getId(), p.getPreco());
		}
	}

	public void aplicarDesconto(String id) {
		ProdutoAbstrato prod = buscarProduto(id);
		
		prod.setPreco(prod.getPreco());
	}
}

package arvoreBinariaBusca;

public class TreeNode <T extends Comparable<T>> implements Comparable<TreeNode<T>>{
	private T dado;
	private TreeNode<T> esq;
	private TreeNode<T> dir;
	
	public TreeNode(T dado) {
		this.dado = dado;
		esq = null;
		dir = null;
	}
	
	public T get() {
		return dado;
	}

	public void set(T dado) {
		this.dado = dado;
	}

	public void setEsq(TreeNode<T> esq) {
		this.esq = esq;
	}
	
	public TreeNode<T> getEsq(){
		return esq;
	}

	public void setDir(TreeNode<T> dir) {
		this.dir = dir;
	}
	
	public TreeNode<T> getDir(){
		return dir;
	}
	
    @Override
    public int compareTo(TreeNode<T> o) {
        return get().compareTo(o.get());
    }

}

/*Crie uma estrutura de dados árvore de busca binária para armazenar tipos
genéricos
• Crie um aplicativo que utilize a classe Tree

๏ Classe TreeNode
	O tipo armazenado em um nó precisa ser Comparable
	Os atributo de um nós são: dado, referência para o filho esquerdo e referência para filho direito

*
*Classe Tree
	Precisa ser genérica, pois é o tipo de dado que os nós irão armazenar
	Seu único atributo é a referência para o nó raiz
	Implemente um método para Inserção
	Implemente os métodos de Impressão
		preOrder
		inOrder
		posOrder
*/


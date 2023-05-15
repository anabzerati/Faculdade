package arvoreBinariaBusca;

public class Tree <T extends Comparable<T>>{
	TreeNode<T> raiz;
	
    public Tree() {
        raiz = null;
    }
	
	public void inserir(T dado) {
		this.raiz = inserir(raiz, dado);
	}
    
	public void imprimeEmOrdem() {
		imprimeEmOrdem(raiz);
	}
	
	public void imprimePreOrdem() {
		imprimePreOrdem(raiz);
	}
	
	public void imprimePosOrdem() {
		imprimePosOrdem(raiz);
	}
	
	public boolean buscar(T dado) {
		return buscar(raiz, dado);
	}
	
	private void imprimeEmOrdem(TreeNode<T> node){
        if (node == null)
            return;

        imprimeEmOrdem(node.esq);//subarvore esquerda
        System.out.print(node.dado + " ");//raiz no meio
        imprimeEmOrdem(node.dir);//subarvore direita
    }
    
    private void imprimePreOrdem(TreeNode<T> node){
        if (node == null)
            return;

        System.out.print(node.dado + " ");//raiz no começo
        imprimePreOrdem(node.esq);//subarvore esquerda
        imprimePreOrdem(node.dir);//subarvore direita
    }
   
    private void imprimePosOrdem(TreeNode<T> node){
        if (node == null)
            return;

        imprimePosOrdem(node.esq);//subarvore esquerda
        imprimePosOrdem(node.dir);//subarvore direita
        System.out.print(node.dado + " ");//raiz no fim
    }
    
    private TreeNode<T> inserir(TreeNode<T> node, T dado) {
        if (node == null) {
            node = new TreeNode<>(dado);
        } else if (node.dado.compareTo(dado) > 0) {
            node.esq = inserir(node.esq, dado);
        } else if (node.dado.compareTo(dado) < 0) {
            node.dir = inserir(node.dir, dado);
        }
        return node;
    }
    
    private boolean buscar(TreeNode<T> node, T dado) {
        if (node == null) {
            return false;
        } else if (node.dado.compareTo(dado) == 0) {
            return true;
        } else if (node.dado.compareTo(dado) > 0) {
            return buscar(node.esq, dado);
        } else {
            return buscar(node.dir, dado);
        }
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

 
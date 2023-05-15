package arvoreBinariaBusca;

public class Tree <T extends TreeNode<? extends Comparable<T>>>{
	private TreeNode<? extends Comparable<T>> raiz;
	
	public Tree(TreeNode<? extends Comparable<T>> raiz) {
		this.raiz = raiz;
	}
	
	public void inserir(TreeNode<? extends Comparable<T>> node){
		this.raiz = node;
	}
	
	public TreeNode<? extends Comparable<T>> getRaiz() {
		return raiz;
	}
	
	public void ImprimeEmOrdem() {
		ImprimeEmOrdem(raiz);
	}
	
	public void ImprimePreOrdem() {
		ImprimePreOrdem(raiz);
	}
	
	public void ImprimePosOrdem() {
		ImprimePosOrdem(raiz);
	}
	
	private void ImprimeEmOrdem(TreeNode<? extends Comparable<T>> node){
        if (node == null)
            return;

        ImprimeEmOrdem(node.getEsq());//subarvore esquerda
        System.out.print(node.get() + " ");//raiz no meio
        ImprimeEmOrdem(node.getDir());//subarvore direita
    }
    
    private void ImprimePreOrdem(TreeNode<? extends Comparable<T>> node){
        if (node == null)
            return;

        System.out.print(node.get() + " ");//raiz no começo
        ImprimePreOrdem(node.getEsq());//subarvore esquerda
        ImprimePreOrdem(node.getDir());//subarvore direita
    }
   
    private void ImprimePosOrdem(TreeNode<? extends Comparable<T>> node){
        if (node == null)
            return;

        ImprimePosOrdem(node.getEsq());//subarvore esquerda
        ImprimePosOrdem(node.getDir());//subarvore direita
        System.out.print(node.get() + " ");//raiz no fim
    }
    
    public void Inserir(TreeNode<? extends Comparable<T>> valor) {
    	Inserir(valor, raiz);
    }
    
    private void Inserir(TreeNode<? extends Comparable<T>> valor, TreeNode<? extends Comparable<T>> raiz) {//inserir elemento de forma recursiva
    	if (raiz.get() == valor)
    		return;
    	if (raiz.getEsq() == null && raiz.get().compareTo((T) valor) == 1) {
    			TreeNode novoNo = new TreeNode(valor);
    			raiz.setEsq(novoNo);
    		return;//inserir o valor na esquerda caso menor que o valor da raiz
    	} else if (raiz.getDir() == null && raiz.get().compareTo((T) valor) == -1) {
    			TreeNode novoNo = new TreeNode(valor);
    			raiz.setDir(novoNo);
    		return;//inserir o valor na direita caso maior que o valor da raiz
    	}//fazer recursividade com os demais filhos da arvore(os demais elementos da das direitas e esquerdas da árvore)
    	if (valor.get().compareTo((T) raiz.get())) == -1)
    		Inserir(valor, raiz.getEsq());
    	else
    		Inserir(valor, raiz.getDir());
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

/*
public class ArvoreBinaria {
	
	public void ImprimeEmOrdem() {
		ImprimeEmOrdem(raiz);
	}
	
	public void ImprimePreOrdem() {
		ImprimePreOrdem(raiz);
	}
	
	public void ImprimePosOrdem() {
		ImprimePosOrdem(raiz);
	}
	
	public boolean EstritamenteBinaria() {
		return EstritamenteBinaria(raiz);
	}
	
	public int Profundidade() {
		return Profundidade(raiz);
	}
	
	public int QuantidadeNos() {
		return QuantidadeNos(raiz);
	}
	
	public void Insert(int valor) {
	    	Insert(valor, raiz);
	    }
	
	public boolean Search(int valor) {
    	return Search(valor, raiz);
    }
	
	    
    private void ImprimeEmOrdem (Node node){
        if (node == null)
            return;

        ImprimeEmOrdem(node.getNodeLeft());//subarvore esquerda
        	System.out.print(node.getValor() + " ");//raiz no meio
        ImprimeEmOrdem(node.getNodeRight());//subarvore direita
    }
    
    private void ImprimePreOrdem (Node node){
        if (node == null)
            return;

        	System.out.print(node.getValor() + " ");//raiz no começo
        ImprimePreOrdem(node.getNodeLeft());//subarvore esquerda
        ImprimePreOrdem(node.getNodeRight());//subarvore direita
    }
   
    private void ImprimePosOrdem (Node node){
        if (node == null)
            return;

        ImprimePosOrdem(node.getNodeLeft());//subarvore esquerda
        ImprimePosOrdem(node.getNodeRight());//subarvore direita
        	System.out.print(node.getValor() + " ");//raiz no fim
    }
    
    private boolean EstritamenteBinaria(Node node) {
    	if (node == null)
    		return true;
    	if ((node.getNodeLeft() == null && node.getNodeRight() != null) || //caso tenha apenas um filho dos dois lados
    		(node.getNodeLeft() != null && node.getNodeLeft() == null))
    		return false;
    	
    	return EstritamenteBinaria(node.getNodeLeft()) && //atravez de recursividade, voltar nos filhos e fazer o metodo novamente, para percorrer toda a árvore
    		   EstritamenteBinaria(node.getNodeRight());
    }
    
    private int QuantidadeNos (Node node) {//quantidade de nos
	    if (node == null) {
	        return 0;
	    } else {
	        return (QuantidadeNos(node.getNodeRight()) + QuantidadeNos(node.getNodeLeft()) + 1);//recursividade para contar todos os nós
	    }
	}
    
    private int Profundidade (Node tree) {//profundidade da arvore, altura total
	    if (tree == null) {
	        return 0;
	    } else 
	    	return Math.max(Profundidade(tree.getNodeLeft()), 
	    			Profundidade(tree.getNodeRight()))+1;
	    
	}
    
    
    
}

*/
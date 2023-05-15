package arvoreBinariaBusca;

public class TreeNode <T>{
	 T dado;
	 TreeNode<T> esq;
     TreeNode<T> dir;

     TreeNode(T dado) {
         this.dado = dado;
         esq = null;
         dir = null;
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


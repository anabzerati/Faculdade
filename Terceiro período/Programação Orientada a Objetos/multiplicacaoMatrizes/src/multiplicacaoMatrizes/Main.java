package multiplicacaoMatrizes;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int linhas1, colunas1, linhas2, colunas2;
		int[][] matriz1, matriz2, matriz3;
		
		System.out.println("Insira (separando por espaço) a quantidade de linhas e colunas da primeira matriz:");
		linhas1 = input.nextInt();
		colunas1 = input.nextInt();
		
		System.out.println("Insira (separando por espaço) a quantidade de linhas e colunas da segunda matriz:");
		linhas2 = input.nextInt();
		colunas2 = input.nextInt();
		
		if(linhas1 > 0 && colunas1 > 0 && linhas2 > 0 && colunas2 > 0) {
			matriz1 = new int[linhas1][colunas1];
			matriz2 = new int[linhas2][colunas2];
			
			Matriz.preencherMatriz(matriz1);
			Matriz.preencherMatriz(matriz2);
			
			matriz3 = Matriz.multiplicaMatrizes(matriz1, matriz2);
			System.out.println("Resultado da multiplicação das matrizes");
			Matriz.imprimirMatriz(matriz3);
		} else {
			System.out.println("Valores inválidos. Operação cancelada.");
		}
	
		input.close();

	}

}

package multiplicacaoMatrizes;

import java.util.Scanner;

public class Matriz {
	public static void preencherMatriz(int[][] matriz) {
		Scanner input = new Scanner(System.in);
		int i, j;
	
		System.out.println("Preenchendo matriz");
		for(i = 0; i < matriz.length; i++) {
			for(j = 0; j < matriz[0].length; j++) {
				System.out.printf("Elemento [%d][%d] - ", i, j);
				matriz[i][j] = input.nextInt();
			}
		}
	}
	
	public static void imprimirMatriz(int[][] matriz) {
		int i, j;
		
		System.out.println("Imprimindo matriz");
		for(i = 0; i < matriz.length; i++) {
			for(j = 0; j < matriz[0].length; j++) {
				System.out.printf("Elemento [%d][%d] = %d\n", i, j, matriz[i][j]);
			}
		}
	}

	public static int[][] multiplicaMatrizes(int[][] matriz1, int[][] matriz2){
		int[][] matrizNova = null;
		int linhas1, colunas1, linhas2, colunas2;
		
		linhas1 = matriz1.length;
		colunas1 = matriz1[0].length;
		linhas2 = matriz2.length;
		colunas2 = matriz2[0].length;
		
		if(linhas2 == colunas1) { //possível realizar multiplicação
			matrizNova = new int[linhas1][colunas2];
			int soma, k;
			
			for(int i = 0; i < linhas1; i++) {
				for(int j = 0; j < colunas2; j++) {
					soma = 0;
					for(k = 0; k < colunas1; k++) {
						soma = soma + matriz1[i][k] * matriz2[k][j];
					}
					matrizNova[i][j] = soma;
				}
			}
		}
		return matrizNova;
	}
}

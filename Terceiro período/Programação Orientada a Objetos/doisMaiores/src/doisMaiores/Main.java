package doisMaiores;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] vetor = new int[15];
		int i, maior, segundoMaior, indice;
		
		System.out.println("Preenchendo vetor: ");
		for(i = 0; i < 15; i++) {
			System.out.println("Elemento " + (i+1));
			vetor[i] = input.nextInt();		
		}
		
		input.close();
		
		insertionSort(vetor);
		
		maior = vetor[15];
		indice = 14;
		do {
			segundoMaior = vetor[indice];
			indice--;
		} while(maior == segundoMaior);
		
		System.out.println("Maiores elementos: " + maior + segundoMaior);
	}
	
	public static void insertionSort(int[] vetor) {
		int i, j, aux;
		
		for(i = 1; i < vetor.length - 1; i++) {
			j = i;
			aux = vetor[j];
			while(j>0 && vetor[j-1] > aux) {
				vetor[j] = vetor[j - 1];
				j--;
			}
			vetor[j] = aux;
		}
	}

}

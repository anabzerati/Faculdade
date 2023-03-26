package operações;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Operacoes operacao = new Operacoes();
		int n1, n2, n3, flag;
		
		System.out.println("Insira três inteiros separados por espaço: ");
		n1 = input.nextInt();
		n2 = input.nextInt();
		n3 = input.nextInt();
		
		do {
			System.out.println("\nOperações: \n1)Soma; \n2)Produto; \n3)Média; \n4)Maior elemento lido; \n5)Menor elemento lid0; \n0)Sair.");
			flag = input.nextInt();
			
			switch(flag) {
			case 1: System.out.println("Soma = " + operacao.soma(n1, operacao.soma(n2, n3))); 
					break;
			case 2: System.out.println("Produto = " + operacao.produto(n1, operacao.produto(n2, n3)));
					break;
			case 3: System.out.println("Média = " + operacao.media(n1, n2, n3));
					break;
			case 4: System.out.println("Maior elemento lido = " + operacao.maior(n1, operacao.maior(n2, n3)));
					break;
			case 6: System.out.println("Menor elemento lido = " + operacao.menor(n1, operacao.menor(n2, n3)));
					break;
			}
		} while(flag != 0);
		
		input.close();
	}

}
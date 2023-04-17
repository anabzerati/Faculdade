package calculoEuler;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int quant;
		long fat;
		double e = 0;
		
		System.out.println("Insira o número de termos do somatório: ");
		quant = input.nextInt();
		 
		for(int i = 0; i < quant; i++) {
			fat = fatorial(quant);
			e = e + 1/(double)fat;
		}
		
		System.out.println(e);
		
		input.close();

	}
	
	private static long fatorial(int num) {
		int i, fat = 1;
		
		for(i = 1; i <= num; i++) {
			fat = fat * i;
		}
		
		return fat;
	}

}

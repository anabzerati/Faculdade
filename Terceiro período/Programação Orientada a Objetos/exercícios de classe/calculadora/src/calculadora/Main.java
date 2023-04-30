package calculadora;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		try {
			System.out.println("Insira a operação desejada: ");
			char operacao = input.next().charAt(0);
			System.out.println("Valores: ");
			double a = input.nextDouble();
			double b = input.nextDouble();
			System.out.println(a + " " + operacao + " " + b + " = " + Calculadora.calcular(a, b, operacao));
		} catch(InvalidOperationExcepction | ArithmeticException e) {
			System.err.println(e.getMessage());
		} 
		input.close();
	}
}

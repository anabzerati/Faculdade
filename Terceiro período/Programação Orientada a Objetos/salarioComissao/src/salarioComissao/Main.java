package salarioComissao;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double flag;
		
		do {
			System.out.println("Insira a comissão do funcionário ou -1 para parar a aplicação");
			flag = input.nextDouble();
			
			if(flag != -1) {
				Vendedor vendedor = new Vendedor();
				vendedor.setVendas(flag);
				if(flag < 0) {
					System.out.println("Operação inválida! Insira número positivo!");
				} else {
					System.out.printf("Salário = %.2f\n", vendedor.calculaSalarioFinal());
				}
				vendedor = null;
			}		
		} while(flag != -1);

		input.close();
	}

}
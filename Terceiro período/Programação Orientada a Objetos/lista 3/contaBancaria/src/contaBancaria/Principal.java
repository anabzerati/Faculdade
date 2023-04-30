package contaBancaria;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		try {
			ContaPoupanca poupanca = new ContaPoupanca(1, 100.0, 1.5);
			ContaCorrente corrente = new ContaCorrente(2, 100.0, 200.0);
			
			ContaBancaria[] contas = new ContaBancaria[2];
			contas[0] = poupanca;
			contas[1] = corrente;
			
			for(ContaBancaria atual : contas) {
				System.out.println("Conta " + atual.getNumeroDaConta());
				
				int cont = 1;
				while(cont == 1) {
					System.out.println("Opções: 1) Sacar; 2)Depositar");
					int op = input.nextInt();
					
					switch(op) {
					case 1:
						System.out.println("Inisra valor para saque");
						double saque = input.nextDouble();
						try {
							atual.sacar(saque);
						} catch(ValorInvalidoException e) {
							System.out.println("Erro: " + e.getMessage());
						}
						break;
						
					case 2:
						System.out.println("Insira valor para deposito: ");
						double deposito = input.nextDouble();
						try {
							atual.depositar(deposito);
						} catch(ValorInvalidoException e) {
							System.out.println("Erro: " + e.getMessage());
						}
						break;
					}
					
					System.out.println("Se deseja continuar, insira 1");
					cont = input.nextInt();
				}
			}
		} catch (ValorInvalidoException e) {
			System.out.println("Erro: " + e.getMessage());
			e.printStackTrace();
		}
	
		input.close();
	}
}
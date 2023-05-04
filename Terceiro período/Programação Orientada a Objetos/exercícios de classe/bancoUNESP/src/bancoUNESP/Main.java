package bancoUNESP;

public class Main {

	public static void main(String[] args) {
		Agencia agencia1 = new Agencia(1);
		Agencia agencia2 = new Agencia(2);
		Conta conta1 = new Conta("Ana", 123, agencia1);
		Conta conta2 = new Conta("William", 1234, agencia1);
		Conta conta3 = new Conta("cabecinha", 12345, agencia2);
		
		conta1.setSaldo(1000);
		System.out.println("Conta 1: nome: " + conta1.getNome() + " cpf: " + conta1.getCpf() + " numero da conta: " + conta1.getNumeroConta() + " saldo: " + conta1.getSaldo());
		
		conta2.setSaldo(1000000);
		System.out.println("Conta 2: nome: " + conta2.getNome() + " cpf: " + conta2.getCpf() + " numero da conta: " + conta2.getNumeroConta() + " saldo: " + conta2.getSaldo());
		
		System.out.println("Conta 3: nome: " + conta3.getNome() + " cpf: " + conta3.getCpf() + " numero da conta: " + conta3.getNumeroConta() + " saldo: " + conta3.getSaldo());
		
		
		System.out.println("Depositando 120 reais para conta 1");
		conta1.depositar(120);
		System.out.println("Saldo total da conta 1: " + conta1.getSaldo());

		System.out.println("Sacando 120 reais da conta 2");
		conta2.sacar(120);
		System.out.println("Saldo total da conta 2: " + conta2.getSaldo());
		
		System.out.println("Sacando 1 real da conta 3");
		conta3.sacar(1);
		System.out.println("Saldo total da conta 3: " + conta3.getSaldo());
	}

}

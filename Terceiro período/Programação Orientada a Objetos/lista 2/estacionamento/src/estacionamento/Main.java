package estacionamento;

public class Main {
	public static void main(String[] Args) {
		Estacionamento carro = new Estacionamento();
		carro.setModelo("Modelo X");
		carro.setPlaca("123-ABCD");
		carro.setEntrada(1, 15, 22);
		carro.setSaida(2, 35, 20);
		carro.imprimirDados();
		System.out.println("Preço: " + carro.precoTotal()); 
	}
}

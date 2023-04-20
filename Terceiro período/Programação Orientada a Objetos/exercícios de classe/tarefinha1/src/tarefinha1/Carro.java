package tarefinha1;

public class Carro {
	private String marca;
	private String modelo;
	private int ano;
	private float quantidadeGasolina;
	private Homem dono;
	
	public Carro(String marca, String modelo, int ano, float quantidadeGasolina) {
		this.marca = marca;
		this.modelo = modelo;
		this.ano = ano;
		this.quantidadeGasolina = quantidadeGasolina;
	}
	
	public void setDono(Homem dono) {
		this.dono = dono;
	}
	
	public Homem getDono() {
		if(dono == null) {
			System.out.println("Esse carro ainda não tem dono definido");
		}
		return dono;
	}
	
	public void acelerar() {
		if(quantidadeGasolina > 0) {
			System.out.println(dono.getNome() + " está acelerando carro " + modelo);
		} else {
			System.out.println("Quantidade de gasolina insuficiente.");
		}
	}
	
	public void estacionar() {
		System.out.println(dono.getNome() + " estacionou o carro" + modelo);
	}
}

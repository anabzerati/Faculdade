package estacionamento;

import tempo.Tempo;

public class Estacionamento {
	private String placa;
	private String modelo;
	Tempo entrada;
	Tempo saida;

	public Estacionamento() {
		placa = null;
		modelo = null;
		entrada = new Tempo();
		saida = new Tempo();
	}

	public String getPlaca() {
		return placa;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public Tempo getEntrada() {
		return entrada;
	}

	public void setEntrada(Tempo entrada) {
		this.entrada = entrada;
	}
	
	public void setEntrada(int horas, int minutos, int segundos) {
		entrada.setHora(horas);
		entrada.setMinutos(minutos);
		entrada.setSegundos(segundos);
	}

	public Tempo getSaida() {
		return saida;
	}

	public void setSaida(Tempo saida) {
		this.saida = saida;
	}
	
	public void setSaida(int horas, int minutos, int segundos) {
		saida.setHora(horas);
		saida.setMinutos(minutos);
		saida.setSegundos(segundos);
	}
	
	public void imprimirDados() {
		System.out.println("Modelo e placa: " + modelo + " " + placa);
		System.out.println("Entrada: ");
		entrada.imprimir();
		System.out.println("Saída: ");
		saida.imprimir();
	}
	
	public double precoTotal() {
		entrada.subtrair(saida);
		int carry = 0;
		if(entrada.getMinutos() > 45) {
			carry = 1;
		}
		return (entrada.getHoras() + carry) * 1.5 * (-1);
	}
	
}

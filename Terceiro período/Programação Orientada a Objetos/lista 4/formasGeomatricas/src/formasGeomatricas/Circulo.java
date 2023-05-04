package formasGeomatricas;

import java.util.InputMismatchException;

public class Circulo implements FormaGeomatrica{
	private double raio;
	private static final double pi = 3.1415;
	
	public Circulo(double raio) {
		if(raio < 0) {
			throw new InputMismatchException("Raio negativo");
		}
		this.raio = raio;
	}
	
	public double getRaio() {
		return raio;
	}
	
	public double calcularArea() {
		return (pi * raio * raio);
	}
	
	public double calcularPerimetro() {
		return (2 * pi * raio);
	}
	
}

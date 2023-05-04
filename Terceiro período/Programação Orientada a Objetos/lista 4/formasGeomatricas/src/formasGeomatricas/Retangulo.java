package formasGeomatricas;

import java.util.InputMismatchException;

public class Retangulo implements FormaGeomatrica{
	private double base;
	private double altura;
	
	public Retangulo(double base, double altura) {
		if(base < 0 || altura < 0) {
			throw new InputMismatchException("Valor negativo");
		}
		
		this.base = base;
		this.altura = altura;
	}

	public double getBase() {
		return base;
	}

	public double getAltura() {
		return altura;
	}
	
	public double calcularArea() {
		return (base * altura);
	}
	
	public double calcularPerimetro() {
		return (2 * base + 2 * altura);
	}
	
}

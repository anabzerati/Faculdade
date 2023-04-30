package calculadoraFigurasGeometricas;

public class Circulo extends FormaGeometrica {
	private double raio;
	private static final double pi = 3.1415;
	
	public Circulo(double raio) {
		this.raio = raio;
	}

	public double getRaio() {
		return raio;
	}

	public void setRaio(double raio) {
		this.raio = raio;
	}
	
	public double calcularArea() {
		return (pi * raio * raio);
	}
	
	public double calcularPerimetro() {
		return (2 * pi * raio);
	}
}

package calculadoraFigurasGeometricas;

public class Quadrado extends FormaGeometrica {
	private double lado;
	
	public Quadrado(double lado) {
		this.lado = lado;
	}

	public double getLado() {
		return lado;
	}

	public void setLado(double lado) {
		this.lado = lado;
	}
	
	public double calcularArea() {
		return (lado * lado);
	}
	
	public double calcularPerimetro() {
		return (lado * 4);
	}
}

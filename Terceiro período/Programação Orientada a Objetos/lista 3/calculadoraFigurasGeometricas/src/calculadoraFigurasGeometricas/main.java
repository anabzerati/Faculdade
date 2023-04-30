package calculadoraFigurasGeometricas;

public class main {
	public static void main(String[] args) {
		FormaGeometrica[] figuras = new FormaGeometrica[4];
		figuras[0] = new Quadrado(2);
		figuras[1] = new Retangulo(2,3);
		figuras[2] = new Circulo(4);
		figuras[3] = new TrianguloEquilatero(3,4);
		
		for(FormaGeometrica atual : figuras) {
			System.out.println("Forma: " + atual.getClass().getName());
			System.out.println("Área: " + atual.calcularArea());
			System.out.println("Perímetro: " + atual.calcularPerimetro());
		}
	}
}
package tempo;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tempo tempo = new Tempo(9,10,33);
		tempo.imprimir();
		Tempo tempo2 = new Tempo(8, 11, 10);
		tempo.subtrair(tempo2);
		tempo.imprimir();
	}

}

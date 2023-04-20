package zoologico;

public class Vaca extends Animal{
	public Vaca(String nome, int numeroPatas) {
		super(nome, numeroPatas);
	}
	
	@Override
	public void emitirSom() {
		super.emitirSom();
		System.out.println("Muuu");
	}
}

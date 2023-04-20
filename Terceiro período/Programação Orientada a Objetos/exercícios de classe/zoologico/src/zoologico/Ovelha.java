package zoologico;

public class Ovelha extends Animal{
	public Ovelha(String nome, int numeroPatas) {
		super(nome, numeroPatas);
	}
	
	@Override
	public void emitirSom() {
		super.emitirSom();
		System.out.println("Méee");
	}
}

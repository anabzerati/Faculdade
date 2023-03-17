package tarefinha1;

public class Cachorro extends Animal{
	private String dono;
	private String raca;
	private String nome;
	
	public Cachorro(String nome, float peso, String habittat, String dono, String raca) {
		super("Cachorro", peso, habittat);
		this.nome = nome;
		this.dono = dono;
		this.raca = raca;
	}
	
	/*faltam setters e getters*/
	
	public void passearComDono() {
		System.out.println(nome + " está passeando com " + dono);
	}
	
	public void brincarComDono() {
		System.out.println(nome + " está brincando com " + dono);
	}
}
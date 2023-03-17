package tarefinha1;

public class Cachorro extends Animal{
	private Homem dono;
	private String raca;
	private String nome;
	
	public Cachorro(String nome, float peso, String habittat, String raca) {
		super("Cachorro", peso, habittat);
		this.nome = nome;
		this.raca = raca;
	}
	
	public void setDono(Homem dono) {
		this.dono = dono;
	}
	
	public Homem getDono() {
		if(dono == null) {
			System.out.println("Esse cachorro ainda não tem dono definido");
		}
		return dono;
	}
	
	public void passearComDono() {
		System.out.println(nome + " de raça " + raca + " está passeando com " + dono.getNome());
	}
	
	public void brincarComDono() {
		System.out.println(nome + " de raça " + raca + " está brincando com " + dono.getNome());
	}
}
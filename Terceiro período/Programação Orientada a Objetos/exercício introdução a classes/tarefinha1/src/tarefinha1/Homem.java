package tarefinha1;

public class Homem {
	private String nome;
	private String dataNascimento;
	
	public Homem(String nome) {
		this.nome = nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setDataNascimento(String dataNascimento) {
		this.dataNascimento = dataNascimento;
	}
	
	public String getDataNascimento() {
		return dataNascimento;
	}
	
	public void comer() {
		System.out.println(nome + " está comendo");
	}
	
	public void dormir() {
		System.out.println(nome + " está dormindo");
	}
	
}

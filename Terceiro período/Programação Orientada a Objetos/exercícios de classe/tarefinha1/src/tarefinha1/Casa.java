package tarefinha1;

public class Casa {
	private String rua;
	private int numero;
	private Homem morador;
	
	public Casa(String rua, int numero) {
		this.rua = rua;
		this.numero = numero;
	}
	
	public void setMorador(Homem morador) {
		this.morador = morador;
	}
	
	public Homem getMorador() {
		if(morador == null) {
			System.out.println("Essa casa ainda não tem morador definido");
		}
		return morador;
	}

	public void limparCasa() {
		System.out.println("Casa sendo limpa por morador " + morador.getNome());
	}
	
	public void mudarDeCasa() {
		System.out.println("Casa não tem mais morador");
		setMorador(null);
	}
}

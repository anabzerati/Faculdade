package bancoUNESP;

public class Agencia {
	private final long numeroAgencia;
	private long quantidadeContas;
	
	public Agencia(long numeroAgencia) {
		this.numeroAgencia = numeroAgencia;
		quantidadeContas = 0;
	}
	
	public long getNumeroAgencia() {
		return numeroAgencia;
	}
	
	public long getNumero() {
		quantidadeContas++;
		return quantidadeContas;
	}
}

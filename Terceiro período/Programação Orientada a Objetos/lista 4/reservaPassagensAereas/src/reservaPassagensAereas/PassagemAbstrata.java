package reservaPassagensAereas;

import java.time.LocalDateTime;
import java.util.InputMismatchException;

public abstract class PassagemAbstrata {
	private String codigo;
	private double preco;
	private LocalDateTime dataHora;
	private String origem;
	private String destino;
	
	public PassagemAbstrata(String codigo, double preco, LocalDateTime dataHora, String origem, String destino) {
		if(preco < 0) {
			throw new InputMismatchException("Valor negativo");
		}
		this.codigo = codigo;
		this.preco = preco;
		this.dataHora = dataHora;
		this.origem = origem;
		this.destino = destino;
	}
	
	String getCodigo() {
		return codigo;
	}
	
	double getPreco() {
		return preco;
	}
	
	LocalDateTime getDataHora() {
		return dataHora;
	}
	
	String getOrigem() {
		return origem;
	}
	
	String getDestino() {
		return destino;
	}
	
	public abstract double calcularPrecoFinal();
}

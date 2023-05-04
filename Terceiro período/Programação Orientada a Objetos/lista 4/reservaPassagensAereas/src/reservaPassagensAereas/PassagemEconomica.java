package reservaPassagensAereas;

import java.time.LocalDateTime;

public class PassagemEconomica extends PassagemAbstrata {
	public PassagemEconomica(String codigo, double preco, LocalDateTime dataHora, String origem, String destino) {
		super(codigo, preco, dataHora, origem, destino);
	}

	@Override
	public double calcularPrecoFinal() {
		return getPreco();
	}
}

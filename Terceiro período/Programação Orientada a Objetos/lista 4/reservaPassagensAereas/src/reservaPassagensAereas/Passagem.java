package reservaPassagensAereas;

import java.time.LocalDateTime;

public interface Passagem {
	String getCodigo();
	double getPreco();
	LocalDateTime getDataHora();
	String getOrigem();
	String getDestino();
}

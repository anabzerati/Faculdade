package reservaPassagensAereas;

import java.util.ArrayList;

public class SistemaReservas {
	private ArrayList<Passagem> passagens = new ArrayList<>();
	
	public void adicionarPassagem(Passagem passagem) {
		passagens.add(passagem);
	}
	
	Passagem buscarPassagem(String codigo) {
		for(Passagem p : passagens) {
			if(p.getCodigo().equals(codigo)) {
				return p;
			}
		}
		return null;
	}
	
	public void removerPassagem(String codigo) {
		Passagem remover = buscarPassagem(codigo);
		
		if(remover == null) {
			return;
		}
		passagens.remove(remover);
	}
	
	public void listarPassagens() {
		for(Passagem p : passagens) {
			if(p instanceof PassagemEconomica) {
				System.out.printf("Passagem econômica: ");
			} else {
				System.out.printf("Passagem executiva: ");
			}
			System.out.println(p.getCodigo() + " - " + calcularPrecoFinal(p.getCodigo()) + " reais - Origem: " + p.getOrigem() + " Destino: " + p.getDestino());
		}
	}
	
	public double calcularPrecoFinal(String codigo) {
		PassagemAbstrata calcular = (PassagemAbstrata) buscarPassagem(codigo);
		
		return calcular.calcularPrecoFinal();
	}
}
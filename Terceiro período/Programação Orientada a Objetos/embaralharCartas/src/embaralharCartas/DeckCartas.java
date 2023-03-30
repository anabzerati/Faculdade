package embaralharCartas;

import java.security.SecureRandom;

public class DeckCartas {
	private Carta[] deck; //vetor de cartas
	private int cartaAtual;
	private static final int NUMERO_CARTAS = 52; //constante
	private static final SecureRandom numAleatorio = new SecureRandom();
	int i;
	
	public DeckCartas() {
		String[] caras = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
		String[] naipes = {"Ouros", "Espadas", "Paus", "Copas"};
		
		deck = new Carta[NUMERO_CARTAS];
		cartaAtual = 0;
		
		for(i = 0; i < deck.length; i++) {
			deck[i] = new Carta(caras[i%13], naipes[i%4]);
		}
	}
	
	public void embaralhar() {
		cartaAtual = 0;
		
		for(i = 0; i < deck.length; i++) {
			int j = numAleatorio.nextInt(NUMERO_CARTAS);
			Carta aux = deck[i];
			deck[i] = deck[j];
			deck[j] = aux;
		}
	}
	
	public Carta distribuiCarta() {
		if(cartaAtual < deck.length) {
			return deck[cartaAtual++];
		} else {
			return null;
		}
	}
}
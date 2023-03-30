package embaralharCartas;

public class Main {

	public static void main(String[] args) {
		DeckCartas meuDeck = new DeckCartas();
		meuDeck.embaralhar();
		int i;
		
		for(i = 0; i < 52; i++) {
			System.out.println(meuDeck.distribuiCarta());
		}
	}

}
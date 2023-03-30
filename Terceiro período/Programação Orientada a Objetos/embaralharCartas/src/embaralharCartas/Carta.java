package embaralharCartas;

public class Carta {
	private final String cara;
	private final String naipe;
	
	public Carta(String cara, String naipe) {
		this.cara = cara;
		this.naipe = naipe;
	}
	
	public String tornaString() {
		return cara + "de" + naipe;
	}
}
 package editoraLivros;

public class Capitulo {
	private String titulo;
	private int numPag;
	private String autor;
	
	public Capitulo(String titulo, int numPag, String autor) {
		this.titulo = titulo;
		this.numPag = numPag;
		this.autor = autor;
	}

	public String getTitulo() {
		return titulo;
	}

	public int getNumPag() {
		return numPag;
	}

	public String getAutor() {
		return autor;
	}
}

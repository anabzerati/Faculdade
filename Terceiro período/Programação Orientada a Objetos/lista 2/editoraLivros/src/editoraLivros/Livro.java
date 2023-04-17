package editoraLivros;

import java.util.ArrayList;

public class Livro {
	private String titulo;
	private String editor;
	private int ano;
	private int edicao;
	private double preco;
	private ArrayList<Capitulo> capitulos;
	
	public Livro(String titulo, String editor, int ano, int edicao, double preco) {
		this.titulo = titulo;
		this.edicao = edicao;
		this.editor = editor;
		this.ano = ano;
		this.preco = preco;
		capitulos = new ArrayList<Capitulo>();
	}
	
	public String getTitulo() {
		return titulo;
	}

	public String getEditor() {
		return editor;
	}

	public int getAno() {
		return ano;
	}

	public int getEdicao() {
		return edicao;
	}

	public double getPreco() {
		return preco;
	}

	public ArrayList<Capitulo> getCapitulos() {
		return capitulos;
	}

	public void inserirCapitulo(String titulo, int numPag, String autor) {
		Capitulo novoCapitulo = new Capitulo(titulo, numPag, autor);
		capitulos.add(novoCapitulo);
	}
	
	public void imprimir() {
		System.out.println("Editor: " + editor);
		System.out.println("Título: " + titulo);
		System.out.println("Ano: " + ano);
		System.out.println("Edição: " + edicao);
		System.out.println("Preço: " + preco);
		System.out.println("Lista de capítulos: ");
		for(Capitulo c : capitulos) {
			System.out.println(c.getTitulo() + " - " + c.getAutor() + " - " + c.getNumPag() + " páginas");
		}
	}
}

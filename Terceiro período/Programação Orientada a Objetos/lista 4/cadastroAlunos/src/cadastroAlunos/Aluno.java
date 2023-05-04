package cadastroAlunos;

public class Aluno {
	private String matricula;
	private String nome;
	private double nota;
	
	public Aluno(String matricula, String nome) throws MatriculaInvalidaException {
		if(matricula.isEmpty() || matricula.isBlank() || matricula.length() > 10) {
			throw new MatriculaInvalidaException("Valor inválido");
		}
		this.matricula = matricula;
		this.nome = nome;
	}
	
	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getNota() {
		return nota;
	}

	public void setNota(double nota) {
		try {
			validarNota(nota);
			this.nota = nota;
		} catch(NotaInvalidaException e) {
			System.err.println(e.getMessage());
		}
	}

	public void validarNota(double nota) throws NotaInvalidaException {
		if(nota < 0 || nota > 10) {
			throw new NotaInvalidaException("Valor fora do intervalo permitido");
		}
	}
}
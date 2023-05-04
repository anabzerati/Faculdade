package cadastroAlunos;

public class AlunoInexistenteException extends Exception {
private static final long serialVersionUID = 1L;
	
	public AlunoInexistenteException(String message) {
		super(message);
	}
}

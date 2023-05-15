package arquivoUsuario;

public class SenhaInvalidaException extends Exception {
	private static final long serialVersionUID = 1L;
	
	public SenhaInvalidaException(String message) {
		super(message);
	}

}

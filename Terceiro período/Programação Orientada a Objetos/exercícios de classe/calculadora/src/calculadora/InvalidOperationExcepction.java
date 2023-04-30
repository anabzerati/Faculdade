package calculadora;

public class InvalidOperationExcepction extends Exception{
	private static final long serialVersionUID = 1L;

	public InvalidOperationExcepction(String message) {
		super(message);
	}
}

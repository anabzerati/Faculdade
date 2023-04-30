package calculadora;

public class Calculadora {
	public static double calcular(double a, double b, char operacao) throws InvalidOperationExcepction {
		switch(operacao) {
		case '+': 
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(b == 0) {
				throw new ArithmeticException("Divisão por zero");
			}
			return a/b;
		default:
			throw new InvalidOperationExcepction("Operação inválida" + operacao);
		}
	}
}

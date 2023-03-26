package operações;

public class Operacoes {
	public long soma(long n1, long n2) {
		return n1 + n2;
	}
	
	public double media(long n1, long n2, long n3) {
		return (double)(n1 + n2 + n3) / 3;
	}
	
	public long produto(long n1, long n2) {
		return n1 * n2;
	}
	
	public long maior(long n1, long n2) {
		return n1 > n2 ? n1 : n2;
	}

	public long menor(long n1, long n2) {
		return n1 < n2 ? n1 : n2;
	}
}
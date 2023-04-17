package vetor;

public class Vetor {
	public static int[] somar(int[] vetor1, int[] vetor2) {
		int tam1 = vetor1.length;
		int tam2 = vetor2.length;
		int[] resultado;
		int i, j;
		
		if(tam1 > tam2) {
			resultado = new int[tam1];
			for(i = 0; i < tam2; i++) {
				resultado[i] = vetor1[i] + vetor2[i];
			}
			for(j = tam2; j < tam1; j++) {
				resultado[j] = vetor1[j];
			}
		} else {
			resultado = new int[tam2];
			for(i = 0; i < tam1; i++) {
				resultado[i] = vetor1[i] + vetor2[i];
			}
			for(j = tam1; j < tam2; j++) {
				resultado[j] = vetor1[j];
			}
		}
		
		return resultado;
	}
	
	public static double[] somar(double[] vetor1, double[] vetor2) {
		int tam1 = vetor1.length;
		int tam2 = vetor2.length;
		double[] resultado;
		int i, j;
		
		if(tam1 > tam2) {
			resultado = new double[tam1];
			for(i = 0; i < tam2; i++) {
				resultado[i] = vetor1[i] + vetor2[i];
			}
			for(j = tam2; j < tam1; j++) {
				resultado[j] = vetor1[j];
			}
		} else {
			resultado = new double[tam2];
			for(i = 0; i < tam1; i++) {
				resultado[i] = vetor1[i] + vetor2[i];
			}
			for(j = tam1; j < tam2; j++) {
				resultado[j] = vetor1[j];
			}
		}
		
		return resultado;
	}
}

package frequenciaDado;

import java.security.SecureRandom;

public class Main {

	public static void main(String[] args) {
		SecureRandom randomNumbers = new SecureRandom();
		int[] frequency = new int[7];
		int i;
		
		for(i = 0; i < 10000; i++) {
			frequency[1 + randomNumbers.nextInt(6)]++;
		}
		
		System.out.println("Face  Frequency");
		
		for(i = 0; i < frequency.length; i++) {
			System.out.printf("%d  %d\n", i+1, frequency[i+1]);
		}
		
	}

}
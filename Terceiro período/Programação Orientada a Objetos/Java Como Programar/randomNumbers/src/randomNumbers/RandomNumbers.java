package randomNumbers;

import java.security.SecureRandom;

public class RandomNumbers {

	public static void main(String[] args) {
		SecureRandom randomNumbers = new SecureRandom();
		int counter;
		
		for(counter = 0; counter < 20; counter++) {
			int num = 1 + randomNumbers.nextInt(6);
			
			System.out.printf("%d ", num);
		}

	}

}

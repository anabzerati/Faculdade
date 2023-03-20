package maximunFinder;

import java.util.Scanner;

public class MaximunFinder {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter three floating-point values separated by spaces:");
		double number1 = input.nextDouble();
		double number2 = input.nextDouble();
		double number3 = input.nextDouble();
		
		System.out.println("Maximun is " + maximun(number1, number2, number3));
	}
	
	public static double maximun(double x, double y, double z) { /*public pois pode ser chamado por métodos de outras classes e
	static para que possa ser chamado sem objeto (como maximun e main são métodos da mesma classe, main pode chamar diretamente)*/
		double max = x;
		
		if(y > max) {
			max = y;
		}
		
		if(z > max) {
			max = z;
		}
		
		return max;
		
		/*poderiamos usar o math.max(x, math.max(y, z))*/
	}
}

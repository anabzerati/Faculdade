
public class Main {

	public static void main(String[] args) {
		int[] array = new int[10];
		int i, soma = 0;
		
		for(i = 0; i < array.length; i++) {
			array[i] = 10 * i;
		}
		
		i = 0;
		System.out.printf("%s%8s%n", "Index", "Value"); 
		for(int num : array) {
			System.out.printf("%d %d\n", i, num);
			i++;
			soma = soma + num;
		}
		
		System.out.println("Soma dos elementos: " + soma);
	}

}
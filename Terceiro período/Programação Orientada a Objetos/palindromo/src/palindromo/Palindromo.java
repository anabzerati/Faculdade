 package palindromo;
 
 import java.util.Scanner;

public class Palindromo {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int i;
		
		System.out.println("Insira uma palavra ou frase: ");
		String text = input.nextLine();
		
		text = text.replaceAll("\\s", "").toLowerCase();	
		
		
		String textInverso = "";
		for(i = text.length() - 1; i >= 0; i--) {
			textInverso = textInverso + text.charAt(i);
		}
		
		if(text.equals(textInverso)) {
			System.out.println("É palíndromo");
		} else {
			System.out.println("Não é palíndromo");
		}
		
	}

}

package welcome2;
import java.util.Scanner;

public class WelcomeTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); //usado para entrada de dados
		String name;
		
		System.out.println("Enter your name: ");
		name = input.nextLine(); //pega string (linha toda)
		
		Welcome myWelcome = new Welcome(name); //criando novo objeto usando construtor!! nome já definido
		
		System.out.printf("Name = %s\n", myWelcome.getName());
		myWelcome.sayHello();
		
		input.close();

	}

}

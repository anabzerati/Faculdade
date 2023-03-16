package account;
import java.util.Scanner;

public class AccountTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String name;
		double amount;
		int op;
		
		System.out.println("Enter name");
		name = input.nextLine();
		
		Account myAccount = new Account(name);
		
		System.out.printf("Name and initial amount: %s - %.2f\n", myAccount.getName(), myAccount.getBalance());
		
		System.out.println("Enter 1 to deposit and 2 to withdraw: ");
		op = input.nextInt();
		
		if(op == 1) {
			System.out.println("Enter the amount: ");
			amount = input.nextDouble();
			myAccount.deposit(amount);
			System.out.printf("Account balance: %.2f\n", myAccount.getBalance());
		} else if(op == 2) {
			System.out.println("Enter the amount: ");
			amount = input.nextDouble();
			myAccount.withdraw(amount);
			System.out.printf("Account balance: %.2f\n", myAccount.getBalance());
		} else {
			System.out.println("Invalid option!");
		}

		
		input.close();
	}

}

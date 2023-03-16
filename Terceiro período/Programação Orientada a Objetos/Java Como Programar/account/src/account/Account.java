package account;

public class Account {
	private String name;
	private double balance;
	
	public Account(String name){
		this.name = name; 
	}
	
	public void setName(String name){
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public void deposit(double amount) {
		if(amount > 0) {
			balance = balance + amount;
		}
	}
	
	public void withdraw(double amount) {
		if(amount > 0) {
			balance = balance - amount;
		}
	}
}

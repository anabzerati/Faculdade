package commissionEmployee;

public class CommissionEmployee extends Object{
	private final String firstName; 
	private final String lastName; 
	private final String socialSecurityNumber; 
	private double grossSales; // vendas brutas semanais 
	private double commissionRate; // percentagem da comissão

	// construtor de cinco argumentos 
	public CommissionEmployee(String firstName, String lastName, String socialSecurityNumber, double grossSales, double commissionRate){  // a chamada implícita para o construtor padrão de Object ocorre aqui
		// se grossSales é inválido, lança uma exceção
		if (grossSales < 0.0) 
			throw new IllegalArgumentException("Gross sales must be >= 0.0");
	
		// se commissionRate é inválido, lança uma exceção 
		if (commissionRate <= 0.0 || commissionRate >= 1.0)
			throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
	
		this.firstName = firstName; 
		this.lastName = lastName; 
		this.socialSecurityNumber = socialSecurityNumber; 
		this.grossSales = grossSales;
		this.commissionRate = commissionRate;
	} 
	
	public String getFirstName(){
		return firstName;
	}
	
	public String getLastName(){
		return lastName;
	} 
	
	 public String getSocialSecurityNumber(){
		 return socialSecurityNumber;
	 } 
	
	 public void setGrossSales(double grossSales){
		 if (grossSales < 0.0) 
			 	throw new IllegalArgumentException("Gross sales must be >= 0.0");
	
		 this.grossSales = grossSales;
	 } 
	
	 public double getGrossSales(){
		 return grossSales;
	 } 
	
	 public void setCommissionRate(double commissionRate){
		 if (commissionRate <= 0.0 || commissionRate >= 1.0)
			 throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
	
		 this.commissionRate = commissionRate;
	 } 
	
	 public double getCommissionRate(){
		 return commissionRate;
	 } 

	 //calcula lucros
	 public double earnings() { 
		 return commissionRate * grossSales;
	 } 
	 
	 // retorna a representação String do objeto CommissionEmployee
	 @Override //do método toString de Object
	 public String toString(){ 
		 return String.format("%s: %s %s%n%s: %s%n%s: %.2f%n%s: %.2f", "commission employee", firstName, lastName, "social security number", socialSecurityNumber, "gross sales", grossSales, "commission rate", commissionRate); 
	 }
}
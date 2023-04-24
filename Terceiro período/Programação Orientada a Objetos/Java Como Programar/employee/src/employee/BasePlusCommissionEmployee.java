package employee;

public class BasePlusCommissionEmployee extends CommissionEmployee {
	private double baseSalary; //salário-base por semana
	
	public BasePlusCommissionEmployee(String firstName, String lastName, String socialSecurityNumber, double grossSales, double commissionRate, double baseSalary) {
		super(firstName, lastName, socialSecurityNumber, grossSales, commissionRate);
		
		if(baseSalary < 0.0) {
			throw new IllegalArgumentException("Base Salary must be >= 0.0");
		}
		this.baseSalary = baseSalary;
	}

	public double getBaseSalary() {
		return baseSalary;
	}

	public void setBaseSalary(double baseSalary) {
		if(baseSalary < 0.0) {
			throw new IllegalArgumentException("Base Salary must be >= 0.0");
		}
		this.baseSalary = baseSalary;
	}
	
	@Override
	public double earnings() {
		return baseSalary + super.earnings(); 
	}
	
	@Override
	public String toString() {
		return String.format("%s %s%n%s: %.2f", "base-salaried", super.toString(), "base salary", getBaseSalary());
	}

}
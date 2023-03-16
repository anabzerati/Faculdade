package student;

public class Student {
	private String name;
	private double average;
	
	public Student(String name) {
		this.name = name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public void setAverage(double test1, double test2) {
		if(test1>=0.0 && test2>=0.0 && test1<=100.0 & test2<=100.0) {
			average = (test1 + test2)/2.0;
		} else {
			System.out.println("Error in test value");
		}
	}
	
	public double getAverage() {
		return average;
	}
	
	public String getLetterGrade() {
		String letterGrade = "";
		
		if(average >= 90) {
			letterGrade = "A";
		} else if(average >= 80) {
			letterGrade = "B";
		} else if(average >= 70) {
			letterGrade = "C";
		} else if(average >= 60) {
			letterGrade = "D";
		} else {
			letterGrade = "E";
		}
		
		return letterGrade;
	}
	
}

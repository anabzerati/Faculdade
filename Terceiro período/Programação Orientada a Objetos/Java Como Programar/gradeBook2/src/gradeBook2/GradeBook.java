package gradeBook2;

public class GradeBook {
	private String courseName;
	private int[][] grades;
	
	public GradeBook(String courseName, int[][] grades) {
		this.courseName = courseName;
		this.grades = grades;
	}
	
	public String getCourseName() {
		return courseName;
	}
	
	public void processGrades() {
		outputGrades();
		
		System.out.printf("Lowest grade is %d \n Highest grade is %d\n", getLowest(), getHighest());
		
		outputBarChart();
	}
	
	public int getLowest() {
		int lowest = grades[0][0];
		
		for(int[] studentGrades : grades) {
			for(int grade : studentGrades) {
				if(grade < lowest) {
					lowest = grade;
				}
			}
		}
		
		return lowest;
	}
	
	public int getHighest() {
		int highest = grades[0][0];
		
		for(int[] studentGrades : grades) {
			for(int grade : studentGrades) {
				if(grade > highest) {
					highest = grade;
				}
			}
		}
		
		return highest;
	}
	
	public double getAverage(int[] setOfGrades) {
		int sum = 0;
		for(int grade : setOfGrades) {
			sum = sum + grade;
		}
		
		return (double) sum / setOfGrades.length;
	}
	
	public void outputBarChart() {
		int[] frequency = new int[11];
		int i;
		
		System.out.println("Overall grade distribution: ");
		
		for(int[] studentGrades : grades) {
			for(int grade : studentGrades) {
				frequency[grade/10]++;
			}
		}
		
		for(i = 0; i < frequency.length; i++) {
			if(i == 10) {
				System.out.printf("%5d: ", 100);
			} else {
				System.out.printf("%02d-%02d: ", i * 10, i * 10 + 9); 
			}
			
			for(int stars = 0; stars < frequency[i]; stars++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
	}
	
	public void outputGrades() {
		System.out.println("Grades are: ");
		
		for (int test = 0; test < grades[0].length; test++) 
			System.out.printf("Test %d ", test + 1);
		
		System.out.println("Average"); 
		
		for (int student = 0; student < grades.length; student++){
			System.out.printf("Student %2d", student + 1);
			for (int test : grades[student]) 
				System.out.printf("%8d", test); 
			
			double average = getAverage(grades[student]);
			System.out.printf("%9.2f%n", average);
		} 
	}
	
}
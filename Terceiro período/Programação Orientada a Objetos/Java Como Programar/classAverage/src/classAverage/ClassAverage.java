package classAverage;
import java.util.Scanner;

public class ClassAverage {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int total = 0, counter = 0, grade;
		
		do {
			System.out.println("Enter a grade or -1 to quit:");
			grade = input.nextInt();
			
			if(grade != -1) {
				total = total + grade;
				counter++;
			}
			
		} while(grade != -1);

		if(counter != 0) {
			double average = (double) total / counter;
			
			System.out.printf("Total of grades entered: %d\n", counter);
			System.out.printf("Class average: %.2f\n", average);
		} else {
			System.out.println("No grades were entered");
		}
		
	}

}

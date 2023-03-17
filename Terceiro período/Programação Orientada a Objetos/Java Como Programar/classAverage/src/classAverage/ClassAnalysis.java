package classAverage;
import java.util.Scanner;

public class ClassAnalysis {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int passes = 0, failures = 0, counter = 0, grade;
		
		while(counter < 10) {
			System.out.println("Enter exam grade: ");
			grade = input.nextInt();
			
			if(grade >= 6) {
				passes++;
			} else {
				failures++;
			}
			
			counter++;
		}
		
		System.out.printf("Passed %d \n Failed %d\n", passes, failures);
		
		if(passes > 8) {
			System.out.println("Bonus to instructor!");
		}

		input.close();
	}

}

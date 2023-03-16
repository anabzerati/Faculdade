package student;
import java.util.Scanner;

public class StudentTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String studentName;
		double test1Grade, test2Grade;
		
		System.out.println("Enter student's name: ");
		studentName = input.nextLine();
		
		System.out.println("Enter grade1: ");
		test1Grade = input.nextDouble();
		
		System.out.println("Enter grade2: ");
		test2Grade = input.nextDouble();
		
		Student myStudent = new Student(studentName);
		myStudent.setAverage(test1Grade, test2Grade);
		
		System.out.printf("%s's average = %.2f\n", myStudent.getName(), myStudent.getAverage());
		System.out.printf("%s's letter grade = %s\n", myStudent.getName(), myStudent.getLetterGrade());
		
		
		input.close();
	}

}

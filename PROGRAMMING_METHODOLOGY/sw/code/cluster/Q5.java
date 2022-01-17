class Person {
	private String name;
	public Person(String n) { name = n; }
} 
class Undergrad extends Person {
	private char grade; 
	public Undergrad(String n, char g) { super(n); grade = g; }
	public char getGrade() { return grade; }
} 
class Faculty extends Person {
	private int salary;
	public Faculty(String n, int s) { super(n); salary = s; }
	public int getSalary() { return salary; }
} 

public class Q5 {
	public static int countFaculty(Person[] people, int salary) {
		if (people == null) return 0;
		int result = 0;    // 반환할 결과값
	
		for(int i = 0; i < people.length ; i++ ) {
			if (people[i] instanceof Faculty) {
				if ( ((Faculty) people[i]).getSalary() == salary ) result++;
			}
		}
		return result; 
	}
	
	public static void main(String[] args) {
		Person[] people = new Person[3];
		people[0] = new Faculty("a", 100);
		people[1] = new Faculty("b", 100);
		people[2] = new Undergrad("a", 'a');
		System.out.println(countFaculty(people, 100));  // 2
	}
}

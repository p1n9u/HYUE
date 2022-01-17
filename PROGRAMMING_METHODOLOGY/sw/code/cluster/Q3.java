public class Q3 {
	public static String numbersBetween(int num1, int num2) {
		String result = "";
		// fill here! 
		for (int i = num1; i<num2 ; i++) {
			result += i;
			result += " ";
		}
		result += num2;

		return result; 
	}
	public static void main(String[] args) {
		System.out.println(numbersBetween(3, 6)); // 3 4 5 6
		System.out.println(numbersBetween(20, 20)); // 20
	}
}

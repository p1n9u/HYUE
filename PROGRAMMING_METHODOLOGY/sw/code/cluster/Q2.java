public class Q2 {
	public static int countDots(String s) {
		int result = 0;
		for(int i = 0; i<s.length(); i++) {
			if (s.charAt(i) == '.') result++; 
		}
		return result; 
 	}
	public static void main(String[] args) {
		System.out.println(countDots("...I am a boy...")); // 6
		System.out.println(countDots("Here. Take it.")); // 2
	}
}

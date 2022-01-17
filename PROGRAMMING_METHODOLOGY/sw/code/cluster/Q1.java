
public class Q1 {
	public static int foo(int v)  {
		return v;
	}
	public static void main(String[] args) {
		int a = 0; 
		int b = 3; 
		float c = b + 1;
		String s = "abc"; 
		System.out.println(foo((int)c)); // 4
	}
}

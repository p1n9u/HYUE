class ScoreBook {
	private int[] scores; // �л����� ������ �迭 
	private int  n_students; // ���� ������ ��ϵ� �� �л����� ��
	public ScoreBook(int max_students) {
		scores = new int[max_students];
	}
	
	public void add_score (int score) { // �Ѹ��� ������ �߰���� 
		if (n_students == scores.length) return;
		else {
			scores[n_students] = score; 
			n_students++;
		}
	}
	public double getAverage() { // ��� ��� 
		int sum = 0; double avg;
		for (int i = 0; i < n_students ; i++) {
			sum += scores[i];
		}
		avg = (double)sum/n_students;
		return avg;
		
	}
	public double getStdDev() { // ǥ������ ��� 
		double avg = getAverage();
		double sum = 0; 
		for(int i=0 ; i < n_students; i++) {
			double cha = scores[i] - avg;
			sum += Math.pow(cha, 2);
		}
		double var = sum/n_students;
		double std = Math.sqrt(var);
		return std;
	}
}
public class Q4 {
	public static void main(String[] args) {
		ScoreBook sb = new ScoreBook(100);
		sb.add_score(79);
		sb.add_score(98);
		sb.add_score(62);
		System.out.println("Avg : " + sb.getAverage()); // Avg : 79.666...
		System.out.println("StdDev : " + sb.getStdDev()); // StdDev : 14.704...
	}
}

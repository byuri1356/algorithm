import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int num = sc.nextInt();
		int values[] = new int[1000001];

		for (int i = 2; i <= num; i++) {
			int least = values[i - 1];
			if ((i % 3) == 0) {
				least = Math.min(least, values[i / 3]);

			}
			if ((i % 2) == 0) {
				least = Math.min(least, values[i / 2]);
			}
			values[i] = least + 1;
		}
		System.out.println(values[num]);
	}
}
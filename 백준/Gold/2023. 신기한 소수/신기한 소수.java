import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.concurrent.BrokenBarrierException;

public class Main {

	static int N;

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static boolean backtracking(int number) {
		boolean tk = false;
		for (int i = 2; i * i <= number; ++i) {
			if (number % i == 0) {
				tk = true;
				break;
			}
		}

		return tk;
	}

	static void combi(int degree, int number) {
		if (degree != 0) {
			if (backtracking(number))
				return;
			if (degree == N) {
				System.out.println(number);
				return;
			}

		}

		for (int i = 0; i < 10; ++i) {
			combi(degree + 1, number * 10 + i);
		}
	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());

		for (int i = 2; i < 10; ++i) {
			combi(1, i);
		}

	}
}
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int N, R, C, Ans;

	// 재귀는 수식쓰지말고 만들어 쓰세요 ㅜㅜ
	static void recur(int r, int c, int n) {
		if (n == 0)
			return;

		int half = n - 1;

		// 재귀는 수식쓰지말고 만들어 쓰세요 ㅜㅜ
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (r + i * Math.pow(2, half) <= R && r + (i + 1) * Math.pow(2, half) > R
						&& c + j * Math.pow(2, half) <= C && c + (j + 1) * Math.pow(2, half) > C) {
					Ans += Math.pow(2, half) * Math.pow(2, half) * (2 * i + j);
					recur(r + i * (int) Math.pow(2, half), c + j * (int) Math.pow(2, half), half);
					return;
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		// 재귀
		recur(0, 0, N);

		System.out.print(Ans);

	}
}
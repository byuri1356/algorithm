import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; ++t) {
			st = new StringTokenizer(br.readLine());
			long a = Integer.parseInt(st.nextToken());
			long b = Integer.parseInt(st.nextToken());

			long arr[] = new long[(int) b + 1];
			arr[1] = b;

			for (int i = 2; i <= a; ++i) {
				arr[i] = arr[i - 1] * (b - i + 1) / i;
			}

			System.out.println(arr[(int) a]);
		}

	}
}
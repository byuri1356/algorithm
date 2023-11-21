import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int Arr[][];

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {

		// N, M 입력받기
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		Arr = new int[N + 1][N + 1];
		for (int i = 1; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
				Arr[i][j] += Arr[i][j - 1];
			}
		}

		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());

			int total = 0;

			for (int j = x1; j <= x2; ++j) {
				total += Arr[j][y2] - Arr[j][y1 - 1];
			}

			sb.append(total).append("\n");
		}
		System.out.print(sb.toString());
	}
}

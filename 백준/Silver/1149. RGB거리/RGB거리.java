import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {

		int ans = Integer.MAX_VALUE;
		int N = Integer.parseInt(br.readLine());
		int arr[][] = new int[N][3];
		int rgb[][] = new int[N][3];

		// 집 색칠 맵핑
		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		//초기값 설정
		rgb[0][0] = arr[0][0];
		rgb[0][1] = arr[0][1];
		rgb[0][2] = arr[0][2];

		//dp 구하는중...
		for (int i = 1; i < N; ++i) {
			rgb[i][0] = Math.min(rgb[i - 1][1], rgb[i - 1][2]) + arr[i][0];
			rgb[i][1] = Math.min(rgb[i - 1][0], rgb[i - 1][2]) + arr[i][1];
			rgb[i][2] = Math.min(rgb[i - 1][0], rgb[i - 1][1]) + arr[i][2];
		}

		//정답
		ans = Math.min(rgb[N - 1][0], rgb[N - 1][1]);
		ans = Math.min(ans, rgb[N - 1][2]);

		System.out.println(ans);
	}
}
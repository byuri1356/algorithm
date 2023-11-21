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
			int N = Integer.parseInt(br.readLine());
			int arr[][] = new int[N + 2][2];
			boolean dis[][] = new boolean[N + 2][N + 2];
			for (int i = 0; i < N + 2; ++i) {
				st = new StringTokenizer(br.readLine());
				arr[i][0] = Integer.parseInt(st.nextToken());
				arr[i][1] = Integer.parseInt(st.nextToken());
			}

			for (int i = 0; i < N + 2; ++i) {
				for (int j = 0; j < N + 2; ++j) {
					if (Math.abs(arr[i][0] - arr[j][0]) + Math.abs(arr[i][1] - arr[j][1]) <= 1000) {
						dis[i][j] = true;
					}
				}
			}

			for (int i = 0; i < N + 2; ++i) {
				for (int j = 0; j < N + 2; ++j) {
					for (int k = 0; k < N + 2; ++k) {
						dis[j][k] = dis[j][k] || (dis[j][i] && dis[i][k]);
					}
				}
			}
			
			if(dis[0][N+1]) {
				System.out.println("happy");
			}
			else {
				System.out.println("sad");
			}
		}

	}

}

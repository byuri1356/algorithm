import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		int dp[][] = new int[N + 1][K + 1];

		for(int i=0; i<=K; ++i) {
			dp[0][i] = 1;
		}
		
		for (int i = 1; i <= N; ++i) {
			dp[i][1] = 1;
		}

		for (int i = 2; i <= K; ++i) {
			for (int j = 1; j <= N; ++j) {
				dp[j][i] = dp[j-1][i] + dp[j][i-1];
				dp[j][i] %= 1000000000;
			}
		}
		
		System.out.println(dp[N][K]);

	}
}
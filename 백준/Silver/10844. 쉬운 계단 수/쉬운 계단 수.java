import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {

		long ans = 0;
		int N = Integer.parseInt(br.readLine());

		int dp[][] = new int[101][10];

		for (int i = 1; i < 10; ++i) {
			dp[1][i] = 1;
		}
		
		for(int i = 2; i<=N; ++i) {
			dp[i][0] = dp[i-1][1];
			dp[i][9] = dp[i-1][8];
			for(int j=1; j<9; ++j) {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
				dp[i][j] %= 1000000000;
			}
		}
		
		for(int i=0; i<10; ++i) {
			ans += dp[N][i];
		}

		System.out.println(ans % 1000000000);
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, Mid, Ans;
	static boolean Heavy[][], Light[][];

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Mid = (N + 1) / 2;

		Heavy = new boolean[N + 1][N + 1];
		Light = new boolean[N + 1][N + 1];

		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			Heavy[a][b] = true;
			Light[b][a] = true;
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (int k = 1; k <= N; ++k) {
					if (!Heavy[j][k])
						Heavy[j][k] = Heavy[j][i] && Heavy[i][k];
					if (!Light[j][k])
						Light[j][k] = Light[j][i] && Light[i][k];
				}
			}
		}

		for (int i = 1; i <= N; ++i) {
			int heavySum = 0, lightSum = 0;
			for (int j = 1; j <= N; ++j) {
				if (Heavy[i][j])
					heavySum++;
				if (Light[i][j])
					lightSum++;
			}
			if (heavySum >= Mid || lightSum >= Mid)
				Ans++;
		}

		System.out.println(Ans);
	}

}

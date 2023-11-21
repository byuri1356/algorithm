import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, arr[][], ans = Integer.MAX_VALUE;
	static boolean isVisit[];

	static void combi(int end, int cur, int dep, int tt) {
		if(dep == N - 1) {
			if(arr[cur][end] != 0) {
				tt += arr[cur][end];
				ans = Math.min(ans, tt);
			}
			return;
		}
		
		if(tt > ans) return;
		
		for(int i=0; i<N; ++i) {
			if(!isVisit[i] && arr[cur][i] != 0) {
				isVisit[i] = true;
				combi(end, i, dep+1, tt+arr[cur][i]);
				isVisit[i] = false;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		isVisit = new boolean[N];

		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < N; ++i) {
			isVisit[i] = true;
			combi(i, i, 0, 0);
			isVisit[i] = false;
		}

		System.out.println(ans);
	}
}

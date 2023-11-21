import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, Arr[];
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();

	static void combi(int cur, int dep) {
		
		if (dep == M) {
			for (int i = 0; i < M; ++i) {
				sb.append(Arr[i]).append(" ");
			}
			sb.append("\n");
			return;
		}

		
		if (cur == N + 1)
			return;

		Arr[dep] = cur;
		combi(cur + 1, dep + 1);
		combi(cur + 1, dep);
	}

	public static void main(String[] args) throws Exception {

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		Arr = new int[M];

		combi(1, 0);
		System.out.println(sb.toString());
	}
}

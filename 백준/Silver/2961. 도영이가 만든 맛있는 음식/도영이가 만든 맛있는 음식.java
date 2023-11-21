import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int Arr[][];
	static int Ans = Integer.MAX_VALUE;
	static boolean sel[];

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void select(int sour, int bitter, int cur, int dep, int based) {
		if (dep == based) {
			Ans = Math.min(Ans, Math.abs(sour - bitter));
			return;
		}

		if (based - dep > N - cur)
			return;

		select(sour * Arr[cur][0], bitter + Arr[cur][1], cur + 1, dep + 1, based);
		select(sour, bitter, cur + 1, dep, based);
	}

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		Arr = new int[N][2];
		sel = new boolean[N];

		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			Arr[i][0] = Integer.parseInt(st.nextToken());
			Arr[i][1] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= N; ++i) {
			select(1, 0, 0, 0, i);
		}

		System.out.println(Ans);
	}
}
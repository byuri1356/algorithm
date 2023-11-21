import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int R, C, ans;
	static int deltas[][] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	static boolean isVisit[][], isDupli[];
	static String S[];

	static boolean isValid(int x, int y) {
		return (x >= 0 && x < R && y >= 0 && y < C);
	}

	static void DFS(int x, int y, int sum) {
		if (isDupli[S[x].charAt(y) - 'A']) {
			return;
		}

		ans = Math.max(ans, sum);
		isDupli[S[x].charAt(y) - 'A'] = true;

		for (int i = 0; i < 4; ++i) {
			int nextX = x + deltas[i][0];
			int nextY = y + deltas[i][1];

			if (isValid(nextX, nextY) && !isVisit[nextX][nextY]) {
				isVisit[nextX][nextY] = true;
				DFS(nextX, nextY, sum + 1);
				isVisit[nextX][nextY] = false;
			}
		}

		isDupli[S[x].charAt(y) - 'A'] = false;
	}

	public static void main(String[] args) throws Exception {

		// 맵 크기, 사거리
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		S = new String[R];
		isDupli = new boolean[26];
		isVisit = new boolean[R][C];

		for (int i = 0; i < R; ++i) {
			S[i] = br.readLine();
		}

		DFS(0, 0, 1);

		System.out.print(ans);
	}

}
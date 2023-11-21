
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static boolean flag;
	static char Arr[][];
	static int R, C, Ans;

	static void DFS(int x, int y) {
		if (y == 1) {
			Ans++;
			flag = true;
			return;
		}

		for (int i = -1; i <= 1; ++i) {
			int next_x = x + i;
			if (next_x >= 0 && next_x < R && Arr[next_x][y - 1] == '.') {
				Arr[next_x][y - 1] = 'X';
				DFS(next_x, y - 1);
				if (flag)
					return;
			}
		}
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		Arr = new char[R][C];

		for (int i = 0; i < R; ++i) {
			String s = br.readLine();
			for (int j = 0; j < C; ++j) {
				Arr[i][j] = s.charAt(j);
			}
		}

		for (int i = 0; i < R; ++i) {
			if (Arr[i][C - 2] == '.') {
				flag = false;
				DFS(i, C - 2);
			}
		}

		System.out.println(Ans);

	}
}
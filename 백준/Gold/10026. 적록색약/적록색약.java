
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static char Arr[][];
	static int N, notWeak, isWeak;
	static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	static boolean visit[][];

	static boolean isValid(int x, int y) {
		return (x >= 0 && x < N && y >= 0 && y < N);
	}

	static void BFS(int sx, int sy, char pi[]) {
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { sx, sy });

		while (!queue.isEmpty()) {
			int x = queue.peek()[0];
			int y = queue.poll()[1];

			for (int i = 0; i < 4; ++i) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				if (isValid(next_x, next_y) && !visit[next_x][next_y]
						&& (Arr[next_x][next_y] == pi[0] || Arr[next_x][next_y] == pi[1])) {
					visit[next_x][next_y] = true;
					queue.add(new int[] { next_x, next_y });
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());
		Arr = new char[N][N];
		visit = new boolean[N][N];

		for (int i = 0; i < N; ++i) {
			String s = br.readLine();
			for (int j = 0; j < N; ++j) {
				Arr[i][j] = s.charAt(j);
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visit[i][j]) {
					notWeak++;
					visit[i][j] = true;
					BFS(i, j, new char[] { Arr[i][j], Arr[i][j] });
				}
			}
		}

		sb.append(notWeak).append(" ");

		visit = new boolean[N][N];

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visit[i][j]) {
					isWeak++;
					visit[i][j] = true;
					if (Arr[i][j] == 'R' || Arr[i][j] == 'G')
						BFS(i, j, new char[] { 'R', 'G' });
					else
						BFS(i, j, new char[] { 'B', 'B' });
				}
			}
		}

		sb.append(isWeak).append(" ");
		
		System.out.println(sb);
	}
}
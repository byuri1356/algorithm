import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int K, W, H;
	static int arr[][];
	static int skill[][];
	static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	static int hx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }, hy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	static Queue<int[]> q = new LinkedList<>();

	static boolean isValid(int x, int y) {
		return (x >= 0 && x < H && y >= 0 && y < W);
	}

	static void BFS() {
		skill[0][0] = K;
		q.add(new int[] { 0, 0, 0, K });
		while (!q.isEmpty()) {
			int x = q.peek()[0];
			int y = q.peek()[1];
			int t = q.peek()[2];
			int h = q.poll()[3];

			if (x == H - 1 && y == W - 1) {
				System.out.println(t);
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];

				if (isValid(nextX, nextY) && arr[nextX][nextY] > -1) {
					if (arr[nextX][nextY] == 0) {
						arr[nextX][nextY] = t + 1;
						skill[nextX][nextY] = h;
						q.add(new int[] { nextX, nextY, t + 1, h });
					} else if (skill[nextX][nextY] < h) {
						arr[nextX][nextY] = t + 1;
						skill[nextX][nextY] = h;
						q.add(new int[] { nextX, nextY, t + 1, h });
					}
				}
			}

			if (h != 0) {
				for (int i = 0; i < 8; ++i) {
					int nextX = x + hx[i];
					int nextY = y + hy[i];

					if (isValid(nextX, nextY) && arr[nextX][nextY] > -1) {
						if (arr[nextX][nextY] == 0) {
							arr[nextX][nextY] = t + 1;
							skill[nextX][nextY] = h - 1;
							q.add(new int[] { nextX, nextY, t + 1, h - 1 });
						} else if (skill[nextX][nextY] < h - 1) {
							arr[nextX][nextY] = t + 1;
							skill[nextX][nextY] = h - 1;
							q.add(new int[] { nextX, nextY, t + 1, h - 1 });
						}
					}
				}
			}

		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		K = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		arr = new int[H][W];
		skill = new int[H][W];

		for (int i = 0; i < H; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 1)
					arr[i][j] = -1;
			}
		}

		BFS();
		if (arr[H - 1][W - 1] == 0 && skill[H - 1][W - 1] == 0)
			System.out.println(-1);

	}
}
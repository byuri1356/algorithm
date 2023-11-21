import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static class Adj implements Comparable<Adj> {
		int dis, x, y;

		Adj(int dis, int x, int y) {
			this.dis = dis;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Adj o) {
			return this.dis - o.dis;
		}

	}

	static int N, M, ans, islandCnt = 1, arr[][], parent[], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	static ArrayList<int[]> al = new ArrayList<>();
	static PriorityQueue<Adj> pq = new PriorityQueue<>();

	static int find(int x) {
		if (parent[x] == x)
			return x;

		return find(parent[x]);
	}

	static void union(int x, int y, int px, int py) {
		parent[py] = px;
	}

	static boolean isValid(int x, int y) {
		return (x >= 0 && x < N && y >= 0 && y < M);
	}

	static void BFS(int sx, int sy) {
		Queue<int[]> queue = new LinkedList<>();
		arr[sx][sy] = islandCnt;
		queue.add(new int[] { sx, sy });

		while (!queue.isEmpty()) {
			int x = queue.peek()[0];
			int y = queue.poll()[1];

			for (int i = 0; i < 4; ++i) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];

				if (isValid(nextX, nextY) && arr[nextX][nextY] == 1) {
					arr[nextX][nextY] = islandCnt;
					queue.add(new int[] { nextX, nextY });
				}
			}

		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];

		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] == 1) {
					islandCnt++;
					BFS(i, j);
				}
			}
		}

		parent = new int[++islandCnt];
		for (int i = 0; i < islandCnt; ++i) {
			parent[i] = i;
		}

		for (int i = 0; i < N; ++i) {
			int st = -1, ed = -1;
			for (int j = 1; j < M; ++j) {
				if (arr[i][j] == 0 && arr[i][j - 1] != 0) {
					st = j;
				} else if (arr[i][j] != 0 && arr[i][j - 1] == 0) {
					ed = j;
					if (st != -1 && ed - st > 1) {
						pq.add(new Adj(ed - st, arr[i][st - 1], arr[i][ed]));
					}
				}
			}
		}

		for (int i = 0; i < M; ++i) {
			int st = -1, ed = -1;
			for (int j = 1; j < N; ++j) {
				if (arr[j][i] == 0 && arr[j - 1][i] != 0) {
					st = j;
				} else if (arr[j][i] != 0 && arr[j - 1][i] == 0) {
					ed = j;
					if (st != -1 && ed - st > 1) {
						pq.add(new Adj(ed - st, arr[st - 1][i], arr[ed][i]));
					}
				}
			}
		}

		int cnt = 0;
		while (!pq.isEmpty() && cnt != islandCnt - 3) {
			Adj adj = pq.poll();
			int a = find(adj.x);
			int b = find(adj.y);
			if (a != b) {
				union(adj.x, adj.y, a, b);
				ans += adj.dis;
				++cnt;
			}
		}

		if (cnt != islandCnt - 3) {
			System.out.println(-1);
		} else
			System.out.println(ans);
	}

}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, Arr[][], dist[][];
	static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	static PriorityQueue<Pos> pq = new PriorityQueue<>();

	static class Pos implements Comparable<Pos> {
		int x, y, d;

		Pos(int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.d = d;
		}

		@Override
		public int compareTo(Pos o) {
			return this.d - o.d;
		}
	}

	static boolean isValid(int x, int y) {
		return (x >= 0 && x < N & y >= 0 && y < N);
	}

	static void Dijkstra() {
		dist[0][0] = Arr[0][0];
		pq.add(new Pos(0, 0, Arr[0][0]));

		while (!pq.isEmpty()) {
			int curX = pq.peek().x;
			int curY = pq.peek().y;
			int curD = pq.poll().d;

			if (curD > dist[curX][curY])
				continue;

			for (int i = 0; i < 4; ++i) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isValid(nextX, nextY)) {
					int nextD = curD + Arr[nextX][nextY];

					if (nextD < dist[nextX][nextY]) {
						dist[nextX][nextY] = nextD;
						pq.add(new Pos(nextX, nextY, nextD));
					}
				}
			}

		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		int t = 0;

		while (++t != 0) {
			N = Integer.parseInt(br.readLine());
			if (N == 0)
				break;

			Arr = new int[N][N];
			dist = new int[N][N];

			for (int i = 0; i < N; ++i) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; ++j) {
					Arr[i][j] = Integer.parseInt(st.nextToken());
					dist[i][j] = Integer.MAX_VALUE;
				}
			}

			Dijkstra();
			sb.append("Problem ").append(t).append(": ").append(dist[N-1][N-1]).append("\n");
		}

		System.out.println(sb.toString());
	}
}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, D, Sum, Enemy, Ans = 0;
	static int Arr[][], Copy[][], select[] = new int[3];
	static int deltas[][] = { { 0, -1 }, { -1, 0 }, { 0, 1 } };
	static boolean isVisit[][];
	static ArrayList<int[]> al;

	// 적 진군!
	static void advanceEnemy() {
		for (int i = N; i > 0; --i) {
			for (int j = 0; j < M; ++j) {
				Copy[i][j] = Copy[i - 1][j];
			}
		}
	}

	// 화살 쏘기
	static void shooting() {
		for (int[] arr : al) {
			if (Copy[arr[0]][arr[1]] == 1) {
				Copy[arr[0]][arr[1]] = 0;
				Sum++;
			}
		}
	}

	static boolean isValid(int x, int y) {
		return (x > 0 && x <= N && y >= 0 && y < M);
	}

	// 누굴 쏠지 찾는중..
	static void BFS(int sel) {
		if (Copy[N][select[sel]] == 1) {
			al.add(new int[] { N, select[sel] });
			return;
		}

		boolean flag = false;
		isVisit = new boolean[N + 1][M];
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { N, select[sel], 1 });

		while (!queue.isEmpty()) {
			int x = queue.peek()[0];
			int y = queue.peek()[1];
			int tm = queue.poll()[2];

			if (tm >= D)
				break;

			for (int i = 0; i < 3; ++i) {
				int nextX = x + deltas[i][0];
				int nextY = y + deltas[i][1];

				if (isValid(nextX, nextY) && !isVisit[nextX][nextY]) {
					isVisit[nextX][nextY] = true;
					if (Copy[nextX][nextY] == 0)
						queue.add(new int[] { nextX, nextY, tm + 1 });
					else {
						al.add(new int[] { nextX, nextY });
						flag = true;
						break;
					}
				}

			}
			if (flag)
				return;
		}
	}

	// 게임을 진행할 맵 카피
	static void copyArr() {
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < M; ++j) {
				Copy[i][j] = Arr[i][j];
			}
		}
	}

	// 궁수 위치 조합
	static void combi(int cur, int dep) {

		// 궁수 배치 완료~
		if (dep == 3) {
			Sum = 0;
			copyArr();
			for (int i = 0; i < N; ++i) {
				al = new ArrayList<>();
				for (int j = 0; j < 3; ++j) {
					BFS(j);
				}
				shooting();
				advanceEnemy();
			}

			Ans = Math.max(Ans, Sum);
			return;
		}

		if (cur == M)
			return;

		// 궁수 위치 조합중...
		select[dep] = cur;
		combi(cur + 1, dep + 1);
		combi(cur + 1, dep);

	}

	public static void main(String[] args) throws Exception {

		// 맵 크기, 사거리
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		Arr = new int[N + 1][M];
		Copy = new int[N + 1][M];

		// 맵 맵핑
		for (int i = 1; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
				if (Arr[i][j] == 1)
					Enemy++;
			}
		}

		// 궁수위치 조합
		combi(0, 0);

		System.out.print(Ans);
	}

}
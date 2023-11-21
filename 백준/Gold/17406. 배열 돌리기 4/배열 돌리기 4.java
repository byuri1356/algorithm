import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static boolean visit[];
	static int N, M, K, Ans = Integer.MAX_VALUE;
	static int Arr[][];
	static int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
	static ArrayList<int[]> query = new ArrayList<>();
	static Deque<Integer> rotate = new ArrayDeque<>();

	// 배열 돌리기
	static int[][] rotateArr(int[][] copied, int r, int c, int s) {

		for (int i = 1; i <= s; ++i) {
			int cnt = 2 * i;
			int start_x = r - i, start_y = c - i;
			int next_x = r - i, next_y = c - i;
			int dir = 0;
			do {

				next_x += dx[dir];
				next_y += dy[dir];
				rotate.addLast(copied[next_x][next_y]);
				if (cnt == 1) {
					dir = (dir + 1) % 4;
					cnt = 2 * i;
				} else
					cnt--;
			} while (!(next_x == start_x && next_y == start_y));

			rotate.addFirst(rotate.pollLast());

			cnt = 2 * i;
			start_x = r - i;
			start_y = c - i;
			next_x = r - i;
			next_y = c - i;
			do {

				next_x += dx[dir];
				next_y += dy[dir];
				copied[next_x][next_y] = rotate.pollFirst();
				if (cnt == 1) {
					dir = (dir + 1) % 4;
					cnt = 2 * i;
				} else
					cnt--;
			} while (!(next_x == start_x && next_y == start_y));
		}

		return copied;
	}

	// 순열 생성기
	static void permu(int depth, int[][] copy) {

		// 순열 완성!
		if (depth == K) {
			for (int i = 1; i <= N; ++i) {
				int Sum = 0;
				for (int j = 1; j <= M; ++j) {
					Sum += copy[i][j];
				}
				Ans = Math.min(Sum, Ans);
			}

			return;
		}

		// 배열 복사중...
		int copied[][] = new int[N + 1][M + 1];

		for (int i = 1; i <= N; ++i) {
			copied[i] = copy[i].clone();

		}

		// 순열 생성중...
		for (int i = 0; i < K; ++i) {
			if (!visit[i]) {
				visit[i] = true;
				rotateArr(copied, query.get(i)[0], query.get(i)[1], query.get(i)[2]);
				permu(depth + 1, copied);
				for (int j = 1; j <= N; ++j) {
					copied[j] = copy[j].clone();

				}
				visit[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {

		// 배열의 가로 길이 세로 길이, 쿼리 개수
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		Arr = new int[N + 1][M + 1];
		visit = new boolean[K];

		// 배열 맵핑중...
		for (int i = 1; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= M; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// 쿼리 입력받기
		for (int i = 0; i < K; ++i) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			query.add(new int[] { r, c, s });
		}

		// 순열 만들기!
		permu(0, Arr);

		System.out.println(Ans);
	}

}

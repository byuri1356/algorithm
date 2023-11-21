import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 구간 합 구하기 3 -> https://www.acmicpc.net/problem/11658
public class Main {

	// 항상 br, sb, st 는 선언해놓고 시작하는편...
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M; // 배열 크기, 쿼리 수
	static int arr[][]; // 2차원 배열
	static int fwTree[][]; // 2차원 펜윅 트리

	// query == 0 인 경우 구간 합 찾기!
	static int find(int x, int y) {
		int sum = 0;

		// 펜윅트리의 구간 합 찾기는 i 에다가 (i & -i) 를 -= 연산한 것이라는것만 일단 기억해두자! (1차원 펜윅 트리 기준)
		for (int i = x; i > 0; i -= (i & -i)) {
			for (int j = y; j > 0; j -= (j & -j)) {
				sum += fwTree[i][j];
			}
		}

		return sum;
	}

	// fwTree 업데이트 하기!
	static void update(int x, int y, int diff) {

		// 펜윅트리의 업데이트는 i 에다가 (i & -i) 를 += 연산한 것이라는것만 일단 기억해두자! (1차원 펜윅 트리 기준)
		for (int i = x; i <= N; i += (i & -i)) {
			for (int j = y; j <= N; j += (j & -j)) {
				fwTree[i][j] += diff;
			}
		}
	}

	// case 2: 다차원 세그먼트 트리
	public static void main(String[] args) throws IOException {

		// 배열 크기, 쿼리 수 입력
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		// 2차원 배열, 2차원 펜윅 트리 초기화
		arr = new int[N + 1][N + 1];
		fwTree = new int[N + 1][N + 1];

		// 배열 입력 후, 펜윅 트리 업데이트
		for (int i = 1; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken());

				// 핵심 로직 1. 2차원 펜윅 트리 업데이트
				update(i, j, arr[i][j]);
			}
		}

		// 쿼리 입력
		while (M-- != 0) {
			int query, a, b, c, d, ans = 0;

			st = new StringTokenizer(br.readLine());
			query = Integer.parseInt(st.nextToken());

			// 쿼리가 0인 경우 arr[a][b]의 값을 c로 바꾸기!
			if (query == 0) {
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());

				// diff = arr[a][b]들어있는 값과 교체해야 될 값 간의 차이
				int diff = c - arr[a][b];
				arr[a][b] = c;

				// 핵심 로직 1. 2차원 펜윅 트리 업데이트
				update(a, b, diff);
			}

			// 쿼리가 1인 경우 arr[a][b] ~ arr[c][d]구간의 합 구하기!
			else if (query == 1) {
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				d = Integer.parseInt(st.nextToken());

				// 핵심 로직 2. 2차원 펜윅 트리 구간 합 찾기
				ans = find(c, d) - find(c, b - 1) - find(a - 1, d) + find(a - 1, b - 1);

				// 정답 출력!
				System.out.println(ans);
			}
		}
	}
}

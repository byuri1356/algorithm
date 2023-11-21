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

	// CCTV 정보를 저장할 클래스
	static class CCTV {
		ArrayList<int[]> dir;

		CCTV() {
			dir = new ArrayList<>();
		}
	}

	static int N, M, blank, copyBlank, fix[], Arr[][], Copy[][], Ans = Integer.MAX_VALUE;
	static int deltas[][] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	static CCTV cctv[] = new CCTV[6];
	static ArrayList<int[]> pos = new ArrayList<>();

	// 유효한 위치인가?
	static boolean isValid(int x, int y) {
		return (x >= 0 && x < N && y >= 0 && y < M);
	}

	// 맵 탐색중...
	static void BFS(int cctvNum, int cctvDir) {
		boolean isVisit[][] = new boolean[N][M];
		isVisit[pos.get(cctvNum)[0]][pos.get(cctvNum)[1]] = true;
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { pos.get(cctvNum)[0], pos.get(cctvNum)[1] });

		while (!queue.isEmpty()) {
			int x = queue.peek()[0];
			int y = queue.poll()[1];

			// 진짜 변수 길이 실화냐...
			int nextX = x + deltas[cctv[pos.get(cctvNum)[2]].dir.get(fix[cctvNum])[cctvDir]][0];
			int nextY = y + deltas[cctv[pos.get(cctvNum)[2]].dir.get(fix[cctvNum])[cctvDir]][1];

			if (isValid(nextX, nextY) && Copy[nextX][nextY] != 6 && !isVisit[nextX][nextY]) {
				isVisit[nextX][nextY] = true;
				queue.add(new int[] { nextX, nextY });
				if (Copy[nextX][nextY] == 0) {
					Copy[nextX][nextY] = 1;
					copyBlank--;
				}
			}
		}

	}

	// 맵 복사중...
	static void copyMap() {
		copyBlank = blank;
		Copy = new int[N][M];

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				Copy[i][j] = Arr[i][j];
			}
		}

	}

	// 조합 만들기
	static void combi(int cur, int dep) {

		// 방향 세팅 완료!
		if (dep == pos.size()) {
			copyMap();
			for (int i = 0; i < pos.size(); ++i) {
				for (int j = 0; j < cctv[pos.get(i)[2]].dir.get(fix[i]).length; ++j) {
					BFS(i, j);
				}
			}

			Ans = Math.min(Ans, copyBlank);
			return;
		}

		// CCTV 방향 세팅중...
		for (int i = 0; i < cctv[pos.get(cur)[2]].dir.size(); ++i) {
			fix[cur] = i;
			combi(cur + 1, dep + 1);
		}

	}

	// cctv 탐색가능 방향 맵핑
	static void setCCTV() {
		for (int i = 0; i < 6; ++i) {
			cctv[i] = new CCTV();
		}

		cctv[1].dir.add(new int[] { 0 });
		cctv[1].dir.add(new int[] { 1 });
		cctv[1].dir.add(new int[] { 2 });
		cctv[1].dir.add(new int[] { 3 });

		cctv[2].dir.add(new int[] { 0, 2 });
		cctv[2].dir.add(new int[] { 1, 3 });

		cctv[3].dir.add(new int[] { 0, 1 });
		cctv[3].dir.add(new int[] { 1, 2 });
		cctv[3].dir.add(new int[] { 2, 3 });
		cctv[3].dir.add(new int[] { 3, 0 });

		cctv[4].dir.add(new int[] { 0, 1, 2 });
		cctv[4].dir.add(new int[] { 1, 2, 3 });
		cctv[4].dir.add(new int[] { 2, 3, 0 });
		cctv[4].dir.add(new int[] { 3, 0, 1 });

		cctv[5].dir.add(new int[] { 0, 1, 2, 3 });
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Arr = new int[N][M];

		setCCTV();

		// 맵 맵핑
		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
				if (Arr[i][j] == 0)
					blank++;
				else if (Arr[i][j] == 6)
					continue;
				else {
					pos.add(new int[] { i, j, Arr[i][j] });
				}

			}
		}

		// 조합 고르기
		fix = new int[pos.size()];
		combi(0, 0);

		System.out.println(Ans);

	}

}

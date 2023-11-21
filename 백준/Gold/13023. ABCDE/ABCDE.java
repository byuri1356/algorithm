import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	// 너와 나의 친구 관계
	static class friends {
		ArrayList<Integer> relation = new ArrayList<>();
	}

	static int N, M, start, isVisit[];
	static boolean flag;
	static friends f[];

	// DFS
	static void DFS(int cur, int dep) {

		// 기저 조건
		if (dep == 4) {
			flag = true;
			return;
		}

		// 이미 친구를 다 찾은 경우
		if (flag)
			return;

		// 친구 찾는중...
		for (int frd : f[cur].relation) {
			if (isVisit[frd] != start) {
				isVisit[frd] = start;
				DFS(frd, dep + 1);
				isVisit[frd] = -1;

				if (flag)
					return;
			}
		}
	}

	public static void main(String[] args) throws Exception {

		// 사람 수, 관계 수
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		f = new friends[N];
		isVisit = new int[N];

		Arrays.fill(isVisit, -1);

		for (int i = 0; i < N; ++i) {
			f[i] = new friends();
		}

		// 친구 관계 형성
		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			f[a].relation.add(b);
			f[b].relation.add(a);
		}

		// 한명씩 돌면서 친구 찾기
		for (int i = 0; i < N; ++i) {
			if (flag)
				break;

			start = i;
			isVisit[i] = i;
			DFS(i, 0);
		}

		if (flag)
			System.out.println(1);
		else
			System.out.println(0);
	}

}

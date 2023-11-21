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

	static int N, Total, Ans = Integer.MAX_VALUE, ppl[];
	static boolean flag, isSelect[], Visit[], checkVisit[];
	static ArrayList<Integer> al[];
	static Queue<Integer> queue;

	static void BFS(int start) {
		checkVisit = new boolean[N + 1];
		checkVisit[start] = true;
		queue = new LinkedList<>();
		queue.add(start);

		while (!queue.isEmpty()) {
			int cur = queue.poll();

			for (int i = 0; i < al[cur].size(); ++i) {
				int nextN = al[cur].get(i);

				if (!checkVisit[nextN] && Visit[nextN]) {
					checkVisit[nextN] = true;
					queue.add(nextN);
				}
			}

		}

		for (int i = 1; i <= N; ++i) {
			if (checkVisit[i] != Visit[i]) {
				flag = false;
				break;
			}
		}

	}

	static void combi(int cur, int sel, int dep, int sum) {
		if (sel == dep) {
			flag = true;
			Visit = new boolean[N + 1];
			for (int i = 1; i <= N; ++i) {
				if (isSelect[i])
					Visit[i] = true;
			}

			for (int i = 1; i <= N; ++i) {
				if (isSelect[i]) {
					BFS(i);
					break;
				}
			}

			Visit = new boolean[N + 1];

			for (int i = 1; i <= N; ++i) {
				if (!isSelect[i])
					Visit[i] = true;
			}

			for (int i = 1; i <= N; ++i) {
				if (!isSelect[i]) {
					BFS(i);
					break;
				}
			}

			if (flag) {
				Ans = Math.min(Ans, Math.abs(Total - sum - sum));
			}

			return;
		}

		for (int i = cur; i <= N; ++i) {
			if (!isSelect[i]) {
				isSelect[i] = true;
				combi(i + 1, sel + 1, dep, sum + ppl[i]);
				isSelect[i] = false;
			}
		}

	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());
		ppl = new int[N + 1];
		isSelect = new boolean[N + 1];

		al = new ArrayList[N + 1];
		for (int i = 0; i <= N; ++i) {
			al[i] = new ArrayList<>();
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; ++i) {
			ppl[i] = Integer.parseInt(st.nextToken());
			Total += ppl[i];
		}

		for (int i = 1; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			for (int j = 0; j < M; ++j) {
				al[i].add(Integer.parseInt(st.nextToken()));
			}
		}

		for (int i = 1; i < N; ++i) {
			combi(1, 0, i, 0);
		}

		if (Ans == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(Ans);
	}

}

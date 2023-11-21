import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static class Pair {
		int x;
		int y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

	}

	static int N, M, Ans = Integer.MAX_VALUE;
	static int Arr[][], combination[];
	static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	static boolean visit[][];
	static List<Pair> house = new ArrayList<>();
	static List<Pair> chicken = new ArrayList<>();

	static void combi(int cur, int depth) {
		//조합 완성~!
		if (depth == M) {
			int res = 0;
			for (int i = 0; i < house.size(); ++i) {
				int dis = Integer.MAX_VALUE;
				for (int j = 0; j < depth; ++j) {
					int x = chicken.get(combination[j]).x;
					int y = chicken.get(combination[j]).y;
					dis = Math.min(dis, Math.abs(house.get(i).x - x) + Math.abs(house.get(i).y - y));
				}
				res += dis;
			}

			Ans = Math.min(Ans, res);
			return;
		}

		//조합 만드는 중...
		for (int i = cur; i < chicken.size(); ++i) {
			combination[depth] = i;
			combi(i + 1, depth + 1);
		}
	}

	public static void main(String[] args) throws Exception {

		// 배열 크기와, 선택할 치킨집 초기화
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		Arr = new int[N][N];
		combination = new int[M];

		// 맵 맵핑, 동시에 치킨집과, 집 위치 저장
		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
				if (Arr[i][j] == 1)
					house.add(new Pair(i, j));
				else if (Arr[i][j] == 2)
					chicken.add(new Pair(i, j));
			}
		}

		// 조합 만들기~
		combi(0, 0);
		System.out.println(Ans);
	}
}

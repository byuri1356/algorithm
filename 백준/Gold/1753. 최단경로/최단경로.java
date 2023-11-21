import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	// 간선 정보를 나타낼 Pair 클래스
	static class Pair implements Comparable<Pair> {
		int dst, wgt;

		Pair(int dst, int wgt) {
			this.dst = dst;
			this.wgt = wgt;
		}

		@Override
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return this.wgt - o.wgt;
		}
	}

	// 각종 변수들
	static int V, E, startV, dist[];
	static ArrayList<Pair> edge[];
	static PriorityQueue<Pair> pq = new PriorityQueue<>();

	//데이크스트라
	static void Dijkstra() {

		while (!pq.isEmpty()) {
			int curV = pq.peek().dst;
			int curD = pq.poll().wgt;

			if (dist[curV] < curD)
				continue;

			for (int i = 0; i < edge[curV].size(); ++i) {
				int nextV = edge[curV].get(i).dst;
				int nextD = curD + edge[curV].get(i).wgt;

				if (dist[nextV] > nextD) {
					dist[nextV] = nextD;
					pq.add(new Pair(nextV, nextD));
				}
			}
		}
	}

	// 초기화 클래스
	static void initInfo() {
		// 간선 초기화
		edge = new ArrayList[V + 1];
		for (int i = 0; i < V + 1; ++i) {
			edge[i] = new ArrayList<>();
		}

		// 거리 초기화
		dist = new int[V + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);

		dist[startV] = 0;
		pq.add(new Pair(startV, 0));
	}

	public static void main(String[] args) throws Exception {

		// 정점 간선 개수 입력받기
		st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		// 시작 점 입력받기
		startV = Integer.parseInt(br.readLine());

		initInfo();

		// 간선 정보 입력받기
		for (int i = 0; i < E; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			edge[a].add(new Pair(b, c));
		}

		// 데이크스트라
		Dijkstra();

		// 출력
		for (int i = 1; i <= V; ++i) {
			if (dist[i] == Integer.MAX_VALUE)
				System.out.println("INF");
			else
				System.out.println(dist[i]);
		}
	}

}

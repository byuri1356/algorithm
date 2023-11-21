import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	// 간선 정보
	static class vertex {
		ArrayList<Integer> al;

		vertex() {
			al = new ArrayList<>();
		}
	}

	static int N, M, V;
	static boolean isVisit[];
	static vertex vtx[];

	// BFS
	static void BFS(int start) {
		
		//시작점 넣어주기~
		Queue<Integer> queue = new LinkedList<>();
		queue.add(start);
		isVisit[start] = true;

		//방문 가능한 점이 있는 경우
		while (!queue.isEmpty()) {
			int curV = queue.poll();

			sb.append(curV).append(" ");

			//방문하지 않았던 점 큐에 넣기~
			for (int i = 0; i < vtx[curV].al.size(); ++i) {
				int nextV = vtx[curV].al.get(i);

				if (!isVisit[nextV]) {
					isVisit[nextV] = true;
					queue.add(nextV);
				}
			}
		}
	}

	// DFS
	static void DFS(int start) {

		// 출력, 방문 설정
		sb.append(start).append(" ");
		isVisit[start] = true;

		// 방문하지 않은 점으로 탐색 진행
		for (int i = 0; i < vtx[start].al.size(); ++i) {
			int nextV = vtx[start].al.get(i);

			if (!isVisit[nextV]) {
				DFS(nextV);
			}
		}
	}

	public static void main(String[] args) throws Exception {

		// 정점의 개수, 간선의 개수, 시작점 입력받기
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		vtx = new vertex[N + 1];

		// 간선 초기화
		for (int i = 0; i < N + 1; ++i) {
			vtx[i] = new vertex();
		}

		// 간선 정보 입력받기
		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			vtx[a].al.add(b);
			vtx[b].al.add(a);
		}

		// 낮은 점 먼저 이동하도록 유도
		for (int i = 1; i <= N; ++i) {
			Collections.sort(vtx[i].al);
		}

		// 탐색
		isVisit = new boolean[N + 1];
		DFS(V);

		sb.append("\n");

		isVisit = new boolean[N + 1];
		BFS(V);

		System.out.print(sb);
	}

}
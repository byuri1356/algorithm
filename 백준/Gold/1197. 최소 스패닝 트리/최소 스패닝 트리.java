import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int T, V, E, pNode[], edge[][];
	static long Ans;

	static void union(int a, int b) {
		a = find(a);
		b = find(b);

		if (a < b)
			pNode[b] = a;
		else
			pNode[a] = b;

	}

	static int find(int n) {
		if (pNode[n] != n)
			return find(pNode[n]);

		return n;
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		Ans = 0;
		pNode = new int[V + 1];
		for (int i = 0; i <= V; ++i) {
			pNode[i] = i;
		}

		edge = new int[E][3];

		for (int i = 0; i < E; ++i) {
			st = new StringTokenizer(br.readLine());
			edge[i][0] = Integer.parseInt(st.nextToken());
			edge[i][1] = Integer.parseInt(st.nextToken());
			edge[i][2] = Integer.parseInt(st.nextToken());

		}

		Arrays.sort(edge, (o1, o2) -> o1[2] - o2[2]);

		for (int i = 0; i < E; ++i) {
			if (find(edge[i][0]) != find(edge[i][1])) {
				Ans += edge[i][2];
				union(edge[i][0], edge[i][1]);
			}
		}

		System.out.println(Ans);
	}

}

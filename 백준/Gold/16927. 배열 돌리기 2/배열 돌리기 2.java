import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, R, NM, NMR;
	static int Arr[][];
	static Deque<Integer> dq = new ArrayDeque<>();

	static void setMap(int depth, boolean setget) {
		for (int i = 1 + depth; i < N - depth; ++i) {
			if (setget)
				dq.offerLast(Arr[i][0 + depth]);
			else
				Arr[i][0 + depth] = dq.pollFirst();
		}

		for (int i = 1 + depth; i < M - depth; ++i) {
			if (setget)
				dq.offerLast(Arr[N - 1 - depth][i]);
			else
				Arr[N - 1 - depth][i] = dq.pollFirst();

		}

		for (int i = N - 2 - depth; i >= 0 + depth; --i) {
			if (setget)
				dq.offerLast(Arr[i][M - 1 - depth]);
			else
				Arr[i][M - 1 - depth] = dq.pollFirst();
		}

		for (int i = M - 2 - depth; i >= 0 + depth; --i) {
			if (setget)
				dq.offerLast(Arr[0 + depth][i]);
			else
				Arr[0 + depth][i] = dq.pollFirst();
		}
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		NM = Math.min(N, M) / 2;

		Arr = new int[N][M];

		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; ++j) {
				Arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < NM; ++i) {
			NMR = R % (2 * ( N + M) - 4 - 8 * i);
			setMap(i, true);
			for(int j=0; j< NMR; ++j) {
				dq.addFirst(dq.pollLast());
			}
			
			setMap(i, false);
			dq.clear();
		}
		
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				sb.append(Arr[i][j]).append(" ");
			}
			sb.append("\n");
		}
		
		System.out.print(sb.toString());
	}

}

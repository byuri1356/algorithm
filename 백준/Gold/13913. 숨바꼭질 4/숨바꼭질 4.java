import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, K, prevP[] = new int[100001];
	static boolean isVisit[] = new boolean[100001];

	static boolean isValid(int curP) {
		return (curP >= 0 && curP <= 100000);
	}

	static void BFS() {
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { N, 0 });
		isVisit[N] = true;

		while (!queue.isEmpty()) {
			int curP = queue.peek()[0];
			int curT = queue.poll()[1];

			if (curP == K) {
				Deque<Integer> deque = new ArrayDeque();
				while (curP != N) {
					deque.addFirst(curP);
					curP = prevP[curP];
				}

				deque.addFirst(N);
				sb.append(curT).append("\n");
				for (int curPos : deque) {
					sb.append(curPos).append(" ");
				}

				break;
			}

			int nextM = curP - 1;
			int nextP = curP + 1;
			int nextMulti = curP * 2;

			if (isValid(nextM) && !isVisit[nextM]) {
				isVisit[nextM] = true;
				queue.add(new int[] { nextM, curT + 1 });
				prevP[nextM] = curP;
			}

			if (isValid(nextP) && !isVisit[nextP]) {
				isVisit[nextP] = true;
				queue.add(new int[] { nextP, curT + 1 });
				prevP[nextP] = curP;
			}

			if (isValid(nextMulti) && !isVisit[nextMulti]) {
				isVisit[nextMulti] = true;
				queue.add(new int[] { nextMulti, curT + 1 });
				prevP[nextMulti] = curP;
			}

		}

	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		BFS();

		System.out.print(sb);
	}

}
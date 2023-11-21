import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static class Pos implements Comparable<Pos> {
		int x, y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pos o) {
			// TODO Auto-generated method stub
			return y - o.y;
		}
	}

	static int N, startX, startY, prevX, prevY, curX, curY, nonInclude;
	static Stack<Integer> upStack = new Stack<>();
	static Stack<Integer> downStack = new Stack<>();
	static Stack<Pos> sweepingStack = new Stack<>();
	static ArrayList<Pos> peak = new ArrayList<>();

	static void findPeak() {
		if (prevY > 0 && curY < 0) {
			if (upStack.isEmpty()) {
				downStack.add(curX);
			} else {
				int upX = upStack.pop();
				if (upX > curX) {
					peak.add(new Pos(curX, upX));
				} else {
					peak.add(new Pos(upX, curX));
				}
			}
		} else if (prevY < 0 && curY > 0) {
			upStack.add(curX);
		}
	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		startX = Integer.parseInt(st.nextToken());
		startY = Integer.parseInt(st.nextToken());

		prevX = startX;
		prevY = startY;

		for (int i = 1; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			curX = Integer.parseInt(st.nextToken());
			curY = Integer.parseInt(st.nextToken());

			findPeak();

			prevX = curX;
			prevY = curY;
		}

		curX = startX;
		curY = startY;

		findPeak();

		if (!downStack.isEmpty()) {
			int upX = upStack.pop();
			int downX = downStack.pop();

			if (upX > downX)
				peak.add(new Pos(downX, upX));
			else
				peak.add(new Pos(upX, downX));
		}

		Collections.sort(peak);

		for (Pos pos : peak) {
			boolean tk = true;

			while (!sweepingStack.isEmpty()) {
				if (pos.x < sweepingStack.peek().y) {
					sweepingStack.pop();
					tk = false;
				} else {
					break;
				}
			}

			if (tk)
				nonInclude++;
			sweepingStack.add(pos);
		}

		sb.append(sweepingStack.size()).append(" ").append(nonInclude);
		System.out.println(sb);
	}

}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static public class Pair {
		public int height;
		public int num;

		Pair(int height, int num) {
			this.height = height;
			this.num = num;
		}
	}

	static ArrayList<Pair> al = new ArrayList<>();

	static int N;

	public static void main(String[] args) throws Exception {

		al.add(new Pair(Integer.MAX_VALUE, 0));
		N = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; ++i) {
			int a = Integer.parseInt(st.nextToken());

			for (int j = al.size() - 1; j >= 0; --j) {
				if (al.get(j).height >= a) {
					sb.append(al.get(j).num).append(" ");
					break;
				} else {
					al.remove(j);
				}

			}
			al.add(new Pair(a, i));
		}

		System.out.print(sb.toString());
	}

}

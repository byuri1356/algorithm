import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, K, Cur;
	static ArrayList<Integer> al = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception {

		sb.append("<");

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; ++i) {
			al.add(i);
		}

		int Cur = -1;
		while (!al.isEmpty()) {
			Cur = (Cur + K) % al.size();

			sb.append(al.get(Cur));
			al.remove(Cur);
			if(!al.isEmpty()) sb.append(", ");
			Cur--;
		}

		sb.append(">");
		System.out.print(sb.toString());
	}

}

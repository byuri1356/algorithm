import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static Deque<Integer> dq = new ArrayDeque<>();

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=N; ++i) {
			dq.addLast(i);
		}
		
		while(dq.size() != 1) {
			dq.pollFirst();
			int tmp = dq.getFirst();
			dq.pollFirst();
			dq.addLast(tmp);			
		}
		
		sb.append(dq.getFirst());
		
		System.out.println(sb.toString());
	}
	
	
}

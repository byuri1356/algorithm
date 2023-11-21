import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, Ans;
	static PriorityQueue<Integer> pq = new PriorityQueue<>();

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; ++i) {
			pq.add(Integer.parseInt(br.readLine()));
		}
		
		while(pq.size() != 1) {
			int first = pq.poll();
			int second = pq.poll();
			
			int sum = first + second;
			
			Ans += sum;
			pq.add(sum);
			
		}
		
		System.out.println(Ans);

	}

}

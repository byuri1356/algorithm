import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;
	static PriorityQueue<Integer> pq = new PriorityQueue<>();
	static PriorityQueue<Integer> mq = new PriorityQueue<>(Collections.reverseOrder());

	public static void main(String[] args) throws Exception {

		// 배열크기, 쿼리 입력 받기
		N = Integer.parseInt(br.readLine());
		for(int i=0; i<N; ++i) {
			int a = Integer.parseInt(br.readLine());
			if(a >0) pq.add(a);
			else if(a < 0) mq.add(a);
			else {
				if(pq.isEmpty() && mq.isEmpty()) sb.append(0).append("\n");
				else if(pq.isEmpty()) sb.append(mq.poll()).append("\n");
				else if(mq.isEmpty()) sb.append(pq.poll()).append("\n");
				else {
					if(pq.peek() + mq.peek() >= 0) 
						sb.append(mq.poll()).append("\n");
					else sb.append(pq.poll()).append("\n");
				}
			}
		}
		
		System.out.print(sb.toString());

	}

}

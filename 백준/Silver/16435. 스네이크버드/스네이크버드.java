import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, L, Arr[];
	
	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		Arr = new int[N];
		
		st = new StringTokenizer(br.readLine());
		
		
		for(int i=0; i<N; ++i) {
			Arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(Arr);
		
		for(int i=0; i<N; ++i) {
			if(Arr[i] <= L) L++;
			else break;
		}
		
		System.out.println(L);
	}
}

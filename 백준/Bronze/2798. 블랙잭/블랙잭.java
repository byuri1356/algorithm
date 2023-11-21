import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, Max = 0;
	static int Arr[];

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		Arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; ++i) {
			Arr[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				for (int k = j + 1; k < N; ++k) {
					int total = Arr[i] + Arr[j] + Arr[k];
					if(total <= M) {
						Max = Math.max(Max, total);
					}
				}
			}
		}
		
		System.out.println(Max);
	}
}

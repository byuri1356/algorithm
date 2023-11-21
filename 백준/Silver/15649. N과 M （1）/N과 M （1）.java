import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int M;
	static int Arr[] = new int[8];
	static boolean vst[] = new boolean[9];
	
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;

	static void permutation(int dep) {
		if (dep == M) {
			for (int i=0; i<M; ++i) {
				sb.append("" + Arr[i] + " ");
			}
			sb.append("\n");
		}

		for (int i = 1; i <= N; ++i) {
			if (!vst[i]) {
				vst[i] = true;
				Arr[dep] = i;
				permutation(dep + 1);
				vst[i] = false;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine(), " ");
		sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		permutation(0);
		System.out.print(sb.toString());
	}

}

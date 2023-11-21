import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.concurrent.BrokenBarrierException;

public class Main {

	static int tmp[];
	static int Ans;
	static int S, P;
	static int A, C, G, T;
	static String Arr;

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static boolean password() {
		return (tmp[0] >= A && tmp[1] >= C && tmp[2] >= G && tmp[3] >= T);
	}

	static void plusCheck(int i) {
		if (Arr.charAt(i) == 'A') {
			tmp[0]++;
		} else if (Arr.charAt(i) == 'C') {
			tmp[1]++;
		} else if (Arr.charAt(i) == 'G') {
			tmp[2]++;
		} else if (Arr.charAt(i) == 'T') {
			tmp[3]++;
		}
	}

	static void minusCheck(int i) {
		if (Arr.charAt(i) == 'A') {
			tmp[0]--;
		} else if (Arr.charAt(i) == 'C') {
			tmp[1]--;
		} else if (Arr.charAt(i) == 'G') {
			tmp[2]--;
		} else if (Arr.charAt(i) == 'T') {
			tmp[3]--;
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());

		S = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());

		tmp = new int[4];

		Arr = br.readLine();

		st = new StringTokenizer(br.readLine());

		A = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		for (int i = 0; i < P; ++i) {
			plusCheck(i);
		}
		
		if(password()) Ans++;

		for (int i = P; i < S; ++i) {
			plusCheck(i);
			minusCheck(i - P);
			if(password()) Ans++;
		}
		
		System.out.println(Ans);
	}
}
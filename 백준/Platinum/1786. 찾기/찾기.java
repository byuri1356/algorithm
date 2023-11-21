import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {

		int ans = 0;
		ArrayList<Integer> al = new ArrayList<>();
		String S, P;
		S = br.readLine();
		P = br.readLine();

		int pi[] = new int[P.length()];

		int j = 0;
		for (int i = 1; i < P.length(); ++i) {
			while (j > 0 && P.charAt(j) != P.charAt(i)) {
				j = pi[j - 1];
			}

			if (P.charAt(j) == P.charAt(i)) {
				pi[i] = ++j;
			}
		}

		j = 0;
		for (int i = 0; i < S.length(); ++i) {
			while (j > 0 && P.charAt(j) != S.charAt(i)) {
				j = pi[j - 1];
			}

			if (P.charAt(j) == S.charAt(i)) {
				if (j == P.length() - 1) {
					ans++;
					sb.append(i - P.length() + 2).append(" ");
					j = pi[j];
				}
				else {
					++j;
				}
			}
		}

		System.out.println(ans);
		System.out.println(sb.toString());
	}

}

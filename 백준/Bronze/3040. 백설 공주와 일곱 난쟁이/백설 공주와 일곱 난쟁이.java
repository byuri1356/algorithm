import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int Arr[] = new int[9];

	public static void main(String[] args) throws Exception {

		for (int i = 0; i < 9; ++i) {
			Arr[i] = Integer.parseInt(br.readLine());
		}

		for (int a = 0; a < 9; ++a) {
			for (int b = a + 1; b < 9; ++b) {
				for (int c = b + 1; c < 9; ++c) {
					for (int d = c + 1; d < 9; ++d) {
						for (int e = d + 1; e < 9; ++e) {
							for (int f = e + 1; f < 9; ++f) {
								for (int g = f + 1; g < 9; ++g) {
									if (Arr[a] + Arr[b] + Arr[c] + Arr[d] + Arr[e] + Arr[f] + Arr[g] == 100) {
										System.out.println(Arr[a]);
										System.out.println(Arr[b]);
										System.out.println(Arr[c]);
										System.out.println(Arr[d]);
										System.out.println(Arr[e]);
										System.out.println(Arr[f]);
										System.out.println(Arr[g]);
										return;
									}
								}
							}
						}
					}
				}
			}
		}

	}
}
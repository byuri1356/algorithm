import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static StringTokenizer st;

	static int N, M;
	static int Arr[] = new int[101];
	static int bulb;
	static int MW;
	static int minn;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; ++i) {
			Arr[i] = Integer.parseInt(st.nextToken());
		}

		M = Integer.parseInt(br.readLine());

		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			MW = Integer.parseInt(st.nextToken());
			bulb = Integer.parseInt(st.nextToken());

			if (MW == 1) {
				for (int j = 1; j * bulb <= N; ++j) {
					Arr[j * bulb] = (Arr[j * bulb] + 1) % 2;
				}
			} else {
				minn = Math.min(bulb - 1, N - bulb);

				for (int j = 0; j <= minn; ++j) {
					if (Arr[bulb + j] == Arr[bulb - j]) {
						Arr[bulb + j] = Arr[bulb -j] = (Arr[bulb + j] + 1) % 2;
					} else
						break;
				}
			}
		}

		for (int i = 1; i <= N; ++i) {
			sb.append("" + Arr[i] + " ");
			if(i % 20 == 0) sb.append("\n");
		}

		System.out.print(sb.toString());

	}
}

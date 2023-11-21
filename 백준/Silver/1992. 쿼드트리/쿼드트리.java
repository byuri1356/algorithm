
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;
	static char Arr[][];

	public static void recur(int startX, int startY, int size) {
		if (size == 0)
			return;

		char pivot = Arr[startX][startY];

		boolean tk = true;
		outLoop: for (int i = startX; i < startX + size; ++i) {
			for (int j = startY; j < startY + size; ++j) {
				if (Arr[i][j] != pivot) {
					tk = false;
					sb.append("(");
					for (int k = 0; k < 2; ++k) {
						for (int l = 0; l < 2; ++l) {
							recur(startX + k * (size / 2), startY + l * (size / 2), size / 2);
						}
					}
					sb.append(")");
					break outLoop;
				}
			}
		}
		if (tk)
			sb.append(pivot);

	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());
		Arr = new char[N][N];

		for (int i = 0; i < N; ++i) {
			String s = br.readLine();
			for (int j = 0; j < N; ++j) {
				Arr[i][j] = s.charAt(j);
			}
		}

		recur(0, 0, N);

		System.out.println(sb);
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;
	static int arr[][][];

	static boolean isValid(int x, int y) {
		return ((x >= 0 && x < N && y >= 0 && y < N) && arr[0][x][y] != -1);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		N = Integer.parseInt(br.readLine());
		arr = new int[3][N][N];

		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; ++j) {
				int a = Integer.parseInt(st.nextToken());
				if (a == 1) {
					arr[0][i][j] = -1;
					arr[1][i][j] = -1;
					arr[2][i][j] = -1;
				}
			}
		}

		for (int i = 1; i < N; ++i) {
			if (arr[0][0][i] == -1)
				break;
			arr[0][0][i] = 1;
		}

		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (arr[0][i][j] == -1)
					continue;

				if (isValid(i, j - 1)) {
					arr[0][i][j] = arr[0][i][j - 1] + arr[2][i][j - 1];
				}

				if (isValid(i - 1, j)) {
					arr[1][i][j] = arr[1][i - 1][j] + arr[2][i - 1][j];
				}

				if (isValid(i, j - 1) && isValid(i - 1, j) && isValid(i - 1, j - 1)) {
					arr[2][i][j] = arr[0][i - 1][j - 1] + arr[1][i - 1][j - 1] + arr[2][i - 1][j - 1];
				}

			}
		}

		if (arr[0][N - 1][N - 1] == -1)
			System.out.println(0);
		else
			System.out.println(arr[0][N - 1][N - 1] + arr[1][N - 1][N - 1] + arr[2][N - 1][N - 1]);
	}
}
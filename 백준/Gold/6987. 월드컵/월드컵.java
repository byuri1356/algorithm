import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static boolean isPossible;
	static int game[][];
	static int idx[][] = new int[][] { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 }, { 1, 2 }, { 1, 3 }, { 1, 4 },
			{ 1, 5 }, { 2, 3 }, { 2, 4 }, { 2, 5 }, { 3, 4 }, { 3, 5 }, { 4, 5 } };

	static void checkGame(int round) {
		if (round == 15) {
			isPossible = true;
			return;
		}

		if (isPossible)
			return;

		int team1 = idx[round][0];
		int team2 = idx[round][1];

		if (game[team1][0] > 0 && game[team2][2] > 0) {
			game[team1][0]--;
			game[team2][2]--;
			checkGame(round + 1);
			game[team1][0]++;
			game[team2][2]++;
		}

		if (game[team1][1] > 0 && game[team2][1] > 0) {
			game[team1][1]--;
			game[team2][1]--;
			checkGame(round + 1);
			game[team1][1]++;
			game[team2][1]++;
		}

		if (game[team1][2] > 0 && game[team2][0] > 0) {
			game[team1][2]--;
			game[team2][0]--;
			checkGame(round + 1);
			game[team1][2]++;
			game[team2][0]++;
		}

	}

	public static void main(String[] args) throws Exception {

		outLoop: for (int t = 0; t < 4; ++t) {
			int sum = 0;
			isPossible = false;
			game = new int[6][3];

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 6; ++i) {
				for (int j = 0; j < 3; ++j) {
					game[i][j] = Integer.parseInt(st.nextToken());
					sum += game[i][j];
				}
			}

			if (sum != 30) {
				System.out.print("0 ");
				continue;
			}
			
			checkGame(0);

			if (isPossible)
				System.out.print("1 ");
			else
				System.out.print("0 ");
		}
	}

}
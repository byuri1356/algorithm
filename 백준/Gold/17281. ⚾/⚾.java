import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, score, permScore, rpIdx;
	static int[][] player; // 각 선수가 얻는 결과

	static boolean[] visited;
	static int[] numbers, realPlayer;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine()); // 이닝의 수
		player = new int[N][9]; // 1번타자가 0번째 인덱스
		score = 0; // 모든 이닝에서 얻은 점수

		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 9; j++) {
				player[i][j] = Integer.parseInt(st.nextToken()); // 각 선수가 이닝에서 얻는 결과
			}
		}

		visited = new boolean[9];
		numbers = new int[9];
		realPlayer = new int[9];

		perm(1, 0); // 각 이닝마다 점수 가져옴
		System.out.println(score);

	}

	private static void perm(int cnt, int idx) {
		if (cnt == 9) {
//            System.out.println(Arrays.toString(numbers));

			// 선수들의 조합에서 1번선수가 4번타자가 되도록 해줌
			for (int i = 0; i < 9; i++) {
				if (i < 3)
					realPlayer[i] = numbers[i + 1];
				else if (i == 3)
					realPlayer[3] = 0;
				else
					realPlayer[i] = numbers[i];
			}
//            System.out.println(Arrays.toString(realPlayer));

			permScore = 0;
			rpIdx = 0; // 이닝이 시작될 때 가져울 배열의 인덱스

			for (int i = 0; i < N; i++) {
				int num = getScore(i);
				permScore += num;
			}

			score = Math.max(score, permScore);
			return;
		}

		for (int i = 1; i <= 8; i++) { // 1부터 8까지
			// 중복체크
			if (visited[i])
				continue;
			numbers[cnt] = i;
			visited[i] = true;
			// 다음 주사위 던지러 가기
			perm(cnt + 1, idx);
			visited[i] = false;
		}
	}

	private static int getScore(int idx) {
		// 각 이닝마다 최대 점수를 계산해주는 함수
		// realPlayer가 현재 이닝의 타순
		// score에 점수를 더해줌
		int iningScore = 0;
		int out = 0; // 아웃이 기록될 카운트
		int[] arr = new int[3]; // 1루, 2루, 3루

		while (true) {
			int x = player[idx][realPlayer[rpIdx]]; // 선수가 현재 이닝에서 얻는 결과

			if (x == 0) {
				// 아웃이라면
				out++;
				if (out == 3) {
					rpIdx++;
					if (rpIdx == realPlayer.length)
						rpIdx = 0;
					return iningScore;
				}
			} else if (x == 1) {
				// 안타라면 - 타자와 모든 주자가 한 루 씩 진루한다

				iningScore += arr[2];
				arr[2] = arr[1];
				arr[1] = arr[0];
				arr[0] = 1;

			} else if (x == 2) {
				// 2루타라면

				iningScore += arr[2];
				iningScore += arr[1];
				arr[2] = arr[0];
				arr[1] = 1;

				// 더한 배열들 초기화
				arr[0] = 0;

			} else if (x == 3) {
				// 3루타라면

				iningScore += arr[2];
				iningScore += arr[1];
				iningScore += arr[0];
				arr[2] = 1;

				// 더한 배열들 초기화
				arr[1] = 0;
				arr[0] = 0;

			} else if (x == 4) {
				// 홈 이라면

				iningScore += arr[2];
				iningScore += arr[1];
				iningScore += arr[0];
				iningScore += 1;

				// 더한 배열들 초기화
				arr[2] = 0;
				arr[1] = 0;
				arr[0] = 0;

			}

			rpIdx++;
			if (rpIdx == realPlayer.length)
				rpIdx = 0;
		}
	}
}
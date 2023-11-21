import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, Answer;
	static char Arr[][], Ans[][];

	public static void main(String[] args) throws Exception {

		//배열 가로 세로 크기 입력받기
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		Arr = new char[N][M];
		Ans = new char[N][M];

		//돌릴 배열 초기화
		for (int i = 0; i < N; ++i) {
			String s = br.readLine();
			for (int j = 0; j < M; ++j) {
				Arr[i][j] = s.charAt(j);
			}
		}

		//정답 배열 초기화
		for (int i = 0; i < N; ++i) {
			String s = br.readLine();
			for (int j = 0; j < M; ++j) {
				Ans[i][j] = s.charAt(j);
			}
		}

		//만약 두 배열이 다른 값을 가지고 있으면 돌리기
		for (int i = 0; i <= N - 3; ++i) {
			for (int j = 0; j <= M - 3; ++j) {
				if (Arr[i][j] != Ans[i][j]) {
					Answer++;
					for (int k = 0; k < 3; ++k) {
						for (int l = 0; l < 3; ++l) {
							if (Arr[i + k][j + l] == '1')
								Arr[i + k][j + l] = '0';
							else
								Arr[i + k][j + l] = '1';
						}
					}
				}
			}
		}

		//돌린 배열이 정답 배열과 같은지 확인
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if(Arr[i][j] != Ans[i][j]) {
					System.out.println(-1);
					return;
				}
			}
		}
		
		System.out.println(Answer);

	}
}


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M;
	static long Ans, Sum, AnsSum = Long.MAX_VALUE;
	static long start = 0, end = 0;
	static long Arr[];

	public static void main(String[] args) throws Exception {

		// N, M 입력받기
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Arr = new long[N];

		// 나무 길이 초기화, end값 가장 큰 나무로 초기화
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; ++i) {
			Arr[i] = Long.parseLong(st.nextToken());
			end = Math.max(Arr[i], end);
		}

		// 이분 탐색 시작
		while (start <= end) {
			long half = (start + end) / 2;
			Sum = 0;

			for (int i = 0; i < N; ++i) {
				if (Arr[i] > half) {
					Sum += Arr[i] - half;
				}
			}

			// M만큼 가져갈 수 있을때
			if (Sum == M) {
				Ans = half;
				break;
			}

			// 더 많이 가져갈 때
			else if (Sum > M) {
				start = half + 1;
				if (Math.abs(M - AnsSum) > Math.abs(M - Sum)) {
					Ans = half;
					AnsSum = Sum;
				}
			}

			// 더 작게 가져갈때
			else
				end = half - 1;
		}

		System.out.println(Ans);

	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, Ans = -1;

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(br.readLine());

		// a = 최대 가능한 5kg 개수
		int a = N / 5, b = a;

		// 5kg 짜리 설탕봉지 개수를 조절하면서 판단
		while (a != -1) {

			// 만들수 있는 무게일 경우
			if ((5 * (b - a) + N % 5) % 3 != 0) {
				a--;
			}

			// 만들 수 없는 무게일 경우 5kg 짜리 봉지 하나 빼고 다시 계산
			else {
				Ans = a + (5 * (b - a) + N % 5) / 3;
				break;
			}
		}

		// 출력
		System.out.println(Ans);

	}
}

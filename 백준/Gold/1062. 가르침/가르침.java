import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, K, Ans = 0;
	static int[] com = new int[] { 1, 3, 4, 5, 6, 7, 9, 10, 11, 12, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25 };
	static String Arr[];
	static boolean tk[] = new boolean[27];

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	//가르친 문자중에서 읽을 수 있는 문자열은 몇개인가
	static int isCheck() {
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			boolean tok = true;
			for (int j = 0; j < Arr[i].length(); ++j) {
				if(!tk[ (int)(Arr[i].charAt(j) - 'a') ]) {
					tok = false;
					break;
				}
			}
			if(tok) cnt++;
		}
		return cnt;
	}

	//조합 만들기!
	static void combi(int cur, int sel) {
		if (Ans == N)
			return;

		if (sel == K) {
			Ans = Math.max(Ans, isCheck());
			return;
		}

		if (K - sel > com.length - cur)
			return;

		tk[com[cur]] = true;
		combi(cur + 1, sel + 1);
		tk[com[cur]] = false;
		combi(cur + 1, sel);

	}

	public static void main(String[] args) throws Exception {

		tk[0] = true;
		tk[2] = true;
		tk[8] = true;
		tk[13] = true;
		tk[19] = true;

		// 문자열 개수, 가르칠 문자 수
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		//문자열 배열 초기화
		Arr = new String[N];

		//문자열 설정
		for (int i = 0; i < N; ++i) {
			Arr[i] = br.readLine();
		}

		//5개 이하인경우 볼필요도 없이 0 출력
		if (K < 5) {
			sb.append("0");
		}
		//아닌경우 조합 찾기
		else {
			combi(0, 5);
		}

		System.out.println(Ans);
	}

}
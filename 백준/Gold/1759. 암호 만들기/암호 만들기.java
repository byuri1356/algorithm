import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int L; // 암호 길이
	static int C; // 문자 종류 개수
	static char inArr[]; // 문자 종류 배열
	static char outArr[]; // 만들어진 암호 배열

	// BufferedReader -> 입력받는 속도 상승!
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	// StringBuilder -> 출력하는 속도 상승!
	static StringBuilder sb = new StringBuilder();

	// 뽑은거 또뽑기 x, 순서만 다른 암호가 존재할 수 없음(오름차순 이기 때문에) 따라서 조합 이용해야한다.
	static void makePassword(int cur, int dep, int selC, int selV) {
		selC = (selC < 0) ? 0 : selC;
		selV = (selV < 0) ? 0 : selV;
		if (L - dep - selC - selV < 0)
			return;
		if (dep == L) {
			for(int i=0; i<dep; ++i) {
				sb.append(outArr[i]);
			}
			sb.append("\n");
			//sb.append(outArr + "\n");
			return;
		}

		for (int i = cur; i < C; ++i) {
			if (inArr[i] == 'a' || inArr[i] == 'e' || inArr[i] == 'i' || inArr[i] == 'o' || inArr[i] == 'u') {
				outArr[dep] = inArr[i];
				makePassword(i + 1, dep + 1, selC - 1, selV);
			} else {
				outArr[dep] = inArr[i];
				makePassword(i + 1, dep + 1, selC, selV - 1);
			}
		}
	}

	public static void main(String[] args) throws Exception {

		StringTokenizer st = new StringTokenizer(br.readLine()); // 첫 줄 입력받기 4 6
		L = Integer.parseInt(st.nextToken()); // L = 4
		C = Integer.parseInt(st.nextToken()); // C = 6

		st = new StringTokenizer(br.readLine()); // 둘째 줄 입력받기 a t c i s w

		// 배열크기 동적 할당 (크기 가변적) -> java의 장점
		inArr = new char[C];
		outArr = new char[L];

		for (int i = 0; i < C; ++i) {
			// 둘째 줄 입력받은 내용으로부터 한 글자 씩 짤라서 char[] 에 저장
			inArr[i] = st.nextToken().charAt(0);
		}

		// 암호는 무조건 오름차순 -> 정렬 후 a c i s t w
		Arrays.sort(inArr);

		// 암호 유추하기
		makePassword(0, 0, 1, 2);

		// 정답 출력
		System.out.print(sb.toString());
	}
}

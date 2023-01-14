import java.util.Scanner;

public class Main {

	static int N;
	static long conbi[][] = new long[49][49];
	static long ans;
	
	static void setConbi() {
		for (int i = 0; i < 49; ++i) {
			conbi[i][0] = 1;
			conbi[i][1] = i;
		}

		for (int i = 2; i < 14; ++i) {
			conbi[13][i] = conbi[13][i - 1] * (13 - i + 1) / i;
		}

		for (int i = 2; i < 49; ++i) {
			conbi[48][i] = conbi[48][i - 1] * (48 - i + 1) / i;
		}

		for (int i = 2; i < 45; ++i) {
			conbi[44][i] = conbi[44][i - 1] * (44 - i + 1) / i;
		}

		for (int i = 2; i < 41; ++i) {
			conbi[40][i] = conbi[40][i - 1] * (40 - i + 1) / i;
		}

		for (int i = 2; i < 37; ++i) {
			conbi[36][i] = conbi[36][i - 1] * (36 - i + 1) / i;
		}

		for (int i = 2; i < 33; ++i) {
			conbi[32][i] = conbi[32][i - 1] * (32 - i + 1) / i;
		}

		for (int i = 2; i < 29; ++i) {
			conbi[28][i] = conbi[28][i - 1] * (28 - i + 1) / i;
		}

		for (int i = 2; i < 25; ++i) {
			conbi[24][i] = conbi[24][i - 1] * (24 - i + 1) / i;
		}

		for (int i = 2; i < 21; ++i) {
			conbi[20][i] = conbi[20][i - 1] * (20 - i + 1) / i;
		}

		for (int i = 2; i < 17; ++i) {
			conbi[16][i] = conbi[16][i - 1] * (16 - i + 1) / i;
		}

		for (int i = 2; i < 13; ++i) {
			conbi[12][i] = conbi[12][i - 1] * (12 - i + 1) / i;
		}

		for (int i = 2; i < 9; ++i) {
			conbi[8][i] = conbi[8][i - 1] * (8 - i + 1) / i;
		}

		for (int i = 2; i < 5; ++i) {
			conbi[4][i] = conbi[4][i - 1] * (4 - i + 1) / i;
		}
	}
		
	static void solveNPoker(int dep, int re_dep, int cur) {
		if (dep % 2 == 1) {
			ans = ans + conbi[13][dep] * conbi[re_dep][cur];
		}
		else {
			ans = ans - conbi[13][dep] * conbi[re_dep][cur];
		}
		
		if (cur < 4) return;
		else solveNPoker(dep + 1, re_dep - 4, cur - 4);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		setConbi();
		
		if(N < 4) ans =0;
		else solveNPoker(1, 48, N-4);
		
		System.out.println(ans % 10007);
	}

}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static class Shark {

		// x좌표, y좌표, 속력, 방향, 크기
		public int x, y, spd, drt, sz;
		public boolean isLive;

		public Shark(int x, int y, int spd, int drt, int sz) {
			this.x = x;
			this.y = y;
			this.spd = spd;
			this.drt = drt;
			this.sz = sz;
			this.isLive = true;
		}
	}

	static int R, C, M, ctch, Arr[][], chgPos[] = { 0, 2, 1, 4, 3 },
			deltas[][] = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
	static Shark shark[];

	// 초기화 클래스
	static void initInfo() {
		shark = new Shark[M + 1];
		shark[0] = new Shark(0, 0, 0, 0, 0);
	}

	public static void main(String[] args) throws Exception {

		// 격자판 크기, 상어 수
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		initInfo();

		// 상어 정보 입력받기
		for (int i = 1; i <= M; ++i) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());

			shark[i] = new Shark(r, c, s, d, z);
		}

		// 상어상어
		for (int i = 1; i <= C; ++i) {

			// 잡을 상어 찾는 부분
			int chShark = 0, schClose = R + 1;
			for (int j = 1; j <= M; ++j) {
				if (!shark[j].isLive)
					continue;
				if (shark[j].y == i && shark[j].x < schClose) {
					chShark = j;
					schClose = shark[j].x;
				}

			}

			// 찾은 상어 잡기
			ctch += shark[chShark].sz;
			shark[chShark].isLive = false;

			// 상어 이동중...
			Arr = new int[R + 1][C + 1];
			for (int j = 1; j <= M; ++j) {
				if (!shark[j].isLive)
					continue;

				int k = 0;
				if (shark[j].drt == 1 || shark[j].drt == 2) {
					k = shark[j].spd % (2 * R - 2);
				}
				else {
					k = shark[j].spd % (2 * C - 2);
				}

				for (; k > 0; --k) {
					int nextX = shark[j].x + deltas[shark[j].drt][0];
					int nextY = shark[j].y + deltas[shark[j].drt][1];

					if (nextX > 0 && nextX <= R && nextY > 0 && nextY <= C) {
						shark[j].x = nextX;
						shark[j].y = nextY;
					} else {
						shark[j].drt = chgPos[shark[j].drt];
						shark[j].x = shark[j].x + deltas[shark[j].drt][0];
						shark[j].y = shark[j].y + deltas[shark[j].drt][1];
					}
				}

				// 상어가 상어 잡아먹는중..
				if (Arr[shark[j].x][shark[j].y] != 0) {
					if (shark[Arr[shark[j].x][shark[j].y]].sz > shark[j].sz) {
						shark[j].isLive = false;
					} else {
						shark[Arr[shark[j].x][shark[j].y]].isLive = false;
						Arr[shark[j].x][shark[j].y] = j;
					}
				} else {
					Arr[shark[j].x][shark[j].y] = j;
				}

			}

		}

		System.out.println(ctch);

	}

}

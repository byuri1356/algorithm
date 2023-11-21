#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

inline bool isValid(int64 x, int64 y, int64 W, int64 H) {
	return (x >= 0 && x < H&& y >= 0 && y < W);
}

int main() {
	fastio;

	while (1) {

		int64 W, H;
		cin >> W >> H;

		if (W != 0 || H != 0) {
			bool rip[30][30] = { false, };
			int64 warmHole[30][30][4] = { 0, };
			int64 dist[30][30];

			for (int64 i = 0; i < H; ++i) {
				for (int64 j = 0; j < W; ++j) {
					dist[i][j] = INF;
				}
			}
			dist[0][0] = 0;

			int64 G;
			cin >> G;

			for (int64 i = 0; i < G; ++i) {
				int64 x, y;
				cin >> y >> x;

				rip[x][y] = true;
			}

			int64 E;
			cin >> E;
			
			for (int64 i = 0; i < E; ++i) {
				int64 x1, y1, x2, y2, dis;
				cin >> y1 >> x1 >> y2 >> x2 >> dis;

				warmHole[x1][y1][0] = x2;
				warmHole[x1][y1][1] = y2;
				warmHole[x1][y1][2] = dis;
				warmHole[x1][y1][3] = 1;
			}

			for (int64 i = 1; i < W * H; ++i) {
				for (int64 j = 0; j < H; ++j) {
					for (int64 k = 0; k < W; ++k) {
						if (dist[j][k] == INF) continue;
						else if (warmHole[j][k][3]) {
							if (dist[warmHole[j][k][0]][warmHole[j][k][1]] > dist[j][k] + warmHole[j][k][2]) {
								dist[warmHole[j][k][0]][warmHole[j][k][1]] = dist[j][k] + warmHole[j][k][2];
							}
							continue;
						}
						else if ((j == H - 1) && (k == W - 1)) continue;
						for (int64 l = 0; l < 4; ++l) {
							int64 next_x = j + dx[l];
							int64 next_y = k + dy[l];

							if (isValid(next_x, next_y, W, H)) {
								if (rip[next_x][next_y]) continue;

								if (dist[next_x][next_y] > dist[j][k] + 1) {
									dist[next_x][next_y] = dist[j][k] + 1;
								}
							}
						}
					}
				}
			}
	
			bool tk = false;
			int64 res = dist[H - 1][W - 1];
			for (int64 i = 1; i <= W * H; ++i) {
				for (int64 j = 0; j < H; ++j) {
					for (int64 k = 0; k < W; ++k) {
						if (dist[j][k] == INF) continue;
						else if (warmHole[j][k][3]) {
							if (dist[warmHole[j][k][0]][warmHole[j][k][1]] > dist[j][k] + warmHole[j][k][2]) {
								tk = true;
							}
							continue;
						}
						else if ((j == H - 1) && (k == W - 1)) continue;
						for (int64 l = 0; l < 4; ++l) {
							int64 next_x = j + dx[l];
							int64 next_y = k + dy[l];

							if (isValid(next_x, next_y, W, H)) {
								if (rip[next_x][next_y]) continue;

								if (dist[next_x][next_y] > dist[j][k] + 1) {
									tk = true;
								}
							}
						}
					}
				}
			}

			if (tk) cout << "Never" << "\n";
			else if (dist[H - 1][W - 1] == INF) cout << "Impossible" << "\n";
			else cout << dist[H - 1][W - 1] << "\n";

		}

		else break;

	}

	return EXIT_SUCCESS;
}
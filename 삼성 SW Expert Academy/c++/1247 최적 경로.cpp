#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

typedef struct client {
	bool vit = false;
	int64 x, y;
}client;

client c[10];

int64 start_x, start_y, end_x, end_y, ans, N;
int64 dis[10][12];

inline void checkDis(int64 dep, int64 cur, int64 sum) {
	if (dep == N) {
		ans = min(ans, sum + dis[cur][N+1]);
	}

	if (sum > ans) return;

	for (int64 i = 0; i < N; ++i) {
		if (!c[i].vit) {
			c[i].vit = true;
			checkDis(dep + 1, i, sum + dis[cur][i]);
			c[i].vit = false;
		}
	}

}

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		N, ans = INF;
		cin >> N;

		cin >> start_x >> start_y >> end_x >> end_y;
		for (int64 i = 0; i < N; ++i) {
			cin >> c[i].x >> c[i].y;
			c[i].vit = false;
		}
		

		for (int64 i = 0; i < N; ++i) {
			dis[i][N] = abs(c[i].x - start_x) + abs(c[i].y - start_y);
			dis[i][N+1] = abs(c[i].x - end_x) + abs(c[i].y - end_y);
		}

		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j < N; ++j) {
				dis[i][j] = abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y);
			}
		}

		for (int64 i = 0; i < N; ++i) {
			c[i].vit = true;
			checkDis(1, i, dis[i][N]);
			c[i].vit = false;
		}
	

		cout << "#" << t << ' ' << ans << "\n";
	}

	return EXIT_SUCCESS;
}
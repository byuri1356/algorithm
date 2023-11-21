#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;
//BOJ_1012_S2_유기농 배추
// KB, ms

int N, M, bg, ans, _map[51][51];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector < pair<int, int>> v;
queue<pair<int, int>> q;

inline bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

inline void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (isValid(next_x, next_y)) {
				if (_map[next_x][next_y]) {
					_map[next_x][next_y] = 0;
					q.push({ next_x, next_y });
				}
			}
		}
	}
}

int main() {
	fastio;

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {

		cin >> N >> M >> bg;
		for (int i = 0; i < bg; ++i) {
			int a, b;
			cin >> a >> b;

			_map[a][b] = 1;
			v.push_back({ a,b });
		}

		for (auto iter : v) {
			if (_map[iter.first][iter.second]) {
				_map[iter.first][iter.second] = 0;
				q.push({ iter.first, iter.second });
				ans++;
				BFS();
			}
		}

		cout << ans << "\n";

		v.clear();
		ans = 0;

	}

	return EXIT_SUCCESS;
}
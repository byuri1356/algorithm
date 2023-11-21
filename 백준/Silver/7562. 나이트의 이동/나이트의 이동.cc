#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }, dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };


inline bool _pos(int64 L, int64 next_x, int64 next_y) {
	return ((next_x >= 0) && (next_x < L)&& (next_y >= 0) && (next_y < L));
}

inline void Solve(int64 L, int64 cur_x, int64 cur_y, int64 des_x, int64 des_y) {
	int64 _map[300][300];
	fill(_map[0], _map[0]+90000, 0);
	_map[cur_x][cur_y] = 1;
	queue<pair<int64, int64>>q;
	q.push({ cur_x, cur_y });
	while (!q.empty()) {
		int64 x = q.front().first;
		int64 y = q.front().second;
		q.pop();
		if ((x == des_x) && (y == des_y)) {
			cout << _map[x][y] - 1 << "\n";
			break;
		}

		for (int64 i = 0; i < 8; ++i) {
			int64 next_x = x + dx[i];
			int64 next_y = y + dy[i];
			if (_pos(L, next_x, next_y)) {
				if (!_map[next_x][next_y]) {
					_map[next_x][next_y] = _map[x][y] + 1;
					q.push({ next_x, next_y });
				}
			}
		}
	}
}

int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		int64 L, cur_x, cur_y, des_x, des_y;
		cin >> L >> cur_x >> cur_y >> des_x >> des_y;
		if ((cur_x == des_x) && (cur_y == des_y)) cout << 0 << "\n";
		else Solve(L, cur_x, cur_y, des_x, des_y);
	}

	return EXIT_SUCCESS;
}
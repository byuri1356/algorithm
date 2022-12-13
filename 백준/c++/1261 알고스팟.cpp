#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[101][101];
char _map[101][101];
int64 N, M, brk_count[101][101], dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
queue <tuple<int64, int64, int64>> q;

inline bool _valid(int64 next_X, int64 next_Y) {
	return(next_X > 0 && next_X <= N && next_Y > 0 && next_Y <= M);
}

inline void BFS() {
	q.push(make_tuple(1, 1, 0));
	while (!q.empty()) {
		int64 x = get<0>(q.front());
		int64 y = get<1>(q.front());
		int64 _count = get<2>(q.front());
		q.pop();

		for (int64 i = 0; i < 4; ++i) {
			int64 next_X = x + dx[i];
			int64 next_Y = y + dy[i];
			if (_valid(next_X, next_Y)) {
				if (!_visit[next_X][next_Y]) {
					_visit[next_X][next_Y] = true;
					if (_map[next_X][next_Y] == '0') {
						brk_count[next_X][next_Y] = _count;
						q.push(make_tuple(next_X, next_Y, _count));
					}
					else {
						brk_count[next_X][next_Y] = _count + 1;
						q.push(make_tuple(next_X, next_Y, _count + 1));
					}
				}
				else {
					if (_map[next_X][next_Y] == '0' && brk_count[next_X][next_Y] > _count) {
						brk_count[next_X][next_Y] = _count;
						q.push(make_tuple(next_X, next_Y, _count));
					}
					else if (_map[next_X][next_Y] == '1' && brk_count[next_X][next_Y] > _count + 1) {
						brk_count[next_X][next_Y] = _count + 1;
						q.push(make_tuple(next_X, next_Y, _count + 1));
					}
				}
			}
		}
	}
}

int main() {
	fastio;

	cin >> M >> N;
	for (int64 i = 1; i <= N; ++i) {
		for (int64 j = 1; j <= M; ++j) {
			cin >> _map[i][j];
		}
	}

	BFS();
	cout << brk_count[N][M];

	return EXIT_SUCCESS;
}
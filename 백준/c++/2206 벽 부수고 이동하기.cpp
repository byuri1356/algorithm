#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dx[4] = {-1, 0, 1, 0};
int64 dy[4] = {0, 1, 0, -1};
char _map[1001][1001];
int64 _num[1001][1001];
bool _visit[1001][1001];
queue<pair<int64, int64>> q;

inline bool _pos(int64 next_X, int64 next_Y, int64 N, int64 M) {
	return ((next_X >= 1) && (next_X <= N) && (next_Y >= 1) && (next_Y <= M));
}

inline void Solve(int64 N, int64 M) {
	q.push({ 1,1 });
	_visit[1][1] = true;
	while (!q.empty()) {
		int64 x = q.front().first;
		int64 y = q.front().second;
		int64 _count = _num[x][y];
		q.pop();
		for (int64 i = 0; i < 4; ++i) {
			int64 next_X = x + dx[i];
			int64 next_Y = y + dy[i];
			if (_pos(next_X, next_Y, N, M)) {
				if (!_visit[next_X][next_Y]) {
					if (_num[x][y] < 0) {
						if (_map[next_X][next_Y] == '1') continue;
						else {
							_num[next_X][next_Y] = _count - 1;
							_visit[next_X][next_Y] = true;
							q.push({ next_X, next_Y });
						}
					}
					else {
						if (_map[next_X][next_Y] == '1') {
							_num[next_X][next_Y] = -_count - 1;
							_visit[next_X][next_Y] = true;
							q.push({ next_X, next_Y });
						}
						else {
							_num[next_X][next_Y] = _count + 1;
							_visit[next_X][next_Y] = true;
							q.push({ next_X, next_Y });
						}
					}
				}
				else {
					if ((_map[next_X][next_Y] != '1') && !((next_X == N) && (next_Y == M)) && (_num[next_X][next_Y] < 0) && (_num[x][y] >= 0)) {
						_num[next_X][next_Y] = _count + 1;
						q.push({ next_X, next_Y });
					}
				}
			}
		}
	}
}

int main() {
	fastio;

	int64 N, M;
	cin >> N >> M;
	for (int64 i = 1; i <= N;) {
		for (int64 j = 1; j <= M;) {
			cin >> _map[i][j];
			++j;
		}
		++i;
	}
	Solve(N, M);
	if ((N == 1) && (M == 1)) {
		cout << 1;
	}
	else {
		if(!abs(_num[N][M])) cout<< -1;
		else cout << abs(_num[N][M]) + 1;
	}

	return EXIT_SUCCESS;
}
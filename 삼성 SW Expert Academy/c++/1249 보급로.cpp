#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

char arr[100][100];
int64 N, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

inline int64 checkMap(int64 a, int64 b) {
	bool vi[100][100] = { false, };
	int64 m[100][100] = { 0, };

	queue<pair<int64, int64>> q;
	vi[a][b] = true;
	q.push({ a,b });

	while (!q.empty()) {
		int64 x = q.front().first;
		int64 y = q.front().second;
		q.pop(); m[5][5];

		for (int64 i = 0; i < 4; ++i) {
			int64 next_x = x + dx[i];
			int64 next_y = y + dy[i]; 

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
				if (!vi[next_x][next_y]) {
					vi[next_x][next_y] = true;
					m[next_x][next_y] = m[x][y] + (int)arr[next_x][next_y] - 48;
					q.push({ next_x, next_y });
				}
				else if (m[next_x][next_y] > (m[x][y] + (int)arr[next_x][next_y] - 48)) {
					m[next_x][next_y] = m[x][y] + (int)arr[next_x][next_y] - 48;
					q.push({ next_x, next_y });
				}
			}
		}
	}

	return m[N - 1][N - 1];
}

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		cin >> N;
	
		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j < N; ++j) {
				cin >> arr[i][j];
			}
		}

		cout << "#" << t << ' ' << checkMap(0, 0) << "\n";
	}

	return EXIT_SUCCESS;
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[5][5], __visit[5][5];
char _map[5][5];
int64 Ans, dn[4] = { -1, 0, 1, 0 }, dm[4] = { 0, 1, 0, -1 };
vector<pair<int64, int64>> v;
queue<pair<int64, int64>> q;

inline bool _pos(int64 N, int64 M) {
	return ((N >= 0) && (N < 5) && (M >= 0) && (M < 5));
}

inline void Solve(int64 N, int64 M, int64 S, int64 R) {
	if (R - S < 0) return;
	else if (R == 0) {
		int64 cnt = 0;
		q.push({ v.front().first, v.front().second });
		while (!q.empty()) {
			int64 n = q.front().first;
			int64 m = q.front().second;
			q.pop();
			for (int64 i = 0; i < 4; ++i) {
				int64 next_N = n + dn[i];
				int64 next_M = m + dm[i];
				if (_pos(next_N, next_M)) {
					if (_visit[next_N][next_M]) {
						if (!__visit[next_N][next_M]) {
							__visit[next_N][next_M] = true;
							q.push({ next_N, next_M });
							cnt++;
						}
					}
				}
			}
		}
		for (auto _iter : v) {
			__visit[_iter.first][_iter.second] = false;
		}
		if (cnt == 7) {
			Ans++;
			return;
		}
		else return;
	}

	for (int64 i = N; i < 5; ++i) {
		int64 j;
		if (i == N)  j = M;
		else j = 0;
		for (; j < 5; ++j) {
			_visit[i][j] = true;
			v.push_back({ i,j });
			if (_map[i][j] == 'S') Solve(i, j + 1, S - 1, R - 1);
			else Solve(i, j + 1, S, R - 1);
			_visit[i][j] = false;
			v.pop_back();
		}
	}
}

int main() {
	fastio;

	for (int64 i = 0; i < 5; ++i) {
		for (int64 j = 0; j < 5; ++j) {
			cin >> _map[i][j];
		}
	}

	for (int64 i = 0; i < 5; ++i) {
		for (int64 j = 0; j < 5; ++j) {
			_visit[i][j] = true;
			v.push_back({ i,j });
			if (_map[i][j] == 'S') Solve(i, j + 1, 3, 6);
			else Solve(i, j + 1, 4, 6);
			_visit[i][j] = false;
			v.pop_back();
		}
	}

	cout << Ans;

	return EXIT_SUCCESS;
}
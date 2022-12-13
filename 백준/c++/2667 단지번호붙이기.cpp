#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[26][26];
char _map[26][26];
int64 NM, dn[4] = { -1, 0, 1, 0 }, dm[4] = { 0, 1, 0, -1 };
vector<int64> v;
queue<pair<int64, int64>> q;

inline bool _pos(int64 next_N, int64 next_M) {
	return ((next_N > 0) && (next_N <= NM) && (next_M > 0) && (next_M <= NM));
}

inline int64 BFS(int64 N, int64 M) {
	int64 _count = 0;
	_visit[N][M] = true;
	q.push({ N, M });
	while (!q.empty()) {
		int64 n = q.front().first;
		int64 m = q.front().second;
		_count++;
		q.pop();
		for (int64 i = 0; i < 4; ++i) {
			int64 next_N = n + dn[i];
			int64 next_M = m + dm[i];
			if (_pos(next_N, next_M)) {
				if (!_visit[next_N][next_M]) {
					_visit[next_N][next_M] = true;
					q.push({ next_N, next_M });
				}
			}
		}
	}
	return _count;
}

int main() {
	fastio;

	int64 _count = 0;
	cin >> NM;
	for (int64 i = 1; i <= NM; ++i) {
		for (int64 j = 1; j <= NM; ++j) {
			cin >> _map[i][j];
			if (_map[i][j] == '0') _visit[i][j] = true;
		}
	}

	for (int64 i = 1; i <= NM; ++i) {
		for (int64 j = 1; j <= NM; ++j) {
			if (!_visit[i][j]) {
				_count++;
				v.push_back(BFS(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << _count << "\n";
	for (auto _iter : v) {
		cout << _iter << "\n";
	}

	return EXIT_SUCCESS;
}
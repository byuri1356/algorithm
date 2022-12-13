#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int64 dx[4] = { -1, 0, 1, 0 };
int64 dy[4] = { 0, 1, 0, -1 };
int64 arr[10][10], _visit[10][10], ans, _max= -999999;
vector<int64> v;

bool _pos(int64 N, int64 M, int64 nextX, int64 nextY) {
	return ((nextX < N) && (nextX >= 0) && (nextY < M) && (nextY >= 0));
}

inline void Solve(int64 N, int64 M, int64 n, int64 m, int64 K) {
	if (K == 0) {
		for (auto _iter : v) {
			ans += _iter;
		}
		_max = max(_max, ans);
		ans = 0;
		return;
	}
	for (int64 i = n; i < N; ++i) {
		if (i != n)
			m = 0;
		for (int64 j = m; j < M; ++j) {
			int64 _valid = 0, _count = 0;
			for (int64 k = 0; k < 4; ++k) {
				int64 nextX = i + dx[k];
				int64 nextY = j + dy[k];
				if (_pos(N, M, nextX, nextY)) {
					_valid++;
					if (_visit[nextX][nextY]) break;
					else _count++;
				}
			}
			if (_valid == _count) {
				v.push_back(arr[i][j]);
				_visit[i][j] = true;
				if ((j + 1) >= M) 
					Solve(N, M, i+1, 0, K - 1);
				else 
					Solve(N, M, i, j+1, K - 1); 
				v.pop_back(); 
				_visit[i][j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N, M, K;
	cin >> N >> M >> K;
	for (int64 i = 0; i < N;) {
		for (int64 j = 0; j < M;) {
			cin >> arr[i][j];
			++j;
		}
		++i;
	}
	Solve(N, M, 0, 0, K);
	cout << _max;

	return EXIT_SUCCESS;
}
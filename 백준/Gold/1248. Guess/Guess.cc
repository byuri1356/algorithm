#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

char _map[100][100];
int64 _bit[100][100], n, token;
vector<int64> v;

bool Guess(int64 N) {
	for (int64 i = 0; i <= N; ++i) {
		if ((_map[i][N] == '+') && (_bit[i][N] <= 0)) return false;
		else if ((_map[i][N] == '-') && (_bit[i][N] >= 0)) return false;
		else if ((_map[i][N] == '0') && (_bit[i][N] != 0)) return false;
	}
	return true;
}

inline void Solve(int64 N) {
	if (N == n) {
		token = 1;
		for (auto _iter : v) {
			cout << _iter << ' ';
		}
		return;
	}
	for (int64 i = -10; i < 11; ++i) {
		_bit[N][N] = i; v.size();
		for (int64 j = 0; j < N; ++j) {
			_bit[j][N] = _bit[j][N - 1]  + _bit[N][N];
		}
		if (Guess(N)) {
			v.push_back(i);
			Solve(N + 1);
			v.pop_back();
		}
		if (token) return;
	}
}

int main() {
	fastio;

	cin >> n;
	for (int64 i = 0; i < n; ++i) {
		for (int64 j = i; j < n; ++j) {
			cin >> _map[i][j];
		}
	}

	Solve(0);
	
	return EXIT_SUCCESS;
}
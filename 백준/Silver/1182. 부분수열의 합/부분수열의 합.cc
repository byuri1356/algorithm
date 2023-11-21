#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 ans = 0;
vector<int64> v;

inline void Solve(int64 _cur, int64 _sel, int64 _goal, int64 _sum) {
	if (!_sel) {
		if (_goal == _sum) {
			ans++;
			return;
		}
		return;
	}
	for (int64 i = _cur; i < v.size(); ++i) {
		Solve(i+1, _sel - 1, _goal, _sum + v[i]);
	}
}

int main() {
	fastio;

	int64 N, S, n;
	cin >> N >> S;
	for (int64 i = 0; i < N;) {
		cin >> n;
		v.push_back(n);
		++i;
	}
	
	for (int64 i = 1; i <= N;) {
		Solve(0, i, S, 0);
		++i;
	}

	cout << ans;
	return EXIT_SUCCESS;
}
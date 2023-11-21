#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 N, M, ans;
vector<int64> v;

inline void dfs(int64 cur_f, int64 cur, int64 dep, int64 total) {
	if (cur) {
		if (cur % 2) ans = ans + (M / total);
		else ans = ans - (M / total);
		if (cur == dep)	return;
	}

	for (int64 i = cur_f; i < v.size(); ++i) {
		dfs(i + 1, cur + 1, dep, total * v[i]);
	}
}

int main() {
	fastio;

	cin >> N >> M;

	for (int64 i = 0; i < N; ++i) {
		int64 a;
		cin >> a;
		v.push_back(a);
	}
	
	dfs(0, 0, v.size(), 1);
	
	cout << ans;

	return EXIT_SUCCESS;
}
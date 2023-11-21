#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 N, dummy_N, ans;
vector<int64> v;

inline void dfs(int64 cur_f, int64 cur, int64 dep, int64 total) {
	if (cur) {
		if (cur % 2) ans = ans - (dummy_N / total);
		else ans = ans + (dummy_N / total);
		if (cur == dep)	return;
	}

	for (int64 i = cur_f; i < v.size(); ++i) {
		dfs(i + 1, cur + 1, dep, total * v[i]);
	}
}

int main() {
	fastio;

	cin >> N;
	dummy_N = N;
	ans = N;

	if (N != 1) {
		for (int64 i = 2; i <= sqrt(dummy_N); ++i) {
			while (1) {
				if (N % i == 0) {
					v.push_back(i);
					N /= i;
				}
				else break;
			}
		}
		if (N > sqrt(dummy_N)) v.push_back(N);

		v.erase(unique(v.begin(), v.end()), v.end());

		dfs(0, 0, v.size(), 1);
	}

	cout << ans;

	return EXIT_SUCCESS;
}
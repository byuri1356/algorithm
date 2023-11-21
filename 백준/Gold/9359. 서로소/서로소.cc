#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 N, dummy_N, A, B, mx, mi, ans;
vector<int64> v;

inline void miDfs(int64 cur_f, int64 cur, int64 dep, int64 total) {
	if (cur) {
		if (cur % 2) A = A - (mi / total);
		else A = A + (mi / total);
		if (cur == dep)	return;
	}

	for (int64 i = cur_f; i < v.size(); ++i) {
		miDfs(i + 1, cur + 1, dep, total * v[i]);
	}
}

inline void mxDfs(int64 cur_f, int64 cur, int64 dep, int64 total) {
	if (cur) {
		if (cur % 2) B = B - (mx / total);
		else B = B + (mx / total);
		if (cur == dep)	return;
	}

	for (int64 i = cur_f; i < v.size(); ++i) {
		mxDfs(i + 1, cur + 1, dep, total * v[i]);
	}
}

int main() {
	fastio;

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> A >> B >> N;
		A -= 1;
		dummy_N = N;
		mx = B;
		mi = A;

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

			mxDfs(0, 0, v.size(), 1);
			miDfs(0, 0, v.size(), 1);
			ans = B - A;
		}
		else ans = mx - mi;

		cout << "Case #" << t << ": " << ans << "\n";
		ans = 0;
		v.clear();

	}

	return EXIT_SUCCESS;
}
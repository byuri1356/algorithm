#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

map<int, int> mp;

int main() {
	fastio;

	int64 Ans = 0;
	vector<pair<int64, int64>> vp;
	int N;
	cin >> N;

	int64 a;
	cin >> a;
	vp.push_back({ a, 1 });

	for (int i = 1; i < N; ++i) {
		cin >> a;

		int idx = -1;
		for (int j = vp.size() - 1; j >= 0; --j) {
			if (vp[j].first < a) {
				Ans += vp[j].second;
				vp.pop_back();
			}
			else if (vp[j].first == a) {
				Ans += vp[j].second;
				idx = j;
			}
			else {
				Ans++;
				break;
			}
		}

		if (idx == -1) vp.push_back({ a, 1 });
		else vp[idx].second++;
	}

	cout << Ans;

	return EXIT_SUCCESS;
}
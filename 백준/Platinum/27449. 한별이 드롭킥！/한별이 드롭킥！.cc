#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 N, M;
int64 dp[2][5002][5002], ht[5002][5002], ans;
vector<pair<int64, int64>> pv, mv;

int main() {

	fastio;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;

		if (a > 0) pv.push_back({ a ,b });
		else mv.push_back({ a, b });
	}

	pv.push_back({ 0, 0 });
	mv.push_back({ 0, 0 });

	sort(pv.begin(), pv.end());
	sort(mv.rbegin(), mv.rend());

	int msz = mv.size(), psz = pv.size();

	pv.push_back({ 1e13, 0 });
	mv.push_back({ -1e13, 0 });

	ht[0][0] = dp[0][0][0] = dp[1][0][0] = M;

	for (int i = 1; i < msz; ++i) {
		ht[i][0] = ht[i - 1][0] + mv[i].second;
	}

	for (int i = 1; i < psz; ++i) {
		ht[0][i] = ht[0][i - 1] + pv[i].second;
	}

	for (int i = 0; i < msz; ++i) {
		for (int j = 0; j < psz; ++j) {
			if (dp[0][i][j] || dp[1][i][j]) {
				ans = max(ans, ht[i][0] + ht[0][j] - ht[0][0]);

				int64 h = dp[0][i][j] + mv[i + 1].first - mv[i].first;
				if (h > 0) {
					dp[0][i + 1][j] = max(dp[0][i + 1][j], h + mv[i + 1].second);
				}

				h = dp[0][i][j] + mv[i].first - pv[j + 1].first;
				if (h > 0) {
					dp[1][i][j + 1] = max(dp[1][i][j + 1], h + pv[j + 1].second);
				}

				h = dp[1][i][j] + mv[i + 1].first - pv[j].first;
				if (h > 0) {
					dp[0][i + 1][j] = max(dp[0][i + 1][j], h + mv[i + 1].second);
				}

				h = dp[1][i][j] - pv[j + 1].first + pv[j].first;
				if (h > 0) {
					dp[1][i][j + 1] = max(dp[1][i][j + 1], h + pv[j + 1].second);
				}
			}
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}
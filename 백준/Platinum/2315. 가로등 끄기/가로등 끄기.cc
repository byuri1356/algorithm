#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M;
int64 dp[2][1002][1002], nu[1002][1002];

int main() {

	fastio;

	fill_n(&dp[0][0][0], 2 * 1002 * 1002, 1e14);

	dp[0][0][0] = dp[1][0][0] = 0;

	cin >> N >> M;

	vector<pair<int, int64>> mv(M), pv(N - M + 1);

	for (int i = M - 1; i >= 0; --i) {
		cin >> mv[i].first >> mv[i].second;
	}

	pv[0] = mv[0];

	for (int i = 1; i < N - M + 1; ++i) {
		cin >> pv[i].first >> pv[i].second;
	}

	for (int i = mv.size() - 2; i >= 0; --i) {
		nu[i][pv.size() - 1] = nu[i + 1][pv.size() - 1] + mv[i + 1].second;
	}

	for (int i = pv.size() - 2; i >= 0; --i) {
		nu[mv.size() - 1][i] = nu[mv.size() - 1][i + 1] + pv[i + 1].second;
	}

	mv.push_back({ -1, 0 });
	pv.push_back({ 1001, 0 });

	for (int i = 0; i < mv.size() - 1; ++i) {
		for (int j = 0; j < pv.size() - 1; ++j) {
			nu[i][j] = nu[mv.size() - 2][j] + nu[i][pv.size() - 2];

			int64 h = dp[0][i][j] + nu[i][j] * (mv[i].first - mv[i + 1].first);
			if (dp[0][i + 1][j] > h) {
				dp[0][i + 1][j] = h;
			}

			h = dp[0][i][j] + nu[i][j] * (pv[j + 1].first - mv[i].first);
			if (dp[1][i][j + 1] > h) {
				dp[1][i][j + 1] = h;
			}

			h = dp[1][i][j] + nu[i][j] * (pv[j].first - mv[i + 1].first);
			if (dp[0][i + 1][j] > h) {
				dp[0][i + 1][j] = h;
			}

			h = dp[1][i][j] + nu[i][j] * (pv[j + 1].first - pv[j].first);
			if (dp[1][i][j + 1] > h) {
				dp[1][i][j + 1] = h;
			}
		}
	}

	cout << min(dp[0][mv.size() - 2][pv.size() - 2], dp[1][mv.size() - 2][pv.size() - 2]);

	return EXIT_SUCCESS;
}
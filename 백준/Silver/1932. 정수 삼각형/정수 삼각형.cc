#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 Ans = 0;
vector<int64> v[500], dp[500];

int main() {
	fastio;

	int64 T, t;
	cin >> T;

	for (int64 i = 0; i < T; ++i) {
		for (int64 j = 0; j <= i; ++j) {
			cin >> t;
			v[i].push_back(t);
			dp[i].push_back(t);
		}
	}
	Ans = dp[0][0];
	for (int64 i = 0; i <T-1; ++i) {
		for (int64 j = 0; j <= i; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
			Ans = max(Ans, dp[i + 1][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], dp[i][j] + v[i + 1][j+1]);
			Ans = max(Ans, dp[i + 1][j+1]);
		}
	}
	cout << Ans;
	return EXIT_SUCCESS;
}
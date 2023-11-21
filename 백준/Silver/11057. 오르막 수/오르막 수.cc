#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dp[1001][10] = { {1,1,1,1,1,1,1,1,1,1} };

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 i = 1; i <= T; ++i) {
		dp[i][0] = dp[i - 1][0] % 10'007;
		dp[i][1] = (dp[i - 1][1] + dp[i][0]) % 10'007;
		dp[i][2] = (dp[i - 1][2] + dp[i][1]) % 10'007;
		dp[i][3] = (dp[i - 1][3] + dp[i][2]) % 10'007;
		dp[i][4] = (dp[i - 1][4] + dp[i][3]) % 10'007;
		dp[i][5] = (dp[i - 1][5] + dp[i][4]) % 10'007;
		dp[i][6] = (dp[i - 1][6] + dp[i][5]) % 10'007;
		dp[i][7] = (dp[i - 1][7] + dp[i][6]) % 10'007;
		dp[i][8] = (dp[i - 1][8] + dp[i][7]) % 10'007;
		dp[i][9] = (dp[i - 1][9] + dp[i][8]) % 10'007;
	}

	cout << dp[T][9] % 10'007;
	return EXIT_SUCCESS;
}
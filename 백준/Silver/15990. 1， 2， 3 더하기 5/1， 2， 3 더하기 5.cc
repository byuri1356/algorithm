#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dp[100'001][3];

int main() {
	fastio;

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][0] = 1;
	for (int64 i = 4; i <= 1'00'000; ++i) {
		for (int64 j = 1; j <= 3; ++j) {
			dp[i][j % 3] += dp[i - j][(j + 1) % 3] % 1'000'000'009 + dp[i - j][(j + 2) % 3] % 1'000'000'009;
		}
	}
	int64 T, t;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> t;
		cout << (dp[t][0] + dp[t][1] + dp[t][2]) % 1'000'000'009 <<"\n";
	}
	
	return EXIT_SUCCESS;
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dp[100'001][4];

int main() {
	fastio;

	int64 T;
	cin >> T;

	dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1;

	for (int64 i = 2; i <= T; ++i) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 9901;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 9901;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
	}

	cout << (dp[T][1] + dp[T][2] + dp[T][3]) % 9901;
	return EXIT_SUCCESS;
}
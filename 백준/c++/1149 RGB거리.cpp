#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1001][4], dp[1001][4], _min = INF;

int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 1; i <= T; ++i) {
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	dp[1][1] = arr[1][1]; dp[1][2] = arr[1][2]; dp[1][3] = arr[1][3];

	for (int64 i = 2; i <= T; ++i) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
	}

	for (int64 i = 1; i < 4; ++i) {
		_min = min(dp[T][i], _min);
	}
	cout << _min;
	return EXIT_SUCCESS;
}
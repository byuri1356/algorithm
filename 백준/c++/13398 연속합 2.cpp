#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[100'001], dp[100'001], bdp[100'001], Ans = -INF;
int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	Ans = dp[0];
	for (int64 i = 1; i < T; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		bdp[i] = bdp[i - 1] + arr[i];
		if (arr[i] < 0) {
			bdp[i] = max(bdp[i], dp[i - 1]);
		}
		Ans = max(Ans, dp[i]);
		Ans = max(Ans, bdp[i]);
	}

	cout << Ans;

	return EXIT_SUCCESS;
}
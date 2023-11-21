#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1'001], dp[1'001], Ans;

int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 1; i <= T; ++i) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	Ans = arr[1];
	for (int64 i = 1; i < T; ++i) {
		for (int64 j = i + 1; j <= T; ++j) {
			if (arr[j] > arr[i]) dp[j] = max(dp[j], arr[j] + dp[i]);
			Ans = max(Ans, dp[j]);
		}
	}

	cout << Ans;
	return EXIT_SUCCESS;
}
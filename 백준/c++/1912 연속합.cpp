#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[100'001], dp[100'001], Ans = -INF;
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
		Ans = max(Ans, dp[i]);
	}
	
	cout << Ans;

	return EXIT_SUCCESS;
}
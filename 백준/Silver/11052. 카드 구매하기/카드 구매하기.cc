#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dp[1'001] = {};

int main() {
	fastio;

	int64 N, P;
	cin >> N;
	for (int64 i = 1; i <= N; ++i) {
		cin >> P;
		for (int64 j = i; j <= N; ++j) {
			dp[j] = max(dp[j], dp[j - i] + P);
		}
	}
	cout << dp[N];
	return EXIT_SUCCESS;
}
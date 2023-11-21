#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 W[21], V[21], dp[101];

int main() {
	fastio;

	int64 N;
	cin >> N;
	for (int64 i = 1; i <= N;) {
		cin >> W[i];
		++i;
	}
	for (int64 i = 1; i <= N;) {
		cin >> V[i];
		for (int64 j = 100; j > W[i];) {
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
			--j;
		}
		++i;
	}
	cout << dp[100];

	return EXIT_SUCCESS;
}
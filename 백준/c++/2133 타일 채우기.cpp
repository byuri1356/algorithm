#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 dp[31] = { 1, 0, 3, 0, 11, };

int main() {
	fastio;

	int64 T;
	cin >> T;
	for (int64 i = 5; i <= T; ++i) {
		if (i % 2)dp[i] = 0;
		else {
			dp[i] = 3 * dp[i - 2];
			for (int64 j = i - 4; j >= 0; j -= 2) {
				dp[i] += 2 * dp[j];
			}
		}
	}

	cout << dp[T];

	return EXIT_SUCCESS;
}
#include<iostream>

using namespace std;
using ll = long long;

ll t, a, s, b, x, ans, arr[201], dp[202][4002];
const int MOD = 1e6;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t >> a >> s >> b;
	for (int i = 0; i < a; ++i) cin >> x, ++arr[x];

	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= arr[i]; ++j) ++dp[i][j];
		for (int j = 1; j <= a; ++j) {
			dp[i][j] += dp[i - 1][j];
			for (int k = 1; k <= arr[i]; ++k) {
				if (j - k > 0) dp[i][j] += dp[i - 1][j - k] % MOD;
			}
		}
	}

	for (int i = s; i <= b; ++i) ans += dp[t][i];
	cout << ans % MOD;

	return 0;
}
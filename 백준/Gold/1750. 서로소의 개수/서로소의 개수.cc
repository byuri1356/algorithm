#include<iostream>
#include<map>
#define MOD 10'000'003
using namespace std;
using ll = long long;

ll n, dp[52][100'002];

ll gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;

		dp[i][a] = 1;

		for (int j = 100'000; 0 <= j; --j) {
			dp[i][j] += dp[i - 1][j] % MOD;
			dp[i][gcd(j, a)] += dp[i - 1][j] % MOD;
		}
	}

	cout << dp[n][1] % MOD;

	return 0;
}
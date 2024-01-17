#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
ll N, L, R, dp[101][101][101];

ll solve(int n, int l, int r) {
	if (l <= 0 || r <= 0 || n <= 0) return 0;
	if (dp[n][l][r] != -1) return dp[n][l][r];

	dp[n][l][r] = 0;

	return dp[n][l][r] = (solve(n-1, l-1, r) + solve(n-1, l, r-1) + solve(n-1, l, r) * (n - 2)) % MOD;

}

int main() {

	fastio;

	memset(dp, -1, sizeof(dp));

	dp[1][1][1] = 1;

	cin >> N >> L >> R;

	cout << solve(N, L, R);

}
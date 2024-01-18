#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define MOD 1000000000
using namespace std;
using ll = long long;

ll N, answer, dp[101][10][1<<10];

ll solve(int n, int pv, int bt) {
	if (pv < 0 || 9 < pv) return 0;
	if (dp[n][pv][bt] != -1) return dp[n][pv][bt];
	if (n == N) return bt == (1 << 10) - 1 ? 1 : 0;

	dp[n][pv][bt] = 0;

	return dp[n][pv][bt] = (solve(n + 1, pv - 1, (bt | (1 << (pv - 1)))) + solve(n + 1, pv + 1, (bt | (1 << (pv + 1))))) % MOD;

}

int main() {

	fastio;

	cin >> N;

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < 10; ++i) {
		answer += solve(1, i, 1 << i);
	}
	
	cout << answer % MOD;
}
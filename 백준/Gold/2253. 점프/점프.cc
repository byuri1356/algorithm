#include<iostream>
#include<map>
using namespace std;

int n, m, a, ans, s[10001];
map<int, int> dp[10150];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	while (m--) cin >> a, ++s[a];

	dp[1][0] = 0;
	for (int i = 1; i <= n; ++i) for (auto& j : dp[i]) {
		for (int k = j.first + 1; j.first - 2 < k && 0 < k; --k) {
			if (s[i + k]) continue;
			auto& ref = dp[i + k][k];
			if (!ref) ref += j.second + 1;
			else ref = min(ref, j.second + 1);
		}
	}

	ans = 1e9;

	for (auto& i : dp[n]) ans = min(ans, i.second);
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}
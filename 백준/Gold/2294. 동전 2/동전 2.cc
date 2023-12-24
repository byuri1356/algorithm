#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	vector<int> coin, dp(200001, 1000000);
	dp[0] = 0;

	int n, k;
	cin >> n >> k;

	while (n--) {
		int a; cin >> a;
		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());


	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < coin.size(); ++j) {
			dp[i + coin[j]] = min(dp[i + coin[j]], dp[i] + 1);
		}
	}

	if (dp[k] == 1000000) cout << -1;
	else cout << dp[k];
}
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	vector<int> coin, dp(100001);
	dp[0] = 1;

	int n, k;
	cin >> n >> k;

	while (n--) {
		int a; cin >> a;
		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());


	for (int i = 0; i < coin.size(); ++i) {
		for (int j = coin[i]; j <= k; ++j) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];
}
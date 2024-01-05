#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int n, m; cin >> n >> m;
	
	vector<int> dp(n + 1);
	vector<bool> vip(n + 1);

	for (int i = 0; i < m; ++i) {
		int l; cin >> l;
		vip[l] = true;
	}

	dp[0] = dp[1] = 1;
	dp[2] = vip[1] || vip[2] ? 1 : 2;

	for (int i = 3; i <= n; ++i) {
		dp[i] = vip[i] || vip[i - 1] ? dp[i - 1] : dp[i - 2] + dp[i - 1];
	}
	
	cout << dp[n];

}
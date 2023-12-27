#include<iostream>
#include<vector>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

const int MOD = 1e6;

int main() {

	fastio;

	string s; cin >> s;
	vector<ll> dp(5002);

	s = '#' + s;
	dp[0] = dp[1] = 1;

  	for (int i = 2; i < s.length(); ++i) {
		if (s[i] != '0') dp[i] += dp[i - 1];
		
		int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
		if (10 <= tmp && tmp <= 26) dp[i] += dp[i - 2];

		dp[i] %= MOD;
	}

	if (s[1] == '0') cout << 0;
	else cout << dp[s.length() - 1];

}
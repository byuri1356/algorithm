#include<iostream>
#include<string>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int dp[501][501];
string s;

int sol(int l, int r) {

	if (l < 0 || s.length() - 1 < r || r < l) return 0;

	if (dp[l][r] != -1) return dp[l][r];

	dp[l][r] = 0;

	for (int i = l; i <= r; ++i) dp[l][r] = max(dp[l][r], sol(l, i) + sol(i + 1, r));

	if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c')) dp[l][r] = max(dp[l][r], sol(l+1, r-1) + 2);

	return dp[l][r];
}

int main() {

	fastio;

	memset(dp, -1, sizeof(dp));

	cin >> s;

	cout << sol(0, s.length() - 1);

	//cout << "!";

}
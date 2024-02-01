#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

const int MOD = 1e9;

ll N, dp[1'000'0001];

int main() {

	fastio;

	cin >> N;

	dp[2] = 1;
	
	for (int i = 3; i <= N; ++i) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]), dp[i] %= MOD;

	cout << dp[N];

}
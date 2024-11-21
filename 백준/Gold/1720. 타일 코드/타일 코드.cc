#include<iostream>
using namespace std;
using ll = long long;

int dp[31];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 31; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	}

	int n;
	cin >> n;

	if (n % 2) cout << (dp[n] + dp[(n - 1) / 2]) / 2;
	else cout << (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;


	return 0;
}
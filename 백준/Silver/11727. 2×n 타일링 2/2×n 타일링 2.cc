#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int64 T, dp[1001] = { 0,1,3 };
	cin >> T;
	for (int64 i = 3; i < 1001;) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
		++i;
	}
	cout << dp[T]%10007;
	
	return EXIT_SUCCESS;
}
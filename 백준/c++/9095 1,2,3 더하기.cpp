#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int64 dp[12] = { 0,1,2,4 };
	for (int64 i = 4; i < 12;) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		++i;
	}
	int64 T,t;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		cout << dp[t] << "\n";
		++i;
	}
	
	return EXIT_SUCCESS;
}
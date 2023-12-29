#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

struct s {
	int a, b;
};

int main() {

	fastio;

	int t; cin >> t;

	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		vector<s> arr(n), dp(n);

		for (int j = 0; j < n; ++j) cin >> arr[j].a;
		for (int j = 0; j < n; ++j) cin >> arr[j].b;

		dp[0].a = arr[0].a;
		dp[0].b = arr[0].b;

		for (int j = 1; j < n; ++j) dp[j].a = max(dp[j - 1].a, dp[j - 1].b + arr[j].a), dp[j].b = max(dp[j - 1].b, dp[j - 1].a + arr[j].b);

		cout << max(dp[n - 1].a, dp[n - 1].b) << "\n";
	}

}
#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int n; cin >> n;
	vector<int> arr(n + 2), dp(n);

	for (int i = 0; i < n; ++i) cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	dp[2] = max(dp[0], arr[1]) + arr[2];

	for (int i = 3; i < n; ++i) dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];

	cout << dp[n - 1];
}
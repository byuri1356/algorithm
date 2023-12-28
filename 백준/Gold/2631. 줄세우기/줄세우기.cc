#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int mx = 0, n; cin >> n;
	vector<int> arr(n), dp(n, 1);

	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1), mx = max(mx, dp[i]);

	cout << n - mx;
	
}
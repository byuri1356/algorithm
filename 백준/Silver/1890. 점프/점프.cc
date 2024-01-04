#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int n;

ll solve(int x, int y, vector<vector<ll>>& arr, vector<vector<ll>>& dp) {
	if (x < 0 || n <= x || y < 0 || n <= y) return 0;

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	return dp[x][y] = solve(x + arr[x][y], y, arr, dp) + solve(x, y + arr[x][y], arr, dp);
}

int main() {

	fastio;

	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n)), dp(n, vector<ll>(n, -1));

	dp[n - 1][n - 1] = 1;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	cout << solve(0, 0, arr, dp);

}
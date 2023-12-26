#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int n, m;
int arr[501][501], dp[501][501];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

bool isValid(int x, int y) {
	return (0 <= x) && (x < n) && (0 <= y) && (y < m);
}

int solve(int x, int y) {

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isValid(nextX, nextY) && (arr[nextX][nextY] < arr[x][y])) {
			dp[x][y] = dp[x][y] + solve(nextX, nextY);
		}
	}

	return dp[x][y];

}

int main() {

	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	dp[n - 1][m - 1] = 1;

	cout << solve(0, 0);

}
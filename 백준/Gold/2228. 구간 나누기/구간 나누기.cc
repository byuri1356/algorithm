#include<iostream>
#include<vector>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define MOD 1000000000
using namespace std;
using ll = long long;

int N, M;
int arr[101], sum[101], dp[101][52];

int sol(int n, int m) {

	if (n < 2 * m - 1) return -9999999;

	if (dp[n][m] != -1e9) return dp[n][m];

	dp[n][m] = sol(n - 1, m);

	for (int i = 2; i < n; ++i) {
		dp[n][m] = max(dp[n][m], sol(i - 1, m - 1) + sum[n] - sum[i]);
	}

	return dp[n][m];

}

int main() {

	fastio;

	cin >> N >> M;

	fill(&dp[0][0], &dp[0][0] + 101 * 52, -1e9);

	int currentSum = -1e9;
	int maxSum = -1e9;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];

		sum[i] = arr[i] + sum[i - 1];

		if (currentSum + arr[i] > arr[i]) currentSum += arr[i];
		else currentSum = arr[i];

		if (maxSum < currentSum) maxSum = currentSum;

		dp[i][1] = maxSum;
	}

	cout << sol(N, M);

	//cout << "!";

}
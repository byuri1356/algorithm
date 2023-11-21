#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int arr[4002][4002], dp[801][4002];

void sol(int p, int l, int r, int pl, int pr) {
	if (l > r) return;

	int lem, m = (l + r) >> 1;
	int pm = min(m, pr);

	dp[p][m] = INT32_MAX;

	for (int i = pl; i <= pm; ++i) {
		int c = dp[p - 1][i] + arr[i + 1][m];
		if (dp[p][m] > c) {
			dp[p][m] = c;
			lem = i;
		}
	}

	sol(p, l, m - 1, pl, lem);
	sol(p, m + 1, r, lem, pr);
}

int main() {

	fastio;

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			arr[j][i] += arr[j + 1][i];
		}
	}

	for (int i = 1; i <= N; ++i) {
		dp[1][i] = arr[1][i];
	}

	for (int i = 2; i <= K; ++i) {
		sol(i, 1, N, 1, N);
	}

	cout << dp[K][N];
	return EXIT_SUCCESS;
}
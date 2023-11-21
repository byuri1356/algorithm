#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int dp[501][501], nu[501];

int main() {

	fastio;

	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;

		for (int i = 1; i <= K; ++i) {
			cin >> dp[i][i];
			nu[i] = dp[i][i] + nu[i - 1];
		}

		for (int i = 1; i < K; ++i) {
			for (int j = 1; j + i <= K; ++j) {
				dp[j][j + i] = INT32_MAX;
				for (int k = j; k < j + i; ++k) {
					dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + nu[j + i] - nu[j - 1]);
				}
			}
		}

		cout << dp[1][K] - nu[K] << "\n";
	}

	return EXIT_SUCCESS;
}
#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int dp[5001][5001], lm[5001][5001]; // lemma

//DP[i][j]   = min(DP[i][k] + DP[k+1][j]) + s[j] - s[i-1];
//DP[i+1][j] = min(DP[i+1][k] + DP[k+1][j]) + s[j] - s[i];
//dp[i][j] = DP[i+1][j]
//dp[i][j] = min(dp[i][k] + dp[k][j]) + s[j] - s[i];


int main() {

	fastio;

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;

		vector<int> nu(N + 1), pg(N + 1);

		for (int i = 1; i <= N; ++i) {
			cin >> pg[i];
			nu[i] = nu[i - 1] + pg[i];
			dp[i - 1][i] = 0;
			lm[i - 1][i] = i;
		}

		for (int l = 2; l <= N; ++l) {
			for (int i = 0; i + l <= N; ++i) {
				int j = i + l;
				dp[i][j] = INT32_MAX;
				for (int k = lm[i][j - 1]; k <= lm[i + 1][j]; ++k) {
					int cur = dp[i][k] + dp[k][j] + nu[j] - nu[i];
					if (dp[i][j] > cur) {
						dp[i][j] = cur;
						lm[i][j] = k;
					}
				}
			}
		}

		cout << dp[0][N] << "\n";
	}

	return EXIT_SUCCESS;
}
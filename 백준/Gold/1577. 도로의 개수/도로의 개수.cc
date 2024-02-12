#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

ll n, m, k, work[51][4], dp[102][102];


int main() {

	fastio;

	cin >> n >> m >> k;

	dp[0][0] = 1;

	for (int i = 0; i < k; ++i) cin >> work[i][0] >> work[i][1] >> work[i][2] >> work[i][3];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {

			bool flag = true;
			for (int a = 0; a < k; ++a) {
				if ((i == work[a][0] && j == work[a][1] && i + 1 == work[a][2] && j == work[a][3]) ||
					i == work[a][2] && j == work[a][3] && i + 1 == work[a][0] && j == work[a][1])
					flag = false;
			}
			if (flag) dp[i + 1][j] += dp[i][j];

			flag = true;
			for (int a = 0; a < k; ++a) {
				if ((i == work[a][0] && j == work[a][1] && i == work[a][2] && j + 1 == work[a][3]) ||
					i == work[a][2] && j == work[a][3] && i == work[a][0] && j + 1 == work[a][1])
					flag = false;
			}
			if (flag) dp[i][j + 1] += dp[i][j];
		}
	}

	cout << dp[n][m];

	//cout << "!";
}
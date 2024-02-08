#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

const int MOD = 1e6 + 7;

int n, m, c, flag, dp[52][52][52][52], room[52][52];

int main() {

	fastio;

	cin >> n >> m >> c;

	for (int i = 1; i <= c; ++i) {
		int a, b; cin >> a >> b;
		room[a][b] = i;
	}

	if (room[1][1]) dp[1][1][room[1][1]][1] = 1;
	else dp[1][1][0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (room[i][j]) flag = room[i][j];
			else flag = c;

			for (int k = 0; k <= flag; ++k) {
				for (int l = 0; l <= k; ++l) {
					dp[i][j][k][l] %= MOD;
					if (!room[i + 1][j]) dp[i + 1][j][k][l] += dp[i][j][k][l];
					if (room[i + 1][j] && (k < room[i + 1][j])) dp[i + 1][j][room[i + 1][j]][l + 1] += dp[i][j][k][l];
					if (!room[i][j + 1]) dp[i][j + 1][k][l] += dp[i][j][k][l];
					if (room[i][j + 1] && (k < room[i][j + 1])) dp[i][j + 1][room[i][j + 1]][l + 1] += dp[i][j][k][l];
				}
			}
		}
	}

	for (int i = 0; i <= c; ++i) {
		int mx = 0;
		for (int j = 0; j <= c; ++j) mx += dp[n][m][j][i];
		cout << mx % MOD << " ";
	}

	//cout << "!";
}
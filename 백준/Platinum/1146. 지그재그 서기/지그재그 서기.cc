#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

ll n, ans, dp[102][102][102][2];

ll sol(int o, int l, int r, int c) {
	ll& ref = dp[o][l][r][c];
	if (ref != -1) return ref;
	if (o == n + 1) return 1;

	ref = 0;

	if (c) {
		for (int i = 1; i <= l; ++i) {
			ref += sol(o + 1, i - 1, r + l - i, 0);
		}
	}
	else {
		for (int i = 1; i <= r; ++i) {
			ref += sol(o + 1, l + i - 1, r - i, 1);
		}
	}

	return ref %= 1'000'000;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> n;

	if (n < 3) cout << n;
	else {
		for (int i = 1; i <= n; ++i) {
			int l = i - 1, r = n - i;
			for (int j = 1; j <= l; ++j) {
				int lt = j - 1, rt = r + l - j;
				ans += sol(3, lt, rt, 0);
			}
			for (int j = 1; j <= r; ++j) {
				int lt = l + j - 1, rt = r - j;
				ans += sol(3, lt, rt, 1);
			}
		}

		cout << ans % 1'000'000;
	}

	//cout << "!";
}
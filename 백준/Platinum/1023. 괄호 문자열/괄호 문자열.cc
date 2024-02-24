#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;

ll n, k, dp[52][104][2];

ll sol(int idx, int p, int f) {
	ll& ref = dp[idx][p + n][f];
	if (ref != -1) return ref;

	if (idx == n) return ref = f || p != 0;

	ref = 0;
	ref += sol(idx + 1, p + 1, f) + sol(idx + 1, p - 1, f || p <= 0);

	return ref;
}

void sol1(int idx, int p, int f) {
	if (idx == n) return;

	ll ret = dp[idx + 1][p + n + 1][f];

	if (ret < k) {
		cout << ")";
		k -= ret;
		sol1(idx + 1, p - 1, f || p <= 0);
	}
	else {
		cout << "(";
		sol1(idx + 1, p + 1, f);
	}

}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> n >> k;
	k++;

	if (sol(0, 0, 0) < k) cout << -1;
	else sol1(0, 0, 0);

	return 0;
}
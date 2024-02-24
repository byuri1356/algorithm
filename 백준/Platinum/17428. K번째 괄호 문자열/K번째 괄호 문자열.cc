#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;

ll n, k, dp[52][52];

ll sol(int idx, int p) {
	if (p < 0) return 0;

	ll& ref = dp[idx][p];
	if (ref != -1) return ref;
	if (idx == n) return ref = !p;

	ref = sol(idx + 1, p + 1) + sol(idx + 1, p - 1);

	return ref;
}

void sol1(int idx, int p) {
	if (idx == n) return;

	ll ret = dp[idx + 1][p + 1];

	if (ret < k) {
		cout << ")";
		k -= ret;
		sol1(idx + 1, p - 1);
	}
	else {
		cout << "(";
		sol1(idx + 1, p + 1);
	}

}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> n >> k;
	k++;

	if (sol(0, 0) < k) cout << -1;
	else sol1(0, 0);

	return 0;
}
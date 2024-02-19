#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

ll n, m, l, dp[33][33];

ll sol(int n, int m) {
	ll& ref = dp[n][m];
	if (ref != -1) return ref;
	if (m == 0 || n == 0) return ref = 1;

	ref = sol(n - 1, m);
	ref += sol(n - 1, m - 1);

	return ref;
}

void pv(int n, int m) {

	if (n == 0) return;
	ll pivot = sol(n - 1, m);
	if (pivot < l) {
		cout << "1";
		l -= pivot;
		pv(n - 1, m - 1);
	}
	else {
		cout << "0";
		pv(n - 1, m);
	}
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	dp[0][0] = dp[1][0] = 1;

	cin >> n >> m >> l;

	pv(n, m);

}
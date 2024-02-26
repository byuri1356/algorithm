#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;

ll n, m, dp[21][21];

ll sol(int k, int b) {
	if (b < 0) return 0;
	if (k == 0) return 1;

	ll& ref = dp[k][b];
	if (ref != -1) return ref;

	return ref = sol(k - 1, b) * (k - 1) + sol(k - 1, b - 1);
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> n >> m;
	ll a = sol(n, m), b = 1, c;
	for (int i = 1; i <= n; ++i) b *= i;
	
	c = gcd(a, b);

	cout << a / c << "/" << b / c;

	return 0;
}
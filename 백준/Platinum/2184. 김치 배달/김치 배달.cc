#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k[1003], dp[1003][1003][2];

int sol(int l, int r, int d, int idx) {
	if (l == 0 && r == n) return 0;

	int &ref = dp[l][r][d];
	if (ref != 1e9) return ref;

	int cur = d ? k[l] : k[r];

	if (0 < l) ref = min(ref, idx * abs(cur - k[l - 1]) + sol(l - 1, r, 1, idx - 1));
	if (r < n) ref = min(ref, idx * abs(k[r + 1] - cur) + sol(l, r + 1, 0, idx - 1));

	return ref;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	fill(&dp[0][0][0], &dp[0][0][0] + sizeof dp / sizeof(int), 1e9);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> k[i]; k[0] = m;

	sort(k, k + n + 1);

	int start = lower_bound(k, k + n + 1, m) - k;

	cout<<sol(start, start, 1, n);

	//cout << "!";

	return 0;
}
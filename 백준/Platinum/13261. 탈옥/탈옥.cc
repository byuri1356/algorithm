#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 dp[801][8003], nu[8003];

int64 sum(int64 l, int64 r) {
	return (nu[r] - nu[l - 1]) * (r - l + 1);
}

void sol(int p, int l, int r, int pl, int pr) {
	if (l > r) return;

	int lem, m = (l + r) >> 1;
	int pm = min(pr, m);
	dp[p][m] = INT64_MAX;

	for (int i = pl; i <= pm; ++i) {
		int64 cur = dp[p - 1][i] + sum(i + 1, m);
		if (dp[p][m] > cur) {
			dp[p][m] = cur;
			lem = i;
		}
	}

	sol(p, l, m - 1, pl, lem);
	sol(p, m + 1, r, lem, pr);
}

int main() {

	fastio;

	int L, G;
	cin >> L >> G;
	
	for (int i = 1; i <= L; ++i) {
		cin >> nu[i];
		nu[i] += nu[i - 1];
		dp[1][i] = sum(1, i);
	}

	G = min(G, L);

	for (int i = 2; i <= G; ++i) {
		sol(i, 1, L, 1, L);
	}

	cout << dp[G][L];

	return EXIT_SUCCESS;
}
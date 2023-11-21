#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, D;
int64 ans = INT64_MIN;
vector<int64> T, V;

int64 sum(int64 l, int64 r) {
	return (r - l) * T[r] + V[l];
}

void sol(int l, int r, int pl, int pr) {
	if (l > r) return;

	int m = (l + r) >> 1;
	int lo = max(pl, m - D);
	int hi = min(pr, m + D);

	for (int i = lo; i <= hi; ++i) {
		if (sum(lo, m) < sum(i, m)) {
			lo = i;
		}
	}

	ans = max(ans, sum(lo, m));

	sol(l, m - 1, pl, lo);
	sol(m + 1, r, lo, pr);
}

int main() {

	fastio;

	cin >> N >> D;

	T.resize(N + 1), V.resize(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> T[i];
	}

	for (int i = 1; i <= N; ++i) {
		cin >> V[i];
	}

	sol(1, N, 1, N);

	cout << ans;

	return EXIT_SUCCESS;
}
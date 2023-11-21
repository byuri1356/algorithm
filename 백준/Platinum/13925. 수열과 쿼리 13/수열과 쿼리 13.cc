#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 A[100001], seg[400004], lazy[400004][2];
const int64 MOD = 1e9 + 7;

void lz(int s, int e, int n) {
	int64& mul = lazy[n][0];
	int64& sum = lazy[n][1];

	if (mul == 1 && sum == 0) return;
	
	seg[n] *= mul;
	seg[n] %= MOD;
	seg[n] += sum * (e - s + 1);
	seg[n] %= MOD;

	if (s != e) {
		lazy[n * 2][0] *= mul;
		lazy[n * 2][0] %= MOD;
		lazy[n * 2][1] *= mul;
		lazy[n * 2][1] %= MOD;
		lazy[n * 2][1] += sum;
		lazy[n * 2][1] %= MOD;

		lazy[n * 2 + 1][0] *= mul;
		lazy[n * 2 + 1][0] %= MOD;
		lazy[n * 2 + 1][1] *= mul;
		lazy[n * 2 + 1][1] %= MOD;
		lazy[n * 2 + 1][1] += sum;
		lazy[n * 2 + 1][1] %= MOD;
	}

	mul = 1;
	sum = 0;
}

int64 fd(int s, int e, int n, int l, int r) {
	lz(s, e, n);

	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return (fd(s, h, n * 2, l, r) + fd(h + 1, e, n * 2 + 1, l, r)) % MOD;
}

int64 ud(int s, int e, int n, int l, int r, int64 mul, int64 sum) {
	lz(s, e, n);

	if (r < s || e < l) return seg[n];
	if (l <= s && e <= r) {
		seg[n] *= mul;
		seg[n] %= MOD;
		seg[n] += sum * (e - s + 1);
		seg[n] %= MOD;

		if (s != e) {
			lazy[n * 2][0] *= mul;
			lazy[n * 2][0] %= MOD;
			lazy[n * 2][1] *= mul;
			lazy[n * 2][1] %= MOD;
			lazy[n * 2][1] += sum;
			lazy[n * 2][1] %= MOD;

			lazy[n * 2 + 1][0] *= mul;
			lazy[n * 2 + 1][0] %= MOD;
			lazy[n * 2 + 1][1] *= mul;
			lazy[n * 2 + 1][1] %= MOD;
			lazy[n * 2 + 1][1] += sum;
			lazy[n * 2 + 1][1] %= MOD;
		}

		return seg[n];
	}

	int h = (s + e) >> 1;
	return seg[n] = (ud(s, h, n * 2, l, r, mul, sum) + ud(h + 1, e, n * 2 + 1, l, r, mul, sum)) % MOD;
}

int64 init(int s, int e, int n) {
	if (s == e) return seg[n] = A[s];

	int h = (s + e) >> 1;

	return seg[n] = (init(s, h, n * 2) + init(h + 1, e, n * 2 + 1)) % MOD;
}

int main() {

	fastio;

	int N, M;
	cin >> N;

	for (int i = 0; i < 400004; ++i) {
		lazy[i][0] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}

	init(1, N, 1);

	cin >> M;

	while (M--) {
		int q, x, y;
		int64 v;

		cin >> q >> x >> y;

		switch (q) {
		case 1:
			cin >> v;
			ud(1, N, 1, x, y, 1, v);
			break;
		case 2:
			cin >> v;
			ud(1, N, 1, x, y, v, 0);
			break;
		case 3:
			cin >> v;
			ud(1, N, 1, x, y, 0, v);
			break;
		default:
			cout << fd(1, N, 1, x, y) % MOD << "\n";
			break;
		}
	}


	return EXIT_SUCCESS;
}
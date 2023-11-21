#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

vector<int> seg, arr;

int ud(int s, int e, int n, int p, int d) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) return seg[n] += d;

	int h = (s + e) >> 1;

	return seg[n] = ud(s, h, n * 2, p, d) + ud(h + 1, e, n * 2 + 1, p, d);
}

int fd(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return fd(s, h, n * 2, l, r) + fd(h + 1, e, n * 2 + 1, l, r);
}

int main() {

	fastio;

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		int idx = M;

		seg.clear();
		arr.clear();

		seg.resize(4 * (N + M));
		arr.resize(N + 1);

		for (int i = 1; i <= N; ++i) {
			arr[i] = i + M;
			ud(1, N + M, 1, arr[i], 1);
		}

		for (int i = 0; i < M; ++i) {
			int a;
			cin >> a;
			cout << fd(1, N + M, 1, 1, arr[a] - 1) << " ";

			ud(1, N + M, 1, arr[a], -1);
			arr[a] = idx--;
			ud(1, N + M, 1, arr[a], 1);
		}

		cout << "\n";
	}

	return EXIT_SUCCESS;
}
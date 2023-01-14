#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 a[20], b[20];

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 N, M, ans = -INF;
		cin >> N >> M;

		for (int64 i = 0; i < N; ++i) {
			cin >> a[i];
		}

		for (int64 i = 0; i < M; ++i) {
			cin >> b[i];
		}

		int64 dif = abs(N - M);
		if (N > M) {
			for (int64 i = 0; i <= dif; ++i) {
				int64 sum = 0;
				for (int64 j = 0; j < M; ++j) {
					sum = sum + (a[j + i] * b[j]);
				}
				ans = max(ans, sum);
			}
		}
		else {
			for (int64 i = 0; i <= dif; ++i) {
				int64 sum = 0;
				for (int64 j = 0; j < N; ++j) {
					sum = sum + (b[j + i] * a[j]);
				}
				ans = max(ans, sum);
			}
		}

		cout << "#" << t << ' ' << ans << "\n";

	}

	return EXIT_SUCCESS;
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 mx, mi;

int main() {
	fastio;

	int64 N, arr[50], ans = 0;
	cin >> N;
	for (int64 i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int64 i = 0; i < N; ++i) {
		int64 cnt = 0;
		for (int64 j = i - 1; j >= 0; --j) {
			if (j == i - 1) {
				cnt++;
				mi = j;
			}
			else {
				if ((arr[i] - arr[mi]) * (i - j) > (arr[i] - arr[j]) * (i - mi)) {
					cnt++;
					mi = j;
				}
			}
		}
		for (int64 j = i + 1; j < N; ++j) {
			if (j == i + 1) {
				cnt++;
				mx = j;
			}
			else {
				if ((arr[mx] - arr[i]) * (j - i) < (arr[j] - arr[i]) * (mx - i)) {
					cnt++;
					mx = j;
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;

	return EXIT_SUCCESS;
}
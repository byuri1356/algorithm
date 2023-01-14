#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[9], fac[10] = { 1, }, cnt, N, total;

inline void checkComp(int64 dep, int64 left, int64 right, int64 tt) {
	if (tt + right <= left) {
		cnt = cnt + (pow(2, N - dep) * fac[N - dep]); left; right; tt;
		return;
	}

	for (int64 i = dep; i < N; ++i) {
		if (right + arr[i] <= left) {
			int64 tmp = arr[dep];
			arr[dep] = arr[i];
			arr[i] = tmp;
			checkComp(dep + 1, left, right + arr[dep], tt - arr[dep]);
			tmp = arr[dep];
			arr[dep] = arr[i];
			arr[i] = tmp;
		}
		int64 tmp = arr[dep];
		arr[dep] = arr[i];
		arr[i] = tmp;
		checkComp(dep + 1, left + arr[dep], right, tt - arr[dep]);
		tmp = arr[dep];
		arr[dep] = arr[i];
		arr[i] = tmp;
	}
}

int main() {
	fastio;

	for (int64 i = 1; i < 10; ++i) {
		fac[i] = i * fac[i - 1];
	}

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		cin >> N;

		cnt = 0, total = 0;
		for (int64 i = 0; i < N; ++i) {
			cin >> arr[i];
			total += arr[i];
		}

		checkComp(0, 0, 0, total);

		cout << "#" << t << ' ' << cnt << "\n";
	}

	return EXIT_SUCCESS;
}
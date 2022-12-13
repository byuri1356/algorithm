#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[101][10] = { {0,}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };

int main() {
	fastio;

	for (int64 i = 2; i <= 100; ++i) {
		for (int64 j = 0; j <= 9; ++j) {
			if (j == 0) arr[i][j] += arr[i - 1][j + 1] % 1'000'000'000;
			else if (j == 9) arr[i][j] += arr[i - 1][j - 1] % 1'000'000'000;
			else arr[i][j] += (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1'000'000'000;
		}
	}

	int64 T, ans=0;
	cin >> T;
	for (int64 i = 0; i < 10; ++i) {
		ans += arr[T][i];
	}
	cout << ans % 1'000'000'000;
	return EXIT_SUCCESS;
}
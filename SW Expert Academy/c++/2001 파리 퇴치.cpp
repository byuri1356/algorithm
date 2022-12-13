#include<iostream>
#include<algorithm>

using namespace std;
using int64 = int64_t;

int64 arr[15][15];

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, N, M;
	cin >> T;
	for (int64 i = 1; i <= T; ++i) {
		cin >> N >> M;
		//map init
		for (int64 j = 0; j < N; ++j) {
			for (int64 k = 0; k < N; ++k) {
				cin >> arr[j][k];
			}
		}

		//solve
		int64 ans = 0;
		for (int64 j = 0; j <= N - M; ++j) {
			for (int64 k = 0; k <= N - M; ++k) {
				int64 sum = 0;
				for (int64 l = 0; l < M; ++l) {
					for (int64 m = 0; m < M; ++m) {
						sum += arr[j + l][k + m];
					}
				}
				ans = max(ans, sum);
			}
		}

		//print
		cout << "#" << i << ' ' << ans << "\n";
	}

	return EXIT_SUCCESS;
}